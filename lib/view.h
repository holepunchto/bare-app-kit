#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

// A plain `NSView` cannot report input and is not flipped, so the base view is
// a subclass. Both matter for anything laying out from the top left and
// handling its own events; the delivery mask keeps a view that listens to
// nothing as cheap as the plain one it replaces.
enum {
  bare_app_kit_view_event_mouse_down = 1 << 0,
  bare_app_kit_view_event_mouse_up = 1 << 1,
  bare_app_kit_view_event_mouse_dragged = 1 << 2,
  bare_app_kit_view_event_mouse_moved = 1 << 3,
  bare_app_kit_view_event_right_mouse_down = 1 << 4,
  bare_app_kit_view_event_right_mouse_up = 1 << 5,
  bare_app_kit_view_event_mouse_entered = 1 << 6,
  bare_app_kit_view_event_mouse_exited = 1 << 7,
  bare_app_kit_view_event_scroll_wheel = 1 << 8,
  bare_app_kit_view_event_key_down = 1 << 9,
  bare_app_kit_view_event_key_up = 1 << 10,
  bare_app_kit_view_event_flags_changed = 1 << 11,
  bare_app_kit_view_event_will_draw = 1 << 12,
};

@interface BareView : NSView <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;

  int32_t mask;
  bool flipped;
  bool accepts_first_responder;
  bool hit_testable;
}

@end

@implementation BareView

- (void)dealloc {
  int err;

  err = js_delete_reference(env, ctx);
  assert(err == 0);

  [super dealloc];
}

- (int32_t)eventMask {
  return mask;
}

- (void)setEventMask:(int32_t)value {
  mask = value;
}

- (BOOL)isFlipped {
  return flipped;
}

- (BOOL)acceptsFirstResponder {
  return accepts_first_responder;
}

// The one thing here that AppKit has no property for. A view is a hit target
// or it is not, which UIKit, GTK and WinUI each say with a property of their
// own, and AppKit says only by overriding this. Returning nil takes the
// subviews out of the hit with it, which is what not being a target means.
- (NSView *)hitTest:(NSPoint)point {
  if (!hit_testable) return nil;

  return [super hitTest:point];
}

- (void)viewWillDraw {
  [super viewWillDraw];

  if ((mask & bare_app_kit_view_event_will_draw) == 0) return;

  bare_app_kit__emit(env, ctx, "_onwilldraw");
}

- (void)bareEmit:(int32_t)type event:(NSEvent *)event a:(double)a b:(double)b {
  NSPoint point = [self convertPoint:event.locationInWindow fromView:nil];

  bare_app_kit__emit_event(env, ctx, "_onevent", type, point.x, point.y, a, b, (int32_t) event.modifierFlags, nil);
}

- (void)mouseDown:(NSEvent *)event {
  if ((mask & bare_app_kit_view_event_mouse_down) == 0) return [super mouseDown:event];

  [self bareEmit:bare_app_kit_view_event_mouse_down event:event a:event.buttonNumber b:event.clickCount];
}

- (void)mouseUp:(NSEvent *)event {
  if ((mask & bare_app_kit_view_event_mouse_up) == 0) return [super mouseUp:event];

  [self bareEmit:bare_app_kit_view_event_mouse_up event:event a:event.buttonNumber b:event.clickCount];
}

- (void)mouseDragged:(NSEvent *)event {
  if ((mask & bare_app_kit_view_event_mouse_dragged) == 0) return [super mouseDragged:event];

  [self bareEmit:bare_app_kit_view_event_mouse_dragged event:event a:event.buttonNumber b:event.clickCount];
}

- (void)mouseMoved:(NSEvent *)event {
  if ((mask & bare_app_kit_view_event_mouse_moved) == 0) return [super mouseMoved:event];

  [self bareEmit:bare_app_kit_view_event_mouse_moved event:event a:event.buttonNumber b:event.clickCount];
}

