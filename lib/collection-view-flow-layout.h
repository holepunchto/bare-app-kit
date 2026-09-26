#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_collection_view_flow_layout_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 0;
  js_value_t *argv[0];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  js_value_t *result;

  @autoreleasepool {
    NSCollectionViewFlowLayout *handle = [[[NSCollectionViewFlowLayout alloc] init] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_item_size(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, collection_view_flow_layout.itemSize);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      collection_view_flow_layout.itemSize = NSMakeSize(width, height);
    }
  }

  return result;
}

static void
bare_app_kit_collection_view_flow_layout_item_size_typed(js_value_t *receiver, int32_t bare_tag, double width, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    collection_view_flow_layout.itemSize = NSMakeSize(width, height);
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_item_size_into(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    __typeof__(collection_view_flow_layout.itemSize) value = collection_view_flow_layout.itemSize;

    out[0] = value.width;
    out[1] = value.height;
  }

  return NULL;
}

static void
bare_app_kit_collection_view_flow_layout_item_size_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    __typeof__(collection_view_flow_layout.itemSize) value = collection_view_flow_layout.itemSize;

    out[0] = value.width;
    out[1] = value.height;
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_estimated_item_size(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, collection_view_flow_layout.estimatedItemSize);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      collection_view_flow_layout.estimatedItemSize = NSMakeSize(width, height);
    }
  }

  return result;
}

static void
bare_app_kit_collection_view_flow_layout_estimated_item_size_typed(js_value_t *receiver, int32_t bare_tag, double width, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    collection_view_flow_layout.estimatedItemSize = NSMakeSize(width, height);
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_estimated_item_size_into(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    __typeof__(collection_view_flow_layout.estimatedItemSize) value = collection_view_flow_layout.estimatedItemSize;

    out[0] = value.width;
    out[1] = value.height;
  }

  return NULL;
}

static void
bare_app_kit_collection_view_flow_layout_estimated_item_size_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    __typeof__(collection_view_flow_layout.estimatedItemSize) value = collection_view_flow_layout.estimatedItemSize;

    out[0] = value.width;
    out[1] = value.height;
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_minimum_line_spacing(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    if (argc == 1) {
      err = js_create_double(env, collection_view_flow_layout.minimumLineSpacing, &result);
      assert(err == 0);
    } else {
      double minimum_line_spacing;
      if (!bare_app_kit__read_double(env, argv[1], "minimum_line_spacing", &minimum_line_spacing)) return NULL;

      collection_view_flow_layout.minimumLineSpacing = minimum_line_spacing;
    }
  }

  return result;
}

static void
bare_app_kit_collection_view_flow_layout_minimum_line_spacing_typed(js_value_t *receiver, int32_t bare_tag, double minimum_line_spacing, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    collection_view_flow_layout.minimumLineSpacing = minimum_line_spacing;
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_minimum_interitem_spacing(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    if (argc == 1) {
      err = js_create_double(env, collection_view_flow_layout.minimumInteritemSpacing, &result);
      assert(err == 0);
    } else {
      double minimum_interitem_spacing;
      if (!bare_app_kit__read_double(env, argv[1], "minimum_interitem_spacing", &minimum_interitem_spacing)) return NULL;

      collection_view_flow_layout.minimumInteritemSpacing = minimum_interitem_spacing;
    }
  }

  return result;
}

static void
bare_app_kit_collection_view_flow_layout_minimum_interitem_spacing_typed(js_value_t *receiver, int32_t bare_tag, double minimum_interitem_spacing, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    collection_view_flow_layout.minimumInteritemSpacing = minimum_interitem_spacing;
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_section_inset(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_insets(env, collection_view_flow_layout.sectionInset);
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

      collection_view_flow_layout.sectionInset = NSEdgeInsetsMake(top, left, bottom, right);
    }
  }

  return result;
}

static void
bare_app_kit_collection_view_flow_layout_section_inset_typed(js_value_t *receiver, int32_t bare_tag, double top, double left, double bottom, double right, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    collection_view_flow_layout.sectionInset = NSEdgeInsetsMake(top, left, bottom, right);
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_section_inset_into(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    __typeof__(collection_view_flow_layout.sectionInset) value = collection_view_flow_layout.sectionInset;

    out[0] = value.top;
    out[1] = value.left;
    out[2] = value.bottom;
    out[3] = value.right;
  }

  return NULL;
}

static void
bare_app_kit_collection_view_flow_layout_section_inset_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 4, &out)) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    __typeof__(collection_view_flow_layout.sectionInset) value = collection_view_flow_layout.sectionInset;

    out[0] = value.top;
    out[1] = value.left;
    out[2] = value.bottom;
    out[3] = value.right;
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_scroll_direction(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    if (argc == 1) {
      err = js_create_int32(env, collection_view_flow_layout.scrollDirection, &result);
      assert(err == 0);
    } else {
      int32_t scroll_direction;
      if (!bare_app_kit__read_int32(env, argv[1], "scroll_direction", &scroll_direction)) return NULL;

      collection_view_flow_layout.scrollDirection = scroll_direction;
    }
  }

  return result;
}

