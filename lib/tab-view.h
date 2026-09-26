#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareTabView : NSTabView <NSTabViewDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareTabView

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

- (void)tabView:(NSTabView *)tabView didSelectTabViewItem:(NSTabViewItem *)item {
  if ((mask & (1 << 0)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidselect");
}

@end

static js_value_t *
bare_app_kit_tab_view_init(js_env_t *env, js_callback_info_t *info) {
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
    BareTabView *handle = [[[BareTabView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    [handle setDelegate:handle];
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_tab_view_type(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, tab_view.tabViewType, &result);
      assert(err == 0);
    } else {
      int32_t tab_view_type;
      if (!bare_app_kit__read_int32(env, argv[1], "tab_view_type", &tab_view_type)) return NULL;

      tab_view.tabViewType = tab_view_type;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_tab_position(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, tab_view.tabPosition, &result);
      assert(err == 0);
    } else {
      int32_t tab_position;
      if (!bare_app_kit__read_int32(env, argv[1], "tab_position", &tab_position)) return NULL;

      tab_view.tabPosition = tab_position;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_font(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, tab_view.font);
    } else {
      tab_view.font = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_number_of_tab_view_items(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    err = js_create_int32(env, tab_view.numberOfTabViewItems, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_allows_truncated_labels(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, tab_view.allowsTruncatedLabels, &result);
      assert(err == 0);
    } else {
      bool allows_truncated_labels;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_truncated_labels", &allows_truncated_labels)) return NULL;

      tab_view.allowsTruncatedLabels = allows_truncated_labels;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_draws_background(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, tab_view.drawsBackground, &result);
      assert(err == 0);
    } else {
      bool draws_background;
      if (!bare_app_kit__read_bool(env, argv[1], "draws_background", &draws_background)) return NULL;

      tab_view.drawsBackground = draws_background;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_control_size(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, tab_view.controlSize, &result);
      assert(err == 0);
    } else {
      int32_t control_size;
      if (!bare_app_kit__read_int32(env, argv[1], "control_size", &control_size)) return NULL;

      tab_view.controlSize = control_size;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_tab_view_border_type(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, tab_view.tabViewBorderType, &result);
      assert(err == 0);
    } else {
      int32_t tab_view_border_type;
      if (!bare_app_kit__read_int32(env, argv[1], "tab_view_border_type", &tab_view_border_type)) return NULL;

      tab_view.tabViewBorderType = tab_view_border_type;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_content_rect(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    result = bare_app_kit__from_rect(env, tab_view.contentRect);
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_minimum_size(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    result = bare_app_kit__from_size(env, tab_view.minimumSize);
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_index_of_selected_tab_view_item(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    result = bare_app_kit__from_index(env, [tab_view indexOfTabViewItem:tab_view.selectedTabViewItem]);
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_add_tab_view_item(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    [tab_view addTabViewItem:item];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_tab_view_insert_tab_view_item(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    [tab_view insertTabViewItem:item atIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_tab_view_remove_tab_view_item(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    [tab_view removeTabViewItem:item];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_tab_view_select_tab_view_item_at_index(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    [tab_view selectTabViewItemAtIndex:index];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_tab_view_index_of_tab_view_item(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    result = bare_app_kit__from_index(env, [tab_view indexOfTabViewItem:item]);
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_tab_view_items(js_env_t *env, js_callback_info_t *info) {
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
    NSTabView *tab_view = (__bridge NSTabView *) handle;

    result = bare_app_kit__from_objects(env, tab_view.tabViewItems);
  }

  return result;
}
