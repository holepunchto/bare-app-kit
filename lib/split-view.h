#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_split_view_init(js_env_t *env, js_callback_info_t *info) {
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
    NSSplitView *handle = [[[NSSplitView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_split_view_vertical(js_env_t *env, js_callback_info_t *info) {
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
    NSSplitView *split_view = (__bridge NSSplitView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, split_view.vertical, &result);
      assert(err == 0);
    } else {
      bool vertical;
      if (!bare_app_kit__read_bool(env, argv[1], "vertical", &vertical)) return NULL;

      split_view.vertical = vertical;
    }
  }

  return result;
}

static void
bare_app_kit_split_view_vertical_typed(js_value_t *receiver, int32_t bare_tag, bool vertical, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSplitView *split_view = (NSSplitView *) bare_object;

    split_view.vertical = vertical;
  }
}

static js_value_t *
bare_app_kit_split_view_divider_style(js_env_t *env, js_callback_info_t *info) {
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
    NSSplitView *split_view = (__bridge NSSplitView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, split_view.dividerStyle, &result);
      assert(err == 0);
    } else {
      int32_t divider_style;
      if (!bare_app_kit__read_int32(env, argv[1], "divider_style", &divider_style)) return NULL;

      split_view.dividerStyle = divider_style;
    }
  }

  return result;
}

static void
bare_app_kit_split_view_divider_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t divider_style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSplitView *split_view = (NSSplitView *) bare_object;

    split_view.dividerStyle = divider_style;
  }
}

static js_value_t *
bare_app_kit_split_view_arranges_all_subviews(js_env_t *env, js_callback_info_t *info) {
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
    NSSplitView *split_view = (__bridge NSSplitView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, split_view.arrangesAllSubviews, &result);
      assert(err == 0);
    } else {
      bool arranges_all_subviews;
      if (!bare_app_kit__read_bool(env, argv[1], "arranges_all_subviews", &arranges_all_subviews)) return NULL;

      split_view.arrangesAllSubviews = arranges_all_subviews;
    }
  }

  return result;
}

static void
bare_app_kit_split_view_arranges_all_subviews_typed(js_value_t *receiver, int32_t bare_tag, bool arranges_all_subviews, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSplitView *split_view = (NSSplitView *) bare_object;

    split_view.arrangesAllSubviews = arranges_all_subviews;
  }
}

static js_value_t *
bare_app_kit_split_view_divider_thickness(js_env_t *env, js_callback_info_t *info) {
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
    NSSplitView *split_view = (__bridge NSSplitView *) handle;

    err = js_create_double(env, split_view.dividerThickness, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_split_view_add_arranged_subview(js_env_t *env, js_callback_info_t *info) {
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
    NSSplitView *split_view = (__bridge NSSplitView *) handle;

    [split_view addArrangedSubview:view];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_split_view_insert_arranged_subview(js_env_t *env, js_callback_info_t *info) {
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
    NSSplitView *split_view = (__bridge NSSplitView *) handle;

    [split_view insertArrangedSubview:view atIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_split_view_remove_arranged_subview(js_env_t *env, js_callback_info_t *info) {
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
    NSSplitView *split_view = (__bridge NSSplitView *) handle;

    [split_view removeArrangedSubview:view];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_split_view_set_position(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double position;
  if (!bare_app_kit__read_double(env, argv[1], "position", &position)) return NULL;

  int32_t divider;
  if (!bare_app_kit__read_int32(env, argv[2], "divider", &divider)) return NULL;

  @autoreleasepool {
    NSSplitView *split_view = (__bridge NSSplitView *) handle;

    [split_view setPosition:position ofDividerAtIndex:divider];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_split_view_set_holding_priority(js_env_t *env, js_callback_info_t *info) {
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

  int32_t index;
  if (!bare_app_kit__read_int32(env, argv[2], "index", &index)) return NULL;

  @autoreleasepool {
    NSSplitView *split_view = (__bridge NSSplitView *) handle;

    [split_view setHoldingPriority:priority forSubviewAtIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_split_view_holding_priority_for_subview_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSSplitView *split_view = (__bridge NSSplitView *) handle;

    err = js_create_double(env, [split_view holdingPriorityForSubviewAtIndex:index], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_split_view_adjust_subviews(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSSplitView *split_view = (__bridge NSSplitView *) handle;

    [split_view adjustSubviews];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_split_view_arranged_subviews(js_env_t *env, js_callback_info_t *info) {
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
    NSSplitView *split_view = (__bridge NSSplitView *) handle;

    result = bare_app_kit__from_objects(env, split_view.arrangedSubviews);
  }

  return result;
}
