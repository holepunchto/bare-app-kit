#import <assert.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import "bridging.h"

// `boundingRectWithSize:` returns tight glyph bounds, which come out shorter
// than the line boxes AppKit actually lays out, so text measured that way is
// clipped when it is drawn. A layout manager reports what will be rendered.
//
// The text system is reused across measurements because a flexbox pass asks
// for the same string at several widths before it settles.
@interface BareTextMeasurer : NSObject {
@public
  NSTextStorage *storage;
  NSLayoutManager *manager;
  NSTextContainer *container;
}

@end

@implementation BareTextMeasurer

- (instancetype)init {
  self = [super init];

  if (self) {
    storage = [[NSTextStorage alloc] init];
    manager = [[NSLayoutManager alloc] init];
    container = [[NSTextContainer alloc] initWithSize:NSMakeSize(0, 0)];

    container.lineFragmentPadding = 0;

    [storage addLayoutManager:manager];
    [manager addTextContainer:container];
  }

  return self;
}

- (void)dealloc {
  [container release];
  [manager release];
  [storage release];

  [super dealloc];
}

- (NSRect)measure:(NSAttributedString *)text width:(double)width height:(double)height {
  [storage setAttributedString:text];

  container.size = NSMakeSize(width, height);

  // Forces layout; the used rect is only valid once glyphs are laid out.
  [manager glyphRangeForTextContainer:container];

  return [manager usedRectForTextContainer:container];
}

@end

static js_value_t *
bare_app_kit_text_measurer_init(js_env_t *env, js_callback_info_t *info) {
  js_value_t *result;

  @autoreleasepool {
    BareTextMeasurer *handle = [[[BareTextMeasurer alloc] init] autorelease];

    result = bare_foundation__bridge(env, handle);
  }

  return result;
}

static js_value_t *
bare_app_kit_text_measurer_line_fragment_padding(js_env_t *env, js_callback_info_t *info) {
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
    BareTextMeasurer *measurer = (__bridge BareTextMeasurer *) handle;

    if (argc == 1) {
      err = js_create_double(env, measurer->container.lineFragmentPadding, &result);
      assert(err == 0);
    } else {
      double padding;
      if (!bare_app_kit__read_double(env, argv[1], "padding", &padding)) return NULL;

      measurer->container.lineFragmentPadding = padding;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_measurer_maximum_number_of_lines(js_env_t *env, js_callback_info_t *info) {
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
    BareTextMeasurer *measurer = (__bridge BareTextMeasurer *) handle;

    if (argc == 1) {
      err = js_create_int32(env, (int32_t) measurer->container.maximumNumberOfLines, &result);
      assert(err == 0);
    } else {
      int32_t lines;
      if (!bare_app_kit__read_int32(env, argv[1], "lines", &lines)) return NULL;

      measurer->container.maximumNumberOfLines = lines;
    }
  }

  return result;
}

static js_value_t *
bare_app_kit_text_measurer_measure(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 5;
  js_value_t *argv[5];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 5);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[3], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[4], "height", &height)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    BareTextMeasurer *measurer = (__bridge BareTextMeasurer *) handle;

    NSString *string = bare_app_kit__to_string(env, argv[1]);
    NSDictionary *attributes = bare_app_kit__to_attributes(env, argv[2]);

    NSAttributedString *text = [[[NSAttributedString alloc]
      initWithString:string attributes:attributes] autorelease];

    result = bare_app_kit__from_size(env, [measurer measure:text width:width height:height].size);
  }

  return result;
}

static js_value_t *
bare_app_kit_text_measurer_measure_attributed(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 4;
  js_value_t *argv[4];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 4);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  void *text;
  if (!bare_foundation__read_tag(env, argv[1], "text", &text)) return NULL;

  double width;
  if (!bare_app_kit__read_double(env, argv[2], "width", &width)) return NULL;

  double height;
  if (!bare_app_kit__read_double(env, argv[3], "height", &height)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    BareTextMeasurer *measurer = (__bridge BareTextMeasurer *) handle;

    result = bare_app_kit__from_size(env, [measurer measure:(__bridge NSAttributedString *) text width:width height:height].size);
  }

  return result;
}
