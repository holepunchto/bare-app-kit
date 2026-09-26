#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

// The list every system colour is generated from: the ids below, the switch in
// `bare_app_kit_color_system()`, and the constants in `binding.m`.
#define BARE_APP_KIT_COLORS(V) \
  V(BLACK, blackColor) \
  V(WHITE, whiteColor) \
  V(CLEAR, clearColor) \
  V(LABEL, labelColor) \
  V(SECONDARY_LABEL, secondaryLabelColor) \
  V(TERTIARY_LABEL, tertiaryLabelColor) \
  V(QUATERNARY_LABEL, quaternaryLabelColor) \
  V(TEXT, textColor) \
  V(PLACEHOLDER_TEXT, placeholderTextColor) \
  V(SELECTED_TEXT, selectedTextColor) \
  V(TEXT_BACKGROUND, textBackgroundColor) \
  V(SELECTED_TEXT_BACKGROUND, selectedTextBackgroundColor) \
  V(LINK, linkColor) \
  V(SEPARATOR, separatorColor) \
  V(GRID, gridColor) \
  V(HEADER_TEXT, headerTextColor) \
  V(CONTROL_ACCENT, controlAccentColor) \
  V(CONTROL, controlColor) \
  V(CONTROL_BACKGROUND, controlBackgroundColor) \
  V(CONTROL_TEXT, controlTextColor) \
  V(DISABLED_CONTROL_TEXT, disabledControlTextColor) \
  V(SELECTED_CONTROL, selectedControlColor) \
  V(SELECTED_CONTROL_TEXT, selectedControlTextColor) \
  V(ALTERNATE_SELECTED_CONTROL_TEXT, alternateSelectedControlTextColor) \
  V(SELECTED_CONTENT_BACKGROUND, selectedContentBackgroundColor) \
  V(UNEMPHASIZED_SELECTED_CONTENT_BACKGROUND, unemphasizedSelectedContentBackgroundColor) \
  V(WINDOW_BACKGROUND, windowBackgroundColor) \
  V(WINDOW_FRAME_TEXT, windowFrameTextColor) \
  V(UNDER_PAGE_BACKGROUND, underPageBackgroundColor) \
  V(FIND_HIGHLIGHT, findHighlightColor) \
  V(HIGHLIGHT, highlightColor) \
  V(SHADOW, shadowColor) \
  V(SYSTEM_RED, systemRedColor) \
  V(SYSTEM_ORANGE, systemOrangeColor) \
  V(SYSTEM_YELLOW, systemYellowColor) \
  V(SYSTEM_GREEN, systemGreenColor) \
  V(SYSTEM_MINT, systemMintColor) \
  V(SYSTEM_TEAL, systemTealColor) \
  V(SYSTEM_CYAN, systemCyanColor) \
  V(SYSTEM_BLUE, systemBlueColor) \
  V(SYSTEM_INDIGO, systemIndigoColor) \
  V(SYSTEM_PURPLE, systemPurpleColor) \
  V(SYSTEM_PINK, systemPinkColor) \
  V(SYSTEM_BROWN, systemBrownColor) \
  V(SYSTEM_GRAY, systemGrayColor)

enum {
#define V(name, selector) bare_app_kit_color_##name,
  BARE_APP_KIT_COLORS(V)
#undef V
};

