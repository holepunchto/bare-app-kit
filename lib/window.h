#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareWindow : NSWindow <NSWindowDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareWindow

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
bare_app_kit_window_init(js_env_t *env, js_callback_info_t *info) {
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
    BareWindow *handle = [[[BareWindow alloc]
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

    // The window belongs to its JS wrapper, so it must not free itself.
    [handle setReleasedWhenClosed:NO];
  }

  return result;
}

static js_value_t *
bare_app_kit_window_title(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, window.title);
    } else {
      window.title = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_subtitle(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, window.subtitle);
    } else {
      window.subtitle = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_represented_filename(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, window.representedFilename);
    } else {
      window.representedFilename = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_miniwindow_title(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, window.miniwindowTitle);
    } else {
      window.miniwindowTitle = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_frame_autosave_name(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    result = bare_app_kit__from_string(env, window.frameAutosaveName);
  }

  return result;
}

// Where the tab key starts. A window whose first responder is the window
// itself has nowhere to begin walking its key view loop, so tabbing does
// nothing at all until something has been given the focus by other means.
static js_value_t *
bare_app_kit_window_initial_first_responder(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, window.initialFirstResponder);
    } else {
      window.initialFirstResponder = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_content_view(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, window.contentView);
    } else {
      window.contentView = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_background_color(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, window.backgroundColor);
    } else {
      window.backgroundColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_miniwindow_image(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, window.miniwindowImage);
    } else {
      window.miniwindowImage = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_toolbar(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, window.toolbar);
    } else {
      window.toolbar = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_appearance(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, window.appearance);
    } else {
      window.appearance = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_effective_appearance(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    result = bare_foundation__bridge(env, window.effectiveAppearance);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_parent_window(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, window.parentWindow);
    } else {
      window.parentWindow = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_attached_sheet(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    result = bare_foundation__bridge(env, window.attachedSheet);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_style_mask(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_create_int32(env, window.styleMask, &result);
      assert(err == 0);
    } else {
      int32_t style_mask;
      if (!bare_app_kit__read_int32(env, argv[1], "style_mask", &style_mask)) return NULL;

      window.styleMask = style_mask;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_level(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_create_int32(env, window.level, &result);
      assert(err == 0);
    } else {
      int32_t level;
      if (!bare_app_kit__read_int32(env, argv[1], "level", &level)) return NULL;

      window.level = level;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_collection_behavior(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_create_int32(env, window.collectionBehavior, &result);
      assert(err == 0);
    } else {
      int32_t collection_behavior;
      if (!bare_app_kit__read_int32(env, argv[1], "collection_behavior", &collection_behavior)) return NULL;

      window.collectionBehavior = collection_behavior;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_animation_behavior(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_create_int32(env, window.animationBehavior, &result);
      assert(err == 0);
    } else {
      int32_t animation_behavior;
      if (!bare_app_kit__read_int32(env, argv[1], "animation_behavior", &animation_behavior)) return NULL;

      window.animationBehavior = animation_behavior;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_title_visibility(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_create_int32(env, window.titleVisibility, &result);
      assert(err == 0);
    } else {
      int32_t title_visibility;
      if (!bare_app_kit__read_int32(env, argv[1], "title_visibility", &title_visibility)) return NULL;

      window.titleVisibility = title_visibility;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_toolbar_style(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_create_int32(env, window.toolbarStyle, &result);
      assert(err == 0);
    } else {
      int32_t toolbar_style;
      if (!bare_app_kit__read_int32(env, argv[1], "toolbar_style", &toolbar_style)) return NULL;

      window.toolbarStyle = toolbar_style;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_titlebar_separator_style(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_create_int32(env, window.titlebarSeparatorStyle, &result);
      assert(err == 0);
    } else {
      int32_t titlebar_separator_style;
      if (!bare_app_kit__read_int32(env, argv[1], "titlebar_separator_style", &titlebar_separator_style)) return NULL;

      window.titlebarSeparatorStyle = titlebar_separator_style;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_tabbing_mode(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_create_int32(env, window.tabbingMode, &result);
      assert(err == 0);
    } else {
      int32_t tabbing_mode;
      if (!bare_app_kit__read_int32(env, argv[1], "tabbing_mode", &tabbing_mode)) return NULL;

      window.tabbingMode = tabbing_mode;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_window_number(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_create_int32(env, window.windowNumber, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_titlebar_appears_transparent(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.titlebarAppearsTransparent, &result);
      assert(err == 0);
    } else {
      bool titlebar_appears_transparent;
      if (!bare_app_kit__read_bool(env, argv[1], "titlebar_appears_transparent", &titlebar_appears_transparent)) return NULL;

      window.titlebarAppearsTransparent = titlebar_appears_transparent;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_excluded_from_windows_menu(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.excludedFromWindowsMenu, &result);
      assert(err == 0);
    } else {
      bool excluded_from_windows_menu;
      if (!bare_app_kit__read_bool(env, argv[1], "excluded_from_windows_menu", &excluded_from_windows_menu)) return NULL;

      window.excludedFromWindowsMenu = excluded_from_windows_menu;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_document_edited(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.documentEdited, &result);
      assert(err == 0);
    } else {
      bool document_edited;
      if (!bare_app_kit__read_bool(env, argv[1], "document_edited", &document_edited)) return NULL;

      window.documentEdited = document_edited;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_movable(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.movable, &result);
      assert(err == 0);
    } else {
      bool movable;
      if (!bare_app_kit__read_bool(env, argv[1], "movable", &movable)) return NULL;

      window.movable = movable;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_movable_by_window_background(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.movableByWindowBackground, &result);
      assert(err == 0);
    } else {
      bool movable_by_window_background;
      if (!bare_app_kit__read_bool(env, argv[1], "movable_by_window_background", &movable_by_window_background)) return NULL;

      window.movableByWindowBackground = movable_by_window_background;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_hides_on_deactivate(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.hidesOnDeactivate, &result);
      assert(err == 0);
    } else {
      bool hides_on_deactivate;
      if (!bare_app_kit__read_bool(env, argv[1], "hides_on_deactivate", &hides_on_deactivate)) return NULL;

      window.hidesOnDeactivate = hides_on_deactivate;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_can_hide(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.canHide, &result);
      assert(err == 0);
    } else {
      bool can_hide;
      if (!bare_app_kit__read_bool(env, argv[1], "can_hide", &can_hide)) return NULL;

      window.canHide = can_hide;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_has_shadow(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.hasShadow, &result);
      assert(err == 0);
    } else {
      bool has_shadow;
      if (!bare_app_kit__read_bool(env, argv[1], "has_shadow", &has_shadow)) return NULL;

      window.hasShadow = has_shadow;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_opaque(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.opaque, &result);
      assert(err == 0);
    } else {
      bool opaque;
      if (!bare_app_kit__read_bool(env, argv[1], "opaque", &opaque)) return NULL;

      window.opaque = opaque;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_preserves_content_during_live_resize(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.preservesContentDuringLiveResize, &result);
      assert(err == 0);
    } else {
      bool preserves_content_during_live_resize;
      if (!bare_app_kit__read_bool(env, argv[1], "preserves_content_during_live_resize", &preserves_content_during_live_resize)) return NULL;

      window.preservesContentDuringLiveResize = preserves_content_during_live_resize;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_allows_concurrent_view_drawing(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.allowsConcurrentViewDrawing, &result);
      assert(err == 0);
    } else {
      bool allows_concurrent_view_drawing;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_concurrent_view_drawing", &allows_concurrent_view_drawing)) return NULL;

      window.allowsConcurrentViewDrawing = allows_concurrent_view_drawing;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_views_need_display(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.viewsNeedDisplay, &result);
      assert(err == 0);
    } else {
      bool views_need_display;
      if (!bare_app_kit__read_bool(env, argv[1], "views_need_display", &views_need_display)) return NULL;

      window.viewsNeedDisplay = views_need_display;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_autorecalculates_key_view_loop(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, window.autorecalculatesKeyViewLoop, &result);
      assert(err == 0);
    } else {
      bool autorecalculates_key_view_loop;
      if (!bare_app_kit__read_bool(env, argv[1], "autorecalculates_key_view_loop", &autorecalculates_key_view_loop)) return NULL;

      window.autorecalculatesKeyViewLoop = autorecalculates_key_view_loop;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_works_when_modal(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, window.worksWhenModal, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_visible(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, window.visible, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_key_window(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, window.keyWindow, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_main_window(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, window.mainWindow, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_zoomed(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, window.zoomed, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_miniaturized(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, window.miniaturized, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_in_live_resize(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, window.inLiveResize, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_on_active_space(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, window.onActiveSpace, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_sheet(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, window.sheet, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_can_become_key_window(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, window.canBecomeKeyWindow, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_can_become_main_window(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, window.canBecomeMainWindow, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_alpha_value(js_env_t *env, js_callback_info_t *info) {
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
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      err = js_create_double(env, window.alphaValue, &result);
      assert(err == 0);
    } else {
      double alpha_value;
      if (!bare_app_kit__read_double(env, argv[1], "alpha_value", &alpha_value)) return NULL;

      window.alphaValue = alpha_value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_backing_scale_factor(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_create_double(env, window.backingScaleFactor, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_frame(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    result = bare_app_kit__from_rect(env, window.frame);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_content_layout_rect(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    result = bare_app_kit__from_rect(env, window.contentLayoutRect);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_min_size(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, window.minSize);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      window.minSize = NSMakeSize(width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_max_size(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, window.maxSize);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      window.maxSize = NSMakeSize(width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_content_min_size(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, window.contentMinSize);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      window.contentMinSize = NSMakeSize(width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_content_max_size(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, window.contentMaxSize);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      window.contentMaxSize = NSMakeSize(width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_resize_increments(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, window.resizeIncrements);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      window.resizeIncrements = NSMakeSize(width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_aspect_ratio(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, window.aspectRatio);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      window.aspectRatio = NSMakeSize(width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_content_resize_increments(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, window.contentResizeIncrements);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      window.contentResizeIncrements = NSMakeSize(width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_content_aspect_ratio(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, window.contentAspectRatio);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      window.contentAspectRatio = NSMakeSize(width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_window_center(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window center];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_close(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window close];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_perform_close(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window performClose:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_make_key_window(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window makeKeyWindow];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_make_main_window(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window makeMainWindow];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_make_key_and_order_front(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window makeKeyAndOrderFront:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_order_back(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window orderBack:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_order_front(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window orderFront:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_order_out(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window orderOut:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_miniaturize(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window miniaturize:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_deminiaturize(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window deminiaturize:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_zoom(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window zoom:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_toggle_full_screen(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window toggleFullScreen:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_display(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window display];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_invalidate_shadow(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window invalidateShadow];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_select_next_key_view(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window selectNextKeyView:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_select_previous_key_view(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window selectPreviousKeyView:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_set_frame(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 7;
  js_value_t *argv[7];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 7);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[3], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[4], "height", &height)) return NULL;

  bool display;
  if (!bare_app_kit__read_bool(env, argv[5], "display", &display)) return NULL;

  bool animate;
  if (!bare_app_kit__read_bool(env, argv[6], "animate", &animate)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window setFrame:NSMakeRect(x, y, width, height) display:display animate:animate];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_set_frame_origin(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window setFrameOrigin:NSMakePoint(x, y)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_set_frame_top_left_point(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window setFrameTopLeftPoint:NSMakePoint(x, y)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_set_content_size(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[1], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[2], "height", &height)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window setContentSize:NSMakeSize(width, height)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_make_first_responder(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id view = bare_foundation__to_object(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, [window makeFirstResponder:view], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_set_frame_autosave_name(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *name = bare_app_kit__to_string(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, [window setFrameAutosaveName:name], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_save_frame_using_name(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *name = bare_app_kit__to_string(env, argv[1]);

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window saveFrameUsingName:name];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_set_frame_using_name(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *name = bare_app_kit__to_string(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    err = js_get_boolean(env, [window setFrameUsingName:name], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_window_add_child_window(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id child = bare_foundation__to_object(env, argv[1]);

  int32_t ordered;
  if (!bare_app_kit__read_int32(env, argv[2], "ordered", &ordered)) return NULL;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window addChildWindow:child ordered:ordered];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_remove_child_window(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id child = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    [window removeChildWindow:child];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_window_child_windows(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSWindow *window = (__bridge NSWindow *) handle;

    result = bare_app_kit__from_objects(env, window.childWindows);
  }

  return result;
}
