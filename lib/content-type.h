#import <assert.h>
#import <bare.h>
#import <js.h>

#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>

#import "bridging.h"

// The ids below, the switch in `bare_app_kit_content_type_system()`, and the
// constants exported from `binding.m` are all expanded from this list.
#define BARE_APP_KIT_CONTENT_TYPES(V) \
  V(ITEM, UTTypeItem) \
  V(CONTENT, UTTypeContent) \
  V(DATA, UTTypeData) \
  V(DIRECTORY, UTTypeDirectory) \
  V(FOLDER, UTTypeFolder) \
  V(PACKAGE, UTTypePackage) \
  V(BUNDLE, UTTypeBundle) \
  V(APPLICATION, UTTypeApplication) \
  V(APPLICATION_BUNDLE, UTTypeApplicationBundle) \
  V(EXECUTABLE, UTTypeExecutable) \
  V(SYMBOLIC_LINK, UTTypeSymbolicLink) \
  V(ALIAS_FILE, UTTypeAliasFile) \
  V(VOLUME, UTTypeVolume) \
  V(DISK_IMAGE, UTTypeDiskImage) \
  V(URL, UTTypeURL) \
  V(FILE_URL, UTTypeFileURL) \
  V(TEXT, UTTypeText) \
  V(PLAIN_TEXT, UTTypePlainText) \
  V(UTF8_PLAIN_TEXT, UTTypeUTF8PlainText) \
  V(DELIMITED_TEXT, UTTypeDelimitedText) \
  V(COMMA_SEPARATED_TEXT, UTTypeCommaSeparatedText) \
  V(TAB_SEPARATED_TEXT, UTTypeTabSeparatedText) \
  V(RTF, UTTypeRTF) \
  V(HTML, UTTypeHTML) \
  V(XML, UTTypeXML) \
  V(YAML, UTTypeYAML) \
  V(JSON, UTTypeJSON) \
  V(PROPERTY_LIST, UTTypePropertyList) \
  V(SOURCE_CODE, UTTypeSourceCode) \
  V(C_SOURCE, UTTypeCSource) \
  V(C_HEADER, UTTypeCHeader) \
  V(OBJECTIVE_C_SOURCE, UTTypeObjectiveCSource) \
  V(SWIFT_SOURCE, UTTypeSwiftSource) \
  V(JAVASCRIPT, UTTypeJavaScript) \
  V(SHELL_SCRIPT, UTTypeShellScript) \
  V(PYTHON_SCRIPT, UTTypePythonScript) \
  V(MAKEFILE, UTTypeMakefile) \
  V(PDF, UTTypePDF) \
  V(EPUB, UTTypeEPUB) \
  V(WEB_ARCHIVE, UTTypeWebArchive) \
  V(IMAGE, UTTypeImage) \
  V(PNG, UTTypePNG) \
  V(JPEG, UTTypeJPEG) \
  V(GIF, UTTypeGIF) \
  V(TIFF, UTTypeTIFF) \
  V(BMP, UTTypeBMP) \
  V(ICNS, UTTypeICNS) \
  V(ICO, UTTypeICO) \
  V(SVG, UTTypeSVG) \
  V(WEBP, UTTypeWebP) \
  V(HEIC, UTTypeHEIC) \
  V(RAW_IMAGE, UTTypeRAWImage) \
  V(LIVE_PHOTO, UTTypeLivePhoto) \
  V(AUDIOVISUAL_CONTENT, UTTypeAudiovisualContent) \
  V(MOVIE, UTTypeMovie) \
  V(VIDEO, UTTypeVideo) \
  V(AUDIO, UTTypeAudio) \
  V(QUICKTIME_MOVIE, UTTypeQuickTimeMovie) \
  V(MPEG4_MOVIE, UTTypeMPEG4Movie) \
  V(MPEG4_AUDIO, UTTypeMPEG4Audio) \
  V(MP3, UTTypeMP3) \
  V(WAV, UTTypeWAV) \
  V(AIFF, UTTypeAIFF) \
  V(MIDI, UTTypeMIDI) \
  V(ARCHIVE, UTTypeArchive) \
  V(ZIP, UTTypeZIP) \
  V(GZIP, UTTypeGZIP) \
  V(SPREADSHEET, UTTypeSpreadsheet) \
  V(PRESENTATION, UTTypePresentation) \
  V(DATABASE, UTTypeDatabase) \
  V(FONT, UTTypeFont) \
  V(CONTACT, UTTypeContact) \
  V(VCARD, UTTypeVCard) \
  V(CALENDAR_EVENT, UTTypeCalendarEvent) \
  V(EMAIL_MESSAGE, UTTypeEmailMessage) \
  V(LOG, UTTypeLog)

