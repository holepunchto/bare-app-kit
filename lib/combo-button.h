#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

API_AVAILABLE(macos(13.0))
@interface BareComboButton : NSComboButton <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareComboButton

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

- (void)onClick:(id)sender {
  if ((mask & (1 << 0)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onclick");
}

@end

static js_value_t *
bare_app_kit_combo_button_init(js_env_t *env, js_callback_info_t *info) {
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
    BareComboButton *handle = [[[BareComboButton alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onClick:)];
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_button_title(js_env_t *env, js_callback_info_t *info) {
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
    NSComboButton *combo_button = (__bridge NSComboButton *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, combo_button.title);
    } else {
      combo_button.title = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_button_image(js_env_t *env, js_callback_info_t *info) {
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
    NSComboButton *combo_button = (__bridge NSComboButton *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, combo_button.image);
    } else {
      combo_button.image = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_combo_button_image_scaling(js_env_t *env, js_callback_info_t *info) {
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
    NSComboButton *combo_button = (__bridge NSComboButton *) handle;

    if (argc == 1) {
      err = js_create_int32(env, combo_button.imageScaling, &result);
      assert(err == 0);
    } else {
      int32_t image_scaling;
      if (!bare_app_kit__read_int32(env, argv[1], "image_scaling", &image_scaling)) return NULL;

      combo_button.imageScaling = image_scaling;
    }
  }

  return result;
}

static void
bare_app_kit_combo_button_image_scaling_typed(js_value_t *receiver, int32_t bare_tag, int32_t image_scaling, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSComboButton *combo_button = (NSComboButton *) bare_object;

    combo_button.imageScaling = image_scaling;
  }
}

static js_value_t *
bare_app_kit_combo_button_style(js_env_t *env, js_callback_info_t *info) {
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
    NSComboButton *combo_button = (__bridge NSComboButton *) handle;

    if (argc == 1) {
      err = js_create_int32(env, combo_button.style, &result);
      assert(err == 0);
    } else {
      int32_t style;
      if (!bare_app_kit__read_int32(env, argv[1], "style", &style)) return NULL;

      combo_button.style = style;
    }
  }

  return result;
}

static void
bare_app_kit_combo_button_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSComboButton *combo_button = (NSComboButton *) bare_object;

    combo_button.style = style;
  }
}

static js_value_t *
bare_app_kit_combo_button_menu(js_env_t *env, js_callback_info_t *info) {
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
    NSComboButton *combo_button = (__bridge NSComboButton *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, combo_button.menu);
    } else {
      combo_button.menu = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}
