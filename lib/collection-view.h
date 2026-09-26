#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

// Unlike the table and outline views, `NSCollectionView` declares methods with
// the same selectors as its delegate protocol and forwards them to the
// delegate, so a collection view that is its own delegate recurses forever. The
// data source therefore lives on a separate object that the view retains.
@interface BareCollectionViewSource : NSObject <NSCollectionViewDataSource, NSCollectionViewDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  js_ref_t *number_of_items;
  js_ref_t *make_item;
  int32_t mask;

  NSInteger sections;
}

@end

@interface BareCollectionView : NSCollectionView <BareEventTarget> {
@public
  BareCollectionViewSource *source;
}

@end

@implementation BareCollectionViewSource

- (int32_t)eventMask {
  return mask;
}

- (void)setEventMask:(int32_t)value {
  mask = value;
}

- (void)dealloc {
  int err;

  err = js_delete_reference(env, number_of_items);
  assert(err == 0);

  err = js_delete_reference(env, make_item);
  assert(err == 0);

  err = js_delete_reference(env, ctx);
  assert(err == 0);

  [super dealloc];
}

- (NSInteger)numberOfSectionsInCollectionView:(NSCollectionView *)collectionView {
  return sections;
}

- (NSInteger)collectionView:(NSCollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
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
    err = js_get_reference_value(env, number_of_items, &fn);
    assert(err == 0);

    js_value_t *argv[1];
    err = js_create_int32(env, (int32_t) section, &argv[0]);
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

- (NSCollectionViewItem *)collectionView:(NSCollectionView *)collectionView itemForRepresentedObjectAtIndexPath:(NSIndexPath *)indexPath {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  NSCollectionViewItem *item = nil;

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  if (receiver != NULL) {
    js_value_t *fn;
    err = js_get_reference_value(env, make_item, &fn);
    assert(err == 0);

    js_value_t *argv[2];

    err = js_create_int32(env, (int32_t) indexPath.section, &argv[0]);
    assert(err == 0);

    err = js_create_int32(env, (int32_t) indexPath.item, &argv[1]);
    assert(err == 0);

    js_value_t *result;
    err = js_call_function(env, receiver, fn, 2, argv, &result);

    if (bare_app_kit__settle(env, err)) {
      item = bare_foundation__to_object(env, result);
    }
  }

  err = js_close_handle_scope(env, scope);
  assert(err == 0);

  // A nil item is a hard error inside AppKit, so fall back to an empty one.
  if (item == nil) item = [[[NSCollectionViewItem alloc] init] autorelease];

  return [[item retain] autorelease];
}

- (void)collectionView:(NSCollectionView *)collectionView didSelectItemsAtIndexPaths:(NSSet<NSIndexPath *> *)indexPaths {
  if (mask & (1 << 0)) bare_app_kit__emit(env, ctx, "_onselectionchange");
}

- (void)collectionView:(NSCollectionView *)collectionView didDeselectItemsAtIndexPaths:(NSSet<NSIndexPath *> *)indexPaths {
  if (mask & (1 << 1)) bare_app_kit__emit(env, ctx, "_ondeselectionchange");
}

@end

@implementation BareCollectionView

// The callbacks live on the source, so the mask does too.
- (int32_t)eventMask {
  return source.eventMask;
}

- (void)setEventMask:(int32_t)value {
  source.eventMask = value;
}

- (void)dealloc {
  [source release];

  [super dealloc];
}

@end

static js_value_t *
bare_app_kit_collection_view_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 7;
  js_value_t *argv[7];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 7);

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
    BareCollectionView *handle = [[[BareCollectionView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    BareCollectionViewSource *source = [[BareCollectionViewSource alloc] init];

    source->sections = 1;
    source->env = env;

    handle->source = source;

    result = bare_foundation__bridge(env, handle);

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &source->ctx);
    assert(err == 0);

    err = js_create_reference(env, argv[5], 1, &source->number_of_items);
    assert(err == 0);

    err = js_create_reference(env, argv[6], 1, &source->make_item);
    assert(err == 0);

    [handle setDataSource:source];
    [handle setDelegate:source];
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_number_of_sections(js_env_t *env, js_callback_info_t *info) {
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
    BareCollectionView *collection_view = (__bridge BareCollectionView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, (int32_t) collection_view->source->sections, &result);
      assert(err == 0);
    } else {
      int32_t sections;
      if (!bare_app_kit__read_int32(env, argv[1], "sections", &sections)) return NULL;

      collection_view->source->sections = sections;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_collection_view_layout(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, collection_view.collectionViewLayout);
    } else {
      collection_view.collectionViewLayout = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_background_view(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, collection_view.backgroundView);
    } else {
      collection_view.backgroundView = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_selectable(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, collection_view.selectable, &result);
      assert(err == 0);
    } else {
      bool selectable;
      if (!bare_app_kit__read_bool(env, argv[1], "selectable", &selectable)) return NULL;

      collection_view.selectable = selectable;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_allows_empty_selection(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, collection_view.allowsEmptySelection, &result);
      assert(err == 0);
    } else {
      bool allows_empty_selection;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_empty_selection", &allows_empty_selection)) return NULL;

      collection_view.allowsEmptySelection = allows_empty_selection;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_allows_multiple_selection(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, collection_view.allowsMultipleSelection, &result);
      assert(err == 0);
    } else {
      bool allows_multiple_selection;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_multiple_selection", &allows_multiple_selection)) return NULL;

      collection_view.allowsMultipleSelection = allows_multiple_selection;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_background_view_scrolls_with_content(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, collection_view.backgroundViewScrollsWithContent, &result);
      assert(err == 0);
    } else {
      bool background_view_scrolls_with_content;
      if (!bare_app_kit__read_bool(env, argv[1], "background_view_scrolls_with_content", &background_view_scrolls_with_content)) return NULL;

      collection_view.backgroundViewScrollsWithContent = background_view_scrolls_with_content;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_selection_index_paths(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    result = bare_app_kit__from_index_paths(env, collection_view.selectionIndexPaths);
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_reload_data(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    [collection_view reloadData];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_collection_view_deselect_all(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    [collection_view deselectAll:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_collection_view_select_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t section;
  if (!bare_app_kit__read_int32(env, argv[1], "section", &section)) return NULL;

  int32_t item;
  if (!bare_app_kit__read_int32(env, argv[2], "item", &item)) return NULL;

  @autoreleasepool {
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    [collection_view selectItemsAtIndexPaths:[NSSet setWithObject:[NSIndexPath indexPathForItem:item inSection:section]] scrollPosition:NSCollectionViewScrollPositionNone];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_collection_view_scroll_to_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t section;
  if (!bare_app_kit__read_int32(env, argv[1], "section", &section)) return NULL;

  int32_t item;
  if (!bare_app_kit__read_int32(env, argv[2], "item", &item)) return NULL;

  int32_t position;
  if (!bare_app_kit__read_int32(env, argv[3], "position", &position)) return NULL;

  @autoreleasepool {
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    [collection_view scrollToItemsAtIndexPaths:[NSSet setWithObject:[NSIndexPath indexPathForItem:item inSection:section]] scrollPosition:position];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_collection_view_item_at(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t section;
  if (!bare_app_kit__read_int32(env, argv[1], "section", &section)) return NULL;

  int32_t item;
  if (!bare_app_kit__read_int32(env, argv[2], "item", &item)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    result = bare_foundation__bridge(env, [collection_view itemAtIndexPath:[NSIndexPath indexPathForItem:item inSection:section]]);
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_number_of_items_in_section(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t section;
  if (!bare_app_kit__read_int32(env, argv[1], "section", &section)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSCollectionView *collection_view = (__bridge NSCollectionView *) handle;

    err = js_create_int32(env, (int32_t) [collection_view numberOfItemsInSection:section], &result);
    assert(err == 0);
  }

  return result;
}
