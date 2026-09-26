#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BarePanel : NSPanel <NSWindowDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BarePanel

- (void)dealloc {
  int err;

  err = js_delete_reference(env, ctx);
  assert(err == 0);

  [super dealloc];
}

- (int32_t)eventMask {
  return mask;
}

- (void)setEventMask:(int32_t)value {
  mask = value;
}

- (void)windowDidResize:(NSNotification *)notification {
  if ((mask & (1 << 0)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidresize");
}

- (void)windowDidMove:(NSNotification *)notification {
  if ((mask & (1 << 1)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidmove");
}

- (void)windowWillClose:(NSNotification *)notification {
  if ((mask & (1 << 2)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onwillclose");
}

- (void)windowDidBecomeKey:(NSNotification *)notification {
  if ((mask & (1 << 3)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidbecomekey");
}

- (void)windowDidResignKey:(NSNotification *)notification {
  if ((mask & (1 << 4)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidresignkey");
}

- (void)windowDidBecomeMain:(NSNotification *)notification {
  if ((mask & (1 << 5)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidbecomemain");
}

- (void)windowDidResignMain:(NSNotification *)notification {
  if ((mask & (1 << 6)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidresignmain");
}

- (void)windowDidMiniaturize:(NSNotification *)notification {
  if ((mask & (1 << 7)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidminiaturize");
}

- (void)windowDidDeminiaturize:(NSNotification *)notification {
  if ((mask & (1 << 8)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondiddeminiaturize");
}

- (void)windowDidEnterFullScreen:(NSNotification *)notification {
  if ((mask & (1 << 9)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidenterfullscreen");
}

- (void)windowDidExitFullScreen:(NSNotification *)notification {
  if ((mask & (1 << 10)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidexitfullscreen");
}

- (void)windowWillStartLiveResize:(NSNotification *)notification {
  if ((mask & (1 << 11)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onwillstartliveresize");
}

- (void)windowDidEndLiveResize:(NSNotification *)notification {
  if ((mask & (1 << 12)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidendliveresize");
}

@end

static js_value_t *
bare_app_kit_panel_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 7;
  js_value_t *argv[7];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 7);

  double x;
  err = js_get_value_double(env, argv[0], &x);
  assert(err == 0);

  double y;
  err = js_get_value_double(env, argv[1], &y);
  assert(err == 0);

  double width;
  err = js_get_value_double(env, argv[2], &width);
  assert(err == 0);

  double height;
  err = js_get_value_double(env, argv[3], &height);
  assert(err == 0);

  int32_t style_mask;
  if (!bare_app_kit__read_int32(env, argv[4], "style_mask", &style_mask)) return NULL;

  bool defer;
  if (!bare_app_kit__read_bool(env, argv[5], "defer", &defer)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    BarePanel *handle = [[[BarePanel alloc]
      initWithContentRect:NSMakeRect(x, y, width, height)
                styleMask:style_mask
                  backing:NSBackingStoreBuffered
                    defer:defer] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[6], 0, &handle->ctx);
    assert(err == 0);

    [handle setDelegate:handle];

    // The panel belongs to its JS wrapper, so it must not free itself.
    [handle setReleasedWhenClosed:NO];
  }

  return result;
}

static js_value_t *
bare_app_kit_panel_floating_panel(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSPanel *panel = (__bridge NSPanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, panel.floatingPanel, &result);
      assert(err == 0);
    } else {
      bool floating_panel;
      if (!bare_app_kit__read_bool(env, argv[1], "floating_panel", &floating_panel)) return NULL;

      panel.floatingPanel = floating_panel;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_panel_becomes_key_only_if_needed(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSPanel *panel = (__bridge NSPanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, panel.becomesKeyOnlyIfNeeded, &result);
      assert(err == 0);
    } else {
      bool becomes_key_only_if_needed;
      if (!bare_app_kit__read_bool(env, argv[1], "becomes_key_only_if_needed", &becomes_key_only_if_needed)) return NULL;

      panel.becomesKeyOnlyIfNeeded = becomes_key_only_if_needed;
    }
  }

  return result;
}
