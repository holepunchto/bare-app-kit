#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_paragraph_style_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 0;
  js_value_t *argv[0];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    NSMutableParagraphStyle *handle = [[[NSMutableParagraphStyle alloc] init] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_paragraph_style_alignment(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_int32(env, paragraph_style.alignment, &result);
      assert(err == 0);
    } else {
      int32_t alignment;
      if (!bare_app_kit__read_int32(env, argv[1], "alignment", &alignment)) return NULL;

      paragraph_style.alignment = alignment;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_alignment_typed(js_value_t *receiver, int32_t bare_tag, int32_t alignment, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.alignment = alignment;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_line_spacing(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_double(env, paragraph_style.lineSpacing, &result);
      assert(err == 0);
    } else {
      double line_spacing;
      if (!bare_app_kit__read_double(env, argv[1], "line_spacing", &line_spacing)) return NULL;

      paragraph_style.lineSpacing = line_spacing;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_line_spacing_typed(js_value_t *receiver, int32_t bare_tag, double line_spacing, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.lineSpacing = line_spacing;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_paragraph_spacing(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_double(env, paragraph_style.paragraphSpacing, &result);
      assert(err == 0);
    } else {
      double paragraph_spacing;
      if (!bare_app_kit__read_double(env, argv[1], "paragraph_spacing", &paragraph_spacing)) return NULL;

      paragraph_style.paragraphSpacing = paragraph_spacing;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_paragraph_spacing_typed(js_value_t *receiver, int32_t bare_tag, double paragraph_spacing, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.paragraphSpacing = paragraph_spacing;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_paragraph_spacing_before(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_double(env, paragraph_style.paragraphSpacingBefore, &result);
      assert(err == 0);
    } else {
      double paragraph_spacing_before;
      if (!bare_app_kit__read_double(env, argv[1], "paragraph_spacing_before", &paragraph_spacing_before)) return NULL;

      paragraph_style.paragraphSpacingBefore = paragraph_spacing_before;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_paragraph_spacing_before_typed(js_value_t *receiver, int32_t bare_tag, double paragraph_spacing_before, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.paragraphSpacingBefore = paragraph_spacing_before;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_first_line_head_indent(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_double(env, paragraph_style.firstLineHeadIndent, &result);
      assert(err == 0);
    } else {
      double first_line_head_indent;
      if (!bare_app_kit__read_double(env, argv[1], "first_line_head_indent", &first_line_head_indent)) return NULL;

      paragraph_style.firstLineHeadIndent = first_line_head_indent;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_first_line_head_indent_typed(js_value_t *receiver, int32_t bare_tag, double first_line_head_indent, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.firstLineHeadIndent = first_line_head_indent;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_head_indent(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_double(env, paragraph_style.headIndent, &result);
      assert(err == 0);
    } else {
      double head_indent;
      if (!bare_app_kit__read_double(env, argv[1], "head_indent", &head_indent)) return NULL;

      paragraph_style.headIndent = head_indent;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_head_indent_typed(js_value_t *receiver, int32_t bare_tag, double head_indent, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.headIndent = head_indent;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_tail_indent(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_double(env, paragraph_style.tailIndent, &result);
      assert(err == 0);
    } else {
      double tail_indent;
      if (!bare_app_kit__read_double(env, argv[1], "tail_indent", &tail_indent)) return NULL;

      paragraph_style.tailIndent = tail_indent;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_tail_indent_typed(js_value_t *receiver, int32_t bare_tag, double tail_indent, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.tailIndent = tail_indent;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_line_height_multiple(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_double(env, paragraph_style.lineHeightMultiple, &result);
      assert(err == 0);
    } else {
      double line_height_multiple;
      if (!bare_app_kit__read_double(env, argv[1], "line_height_multiple", &line_height_multiple)) return NULL;

      paragraph_style.lineHeightMultiple = line_height_multiple;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_line_height_multiple_typed(js_value_t *receiver, int32_t bare_tag, double line_height_multiple, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.lineHeightMultiple = line_height_multiple;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_minimum_line_height(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_double(env, paragraph_style.minimumLineHeight, &result);
      assert(err == 0);
    } else {
      double minimum_line_height;
      if (!bare_app_kit__read_double(env, argv[1], "minimum_line_height", &minimum_line_height)) return NULL;

      paragraph_style.minimumLineHeight = minimum_line_height;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_minimum_line_height_typed(js_value_t *receiver, int32_t bare_tag, double minimum_line_height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.minimumLineHeight = minimum_line_height;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_maximum_line_height(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_double(env, paragraph_style.maximumLineHeight, &result);
      assert(err == 0);
    } else {
      double maximum_line_height;
      if (!bare_app_kit__read_double(env, argv[1], "maximum_line_height", &maximum_line_height)) return NULL;

      paragraph_style.maximumLineHeight = maximum_line_height;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_maximum_line_height_typed(js_value_t *receiver, int32_t bare_tag, double maximum_line_height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.maximumLineHeight = maximum_line_height;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_default_tab_interval(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_double(env, paragraph_style.defaultTabInterval, &result);
      assert(err == 0);
    } else {
      double default_tab_interval;
      if (!bare_app_kit__read_double(env, argv[1], "default_tab_interval", &default_tab_interval)) return NULL;

      paragraph_style.defaultTabInterval = default_tab_interval;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_default_tab_interval_typed(js_value_t *receiver, int32_t bare_tag, double default_tab_interval, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.defaultTabInterval = default_tab_interval;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_hyphenation_factor(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_double(env, paragraph_style.hyphenationFactor, &result);
      assert(err == 0);
    } else {
      double hyphenation_factor;
      if (!bare_app_kit__read_double(env, argv[1], "hyphenation_factor", &hyphenation_factor)) return NULL;

      paragraph_style.hyphenationFactor = hyphenation_factor;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_hyphenation_factor_typed(js_value_t *receiver, int32_t bare_tag, double hyphenation_factor, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.hyphenationFactor = hyphenation_factor;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_line_break_mode(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_int32(env, paragraph_style.lineBreakMode, &result);
      assert(err == 0);
    } else {
      int32_t line_break_mode;
      if (!bare_app_kit__read_int32(env, argv[1], "line_break_mode", &line_break_mode)) return NULL;

      paragraph_style.lineBreakMode = line_break_mode;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_line_break_mode_typed(js_value_t *receiver, int32_t bare_tag, int32_t line_break_mode, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.lineBreakMode = line_break_mode;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_base_writing_direction(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_create_int32(env, paragraph_style.baseWritingDirection, &result);
      assert(err == 0);
    } else {
      int32_t base_writing_direction;
      if (!bare_app_kit__read_int32(env, argv[1], "base_writing_direction", &base_writing_direction)) return NULL;

      paragraph_style.baseWritingDirection = base_writing_direction;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_base_writing_direction_typed(js_value_t *receiver, int32_t bare_tag, int32_t base_writing_direction, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.baseWritingDirection = base_writing_direction;
  }
}

static js_value_t *
bare_app_kit_paragraph_style_allows_default_tightening_for_truncation(js_env_t *env, js_callback_info_t *info) {
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
    NSMutableParagraphStyle *paragraph_style = (__bridge NSMutableParagraphStyle *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, paragraph_style.allowsDefaultTighteningForTruncation, &result);
      assert(err == 0);
    } else {
      bool allows_default_tightening_for_truncation;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_default_tightening_for_truncation", &allows_default_tightening_for_truncation)) return NULL;

      paragraph_style.allowsDefaultTighteningForTruncation = allows_default_tightening_for_truncation;
    }
  }

  return result;
}

static void
bare_app_kit_paragraph_style_allows_default_tightening_for_truncation_typed(js_value_t *receiver, int32_t bare_tag, bool allows_default_tightening_for_truncation, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSMutableParagraphStyle *paragraph_style = (NSMutableParagraphStyle *) bare_object;

    paragraph_style.allowsDefaultTighteningForTruncation = allows_default_tightening_for_truncation;
  }
}
