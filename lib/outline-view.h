#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

// An outline view's data source is item based rather than index based, so the
// tree has to be pulled: every question about shape depends on the item being
// asked about. Items cross the boundary as integer ids that the JavaScript side
// assigns, wrapped here as `NSNumber` so that `NSOutlineView` can hash and
// compare them. A nil item, meaning the root, is -1.
#define BARE_APP_KIT_OUTLINE_VIEW_ROOT (-1)

@interface BareOutlineView : NSOutlineView <NSOutlineViewDataSource, NSOutlineViewDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  js_ref_t *number_of_children;
  js_ref_t *child;
  js_ref_t *is_expandable;
  js_ref_t *make_view;
  int32_t mask;
}

@end

@implementation BareOutlineView

- (int32_t)eventMask {
  return mask;
}

- (void)setEventMask:(int32_t)value {
  mask = value;
}

- (void)dealloc {
  int err;

  err = js_delete_reference(env, number_of_children);
  assert(err == 0);

  err = js_delete_reference(env, child);
  assert(err == 0);

  err = js_delete_reference(env, is_expandable);
  assert(err == 0);

  err = js_delete_reference(env, make_view);
  assert(err == 0);

  err = js_delete_reference(env, ctx);
  assert(err == 0);

  [super dealloc];
}

- (int32_t)idForItem:(id)item {
  return item == nil ? BARE_APP_KIT_OUTLINE_VIEW_ROOT : (int32_t) [item intValue];
}

- (NSInteger)outlineView:(NSOutlineView *)outlineView numberOfChildrenOfItem:(id)item {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  int32_t count = 0;

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  if (receiver != NULL) {
    js_value_t *fn;
    err = js_get_reference_value(env, number_of_children, &fn);
    assert(err == 0);

    js_value_t *argv[1];
    err = js_create_int32(env, [self idForItem:item], &argv[0]);
    assert(err == 0);

    js_value_t *result;
    err = js_call_function(env, receiver, fn, 1, argv, &result);

    if (bare_app_kit__settle(env, err)) {
      err = js_get_value_int32(env, result, &count);
      if (err != 0) count = 0;
    }
  }

  err = js_close_handle_scope(env, scope);
  assert(err == 0);

  return count;
}

- (id)outlineView:(NSOutlineView *)outlineView child:(NSInteger)index ofItem:(id)item {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  int32_t id_ = BARE_APP_KIT_OUTLINE_VIEW_ROOT;

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  if (receiver != NULL) {
    js_value_t *fn;
    err = js_get_reference_value(env, child, &fn);
    assert(err == 0);

    js_value_t *argv[2];

    err = js_create_int32(env, (int32_t) index, &argv[0]);
    assert(err == 0);

    err = js_create_int32(env, [self idForItem:item], &argv[1]);
    assert(err == 0);

    js_value_t *result;
    err = js_call_function(env, receiver, fn, 2, argv, &result);

    if (bare_app_kit__settle(env, err)) {
      err = js_get_value_int32(env, result, &id_);
      if (err != 0) id_ = BARE_APP_KIT_OUTLINE_VIEW_ROOT;
    }
  }

  err = js_close_handle_scope(env, scope);
  assert(err == 0);

  return @(id_);
}

- (BOOL)outlineView:(NSOutlineView *)outlineView isItemExpandable:(id)item {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  bool expandable = false;

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  if (receiver != NULL) {
    js_value_t *fn;
    err = js_get_reference_value(env, is_expandable, &fn);
    assert(err == 0);

    js_value_t *argv[1];
    err = js_create_int32(env, [self idForItem:item], &argv[0]);
    assert(err == 0);

    js_value_t *result;
    err = js_call_function(env, receiver, fn, 1, argv, &result);

    if (bare_app_kit__settle(env, err)) {
      err = js_get_value_bool(env, result, &expandable);
      if (err != 0) expandable = false;
    }
  }

  err = js_close_handle_scope(env, scope);
  assert(err == 0);

  return expandable;
}

