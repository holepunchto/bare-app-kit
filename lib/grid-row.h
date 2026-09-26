#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_grid_row_number_of_cells(js_env_t *env, js_callback_info_t *info) {
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
    NSGridRow *grid_row = (__bridge NSGridRow *) handle;

    err = js_create_int32(env, grid_row.numberOfCells, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_row_height(js_env_t *env, js_callback_info_t *info) {
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
    NSGridRow *grid_row = (__bridge NSGridRow *) handle;

    if (argc == 1) {
      err = js_create_double(env, grid_row.height, &result);
      assert(err == 0);
    } else {
      double height;
      if (!bare_app_kit__read_double(env, argv[1], "height", &height)) return NULL;

      grid_row.height = height;
    }
  }

  return result;
}

static void
bare_app_kit_grid_row_height_typed(js_value_t *receiver, int32_t bare_tag, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridRow *grid_row = (NSGridRow *) bare_object;

    grid_row.height = height;
  }
}

static js_value_t *
bare_app_kit_grid_row_top_padding(js_env_t *env, js_callback_info_t *info) {
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
    NSGridRow *grid_row = (__bridge NSGridRow *) handle;

    if (argc == 1) {
      err = js_create_double(env, grid_row.topPadding, &result);
      assert(err == 0);
    } else {
      double top_padding;
      if (!bare_app_kit__read_double(env, argv[1], "top_padding", &top_padding)) return NULL;

      grid_row.topPadding = top_padding;
    }
  }

  return result;
}

static void
bare_app_kit_grid_row_top_padding_typed(js_value_t *receiver, int32_t bare_tag, double top_padding, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridRow *grid_row = (NSGridRow *) bare_object;

    grid_row.topPadding = top_padding;
  }
}

static js_value_t *
bare_app_kit_grid_row_bottom_padding(js_env_t *env, js_callback_info_t *info) {
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
    NSGridRow *grid_row = (__bridge NSGridRow *) handle;

    if (argc == 1) {
      err = js_create_double(env, grid_row.bottomPadding, &result);
      assert(err == 0);
    } else {
      double bottom_padding;
      if (!bare_app_kit__read_double(env, argv[1], "bottom_padding", &bottom_padding)) return NULL;

      grid_row.bottomPadding = bottom_padding;
    }
  }

  return result;
}

static void
bare_app_kit_grid_row_bottom_padding_typed(js_value_t *receiver, int32_t bare_tag, double bottom_padding, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridRow *grid_row = (NSGridRow *) bare_object;

    grid_row.bottomPadding = bottom_padding;
  }
}

static js_value_t *
bare_app_kit_grid_row_y_placement(js_env_t *env, js_callback_info_t *info) {
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
    NSGridRow *grid_row = (__bridge NSGridRow *) handle;

    if (argc == 1) {
      err = js_create_int32(env, grid_row.yPlacement, &result);
      assert(err == 0);
    } else {
      int32_t y_placement;
      if (!bare_app_kit__read_int32(env, argv[1], "y_placement", &y_placement)) return NULL;

      grid_row.yPlacement = y_placement;
    }
  }

  return result;
}

static void
bare_app_kit_grid_row_y_placement_typed(js_value_t *receiver, int32_t bare_tag, int32_t y_placement, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridRow *grid_row = (NSGridRow *) bare_object;

    grid_row.yPlacement = y_placement;
  }
}

static js_value_t *
bare_app_kit_grid_row_row_alignment(js_env_t *env, js_callback_info_t *info) {
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
    NSGridRow *grid_row = (__bridge NSGridRow *) handle;

    if (argc == 1) {
      err = js_create_int32(env, grid_row.rowAlignment, &result);
      assert(err == 0);
    } else {
      int32_t row_alignment;
      if (!bare_app_kit__read_int32(env, argv[1], "row_alignment", &row_alignment)) return NULL;

      grid_row.rowAlignment = row_alignment;
    }
  }

  return result;
}

static void
bare_app_kit_grid_row_row_alignment_typed(js_value_t *receiver, int32_t bare_tag, int32_t row_alignment, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridRow *grid_row = (NSGridRow *) bare_object;

    grid_row.rowAlignment = row_alignment;
  }
}

static js_value_t *
bare_app_kit_grid_row_hidden(js_env_t *env, js_callback_info_t *info) {
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
    NSGridRow *grid_row = (__bridge NSGridRow *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, grid_row.hidden, &result);
      assert(err == 0);
    } else {
      bool hidden;
      if (!bare_app_kit__read_bool(env, argv[1], "hidden", &hidden)) return NULL;

      grid_row.hidden = hidden;
    }
  }

  return result;
}

static void
bare_app_kit_grid_row_hidden_typed(js_value_t *receiver, int32_t bare_tag, bool hidden, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridRow *grid_row = (NSGridRow *) bare_object;

    grid_row.hidden = hidden;
  }
}

static js_value_t *
bare_app_kit_grid_row_cell_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSGridRow *grid_row = (__bridge NSGridRow *) handle;

    result = bare_foundation__bridge(env, [grid_row cellAtIndex:index]);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_row_merge_cells(js_env_t *env, js_callback_info_t *info) {
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
    NSGridRow *grid_row = (__bridge NSGridRow *) handle;

    [grid_row mergeCellsInRange:NSMakeRange(index, count)];
  }

  return NULL;
}
