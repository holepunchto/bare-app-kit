#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareSlider : NSSlider <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareSlider

- (int32_t)eventMask {
  return mask;
}

- (void)setEventMask:(int32_t)value {
  mask = value;
}

- (void)dealloc {
  int err;

  err = js_delete_reference(env, ctx);
  assert(err == 0);

  [super dealloc];
}

- (void)onChange:(id)sender {
  if (mask & (1 << 0)) bare_app_kit__emit(env, ctx, "_onchange");
}

@end

static js_value_t *
bare_app_kit_slider_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 5);

  double x;
  if (!bare_app_kit__read_double(env, argv[0], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[1], "y", &y)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[2], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[3], "height", &height)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    BareSlider *handle = [[[BareSlider alloc]
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
bare_app_kit_slider_min_value(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_create_double(env, slider.minValue, &result);
      assert(err == 0);
    } else {
      double min_value;
      if (!bare_app_kit__read_double(env, argv[1], "min_value", &min_value)) return NULL;

      slider.minValue = min_value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_max_value(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_create_double(env, slider.maxValue, &result);
      assert(err == 0);
    } else {
      double max_value;
      if (!bare_app_kit__read_double(env, argv[1], "max_value", &max_value)) return NULL;

      slider.maxValue = max_value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_alt_increment_value(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_create_double(env, slider.altIncrementValue, &result);
      assert(err == 0);
    } else {
      double alt_increment_value;
      if (!bare_app_kit__read_double(env, argv[1], "alt_increment_value", &alt_increment_value)) return NULL;

      slider.altIncrementValue = alt_increment_value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_knob_thickness(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    err = js_create_double(env, slider.knobThickness, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_vertical(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, slider.vertical, &result);
      assert(err == 0);
    } else {
      bool vertical;
      if (!bare_app_kit__read_bool(env, argv[1], "vertical", &vertical)) return NULL;

      slider.vertical = vertical;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_type(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_create_int32(env, slider.sliderType, &result);
      assert(err == 0);
    } else {
      int32_t slider_type;
      if (!bare_app_kit__read_int32(env, argv[1], "slider_type", &slider_type)) return NULL;

      slider.sliderType = slider_type;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_number_of_tick_marks(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_create_int64(env, slider.numberOfTickMarks, &result);
      assert(err == 0);
    } else {
      int64_t number_of_tick_marks;
      err = js_get_value_int64(env, argv[1], &number_of_tick_marks);
      assert(err == 0);

      slider.numberOfTickMarks = number_of_tick_marks;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_tick_mark_position(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_create_int32(env, slider.tickMarkPosition, &result);
      assert(err == 0);
    } else {
      int32_t tick_mark_position;
      if (!bare_app_kit__read_int32(env, argv[1], "tick_mark_position", &tick_mark_position)) return NULL;

      slider.tickMarkPosition = tick_mark_position;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_allows_tick_mark_values_only(js_env_t *env, js_callback_info_t *info) {
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
    NSSlider *slider = (__bridge NSSlider *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, slider.allowsTickMarkValuesOnly, &result);
      assert(err == 0);
    } else {
      bool allows_tick_mark_values_only;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_tick_mark_values_only", &allows_tick_mark_values_only)) return NULL;

      slider.allowsTickMarkValuesOnly = allows_tick_mark_values_only;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_tick_mark_value_at_index(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int64_t index;
  err = js_get_value_int64(env, argv[1], &index);
  assert(err == 0);

  js_value_t *result;

  @autoreleasepool {
    NSSlider *slider = (__bridge NSSlider *) handle;

    err = js_create_double(env, [slider tickMarkValueAtIndex:index], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_slider_closest_tick_mark_value_to_value(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double value;
  if (!bare_app_kit__read_double(env, argv[1], "value", &value)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSSlider *slider = (__bridge NSSlider *) handle;

    err = js_create_double(env, [slider closestTickMarkValueToValue:value], &result);
    assert(err == 0);
  }

  return result;
}
