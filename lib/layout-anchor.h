#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_layout_anchor_equal_to(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  id anchor = bare_foundation_to_object(env, registry, argv[1]);

  double constant;
  if (!bare_app_kit__read_double(env, argv[2], "constant", &constant)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSLayoutAnchor *layout_anchor = (__bridge NSLayoutAnchor *) handle;

    result = bare_foundation_bridge(env, registry, [layout_anchor constraintEqualToAnchor:anchor constant:constant]);
  }

  return result;
}

static js_value_t *
bare_app_kit_layout_anchor_greater_than_or_equal_to(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  id anchor = bare_foundation_to_object(env, registry, argv[1]);

  double constant;
  if (!bare_app_kit__read_double(env, argv[2], "constant", &constant)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSLayoutAnchor *layout_anchor = (__bridge NSLayoutAnchor *) handle;

    result = bare_foundation_bridge(env, registry, [layout_anchor constraintGreaterThanOrEqualToAnchor:anchor constant:constant]);
  }

  return result;
}

static js_value_t *
bare_app_kit_layout_anchor_less_than_or_equal_to(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  id anchor = bare_foundation_to_object(env, registry, argv[1]);

  double constant;
  if (!bare_app_kit__read_double(env, argv[2], "constant", &constant)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSLayoutAnchor *layout_anchor = (__bridge NSLayoutAnchor *) handle;

    result = bare_foundation_bridge(env, registry, [layout_anchor constraintLessThanOrEqualToAnchor:anchor constant:constant]);
  }

  return result;
}

static js_value_t *
bare_app_kit_layout_anchor_equal_to_constant(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  double constant;
  if (!bare_app_kit__read_double(env, argv[1], "constant", &constant)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSLayoutDimension *layout_anchor = (__bridge NSLayoutDimension *) handle;

    result = bare_foundation_bridge(env, registry, [layout_anchor constraintEqualToConstant:constant]);
  }

  return result;
}

static js_value_t *
bare_app_kit_layout_anchor_greater_than_or_equal_to_constant(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  double constant;
  if (!bare_app_kit__read_double(env, argv[1], "constant", &constant)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSLayoutDimension *layout_anchor = (__bridge NSLayoutDimension *) handle;

    result = bare_foundation_bridge(env, registry, [layout_anchor constraintGreaterThanOrEqualToConstant:constant]);
  }

  return result;
}

static js_value_t *
bare_app_kit_layout_anchor_less_than_or_equal_to_constant(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  double constant;
  if (!bare_app_kit__read_double(env, argv[1], "constant", &constant)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSLayoutDimension *layout_anchor = (__bridge NSLayoutDimension *) handle;

    result = bare_foundation_bridge(env, registry, [layout_anchor constraintLessThanOrEqualToConstant:constant]);
  }

  return result;
}

static js_value_t *
bare_app_kit_layout_anchor_equal_to_multiple(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 4);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  id anchor = bare_foundation_to_object(env, registry, argv[1]);

  double multiplier;
  if (!bare_app_kit__read_double(env, argv[2], "multiplier", &multiplier)) return NULL;

  double constant;
  if (!bare_app_kit__read_double(env, argv[3], "constant", &constant)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSLayoutDimension *layout_anchor = (__bridge NSLayoutDimension *) handle;

    result = bare_foundation_bridge(env, registry, [layout_anchor constraintEqualToAnchor:anchor multiplier:multiplier constant:constant]);
  }

  return result;
}
