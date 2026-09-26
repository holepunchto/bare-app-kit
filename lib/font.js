const binding = require('../binding')
const scratch = require('./scratch')
const wrap = require('./wrap')
const AppKitFontDescriptor = require('./font-descriptor')

module.exports = exports = class AppKitFont {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  static systemFont(size, weight = binding.FONT_WEIGHT_REGULAR) {
    return wrap(AppKitFont, binding.fontSystemFont(size, weight))
  }

  static boldSystemFont(size) {
    return wrap(AppKitFont, binding.fontBoldSystemFont(size))
  }

  static monospacedSystemFont(size, weight = binding.FONT_WEIGHT_REGULAR) {
    return wrap(AppKitFont, binding.fontMonospacedSystemFont(size, weight))
  }

  static monospacedDigitSystemFont(size, weight = binding.FONT_WEIGHT_REGULAR) {
    return wrap(AppKitFont, binding.fontMonospacedDigitSystemFont(size, weight))
  }

  static withName(name, size) {
    return wrap(AppKitFont, binding.fontWithName(name, size))
  }

  static withDescriptor(descriptor, size) {
    return wrap(AppKitFont, binding.fontWithDescriptor(descriptor._tag, size))
  }

  get fontDescriptor() {
    return wrap(AppKitFontDescriptor, binding.fontFontDescriptor(this._tag))
  }

  get fontName() {
    return binding.fontFontName(this._tag)
  }

  get familyName() {
    return binding.fontFamilyName(this._tag)
  }

  get displayName() {
    return binding.fontDisplayName(this._tag)
  }

  get pointSize() {
    return binding.fontPointSize(this._tag)
  }

  get ascender() {
    return binding.fontAscender(this._tag)
  }

  get descender() {
    return binding.fontDescender(this._tag)
  }

  get capHeight() {
    return binding.fontCapHeight(this._tag)
  }

  get xHeight() {
    return binding.fontXHeight(this._tag)
  }

  get leading() {
    return binding.fontLeading(this._tag)
  }

  get italicAngle() {
    return binding.fontItalicAngle(this._tag)
  }

  get underlinePosition() {
    return binding.fontUnderlinePosition(this._tag)
  }

  get underlineThickness() {
    return binding.fontUnderlineThickness(this._tag)
  }

  get numberOfGlyphs() {
    return binding.fontNumberOfGlyphs(this._tag)
  }

  get fixedPitch() {
    return binding.fontFixedPitch(this._tag)
  }

  get boundingRectForFont() {
    binding.fontBoundingRectForFontInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1], width: scratch[2], height: scratch[3] }
  }

  get maximumAdvancement() {
    binding.fontMaximumAdvancementInto(this._tag, scratch.buffer, 0)

    return { width: scratch[0], height: scratch[1] }
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitFont }
    }
  }
}

exports.WEIGHT = {
  ULTRA_LIGHT: binding.FONT_WEIGHT_ULTRA_LIGHT,
  THIN: binding.FONT_WEIGHT_THIN,
  LIGHT: binding.FONT_WEIGHT_LIGHT,
  REGULAR: binding.FONT_WEIGHT_REGULAR,
  MEDIUM: binding.FONT_WEIGHT_MEDIUM,
  SEMIBOLD: binding.FONT_WEIGHT_SEMIBOLD,
  BOLD: binding.FONT_WEIGHT_BOLD,
  HEAVY: binding.FONT_WEIGHT_HEAVY,
  BLACK: binding.FONT_WEIGHT_BLACK
}
