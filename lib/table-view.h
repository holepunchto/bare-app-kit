#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

// The row count is pushed from JavaScript so that the hottest data source
// method never crosses the boundary. Cell views are pulled on demand, which is
// the only way to keep the table lazy while still allowing arbitrary views.
@interface BareTableView : NSTableView <NSTableViewDataSource, NSTableViewDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  js_ref_t *make_view;
  int32_t mask;

  NSInteger rows;
}

@end

@implementation BareTableView

- (int32_t)eventMask {
  return mask;
}

- (void)setEventMask:(int32_t)value {
  mask = value;
}

- (void)dealloc {
  int err;

  err = js_delete_reference(env, make_view);
  assert(err == 0);

  err = js_delete_reference(env, ctx);
  assert(err == 0);

  [super dealloc];
}

- (NSInteger)numberOfRowsInTableView:(NSTableView *)tableView {
  return rows;
}

- (NSView *)tableView:(NSTableView *)tableView viewForTableColumn:(NSTableColumn *)column row:(NSInteger)row {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  NSView *view = nil;

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  if (receiver != NULL) {
    js_value_t *fn;
    err = js_get_reference_value(env, make_view, &fn);
    assert(err == 0);

    js_value_t *argv[2];

    argv[0] = bare_app_kit__from_string(env, column.identifier);

    err = js_create_int32(env, (int32_t) row, &argv[1]);
    assert(err == 0);

    js_value_t *result;
    err = js_call_function(env, receiver, fn, 2, argv, &result);

    if (bare_app_kit__settle(env, err)) {
      view = bare_foundation__to_object(env, result);
    }
  }

  err = js_close_handle_scope(env, scope);
  assert(err == 0);

  return [[view retain] autorelease];
}

- (void)tableViewSelectionDidChange:(NSNotification *)notification {
  if (mask & (1 << 0)) bare_app_kit__emit(env, ctx, "_onselectionchange");
}

- (void)onClick:(id)sender {
  if (mask & (1 << 1)) bare_app_kit__emit(env, ctx, "_onclick");
}

- (void)onDoubleClick:(id)sender {
  if (mask & (1 << 2)) bare_app_kit__emit(env, ctx, "_ondoubleclick");
}

@end

