#import <assert.h>
#import <bare.h>
#import <js.h>
#import <utf.h>

#import <AppKit/AppKit.h>

#import "lib/alert.h"
#import "lib/appearance.h"
#import "lib/application.h"
#import "lib/attributed-string.h"
#import "lib/bezier-path.h"
#import "lib/box.h"
#import "lib/button.h"
#import "lib/clip-view.h"
#import "lib/collection-view-flow-layout.h"
#import "lib/collection-view-item.h"
#import "lib/collection-view.h"
#import "lib/color-panel.h"
#import "lib/color-well.h"
#import "lib/color.h"
#import "lib/combo-box.h"
#import "lib/combo-button.h"
#import "lib/content-type.h"
#import "lib/control.h"
#import "lib/cursor.h"
#import "lib/date-picker.h"
#import "lib/event.h"
#import "lib/font-descriptor.h"
#import "lib/font-panel.h"
#import "lib/font.h"
#import "lib/gradient.h"
#import "lib/graphics-context.h"
#import "lib/grid-cell.h"
#import "lib/grid-column.h"
#import "lib/grid-row.h"
#import "lib/grid-view.h"
#import "lib/image-view.h"
#import "lib/image.h"
#import "lib/layout-anchor.h"
#import "lib/layout-constraint.h"
#import "lib/level-indicator.h"
#import "lib/menu-item.h"
#import "lib/menu.h"
#import "lib/open-panel.h"
#import "lib/outline-view.h"
#import "lib/panel.h"
#import "lib/paragraph-style.h"
#import "lib/pasteboard.h"
#import "lib/path-control-item.h"
#import "lib/path-control.h"
#import "lib/pop-up-button.h"
#import "lib/progress-indicator.h"
#import "lib/save-panel.h"
#import "lib/screen.h"
#import "lib/scroll-view.h"
#import "lib/search-field.h"
#import "lib/secure-text-field.h"
#import "lib/segmented-control.h"
#import "lib/slider.h"
#import "lib/split-view.h"
#import "lib/stack-view.h"
#import "lib/status-item.h"
#import "lib/stepper.h"
#import "lib/switch.h"
#import "lib/tab-view-item.h"
#import "lib/tab-view.h"
#import "lib/table-column.h"
#import "lib/table-header-view.h"
#import "lib/table-view.h"
#import "lib/text-field.h"
#import "lib/text-view.h"
#import "lib/text-measurer.h"
#import "lib/text.h"
#import "lib/token-field.h"
#import "lib/toolbar-item.h"
#import "lib/toolbar-item-group.h"
#import "lib/toolbar.h"
#import "lib/tracking-separator-toolbar-item.h"
#import "lib/tracking-area.h"
#import "lib/undo-manager.h"
#import "lib/view.h"
#import "lib/visual-effect-view.h"
#import "lib/window.h"
#import "lib/workspace.h"

