#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareMenu : NSMenu <NSMenuDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareMenu

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

- (void)menuWillOpen:(NSMenu *)menu {
  if ((mask & (1 << 0)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onwillopen");
}

- (void)menuDidClose:(NSMenu *)menu {
  if ((mask & (1 << 1)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidclose");
}

@end

static js_value_t *
bare_app_kit_menu_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  js_value_t *result;

  @autoreleasepool {
    NSString *title = bare_app_kit__to_string(env, argv[0]);

    BareMenu *handle = [[[BareMenu alloc] initWithTitle:title] autorelease];

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
bare_app_kit_menu_title(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, menu.title);
    } else {
      menu.title = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_autoenables_items(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, menu.autoenablesItems, &result);
      assert(err == 0);
    } else {
      bool autoenables_items;
      if (!bare_app_kit__read_bool(env, argv[1], "autoenables_items", &autoenables_items)) return NULL;

      menu.autoenablesItems = autoenables_items;
    }
  }

  return result;
}

static void
bare_app_kit_menu_autoenables_items_typed(js_value_t *receiver, int32_t bare_tag, bool autoenables_items, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMenu *menu = (NSMenu *) bare_object;

    menu.autoenablesItems = autoenables_items;
  }
}

static js_value_t *
bare_app_kit_menu_minimum_width(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    if (argc == 1) {
      err = js_create_double(env, menu.minimumWidth, &result);
      assert(err == 0);
    } else {
      double minimum_width;
      if (!bare_app_kit__read_double(env, argv[1], "minimum_width", &minimum_width)) return NULL;

      menu.minimumWidth = minimum_width;
    }
  }

  return result;
}

static void
bare_app_kit_menu_minimum_width_typed(js_value_t *receiver, int32_t bare_tag, double minimum_width, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMenu *menu = (NSMenu *) bare_object;

    menu.minimumWidth = minimum_width;
  }
}

static js_value_t *
bare_app_kit_menu_shows_state_column(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, menu.showsStateColumn, &result);
      assert(err == 0);
    } else {
      bool shows_state_column;
      if (!bare_app_kit__read_bool(env, argv[1], "shows_state_column", &shows_state_column)) return NULL;

      menu.showsStateColumn = shows_state_column;
    }
  }

  return result;
}

static void
bare_app_kit_menu_shows_state_column_typed(js_value_t *receiver, int32_t bare_tag, bool shows_state_column, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMenu *menu = (NSMenu *) bare_object;

    menu.showsStateColumn = shows_state_column;
  }
}

static js_value_t *
bare_app_kit_menu_allows_context_menu_plug_ins(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, menu.allowsContextMenuPlugIns, &result);
      assert(err == 0);
    } else {
      bool allows_context_menu_plug_ins;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_context_menu_plug_ins", &allows_context_menu_plug_ins)) return NULL;

      menu.allowsContextMenuPlugIns = allows_context_menu_plug_ins;
    }
  }

  return result;
}

static void
bare_app_kit_menu_allows_context_menu_plug_ins_typed(js_value_t *receiver, int32_t bare_tag, bool allows_context_menu_plug_ins, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMenu *menu = (NSMenu *) bare_object;

    menu.allowsContextMenuPlugIns = allows_context_menu_plug_ins;
  }
}

static js_value_t *
bare_app_kit_menu_size(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    result = bare_app_kit__from_size(env, menu.size);
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_size_into(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  uint32_t offset;
  if (!bare_app_kit__read_uint32(env, argv[2], "offset", &offset)) return NULL;

  double *out;

  if (!bare_app_kit__buffer(env, argv[1], offset, 2, &out)) {
    err = js_throw_type_error(env, NULL, "Expected an array buffer with room for 2 doubles");
    assert(err == 0);

    return NULL;
  }

  @autoreleasepool {
    NSMenu *menu = (__bridge NSMenu *) handle;

    __typeof__(menu.size) value = menu.size;

    out[0] = value.width;
    out[1] = value.height;
  }

  return NULL;
}

static void
bare_app_kit_menu_size_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSMenu *menu = (NSMenu *) bare_object;

    __typeof__(menu.size) value = menu.size;

    out[0] = value.width;
    out[1] = value.height;
  }
}

static js_value_t *
bare_app_kit_menu_highlighted_item(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    result = bare_foundation__bridge(env, menu.highlightedItem);
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_supermenu(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    result = bare_foundation__bridge(env, menu.supermenu);
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_font(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, menu.font);
    } else {
      menu.font = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_number_of_items(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    err = js_create_int32(env, menu.numberOfItems, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_add_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id item = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSMenu *menu = (__bridge NSMenu *) handle;

    [menu addItem:item];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_menu_insert_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id item = bare_foundation__to_object(env, argv[1]);

  int32_t index;
  if (!bare_app_kit__read_int32(env, argv[2], "index", &index)) return NULL;

  @autoreleasepool {
    NSMenu *menu = (__bridge NSMenu *) handle;

    [menu insertItem:item atIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_menu_remove_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id item = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSMenu *menu = (__bridge NSMenu *) handle;

    [menu removeItem:item];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_menu_remove_item_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    [menu removeItemAtIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_menu_remove_all_items(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSMenu *menu = (__bridge NSMenu *) handle;

    [menu removeAllItems];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_menu_item_at_index(js_env_t *env, js_callback_info_t *info) {
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

  js_value_t *result;

  @autoreleasepool {
    NSMenu *menu = (__bridge NSMenu *) handle;

    result = bare_foundation__bridge(env, [menu itemAtIndex:index]);
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_index_of_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id item = bare_foundation__to_object(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSMenu *menu = (__bridge NSMenu *) handle;

    result = bare_app_kit__from_index(env, [menu indexOfItem:item]);
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_pop_up_context_menu(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id view = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSMenu *menu = (__bridge NSMenu *) handle;

    [NSMenu popUpContextMenu:menu withEvent:[NSApp currentEvent] forView:view];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_menu_perform_action_for_item_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    [menu performActionForItemAtIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_menu_cancel_tracking(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSMenu *menu = (__bridge NSMenu *) handle;

    [menu cancelTracking];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_menu_update(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSMenu *menu = (__bridge NSMenu *) handle;

    [menu update];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_menu_index_of_item_with_title(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *title = bare_app_kit__to_string(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSMenu *menu = (__bridge NSMenu *) handle;

    result = bare_app_kit__from_index(env, [menu indexOfItemWithTitle:title]);
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_index_of_item_with_tag(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t tag;
  if (!bare_app_kit__read_int32(env, argv[1], "tag", &tag)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSMenu *menu = (__bridge NSMenu *) handle;

    result = bare_app_kit__from_index(env, [menu indexOfItemWithTag:tag]);
  }

  return result;
}

static js_value_t *
bare_app_kit_menu_items(js_env_t *env, js_callback_info_t *info) {
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
    NSMenu *menu = (__bridge NSMenu *) handle;

    result = bare_app_kit__from_objects(env, menu.itemArray);
  }

  return result;
}
