#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

// An `NSClipView` says it scrolled by posting `NSViewBoundsDidChange`, which
// covers a programmatic scroll as well as the user's. There is no delegate to
// take, so the notification is observed for as long as the mask asks for it.
enum {
  bare_app_kit_clip_view_event_bounds_did_change = 1 << 0,
};

@interface BareClipView : NSClipView <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;

  int32_t mask;
}

@end

@implementation BareClipView

- (void)dealloc {
  int err;

  [NSNotificationCenter.defaultCenter removeObserver:self];

  err = js_delete_reference(env, ctx);
  assert(err == 0);

  [super dealloc];
}

- (int32_t)eventMask {
  return mask;
}

- (void)setEventMask:(int32_t)value {
  int32_t changed = mask ^ value;

  mask = value;

  if ((changed & bare_app_kit_clip_view_event_bounds_did_change) == 0) return;

  if ((value & bare_app_kit_clip_view_event_bounds_did_change) != 0) {
    [NSNotificationCenter.defaultCenter
      addObserver:self
         selector:@selector(bareBoundsDidChange:)
             name:NSViewBoundsDidChangeNotification
           object:self];
  } else {
    [NSNotificationCenter.defaultCenter
      removeObserver:self
                name:NSViewBoundsDidChangeNotification
              object:self];
  }
}

- (void)bareBoundsDidChange:(NSNotification *)notification {
  bare_app_kit__emit(env, ctx, "_onboundsdidchange");
}

@end

static js_value_t *
bare_app_kit_clip_view_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 5);

  double x;
  if (!bare_app_kit__read_double(env, argv[0], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[1], "y", &y)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[2], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[3], "height", &height)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    BareClipView *handle = [[[BareClipView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_clip_view_scroll_to_point(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  @autoreleasepool {
    NSClipView *view = (__bridge NSClipView *) handle;

    [view scrollToPoint:NSMakePoint(x, y)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_clip_view_draws_background(js_env_t *env, js_callback_info_t *info) {
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
    NSClipView *view = (__bridge NSClipView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, view.drawsBackground, &result);
      assert(err == 0);
    } else {
      bool draws_background;
      if (!bare_app_kit__read_bool(env, argv[1], "draws_background", &draws_background)) return NULL;

      view.drawsBackground = draws_background;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_clip_view_background_color(js_env_t *env, js_callback_info_t *info) {
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
    NSClipView *view = (__bridge NSClipView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, view.backgroundColor);
    } else {
      view.backgroundColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}
