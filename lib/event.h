#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_event_type(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_int32(env, event.type, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_modifier_flags(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_int32(env, event.modifierFlags, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_timestamp(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_double(env, event.timestamp, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_window_number(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_int32(env, event.windowNumber, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_click_count(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_int32(env, event.clickCount, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_button_number(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_int32(env, event.buttonNumber, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_pressure(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_double(env, event.pressure, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_location_in_window(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    result = bare_app_kit__from_point(env, event.locationInWindow);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_location_in_window_into(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  uint32_t offset;
  if (!bare_app_kit__read_uint32(env, argv[2], "offset", &offset)) return NULL;

  double *out;

  if (!bare_app_kit__buffer(env, argv[1], offset, 2, &out)) {
    err = js_throw_type_error(env, NULL, "Expected an array buffer with room for 2 doubles");
    assert(err == 0);

    return NULL;
  }

  @autoreleasepool {
    NSEvent *event = (__bridge NSEvent *) handle;

    __typeof__(event.locationInWindow) value = event.locationInWindow;

    out[0] = value.x;
    out[1] = value.y;
  }

  return NULL;
}

static void
bare_app_kit_event_location_in_window_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSEvent *event = (NSEvent *) bare_object;

    __typeof__(event.locationInWindow) value = event.locationInWindow;

    out[0] = value.x;
    out[1] = value.y;
  }
}

static js_value_t *
bare_app_kit_event_delta_x(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_double(env, event.deltaX, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_delta_y(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_double(env, event.deltaY, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_scrolling_delta_x(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_double(env, event.scrollingDeltaX, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_scrolling_delta_y(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_double(env, event.scrollingDeltaY, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_magnification(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_double(env, event.magnification, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_characters(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    result = bare_app_kit__from_string(env, event.characters);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_characters_ignoring_modifiers(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    result = bare_app_kit__from_string(env, event.charactersIgnoringModifiers);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_key_code(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_create_int32(env, event.keyCode, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_repeat(js_env_t *env, js_callback_info_t *info) {
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
    NSEvent *event = (__bridge NSEvent *) handle;

    err = js_get_boolean(env, event.ARepeat, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_current(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSApp currentEvent]);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_current_modifier_flags(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    err = js_create_int32(env, (int32_t) [NSEvent modifierFlags], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_current_mouse_location(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    result = bare_app_kit__from_point(env, [NSEvent mouseLocation]);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_current_pressed_mouse_buttons(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    err = js_create_int32(env, (int32_t) [NSEvent pressedMouseButtons], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_event_double_click_interval(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    err = js_create_double(env, [NSEvent doubleClickInterval], &result);
    assert(err == 0);
  }

  return result;
}
