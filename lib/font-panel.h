#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_font_panel_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 0;
  js_value_t *argv[0];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    NSFontPanel *handle = [NSFontPanel sharedFontPanel];

    result = bare_foundation_bridge(env, registry, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_panel_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSFontPanel *font_panel = (__bridge NSFontPanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, font_panel.enabled, &result);
      assert(err == 0);
    } else {
      bool enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "enabled", &enabled)) return NULL;

      font_panel.enabled = enabled;
    }
  }

  return result;
}

static void
bare_app_kit_font_panel_enabled_typed(js_value_t *receiver, int32_t bare_tag, bool enabled, js_typed_callback_info_t *info) {
  int err;

  bare_foundation_registry_t *registry;
  err = js_get_typed_callback_info(info, NULL, (void **) &registry);
  assert(err == 0);

  id bare_object = bare_foundation_object(registry, bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSFontPanel *font_panel = (NSFontPanel *) bare_object;

    font_panel.enabled = enabled;
  }
}

static js_value_t *
bare_app_kit_font_panel_accessory_view(js_env_t *env, js_callback_info_t *info) {
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
    NSFontPanel *font_panel = (__bridge NSFontPanel *) handle;

    if (argc == 1) {
      result = bare_foundation_bridge(env, registry, font_panel.accessoryView);
    } else {
      font_panel.accessoryView = bare_foundation_to_object(env, registry, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_font_panel_set_panel_font(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  id font = bare_foundation_to_object(env, registry, argv[1]);

  bool multiple;
  if (!bare_app_kit__read_bool(env, argv[2], "multiple", &multiple)) return NULL;

  @autoreleasepool {
    NSFontPanel *font_panel = (__bridge NSFontPanel *) handle;

    [font_panel setPanelFont:font isMultiple:multiple];
  }

  return NULL;
}
