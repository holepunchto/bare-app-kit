#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

enum {
  bare_app_kit_panel_event_did_resize = 1 << 0,
  bare_app_kit_panel_event_did_move = 1 << 1,
  bare_app_kit_panel_event_will_close = 1 << 2,
  bare_app_kit_panel_event_did_become_key = 1 << 3,
  bare_app_kit_panel_event_did_resign_key = 1 << 4,
  bare_app_kit_panel_event_did_become_main = 1 << 5,
  bare_app_kit_panel_event_did_resign_main = 1 << 6,
  bare_app_kit_panel_event_did_miniaturize = 1 << 7,
  bare_app_kit_panel_event_did_deminiaturize = 1 << 8,
  bare_app_kit_panel_event_did_enter_full_screen = 1 << 9,
  bare_app_kit_panel_event_did_exit_full_screen = 1 << 10,
  bare_app_kit_panel_event_will_start_live_resize = 1 << 11,
  bare_app_kit_panel_event_did_end_live_resize = 1 << 12,
};


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
  if ((mask & bare_app_kit_panel_event_did_resize) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidresize");
}

- (void)windowDidMove:(NSNotification *)notification {
  if ((mask & bare_app_kit_panel_event_did_move) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidmove");
}

- (void)windowWillClose:(NSNotification *)notification {
  if ((mask & bare_app_kit_panel_event_will_close) == 0) return;

  bare_app_kit__emit(env, ctx, "_onwillclose");
}

- (void)windowDidBecomeKey:(NSNotification *)notification {
  if ((mask & bare_app_kit_panel_event_did_become_key) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidbecomekey");
}

- (void)windowDidResignKey:(NSNotification *)notification {
  if ((mask & bare_app_kit_panel_event_did_resign_key) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidresignkey");
}

- (void)windowDidBecomeMain:(NSNotification *)notification {
  if ((mask & bare_app_kit_panel_event_did_become_main) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidbecomemain");
}

- (void)windowDidResignMain:(NSNotification *)notification {
  if ((mask & bare_app_kit_panel_event_did_resign_main) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidresignmain");
}

- (void)windowDidMiniaturize:(NSNotification *)notification {
  if ((mask & bare_app_kit_panel_event_did_miniaturize) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidminiaturize");
}

- (void)windowDidDeminiaturize:(NSNotification *)notification {
  if ((mask & bare_app_kit_panel_event_did_deminiaturize) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondiddeminiaturize");
}

- (void)windowDidEnterFullScreen:(NSNotification *)notification {
  if ((mask & bare_app_kit_panel_event_did_enter_full_screen) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidenterfullscreen");
}

- (void)windowDidExitFullScreen:(NSNotification *)notification {
  if ((mask & bare_app_kit_panel_event_did_exit_full_screen) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidexitfullscreen");
}

- (void)windowWillStartLiveResize:(NSNotification *)notification {
  if ((mask & bare_app_kit_panel_event_will_start_live_resize) == 0) return;

  bare_app_kit__emit(env, ctx, "_onwillstartliveresize");
}

- (void)windowDidEndLiveResize:(NSNotification *)notification {
  if ((mask & bare_app_kit_panel_event_did_end_live_resize) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidendliveresize");
}

@end

static js_value_t *
bare_app_kit_panel_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 7;
  js_value_t *argv[7];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
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

    result = bare_foundation_bridge(env, registry, handle);

    handle->env = env;

    // Weak, so the native object does not keep its own wrapper alive. Events
    // are dropped once the wrapper is collected.
    err = js_create_reference(env, argv[6], 0, &handle->ctx);
    assert(err == 0);

    [handle setDelegate:handle];

    // The panel belongs to its wrapper, so it must not free itself.
    [handle setReleasedWhenClosed:NO];
  }

  return result;
}

static js_value_t *
bare_app_kit_panel_floating_panel(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

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

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

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