- (NSView *)outlineView:(NSOutlineView *)outlineView viewForTableColumn:(NSTableColumn *)column item:(id)item {
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

    err = js_create_int32(env, [self idForItem:item], &argv[1]);
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

- (void)outlineViewSelectionDidChange:(NSNotification *)notification {
  if (mask & (1 << 0)) bare_app_kit__emit(env, ctx, "_onselectionchange");
}

- (void)outlineViewItemDidExpand:(NSNotification *)notification {
  if (mask & (1 << 1)) bare_app_kit__emit(env, ctx, "_onitemdidexpand");
}

- (void)outlineViewItemDidCollapse:(NSNotification *)notification {
  if (mask & (1 << 2)) bare_app_kit__emit(env, ctx, "_onitemdidcollapse");
}

@end

static js_value_t *
bare_app_kit_outline_view_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 9;
  js_value_t *argv[9];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 9);

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
    BareOutlineView *handle = [[[BareOutlineView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    err = js_create_reference(env, argv[5], 1, &handle->number_of_children);
    assert(err == 0);

    err = js_create_reference(env, argv[6], 1, &handle->child);
    assert(err == 0);

    err = js_create_reference(env, argv[7], 1, &handle->is_expandable);
    assert(err == 0);

    err = js_create_reference(env, argv[8], 1, &handle->make_view);
    assert(err == 0);

    [handle setDataSource:handle];
    [handle setDelegate:handle];
  }

  return result;
}

static js_value_t *
bare_app_kit_outline_view_number_of_rows(js_env_t *env, js_callback_info_t *info) {
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
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    err = js_create_int32(env, outline_view.numberOfRows, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_outline_view_indentation_per_level(js_env_t *env, js_callback_info_t *info) {
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
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    if (argc == 1) {
      err = js_create_double(env, outline_view.indentationPerLevel, &result);
      assert(err == 0);
    } else {
      double indentation_per_level;
      if (!bare_app_kit__read_double(env, argv[1], "indentation_per_level", &indentation_per_level)) return NULL;

      outline_view.indentationPerLevel = indentation_per_level;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_outline_view_indentation_marker_follows_cell(js_env_t *env, js_callback_info_t *info) {
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
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, outline_view.indentationMarkerFollowsCell, &result);
      assert(err == 0);
    } else {
      bool indentation_marker_follows_cell;
      if (!bare_app_kit__read_bool(env, argv[1], "indentation_marker_follows_cell", &indentation_marker_follows_cell)) return NULL;

      outline_view.indentationMarkerFollowsCell = indentation_marker_follows_cell;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_outline_view_autoresizes_outline_column(js_env_t *env, js_callback_info_t *info) {
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
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, outline_view.autoresizesOutlineColumn, &result);
      assert(err == 0);
    } else {
      bool autoresizes_outline_column;
      if (!bare_app_kit__read_bool(env, argv[1], "autoresizes_outline_column", &autoresizes_outline_column)) return NULL;

      outline_view.autoresizesOutlineColumn = autoresizes_outline_column;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_outline_view_autosave_expanded_items(js_env_t *env, js_callback_info_t *info) {
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
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, outline_view.autosaveExpandedItems, &result);
      assert(err == 0);
    } else {
      bool autosave_expanded_items;
      if (!bare_app_kit__read_bool(env, argv[1], "autosave_expanded_items", &autosave_expanded_items)) return NULL;

      outline_view.autosaveExpandedItems = autosave_expanded_items;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_outline_view_strongly_references_items(js_env_t *env, js_callback_info_t *info) {
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
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, outline_view.stronglyReferencesItems, &result);
      assert(err == 0);
    } else {
      bool strongly_references_items;
      if (!bare_app_kit__read_bool(env, argv[1], "strongly_references_items", &strongly_references_items)) return NULL;

      outline_view.stronglyReferencesItems = strongly_references_items;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_outline_view_outline_table_column(js_env_t *env, js_callback_info_t *info) {
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
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, outline_view.outlineTableColumn);
    } else {
      outline_view.outlineTableColumn = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_outline_view_expand_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t item;
  if (!bare_app_kit__read_int32(env, argv[1], "item", &item)) return NULL;

  bool children;
  if (!bare_app_kit__read_bool(env, argv[2], "children", &children)) return NULL;

  @autoreleasepool {
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    [outline_view expandItem:(item < 0 ? nil : @(item)) expandChildren:children];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_outline_view_collapse_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t item;
  if (!bare_app_kit__read_int32(env, argv[1], "item", &item)) return NULL;

  bool children;
  if (!bare_app_kit__read_bool(env, argv[2], "children", &children)) return NULL;

  @autoreleasepool {
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    [outline_view collapseItem:(item < 0 ? nil : @(item)) collapseChildren:children];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_outline_view_is_item_expanded(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t item;
  if (!bare_app_kit__read_int32(env, argv[1], "item", &item)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    err = js_get_boolean(env, [outline_view isItemExpanded:(item < 0 ? nil : @(item))], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_outline_view_reload_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t item;
  if (!bare_app_kit__read_int32(env, argv[1], "item", &item)) return NULL;

  bool children;
  if (!bare_app_kit__read_bool(env, argv[2], "children", &children)) return NULL;

  @autoreleasepool {
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    [outline_view reloadItem:(item < 0 ? nil : @(item)) reloadChildren:children];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_outline_view_level_for_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t item;
  if (!bare_app_kit__read_int32(env, argv[1], "item", &item)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    err = js_create_int32(env, (int32_t) [outline_view levelForItem:(item < 0 ? nil : @(item))], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_outline_view_row_for_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t item;
  if (!bare_app_kit__read_int32(env, argv[1], "item", &item)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    result = bare_app_kit__from_index(env, [outline_view rowForItem:(item < 0 ? nil : @(item))]);
  }

  return result;
}

static js_value_t *
bare_app_kit_outline_view_item_at_row(js_env_t *env, js_callback_info_t *info) {
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
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    err = js_create_int32(env, (int32_t) [[outline_view itemAtRow:row] intValue], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_outline_view_parent_for_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t item;
  if (!bare_app_kit__read_int32(env, argv[1], "item", &item)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSOutlineView *outline_view = (__bridge NSOutlineView *) handle;

    err = js_create_int32(env, [outline_view parentForItem:(item < 0 ? nil : @(item))] == nil ? -1 : (int32_t) [[outline_view parentForItem:(item < 0 ? nil : @(item))] intValue], &result);
    assert(err == 0);
  }

  return result;
}
