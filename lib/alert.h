#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

enum {
  bare_app_kit_alert_event_response = 1 << 0,
};


@interface BareAlert : NSAlert <BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareAlert

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

- (void)onResponse:(NSModalResponse)response {
  if ((mask & bare_app_kit_alert_event_response) == 0) return;

  bare_app_kit__emit_int32(env, ctx, "_onresponse", (int32_t) response);
}

@end

static js_value_t *
bare_app_kit_alert_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1);

  js_value_t *result;

  @autoreleasepool {
    BareAlert *handle = [[[BareAlert alloc] init] autorelease];

    result = bare_foundation_bridge(env, registry, handle);

    handle->env = env;

    // Weak, so the native object does not keep its own wrapper alive. Events
    // are dropped once the wrapper is collected.
    err = js_create_reference(env, argv[0], 0, &handle->ctx);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_alert_message_text(js_env_t *env, js_callback_info_t *info) {
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
    NSAlert *alert = (__bridge NSAlert *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, alert.messageText);
    } else {
      alert.messageText = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_alert_informative_text(js_env_t *env, js_callback_info_t *info) {
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
    NSAlert *alert = (__bridge NSAlert *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, alert.informativeText);
    } else {
      alert.informativeText = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_alert_alert_style(js_env_t *env, js_callback_info_t *info) {
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
    NSAlert *alert = (__bridge NSAlert *) handle;

    if (argc == 1) {
      err = js_create_int32(env, alert.alertStyle, &result);
      assert(err == 0);
    } else {
      int32_t alert_style;
      if (!bare_app_kit__read_int32(env, argv[1], "alert_style", &alert_style)) return NULL;

      alert.alertStyle = alert_style;
    }
  }

  return result;
}

static void
bare_app_kit_alert_alert_style_typed(js_value_t *receiver, int32_t bare_tag, int32_t alert_style, js_typed_callback_info_t *info) {
  int err;

  bare_foundation_registry_t *registry;
  err = js_get_typed_callback_info(info, NULL, (void **) &registry);
  assert(err == 0);

  id bare_object = bare_foundation_object(registry, bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSAlert *alert = (NSAlert *) bare_object;

    alert.alertStyle = alert_style;
  }
}

static js_value_t *
bare_app_kit_alert_shows_help(js_env_t *env, js_callback_info_t *info) {
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
    NSAlert *alert = (__bridge NSAlert *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, alert.showsHelp, &result);
      assert(err == 0);
    } else {
      bool shows_help;
      if (!bare_app_kit__read_bool(env, argv[1], "shows_help", &shows_help)) return NULL;

      alert.showsHelp = shows_help;
    }
  }

  return result;
}

static void
bare_app_kit_alert_shows_help_typed(js_value_t *receiver, int32_t bare_tag, bool shows_help, js_typed_callback_info_t *info) {
  int err;

  bare_foundation_registry_t *registry;
  err = js_get_typed_callback_info(info, NULL, (void **) &registry);
  assert(err == 0);

  id bare_object = bare_foundation_object(registry, bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSAlert *alert = (NSAlert *) bare_object;

    alert.showsHelp = shows_help;
  }
}

static js_value_t *
bare_app_kit_alert_shows_suppression_button(js_env_t *env, js_callback_info_t *info) {
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
    NSAlert *alert = (__bridge NSAlert *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, alert.showsSuppressionButton, &result);
      assert(err == 0);
    } else {
      bool shows_suppression_button;
      if (!bare_app_kit__read_bool(env, argv[1], "shows_suppression_button", &shows_suppression_button)) return NULL;

      alert.showsSuppressionButton = shows_suppression_button;
    }
  }

  return result;
}

static void
bare_app_kit_alert_shows_suppression_button_typed(js_value_t *receiver, int32_t bare_tag, bool shows_suppression_button, js_typed_callback_info_t *info) {
  int err;

  bare_foundation_registry_t *registry;
  err = js_get_typed_callback_info(info, NULL, (void **) &registry);
  assert(err == 0);

  id bare_object = bare_foundation_object(registry, bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSAlert *alert = (NSAlert *) bare_object;

    alert.showsSuppressionButton = shows_suppression_button;
  }
}

static js_value_t *
bare_app_kit_alert_help_anchor(js_env_t *env, js_callback_info_t *info) {
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
    NSAlert *alert = (__bridge NSAlert *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, alert.helpAnchor);
    } else {
      alert.helpAnchor = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_alert_icon(js_env_t *env, js_callback_info_t *info) {
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
    NSAlert *alert = (__bridge NSAlert *) handle;

    if (argc == 1) {
      result = bare_foundation_bridge(env, registry, alert.icon);
    } else {
      alert.icon = bare_foundation_to_object(env, registry, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_alert_accessory_view(js_env_t *env, js_callback_info_t *info) {
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
    NSAlert *alert = (__bridge NSAlert *) handle;

    if (argc == 1) {
      result = bare_foundation_bridge(env, registry, alert.accessoryView);
    } else {
      alert.accessoryView = bare_foundation_to_object(env, registry, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_alert_suppression_button(js_env_t *env, js_callback_info_t *info) {
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
    NSAlert *alert = (__bridge NSAlert *) handle;

    result = bare_foundation_bridge(env, registry, alert.suppressionButton);
  }

  return result;
}

static js_value_t *
bare_app_kit_alert_window(js_env_t *env, js_callback_info_t *info) {
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
    NSAlert *alert = (__bridge NSAlert *) handle;

    result = bare_foundation_bridge(env, registry, alert.window);
  }

  return result;
}

static js_value_t *
bare_app_kit_alert_add_button_with_title(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  NSString *title = bare_app_kit__to_string(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    NSAlert *alert = (__bridge NSAlert *) handle;

    result = bare_foundation_bridge(env, registry, [alert addButtonWithTitle:title]);
  }

  return result;
}

static js_value_t *
bare_app_kit_alert_run_modal(js_env_t *env, js_callback_info_t *info) {
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
    NSAlert *alert = (__bridge NSAlert *) handle;

    err = js_create_int32(env, [alert runModal], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_alert_begin_sheet_modal(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  id parent = bare_foundation_to_object(env, registry, argv[1]);

  @autoreleasepool {
    BareAlert *alert = (__bridge BareAlert *) handle;

    [alert beginSheetModalForWindow:parent completionHandler:^(NSModalResponse response) { [alert onResponse:response]; }];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_alert_buttons(js_env_t *env, js_callback_info_t *info) {
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
    NSAlert *alert = (__bridge NSAlert *) handle;

    result = bare_app_kit__from_objects(env, registry, alert.buttons);
  }

  return result;
}
