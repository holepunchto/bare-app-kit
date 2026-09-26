#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareTextView : NSTextView <NSTextViewDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareTextView

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

- (void)textDidChange:(NSNotification *)notification {
  if ((mask & (1 << 0)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onchange");
}

- (void)textDidBeginEditing:(NSNotification *)notification {
  if ((mask & (1 << 1)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onbeginediting");
}

- (void)textDidEndEditing:(NSNotification *)notification {
  if ((mask & (1 << 2)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onendediting");
}

- (void)textViewDidChangeSelection:(NSNotification *)notification {
  if ((mask & (1 << 3)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onselectionchange");
}

- (BOOL)textView:(NSTextView *)view shouldChangeTextInRange:(NSRange)range replacementString:(NSString *)string {
  if (mask & (1 << 4)) {
    bare_app_kit__emit_replacement(env, ctx, "_onshouldchangetext", (int32_t) range.location, (int32_t) range.length, string);
  }

  return YES;
}

- (BOOL)becomeFirstResponder {
  BOOL became = [super becomeFirstResponder];

  if (became && (mask & (1 << 5))) {
    bare_app_kit__emit(env, ctx, "_onbecomefirstresponder");
  }

  return became;
}

BARE_APP_KIT_REPORTS_WILL_DRAW(1 << 6)

@end

static js_value_t *
bare_app_kit_text_view_init(js_env_t *env, js_callback_info_t *info) {
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
    BareTextView *handle = [[[BareTextView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    [handle setDelegate:handle];
  }

  return result;
}


static js_value_t *
bare_app_kit_text_view_text_container_inset(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, text_view.textContainerInset);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      text_view.textContainerInset = NSMakeSize(width, height);
    }
  }

  return result;
}

static void
bare_app_kit_text_view_text_container_inset_typed(js_value_t *receiver, int32_t bare_tag, double width, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.textContainerInset = NSMakeSize(width, height);
  }
}

static js_value_t *
bare_app_kit_text_view_text_container_inset_into(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    __typeof__(text_view.textContainerInset) value = text_view.textContainerInset;

    out[0] = value.width;
    out[1] = value.height;
  }

  return NULL;
}

static void
bare_app_kit_text_view_text_container_inset_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    __typeof__(text_view.textContainerInset) value = text_view.textContainerInset;

    out[0] = value.width;
    out[1] = value.height;
  }
}

static js_value_t *
bare_app_kit_text_view_insertion_point_color(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, text_view.insertionPointColor);
    } else {
      text_view.insertionPointColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_view_allows_undo(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.allowsUndo, &result);
      assert(err == 0);
    } else {
      bool allows_undo;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_undo", &allows_undo)) return NULL;

      text_view.allowsUndo = allows_undo;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_allows_undo_typed(js_value_t *receiver, int32_t bare_tag, bool allows_undo, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.allowsUndo = allows_undo;
  }
}

static js_value_t *
bare_app_kit_text_view_allows_image_editing(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.allowsImageEditing, &result);
      assert(err == 0);
    } else {
      bool allows_image_editing;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_image_editing", &allows_image_editing)) return NULL;

      text_view.allowsImageEditing = allows_image_editing;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_allows_image_editing_typed(js_value_t *receiver, int32_t bare_tag, bool allows_image_editing, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.allowsImageEditing = allows_image_editing;
  }
}

static js_value_t *
bare_app_kit_text_view_allows_document_background_color_change(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.allowsDocumentBackgroundColorChange, &result);
      assert(err == 0);
    } else {
      bool allows_document_background_color_change;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_document_background_color_change", &allows_document_background_color_change)) return NULL;

      text_view.allowsDocumentBackgroundColorChange = allows_document_background_color_change;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_allows_document_background_color_change_typed(js_value_t *receiver, int32_t bare_tag, bool allows_document_background_color_change, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.allowsDocumentBackgroundColorChange = allows_document_background_color_change;
  }
}

static js_value_t *
bare_app_kit_text_view_displays_link_tool_tips(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.displaysLinkToolTips, &result);
      assert(err == 0);
    } else {
      bool displays_link_tool_tips;
      if (!bare_app_kit__read_bool(env, argv[1], "displays_link_tool_tips", &displays_link_tool_tips)) return NULL;

      text_view.displaysLinkToolTips = displays_link_tool_tips;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_displays_link_tool_tips_typed(js_value_t *receiver, int32_t bare_tag, bool displays_link_tool_tips, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.displaysLinkToolTips = displays_link_tool_tips;
  }
}

