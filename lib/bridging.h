#pragma once

#import <assert.h>
#import <js.h>
#import <stdlib.h>
#import <utf.h>

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>

// The tag registry and the protocol for passing an object to another addon.
#import "registry.h"

@protocol BareEventTarget

- (int32_t)eventMask;
- (void)setEventMask:(int32_t)mask;

@end

// A value of the wrong type would otherwise reach V8's `Cast()` and abort the
// whole process, which leaves no JS stack to debug from. These raise an
// ordinary JS exception instead; every caller returns NULL so it propagates.
static bool
bare_app_kit__read_number(js_env_t *env, js_value_t *value, const char *name) {
  int err;

  js_value_type_t type;
  err = js_typeof(env, value, &type);
  assert(err == 0);

  if (type == js_number) return true;

  err = js_throw_type_errorf(env, NULL, "Expected a number for '%s'", name);
  assert(err == 0);

  return false;
}

static bool
bare_app_kit__read_bool(js_env_t *env, js_value_t *value, const char *name, bool *result) {
  int err;

  js_value_type_t type;
  err = js_typeof(env, value, &type);
  assert(err == 0);

  if (type != js_boolean) {
    err = js_throw_type_errorf(env, NULL, "Expected a boolean for '%s'", name);
    assert(err == 0);

    return false;
  }

  err = js_get_value_bool(env, value, result);
  assert(err == 0);

  return true;
}

static bool
bare_app_kit__read_int32(js_env_t *env, js_value_t *value, const char *name, int32_t *result) {
  if (!bare_app_kit__read_number(env, value, name)) return false;

  int err = js_get_value_int32(env, value, result);
  assert(err == 0);

  return true;
}

static bool
bare_app_kit__read_uint32(js_env_t *env, js_value_t *value, const char *name, uint32_t *result) {
  if (!bare_app_kit__read_number(env, value, name)) return false;

  int err = js_get_value_uint32(env, value, result);
  assert(err == 0);

  return true;
}

static bool
bare_app_kit__read_double(js_env_t *env, js_value_t *value, const char *name, double *result) {
  if (!bare_app_kit__read_number(env, value, name)) return false;

  int err = js_get_value_double(env, value, result);
  assert(err == 0);

  return true;
}

// Native objects cross the boundary as integer tags rather than externals. An
// external had to be minted on every return, which allocated, took a retain
// and gave a value that never compared equal to itself; a tag is stable, so
// object identity is free and returning one costs nothing.
//

// Objects cross a module boundary as an external carrying the bare pointer,
// because a tag only means something to the registry that issued it. The type
// tag makes the external unforgeable: an external from somewhere else, or a
// value that merely looks like one, is rejected before anything is cast.
//

// A getter that returns a struct has to build a JS object, which is the most
// expensive thing a binding does and cannot happen in a typed callback. The
// caller supplies the storage instead, and the components are written into it.
// Reading an array buffer's backing store needs no handle scope.
static bool
bare_app_kit__buffer(js_env_t *env, js_value_t *value, uint32_t offset, uint32_t count, double **result) {
  int err;

  bool is_arraybuffer;
  err = js_is_arraybuffer(env, value, &is_arraybuffer);
  assert(err == 0);

  if (!is_arraybuffer) return false;

  void *data;
  size_t len;
  err = js_get_arraybuffer_info(env, value, &data, &len);
  assert(err == 0);

  if ((uint64_t) offset + (uint64_t) count * sizeof(double) > len) return false;

  *result = (double *) ((uint8_t *) data + offset);

  return true;
}

static js_value_t *
bare_app_kit__from_string(js_env_t *env, NSString *string) {
  int err;

  js_value_t *result;

  if (string == nil) {
    err = js_get_null(env, &result);
    assert(err == 0);
  } else {
    err = js_create_string_utf8(env, (const utf8_t *) [string UTF8String], -1, &result);
    assert(err == 0);
  }

  return result;
}

static NSString *
bare_app_kit__to_string(js_env_t *env, js_value_t *value) {
  int err;

  js_value_type_t type;
  err = js_typeof(env, value, &type);
  assert(err == 0);

  if (type == js_null || type == js_undefined) return nil;

  size_t len;
  err = js_get_value_string_utf8(env, value, NULL, 0, &len);
  assert(err == 0);

  len += 1 /* NULL */;

  char *data = malloc(len);

  err = js_get_value_string_utf8(env, value, (utf8_t *) data, len, &len);
  assert(err == 0);

  NSString *result = [NSString stringWithUTF8String:data];

  free(data);

  return result;
}

