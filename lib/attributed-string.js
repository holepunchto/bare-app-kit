const binding = require('../binding')
const { adopt } = require('./handle')
const observe = require('./events')
const wrap = require('./wrap')
const EventEmitter = require('bare-events')
const { wrapAttributes, unwrapAttributes } = require('./attributes')

module.exports = exports = class AppKitAttributedString extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init(opts) {
    const { string = '', attributes = {} } = opts

    return binding.attributedStringInit(string, unwrapAttributes(attributes))
  }

  static measure(string, attributes, width, height, options) {
    return binding.attributedStringMeasure(
      string,
      unwrapAttributes(attributes),
      width,
      height,
      options
    )
  }

  get string() {
    return binding.attributedStringString(this._tag)
  }

  get length() {
    return binding.attributedStringLength(this._tag)
  }

  attributesAt(location) {
    return wrapAttributes(binding.attributedStringAttributesAt(this._tag, location))
  }

  setAttributes(attributes, location, length) {
    binding.attributedStringSetAttributes(this._tag, unwrapAttributes(attributes), location, length)
    return this
  }

  addAttributes(attributes, location, length) {
    binding.attributedStringAddAttributes(this._tag, unwrapAttributes(attributes), location, length)
    return this
  }

  removeAttributes(location, length) {
    binding.attributedStringRemoveAttributes(this._tag, location, length)
    return this
  }

  append(other) {
    binding.attributedStringAppend(this._tag, adopt(other))
    return this
  }

  appendString(string, attributes) {
    binding.attributedStringAppendString(this._tag, string, unwrapAttributes(attributes))
    return this
  }

  replaceCharacters(location, length, string) {
    binding.attributedStringReplaceCharacters(this._tag, location, length, string)
    return this
  }

  substring(location, length) {
    return wrap(
      AppKitAttributedString,
      binding.attributedStringSubstring(this._tag, location, length)
    )
  }

  boundingRect(width, height, options) {
    return binding.attributedStringBoundingRect(this._tag, width, height, options)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitAttributedString }
    }
  }
}

exports.UNDERLINE = {
  NONE: binding.UNDERLINE_STYLE_NONE,
  SINGLE: binding.UNDERLINE_STYLE_SINGLE,
  THICK: binding.UNDERLINE_STYLE_THICK,
  DOUBLE: binding.UNDERLINE_STYLE_DOUBLE,
  PATTERN_DOT: binding.UNDERLINE_STYLE_PATTERN_DOT,
  PATTERN_DASH: binding.UNDERLINE_STYLE_PATTERN_DASH,
  BY_WORD: binding.UNDERLINE_STYLE_BY_WORD
}

exports.OPTIONS = {
  USES_LINE_FRAGMENT_ORIGIN: binding.STRING_DRAWING_USES_LINE_FRAGMENT_ORIGIN,
  USES_FONT_LEADING: binding.STRING_DRAWING_USES_FONT_LEADING,
  USES_DEVICE_METRICS: binding.STRING_DRAWING_USES_DEVICE_METRICS,
  TRUNCATES_LAST_VISIBLE_LINE: binding.STRING_DRAWING_TRUNCATES_LAST_VISIBLE_LINE
}
