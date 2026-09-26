#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareLevelIndicator : NSLevelIndicator <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareLevelIndicator

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
bare_app_kit_level_indicator_init(js_env_t *env, js_callback_info_t *info) {
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
    BareLevelIndicator *handle = [[[BareLevelIndicator alloc]
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
bare_app_kit_level_indicator_min_value(js_env_t *env, js_callback_info_t *info) {
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
    NSLevelIndicator *level_indicator = (__bridge NSLevelIndicator *) handle;

    if (argc == 1) {
      err = js_create_double(env, level_indicator.minValue, &result);
      assert(err == 0);
    } else {
      double min_value;
      if (!bare_app_kit__read_double(env, argv[1], "min_value", &min_value)) return NULL;

      level_indicator.minValue = min_value;
    }
  }

  return result;
}

static void
bare_app_kit_level_indicator_min_value_typed(js_value_t *receiver, int32_t bare_tag, double min_value, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSLevelIndicator *level_indicator = (NSLevelIndicator *) bare_object;

    level_indicator.minValue = min_value;
  }
}

static js_value_t *
bare_app_kit_level_indicator_max_value(js_env_t *env, js_callback_info_t *info) {
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
    NSLevelIndicator *level_indicator = (__bridge NSLevelIndicator *) handle;

    if (argc == 1) {
      err = js_create_double(env, level_indicator.maxValue, &result);
      assert(err == 0);
    } else {
      double max_value;
      if (!bare_app_kit__read_double(env, argv[1], "max_value", &max_value)) return NULL;

      level_indicator.maxValue = max_value;
    }
  }

  return result;
}

static void
bare_app_kit_level_indicator_max_value_typed(js_value_t *receiver, int32_t bare_tag, double max_value, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSLevelIndicator *level_indicator = (NSLevelIndicator *) bare_object;

    level_indicator.maxValue = max_value;
  }
}

static js_value_t *
bare_app_kit_level_indicator_warning_value(js_env_t *env, js_callback_info_t *info) {
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
    NSLevelIndicator *level_indicator = (__bridge NSLevelIndicator *) handle;

    if (argc == 1) {
      err = js_create_double(env, level_indicator.warningValue, &result);
      assert(err == 0);
    } else {
      double warning_value;
      if (!bare_app_kit__read_double(env, argv[1], "warning_value", &warning_value)) return NULL;

      level_indicator.warningValue = warning_value;
    }
  }

  return result;
}

static void
bare_app_kit_level_indicator_warning_value_typed(js_value_t *receiver, int32_t bare_tag, double warning_value, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSLevelIndicator *level_indicator = (NSLevelIndicator *) bare_object;

    level_indicator.warningValue = warning_value;
  }
}

static js_value_t *
bare_app_kit_level_indicator_critical_value(js_env_t *env, js_callback_info_t *info) {
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
    NSLevelIndicator *level_indicator = (__bridge NSLevelIndicator *) handle;

    if (argc == 1) {
      err = js_create_double(env, level_indicator.criticalValue, &result);
      assert(err == 0);
    } else {
      double critical_value;
      if (!bare_app_kit__read_double(env, argv[1], "critical_value", &critical_value)) return NULL;

      level_indicator.criticalValue = critical_value;
    }
  }

  return result;
}

static void
bare_app_kit_level_indicator_critical_value_typed(js_value_t *receiver, int32_t bare_tag, double critical_value, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSLevelIndicator *level_indicator = (NSLevelIndicator *) bare_object;

    level_indicator.criticalValue = critical_value;
  }
}

static js_value_t *
bare_app_kit_level_indicator_style(js_env_t *env, js_callback_info_t *info) {
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
    NSLevelIndicator *level_indicator = (__bridge NSLevelIndicator *) handle;

    if (argc == 1) {
      err = js_create_int32(env, level_indicator.levelIndicatorStyle, &result);
      assert(err == 0);
    } else {
      int32_t style;
      if (!bare_app_kit__read_int32(env, argv[1], "style", &style)) return NULL;

      level_indicator.levelIndicatorStyle = style;
    }
  }

  return result;
}

