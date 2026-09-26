#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

enum {
  bare_app_kit_switch_event_change = 1 << 0,
  bare_app_kit_switch_event_will_draw = 1 << 1,
};


API_AVAILABLE(macos(10.15))
@interface BareSwitch : NSSwitch <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareSwitch

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

- (void)onChange:(id)sender {
  if (mask & bare_app_kit_switch_event_change) bare_app_kit__emit(env, ctx, "_onchange");
}

BARE_APP_KIT_REPORTS_WILL_DRAW(bare_app_kit_switch_event_will_draw)

@end

static js_value_t *
bare_app_kit_switch_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
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
    BareSwitch *handle = [[[BareSwitch alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation_bridge(env, registry, handle);

    handle->env = env;

    // Weak, so the native object does not keep its own wrapper alive. Events
    // are dropped once the wrapper is collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onChange:)];
  }

  return result;
}

static js_value_t *
bare_app_kit_switch_state(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1 || argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSSwitch *control = (__bridge NSSwitch *) handle;

    if (argc == 1) {
      err = js_create_int32(env, control.state, &result);
      assert(err == 0);
    } else {
      int32_t state;
      if (!bare_app_kit__read_int32(env, argv[1], "state", &state)) return NULL;

      control.state = state;
    }
  }

  return result;
}
