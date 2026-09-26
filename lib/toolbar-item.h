#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareToolbarItem : NSToolbarItem <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareToolbarItem

- (void)dealloc {
  int err;

  err = js_delete_reference(env, ctx);
  assert(err == 0);

  [super dealloc];
}

- (int32_t)eventMask {
  return mask;
}

- (void)setEventMask:(int32_t)value {
  mask = value;
}

- (void)onClick:(id)sender {
  if ((mask & (1 << 0)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onclick");
}

@end

static js_value_t *
bare_app_kit_toolbar_item_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  js_value_t *result;

  @autoreleasepool {
    NSString *identifier = bare_app_kit__to_string(env, argv[0]);

    BareToolbarItem *handle = [[[BareToolbarItem alloc] initWithItemIdentifier:identifier] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[1], 0, &handle->ctx);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onClick:)];
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_item_item_identifier(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    result = bare_app_kit__from_string(env, toolbar_item.itemIdentifier);
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_item_label(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, toolbar_item.label);
    } else {
      toolbar_item.label = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_item_palette_label(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, toolbar_item.paletteLabel);
    } else {
      toolbar_item.paletteLabel = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_item_tool_tip(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, toolbar_item.toolTip);
    } else {
      toolbar_item.toolTip = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_item_title(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, toolbar_item.title);
    } else {
      toolbar_item.title = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_item_tag(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      err = js_create_int32(env, toolbar_item.tag, &result);
      assert(err == 0);
    } else {
      int32_t tag;
      if (!bare_app_kit__read_int32(env, argv[1], "tag", &tag)) return NULL;

      toolbar_item.tag = tag;
    }
  }

  return result;
}

static void
bare_app_kit_toolbar_item_tag_typed(js_value_t *receiver, int32_t bare_tag, int32_t tag, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSToolbarItem *toolbar_item = (NSToolbarItem *) bare_object;

    toolbar_item.tag = tag;
  }
}

static js_value_t *
bare_app_kit_toolbar_item_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, toolbar_item.enabled, &result);
      assert(err == 0);
    } else {
      bool enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "enabled", &enabled)) return NULL;

      toolbar_item.enabled = enabled;
    }
  }

  return result;
}

static void
bare_app_kit_toolbar_item_enabled_typed(js_value_t *receiver, int32_t bare_tag, bool enabled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSToolbarItem *toolbar_item = (NSToolbarItem *) bare_object;

    toolbar_item.enabled = enabled;
  }
}

static js_value_t *
bare_app_kit_toolbar_item_bordered(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, toolbar_item.bordered, &result);
      assert(err == 0);
    } else {
      bool bordered;
      if (!bare_app_kit__read_bool(env, argv[1], "bordered", &bordered)) return NULL;

      toolbar_item.bordered = bordered;
    }
  }

  return result;
}

static void
bare_app_kit_toolbar_item_bordered_typed(js_value_t *receiver, int32_t bare_tag, bool bordered, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSToolbarItem *toolbar_item = (NSToolbarItem *) bare_object;

    toolbar_item.bordered = bordered;
  }
}

static js_value_t *
bare_app_kit_toolbar_item_navigational(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, toolbar_item.navigational, &result);
      assert(err == 0);
    } else {
      bool navigational;
      if (!bare_app_kit__read_bool(env, argv[1], "navigational", &navigational)) return NULL;

      toolbar_item.navigational = navigational;
    }
  }

  return result;
}

static void
bare_app_kit_toolbar_item_navigational_typed(js_value_t *receiver, int32_t bare_tag, bool navigational, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSToolbarItem *toolbar_item = (NSToolbarItem *) bare_object;

    toolbar_item.navigational = navigational;
  }
}

static js_value_t *
bare_app_kit_toolbar_item_autovalidates(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, toolbar_item.autovalidates, &result);
      assert(err == 0);
    } else {
      bool autovalidates;
      if (!bare_app_kit__read_bool(env, argv[1], "autovalidates", &autovalidates)) return NULL;

      toolbar_item.autovalidates = autovalidates;
    }
  }

  return result;
}

static void
bare_app_kit_toolbar_item_autovalidates_typed(js_value_t *receiver, int32_t bare_tag, bool autovalidates, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSToolbarItem *toolbar_item = (NSToolbarItem *) bare_object;

    toolbar_item.autovalidates = autovalidates;
  }
}

static js_value_t *
bare_app_kit_toolbar_item_visible(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    err = js_get_boolean(env, toolbar_item.visible, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_item_visibility_priority(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      err = js_create_int32(env, toolbar_item.visibilityPriority, &result);
      assert(err == 0);
    } else {
      int32_t visibility_priority;
      if (!bare_app_kit__read_int32(env, argv[1], "visibility_priority", &visibility_priority)) return NULL;

      toolbar_item.visibilityPriority = visibility_priority;
    }
  }

  return result;
}

static void
bare_app_kit_toolbar_item_visibility_priority_typed(js_value_t *receiver, int32_t bare_tag, int32_t visibility_priority, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSToolbarItem *toolbar_item = (NSToolbarItem *) bare_object;

    toolbar_item.visibilityPriority = visibility_priority;
  }
}

static js_value_t *
bare_app_kit_toolbar_item_image(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, toolbar_item.image);
    } else {
      toolbar_item.image = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_item_view(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, toolbar_item.view);
    } else {
      toolbar_item.view = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_toolbar_item_menu_form_representation(js_env_t *env, js_callback_info_t *info) {
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
    NSToolbarItem *toolbar_item = (__bridge NSToolbarItem *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, toolbar_item.menuFormRepresentation);
    } else {
      toolbar_item.menuFormRepresentation = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}