static js_value_t *
bare_app_kit_exports(js_env_t *env, js_value_t *exports) {
  int err;

  // A setter whose arguments are all primitives is registered with a typed
  // entry point as well. V8 calls it directly when the call site's types match
  // and falls back to the untyped function otherwise, which still serves the
  // getter.
#define T(name, fn, signature, typed) \
  { \
    js_value_t *val; \
    err = js_create_typed_function(env, name, -1, fn, signature, typed, NULL, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, exports, name, val); \
    assert(err == 0); \
  }

#define V(name, fn) \
  { \
    js_value_t *val; \
    err = js_create_function(env, name, -1, fn, NULL, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, exports, name, val); \
    assert(err == 0); \
  }

  V("alertInit", bare_app_kit_alert_init)
  V("alertMessageText", bare_app_kit_alert_message_text)
  V("alertInformativeText", bare_app_kit_alert_informative_text)
  T(
    "alertAlertStyle",
    bare_app_kit_alert_alert_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_alert_alert_style_typed
  )
  T(
    "alertShowsHelp",
    bare_app_kit_alert_shows_help,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_alert_shows_help_typed
  )
  T(
    "alertShowsSuppressionButton",
    bare_app_kit_alert_shows_suppression_button,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_alert_shows_suppression_button_typed
  )
  V("alertHelpAnchor", bare_app_kit_alert_help_anchor)
  V("alertIcon", bare_app_kit_alert_icon)
  V("alertAccessoryView", bare_app_kit_alert_accessory_view)
  V("alertSuppressionButton", bare_app_kit_alert_suppression_button)
  V("alertWindow", bare_app_kit_alert_window)
  V("alertButtons", bare_app_kit_alert_buttons)
  V("alertAddButtonWithTitle", bare_app_kit_alert_add_button_with_title)
  V("alertRunModal", bare_app_kit_alert_run_modal)
  V("alertBeginSheetModal", bare_app_kit_alert_begin_sheet_modal)

  V("appearanceName", bare_app_kit_appearance_name)
  V("appearanceNamed", bare_app_kit_appearance_named)
  V("appearanceCurrent", bare_app_kit_appearance_current)
  V("appearanceBestMatch", bare_app_kit_appearance_best_match)

  V("applicationMainMenu", bare_app_kit_application_main_menu)
  V("applicationActivate", bare_app_kit_application_activate)
  V("applicationActivationPolicy", bare_app_kit_application_activation_policy)
  V("applicationPresentationOptions", bare_app_kit_application_presentation_options)
  V("applicationApplicationIconImage", bare_app_kit_application_application_icon_image)
  V("applicationRunning", bare_app_kit_application_running)
  V("applicationActive", bare_app_kit_application_active)
  V("applicationHidden", bare_app_kit_application_hidden)
  V("applicationMainWindow", bare_app_kit_application_main_window)
  V("applicationKeyWindow", bare_app_kit_application_key_window)
  V("applicationWindowsMenu", bare_app_kit_application_windows_menu)
  V("applicationServicesMenu", bare_app_kit_application_services_menu)
  V("applicationHelpMenu", bare_app_kit_application_help_menu)
  V("applicationEffectiveAppearance", bare_app_kit_application_effective_appearance)
  V("applicationAppearance", bare_app_kit_application_appearance)
  V("applicationHide", bare_app_kit_application_hide)
  V("applicationUnhide", bare_app_kit_application_unhide)
  V("applicationUnhideAllApplications", bare_app_kit_application_unhide_all_applications)
  V("applicationTerminate", bare_app_kit_application_terminate)
  V("applicationArrangeInFront", bare_app_kit_application_arrange_in_front)
  V("applicationRequestUserAttention", bare_app_kit_application_request_user_attention)
  V("applicationCancelUserAttentionRequest", bare_app_kit_application_cancel_user_attention_request)
  V("applicationNumberOfWindows", bare_app_kit_application_number_of_windows)
  V("applicationWindowAt", bare_app_kit_application_window_at)
  V("applicationSetActivationPolicy", bare_app_kit_application_set_activation_policy)

  V("attributedStringInit", bare_app_kit_attributed_string_init)
  V("attributedStringString", bare_app_kit_attributed_string_string)
  V("attributedStringLength", bare_app_kit_attributed_string_length)
  V("attributedStringAttributesAt", bare_app_kit_attributed_string_attributes_at)
  V("attributedStringSetAttributes", bare_app_kit_attributed_string_set_attributes)
  V("attributedStringAddAttributes", bare_app_kit_attributed_string_add_attributes)
  V("attributedStringRemoveAttributes", bare_app_kit_attributed_string_remove_attributes)
  V("attributedStringAppend", bare_app_kit_attributed_string_append)
  V("attributedStringAppendString", bare_app_kit_attributed_string_append_string)
  V("attributedStringReplaceCharacters", bare_app_kit_attributed_string_replace_characters)
  V("attributedStringSubstring", bare_app_kit_attributed_string_substring)
  V("attributedStringBoundingRect", bare_app_kit_attributed_string_bounding_rect)
  V("attributedStringMeasure", bare_app_kit_attributed_string_measure)

  V("bezierPathInit", bare_app_kit_bezier_path_init)
  T(
    "bezierPathLineWidth",
    bare_app_kit_bezier_path_line_width,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_bezier_path_line_width_typed
  )
  T(
    "bezierPathLineCapStyle",
    bare_app_kit_bezier_path_line_cap_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_bezier_path_line_cap_style_typed
  )
  T(
    "bezierPathLineJoinStyle",
    bare_app_kit_bezier_path_line_join_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_bezier_path_line_join_style_typed
  )
  T(
    "bezierPathWindingRule",
    bare_app_kit_bezier_path_winding_rule,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_bezier_path_winding_rule_typed
  )
  T(
    "bezierPathMiterLimit",
    bare_app_kit_bezier_path_miter_limit,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_bezier_path_miter_limit_typed
  )
  T(
    "bezierPathFlatness",
    bare_app_kit_bezier_path_flatness,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_bezier_path_flatness_typed
  )
  V("bezierPathEmpty", bare_app_kit_bezier_path_empty)
  V("bezierPathElementCount", bare_app_kit_bezier_path_element_count)
  V("bezierPathBounds", bare_app_kit_bezier_path_bounds)
  V("bezierPathControlPointBounds", bare_app_kit_bezier_path_control_point_bounds)
  V("bezierPathCurrentPoint", bare_app_kit_bezier_path_current_point)
  V("bezierPathWithRect", bare_app_kit_bezier_path_with_rect)
  V("bezierPathWithOval", bare_app_kit_bezier_path_with_oval)
  V("bezierPathWithRoundedRect", bare_app_kit_bezier_path_with_rounded_rect)
  V("bezierPathMoveTo", bare_app_kit_bezier_path_move_to)
  V("bezierPathLineTo", bare_app_kit_bezier_path_line_to)
  V("bezierPathCurveTo", bare_app_kit_bezier_path_curve_to)
  V("bezierPathClosePath", bare_app_kit_bezier_path_close_path)
  V("bezierPathRemoveAllPoints", bare_app_kit_bezier_path_remove_all_points)
  V("bezierPathAppendRect", bare_app_kit_bezier_path_append_rect)
  V("bezierPathAppendOval", bare_app_kit_bezier_path_append_oval)
  V("bezierPathAppend", bare_app_kit_bezier_path_append)
  V("bezierPathStroke", bare_app_kit_bezier_path_stroke)
  V("bezierPathFill", bare_app_kit_bezier_path_fill)
  V("bezierPathAddClip", bare_app_kit_bezier_path_add_clip)
  V("bezierPathSetClip", bare_app_kit_bezier_path_set_clip)
  V("bezierPathContainsPoint", bare_app_kit_bezier_path_contains_point)
  T(
    "bezierPathBoundsInto",
    bare_app_kit_bezier_path_bounds_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_bezier_path_bounds_into_typed
  )
  T(
    "bezierPathControlPointBoundsInto",
    bare_app_kit_bezier_path_control_point_bounds_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_bezier_path_control_point_bounds_into_typed
  )
  T(
    "bezierPathCurrentPointInto",
    bare_app_kit_bezier_path_current_point_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_bezier_path_current_point_into_typed
  )

  V("boxInit", bare_app_kit_box_init)
  V("boxTitle", bare_app_kit_box_title)
  T(
    "boxTitlePosition",
    bare_app_kit_box_title_position,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_box_title_position_typed
  )
  T(
    "boxType",
    bare_app_kit_box_type,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_box_type_typed
  )
  T(
    "boxBorderWidth",
    bare_app_kit_box_border_width,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_box_border_width_typed
  )
  T(
    "boxCornerRadius",
    bare_app_kit_box_corner_radius,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_box_corner_radius_typed
  )
  T(
    "boxTransparent",
    bare_app_kit_box_transparent,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_box_transparent_typed
  )
  T(
    "boxContentViewMargins",
    bare_app_kit_box_content_view_margins,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_float64, js_float64},
    }),
    bare_app_kit_box_content_view_margins_typed
  )
  V("boxContentView", bare_app_kit_box_content_view)
  V("boxFillColor", bare_app_kit_box_fill_color)
  V("boxBorderColor", bare_app_kit_box_border_color)
  V("boxTitleFont", bare_app_kit_box_title_font)
  V("boxSizeToFit", bare_app_kit_box_size_to_fit)
  V("boxSetFrameFromContentFrame", bare_app_kit_box_set_frame_from_content_frame)
  T(
    "boxContentViewMarginsInto",
    bare_app_kit_box_content_view_margins_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_box_content_view_margins_into_typed
  )

  V("buttonInit", bare_app_kit_button_init)
  V("buttonTitle", bare_app_kit_button_title)
  V("buttonAlternateTitle", bare_app_kit_button_alternate_title)
  V("buttonState", bare_app_kit_button_state)
  V("buttonAllowsMixedState", bare_app_kit_button_allows_mixed_state)
  V("buttonBezelStyle", bare_app_kit_button_bezel_style)
  V("buttonBordered", bare_app_kit_button_bordered)
  V("buttonTransparent", bare_app_kit_button_transparent)
  V("buttonShowsBorderOnlyWhileMouseInside", bare_app_kit_button_shows_border_only_while_mouse_inside)
  V("buttonSpringLoaded", bare_app_kit_button_spring_loaded)
  V("buttonHasDestructiveAction", bare_app_kit_button_has_destructive_action)
  V("buttonKeyEquivalent", bare_app_kit_button_key_equivalent)
  V("buttonKeyEquivalentModifierMask", bare_app_kit_button_key_equivalent_modifier_mask)
  V("buttonSetButtonType", bare_app_kit_button_set_button_type)
  V("buttonSetNextState", bare_app_kit_button_set_next_state)
  V("buttonHighlight", bare_app_kit_button_highlight)
  V("buttonSetPeriodicDelay", bare_app_kit_button_set_periodic_delay)
  V("buttonGetPeriodicDelay", bare_app_kit_button_get_periodic_delay)
  V("buttonContentTintColor", bare_app_kit_button_content_tint_color)
  V("buttonBezelColor", bare_app_kit_button_bezel_color)
  V("buttonAttributedTitle", bare_app_kit_button_attributed_title)
  T(
    "buttonImagePosition",
    bare_app_kit_button_image_position,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_button_image_position_typed
  )
  T(
    "buttonImageScaling",
    bare_app_kit_button_image_scaling,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_button_image_scaling_typed
  )

  V("clipViewInit", bare_app_kit_clip_view_init)
  V("clipViewScrollToPoint", bare_app_kit_clip_view_scroll_to_point)
  V("clipViewDrawsBackground", bare_app_kit_clip_view_draws_background)
  V("clipViewBackgroundColor", bare_app_kit_clip_view_background_color)

  V("collectionViewInit", bare_app_kit_collection_view_init)
  V("collectionViewNumberOfSections", bare_app_kit_collection_view_number_of_sections)
  V("collectionViewCollectionViewLayout", bare_app_kit_collection_view_collection_view_layout)
  V("collectionViewBackgroundView", bare_app_kit_collection_view_background_view)
  V("collectionViewSelectable", bare_app_kit_collection_view_selectable)
  V("collectionViewAllowsEmptySelection", bare_app_kit_collection_view_allows_empty_selection)
  V("collectionViewAllowsMultipleSelection", bare_app_kit_collection_view_allows_multiple_selection)
  V("collectionViewBackgroundViewScrollsWithContent", bare_app_kit_collection_view_background_view_scrolls_with_content)
  V("collectionViewSelectionIndexPaths", bare_app_kit_collection_view_selection_index_paths)
  V("collectionViewReloadData", bare_app_kit_collection_view_reload_data)
  V("collectionViewDeselectAll", bare_app_kit_collection_view_deselect_all)
  V("collectionViewSelectItem", bare_app_kit_collection_view_select_item)
  V("collectionViewScrollToItem", bare_app_kit_collection_view_scroll_to_item)
  V("collectionViewItemAt", bare_app_kit_collection_view_item_at)
  V("collectionViewNumberOfItemsInSection", bare_app_kit_collection_view_number_of_items_in_section)

  V("collectionViewFlowLayoutInit", bare_app_kit_collection_view_flow_layout_init)
  T(
    "collectionViewFlowLayoutItemSize",
    bare_app_kit_collection_view_flow_layout_item_size,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_float64, js_float64},
    }),
    bare_app_kit_collection_view_flow_layout_item_size_typed
  )
  T(
    "collectionViewFlowLayoutEstimatedItemSize",
    bare_app_kit_collection_view_flow_layout_estimated_item_size,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_float64, js_float64},
    }),
    bare_app_kit_collection_view_flow_layout_estimated_item_size_typed
  )
  T(
    "collectionViewFlowLayoutMinimumLineSpacing",
    bare_app_kit_collection_view_flow_layout_minimum_line_spacing,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_collection_view_flow_layout_minimum_line_spacing_typed
  )
  T(
    "collectionViewFlowLayoutMinimumInteritemSpacing",
    bare_app_kit_collection_view_flow_layout_minimum_interitem_spacing,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_collection_view_flow_layout_minimum_interitem_spacing_typed
  )
  T(
    "collectionViewFlowLayoutSectionInset",
    bare_app_kit_collection_view_flow_layout_section_inset,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 6,
      .args = (int[]){js_object, js_int32, js_float64, js_float64, js_float64, js_float64},
    }),
    bare_app_kit_collection_view_flow_layout_section_inset_typed
  )
  T(
    "collectionViewFlowLayoutScrollDirection",
    bare_app_kit_collection_view_flow_layout_scroll_direction,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_collection_view_flow_layout_scroll_direction_typed
  )
  T(
    "collectionViewFlowLayoutHeaderReferenceSize",
    bare_app_kit_collection_view_flow_layout_header_reference_size,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_float64, js_float64},
    }),
    bare_app_kit_collection_view_flow_layout_header_reference_size_typed
  )
  T(
    "collectionViewFlowLayoutFooterReferenceSize",
    bare_app_kit_collection_view_flow_layout_footer_reference_size,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_float64, js_float64},
    }),
    bare_app_kit_collection_view_flow_layout_footer_reference_size_typed
  )
  T(
    "collectionViewFlowLayoutSectionHeadersPinToVisibleBounds",
    bare_app_kit_collection_view_flow_layout_section_headers_pin_to_visible_bounds,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_collection_view_flow_layout_section_headers_pin_to_visible_bounds_typed
  )
  T(
    "collectionViewFlowLayoutSectionFootersPinToVisibleBounds",
    bare_app_kit_collection_view_flow_layout_section_footers_pin_to_visible_bounds,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_collection_view_flow_layout_section_footers_pin_to_visible_bounds_typed
  )
  T(
    "collectionViewFlowLayoutItemSizeInto",
    bare_app_kit_collection_view_flow_layout_item_size_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_collection_view_flow_layout_item_size_into_typed
  )
  T(
    "collectionViewFlowLayoutEstimatedItemSizeInto",
    bare_app_kit_collection_view_flow_layout_estimated_item_size_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_collection_view_flow_layout_estimated_item_size_into_typed
  )
  T(
    "collectionViewFlowLayoutSectionInsetInto",
    bare_app_kit_collection_view_flow_layout_section_inset_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_collection_view_flow_layout_section_inset_into_typed
  )
  T(
    "collectionViewFlowLayoutHeaderReferenceSizeInto",
    bare_app_kit_collection_view_flow_layout_header_reference_size_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_collection_view_flow_layout_header_reference_size_into_typed
  )
  T(
    "collectionViewFlowLayoutFooterReferenceSizeInto",
    bare_app_kit_collection_view_flow_layout_footer_reference_size_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_collection_view_flow_layout_footer_reference_size_into_typed
  )

  V("collectionViewItemInit", bare_app_kit_collection_view_item_init)
  V("collectionViewItemView", bare_app_kit_collection_view_item_view)
  T(
    "collectionViewItemSelected",
    bare_app_kit_collection_view_item_selected,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_collection_view_item_selected_typed
  )
  T(
    "collectionViewItemHighlightState",
    bare_app_kit_collection_view_item_highlight_state,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_collection_view_item_highlight_state_typed
  )
  V("collectionViewItemImageView", bare_app_kit_collection_view_item_image_view)
  V("collectionViewItemTextField", bare_app_kit_collection_view_item_text_field)

  V("colorSystem", bare_app_kit_color_system)
  V("colorRGB", bare_app_kit_color_rgb)
  V("colorHSB", bare_app_kit_color_hsb)
  V("colorWhite", bare_app_kit_color_white)
  V("colorComponents", bare_app_kit_color_components)
  V("colorAlphaComponent", bare_app_kit_color_alpha_component)
  V("colorWithAlphaComponent", bare_app_kit_color_with_alpha_component)
  V("colorBlendedColor", bare_app_kit_color_blended_color)
  V("colorType", bare_app_kit_color_type)
  V("colorNumberOfComponents", bare_app_kit_color_number_of_components)
  V("colorWithPatternImage", bare_app_kit_color_with_pattern_image)
  V("colorHighlight", bare_app_kit_color_highlight)
  V("colorShadow", bare_app_kit_color_shadow)
  V("colorWithSystemEffect", bare_app_kit_color_with_system_effect)

  V("colorPanelInit", bare_app_kit_color_panel_init)
  V("colorPanelColor", bare_app_kit_color_panel_color)
  T(
    "colorPanelMode",
    bare_app_kit_color_panel_mode,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_color_panel_mode_typed
  )
  T(
    "colorPanelShowsAlpha",
    bare_app_kit_color_panel_shows_alpha,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_color_panel_shows_alpha_typed
  )
  T(
    "colorPanelContinuous",
    bare_app_kit_color_panel_continuous,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_color_panel_continuous_typed
  )
  V("colorPanelAccessoryView", bare_app_kit_color_panel_accessory_view)

  V("colorWellInit", bare_app_kit_color_well_init)
  V("colorWellColor", bare_app_kit_color_well_color)
  T(
    "colorWellBordered",
    bare_app_kit_color_well_bordered,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_color_well_bordered_typed
  )
  V("colorWellActive", bare_app_kit_color_well_active)
  T(
    "colorWellColorWellStyle",
    bare_app_kit_color_well_color_well_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_color_well_color_well_style_typed
  )
  V("colorWellImage", bare_app_kit_color_well_image)
  V("colorWellActivate", bare_app_kit_color_well_activate)
  V("colorWellDeactivate", bare_app_kit_color_well_deactivate)

  V("comboBoxInit", bare_app_kit_combo_box_init)
  V("comboBoxHasVerticalScroller", bare_app_kit_combo_box_has_vertical_scroller)
  V("comboBoxNumberOfVisibleItems", bare_app_kit_combo_box_number_of_visible_items)
  V("comboBoxUsesDataSource", bare_app_kit_combo_box_uses_data_source)
  V("comboBoxCompletes", bare_app_kit_combo_box_completes)
  V("comboBoxButtonBordered", bare_app_kit_combo_box_button_bordered)
  V("comboBoxItemHeight", bare_app_kit_combo_box_item_height)
  V("comboBoxIntercellSpacing", bare_app_kit_combo_box_intercell_spacing)
  V("comboBoxNumberOfItems", bare_app_kit_combo_box_number_of_items)
  V("comboBoxIndexOfSelectedItem", bare_app_kit_combo_box_index_of_selected_item)
  V("comboBoxObjectValueOfSelectedItem", bare_app_kit_combo_box_object_value_of_selected_item)
  V("comboBoxObjectValues", bare_app_kit_combo_box_object_values)
  V("comboBoxAddItemWithObjectValue", bare_app_kit_combo_box_add_item_with_object_value)
  V("comboBoxInsertItemWithObjectValue", bare_app_kit_combo_box_insert_item_with_object_value)
  V("comboBoxRemoveItemWithObjectValue", bare_app_kit_combo_box_remove_item_with_object_value)
  V("comboBoxRemoveItemAtIndex", bare_app_kit_combo_box_remove_item_at_index)
  V("comboBoxRemoveAllItems", bare_app_kit_combo_box_remove_all_items)
  V("comboBoxSelectItemAtIndex", bare_app_kit_combo_box_select_item_at_index)
  V("comboBoxDeselectItemAtIndex", bare_app_kit_combo_box_deselect_item_at_index)
  V("comboBoxSelectItemWithObjectValue", bare_app_kit_combo_box_select_item_with_object_value)
  V("comboBoxItemObjectValueAtIndex", bare_app_kit_combo_box_item_object_value_at_index)
  V("comboBoxIndexOfItemWithObjectValue", bare_app_kit_combo_box_index_of_item_with_object_value)
  V("comboBoxReloadData", bare_app_kit_combo_box_reload_data)
  V("comboBoxNoteNumberOfItemsChanged", bare_app_kit_combo_box_note_number_of_items_changed)
  V("comboBoxScrollItemAtIndexToTop", bare_app_kit_combo_box_scroll_item_at_index_to_top)
  V("comboBoxScrollItemAtIndexToVisible", bare_app_kit_combo_box_scroll_item_at_index_to_visible)

  V("comboButtonInit", bare_app_kit_combo_button_init)
  V("comboButtonTitle", bare_app_kit_combo_button_title)
  V("comboButtonImage", bare_app_kit_combo_button_image)
  T(
    "comboButtonImageScaling",
    bare_app_kit_combo_button_image_scaling,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_combo_button_image_scaling_typed
  )
  T(
    "comboButtonStyle",
    bare_app_kit_combo_button_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_combo_button_style_typed
  )
  V("comboButtonMenu", bare_app_kit_combo_button_menu)

  V("contentTypeSystem", bare_app_kit_content_type_system)
  V("contentTypeIdentifier", bare_app_kit_content_type_identifier)
  V("contentTypePreferredFilenameExtension", bare_app_kit_content_type_preferred_filename_extension)
  V("contentTypePreferredMIMEType", bare_app_kit_content_type_preferred_mime_type)
  V("contentTypeLocalizedDescription", bare_app_kit_content_type_localized_description)
  V("contentTypeDynamic", bare_app_kit_content_type_dynamic)
  V("contentTypeDeclared", bare_app_kit_content_type_declared)
  V("contentTypePublicType", bare_app_kit_content_type_public_type)
  V("contentTypeWithIdentifier", bare_app_kit_content_type_with_identifier)
  V("contentTypeWithFilenameExtension", bare_app_kit_content_type_with_filename_extension)
  V("contentTypeWithMIMEType", bare_app_kit_content_type_with_mime_type)
  V("contentTypeConformsTo", bare_app_kit_content_type_conforms_to)

  V("controlCurrentEditor", bare_app_kit_control_current_editor)
  V("controlEnabled", bare_app_kit_control_enabled)
  V("controlContinuous", bare_app_kit_control_continuous)
  V("controlIgnoresMultiClick", bare_app_kit_control_ignores_multi_click)
  V("controlHighlighted", bare_app_kit_control_highlighted)
  V("controlRefusesFirstResponder", bare_app_kit_control_refuses_first_responder)
  V("controlTag", bare_app_kit_control_tag)
  V("controlSize", bare_app_kit_control_size)
  V("controlStringValue", bare_app_kit_control_string_value)
  V("controlIntValue", bare_app_kit_control_int_value)
  V("controlIntegerValue", bare_app_kit_control_integer_value)
  V("controlFloatValue", bare_app_kit_control_float_value)
  V("controlDoubleValue", bare_app_kit_control_double_value)
  V("controlSizeToFit", bare_app_kit_control_size_to_fit)
  V("controlPerformClick", bare_app_kit_control_perform_click)
  V("controlFont", bare_app_kit_control_font)
  V("controlAttributedStringValue", bare_app_kit_control_attributed_string_value)
  T(
    "controlAlignment",
    bare_app_kit_control_alignment,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_control_alignment_typed
  )
  T(
    "controlLineBreakMode",
    bare_app_kit_control_line_break_mode,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_control_line_break_mode_typed
  )
  T(
    "controlUsesSingleLineMode",
    bare_app_kit_control_uses_single_line_mode,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_control_uses_single_line_mode_typed
  )

  V("cursorImage", bare_app_kit_cursor_image)
  V("cursorHotSpot", bare_app_kit_cursor_hot_spot)
  V("cursorSystem", bare_app_kit_cursor_system)
  V("cursorHide", bare_app_kit_cursor_hide)
  V("cursorUnhide", bare_app_kit_cursor_unhide)
  V("cursorPop", bare_app_kit_cursor_pop)
  V("cursorSet", bare_app_kit_cursor_set)
  V("cursorPush", bare_app_kit_cursor_push)

  V("datePickerInit", bare_app_kit_date_picker_init)
  V("datePickerDateValue", bare_app_kit_date_picker_date_value)
  V("datePickerMinDate", bare_app_kit_date_picker_min_date)
  V("datePickerMaxDate", bare_app_kit_date_picker_max_date)
  T(
    "datePickerTimeInterval",
    bare_app_kit_date_picker_time_interval,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_date_picker_time_interval_typed
  )
  T(
    "datePickerDatePickerStyle",
    bare_app_kit_date_picker_date_picker_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_date_picker_date_picker_style_typed
  )
  T(
    "datePickerDatePickerMode",
    bare_app_kit_date_picker_date_picker_mode,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_date_picker_date_picker_mode_typed
  )
  T(
    "datePickerDatePickerElements",
    bare_app_kit_date_picker_date_picker_elements,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_date_picker_date_picker_elements_typed
  )
  T(
    "datePickerDrawsBackground",
    bare_app_kit_date_picker_draws_background,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_date_picker_draws_background_typed
  )
  T(
    "datePickerBordered",
    bare_app_kit_date_picker_bordered,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_date_picker_bordered_typed
  )
  T(
    "datePickerBezeled",
    bare_app_kit_date_picker_bezeled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_date_picker_bezeled_typed
  )
  V("datePickerTextColor", bare_app_kit_date_picker_text_color)

  V("eventType", bare_app_kit_event_type)
  V("eventModifierFlags", bare_app_kit_event_modifier_flags)
  V("eventTimestamp", bare_app_kit_event_timestamp)
  V("eventWindowNumber", bare_app_kit_event_window_number)
  V("eventClickCount", bare_app_kit_event_click_count)
  V("eventButtonNumber", bare_app_kit_event_button_number)
  V("eventPressure", bare_app_kit_event_pressure)
  V("eventLocationInWindow", bare_app_kit_event_location_in_window)
  V("eventDeltaX", bare_app_kit_event_delta_x)
  V("eventDeltaY", bare_app_kit_event_delta_y)
  V("eventScrollingDeltaX", bare_app_kit_event_scrolling_delta_x)
  V("eventScrollingDeltaY", bare_app_kit_event_scrolling_delta_y)
  V("eventMagnification", bare_app_kit_event_magnification)
  V("eventCharacters", bare_app_kit_event_characters)
  V("eventCharactersIgnoringModifiers", bare_app_kit_event_characters_ignoring_modifiers)
  V("eventKeyCode", bare_app_kit_event_key_code)
  V("eventRepeat", bare_app_kit_event_repeat)
  V("eventCurrent", bare_app_kit_event_current)
  V("eventCurrentModifierFlags", bare_app_kit_event_current_modifier_flags)
  V("eventCurrentMouseLocation", bare_app_kit_event_current_mouse_location)
  V("eventCurrentPressedMouseButtons", bare_app_kit_event_current_pressed_mouse_buttons)
  V("eventDoubleClickInterval", bare_app_kit_event_double_click_interval)
  T(
    "eventLocationInWindowInto",
    bare_app_kit_event_location_in_window_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_event_location_in_window_into_typed
  )

  V("fontFontName", bare_app_kit_font_font_name)
  V("fontFamilyName", bare_app_kit_font_family_name)
  V("fontDisplayName", bare_app_kit_font_display_name)
  V("fontPointSize", bare_app_kit_font_point_size)
  V("fontAscender", bare_app_kit_font_ascender)
  V("fontDescender", bare_app_kit_font_descender)
  V("fontCapHeight", bare_app_kit_font_cap_height)
  V("fontXHeight", bare_app_kit_font_x_height)
  V("fontLeading", bare_app_kit_font_leading)
  V("fontItalicAngle", bare_app_kit_font_italic_angle)
  V("fontUnderlinePosition", bare_app_kit_font_underline_position)
  V("fontUnderlineThickness", bare_app_kit_font_underline_thickness)
  V("fontNumberOfGlyphs", bare_app_kit_font_number_of_glyphs)
  V("fontFixedPitch", bare_app_kit_font_fixed_pitch)
  V("fontBoundingRectForFont", bare_app_kit_font_bounding_rect_for_font)
  V("fontMaximumAdvancement", bare_app_kit_font_maximum_advancement)
  V("fontSystemFont", bare_app_kit_font_system_font)
  V("fontBoldSystemFont", bare_app_kit_font_bold_system_font)
  V("fontMonospacedSystemFont", bare_app_kit_font_monospaced_system_font)
  V("fontMonospacedDigitSystemFont", bare_app_kit_font_monospaced_digit_system_font)
  V("fontWithName", bare_app_kit_font_with_name)
  V("fontWithDescriptor", bare_app_kit_font_with_descriptor)
  V("fontFontDescriptor", bare_app_kit_font_font_descriptor)

  V("fontDescriptorSymbolicTraits", bare_app_kit_font_descriptor_symbolic_traits)
  V("fontDescriptorWithSymbolicTraits", bare_app_kit_font_descriptor_with_symbolic_traits)
  V("fontDescriptorWithFamily", bare_app_kit_font_descriptor_with_family)
  T(
    "fontBoundingRectForFontInto",
    bare_app_kit_font_bounding_rect_for_font_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_font_bounding_rect_for_font_into_typed
  )
  T(
    "fontMaximumAdvancementInto",
    bare_app_kit_font_maximum_advancement_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_font_maximum_advancement_into_typed
  )

  V("fontPanelInit", bare_app_kit_font_panel_init)
  T(
    "fontPanelEnabled",
    bare_app_kit_font_panel_enabled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_font_panel_enabled_typed
  )
  V("fontPanelAccessoryView", bare_app_kit_font_panel_accessory_view)
  V("fontPanelSetPanelFont", bare_app_kit_font_panel_set_panel_font)

  V("gradientInit", bare_app_kit_gradient_init)
  V("gradientNumberOfColorStops", bare_app_kit_gradient_number_of_color_stops)
  V("gradientDrawInRect", bare_app_kit_gradient_draw_in_rect)
  V("gradientDrawInPath", bare_app_kit_gradient_draw_in_path)
  V("gradientInterpolatedColorAt", bare_app_kit_gradient_interpolated_color_at)

  T(
    "graphicsContextShouldAntialias",
    bare_app_kit_graphics_context_should_antialias,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_graphics_context_should_antialias_typed
  )
  T(
    "graphicsContextImageInterpolation",
    bare_app_kit_graphics_context_image_interpolation,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_graphics_context_image_interpolation_typed
  )
  T(
    "graphicsContextCompositingOperation",
    bare_app_kit_graphics_context_compositing_operation,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_graphics_context_compositing_operation_typed
  )
  V("graphicsContextFlipped", bare_app_kit_graphics_context_flipped)
  V("graphicsContextCurrent", bare_app_kit_graphics_context_current)
  V("graphicsContextSave", bare_app_kit_graphics_context_save)
  V("graphicsContextRestore", bare_app_kit_graphics_context_restore)
  V("graphicsContextFlush", bare_app_kit_graphics_context_flush)

  V("gridCellContentView", bare_app_kit_grid_cell_content_view)
  T(
    "gridCellXPlacement",
    bare_app_kit_grid_cell_x_placement,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_grid_cell_x_placement_typed
  )
  T(
    "gridCellYPlacement",
    bare_app_kit_grid_cell_y_placement,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_grid_cell_y_placement_typed
  )
  T(
    "gridCellRowAlignment",
    bare_app_kit_grid_cell_row_alignment,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_grid_cell_row_alignment_typed
  )

  V("gridColumnNumberOfCells", bare_app_kit_grid_column_number_of_cells)
  T(
    "gridColumnWidth",
    bare_app_kit_grid_column_width,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_grid_column_width_typed
  )
  T(
    "gridColumnLeadingPadding",
    bare_app_kit_grid_column_leading_padding,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_grid_column_leading_padding_typed
  )
  T(
    "gridColumnTrailingPadding",
    bare_app_kit_grid_column_trailing_padding,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_grid_column_trailing_padding_typed
  )
  T(
    "gridColumnXPlacement",
    bare_app_kit_grid_column_x_placement,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_grid_column_x_placement_typed
  )
  T(
    "gridColumnHidden",
    bare_app_kit_grid_column_hidden,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_grid_column_hidden_typed
  )
  V("gridColumnCellAtIndex", bare_app_kit_grid_column_cell_at_index)
  V("gridColumnMergeCells", bare_app_kit_grid_column_merge_cells)

  V("gridRowNumberOfCells", bare_app_kit_grid_row_number_of_cells)
  T(
    "gridRowHeight",
    bare_app_kit_grid_row_height,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_grid_row_height_typed
  )
  T(
    "gridRowTopPadding",
    bare_app_kit_grid_row_top_padding,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_grid_row_top_padding_typed
  )
  T(
    "gridRowBottomPadding",
    bare_app_kit_grid_row_bottom_padding,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_grid_row_bottom_padding_typed
  )
  T(
    "gridRowYPlacement",
    bare_app_kit_grid_row_y_placement,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_grid_row_y_placement_typed
  )
  T(
    "gridRowRowAlignment",
    bare_app_kit_grid_row_row_alignment,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_grid_row_row_alignment_typed
  )
  T(
    "gridRowHidden",
    bare_app_kit_grid_row_hidden,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_grid_row_hidden_typed
  )
  V("gridRowCellAtIndex", bare_app_kit_grid_row_cell_at_index)
  V("gridRowMergeCells", bare_app_kit_grid_row_merge_cells)

  V("gridViewInit", bare_app_kit_grid_view_init)
  V("gridViewNumberOfRows", bare_app_kit_grid_view_number_of_rows)
  V("gridViewNumberOfColumns", bare_app_kit_grid_view_number_of_columns)
  T(
    "gridViewRowSpacing",
    bare_app_kit_grid_view_row_spacing,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_grid_view_row_spacing_typed
  )
  T(
    "gridViewColumnSpacing",
    bare_app_kit_grid_view_column_spacing,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_grid_view_column_spacing_typed
  )
  T(
    "gridViewXPlacement",
    bare_app_kit_grid_view_x_placement,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_grid_view_x_placement_typed
  )
  T(
    "gridViewYPlacement",
    bare_app_kit_grid_view_y_placement,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_grid_view_y_placement_typed
  )
  T(
    "gridViewRowAlignment",
    bare_app_kit_grid_view_row_alignment,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_grid_view_row_alignment_typed
  )
  V("gridViewAddRow", bare_app_kit_grid_view_add_row)
  V("gridViewInsertRow", bare_app_kit_grid_view_insert_row)
  V("gridViewRemoveRow", bare_app_kit_grid_view_remove_row)
  V("gridViewAddColumn", bare_app_kit_grid_view_add_column)
  V("gridViewInsertColumn", bare_app_kit_grid_view_insert_column)
  V("gridViewRemoveColumn", bare_app_kit_grid_view_remove_column)
  V("gridViewRowAtIndex", bare_app_kit_grid_view_row_at_index)
  V("gridViewColumnAtIndex", bare_app_kit_grid_view_column_at_index)
  V("gridViewCellAt", bare_app_kit_grid_view_cell_at)
  V("gridViewMergeCells", bare_app_kit_grid_view_merge_cells)

  T(
    "imageSize",
    bare_app_kit_image_size,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_float64, js_float64},
    }),
    bare_app_kit_image_size_typed
  )
  T(
    "imageTemplate",
    bare_app_kit_image_template,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_image_template_typed
  )
  V("imageName", bare_app_kit_image_name)
  V("imageValid", bare_app_kit_image_valid)
  T(
    "imageCacheMode",
    bare_app_kit_image_cache_mode,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_image_cache_mode_typed
  )
  T(
    "imageResizingMode",
    bare_app_kit_image_resizing_mode,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_image_resizing_mode_typed
  )
  T(
    "imageAlignmentRect",
    bare_app_kit_image_alignment_rect,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 6,
      .args = (int[]){js_object, js_int32, js_float64, js_float64, js_float64, js_float64},
    }),
    bare_app_kit_image_alignment_rect_typed
  )
  T(
    "imageMatchesOnMultipleResolution",
    bare_app_kit_image_matches_on_multiple_resolution,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_image_matches_on_multiple_resolution_typed
  )
  T(
    "imagePrefersColorMatch",
    bare_app_kit_image_prefers_color_match,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_image_prefers_color_match_typed
  )
  V("imageWithContentsOfFile", bare_app_kit_image_with_contents_of_file)
  V("imageNamed", bare_app_kit_image_named)
  V("imageWithSystemSymbolName", bare_app_kit_image_with_system_symbol_name)
  V("imageWithSize", bare_app_kit_image_with_size)
  V("imageLockFocus", bare_app_kit_image_lock_focus)
  V("imageUnlockFocus", bare_app_kit_image_unlock_focus)
  V("imageDrawInRect", bare_app_kit_image_draw_in_rect)
  V("imageDrawAtPoint", bare_app_kit_image_draw_at_point)
  V("imageTiffRepresentation", bare_app_kit_image_tiff_representation)
  V("imageRecommendedLayerContentsScale", bare_app_kit_image_recommended_layer_contents_scale)
  T(
    "imageSizeInto",
    bare_app_kit_image_size_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_image_size_into_typed
  )
  T(
    "imageAlignmentRectInto",
    bare_app_kit_image_alignment_rect_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_image_alignment_rect_into_typed
  )

  V("imageViewInit", bare_app_kit_image_view_init)
  V("imageViewImage", bare_app_kit_image_view_image)
  T(
    "imageViewImageScaling",
    bare_app_kit_image_view_image_scaling,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_image_view_image_scaling_typed
  )
  T(
    "imageViewImageAlignment",
    bare_app_kit_image_view_image_alignment,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_image_view_image_alignment_typed
  )
  T(
    "imageViewImageFrameStyle",
    bare_app_kit_image_view_image_frame_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_image_view_image_frame_style_typed
  )
  T(
    "imageViewEditable",
    bare_app_kit_image_view_editable,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_image_view_editable_typed
  )
  T(
    "imageViewAnimates",
    bare_app_kit_image_view_animates,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_image_view_animates_typed
  )
  V("imageViewContentTintColor", bare_app_kit_image_view_content_tint_color)

  V("layoutAnchorEqualTo", bare_app_kit_layout_anchor_equal_to)
  V("layoutAnchorGreaterThanOrEqualTo", bare_app_kit_layout_anchor_greater_than_or_equal_to)
  V("layoutAnchorLessThanOrEqualTo", bare_app_kit_layout_anchor_less_than_or_equal_to)
  V("layoutAnchorEqualToConstant", bare_app_kit_layout_anchor_equal_to_constant)
  V("layoutAnchorGreaterThanOrEqualToConstant", bare_app_kit_layout_anchor_greater_than_or_equal_to_constant)
  V("layoutAnchorLessThanOrEqualToConstant", bare_app_kit_layout_anchor_less_than_or_equal_to_constant)
  V("layoutAnchorEqualToMultiple", bare_app_kit_layout_anchor_equal_to_multiple)

  T(
    "layoutConstraintActive",
    bare_app_kit_layout_constraint_active,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_layout_constraint_active_typed
  )
  T(
    "layoutConstraintConstant",
    bare_app_kit_layout_constraint_constant,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_layout_constraint_constant_typed
  )
  T(
    "layoutConstraintPriority",
    bare_app_kit_layout_constraint_priority,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_layout_constraint_priority_typed
  )
  V("layoutConstraintIdentifier", bare_app_kit_layout_constraint_identifier)
  V("layoutConstraintMultiplier", bare_app_kit_layout_constraint_multiplier)
  V("layoutConstraintRelation", bare_app_kit_layout_constraint_relation)
  V("layoutConstraintFirstAttribute", bare_app_kit_layout_constraint_first_attribute)
  V("layoutConstraintSecondAttribute", bare_app_kit_layout_constraint_second_attribute)
  V("layoutConstraintActivate", bare_app_kit_layout_constraint_activate)
  V("layoutConstraintDeactivate", bare_app_kit_layout_constraint_deactivate)

  V("levelIndicatorInit", bare_app_kit_level_indicator_init)
  T(
    "levelIndicatorMinValue",
    bare_app_kit_level_indicator_min_value,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_level_indicator_min_value_typed
  )
  T(
    "levelIndicatorMaxValue",
    bare_app_kit_level_indicator_max_value,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_level_indicator_max_value_typed
  )
  T(
    "levelIndicatorWarningValue",
    bare_app_kit_level_indicator_warning_value,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_level_indicator_warning_value_typed
  )
  T(
    "levelIndicatorCriticalValue",
    bare_app_kit_level_indicator_critical_value,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_level_indicator_critical_value_typed
  )
  T(
    "levelIndicatorStyle",
    bare_app_kit_level_indicator_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_level_indicator_style_typed
  )
  T(
    "levelIndicatorNumberOfTickMarks",
    bare_app_kit_level_indicator_number_of_tick_marks,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_level_indicator_number_of_tick_marks_typed
  )
  T(
    "levelIndicatorNumberOfMajorTickMarks",
    bare_app_kit_level_indicator_number_of_major_tick_marks,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_level_indicator_number_of_major_tick_marks_typed
  )
  T(
    "levelIndicatorTickMarkPosition",
    bare_app_kit_level_indicator_tick_mark_position,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_level_indicator_tick_mark_position_typed
  )
  T(
    "levelIndicatorEditable",
    bare_app_kit_level_indicator_editable,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_level_indicator_editable_typed
  )
  V("levelIndicatorTickMarkValueAtIndex", bare_app_kit_level_indicator_tick_mark_value_at_index)

  V("menuInit", bare_app_kit_menu_init)
  V("menuTitle", bare_app_kit_menu_title)
  T(
    "menuAutoenablesItems",
    bare_app_kit_menu_autoenables_items,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_menu_autoenables_items_typed
  )
  T(
    "menuMinimumWidth",
    bare_app_kit_menu_minimum_width,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_menu_minimum_width_typed
  )
  T(
    "menuShowsStateColumn",
    bare_app_kit_menu_shows_state_column,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_menu_shows_state_column_typed
  )
  T(
    "menuAllowsContextMenuPlugIns",
    bare_app_kit_menu_allows_context_menu_plug_ins,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_menu_allows_context_menu_plug_ins_typed
  )
  V("menuSize", bare_app_kit_menu_size)
  V("menuHighlightedItem", bare_app_kit_menu_highlighted_item)
  V("menuSupermenu", bare_app_kit_menu_supermenu)
  V("menuFont", bare_app_kit_menu_font)
  V("menuNumberOfItems", bare_app_kit_menu_number_of_items)
  V("menuItems", bare_app_kit_menu_items)
  V("menuAddItem", bare_app_kit_menu_add_item)
  V("menuInsertItem", bare_app_kit_menu_insert_item)
  V("menuRemoveItem", bare_app_kit_menu_remove_item)
  V("menuRemoveItemAtIndex", bare_app_kit_menu_remove_item_at_index)
  V("menuRemoveAllItems", bare_app_kit_menu_remove_all_items)
  V("menuItemAtIndex", bare_app_kit_menu_item_at_index)
  V("menuIndexOfItem", bare_app_kit_menu_index_of_item)
  V("menuPopUpContextMenu", bare_app_kit_menu_pop_up_context_menu)
  V("menuPerformActionForItemAtIndex", bare_app_kit_menu_perform_action_for_item_at_index)
  V("menuCancelTracking", bare_app_kit_menu_cancel_tracking)
  V("menuUpdate", bare_app_kit_menu_update)
  V("menuIndexOfItemWithTitle", bare_app_kit_menu_index_of_item_with_title)
  V("menuIndexOfItemWithTag", bare_app_kit_menu_index_of_item_with_tag)
  T(
    "menuSizeInto",
    bare_app_kit_menu_size_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_menu_size_into_typed
  )

  V("menuItemInit", bare_app_kit_menu_item_init)
  V("menuItemTitle", bare_app_kit_menu_item_title)
  T(
    "menuItemEnabled",
    bare_app_kit_menu_item_enabled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_menu_item_enabled_typed
  )
  T(
    "menuItemHidden",
    bare_app_kit_menu_item_hidden,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_menu_item_hidden_typed
  )
  T(
    "menuItemState",
    bare_app_kit_menu_item_state,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_menu_item_state_typed
  )
  T(
    "menuItemTag",
    bare_app_kit_menu_item_tag,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_menu_item_tag_typed
  )
  V("menuItemToolTip", bare_app_kit_menu_item_tool_tip)
  T(
    "menuItemIndentationLevel",
    bare_app_kit_menu_item_indentation_level,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_menu_item_indentation_level_typed
  )
  V("menuItemKeyEquivalent", bare_app_kit_menu_item_key_equivalent)
  T(
    "menuItemKeyEquivalentModifierMask",
    bare_app_kit_menu_item_key_equivalent_modifier_mask,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_menu_item_key_equivalent_modifier_mask_typed
  )
  V("menuItemImage", bare_app_kit_menu_item_image)
  V("menuItemSubmenu", bare_app_kit_menu_item_submenu)
  V("menuItemAttributedTitle", bare_app_kit_menu_item_attributed_title)
  V("menuItemSeparatorItem", bare_app_kit_menu_item_separator_item)
  V("menuItemSeparator", bare_app_kit_menu_item_separator)

  V("openPanelInit", bare_app_kit_open_panel_init)
  V("openPanelUrls", bare_app_kit_open_panel_urls)
  T(
    "openPanelCanChooseFiles",
    bare_app_kit_open_panel_can_choose_files,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_open_panel_can_choose_files_typed
  )
  T(
    "openPanelCanChooseDirectories",
    bare_app_kit_open_panel_can_choose_directories,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_open_panel_can_choose_directories_typed
  )
  T(
    "openPanelAllowsMultipleSelection",
    bare_app_kit_open_panel_allows_multiple_selection,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_open_panel_allows_multiple_selection_typed
  )
  T(
    "openPanelResolvesAliases",
    bare_app_kit_open_panel_resolves_aliases,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_open_panel_resolves_aliases_typed
  )

  V("outlineViewInit", bare_app_kit_outline_view_init)
  V("outlineViewNumberOfRows", bare_app_kit_outline_view_number_of_rows)
  V("outlineViewIndentationPerLevel", bare_app_kit_outline_view_indentation_per_level)
  V("outlineViewIndentationMarkerFollowsCell", bare_app_kit_outline_view_indentation_marker_follows_cell)
  V("outlineViewAutoresizesOutlineColumn", bare_app_kit_outline_view_autoresizes_outline_column)
  V("outlineViewAutosaveExpandedItems", bare_app_kit_outline_view_autosave_expanded_items)
  V("outlineViewStronglyReferencesItems", bare_app_kit_outline_view_strongly_references_items)
  V("outlineViewOutlineTableColumn", bare_app_kit_outline_view_outline_table_column)
  V("outlineViewExpandItem", bare_app_kit_outline_view_expand_item)
  V("outlineViewCollapseItem", bare_app_kit_outline_view_collapse_item)
  V("outlineViewIsItemExpanded", bare_app_kit_outline_view_is_item_expanded)
  V("outlineViewReloadItem", bare_app_kit_outline_view_reload_item)
  V("outlineViewLevelForItem", bare_app_kit_outline_view_level_for_item)
  V("outlineViewRowForItem", bare_app_kit_outline_view_row_for_item)
  V("outlineViewItemAtRow", bare_app_kit_outline_view_item_at_row)
  V("outlineViewParentForItem", bare_app_kit_outline_view_parent_for_item)

  V("panelInit", bare_app_kit_panel_init)
  V("panelFloatingPanel", bare_app_kit_panel_floating_panel)
  V("panelBecomesKeyOnlyIfNeeded", bare_app_kit_panel_becomes_key_only_if_needed)

  V("paragraphStyleInit", bare_app_kit_paragraph_style_init)
  T(
    "paragraphStyleAlignment",
    bare_app_kit_paragraph_style_alignment,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_paragraph_style_alignment_typed
  )
  T(
    "paragraphStyleLineSpacing",
    bare_app_kit_paragraph_style_line_spacing,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_paragraph_style_line_spacing_typed
  )
  T(
    "paragraphStyleParagraphSpacing",
    bare_app_kit_paragraph_style_paragraph_spacing,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_paragraph_style_paragraph_spacing_typed
  )
  T(
    "paragraphStyleParagraphSpacingBefore",
    bare_app_kit_paragraph_style_paragraph_spacing_before,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_paragraph_style_paragraph_spacing_before_typed
  )
  T(
    "paragraphStyleFirstLineHeadIndent",
    bare_app_kit_paragraph_style_first_line_head_indent,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_paragraph_style_first_line_head_indent_typed
  )
  T(
    "paragraphStyleHeadIndent",
    bare_app_kit_paragraph_style_head_indent,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_paragraph_style_head_indent_typed
  )
  T(
    "paragraphStyleTailIndent",
    bare_app_kit_paragraph_style_tail_indent,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_paragraph_style_tail_indent_typed
  )
  T(
    "paragraphStyleLineHeightMultiple",
    bare_app_kit_paragraph_style_line_height_multiple,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_paragraph_style_line_height_multiple_typed
  )
  T(
    "paragraphStyleMinimumLineHeight",
    bare_app_kit_paragraph_style_minimum_line_height,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_paragraph_style_minimum_line_height_typed
  )
  T(
    "paragraphStyleMaximumLineHeight",
    bare_app_kit_paragraph_style_maximum_line_height,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_paragraph_style_maximum_line_height_typed
  )
  T(
    "paragraphStyleDefaultTabInterval",
    bare_app_kit_paragraph_style_default_tab_interval,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_paragraph_style_default_tab_interval_typed
  )
  T(
    "paragraphStyleHyphenationFactor",
    bare_app_kit_paragraph_style_hyphenation_factor,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_paragraph_style_hyphenation_factor_typed
  )
  T(
    "paragraphStyleLineBreakMode",
    bare_app_kit_paragraph_style_line_break_mode,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_paragraph_style_line_break_mode_typed
  )
  T(
    "paragraphStyleBaseWritingDirection",
    bare_app_kit_paragraph_style_base_writing_direction,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_paragraph_style_base_writing_direction_typed
  )
  T(
    "paragraphStyleAllowsDefaultTighteningForTruncation",
    bare_app_kit_paragraph_style_allows_default_tightening_for_truncation,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_paragraph_style_allows_default_tightening_for_truncation_typed
  )

  V("pasteboardName", bare_app_kit_pasteboard_name)
  V("pasteboardChangeCount", bare_app_kit_pasteboard_change_count)
  V("pasteboardTypes", bare_app_kit_pasteboard_types)
  V("pasteboardGeneral", bare_app_kit_pasteboard_general)
  V("pasteboardWithName", bare_app_kit_pasteboard_with_name)
  V("pasteboardWithUniqueName", bare_app_kit_pasteboard_with_unique_name)
  V("pasteboardClearContents", bare_app_kit_pasteboard_clear_contents)
  V("pasteboardSetString", bare_app_kit_pasteboard_set_string)
  V("pasteboardStringForType", bare_app_kit_pasteboard_string_for_type)
  V("pasteboardSetData", bare_app_kit_pasteboard_set_data)
  V("pasteboardDataForType", bare_app_kit_pasteboard_data_for_type)
  V("pasteboardAvailableTypeFrom", bare_app_kit_pasteboard_available_type_from)
  V("pasteboardDeclareTypes", bare_app_kit_pasteboard_declare_types)

  V("pathControlInit", bare_app_kit_path_control_init)
  V("pathControlUrl", bare_app_kit_path_control_url)
  T(
    "pathControlPathStyle",
    bare_app_kit_path_control_path_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_path_control_path_style_typed
  )
  T(
    "pathControlEditable",
    bare_app_kit_path_control_editable,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_path_control_editable_typed
  )
  V("pathControlPlaceholderString", bare_app_kit_path_control_placeholder_string)
  V("pathControlBackgroundColor", bare_app_kit_path_control_background_color)
  V("pathControlAllowedTypes", bare_app_kit_path_control_allowed_types)
  V("pathControlMenu", bare_app_kit_path_control_menu)
  V("pathControlSetPathItems", bare_app_kit_path_control_set_path_items)
  V("pathControlNumberOfPathItems", bare_app_kit_path_control_number_of_path_items)
  V("pathControlPathItemAt", bare_app_kit_path_control_path_item_at)
  V("pathControlClickedPathItem", bare_app_kit_path_control_clicked_path_item)

  V("pathControlItemInit", bare_app_kit_path_control_item_init)
  V("pathControlItemTitle", bare_app_kit_path_control_item_title)
  V("pathControlItemImage", bare_app_kit_path_control_item_image)
  V("pathControlItemUrl", bare_app_kit_path_control_item_url)
  V("pathControlItemAttributedTitle", bare_app_kit_path_control_item_attributed_title)

  V("popUpButtonInit", bare_app_kit_pop_up_button_init)
  T(
    "popUpButtonPullsDown",
    bare_app_kit_pop_up_button_pulls_down,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_pop_up_button_pulls_down_typed
  )
  T(
    "popUpButtonAutoenablesItems",
    bare_app_kit_pop_up_button_autoenables_items,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_pop_up_button_autoenables_items_typed
  )
  T(
    "popUpButtonPreferredEdge",
    bare_app_kit_pop_up_button_preferred_edge,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_pop_up_button_preferred_edge_typed
  )
  V("popUpButtonNumberOfItems", bare_app_kit_pop_up_button_number_of_items)
  V("popUpButtonIndexOfSelectedItem", bare_app_kit_pop_up_button_index_of_selected_item)
  V("popUpButtonTitleOfSelectedItem", bare_app_kit_pop_up_button_title_of_selected_item)
  V("popUpButtonMenu", bare_app_kit_pop_up_button_menu)
  V("popUpButtonItemTitles", bare_app_kit_pop_up_button_item_titles)
  V("popUpButtonAddItemWithTitle", bare_app_kit_pop_up_button_add_item_with_title)
  V("popUpButtonAddItemsWithTitles", bare_app_kit_pop_up_button_add_items_with_titles)
  V("popUpButtonInsertItemWithTitle", bare_app_kit_pop_up_button_insert_item_with_title)
  V("popUpButtonRemoveItemWithTitle", bare_app_kit_pop_up_button_remove_item_with_title)
  V("popUpButtonRemoveItemAtIndex", bare_app_kit_pop_up_button_remove_item_at_index)
  V("popUpButtonRemoveAllItems", bare_app_kit_pop_up_button_remove_all_items)
  V("popUpButtonSelectItemAtIndex", bare_app_kit_pop_up_button_select_item_at_index)
  V("popUpButtonSelectItemWithTitle", bare_app_kit_pop_up_button_select_item_with_title)
  V("popUpButtonItemTitleAtIndex", bare_app_kit_pop_up_button_item_title_at_index)
  V("popUpButtonIndexOfItemWithTitle", bare_app_kit_pop_up_button_index_of_item_with_title)
  V("popUpButtonSynchronizeTitleAndSelectedItem", bare_app_kit_pop_up_button_synchronize_title_and_selected_item)

  V("progressIndicatorInit", bare_app_kit_progress_indicator_init)
  T(
    "progressIndicatorMinValue",
    bare_app_kit_progress_indicator_min_value,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_progress_indicator_min_value_typed
  )
  T(
    "progressIndicatorMaxValue",
    bare_app_kit_progress_indicator_max_value,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_progress_indicator_max_value_typed
  )
  T(
    "progressIndicatorDoubleValue",
    bare_app_kit_progress_indicator_double_value,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_progress_indicator_double_value_typed
  )
  T(
    "progressIndicatorIndeterminate",
    bare_app_kit_progress_indicator_indeterminate,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_progress_indicator_indeterminate_typed
  )
  T(
    "progressIndicatorStyle",
    bare_app_kit_progress_indicator_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_progress_indicator_style_typed
  )
  T(
    "progressIndicatorControlSize",
    bare_app_kit_progress_indicator_control_size,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_progress_indicator_control_size_typed
  )
  T(
    "progressIndicatorUsesThreadedAnimation",
    bare_app_kit_progress_indicator_uses_threaded_animation,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_progress_indicator_uses_threaded_animation_typed
  )
  T(
    "progressIndicatorDisplayedWhenStopped",
    bare_app_kit_progress_indicator_displayed_when_stopped,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_progress_indicator_displayed_when_stopped_typed
  )
  V("progressIndicatorStartAnimation", bare_app_kit_progress_indicator_start_animation)
  V("progressIndicatorStopAnimation", bare_app_kit_progress_indicator_stop_animation)
  V("progressIndicatorIncrementBy", bare_app_kit_progress_indicator_increment_by)
  V("progressIndicatorSizeToFit", bare_app_kit_progress_indicator_size_to_fit)

  V("claim", bare_foundation_claim)
  V("wrapper", bare_foundation_wrapper)
  V("registrySize", bare_foundation_registry_size)
  V("eventMask", bare_app_kit_event_mask)
  V("handle", bare_foundation_handle)
  V("adopt", bare_foundation_adopt)

  V("savePanelInit", bare_app_kit_save_panel_init)
  V("savePanelUrl", bare_app_kit_save_panel_url)
  V("savePanelDirectoryURL", bare_app_kit_save_panel_directory_url)
  V("savePanelNameFieldStringValue", bare_app_kit_save_panel_name_field_string_value)
  V("savePanelNameFieldLabel", bare_app_kit_save_panel_name_field_label)
  V("savePanelMessage", bare_app_kit_save_panel_message)
  V("savePanelPrompt", bare_app_kit_save_panel_prompt)
  T(
    "savePanelCanCreateDirectories",
    bare_app_kit_save_panel_can_create_directories,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_save_panel_can_create_directories_typed
  )
  T(
    "savePanelCanSelectHiddenExtension",
    bare_app_kit_save_panel_can_select_hidden_extension,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_save_panel_can_select_hidden_extension_typed
  )
  T(
    "savePanelShowsHiddenFiles",
    bare_app_kit_save_panel_shows_hidden_files,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_save_panel_shows_hidden_files_typed
  )
  T(
    "savePanelShowsTagField",
    bare_app_kit_save_panel_shows_tag_field,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_save_panel_shows_tag_field_typed
  )
  T(
    "savePanelExtensionHidden",
    bare_app_kit_save_panel_extension_hidden,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_save_panel_extension_hidden_typed
  )
  T(
    "savePanelTreatsFilePackagesAsDirectories",
    bare_app_kit_save_panel_treats_file_packages_as_directories,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_save_panel_treats_file_packages_as_directories_typed
  )
  V("savePanelAccessoryView", bare_app_kit_save_panel_accessory_view)
  V("savePanelAllowedContentTypes", bare_app_kit_save_panel_allowed_content_types)
  V("savePanelRunModal", bare_app_kit_save_panel_run_modal)
  V("savePanelOk", bare_app_kit_save_panel_ok)
  V("savePanelCancel", bare_app_kit_save_panel_cancel)
  V("savePanelValidateVisibleColumns", bare_app_kit_save_panel_validate_visible_columns)

  V("screenFrame", bare_app_kit_screen_frame)
  V("screenVisibleFrame", bare_app_kit_screen_visible_frame)
  V("screenBackingScaleFactor", bare_app_kit_screen_backing_scale_factor)
  V("screenLocalizedName", bare_app_kit_screen_localized_name)
  V("screenSafeAreaInsets", bare_app_kit_screen_safe_area_insets)
  V("screenMaximumFramesPerSecond", bare_app_kit_screen_maximum_frames_per_second)
  V("screenMinimumRefreshInterval", bare_app_kit_screen_minimum_refresh_interval)
  V("screenMaximumRefreshInterval", bare_app_kit_screen_maximum_refresh_interval)
  V("screenDisplayUpdateGranularity", bare_app_kit_screen_display_update_granularity)
  V("screenAuxiliaryTopLeftArea", bare_app_kit_screen_auxiliary_top_left_area)
  V("screenAuxiliaryTopRightArea", bare_app_kit_screen_auxiliary_top_right_area)
  V("screenMaximumExtendedDynamicRangeColorComponentValue", bare_app_kit_screen_maximum_extended_dynamic_range_color_component_value)
  V("screenMain", bare_app_kit_screen_main)
  V("screenDeepest", bare_app_kit_screen_deepest)
  V("screenCount", bare_app_kit_screen_count)
  V("screenAt", bare_app_kit_screen_at)
  T(
    "screenFrameInto",
    bare_app_kit_screen_frame_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_screen_frame_into_typed
  )
  T(
    "screenVisibleFrameInto",
    bare_app_kit_screen_visible_frame_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_screen_visible_frame_into_typed
  )
  T(
    "screenSafeAreaInsetsInto",
    bare_app_kit_screen_safe_area_insets_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_screen_safe_area_insets_into_typed
  )
  T(
    "screenAuxiliaryTopLeftAreaInto",
    bare_app_kit_screen_auxiliary_top_left_area_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_screen_auxiliary_top_left_area_into_typed
  )
  T(
    "screenAuxiliaryTopRightAreaInto",
    bare_app_kit_screen_auxiliary_top_right_area_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_screen_auxiliary_top_right_area_into_typed
  )

  V("scrollViewInit", bare_app_kit_scroll_view_init)
  V("scrollViewContentView", bare_app_kit_scroll_view_content_view)
  V("scrollViewReflectScrolledClipView", bare_app_kit_scroll_view_reflect_scrolled_clip_view)
  V("scrollViewDocumentView", bare_app_kit_scroll_view_document_view)
  T(
    "scrollViewHasVerticalScroller",
    bare_app_kit_scroll_view_has_vertical_scroller,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_scroll_view_has_vertical_scroller_typed
  )
  T(
    "scrollViewHasHorizontalScroller",
    bare_app_kit_scroll_view_has_horizontal_scroller,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_scroll_view_has_horizontal_scroller_typed
  )
  T(
    "scrollViewAutohidesScrollers",
    bare_app_kit_scroll_view_autohides_scrollers,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_scroll_view_autohides_scrollers_typed
  )
  T(
    "scrollViewBorderType",
    bare_app_kit_scroll_view_border_type,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_scroll_view_border_type_typed
  )
  T(
    "scrollViewScrollerStyle",
    bare_app_kit_scroll_view_scroller_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_scroll_view_scroller_style_typed
  )
  T(
    "scrollViewDrawsBackground",
    bare_app_kit_scroll_view_draws_background,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_scroll_view_draws_background_typed
  )
  V("scrollViewBackgroundColor", bare_app_kit_scroll_view_background_color)
  T(
    "scrollViewAllowsMagnification",
    bare_app_kit_scroll_view_allows_magnification,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_scroll_view_allows_magnification_typed
  )
  T(
    "scrollViewMagnification",
    bare_app_kit_scroll_view_magnification,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_scroll_view_magnification_typed
  )
  T(
    "scrollViewHorizontalScrollElasticity",
    bare_app_kit_scroll_view_horizontal_scroll_elasticity,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_scroll_view_horizontal_scroll_elasticity_typed
  )
  T(
    "scrollViewVerticalScrollElasticity",
    bare_app_kit_scroll_view_vertical_scroll_elasticity,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_scroll_view_vertical_scroll_elasticity_typed
  )
  V("scrollViewContentSize", bare_app_kit_scroll_view_content_size)
  V("scrollViewDocumentVisibleRect", bare_app_kit_scroll_view_document_visible_rect)
  T(
    "scrollViewRulersVisible",
    bare_app_kit_scroll_view_rulers_visible,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_scroll_view_rulers_visible_typed
  )
  T(
    "scrollViewHasHorizontalRuler",
    bare_app_kit_scroll_view_has_horizontal_ruler,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_scroll_view_has_horizontal_ruler_typed
  )
  T(
    "scrollViewHasVerticalRuler",
    bare_app_kit_scroll_view_has_vertical_ruler,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_scroll_view_has_vertical_ruler_typed
  )
  T(
    "scrollViewScrollsDynamically",
    bare_app_kit_scroll_view_scrolls_dynamically,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_scroll_view_scrolls_dynamically_typed
  )
  T(
    "scrollViewLineScroll",
    bare_app_kit_scroll_view_line_scroll,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_scroll_view_line_scroll_typed
  )
  T(
    "scrollViewPageScroll",
    bare_app_kit_scroll_view_page_scroll,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_scroll_view_page_scroll_typed
  )
  T(
    "scrollViewHorizontalLineScroll",
    bare_app_kit_scroll_view_horizontal_line_scroll,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_scroll_view_horizontal_line_scroll_typed
  )
  T(
    "scrollViewVerticalLineScroll",
    bare_app_kit_scroll_view_vertical_line_scroll,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_scroll_view_vertical_line_scroll_typed
  )
  T(
    "scrollViewHorizontalPageScroll",
    bare_app_kit_scroll_view_horizontal_page_scroll,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_scroll_view_horizontal_page_scroll_typed
  )
  T(
    "scrollViewVerticalPageScroll",
    bare_app_kit_scroll_view_vertical_page_scroll,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_scroll_view_vertical_page_scroll_typed
  )
  T(
    "scrollViewAutomaticallyAdjustsContentInsets",
    bare_app_kit_scroll_view_automatically_adjusts_content_insets,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_scroll_view_automatically_adjusts_content_insets_typed
  )
  T(
    "scrollViewContentInsets",
    bare_app_kit_scroll_view_content_insets,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 6,
      .args = (int[]){js_object, js_int32, js_float64, js_float64, js_float64, js_float64},
    }),
    bare_app_kit_scroll_view_content_insets_typed
  )
  T(
    "scrollViewScrollerInsets",
    bare_app_kit_scroll_view_scroller_insets,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 6,
      .args = (int[]){js_object, js_int32, js_float64, js_float64, js_float64, js_float64},
    }),
    bare_app_kit_scroll_view_scroller_insets_typed
  )
  T(
    "scrollViewFindBarPosition",
    bare_app_kit_scroll_view_find_bar_position,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_scroll_view_find_bar_position_typed
  )
  T(
    "scrollViewMinMagnification",
    bare_app_kit_scroll_view_min_magnification,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_scroll_view_min_magnification_typed
  )
  T(
    "scrollViewMaxMagnification",
    bare_app_kit_scroll_view_max_magnification,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_scroll_view_max_magnification_typed
  )
  V("scrollViewFlashScrollers", bare_app_kit_scroll_view_flash_scrollers)
  T(
    "scrollViewContentSizeInto",
    bare_app_kit_scroll_view_content_size_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_scroll_view_content_size_into_typed
  )
  T(
    "scrollViewDocumentVisibleRectInto",
    bare_app_kit_scroll_view_document_visible_rect_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_scroll_view_document_visible_rect_into_typed
  )
  T(
    "scrollViewContentInsetsInto",
    bare_app_kit_scroll_view_content_insets_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_scroll_view_content_insets_into_typed
  )
  T(
    "scrollViewScrollerInsetsInto",
    bare_app_kit_scroll_view_scroller_insets_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_scroll_view_scroller_insets_into_typed
  )

  V("searchFieldInit", bare_app_kit_search_field_init)
  T(
    "searchFieldSendsSearchStringImmediately",
    bare_app_kit_search_field_sends_search_string_immediately,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_search_field_sends_search_string_immediately_typed
  )
  T(
    "searchFieldSendsWholeSearchString",
    bare_app_kit_search_field_sends_whole_search_string,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_search_field_sends_whole_search_string_typed
  )
  T(
    "searchFieldMaximumRecents",
    bare_app_kit_search_field_maximum_recents,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_search_field_maximum_recents_typed
  )
  V("searchFieldRecentsAutosaveName", bare_app_kit_search_field_recents_autosave_name)
  V("searchFieldRecentSearches", bare_app_kit_search_field_recent_searches)

  V("secureTextFieldInit", bare_app_kit_secure_text_field_init)

  V("segmentedControlInit", bare_app_kit_segmented_control_init)
  T(
    "segmentedControlSegmentCount",
    bare_app_kit_segmented_control_segment_count,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_segmented_control_segment_count_typed
  )
  T(
    "segmentedControlSelectedSegment",
    bare_app_kit_segmented_control_selected_segment,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_segmented_control_selected_segment_typed
  )
  T(
    "segmentedControlSegmentStyle",
    bare_app_kit_segmented_control_segment_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_segmented_control_segment_style_typed
  )
  T(
    "segmentedControlTrackingMode",
    bare_app_kit_segmented_control_tracking_mode,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_segmented_control_tracking_mode_typed
  )
  T(
    "segmentedControlSegmentDistribution",
    bare_app_kit_segmented_control_segment_distribution,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_segmented_control_segment_distribution_typed
  )
  V("segmentedControlSetLabelForSegment", bare_app_kit_segmented_control_set_label_for_segment)
  V("segmentedControlLabelForSegment", bare_app_kit_segmented_control_label_for_segment)
  V("segmentedControlSetWidthForSegment", bare_app_kit_segmented_control_set_width_for_segment)
  V("segmentedControlWidthForSegment", bare_app_kit_segmented_control_width_for_segment)
  V("segmentedControlSetSelectedForSegment", bare_app_kit_segmented_control_set_selected_for_segment)
  V("segmentedControlSelectedForSegment", bare_app_kit_segmented_control_selected_for_segment)
  V("segmentedControlSetEnabledForSegment", bare_app_kit_segmented_control_set_enabled_for_segment)
  V("segmentedControlEnabledForSegment", bare_app_kit_segmented_control_enabled_for_segment)
  V("segmentedControlSetToolTipForSegment", bare_app_kit_segmented_control_set_tool_tip_for_segment)
  V("segmentedControlToolTipForSegment", bare_app_kit_segmented_control_tool_tip_for_segment)
  V("segmentedControlSetTagForSegment", bare_app_kit_segmented_control_set_tag_for_segment)
  V("segmentedControlTagForSegment", bare_app_kit_segmented_control_tag_for_segment)

  V("sliderInit", bare_app_kit_slider_init)
  V("sliderMinValue", bare_app_kit_slider_min_value)
  V("sliderMaxValue", bare_app_kit_slider_max_value)
  V("sliderAltIncrementValue", bare_app_kit_slider_alt_increment_value)
  V("sliderKnobThickness", bare_app_kit_slider_knob_thickness)
  V("sliderVertical", bare_app_kit_slider_vertical)
  V("sliderType", bare_app_kit_slider_type)
  V("sliderNumberOfTickMarks", bare_app_kit_slider_number_of_tick_marks)
  V("sliderTickMarkPosition", bare_app_kit_slider_tick_mark_position)
  V("sliderAllowsTickMarkValuesOnly", bare_app_kit_slider_allows_tick_mark_values_only)
  V("sliderTickMarkValueAtIndex", bare_app_kit_slider_tick_mark_value_at_index)
  V("sliderClosestTickMarkValueToValue", bare_app_kit_slider_closest_tick_mark_value_to_value)

  V("splitViewInit", bare_app_kit_split_view_init)
  T(
    "splitViewVertical",
    bare_app_kit_split_view_vertical,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_split_view_vertical_typed
  )
  T(
    "splitViewDividerStyle",
    bare_app_kit_split_view_divider_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_split_view_divider_style_typed
  )
  T(
    "splitViewArrangesAllSubviews",
    bare_app_kit_split_view_arranges_all_subviews,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_split_view_arranges_all_subviews_typed
  )
  V("splitViewDividerThickness", bare_app_kit_split_view_divider_thickness)
  V("splitViewArrangedSubviews", bare_app_kit_split_view_arranged_subviews)
  V("splitViewAddArrangedSubview", bare_app_kit_split_view_add_arranged_subview)
  V("splitViewInsertArrangedSubview", bare_app_kit_split_view_insert_arranged_subview)
  V("splitViewRemoveArrangedSubview", bare_app_kit_split_view_remove_arranged_subview)
  V("splitViewSetPosition", bare_app_kit_split_view_set_position)
  V("splitViewSetHoldingPriority", bare_app_kit_split_view_set_holding_priority)
  V("splitViewHoldingPriorityForSubviewAtIndex", bare_app_kit_split_view_holding_priority_for_subview_at_index)
  V("splitViewAdjustSubviews", bare_app_kit_split_view_adjust_subviews)

  V("stackViewInit", bare_app_kit_stack_view_init)
  T(
    "stackViewOrientation",
    bare_app_kit_stack_view_orientation,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_stack_view_orientation_typed
  )
  T(
    "stackViewAlignment",
    bare_app_kit_stack_view_alignment,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_stack_view_alignment_typed
  )
  T(
    "stackViewDistribution",
    bare_app_kit_stack_view_distribution,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_stack_view_distribution_typed
  )
  T(
    "stackViewSpacing",
    bare_app_kit_stack_view_spacing,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_stack_view_spacing_typed
  )
  T(
    "stackViewEdgeInsets",
    bare_app_kit_stack_view_edge_insets,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 6,
      .args = (int[]){js_object, js_int32, js_float64, js_float64, js_float64, js_float64},
    }),
    bare_app_kit_stack_view_edge_insets_typed
  )
  T(
    "stackViewDetachesHiddenViews",
    bare_app_kit_stack_view_detaches_hidden_views,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_stack_view_detaches_hidden_views_typed
  )
  V("stackViewArrangedSubviews", bare_app_kit_stack_view_arranged_subviews)
  V("stackViewAddArrangedSubview", bare_app_kit_stack_view_add_arranged_subview)
  V("stackViewInsertArrangedSubview", bare_app_kit_stack_view_insert_arranged_subview)
  V("stackViewRemoveArrangedSubview", bare_app_kit_stack_view_remove_arranged_subview)
  V("stackViewRemoveView", bare_app_kit_stack_view_remove_view)
  V("stackViewSetVisibilityPriority", bare_app_kit_stack_view_set_visibility_priority)
  V("stackViewSetCustomSpacing", bare_app_kit_stack_view_set_custom_spacing)
  T(
    "stackViewEdgeInsetsInto",
    bare_app_kit_stack_view_edge_insets_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_stack_view_edge_insets_into_typed
  )

  V("statusItemInit", bare_app_kit_status_item_init)
  T(
    "statusItemLength",
    bare_app_kit_status_item_length,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_status_item_length_typed
  )
  T(
    "statusItemVisible",
    bare_app_kit_status_item_visible,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_status_item_visible_typed
  )
  V("statusItemMenu", bare_app_kit_status_item_menu)
  V("statusItemButton", bare_app_kit_status_item_button)

  V("stepperInit", bare_app_kit_stepper_init)
  T(
    "stepperMinValue",
    bare_app_kit_stepper_min_value,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_stepper_min_value_typed
  )
  T(
    "stepperMaxValue",
    bare_app_kit_stepper_max_value,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_stepper_max_value_typed
  )
  T(
    "stepperIncrement",
    bare_app_kit_stepper_increment,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_stepper_increment_typed
  )
  T(
    "stepperValueWraps",
    bare_app_kit_stepper_value_wraps,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_stepper_value_wraps_typed
  )
  T(
    "stepperAutorepeat",
    bare_app_kit_stepper_autorepeat,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_stepper_autorepeat_typed
  )

  V("switchInit", bare_app_kit_switch_init)
  V("switchState", bare_app_kit_switch_state)

  V("tabViewInit", bare_app_kit_tab_view_init)
  V("tabViewTabViewType", bare_app_kit_tab_view_tab_view_type)
  V("tabViewTabPosition", bare_app_kit_tab_view_tab_position)
  V("tabViewFont", bare_app_kit_tab_view_font)
  V("tabViewNumberOfTabViewItems", bare_app_kit_tab_view_number_of_tab_view_items)
  V("tabViewAllowsTruncatedLabels", bare_app_kit_tab_view_allows_truncated_labels)
  V("tabViewDrawsBackground", bare_app_kit_tab_view_draws_background)
  V("tabViewControlSize", bare_app_kit_tab_view_control_size)
  V("tabViewTabViewBorderType", bare_app_kit_tab_view_tab_view_border_type)
  V("tabViewContentRect", bare_app_kit_tab_view_content_rect)
  V("tabViewMinimumSize", bare_app_kit_tab_view_minimum_size)
  V("tabViewIndexOfSelectedTabViewItem", bare_app_kit_tab_view_index_of_selected_tab_view_item)
  V("tabViewTabViewItems", bare_app_kit_tab_view_tab_view_items)
  V("tabViewAddTabViewItem", bare_app_kit_tab_view_add_tab_view_item)
  V("tabViewInsertTabViewItem", bare_app_kit_tab_view_insert_tab_view_item)
  V("tabViewRemoveTabViewItem", bare_app_kit_tab_view_remove_tab_view_item)
  V("tabViewSelectTabViewItemAtIndex", bare_app_kit_tab_view_select_tab_view_item_at_index)
  V("tabViewIndexOfTabViewItem", bare_app_kit_tab_view_index_of_tab_view_item)

  V("tabViewItemInit", bare_app_kit_tab_view_item_init)
  V("tabViewItemLabel", bare_app_kit_tab_view_item_label)
  V("tabViewItemToolTip", bare_app_kit_tab_view_item_tool_tip)
  V("tabViewItemView", bare_app_kit_tab_view_item_view)
  V("tabViewItemImage", bare_app_kit_tab_view_item_image)

  V("tableColumnInit", bare_app_kit_table_column_init)
  V("tableColumnIdentifier", bare_app_kit_table_column_identifier)
  V("tableColumnTitle", bare_app_kit_table_column_title)
  T(
    "tableColumnWidth",
    bare_app_kit_table_column_width,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_table_column_width_typed
  )
  T(
    "tableColumnMinWidth",
    bare_app_kit_table_column_min_width,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_table_column_min_width_typed
  )
  T(
    "tableColumnMaxWidth",
    bare_app_kit_table_column_max_width,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_table_column_max_width_typed
  )
  T(
    "tableColumnResizingMask",
    bare_app_kit_table_column_resizing_mask,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_table_column_resizing_mask_typed
  )
  T(
    "tableColumnEditable",
    bare_app_kit_table_column_editable,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_table_column_editable_typed
  )
  T(
    "tableColumnHidden",
    bare_app_kit_table_column_hidden,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_table_column_hidden_typed
  )
  V("tableColumnSizeToFit", bare_app_kit_table_column_size_to_fit)

  V("tableHeaderViewInit", bare_app_kit_table_header_view_init)
  V("tableHeaderViewDraggedColumn", bare_app_kit_table_header_view_dragged_column)
  V("tableHeaderViewResizedColumn", bare_app_kit_table_header_view_resized_column)
  V("tableHeaderViewDraggedDistance", bare_app_kit_table_header_view_dragged_distance)
  V("tableHeaderViewColumnAtPoint", bare_app_kit_table_header_view_column_at_point)
  V("tableHeaderViewHeaderRectOfColumn", bare_app_kit_table_header_view_header_rect_of_column)

  V("tableViewInit", bare_app_kit_table_view_init)
  V("tableViewNumberOfRows", bare_app_kit_table_view_number_of_rows)
  V("tableViewRowHeight", bare_app_kit_table_view_row_height)
  V("tableViewIntercellSpacing", bare_app_kit_table_view_intercell_spacing)
  V("tableViewUsesAlternatingRowBackgroundColors", bare_app_kit_table_view_uses_alternating_row_background_colors)
  V("tableViewUsesAutomaticRowHeights", bare_app_kit_table_view_uses_automatic_row_heights)
  V("tableViewAllowsMultipleSelection", bare_app_kit_table_view_allows_multiple_selection)
  V("tableViewAllowsEmptySelection", bare_app_kit_table_view_allows_empty_selection)
  V("tableViewAllowsColumnReordering", bare_app_kit_table_view_allows_column_reordering)
  V("tableViewAllowsColumnResizing", bare_app_kit_table_view_allows_column_resizing)
  V("tableViewAllowsColumnSelection", bare_app_kit_table_view_allows_column_selection)
  V("tableViewStyle", bare_app_kit_table_view_style)
  V("tableViewGridStyleMask", bare_app_kit_table_view_grid_style_mask)
  V("tableViewRowSizeStyle", bare_app_kit_table_view_row_size_style)
  V("tableViewColumnAutoresizingStyle", bare_app_kit_table_view_column_autoresizing_style)
  V("tableViewBackgroundColor", bare_app_kit_table_view_background_color)
  V("tableViewGridColor", bare_app_kit_table_view_grid_color)
  V("tableViewHeaderView", bare_app_kit_table_view_header_view)
  V("tableViewNumberOfColumns", bare_app_kit_table_view_number_of_columns)
  V("tableViewSelectedRow", bare_app_kit_table_view_selected_row)
  V("tableViewSelectedColumn", bare_app_kit_table_view_selected_column)
  V("tableViewClickedRow", bare_app_kit_table_view_clicked_row)
  V("tableViewClickedColumn", bare_app_kit_table_view_clicked_column)
  V("tableViewNumberOfSelectedRows", bare_app_kit_table_view_number_of_selected_rows)
  V("tableViewReloadData", bare_app_kit_table_view_reload_data)
  V("tableViewColumns", bare_app_kit_table_view_columns)
  V("tableViewAddTableColumn", bare_app_kit_table_view_add_table_column)
  V("tableViewRemoveTableColumn", bare_app_kit_table_view_remove_table_column)
  V("tableViewMoveColumn", bare_app_kit_table_view_move_column)
  V("tableViewSelectRow", bare_app_kit_table_view_select_row)
  V("tableViewDeselectRow", bare_app_kit_table_view_deselect_row)
  V("tableViewDeselectAll", bare_app_kit_table_view_deselect_all)
  V("tableViewSelectAll", bare_app_kit_table_view_select_all)
  V("tableViewIsRowSelected", bare_app_kit_table_view_is_row_selected)
  V("tableViewScrollRowToVisible", bare_app_kit_table_view_scroll_row_to_visible)
  V("tableViewReloadRow", bare_app_kit_table_view_reload_row)
  V("tableViewSizeToFit", bare_app_kit_table_view_size_to_fit)
  V("tableViewSizeLastColumnToFit", bare_app_kit_table_view_size_last_column_to_fit)

  V("textInit", bare_app_kit_text_init)
  V("textString", bare_app_kit_text_string)
  V("textEditable", bare_app_kit_text_editable)
  V("textSelectable", bare_app_kit_text_selectable)
  V("textRichText", bare_app_kit_text_rich_text)
  V("textImportsGraphics", bare_app_kit_text_imports_graphics)
  V("textFieldEditor", bare_app_kit_text_field_editor)
  V("textUsesFontPanel", bare_app_kit_text_uses_font_panel)
  V("textDrawsBackground", bare_app_kit_text_draws_background)
  V("textRulerVisible", bare_app_kit_text_ruler_visible)
  V("textAlignment", bare_app_kit_text_alignment)
  V("textBaseWritingDirection", bare_app_kit_text_base_writing_direction)
  V("textSizeToFit", bare_app_kit_text_size_to_fit)
  V("textCopy", bare_app_kit_text_copy)
  V("textCut", bare_app_kit_text_cut)
  V("textDelete", bare_app_kit_text_delete)
  V("textPaste", bare_app_kit_text_paste)
  V("textSelectAll", bare_app_kit_text_select_all)
  V("textFont", bare_app_kit_text_font)
  V("textTextColor", bare_app_kit_text_text_color)
  V("textBackgroundColor", bare_app_kit_text_background_color)
  T(
    "textVerticallyResizable",
    bare_app_kit_text_vertically_resizable,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_vertically_resizable_typed
  )
  T(
    "textHorizontallyResizable",
    bare_app_kit_text_horizontally_resizable,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_horizontally_resizable_typed
  )
  T(
    "textMinSize",
    bare_app_kit_text_min_size,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_float64, js_float64},
    }),
    bare_app_kit_text_min_size_typed
  )
  T(
    "textMaxSize",
    bare_app_kit_text_max_size,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_float64, js_float64},
    }),
    bare_app_kit_text_max_size_typed
  )
  T(
    "textMinSizeInto",
    bare_app_kit_text_min_size_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_text_min_size_into_typed
  )
  T(
    "textMaxSizeInto",
    bare_app_kit_text_max_size_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_text_max_size_into_typed
  )

  V("textFieldInit", bare_app_kit_text_field_init)
  V("textFieldPlaceholderString", bare_app_kit_text_field_placeholder_string)
  V("textFieldTextColor", bare_app_kit_text_field_text_color)
  V("textFieldBackgroundColor", bare_app_kit_text_field_background_color)
  T(
    "textFieldBordered",
    bare_app_kit_text_field_bordered,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_field_bordered_typed
  )
  T(
    "textFieldBezeled",
    bare_app_kit_text_field_bezeled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_field_bezeled_typed
  )
  T(
    "textFieldEditable",
    bare_app_kit_text_field_editable,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_field_editable_typed
  )
  T(
    "textFieldSelectable",
    bare_app_kit_text_field_selectable,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_field_selectable_typed
  )
  T(
    "textFieldDrawsBackground",
    bare_app_kit_text_field_draws_background,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_field_draws_background_typed
  )
  T(
    "textFieldBezelStyle",
    bare_app_kit_text_field_bezel_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_text_field_bezel_style_typed
  )
  T(
    "textFieldMaximumNumberOfLines",
    bare_app_kit_text_field_maximum_number_of_lines,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_text_field_maximum_number_of_lines_typed
  )
  T(
    "textFieldPreferredMaxLayoutWidth",
    bare_app_kit_text_field_preferred_max_layout_width,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_text_field_preferred_max_layout_width_typed
  )
  V("textFieldSelectText", bare_app_kit_text_field_select_text)

  V("textMeasurerInit", bare_app_kit_text_measurer_init)
  V("textMeasurerLineFragmentPadding", bare_app_kit_text_measurer_line_fragment_padding)
  V("textMeasurerMaximumNumberOfLines", bare_app_kit_text_measurer_maximum_number_of_lines)
  V("textMeasurerMeasure", bare_app_kit_text_measurer_measure)
  V("textMeasurerMeasureAttributed", bare_app_kit_text_measurer_measure_attributed)

  V("textViewInit", bare_app_kit_text_view_init)
  V("textSelectedRange", bare_app_kit_text_selected_range)
  T(
    "textViewTextContainerInset",
    bare_app_kit_text_view_text_container_inset,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_float64, js_float64},
    }),
    bare_app_kit_text_view_text_container_inset_typed
  )
  V("textViewInsertionPointColor", bare_app_kit_text_view_insertion_point_color)
  T(
    "textViewAllowsUndo",
    bare_app_kit_text_view_allows_undo,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_allows_undo_typed
  )
  T(
    "textViewAllowsImageEditing",
    bare_app_kit_text_view_allows_image_editing,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_allows_image_editing_typed
  )
  T(
    "textViewAllowsDocumentBackgroundColorChange",
    bare_app_kit_text_view_allows_document_background_color_change,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_allows_document_background_color_change_typed
  )
  T(
    "textViewDisplaysLinkToolTips",
    bare_app_kit_text_view_displays_link_tool_tips,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_displays_link_tool_tips_typed
  )
  T(
    "textViewUsesFindBar",
    bare_app_kit_text_view_uses_find_bar,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_uses_find_bar_typed
  )
  T(
    "textViewUsesFindPanel",
    bare_app_kit_text_view_uses_find_panel,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_uses_find_panel_typed
  )
  T(
    "textViewUsesRuler",
    bare_app_kit_text_view_uses_ruler,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_uses_ruler_typed
  )
  T(
    "textViewUsesInspectorBar",
    bare_app_kit_text_view_uses_inspector_bar,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_uses_inspector_bar_typed
  )
  T(
    "textViewIncrementalSearchingEnabled",
    bare_app_kit_text_view_incremental_searching_enabled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_incremental_searching_enabled_typed
  )
  T(
    "textViewContinuousSpellCheckingEnabled",
    bare_app_kit_text_view_continuous_spell_checking_enabled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_continuous_spell_checking_enabled_typed
  )
  T(
    "textViewGrammarCheckingEnabled",
    bare_app_kit_text_view_grammar_checking_enabled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_grammar_checking_enabled_typed
  )
  T(
    "textViewAutomaticSpellingCorrectionEnabled",
    bare_app_kit_text_view_automatic_spelling_correction_enabled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_automatic_spelling_correction_enabled_typed
  )
  T(
    "textViewAutomaticQuoteSubstitutionEnabled",
    bare_app_kit_text_view_automatic_quote_substitution_enabled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_automatic_quote_substitution_enabled_typed
  )
  T(
    "textViewAutomaticDashSubstitutionEnabled",
    bare_app_kit_text_view_automatic_dash_substitution_enabled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_automatic_dash_substitution_enabled_typed
  )
  T(
    "textViewAutomaticTextReplacementEnabled",
    bare_app_kit_text_view_automatic_text_replacement_enabled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_automatic_text_replacement_enabled_typed
  )
  T(
    "textViewAutomaticLinkDetectionEnabled",
    bare_app_kit_text_view_automatic_link_detection_enabled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_automatic_link_detection_enabled_typed
  )
  T(
    "textViewSmartInsertDeleteEnabled",
    bare_app_kit_text_view_smart_insert_delete_enabled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_text_view_smart_insert_delete_enabled_typed
  )
  V("textViewInsertText", bare_app_kit_text_view_insert_text)
  V("textViewScrollRangeToVisible", bare_app_kit_text_view_scroll_range_to_visible)
  V("textViewDidChangeText", bare_app_kit_text_view_did_change_text)
  V("textViewAlignLeft", bare_app_kit_text_view_align_left)
  V("textViewAlignCenter", bare_app_kit_text_view_align_center)
  V("textViewAlignRight", bare_app_kit_text_view_align_right)
  V("textViewCheckTextInDocument", bare_app_kit_text_view_check_text_in_document)
  V("textViewAttributedString", bare_app_kit_text_view_attributed_string)
  V("textViewSetAttributedString", bare_app_kit_text_view_set_attributed_string)
  T(
    "textViewTextContainerInsetInto",
    bare_app_kit_text_view_text_container_inset_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_text_view_text_container_inset_into_typed
  )

  V("tokenFieldInit", bare_app_kit_token_field_init)
  T(
    "tokenFieldTokenStyle",
    bare_app_kit_token_field_token_style,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_token_field_token_style_typed
  )
  T(
    "tokenFieldCompletionDelay",
    bare_app_kit_token_field_completion_delay,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_token_field_completion_delay_typed
  )
  V("tokenFieldTokens", bare_app_kit_token_field_tokens)

  V("toolbarInit", bare_app_kit_toolbar_init)
  V("toolbarItems", bare_app_kit_toolbar_items)
  V("toolbarRegisterItem", bare_app_kit_toolbar_register_item)
  V("toolbarAllowedItemIdentifiers", bare_app_kit_toolbar_allowed_item_identifiers)
  V("toolbarDefaultItemIdentifiers", bare_app_kit_toolbar_default_item_identifiers)
  V("toolbarIdentifier", bare_app_kit_toolbar_identifier)
  V("toolbarDisplayMode", bare_app_kit_toolbar_display_mode)
  V("toolbarSelectedItemIdentifier", bare_app_kit_toolbar_selected_item_identifier)
  V("toolbarCenteredItemIdentifiers", bare_app_kit_toolbar_centered_item_identifiers)
  V("toolbarVisible", bare_app_kit_toolbar_visible)
  V("toolbarAllowsUserCustomization", bare_app_kit_toolbar_allows_user_customization)
  V("toolbarAllowsExtensionItems", bare_app_kit_toolbar_allows_extension_items)
  V("toolbarAutosavesConfiguration", bare_app_kit_toolbar_autosaves_configuration)
  V("toolbarCustomizationPaletteIsRunning", bare_app_kit_toolbar_customization_palette_is_running)
  V("toolbarInsertItemWithItemIdentifier", bare_app_kit_toolbar_insert_item_with_item_identifier)
  V("toolbarRemoveItemAtIndex", bare_app_kit_toolbar_remove_item_at_index)
  V("toolbarRunCustomizationPalette", bare_app_kit_toolbar_run_customization_palette)
  V("toolbarValidateVisibleItems", bare_app_kit_toolbar_validate_visible_items)
  V("toolbarSetCenteredItemIdentifiers", bare_app_kit_toolbar_set_centered_item_identifiers)

  V("toolbarItemInit", bare_app_kit_toolbar_item_init)
  V("toolbarItemItemIdentifier", bare_app_kit_toolbar_item_item_identifier)
  V("toolbarItemLabel", bare_app_kit_toolbar_item_label)
  V("toolbarItemPaletteLabel", bare_app_kit_toolbar_item_palette_label)
  V("toolbarItemToolTip", bare_app_kit_toolbar_item_tool_tip)
  V("toolbarItemTitle", bare_app_kit_toolbar_item_title)
  T(
    "toolbarItemTag",
    bare_app_kit_toolbar_item_tag,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_toolbar_item_tag_typed
  )
  T(
    "toolbarItemEnabled",
    bare_app_kit_toolbar_item_enabled,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_toolbar_item_enabled_typed
  )
  T(
    "toolbarItemBordered",
    bare_app_kit_toolbar_item_bordered,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_toolbar_item_bordered_typed
  )
  T(
    "toolbarItemNavigational",
    bare_app_kit_toolbar_item_navigational,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_toolbar_item_navigational_typed
  )
  T(
    "toolbarItemAutovalidates",
    bare_app_kit_toolbar_item_autovalidates,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_toolbar_item_autovalidates_typed
  )
  V("toolbarItemVisible", bare_app_kit_toolbar_item_visible)
  T(
    "toolbarItemVisibilityPriority",
    bare_app_kit_toolbar_item_visibility_priority,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_toolbar_item_visibility_priority_typed
  )
  V("toolbarItemImage", bare_app_kit_toolbar_item_image)
  V("toolbarItemView", bare_app_kit_toolbar_item_view)
  V("toolbarItemMenuFormRepresentation", bare_app_kit_toolbar_item_menu_form_representation)

  V("toolbarItemGroupInit", bare_app_kit_toolbar_item_group_init)
  T(
    "toolbarItemGroupSelectionMode",
    bare_app_kit_toolbar_item_group_selection_mode,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_toolbar_item_group_selection_mode_typed
  )
  T(
    "toolbarItemGroupControlRepresentation",
    bare_app_kit_toolbar_item_group_control_representation,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_toolbar_item_group_control_representation_typed
  )
  T(
    "toolbarItemGroupSelectedIndex",
    bare_app_kit_toolbar_item_group_selected_index,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_toolbar_item_group_selected_index_typed
  )
  V("toolbarItemGroupSetSubitems", bare_app_kit_toolbar_item_group_set_subitems)

  V("trackingAreaInit", bare_app_kit_tracking_area_init)
  V("trackingAreaRect", bare_app_kit_tracking_area_rect)
  V("trackingAreaOptions", bare_app_kit_tracking_area_options)

  V("trackingSeparatorToolbarItemInit", bare_app_kit_tracking_separator_toolbar_item_init)

  V("undoManagerInit", bare_app_kit_undo_manager_init)
  V("undoManagerCanUndo", bare_app_kit_undo_manager_can_undo)
  V("undoManagerCanRedo", bare_app_kit_undo_manager_can_redo)
  V("undoManagerUndoing", bare_app_kit_undo_manager_undoing)
  V("undoManagerRedoing", bare_app_kit_undo_manager_redoing)
  V("undoManagerUndoRegistrationEnabled", bare_app_kit_undo_manager_undo_registration_enabled)
  T(
    "undoManagerGroupsByEvent",
    bare_app_kit_undo_manager_groups_by_event,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_undo_manager_groups_by_event_typed
  )
  T(
    "undoManagerLevelsOfUndo",
    bare_app_kit_undo_manager_levels_of_undo,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_undo_manager_levels_of_undo_typed
  )
  V("undoManagerUndoActionName", bare_app_kit_undo_manager_undo_action_name)
  V("undoManagerRedoActionName", bare_app_kit_undo_manager_redo_action_name)
  V("undoManagerUndoMenuItemTitle", bare_app_kit_undo_manager_undo_menu_item_title)
  V("undoManagerRedoMenuItemTitle", bare_app_kit_undo_manager_redo_menu_item_title)
  V("undoManagerGroupingLevel", bare_app_kit_undo_manager_grouping_level)
  V("undoManagerUndo", bare_app_kit_undo_manager_undo)
  V("undoManagerRedo", bare_app_kit_undo_manager_redo)
  V("undoManagerUndoNestedGroup", bare_app_kit_undo_manager_undo_nested_group)
  V("undoManagerBeginUndoGrouping", bare_app_kit_undo_manager_begin_undo_grouping)
  V("undoManagerEndUndoGrouping", bare_app_kit_undo_manager_end_undo_grouping)
  V("undoManagerRemoveAllActions", bare_app_kit_undo_manager_remove_all_actions)
  V("undoManagerDisableUndoRegistration", bare_app_kit_undo_manager_disable_undo_registration)
  V("undoManagerEnableUndoRegistration", bare_app_kit_undo_manager_enable_undo_registration)
  V("undoManagerSetActionName", bare_app_kit_undo_manager_set_action_name)

  V("viewInit", bare_app_kit_view_init)
  V("viewAcceptsFirstResponder", bare_app_kit_view_accepts_first_responder)
  T(
    "viewFrame",
    bare_app_kit_view_frame,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 6,
      .args = (int[]){js_object, js_int32, js_float64, js_float64, js_float64, js_float64},
    }),
    bare_app_kit_view_frame_typed
  )
  T(
    "viewBounds",
    bare_app_kit_view_bounds,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 6,
      .args = (int[]){js_object, js_int32, js_float64, js_float64, js_float64, js_float64},
    }),
    bare_app_kit_view_bounds_typed
  )
  T(
    "viewHidden",
    bare_app_kit_view_hidden,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_view_hidden_typed
  )
  V("viewHiddenOrHasHiddenAncestor", bare_app_kit_view_hidden_or_has_hidden_ancestor)
  T(
    "viewAlphaValue",
    bare_app_kit_view_alpha_value,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_float64},
    }),
    bare_app_kit_view_alpha_value_typed
  )
  V("viewToolTip", bare_app_kit_view_tool_tip)
  T(
    "viewAutoresizingMask",
    bare_app_kit_view_autoresizing_mask,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_view_autoresizing_mask_typed
  )
  T(
    "viewAutoresizesSubviews",
    bare_app_kit_view_autoresizes_subviews,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_view_autoresizes_subviews_typed
  )
  T(
    "viewTranslatesAutoresizingMaskIntoConstraints",
    bare_app_kit_view_translates_autoresizing_mask_into_constraints,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_view_translates_autoresizing_mask_into_constraints_typed
  )
  T(
    "viewWantsLayer",
    bare_app_kit_view_wants_layer,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_view_wants_layer_typed
  )
  T(
    "viewNeedsDisplay",
    bare_app_kit_view_needs_display,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_view_needs_display_typed
  )
  T(
    "viewNeedsLayout",
    bare_app_kit_view_needs_layout,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_view_needs_layout_typed
  )
  V("viewFittingSize", bare_app_kit_view_fitting_size)
  V("viewIntrinsicContentSize", bare_app_kit_view_intrinsic_content_size)
  V("viewSuperview", bare_app_kit_view_superview)
  V("viewSubviews", bare_app_kit_view_subviews)
  V("viewAddSubview", bare_app_kit_view_add_subview)
  V("viewRemoveFromSuperview", bare_app_kit_view_remove_from_superview)
  V("viewDisplay", bare_app_kit_view_display)
  V("viewLayout", bare_app_kit_view_layout)
  V("viewMenu", bare_app_kit_view_menu)
  V("viewTopAnchor", bare_app_kit_view_top_anchor)
  V("viewBottomAnchor", bare_app_kit_view_bottom_anchor)
  V("viewLeadingAnchor", bare_app_kit_view_leading_anchor)
  V("viewTrailingAnchor", bare_app_kit_view_trailing_anchor)
  V("viewLeftAnchor", bare_app_kit_view_left_anchor)
  V("viewRightAnchor", bare_app_kit_view_right_anchor)
  V("viewWidthAnchor", bare_app_kit_view_width_anchor)
  V("viewHeightAnchor", bare_app_kit_view_height_anchor)
  V("viewCenterXAnchor", bare_app_kit_view_center_x_anchor)
  V("viewCenterYAnchor", bare_app_kit_view_center_y_anchor)
  V("viewFirstBaselineAnchor", bare_app_kit_view_first_baseline_anchor)
  V("viewLastBaselineAnchor", bare_app_kit_view_last_baseline_anchor)
  V("viewAppearance", bare_app_kit_view_appearance)
  V("viewEffectiveAppearance", bare_app_kit_view_effective_appearance)
  T(
    "viewNeedsUpdateConstraints",
    bare_app_kit_view_needs_update_constraints,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_view_needs_update_constraints_typed
  )
  V("viewUndoManager", bare_app_kit_view_undo_manager)
  V("viewVisibleRect", bare_app_kit_view_visible_rect)
  T(
    "viewClipsToBounds",
    bare_app_kit_view_clips_to_bounds,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_view_clips_to_bounds_typed
  )
  T(
    "viewCanDrawSubviewsIntoLayer",
    bare_app_kit_view_can_draw_subviews_into_layer,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_view_can_draw_subviews_into_layer_typed
  )
  T(
    "viewLayerContentsRedrawPolicy",
    bare_app_kit_view_layer_contents_redraw_policy,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_view_layer_contents_redraw_policy_typed
  )
  T(
    "viewFocusRingType",
    bare_app_kit_view_focus_ring_type,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_view_focus_ring_type_typed
  )
  V("viewOpaque", bare_app_kit_view_opaque)
  V("viewAllowsVibrancy", bare_app_kit_view_allows_vibrancy)
  V("viewRotatedFromBase", bare_app_kit_view_rotated_from_base)
  V("viewFlipped", bare_app_kit_view_flipped)
  V("viewInLiveResize", bare_app_kit_view_in_live_resize)
  V("viewCanBecomeKeyView", bare_app_kit_view_can_become_key_view)
  T(
    "viewUserInterfaceLayoutDirection",
    bare_app_kit_view_user_interface_layout_direction,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_view_user_interface_layout_direction_typed
  )
  V("viewNextKeyView", bare_app_kit_view_next_key_view)
  V("viewWindow", bare_app_kit_view_window)
  V("viewEnclosingScrollView", bare_app_kit_view_enclosing_scroll_view)
  V("viewSetContentHuggingPriority", bare_app_kit_view_set_content_hugging_priority)
  V("viewSetContentCompressionResistancePriority", bare_app_kit_view_set_content_compression_resistance_priority)
  V("viewAddTrackingArea", bare_app_kit_view_add_tracking_area)
  V("viewRemoveTrackingArea", bare_app_kit_view_remove_tracking_area)
  V("viewConvertPointFromView", bare_app_kit_view_convert_point_from_view)
  V("viewConvertPointToView", bare_app_kit_view_convert_point_to_view)
  V("viewHitTest", bare_app_kit_view_hit_test)
  V("viewSetNeedsDisplayInRect", bare_app_kit_view_set_needs_display_in_rect)
  V("viewScrollPointToVisible", bare_app_kit_view_scroll_point_to_visible)
  V("viewLayoutSubtreeIfNeeded", bare_app_kit_view_layout_subtree_if_needed)
  T(
    "viewVisibleRectInto",
    bare_app_kit_view_visible_rect_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_view_visible_rect_into_typed
  )
  T(
    "viewFrameInto",
    bare_app_kit_view_frame_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_view_frame_into_typed
  )
  T(
    "viewSafeAreaInsetsInto",
    bare_app_kit_view_safe_area_insets_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_view_safe_area_insets_into_typed
  )
  T(
    "viewBoundsInto",
    bare_app_kit_view_bounds_into,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 4,
      .args = (int[]){js_object, js_int32, js_object, js_uint32},
    }),
    bare_app_kit_view_bounds_into_typed
  )

  V("visualEffectViewInit", bare_app_kit_visual_effect_view_init)
  T(
    "visualEffectViewMaterial",
    bare_app_kit_visual_effect_view_material,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_visual_effect_view_material_typed
  )
  T(
    "visualEffectViewBlendingMode",
    bare_app_kit_visual_effect_view_blending_mode,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_visual_effect_view_blending_mode_typed
  )
  T(
    "visualEffectViewState",
    bare_app_kit_visual_effect_view_state,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_int32},
    }),
    bare_app_kit_visual_effect_view_state_typed
  )
  T(
    "visualEffectViewEmphasized",
    bare_app_kit_visual_effect_view_emphasized,
    &((js_callback_signature_t){
      .version = 0,
      .result = js_undefined,
      .args_len = 3,
      .args = (int[]){js_object, js_int32, js_boolean},
    }),
    bare_app_kit_visual_effect_view_emphasized_typed
  )

  V("windowInit", bare_app_kit_window_init)
  V("windowTitle", bare_app_kit_window_title)
  V("windowSubtitle", bare_app_kit_window_subtitle)
  V("windowRepresentedFilename", bare_app_kit_window_represented_filename)
  V("windowMiniwindowTitle", bare_app_kit_window_miniwindow_title)
  V("windowFrameAutosaveName", bare_app_kit_window_frame_autosave_name)
  V("windowContentView", bare_app_kit_window_content_view)
  V("windowBackgroundColor", bare_app_kit_window_background_color)
  V("windowMiniwindowImage", bare_app_kit_window_miniwindow_image)
  V("windowToolbar", bare_app_kit_window_toolbar)
  V("windowAppearance", bare_app_kit_window_appearance)
  V("windowEffectiveAppearance", bare_app_kit_window_effective_appearance)
  V("windowParentWindow", bare_app_kit_window_parent_window)
  V("windowAttachedSheet", bare_app_kit_window_attached_sheet)
  V("windowStyleMask", bare_app_kit_window_style_mask)
  V("windowLevel", bare_app_kit_window_level)
  V("windowCollectionBehavior", bare_app_kit_window_collection_behavior)
  V("windowAnimationBehavior", bare_app_kit_window_animation_behavior)
  V("windowTitleVisibility", bare_app_kit_window_title_visibility)
  V("windowToolbarStyle", bare_app_kit_window_toolbar_style)
  V("windowTitlebarSeparatorStyle", bare_app_kit_window_titlebar_separator_style)
  V("windowTabbingMode", bare_app_kit_window_tabbing_mode)
  V("windowWindowNumber", bare_app_kit_window_window_number)
  V("windowTitlebarAppearsTransparent", bare_app_kit_window_titlebar_appears_transparent)
  V("windowExcludedFromWindowsMenu", bare_app_kit_window_excluded_from_windows_menu)
  V("windowDocumentEdited", bare_app_kit_window_document_edited)
  V("windowMovable", bare_app_kit_window_movable)
  V("windowMovableByWindowBackground", bare_app_kit_window_movable_by_window_background)
  V("windowHidesOnDeactivate", bare_app_kit_window_hides_on_deactivate)
  V("windowCanHide", bare_app_kit_window_can_hide)
  V("windowHasShadow", bare_app_kit_window_has_shadow)
  V("windowOpaque", bare_app_kit_window_opaque)
  V("windowPreservesContentDuringLiveResize", bare_app_kit_window_preserves_content_during_live_resize)
  V("windowAllowsConcurrentViewDrawing", bare_app_kit_window_allows_concurrent_view_drawing)
  V("windowViewsNeedDisplay", bare_app_kit_window_views_need_display)
  V("windowAutorecalculatesKeyViewLoop", bare_app_kit_window_autorecalculates_key_view_loop)
  V("windowInitialFirstResponder", bare_app_kit_window_initial_first_responder)
  V("windowWorksWhenModal", bare_app_kit_window_works_when_modal)
  V("windowVisible", bare_app_kit_window_visible)
  V("windowKeyWindow", bare_app_kit_window_key_window)
  V("windowMainWindow", bare_app_kit_window_main_window)
  V("windowZoomed", bare_app_kit_window_zoomed)
  V("windowMiniaturized", bare_app_kit_window_miniaturized)
  V("windowInLiveResize", bare_app_kit_window_in_live_resize)
  V("windowOnActiveSpace", bare_app_kit_window_on_active_space)
  V("windowSheet", bare_app_kit_window_sheet)
  V("windowCanBecomeKeyWindow", bare_app_kit_window_can_become_key_window)
  V("windowCanBecomeMainWindow", bare_app_kit_window_can_become_main_window)
  V("windowAlphaValue", bare_app_kit_window_alpha_value)
  V("windowBackingScaleFactor", bare_app_kit_window_backing_scale_factor)
  V("windowFrame", bare_app_kit_window_frame)
  V("windowContentLayoutRect", bare_app_kit_window_content_layout_rect)
  V("windowMinSize", bare_app_kit_window_min_size)
  V("windowMaxSize", bare_app_kit_window_max_size)
  V("windowContentMinSize", bare_app_kit_window_content_min_size)
  V("windowContentMaxSize", bare_app_kit_window_content_max_size)
  V("windowResizeIncrements", bare_app_kit_window_resize_increments)
  V("windowAspectRatio", bare_app_kit_window_aspect_ratio)
  V("windowContentResizeIncrements", bare_app_kit_window_content_resize_increments)
  V("windowContentAspectRatio", bare_app_kit_window_content_aspect_ratio)
  V("windowCenter", bare_app_kit_window_center)
  V("windowClose", bare_app_kit_window_close)
  V("windowPerformClose", bare_app_kit_window_perform_close)
  V("windowMakeKeyWindow", bare_app_kit_window_make_key_window)
  V("windowMakeMainWindow", bare_app_kit_window_make_main_window)
  V("windowMakeKeyAndOrderFront", bare_app_kit_window_make_key_and_order_front)
  V("windowOrderBack", bare_app_kit_window_order_back)
  V("windowOrderFront", bare_app_kit_window_order_front)
  V("windowOrderOut", bare_app_kit_window_order_out)
  V("windowMiniaturize", bare_app_kit_window_miniaturize)
  V("windowDeminiaturize", bare_app_kit_window_deminiaturize)
  V("windowZoom", bare_app_kit_window_zoom)
  V("windowToggleFullScreen", bare_app_kit_window_toggle_full_screen)
  V("windowDisplay", bare_app_kit_window_display)
  V("windowInvalidateShadow", bare_app_kit_window_invalidate_shadow)
  V("windowSelectNextKeyView", bare_app_kit_window_select_next_key_view)
  V("windowSelectPreviousKeyView", bare_app_kit_window_select_previous_key_view)
  V("windowSetFrame", bare_app_kit_window_set_frame)
  V("windowSetFrameOrigin", bare_app_kit_window_set_frame_origin)
  V("windowSetFrameTopLeftPoint", bare_app_kit_window_set_frame_top_left_point)
  V("windowSetContentSize", bare_app_kit_window_set_content_size)
  V("windowMakeFirstResponder", bare_app_kit_window_make_first_responder)
  V("windowSetFrameAutosaveName", bare_app_kit_window_set_frame_autosave_name)
  V("windowSaveFrameUsingName", bare_app_kit_window_save_frame_using_name)
  V("windowSetFrameUsingName", bare_app_kit_window_set_frame_using_name)
  V("windowChildWindows", bare_app_kit_window_child_windows)
  V("windowAddChildWindow", bare_app_kit_window_add_child_window)
  V("windowRemoveChildWindow", bare_app_kit_window_remove_child_window)

  V("workspaceOpenURL", bare_app_kit_workspace_open_url)
  V("workspaceOpenFile", bare_app_kit_workspace_open_file)
  V("workspaceSelectFile", bare_app_kit_workspace_select_file)
  V("workspaceIconForFile", bare_app_kit_workspace_icon_for_file)
  V("workspaceUrlForApplication", bare_app_kit_workspace_url_for_application)
  V("workspaceIconForContentType", bare_app_kit_workspace_icon_for_content_type)
  V("workspaceIsFilePackage", bare_app_kit_workspace_is_file_package)
  V("workspaceOpenApplication", bare_app_kit_workspace_open_application)
  V("workspaceHideOtherApplications", bare_app_kit_workspace_hide_other_applications)
  V("workspaceUrlForApplicationToOpenFile", bare_app_kit_workspace_url_for_application_to_open_file)
