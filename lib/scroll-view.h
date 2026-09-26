#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_scroll_view_init(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *handle = [[[NSScrollView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_scroll_view_content_view(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, scroll_view.contentView);
    } else {
      scroll_view.contentView = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

// A clip view that was scrolled directly has not told the scroll view, which
// is what this is for and what AppKit says to call after `scrollToPoint:`.
static js_value_t *
bare_app_kit_scroll_view_reflect_scrolled_clip_view(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  void *clip;
  if (!bare_foundation__read_tag(env, argv[1], "clipView", &clip)) return NULL;

  @autoreleasepool {
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    [scroll_view reflectScrolledClipView:(__bridge NSClipView *) clip];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_scroll_view_document_view(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, scroll_view.documentView);
    } else {
      scroll_view.documentView = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_scroll_view_has_vertical_scroller(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, scroll_view.hasVerticalScroller, &result);
      assert(err == 0);
    } else {
      bool has_vertical_scroller;
      if (!bare_app_kit__read_bool(env, argv[1], "has_vertical_scroller", &has_vertical_scroller)) return NULL;

      scroll_view.hasVerticalScroller = has_vertical_scroller;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_has_vertical_scroller_typed(js_value_t *receiver, int32_t bare_tag, bool has_vertical_scroller, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.hasVerticalScroller = has_vertical_scroller;
  }
}

static js_value_t *
bare_app_kit_scroll_view_has_horizontal_scroller(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, scroll_view.hasHorizontalScroller, &result);
      assert(err == 0);
    } else {
      bool has_horizontal_scroller;
      if (!bare_app_kit__read_bool(env, argv[1], "has_horizontal_scroller", &has_horizontal_scroller)) return NULL;

      scroll_view.hasHorizontalScroller = has_horizontal_scroller;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_has_horizontal_scroller_typed(js_value_t *receiver, int32_t bare_tag, bool has_horizontal_scroller, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.hasHorizontalScroller = has_horizontal_scroller;
  }
}

static js_value_t *
bare_app_kit_scroll_view_autohides_scrollers(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, scroll_view.autohidesScrollers, &result);
      assert(err == 0);
    } else {
      bool autohides_scrollers;
      if (!bare_app_kit__read_bool(env, argv[1], "autohides_scrollers", &autohides_scrollers)) return NULL;

      scroll_view.autohidesScrollers = autohides_scrollers;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_autohides_scrollers_typed(js_value_t *receiver, int32_t bare_tag, bool autohides_scrollers, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.autohidesScrollers = autohides_scrollers;
  }
}

static js_value_t *
bare_app_kit_scroll_view_border_type(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, scroll_view.borderType, &result);
      assert(err == 0);
    } else {
      int32_t border_type;
      if (!bare_app_kit__read_int32(env, argv[1], "border_type", &border_type)) return NULL;

      scroll_view.borderType = border_type;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_border_type_typed(js_value_t *receiver, int32_t bare_tag, int32_t border_type, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.borderType = border_type;
  }
}

static js_value_t *
bare_app_kit_scroll_view_scroller_style(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, scroll_view.scrollerStyle, &result);
      assert(err == 0);
    } else {
      int32_t scroller_style;
      if (!bare_app_kit__read_int32(env, argv[1], "scroller_style", &scroller_style)) return NULL;

      scroll_view.scrollerStyle = scroller_style;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_scroller_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t scroller_style, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.scrollerStyle = scroller_style;
  }
}

static js_value_t *
bare_app_kit_scroll_view_draws_background(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, scroll_view.drawsBackground, &result);
      assert(err == 0);
    } else {
      bool draws_background;
      if (!bare_app_kit__read_bool(env, argv[1], "draws_background", &draws_background)) return NULL;

      scroll_view.drawsBackground = draws_background;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_draws_background_typed(js_value_t *receiver, int32_t bare_tag, bool draws_background, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.drawsBackground = draws_background;
  }
}

