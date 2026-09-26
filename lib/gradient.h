#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_gradient_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1);

  js_value_t *result;

  @autoreleasepool {
    NSArray *colors = bare_app_kit__to_objects(env, registry, argv[0]);

    NSGradient *handle = [[[NSGradient alloc] initWithColors:colors] autorelease];

    result = bare_foundation_bridge(env, registry, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_gradient_number_of_color_stops(js_env_t *env, js_callback_info_t *info) {
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
    NSGradient *gradient = (__bridge NSGradient *) handle;

    err = js_create_int32(env, gradient.numberOfColorStops, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_gradient_draw_in_rect(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 6;
  js_value_t *argv[6];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 6);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[3], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[4], "height", &height)) return NULL;

  double angle;
  if (!bare_app_kit__read_double(env, argv[5], "angle", &angle)) return NULL;

  @autoreleasepool {
    NSGradient *gradient = (__bridge NSGradient *) handle;

    [gradient drawInRect:NSMakeRect(x, y, width, height) angle:angle];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_gradient_draw_in_path(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  id path = bare_foundation_to_object(env, registry, argv[1]);

  double angle;
  if (!bare_app_kit__read_double(env, argv[2], "angle", &angle)) return NULL;

  @autoreleasepool {
    NSGradient *gradient = (__bridge NSGradient *) handle;

    [gradient drawInBezierPath:path angle:angle];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_gradient_interpolated_color_at(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  double location;
  if (!bare_app_kit__read_double(env, argv[1], "location", &location)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSGradient *gradient = (__bridge NSGradient *) handle;

    result = bare_foundation_bridge(env, registry, [gradient interpolatedColorAtLocation:location]);
  }

  return result;
}