static js_value_t *
bare_app_kit_color_system(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1);

  int32_t id;
  if (!bare_app_kit__read_int32(env, argv[0], "id", &id)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSColor *color = nil;

    switch (id) {
#define V(name, selector) \
  case bare_app_kit_color_##name: \
    color = [NSColor selector]; \
    break;
      BARE_APP_KIT_COLORS(V)
#undef V
    }

    result = bare_foundation_bridge(env, registry, color);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_rgb(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 4);

  double red;
  if (!bare_app_kit__read_double(env, argv[0], "red", &red)) return NULL;

  double green;
  if (!bare_app_kit__read_double(env, argv[1], "green", &green)) return NULL;

  double blue;
  if (!bare_app_kit__read_double(env, argv[2], "blue", &blue)) return NULL;

  double alpha;
  if (!bare_app_kit__read_double(env, argv[3], "alpha", &alpha)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation_bridge(env, registry, [NSColor colorWithSRGBRed:red green:green blue:blue alpha:alpha]);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_hsb(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 4);

  double hue;
  if (!bare_app_kit__read_double(env, argv[0], "hue", &hue)) return NULL;

  double saturation;
  if (!bare_app_kit__read_double(env, argv[1], "saturation", &saturation)) return NULL;

  double brightness;
  if (!bare_app_kit__read_double(env, argv[2], "brightness", &brightness)) return NULL;

  double alpha;
  if (!bare_app_kit__read_double(env, argv[3], "alpha", &alpha)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation_bridge(env, registry, [NSColor colorWithHue:hue saturation:saturation brightness:brightness alpha:alpha]);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_white(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  double white;
  if (!bare_app_kit__read_double(env, argv[0], "white", &white)) return NULL;

  double alpha;
  if (!bare_app_kit__read_double(env, argv[1], "alpha", &alpha)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation_bridge(env, registry, [NSColor colorWithWhite:white alpha:alpha]);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_components(js_env_t *env, js_callback_info_t *info) {
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
    NSColor *color = (__bridge NSColor *) handle;

    // Dynamic and catalog colours have no components until they are resolved
    // against a colour space.
    NSColor *srgb = [color colorUsingColorSpace:[NSColorSpace sRGBColorSpace]];

    if (srgb == nil) {
      err = js_get_null(env, &result);
      assert(err == 0);
    } else {
      err = js_create_object(env, &result);
      assert(err == 0);

#define V(name, n) \
  { \
    js_value_t *val; \
    err = js_create_double(env, n, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, result, name, val); \
    assert(err == 0); \
  }

      V("red", srgb.redComponent)
      V("green", srgb.greenComponent)
      V("blue", srgb.blueComponent)
      V("alpha", srgb.alphaComponent)
#undef V
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_color_alpha_component(js_env_t *env, js_callback_info_t *info) {
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
    NSColor *color = (__bridge NSColor *) handle;

    err = js_create_double(env, color.alphaComponent, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_with_alpha_component(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  double alpha;
  if (!bare_app_kit__read_double(env, argv[1], "alpha", &alpha)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSColor *color = (__bridge NSColor *) handle;

    result = bare_foundation_bridge(env, registry, [color colorWithAlphaComponent:alpha]);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_blended_color(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 3);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  double fraction;
  if (!bare_app_kit__read_double(env, argv[1], "fraction", &fraction)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSColor *color = (__bridge NSColor *) handle;
    NSColor *other = bare_foundation_to_object(env, registry, argv[2]);

    result = bare_foundation_bridge(env, registry, [color blendedColorWithFraction:fraction ofColor:other]);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_type(js_env_t *env, js_callback_info_t *info) {
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
    NSColor *color = (__bridge NSColor *) handle;

    err = js_create_int32(env, color.type, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_number_of_components(js_env_t *env, js_callback_info_t *info) {
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
    NSColor *color = (__bridge NSColor *) handle;

    err = js_create_int32(env, color.type == NSColorTypeComponentBased ? (int32_t) color.numberOfComponents : -1, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_with_pattern_image(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 1);

  id image = bare_foundation_to_object(env, registry, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation_bridge(env, registry, [NSColor colorWithPatternImage:image]);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_highlight(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  double level;
  if (!bare_app_kit__read_double(env, argv[1], "level", &level)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSColor *color = (__bridge NSColor *) handle;

    result = bare_foundation_bridge(env, registry, [color highlightWithLevel:level]);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_shadow(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  double level;
  if (!bare_app_kit__read_double(env, argv[1], "level", &level)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSColor *color = (__bridge NSColor *) handle;

    result = bare_foundation_bridge(env, registry, [color shadowWithLevel:level]);
  }

  return result;
}

static js_value_t *
bare_app_kit_color_with_system_effect(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  int32_t effect;
  if (!bare_app_kit__read_int32(env, argv[1], "effect", &effect)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSColor *color = (__bridge NSColor *) handle;

    result = bare_foundation_bridge(env, registry, [color colorWithSystemEffect:effect]);
  }

  return result;
}