static js_value_t *
bare_app_kit_scroll_view_background_color(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, scroll_view.backgroundColor);
    } else {
      scroll_view.backgroundColor = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_scroll_view_allows_magnification(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, scroll_view.allowsMagnification, &result);
      assert(err == 0);
    } else {
      bool allows_magnification;
      if (!bare_app_kit__read_bool(env, argv[1], "allows_magnification", &allows_magnification)) return NULL;

      scroll_view.allowsMagnification = allows_magnification;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_allows_magnification_typed(js_value_t *receiver, int32_t bare_tag, bool allows_magnification, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.allowsMagnification = allows_magnification;
  }
}

static js_value_t *
bare_app_kit_scroll_view_magnification(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_double(env, scroll_view.magnification, &result);
      assert(err == 0);
    } else {
      double magnification;
      if (!bare_app_kit__read_double(env, argv[1], "magnification", &magnification)) return NULL;

      scroll_view.magnification = magnification;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_magnification_typed(js_value_t *receiver, int32_t bare_tag, double magnification, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.magnification = magnification;
  }
}

static js_value_t *
bare_app_kit_scroll_view_horizontal_scroll_elasticity(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, scroll_view.horizontalScrollElasticity, &result);
      assert(err == 0);
    } else {
      int32_t horizontal_scroll_elasticity;
      if (!bare_app_kit__read_int32(env, argv[1], "horizontal_scroll_elasticity", &horizontal_scroll_elasticity)) return NULL;

      scroll_view.horizontalScrollElasticity = horizontal_scroll_elasticity;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_horizontal_scroll_elasticity_typed(js_value_t *receiver, int32_t bare_tag, int32_t horizontal_scroll_elasticity, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.horizontalScrollElasticity = horizontal_scroll_elasticity;
  }
}

static js_value_t *
bare_app_kit_scroll_view_vertical_scroll_elasticity(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, scroll_view.verticalScrollElasticity, &result);
      assert(err == 0);
    } else {
      int32_t vertical_scroll_elasticity;
      if (!bare_app_kit__read_int32(env, argv[1], "vertical_scroll_elasticity", &vertical_scroll_elasticity)) return NULL;

      scroll_view.verticalScrollElasticity = vertical_scroll_elasticity;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_vertical_scroll_elasticity_typed(js_value_t *receiver, int32_t bare_tag, int32_t vertical_scroll_elasticity, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.verticalScrollElasticity = vertical_scroll_elasticity;
  }
}

static js_value_t *
bare_app_kit_scroll_view_content_size(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    result = bare_app_kit__from_size(env, scroll_view.contentSize);
  }

  return result;
}

static js_value_t *
bare_app_kit_scroll_view_content_size_into(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    __typeof__(scroll_view.contentSize) value = scroll_view.contentSize;

    out[0] = value.width;
    out[1] = value.height;
  }

  return NULL;
}

static void
bare_app_kit_scroll_view_content_size_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    __typeof__(scroll_view.contentSize) value = scroll_view.contentSize;

    out[0] = value.width;
    out[1] = value.height;
  }
}

static js_value_t *
bare_app_kit_scroll_view_document_visible_rect(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    result = bare_app_kit__from_rect(env, scroll_view.documentVisibleRect);
  }

  return result;
}

static js_value_t *
bare_app_kit_scroll_view_document_visible_rect_into(js_env_t *env, js_callback_info_t *info) {
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

  if (!bare_app_kit__buffer(env, argv[1], offset, 4, &out)) {
    err = js_throw_type_error(env, NULL, "Expected an array buffer with room for 4 doubles");
    assert(err == 0);

    return NULL;
  }

  @autoreleasepool {
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    __typeof__(scroll_view.documentVisibleRect) value = scroll_view.documentVisibleRect;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }

  return NULL;
}

static void
bare_app_kit_scroll_view_document_visible_rect_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    __typeof__(scroll_view.documentVisibleRect) value = scroll_view.documentVisibleRect;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }
}

