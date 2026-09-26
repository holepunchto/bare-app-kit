#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BarePathControl : NSPathControl <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BarePathControl

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

@end

static js_value_t *
bare_app_kit_path_control_init(js_env_t *env, js_callback_info_t *info) {
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
    BarePathControl *handle = [[[BarePathControl alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onChange:)];
  }

  return result;
}

static js_value_t *
bare_app_kit_path_control_url(js_env_t *env, js_callback_info_t *info) {
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
    NSPathControl *path_control = (__bridge NSPathControl *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_url(env, path_control.URL);
    } else {
      path_control.URL = bare_app_kit__to_url(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_path_control_path_style(js_env_t *env, js_callback_info_t *info) {
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
    NSPathControl *path_control = (__bridge NSPathControl *) handle;

    if (argc == 1) {
      err = js_create_int32(env, path_control.pathStyle, &result);
      assert(err == 0);
    } else {
      int32_t path_style;
      if (!bare_app_kit__read_int32(env, argv[1], "path_style", &path_style)) return NULL;

      path_control.pathStyle = path_style;
    }
  }

  return result;
}

static void
bare_app_kit_path_control_path_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t path_style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSPathControl *path_control = (NSPathControl *) bare_object;

    path_control.pathStyle = path_style;
  }
}

static js_value_t *
bare_app_kit_path_control_editable(js_env_t *env, js_callback_info_t *info) {
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
    NSPathControl *path_control = (__bridge NSPathControl *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, path_control.editable, &result);
      assert(err == 0);
    } else {
      bool editable;
      if (!bare_app_kit__read_bool(env, argv[1], "editable", &editable)) return NULL;

      path_control.editable = editable;
    }
  }

  return result;
}

static void
bare_app_kit_path_control_editable_typed(js_value_t *receiver, int32_t bare_tag, bool editable, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSPathControl *path_control = (NSPathControl *) bare_object;

    path_control.editable = editable;
  }
}

static js_value_t *
bare_app_kit_path_control_placeholder_string(js_env_t *env, js_callback_info_t *info) {
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
    NSPathControl *path_control = (__bridge NSPathControl *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, path_control.placeholderString);
    } else {
      path_control.placeholderString = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_path_control_background_color(js_env_t *env, js_callback_info_t *info) {
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
    NSPathControl *path_control = (__bridge NSPathControl *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, path_control.backgroundColor);
    } else {
      path_control.backgroundColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_path_control_allowed_types(js_env_t *env, js_callback_info_t *info) {
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
    NSPathControl *path_control = (__bridge NSPathControl *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_strings(env, path_control.allowedTypes);
    } else {
      path_control.allowedTypes = bare_app_kit__to_strings(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_path_control_menu(js_env_t *env, js_callback_info_t *info) {
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
    NSPathControl *path_control = (__bridge NSPathControl *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, path_control.menu);
    } else {
      path_control.menu = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_path_control_set_path_items(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSArray *items = bare_app_kit__to_objects(env, argv[1]);

  @autoreleasepool {
    NSPathControl *path_control = (__bridge NSPathControl *) handle;

    [path_control setPathItems:items];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_path_control_number_of_path_items(js_env_t *env, js_callback_info_t *info) {
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
    NSPathControl *path_control = (__bridge NSPathControl *) handle;

    err = js_create_int32(env, (int32_t) path_control.pathItems.count, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_path_control_path_item_at(js_env_t *env, js_callback_info_t *info) {
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
    NSPathControl *path_control = (__bridge NSPathControl *) handle;

    result = bare_foundation__bridge(env, path_control.pathItems[index]);
  }

  return result;
}

static js_value_t *
bare_app_kit_path_control_clicked_path_item(js_env_t *env, js_callback_info_t *info) {
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
    NSPathControl *path_control = (__bridge NSPathControl *) handle;

    result = bare_foundation__bridge(env, path_control.clickedPathItem);
  }

  return result;
}
