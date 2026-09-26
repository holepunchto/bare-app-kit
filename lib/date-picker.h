#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareDatePicker : NSDatePicker <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareDatePicker

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
bare_app_kit_date_picker_init(js_env_t *env, js_callback_info_t *info) {
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
    BareDatePicker *handle = [[[BareDatePicker alloc]
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
bare_app_kit_date_picker_date_value(js_env_t *env, js_callback_info_t *info) {
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
    NSDatePicker *date_picker = (__bridge NSDatePicker *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_date(env, date_picker.dateValue);
    } else {
      date_picker.dateValue = bare_app_kit__to_date(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_date_picker_min_date(js_env_t *env, js_callback_info_t *info) {
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
    NSDatePicker *date_picker = (__bridge NSDatePicker *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_date(env, date_picker.minDate);
    } else {
      date_picker.minDate = bare_app_kit__to_date(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_date_picker_max_date(js_env_t *env, js_callback_info_t *info) {
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
    NSDatePicker *date_picker = (__bridge NSDatePicker *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_date(env, date_picker.maxDate);
    } else {
      date_picker.maxDate = bare_app_kit__to_date(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_date_picker_time_interval(js_env_t *env, js_callback_info_t *info) {
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
    NSDatePicker *date_picker = (__bridge NSDatePicker *) handle;

    if (argc == 1) {
      err = js_create_double(env, date_picker.timeInterval, &result);
      assert(err == 0);
    } else {
      double time_interval;
      if (!bare_app_kit__read_double(env, argv[1], "time_interval", &time_interval)) return NULL;

      date_picker.timeInterval = time_interval;
    }
  }

  return result;
}

static void
bare_app_kit_date_picker_time_interval_typed(js_value_t *receiver, int32_t bare_tag, double time_interval, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSDatePicker *date_picker = (NSDatePicker *) bare_object;

    date_picker.timeInterval = time_interval;
  }
}

static js_value_t *
bare_app_kit_date_picker_date_picker_style(js_env_t *env, js_callback_info_t *info) {
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
    NSDatePicker *date_picker = (__bridge NSDatePicker *) handle;

    if (argc == 1) {
      err = js_create_int32(env, date_picker.datePickerStyle, &result);
      assert(err == 0);
    } else {
      int32_t date_picker_style;
      if (!bare_app_kit__read_int32(env, argv[1], "date_picker_style", &date_picker_style)) return NULL;

      date_picker.datePickerStyle = date_picker_style;
    }
  }

  return result;
}

static void
bare_app_kit_date_picker_date_picker_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t date_picker_style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSDatePicker *date_picker = (NSDatePicker *) bare_object;

    date_picker.datePickerStyle = date_picker_style;
  }
}

static js_value_t *
bare_app_kit_date_picker_date_picker_mode(js_env_t *env, js_callback_info_t *info) {
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
    NSDatePicker *date_picker = (__bridge NSDatePicker *) handle;

    if (argc == 1) {
      err = js_create_int32(env, date_picker.datePickerMode, &result);
      assert(err == 0);
    } else {
      int32_t date_picker_mode;
      if (!bare_app_kit__read_int32(env, argv[1], "date_picker_mode", &date_picker_mode)) return NULL;

      date_picker.datePickerMode = date_picker_mode;
    }
  }

  return result;
}

static void
bare_app_kit_date_picker_date_picker_mode_typed(js_value_t *receiver, int32_t bare_tag, int32_t date_picker_mode, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSDatePicker *date_picker = (NSDatePicker *) bare_object;

    date_picker.datePickerMode = date_picker_mode;
  }
}

static js_value_t *
bare_app_kit_date_picker_date_picker_elements(js_env_t *env, js_callback_info_t *info) {
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
    NSDatePicker *date_picker = (__bridge NSDatePicker *) handle;

    if (argc == 1) {
      err = js_create_int32(env, date_picker.datePickerElements, &result);
      assert(err == 0);
    } else {
      int32_t date_picker_elements;
      if (!bare_app_kit__read_int32(env, argv[1], "date_picker_elements", &date_picker_elements)) return NULL;

      date_picker.datePickerElements = date_picker_elements;
    }
  }

  return result;
}

static void
bare_app_kit_date_picker_date_picker_elements_typed(js_value_t *receiver, int32_t bare_tag, int32_t date_picker_elements, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSDatePicker *date_picker = (NSDatePicker *) bare_object;

    date_picker.datePickerElements = date_picker_elements;
  }
}

static js_value_t *
bare_app_kit_date_picker_draws_background(js_env_t *env, js_callback_info_t *info) {
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
    NSDatePicker *date_picker = (__bridge NSDatePicker *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, date_picker.drawsBackground, &result);
      assert(err == 0);
    } else {
      bool draws_background;
      if (!bare_app_kit__read_bool(env, argv[1], "draws_background", &draws_background)) return NULL;

      date_picker.drawsBackground = draws_background;
    }
  }

  return result;
}

static void
bare_app_kit_date_picker_draws_background_typed(js_value_t *receiver, int32_t bare_tag, bool draws_background, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSDatePicker *date_picker = (NSDatePicker *) bare_object;

    date_picker.drawsBackground = draws_background;
  }
}

static js_value_t *
bare_app_kit_date_picker_bordered(js_env_t *env, js_callback_info_t *info) {
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
    NSDatePicker *date_picker = (__bridge NSDatePicker *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, date_picker.bordered, &result);
      assert(err == 0);
    } else {
      bool bordered;
      if (!bare_app_kit__read_bool(env, argv[1], "bordered", &bordered)) return NULL;

      date_picker.bordered = bordered;
    }
  }

  return result;
}

static void
bare_app_kit_date_picker_bordered_typed(js_value_t *receiver, int32_t bare_tag, bool bordered, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSDatePicker *date_picker = (NSDatePicker *) bare_object;

    date_picker.bordered = bordered;
  }
}

static js_value_t *
bare_app_kit_date_picker_bezeled(js_env_t *env, js_callback_info_t *info) {
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
    NSDatePicker *date_picker = (__bridge NSDatePicker *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, date_picker.bezeled, &result);
      assert(err == 0);
    } else {
      bool bezeled;
      if (!bare_app_kit__read_bool(env, argv[1], "bezeled", &bezeled)) return NULL;

      date_picker.bezeled = bezeled;
    }
  }

  return result;
}

static void
bare_app_kit_date_picker_bezeled_typed(js_value_t *receiver, int32_t bare_tag, bool bezeled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSDatePicker *date_picker = (NSDatePicker *) bare_object;

    date_picker.bezeled = bezeled;
  }
}

static js_value_t *
bare_app_kit_date_picker_text_color(js_env_t *env, js_callback_info_t *info) {
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
    NSDatePicker *date_picker = (__bridge NSDatePicker *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, date_picker.textColor);
    } else {
      date_picker.textColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}
