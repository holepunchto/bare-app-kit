#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_tab_view_item_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 0;
  js_value_t *argv[0];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    NSTabViewItem *handle = [[[NSTabViewItem alloc] initWithIdentifier:nil] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_item_label(js_env_t *env, js_callback_info_t *info) {
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
    NSTabViewItem *tab_view_item = (__bridge NSTabViewItem *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, tab_view_item.label);
    } else {
      tab_view_item.label = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_item_tool_tip(js_env_t *env, js_callback_info_t *info) {
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
    NSTabViewItem *tab_view_item = (__bridge NSTabViewItem *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, tab_view_item.toolTip);
    } else {
      tab_view_item.toolTip = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_item_view(js_env_t *env, js_callback_info_t *info) {
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
    NSTabViewItem *tab_view_item = (__bridge NSTabViewItem *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, tab_view_item.view);
    } else {
      tab_view_item.view = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_tab_view_item_image(js_env_t *env, js_callback_info_t *info) {
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
    NSTabViewItem *tab_view_item = (__bridge NSTabViewItem *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, tab_view_item.image);
    } else {
      tab_view_item.image = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}