static js_value_t *
bare_app_kit_text_view_uses_find_bar(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.usesFindBar, &result);
      assert(err == 0);
    } else {
      bool uses_find_bar;
      if (!bare_app_kit__read_bool(env, argv[1], "uses_find_bar", &uses_find_bar)) return NULL;

      text_view.usesFindBar = uses_find_bar;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_uses_find_bar_typed(js_value_t *receiver, int32_t bare_tag, bool uses_find_bar, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.usesFindBar = uses_find_bar;
  }
}

static js_value_t *
bare_app_kit_text_view_uses_find_panel(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.usesFindPanel, &result);
      assert(err == 0);
    } else {
      bool uses_find_panel;
      if (!bare_app_kit__read_bool(env, argv[1], "uses_find_panel", &uses_find_panel)) return NULL;

      text_view.usesFindPanel = uses_find_panel;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_uses_find_panel_typed(js_value_t *receiver, int32_t bare_tag, bool uses_find_panel, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.usesFindPanel = uses_find_panel;
  }
}

static js_value_t *
bare_app_kit_text_view_uses_ruler(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.usesRuler, &result);
      assert(err == 0);
    } else {
      bool uses_ruler;
      if (!bare_app_kit__read_bool(env, argv[1], "uses_ruler", &uses_ruler)) return NULL;

      text_view.usesRuler = uses_ruler;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_uses_ruler_typed(js_value_t *receiver, int32_t bare_tag, bool uses_ruler, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.usesRuler = uses_ruler;
  }
}

static js_value_t *
bare_app_kit_text_view_uses_inspector_bar(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.usesInspectorBar, &result);
      assert(err == 0);
    } else {
      bool uses_inspector_bar;
      if (!bare_app_kit__read_bool(env, argv[1], "uses_inspector_bar", &uses_inspector_bar)) return NULL;

      text_view.usesInspectorBar = uses_inspector_bar;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_uses_inspector_bar_typed(js_value_t *receiver, int32_t bare_tag, bool uses_inspector_bar, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.usesInspectorBar = uses_inspector_bar;
  }
}

static js_value_t *
bare_app_kit_text_view_incremental_searching_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.incrementalSearchingEnabled, &result);
      assert(err == 0);
    } else {
      bool incremental_searching_enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "incremental_searching_enabled", &incremental_searching_enabled)) return NULL;

      text_view.incrementalSearchingEnabled = incremental_searching_enabled;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_incremental_searching_enabled_typed(js_value_t *receiver, int32_t bare_tag, bool incremental_searching_enabled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.incrementalSearchingEnabled = incremental_searching_enabled;
  }
}

static js_value_t *
bare_app_kit_text_view_continuous_spell_checking_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.continuousSpellCheckingEnabled, &result);
      assert(err == 0);
    } else {
      bool continuous_spell_checking_enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "continuous_spell_checking_enabled", &continuous_spell_checking_enabled)) return NULL;

      text_view.continuousSpellCheckingEnabled = continuous_spell_checking_enabled;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_continuous_spell_checking_enabled_typed(js_value_t *receiver, int32_t bare_tag, bool continuous_spell_checking_enabled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.continuousSpellCheckingEnabled = continuous_spell_checking_enabled;
  }
}

static js_value_t *
bare_app_kit_text_view_grammar_checking_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.grammarCheckingEnabled, &result);
      assert(err == 0);
    } else {
      bool grammar_checking_enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "grammar_checking_enabled", &grammar_checking_enabled)) return NULL;

      text_view.grammarCheckingEnabled = grammar_checking_enabled;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_grammar_checking_enabled_typed(js_value_t *receiver, int32_t bare_tag, bool grammar_checking_enabled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.grammarCheckingEnabled = grammar_checking_enabled;
  }
}

static js_value_t *
bare_app_kit_text_view_automatic_spelling_correction_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.automaticSpellingCorrectionEnabled, &result);
      assert(err == 0);
    } else {
      bool automatic_spelling_correction_enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "automatic_spelling_correction_enabled", &automatic_spelling_correction_enabled)) return NULL;

      text_view.automaticSpellingCorrectionEnabled = automatic_spelling_correction_enabled;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_automatic_spelling_correction_enabled_typed(js_value_t *receiver, int32_t bare_tag, bool automatic_spelling_correction_enabled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.automaticSpellingCorrectionEnabled = automatic_spelling_correction_enabled;
  }
}

