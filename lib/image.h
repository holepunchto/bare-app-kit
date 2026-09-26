#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_image_size(js_env_t *env, js_callback_info_t *info) {
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
    NSImage *image = (__bridge NSImage *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, image.size);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      image.size = NSMakeSize(width, height);
    }
  }

  return result;
}

static void
bare_app_kit_image_size_typed(js_value_t *receiver, int32_t bare_tag, double width, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSImage *image = (NSImage *) bare_object;

    image.size = NSMakeSize(width, height);
  }
}

static js_value_t *
bare_app_kit_image_size_into(js_env_t *env, js_callback_info_t *info) {
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
    NSImage *image = (__bridge NSImage *) handle;

    __typeof__(image.size) value = image.size;

    out[0] = value.width;
    out[1] = value.height;
  }

  return NULL;
}

static void
bare_app_kit_image_size_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSImage *image = (NSImage *) bare_object;

    __typeof__(image.size) value = image.size;

    out[0] = value.width;
    out[1] = value.height;
  }
}

static js_value_t *
bare_app_kit_image_template(js_env_t *env, js_callback_info_t *info) {
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
    NSImage *image = (__bridge NSImage *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, image.template, &result);
      assert(err == 0);
    } else {
      bool template;
      if (!bare_app_kit__read_bool(env, argv[1], "template", &template)) return NULL;

      image.template = template;
    }
  }

  return result;
}

static void
bare_app_kit_image_template_typed(js_value_t *receiver, int32_t bare_tag, bool template, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSImage *image = (NSImage *) bare_object;

    image.template = template;
  }
}

static js_value_t *
bare_app_kit_image_name(js_env_t *env, js_callback_info_t *info) {
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
    NSImage *image = (__bridge NSImage *) handle;

    result = bare_app_kit__from_string(env, [image name]);
  }

  return result;
}

static js_value_t *
bare_app_kit_image_valid(js_env_t *env, js_callback_info_t *info) {
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
    NSImage *image = (__bridge NSImage *) handle;

    err = js_get_boolean(env, image.valid, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_image_cache_mode(js_env_t *env, js_callback_info_t *info) {
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
    NSImage *image = (__bridge NSImage *) handle;

    if (argc == 1) {
      err = js_create_int32(env, image.cacheMode, &result);
      assert(err == 0);
    } else {
      int32_t cache_mode;
      if (!bare_app_kit__read_int32(env, argv[1], "cache_mode", &cache_mode)) return NULL;

      image.cacheMode = cache_mode;
    }
  }

  return result;
}

static void
bare_app_kit_image_cache_mode_typed(js_value_t *receiver, int32_t bare_tag, int32_t cache_mode, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSImage *image = (NSImage *) bare_object;

    image.cacheMode = cache_mode;
  }
}

static js_value_t *
bare_app_kit_image_resizing_mode(js_env_t *env, js_callback_info_t *info) {
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
    NSImage *image = (__bridge NSImage *) handle;

    if (argc == 1) {
      err = js_create_int32(env, image.resizingMode, &result);
      assert(err == 0);
    } else {
      int32_t resizing_mode;
      if (!bare_app_kit__read_int32(env, argv[1], "resizing_mode", &resizing_mode)) return NULL;

      image.resizingMode = resizing_mode;
    }
  }

  return result;
}

static void
bare_app_kit_image_resizing_mode_typed(js_value_t *receiver, int32_t bare_tag, int32_t resizing_mode, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSImage *image = (NSImage *) bare_object;

    image.resizingMode = resizing_mode;
  }
}

static js_value_t *
bare_app_kit_image_alignment_rect(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 5);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSImage *image = (__bridge NSImage *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_rect(env, image.alignmentRect);
    } else {
      double x;
      err = js_get_value_double(env, argv[1], &x);
      assert(err == 0);

      double y;
      err = js_get_value_double(env, argv[2], &y);
      assert(err == 0);

      double width;
      err = js_get_value_double(env, argv[3], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[4], &height);
      assert(err == 0);

      image.alignmentRect = NSMakeRect(x, y, width, height);
    }
  }

  return result;
}

static void
bare_app_kit_image_alignment_rect_typed(js_value_t *receiver, int32_t bare_tag, double x, double y, double width, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSImage *image = (NSImage *) bare_object;

    image.alignmentRect = NSMakeRect(x, y, width, height);
  }
}

