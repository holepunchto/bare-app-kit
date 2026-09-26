#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

#define BARE_APP_KIT_CURSORS(V) \
  V(ARROW, arrowCursor) \
  V(IBEAM, IBeamCursor) \
  V(IBEAM_VERTICAL, IBeamCursorForVerticalLayout) \
  V(CROSSHAIR, crosshairCursor) \
  V(POINTING_HAND, pointingHandCursor) \
  V(CLOSED_HAND, closedHandCursor) \
  V(OPEN_HAND, openHandCursor) \
  V(RESIZE_LEFT, resizeLeftCursor) \
  V(RESIZE_RIGHT, resizeRightCursor) \
  V(RESIZE_LEFT_RIGHT, resizeLeftRightCursor) \
  V(RESIZE_UP, resizeUpCursor) \
  V(RESIZE_DOWN, resizeDownCursor) \
  V(RESIZE_UP_DOWN, resizeUpDownCursor) \
  V(DISAPPEARING_ITEM, disappearingItemCursor) \
  V(OPERATION_NOT_ALLOWED, operationNotAllowedCursor) \
  V(DRAG_LINK, dragLinkCursor) \
  V(DRAG_COPY, dragCopyCursor) \
  V(CONTEXTUAL_MENU, contextualMenuCursor) \
  V(CURRENT, currentCursor)

enum {
#define V(name, selector) bare_app_kit_cursor_##name,
  BARE_APP_KIT_CURSORS(V)
#undef V
};

static NSCursor *
bare_app_kit__cursor(int32_t id) {
  switch (id) {
#define V(name, selector) \
  case bare_app_kit_cursor_##name: \
    return [NSCursor selector];
    BARE_APP_KIT_CURSORS(V)
#undef V
  }

  return nil;
}

static js_value_t *
bare_app_kit_cursor_image(js_env_t *env, js_callback_info_t *info) {
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
    NSCursor *cursor = (__bridge NSCursor *) handle;

    result = bare_foundation__bridge(env, cursor.image);
  }

  return result;
}

static js_value_t *
bare_app_kit_cursor_hot_spot(js_env_t *env, js_callback_info_t *info) {
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
    NSCursor *cursor = (__bridge NSCursor *) handle;

    result = bare_app_kit__from_point(env, cursor.hotSpot);
  }

  return result;
}

static js_value_t *
bare_app_kit_cursor_system(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  int32_t id;
  if (!bare_app_kit__read_int32(env, argv[0], "id", &id)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, bare_app_kit__cursor(id));
  }

  return result;
}

static js_value_t *
bare_app_kit_cursor_hide(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  @autoreleasepool {
    [NSCursor hide];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_cursor_unhide(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  @autoreleasepool {
    [NSCursor unhide];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_cursor_pop(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  @autoreleasepool {
    [NSCursor pop];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_cursor_set(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSCursor *cursor = (__bridge NSCursor *) handle;

    [cursor set];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_cursor_push(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSCursor *cursor = (__bridge NSCursor *) handle;

    [cursor push];
  }

  return NULL;
}
