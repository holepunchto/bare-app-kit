#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_font_descriptor_symbolic_traits(js_env_t *env, js_callback_info_t *info) {
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
    NSFontDescriptor *descriptor = (__bridge NSFontDescriptor *) handle;

    err = js_create_uint32(env, descriptor.symbolicTraits, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_font_descriptor_with_symbolic_traits(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  uint32_t traits;
  if (!bare_app_kit__read_uint32(env, argv[1], "traits", &traits)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSFontDescriptor *descriptor = (__bridge NSFontDescriptor *) handle;

    result = bare_foundation_bridge(
      env, registry, [descriptor fontDescriptorWithSymbolicTraits:(NSFontDescriptorSymbolicTraits) traits]
    );
  }

  return result;
}

static js_value_t *
bare_app_kit_font_descriptor_with_family(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  bare_foundation_registry_t *registry;
  err = js_get_callback_info(env, info, &argc, argv, NULL, (void **) &registry);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (bare_foundation_read_tag(env, registry, argv[0], "handle", &handle) < 0) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSFontDescriptor *descriptor = (__bridge NSFontDescriptor *) handle;

    NSString *family = bare_app_kit__to_string(env, argv[1]);

    result = bare_foundation_bridge(env, registry, [descriptor fontDescriptorWithFamily:family]);
  }

  return result;
}
