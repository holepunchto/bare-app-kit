#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_status_item_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1);

  double length;
  if (!bare_app_kit__read_double(env, argv[0], "length", &length)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSStatusItem *handle = [[NSStatusBar systemStatusBar] statusItemWithLength:length];

    result = bare_foundation_bridge(env, registry, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_status_item_length(js_env_t *env, js_callback_info_t *info) {
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
    NSStatusItem *status_item = (__bridge NSStatusItem *) handle;

    if (argc == 1) {
      err = js_create_double(env, status_item.length, &result);
      assert(err == 0);
    } else {
      double length;
      if (!bare_app_kit__read_double(env, argv[1], "length", &length)) return NULL;

      status_item.length = length;
    }
  }

  return result;
}

static void
bare_app_kit_status_item_length_typed(js_value_t *receiver, int32_t bare_tag, double length, js_typed_callback_info_t *info) {
  int err;

  bare_foundation_registry_t *registry;
  err = js_get_typed_callback_info(info, NULL, (void **) &registry);
  assert(err == 0);

  id bare_object = bare_foundation_object(registry, bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStatusItem *status_item = (NSStatusItem *) bare_object;

    status_item.length = length;
  }
}

static js_value_t *
bare_app_kit_status_item_visible(js_env_t *env, js_callback_info_t *info) {
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
    NSStatusItem *status_item = (__bridge NSStatusItem *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, status_item.visible, &result);
      assert(err == 0);
    } else {
      bool visible;
      if (!bare_app_kit__read_bool(env, argv[1], "visible", &visible)) return NULL;

      status_item.visible = visible;
    }
  }

  return result;
}

static void
bare_app_kit_status_item_visible_typed(js_value_t *receiver, int32_t bare_tag, bool visible, js_typed_callback_info_t *info) {
  int err;

  bare_foundation_registry_t *registry;
  err = js_get_typed_callback_info(info, NULL, (void **) &registry);
  assert(err == 0);

  id bare_object = bare_foundation_object(registry, bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStatusItem *status_item = (NSStatusItem *) bare_object;

    status_item.visible = visible;
  }
}

static js_value_t *
bare_app_kit_status_item_menu(js_env_t *env, js_callback_info_t *info) {
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
    NSStatusItem *status_item = (__bridge NSStatusItem *) handle;

    if (argc == 1) {
      result = bare_foundation_bridge(env, registry, status_item.menu);
    } else {
      status_item.menu = bare_foundation_to_object(env, registry, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_status_item_button(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSStatusItem *status_item = (__bridge NSStatusItem *) handle;

    result = bare_foundation_bridge(env, registry, status_item.button);
  }

  return result;
}