#undef V
#undef T

#define V(name, n) \
  { \
    js_value_t *val; \
    err = js_create_int32(env, n, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, exports, name, val); \
    assert(err == 0); \
  }

  V("ALERT_STYLE_WARNING", NSAlertStyleWarning)
  V("ALERT_STYLE_INFORMATIONAL", NSAlertStyleInformational)
  V("ALERT_STYLE_CRITICAL", NSAlertStyleCritical)

  V("APPLICATION_ACTIVATION_POLICY_REGULAR", NSApplicationActivationPolicyRegular)
  V("APPLICATION_ACTIVATION_POLICY_ACCESSORY", NSApplicationActivationPolicyAccessory)
  V("APPLICATION_ACTIVATION_POLICY_PROHIBITED", NSApplicationActivationPolicyProhibited)

  V("APPLICATION_REQUEST_TYPE_CRITICAL", NSCriticalRequest)
  V("APPLICATION_REQUEST_TYPE_INFORMATIONAL", NSInformationalRequest)

  V("BEZIER_PATH_LINE_CAP_BUTT", NSLineCapStyleButt)
  V("BEZIER_PATH_LINE_CAP_ROUND", NSLineCapStyleRound)
  V("BEZIER_PATH_LINE_CAP_SQUARE", NSLineCapStyleSquare)

  V("BEZIER_PATH_LINE_JOIN_MITER", NSLineJoinStyleMiter)
  V("BEZIER_PATH_LINE_JOIN_ROUND", NSLineJoinStyleRound)
  V("BEZIER_PATH_LINE_JOIN_BEVEL", NSLineJoinStyleBevel)

  V("BEZIER_PATH_WINDING_NON_ZERO", NSWindingRuleNonZero)
  V("BEZIER_PATH_WINDING_EVEN_ODD", NSWindingRuleEvenOdd)

  V("BOX_TITLE_POSITION_NONE", NSNoTitle)
  V("BOX_TITLE_POSITION_ABOVE_TOP", NSAboveTop)
  V("BOX_TITLE_POSITION_AT_TOP", NSAtTop)
  V("BOX_TITLE_POSITION_BELOW_TOP", NSBelowTop)
  V("BOX_TITLE_POSITION_ABOVE_BOTTOM", NSAboveBottom)
  V("BOX_TITLE_POSITION_AT_BOTTOM", NSAtBottom)
  V("BOX_TITLE_POSITION_BELOW_BOTTOM", NSBelowBottom)

  V("BOX_TYPE_PRIMARY", NSBoxPrimary)
  V("BOX_TYPE_SEPARATOR", NSBoxSeparator)
  V("BOX_TYPE_CUSTOM", NSBoxCustom)

  V("BUTTON_BEZEL_STYLE_PUSH", NSBezelStylePush)
  V("BUTTON_BEZEL_STYLE_FLEXIBLE_PUSH", NSBezelStyleFlexiblePush)
  V("BUTTON_BEZEL_STYLE_DISCLOSURE", NSBezelStyleDisclosure)
  V("BUTTON_BEZEL_STYLE_CIRCULAR", NSBezelStyleCircular)
  V("BUTTON_BEZEL_STYLE_HELP_BUTTON", NSBezelStyleHelpButton)
  V("BUTTON_BEZEL_STYLE_SMALL_SQUARE", NSBezelStyleSmallSquare)
  V("BUTTON_BEZEL_STYLE_TOOLBAR", NSBezelStyleToolbar)
  V("BUTTON_BEZEL_STYLE_ACCESSORY_BAR_ACTION", NSBezelStyleAccessoryBarAction)
  V("BUTTON_BEZEL_STYLE_ACCESSORY_BAR", NSBezelStyleAccessoryBar)
  V("BUTTON_BEZEL_STYLE_PUSH_DISCLOSURE", NSBezelStylePushDisclosure)
  V("BUTTON_BEZEL_STYLE_BADGE", NSBezelStyleBadge)

  V("BUTTON_IMAGE_POSITION_NO_IMAGE", NSNoImage)
  V("BUTTON_IMAGE_POSITION_IMAGE_ONLY", NSImageOnly)
  V("BUTTON_IMAGE_POSITION_IMAGE_LEFT", NSImageLeft)
  V("BUTTON_IMAGE_POSITION_IMAGE_RIGHT", NSImageRight)
  V("BUTTON_IMAGE_POSITION_IMAGE_BELOW", NSImageBelow)
  V("BUTTON_IMAGE_POSITION_IMAGE_ABOVE", NSImageAbove)
  V("BUTTON_IMAGE_POSITION_IMAGE_OVERLAPS", NSImageOverlaps)
  V("BUTTON_IMAGE_POSITION_IMAGE_LEADING", NSImageLeading)
  V("BUTTON_IMAGE_POSITION_IMAGE_TRAILING", NSImageTrailing)

  V("BUTTON_TYPE_MOMENTARY_LIGHT", NSButtonTypeMomentaryLight)
  V("BUTTON_TYPE_PUSH_ON_PUSH_OFF", NSButtonTypePushOnPushOff)
  V("BUTTON_TYPE_TOGGLE", NSButtonTypeToggle)
  V("BUTTON_TYPE_SWITCH", NSButtonTypeSwitch)
  V("BUTTON_TYPE_RADIO", NSButtonTypeRadio)
  V("BUTTON_TYPE_MOMENTARY_CHANGE", NSButtonTypeMomentaryChange)
  V("BUTTON_TYPE_ON_OFF", NSButtonTypeOnOff)
  V("BUTTON_TYPE_MOMENTARY_PUSH_IN", NSButtonTypeMomentaryPushIn)
  V("BUTTON_TYPE_ACCELERATOR", NSButtonTypeAccelerator)
  V("BUTTON_TYPE_MULTI_LEVEL_ACCELERATOR", NSButtonTypeMultiLevelAccelerator)

  V("COLLECTION_VIEW_ITEM_HIGHLIGHT_NONE", NSCollectionViewItemHighlightNone)
  V("COLLECTION_VIEW_ITEM_HIGHLIGHT_FOR_SELECTION", NSCollectionViewItemHighlightForSelection)
  V("COLLECTION_VIEW_ITEM_HIGHLIGHT_FOR_DESELECTION", NSCollectionViewItemHighlightForDeselection)
  V("COLLECTION_VIEW_ITEM_HIGHLIGHT_AS_DROP_TARGET", NSCollectionViewItemHighlightAsDropTarget)

  V("COLLECTION_VIEW_SCROLL_DIRECTION_VERTICAL", NSCollectionViewScrollDirectionVertical)
  V("COLLECTION_VIEW_SCROLL_DIRECTION_HORIZONTAL", NSCollectionViewScrollDirectionHorizontal)

  V("COLLECTION_VIEW_SCROLL_POSITION_NONE", NSCollectionViewScrollPositionNone)
  V("COLLECTION_VIEW_SCROLL_POSITION_TOP", NSCollectionViewScrollPositionTop)
  V("COLLECTION_VIEW_SCROLL_POSITION_CENTERED_VERTICALLY", NSCollectionViewScrollPositionCenteredVertically)
  V("COLLECTION_VIEW_SCROLL_POSITION_BOTTOM", NSCollectionViewScrollPositionBottom)
  V("COLLECTION_VIEW_SCROLL_POSITION_NEAREST_HORIZONTAL_EDGE", NSCollectionViewScrollPositionNearestHorizontalEdge)
  V("COLLECTION_VIEW_SCROLL_POSITION_LEFT", NSCollectionViewScrollPositionLeft)
  V("COLLECTION_VIEW_SCROLL_POSITION_CENTERED_HORIZONTALLY", NSCollectionViewScrollPositionCenteredHorizontally)
  V("COLLECTION_VIEW_SCROLL_POSITION_RIGHT", NSCollectionViewScrollPositionRight)