static void
bare_app_kit_collection_view_flow_layout_scroll_direction_typed(js_value_t *receiver, int32_t bare_tag, int32_t scroll_direction, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    collection_view_flow_layout.scrollDirection = scroll_direction;
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_header_reference_size(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, collection_view_flow_layout.headerReferenceSize);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      collection_view_flow_layout.headerReferenceSize = NSMakeSize(width, height);
    }
  }

  return result;
}

static void
bare_app_kit_collection_view_flow_layout_header_reference_size_typed(js_value_t *receiver, int32_t bare_tag, double width, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    collection_view_flow_layout.headerReferenceSize = NSMakeSize(width, height);
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_header_reference_size_into(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    __typeof__(collection_view_flow_layout.headerReferenceSize) value = collection_view_flow_layout.headerReferenceSize;

    out[0] = value.width;
    out[1] = value.height;
  }

  return NULL;
}

static void
bare_app_kit_collection_view_flow_layout_header_reference_size_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    __typeof__(collection_view_flow_layout.headerReferenceSize) value = collection_view_flow_layout.headerReferenceSize;

    out[0] = value.width;
    out[1] = value.height;
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_footer_reference_size(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1 || argc == 3);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result = NULL;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_size(env, collection_view_flow_layout.footerReferenceSize);
    } else {
      double width;
      err = js_get_value_double(env, argv[1], &width);
      assert(err == 0);

      double height;
      err = js_get_value_double(env, argv[2], &height);
      assert(err == 0);

      collection_view_flow_layout.footerReferenceSize = NSMakeSize(width, height);
    }
  }

  return result;
}

static void
bare_app_kit_collection_view_flow_layout_footer_reference_size_typed(js_value_t *receiver, int32_t bare_tag, double width, double height, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    collection_view_flow_layout.footerReferenceSize = NSMakeSize(width, height);
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_footer_reference_size_into(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    __typeof__(collection_view_flow_layout.footerReferenceSize) value = collection_view_flow_layout.footerReferenceSize;

    out[0] = value.width;
    out[1] = value.height;
  }

  return NULL;
}

static void
bare_app_kit_collection_view_flow_layout_footer_reference_size_into_typed(js_value_t *receiver, int32_t bare_tag, js_value_t *bare_buffer, uint32_t bare_offset, js_typed_callback_info_t *info) {
  int err;

  js_env_t *env;
  err = js_get_typed_callback_info(info, &env, NULL);
  assert(err == 0);

  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  double *out;

  if (!bare_app_kit__buffer(env, bare_buffer, bare_offset, 2, &out)) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    __typeof__(collection_view_flow_layout.footerReferenceSize) value = collection_view_flow_layout.footerReferenceSize;

    out[0] = value.width;
    out[1] = value.height;
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_section_headers_pin_to_visible_bounds(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, collection_view_flow_layout.sectionHeadersPinToVisibleBounds, &result);
      assert(err == 0);
    } else {
      bool section_headers_pin_to_visible_bounds;
      if (!bare_app_kit__read_bool(env, argv[1], "section_headers_pin_to_visible_bounds", &section_headers_pin_to_visible_bounds)) return NULL;

      collection_view_flow_layout.sectionHeadersPinToVisibleBounds = section_headers_pin_to_visible_bounds;
    }
  }

  return result;
}

static void
bare_app_kit_collection_view_flow_layout_section_headers_pin_to_visible_bounds_typed(js_value_t *receiver, int32_t bare_tag, bool section_headers_pin_to_visible_bounds, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    collection_view_flow_layout.sectionHeadersPinToVisibleBounds = section_headers_pin_to_visible_bounds;
  }
}

static js_value_t *
bare_app_kit_collection_view_flow_layout_section_footers_pin_to_visible_bounds(js_env_t *env, js_callback_info_t *info) {
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
    NSCollectionViewFlowLayout *collection_view_flow_layout = (__bridge NSCollectionViewFlowLayout *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, collection_view_flow_layout.sectionFootersPinToVisibleBounds, &result);
      assert(err == 0);
    } else {
      bool section_footers_pin_to_visible_bounds;
      if (!bare_app_kit__read_bool(env, argv[1], "section_footers_pin_to_visible_bounds", &section_footers_pin_to_visible_bounds)) return NULL;

      collection_view_flow_layout.sectionFootersPinToVisibleBounds = section_footers_pin_to_visible_bounds;
    }
  }

  return result;
}

static void
bare_app_kit_collection_view_flow_layout_section_footers_pin_to_visible_bounds_typed(js_value_t *receiver, int32_t bare_tag, bool section_footers_pin_to_visible_bounds, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSCollectionViewFlowLayout *collection_view_flow_layout = (NSCollectionViewFlowLayout *) bare_object;

    collection_view_flow_layout.sectionFootersPinToVisibleBounds = section_footers_pin_to_visible_bounds;
  }
}
