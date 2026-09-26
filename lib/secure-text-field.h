#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

enum {
  bare_app_kit_secure_text_field_event_change = 1 << 0,
  bare_app_kit_secure_text_field_event_did_change = 1 << 1,
  bare_app_kit_secure_text_field_event_did_begin_editing = 1 << 2,
  bare_app_kit_secure_text_field_event_did_end_editing = 1 << 3,
  bare_app_kit_secure_text_field_event_become_first_responder = 1 << 4,
  bare_app_kit_secure_text_field_event_resign_first_responder = 1 << 5,
  bare_app_kit_secure_text_field_event_did_change_selection = 1 << 6,
  bare_app_kit_secure_text_field_event_should_change_text = 1 << 7,
  bare_app_kit_secure_text_field_event_will_draw = 1 << 8,
};


@interface BareSecureTextField : NSSecureTextField <NSTextFieldDelegate, NSTextViewDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareSecureTextField

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
  if ((mask & bare_app_kit_secure_text_field_event_change) == 0) return;

  bare_app_kit__emit(env, ctx, "_onchange");
}

- (void)controlTextDidChange:(NSNotification *)notification {
  if ((mask & bare_app_kit_secure_text_field_event_did_change) == 0) return;

  bare_app_kit__emit(env, ctx, "_oninput");
}

- (void)controlTextDidBeginEditing:(NSNotification *)notification {
  if ((mask & bare_app_kit_secure_text_field_event_did_begin_editing) == 0) return;

  bare_app_kit__emit(env, ctx, "_onbeginediting");
}

- (void)controlTextDidEndEditing:(NSNotification *)notification {
  if ((mask & bare_app_kit_secure_text_field_event_did_end_editing) == 0) return;

  bare_app_kit__emit(env, ctx, "_onendediting");
}

// The field editor reports where the caret went and what is about to be
// replaced, which a control has no other way to report.
- (void)textViewDidChangeSelection:(NSNotification *)notification {
  if ((mask & bare_app_kit_secure_text_field_event_did_change_selection) == 0) return;

  bare_app_kit__emit(env, ctx, "_ondidchangeselection");
}

- (BOOL)textView:(NSTextView *)view shouldChangeTextInRange:(NSRange)range replacementString:(NSString *)string {
  if ((mask & bare_app_kit_secure_text_field_event_should_change_text) != 0) {
    bare_app_kit__emit_replacement(env, ctx, "_onshouldchangetext", (int32_t) range.location, (int32_t) range.length, string);
  }

  return YES;
}

// Editing starting is not the same as the field taking focus, as for a plain
// text field.
- (BOOL)becomeFirstResponder {
  BOOL became = [super becomeFirstResponder];

  if (became && (mask & bare_app_kit_secure_text_field_event_become_first_responder) != 0) {
    bare_app_kit__emit(env, ctx, "_onbecomefirstresponder");
  }

  return became;
}

- (BOOL)resignFirstResponder {
  BOOL resigned = [super resignFirstResponder];

  if (resigned && (mask & bare_app_kit_secure_text_field_event_resign_first_responder) != 0) {
    bare_app_kit__emit(env, ctx, "_onresignfirstresponder");
  }

  return resigned;
}

BARE_APP_KIT_REPORTS_WILL_DRAW(bare_app_kit_secure_text_field_event_will_draw)

@end

static js_value_t *
bare_app_kit_secure_text_field_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
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
    BareSecureTextField *handle = [[[BareSecureTextField alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation_bridge(env, registry, handle);

    handle->env = env;

    // Weak, so the native object does not keep its own wrapper alive. Events
    // are dropped once the wrapper is collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onChange:)];
    [handle setDelegate:handle];
  }

  return result;
}
