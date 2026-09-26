#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareTokenField : NSTokenField <NSTokenFieldDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareTokenField

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

@end

static js_value_t *
bare_app_kit_token_field_init(js_env_t *env, js_callback_info_t *info) {
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
    BareTokenField *handle = [[[BareTokenField alloc]
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
bare_app_kit_token_field_token_style(js_env_t *env, js_callback_info_t *info) {
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
    NSTokenField *token_field = (__bridge NSTokenField *) handle;

    if (argc == 1) {
      err = js_create_int32(env, token_field.tokenStyle, &result);
      assert(err == 0);
    } else {
      int32_t token_style;
      if (!bare_app_kit__read_int32(env, argv[1], "token_style", &token_style)) return NULL;

      token_field.tokenStyle = token_style;
    }
  }

  return result;
}

static void
bare_app_kit_token_field_token_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t token_style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTokenField *token_field = (NSTokenField *) bare_object;

    token_field.tokenStyle = token_style;
  }
}

static js_value_t *
bare_app_kit_token_field_completion_delay(js_env_t *env, js_callback_info_t *info) {
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
    NSTokenField *token_field = (__bridge NSTokenField *) handle;

    if (argc == 1) {
      err = js_create_double(env, token_field.completionDelay, &result);
      assert(err == 0);
    } else {
      double completion_delay;
      if (!bare_app_kit__read_double(env, argv[1], "completion_delay", &completion_delay)) return NULL;

      token_field.completionDelay = completion_delay;
    }
  }

  return result;
}

static void
bare_app_kit_token_field_completion_delay_typed(js_value_t *receiver, int32_t bare_tag, double completion_delay, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTokenField *token_field = (NSTokenField *) bare_object;

    token_field.completionDelay = completion_delay;
  }
}

static js_value_t *
bare_app_kit_token_field_tokens(js_env_t *env, js_callback_info_t *info) {
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
    NSTokenField *token_field = (__bridge NSTokenField *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_strings(env, token_field.objectValue);
    } else {
      token_field.objectValue = bare_app_kit__to_strings(env, argv[1]);
    }
  }

  return result;
}
