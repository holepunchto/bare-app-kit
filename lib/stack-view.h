#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_stack_view_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

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
    NSStackView *handle = [[[NSStackView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_stack_view_orientation(js_env_t *env, js_callback_info_t *info) {
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
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, stack_view.orientation, &result);
      assert(err == 0);
    } else {
      int32_t orientation;
      if (!bare_app_kit__read_int32(env, argv[1], "orientation", &orientation)) return NULL;

      stack_view.orientation = orientation;
    }
  }

  return result;
}

static void
bare_app_kit_stack_view_orientation_typed(js_value_t *receiver, int32_t bare_tag, int32_t orientation, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStackView *stack_view = (NSStackView *) bare_object;

    stack_view.orientation = orientation;
  }
}

static js_value_t *
bare_app_kit_stack_view_alignment(js_env_t *env, js_callback_info_t *info) {
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
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, stack_view.alignment, &result);
      assert(err == 0);
    } else {
      int32_t alignment;
      if (!bare_app_kit__read_int32(env, argv[1], "alignment", &alignment)) return NULL;

      stack_view.alignment = alignment;
    }
  }

  return result;
}

static void
bare_app_kit_stack_view_alignment_typed(js_value_t *receiver, int32_t bare_tag, int32_t alignment, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStackView *stack_view = (NSStackView *) bare_object;

    stack_view.alignment = alignment;
  }
}

static js_value_t *
bare_app_kit_stack_view_distribution(js_env_t *env, js_callback_info_t *info) {
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
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, stack_view.distribution, &result);
      assert(err == 0);
    } else {
      int32_t distribution;
      if (!bare_app_kit__read_int32(env, argv[1], "distribution", &distribution)) return NULL;

      stack_view.distribution = distribution;
    }
  }

  return result;
}

static void
bare_app_kit_stack_view_distribution_typed(js_value_t *receiver, int32_t bare_tag, int32_t distribution, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStackView *stack_view = (NSStackView *) bare_object;

    stack_view.distribution = distribution;
  }
}

static js_value_t *
bare_app_kit_stack_view_spacing(js_env_t *env, js_callback_info_t *info) {
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
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    if (argc == 1) {
      err = js_create_double(env, stack_view.spacing, &result);
      assert(err == 0);
    } else {
      double spacing;
      if (!bare_app_kit__read_double(env, argv[1], "spacing", &spacing)) return NULL;

      stack_view.spacing = spacing;
    }
  }

  return result;
}

static void
bare_app_kit_stack_view_spacing_typed(js_value_t *receiver, int32_t bare_tag, double spacing, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStackView *stack_view = (NSStackView *) bare_object;

    stack_view.spacing = spacing;
  }
}

static js_value_t *
bare_app_kit_stack_view_edge_insets(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 5);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_insets(env, stack_view.edgeInsets);
    } else {
      double top;
      err = js_get_value_double(env, argv[1], &top);
      assert(err == 0);

      double left;
      err = js_get_value_double(env, argv[2], &left);
      assert(err == 0);

      double bottom;
      err = js_get_value_double(env, argv[3], &bottom);
      assert(err == 0);

      double right;
      err = js_get_value_double(env, argv[4], &right);
      assert(err == 0);

      stack_view.edgeInsets = NSEdgeInsetsMake(top, left, bottom, right);
    }
  }

  return result;
}

static void
bare_app_kit_stack_view_edge_insets_typed(js_value_t *receiver, int32_t bare_tag, double top, double left, double bottom, double right, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStackView *stack_view = (NSStackView *) bare_object;

    stack_view.edgeInsets = NSEdgeInsetsMake(top, left, bottom, right);
  }
}

static js_value_t *
bare_app_kit_stack_view_edge_insets_into(js_env_t *env, js_callback_info_t *info) {
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
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    __typeof__(stack_view.edgeInsets) value = stack_view.edgeInsets;

    out[0] = value.top;
    out[1] = value.left;
    out[2] = value.bottom;
    out[3] = value.right;
  }

  return NULL;
}

static void
bare_app_kit_stack_view_edge_insets_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSStackView *stack_view = (NSStackView *) bare_object;

    __typeof__(stack_view.edgeInsets) value = stack_view.edgeInsets;

    out[0] = value.top;
    out[1] = value.left;
    out[2] = value.bottom;
    out[3] = value.right;
  }
}

static js_value_t *
bare_app_kit_stack_view_detaches_hidden_views(js_env_t *env, js_callback_info_t *info) {
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
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, stack_view.detachesHiddenViews, &result);
      assert(err == 0);
    } else {
      bool detaches_hidden_views;
      if (!bare_app_kit__read_bool(env, argv[1], "detaches_hidden_views", &detaches_hidden_views)) return NULL;

      stack_view.detachesHiddenViews = detaches_hidden_views;
    }
  }

  return result;
}

static void
bare_app_kit_stack_view_detaches_hidden_views_typed(js_value_t *receiver, int32_t bare_tag, bool detaches_hidden_views, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSStackView *stack_view = (NSStackView *) bare_object;

    stack_view.detachesHiddenViews = detaches_hidden_views;
  }
}

static js_value_t *
bare_app_kit_stack_view_add_arranged_subview(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id view = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    [stack_view addArrangedSubview:view];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_stack_view_insert_arranged_subview(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id view = bare_foundation__to_object(env, argv[1]);

  int32_t index;
  if (!bare_app_kit__read_int32(env, argv[2], "index", &index)) return NULL;

  @autoreleasepool {
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    [stack_view insertArrangedSubview:view atIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_stack_view_remove_arranged_subview(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id view = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    [stack_view removeArrangedSubview:view];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_stack_view_remove_view(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id view = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    [stack_view removeView:view];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_stack_view_set_visibility_priority(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double priority;
  if (!bare_app_kit__read_double(env, argv[1], "priority", &priority)) return NULL;

  id view = bare_foundation__to_object(env, argv[2]);

  @autoreleasepool {
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    [stack_view setVisibilityPriority:priority forView:view];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_stack_view_set_custom_spacing(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double spacing;
  if (!bare_app_kit__read_double(env, argv[1], "spacing", &spacing)) return NULL;

  id view = bare_foundation__to_object(env, argv[2]);

  @autoreleasepool {
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    [stack_view setCustomSpacing:spacing afterView:view];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_stack_view_arranged_subviews(js_env_t *env, js_callback_info_t *info) {
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
    NSStackView *stack_view = (__bridge NSStackView *) handle;

    result = bare_app_kit__from_objects(env, stack_view.arrangedSubviews);
  }

  return result;
}
