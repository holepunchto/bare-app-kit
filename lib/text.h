#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_text_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

  double x;
  if (!bare_app_kit__read_double(env, argv[0], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[1], "y", &y)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[2], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[3], "height", &height)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSText *handle = [[[NSText alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_text_string(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, text.string);
    } else {
      text.string = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_editable(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.editable, &result);
      assert(err == 0);
    } else {
      bool editable;
      if (!bare_app_kit__read_bool(env, argv[1], "editable", &editable)) return NULL;

      text.editable = editable;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_selectable(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.selectable, &result);
      assert(err == 0);
    } else {
      bool selectable;
      if (!bare_app_kit__read_bool(env, argv[1], "selectable", &selectable)) return NULL;

      text.selectable = selectable;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_rich_text(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.richText, &result);
      assert(err == 0);
    } else {
      bool rich_text;
      if (!bare_app_kit__read_bool(env, argv[1], "rich_text", &rich_text)) return NULL;

      text.richText = rich_text;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_imports_graphics(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.importsGraphics, &result);
      assert(err == 0);
    } else {
      bool imports_graphics;
      if (!bare_app_kit__read_bool(env, argv[1], "imports_graphics", &imports_graphics)) return NULL;

      text.importsGraphics = imports_graphics;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_editor(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.fieldEditor, &result);
      assert(err == 0);
    } else {
      bool field_editor;
      if (!bare_app_kit__read_bool(env, argv[1], "field_editor", &field_editor)) return NULL;

      text.fieldEditor = field_editor;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_uses_font_panel(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.usesFontPanel, &result);
      assert(err == 0);
    } else {
      bool uses_font_panel;
      if (!bare_app_kit__read_bool(env, argv[1], "uses_font_panel", &uses_font_panel)) return NULL;

      text.usesFontPanel = uses_font_panel;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_draws_background(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.drawsBackground, &result);
      assert(err == 0);
    } else {
      bool draws_background;
      if (!bare_app_kit__read_bool(env, argv[1], "draws_background", &draws_background)) return NULL;

      text.drawsBackground = draws_background;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_ruler_visible(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    err = js_get_boolean(env, text.rulerVisible, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_text_alignment(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_create_int64(env, text.alignment, &result);
      assert(err == 0);
    } else {
      int64_t alignment;
      err = js_get_value_int64(env, argv[1], &alignment);
      assert(err == 0);

      text.alignment = (NSTextAlignment) alignment;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_base_writing_direction(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_create_int64(env, text.baseWritingDirection, &result);
      assert(err == 0);
    } else {
      int64_t base_writing_direction;
      err = js_get_value_int64(env, argv[1], &base_writing_direction);
      assert(err == 0);

      text.baseWritingDirection = (NSWritingDirection) base_writing_direction;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_copy(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSText *text = (__bridge NSText *) handle;

    [text copy:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_cut(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSText *text = (__bridge NSText *) handle;

    [text cut:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_delete(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSText *text = (__bridge NSText *) handle;

    [text delete:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_paste(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSText *text = (__bridge NSText *) handle;

    [text paste:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_select_all(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSText *text = (__bridge NSText *) handle;

    [text selectAll:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_size_to_fit(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSText *text = (__bridge NSText *) handle;

    [text sizeToFit];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_font(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, text.font);
    } else {
      text.font = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_text_color(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, text.textColor);
    } else {
      text.textColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_background_color(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, text.backgroundColor);
    } else {
      text.backgroundColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_vertically_resizable(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.verticallyResizable, &result);
      assert(err == 0);
    } else {
      bool vertically_resizable;
      if (!bare_app_kit__read_bool(env, argv[1], "vertically_resizable", &vertically_resizable)) return NULL;

      text.verticallyResizable = vertically_resizable;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_horizontally_resizable(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text.horizontallyResizable, &result);
      assert(err == 0);
    } else {
      bool horizontally_resizable;
      if (!bare_app_kit__read_bool(env, argv[1], "horizontally_resizable", &horizontally_resizable)) return NULL;

      text.horizontallyResizable = horizontally_resizable;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_min_size(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, text.minSize);
    } else {
      double width;
      if (!bare_app_kit__read_double(env, argv[1], "width", &width)) return NULL;

      double height;
      if (!bare_app_kit__read_double(env, argv[2], "height", &height)) return NULL;

      text.minSize = NSMakeSize(width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_max_size(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, text.maxSize);
    } else {
      double width;
      if (!bare_app_kit__read_double(env, argv[1], "width", &width)) return NULL;

      double height;
      if (!bare_app_kit__read_double(env, argv[2], "height", &height)) return NULL;

      text.maxSize = NSMakeSize(width, height);
    }
  }

  return result;
}

static void
bare_app_kit_text_vertically_resizable_typed(js_value_t *receiver, int32_t bare_tag, bool vertically_resizable, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSText *text = (NSText *) bare_object;

    text.verticallyResizable = vertically_resizable;
  }
}

static void
bare_app_kit_text_horizontally_resizable_typed(js_value_t *receiver, int32_t bare_tag, bool horizontally_resizable, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSText *text = (NSText *) bare_object;

    text.horizontallyResizable = horizontally_resizable;
  }
}

static void
bare_app_kit_text_min_size_typed(js_value_t *receiver, int32_t bare_tag, double width, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSText *text = (NSText *) bare_object;

    text.minSize = NSMakeSize(width, height);
  }
}

static void
bare_app_kit_text_max_size_typed(js_value_t *receiver, int32_t bare_tag, double width, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSText *text = (NSText *) bare_object;

    text.maxSize = NSMakeSize(width, height);
  }
}

static js_value_t *
bare_app_kit_text_min_size_into(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    __typeof__(text.minSize) value = text.minSize;

    out[0] = value.width;
    out[1] = value.height;
  }

  return NULL;
}

static void
bare_app_kit_text_min_size_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSText *text = (NSText *) bare_object;

    __typeof__(text.minSize) value = text.minSize;

    out[0] = value.width;
    out[1] = value.height;
  }
}

static js_value_t *
bare_app_kit_text_max_size_into(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    __typeof__(text.maxSize) value = text.maxSize;

    out[0] = value.width;
    out[1] = value.height;
  }

  return NULL;
}

static void
bare_app_kit_text_max_size_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSText *text = (NSText *) bare_object;

    __typeof__(text.maxSize) value = text.maxSize;

    out[0] = value.width;
    out[1] = value.height;
  }
}

static js_value_t *
bare_app_kit_text_selected_range(js_env_t *env, js_callback_info_t *info) {
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
    NSText *text = (__bridge NSText *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_range(env, text.selectedRange);
    } else {
      int32_t location;
      err = js_get_value_int32(env, argv[1], &location);
      assert(err == 0);

      int32_t length;
      err = js_get_value_int32(env, argv[2], &length);
      assert(err == 0);

      text.selectedRange = NSMakeRange(location, length);
    }
  }

  return result;
}
