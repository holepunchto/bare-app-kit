#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_tracking_separator_toolbar_item_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 3;
  js_value_t *argv[3];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 3);

  int32_t dividerIndex;
  if (!bare_app_kit__read_int32(env, argv[2], "dividerIndex", &dividerIndex)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    NSString *identifier = bare_app_kit__to_string(env, argv[0]);

    id splitView = bare_foundation__to_object(env, argv[1]);

    NSTrackingSeparatorToolbarItem *handle = [NSTrackingSeparatorToolbarItem trackingSeparatorToolbarItemWithIdentifier:identifier splitView:splitView dividerIndex:dividerIndex];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}