static js_value_t *
bare_app_kit__from_rect(js_env_t *env, NSRect rect) {
  int err;

  js_value_t *result;
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

  V("x", rect.origin.x)
  V("y", rect.origin.y)
  V("width", rect.size.width)
  V("height", rect.size.height)
#undef V

  return result;
}

static js_value_t *
bare_app_kit__from_size(js_env_t *env, NSSize size) {
  int err;

  js_value_t *result;
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

  V("width", size.width)
  V("height", size.height)
#undef V

  return result;
}

static bool
bare_app_kit__handler(js_env_t *env, js_value_t *receiver, const char *name, js_value_t **result) {
  int err = js_get_named_property(env, receiver, name, result);
  assert(err == 0);

  js_value_type_t type;
  err = js_typeof(env, *result, &type);
  assert(err == 0);

  return type == js_function;
}

// AppKit clears whatever sits on a layer-backed view's layer when it realises
// the layer tree, the transform included, and changes no frame doing it. A
// view says when it is about to draw, which is after that, so what was on the
// layer can go back on.
#define BARE_APP_KIT_REPORTS_WILL_DRAW(bit) \
  -(void)viewWillDraw { \
    [super viewWillDraw]; \
\
    if ((mask & (bit)) == 0) return; \
\
    bare_app_kit__emit(env, ctx, "_onwilldraw"); \
  }

static void
bare_app_kit__emit(js_env_t *env, js_ref_t *ctx, const char *name) {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  // The context is weak, so it is empty once the JS wrapper has been collected.
  js_value_t *fn;

  if (receiver != NULL && bare_app_kit__handler(env, receiver, name, &fn)) {
    err = js_call_function(env, receiver, fn, 0, NULL, NULL);
    (void) err;
  }

  err = js_close_handle_scope(env, scope);
  assert(err == 0);
}

// Input is delivered through a single callback per view rather than one per
// event kind, so a view costs one reference no matter how much it listens to.
// The payload is positional and its meaning depends on `type`; nothing is
// allocated for the common pointer events.
static void
bare_app_kit__emit_event(js_env_t *env, js_ref_t *ctx, const char *name, int32_t type, double x, double y, double a, double b, int32_t modifiers, NSString *characters) {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  js_value_t *fn;

  if (receiver != NULL && bare_app_kit__handler(env, receiver, name, &fn)) {
    js_value_t *argv[7];

    err = js_create_int32(env, type, &argv[0]);
    assert(err == 0);

    const double values[] = {x, y, a, b};

    for (size_t i = 0; i < 4; i++) {
      err = js_create_double(env, values[i], &argv[i + 1]);
      assert(err == 0);
    }

    err = js_create_int32(env, modifiers, &argv[5]);
    assert(err == 0);

    argv[6] = bare_app_kit__from_string(env, characters);

    err = js_call_function(env, receiver, fn, 7, argv, NULL);
    (void) err;
  }

  err = js_close_handle_scope(env, scope);
  assert(err == 0);
}

static js_value_t *
bare_app_kit__from_strings(js_env_t *env, NSArray<NSString *> *strings) {
  int err;

  js_value_t *result;
  err = js_create_array_with_length(env, strings.count, &result);
  assert(err == 0);

  for (NSUInteger i = 0, n = strings.count; i < n; i++) {
    err = js_set_element(env, result, (uint32_t) i, bare_app_kit__from_string(env, strings[i]));
    assert(err == 0);
  }

  return result;
}

static NSArray<NSString *> *
bare_app_kit__to_strings(js_env_t *env, js_value_t *value) {
  int err;

  uint32_t len;
  err = js_get_array_length(env, value, &len);
  assert(err == 0);

  NSMutableArray<NSString *> *result = [NSMutableArray arrayWithCapacity:len];

  for (uint32_t i = 0; i < len; i++) {
    js_value_t *element;
    err = js_get_element(env, value, i, &element);
    assert(err == 0);

    [result addObject:bare_app_kit__to_string(env, element)];
  }

  return result;
}

static js_value_t *
bare_app_kit__from_index(js_env_t *env, NSInteger index) {
  int err;

  js_value_t *result;
  err = js_create_int32(env, index == NSNotFound ? -1 : (int32_t) index, &result);
  assert(err == 0);

  return result;
}

static js_value_t *
bare_app_kit__from_insets(js_env_t *env, NSEdgeInsets insets) {
  int err;

  js_value_t *result;
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

  V("top", insets.top)
  V("left", insets.left)
  V("bottom", insets.bottom)
  V("right", insets.right)
#undef V

  return result;
}

