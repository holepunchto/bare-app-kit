#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_control_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, control.enabled, &result);
      assert(err == 0);
    } else {
      bool enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "enabled", &enabled)) return NULL;

      control.enabled = enabled;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_continuous(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, control.continuous, &result);
      assert(err == 0);
    } else {
      bool continuous;
      if (!bare_app_kit__read_bool(env, argv[1], "continuous", &continuous)) return NULL;

      control.continuous = continuous;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_ignores_multi_click(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, control.ignoresMultiClick, &result);
      assert(err == 0);
    } else {
      bool ignores_multi_click;
      if (!bare_app_kit__read_bool(env, argv[1], "ignores_multi_click", &ignores_multi_click)) return NULL;

      control.ignoresMultiClick = ignores_multi_click;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_highlighted(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, control.highlighted, &result);
      assert(err == 0);
    } else {
      bool highlighted;
      if (!bare_app_kit__read_bool(env, argv[1], "highlighted", &highlighted)) return NULL;

      control.highlighted = highlighted;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_refuses_first_responder(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, control.refusesFirstResponder, &result);
      assert(err == 0);
    } else {
      bool refuses_first_responder;
      if (!bare_app_kit__read_bool(env, argv[1], "refuses_first_responder", &refuses_first_responder)) return NULL;

      control.refusesFirstResponder = refuses_first_responder;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_tag(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_int64(env, control.tag, &result);
      assert(err == 0);
    } else {
      int64_t tag;
      err = js_get_value_int64(env, argv[1], &tag);
      assert(err == 0);

      control.tag = tag;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_size(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_int32(env, control.controlSize, &result);
      assert(err == 0);
    } else {
      int32_t control_size;
      if (!bare_app_kit__read_int32(env, argv[1], "control_size", &control_size)) return NULL;

      control.controlSize = control_size;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_string_value(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, control.stringValue);
    } else {
      control.stringValue = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_int_value(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_int32(env, control.intValue, &result);
      assert(err == 0);
    } else {
      int32_t value;
      if (!bare_app_kit__read_int32(env, argv[1], "value", &value)) return NULL;

      control.intValue = value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_integer_value(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_int64(env, control.integerValue, &result);
      assert(err == 0);
    } else {
      int64_t value;
      err = js_get_value_int64(env, argv[1], &value);
      assert(err == 0);

      control.integerValue = value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_float_value(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_double(env, control.floatValue, &result);
      assert(err == 0);
    } else {
      double value;
      if (!bare_app_kit__read_double(env, argv[1], "value", &value)) return NULL;

      control.floatValue = value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_double_value(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_double(env, control.doubleValue, &result);
      assert(err == 0);
    } else {
      double value;
      if (!bare_app_kit__read_double(env, argv[1], "value", &value)) return NULL;

      control.doubleValue = value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_size_to_fit(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSControl *control = (__bridge NSControl *) handle;

    [control sizeToFit];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_control_perform_click(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSControl *control = (__bridge NSControl *) handle;

    [control performClick:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_control_font(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, control.font);
    } else {
      control.font = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_attributed_string_value(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, control.attributedStringValue);
    } else {
      control.attributedStringValue = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_alignment(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_int32(env, control.alignment, &result);
      assert(err == 0);
    } else {
      int32_t alignment;
      if (!bare_app_kit__read_int32(env, argv[1], "alignment", &alignment)) return NULL;

      control.alignment = alignment;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_line_break_mode(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_create_int32(env, control.lineBreakMode, &result);
      assert(err == 0);
    } else {
      int32_t line_break_mode;
      if (!bare_app_kit__read_int32(env, argv[1], "line_break_mode", &line_break_mode)) return NULL;

      control.lineBreakMode = line_break_mode;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_control_uses_single_line_mode(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, control.usesSingleLineMode, &result);
      assert(err == 0);
    } else {
      bool uses_single_line_mode;
      if (!bare_app_kit__read_bool(env, argv[1], "uses_single_line_mode", &uses_single_line_mode)) return NULL;

      control.usesSingleLineMode = uses_single_line_mode;
    }
  }

  return result;
}

static void
bare_app_kit_control_alignment_typed(js_value_t *receiver, int32_t bare_tag, int32_t alignment, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSControl *control = (NSControl *) bare_object;

    control.alignment = alignment;
  }
}

static void
bare_app_kit_control_line_break_mode_typed(js_value_t *receiver, int32_t bare_tag, int32_t line_break_mode, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSControl *control = (NSControl *) bare_object;

    control.lineBreakMode = line_break_mode;
  }
}

static void
bare_app_kit_control_uses_single_line_mode_typed(js_value_t *receiver, int32_t bare_tag, bool uses_single_line_mode, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSControl *control = (NSControl *) bare_object;

    control.usesSingleLineMode = uses_single_line_mode;
  }
}

// The text object a control edits through, which for a text field is the
// window's shared field editor and exists only while the control is being
// edited. A selection and the spelling behaviour live on it rather than on the
// control, so this is how a caller reaches them.
static js_value_t *
bare_app_kit_control_current_editor(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    result = bare_foundation__bridge(env, [control currentEditor]);
  }

  return result;
}

static js_value_t *
bare_app_kit_control_cell(js_env_t *env, js_callback_info_t *info) {
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
    NSControl *control = (__bridge NSControl *) handle;

    result = bare_foundation__bridge(env, control.cell);
  }

  return result;
}
