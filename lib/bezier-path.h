#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_bezier_path_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 0;
  js_value_t *argv[0];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    NSBezierPath *handle = [NSBezierPath bezierPath];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_bezier_path_line_width(js_env_t *env, js_callback_info_t *info) {
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
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    if (argc == 1) {
      err = js_create_double(env, bezier_path.lineWidth, &result);
      assert(err == 0);
    } else {
      double line_width;
      if (!bare_app_kit__read_double(env, argv[1], "line_width", &line_width)) return NULL;

      bezier_path.lineWidth = line_width;
    }
  }

  return result;
}

static void
bare_app_kit_bezier_path_line_width_typed(js_value_t *receiver, int32_t bare_tag, double line_width, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSBezierPath *bezier_path = (NSBezierPath *) bare_object;

    bezier_path.lineWidth = line_width;
  }
}

static js_value_t *
bare_app_kit_bezier_path_line_cap_style(js_env_t *env, js_callback_info_t *info) {
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
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    if (argc == 1) {
      err = js_create_int32(env, bezier_path.lineCapStyle, &result);
      assert(err == 0);
    } else {
      int32_t line_cap_style;
      if (!bare_app_kit__read_int32(env, argv[1], "line_cap_style", &line_cap_style)) return NULL;

      bezier_path.lineCapStyle = line_cap_style;
    }
  }

  return result;
}

static void
bare_app_kit_bezier_path_line_cap_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t line_cap_style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSBezierPath *bezier_path = (NSBezierPath *) bare_object;

    bezier_path.lineCapStyle = line_cap_style;
  }
}

static js_value_t *
bare_app_kit_bezier_path_line_join_style(js_env_t *env, js_callback_info_t *info) {
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
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    if (argc == 1) {
      err = js_create_int32(env, bezier_path.lineJoinStyle, &result);
      assert(err == 0);
    } else {
      int32_t line_join_style;
      if (!bare_app_kit__read_int32(env, argv[1], "line_join_style", &line_join_style)) return NULL;

      bezier_path.lineJoinStyle = line_join_style;
    }
  }

  return result;
}

static void
bare_app_kit_bezier_path_line_join_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t line_join_style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSBezierPath *bezier_path = (NSBezierPath *) bare_object;

    bezier_path.lineJoinStyle = line_join_style;
  }
}

static js_value_t *
bare_app_kit_bezier_path_winding_rule(js_env_t *env, js_callback_info_t *info) {
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
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    if (argc == 1) {
      err = js_create_int32(env, bezier_path.windingRule, &result);
      assert(err == 0);
    } else {
      int32_t winding_rule;
      if (!bare_app_kit__read_int32(env, argv[1], "winding_rule", &winding_rule)) return NULL;

      bezier_path.windingRule = winding_rule;
    }
  }

  return result;
}

static void
bare_app_kit_bezier_path_winding_rule_typed(js_value_t *receiver, int32_t bare_tag, int32_t winding_rule, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSBezierPath *bezier_path = (NSBezierPath *) bare_object;

    bezier_path.windingRule = winding_rule;
  }
}

static js_value_t *
bare_app_kit_bezier_path_miter_limit(js_env_t *env, js_callback_info_t *info) {
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
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    if (argc == 1) {
      err = js_create_double(env, bezier_path.miterLimit, &result);
      assert(err == 0);
    } else {
      double miter_limit;
      if (!bare_app_kit__read_double(env, argv[1], "miter_limit", &miter_limit)) return NULL;

      bezier_path.miterLimit = miter_limit;
    }
  }

  return result;
}

static void
bare_app_kit_bezier_path_miter_limit_typed(js_value_t *receiver, int32_t bare_tag, double miter_limit, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSBezierPath *bezier_path = (NSBezierPath *) bare_object;

    bezier_path.miterLimit = miter_limit;
  }
}

static js_value_t *
bare_app_kit_bezier_path_flatness(js_env_t *env, js_callback_info_t *info) {
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
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    if (argc == 1) {
      err = js_create_double(env, bezier_path.flatness, &result);
      assert(err == 0);
    } else {
      double flatness;
      if (!bare_app_kit__read_double(env, argv[1], "flatness", &flatness)) return NULL;

      bezier_path.flatness = flatness;
    }
  }

  return result;
}

static void
bare_app_kit_bezier_path_flatness_typed(js_value_t *receiver, int32_t bare_tag, double flatness, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSBezierPath *bezier_path = (NSBezierPath *) bare_object;

    bezier_path.flatness = flatness;
  }
}

static js_value_t *
bare_app_kit_bezier_path_empty(js_env_t *env, js_callback_info_t *info) {
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
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    err = js_get_boolean(env, bezier_path.empty, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_bezier_path_element_count(js_env_t *env, js_callback_info_t *info) {
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
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    err = js_create_int32(env, bezier_path.elementCount, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_bezier_path_bounds(js_env_t *env, js_callback_info_t *info) {
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
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    result = bare_app_kit__from_rect(env, bezier_path.bounds);
  }

  return result;
}

static js_value_t *
bare_app_kit_bezier_path_bounds_into(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  uint32_t offset;
  if (!bare_app_kit__read_uint32(env, argv[2], "offset", &offset)) return NULL;

  double *out;

  if (!bare_app_kit__buffer(env, argv[1], offset, 4, &out)) {
    err = js_throw_type_error(env, NULL, "Expected an array buffer with room for 4 doubles");
    assert(err == 0);

    return NULL;
  }

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    __typeof__(bezier_path.bounds) value = bezier_path.bounds;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }

  return NULL;
}

static void
bare_app_kit_bezier_path_bounds_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSBezierPath *bezier_path = (NSBezierPath *) bare_object;

    __typeof__(bezier_path.bounds) value = bezier_path.bounds;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }
}

