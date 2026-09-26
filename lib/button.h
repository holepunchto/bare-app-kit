#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareButton : NSButton <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareButton

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

- (void)mouseDown:(NSEvent *)event {
  if (mask & (1 << 0)) bare_app_kit__emit(env, ctx, "_onmousedown");

  [super mouseDown:event];
}

- (void)onClick:(id)sender {
  if (mask & (1 << 1)) bare_app_kit__emit(env, ctx, "_onclick");
}

@end

static js_value_t *
bare_app_kit_button_init(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *handle = [[[BareButton alloc]
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
bare_app_kit_button_title(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, [button title]);
    } else {
      [button setTitle:bare_app_kit__to_string(env, argv[1])];
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_alternate_title(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, [button alternateTitle]);
    } else {
      [button setAlternateTitle:bare_app_kit__to_string(env, argv[1])];
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_state(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_create_int32(env, button.state, &result);
      assert(err == 0);
    } else {
      int32_t state;
      if (!bare_app_kit__read_int32(env, argv[1], "state", &state)) return NULL;

      button.state = state;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_allows_mixed_state(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, button.allowsMixedState, &result);
      assert(err == 0);
    } else {
      bool allows_mixed_state;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_mixed_state", &allows_mixed_state)) return NULL;

      button.allowsMixedState = allows_mixed_state;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_bezel_style(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_create_int32(env, button.bezelStyle, &result);
      assert(err == 0);
    } else {
      int32_t bezel_style;
      if (!bare_app_kit__read_int32(env, argv[1], "bezel_style", &bezel_style)) return NULL;

      button.bezelStyle = bezel_style;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_bordered(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, button.bordered, &result);
      assert(err == 0);
    } else {
      bool bordered;
      if (!bare_app_kit__read_bool(env, argv[1], "bordered", &bordered)) return NULL;

      button.bordered = bordered;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_transparent(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, button.transparent, &result);
      assert(err == 0);
    } else {
      bool transparent;
      if (!bare_app_kit__read_bool(env, argv[1], "transparent", &transparent)) return NULL;

      button.transparent = transparent;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_shows_border_only_while_mouse_inside(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, button.showsBorderOnlyWhileMouseInside, &result);
      assert(err == 0);
    } else {
      bool shows_border_only_while_mouse_inside;
      if (!bare_app_kit__read_bool(env, argv[1], "shows_border_only_while_mouse_inside", &shows_border_only_while_mouse_inside)) return NULL;

      button.showsBorderOnlyWhileMouseInside = shows_border_only_while_mouse_inside;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_spring_loaded(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, button.springLoaded, &result);
      assert(err == 0);
    } else {
      bool spring_loaded;
      if (!bare_app_kit__read_bool(env, argv[1], "spring_loaded", &spring_loaded)) return NULL;

      button.springLoaded = spring_loaded;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_has_destructive_action(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, button.hasDestructiveAction, &result);
      assert(err == 0);
    } else {
      bool has_destructive_action;
      if (!bare_app_kit__read_bool(env, argv[1], "has_destructive_action", &has_destructive_action)) return NULL;

      button.hasDestructiveAction = has_destructive_action;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_key_equivalent(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, button.keyEquivalent);
    } else {
      button.keyEquivalent = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_key_equivalent_modifier_mask(js_env_t *env, js_callback_info_t *info) {
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
    BareButton *button = (__bridge BareButton *) handle;

    if (argc == 1) {
      err = js_create_int64(env, button.keyEquivalentModifierMask, &result);
      assert(err == 0);
    } else {
      int64_t key_equivalent_modifier_mask;
      err = js_get_value_int64(env, argv[1], &key_equivalent_modifier_mask);
      assert(err == 0);

      button.keyEquivalentModifierMask = key_equivalent_modifier_mask;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_set_button_type(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  int32_t type;
  if (!bare_app_kit__read_int32(env, argv[1], "type", &type)) return NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    [button setButtonType:type];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_button_set_periodic_delay(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double delay;
  if (!bare_app_kit__read_double(env, argv[1], "delay", &delay)) return NULL;

  double interval;
  if (!bare_app_kit__read_double(env, argv[2], "interval", &interval)) return NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    [button setPeriodicDelay:delay interval:interval];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_button_get_periodic_delay(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;
  err = js_create_object(env, &result);
  assert(err == 0);

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    float delay;
    float interval;
    [button getPeriodicDelay:&delay interval:&interval];

    js_value_t *value;
    err = js_create_double(env, delay, &value);
    assert(err == 0);

    err = js_set_named_property(env, result, "delay", value);
    assert(err == 0);

    err = js_create_double(env, interval, &value);
    assert(err == 0);

    err = js_set_named_property(env, result, "interval", value);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_button_set_next_state(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    [button setNextState];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_button_highlight(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  bool flag;
  if (!bare_app_kit__read_bool(env, argv[1], "flag", &flag)) return NULL;

  @autoreleasepool {
    BareButton *button = (__bridge BareButton *) handle;

    [button highlight:flag];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_button_content_tint_color(js_env_t *env, js_callback_info_t *info) {
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
    NSButton *button = (__bridge NSButton *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, button.contentTintColor);
    } else {
      button.contentTintColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_bezel_color(js_env_t *env, js_callback_info_t *info) {
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
    NSButton *button = (__bridge NSButton *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, button.bezelColor);
    } else {
      button.bezelColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_attributed_title(js_env_t *env, js_callback_info_t *info) {
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
    NSButton *button = (__bridge NSButton *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, button.attributedTitle);
    } else {
      button.attributedTitle = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_image_position(js_env_t *env, js_callback_info_t *info) {
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
    NSButton *button = (__bridge NSButton *) handle;

    if (argc == 1) {
      err = js_create_int32(env, button.imagePosition, &result);
      assert(err == 0);
    } else {
      int32_t image_position;
      if (!bare_app_kit__read_int32(env, argv[1], "image_position", &image_position)) return NULL;

      button.imagePosition = image_position;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_button_image_scaling(js_env_t *env, js_callback_info_t *info) {
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
    NSButton *button = (__bridge NSButton *) handle;

    if (argc == 1) {
      err = js_create_int32(env, button.imageScaling, &result);
      assert(err == 0);
    } else {
      int32_t image_scaling;
      if (!bare_app_kit__read_int32(env, argv[1], "image_scaling", &image_scaling)) return NULL;

      button.imageScaling = image_scaling;
    }
  }

  return result;
}

static void
bare_app_kit_button_image_position_typed(js_value_t *receiver, int32_t bare_tag, int32_t image_position, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSButton *button = (NSButton *) bare_object;

    button.imagePosition = image_position;
  }
}

static void
bare_app_kit_button_image_scaling_typed(js_value_t *receiver, int32_t bare_tag, int32_t image_scaling, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSButton *button = (NSButton *) bare_object;

    button.imageScaling = image_scaling;
  }
}
