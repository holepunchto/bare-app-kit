#import <assert.h>
#import <bare.h>
#import <js.h>
#import <log.h>
#import <path.h>
#import <rlimit.h>
#import <signal.h>
#import <uv.h>

#import <AppKit/AppKit.h>

static uv_barrier_t bare__platform_ready;
static uv_async_t bare__platform_shutdown;
static uv_thread_t bare__platform_thread;
static js_platform_t *bare__platform;

static int bare__argc;
static char **bare__argv;

static uv_loop_t *bare__loop;
static uv_async_t bare__shutdown;
static bare_t *bare;

static dispatch_source_t bare__poll;
static dispatch_source_t bare__timer;

static void
bare__on_shutdown(uv_async_t *handle) {
  uv_close((uv_handle_t *) handle, NULL);
}

static void
bare__on_platform_thread(void *data) {
  int err;

  uv_loop_t loop;
  err = uv_loop_init(&loop);
  assert(err == 0);

  err = uv_async_init(&loop, &bare__platform_shutdown, bare__on_shutdown);
  assert(err == 0);

  err = js_create_platform(&loop, NULL, &bare__platform);
  assert(err == 0);

  uv_barrier_wait(&bare__platform_ready);

  err = uv_run(&loop, UV_RUN_DEFAULT);
  assert(err == 0);

  err = js_destroy_platform(bare__platform);
  assert(err == 0);

  err = uv_run(&loop, UV_RUN_DEFAULT);
  assert(err == 0);

  err = uv_loop_close(&loop);
  assert(err == 0);
}

static void
bare__run(void) {
  int err;

  int timeout = uv_backend_timeout(bare__loop);

  if (timeout < 0) {
    dispatch_source_cancel(bare__timer);
  } else {
    uint64_t nanoseconds = (uint64_t) timeout * NSEC_PER_MSEC;

    dispatch_source_set_timer(
      bare__timer,
      dispatch_time(DISPATCH_TIME_NOW, nanoseconds),
      DISPATCH_TIME_FOREVER,
      0
    );
  }

  err = bare_run(bare, UV_RUN_NOWAIT);
  assert(err >= 0);
}

static void
bare__launch(void) {
  int err;

  err = uv_barrier_init(&bare__platform_ready, 2);
  assert(err == 0);

  err = uv_thread_create(&bare__platform_thread, bare__on_platform_thread, NULL);
  assert(err == 0);

  uv_barrier_wait(&bare__platform_ready);

  uv_barrier_destroy(&bare__platform_ready);

  bare__loop = uv_default_loop();

  err = uv_async_init(bare__loop, &bare__shutdown, bare__on_shutdown);
  assert(err == 0);

  err = bare_setup(bare__loop, bare__platform, NULL, bare__argc, (const char **) bare__argv, NULL, &bare);
  assert(err == 0);

  size_t len;

  char bin[4096];
  len = sizeof(bin);

  err = uv_exepath(bin, &len);
  assert(err == 0);

  size_t dir;
  err = path_dirname(bin, &dir, path_behavior_system);
  assert(err == 0);

  char bundle[4096];
  len = 4096;

  err = path_join(
    (const char *[]) {bin, "..", "..", "Resources", "app.bundle", NULL},
    bundle,
    &len,
    path_behavior_system
  );
  assert(err == 0);

  err = bare_load(bare, bundle, NULL, NULL);
  (void) err;

  dispatch_queue_t queue = dispatch_get_main_queue();

  bare__poll = dispatch_source_create(DISPATCH_SOURCE_TYPE_READ, bare__loop->backend_fd, 0, queue);

  bare__timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, queue);

  dispatch_source_set_event_handler(bare__poll, ^{
    bare__run();
  });

  dispatch_source_set_event_handler(bare__timer, ^{
    bare__run();
  });

  dispatch_resume(bare__poll);
  dispatch_resume(bare__timer);

  bare__run();
}

static void
bare__terminate(void) {
  int err;

  dispatch_source_cancel(bare__poll);
  dispatch_source_cancel(bare__timer);

  err = uv_async_send(&bare__shutdown);
  assert(err == 0);

  err = bare_terminate(bare);
  assert(err == 0);

  err = bare_run(bare, UV_RUN_DEFAULT);
  assert(err == 0);

  err = bare_teardown(bare, UV_RUN_DEFAULT, NULL);
  assert(err == 0);

  err = uv_loop_close(bare__loop);
  assert(err == 0);

  err = uv_async_send(&bare__platform_shutdown);
  assert(err == 0);

  uv_thread_join(&bare__platform_thread);

  err = log_close();
  assert(err == 0);
}

@interface BareDelegate : NSObject <NSApplicationDelegate>

@end

@implementation BareDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)notification {
  bare__launch();
}

- (void)applicationWillTerminate:(NSNotification *)notification {
  bare__terminate();
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
  return YES;
}

@end

int
main(int argc, char *argv[]) {
  int err;

#ifdef SIGPIPE
  signal(SIGPIPE, SIG_IGN);
#endif

  err = log_open("bare", 0);
  assert(err == 0);

  err = rlimit_set(rlimit_open_files, rlimit_infer);
  assert(err == 0);

  argv = uv_setup_args(argc, argv);

  bare__argc = argc;
  bare__argv = argv;

  @autoreleasepool {
    NSApplication *app = [NSApplication sharedApplication];

    app.delegate = [[BareDelegate alloc] init];

    return NSApplicationMain(argc, (const char **) argv);
  }
}
