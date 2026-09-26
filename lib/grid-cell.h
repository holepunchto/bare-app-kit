#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_grid_cell_content_view(js_env_t *env, js_callback_info_t *info) {
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
    NSGridCell *grid_cell = (__bridge NSGridCell *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, grid_cell.contentView);
    } else {
      grid_cell.contentView = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_grid_cell_x_placement(js_env_t *env, js_callback_info_t *info) {
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
    NSGridCell *grid_cell = (__bridge NSGridCell *) handle;

    if (argc == 1) {
      err = js_create_int32(env, grid_cell.xPlacement, &result);
      assert(err == 0);
    } else {
      int32_t x_placement;
      if (!bare_app_kit__read_int32(env, argv[1], "x_placement", &x_placement)) return NULL;

      grid_cell.xPlacement = x_placement;
    }
  }

  return result;
}

static void
bare_app_kit_grid_cell_x_placement_typed(js_value_t *receiver, int32_t bare_tag, int32_t x_placement, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridCell *grid_cell = (NSGridCell *) bare_object;

    grid_cell.xPlacement = x_placement;
  }
}

static js_value_t *
bare_app_kit_grid_cell_y_placement(js_env_t *env, js_callback_info_t *info) {
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
    NSGridCell *grid_cell = (__bridge NSGridCell *) handle;

    if (argc == 1) {
      err = js_create_int32(env, grid_cell.yPlacement, &result);
      assert(err == 0);
    } else {
      int32_t y_placement;
      if (!bare_app_kit__read_int32(env, argv[1], "y_placement", &y_placement)) return NULL;

      grid_cell.yPlacement = y_placement;
    }
  }

  return result;
}

static void
bare_app_kit_grid_cell_y_placement_typed(js_value_t *receiver, int32_t bare_tag, int32_t y_placement, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridCell *grid_cell = (NSGridCell *) bare_object;

    grid_cell.yPlacement = y_placement;
  }
}

static js_value_t *
bare_app_kit_grid_cell_row_alignment(js_env_t *env, js_callback_info_t *info) {
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
    NSGridCell *grid_cell = (__bridge NSGridCell *) handle;

    if (argc == 1) {
      err = js_create_int32(env, grid_cell.rowAlignment, &result);
      assert(err == 0);
    } else {
      int32_t row_alignment;
      if (!bare_app_kit__read_int32(env, argv[1], "row_alignment", &row_alignment)) return NULL;

      grid_cell.rowAlignment = row_alignment;
    }
  }

  return result;
}

static void
bare_app_kit_grid_cell_row_alignment_typed(js_value_t *receiver, int32_t bare_tag, int32_t row_alignment, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGridCell *grid_cell = (NSGridCell *) bare_object;

    grid_cell.rowAlignment = row_alignment;
  }
}
