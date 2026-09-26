#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_graphics_context_should_antialias(js_env_t *env, js_callback_info_t *info) {
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
    NSGraphicsContext *graphics_context = (__bridge NSGraphicsContext *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, graphics_context.shouldAntialias, &result);
      assert(err == 0);
    } else {
      bool should_antialias;
      if (!bare_app_kit__read_bool(env, argv[1], "should_antialias", &should_antialias)) return NULL;

      graphics_context.shouldAntialias = should_antialias;
    }
  }

  return result;
}

static void
bare_app_kit_graphics_context_should_antialias_typed(js_value_t *receiver, int32_t bare_tag, bool should_antialias, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGraphicsContext *graphics_context = (NSGraphicsContext *) bare_object;

    graphics_context.shouldAntialias = should_antialias;
  }
}

static js_value_t *
bare_app_kit_graphics_context_image_interpolation(js_env_t *env, js_callback_info_t *info) {
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
    NSGraphicsContext *graphics_context = (__bridge NSGraphicsContext *) handle;

    if (argc == 1) {
      err = js_create_int32(env, graphics_context.imageInterpolation, &result);
      assert(err == 0);
    } else {
      int32_t image_interpolation;
      if (!bare_app_kit__read_int32(env, argv[1], "image_interpolation", &image_interpolation)) return NULL;

      graphics_context.imageInterpolation = image_interpolation;
    }
  }

  return result;
}

static void
bare_app_kit_graphics_context_image_interpolation_typed(js_value_t *receiver, int32_t bare_tag, int32_t image_interpolation, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGraphicsContext *graphics_context = (NSGraphicsContext *) bare_object;

    graphics_context.imageInterpolation = image_interpolation;
  }
}

static js_value_t *
bare_app_kit_graphics_context_compositing_operation(js_env_t *env, js_callback_info_t *info) {
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
    NSGraphicsContext *graphics_context = (__bridge NSGraphicsContext *) handle;

    if (argc == 1) {
      err = js_create_int32(env, graphics_context.compositingOperation, &result);
      assert(err == 0);
    } else {
      int32_t compositing_operation;
      if (!bare_app_kit__read_int32(env, argv[1], "compositing_operation", &compositing_operation)) return NULL;

      graphics_context.compositingOperation = compositing_operation;
    }
  }

  return result;
}

static void
bare_app_kit_graphics_context_compositing_operation_typed(js_value_t *receiver, int32_t bare_tag, int32_t compositing_operation, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSGraphicsContext *graphics_context = (NSGraphicsContext *) bare_object;

    graphics_context.compositingOperation = compositing_operation;
  }
}

static js_value_t *
bare_app_kit_graphics_context_flipped(js_env_t *env, js_callback_info_t *info) {
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
    NSGraphicsContext *graphics_context = (__bridge NSGraphicsContext *) handle;

    err = js_get_boolean(env, graphics_context.flipped, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_graphics_context_current(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSGraphicsContext currentContext]);
  }

  return result;
}

static js_value_t *
bare_app_kit_graphics_context_save(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  @autoreleasepool {
    [NSGraphicsContext saveGraphicsState];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_graphics_context_restore(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  @autoreleasepool {
    [NSGraphicsContext restoreGraphicsState];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_graphics_context_flush(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSGraphicsContext *graphics_context = (__bridge NSGraphicsContext *) handle;

    [graphics_context flushGraphics];
  }

  return NULL;
}
