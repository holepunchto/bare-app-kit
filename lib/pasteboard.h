#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_pasteboard_name(js_env_t *env, js_callback_info_t *info) {
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
    NSPasteboard *pasteboard = (__bridge NSPasteboard *) handle;

    result = bare_app_kit__from_string(env, pasteboard.name);
  }

  return result;
}

static js_value_t *
bare_app_kit_pasteboard_change_count(js_env_t *env, js_callback_info_t *info) {
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
    NSPasteboard *pasteboard = (__bridge NSPasteboard *) handle;

    err = js_create_int32(env, pasteboard.changeCount, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_pasteboard_types(js_env_t *env, js_callback_info_t *info) {
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
    NSPasteboard *pasteboard = (__bridge NSPasteboard *) handle;

    result = bare_app_kit__from_strings(env, pasteboard.types);
  }

  return result;
}

static js_value_t *
bare_app_kit_pasteboard_general(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSPasteboard generalPasteboard]);
  }

  return result;
}

static js_value_t *
bare_app_kit_pasteboard_with_name(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSString *name = bare_app_kit__to_string(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSPasteboard pasteboardWithName:name]);
  }

  return result;
}

static js_value_t *
bare_app_kit_pasteboard_with_unique_name(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSPasteboard pasteboardWithUniqueName]);
  }

  return result;
}

static js_value_t *
bare_app_kit_pasteboard_clear_contents(js_env_t *env, js_callback_info_t *info) {
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
    NSPasteboard *pasteboard = (__bridge NSPasteboard *) handle;

    err = js_create_int32(env, (int32_t) [pasteboard clearContents], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_pasteboard_set_string(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *string = bare_app_kit__to_string(env, argv[1]);

  NSString *type = bare_app_kit__to_string(env, argv[2]);

  js_value_t *result;

  @autoreleasepool {
    NSPasteboard *pasteboard = (__bridge NSPasteboard *) handle;

    err = js_get_boolean(env, [pasteboard setString:string forType:type], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_pasteboard_string_for_type(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *type = bare_app_kit__to_string(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSPasteboard *pasteboard = (__bridge NSPasteboard *) handle;

    result = bare_app_kit__from_string(env, [pasteboard stringForType:type]);
  }

  return result;
}

static js_value_t *
bare_app_kit_pasteboard_set_data(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSData *data = bare_app_kit__to_data(env, argv[1]);

  NSString *type = bare_app_kit__to_string(env, argv[2]);

  js_value_t *result;

  @autoreleasepool {
    NSPasteboard *pasteboard = (__bridge NSPasteboard *) handle;

    err = js_get_boolean(env, [pasteboard setData:data forType:type], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_pasteboard_data_for_type(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *type = bare_app_kit__to_string(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSPasteboard *pasteboard = (__bridge NSPasteboard *) handle;

    result = bare_app_kit__from_data(env, [pasteboard dataForType:type]);
  }

  return result;
}

static js_value_t *
bare_app_kit_pasteboard_available_type_from(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSArray<NSString *> *types = bare_app_kit__to_strings(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSPasteboard *pasteboard = (__bridge NSPasteboard *) handle;

    result = bare_app_kit__from_string(env, [pasteboard availableTypeFromArray:types]);
  }

  return result;
}

static js_value_t *
bare_app_kit_pasteboard_declare_types(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSArray<NSString *> *types = bare_app_kit__to_strings(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSPasteboard *pasteboard = (__bridge NSPasteboard *) handle;

    err = js_create_int32(env, (int32_t) [pasteboard declareTypes:types owner:nil], &result);
    assert(err == 0);
  }

  return result;
}
