#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

#define V(name, method) \
  static js_value_t * \
  bare_app_kit_cell_##name(js_env_t *env, js_callback_info_t *info) { \
    int err; \
\
    size_t argc = 5; \
    js_value_t *argv[5]; \
\
    bare_foundation_registry_t *registry; \
    err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry); \
    assert(err == 0); \
\
    assert(argc == 5); \
\
    void *handle; \
    if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL; \
\
    double x; \
    err = js_get_value_double(env, argv[1], &x); \
    assert(err == 0); \
\
    double y; \
    err = js_get_value_double(env, argv[2], &y); \
    assert(err == 0); \
\
    double width; \
    err = js_get_value_double(env, argv[3], &width); \
    assert(err == 0); \
\
    double height; \
    err = js_get_value_double(env, argv[4], &height); \
    assert(err == 0); \
\
    js_value_t *result; \
\
    @autoreleasepool { \
      NSCell *cell = (__bridge NSCell *) handle; \
\
      result = bare_app_kit__from_rect(env, [cell method:NSMakeRect(x, y, width, height)]); \
    } \
\
    return result; \
  }

V(drawing_rect_for_bounds, drawingRectForBounds)
V(image_rect_for_bounds, imageRectForBounds)
V(title_rect_for_bounds, titleRectForBounds)
#undef V
