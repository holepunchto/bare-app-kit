#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BarePopUpButton : NSPopUpButton <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BarePopUpButton

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

- (void)mouseDown:(NSEvent *)event {
  if ((mask & (1 << 0)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onmousedown");

  [super mouseDown:event];
}

- (void)onClick:(id)sender {
  if ((mask & (1 << 1)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onclick");
}

@end

static js_value_t *
bare_app_kit_pop_up_button_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 6;
  js_value_t *argv[6];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 6);

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

  bool pulls_down;
  if (!bare_app_kit__read_bool(env, argv[4], "pulls_down", &pulls_down)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    BarePopUpButton *handle = [[[BarePopUpButton alloc]
      initWithFrame:NSMakeRect(x, y, width, height)
      pullsDown:pulls_down] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[5], 0, &handle->ctx);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onClick:)];
  }

  return result;
}

static js_value_t *
bare_app_kit_pop_up_button_pulls_down(js_env_t *env, js_callback_info_t *info) {
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
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, pop_up_button.pullsDown, &result);
      assert(err == 0);
    } else {
      bool pulls_down;
      if (!bare_app_kit__read_bool(env, argv[1], "pulls_down", &pulls_down)) return NULL;

      pop_up_button.pullsDown = pulls_down;
    }
  }

  return result;
}

static void
bare_app_kit_pop_up_button_pulls_down_typed(js_value_t *receiver, int32_t bare_tag, bool pulls_down, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSPopUpButton *pop_up_button = (NSPopUpButton *) bare_object;

    pop_up_button.pullsDown = pulls_down;
  }
}

static js_value_t *
bare_app_kit_pop_up_button_autoenables_items(js_env_t *env, js_callback_info_t *info) {
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
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, pop_up_button.autoenablesItems, &result);
      assert(err == 0);
    } else {
      bool autoenables_items;
      if (!bare_app_kit__read_bool(env, argv[1], "autoenables_items", &autoenables_items)) return NULL;

      pop_up_button.autoenablesItems = autoenables_items;
    }
  }

  return result;
}

static void
bare_app_kit_pop_up_button_autoenables_items_typed(js_value_t *receiver, int32_t bare_tag, bool autoenables_items, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSPopUpButton *pop_up_button = (NSPopUpButton *) bare_object;

    pop_up_button.autoenablesItems = autoenables_items;
  }
}

static js_value_t *
bare_app_kit_pop_up_button_preferred_edge(js_env_t *env, js_callback_info_t *info) {
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
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    if (argc == 1) {
      err = js_create_int32(env, pop_up_button.preferredEdge, &result);
      assert(err == 0);
    } else {
      int32_t preferred_edge;
      if (!bare_app_kit__read_int32(env, argv[1], "preferred_edge", &preferred_edge)) return NULL;

      pop_up_button.preferredEdge = preferred_edge;
    }
  }

  return result;
}

static void
bare_app_kit_pop_up_button_preferred_edge_typed(js_value_t *receiver, int32_t bare_tag, int32_t preferred_edge, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSPopUpButton *pop_up_button = (NSPopUpButton *) bare_object;

    pop_up_button.preferredEdge = preferred_edge;
  }
}

static js_value_t *
bare_app_kit_pop_up_button_number_of_items(js_env_t *env, js_callback_info_t *info) {
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
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    err = js_create_int32(env, pop_up_button.numberOfItems, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_pop_up_button_index_of_selected_item(js_env_t *env, js_callback_info_t *info) {
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
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    result = bare_app_kit__from_index(env, pop_up_button.indexOfSelectedItem);
  }

  return result;
}

static js_value_t *
bare_app_kit_pop_up_button_title_of_selected_item(js_env_t *env, js_callback_info_t *info) {
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
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    result = bare_app_kit__from_string(env, pop_up_button.titleOfSelectedItem);
  }

  return result;
}

static js_value_t *
bare_app_kit_pop_up_button_menu(js_env_t *env, js_callback_info_t *info) {
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
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, pop_up_button.menu);
    } else {
      pop_up_button.menu = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_pop_up_button_item_titles(js_env_t *env, js_callback_info_t *info) {
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
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    result = bare_app_kit__from_strings(env, pop_up_button.itemTitles);
  }

  return result;
}

static js_value_t *
bare_app_kit_pop_up_button_add_item_with_title(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *title = bare_app_kit__to_string(env, argv[1]);

  @autoreleasepool {
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    [pop_up_button addItemWithTitle:title];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_pop_up_button_add_items_with_titles(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSArray<NSString *> *titles = bare_app_kit__to_strings(env, argv[1]);

  @autoreleasepool {
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    [pop_up_button addItemsWithTitles:titles];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_pop_up_button_insert_item_with_title(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *title = bare_app_kit__to_string(env, argv[1]);

  int32_t index;
  if (!bare_app_kit__read_int32(env, argv[2], "index", &index)) return NULL;

  @autoreleasepool {
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    [pop_up_button insertItemWithTitle:title atIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_pop_up_button_remove_item_with_title(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *title = bare_app_kit__to_string(env, argv[1]);

  @autoreleasepool {
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    [pop_up_button removeItemWithTitle:title];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_pop_up_button_remove_item_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    [pop_up_button removeItemAtIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_pop_up_button_remove_all_items(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    [pop_up_button removeAllItems];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_pop_up_button_select_item_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    [pop_up_button selectItemAtIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_pop_up_button_select_item_with_title(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *title = bare_app_kit__to_string(env, argv[1]);

  @autoreleasepool {
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    [pop_up_button selectItemWithTitle:title];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_pop_up_button_item_title_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    result = bare_app_kit__from_string(env, [pop_up_button itemTitleAtIndex:index]);
  }

  return result;
}

static js_value_t *
bare_app_kit_pop_up_button_index_of_item_with_title(js_env_t *env, js_callback_info_t *info) {
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
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    result = bare_app_kit__from_index(env, [pop_up_button indexOfItemWithTitle:title]);
  }

  return result;
}

static js_value_t *
bare_app_kit_pop_up_button_synchronize_title_and_selected_item(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSPopUpButton *pop_up_button = (__bridge NSPopUpButton *) handle;

    [pop_up_button synchronizeTitleAndSelectedItem];
  }

  return NULL;
}
