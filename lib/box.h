#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_box_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

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
    NSBox *handle = [[[NSBox alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_box_title(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, box.title);
    } else {
      box.title = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_box_title_position(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    if (argc == 1) {
      err = js_create_int32(env, box.titlePosition, &result);
      assert(err == 0);
    } else {
      int32_t title_position;
      if (!bare_app_kit__read_int32(env, argv[1], "title_position", &title_position)) return NULL;

      box.titlePosition = title_position;
    }
  }

  return result;
}

static void
bare_app_kit_box_title_position_typed(js_value_t *receiver, int32_t bare_tag, int32_t title_position, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSBox *box = (NSBox *) bare_object;

    box.titlePosition = title_position;
  }
}

static js_value_t *
bare_app_kit_box_type(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    if (argc == 1) {
      err = js_create_int32(env, box.boxType, &result);
      assert(err == 0);
    } else {
      int32_t type;
      if (!bare_app_kit__read_int32(env, argv[1], "type", &type)) return NULL;

      box.boxType = type;
    }
  }

  return result;
}

static void
bare_app_kit_box_type_typed(js_value_t *receiver, int32_t bare_tag, int32_t type, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSBox *box = (NSBox *) bare_object;

    box.boxType = type;
  }
}

static js_value_t *
bare_app_kit_box_border_width(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    if (argc == 1) {
      err = js_create_double(env, box.borderWidth, &result);
      assert(err == 0);
    } else {
      double border_width;
      if (!bare_app_kit__read_double(env, argv[1], "border_width", &border_width)) return NULL;

      box.borderWidth = border_width;
    }
  }

  return result;
}

static void
bare_app_kit_box_border_width_typed(js_value_t *receiver, int32_t bare_tag, double border_width, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSBox *box = (NSBox *) bare_object;

    box.borderWidth = border_width;
  }
}

static js_value_t *
bare_app_kit_box_corner_radius(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    if (argc == 1) {
      err = js_create_double(env, box.cornerRadius, &result);
      assert(err == 0);
    } else {
      double corner_radius;
      if (!bare_app_kit__read_double(env, argv[1], "corner_radius", &corner_radius)) return NULL;

      box.cornerRadius = corner_radius;
    }
  }

  return result;
}

static void
bare_app_kit_box_corner_radius_typed(js_value_t *receiver, int32_t bare_tag, double corner_radius, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSBox *box = (NSBox *) bare_object;

    box.cornerRadius = corner_radius;
  }
}

static js_value_t *
bare_app_kit_box_transparent(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, box.transparent, &result);
      assert(err == 0);
    } else {
      bool transparent;
      if (!bare_app_kit__read_bool(env, argv[1], "transparent", &transparent)) return NULL;

      box.transparent = transparent;
    }
  }

  return result;
}

static void
bare_app_kit_box_transparent_typed(js_value_t *receiver, int32_t bare_tag, bool transparent, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSBox *box = (NSBox *) bare_object;

    box.transparent = transparent;
  }
}

static js_value_t *
bare_app_kit_box_content_view_margins(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, box.contentViewMargins);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      box.contentViewMargins = NSMakeSize(width, height);
    }
  }

  return result;
}

static void
bare_app_kit_box_content_view_margins_typed(js_value_t *receiver, int32_t bare_tag, double width, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSBox *box = (NSBox *) bare_object;

    box.contentViewMargins = NSMakeSize(width, height);
  }
}

static js_value_t *
bare_app_kit_box_content_view_margins_into(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    __typeof__(box.contentViewMargins) value = box.contentViewMargins;

    out[0] = value.width;
    out[1] = value.height;
  }

  return NULL;
}

static void
bare_app_kit_box_content_view_margins_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSBox *box = (NSBox *) bare_object;

    __typeof__(box.contentViewMargins) value = box.contentViewMargins;

    out[0] = value.width;
    out[1] = value.height;
  }
}

static js_value_t *
bare_app_kit_box_content_view(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, box.contentView);
    } else {
      box.contentView = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_box_fill_color(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, box.fillColor);
    } else {
      box.fillColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_box_border_color(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, box.borderColor);
    } else {
      box.borderColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_box_title_font(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, box.titleFont);
    } else {
      box.titleFont = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_box_size_to_fit(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSBox *box = (__bridge NSBox *) handle;

    [box sizeToFit];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_box_set_frame_from_content_frame(js_env_t *env, js_callback_info_t *info) {
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
    NSBox *box = (__bridge NSBox *) handle;

    [box setFrameFromContentFrame:NSMakeRect(x, y, width, height)];
  }

  return NULL;
}
