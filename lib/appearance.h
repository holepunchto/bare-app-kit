#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_appearance_name(js_env_t *env, js_callback_info_t *info) {
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
    NSAppearance *appearance = (__bridge NSAppearance *) handle;

    result = bare_app_kit__from_string(env, appearance.name);
  }

  return result;
}

static js_value_t *
bare_app_kit_appearance_named(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSString *name = bare_app_kit__to_string(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSAppearance appearanceNamed:name]);
  }

  return result;
}

static js_value_t *
bare_app_kit_appearance_current(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSAppearance currentDrawingAppearance]);
  }

  return result;
}

static js_value_t *
bare_app_kit_appearance_best_match(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSArray<NSString *> *names = bare_app_kit__to_strings(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSAppearance *appearance = (__bridge NSAppearance *) handle;

    result = bare_app_kit__from_string(env, [appearance bestMatchFromAppearancesWithNames:names]);
  }

  return result;
}
