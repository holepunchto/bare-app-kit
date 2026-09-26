#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_application_main_menu(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0 || argc == 1);

  js_value_t *result = NULL;

  @autoreleasepool {
    NSApplication *application = [NSApplication sharedApplication];

    if (argc == 0) {
      result = bare_foundation__bridge(env, application.mainMenu);
    } else {
      application.mainMenu = bare_foundation__to_object(env, argv[0]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_application_activate(js_env_t *env, js_callback_info_t *info) {
  @autoreleasepool {
    [[NSApplication sharedApplication] activateIgnoringOtherApps:YES];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_application_activation_policy(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0 || argc == 1);

  js_value_t *result = NULL;

  @autoreleasepool {
    if (argc == 0) {
      err = js_create_int32(env, [NSApplication sharedApplication].activationPolicy, &result);
    assert(err == 0);
    } else {
      int32_t activation_policy;
      if (!bare_app_kit__read_int32(env, argv[0], "activation_policy", &activation_policy)) return NULL;

      [NSApplication sharedApplication].activationPolicy = activation_policy;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_application_presentation_options(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0 || argc == 1);

  js_value_t *result = NULL;

  @autoreleasepool {
    if (argc == 0) {
      err = js_create_int32(env, [NSApplication sharedApplication].presentationOptions, &result);
    assert(err == 0);
    } else {
      int32_t presentation_options;
      if (!bare_app_kit__read_int32(env, argv[0], "presentation_options", &presentation_options)) return NULL;

      [NSApplication sharedApplication].presentationOptions = presentation_options;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_application_application_icon_image(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0 || argc == 1);

  js_value_t *result = NULL;

  @autoreleasepool {
    if (argc == 0) {
      result = bare_foundation__bridge(env, [NSApplication sharedApplication].applicationIconImage);
    } else {
      [NSApplication sharedApplication].applicationIconImage = bare_foundation__to_object(env, argv[0]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_application_running(js_env_t *env, js_callback_info_t *info) {
  int err;

  js_value_t *result;

  @autoreleasepool {
    err = js_get_boolean(env, [NSApplication sharedApplication].running, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_application_active(js_env_t *env, js_callback_info_t *info) {
  int err;

  js_value_t *result;

  @autoreleasepool {
    err = js_get_boolean(env, [NSApplication sharedApplication].active, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_application_hidden(js_env_t *env, js_callback_info_t *info) {
  int err;

  js_value_t *result;

  @autoreleasepool {
    err = js_get_boolean(env, [NSApplication sharedApplication].hidden, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_application_main_window(js_env_t *env, js_callback_info_t *info) {
  int err;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSApplication sharedApplication].mainWindow);
  }

  return result;
}

static js_value_t *
bare_app_kit_application_key_window(js_env_t *env, js_callback_info_t *info) {
  int err;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSApplication sharedApplication].keyWindow);
  }

  return result;
}

static js_value_t *
bare_app_kit_application_windows_menu(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0 || argc == 1);

  js_value_t *result = NULL;

  @autoreleasepool {
    if (argc == 0) {
      result = bare_foundation__bridge(env, [NSApplication sharedApplication].windowsMenu);
    } else {
      [NSApplication sharedApplication].windowsMenu = bare_foundation__to_object(env, argv[0]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_application_services_menu(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0 || argc == 1);

  js_value_t *result = NULL;

  @autoreleasepool {
    if (argc == 0) {
      result = bare_foundation__bridge(env, [NSApplication sharedApplication].servicesMenu);
    } else {
      [NSApplication sharedApplication].servicesMenu = bare_foundation__to_object(env, argv[0]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_application_help_menu(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0 || argc == 1);

  js_value_t *result = NULL;

  @autoreleasepool {
    if (argc == 0) {
      result = bare_foundation__bridge(env, [NSApplication sharedApplication].helpMenu);
    } else {
      [NSApplication sharedApplication].helpMenu = bare_foundation__to_object(env, argv[0]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_application_effective_appearance(js_env_t *env, js_callback_info_t *info) {
  int err;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSApplication sharedApplication].effectiveAppearance);
  }

  return result;
}

static js_value_t *
bare_app_kit_application_appearance(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0 || argc == 1);

  js_value_t *result = NULL;

  @autoreleasepool {
    if (argc == 0) {
      result = bare_foundation__bridge(env, [NSApplication sharedApplication].appearance);
    } else {
      [NSApplication sharedApplication].appearance = bare_foundation__to_object(env, argv[0]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_application_hide(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  @autoreleasepool {
    [[NSApplication sharedApplication] hide:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_application_unhide(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  @autoreleasepool {
    [[NSApplication sharedApplication] unhide:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_application_unhide_all_applications(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  @autoreleasepool {
    [[NSApplication sharedApplication] unhideAllApplications:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_application_terminate(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  @autoreleasepool {
    [[NSApplication sharedApplication] terminate:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_application_arrange_in_front(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  @autoreleasepool {
    [[NSApplication sharedApplication] arrangeInFront:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_application_request_user_attention(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  int32_t type;
  if (!bare_app_kit__read_int32(env, argv[0], "type", &type)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    err = js_create_int32(env, (int32_t) [[NSApplication sharedApplication] requestUserAttention:type], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_application_cancel_user_attention_request(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  int32_t request;
  if (!bare_app_kit__read_int32(env, argv[0], "request", &request)) return NULL;

  @autoreleasepool {
    [[NSApplication sharedApplication] cancelUserAttentionRequest:request];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_application_number_of_windows(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    err = js_create_int32(env, (int32_t) [NSApplication sharedApplication].windows.count, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_application_window_at(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  int32_t index;
  if (!bare_app_kit__read_int32(env, argv[0], "index", &index)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [NSApplication sharedApplication].windows[index]);
  }

  return result;
}

static js_value_t *
bare_app_kit_application_set_activation_policy(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  int32_t policy;
  if (!bare_app_kit__read_int32(env, argv[0], "policy", &policy)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    err = js_get_boolean(env, [[NSApplication sharedApplication] setActivationPolicy:policy], &result);
    assert(err == 0);
  }

  return result;
}