static js_value_t *
bare_app_kit_scroll_view_rulers_visible(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, scroll_view.rulersVisible, &result);
      assert(err == 0);
    } else {
      bool rulers_visible;
      if (!bare_app_kit__read_bool(env, argv[1], "rulers_visible", &rulers_visible)) return NULL;

      scroll_view.rulersVisible = rulers_visible;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_rulers_visible_typed(js_value_t *receiver, int32_t bare_tag, bool rulers_visible, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.rulersVisible = rulers_visible;
  }
}

static js_value_t *
bare_app_kit_scroll_view_has_horizontal_ruler(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, scroll_view.hasHorizontalRuler, &result);
      assert(err == 0);
    } else {
      bool has_horizontal_ruler;
      if (!bare_app_kit__read_bool(env, argv[1], "has_horizontal_ruler", &has_horizontal_ruler)) return NULL;

      scroll_view.hasHorizontalRuler = has_horizontal_ruler;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_has_horizontal_ruler_typed(js_value_t *receiver, int32_t bare_tag, bool has_horizontal_ruler, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.hasHorizontalRuler = has_horizontal_ruler;
  }
}

static js_value_t *
bare_app_kit_scroll_view_has_vertical_ruler(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, scroll_view.hasVerticalRuler, &result);
      assert(err == 0);
    } else {
      bool has_vertical_ruler;
      if (!bare_app_kit__read_bool(env, argv[1], "has_vertical_ruler", &has_vertical_ruler)) return NULL;

      scroll_view.hasVerticalRuler = has_vertical_ruler;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_has_vertical_ruler_typed(js_value_t *receiver, int32_t bare_tag, bool has_vertical_ruler, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.hasVerticalRuler = has_vertical_ruler;
  }
}

static js_value_t *
bare_app_kit_scroll_view_scrolls_dynamically(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, scroll_view.scrollsDynamically, &result);
      assert(err == 0);
    } else {
      bool scrolls_dynamically;
      if (!bare_app_kit__read_bool(env, argv[1], "scrolls_dynamically", &scrolls_dynamically)) return NULL;

      scroll_view.scrollsDynamically = scrolls_dynamically;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_scrolls_dynamically_typed(js_value_t *receiver, int32_t bare_tag, bool scrolls_dynamically, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.scrollsDynamically = scrolls_dynamically;
  }
}

static js_value_t *
bare_app_kit_scroll_view_line_scroll(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_double(env, scroll_view.lineScroll, &result);
      assert(err == 0);
    } else {
      double line_scroll;
      if (!bare_app_kit__read_double(env, argv[1], "line_scroll", &line_scroll)) return NULL;

      scroll_view.lineScroll = line_scroll;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_line_scroll_typed(js_value_t *receiver, int32_t bare_tag, double line_scroll, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.lineScroll = line_scroll;
  }
}

static js_value_t *
bare_app_kit_scroll_view_page_scroll(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_double(env, scroll_view.pageScroll, &result);
      assert(err == 0);
    } else {
      double page_scroll;
      if (!bare_app_kit__read_double(env, argv[1], "page_scroll", &page_scroll)) return NULL;

      scroll_view.pageScroll = page_scroll;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_page_scroll_typed(js_value_t *receiver, int32_t bare_tag, double page_scroll, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.pageScroll = page_scroll;
  }
}

static js_value_t *
bare_app_kit_scroll_view_horizontal_line_scroll(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_double(env, scroll_view.horizontalLineScroll, &result);
      assert(err == 0);
    } else {
      double horizontal_line_scroll;
      if (!bare_app_kit__read_double(env, argv[1], "horizontal_line_scroll", &horizontal_line_scroll)) return NULL;

      scroll_view.horizontalLineScroll = horizontal_line_scroll;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_horizontal_line_scroll_typed(js_value_t *receiver, int32_t bare_tag, double horizontal_line_scroll, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.horizontalLineScroll = horizontal_line_scroll;
  }
}

