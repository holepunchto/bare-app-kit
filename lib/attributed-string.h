#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_attributed_string_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  js_value_t *result;

  @autoreleasepool {
    NSString *string = bare_app_kit__to_string(env, argv[0]);

    NSDictionary<NSAttributedStringKey, id> *attributes = bare_app_kit__to_attributes(env, argv[1]);

    NSMutableAttributedString *handle = [[[NSMutableAttributedString alloc] initWithString:string attributes:attributes] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_attributed_string_string(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableAttributedString *attributed_string = (__bridge NSMutableAttributedString *) handle;

    result = bare_app_kit__from_string(env, attributed_string.string);
  }

  return result;
}

static js_value_t *
bare_app_kit_attributed_string_length(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableAttributedString *attributed_string = (__bridge NSMutableAttributedString *) handle;

    err = js_create_int32(env, attributed_string.length, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_attributed_string_attributes_at(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t location;
  if (!bare_app_kit__read_int32(env, argv[1], "location", &location)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSMutableAttributedString *attributed_string = (__bridge NSMutableAttributedString *) handle;

    result = bare_app_kit__from_attributes(env, [attributed_string attributesAtIndex:location effectiveRange:NULL]);
  }

  return result;
}

static js_value_t *
bare_app_kit_attributed_string_set_attributes(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSDictionary<NSAttributedStringKey, id> *attributes = bare_app_kit__to_attributes(env, argv[1]);

  int32_t location;
  if (!bare_app_kit__read_int32(env, argv[2], "location", &location)) return NULL;

  int32_t length;
  if (!bare_app_kit__read_int32(env, argv[3], "length", &length)) return NULL;

  @autoreleasepool {
    NSMutableAttributedString *attributed_string = (__bridge NSMutableAttributedString *) handle;

    [attributed_string setAttributes:attributes range:NSMakeRange(location, length)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_attributed_string_add_attributes(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSDictionary<NSAttributedStringKey, id> *attributes = bare_app_kit__to_attributes(env, argv[1]);

  int32_t location;
  if (!bare_app_kit__read_int32(env, argv[2], "location", &location)) return NULL;

  int32_t length;
  if (!bare_app_kit__read_int32(env, argv[3], "length", &length)) return NULL;

  @autoreleasepool {
    NSMutableAttributedString *attributed_string = (__bridge NSMutableAttributedString *) handle;

    [attributed_string addAttributes:attributes range:NSMakeRange(location, length)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_attributed_string_remove_attributes(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t location;
  if (!bare_app_kit__read_int32(env, argv[1], "location", &location)) return NULL;

  int32_t length;
  if (!bare_app_kit__read_int32(env, argv[2], "length", &length)) return NULL;

  @autoreleasepool {
    NSMutableAttributedString *attributed_string = (__bridge NSMutableAttributedString *) handle;

    [attributed_string setAttributes:@{} range:NSMakeRange(location, length)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_attributed_string_append(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id other = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSMutableAttributedString *attributed_string = (__bridge NSMutableAttributedString *) handle;

    [attributed_string appendAttributedString:other];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_attributed_string_append_string(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *string = bare_app_kit__to_string(env, argv[1]);

  NSDictionary<NSAttributedStringKey, id> *attributes = bare_app_kit__to_attributes(env, argv[2]);

  @autoreleasepool {
    NSMutableAttributedString *attributed_string = (__bridge NSMutableAttributedString *) handle;

    [attributed_string appendAttributedString:[[[NSAttributedString alloc] initWithString:string attributes:attributes] autorelease]];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_attributed_string_replace_characters(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t location;
  if (!bare_app_kit__read_int32(env, argv[1], "location", &location)) return NULL;

  int32_t length;
  if (!bare_app_kit__read_int32(env, argv[2], "length", &length)) return NULL;

  NSString *string = bare_app_kit__to_string(env, argv[3]);

  @autoreleasepool {
    NSMutableAttributedString *attributed_string = (__bridge NSMutableAttributedString *) handle;

    [attributed_string replaceCharactersInRange:NSMakeRange(location, length) withString:string];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_attributed_string_substring(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t location;
  if (!bare_app_kit__read_int32(env, argv[1], "location", &location)) return NULL;

  int32_t length;
  if (!bare_app_kit__read_int32(env, argv[2], "length", &length)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSMutableAttributedString *attributed_string = (__bridge NSMutableAttributedString *) handle;

    result = bare_foundation__bridge(env, [[[NSMutableAttributedString alloc] initWithAttributedString:[attributed_string attributedSubstringFromRange:NSMakeRange(location, length)]] autorelease]);
  }

  return result;
}

static js_value_t *
bare_app_kit_attributed_string_bounding_rect(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[1], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[2], "height", &height)) return NULL;

  int32_t options;
  if (!bare_app_kit__read_int32(env, argv[3], "options", &options)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSMutableAttributedString *attributed_string = (__bridge NSMutableAttributedString *) handle;

    result = bare_app_kit__from_rect(env, [attributed_string boundingRectWithSize:NSMakeSize(width, height) options:options]);
  }

  return result;
}

static js_value_t *
bare_app_kit_attributed_string_measure(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 5);

  NSString *string = bare_app_kit__to_string(env, argv[0]);

  NSDictionary<NSAttributedStringKey, id> *attributes = bare_app_kit__to_attributes(env, argv[1]);

  double width;
  if (!bare_app_kit__read_double(env, argv[2], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[3], "height", &height)) return NULL;

  int32_t options;
  if (!bare_app_kit__read_int32(env, argv[4], "options", &options)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_app_kit__from_rect(env, [string boundingRectWithSize:NSMakeSize(width, height) options:options attributes:attributes context:nil]);
  }

  return result;
}
