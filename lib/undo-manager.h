#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_undo_manager_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 0;
  js_value_t *argv[0];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    NSUndoManager *handle = [[[NSUndoManager alloc] init] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_undo_manager_can_undo(js_env_t *env, js_callback_info_t *info) {
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
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    err = js_get_boolean(env, undo_manager.canUndo, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_undo_manager_can_redo(js_env_t *env, js_callback_info_t *info) {
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
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    err = js_get_boolean(env, undo_manager.canRedo, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_undo_manager_undoing(js_env_t *env, js_callback_info_t *info) {
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
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    err = js_get_boolean(env, undo_manager.undoing, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_undo_manager_redoing(js_env_t *env, js_callback_info_t *info) {
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
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    err = js_get_boolean(env, undo_manager.redoing, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_undo_manager_undo_registration_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    err = js_get_boolean(env, undo_manager.undoRegistrationEnabled, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_undo_manager_groups_by_event(js_env_t *env, js_callback_info_t *info) {
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
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, undo_manager.groupsByEvent, &result);
      assert(err == 0);
    } else {
      bool groups_by_event;
      if (!bare_app_kit__read_bool(env, argv[1], "groups_by_event", &groups_by_event)) return NULL;

      undo_manager.groupsByEvent = groups_by_event;
    }
  }

  return result;
}

static void
bare_app_kit_undo_manager_groups_by_event_typed(js_value_t *receiver, int32_t bare_tag, bool groups_by_event, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSUndoManager *undo_manager = (NSUndoManager *) bare_object;

    undo_manager.groupsByEvent = groups_by_event;
  }
}

static js_value_t *
bare_app_kit_undo_manager_levels_of_undo(js_env_t *env, js_callback_info_t *info) {
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
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    if (argc == 1) {
      err = js_create_int32(env, undo_manager.levelsOfUndo, &result);
      assert(err == 0);
    } else {
      int32_t levels_of_undo;
      if (!bare_app_kit__read_int32(env, argv[1], "levels_of_undo", &levels_of_undo)) return NULL;

      undo_manager.levelsOfUndo = levels_of_undo;
    }
  }

  return result;
}

static void
bare_app_kit_undo_manager_levels_of_undo_typed(js_value_t *receiver, int32_t bare_tag, int32_t levels_of_undo, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSUndoManager *undo_manager = (NSUndoManager *) bare_object;

    undo_manager.levelsOfUndo = levels_of_undo;
  }
}

static js_value_t *
bare_app_kit_undo_manager_undo_action_name(js_env_t *env, js_callback_info_t *info) {
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
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    result = bare_app_kit__from_string(env, undo_manager.undoActionName);
  }

  return result;
}

static js_value_t *
bare_app_kit_undo_manager_redo_action_name(js_env_t *env, js_callback_info_t *info) {
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
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    result = bare_app_kit__from_string(env, undo_manager.redoActionName);
  }

  return result;
}

static js_value_t *
bare_app_kit_undo_manager_undo_menu_item_title(js_env_t *env, js_callback_info_t *info) {
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
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    result = bare_app_kit__from_string(env, undo_manager.undoMenuItemTitle);
  }

  return result;
}

static js_value_t *
bare_app_kit_undo_manager_redo_menu_item_title(js_env_t *env, js_callback_info_t *info) {
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
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    result = bare_app_kit__from_string(env, undo_manager.redoMenuItemTitle);
  }

  return result;
}

static js_value_t *
bare_app_kit_undo_manager_grouping_level(js_env_t *env, js_callback_info_t *info) {
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
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    err = js_create_int32(env, undo_manager.groupingLevel, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_undo_manager_undo(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    [undo_manager undo];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_undo_manager_redo(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    [undo_manager redo];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_undo_manager_undo_nested_group(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    [undo_manager undoNestedGroup];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_undo_manager_begin_undo_grouping(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    [undo_manager beginUndoGrouping];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_undo_manager_end_undo_grouping(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    [undo_manager endUndoGrouping];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_undo_manager_remove_all_actions(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    [undo_manager removeAllActions];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_undo_manager_disable_undo_registration(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    [undo_manager disableUndoRegistration];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_undo_manager_enable_undo_registration(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    [undo_manager enableUndoRegistration];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_undo_manager_set_action_name(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *name = bare_app_kit__to_string(env, argv[1]);

  @autoreleasepool {
    NSUndoManager *undo_manager = (__bridge NSUndoManager *) handle;

    [undo_manager setActionName:name];
  }

  return NULL;
}