static js_value_t *
bare_app_kit__from_date(js_env_t *env, NSDate *date) {
  int err;

  js_value_t *result;

  if (date == nil) {
    err = js_get_null(env, &result);
    assert(err == 0);
  } else {
    err = js_create_double(env, date.timeIntervalSince1970 * 1000, &result);
    assert(err == 0);
  }

  return result;
}

static NSDate *
bare_app_kit__to_date(js_env_t *env, js_value_t *value) {
  int err;

  js_value_type_t type;
  err = js_typeof(env, value, &type);
  assert(err == 0);

  if (type != js_number) return nil;

  double milliseconds;
  err = js_get_value_double(env, value, &milliseconds);
  assert(err == 0);

  return [NSDate dateWithTimeIntervalSince1970:milliseconds / 1000];
}

// Sheets and panels report their outcome, so the emitted event carries it.
static void
bare_app_kit__emit_int32(js_env_t *env, js_ref_t *ctx, const char *name, int32_t value) {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  js_value_t *fn;

  if (receiver != NULL && bare_app_kit__handler(env, receiver, name, &fn)) {
    js_value_t *argv[1];
    err = js_create_int32(env, value, &argv[0]);
    assert(err == 0);

    err = js_call_function(env, receiver, fn, 1, argv, NULL);
    (void) err;
  }

  err = js_close_handle_scope(env, scope);
  assert(err == 0);
}

// A range and the string about to replace it, which is what the text objects
// report about an edit before it happens.
static void
bare_app_kit__emit_replacement(js_env_t *env, js_ref_t *ctx, const char *name, int32_t location, int32_t length, NSString *string) {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *receiver;
  err = js_get_reference_value(env, ctx, &receiver);
  assert(err == 0);

  js_value_t *fn;

  if (receiver != NULL && bare_app_kit__handler(env, receiver, name, &fn)) {
    js_value_t *argv[3];

    err = js_create_int32(env, location, &argv[0]);
    assert(err == 0);

    err = js_create_int32(env, length, &argv[1]);
    assert(err == 0);

    argv[2] = bare_app_kit__from_string(env, string);

    err = js_call_function(env, receiver, fn, 3, argv, NULL);
    (void) err;
  }

  err = js_close_handle_scope(env, scope);
  assert(err == 0);
}

static js_value_t *
bare_app_kit__from_url(js_env_t *env, NSURL *url) {
  return bare_app_kit__from_string(env, url == nil ? nil : url.path);
}

static NSURL *
bare_app_kit__to_url(js_env_t *env, js_value_t *value) {
  NSString *path = bare_app_kit__to_string(env, value);

  return path == nil ? nil : [NSURL fileURLWithPath:path];
}

static js_value_t *
bare_app_kit__from_urls(js_env_t *env, NSArray<NSURL *> *urls) {
  int err;

  js_value_t *result;
  err = js_create_array_with_length(env, urls.count, &result);
  assert(err == 0);

  for (NSUInteger i = 0, n = urls.count; i < n; i++) {
    err = js_set_element(env, result, (uint32_t) i, bare_app_kit__from_url(env, urls[i]));
    assert(err == 0);
  }

  return result;
}

// A data source callback that throws must not leave an exception pending across
// the rest of the framework's own work. Reports it the way an uncaught exception
// from any other callback is reported, and answers whether the call succeeded.
static bool
bare_app_kit__settle(js_env_t *env, int err) {
  if (err == 0) return true;

  js_value_t *exception;
  err = js_get_and_clear_last_exception(env, &exception);
  assert(err == 0);

  if (exception != NULL) {
    err = js_fatal_exception(env, exception);
    assert(err == 0);
  }

  return false;
}

static js_value_t *
bare_app_kit__from_point(js_env_t *env, NSPoint point) {
  int err;

  js_value_t *result;
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

  V("x", point.x)
  V("y", point.y)
#undef V

  return result;
}

static js_value_t *
bare_app_kit__from_data(js_env_t *env, NSData *data) {
  int err;

  js_value_t *result;

  if (data == nil) {
    err = js_get_null(env, &result);
    assert(err == 0);
  } else {
    void *bytes;
    err = js_create_arraybuffer(env, data.length, &bytes, &result);
    assert(err == 0);

    memcpy(bytes, data.bytes, data.length);
  }

  return result;
}

