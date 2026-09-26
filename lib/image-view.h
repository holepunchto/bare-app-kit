#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareImageView : NSImageView <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareImageView

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
bare_app_kit_image_view_init(js_env_t *env, js_callback_info_t *info) {
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
    BareImageView *handle = [[[BareImageView alloc]
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
bare_app_kit_image_view_image(js_env_t *env, js_callback_info_t *info) {
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
    NSImageView *image_view = (__bridge NSImageView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, image_view.image);
    } else {
      image_view.image = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_image_view_image_scaling(js_env_t *env, js_callback_info_t *info) {
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
    NSImageView *image_view = (__bridge NSImageView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, image_view.imageScaling, &result);
      assert(err == 0);
    } else {
      int32_t image_scaling;
      if (!bare_app_kit__read_int32(env, argv[1], "image_scaling", &image_scaling)) return NULL;

      image_view.imageScaling = image_scaling;
    }
  }

  return result;
}

static void
bare_app_kit_image_view_image_scaling_typed(js_value_t *receiver, int32_t bare_tag, int32_t image_scaling, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSImageView *image_view = (NSImageView *) bare_object;

    image_view.imageScaling = image_scaling;
  }
}

static js_value_t *
bare_app_kit_image_view_image_alignment(js_env_t *env, js_callback_info_t *info) {
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
    NSImageView *image_view = (__bridge NSImageView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, image_view.imageAlignment, &result);
      assert(err == 0);
    } else {
      int32_t image_alignment;
      if (!bare_app_kit__read_int32(env, argv[1], "image_alignment", &image_alignment)) return NULL;

      image_view.imageAlignment = image_alignment;
    }
  }

  return result;
}

static void
bare_app_kit_image_view_image_alignment_typed(js_value_t *receiver, int32_t bare_tag, int32_t image_alignment, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSImageView *image_view = (NSImageView *) bare_object;

    image_view.imageAlignment = image_alignment;
  }
}

static js_value_t *
bare_app_kit_image_view_image_frame_style(js_env_t *env, js_callback_info_t *info) {
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
    NSImageView *image_view = (__bridge NSImageView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, image_view.imageFrameStyle, &result);
      assert(err == 0);
    } else {
      int32_t image_frame_style;
      if (!bare_app_kit__read_int32(env, argv[1], "image_frame_style", &image_frame_style)) return NULL;

      image_view.imageFrameStyle = image_frame_style;
    }
  }

  return result;
}

static void
bare_app_kit_image_view_image_frame_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t image_frame_style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSImageView *image_view = (NSImageView *) bare_object;

    image_view.imageFrameStyle = image_frame_style;
  }
}

static js_value_t *
bare_app_kit_image_view_editable(js_env_t *env, js_callback_info_t *info) {
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
    NSImageView *image_view = (__bridge NSImageView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, image_view.editable, &result);
      assert(err == 0);
    } else {
      bool editable;
      if (!bare_app_kit__read_bool(env, argv[1], "editable", &editable)) return NULL;

      image_view.editable = editable;
    }
  }

  return result;
}

static void
bare_app_kit_image_view_editable_typed(js_value_t *receiver, int32_t bare_tag, bool editable, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSImageView *image_view = (NSImageView *) bare_object;

    image_view.editable = editable;
  }
}

static js_value_t *
bare_app_kit_image_view_animates(js_env_t *env, js_callback_info_t *info) {
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
    NSImageView *image_view = (__bridge NSImageView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, image_view.animates, &result);
      assert(err == 0);
    } else {
      bool animates;
      if (!bare_app_kit__read_bool(env, argv[1], "animates", &animates)) return NULL;

      image_view.animates = animates;
    }
  }

  return result;
}

static void
bare_app_kit_image_view_animates_typed(js_value_t *receiver, int32_t bare_tag, bool animates, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSImageView *image_view = (NSImageView *) bare_object;

    image_view.animates = animates;
  }
}

static js_value_t *
bare_app_kit_image_view_content_tint_color(js_env_t *env, js_callback_info_t *info) {
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
    NSImageView *image_view = (__bridge NSImageView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, image_view.contentTintColor);
    } else {
      image_view.contentTintColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}
