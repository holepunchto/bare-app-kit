#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

// A tracking area delivers its events to an owner object, and does not retain
// it, so the owner lives here and is kept alive by the tracking area itself.
@interface BareTrackingAreaOwner : NSObject <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@interface BareTrackingArea : NSTrackingArea <BareEventTarget> {
@public
  BareTrackingAreaOwner *owner;
}

@end

@implementation BareTrackingAreaOwner

- (int32_t)eventMask {
  return mask;
}

- (void)setEventMask:(int32_t)value {
  mask = value;
}

- (void)dealloc {
  int err;

  err = js_delete_reference(env, ctx);
  assert(err == 0);

  [super dealloc];
}

- (void)mouseEntered:(NSEvent *)event {
  if (mask & (1 << 0)) bare_app_kit__emit(env, ctx, "_onmouseentered");
}

- (void)mouseExited:(NSEvent *)event {
  if (mask & (1 << 1)) bare_app_kit__emit(env, ctx, "_onmouseexited");
}

- (void)mouseMoved:(NSEvent *)event {
  if (mask & (1 << 2)) bare_app_kit__emit(env, ctx, "_onmousemoved");
}

- (void)cursorUpdate:(NSEvent *)event {
  if (mask & (1 << 3)) bare_app_kit__emit(env, ctx, "_oncursorupdate");
}

@end

@implementation BareTrackingArea

// The callbacks live on the owner, so the mask does too.
- (int32_t)eventMask {
  return owner.eventMask;
}

- (void)setEventMask:(int32_t)value {
  owner.eventMask = value;
}

- (void)dealloc {
  [owner release];

  [super dealloc];
}

@end

static js_value_t *
bare_app_kit_tracking_area_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 6;
  js_value_t *argv[6];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 6);

  double x;
  if (!bare_app_kit__read_double(env, argv[0], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[1], "y", &y)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[2], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[3], "height", &height)) return NULL;

  int32_t options;
  if (!bare_app_kit__read_int32(env, argv[4], "options", &options)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    BareTrackingAreaOwner *owner = [[BareTrackingAreaOwner alloc] init];

    owner->env = env;

    BareTrackingArea *handle = [[[BareTrackingArea alloc]
      initWithRect:NSMakeRect(x, y, width, height)
           options:options
             owner:owner
          userInfo:nil] autorelease];

    handle->owner = owner;

    result = bare_foundation__bridge(env, handle);

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[5], 0, &owner->ctx);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_tracking_area_rect(js_env_t *env, js_callback_info_t *info) {
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
    NSTrackingArea *tracking_area = (__bridge NSTrackingArea *) handle;

    result = bare_app_kit__from_rect(env, tracking_area.rect);
  }

  return result;
}

static js_value_t *
bare_app_kit_tracking_area_options(js_env_t *env, js_callback_info_t *info) {
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
    NSTrackingArea *tracking_area = (__bridge NSTrackingArea *) handle;

    err = js_create_int32(env, tracking_area.options, &result);
    assert(err == 0);
  }

  return result;
}
