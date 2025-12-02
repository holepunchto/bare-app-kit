#import <assert.h>
#import <bare.h>
#import <js.h>
#import <utf.h>

#import <AppKit/AppKit.h>

#import "lib/window.h"

static js_value_t *
bare_app_kit_exports(js_env_t *env, js_value_t *exports) {
  int err;

#define V(name, fn) \
  { \
    js_value_t *val; \
    err = js_create_function(env, name, -1, fn, NULL, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, exports, name, val); \
    assert(err == 0); \
  }

  V("windowInit", bare_app_kit_window_init)
  V("windowContentView", bare_app_kit_window_content_view)
  V("windowTitlebarAppearsTransparent", bare_app_kit_window_titlebar_appears_transparent)
  V("windowCenter", bare_app_kit_window_center)
  V("windowClose", bare_app_kit_window_close)
  V("windowMakeKeyWindow", bare_app_kit_window_make_key_window)
  V("windowOrderBack", bare_app_kit_window_order_back)
  V("windowOrderFront", bare_app_kit_window_order_front)
#undef V

#define V(name, n) \
  { \
    js_value_t *val; \
    err = js_create_int32(env, n, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, exports, name, val); \
    assert(err == 0); \
  }

  V("WINDOW_STYLE_MASK_BORDERLESS", NSWindowStyleMaskBorderless)
  V("WINDOW_STYLE_MASK_TITLED", NSWindowStyleMaskTitled)
  V("WINDOW_STYLE_MASK_CLOSABLE", NSWindowStyleMaskClosable)
  V("WINDOW_STYLE_MASK_MINIATURIZABLE", NSWindowStyleMaskMiniaturizable)
  V("WINDOW_STYLE_MASK_RESIZABLE", NSWindowStyleMaskResizable)
  V("WINDOW_STYLE_MASK_FULL_SCREEN", NSWindowStyleMaskFullScreen)
  V("WINDOW_STYLE_MASK_FULL_SIZE_CONTENT_VIEW", NSWindowStyleMaskFullSizeContentView)
#undef V

  return exports;
}

BARE_MODULE(bare_app_kit, bare_app_kit_exports)