#define V_COLOR(name, selector) V("COLOR_" #name, bare_app_kit_color_##name)
  BARE_APP_KIT_COLORS(V_COLOR)
#undef V_COLOR

  V("CLIP_VIEW_EVENT_BOUNDS_DID_CHANGE", bare_app_kit_clip_view_event_bounds_did_change)

  V("COLOR_PANEL_MODE_GRAY", NSColorPanelModeGray)
  V("COLOR_PANEL_MODE_RGB", NSColorPanelModeRGB)
  V("COLOR_PANEL_MODE_CMYK", NSColorPanelModeCMYK)
  V("COLOR_PANEL_MODE_HSB", NSColorPanelModeHSB)
  V("COLOR_PANEL_MODE_CUSTOM_PALETTE", NSColorPanelModeCustomPalette)
  V("COLOR_PANEL_MODE_COLOR_LIST", NSColorPanelModeColorList)
  V("COLOR_PANEL_MODE_WHEEL", NSColorPanelModeWheel)
  V("COLOR_PANEL_MODE_CRAYON", NSColorPanelModeCrayon)

  V("COLOR_SYSTEM_EFFECT_NONE", NSColorSystemEffectNone)
  V("COLOR_SYSTEM_EFFECT_PRESSED", NSColorSystemEffectPressed)
  V("COLOR_SYSTEM_EFFECT_DEEP_PRESSED", NSColorSystemEffectDeepPressed)
  V("COLOR_SYSTEM_EFFECT_DISABLED", NSColorSystemEffectDisabled)
  V("COLOR_SYSTEM_EFFECT_ROLLOVER", NSColorSystemEffectRollover)

  V("COLOR_TYPE_COMPONENT_BASED", NSColorTypeComponentBased)
  V("COLOR_TYPE_PATTERN", NSColorTypePattern)
  V("COLOR_TYPE_CATALOG", NSColorTypeCatalog)

  V("COMBO_BUTTON_STYLE_SPLIT", NSComboButtonStyleSplit)
  V("COMBO_BUTTON_STYLE_UNIFIED", NSComboButtonStyleUnified)