static js_value_t *
bare_app_kit_table_view_init(js_env_t *env, js_callback_info_t *info) {
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

  js_value_t *result;

  @autoreleasepool {
    BareTableView *handle = [[[BareTableView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    err = js_create_reference(env, argv[5], 1, &handle->make_view);
    assert(err == 0);

    [handle setDataSource:handle];
    [handle setDelegate:handle];

    [handle setTarget:handle];
    [handle setAction:@selector(onClick:)];
    [handle setDoubleAction:@selector(onDoubleClick:)];
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_number_of_rows(js_env_t *env, js_callback_info_t *info) {
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
    BareTableView *table_view = (__bridge BareTableView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, (int32_t) table_view->rows, &result);
      assert(err == 0);
    } else {
      int32_t rows;
      if (!bare_app_kit__read_int32(env, argv[1], "rows", &rows)) return NULL;

      table_view->rows = rows;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_row_height(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      err = js_create_double(env, table_view.rowHeight, &result);
      assert(err == 0);
    } else {
      double row_height;
      if (!bare_app_kit__read_double(env, argv[1], "row_height", &row_height)) return NULL;

      table_view.rowHeight = row_height;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_intercell_spacing(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, table_view.intercellSpacing);
    } else {
      double width;
      if (!bare_app_kit__read_double(env, argv[1], "width", &width)) return NULL;

      double height;
      if (!bare_app_kit__read_double(env, argv[2], "height", &height)) return NULL;

      table_view.intercellSpacing = NSMakeSize(width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_uses_alternating_row_background_colors(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, table_view.usesAlternatingRowBackgroundColors, &result);
      assert(err == 0);
    } else {
      bool uses_alternating_row_background_colors;
      if (!bare_app_kit__read_bool(env, argv[1], "uses_alternating_row_background_colors", &uses_alternating_row_background_colors)) return NULL;

      table_view.usesAlternatingRowBackgroundColors = uses_alternating_row_background_colors;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_uses_automatic_row_heights(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, table_view.usesAutomaticRowHeights, &result);
      assert(err == 0);
    } else {
      bool uses_automatic_row_heights;
      if (!bare_app_kit__read_bool(env, argv[1], "uses_automatic_row_heights", &uses_automatic_row_heights)) return NULL;

      table_view.usesAutomaticRowHeights = uses_automatic_row_heights;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_allows_multiple_selection(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, table_view.allowsMultipleSelection, &result);
      assert(err == 0);
    } else {
      bool allows_multiple_selection;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_multiple_selection", &allows_multiple_selection)) return NULL;

      table_view.allowsMultipleSelection = allows_multiple_selection;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_allows_empty_selection(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, table_view.allowsEmptySelection, &result);
      assert(err == 0);
    } else {
      bool allows_empty_selection;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_empty_selection", &allows_empty_selection)) return NULL;

      table_view.allowsEmptySelection = allows_empty_selection;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_allows_column_reordering(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, table_view.allowsColumnReordering, &result);
      assert(err == 0);
    } else {
      bool allows_column_reordering;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_column_reordering", &allows_column_reordering)) return NULL;

      table_view.allowsColumnReordering = allows_column_reordering;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_allows_column_resizing(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, table_view.allowsColumnResizing, &result);
      assert(err == 0);
    } else {
      bool allows_column_resizing;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_column_resizing", &allows_column_resizing)) return NULL;

      table_view.allowsColumnResizing = allows_column_resizing;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_allows_column_selection(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, table_view.allowsColumnSelection, &result);
      assert(err == 0);
    } else {
      bool allows_column_selection;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_column_selection", &allows_column_selection)) return NULL;

      table_view.allowsColumnSelection = allows_column_selection;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_style(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, table_view.style, &result);
      assert(err == 0);
    } else {
      int32_t style;
      if (!bare_app_kit__read_int32(env, argv[1], "style", &style)) return NULL;

      table_view.style = style;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_grid_style_mask(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, table_view.gridStyleMask, &result);
      assert(err == 0);
    } else {
      int32_t grid_style_mask;
      if (!bare_app_kit__read_int32(env, argv[1], "grid_style_mask", &grid_style_mask)) return NULL;

      table_view.gridStyleMask = grid_style_mask;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_row_size_style(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, table_view.rowSizeStyle, &result);
      assert(err == 0);
    } else {
      int32_t row_size_style;
      if (!bare_app_kit__read_int32(env, argv[1], "row_size_style", &row_size_style)) return NULL;

      table_view.rowSizeStyle = row_size_style;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_column_autoresizing_style(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, table_view.columnAutoresizingStyle, &result);
      assert(err == 0);
    } else {
      int32_t column_autoresizing_style;
      if (!bare_app_kit__read_int32(env, argv[1], "column_autoresizing_style", &column_autoresizing_style)) return NULL;

      table_view.columnAutoresizingStyle = column_autoresizing_style;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_background_color(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, table_view.backgroundColor);
    } else {
      table_view.backgroundColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_grid_color(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, table_view.gridColor);
    } else {
      table_view.gridColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_header_view(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, table_view.headerView);
    } else {
      table_view.headerView = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_number_of_columns(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    err = js_create_int32(env, table_view.numberOfColumns, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_selected_row(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    result = bare_app_kit__from_index(env, table_view.selectedRow);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_selected_column(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    result = bare_app_kit__from_index(env, table_view.selectedColumn);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_clicked_row(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    result = bare_app_kit__from_index(env, table_view.clickedRow);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_clicked_column(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    result = bare_app_kit__from_index(env, table_view.clickedColumn);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_number_of_selected_rows(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    err = js_create_int32(env, table_view.numberOfSelectedRows, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_reload_data(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    [table_view reloadData];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_table_view_add_table_column(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id column = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    [table_view addTableColumn:column];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_table_view_remove_table_column(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id column = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    [table_view removeTableColumn:column];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_table_view_move_column(js_env_t *env, js_callback_info_t *info) {
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

  int32_t index;
  if (!bare_app_kit__read_int32(env, argv[2], "index", &index)) return NULL;

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    [table_view moveColumn:column toColumn:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_table_view_select_row(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t row;
  if (!bare_app_kit__read_int32(env, argv[1], "row", &row)) return NULL;

  bool extend;
  if (!bare_app_kit__read_bool(env, argv[2], "extend", &extend)) return NULL;

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    [table_view selectRowIndexes:[NSIndexSet indexSetWithIndex:row] byExtendingSelection:extend];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_table_view_deselect_row(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t row;
  if (!bare_app_kit__read_int32(env, argv[1], "row", &row)) return NULL;

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    [table_view deselectRow:row];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_table_view_deselect_all(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    [table_view deselectAll:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_table_view_select_all(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    [table_view selectAll:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_table_view_is_row_selected(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t row;
  if (!bare_app_kit__read_int32(env, argv[1], "row", &row)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    err = js_get_boolean(env, [table_view isRowSelected:row], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_view_scroll_row_to_visible(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t row;
  if (!bare_app_kit__read_int32(env, argv[1], "row", &row)) return NULL;

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    [table_view scrollRowToVisible:row];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_table_view_reload_row(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t row;
  if (!bare_app_kit__read_int32(env, argv[1], "row", &row)) return NULL;

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    [table_view reloadDataForRowIndexes:[NSIndexSet indexSetWithIndex:row] columnIndexes:[NSIndexSet indexSetWithIndexesInRange:NSMakeRange(0, table_view.numberOfColumns)]];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_table_view_size_to_fit(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    [table_view sizeToFit];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_table_view_size_last_column_to_fit(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSTableView *table_view = (__bridge NSTableView *) handle;

    [table_view sizeLastColumnToFit];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_table_view_columns(js_env_t *env, js_callback_info_t *info) {
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
    NSTableView *table_view = (__bridge NSTableView *) handle;

    result = bare_app_kit__from_objects(env, table_view.tableColumns);
  }

  return result;
}
