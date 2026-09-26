#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

// An `NSToolbar` asks its delegate for items by identifier, which would mean
// calling synchronously into JavaScript for a return value. Instead the items
// are registered up front and the delegate answers from that registry.
@interface BareToolbar : NSToolbar <NSToolbarDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;

  NSMutableDictionary<NSToolbarItemIdentifier, NSToolbarItem *> *registry;
  NSArray<NSToolbarItemIdentifier> *allowed;
  NSArray<NSToolbarItemIdentifier> *defaults;
}

@end

@implementation BareToolbar

- (int32_t)eventMask {
  return mask;
}

- (void)setEventMask:(int32_t)value {
  mask = value;
}

- (void)dealloc {
  int err;

  err = js_delete_reference(env, ctx);
  assert(err == 0);

  [registry release];
  [allowed release];
  [defaults release];

  [super dealloc];
}

- (NSToolbarItem *)toolbar:(NSToolbar *)toolbar itemForItemIdentifier:(NSToolbarItemIdentifier)identifier willBeInsertedIntoToolbar:(BOOL)flag {
  return registry[identifier];
}

- (NSArray<NSToolbarItemIdentifier> *)toolbarAllowedItemIdentifiers:(NSToolbar *)toolbar {
  return allowed ? allowed : registry.allKeys;
}

- (NSArray<NSToolbarItemIdentifier> *)toolbarDefaultItemIdentifiers:(NSToolbar *)toolbar {
  return defaults ? defaults : registry.allKeys;
}

- (void)toolbarWillAddItem:(NSNotification *)notification {
  if (mask & (1 << 0)) bare_app_kit__emit(env, ctx, "_onwilladditem");
}

- (void)toolbarDidRemoveItem:(NSNotification *)notification {
  if (mask & (1 << 1)) bare_app_kit__emit(env, ctx, "_ondidremoveitem");
}

@end

static js_value_t *
bare_app_kit_toolbar_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  js_value_t *result;

  @autoreleasepool {
    NSString *identifier = bare_app_kit__to_string(env, argv[0]);

    BareToolbar *handle = [[[BareToolbar alloc] initWithIdentifier:identifier] autorelease];

    handle->registry = [[NSMutableDictionary alloc] init];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[1], 0, &handle->ctx);
    assert(err == 0);

    [handle setDelegate:handle];
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_register_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    BareToolbar *toolbar = (__bridge BareToolbar *) handle;
    NSToolbarItem *item = bare_foundation__to_object(env, argv[1]);

    toolbar->registry[item.itemIdentifier] = item;
  }

  return NULL;
}

static js_value_t *
bare_app_kit_toolbar_allowed_item_identifiers(js_env_t *env, js_callback_info_t *info) {
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
    BareToolbar *toolbar = (__bridge BareToolbar *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_strings(env, [toolbar toolbarAllowedItemIdentifiers:toolbar]);
    } else {
      NSArray<NSString *> *identifiers = bare_app_kit__to_strings(env, argv[1]);

      [toolbar->allowed release];
      toolbar->allowed = [identifiers retain];
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_default_item_identifiers(js_env_t *env, js_callback_info_t *info) {
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
    BareToolbar *toolbar = (__bridge BareToolbar *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_strings(env, [toolbar toolbarDefaultItemIdentifiers:toolbar]);
    } else {
      NSArray<NSString *> *identifiers = bare_app_kit__to_strings(env, argv[1]);

      [toolbar->defaults release];
      toolbar->defaults = [identifiers retain];
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_identifier(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    result = bare_app_kit__from_string(env, toolbar.identifier);
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_display_mode(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    if (argc == 1) {
      err = js_create_int32(env, toolbar.displayMode, &result);
      assert(err == 0);
    } else {
      int32_t display_mode;
      if (!bare_app_kit__read_int32(env, argv[1], "display_mode", &display_mode)) return NULL;

      toolbar.displayMode = display_mode;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_selected_item_identifier(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, toolbar.selectedItemIdentifier);
    } else {
      toolbar.selectedItemIdentifier = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_centered_item_identifiers(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    result = bare_app_kit__from_strings(env, (NSArray<NSString *> *) [toolbar.centeredItemIdentifiers allObjects]);
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_visible(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, toolbar.visible, &result);
      assert(err == 0);
    } else {
      bool visible;
      if (!bare_app_kit__read_bool(env, argv[1], "visible", &visible)) return NULL;

      toolbar.visible = visible;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_allows_user_customization(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, toolbar.allowsUserCustomization, &result);
      assert(err == 0);
    } else {
      bool allows_user_customization;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_user_customization", &allows_user_customization)) return NULL;

      toolbar.allowsUserCustomization = allows_user_customization;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_allows_extension_items(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, toolbar.allowsExtensionItems, &result);
      assert(err == 0);
    } else {
      bool allows_extension_items;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_extension_items", &allows_extension_items)) return NULL;

      toolbar.allowsExtensionItems = allows_extension_items;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_autosaves_configuration(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, toolbar.autosavesConfiguration, &result);
      assert(err == 0);
    } else {
      bool autosaves_configuration;
      if (!bare_app_kit__read_bool(env, argv[1], "autosaves_configuration", &autosaves_configuration)) return NULL;

      toolbar.autosavesConfiguration = autosaves_configuration;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_customization_palette_is_running(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    err = js_get_boolean(env, toolbar.customizationPaletteIsRunning, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_insert_item_with_item_identifier(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *identifier = bare_app_kit__to_string(env, argv[1]);

  int32_t index;
  if (!bare_app_kit__read_int32(env, argv[2], "index", &index)) return NULL;

  @autoreleasepool {
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    [toolbar insertItemWithItemIdentifier:identifier atIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_toolbar_remove_item_at_index(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t index;
  if (!bare_app_kit__read_int32(env, argv[1], "index", &index)) return NULL;

  @autoreleasepool {
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    [toolbar removeItemAtIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_toolbar_run_customization_palette(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    [toolbar runCustomizationPalette:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_toolbar_validate_visible_items(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    [toolbar validateVisibleItems];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_toolbar_set_centered_item_identifiers(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSArray<NSString *> *identifiers = bare_app_kit__to_strings(env, argv[1]);

  @autoreleasepool {
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    [toolbar setCenteredItemIdentifiers:[NSSet setWithArray:identifiers]];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_toolbar_items(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbar *toolbar = (__bridge NSToolbar *) handle;

    result = bare_app_kit__from_objects(env, toolbar.items);
  }

  return result;
}
