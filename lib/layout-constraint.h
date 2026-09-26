#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_layout_constraint_active(js_env_t *env, js_callback_info_t *info) {
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
    NSLayoutConstraint *layout_constraint = (__bridge NSLayoutConstraint *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, layout_constraint.active, &result);
      assert(err == 0);
    } else {
      bool active;
      if (!bare_app_kit__read_bool(env, argv[1], "active", &active)) return NULL;

      layout_constraint.active = active;
    }
  }

  return result;
}

static void
bare_app_kit_layout_constraint_active_typed(js_value_t *receiver, int32_t bare_tag, bool active, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSLayoutConstraint *layout_constraint = (NSLayoutConstraint *) bare_object;

    layout_constraint.active = active;
  }
}

static js_value_t *
bare_app_kit_layout_constraint_constant(js_env_t *env, js_callback_info_t *info) {
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
    NSLayoutConstraint *layout_constraint = (__bridge NSLayoutConstraint *) handle;

    if (argc == 1) {
      err = js_create_double(env, layout_constraint.constant, &result);
      assert(err == 0);
    } else {
      double constant;
      if (!bare_app_kit__read_double(env, argv[1], "constant", &constant)) return NULL;

      layout_constraint.constant = constant;
    }
  }

  return result;
}

static void
bare_app_kit_layout_constraint_constant_typed(js_value_t *receiver, int32_t bare_tag, double constant, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSLayoutConstraint *layout_constraint = (NSLayoutConstraint *) bare_object;

    layout_constraint.constant = constant;
  }
}

static js_value_t *
bare_app_kit_layout_constraint_priority(js_env_t *env, js_callback_info_t *info) {
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
    NSLayoutConstraint *layout_constraint = (__bridge NSLayoutConstraint *) handle;

    if (argc == 1) {
      err = js_create_double(env, layout_constraint.priority, &result);
      assert(err == 0);
    } else {
      double priority;
      if (!bare_app_kit__read_double(env, argv[1], "priority", &priority)) return NULL;

      layout_constraint.priority = priority;
    }
  }

  return result;
}

static void
bare_app_kit_layout_constraint_priority_typed(js_value_t *receiver, int32_t bare_tag, double priority, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSLayoutConstraint *layout_constraint = (NSLayoutConstraint *) bare_object;

    layout_constraint.priority = priority;
  }
}

static js_value_t *
bare_app_kit_layout_constraint_identifier(js_env_t *env, js_callback_info_t *info) {
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
    NSLayoutConstraint *layout_constraint = (__bridge NSLayoutConstraint *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, layout_constraint.identifier);
    } else {
      layout_constraint.identifier = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_layout_constraint_multiplier(js_env_t *env, js_callback_info_t *info) {
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
    NSLayoutConstraint *layout_constraint = (__bridge NSLayoutConstraint *) handle;

    err = js_create_double(env, layout_constraint.multiplier, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_layout_constraint_relation(js_env_t *env, js_callback_info_t *info) {
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
    NSLayoutConstraint *layout_constraint = (__bridge NSLayoutConstraint *) handle;

    err = js_create_int32(env, layout_constraint.relation, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_layout_constraint_first_attribute(js_env_t *env, js_callback_info_t *info) {
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
    NSLayoutConstraint *layout_constraint = (__bridge NSLayoutConstraint *) handle;

    err = js_create_int32(env, layout_constraint.firstAttribute, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_layout_constraint_second_attribute(js_env_t *env, js_callback_info_t *info) {
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
    NSLayoutConstraint *layout_constraint = (__bridge NSLayoutConstraint *) handle;

    err = js_create_int32(env, layout_constraint.secondAttribute, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_layout_constraint_activate(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSArray *constraints = bare_app_kit__to_objects(env, argv[0]);

  @autoreleasepool {
    [NSLayoutConstraint activateConstraints:constraints];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_layout_constraint_deactivate(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSArray *constraints = bare_app_kit__to_objects(env, argv[0]);

  @autoreleasepool {
    [NSLayoutConstraint deactivateConstraints:constraints];
  }

  return NULL;
}
