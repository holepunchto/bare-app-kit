#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_grid_column_number_of_cells(js_env_t *env, js_callback_info_t *info) {
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
    NSGridColumn *grid_column = (__bridge NSGridColumn *) handle;

    err = js_create_int32(env, grid_column.numberOfCells, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_column_width(js_env_t *env, js_callback_info_t *info) {
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
    NSGridColumn *grid_column = (__bridge NSGridColumn *) handle;

    if (argc == 1) {
      err = js_create_double(env, grid_column.width, &result);
      assert(err == 0);
    } else {
      double width;
      if (!bare_app_kit__read_double(env, argv[1], "width", &width)) return NULL;

      grid_column.width = width;
    }
  }

  return result;
}

static void
bare_app_kit_grid_column_width_typed(js_value_t *receiver, int32_t bare_tag, double width, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridColumn *grid_column = (NSGridColumn *) bare_object;

    grid_column.width = width;
  }
}

static js_value_t *
bare_app_kit_grid_column_leading_padding(js_env_t *env, js_callback_info_t *info) {
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
    NSGridColumn *grid_column = (__bridge NSGridColumn *) handle;

    if (argc == 1) {
      err = js_create_double(env, grid_column.leadingPadding, &result);
      assert(err == 0);
    } else {
      double leading_padding;
      if (!bare_app_kit__read_double(env, argv[1], "leading_padding", &leading_padding)) return NULL;

      grid_column.leadingPadding = leading_padding;
    }
  }

  return result;
}

static void
bare_app_kit_grid_column_leading_padding_typed(js_value_t *receiver, int32_t bare_tag, double leading_padding, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridColumn *grid_column = (NSGridColumn *) bare_object;

    grid_column.leadingPadding = leading_padding;
  }
}

static js_value_t *
bare_app_kit_grid_column_trailing_padding(js_env_t *env, js_callback_info_t *info) {
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
    NSGridColumn *grid_column = (__bridge NSGridColumn *) handle;

    if (argc == 1) {
      err = js_create_double(env, grid_column.trailingPadding, &result);
      assert(err == 0);
    } else {
      double trailing_padding;
      if (!bare_app_kit__read_double(env, argv[1], "trailing_padding", &trailing_padding)) return NULL;

      grid_column.trailingPadding = trailing_padding;
    }
  }

  return result;
}

static void
bare_app_kit_grid_column_trailing_padding_typed(js_value_t *receiver, int32_t bare_tag, double trailing_padding, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridColumn *grid_column = (NSGridColumn *) bare_object;

    grid_column.trailingPadding = trailing_padding;
  }
}

static js_value_t *
bare_app_kit_grid_column_x_placement(js_env_t *env, js_callback_info_t *info) {
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
    NSGridColumn *grid_column = (__bridge NSGridColumn *) handle;

    if (argc == 1) {
      err = js_create_int32(env, grid_column.xPlacement, &result);
      assert(err == 0);
    } else {
      int32_t x_placement;
      if (!bare_app_kit__read_int32(env, argv[1], "x_placement", &x_placement)) return NULL;

      grid_column.xPlacement = x_placement;
    }
  }

  return result;
}

static void
bare_app_kit_grid_column_x_placement_typed(js_value_t *receiver, int32_t bare_tag, int32_t x_placement, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridColumn *grid_column = (NSGridColumn *) bare_object;

    grid_column.xPlacement = x_placement;
  }
}

static js_value_t *
bare_app_kit_grid_column_hidden(js_env_t *env, js_callback_info_t *info) {
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
    NSGridColumn *grid_column = (__bridge NSGridColumn *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, grid_column.hidden, &result);
      assert(err == 0);
    } else {
      bool hidden;
      if (!bare_app_kit__read_bool(env, argv[1], "hidden", &hidden)) return NULL;

      grid_column.hidden = hidden;
    }
  }

  return result;
}

static void
bare_app_kit_grid_column_hidden_typed(js_value_t *receiver, int32_t bare_tag, bool hidden, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridColumn *grid_column = (NSGridColumn *) bare_object;

    grid_column.hidden = hidden;
  }
}

static js_value_t *
bare_app_kit_grid_column_cell_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSGridColumn *grid_column = (__bridge NSGridColumn *) handle;

    result = bare_foundation__bridge(env, [grid_column cellAtIndex:index]);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_column_merge_cells(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t index;
  if (!bare_app_kit__read_int32(env, argv[1], "index", &index)) return NULL;

  int32_t count;
  if (!bare_app_kit__read_int32(env, argv[2], "count", &count)) return NULL;

  @autoreleasepool {
    NSGridColumn *grid_column = (__bridge NSGridColumn *) handle;

    [grid_column mergeCellsInRange:NSMakeRange(index, count)];
  }

  return NULL;
}
