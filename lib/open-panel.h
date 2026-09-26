#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_open_panel_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 0;
  js_value_t *argv[0];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    NSOpenPanel *handle = [NSOpenPanel openPanel];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_open_panel_urls(js_env_t *env, js_callback_info_t *info) {
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
    NSOpenPanel *open_panel = (__bridge NSOpenPanel *) handle;

    result = bare_app_kit__from_urls(env, open_panel.URLs);
  }

  return result;
}

static js_value_t *
bare_app_kit_open_panel_can_choose_files(js_env_t *env, js_callback_info_t *info) {
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
    NSOpenPanel *open_panel = (__bridge NSOpenPanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, open_panel.canChooseFiles, &result);
      assert(err == 0);
    } else {
      bool can_choose_files;
      if (!bare_app_kit__read_bool(env, argv[1], "can_choose_files", &can_choose_files)) return NULL;

      open_panel.canChooseFiles = can_choose_files;
    }
  }

  return result;
}

static void
bare_app_kit_open_panel_can_choose_files_typed(js_value_t *receiver, int32_t bare_tag, bool can_choose_files, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSOpenPanel *open_panel = (NSOpenPanel *) bare_object;

    open_panel.canChooseFiles = can_choose_files;
  }
}

static js_value_t *
bare_app_kit_open_panel_can_choose_directories(js_env_t *env, js_callback_info_t *info) {
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
    NSOpenPanel *open_panel = (__bridge NSOpenPanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, open_panel.canChooseDirectories, &result);
      assert(err == 0);
    } else {
      bool can_choose_directories;
      if (!bare_app_kit__read_bool(env, argv[1], "can_choose_directories", &can_choose_directories)) return NULL;

      open_panel.canChooseDirectories = can_choose_directories;
    }
  }

  return result;
}

static void
bare_app_kit_open_panel_can_choose_directories_typed(js_value_t *receiver, int32_t bare_tag, bool can_choose_directories, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSOpenPanel *open_panel = (NSOpenPanel *) bare_object;

    open_panel.canChooseDirectories = can_choose_directories;
  }
}

static js_value_t *
bare_app_kit_open_panel_allows_multiple_selection(js_env_t *env, js_callback_info_t *info) {
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
    NSOpenPanel *open_panel = (__bridge NSOpenPanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, open_panel.allowsMultipleSelection, &result);
      assert(err == 0);
    } else {
      bool allows_multiple_selection;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_multiple_selection", &allows_multiple_selection)) return NULL;

      open_panel.allowsMultipleSelection = allows_multiple_selection;
    }
  }

  return result;
}

static void
bare_app_kit_open_panel_allows_multiple_selection_typed(js_value_t *receiver, int32_t bare_tag, bool allows_multiple_selection, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSOpenPanel *open_panel = (NSOpenPanel *) bare_object;

    open_panel.allowsMultipleSelection = allows_multiple_selection;
  }
}

static js_value_t *
bare_app_kit_open_panel_resolves_aliases(js_env_t *env, js_callback_info_t *info) {
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
    NSOpenPanel *open_panel = (__bridge NSOpenPanel *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, open_panel.resolvesAliases, &result);
      assert(err == 0);
    } else {
      bool resolves_aliases;
      if (!bare_app_kit__read_bool(env, argv[1], "resolves_aliases", &resolves_aliases)) return NULL;

      open_panel.resolvesAliases = resolves_aliases;
    }
  }

  return result;
}

static void
bare_app_kit_open_panel_resolves_aliases_typed(js_value_t *receiver, int32_t bare_tag, bool resolves_aliases, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSOpenPanel *open_panel = (NSOpenPanel *) bare_object;

    open_panel.resolvesAliases = resolves_aliases;
  }
}