static js_value_t *
bare_app_kit_scroll_view_vertical_line_scroll(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_double(env, scroll_view.verticalLineScroll, &result);
      assert(err == 0);
    } else {
      double vertical_line_scroll;
      if (!bare_app_kit__read_double(env, argv[1], "vertical_line_scroll", &vertical_line_scroll)) return NULL;

      scroll_view.verticalLineScroll = vertical_line_scroll;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_vertical_line_scroll_typed(js_value_t *receiver, int32_t bare_tag, double vertical_line_scroll, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.verticalLineScroll = vertical_line_scroll;
  }
}

static js_value_t *
bare_app_kit_scroll_view_horizontal_page_scroll(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_double(env, scroll_view.horizontalPageScroll, &result);
      assert(err == 0);
    } else {
      double horizontal_page_scroll;
      if (!bare_app_kit__read_double(env, argv[1], "horizontal_page_scroll", &horizontal_page_scroll)) return NULL;

      scroll_view.horizontalPageScroll = horizontal_page_scroll;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_horizontal_page_scroll_typed(js_value_t *receiver, int32_t bare_tag, double horizontal_page_scroll, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.horizontalPageScroll = horizontal_page_scroll;
  }
}

static js_value_t *
bare_app_kit_scroll_view_vertical_page_scroll(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_double(env, scroll_view.verticalPageScroll, &result);
      assert(err == 0);
    } else {
      double vertical_page_scroll;
      if (!bare_app_kit__read_double(env, argv[1], "vertical_page_scroll", &vertical_page_scroll)) return NULL;

      scroll_view.verticalPageScroll = vertical_page_scroll;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_vertical_page_scroll_typed(js_value_t *receiver, int32_t bare_tag, double vertical_page_scroll, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.verticalPageScroll = vertical_page_scroll;
  }
}

static js_value_t *
bare_app_kit_scroll_view_automatically_adjusts_content_insets(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, scroll_view.automaticallyAdjustsContentInsets, &result);
      assert(err == 0);
    } else {
      bool automatically_adjusts_content_insets;
      if (!bare_app_kit__read_bool(env, argv[1], "automatically_adjusts_content_insets", &automatically_adjusts_content_insets)) return NULL;

      scroll_view.automaticallyAdjustsContentInsets = automatically_adjusts_content_insets;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_automatically_adjusts_content_insets_typed(js_value_t *receiver, int32_t bare_tag, bool automatically_adjusts_content_insets, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.automaticallyAdjustsContentInsets = automatically_adjusts_content_insets;
  }
}

static js_value_t *
bare_app_kit_scroll_view_content_insets(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 5);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_insets(env, scroll_view.contentInsets);
    } else {
      double top;
      err = js_get_value_double(env, argv[1], &top);
      assert(err == 0);

      double left;
      err = js_get_value_double(env, argv[2], &left);
      assert(err == 0);

      double bottom;
      err = js_get_value_double(env, argv[3], &bottom);
      assert(err == 0);

      double right;
      err = js_get_value_double(env, argv[4], &right);
      assert(err == 0);

      scroll_view.contentInsets = NSEdgeInsetsMake(top, left, bottom, right);
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_content_insets_typed(js_value_t *receiver, int32_t bare_tag, double top, double left, double bottom, double right, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.contentInsets = NSEdgeInsetsMake(top, left, bottom, right);
  }
}

static js_value_t *
bare_app_kit_scroll_view_content_insets_into(js_env_t *env, js_callback_info_t *info) {
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

  if (!bare_app_kit__buffer(env, argv[1], offset, 4, &out)) {
    err = js_throw_type_error(env, NULL, "Expected an array buffer with room for 4 doubles");
    assert(err == 0);

    return NULL;
  }

  @autoreleasepool {
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    __typeof__(scroll_view.contentInsets) value = scroll_view.contentInsets;

    out[0] = value.top;
    out[1] = value.left;
    out[2] = value.bottom;
    out[3] = value.right;
  }

  return NULL;
}

