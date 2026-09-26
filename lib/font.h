#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_font_font_name(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    result = bare_app_kit__from_string(env, font.fontName);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_family_name(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    result = bare_app_kit__from_string(env, font.familyName);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_display_name(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    result = bare_app_kit__from_string(env, font.displayName);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_point_size(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    err = js_create_double(env, font.pointSize, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_ascender(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    err = js_create_double(env, font.ascender, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_descender(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    err = js_create_double(env, font.descender, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_cap_height(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    err = js_create_double(env, font.capHeight, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_x_height(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    err = js_create_double(env, font.xHeight, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_leading(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    err = js_create_double(env, font.leading, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_italic_angle(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    err = js_create_double(env, font.italicAngle, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_underline_position(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    err = js_create_double(env, font.underlinePosition, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_underline_thickness(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    err = js_create_double(env, font.underlineThickness, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_number_of_glyphs(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    err = js_create_int32(env, font.numberOfGlyphs, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_fixed_pitch(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    err = js_get_boolean(env, font.fixedPitch, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_bounding_rect_for_font(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    result = bare_app_kit__from_rect(env, font.boundingRectForFont);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_bounding_rect_for_font_into(js_env_t *env, js_callback_info_t *info) {
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

  if (!bare_app_kit__buffer(env, argv[1], offset, 4, &out)) {
    err = js_throw_type_error(env, NULL, "Expected an array buffer with room for 4 doubles");
    assert(err == 0);

    return NULL;
  }

  @autoreleasepool {
    NSFont *font = (__bridge NSFont *) handle;

    __typeof__(font.boundingRectForFont) value = font.boundingRectForFont;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }

  return NULL;
}

static void
bare_app_kit_font_bounding_rect_for_font_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSFont *font = (NSFont *) bare_object;

    __typeof__(font.boundingRectForFont) value = font.boundingRectForFont;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }
}

static js_value_t *
bare_app_kit_font_maximum_advancement(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    result = bare_app_kit__from_size(env, font.maximumAdvancement);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_maximum_advancement_into(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    __typeof__(font.maximumAdvancement) value = font.maximumAdvancement;

    out[0] = value.width;
    out[1] = value.height;
  }

  return NULL;
}

static void
bare_app_kit_font_maximum_advancement_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSFont *font = (NSFont *) bare_object;

    __typeof__(font.maximumAdvancement) value = font.maximumAdvancement;

    out[0] = value.width;
    out[1] = value.height;
  }
}

static js_value_t *
bare_app_kit_font_system_font(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  double size;
  if (!bare_app_kit__read_double(env, argv[0], "size", &size)) return NULL;

  double weight;
  if (!bare_app_kit__read_double(env, argv[1], "weight", &weight)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSFont systemFontOfSize:size weight:weight]);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_bold_system_font(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  double size;
  if (!bare_app_kit__read_double(env, argv[0], "size", &size)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSFont boldSystemFontOfSize:size]);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_monospaced_system_font(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  double size;
  if (!bare_app_kit__read_double(env, argv[0], "size", &size)) return NULL;

  double weight;
  if (!bare_app_kit__read_double(env, argv[1], "weight", &weight)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSFont monospacedSystemFontOfSize:size weight:weight]);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_monospaced_digit_system_font(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  double size;
  if (!bare_app_kit__read_double(env, argv[0], "size", &size)) return NULL;

  double weight;
  if (!bare_app_kit__read_double(env, argv[1], "weight", &weight)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSFont monospacedDigitSystemFontOfSize:size weight:weight]);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_with_name(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  NSString *name = bare_app_kit__to_string(env, argv[0]);

  double size;
  if (!bare_app_kit__read_double(env, argv[1], "size", &size)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSFont fontWithName:name size:size]);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_font_descriptor(js_env_t *env, js_callback_info_t *info) {
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
    NSFont *font = (__bridge NSFont *) handle;

    result = bare_foundation__bridge(env, font.fontDescriptor);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_with_descriptor(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double size;
  if (!bare_app_kit__read_double(env, argv[1], "size", &size)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSFontDescriptor *descriptor = (__bridge NSFontDescriptor *) handle;

    result = bare_foundation__bridge(env, [NSFont fontWithDescriptor:descriptor size:size]);
  }

  return result;
}
