#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_save_panel_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 0;
  js_value_t *argv[0];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    NSSavePanel *handle = [NSSavePanel savePanel];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_save_panel_url(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    result = bare_app_kit__from_url(env, save_panel.URL);
  }

  return result;
}

static js_value_t *
bare_app_kit_save_panel_directory_url(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_url(env, save_panel.directoryURL);
    } else {
      save_panel.directoryURL = bare_app_kit__to_url(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_save_panel_name_field_string_value(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, save_panel.nameFieldStringValue);
    } else {
      save_panel.nameFieldStringValue = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_save_panel_name_field_label(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, save_panel.nameFieldLabel);
    } else {
      save_panel.nameFieldLabel = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_save_panel_message(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, save_panel.message);
    } else {
      save_panel.message = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_save_panel_prompt(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, save_panel.prompt);
    } else {
      save_panel.prompt = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_save_panel_can_create_directories(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, save_panel.canCreateDirectories, &result);
      assert(err == 0);
    } else {
      bool can_create_directories;
      if (!bare_app_kit__read_bool(env, argv[1], "can_create_directories", &can_create_directories)) return NULL;

      save_panel.canCreateDirectories = can_create_directories;
    }
  }

  return result;
}

static void
bare_app_kit_save_panel_can_create_directories_typed(js_value_t *receiver, int32_t bare_tag, bool can_create_directories, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSavePanel *save_panel = (NSSavePanel *) bare_object;

    save_panel.canCreateDirectories = can_create_directories;
  }
}

static js_value_t *
bare_app_kit_save_panel_can_select_hidden_extension(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, save_panel.canSelectHiddenExtension, &result);
      assert(err == 0);
    } else {
      bool can_select_hidden_extension;
      if (!bare_app_kit__read_bool(env, argv[1], "can_select_hidden_extension", &can_select_hidden_extension)) return NULL;

      save_panel.canSelectHiddenExtension = can_select_hidden_extension;
    }
  }

  return result;
}

static void
bare_app_kit_save_panel_can_select_hidden_extension_typed(js_value_t *receiver, int32_t bare_tag, bool can_select_hidden_extension, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSavePanel *save_panel = (NSSavePanel *) bare_object;

    save_panel.canSelectHiddenExtension = can_select_hidden_extension;
  }
}

static js_value_t *
bare_app_kit_save_panel_shows_hidden_files(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, save_panel.showsHiddenFiles, &result);
      assert(err == 0);
    } else {
      bool shows_hidden_files;
      if (!bare_app_kit__read_bool(env, argv[1], "shows_hidden_files", &shows_hidden_files)) return NULL;

      save_panel.showsHiddenFiles = shows_hidden_files;
    }
  }

  return result;
}

static void
bare_app_kit_save_panel_shows_hidden_files_typed(js_value_t *receiver, int32_t bare_tag, bool shows_hidden_files, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSavePanel *save_panel = (NSSavePanel *) bare_object;

    save_panel.showsHiddenFiles = shows_hidden_files;
  }
}

static js_value_t *
bare_app_kit_save_panel_shows_tag_field(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, save_panel.showsTagField, &result);
      assert(err == 0);
    } else {
      bool shows_tag_field;
      if (!bare_app_kit__read_bool(env, argv[1], "shows_tag_field", &shows_tag_field)) return NULL;

      save_panel.showsTagField = shows_tag_field;
    }
  }

  return result;
}

static void
bare_app_kit_save_panel_shows_tag_field_typed(js_value_t *receiver, int32_t bare_tag, bool shows_tag_field, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSavePanel *save_panel = (NSSavePanel *) bare_object;

    save_panel.showsTagField = shows_tag_field;
  }
}

static js_value_t *
bare_app_kit_save_panel_extension_hidden(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, save_panel.extensionHidden, &result);
      assert(err == 0);
    } else {
      bool extension_hidden;
      if (!bare_app_kit__read_bool(env, argv[1], "extension_hidden", &extension_hidden)) return NULL;

      save_panel.extensionHidden = extension_hidden;
    }
  }

  return result;
}

static void
bare_app_kit_save_panel_extension_hidden_typed(js_value_t *receiver, int32_t bare_tag, bool extension_hidden, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSavePanel *save_panel = (NSSavePanel *) bare_object;

    save_panel.extensionHidden = extension_hidden;
  }
}

static js_value_t *
bare_app_kit_save_panel_treats_file_packages_as_directories(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, save_panel.treatsFilePackagesAsDirectories, &result);
      assert(err == 0);
    } else {
      bool treats_file_packages_as_directories;
      if (!bare_app_kit__read_bool(env, argv[1], "treats_file_packages_as_directories", &treats_file_packages_as_directories)) return NULL;

      save_panel.treatsFilePackagesAsDirectories = treats_file_packages_as_directories;
    }
  }

  return result;
}

static void
bare_app_kit_save_panel_treats_file_packages_as_directories_typed(js_value_t *receiver, int32_t bare_tag, bool treats_file_packages_as_directories, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSavePanel *save_panel = (NSSavePanel *) bare_object;

    save_panel.treatsFilePackagesAsDirectories = treats_file_packages_as_directories;
  }
}

static js_value_t *
bare_app_kit_save_panel_accessory_view(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, save_panel.accessoryView);
    } else {
      save_panel.accessoryView = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_save_panel_allowed_content_types(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_types(env, save_panel.allowedContentTypes);
    } else {
      save_panel.allowedContentTypes = bare_app_kit__to_types(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_save_panel_run_modal(js_env_t *env, js_callback_info_t *info) {
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
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    err = js_create_int32(env, [save_panel runModal], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_save_panel_ok(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    [save_panel ok:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_save_panel_cancel(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    [save_panel cancel:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_save_panel_validate_visible_columns(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSSavePanel *save_panel = (__bridge NSSavePanel *) handle;

    [save_panel validateVisibleColumns];
  }

  return NULL;
}
