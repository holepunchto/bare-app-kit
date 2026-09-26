#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareComboBox : NSComboBox <NSComboBoxDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareComboBox

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

- (void)onChange:(id)sender {
  if ((mask & (1 << 0)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onchange");
}

- (void)controlTextDidChange:(NSNotification *)notification {
  if ((mask & (1 << 1)) == 0) return;

  bare_app_kit__emit(env, ctx, "_oninput");
}

- (void)controlTextDidBeginEditing:(NSNotification *)notification {
  if ((mask & (1 << 2)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onbeginediting");
}

- (void)controlTextDidEndEditing:(NSNotification *)notification {
  if ((mask & (1 << 3)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onendediting");
}

- (void)comboBoxSelectionDidChange:(NSNotification *)notification {
  if ((mask & (1 << 4)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onselectionchange");
}

- (void)comboBoxWillPopUp:(NSNotification *)notification {
  if ((mask & (1 << 5)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onwillpopup");
}

- (void)comboBoxWillDismiss:(NSNotification *)notification {
  if ((mask & (1 << 6)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onwilldismiss");
}

@end

static js_value_t *
bare_app_kit_combo_box_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 5);

  double x;
  err = js_get_value_double(env, argv[0], &x);
  assert(err == 0);

  double y;
  err = js_get_value_double(env, argv[1], &y);
  assert(err == 0);

  double width;
  err = js_get_value_double(env, argv[2], &width);
  assert(err == 0);

  double height;
  err = js_get_value_double(env, argv[3], &height);
  assert(err == 0);

  js_value_t *result;

  @autoreleasepool {
    BareComboBox *handle = [[[BareComboBox alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onChange:)];
    [handle setDelegate:handle];
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_has_vertical_scroller(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, combo_box.hasVerticalScroller, &result);
      assert(err == 0);
    } else {
      bool has_vertical_scroller;
      if (!bare_app_kit__read_bool(env, argv[1], "has_vertical_scroller", &has_vertical_scroller)) return NULL;

      combo_box.hasVerticalScroller = has_vertical_scroller;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_number_of_visible_items(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    if (argc == 1) {
      err = js_create_int32(env, combo_box.numberOfVisibleItems, &result);
      assert(err == 0);
    } else {
      int32_t number_of_visible_items;
      if (!bare_app_kit__read_int32(env, argv[1], "number_of_visible_items", &number_of_visible_items)) return NULL;

      combo_box.numberOfVisibleItems = number_of_visible_items;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_uses_data_source(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, combo_box.usesDataSource, &result);
      assert(err == 0);
    } else {
      bool uses_data_source;
      if (!bare_app_kit__read_bool(env, argv[1], "uses_data_source", &uses_data_source)) return NULL;

      combo_box.usesDataSource = uses_data_source;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_completes(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, combo_box.completes, &result);
      assert(err == 0);
    } else {
      bool completes;
      if (!bare_app_kit__read_bool(env, argv[1], "completes", &completes)) return NULL;

      combo_box.completes = completes;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_button_bordered(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, combo_box.buttonBordered, &result);
      assert(err == 0);
    } else {
      bool button_bordered;
      if (!bare_app_kit__read_bool(env, argv[1], "button_bordered", &button_bordered)) return NULL;

      combo_box.buttonBordered = button_bordered;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_item_height(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    if (argc == 1) {
      err = js_create_double(env, combo_box.itemHeight, &result);
      assert(err == 0);
    } else {
      double item_height;
      if (!bare_app_kit__read_double(env, argv[1], "item_height", &item_height)) return NULL;

      combo_box.itemHeight = item_height;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_intercell_spacing(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, combo_box.intercellSpacing);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      combo_box.intercellSpacing = NSMakeSize(width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_number_of_items(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    err = js_create_int32(env, combo_box.numberOfItems, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_index_of_selected_item(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    result = bare_app_kit__from_index(env, combo_box.indexOfSelectedItem);
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_object_value_of_selected_item(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    result = bare_app_kit__from_string(env, (NSString *) combo_box.objectValueOfSelectedItem);
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_object_values(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    result = bare_app_kit__from_strings(env, combo_box.objectValues);
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_add_item_with_object_value(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *value = bare_app_kit__to_string(env, argv[1]);

  @autoreleasepool {
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    [combo_box addItemWithObjectValue:value];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_combo_box_insert_item_with_object_value(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *value = bare_app_kit__to_string(env, argv[1]);

  int32_t index;
  if (!bare_app_kit__read_int32(env, argv[2], "index", &index)) return NULL;

  @autoreleasepool {
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    [combo_box insertItemWithObjectValue:value atIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_combo_box_remove_item_with_object_value(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *value = bare_app_kit__to_string(env, argv[1]);

  @autoreleasepool {
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    [combo_box removeItemWithObjectValue:value];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_combo_box_remove_item_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    [combo_box removeItemAtIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_combo_box_remove_all_items(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    [combo_box removeAllItems];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_combo_box_select_item_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    [combo_box selectItemAtIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_combo_box_deselect_item_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    [combo_box deselectItemAtIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_combo_box_select_item_with_object_value(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *value = bare_app_kit__to_string(env, argv[1]);

  @autoreleasepool {
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    [combo_box selectItemWithObjectValue:value];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_combo_box_item_object_value_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    result = bare_app_kit__from_string(env, (NSString *) [combo_box itemObjectValueAtIndex:index]);
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_index_of_item_with_object_value(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *value = bare_app_kit__to_string(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    result = bare_app_kit__from_index(env, [combo_box indexOfItemWithObjectValue:value]);
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_box_reload_data(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    [combo_box reloadData];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_combo_box_note_number_of_items_changed(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    [combo_box noteNumberOfItemsChanged];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_combo_box_scroll_item_at_index_to_top(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    [combo_box scrollItemAtIndexToTop:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_combo_box_scroll_item_at_index_to_visible(js_env_t *env, js_callback_info_t *info) {
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
    NSComboBox *combo_box = (__bridge NSComboBox *) handle;

    [combo_box scrollItemAtIndexToVisible:index];
  }

  return NULL;
}