#define V_CONTENT_TYPE(name, constant) V("CONTENT_TYPE_" #name, bare_app_kit_content_type_##name)
  BARE_APP_KIT_CONTENT_TYPES(V_CONTENT_TYPE)
#undef V_CONTENT_TYPE

#define V_CONTENT_TYPE(name, constant, macos) V("CONTENT_TYPE_" #name, bare_app_kit_content_type_##name)
  BARE_APP_KIT_CONTENT_TYPES_AVAILABLE(V_CONTENT_TYPE)
#undef V_CONTENT_TYPE

  V("CONTROL_SIZE_REGULAR", NSControlSizeRegular)
  V("CONTROL_SIZE_SMALL", NSControlSizeSmall)
  V("CONTROL_SIZE_MINI", NSControlSizeMini)
  V("CONTROL_SIZE_LARGE", NSControlSizeLarge)

  V("CONTROL_STATE_MIXED", NSControlStateValueMixed)
  V("CONTROL_STATE_OFF", NSControlStateValueOff)
  V("CONTROL_STATE_ON", NSControlStateValueOn)

#define V_CURSOR(name, selector) V("CURSOR_" #name, bare_app_kit_cursor_##name)
  BARE_APP_KIT_CURSORS(V_CURSOR)
#undef V_CURSOR

  V("DATE_PICKER_ELEMENTS_HOUR_MINUTE", NSDatePickerElementFlagHourMinute)
  V("DATE_PICKER_ELEMENTS_HOUR_MINUTE_SECOND", NSDatePickerElementFlagHourMinuteSecond)
  V("DATE_PICKER_ELEMENTS_TIME_ZONE", NSDatePickerElementFlagTimeZone)
  V("DATE_PICKER_ELEMENTS_YEAR_MONTH", NSDatePickerElementFlagYearMonth)
  V("DATE_PICKER_ELEMENTS_YEAR_MONTH_DAY", NSDatePickerElementFlagYearMonthDay)
  V("DATE_PICKER_ELEMENTS_ERA", NSDatePickerElementFlagEra)

  V("DATE_PICKER_MODE_SINGLE", NSDatePickerModeSingle)
  V("DATE_PICKER_MODE_RANGE", NSDatePickerModeRange)

  V("DATE_PICKER_STYLE_TEXT_FIELD_AND_STEPPER", NSDatePickerStyleTextFieldAndStepper)
  V("DATE_PICKER_STYLE_CLOCK_AND_CALENDAR", NSDatePickerStyleClockAndCalendar)
  V("DATE_PICKER_STYLE_TEXT_FIELD", NSDatePickerStyleTextField)

  V("EVENT_MODIFIER_CAPS_LOCK", NSEventModifierFlagCapsLock)
  V("EVENT_MODIFIER_SHIFT", NSEventModifierFlagShift)
  V("EVENT_MODIFIER_CONTROL", NSEventModifierFlagControl)
  V("EVENT_MODIFIER_OPTION", NSEventModifierFlagOption)
  V("EVENT_MODIFIER_COMMAND", NSEventModifierFlagCommand)
  V("EVENT_MODIFIER_FUNCTION", NSEventModifierFlagFunction)

  V("EVENT_TYPE_LEFT_MOUSE_DOWN", NSEventTypeLeftMouseDown)
  V("EVENT_TYPE_LEFT_MOUSE_UP", NSEventTypeLeftMouseUp)
  V("EVENT_TYPE_RIGHT_MOUSE_DOWN", NSEventTypeRightMouseDown)
  V("EVENT_TYPE_RIGHT_MOUSE_UP", NSEventTypeRightMouseUp)
  V("EVENT_TYPE_MOUSE_MOVED", NSEventTypeMouseMoved)
  V("EVENT_TYPE_LEFT_MOUSE_DRAGGED", NSEventTypeLeftMouseDragged)
  V("EVENT_TYPE_RIGHT_MOUSE_DRAGGED", NSEventTypeRightMouseDragged)
  V("EVENT_TYPE_MOUSE_ENTERED", NSEventTypeMouseEntered)
  V("EVENT_TYPE_MOUSE_EXITED", NSEventTypeMouseExited)
  V("EVENT_TYPE_KEY_DOWN", NSEventTypeKeyDown)
  V("EVENT_TYPE_KEY_UP", NSEventTypeKeyUp)
  V("EVENT_TYPE_FLAGS_CHANGED", NSEventTypeFlagsChanged)
  V("EVENT_TYPE_SCROLL_WHEEL", NSEventTypeScrollWheel)
  V("EVENT_TYPE_OTHER_MOUSE_DOWN", NSEventTypeOtherMouseDown)
  V("EVENT_TYPE_OTHER_MOUSE_UP", NSEventTypeOtherMouseUp)
  V("EVENT_TYPE_MAGNIFY", NSEventTypeMagnify)
  V("EVENT_TYPE_SWIPE", NSEventTypeSwipe)
  V("EVENT_TYPE_ROTATE", NSEventTypeRotate)

  V("GRAPHICS_CONTEXT_COMPOSITING_CLEAR", NSCompositingOperationClear)
  V("GRAPHICS_CONTEXT_COMPOSITING_COPY", NSCompositingOperationCopy)
  V("GRAPHICS_CONTEXT_COMPOSITING_SOURCE_OVER", NSCompositingOperationSourceOver)
  V("GRAPHICS_CONTEXT_COMPOSITING_MULTIPLY", NSCompositingOperationMultiply)
  V("GRAPHICS_CONTEXT_COMPOSITING_SCREEN", NSCompositingOperationScreen)
  V("GRAPHICS_CONTEXT_COMPOSITING_OVERLAY", NSCompositingOperationOverlay)
  V("GRAPHICS_CONTEXT_COMPOSITING_DARKEN", NSCompositingOperationDarken)
  V("GRAPHICS_CONTEXT_COMPOSITING_LIGHTEN", NSCompositingOperationLighten)

  V("GRAPHICS_CONTEXT_INTERPOLATION_DEFAULT", NSImageInterpolationDefault)
  V("GRAPHICS_CONTEXT_INTERPOLATION_NONE", NSImageInterpolationNone)
  V("GRAPHICS_CONTEXT_INTERPOLATION_LOW", NSImageInterpolationLow)
  V("GRAPHICS_CONTEXT_INTERPOLATION_MEDIUM", NSImageInterpolationMedium)
  V("GRAPHICS_CONTEXT_INTERPOLATION_HIGH", NSImageInterpolationHigh)

  V("GRID_PLACEMENT_INHERITED", NSGridCellPlacementInherited)
  V("GRID_PLACEMENT_NONE", NSGridCellPlacementNone)
  V("GRID_PLACEMENT_LEADING", NSGridCellPlacementLeading)
  V("GRID_PLACEMENT_TOP", NSGridCellPlacementTop)
  V("GRID_PLACEMENT_TRAILING", NSGridCellPlacementTrailing)
  V("GRID_PLACEMENT_BOTTOM", NSGridCellPlacementBottom)
  V("GRID_PLACEMENT_CENTER", NSGridCellPlacementCenter)
  V("GRID_PLACEMENT_FILL", NSGridCellPlacementFill)

  V("GRID_ROW_ALIGNMENT_INHERITED", NSGridRowAlignmentInherited)
  V("GRID_ROW_ALIGNMENT_NONE", NSGridRowAlignmentNone)
  V("GRID_ROW_ALIGNMENT_FIRST_BASELINE", NSGridRowAlignmentFirstBaseline)
  V("GRID_ROW_ALIGNMENT_LAST_BASELINE", NSGridRowAlignmentLastBaseline)

  V("IMAGE_CACHE_MODE_DEFAULT", NSImageCacheDefault)
  V("IMAGE_CACHE_MODE_ALWAYS", NSImageCacheAlways)
  V("IMAGE_CACHE_MODE_BY_SIZE", NSImageCacheBySize)
  V("IMAGE_CACHE_MODE_NEVER", NSImageCacheNever)

  V("IMAGE_RESIZING_MODE_STRETCH", NSImageResizingModeStretch)
  V("IMAGE_RESIZING_MODE_TILE", NSImageResizingModeTile)

  V("IMAGE_SCALING_PROPORTIONALLY_DOWN", NSImageScaleProportionallyDown)
  V("IMAGE_SCALING_AXES_INDEPENDENTLY", NSImageScaleAxesIndependently)
  V("IMAGE_SCALING_NONE", NSImageScaleNone)
  V("IMAGE_SCALING_PROPORTIONALLY_UP_OR_DOWN", NSImageScaleProportionallyUpOrDown)

  V("IMAGE_VIEW_ALIGNMENT_CENTER", NSImageAlignCenter)
  V("IMAGE_VIEW_ALIGNMENT_TOP", NSImageAlignTop)
  V("IMAGE_VIEW_ALIGNMENT_TOP_LEFT", NSImageAlignTopLeft)
  V("IMAGE_VIEW_ALIGNMENT_TOP_RIGHT", NSImageAlignTopRight)
  V("IMAGE_VIEW_ALIGNMENT_LEFT", NSImageAlignLeft)
  V("IMAGE_VIEW_ALIGNMENT_BOTTOM", NSImageAlignBottom)
  V("IMAGE_VIEW_ALIGNMENT_BOTTOM_LEFT", NSImageAlignBottomLeft)
  V("IMAGE_VIEW_ALIGNMENT_BOTTOM_RIGHT", NSImageAlignBottomRight)
  V("IMAGE_VIEW_ALIGNMENT_RIGHT", NSImageAlignRight)

  V("IMAGE_VIEW_FRAME_STYLE_NONE", NSImageFrameNone)
  V("IMAGE_VIEW_FRAME_STYLE_PHOTO", NSImageFramePhoto)
  V("IMAGE_VIEW_FRAME_STYLE_GRAY_BEZEL", NSImageFrameGrayBezel)
  V("IMAGE_VIEW_FRAME_STYLE_GROOVE", NSImageFrameGroove)
  V("IMAGE_VIEW_FRAME_STYLE_BUTTON", NSImageFrameButton)

  V("IMAGE_VIEW_SCALING_PROPORTIONALLY_DOWN", NSImageScaleProportionallyDown)
  V("IMAGE_VIEW_SCALING_AXES_INDEPENDENTLY", NSImageScaleAxesIndependently)
  V("IMAGE_VIEW_SCALING_NONE", NSImageScaleNone)
  V("IMAGE_VIEW_SCALING_PROPORTIONALLY_UP_OR_DOWN", NSImageScaleProportionallyUpOrDown)

  V("LAYOUT_ORIENTATION_HORIZONTAL", NSLayoutConstraintOrientationHorizontal)
  V("LAYOUT_ORIENTATION_VERTICAL", NSLayoutConstraintOrientationVertical)

  V("LAYOUT_RELATION_LESS_THAN_OR_EQUAL", NSLayoutRelationLessThanOrEqual)
  V("LAYOUT_RELATION_EQUAL", NSLayoutRelationEqual)
  V("LAYOUT_RELATION_GREATER_THAN_OR_EQUAL", NSLayoutRelationGreaterThanOrEqual)

  V("LEVEL_INDICATOR_STYLE_RELEVANCY", NSLevelIndicatorStyleRelevancy)
  V("LEVEL_INDICATOR_STYLE_CONTINUOUS_CAPACITY", NSLevelIndicatorStyleContinuousCapacity)
  V("LEVEL_INDICATOR_STYLE_DISCRETE_CAPACITY", NSLevelIndicatorStyleDiscreteCapacity)
  V("LEVEL_INDICATOR_STYLE_RATING", NSLevelIndicatorStyleRating)

  V("LINE_BREAK_MODE_WORD_WRAPPING", NSLineBreakByWordWrapping)
  V("LINE_BREAK_MODE_CHAR_WRAPPING", NSLineBreakByCharWrapping)
  V("LINE_BREAK_MODE_CLIPPING", NSLineBreakByClipping)
  V("LINE_BREAK_MODE_TRUNCATING_HEAD", NSLineBreakByTruncatingHead)
  V("LINE_BREAK_MODE_TRUNCATING_TAIL", NSLineBreakByTruncatingTail)
  V("LINE_BREAK_MODE_TRUNCATING_MIDDLE", NSLineBreakByTruncatingMiddle)

  V("MODAL_RESPONSE_OK", (int32_t) NSModalResponseOK)
  V("MODAL_RESPONSE_CANCEL", (int32_t) NSModalResponseCancel)
  V("MODAL_RESPONSE_STOP", (int32_t) NSModalResponseStop)
  V("MODAL_RESPONSE_ABORT", (int32_t) NSModalResponseAbort)
  V("MODAL_RESPONSE_CONTINUE", (int32_t) NSModalResponseContinue)
  V("MODAL_RESPONSE_FIRST_BUTTON", (int32_t) NSAlertFirstButtonReturn)
  V("MODAL_RESPONSE_SECOND_BUTTON", (int32_t) NSAlertSecondButtonReturn)
  V("MODAL_RESPONSE_THIRD_BUTTON", (int32_t) NSAlertThirdButtonReturn)

  V("PATH_CONTROL_STYLE_STANDARD", NSPathStyleStandard)
  V("PATH_CONTROL_STYLE_POP_UP", NSPathStylePopUp)

  V("POP_UP_BUTTON_EDGE_MIN_X", NSRectEdgeMinX)
  V("POP_UP_BUTTON_EDGE_MIN_Y", NSRectEdgeMinY)
  V("POP_UP_BUTTON_EDGE_MAX_X", NSRectEdgeMaxX)
  V("POP_UP_BUTTON_EDGE_MAX_Y", NSRectEdgeMaxY)

  V("PROGRESS_INDICATOR_STYLE_BAR", NSProgressIndicatorStyleBar)
  V("PROGRESS_INDICATOR_STYLE_SPINNING", NSProgressIndicatorStyleSpinning)


  V("SCROLL_VIEW_BORDER_TYPE_NONE", NSNoBorder)
  V("SCROLL_VIEW_BORDER_TYPE_LINE", NSLineBorder)
  V("SCROLL_VIEW_BORDER_TYPE_BEZEL", NSBezelBorder)
  V("SCROLL_VIEW_BORDER_TYPE_GROOVE", NSGrooveBorder)

  V("SCROLL_VIEW_ELASTICITY_AUTOMATIC", NSScrollElasticityAutomatic)
  V("SCROLL_VIEW_ELASTICITY_NONE", NSScrollElasticityNone)
  V("SCROLL_VIEW_ELASTICITY_ALLOWED", NSScrollElasticityAllowed)

  V("SCROLL_VIEW_SCROLLER_STYLE_LEGACY", NSScrollerStyleLegacy)
  V("SCROLL_VIEW_SCROLLER_STYLE_OVERLAY", NSScrollerStyleOverlay)

  V("SEGMENTED_CONTROL_DISTRIBUTION_FIT", NSSegmentDistributionFit)
  V("SEGMENTED_CONTROL_DISTRIBUTION_FILL", NSSegmentDistributionFill)
  V("SEGMENTED_CONTROL_DISTRIBUTION_FILL_EQUALLY", NSSegmentDistributionFillEqually)
  V("SEGMENTED_CONTROL_DISTRIBUTION_FILL_PROPORTIONALLY", NSSegmentDistributionFillProportionally)

  V("SEGMENTED_CONTROL_STYLE_AUTOMATIC", NSSegmentStyleAutomatic)
  V("SEGMENTED_CONTROL_STYLE_ROUNDED", NSSegmentStyleRounded)
  V("SEGMENTED_CONTROL_STYLE_ROUND_RECT", NSSegmentStyleRoundRect)
  V("SEGMENTED_CONTROL_STYLE_TEXTURED_SQUARE", NSSegmentStyleTexturedSquare)
  V("SEGMENTED_CONTROL_STYLE_SMALL_SQUARE", NSSegmentStyleSmallSquare)
  V("SEGMENTED_CONTROL_STYLE_SEPARATED", NSSegmentStyleSeparated)

  V("SEGMENTED_CONTROL_TRACKING_MODE_SELECT_ONE", NSSegmentSwitchTrackingSelectOne)
  V("SEGMENTED_CONTROL_TRACKING_MODE_SELECT_ANY", NSSegmentSwitchTrackingSelectAny)
  V("SEGMENTED_CONTROL_TRACKING_MODE_MOMENTARY", NSSegmentSwitchTrackingMomentary)
  V("SEGMENTED_CONTROL_TRACKING_MODE_MOMENTARY_ACCELERATOR", NSSegmentSwitchTrackingMomentaryAccelerator)

  V("SLIDER_TYPE_LINEAR", NSSliderTypeLinear)
  V("SLIDER_TYPE_CIRCULAR", NSSliderTypeCircular)

  V("SPLIT_VIEW_DIVIDER_STYLE_THICK", NSSplitViewDividerStyleThick)
  V("SPLIT_VIEW_DIVIDER_STYLE_THIN", NSSplitViewDividerStyleThin)
  V("SPLIT_VIEW_DIVIDER_STYLE_PANE_SPLITTER", NSSplitViewDividerStylePaneSplitter)

  V("STACK_VIEW_ALIGNMENT_LEADING", NSLayoutAttributeLeading)
  V("STACK_VIEW_ALIGNMENT_TRAILING", NSLayoutAttributeTrailing)
  V("STACK_VIEW_ALIGNMENT_TOP", NSLayoutAttributeTop)
  V("STACK_VIEW_ALIGNMENT_BOTTOM", NSLayoutAttributeBottom)
  V("STACK_VIEW_ALIGNMENT_CENTER_X", NSLayoutAttributeCenterX)
  V("STACK_VIEW_ALIGNMENT_CENTER_Y", NSLayoutAttributeCenterY)
  V("STACK_VIEW_ALIGNMENT_FIRST_BASELINE", NSLayoutAttributeFirstBaseline)
  V("STACK_VIEW_ALIGNMENT_WIDTH", NSLayoutAttributeWidth)
  V("STACK_VIEW_ALIGNMENT_HEIGHT", NSLayoutAttributeHeight)

  V("STACK_VIEW_DISTRIBUTION_GRAVITY_AREAS", NSStackViewDistributionGravityAreas)
  V("STACK_VIEW_DISTRIBUTION_FILL", NSStackViewDistributionFill)
  V("STACK_VIEW_DISTRIBUTION_FILL_EQUALLY", NSStackViewDistributionFillEqually)
  V("STACK_VIEW_DISTRIBUTION_FILL_PROPORTIONALLY", NSStackViewDistributionFillProportionally)
  V("STACK_VIEW_DISTRIBUTION_EQUAL_SPACING", NSStackViewDistributionEqualSpacing)
  V("STACK_VIEW_DISTRIBUTION_EQUAL_CENTERING", NSStackViewDistributionEqualCentering)

  V("STACK_VIEW_ORIENTATION_HORIZONTAL", NSUserInterfaceLayoutOrientationHorizontal)
  V("STACK_VIEW_ORIENTATION_VERTICAL", NSUserInterfaceLayoutOrientationVertical)

  V("STATUS_ITEM_LENGTH_VARIABLE", (int32_t) NSVariableStatusItemLength)
  V("STATUS_ITEM_LENGTH_SQUARE", (int32_t) NSSquareStatusItemLength)

  V("STRING_DRAWING_USES_LINE_FRAGMENT_ORIGIN", NSStringDrawingUsesLineFragmentOrigin)
  V("STRING_DRAWING_USES_FONT_LEADING", NSStringDrawingUsesFontLeading)
  V("STRING_DRAWING_USES_DEVICE_METRICS", NSStringDrawingUsesDeviceMetrics)
  V("STRING_DRAWING_TRUNCATES_LAST_VISIBLE_LINE", NSStringDrawingTruncatesLastVisibleLine)

  V("TABLE_COLUMN_RESIZING_NONE", NSTableColumnNoResizing)
  V("TABLE_COLUMN_RESIZING_AUTORESIZING", NSTableColumnAutoresizingMask)
  V("TABLE_COLUMN_RESIZING_USER_RESIZING", NSTableColumnUserResizingMask)

  V("TABLE_VIEW_COLUMN_AUTORESIZING_NONE", NSTableViewNoColumnAutoresizing)
  V("TABLE_VIEW_COLUMN_AUTORESIZING_UNIFORM", NSTableViewUniformColumnAutoresizingStyle)
  V("TABLE_VIEW_COLUMN_AUTORESIZING_SEQUENTIAL", NSTableViewSequentialColumnAutoresizingStyle)
  V("TABLE_VIEW_COLUMN_AUTORESIZING_REVERSE_SEQUENTIAL", NSTableViewReverseSequentialColumnAutoresizingStyle)
  V("TABLE_VIEW_COLUMN_AUTORESIZING_LAST_COLUMN_ONLY", NSTableViewLastColumnOnlyAutoresizingStyle)
  V("TABLE_VIEW_COLUMN_AUTORESIZING_FIRST_COLUMN_ONLY", NSTableViewFirstColumnOnlyAutoresizingStyle)

  V("TABLE_VIEW_GRID_NONE", NSTableViewGridNone)
  V("TABLE_VIEW_GRID_SOLID_VERTICAL", NSTableViewSolidVerticalGridLineMask)
  V("TABLE_VIEW_GRID_SOLID_HORIZONTAL", NSTableViewSolidHorizontalGridLineMask)
  V("TABLE_VIEW_GRID_DASHED_HORIZONTAL", NSTableViewDashedHorizontalGridLineMask)

  V("TABLE_VIEW_ROW_SIZE_STYLE_DEFAULT", NSTableViewRowSizeStyleDefault)
  V("TABLE_VIEW_ROW_SIZE_STYLE_CUSTOM", NSTableViewRowSizeStyleCustom)
  V("TABLE_VIEW_ROW_SIZE_STYLE_SMALL", NSTableViewRowSizeStyleSmall)
  V("TABLE_VIEW_ROW_SIZE_STYLE_MEDIUM", NSTableViewRowSizeStyleMedium)
  V("TABLE_VIEW_ROW_SIZE_STYLE_LARGE", NSTableViewRowSizeStyleLarge)

  V("TABLE_VIEW_STYLE_AUTOMATIC", NSTableViewStyleAutomatic)
  V("TABLE_VIEW_STYLE_FULL_WIDTH", NSTableViewStyleFullWidth)
  V("TABLE_VIEW_STYLE_INSET", NSTableViewStyleInset)
  V("TABLE_VIEW_STYLE_SOURCE_LIST", NSTableViewStyleSourceList)
  V("TABLE_VIEW_STYLE_PLAIN", NSTableViewStylePlain)

  V("TAB_VIEW_POSITION_NONE", NSTabPositionNone)
  V("TAB_VIEW_POSITION_TOP", NSTabPositionTop)
  V("TAB_VIEW_POSITION_LEFT", NSTabPositionLeft)
  V("TAB_VIEW_POSITION_BOTTOM", NSTabPositionBottom)
  V("TAB_VIEW_POSITION_RIGHT", NSTabPositionRight)

  V("TAB_VIEW_TYPE_TOP_TABS_BEZEL_BORDER", NSTopTabsBezelBorder)
  V("TAB_VIEW_TYPE_LEFT_TABS_BEZEL_BORDER", NSLeftTabsBezelBorder)
  V("TAB_VIEW_TYPE_BOTTOM_TABS_BEZEL_BORDER", NSBottomTabsBezelBorder)
  V("TAB_VIEW_TYPE_RIGHT_TABS_BEZEL_BORDER", NSRightTabsBezelBorder)
  V("TAB_VIEW_TYPE_NO_TABS_BEZEL_BORDER", NSNoTabsBezelBorder)
  V("TAB_VIEW_TYPE_NO_TABS_LINE_BORDER", NSNoTabsLineBorder)
  V("TAB_VIEW_TYPE_NO_TABS_NO_BORDER", NSNoTabsNoBorder)

  V("TEXT_ALIGNMENT_LEFT", NSTextAlignmentLeft)
  V("TEXT_ALIGNMENT_RIGHT", NSTextAlignmentRight)
  V("TEXT_ALIGNMENT_CENTER", NSTextAlignmentCenter)
  V("TEXT_ALIGNMENT_JUSTIFIED", NSTextAlignmentJustified)
  V("TEXT_ALIGNMENT_NATURAL", NSTextAlignmentNatural)

  V("TEXT_FIELD_BEZEL_STYLE_SQUARE", NSTextFieldSquareBezel)
  V("TEXT_FIELD_BEZEL_STYLE_ROUNDED", NSTextFieldRoundedBezel)

  V("TICK_MARK_POSITION_BELOW", NSTickMarkPositionBelow)
  V("TICK_MARK_POSITION_ABOVE", NSTickMarkPositionAbove)
  V("TICK_MARK_POSITION_LEADING", NSTickMarkPositionLeading)
  V("TICK_MARK_POSITION_TRAILING", NSTickMarkPositionTrailing)

  V("TOKEN_FIELD_STYLE_DEFAULT", NSTokenStyleDefault)
  V("TOKEN_FIELD_STYLE_NONE", NSTokenStyleNone)
  V("TOKEN_FIELD_STYLE_ROUNDED", NSTokenStyleRounded)
  V("TOKEN_FIELD_STYLE_SQUARED", NSTokenStyleSquared)
  V("TOKEN_FIELD_STYLE_PLAIN_SQUARED", NSTokenStylePlainSquared)

  V("TOOLBAR_DISPLAY_MODE_DEFAULT", NSToolbarDisplayModeDefault)
  V("TOOLBAR_DISPLAY_MODE_ICON_AND_LABEL", NSToolbarDisplayModeIconAndLabel)
  V("TOOLBAR_DISPLAY_MODE_ICON_ONLY", NSToolbarDisplayModeIconOnly)
  V("TOOLBAR_DISPLAY_MODE_LABEL_ONLY", NSToolbarDisplayModeLabelOnly)

  V("TOOLBAR_ITEM_GROUP_CONTROL_REPRESENTATION_AUTOMATIC", NSToolbarItemGroupControlRepresentationAutomatic)
  V("TOOLBAR_ITEM_GROUP_CONTROL_REPRESENTATION_EXPANDED", NSToolbarItemGroupControlRepresentationExpanded)
  V("TOOLBAR_ITEM_GROUP_CONTROL_REPRESENTATION_COLLAPSED", NSToolbarItemGroupControlRepresentationCollapsed)

  V("TOOLBAR_ITEM_GROUP_SELECTION_MODE_SELECT_ONE", NSToolbarItemGroupSelectionModeSelectOne)
  V("TOOLBAR_ITEM_GROUP_SELECTION_MODE_SELECT_ANY", NSToolbarItemGroupSelectionModeSelectAny)
  V("TOOLBAR_ITEM_GROUP_SELECTION_MODE_MOMENTARY", NSToolbarItemGroupSelectionModeMomentary)

  V("TOOLBAR_ITEM_VISIBILITY_PRIORITY_STANDARD", NSToolbarItemVisibilityPriorityStandard)
  V("TOOLBAR_ITEM_VISIBILITY_PRIORITY_LOW", NSToolbarItemVisibilityPriorityLow)
  V("TOOLBAR_ITEM_VISIBILITY_PRIORITY_HIGH", NSToolbarItemVisibilityPriorityHigh)
  V("TOOLBAR_ITEM_VISIBILITY_PRIORITY_USER", NSToolbarItemVisibilityPriorityUser)

  V("TRACKING_AREA_OPTIONS_MOUSE_ENTERED_AND_EXITED", NSTrackingMouseEnteredAndExited)
  V("TRACKING_AREA_OPTIONS_MOUSE_MOVED", NSTrackingMouseMoved)
  V("TRACKING_AREA_OPTIONS_CURSOR_UPDATE", NSTrackingCursorUpdate)
  V("TRACKING_AREA_OPTIONS_ACTIVE_WHEN_FIRST_RESPONDER", NSTrackingActiveWhenFirstResponder)
  V("TRACKING_AREA_OPTIONS_ACTIVE_IN_KEY_WINDOW", NSTrackingActiveInKeyWindow)
  V("TRACKING_AREA_OPTIONS_ACTIVE_IN_ACTIVE_APP", NSTrackingActiveInActiveApp)
  V("TRACKING_AREA_OPTIONS_ACTIVE_ALWAYS", NSTrackingActiveAlways)
  V("TRACKING_AREA_OPTIONS_ASSUME_INSIDE", NSTrackingAssumeInside)
  V("TRACKING_AREA_OPTIONS_IN_VISIBLE_RECT", NSTrackingInVisibleRect)
  V("TRACKING_AREA_OPTIONS_ENABLED_DURING_MOUSE_DRAG", NSTrackingEnabledDuringMouseDrag)

  V("UNDERLINE_STYLE_NONE", NSUnderlineStyleNone)
  V("UNDERLINE_STYLE_SINGLE", NSUnderlineStyleSingle)
  V("UNDERLINE_STYLE_THICK", NSUnderlineStyleThick)
  V("UNDERLINE_STYLE_DOUBLE", NSUnderlineStyleDouble)
  V("UNDERLINE_STYLE_PATTERN_DOT", NSUnderlinePatternDot)
  V("UNDERLINE_STYLE_PATTERN_DASH", NSUnderlinePatternDash)
  V("UNDERLINE_STYLE_BY_WORD", NSUnderlineByWord)

  V("VIEW_AUTORESIZING_NONE", NSViewNotSizable)
  V("VIEW_AUTORESIZING_MIN_X_MARGIN", NSViewMinXMargin)
  V("VIEW_AUTORESIZING_WIDTH_SIZABLE", NSViewWidthSizable)
  V("VIEW_AUTORESIZING_MAX_X_MARGIN", NSViewMaxXMargin)
  V("VIEW_AUTORESIZING_MIN_Y_MARGIN", NSViewMinYMargin)
  V("VIEW_AUTORESIZING_HEIGHT_SIZABLE", NSViewHeightSizable)
  V("VIEW_AUTORESIZING_MAX_Y_MARGIN", NSViewMaxYMargin)

  V("VIEW_EVENT_MOUSE_DOWN", bare_app_kit_view_event_mouse_down)
  V("VIEW_EVENT_MOUSE_UP", bare_app_kit_view_event_mouse_up)
  V("VIEW_EVENT_MOUSE_DRAGGED", bare_app_kit_view_event_mouse_dragged)
  V("VIEW_EVENT_MOUSE_MOVED", bare_app_kit_view_event_mouse_moved)
  V("VIEW_EVENT_RIGHT_MOUSE_DOWN", bare_app_kit_view_event_right_mouse_down)
  V("VIEW_EVENT_RIGHT_MOUSE_UP", bare_app_kit_view_event_right_mouse_up)
  V("VIEW_EVENT_MOUSE_ENTERED", bare_app_kit_view_event_mouse_entered)
  V("VIEW_EVENT_MOUSE_EXITED", bare_app_kit_view_event_mouse_exited)
  V("VIEW_EVENT_SCROLL_WHEEL", bare_app_kit_view_event_scroll_wheel)
  V("VIEW_EVENT_KEY_DOWN", bare_app_kit_view_event_key_down)
  V("VIEW_EVENT_KEY_UP", bare_app_kit_view_event_key_up)
  V("VIEW_EVENT_FLAGS_CHANGED", bare_app_kit_view_event_flags_changed)
  V("VIEW_EVENT_WILL_DRAW", bare_app_kit_view_event_will_draw)

  V("VIEW_FOCUS_RING_TYPE_DEFAULT", NSFocusRingTypeDefault)
  V("VIEW_FOCUS_RING_TYPE_NONE", NSFocusRingTypeNone)
  V("VIEW_FOCUS_RING_TYPE_EXTERIOR", NSFocusRingTypeExterior)

  V("VIEW_LAYER_REDRAW_POLICY_NEVER", NSViewLayerContentsRedrawNever)
  V("VIEW_LAYER_REDRAW_POLICY_ON_SET_NEEDS_DISPLAY", NSViewLayerContentsRedrawOnSetNeedsDisplay)
  V("VIEW_LAYER_REDRAW_POLICY_DURING_VIEW_RESIZE", NSViewLayerContentsRedrawDuringViewResize)
  V("VIEW_LAYER_REDRAW_POLICY_BEFORE_VIEW_RESIZE", NSViewLayerContentsRedrawBeforeViewResize)
  V("VIEW_LAYER_REDRAW_POLICY_CROSSFADE", NSViewLayerContentsRedrawCrossfade)

  V("VIEW_ORDERING_ABOVE", NSWindowAbove)
  V("VIEW_ORDERING_BELOW", NSWindowBelow)

  V("VISUAL_EFFECT_VIEW_BLENDING_MODE_BEHIND_WINDOW", NSVisualEffectBlendingModeBehindWindow)
  V("VISUAL_EFFECT_VIEW_BLENDING_MODE_WITHIN_WINDOW", NSVisualEffectBlendingModeWithinWindow)

  V("VISUAL_EFFECT_VIEW_MATERIAL_TITLEBAR", NSVisualEffectMaterialTitlebar)
  V("VISUAL_EFFECT_VIEW_MATERIAL_SELECTION", NSVisualEffectMaterialSelection)
  V("VISUAL_EFFECT_VIEW_MATERIAL_MENU", NSVisualEffectMaterialMenu)
  V("VISUAL_EFFECT_VIEW_MATERIAL_POPOVER", NSVisualEffectMaterialPopover)
  V("VISUAL_EFFECT_VIEW_MATERIAL_SIDEBAR", NSVisualEffectMaterialSidebar)
  V("VISUAL_EFFECT_VIEW_MATERIAL_HEADER_VIEW", NSVisualEffectMaterialHeaderView)
  V("VISUAL_EFFECT_VIEW_MATERIAL_SHEET", NSVisualEffectMaterialSheet)
  V("VISUAL_EFFECT_VIEW_MATERIAL_WINDOW_BACKGROUND", NSVisualEffectMaterialWindowBackground)
  V("VISUAL_EFFECT_VIEW_MATERIAL_HUD_WINDOW", NSVisualEffectMaterialHUDWindow)
  V("VISUAL_EFFECT_VIEW_MATERIAL_FULL_SCREEN_UI", NSVisualEffectMaterialFullScreenUI)
  V("VISUAL_EFFECT_VIEW_MATERIAL_TOOL_TIP", NSVisualEffectMaterialToolTip)
  V("VISUAL_EFFECT_VIEW_MATERIAL_CONTENT_BACKGROUND", NSVisualEffectMaterialContentBackground)
  V("VISUAL_EFFECT_VIEW_MATERIAL_UNDER_WINDOW_BACKGROUND", NSVisualEffectMaterialUnderWindowBackground)
  V("VISUAL_EFFECT_VIEW_MATERIAL_UNDER_PAGE_BACKGROUND", NSVisualEffectMaterialUnderPageBackground)

  V("VISUAL_EFFECT_VIEW_STATE_FOLLOWS_WINDOW_ACTIVE_STATE", NSVisualEffectStateFollowsWindowActiveState)
  V("VISUAL_EFFECT_VIEW_STATE_ACTIVE", NSVisualEffectStateActive)
  V("VISUAL_EFFECT_VIEW_STATE_INACTIVE", NSVisualEffectStateInactive)

  V("WINDOW_ANIMATION_BEHAVIOR_DEFAULT", NSWindowAnimationBehaviorDefault)
  V("WINDOW_ANIMATION_BEHAVIOR_NONE", NSWindowAnimationBehaviorNone)
  V("WINDOW_ANIMATION_BEHAVIOR_DOCUMENT_WINDOW", NSWindowAnimationBehaviorDocumentWindow)
  V("WINDOW_ANIMATION_BEHAVIOR_UTILITY_WINDOW", NSWindowAnimationBehaviorUtilityWindow)
  V("WINDOW_ANIMATION_BEHAVIOR_ALERT_PANEL", NSWindowAnimationBehaviorAlertPanel)

  V("WINDOW_COLLECTION_BEHAVIOR_DEFAULT", NSWindowCollectionBehaviorDefault)
  V("WINDOW_COLLECTION_BEHAVIOR_CAN_JOIN_ALL_SPACES", NSWindowCollectionBehaviorCanJoinAllSpaces)
  V("WINDOW_COLLECTION_BEHAVIOR_MOVE_TO_ACTIVE_SPACE", NSWindowCollectionBehaviorMoveToActiveSpace)
  V("WINDOW_COLLECTION_BEHAVIOR_MANAGED", NSWindowCollectionBehaviorManaged)
  V("WINDOW_COLLECTION_BEHAVIOR_TRANSIENT", NSWindowCollectionBehaviorTransient)
  V("WINDOW_COLLECTION_BEHAVIOR_STATIONARY", NSWindowCollectionBehaviorStationary)
  V("WINDOW_COLLECTION_BEHAVIOR_PARTICIPATES_IN_CYCLE", NSWindowCollectionBehaviorParticipatesInCycle)
  V("WINDOW_COLLECTION_BEHAVIOR_IGNORES_CYCLE", NSWindowCollectionBehaviorIgnoresCycle)
  V("WINDOW_COLLECTION_BEHAVIOR_FULL_SCREEN_PRIMARY", NSWindowCollectionBehaviorFullScreenPrimary)
  V("WINDOW_COLLECTION_BEHAVIOR_FULL_SCREEN_AUXILIARY", NSWindowCollectionBehaviorFullScreenAuxiliary)
  V("WINDOW_COLLECTION_BEHAVIOR_FULL_SCREEN_NONE", NSWindowCollectionBehaviorFullScreenNone)
  V("WINDOW_COLLECTION_BEHAVIOR_ALLOWS_TILING", NSWindowCollectionBehaviorFullScreenAllowsTiling)
  V("WINDOW_COLLECTION_BEHAVIOR_DISALLOWS_TILING", NSWindowCollectionBehaviorFullScreenDisallowsTiling)

  V("WINDOW_LEVEL_NORMAL", NSNormalWindowLevel)
  V("WINDOW_LEVEL_FLOATING", NSFloatingWindowLevel)
  V("WINDOW_LEVEL_SUBMENU", NSSubmenuWindowLevel)
  V("WINDOW_LEVEL_TORN_OFF_MENU", NSTornOffMenuWindowLevel)
  V("WINDOW_LEVEL_MODAL_PANEL", NSModalPanelWindowLevel)
  V("WINDOW_LEVEL_MAIN_MENU", NSMainMenuWindowLevel)
  V("WINDOW_LEVEL_STATUS", NSStatusWindowLevel)
  V("WINDOW_LEVEL_POP_UP_MENU", NSPopUpMenuWindowLevel)
  V("WINDOW_LEVEL_SCREEN_SAVER", NSScreenSaverWindowLevel)

  V("WINDOW_ORDERING_ABOVE", NSWindowAbove)
  V("WINDOW_ORDERING_BELOW", NSWindowBelow)
  V("WINDOW_ORDERING_OUT", NSWindowOut)

  V("WINDOW_STYLE_MASK_BORDERLESS", NSWindowStyleMaskBorderless)
  V("WINDOW_STYLE_MASK_TITLED", NSWindowStyleMaskTitled)
  V("WINDOW_STYLE_MASK_CLOSABLE", NSWindowStyleMaskClosable)
  V("WINDOW_STYLE_MASK_MINIATURIZABLE", NSWindowStyleMaskMiniaturizable)
  V("WINDOW_STYLE_MASK_RESIZABLE", NSWindowStyleMaskResizable)
  V("WINDOW_STYLE_MASK_UTILITY_WINDOW", NSWindowStyleMaskUtilityWindow)
  V("WINDOW_STYLE_MASK_DOC_MODAL_WINDOW", NSWindowStyleMaskDocModalWindow)
  V("WINDOW_STYLE_MASK_NONACTIVATING_PANEL", NSWindowStyleMaskNonactivatingPanel)
  V("WINDOW_STYLE_MASK_HUD_WINDOW", NSWindowStyleMaskHUDWindow)
  V("WINDOW_STYLE_MASK_FULL_SCREEN", NSWindowStyleMaskFullScreen)
  V("WINDOW_STYLE_MASK_FULL_SIZE_CONTENT_VIEW", NSWindowStyleMaskFullSizeContentView)

  V("WINDOW_TABBING_MODE_AUTOMATIC", NSWindowTabbingModeAutomatic)
  V("WINDOW_TABBING_MODE_PREFERRED", NSWindowTabbingModePreferred)
  V("WINDOW_TABBING_MODE_DISALLOWED", NSWindowTabbingModeDisallowed)

  V("WINDOW_TITLEBAR_SEPARATOR_STYLE_AUTOMATIC", NSTitlebarSeparatorStyleAutomatic)
  V("WINDOW_TITLEBAR_SEPARATOR_STYLE_NONE", NSTitlebarSeparatorStyleNone)
  V("WINDOW_TITLEBAR_SEPARATOR_STYLE_LINE", NSTitlebarSeparatorStyleLine)
  V("WINDOW_TITLEBAR_SEPARATOR_STYLE_SHADOW", NSTitlebarSeparatorStyleShadow)

  V("WINDOW_TITLE_VISIBILITY_VISIBLE", NSWindowTitleVisible)
  V("WINDOW_TITLE_VISIBILITY_HIDDEN", NSWindowTitleHidden)

  V("WINDOW_TOOLBAR_STYLE_AUTOMATIC", NSWindowToolbarStyleAutomatic)
  V("WINDOW_TOOLBAR_STYLE_EXPANDED", NSWindowToolbarStyleExpanded)
  V("WINDOW_TOOLBAR_STYLE_PREFERENCE", NSWindowToolbarStylePreference)
  V("WINDOW_TOOLBAR_STYLE_UNIFIED", NSWindowToolbarStyleUnified)
  V("WINDOW_TOOLBAR_STYLE_UNIFIED_COMPACT", NSWindowToolbarStyleUnifiedCompact)

  V("FONT_DESCRIPTOR_TRAIT_ITALIC", NSFontDescriptorTraitItalic)
  V("FONT_DESCRIPTOR_TRAIT_BOLD", NSFontDescriptorTraitBold)
  V("FONT_DESCRIPTOR_TRAIT_EXPANDED", NSFontDescriptorTraitExpanded)
  V("FONT_DESCRIPTOR_TRAIT_CONDENSED", NSFontDescriptorTraitCondensed)
  V("FONT_DESCRIPTOR_TRAIT_MONO_SPACE", NSFontDescriptorTraitMonoSpace)

  V("WRITING_DIRECTION_NATURAL", NSWritingDirectionNatural)
  V("WRITING_DIRECTION_LEFT_TO_RIGHT", NSWritingDirectionLeftToRight)
  V("WRITING_DIRECTION_RIGHT_TO_LEFT", NSWritingDirectionRightToLeft)
