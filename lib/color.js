const binding = require('../binding')
const wrap = require('./wrap')

module.exports = class AppKitColor {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  static rgb(red, green, blue, alpha = 1) {
    return new AppKitColor({ tag: binding.colorRGB(red, green, blue, alpha) })
  }

  static hsb(hue, saturation, brightness, alpha = 1) {
    return new AppKitColor({ tag: binding.colorHSB(hue, saturation, brightness, alpha) })
  }

  static white(white, alpha = 1) {
    return new AppKitColor({ tag: binding.colorWhite(white, alpha) })
  }

  static get blackColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_BLACK) })
  }

  static get whiteColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_WHITE) })
  }

  static get clearColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_CLEAR) })
  }

  static get labelColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_LABEL) })
  }

  static get secondaryLabelColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SECONDARY_LABEL) })
  }

  static get tertiaryLabelColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_TERTIARY_LABEL) })
  }

  static get quaternaryLabelColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_QUATERNARY_LABEL) })
  }

  static get textColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_TEXT) })
  }

  static get placeholderTextColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_PLACEHOLDER_TEXT) })
  }

  static get selectedTextColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SELECTED_TEXT) })
  }

  static get textBackgroundColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_TEXT_BACKGROUND) })
  }

  static get selectedTextBackgroundColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SELECTED_TEXT_BACKGROUND) })
  }

  static get linkColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_LINK) })
  }

  static get separatorColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SEPARATOR) })
  }

  static get gridColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_GRID) })
  }

  static get headerTextColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_HEADER_TEXT) })
  }

  static get controlAccentColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_CONTROL_ACCENT) })
  }

  static get controlColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_CONTROL) })
  }

  static get controlBackgroundColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_CONTROL_BACKGROUND) })
  }

  static get controlTextColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_CONTROL_TEXT) })
  }

  static get disabledControlTextColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_DISABLED_CONTROL_TEXT) })
  }

  static get selectedControlColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SELECTED_CONTROL) })
  }

  static get selectedControlTextColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SELECTED_CONTROL_TEXT) })
  }

  static get alternateSelectedControlTextColor() {
    return new AppKitColor({
      tag: binding.colorSystem(binding.COLOR_ALTERNATE_SELECTED_CONTROL_TEXT)
    })
  }

  static get selectedContentBackgroundColor() {
    return new AppKitColor({
      tag: binding.colorSystem(binding.COLOR_SELECTED_CONTENT_BACKGROUND)
    })
  }

  static get unemphasizedSelectedContentBackgroundColor() {
    return new AppKitColor({
      tag: binding.colorSystem(binding.COLOR_UNEMPHASIZED_SELECTED_CONTENT_BACKGROUND)
    })
  }

  static get windowBackgroundColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_WINDOW_BACKGROUND) })
  }

  static get windowFrameTextColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_WINDOW_FRAME_TEXT) })
  }

  static get underPageBackgroundColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_UNDER_PAGE_BACKGROUND) })
  }

  static get findHighlightColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_FIND_HIGHLIGHT) })
  }

  static get highlightColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_HIGHLIGHT) })
  }

  static get shadowColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SHADOW) })
  }

  static get systemRedColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_RED) })
  }

  static get systemOrangeColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_ORANGE) })
  }

  static get systemYellowColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_YELLOW) })
  }

  static get systemGreenColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_GREEN) })
  }

  static get systemMintColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_MINT) })
  }

  static get systemTealColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_TEAL) })
  }

  static get systemCyanColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_CYAN) })
  }

  static get systemBlueColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_BLUE) })
  }

  static get systemIndigoColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_INDIGO) })
  }

  static get systemPurpleColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_PURPLE) })
  }

  static get systemPinkColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_PINK) })
  }

  static get systemBrownColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_BROWN) })
  }

  static get systemGrayColor() {
    return new AppKitColor({ tag: binding.colorSystem(binding.COLOR_SYSTEM_GRAY) })
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
    return new AppKitColor({
      tag: binding.colorWithAlphaComponent(this._tag, alpha)
    })
  }

  blendedColor(fraction, color) {
    return new AppKitColor({
      tag: binding.colorBlendedColor(this._tag, fraction, color._tag)
    })
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitColor }
    }
  }
}
