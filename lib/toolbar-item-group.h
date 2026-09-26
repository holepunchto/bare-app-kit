#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_toolbar_item_group_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  js_value_t *result;

  @autoreleasepool {
    NSString *identifier = bare_app_kit__to_string(env, argv[0]);

    NSToolbarItemGroup *handle = [[[NSToolbarItemGroup alloc] initWithItemIdentifier:identifier] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_item_group_selection_mode(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItemGroup *group = (__bridge NSToolbarItemGroup *) handle;

    if (argc == 1) {
      err = js_create_int32(env, group.selectionMode, &result);
      assert(err == 0);
    } else {
      int32_t selection_mode;
      if (!bare_app_kit__read_int32(env, argv[1], "selection_mode", &selection_mode)) return NULL;

      group.selectionMode = selection_mode;
    }
  }

  return result;
}

static void
bare_app_kit_toolbar_item_group_selection_mode_typed(js_value_t *receiver, int32_t bare_tag, int32_t selection_mode, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSToolbarItemGroup *group = (NSToolbarItemGroup *) bare_object;

    group.selectionMode = selection_mode;
  }
}

static js_value_t *
bare_app_kit_toolbar_item_group_control_representation(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItemGroup *group = (__bridge NSToolbarItemGroup *) handle;

    if (argc == 1) {
      err = js_create_int32(env, group.controlRepresentation, &result);
      assert(err == 0);
    } else {
      int32_t control_representation;
      if (!bare_app_kit__read_int32(env, argv[1], "control_representation", &control_representation)) return NULL;

      group.controlRepresentation = control_representation;
    }
  }

  return result;
}

static void
bare_app_kit_toolbar_item_group_control_representation_typed(js_value_t *receiver, int32_t bare_tag, int32_t control_representation, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSToolbarItemGroup *group = (NSToolbarItemGroup *) bare_object;

    group.controlRepresentation = control_representation;
  }
}

static js_value_t *
bare_app_kit_toolbar_item_group_selected_index(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItemGroup *group = (__bridge NSToolbarItemGroup *) handle;

    if (argc == 1) {
      err = js_create_int32(env, group.selectedIndex, &result);
      assert(err == 0);
    } else {
      int32_t selected_index;
      if (!bare_app_kit__read_int32(env, argv[1], "selected_index", &selected_index)) return NULL;

      group.selectedIndex = selected_index;
    }
  }

  return result;
}

static void
bare_app_kit_toolbar_item_group_selected_index_typed(js_value_t *receiver, int32_t bare_tag, int32_t selected_index, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSToolbarItemGroup *group = (NSToolbarItemGroup *) bare_object;

    group.selectedIndex = selected_index;
  }
}

static js_value_t *
bare_app_kit_toolbar_item_group_set_subitems(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSArray *items = bare_app_kit__to_objects(env, argv[1]);

  @autoreleasepool {
    NSToolbarItemGroup *group = (__bridge NSToolbarItemGroup *) handle;

    [group setSubitems:items];
  }

  return NULL;
}