#undef V

#define W(name, n) \
  { \
    js_value_t *val; \
    err = js_create_double(env, n, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, exports, name, val); \
    assert(err == 0); \
  }

  W("FONT_WEIGHT_ULTRA_LIGHT", NSFontWeightUltraLight)
  W("FONT_WEIGHT_THIN", NSFontWeightThin)
  W("FONT_WEIGHT_LIGHT", NSFontWeightLight)
  W("FONT_WEIGHT_REGULAR", NSFontWeightRegular)
  W("FONT_WEIGHT_MEDIUM", NSFontWeightMedium)
  W("FONT_WEIGHT_SEMIBOLD", NSFontWeightSemibold)
  W("FONT_WEIGHT_BOLD", NSFontWeightBold)
  W("FONT_WEIGHT_HEAVY", NSFontWeightHeavy)
  W("FONT_WEIGHT_BLACK", NSFontWeightBlack)

  W("STACK_VIEW_VISIBILITY_PRIORITY_MUST_HOLD", NSStackViewVisibilityPriorityMustHold)
  W("STACK_VIEW_VISIBILITY_PRIORITY_DETACH_ONLY_IF_NECESSARY", NSStackViewVisibilityPriorityDetachOnlyIfNecessary)
  W("STACK_VIEW_VISIBILITY_PRIORITY_NOT_VISIBLE", NSStackViewVisibilityPriorityNotVisible)

  W("LAYOUT_PRIORITY_REQUIRED", NSLayoutPriorityRequired)
  W("LAYOUT_PRIORITY_DEFAULT_HIGH", NSLayoutPriorityDefaultHigh)
  W("LAYOUT_PRIORITY_DRAG_THAT_CAN_RESIZE_WINDOW", NSLayoutPriorityDragThatCanResizeWindow)
  W("LAYOUT_PRIORITY_WINDOW_SIZE_STAY_PUT", NSLayoutPriorityWindowSizeStayPut)
  W("LAYOUT_PRIORITY_DRAG_THAT_CANNOT_RESIZE_WINDOW", NSLayoutPriorityDragThatCannotResizeWindow)
  W("LAYOUT_PRIORITY_DEFAULT_LOW", NSLayoutPriorityDefaultLow)
  W("LAYOUT_PRIORITY_FITTING_SIZE_COMPRESSION", NSLayoutPriorityFittingSizeCompression)
