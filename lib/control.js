const binding = require('../binding')
const { expose } = require('./handle')
const wrap = require('./wrap')
const AppKitAttributedString = require('./attributed-string')
const AppKitCell = require('./cell')
const AppKitFont = require('./font')
const AppKitText = require('./text')
const AppKitView = require('./view')

module.exports = exports = class AppKitControl extends AppKitView {
  get cell() {
    return wrap(AppKitCell, binding.controlCell(this._tag))
  }

  constructor(opts = {}) {
    super(opts)

    if (new.target === AppKitControl) {
      throw new TypeError('Control cannot be instantiated directly')
    }
  }

  get currentEditor() {
    return wrap(AppKitText, binding.controlCurrentEditor(this._tag))
  }

  get enabled() {
    return binding.controlEnabled(this._tag)
  }

  set enabled(enabled) {
    binding.controlEnabled(this._tag, enabled)
  }

  get continuous() {
    return binding.controlContinuous(this._tag)
  }

  set continuous(continuous) {
    binding.controlContinuous(this._tag, continuous)
  }

  get ignoresMultiClick() {
    return binding.controlIgnoresMultiClick(this._tag)
  }

  set ignoresMultiClick(ignoresMultiClick) {
    binding.controlIgnoresMultiClick(this._tag, ignoresMultiClick)
  }

  get highlighted() {
    return binding.controlHighlighted(this._tag)
  }

  set highlighted(highlighted) {
    binding.controlHighlighted(this._tag, highlighted)
  }

  get refusesFirstResponder() {
    return binding.controlRefusesFirstResponder(this._tag)
  }

  set refusesFirstResponder(refusesFirstResponder) {
    binding.controlRefusesFirstResponder(this._tag, refusesFirstResponder)
  }

  get tag() {
    return binding.controlTag(this._tag)
  }

  set tag(tag) {
    binding.controlTag(this._tag, tag)
  }

  get controlSize() {
    return binding.controlSize(this._tag)
  }

  set controlSize(controlSize) {
    binding.controlSize(this._tag, controlSize)
  }

  get stringValue() {
    return binding.controlStringValue(this._tag)
  }

  set stringValue(value) {
    binding.controlStringValue(this._tag, value)
  }

  get attributedStringValue() {
    return wrap(AppKitAttributedString, binding.controlAttributedStringValue(this._tag))
  }

  set attributedStringValue(value) {
    binding.controlAttributedStringValue(this._tag, value._tag)
  }

  get intValue() {
    return binding.controlIntValue(this._tag)
  }

  set intValue(value) {
    binding.controlIntValue(this._tag, value)
  }

  get integerValue() {
    return binding.controlIntegerValue(this._tag)
  }

  set integerValue(value) {
    binding.controlIntegerValue(this._tag, value)
  }

  get floatValue() {
    return binding.controlFloatValue(this._tag)
  }

  set floatValue(value) {
    binding.controlFloatValue(this._tag, value)
  }

  get doubleValue() {
    return binding.controlDoubleValue(this._tag)
  }

  set doubleValue(value) {
    binding.controlDoubleValue(this._tag, value)
  }

  sizeToFit() {
    binding.controlSizeToFit(this._tag)
    return this
  }

  performClick() {
    binding.controlPerformClick(this._tag)
    return this
  }

  get font() {
    return wrap(AppKitFont, binding.controlFont(this._tag))
  }

  set font(font) {
    binding.controlFont(this._tag, font === null ? null : font._tag)
  }

  get alignment() {
    return binding.controlAlignment(this._tag)
  }

  set alignment(alignment) {
    binding.controlAlignment(this._tag, alignment)
  }

  get lineBreakMode() {
    return binding.controlLineBreakMode(this._tag)
  }

  set lineBreakMode(lineBreakMode) {
    binding.controlLineBreakMode(this._tag, lineBreakMode)
  }

  get usesSingleLineMode() {
    return binding.controlUsesSingleLineMode(this._tag)
  }

  set usesSingleLineMode(usesSingleLineMode) {
    binding.controlUsesSingleLineMode(this._tag, usesSingleLineMode)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitControl }
    }
  }
}

exports.SIZE = {
  REGULAR: binding.CONTROL_SIZE_REGULAR,
  SMALL: binding.CONTROL_SIZE_SMALL,
  MINI: binding.CONTROL_SIZE_MINI,
  LARGE: binding.CONTROL_SIZE_LARGE
}

exports.STATE = {
  MIXED: binding.CONTROL_STATE_MIXED,
  OFF: binding.CONTROL_STATE_OFF,
  ON: binding.CONTROL_STATE_ON
}

exports.ALIGNMENT = {
  LEFT: binding.TEXT_ALIGNMENT_LEFT,
  RIGHT: binding.TEXT_ALIGNMENT_RIGHT,
  CENTER: binding.TEXT_ALIGNMENT_CENTER,
  JUSTIFIED: binding.TEXT_ALIGNMENT_JUSTIFIED,
  NATURAL: binding.TEXT_ALIGNMENT_NATURAL
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
