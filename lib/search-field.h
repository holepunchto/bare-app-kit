#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

@interface BareSearchField : NSSearchField <NSSearchFieldDelegate, BareEventTarget> {
@public
  js_env_t *env;
  js_ref_t *ctx;
  int32_t mask;
}

@end

@implementation BareSearchField

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

- (void)onChange:(id)sender {
  if ((mask & (1 << 0)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onchange");
}

- (void)controlTextDidChange:(NSNotification *)notification {
  if ((mask & (1 << 1)) == 0) return;

  bare_app_kit__emit(env, ctx, "_oninput");
}

- (void)controlTextDidBeginEditing:(NSNotification *)notification {
  if ((mask & (1 << 2)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onbeginediting");
}

- (void)controlTextDidEndEditing:(NSNotification *)notification {
  if ((mask & (1 << 3)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onendediting");
}

- (void)searchFieldDidStartSearching:(NSSearchField *)sender {
  if ((mask & (1 << 4)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onstartsearching");
}

- (void)searchFieldDidEndSearching:(NSSearchField *)sender {
  if ((mask & (1 << 5)) == 0) return;

  bare_app_kit__emit(env, ctx, "_onendsearching");
}

@end

static js_value_t *
bare_app_kit_search_field_init(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 5);

  double x;
  err = js_get_value_double(env, argv[0], &x);
  assert(err == 0);

  double y;
  err = js_get_value_double(env, argv[1], &y);
  assert(err == 0);

  double width;
  err = js_get_value_double(env, argv[2], &width);
  assert(err == 0);

  double height;
  err = js_get_value_double(env, argv[3], &height);
  assert(err == 0);

  js_value_t *result;

  @autoreleasepool {
    BareSearchField *handle = [[[BareSearchField alloc]
      initWithFrame:NSMakeRect(x, y, width, height)] autorelease];

    result = bare_foundation__bridge(env, handle);

    handle->env = env;

    // Weak, so that the native object does not keep its own JS wrapper
    // alive. Events are dropped once the wrapper has been collected.
    err = js_create_reference(env, argv[4], 0, &handle->ctx);
    assert(err == 0);

    [handle setTarget:handle];
    [handle setAction:@selector(onChange:)];
    [handle setDelegate:handle];
  }

  return result;
}

static js_value_t *
bare_app_kit_search_field_sends_search_string_immediately(js_env_t *env, js_callback_info_t *info) {
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
    NSSearchField *search_field = (__bridge NSSearchField *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, search_field.sendsSearchStringImmediately, &result);
      assert(err == 0);
    } else {
      bool sends_search_string_immediately;
      if (!bare_app_kit__read_bool(env, argv[1], "sends_search_string_immediately", &sends_search_string_immediately)) return NULL;

      search_field.sendsSearchStringImmediately = sends_search_string_immediately;
    }
  }

  return result;
}

static void
bare_app_kit_search_field_sends_search_string_immediately_typed(js_value_t *receiver, int32_t bare_tag, bool sends_search_string_immediately, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSearchField *search_field = (NSSearchField *) bare_object;

    search_field.sendsSearchStringImmediately = sends_search_string_immediately;
  }
}

static js_value_t *
bare_app_kit_search_field_sends_whole_search_string(js_env_t *env, js_callback_info_t *info) {
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
    NSSearchField *search_field = (__bridge NSSearchField *) handle;

    if (argc == 1) {
      err = js_get_boolean(env, search_field.sendsWholeSearchString, &result);
      assert(err == 0);
    } else {
      bool sends_whole_search_string;
      if (!bare_app_kit__read_bool(env, argv[1], "sends_whole_search_string", &sends_whole_search_string)) return NULL;

      search_field.sendsWholeSearchString = sends_whole_search_string;
    }
  }

  return result;
}

static void
bare_app_kit_search_field_sends_whole_search_string_typed(js_value_t *receiver, int32_t bare_tag, bool sends_whole_search_string, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSearchField *search_field = (NSSearchField *) bare_object;

    search_field.sendsWholeSearchString = sends_whole_search_string;
  }
}

static js_value_t *
bare_app_kit_search_field_maximum_recents(js_env_t *env, js_callback_info_t *info) {
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
    NSSearchField *search_field = (__bridge NSSearchField *) handle;

    if (argc == 1) {
      err = js_create_int32(env, search_field.maximumRecents, &result);
      assert(err == 0);
    } else {
      int32_t maximum_recents;
      if (!bare_app_kit__read_int32(env, argv[1], "maximum_recents", &maximum_recents)) return NULL;

      search_field.maximumRecents = maximum_recents;
    }
  }

  return result;
}

static void
bare_app_kit_search_field_maximum_recents_typed(js_value_t *receiver, int32_t bare_tag, int32_t maximum_recents, js_typed_callback_info_t *info) {
  id bare_object = bare_foundation__object(bare_tag);

  if (bare_object == nil) return;

  @autoreleasepool {
    NSSearchField *search_field = (NSSearchField *) bare_object;

    search_field.maximumRecents = maximum_recents;
  }
}

static js_value_t *
bare_app_kit_search_field_recents_autosave_name(js_env_t *env, js_callback_info_t *info) {
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
    NSSearchField *search_field = (__bridge NSSearchField *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_string(env, search_field.recentsAutosaveName);
    } else {
      search_field.recentsAutosaveName = bare_app_kit__to_string(env, argv[1]);
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_search_field_recent_searches(js_env_t *env, js_callback_info_t *info) {
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
    NSSearchField *search_field = (__bridge NSSearchField *) handle;

    if (argc == 1) {
      result = bare_app_kit__from_strings(env, search_field.recentSearches);
    } else {
      search_field.recentSearches = bare_app_kit__to_strings(env, argv[1]);
    }
  }

  return result;
}
