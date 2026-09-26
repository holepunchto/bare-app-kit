#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_color_panel_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 0;
  js_value_t *argv[0];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    NSColorPanel *handle = [NSColorPanel sharedColorPanel];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_panel_color(js_env_t *env, js_callback_info_t *info) {
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
    NSColorPanel *color_panel = (__bridge NSColorPanel *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, color_panel.color);
    } else {
      color_panel.color = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_color_panel_mode(js_env_t *env, js_callback_info_t *info) {
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
    NSColorPanel *color_panel = (__bridge NSColorPanel *) handle;

    if (argc == 1) {
      err = js_create_int32(env, color_panel.mode, &result);
      assert(err == 0);
    } else {
      int32_t mode;
      if (!bare_app_kit__read_int32(env, argv[1], "mode", &mode)) return NULL;

      color_panel.mode = mode;
    }
  }

  return result;
}

static void
bare_app_kit_color_panel_mode_typed(js_value_t *receiver, int32_t bare_tag, int32_t mode, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSColorPanel *color_panel = (NSColorPanel *) bare_object;

    color_panel.mode = mode;
  }
}

static js_value_t *
bare_app_kit_color_panel_shows_alpha(js_env_t *env, js_callback_info_t *info) {
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
    NSColorPanel *color_panel = (__bridge NSColorPanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, color_panel.showsAlpha, &result);
      assert(err == 0);
    } else {
      bool shows_alpha;
      if (!bare_app_kit__read_bool(env, argv[1], "shows_alpha", &shows_alpha)) return NULL;

      color_panel.showsAlpha = shows_alpha;
    }
  }

  return result;
}

static void
bare_app_kit_color_panel_shows_alpha_typed(js_value_t *receiver, int32_t bare_tag, bool shows_alpha, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSColorPanel *color_panel = (NSColorPanel *) bare_object;

    color_panel.showsAlpha = shows_alpha;
  }
}

static js_value_t *
bare_app_kit_color_panel_continuous(js_env_t *env, js_callback_info_t *info) {
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
    NSColorPanel *color_panel = (__bridge NSColorPanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, color_panel.continuous, &result);
      assert(err == 0);
    } else {
      bool continuous;
      if (!bare_app_kit__read_bool(env, argv[1], "continuous", &continuous)) return NULL;

      color_panel.continuous = continuous;
    }
  }

  return result;
}

static void
bare_app_kit_color_panel_continuous_typed(js_value_t *receiver, int32_t bare_tag, bool continuous, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSColorPanel *color_panel = (NSColorPanel *) bare_object;

    color_panel.continuous = continuous;
  }
}

static js_value_t *
bare_app_kit_color_panel_accessory_view(js_env_t *env, js_callback_info_t *info) {
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
    NSColorPanel *color_panel = (__bridge NSColorPanel *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, color_panel.accessoryView);
    } else {
      color_panel.accessoryView = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}