- (void)rightMouseDown:(NSEvent *)event {
  if ((mask & bare_app_kit_view_event_right_mouse_down) == 0) return [super rightMouseDown:event];

  [self bareEmit:bare_app_kit_view_event_right_mouse_down event:event a:event.buttonNumber b:event.clickCount];
}

- (void)rightMouseUp:(NSEvent *)event {
  if ((mask & bare_app_kit_view_event_right_mouse_up) == 0) return [super rightMouseUp:event];

  [self bareEmit:bare_app_kit_view_event_right_mouse_up event:event a:event.buttonNumber b:event.clickCount];
}

- (void)mouseEntered:(NSEvent *)event {
  if ((mask & bare_app_kit_view_event_mouse_entered) == 0) return [super mouseEntered:event];

  [self bareEmit:bare_app_kit_view_event_mouse_entered event:event a:event.buttonNumber b:event.clickCount];
}

- (void)mouseExited:(NSEvent *)event {
  if ((mask & bare_app_kit_view_event_mouse_exited) == 0) return [super mouseExited:event];

  [self bareEmit:bare_app_kit_view_event_mouse_exited event:event a:event.buttonNumber b:event.clickCount];
}

- (void)scrollWheel:(NSEvent *)event {
  if ((mask & bare_app_kit_view_event_scroll_wheel) == 0) return [super scrollWheel:event];

  [self bareEmit:bare_app_kit_view_event_scroll_wheel event:event a:event.scrollingDeltaX b:event.scrollingDeltaY];
}

- (void)keyDown:(NSEvent *)event {
  if ((mask & bare_app_kit_view_event_key_down) == 0) return [super keyDown:event];

  bare_app_kit__emit_event(env, ctx, "_onevent", bare_app_kit_view_event_key_down, 0, 0, event.keyCode, event.isARepeat ? 1 : 0, (int32_t) event.modifierFlags, event.characters);
}

- (void)keyUp:(NSEvent *)event {
  if ((mask & bare_app_kit_view_event_key_up) == 0) return [super keyUp:event];

  bare_app_kit__emit_event(env, ctx, "_onevent", bare_app_kit_view_event_key_up, 0, 0, event.keyCode, 0, (int32_t) event.modifierFlags, event.characters);
}

- (void)flagsChanged:(NSEvent *)event {
  if ((mask & bare_app_kit_view_event_flags_changed) == 0) return [super flagsChanged:event];

  bare_app_kit__emit_event(env, ctx, "_onevent", bare_app_kit_view_event_flags_changed, 0, 0, 0, 0, (int32_t) event.modifierFlags, nil);
}

@end

