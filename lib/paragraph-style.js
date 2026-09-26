const binding = require('../binding')
const { expose } = require('./handle')
const observe = require('./events')
const EventEmitter = require('bare-events')

module.exports = exports = class AppKitParagraphStyle extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init() {
    return binding.paragraphStyleInit()
  }

  get alignment() {
    return binding.paragraphStyleAlignment(this._tag)
  }

  set alignment(alignment) {
    binding.paragraphStyleAlignment(this._tag, alignment)
  }

  get lineSpacing() {
    return binding.paragraphStyleLineSpacing(this._tag)
  }

  set lineSpacing(lineSpacing) {
    binding.paragraphStyleLineSpacing(this._tag, lineSpacing)
  }

  get paragraphSpacing() {
    return binding.paragraphStyleParagraphSpacing(this._tag)
  }

  set paragraphSpacing(paragraphSpacing) {
    binding.paragraphStyleParagraphSpacing(this._tag, paragraphSpacing)
  }

  get paragraphSpacingBefore() {
    return binding.paragraphStyleParagraphSpacingBefore(this._tag)
  }

  set paragraphSpacingBefore(paragraphSpacingBefore) {
    binding.paragraphStyleParagraphSpacingBefore(this._tag, paragraphSpacingBefore)
  }

  get firstLineHeadIndent() {
    return binding.paragraphStyleFirstLineHeadIndent(this._tag)
  }

  set firstLineHeadIndent(firstLineHeadIndent) {
    binding.paragraphStyleFirstLineHeadIndent(this._tag, firstLineHeadIndent)
  }

  get headIndent() {
    return binding.paragraphStyleHeadIndent(this._tag)
  }

  set headIndent(headIndent) {
    binding.paragraphStyleHeadIndent(this._tag, headIndent)
  }

  get tailIndent() {
    return binding.paragraphStyleTailIndent(this._tag)
  }

  set tailIndent(tailIndent) {
    binding.paragraphStyleTailIndent(this._tag, tailIndent)
  }

  get lineHeightMultiple() {
    return binding.paragraphStyleLineHeightMultiple(this._tag)
  }

  set lineHeightMultiple(lineHeightMultiple) {
    binding.paragraphStyleLineHeightMultiple(this._tag, lineHeightMultiple)
  }

  get minimumLineHeight() {
    return binding.paragraphStyleMinimumLineHeight(this._tag)
  }

  set minimumLineHeight(minimumLineHeight) {
    binding.paragraphStyleMinimumLineHeight(this._tag, minimumLineHeight)
  }

  get maximumLineHeight() {
    return binding.paragraphStyleMaximumLineHeight(this._tag)
  }

  set maximumLineHeight(maximumLineHeight) {
    binding.paragraphStyleMaximumLineHeight(this._tag, maximumLineHeight)
  }

  get defaultTabInterval() {
    return binding.paragraphStyleDefaultTabInterval(this._tag)
  }

  set defaultTabInterval(defaultTabInterval) {
    binding.paragraphStyleDefaultTabInterval(this._tag, defaultTabInterval)
  }

  get hyphenationFactor() {
    return binding.paragraphStyleHyphenationFactor(this._tag)
  }

  set hyphenationFactor(hyphenationFactor) {
    binding.paragraphStyleHyphenationFactor(this._tag, hyphenationFactor)
  }

  get lineBreakMode() {
    return binding.paragraphStyleLineBreakMode(this._tag)
  }

  set lineBreakMode(lineBreakMode) {
    binding.paragraphStyleLineBreakMode(this._tag, lineBreakMode)
  }

  get baseWritingDirection() {
    return binding.paragraphStyleBaseWritingDirection(this._tag)
  }

  set baseWritingDirection(baseWritingDirection) {
    binding.paragraphStyleBaseWritingDirection(this._tag, baseWritingDirection)
  }

  get allowsDefaultTighteningForTruncation() {
    return binding.paragraphStyleAllowsDefaultTighteningForTruncation(this._tag)
  }

  set allowsDefaultTighteningForTruncation(allowsDefaultTighteningForTruncation) {
    binding.paragraphStyleAllowsDefaultTighteningForTruncation(
      this._tag,
      allowsDefaultTighteningForTruncation
    )
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitParagraphStyle }
    }
  }
}

exports.LINE_BREAK_MODE = {
  WORD_WRAPPING: binding.LINE_BREAK_MODE_WORD_WRAPPING,
  CHAR_WRAPPING: binding.LINE_BREAK_MODE_CHAR_WRAPPING,
  CLIPPING: binding.LINE_BREAK_MODE_CLIPPING,
  TRUNCATING_HEAD: binding.LINE_BREAK_MODE_TRUNCATING_HEAD,
  TRUNCATING_TAIL: binding.LINE_BREAK_MODE_TRUNCATING_TAIL,
  TRUNCATING_MIDDLE: binding.LINE_BREAK_MODE_TRUNCATING_MIDDLE
}

expose(exports)
