#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareSegmentedControl : NSSegmentedControl <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareSegmentedControl

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
bare_app_kit_segmented_control_init(js_env_t *env, js_callback_info_t *info) {
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
    BareSegmentedControl *handle = [[[BareSegmentedControl alloc]
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
bare_app_kit_segmented_control_segment_count(js_env_t *env, js_callback_info_t *info) {
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
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    if (argc == 1) {
      err = js_create_int32(env, segmented_control.segmentCount, &result);
      assert(err == 0);
    } else {
      int32_t segment_count;
      if (!bare_app_kit__read_int32(env, argv[1], "segment_count", &segment_count)) return NULL;

      segmented_control.segmentCount = segment_count;
    }
  }

  return result;
}

static void
bare_app_kit_segmented_control_segment_count_typed(js_value_t *receiver, int32_t bare_tag, int32_t segment_count, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (NSSegmentedControl *) bare_object;

    segmented_control.segmentCount = segment_count;
  }
}

static js_value_t *
bare_app_kit_segmented_control_selected_segment(js_env_t *env, js_callback_info_t *info) {
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
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    if (argc == 1) {
      err = js_create_int32(env, segmented_control.selectedSegment, &result);
      assert(err == 0);
    } else {
      int32_t selected_segment;
      if (!bare_app_kit__read_int32(env, argv[1], "selected_segment", &selected_segment)) return NULL;

      segmented_control.selectedSegment = selected_segment;
    }
  }

  return result;
}

static void
bare_app_kit_segmented_control_selected_segment_typed(js_value_t *receiver, int32_t bare_tag, int32_t selected_segment, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (NSSegmentedControl *) bare_object;

    segmented_control.selectedSegment = selected_segment;
  }
}

static js_value_t *
bare_app_kit_segmented_control_segment_style(js_env_t *env, js_callback_info_t *info) {
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
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    if (argc == 1) {
      err = js_create_int32(env, segmented_control.segmentStyle, &result);
      assert(err == 0);
    } else {
      int32_t segment_style;
      if (!bare_app_kit__read_int32(env, argv[1], "segment_style", &segment_style)) return NULL;

      segmented_control.segmentStyle = segment_style;
    }
  }

  return result;
}

static void
bare_app_kit_segmented_control_segment_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t segment_style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (NSSegmentedControl *) bare_object;

    segmented_control.segmentStyle = segment_style;
  }
}

static js_value_t *
bare_app_kit_segmented_control_tracking_mode(js_env_t *env, js_callback_info_t *info) {
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
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    if (argc == 1) {
      err = js_create_int32(env, segmented_control.trackingMode, &result);
      assert(err == 0);
    } else {
      int32_t tracking_mode;
      if (!bare_app_kit__read_int32(env, argv[1], "tracking_mode", &tracking_mode)) return NULL;

      segmented_control.trackingMode = tracking_mode;
    }
  }

  return result;
}

static void
bare_app_kit_segmented_control_tracking_mode_typed(js_value_t *receiver, int32_t bare_tag, int32_t tracking_mode, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (NSSegmentedControl *) bare_object;

    segmented_control.trackingMode = tracking_mode;
  }
}

static js_value_t *
bare_app_kit_segmented_control_segment_distribution(js_env_t *env, js_callback_info_t *info) {
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
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    if (argc == 1) {
      err = js_create_int32(env, segmented_control.segmentDistribution, &result);
      assert(err == 0);
    } else {
      int32_t segment_distribution;
      if (!bare_app_kit__read_int32(env, argv[1], "segment_distribution", &segment_distribution)) return NULL;

      segmented_control.segmentDistribution = segment_distribution;
    }
  }

  return result;
}

static void
bare_app_kit_segmented_control_segment_distribution_typed(js_value_t *receiver, int32_t bare_tag, int32_t segment_distribution, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (NSSegmentedControl *) bare_object;

    segmented_control.segmentDistribution = segment_distribution;
  }
}

static js_value_t *
bare_app_kit_segmented_control_set_label_for_segment(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *label = bare_app_kit__to_string(env, argv[1]);

  int32_t segment;
  if (!bare_app_kit__read_int32(env, argv[2], "segment", &segment)) return NULL;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    [segmented_control setLabel:label forSegment:segment];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_segmented_control_label_for_segment(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t segment;
  if (!bare_app_kit__read_int32(env, argv[1], "segment", &segment)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    result = bare_app_kit__from_string(env, [segmented_control labelForSegment:segment]);
  }

  return result;
}

static js_value_t *
bare_app_kit_segmented_control_set_width_for_segment(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[1], "width", &width)) return NULL;

  int32_t segment;
  if (!bare_app_kit__read_int32(env, argv[2], "segment", &segment)) return NULL;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    [segmented_control setWidth:width forSegment:segment];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_segmented_control_width_for_segment(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t segment;
  if (!bare_app_kit__read_int32(env, argv[1], "segment", &segment)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    err = js_create_double(env, [segmented_control widthForSegment:segment], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_segmented_control_set_selected_for_segment(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  bool selected;
  if (!bare_app_kit__read_bool(env, argv[1], "selected", &selected)) return NULL;

  int32_t segment;
  if (!bare_app_kit__read_int32(env, argv[2], "segment", &segment)) return NULL;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    [segmented_control setSelected:selected forSegment:segment];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_segmented_control_selected_for_segment(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t segment;
  if (!bare_app_kit__read_int32(env, argv[1], "segment", &segment)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    err = js_get_boolean(env, [segmented_control isSelectedForSegment:segment], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_segmented_control_set_enabled_for_segment(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  bool enabled;
  if (!bare_app_kit__read_bool(env, argv[1], "enabled", &enabled)) return NULL;

  int32_t segment;
  if (!bare_app_kit__read_int32(env, argv[2], "segment", &segment)) return NULL;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    [segmented_control setEnabled:enabled forSegment:segment];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_segmented_control_enabled_for_segment(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t segment;
  if (!bare_app_kit__read_int32(env, argv[1], "segment", &segment)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    err = js_get_boolean(env, [segmented_control isEnabledForSegment:segment], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_segmented_control_set_tool_tip_for_segment(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *tool_tip = bare_app_kit__to_string(env, argv[1]);

  int32_t segment;
  if (!bare_app_kit__read_int32(env, argv[2], "segment", &segment)) return NULL;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    [segmented_control setToolTip:tool_tip forSegment:segment];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_segmented_control_tool_tip_for_segment(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t segment;
  if (!bare_app_kit__read_int32(env, argv[1], "segment", &segment)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    result = bare_app_kit__from_string(env, [segmented_control toolTipForSegment:segment]);
  }

  return result;
}

static js_value_t *
bare_app_kit_segmented_control_set_tag_for_segment(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t tag;
  if (!bare_app_kit__read_int32(env, argv[1], "tag", &tag)) return NULL;

  int32_t segment;
  if (!bare_app_kit__read_int32(env, argv[2], "segment", &segment)) return NULL;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    [segmented_control setTag:tag forSegment:segment];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_segmented_control_tag_for_segment(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t segment;
  if (!bare_app_kit__read_int32(env, argv[1], "segment", &segment)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSSegmentedControl *segmented_control = (__bridge NSSegmentedControl *) handle;

    err = js_create_int32(env, [segmented_control tagForSegment:segment], &result);
    assert(err == 0);
  }

  return result;
}