static NSData *
bare_app_kit__to_data(js_env_t *env, js_value_t *value) {
  int err;

  js_value_type_t type;
  err = js_typeof(env, value, &type);
  assert(err == 0);

  if (type != js_object) return nil;

  void *bytes;
  size_t len;
  err = js_get_arraybuffer_info(env, value, &bytes, &len);
  if (err != 0) return nil;

  return [NSData dataWithBytes:bytes length:len];
}

static js_value_t *
bare_app_kit__from_range(js_env_t *env, NSRange range) {
  int err;

  js_value_t *result;
  err = js_create_object(env, &result);
  assert(err == 0);

#define V(name, n) \
  { \
    js_value_t *val; \
    err = js_create_int32(env, n == NSNotFound ? -1 : (int32_t) n, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, result, name, val); \
    assert(err == 0); \
  }

  V("location", range.location)
  V("length", range.length)
#undef V

  return result;
}

static js_value_t *
bare_app_kit__from_objects(js_env_t *env, NSArray *objects) {
  int err;

  js_value_t *result;
  err = js_create_array_with_length(env, objects.count, &result);
  assert(err == 0);

  for (NSUInteger i = 0, n = objects.count; i < n; i++) {
    err = js_set_element(env, result, (uint32_t) i, bare_foundation__bridge(env, objects[i]));
    assert(err == 0);
  }

  return result;
}

static NSArray *
bare_app_kit__to_objects(js_env_t *env, js_value_t *value) {
  int err;

  uint32_t len;
  err = js_get_array_length(env, value, &len);
  assert(err == 0);

  NSMutableArray *result = [NSMutableArray arrayWithCapacity:len];

  for (uint32_t i = 0; i < len; i++) {
    js_value_t *element;
    err = js_get_element(env, value, i, &element);
    assert(err == 0);

    id object = bare_foundation__to_object(env, element);

    if (object != nil) [result addObject:object];
  }

  return result;
}

static js_value_t *
bare_app_kit_event_mask(js_env_t *env, js_callback_info_t *info) {
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
    id object = (__bridge id) handle;

    // An object backed by a plain framework class has nothing to deliver;
    // listening to it is silently inert, as it was before the mask existed.
    if (![object conformsToProtocol:@protocol(BareEventTarget)]) return NULL;

    id<BareEventTarget> target = object;

    if (argc == 1) {
      err = js_create_int32(env, target.eventMask, &result);
      assert(err == 0);
    } else {
      int32_t mask;
      if (!bare_app_kit__read_int32(env, argv[1], "mask", &mask)) return NULL;

      target.eventMask = mask;
    }
  }

  return result;
}

#define BARE_APP_KIT_ATTRIBUTES_OBJECT(V) \
  V("font", NSFontAttributeName) \
  V("foregroundColor", NSForegroundColorAttributeName) \
  V("backgroundColor", NSBackgroundColorAttributeName) \
  V("underlineColor", NSUnderlineColorAttributeName) \
  V("strikethroughColor", NSStrikethroughColorAttributeName) \
  V("paragraphStyle", NSParagraphStyleAttributeName)

#define BARE_APP_KIT_ATTRIBUTES_NUMBER(V) \
  V("underlineStyle", NSUnderlineStyleAttributeName) \
  V("strikethroughStyle", NSStrikethroughStyleAttributeName) \
  V("kern", NSKernAttributeName) \
  V("baselineOffset", NSBaselineOffsetAttributeName) \
  V("obliqueness", NSObliquenessAttributeName) \
  V("expansion", NSExpansionAttributeName) \
  V("ligature", NSLigatureAttributeName)

#define BARE_APP_KIT_ATTRIBUTES_STRING(V) \
  V("toolTip", NSToolTipAttributeName)

static js_value_t *
bare_app_kit__from_attributes(js_env_t *env, NSDictionary<NSAttributedStringKey, id> *attributes) {
  int err;

  js_value_t *result;
  err = js_create_object(env, &result);
  assert(err == 0);

#define V(key, name) \
  if (attributes[name] != nil) { \
    err = js_set_named_property(env, result, key, bare_foundation__bridge(env, attributes[name])); \
    assert(err == 0); \
  }
  BARE_APP_KIT_ATTRIBUTES_OBJECT(V)
#undef V

#define V(key, name) \
  if (attributes[name] != nil) { \
    js_value_t *val; \
    err = js_create_double(env, [attributes[name] doubleValue], &val); \
    assert(err == 0); \
    err = js_set_named_property(env, result, key, val); \
    assert(err == 0); \
  }
  BARE_APP_KIT_ATTRIBUTES_NUMBER(V)
#undef V

#define V(key, name) \
  if (attributes[name] != nil) { \
    err = js_set_named_property(env, result, key, bare_app_kit__from_string(env, attributes[name])); \
    assert(err == 0); \
  }
  BARE_APP_KIT_ATTRIBUTES_STRING(V)
#undef V

  if (attributes[NSLinkAttributeName] != nil) {
    NSURL *link = attributes[NSLinkAttributeName];

    err = js_set_named_property(env, result, "link", bare_app_kit__from_string(env, link.absoluteString));
    assert(err == 0);
  }

  return result;
}

