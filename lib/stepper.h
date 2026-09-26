#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareStepper : NSStepper <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareStepper

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

- (void)onChange:(id)sender {
  if ((mask & (1 << 0)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onchange");
}

@end

static js_value_t *
bare_app_kit_stepper_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 5);

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

  js_value_t *result;

  @autoreleasepool {
    BareStepper *handle = [[[BareStepper alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onChange:)];
  }

  return result;
}

static js_value_t *
bare_app_kit_stepper_min_value(js_env_t *env, js_callback_info_t *info) {
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
    NSStepper *stepper = (__bridge NSStepper *) handle;

    if (argc == 1) {
      err = js_create_double(env, stepper.minValue, &result);
      assert(err == 0);
    } else {
      double min_value;
      if (!bare_app_kit__read_double(env, argv[1], "min_value", &min_value)) return NULL;

      stepper.minValue = min_value;
    }
  }

  return result;
}

static void
bare_app_kit_stepper_min_value_typed(js_value_t *receiver, int32_t bare_tag, double min_value, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStepper *stepper = (NSStepper *) bare_object;

    stepper.minValue = min_value;
  }
}

static js_value_t *
bare_app_kit_stepper_max_value(js_env_t *env, js_callback_info_t *info) {
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
    NSStepper *stepper = (__bridge NSStepper *) handle;

    if (argc == 1) {
      err = js_create_double(env, stepper.maxValue, &result);
      assert(err == 0);
    } else {
      double max_value;
      if (!bare_app_kit__read_double(env, argv[1], "max_value", &max_value)) return NULL;

      stepper.maxValue = max_value;
    }
  }

  return result;
}

static void
bare_app_kit_stepper_max_value_typed(js_value_t *receiver, int32_t bare_tag, double max_value, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStepper *stepper = (NSStepper *) bare_object;

    stepper.maxValue = max_value;
  }
}

static js_value_t *
bare_app_kit_stepper_increment(js_env_t *env, js_callback_info_t *info) {
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
    NSStepper *stepper = (__bridge NSStepper *) handle;

    if (argc == 1) {
      err = js_create_double(env, stepper.increment, &result);
      assert(err == 0);
    } else {
      double increment;
      if (!bare_app_kit__read_double(env, argv[1], "increment", &increment)) return NULL;

      stepper.increment = increment;
    }
  }

  return result;
}

static void
bare_app_kit_stepper_increment_typed(js_value_t *receiver, int32_t bare_tag, double increment, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStepper *stepper = (NSStepper *) bare_object;

    stepper.increment = increment;
  }
}

static js_value_t *
bare_app_kit_stepper_value_wraps(js_env_t *env, js_callback_info_t *info) {
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
    NSStepper *stepper = (__bridge NSStepper *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, stepper.valueWraps, &result);
      assert(err == 0);
    } else {
      bool value_wraps;
      if (!bare_app_kit__read_bool(env, argv[1], "value_wraps", &value_wraps)) return NULL;

      stepper.valueWraps = value_wraps;
    }
  }

  return result;
}

static void
bare_app_kit_stepper_value_wraps_typed(js_value_t *receiver, int32_t bare_tag, bool value_wraps, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStepper *stepper = (NSStepper *) bare_object;

    stepper.valueWraps = value_wraps;
  }
}

static js_value_t *
bare_app_kit_stepper_autorepeat(js_env_t *env, js_callback_info_t *info) {
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
    NSStepper *stepper = (__bridge NSStepper *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, stepper.autorepeat, &result);
      assert(err == 0);
    } else {
      bool autorepeat;
      if (!bare_app_kit__read_bool(env, argv[1], "autorepeat", &autorepeat)) return NULL;

      stepper.autorepeat = autorepeat;
    }
  }

  return result;
}

static void
bare_app_kit_stepper_autorepeat_typed(js_value_t *receiver, int32_t bare_tag, bool autorepeat, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStepper *stepper = (NSStepper *) bare_object;

    stepper.autorepeat = autorepeat;
  }
}
