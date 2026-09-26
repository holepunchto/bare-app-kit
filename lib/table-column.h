#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_table_column_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  js_value_t *result;

  @autoreleasepool {
    NSString *identifier = bare_app_kit__to_string(env, argv[0]);

    NSTableColumn *handle = [[[NSTableColumn alloc] initWithIdentifier:identifier] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_column_identifier(js_env_t *env, js_callback_info_t *info) {
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
    NSTableColumn *table_column = (__bridge NSTableColumn *) handle;

    result = bare_app_kit__from_string(env, table_column.identifier);
  }

  return result;
}

static js_value_t *
bare_app_kit_table_column_title(js_env_t *env, js_callback_info_t *info) {
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
    NSTableColumn *table_column = (__bridge NSTableColumn *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, table_column.title);
    } else {
      table_column.title = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_table_column_width(js_env_t *env, js_callback_info_t *info) {
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
    NSTableColumn *table_column = (__bridge NSTableColumn *) handle;

    if (argc == 1) {
      err = js_create_double(env, table_column.width, &result);
      assert(err == 0);
    } else {
      double width;
      if (!bare_app_kit__read_double(env, argv[1], "width", &width)) return NULL;

      table_column.width = width;
    }
  }

  return result;
}

static void
bare_app_kit_table_column_width_typed(js_value_t *receiver, int32_t bare_tag, double width, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTableColumn *table_column = (NSTableColumn *) bare_object;

    table_column.width = width;
  }
}

static js_value_t *
bare_app_kit_table_column_min_width(js_env_t *env, js_callback_info_t *info) {
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
    NSTableColumn *table_column = (__bridge NSTableColumn *) handle;

    if (argc == 1) {
      err = js_create_double(env, table_column.minWidth, &result);
      assert(err == 0);
    } else {
      double min_width;
      if (!bare_app_kit__read_double(env, argv[1], "min_width", &min_width)) return NULL;

      table_column.minWidth = min_width;
    }
  }

  return result;
}

static void
bare_app_kit_table_column_min_width_typed(js_value_t *receiver, int32_t bare_tag, double min_width, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTableColumn *table_column = (NSTableColumn *) bare_object;

    table_column.minWidth = min_width;
  }
}

static js_value_t *
bare_app_kit_table_column_max_width(js_env_t *env, js_callback_info_t *info) {
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
    NSTableColumn *table_column = (__bridge NSTableColumn *) handle;

    if (argc == 1) {
      err = js_create_double(env, table_column.maxWidth, &result);
      assert(err == 0);
    } else {
      double max_width;
      if (!bare_app_kit__read_double(env, argv[1], "max_width", &max_width)) return NULL;

      table_column.maxWidth = max_width;
    }
  }

  return result;
}

static void
bare_app_kit_table_column_max_width_typed(js_value_t *receiver, int32_t bare_tag, double max_width, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTableColumn *table_column = (NSTableColumn *) bare_object;

    table_column.maxWidth = max_width;
  }
}

static js_value_t *
bare_app_kit_table_column_resizing_mask(js_env_t *env, js_callback_info_t *info) {
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
    NSTableColumn *table_column = (__bridge NSTableColumn *) handle;

    if (argc == 1) {
      err = js_create_int32(env, table_column.resizingMask, &result);
      assert(err == 0);
    } else {
      int32_t resizing_mask;
      if (!bare_app_kit__read_int32(env, argv[1], "resizing_mask", &resizing_mask)) return NULL;

      table_column.resizingMask = resizing_mask;
    }
  }

  return result;
}

static void
bare_app_kit_table_column_resizing_mask_typed(js_value_t *receiver, int32_t bare_tag, int32_t resizing_mask, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTableColumn *table_column = (NSTableColumn *) bare_object;

    table_column.resizingMask = resizing_mask;
  }
}

static js_value_t *
bare_app_kit_table_column_editable(js_env_t *env, js_callback_info_t *info) {
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
    NSTableColumn *table_column = (__bridge NSTableColumn *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, table_column.editable, &result);
      assert(err == 0);
    } else {
      bool editable;
      if (!bare_app_kit__read_bool(env, argv[1], "editable", &editable)) return NULL;

      table_column.editable = editable;
    }
  }

  return result;
}

static void
bare_app_kit_table_column_editable_typed(js_value_t *receiver, int32_t bare_tag, bool editable, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTableColumn *table_column = (NSTableColumn *) bare_object;

    table_column.editable = editable;
  }
}

static js_value_t *
bare_app_kit_table_column_hidden(js_env_t *env, js_callback_info_t *info) {
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
    NSTableColumn *table_column = (__bridge NSTableColumn *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, table_column.hidden, &result);
      assert(err == 0);
    } else {
      bool hidden;
      if (!bare_app_kit__read_bool(env, argv[1], "hidden", &hidden)) return NULL;

      table_column.hidden = hidden;
    }
  }

  return result;
}

static void
bare_app_kit_table_column_hidden_typed(js_value_t *receiver, int32_t bare_tag, bool hidden, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSTableColumn *table_column = (NSTableColumn *) bare_object;

    table_column.hidden = hidden;
  }
}

static js_value_t *
bare_app_kit_table_column_size_to_fit(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  @autoreleasepool {
    NSTableColumn *table_column = (__bridge NSTableColumn *) handle;

    [table_column sizeToFit];
  }

  return NULL;
}