static void
bare_app_kit_level_indicator_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSLevelIndicator *level_indicator = (NSLevelIndicator *) bare_object;

    level_indicator.levelIndicatorStyle = style;
  }
}

static js_value_t *
bare_app_kit_level_indicator_number_of_tick_marks(js_env_t *env, js_callback_info_t *info) {
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
    NSLevelIndicator *level_indicator = (__bridge NSLevelIndicator *) handle;

    if (argc == 1) {
      err = js_create_int32(env, level_indicator.numberOfTickMarks, &result);
      assert(err == 0);
    } else {
      int32_t number_of_tick_marks;
      if (!bare_app_kit__read_int32(env, argv[1], "number_of_tick_marks", &number_of_tick_marks)) return NULL;

      level_indicator.numberOfTickMarks = number_of_tick_marks;
    }
  }

  return result;
}

static void
bare_app_kit_level_indicator_number_of_tick_marks_typed(js_value_t *receiver, int32_t bare_tag, int32_t number_of_tick_marks, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSLevelIndicator *level_indicator = (NSLevelIndicator *) bare_object;

    level_indicator.numberOfTickMarks = number_of_tick_marks;
  }
}

static js_value_t *
bare_app_kit_level_indicator_number_of_major_tick_marks(js_env_t *env, js_callback_info_t *info) {
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
    NSLevelIndicator *level_indicator = (__bridge NSLevelIndicator *) handle;

    if (argc == 1) {
      err = js_create_int32(env, level_indicator.numberOfMajorTickMarks, &result);
      assert(err == 0);
    } else {
      int32_t number_of_major_tick_marks;
      if (!bare_app_kit__read_int32(env, argv[1], "number_of_major_tick_marks", &number_of_major_tick_marks)) return NULL;

      level_indicator.numberOfMajorTickMarks = number_of_major_tick_marks;
    }
  }

  return result;
}

static void
bare_app_kit_level_indicator_number_of_major_tick_marks_typed(js_value_t *receiver, int32_t bare_tag, int32_t number_of_major_tick_marks, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSLevelIndicator *level_indicator = (NSLevelIndicator *) bare_object;

    level_indicator.numberOfMajorTickMarks = number_of_major_tick_marks;
  }
}

static js_value_t *
bare_app_kit_level_indicator_tick_mark_position(js_env_t *env, js_callback_info_t *info) {
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
    NSLevelIndicator *level_indicator = (__bridge NSLevelIndicator *) handle;

    if (argc == 1) {
      err = js_create_int32(env, level_indicator.tickMarkPosition, &result);
      assert(err == 0);
    } else {
      int32_t tick_mark_position;
      if (!bare_app_kit__read_int32(env, argv[1], "tick_mark_position", &tick_mark_position)) return NULL;

      level_indicator.tickMarkPosition = tick_mark_position;
    }
  }

  return result;
}

static void
bare_app_kit_level_indicator_tick_mark_position_typed(js_value_t *receiver, int32_t bare_tag, int32_t tick_mark_position, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSLevelIndicator *level_indicator = (NSLevelIndicator *) bare_object;

    level_indicator.tickMarkPosition = tick_mark_position;
  }
}

static js_value_t *
bare_app_kit_level_indicator_editable(js_env_t *env, js_callback_info_t *info) {
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
    NSLevelIndicator *level_indicator = (__bridge NSLevelIndicator *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, level_indicator.editable, &result);
      assert(err == 0);
    } else {
      bool editable;
      if (!bare_app_kit__read_bool(env, argv[1], "editable", &editable)) return NULL;

      level_indicator.editable = editable;
    }
  }

  return result;
}

static void
bare_app_kit_level_indicator_editable_typed(js_value_t *receiver, int32_t bare_tag, bool editable, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSLevelIndicator *level_indicator = (NSLevelIndicator *) bare_object;

    level_indicator.editable = editable;
  }
}

static js_value_t *
bare_app_kit_level_indicator_tick_mark_value_at_index(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t index;
  if (!bare_app_kit__read_int32(env, argv[1], "index", &index)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSLevelIndicator *level_indicator = (__bridge NSLevelIndicator *) handle;

    err = js_create_double(env, [level_indicator tickMarkValueAtIndex:index], &result);
    assert(err == 0);
  }

  return result;
}