static void
bare_app_kit_scroll_view_content_insets_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    __typeof__(scroll_view.contentInsets) value = scroll_view.contentInsets;

    out[0] = value.top;
    out[1] = value.left;
    out[2] = value.bottom;
    out[3] = value.right;
  }
}

static js_value_t *
bare_app_kit_scroll_view_scroller_insets(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 5);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_insets(env, scroll_view.scrollerInsets);
    } else {
      double top;
      err = js_get_value_double(env, argv[1], &top);
      assert(err == 0);

      double left;
      err = js_get_value_double(env, argv[2], &left);
      assert(err == 0);

      double bottom;
      err = js_get_value_double(env, argv[3], &bottom);
      assert(err == 0);

      double right;
      err = js_get_value_double(env, argv[4], &right);
      assert(err == 0);

      scroll_view.scrollerInsets = NSEdgeInsetsMake(top, left, bottom, right);
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_scroller_insets_typed(js_value_t *receiver, int32_t bare_tag, double top, double left, double bottom, double right, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.scrollerInsets = NSEdgeInsetsMake(top, left, bottom, right);
  }
}

static js_value_t *
bare_app_kit_scroll_view_scroller_insets_into(js_env_t *env, js_callback_info_t *info) {
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

  if (!bare_app_kit__buffer(env, argv[1], offset, 4, &out)) {
    err = js_throw_type_error(env, NULL, "Expected an array buffer with room for 4 doubles");
    assert(err == 0);

    return NULL;
  }

  @autoreleasepool {
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    __typeof__(scroll_view.scrollerInsets) value = scroll_view.scrollerInsets;

    out[0] = value.top;
    out[1] = value.left;
    out[2] = value.bottom;
    out[3] = value.right;
  }

  return NULL;
}

static void
bare_app_kit_scroll_view_scroller_insets_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    __typeof__(scroll_view.scrollerInsets) value = scroll_view.scrollerInsets;

    out[0] = value.top;
    out[1] = value.left;
    out[2] = value.bottom;
    out[3] = value.right;
  }
}

static js_value_t *
bare_app_kit_scroll_view_find_bar_position(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, scroll_view.findBarPosition, &result);
      assert(err == 0);
    } else {
      int32_t find_bar_position;
      if (!bare_app_kit__read_int32(env, argv[1], "find_bar_position", &find_bar_position)) return NULL;

      scroll_view.findBarPosition = find_bar_position;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_find_bar_position_typed(js_value_t *receiver, int32_t bare_tag, int32_t find_bar_position, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.findBarPosition = find_bar_position;
  }
}

static js_value_t *
bare_app_kit_scroll_view_min_magnification(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_double(env, scroll_view.minMagnification, &result);
      assert(err == 0);
    } else {
      double min_magnification;
      if (!bare_app_kit__read_double(env, argv[1], "min_magnification", &min_magnification)) return NULL;

      scroll_view.minMagnification = min_magnification;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_min_magnification_typed(js_value_t *receiver, int32_t bare_tag, double min_magnification, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.minMagnification = min_magnification;
  }
}

static js_value_t *
bare_app_kit_scroll_view_max_magnification(js_env_t *env, js_callback_info_t *info) {
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
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    if (argc == 1) {
      err = js_create_double(env, scroll_view.maxMagnification, &result);
      assert(err == 0);
    } else {
      double max_magnification;
      if (!bare_app_kit__read_double(env, argv[1], "max_magnification", &max_magnification)) return NULL;

      scroll_view.maxMagnification = max_magnification;
    }
  }

  return result;
}

static void
bare_app_kit_scroll_view_max_magnification_typed(js_value_t *receiver, int32_t bare_tag, double max_magnification, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSScrollView *scroll_view = (NSScrollView *) bare_object;

    scroll_view.maxMagnification = max_magnification;
  }
}

static js_value_t *
bare_app_kit_scroll_view_flash_scrollers(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSScrollView *scroll_view = (__bridge NSScrollView *) handle;

    [scroll_view flashScrollers];
  }

  return NULL;
}