static js_value_t *
bare_app_kit_view_init(js_env_t *env, js_callback_info_t *info) {
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
    BareView *handle = [[[BareView alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;
    handle->hit_testable = true;

    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_frame(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_rect(env, view.frame);
    } else {
      double x;
      if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

      double y;
      if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

      double width;
      if (!bare_app_kit__read_double(env, argv[3], "width", &width)) return NULL;

      double height;
      if (!bare_app_kit__read_double(env, argv[4], "height", &height)) return NULL;

      view.frame = NSMakeRect(x, y, width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_bounds(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_rect(env, view.bounds);
    } else {
      double x;
      if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

      double y;
      if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

      double width;
      if (!bare_app_kit__read_double(env, argv[3], "width", &width)) return NULL;

      double height;
      if (!bare_app_kit__read_double(env, argv[4], "height", &height)) return NULL;

      view.bounds = NSMakeRect(x, y, width, height);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_hidden(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, view.hidden, &result);
      assert(err == 0);
    } else {
      bool hidden;
      if (!bare_app_kit__read_bool(env, argv[1], "hidden", &hidden)) return NULL;

      view.hidden = hidden;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_hidden_or_has_hidden_ancestor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    err = js_get_boolean(env, view.hiddenOrHasHiddenAncestor, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_alpha_value(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_create_double(env, view.alphaValue, &result);
      assert(err == 0);
    } else {
      double alpha_value;
      if (!bare_app_kit__read_double(env, argv[1], "alpha_value", &alpha_value)) return NULL;

      view.alphaValue = alpha_value;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_tool_tip(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, view.toolTip);
    } else {
      view.toolTip = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_autoresizing_mask(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, view.autoresizingMask, &result);
      assert(err == 0);
    } else {
      int32_t autoresizing_mask;
      if (!bare_app_kit__read_int32(env, argv[1], "autoresizing_mask", &autoresizing_mask)) return NULL;

      view.autoresizingMask = autoresizing_mask;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_autoresizes_subviews(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, view.autoresizesSubviews, &result);
      assert(err == 0);
    } else {
      bool autoresizes_subviews;
      if (!bare_app_kit__read_bool(env, argv[1], "autoresizes_subviews", &autoresizes_subviews)) return NULL;

      view.autoresizesSubviews = autoresizes_subviews;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_translates_autoresizing_mask_into_constraints(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, view.translatesAutoresizingMaskIntoConstraints, &result);
      assert(err == 0);
    } else {
      bool translates;
      if (!bare_app_kit__read_bool(env, argv[1], "translates", &translates)) return NULL;

      view.translatesAutoresizingMaskIntoConstraints = translates;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_wants_layer(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, view.wantsLayer, &result);
      assert(err == 0);
    } else {
      bool wants_layer;
      if (!bare_app_kit__read_bool(env, argv[1], "wants_layer", &wants_layer)) return NULL;

      view.wantsLayer = wants_layer;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_needs_display(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, view.needsDisplay, &result);
      assert(err == 0);
    } else {
      bool needs_display;
      if (!bare_app_kit__read_bool(env, argv[1], "needs_display", &needs_display)) return NULL;

      view.needsDisplay = needs_display;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_needs_layout(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, view.needsLayout, &result);
      assert(err == 0);
    } else {
      bool needs_layout;
      if (!bare_app_kit__read_bool(env, argv[1], "needs_layout", &needs_layout)) return NULL;

      view.needsLayout = needs_layout;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_fitting_size(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_app_kit__from_size(env, view.fittingSize);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_intrinsic_content_size(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_app_kit__from_size(env, view.intrinsicContentSize);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_superview(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.superview);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_subviews(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_app_kit__from_objects(env, view.subviews);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_add_subview(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2 || argc == 4);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  void *subview_handle;
  if (!bare_foundation__read_tag(env, argv[1], "subview_handle", &subview_handle)) return NULL;

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;
    NSView *subview = (__bridge NSView *) subview_handle;

    if (argc == 2) {
      [view addSubview:subview];
    } else {
      int32_t ordering;
      if (!bare_app_kit__read_int32(env, argv[2], "ordering", &ordering)) return NULL;

      js_value_type_t type;
      err = js_typeof(env, argv[3], &type);
      assert(err == 0);

      NSView *relative_to = nil;

      if (type == js_number) {
        void *relative_handle;
        if (!bare_foundation__read_tag(env, argv[3], "relative_handle", &relative_handle)) return NULL;

        relative_to = (__bridge NSView *) relative_handle;
      }

      [view addSubview:subview positioned:ordering relativeTo:relative_to];
    }
  }

  return NULL;
}

static js_value_t *
bare_app_kit_view_remove_from_superview(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;

    [view removeFromSuperview];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_view_display(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;

    [view display];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_view_layout(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;

    [view layoutSubtreeIfNeeded];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_view_menu(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, view.menu);
    } else {
      view.menu = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_top_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.topAnchor);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_bottom_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.bottomAnchor);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_leading_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.leadingAnchor);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_trailing_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.trailingAnchor);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_left_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.leftAnchor);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_right_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.rightAnchor);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_width_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.widthAnchor);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_height_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.heightAnchor);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_center_x_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.centerXAnchor);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_center_y_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.centerYAnchor);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_first_baseline_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.firstBaselineAnchor);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_last_baseline_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.lastBaselineAnchor);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_appearance(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, view.appearance);
    } else {
      view.appearance = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_effective_appearance(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.effectiveAppearance);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_needs_update_constraints(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, view.needsUpdateConstraints, &result);
      assert(err == 0);
    } else {
      bool needs_update_constraints;
      if (!bare_app_kit__read_bool(env, argv[1], "needs_update_constraints", &needs_update_constraints)) return NULL;

      view.needsUpdateConstraints = needs_update_constraints;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_undo_manager(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.undoManager);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_visible_rect(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_app_kit__from_rect(env, view.visibleRect);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_clips_to_bounds(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, view.clipsToBounds, &result);
      assert(err == 0);
    } else {
      bool clips_to_bounds;
      if (!bare_app_kit__read_bool(env, argv[1], "clips_to_bounds", &clips_to_bounds)) return NULL;

      view.clipsToBounds = clips_to_bounds;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_can_draw_subviews_into_layer(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, view.canDrawSubviewsIntoLayer, &result);
      assert(err == 0);
    } else {
      bool can_draw_subviews_into_layer;
      if (!bare_app_kit__read_bool(env, argv[1], "can_draw_subviews_into_layer", &can_draw_subviews_into_layer)) return NULL;

      view.canDrawSubviewsIntoLayer = can_draw_subviews_into_layer;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_layer_contents_redraw_policy(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, view.layerContentsRedrawPolicy, &result);
      assert(err == 0);
    } else {
      int32_t layer_contents_redraw_policy;
      if (!bare_app_kit__read_int32(env, argv[1], "layer_contents_redraw_policy", &layer_contents_redraw_policy)) return NULL;

      view.layerContentsRedrawPolicy = layer_contents_redraw_policy;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_focus_ring_type(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, view.focusRingType, &result);
      assert(err == 0);
    } else {
      int32_t focus_ring_type;
      if (!bare_app_kit__read_int32(env, argv[1], "focus_ring_type", &focus_ring_type)) return NULL;

      view.focusRingType = focus_ring_type;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_opaque(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    err = js_get_boolean(env, view.opaque, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_allows_vibrancy(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    err = js_get_boolean(env, view.allowsVibrancy, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_rotated_from_base(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    err = js_get_boolean(env, view.rotatedFromBase, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_flipped(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, view.flipped, &result);
      assert(err == 0);
    } else {
      // `isFlipped` is readonly on `NSView`; only the subclass can answer it.
      if (![view isKindOfClass:BareView.class]) {
        err = js_throw_type_error(env, NULL, "Only a View can change 'flipped'");
        assert(err == 0);

        return NULL;
      }

      bool flipped;
      if (!bare_app_kit__read_bool(env, argv[1], "flipped", &flipped)) return NULL;

      ((BareView *) view)->flipped = flipped;

      [view setNeedsDisplay:YES];
      [view.superview setNeedsLayout:YES];
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_accepts_first_responder(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, view.acceptsFirstResponder, &result);
      assert(err == 0);
    } else {
      if (![view isKindOfClass:BareView.class]) {
        err = js_throw_type_error(env, NULL, "Only a View can change 'acceptsFirstResponder'");
        assert(err == 0);

        return NULL;
      }

      bool accepts;
      if (!bare_app_kit__read_bool(env, argv[1], "accepts", &accepts)) return NULL;

      ((BareView *) view)->accepts_first_responder = accepts;
    }
  }

  return result;
}


static js_value_t *
bare_app_kit_view_hit_testable(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (![view isKindOfClass:BareView.class]) {
      err = js_throw_type_error(env, NULL, "Only a View has 'hitTestable'");
      assert(err == 0);

      return NULL;
    }

    if (argc == 1) {
      err = js_get_boolean(env, ((BareView *) view)->hit_testable, &result);
      assert(err == 0);
    } else {
      bool testable;
      if (!bare_app_kit__read_bool(env, argv[1], "testable", &testable)) return NULL;

      ((BareView *) view)->hit_testable = testable;
    }
  }

  return result;
}


static js_value_t *
bare_app_kit_view_in_live_resize(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    err = js_get_boolean(env, view.inLiveResize, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_can_become_key_view(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    err = js_get_boolean(env, view.canBecomeKeyView, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_user_interface_layout_direction(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      err = js_create_int32(env, view.userInterfaceLayoutDirection, &result);
      assert(err == 0);
    } else {
      int32_t user_interface_layout_direction;
      if (!bare_app_kit__read_int32(env, argv[1], "user_interface_layout_direction", &user_interface_layout_direction)) return NULL;

      view.userInterfaceLayoutDirection = user_interface_layout_direction;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_next_key_view(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    if (argc == 1) {
      result = bare_foundation__bridge(env, view.nextKeyView);
    } else {
      view.nextKeyView = bare_foundation__to_object(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_view_window(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.window);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_enclosing_scroll_view(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, view.enclosingScrollView);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_set_content_hugging_priority(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double priority;
  if (!bare_app_kit__read_double(env, argv[1], "priority", &priority)) return NULL;

  int32_t orientation;
  if (!bare_app_kit__read_int32(env, argv[2], "orientation", &orientation)) return NULL;

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;

    [view setContentHuggingPriority:priority forOrientation:orientation];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_view_set_content_compression_resistance_priority(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double priority;
  if (!bare_app_kit__read_double(env, argv[1], "priority", &priority)) return NULL;

  int32_t orientation;
  if (!bare_app_kit__read_int32(env, argv[2], "orientation", &orientation)) return NULL;

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;

    [view setContentCompressionResistancePriority:priority forOrientation:orientation];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_view_add_tracking_area(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id area = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;

    [view addTrackingArea:area];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_view_remove_tracking_area(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id area = bare_foundation__to_object(env, argv[1]);

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;

    [view removeTrackingArea:area];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_view_convert_point_from_view(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  id view = bare_foundation__to_object(env, argv[3]);

  js_value_t *result;

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;

    result = bare_app_kit__from_point(env, [view convertPoint:NSMakePoint(x, y) fromView:view]);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_convert_point_to_view(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  id view = bare_foundation__to_object(env, argv[3]);

  js_value_t *result;

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;

    result = bare_app_kit__from_point(env, [view convertPoint:NSMakePoint(x, y) toView:view]);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_hit_test(js_env_t *env, js_callback_info_t *info) {
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

  js_value_t *result;

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;

    result = bare_foundation__bridge(env, [view hitTest:NSMakePoint(x, y)]);
  }

  return result;
}

static js_value_t *
bare_app_kit_view_set_needs_display_in_rect(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 5);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double x;
  if (!bare_app_kit__read_double(env, argv[1], "x", &x)) return NULL;

  double y;
  if (!bare_app_kit__read_double(env, argv[2], "y", &y)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[3], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[4], "height", &height)) return NULL;

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;

    [view setNeedsDisplayInRect:NSMakeRect(x, y, width, height)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_view_scroll_point_to_visible(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    [view scrollPoint:NSMakePoint(x, y)];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_view_layout_subtree_if_needed(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSView *view = (__bridge NSView *) handle;

    [view layoutSubtreeIfNeeded];
  }

  return NULL;
}

static void
bare_app_kit_view_needs_update_constraints_typed(js_value_t *receiver, int32_t bare_tag, bool needs_update_constraints, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.needsUpdateConstraints = needs_update_constraints;
  }
}

static void
bare_app_kit_view_clips_to_bounds_typed(js_value_t *receiver, int32_t bare_tag, bool clips_to_bounds, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.clipsToBounds = clips_to_bounds;
  }
}

static void
bare_app_kit_view_can_draw_subviews_into_layer_typed(js_value_t *receiver, int32_t bare_tag, bool can_draw_subviews_into_layer, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.canDrawSubviewsIntoLayer = can_draw_subviews_into_layer;
  }
}

static void
bare_app_kit_view_layer_contents_redraw_policy_typed(js_value_t *receiver, int32_t bare_tag, int32_t layer_contents_redraw_policy, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.layerContentsRedrawPolicy = layer_contents_redraw_policy;
  }
}

static void
bare_app_kit_view_focus_ring_type_typed(js_value_t *receiver, int32_t bare_tag, int32_t focus_ring_type, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.focusRingType = focus_ring_type;
  }
}

static void
bare_app_kit_view_user_interface_layout_direction_typed(js_value_t *receiver, int32_t bare_tag, int32_t user_interface_layout_direction, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.userInterfaceLayoutDirection = user_interface_layout_direction;
  }
}

static void
bare_app_kit_view_frame_typed(js_value_t *receiver, int32_t bare_tag, double x, double y, double width, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.frame = NSMakeRect(x, y, width, height);
  }
}

static void
bare_app_kit_view_bounds_typed(js_value_t *receiver, int32_t bare_tag, double x, double y, double width, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.bounds = NSMakeRect(x, y, width, height);
  }
}

static void
bare_app_kit_view_hidden_typed(js_value_t *receiver, int32_t bare_tag, bool hidden, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.hidden = hidden;
  }
}

static void
bare_app_kit_view_alpha_value_typed(js_value_t *receiver, int32_t bare_tag, double alpha_value, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.alphaValue = alpha_value;
  }
}

static void
bare_app_kit_view_autoresizing_mask_typed(js_value_t *receiver, int32_t bare_tag, int32_t autoresizing_mask, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.autoresizingMask = autoresizing_mask;
  }
}

static void
bare_app_kit_view_autoresizes_subviews_typed(js_value_t *receiver, int32_t bare_tag, bool autoresizes_subviews, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.autoresizesSubviews = autoresizes_subviews;
  }
}

static void
bare_app_kit_view_translates_autoresizing_mask_into_constraints_typed(js_value_t *receiver, int32_t bare_tag, bool translates_autoresizing_mask_into_constraints, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.translatesAutoresizingMaskIntoConstraints = translates_autoresizing_mask_into_constraints;
  }
}

static void
bare_app_kit_view_wants_layer_typed(js_value_t *receiver, int32_t bare_tag, bool wants_layer, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.wantsLayer = wants_layer;
  }
}

static void
bare_app_kit_view_needs_display_typed(js_value_t *receiver, int32_t bare_tag, bool needs_display, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.needsDisplay = needs_display;
  }
}

static void
bare_app_kit_view_needs_layout_typed(js_value_t *receiver, int32_t bare_tag, bool needs_layout, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    view.needsLayout = needs_layout;
  }
}

static js_value_t *
bare_app_kit_view_visible_rect_into(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    __typeof__(view.visibleRect) value = view.visibleRect;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }

  return NULL;
}

