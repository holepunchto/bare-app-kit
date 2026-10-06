const binding = require('../binding')
const registry = require('bare-foundation-registry')
const wrap = require('./wrap')

module.exports = exports = class AppKitColor {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  get [registry.tag]() {
    return this._tag
  }

  get [registry.handle]() {
    return binding.handle(this._tag)
  }

  static rgb(red, green, blue, alpha = 1) {
    return wrap(AppKitColor, binding.colorRGB(red, green, blue, alpha))
  }

  static hsb(hue, saturation, brightness, alpha = 1) {
    return wrap(AppKitColor, binding.colorHSB(hue, saturation, brightness, alpha))
  }

  static white(white, alpha = 1) {
    return wrap(AppKitColor, binding.colorWhite(white, alpha))
  }

  static get blackColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_BLACK))
  }

  static get whiteColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_WHITE))
  }

  static get clearColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_CLEAR))
  }

  static get labelColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_LABEL))
  }

  static get secondaryLabelColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SECONDARY_LABEL))
  }

  static get tertiaryLabelColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_TERTIARY_LABEL))
  }

  static get quaternaryLabelColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_QUATERNARY_LABEL))
  }

  static get textColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_TEXT))
  }

  static get placeholderTextColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_PLACEHOLDER_TEXT))
  }

  static get selectedTextColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SELECTED_TEXT))
  }

  static get textBackgroundColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_TEXT_BACKGROUND))
  }

  static get selectedTextBackgroundColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SELECTED_TEXT_BACKGROUND))
  }

  static get linkColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_LINK))
  }

  static get separatorColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SEPARATOR))
  }

  static get gridColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_GRID))
  }

  static get headerTextColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_HEADER_TEXT))
  }

  static get controlAccentColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_CONTROL_ACCENT))
  }

  static get controlColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_CONTROL))
  }

  static get controlBackgroundColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_CONTROL_BACKGROUND))
  }

  static get controlTextColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_CONTROL_TEXT))
  }

  static get disabledControlTextColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_DISABLED_CONTROL_TEXT))
  }

  static get selectedControlColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SELECTED_CONTROL))
  }

  static get selectedControlTextColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SELECTED_CONTROL_TEXT))
  }

  static get alternateSelectedControlTextColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_ALTERNATE_SELECTED_CONTROL_TEXT))
  }

  static get selectedContentBackgroundColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SELECTED_CONTENT_BACKGROUND))
  }

  static get unemphasizedSelectedContentBackgroundColor() {
    return wrap(
      AppKitColor,
      binding.colorSystem(binding.COLOR_UNEMPHASIZED_SELECTED_CONTENT_BACKGROUND)
    )
  }

  static get windowBackgroundColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_WINDOW_BACKGROUND))
  }

  static get windowFrameTextColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_WINDOW_FRAME_TEXT))
  }

  static get underPageBackgroundColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_UNDER_PAGE_BACKGROUND))
  }

  static get findHighlightColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_FIND_HIGHLIGHT))
  }

  static get highlightColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_HIGHLIGHT))
  }

  static get shadowColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SHADOW))
  }

  static get systemRedColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_RED))
  }

  static get systemOrangeColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_ORANGE))
  }

  static get systemYellowColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_YELLOW))
  }

  static get systemGreenColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_GREEN))
  }

  static get systemMintColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_MINT))
  }

  static get systemTealColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_TEAL))
  }

  static get systemCyanColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_CYAN))
  }

  static get systemBlueColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_BLUE))
  }

  static get systemIndigoColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_INDIGO))
  }

  static get systemPurpleColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_PURPLE))
  }

  static get systemPinkColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_PINK))
  }

  static get systemBrownColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_BROWN))
  }

  static get systemGrayColor() {
    return wrap(AppKitColor, binding.colorSystem(binding.COLOR_SYSTEM_GRAY))
  }

  get type() {
    return binding.colorType(this._tag)
  }

  get numberOfComponents() {
    return binding.colorNumberOfComponents(this._tag)
  }

  static withPatternImage(image) {
    return wrap(AppKitColor, binding.colorWithPatternImage(image._tag))
  }

  highlight(level) {
    return wrap(AppKitColor, binding.colorHighlight(this._tag, level))
  }

  shadow(level) {
    return wrap(AppKitColor, binding.colorShadow(this._tag, level))
  }

  withSystemEffect(effect) {
    return wrap(AppKitColor, binding.colorWithSystemEffect(this._tag, effect))
  }

  get alphaComponent() {
    return binding.colorAlphaComponent(this._tag)
  }

  get components() {
    return binding.colorComponents(this._tag)
  }

  withAlphaComponent(alpha) {
    return wrap(AppKitColor, binding.colorWithAlphaComponent(this._tag, alpha))
  }

  blendedColor(fraction, color) {
    return wrap(AppKitColor, binding.colorBlendedColor(this._tag, fraction, color._tag))
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitColor }
    }
  }
}
