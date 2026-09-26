#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

enum {
  bare_app_kit_tracking_area_event_mouse_entered = 1 << 0,
  bare_app_kit_tracking_area_event_mouse_exited = 1 << 1,
  bare_app_kit_tracking_area_event_mouse_moved = 1 << 2,
  bare_app_kit_tracking_area_event_cursor_update = 1 << 3,
};


// A tracking area reports to an owner object without retaining it, so the owner
// is kept alive by the tracking area here.
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
  if (mask & bare_app_kit_tracking_area_event_mouse_entered) bare_app_kit__emit(env, ctx, "_onmouseentered");
}

- (void)mouseExited:(NSEvent *)event {
  if (mask & bare_app_kit_tracking_area_event_mouse_exited) bare_app_kit__emit(env, ctx, "_onmouseexited");
}

- (void)mouseMoved:(NSEvent *)event {
  if (mask & bare_app_kit_tracking_area_event_mouse_moved) bare_app_kit__emit(env, ctx, "_onmousemoved");
}

- (void)cursorUpdate:(NSEvent *)event {
  if (mask & bare_app_kit_tracking_area_event_cursor_update) bare_app_kit__emit(env, ctx, "_oncursorupdate");
}

@end

@implementation BareTrackingArea

// The callbacks are on the owner, so the mask is too.
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

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
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

    result = bare_foundation_bridge(env, registry, handle);

    // Weak, so the native object does not keep its own wrapper alive. Events
    // are dropped once the wrapper is collected.
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

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

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

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSTrackingArea *tracking_area = (__bridge NSTrackingArea *) handle;

    err = js_create_int32(env, tracking_area.options, &result);
    assert(err == 0);
  }

  return result;
}
