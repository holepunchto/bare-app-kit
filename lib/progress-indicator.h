#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareProgressIndicator : NSProgressIndicator <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareProgressIndicator

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

BARE_APP_KIT_REPORTS_WILL_DRAW(1 << 0)

@end

static js_value_t *
bare_app_kit_progress_indicator_init(js_env_t *env, js_callback_info_t *info) {
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
    BareProgressIndicator *handle = [[[BareProgressIndicator alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_progress_indicator_min_value(js_env_t *env, js_callback_info_t *info) {
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
    NSProgressIndicator *progress_indicator = (__bridge NSProgressIndicator *) handle;

    if (argc == 1) {
      err = js_create_double(env, progress_indicator.minValue, &result);
      assert(err == 0);
    } else {
      double min_value;
      if (!bare_app_kit__read_double(env, argv[1], "min_value", &min_value)) return NULL;

      progress_indicator.minValue = min_value;
    }
  }

  return result;
}

static void
bare_app_kit_progress_indicator_min_value_typed(js_value_t *receiver, int32_t bare_tag, double min_value, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSProgressIndicator *progress_indicator = (NSProgressIndicator *) bare_object;

    progress_indicator.minValue = min_value;
  }
}

static js_value_t *
bare_app_kit_progress_indicator_max_value(js_env_t *env, js_callback_info_t *info) {
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
    NSProgressIndicator *progress_indicator = (__bridge NSProgressIndicator *) handle;

    if (argc == 1) {
      err = js_create_double(env, progress_indicator.maxValue, &result);
      assert(err == 0);
    } else {
      double max_value;
      if (!bare_app_kit__read_double(env, argv[1], "max_value", &max_value)) return NULL;

      progress_indicator.maxValue = max_value;
    }
  }

  return result;
}

static void
bare_app_kit_progress_indicator_max_value_typed(js_value_t *receiver, int32_t bare_tag, double max_value, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSProgressIndicator *progress_indicator = (NSProgressIndicator *) bare_object;

    progress_indicator.maxValue = max_value;
  }
}

static js_value_t *
bare_app_kit_progress_indicator_double_value(js_env_t *env, js_callback_info_t *info) {
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
    NSProgressIndicator *progress_indicator = (__bridge NSProgressIndicator *) handle;

    if (argc == 1) {
      err = js_create_double(env, progress_indicator.doubleValue, &result);
      assert(err == 0);
    } else {
      double double_value;
      if (!bare_app_kit__read_double(env, argv[1], "double_value", &double_value)) return NULL;

      progress_indicator.doubleValue = double_value;
    }
  }

  return result;
}

static void
bare_app_kit_progress_indicator_double_value_typed(js_value_t *receiver, int32_t bare_tag, double double_value, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSProgressIndicator *progress_indicator = (NSProgressIndicator *) bare_object;

    progress_indicator.doubleValue = double_value;
  }
}

static js_value_t *
bare_app_kit_progress_indicator_indeterminate(js_env_t *env, js_callback_info_t *info) {
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
    NSProgressIndicator *progress_indicator = (__bridge NSProgressIndicator *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, progress_indicator.indeterminate, &result);
      assert(err == 0);
    } else {
      bool indeterminate;
      if (!bare_app_kit__read_bool(env, argv[1], "indeterminate", &indeterminate)) return NULL;

      progress_indicator.indeterminate = indeterminate;
    }
  }

  return result;
}

static void
bare_app_kit_progress_indicator_indeterminate_typed(js_value_t *receiver, int32_t bare_tag, bool indeterminate, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSProgressIndicator *progress_indicator = (NSProgressIndicator *) bare_object;

    progress_indicator.indeterminate = indeterminate;
  }
}

static js_value_t *
bare_app_kit_progress_indicator_style(js_env_t *env, js_callback_info_t *info) {
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
    NSProgressIndicator *progress_indicator = (__bridge NSProgressIndicator *) handle;

    if (argc == 1) {
      err = js_create_int32(env, progress_indicator.style, &result);
      assert(err == 0);
    } else {
      int32_t style;
      if (!bare_app_kit__read_int32(env, argv[1], "style", &style)) return NULL;

      progress_indicator.style = style;
    }
  }

  return result;
}

