#import <assert.h>
#import <bare.h>
#import <js.h>

#import <AppKit/AppKit.h>

#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h>

#import "bridging.h"

static js_value_t *
bare_app_kit_workspace_open_url(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSString *url = bare_app_kit__to_string(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    err = js_get_boolean(env, [[NSWorkspace sharedWorkspace] openURL:[NSURL URLWithString:url]], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_workspace_open_file(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSURL *path = bare_app_kit__to_url(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    err = js_get_boolean(env, [[NSWorkspace sharedWorkspace] openURL:path], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_workspace_select_file(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSURL *path = bare_app_kit__to_url(env, argv[0]);

  @autoreleasepool {
    [[NSWorkspace sharedWorkspace] activateFileViewerSelectingURLs:@[path]];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_workspace_icon_for_file(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSString *path = bare_app_kit__to_string(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [[NSWorkspace sharedWorkspace] iconForFile:path]);
  }

  return result;
}

static js_value_t *
bare_app_kit_workspace_url_for_application(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSString *identifier = bare_app_kit__to_string(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_app_kit__from_url(env, [[NSWorkspace sharedWorkspace] URLForApplicationWithBundleIdentifier:identifier]);
  }

  return result;
}

static js_value_t *
bare_app_kit_workspace_icon_for_content_type(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSString *identifier = bare_app_kit__to_string(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_foundation__bridge(env, [[NSWorkspace sharedWorkspace] iconForContentType:[UTType typeWithIdentifier:identifier]]);
  }

  return result;
}

static js_value_t *
bare_app_kit_workspace_is_file_package(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSString *path = bare_app_kit__to_string(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    err = js_get_boolean(env, [[NSWorkspace sharedWorkspace] isFilePackageAtPath:path], &result);
    assert(err == 0);
  }

  return result;
}

static js_value_t *
bare_app_kit_workspace_open_application(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSURL *path = bare_app_kit__to_url(env, argv[0]);

  @autoreleasepool {
    [[NSWorkspace sharedWorkspace] openApplicationAtURL:path configuration:[NSWorkspaceOpenConfiguration configuration] completionHandler:nil];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_workspace_hide_other_applications(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 0);

  @autoreleasepool {
    [[NSWorkspace sharedWorkspace] hideOtherApplications];
  }

  return NULL;
}

static js_value_t *
bare_app_kit_workspace_url_for_application_to_open_file(js_env_t *env, js_callback_info_t *info) {
  int err;

  size_t argc = 1;
  js_value_t *argv[1];

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  NSURL *path = bare_app_kit__to_url(env, argv[0]);

  js_value_t *result;

  @autoreleasepool {
    result = bare_app_kit__from_url(env, [[NSWorkspace sharedWorkspace] URLForApplicationToOpenURL:path]);
  }

  return result;
}