static js_value_t *
bare_app_kit_bezier_path_control_point_bounds(js_env_t *env, js_callback_info_t *info) {
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
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    result = bare_app_kit__from_rect(env, bezier_path.controlPointBounds);
  }

  return result;
}

static js_value_t *
bare_app_kit_bezier_path_control_point_bounds_into(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  uint32_t offset;
  if (!bare_app_kit__read_uint32(env, argv[2], "offset", &offset)) return NULL;

  double *out;

  if (!bare_app_kit__buffer(env, argv[1], offset, 4, &out)) {
    err = js_throw_type_error(env, NULL, "Expected an array buffer with room for 4 doubles");
    assert(err == 0);

    return NULL;
  }

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    __typeof__(bezier_path.controlPointBounds) value = bezier_path.controlPointBounds;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }

  return NULL;
}

static void
bare_app_kit_bezier_path_control_point_bounds_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSBezierPath *bezier_path = (NSBezierPath *) bare_object;

    __typeof__(bezier_path.controlPointBounds) value = bezier_path.controlPointBounds;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }
}

static js_value_t *
bare_app_kit_bezier_path_current_point(js_env_t *env, js_callback_info_t *info) {
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
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    result = bare_app_kit__from_point(env, bezier_path.currentPoint);
  }

  return result;
}

static js_value_t *
bare_app_kit_bezier_path_current_point_into(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  uint32_t offset;
  if (!bare_app_kit__read_uint32(env, argv[2], "offset", &offset)) return NULL;

  double *out;

  if (!bare_app_kit__buffer(env, argv[1], offset, 2, &out)) {
    err = js_throw_type_error(env, NULL, "Expected an array buffer with room for 2 doubles");
    assert(err == 0);

    return NULL;
  }

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    __typeof__(bezier_path.currentPoint) value = bezier_path.currentPoint;

    out[0] = value.x;
    out[1] = value.y;
  }

  return NULL;
}

static void
bare_app_kit_bezier_path_current_point_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSBezierPath *bezier_path = (NSBezierPath *) bare_object;

    __typeof__(bezier_path.currentPoint) value = bezier_path.currentPoint;

    out[0] = value.x;
    out[1] = value.y;
  }
}

static js_value_t *
bare_app_kit_bezier_path_with_rect(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

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
    result = bare_foundation__bridge(env, [NSBezierPath bezierPathWithRect:NSMakeRect(x, y, width, height)]);
  }

  return result;
}

static js_value_t *
bare_app_kit_bezier_path_with_oval(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

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
    result = bare_foundation__bridge(env, [NSBezierPath bezierPathWithOvalInRect:NSMakeRect(x, y, width, height)]);
  }

  return result;
}

static js_value_t *
bare_app_kit_bezier_path_with_rounded_rect(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 6;
  js_value_t *argv[6];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 6);

  double x;
  if (!bare_app_kit__read_double(env, argv[0], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[1], "y", &y)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[2], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[3], "height", &height)) return NULL;

  double rx;
  if (!bare_app_kit__read_double(env, argv[4], "rx", &rx)) return NULL;

  double ry;
  if (!bare_app_kit__read_double(env, argv[5], "ry", &ry)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSBezierPath bezierPathWithRoundedRect:NSMakeRect(x, y, width, height) xRadius:rx yRadius:ry]);
  }

  return result;
}

static js_value_t *
bare_app_kit_bezier_path_move_to(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    [bezier_path moveToPoint:NSMakePoint(x, y)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_bezier_path_line_to(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    [bezier_path lineToPoint:NSMakePoint(x, y)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_bezier_path_curve_to(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 7;
  js_value_t *argv[7];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 7);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  double x1;
  if (!bare_app_kit__read_double(env, argv[3], "x1", &x1)) return NULL;

  double y1;
  if (!bare_app_kit__read_double(env, argv[4], "y1", &y1)) return NULL;

  double x2;
  if (!bare_app_kit__read_double(env, argv[5], "x2", &x2)) return NULL;

  double y2;
  if (!bare_app_kit__read_double(env, argv[6], "y2", &y2)) return NULL;

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    [bezier_path curveToPoint:NSMakePoint(x, y) controlPoint1:NSMakePoint(x1, y1) controlPoint2:NSMakePoint(x2, y2)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_bezier_path_close_path(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    [bezier_path closePath];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_bezier_path_remove_all_points(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    [bezier_path removeAllPoints];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_bezier_path_append_rect(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 5);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[3], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[4], "height", &height)) return NULL;

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    [bezier_path appendBezierPathWithRect:NSMakeRect(x, y, width, height)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_bezier_path_append_oval(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 5);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[3], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[4], "height", &height)) return NULL;

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    [bezier_path appendBezierPathWithOvalInRect:NSMakeRect(x, y, width, height)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_bezier_path_append(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id other = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    [bezier_path appendBezierPath:other];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_bezier_path_stroke(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    [bezier_path stroke];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_bezier_path_fill(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    [bezier_path fill];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_bezier_path_add_clip(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    [bezier_path addClip];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_bezier_path_set_clip(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    [bezier_path setClip];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_bezier_path_contains_point(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSBezierPath *bezier_path = (__bridge NSBezierPath *) handle;

    err = js_get_boolean(env, [bezier_path containsPoint:NSMakePoint(x, y)], &result);
    assert(err == 0);
  }

  return result;
}
