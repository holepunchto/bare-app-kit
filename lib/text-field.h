#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareTextField : NSTextField <NSTextFieldDelegate, NSTextViewDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareTextField

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

- (void)controlTextDidChange:(NSNotification *)notification {
  if ((mask & (1 << 1)) == 0) return;

  bare_app_kit__emit(env, ctx, "_oninput");
}

- (void)controlTextDidBeginEditing:(NSNotification *)notification {
  if ((mask & (1 << 2)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onbeginediting");
}

- (void)controlTextDidEndEditing:(NSNotification *)notification {
  if ((mask & (1 << 3)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onendediting");
}

// Editing beginning is not the same as the field taking focus: AppKit posts
// the first when the text object starts changing and the second travels the
// responder chain, so a field that is focused and not yet typed into has done
// only the second.
// The field editor reports where the caret went and what is about to replace
// what, neither of which a control has anywhere else.
- (void)textViewDidChangeSelection:(NSNotification *)notification {
  if ((mask & (1 << 6)) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidchangeselection");
}

- (BOOL)textView:(NSTextView *)view shouldChangeTextInRange:(NSRange)range replacementString:(NSString *)string {
  if ((mask & (1 << 7)) != 0) {
    bare_app_kit__emit_replacement(env, ctx, "_onshouldchangetext", (int32_t) range.location, (int32_t) range.length, string);
  }

  return YES;
}

- (BOOL)becomeFirstResponder {
  BOOL became = [super becomeFirstResponder];

  if (became && (mask & (1 << 4)) != 0) {
    bare_app_kit__emit(env, ctx, "_onbecomefirstresponder");
  }

  return became;
}

- (BOOL)resignFirstResponder {
  BOOL resigned = [super resignFirstResponder];

  if (resigned && (mask & (1 << 5)) != 0) {
    bare_app_kit__emit(env, ctx, "_onresignfirstresponder");
  }

  return resigned;
}

@end

static js_value_t *
bare_app_kit_text_field_init(js_env_t *env, js_callback_info_t *info) {
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
    BareTextField *handle = [[[BareTextField alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onChange:)];
    [handle setDelegate:handle];
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_placeholder_string(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, text_field.placeholderString);
    } else {
      text_field.placeholderString = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_text_color(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, text_field.textColor);
    } else {
      text_field.textColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_background_color(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, text_field.backgroundColor);
    } else {
      text_field.backgroundColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_field_bordered(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_field.bordered, &result);
      assert(err == 0);
    } else {
      bool bordered;
      if (!bare_app_kit__read_bool(env, argv[1], "bordered", &bordered)) return NULL;

      text_field.bordered = bordered;
    }
  }

  return result;
}

static void
bare_app_kit_text_field_bordered_typed(js_value_t *receiver, int32_t bare_tag, bool bordered, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextField *text_field = (NSTextField *) bare_object;

    text_field.bordered = bordered;
  }
}

static js_value_t *
bare_app_kit_text_field_bezeled(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_field.bezeled, &result);
      assert(err == 0);
    } else {
      bool bezeled;
      if (!bare_app_kit__read_bool(env, argv[1], "bezeled", &bezeled)) return NULL;

      text_field.bezeled = bezeled;
    }
  }

  return result;
}

static void
bare_app_kit_text_field_bezeled_typed(js_value_t *receiver, int32_t bare_tag, bool bezeled, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextField *text_field = (NSTextField *) bare_object;

    text_field.bezeled = bezeled;
  }
}

static js_value_t *
bare_app_kit_text_field_editable(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_field.editable, &result);
      assert(err == 0);
    } else {
      bool editable;
      if (!bare_app_kit__read_bool(env, argv[1], "editable", &editable)) return NULL;

      text_field.editable = editable;
    }
  }

  return result;
}

static void
bare_app_kit_text_field_editable_typed(js_value_t *receiver, int32_t bare_tag, bool editable, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextField *text_field = (NSTextField *) bare_object;

    text_field.editable = editable;
  }
}

static js_value_t *
bare_app_kit_text_field_selectable(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_field.selectable, &result);
      assert(err == 0);
    } else {
      bool selectable;
      if (!bare_app_kit__read_bool(env, argv[1], "selectable", &selectable)) return NULL;

      text_field.selectable = selectable;
    }
  }

  return result;
}

static void
bare_app_kit_text_field_selectable_typed(js_value_t *receiver, int32_t bare_tag, bool selectable, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextField *text_field = (NSTextField *) bare_object;

    text_field.selectable = selectable;
  }
}

static js_value_t *
bare_app_kit_text_field_draws_background(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, text_field.drawsBackground, &result);
      assert(err == 0);
    } else {
      bool draws_background;
      if (!bare_app_kit__read_bool(env, argv[1], "draws_background", &draws_background)) return NULL;

      text_field.drawsBackground = draws_background;
    }
  }

  return result;
}

static void
bare_app_kit_text_field_draws_background_typed(js_value_t *receiver, int32_t bare_tag, bool draws_background, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextField *text_field = (NSTextField *) bare_object;

    text_field.drawsBackground = draws_background;
  }
}

static js_value_t *
bare_app_kit_text_field_bezel_style(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_create_int32(env, text_field.bezelStyle, &result);
      assert(err == 0);
    } else {
      int32_t bezel_style;
      if (!bare_app_kit__read_int32(env, argv[1], "bezel_style", &bezel_style)) return NULL;

      text_field.bezelStyle = bezel_style;
    }
  }

  return result;
}

static void
bare_app_kit_text_field_bezel_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t bezel_style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextField *text_field = (NSTextField *) bare_object;

    text_field.bezelStyle = bezel_style;
  }
}

static js_value_t *
bare_app_kit_text_field_maximum_number_of_lines(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_create_int32(env, text_field.maximumNumberOfLines, &result);
      assert(err == 0);
    } else {
      int32_t maximum_number_of_lines;
      if (!bare_app_kit__read_int32(env, argv[1], "maximum_number_of_lines", &maximum_number_of_lines)) return NULL;

      text_field.maximumNumberOfLines = maximum_number_of_lines;
    }
  }

  return result;
}

static void
bare_app_kit_text_field_maximum_number_of_lines_typed(js_value_t *receiver, int32_t bare_tag, int32_t maximum_number_of_lines, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextField *text_field = (NSTextField *) bare_object;

    text_field.maximumNumberOfLines = maximum_number_of_lines;
  }
}

static js_value_t *
bare_app_kit_text_field_preferred_max_layout_width(js_env_t *env, js_callback_info_t *info) {
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
    NSTextField *text_field = (__bridge NSTextField *) handle;

    if (argc == 1) {
      err = js_create_double(env, text_field.preferredMaxLayoutWidth, &result);
      assert(err == 0);
    } else {
      double preferred_max_layout_width;
      if (!bare_app_kit__read_double(env, argv[1], "preferred_max_layout_width", &preferred_max_layout_width)) return NULL;

      text_field.preferredMaxLayoutWidth = preferred_max_layout_width;
    }
  }

  return result;
}

static void
bare_app_kit_text_field_preferred_max_layout_width_typed(js_value_t *receiver, int32_t bare_tag, double preferred_max_layout_width, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTextField *text_field = (NSTextField *) bare_object;

    text_field.preferredMaxLayoutWidth = preferred_max_layout_width;
  }
}

static js_value_t *
bare_app_kit_text_field_select_text(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSTextField *text_field = (__bridge NSTextField *) handle;

    [text_field selectText:nil];
  }

  return NULL;
}