static void
bare_app_kit_progress_indicator_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSProgressIndicator *progress_indicator = (NSProgressIndicator *) bare_object;

    progress_indicator.style = style;
  }
}

static js_value_t *
bare_app_kit_progress_indicator_control_size(js_env_t *env, js_callback_info_t *info) {
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
    NSProgressIndicator *progress_indicator = (__bridge NSProgressIndicator *) handle;

    if (argc == 1) {
      err = js_create_int32(env, progress_indicator.controlSize, &result);
      assert(err == 0);
    } else {
      int32_t control_size;
      if (!bare_app_kit__read_int32(env, argv[1], "control_size", &control_size)) return NULL;

      progress_indicator.controlSize = control_size;
    }
  }

  return result;
}

static void
bare_app_kit_progress_indicator_control_size_typed(js_value_t *receiver, int32_t bare_tag, int32_t control_size, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSProgressIndicator *progress_indicator = (NSProgressIndicator *) bare_object;

    progress_indicator.controlSize = control_size;
  }
}

static js_value_t *
bare_app_kit_progress_indicator_uses_threaded_animation(js_env_t *env, js_callback_info_t *info) {
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
    NSProgressIndicator *progress_indicator = (__bridge NSProgressIndicator *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, progress_indicator.usesThreadedAnimation, &result);
      assert(err == 0);
    } else {
      bool uses_threaded_animation;
      if (!bare_app_kit__read_bool(env, argv[1], "uses_threaded_animation", &uses_threaded_animation)) return NULL;

      progress_indicator.usesThreadedAnimation = uses_threaded_animation;
    }
  }

  return result;
}

static void
bare_app_kit_progress_indicator_uses_threaded_animation_typed(js_value_t *receiver, int32_t bare_tag, bool uses_threaded_animation, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSProgressIndicator *progress_indicator = (NSProgressIndicator *) bare_object;

    progress_indicator.usesThreadedAnimation = uses_threaded_animation;
  }
}

static js_value_t *
bare_app_kit_progress_indicator_displayed_when_stopped(js_env_t *env, js_callback_info_t *info) {
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
    NSProgressIndicator *progress_indicator = (__bridge NSProgressIndicator *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, progress_indicator.displayedWhenStopped, &result);
      assert(err == 0);
    } else {
      bool displayed_when_stopped;
      if (!bare_app_kit__read_bool(env, argv[1], "displayed_when_stopped", &displayed_when_stopped)) return NULL;

      progress_indicator.displayedWhenStopped = displayed_when_stopped;
    }
  }

  return result;
}

static void
bare_app_kit_progress_indicator_displayed_when_stopped_typed(js_value_t *receiver, int32_t bare_tag, bool displayed_when_stopped, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSProgressIndicator *progress_indicator = (NSProgressIndicator *) bare_object;

    progress_indicator.displayedWhenStopped = displayed_when_stopped;
  }
}

static js_value_t *
bare_app_kit_progress_indicator_start_animation(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSProgressIndicator *progress_indicator = (__bridge NSProgressIndicator *) handle;

    [progress_indicator startAnimation:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_progress_indicator_stop_animation(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSProgressIndicator *progress_indicator = (__bridge NSProgressIndicator *) handle;

    [progress_indicator stopAnimation:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_progress_indicator_increment_by(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double delta;
  if (!bare_app_kit__read_double(env, argv[1], "delta", &delta)) return NULL;

  @autoreleasepool {
    NSProgressIndicator *progress_indicator = (__bridge NSProgressIndicator *) handle;

    [progress_indicator incrementBy:delta];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_progress_indicator_size_to_fit(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSProgressIndicator *progress_indicator = (__bridge NSProgressIndicator *) handle;

    [progress_indicator sizeToFit];
  }

  return NULL;
}