static NSDictionary<NSAttributedStringKey, id> *
bare_app_kit__to_attributes(js_env_t *env, js_value_t *value) {
  int err;

  js_value_type_t type;
  err = js_typeof(env, value, &type);
  assert(err == 0);

  NSMutableDictionary<NSAttributedStringKey, id> *result = [NSMutableDictionary dictionary];

  if (type != js_object) return result;

#define V(key, name) \
  { \
    js_value_t *val; \
    err = js_get_named_property(env, value, key, &val); \
    assert(err == 0); \
    id object = bare_foundation__to_object(env, val); \
    if (object != nil) result[name] = object; \
  }
  BARE_APP_KIT_ATTRIBUTES_OBJECT(V)
#undef V

#define V(key, name) \
  { \
    js_value_t *val; \
    err = js_get_named_property(env, value, key, &val); \
    assert(err == 0); \
    js_value_type_t t; \
    err = js_typeof(env, val, &t); \
    assert(err == 0); \
    if (t == js_number) { \
      double n; \
      err = js_get_value_double(env, val, &n); \
      assert(err == 0); \
      result[name] = @(n); \
    } \
  }
  BARE_APP_KIT_ATTRIBUTES_NUMBER(V)
#undef V

#define V(key, name) \
  { \
    js_value_t *val; \
    err = js_get_named_property(env, value, key, &val); \
    assert(err == 0); \
    NSString *string = bare_app_kit__to_string(env, val); \
    if (string != nil) result[name] = string; \
  }
  BARE_APP_KIT_ATTRIBUTES_STRING(V)
#undef V

  {
    js_value_t *val;
    err = js_get_named_property(env, value, "link", &val);
    assert(err == 0);

    NSString *link = bare_app_kit__to_string(env, val);

    if (link != nil) result[NSLinkAttributeName] = [NSURL URLWithString:link];
  }

  return result;
}

static js_value_t *
bare_app_kit__from_types(js_env_t *env, NSArray<UTType *> *types) {
  int err;

  js_value_t *result;
  err = js_create_array_with_length(env, types.count, &result);
  assert(err == 0);

  for (NSUInteger i = 0, n = types.count; i < n; i++) {
    err = js_set_element(env, result, (uint32_t) i, bare_foundation__bridge(env, types[i]));
    assert(err == 0);
  }

  return result;
}

static NSArray<UTType *> *
bare_app_kit__to_types(js_env_t *env, js_value_t *value) {
  int err;

  uint32_t len;
  err = js_get_array_length(env, value, &len);
  assert(err == 0);

  NSMutableArray<UTType *> *result = [NSMutableArray arrayWithCapacity:len];

  for (uint32_t i = 0; i < len; i++) {
    js_value_t *element;
    err = js_get_element(env, value, i, &element);
    assert(err == 0);

    UTType *type = bare_foundation__to_object(env, element);

    if (type != nil) [result addObject:type];
  }

  return result;
}

static js_value_t *
bare_app_kit__from_index_paths(js_env_t *env, NSSet<NSIndexPath *> *paths) {
  int err;

  NSArray<NSIndexPath *> *sorted = [paths.allObjects sortedArrayUsingSelector:@selector(compare:)];

  js_value_t *result;
  err = js_create_array_with_length(env, sorted.count, &result);
  assert(err == 0);

  for (NSUInteger i = 0, n = sorted.count; i < n; i++) {
    js_value_t *entry;
    err = js_create_object(env, &entry);
    assert(err == 0);

#define V(name, n) \
  { \
    js_value_t *val; \
    err = js_create_int32(env, (int32_t) n, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, entry, name, val); \
    assert(err == 0); \
  }

    V("section", sorted[i].section)
    V("item", sorted[i].item)
#undef V

    err = js_set_element(env, result, (uint32_t) i, entry);
    assert(err == 0);
  }

  return result;
}