static js_value_t *
bare_app_kit_text_view_automatic_quote_substitution_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.automaticQuoteSubstitutionEnabled, &result);
      assert(err == 0);
    } else {
      bool automatic_quote_substitution_enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "automatic_quote_substitution_enabled", &automatic_quote_substitution_enabled)) return NULL;

      text_view.automaticQuoteSubstitutionEnabled = automatic_quote_substitution_enabled;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_automatic_quote_substitution_enabled_typed(js_value_t *receiver, int32_t bare_tag, bool automatic_quote_substitution_enabled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.automaticQuoteSubstitutionEnabled = automatic_quote_substitution_enabled;
  }
}

static js_value_t *
bare_app_kit_text_view_automatic_dash_substitution_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.automaticDashSubstitutionEnabled, &result);
      assert(err == 0);
    } else {
      bool automatic_dash_substitution_enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "automatic_dash_substitution_enabled", &automatic_dash_substitution_enabled)) return NULL;

      text_view.automaticDashSubstitutionEnabled = automatic_dash_substitution_enabled;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_automatic_dash_substitution_enabled_typed(js_value_t *receiver, int32_t bare_tag, bool automatic_dash_substitution_enabled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.automaticDashSubstitutionEnabled = automatic_dash_substitution_enabled;
  }
}

static js_value_t *
bare_app_kit_text_view_automatic_text_replacement_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.automaticTextReplacementEnabled, &result);
      assert(err == 0);
    } else {
      bool automatic_text_replacement_enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "automatic_text_replacement_enabled", &automatic_text_replacement_enabled)) return NULL;

      text_view.automaticTextReplacementEnabled = automatic_text_replacement_enabled;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_automatic_text_replacement_enabled_typed(js_value_t *receiver, int32_t bare_tag, bool automatic_text_replacement_enabled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.automaticTextReplacementEnabled = automatic_text_replacement_enabled;
  }
}

static js_value_t *
bare_app_kit_text_view_automatic_link_detection_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.automaticLinkDetectionEnabled, &result);
      assert(err == 0);
    } else {
      bool automatic_link_detection_enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "automatic_link_detection_enabled", &automatic_link_detection_enabled)) return NULL;

      text_view.automaticLinkDetectionEnabled = automatic_link_detection_enabled;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_automatic_link_detection_enabled_typed(js_value_t *receiver, int32_t bare_tag, bool automatic_link_detection_enabled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.automaticLinkDetectionEnabled = automatic_link_detection_enabled;
  }
}

static js_value_t *
bare_app_kit_text_view_smart_insert_delete_enabled(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_view.smartInsertDeleteEnabled, &result);
      assert(err == 0);
    } else {
      bool smart_insert_delete_enabled;
      if (!bare_app_kit__read_bool(env, argv[1], "smart_insert_delete_enabled", &smart_insert_delete_enabled)) return NULL;

      text_view.smartInsertDeleteEnabled = smart_insert_delete_enabled;
    }
  }

  return result;
}

static void
bare_app_kit_text_view_smart_insert_delete_enabled_typed(js_value_t *receiver, int32_t bare_tag, bool smart_insert_delete_enabled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextView *text_view = (NSTextView *) bare_object;

    text_view.smartInsertDeleteEnabled = smart_insert_delete_enabled;
  }
}

static js_value_t *
bare_app_kit_text_view_insert_text(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  NSString *string = bare_app_kit__to_string(env, argv[1]);

  @autoreleasepool {
    NSTextView *text_view = (__bridge NSTextView *) handle;

    [text_view insertText:string replacementRange:text_view.selectedRange];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_view_scroll_range_to_visible(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    [text_view scrollRangeToVisible:NSMakeRange(location, length)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_view_did_change_text(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSTextView *text_view = (__bridge NSTextView *) handle;

    [text_view didChangeText];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_view_align_left(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSTextView *text_view = (__bridge NSTextView *) handle;

    [text_view alignLeft:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_view_align_center(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSTextView *text_view = (__bridge NSTextView *) handle;

    [text_view alignCenter:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_view_align_right(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSTextView *text_view = (__bridge NSTextView *) handle;

    [text_view alignRight:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_view_check_text_in_document(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSTextView *text_view = (__bridge NSTextView *) handle;

    [text_view checkTextInDocument:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_text_view_attributed_string(js_env_t *env, js_callback_info_t *info) {
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
    NSTextView *text_view = (__bridge NSTextView *) handle;

    result = bare_foundation__bridge(env, [[[NSMutableAttributedString alloc] initWithAttributedString:[text_view attributedString]] autorelease]);
  }

  return result;
}

static js_value_t *
bare_app_kit_text_view_set_attributed_string(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id string = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSTextView *text_view = (__bridge NSTextView *) handle;

    [[text_view textStorage] setAttributedString:string];
  }

  return NULL;
}
