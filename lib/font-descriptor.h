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

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

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

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  uint32_t traits;
  if (!bare_app_kit__read_uint32(env, argv[1], "traits", &traits)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSFontDescriptor *descriptor = (__bridge NSFontDescriptor *) handle;

    result = bare_foundation__bridge(
      env, [descriptor fontDescriptorWithSymbolicTraits:(NSFontDescriptorSymbolicTraits) traits]
    );
  }

  return result;
}

static js_value_t *
bare_app_kit_font_descriptor_with_family(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSFontDescriptor *descriptor = (__bridge NSFontDescriptor *) handle;

    NSString *family = bare_app_kit__to_string(env, argv[1]);

    result = bare_foundation__bridge(env, [descriptor fontDescriptorWithFamily:family]);
  }

  return result;
}