#undef W

#define S(name, str) \
  { \
    js_value_t *val; \
    err = js_create_string_utf8(env, (const utf8_t *) [str UTF8String], -1, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, exports, name, val); \
    assert(err == 0); \
  }

  S("TOOLBAR_ITEM_SPACE", NSToolbarSpaceItemIdentifier)
  S("TOOLBAR_ITEM_FLEXIBLE_SPACE", NSToolbarFlexibleSpaceItemIdentifier)
  S("TOOLBAR_ITEM_TOGGLE_SIDEBAR", NSToolbarToggleSidebarItemIdentifier)
  S("TOOLBAR_ITEM_SIDEBAR_TRACKING_SEPARATOR", NSToolbarSidebarTrackingSeparatorItemIdentifier)
  S("TOOLBAR_ITEM_PRINT", NSToolbarPrintItemIdentifier)
  S("TOOLBAR_ITEM_SHOW_COLORS", NSToolbarShowColorsItemIdentifier)
  S("TOOLBAR_ITEM_SHOW_FONTS", NSToolbarShowFontsItemIdentifier)
  S("TOOLBAR_ITEM_CLOUD_SHARING", NSToolbarCloudSharingItemIdentifier)
  S("PASTEBOARD_TYPE_STRING", NSPasteboardTypeString)
  S("PASTEBOARD_TYPE_URL", NSPasteboardTypeURL)
  S("PASTEBOARD_TYPE_FILE_URL", NSPasteboardTypeFileURL)
  S("PASTEBOARD_TYPE_PNG", NSPasteboardTypePNG)
  S("PASTEBOARD_TYPE_TIFF", NSPasteboardTypeTIFF)
  S("PASTEBOARD_TYPE_PDF", NSPasteboardTypePDF)
  S("PASTEBOARD_TYPE_RTF", NSPasteboardTypeRTF)
  S("PASTEBOARD_TYPE_HTML", NSPasteboardTypeHTML)
  S("PASTEBOARD_TYPE_COLOR", NSPasteboardTypeColor)
  S("PASTEBOARD_TYPE_SOUND", NSPasteboardTypeSound)
  S("PASTEBOARD_TYPE_FONT", NSPasteboardTypeFont)
  S("PASTEBOARD_TYPE_TABULAR_TEXT", NSPasteboardTypeTabularText)

  S("APPEARANCE_NAME_AQUA", NSAppearanceNameAqua)
  S("APPEARANCE_NAME_DARK_AQUA", NSAppearanceNameDarkAqua)
  S("APPEARANCE_NAME_VIBRANT_LIGHT", NSAppearanceNameVibrantLight)
  S("APPEARANCE_NAME_VIBRANT_DARK", NSAppearanceNameVibrantDark)
  S("APPEARANCE_NAME_HIGH_CONTRAST_AQUA", NSAppearanceNameAccessibilityHighContrastAqua)
  S("APPEARANCE_NAME_HIGH_CONTRAST_DARK_AQUA", NSAppearanceNameAccessibilityHighContrastDarkAqua)
#undef S

  return exports;
}

BARE_MODULE(bare_app_kit, bare_app_kit_exports)
