#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_table_header_view_init(js_env_t *env, js_callback_info_t *info) {
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
    NSTableHeaderView *handle = [[[NSTableHeaderView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_header_view_dragged_column(js_env_t *env, js_callback_info_t *info) {
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
    NSTableHeaderView *table_header_view = (__bridge NSTableHeaderView *) handle;

    result = bare_app_kit__from_index(env, table_header_view.draggedColumn);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_header_view_resized_column(js_env_t *env, js_callback_info_t *info) {
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
    NSTableHeaderView *table_header_view = (__bridge NSTableHeaderView *) handle;

    result = bare_app_kit__from_index(env, table_header_view.resizedColumn);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_header_view_dragged_distance(js_env_t *env, js_callback_info_t *info) {
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
    NSTableHeaderView *table_header_view = (__bridge NSTableHeaderView *) handle;

    err = js_create_double(env, table_header_view.draggedDistance, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_header_view_column_at_point(js_env_t *env, js_callback_info_t *info) {
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
    NSTableHeaderView *table_header_view = (__bridge NSTableHeaderView *) handle;

    result = bare_app_kit__from_index(env, [table_header_view columnAtPoint:NSMakePoint(x, y)]);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_header_view_header_rect_of_column(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t column;
  if (!bare_app_kit__read_int32(env, argv[1], "column", &column)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSTableHeaderView *table_header_view = (__bridge NSTableHeaderView *) handle;

    result = bare_app_kit__from_rect(env, [table_header_view headerRectOfColumn:column]);
  }

  return result;
}