static void
bare_app_kit_view_visible_rect_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    __typeof__(view.visibleRect) value = view.visibleRect;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }
}

static js_value_t *
bare_app_kit_view_frame_into(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    __typeof__(view.frame) value = view.frame;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }

  return NULL;
}

static void
bare_app_kit_view_frame_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    __typeof__(view.frame) value = view.frame;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }
}

static js_value_t *
bare_app_kit_view_bounds_into(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    __typeof__(view.bounds) value = view.bounds;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }

  return NULL;
}

static void
bare_app_kit_view_bounds_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    __typeof__(view.bounds) value = view.bounds;

    out[0] = value.origin.x;
    out[1] = value.origin.y;
    out[2] = value.size.width;
    out[3] = value.size.height;
  }
}

static js_value_t *
bare_app_kit_view_safe_area_insets_into(js_env_t *env, js_callback_info_t *info) {
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
    NSView *view = (__bridge NSView *) handle;

    NSEdgeInsets value = view.safeAreaInsets;

    out[0] = value.top;
    out[1] = value.left;
    out[2] = value.bottom;
    out[3] = value.right;
  }

  return NULL;
}

static void
bare_app_kit_view_safe_area_insets_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSView *view = (NSView *) bare_object;

    NSEdgeInsets value = view.safeAreaInsets;

    out[0] = value.top;
    out[1] = value.left;
    out[2] = value.bottom;
    out[3] = value.right;
  }
}
