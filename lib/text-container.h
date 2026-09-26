#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_text_container_line_fragment_padding(js_env_t *env, js_callback_info_t *info) {
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
    NSTextContainer *text_container = (__bridge NSTextContainer *) handle;

    if (argc == 1) {
      err = js_create_double(env, text_container.lineFragmentPadding, &result);
      assert(err == 0);
    } else {
      double line_fragment_padding;
      err = js_get_value_double(env, argv[1], &line_fragment_padding);
      assert(err == 0);

      text_container.lineFragmentPadding = line_fragment_padding;
    }
  }

  return result;
}
