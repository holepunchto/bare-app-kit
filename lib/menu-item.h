#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareMenuItem : NSMenuItem <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareMenuItem

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
bare_app_kit_menu_item_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

  js_value_t *result;

  @autoreleasepool {
    NSString *title = bare_app_kit__to_string(env, argv[0]);

    NSString *key_equivalent = bare_app_kit__to_string(env, argv[1]);

    NSString *selector = bare_app_kit__to_string(env, argv[2]);

    // An item that names a selector is left without a target, which is what
    // sends it down the responder chain to whoever can perform it and what
    // lets the menu enable and disable it on its own. An item that names none
    // is the item's own to answer for.
    SEL action = selector.length == 0 ? @selector(onClick:) : NSSelectorFromString(selector);

    BareMenuItem *handle = [[[BareMenuItem alloc] initWithTitle:title action:action keyEquivalent:key_equivalent] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[3], 0, &handle->ctx);
    assert(err == 0);

    if (selector.length == 0) [handle setTarget:handle];
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_item_title(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, menu_item.title);
    } else {
      menu_item.title = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_item_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, menu_item.enabled, &result);
      assert(err == 0);
    } else {
      bool enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "enabled", &enabled)) return NULL;

      menu_item.enabled = enabled;
    }
  }

  return result;
}

static void
bare_app_kit_menu_item_enabled_typed(js_value_t *receiver, int32_t bare_tag, bool enabled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMenuItem *menu_item = (NSMenuItem *) bare_object;

    menu_item.enabled = enabled;
  }
}

static js_value_t *
bare_app_kit_menu_item_hidden(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, menu_item.hidden, &result);
      assert(err == 0);
    } else {
      bool hidden;
      if (!bare_app_kit__read_bool(env, argv[1], "hidden", &hidden)) return NULL;

      menu_item.hidden = hidden;
    }
  }

  return result;
}

static void
bare_app_kit_menu_item_hidden_typed(js_value_t *receiver, int32_t bare_tag, bool hidden, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMenuItem *menu_item = (NSMenuItem *) bare_object;

    menu_item.hidden = hidden;
  }
}

static js_value_t *
bare_app_kit_menu_item_state(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    if (argc == 1) {
      err = js_create_int32(env, menu_item.state, &result);
      assert(err == 0);
    } else {
      int32_t state;
      if (!bare_app_kit__read_int32(env, argv[1], "state", &state)) return NULL;

      menu_item.state = state;
    }
  }

  return result;
}

static void
bare_app_kit_menu_item_state_typed(js_value_t *receiver, int32_t bare_tag, int32_t state, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMenuItem *menu_item = (NSMenuItem *) bare_object;

    menu_item.state = state;
  }
}

static js_value_t *
bare_app_kit_menu_item_tag(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    if (argc == 1) {
      err = js_create_int32(env, menu_item.tag, &result);
      assert(err == 0);
    } else {
      int32_t tag;
      if (!bare_app_kit__read_int32(env, argv[1], "tag", &tag)) return NULL;

      menu_item.tag = tag;
    }
  }

  return result;
}

static void
bare_app_kit_menu_item_tag_typed(js_value_t *receiver, int32_t bare_tag, int32_t tag, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMenuItem *menu_item = (NSMenuItem *) bare_object;

    menu_item.tag = tag;
  }
}

static js_value_t *
bare_app_kit_menu_item_tool_tip(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, menu_item.toolTip);
    } else {
      menu_item.toolTip = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_item_indentation_level(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    if (argc == 1) {
      err = js_create_int32(env, menu_item.indentationLevel, &result);
      assert(err == 0);
    } else {
      int32_t indentation_level;
      if (!bare_app_kit__read_int32(env, argv[1], "indentation_level", &indentation_level)) return NULL;

      menu_item.indentationLevel = indentation_level;
    }
  }

  return result;
}

static void
bare_app_kit_menu_item_indentation_level_typed(js_value_t *receiver, int32_t bare_tag, int32_t indentation_level, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMenuItem *menu_item = (NSMenuItem *) bare_object;

    menu_item.indentationLevel = indentation_level;
  }
}

static js_value_t *
bare_app_kit_menu_item_key_equivalent(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, menu_item.keyEquivalent);
    } else {
      menu_item.keyEquivalent = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_item_key_equivalent_modifier_mask(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    if (argc == 1) {
      err = js_create_int32(env, menu_item.keyEquivalentModifierMask, &result);
      assert(err == 0);
    } else {
      int32_t key_equivalent_modifier_mask;
      if (!bare_app_kit__read_int32(env, argv[1], "key_equivalent_modifier_mask", &key_equivalent_modifier_mask)) return NULL;

      menu_item.keyEquivalentModifierMask = key_equivalent_modifier_mask;
    }
  }

  return result;
}

static void
bare_app_kit_menu_item_key_equivalent_modifier_mask_typed(js_value_t *receiver, int32_t bare_tag, int32_t key_equivalent_modifier_mask, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMenuItem *menu_item = (NSMenuItem *) bare_object;

    menu_item.keyEquivalentModifierMask = key_equivalent_modifier_mask;
  }
}

static js_value_t *
bare_app_kit_menu_item_image(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, menu_item.image);
    } else {
      menu_item.image = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_item_submenu(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, menu_item.submenu);
    } else {
      menu_item.submenu = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_item_attributed_title(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, menu_item.attributedTitle);
    } else {
      menu_item.attributedTitle = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_item_separator_item(js_env_t *env, js_callback_info_t *info) {
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
    NSMenuItem *menu_item = (__bridge NSMenuItem *) handle;

    err = js_get_boolean(env, menu_item.separatorItem, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_item_separator(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSMenuItem separatorItem]);
  }

  return result;
}
