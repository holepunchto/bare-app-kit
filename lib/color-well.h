#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareColorWell : NSColorWell <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareColorWell

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

@end

static js_value_t *
bare_app_kit_color_well_init(js_env_t *env, js_callback_info_t *info) {
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
    BareColorWell *handle = [[[BareColorWell alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onChange:)];
  }

  return result;
}

static js_value_t *
bare_app_kit_color_well_color(js_env_t *env, js_callback_info_t *info) {
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
    NSColorWell *color_well = (__bridge NSColorWell *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, color_well.color);
    } else {
      color_well.color = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_color_well_bordered(js_env_t *env, js_callback_info_t *info) {
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
    NSColorWell *color_well = (__bridge NSColorWell *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, color_well.bordered, &result);
      assert(err == 0);
    } else {
      bool bordered;
      if (!bare_app_kit__read_bool(env, argv[1], "bordered", &bordered)) return NULL;

      color_well.bordered = bordered;
    }
  }

  return result;
}

static void
bare_app_kit_color_well_bordered_typed(js_value_t *receiver, int32_t bare_tag, bool bordered, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSColorWell *color_well = (NSColorWell *) bare_object;

    color_well.bordered = bordered;
  }
}

static js_value_t *
bare_app_kit_color_well_active(js_env_t *env, js_callback_info_t *info) {
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
    NSColorWell *color_well = (__bridge NSColorWell *) handle;

    err = js_get_boolean(env, color_well.active, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_well_color_well_style(js_env_t *env, js_callback_info_t *info) {
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
    NSColorWell *color_well = (__bridge NSColorWell *) handle;

    if (argc == 1) {
      err = js_create_int32(env, color_well.colorWellStyle, &result);
      assert(err == 0);
    } else {
      int32_t color_well_style;
      if (!bare_app_kit__read_int32(env, argv[1], "color_well_style", &color_well_style)) return NULL;

      color_well.colorWellStyle = color_well_style;
    }
  }

  return result;
}

static void
bare_app_kit_color_well_color_well_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t color_well_style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSColorWell *color_well = (NSColorWell *) bare_object;

    color_well.colorWellStyle = color_well_style;
  }
}

static js_value_t *
bare_app_kit_color_well_image(js_env_t *env, js_callback_info_t *info) {
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
    NSColorWell *color_well = (__bridge NSColorWell *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, color_well.image);
    } else {
      color_well.image = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_color_well_activate(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  bool exclusive;
  if (!bare_app_kit__read_bool(env, argv[1], "exclusive", &exclusive)) return NULL;

  @autoreleasepool {
    NSColorWell *color_well = (__bridge NSColorWell *) handle;

    [color_well activate:exclusive];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_color_well_deactivate(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSColorWell *color_well = (__bridge NSColorWell *) handle;

    [color_well deactivate];
  }

  return NULL;
}
