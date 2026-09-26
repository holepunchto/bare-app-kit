#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_visual_effect_view_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

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
    NSVisualEffectView *handle = [[[NSVisualEffectView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_visual_effect_view_material(js_env_t *env, js_callback_info_t *info) {
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
    NSVisualEffectView *visual_effect_view = (__bridge NSVisualEffectView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, visual_effect_view.material, &result);
      assert(err == 0);
    } else {
      int32_t material;
      if (!bare_app_kit__read_int32(env, argv[1], "material", &material)) return NULL;

      visual_effect_view.material = material;
    }
  }

  return result;
}

static void
bare_app_kit_visual_effect_view_material_typed(js_value_t *receiver, int32_t bare_tag, int32_t material, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSVisualEffectView *visual_effect_view = (NSVisualEffectView *) bare_object;

    visual_effect_view.material = material;
  }
}

static js_value_t *
bare_app_kit_visual_effect_view_blending_mode(js_env_t *env, js_callback_info_t *info) {
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
    NSVisualEffectView *visual_effect_view = (__bridge NSVisualEffectView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, visual_effect_view.blendingMode, &result);
      assert(err == 0);
    } else {
      int32_t blending_mode;
      if (!bare_app_kit__read_int32(env, argv[1], "blending_mode", &blending_mode)) return NULL;

      visual_effect_view.blendingMode = blending_mode;
    }
  }

  return result;
}

static void
bare_app_kit_visual_effect_view_blending_mode_typed(js_value_t *receiver, int32_t bare_tag, int32_t blending_mode, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSVisualEffectView *visual_effect_view = (NSVisualEffectView *) bare_object;

    visual_effect_view.blendingMode = blending_mode;
  }
}

static js_value_t *
bare_app_kit_visual_effect_view_state(js_env_t *env, js_callback_info_t *info) {
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
    NSVisualEffectView *visual_effect_view = (__bridge NSVisualEffectView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, visual_effect_view.state, &result);
      assert(err == 0);
    } else {
      int32_t state;
      if (!bare_app_kit__read_int32(env, argv[1], "state", &state)) return NULL;

      visual_effect_view.state = state;
    }
  }

  return result;
}

static void
bare_app_kit_visual_effect_view_state_typed(js_value_t *receiver, int32_t bare_tag, int32_t state, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSVisualEffectView *visual_effect_view = (NSVisualEffectView *) bare_object;

    visual_effect_view.state = state;
  }
}

static js_value_t *
bare_app_kit_visual_effect_view_emphasized(js_env_t *env, js_callback_info_t *info) {
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
    NSVisualEffectView *visual_effect_view = (__bridge NSVisualEffectView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, visual_effect_view.emphasized, &result);
      assert(err == 0);
    } else {
      bool emphasized;
      if (!bare_app_kit__read_bool(env, argv[1], "emphasized", &emphasized)) return NULL;

      visual_effect_view.emphasized = emphasized;
    }
  }

  return result;
}

static void
bare_app_kit_visual_effect_view_emphasized_typed(js_value_t *receiver, int32_t bare_tag, bool emphasized, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSVisualEffectView *visual_effect_view = (NSVisualEffectView *) bare_object;

    visual_effect_view.emphasized = emphasized;
  }
}
