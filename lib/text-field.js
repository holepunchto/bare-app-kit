const binding = require('../binding')
const { adopt } = require('./handle')
const wrap = require('./wrap')
const AppKitColor = require('./color')
const AppKitControl = require('./control')

module.exports = exports = class AppKitTextField extends AppKitControl {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.textFieldInit(x, y, width, height, this)
  }

  get placeholderString() {
    return binding.textFieldPlaceholderString(this._tag)
  }

  set placeholderString(placeholderString) {
    binding.textFieldPlaceholderString(this._tag, placeholderString)
  }

  get textColor() {
    return wrap(AppKitColor, binding.textFieldTextColor(this._tag))
  }

  set textColor(textColor) {
    binding.textFieldTextColor(this._tag, adopt(textColor))
  }

  get backgroundColor() {
    return wrap(AppKitColor, binding.textFieldBackgroundColor(this._tag))
  }

  set backgroundColor(backgroundColor) {
    binding.textFieldBackgroundColor(this._tag, adopt(backgroundColor))
  }

  get bordered() {
    return binding.textFieldBordered(this._tag)
  }

  set bordered(bordered) {
    binding.textFieldBordered(this._tag, bordered)
  }

  get bezeled() {
    return binding.textFieldBezeled(this._tag)
  }

  set bezeled(bezeled) {
    binding.textFieldBezeled(this._tag, bezeled)
  }

  get editable() {
    return binding.textFieldEditable(this._tag)
  }

  set editable(editable) {
    binding.textFieldEditable(this._tag, editable)
  }

  get selectable() {
    return binding.textFieldSelectable(this._tag)
  }

  set selectable(selectable) {
    binding.textFieldSelectable(this._tag, selectable)
  }

  get drawsBackground() {
    return binding.textFieldDrawsBackground(this._tag)
  }

  set drawsBackground(drawsBackground) {
    binding.textFieldDrawsBackground(this._tag, drawsBackground)
  }

  get bezelStyle() {
    return binding.textFieldBezelStyle(this._tag)
  }

  set bezelStyle(bezelStyle) {
    binding.textFieldBezelStyle(this._tag, bezelStyle)
  }

  get maximumNumberOfLines() {
    return binding.textFieldMaximumNumberOfLines(this._tag)
  }

  set maximumNumberOfLines(maximumNumberOfLines) {
    binding.textFieldMaximumNumberOfLines(this._tag, maximumNumberOfLines)
  }

  get preferredMaxLayoutWidth() {
    return binding.textFieldPreferredMaxLayoutWidth(this._tag)
  }

  set preferredMaxLayoutWidth(preferredMaxLayoutWidth) {
    binding.textFieldPreferredMaxLayoutWidth(this._tag, preferredMaxLayoutWidth)
  }

  selectText() {
    binding.textFieldSelectText(this._tag)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTextField }
    }
  }

  _onchange() {
    this.emit('change')
  }

  _oninput() {
    this.emit('didChange')
  }

  _onbeginediting() {
    this.emit('didBeginEditing')
  }

  _onendediting() {
    this.emit('didEndEditing')
  }

  _ondidchangeselection() {
    this.emit('didChangeSelection')
  }

  _onshouldchangetext(location, length, string) {
    this.emit('shouldChangeText', { location, length, string })
  }

  _onbecomefirstresponder() {
    this.emit('becomeFirstResponder')
  }

  _onresignfirstresponder() {
    this.emit('resignFirstResponder')
  }
}

exports._events = {
  change: 1,
  didChange: 2,
  didBeginEditing: 4,
  didEndEditing: 8,
  becomeFirstResponder: 16,
  resignFirstResponder: 32,
  didChangeSelection: 64,
  shouldChangeText: 128
}

exports.BEZEL_STYLE = {
  SQUARE: binding.TEXT_FIELD_BEZEL_STYLE_SQUARE,
  ROUNDED: binding.TEXT_FIELD_BEZEL_STYLE_ROUNDED
}