// Types newer than the deployment target. They resolve to null on systems that
// predate them, so the JavaScript side sees `null` rather than a broken type.
#define BARE_APP_KIT_CONTENT_TYPES_AVAILABLE(V) \
  V(CSS, UTTypeCSS, 15.0) \
  V(TAR_ARCHIVE, UTTypeTarArchive, 15.0) \
  V(GEOJSON, UTTypeGeoJSON, 15.0) \
  V(MARKDOWN, UTTypeMarkdown, 27.0)

enum {
#define V(name, constant) bare_app_kit_content_type_##name,
  BARE_APP_KIT_CONTENT_TYPES(V)
#undef V
#define V(name, constant, macos) bare_app_kit_content_type_##name,
  BARE_APP_KIT_CONTENT_TYPES_AVAILABLE(V)
#undef V
};

static js_value_t *
bare_app_kit_content_type_system(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  int32_t id;
  if (!bare_app_kit__read_int32(env, argv[0], "id", &id)) return NULL;

  js_value_t *result;

  @autoreleasepool {
    UTType *type = nil;

    switch (id) {
#define V(name, constant) \
  case bare_app_kit_content_type_##name: \
    type = constant; \
    break;
      BARE_APP_KIT_CONTENT_TYPES(V)
#undef V
#define V(name, constant, macos) \
  case bare_app_kit_content_type_##name: \
    if (@available(macOS macos, *)) type = constant; \
    break;
      BARE_APP_KIT_CONTENT_TYPES_AVAILABLE(V)
#undef V
    }

    result = bare_foundation__bridge(env, type);
  }

  return result;
}

static js_value_t *
bare_app_kit_content_type_identifier(js_env_t *env, js_callback_info_t *info) {
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
    UTType *content_type = (__bridge UTType *) handle;

    result = bare_app_kit__from_string(env, content_type.identifier);
  }

  return result;
}

static js_value_t *
bare_app_kit_content_type_preferred_filename_extension(js_env_t *env, js_callback_info_t *info) {
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
    UTType *content_type = (__bridge UTType *) handle;

    result = bare_app_kit__from_string(env, content_type.preferredFilenameExtension);
  }

  return result;
}

static js_value_t *
bare_app_kit_content_type_preferred_mime_type(js_env_t *env, js_callback_info_t *info) {
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
    UTType *content_type = (__bridge UTType *) handle;

    result = bare_app_kit__from_string(env, content_type.preferredMIMEType);
  }

  return result;
}

static js_value_t *
bare_app_kit_content_type_localized_description(js_env_t *env, js_callback_info_t *info) {
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
    UTType *content_type = (__bridge UTType *) handle;

    result = bare_app_kit__from_string(env, content_type.localizedDescription);
  }

  return result;
}

static js_value_t *
bare_app_kit_content_type_dynamic(js_env_t *env, js_callback_info_t *info) {
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
    UTType *content_type = (__bridge UTType *) handle;

    err = js_get_boolean(env, content_type.dynamic, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_content_type_declared(js_env_t *env, js_callback_info_t *info) {
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
    UTType *content_type = (__bridge UTType *) handle;

    err = js_get_boolean(env, content_type.declared, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_content_type_public_type(js_env_t *env, js_callback_info_t *info) {
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
    UTType *content_type = (__bridge UTType *) handle;

    err = js_get_boolean(env, content_type.publicType, &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_content_type_with_identifier(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSString *identifier = bare_app_kit__to_string(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [UTType typeWithIdentifier:identifier]);
  }

  return result;
}

static js_value_t *
bare_app_kit_content_type_with_filename_extension(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSString *extension = bare_app_kit__to_string(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [UTType typeWithFilenameExtension:extension]);
  }

  return result;
}

static js_value_t *
bare_app_kit_content_type_with_mime_type(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSString *mime_type = bare_app_kit__to_string(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [UTType typeWithMIMEType:mime_type]);
  }

  return result;
}

static js_value_t *
bare_app_kit_content_type_conforms_to(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 2;
  js_value_t *argv[2];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 2);

  void *handle;
  if (!bare_foundation__read_tag(env, argv[0], "handle", &handle)) return NULL;

  id other = bare_foundation__to_object(env, argv[1]);

  js_value_t *result;

  @autoreleasepool {
    UTType *content_type = (__bridge UTType *) handle;

    err = js_get_boolean(env, [content_type conformsToType:other], &result);
    assert(err == 0);
  }

  return result;
}