static js_value_t *
bare_app_kit_image_alignment_rect_into(js_env_t *env, js_callback_info_t *info) {
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
    NSImage *image = (__bridge NSImage *) handle;

    __typeof__(image.alignmentRect) value = image.alignmentRect;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }

  return NULL;
}

static void
bare_app_kit_image_alignment_rect_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSImage *image = (NSImage *) bare_object;

    __typeof__(image.alignmentRect) value = image.alignmentRect;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }
}

static js_value_t *
bare_app_kit_image_matches_on_multiple_resolution(js_env_t *env, js_callback_info_t *info) {
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
    NSImage *image = (__bridge NSImage *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, image.matchesOnMultipleResolution, &result);
      assert(err == 0);
    } else {
      bool matches_on_multiple_resolution;
      if (!bare_app_kit__read_bool(env, argv[1], "matches_on_multiple_resolution", &matches_on_multiple_resolution)) return NULL;

      image.matchesOnMultipleResolution = matches_on_multiple_resolution;
    }
  }

  return result;
}

static void
bare_app_kit_image_matches_on_multiple_resolution_typed(js_value_t *receiver, int32_t bare_tag, bool matches_on_multiple_resolution, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSImage *image = (NSImage *) bare_object;

    image.matchesOnMultipleResolution = matches_on_multiple_resolution;
  }
}

static js_value_t *
bare_app_kit_image_prefers_color_match(js_env_t *env, js_callback_info_t *info) {
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
    NSImage *image = (__bridge NSImage *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, image.prefersColorMatch, &result);
      assert(err == 0);
    } else {
      bool prefers_color_match;
      if (!bare_app_kit__read_bool(env, argv[1], "prefers_color_match", &prefers_color_match)) return NULL;

      image.prefersColorMatch = prefers_color_match;
    }
  }

  return result;
}

static void
bare_app_kit_image_prefers_color_match_typed(js_value_t *receiver, int32_t bare_tag, bool prefers_color_match, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSImage *image = (NSImage *) bare_object;

    image.prefersColorMatch = prefers_color_match;
  }
}

static js_value_t *
bare_app_kit_image_with_contents_of_file(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSString *path = bare_app_kit__to_string(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [[[NSImage alloc] initWithContentsOfFile:path] autorelease]);
  }

  return result;
}

static js_value_t *
bare_app_kit_image_named(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSString *name = bare_app_kit__to_string(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSImage imageNamed:name]);
  }

  return result;
}

static js_value_t *
bare_app_kit_image_with_system_symbol_name(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  NSString *name = bare_app_kit__to_string(env, argv[0]);

  NSString *description = bare_app_kit__to_string(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSImage imageWithSystemSymbolName:name accessibilityDescription:description]);
  }

  return result;
}

static js_value_t *
bare_app_kit_image_with_size(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  double width;
  if (!bare_app_kit__read_double(env, argv[0], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[1], "height", &height)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [[[NSImage alloc] initWithSize:NSMakeSize(width, height)] autorelease]);
  }

  return result;
}

static js_value_t *
bare_app_kit_image_lock_focus(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSImage *image = (__bridge NSImage *) handle;

    [image lockFocus];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_image_unlock_focus(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSImage *image = (__bridge NSImage *) handle;

    [image unlockFocus];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_image_draw_in_rect(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 5);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[3], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[4], "height", &height)) return NULL;

  @autoreleasepool {
    NSImage *image = (__bridge NSImage *) handle;

    [image drawInRect:NSMakeRect(x, y, width, height)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_image_draw_at_point(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  @autoreleasepool {
    NSImage *image = (__bridge NSImage *) handle;

    [image drawAtPoint:NSMakePoint(x, y) fromRect:NSZeroRect operation:NSCompositingOperationSourceOver fraction:1];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_image_tiff_representation(js_env_t *env, js_callback_info_t *info) {
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
    NSImage *image = (__bridge NSImage *) handle;

    result = bare_app_kit__from_data(env, [image TIFFRepresentation]);
  }

  return result;
}

static js_value_t *
bare_app_kit_image_recommended_layer_contents_scale(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double scale;
  if (!bare_app_kit__read_double(env, argv[1], "scale", &scale)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSImage *image = (__bridge NSImage *) handle;

    err = js_create_double(env, [image recommendedLayerContentsScale:scale], &result);
    assert(err == 0);
  }

  return result;
}
