#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_collection_view_item_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 0;
  js_value_t *argv[0];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    NSCollectionViewItem *handle = [[[NSCollectionViewItem alloc] init] autorelease];

    result = bare_foundation_bridge(env, registry, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_item_view(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSCollectionViewItem *collection_view_item = (__bridge NSCollectionViewItem *) handle;

    if (argc == 1) {
      result = bare_foundation_bridge(env, registry, collection_view_item.view);
    } else {
      collection_view_item.view = bare_foundation_to_object(env, registry, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_item_selected(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSCollectionViewItem *collection_view_item = (__bridge NSCollectionViewItem *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, collection_view_item.selected, &result);
      assert(err == 0);
    } else {
      bool selected;
      if (!bare_app_kit__read_bool(env, argv[1], "selected", &selected)) return NULL;

      collection_view_item.selected = selected;
    }
  }

  return result;
}

static void
bare_app_kit_collection_view_item_selected_typed(js_value_t *receiver, int32_t bare_tag, bool selected, js_typed_callback_info_t *info) {
  int err;

  bare_foundation_registry_t *registry;
  err = js_get_typed_callback_info(info, NULL, (void **) &registry);
  assert(err == 0);

  id bare_object = bare_foundation_object(registry, bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSCollectionViewItem *collection_view_item = (NSCollectionViewItem *) bare_object;

    collection_view_item.selected = selected;
  }
}

static js_value_t *
bare_app_kit_collection_view_item_highlight_state(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSCollectionViewItem *collection_view_item = (__bridge NSCollectionViewItem *) handle;

    if (argc == 1) {
      err = js_create_int32(env, collection_view_item.highlightState, &result);
      assert(err == 0);
    } else {
      int32_t highlight_state;
      if (!bare_app_kit__read_int32(env, argv[1], "highlight_state", &highlight_state)) return NULL;

      collection_view_item.highlightState = highlight_state;
    }
  }

  return result;
}

static void
bare_app_kit_collection_view_item_highlight_state_typed(js_value_t *receiver, int32_t bare_tag, int32_t highlight_state, js_typed_callback_info_t *info) {
  int err;

  bare_foundation_registry_t *registry;
  err = js_get_typed_callback_info(info, NULL, (void **) &registry);
  assert(err == 0);

  id bare_object = bare_foundation_object(registry, bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSCollectionViewItem *collection_view_item = (NSCollectionViewItem *) bare_object;

    collection_view_item.highlightState = highlight_state;
  }
}

static js_value_t *
bare_app_kit_collection_view_item_image_view(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSCollectionViewItem *collection_view_item = (__bridge NSCollectionViewItem *) handle;

    if (argc == 1) {
      result = bare_foundation_bridge(env, registry, collection_view_item.imageView);
    } else {
      collection_view_item.imageView = bare_foundation_to_object(env, registry, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_item_text_field(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSCollectionViewItem *collection_view_item = (__bridge NSCollectionViewItem *) handle;

    if (argc == 1) {
      result = bare_foundation_bridge(env, registry, collection_view_item.textField);
    } else {
      collection_view_item.textField = bare_foundation_to_object(env, registry, argv[1]);
    }
  }

  return result;
}
