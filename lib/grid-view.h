#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_grid_view_init(js_env_t *env, js_callback_info_t *info) {
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
    NSGridView *handle = [[[NSGridView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_view_number_of_rows(js_env_t *env, js_callback_info_t *info) {
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
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    err = js_create_int32(env, grid_view.numberOfRows, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_view_number_of_columns(js_env_t *env, js_callback_info_t *info) {
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
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    err = js_create_int32(env, grid_view.numberOfColumns, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_view_row_spacing(js_env_t *env, js_callback_info_t *info) {
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
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    if (argc == 1) {
      err = js_create_double(env, grid_view.rowSpacing, &result);
      assert(err == 0);
    } else {
      double row_spacing;
      if (!bare_app_kit__read_double(env, argv[1], "row_spacing", &row_spacing)) return NULL;

      grid_view.rowSpacing = row_spacing;
    }
  }

  return result;
}

static void
bare_app_kit_grid_view_row_spacing_typed(js_value_t *receiver, int32_t bare_tag, double row_spacing, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridView *grid_view = (NSGridView *) bare_object;

    grid_view.rowSpacing = row_spacing;
  }
}

static js_value_t *
bare_app_kit_grid_view_column_spacing(js_env_t *env, js_callback_info_t *info) {
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
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    if (argc == 1) {
      err = js_create_double(env, grid_view.columnSpacing, &result);
      assert(err == 0);
    } else {
      double column_spacing;
      if (!bare_app_kit__read_double(env, argv[1], "column_spacing", &column_spacing)) return NULL;

      grid_view.columnSpacing = column_spacing;
    }
  }

  return result;
}

static void
bare_app_kit_grid_view_column_spacing_typed(js_value_t *receiver, int32_t bare_tag, double column_spacing, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridView *grid_view = (NSGridView *) bare_object;

    grid_view.columnSpacing = column_spacing;
  }
}

static js_value_t *
bare_app_kit_grid_view_x_placement(js_env_t *env, js_callback_info_t *info) {
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
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, grid_view.xPlacement, &result);
      assert(err == 0);
    } else {
      int32_t x_placement;
      if (!bare_app_kit__read_int32(env, argv[1], "x_placement", &x_placement)) return NULL;

      grid_view.xPlacement = x_placement;
    }
  }

  return result;
}

static void
bare_app_kit_grid_view_x_placement_typed(js_value_t *receiver, int32_t bare_tag, int32_t x_placement, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridView *grid_view = (NSGridView *) bare_object;

    grid_view.xPlacement = x_placement;
  }
}

static js_value_t *
bare_app_kit_grid_view_y_placement(js_env_t *env, js_callback_info_t *info) {
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
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, grid_view.yPlacement, &result);
      assert(err == 0);
    } else {
      int32_t y_placement;
      if (!bare_app_kit__read_int32(env, argv[1], "y_placement", &y_placement)) return NULL;

      grid_view.yPlacement = y_placement;
    }
  }

  return result;
}

static void
bare_app_kit_grid_view_y_placement_typed(js_value_t *receiver, int32_t bare_tag, int32_t y_placement, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridView *grid_view = (NSGridView *) bare_object;

    grid_view.yPlacement = y_placement;
  }
}

static js_value_t *
bare_app_kit_grid_view_row_alignment(js_env_t *env, js_callback_info_t *info) {
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
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, grid_view.rowAlignment, &result);
      assert(err == 0);
    } else {
      int32_t row_alignment;
      if (!bare_app_kit__read_int32(env, argv[1], "row_alignment", &row_alignment)) return NULL;

      grid_view.rowAlignment = row_alignment;
    }
  }

  return result;
}

static void
bare_app_kit_grid_view_row_alignment_typed(js_value_t *receiver, int32_t bare_tag, int32_t row_alignment, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridView *grid_view = (NSGridView *) bare_object;

    grid_view.rowAlignment = row_alignment;
  }
}

static js_value_t *
bare_app_kit_grid_view_add_row(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSArray *views = bare_app_kit__to_objects(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    result = bare_foundation__bridge(env, [grid_view addRowWithViews:views]);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_view_insert_row(js_env_t *env, js_callback_info_t *info) {
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

  NSArray *views = bare_app_kit__to_objects(env, argv[2]);

  js_value_t *result;

  @autoreleasepool {
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    result = bare_foundation__bridge(env, [grid_view insertRowAtIndex:index withViews:views]);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_view_remove_row(js_env_t *env, js_callback_info_t *info) {
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

  @autoreleasepool {
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    [grid_view removeRowAtIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_grid_view_add_column(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSArray *views = bare_app_kit__to_objects(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    result = bare_foundation__bridge(env, [grid_view addColumnWithViews:views]);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_view_insert_column(js_env_t *env, js_callback_info_t *info) {
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

  NSArray *views = bare_app_kit__to_objects(env, argv[2]);

  js_value_t *result;

  @autoreleasepool {
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    result = bare_foundation__bridge(env, [grid_view insertColumnAtIndex:index withViews:views]);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_view_remove_column(js_env_t *env, js_callback_info_t *info) {
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

  @autoreleasepool {
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    [grid_view removeColumnAtIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_grid_view_row_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    result = bare_foundation__bridge(env, [grid_view rowAtIndex:index]);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_view_column_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    result = bare_foundation__bridge(env, [grid_view columnAtIndex:index]);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_view_cell_at(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t column;
  if (!bare_app_kit__read_int32(env, argv[1], "column", &column)) return NULL;

  int32_t row;
  if (!bare_app_kit__read_int32(env, argv[2], "row", &row)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    result = bare_foundation__bridge(env, [grid_view cellAtColumnIndex:column rowIndex:row]);
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_view_merge_cells(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 5);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t column;
  if (!bare_app_kit__read_int32(env, argv[1], "column", &column)) return NULL;

  int32_t columns;
  if (!bare_app_kit__read_int32(env, argv[2], "columns", &columns)) return NULL;

  int32_t row;
  if (!bare_app_kit__read_int32(env, argv[3], "row", &row)) return NULL;

  int32_t rows;
  if (!bare_app_kit__read_int32(env, argv[4], "rows", &rows)) return NULL;

  @autoreleasepool {
    NSGridView *grid_view = (__bridge NSGridView *) handle;

    [grid_view mergeCellsInHorizontalRange:NSMakeRange(column, columns) verticalRange:NSMakeRange(row, rows)];
  }

  return NULL;
}
