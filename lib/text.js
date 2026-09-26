const binding = require('../binding')
const wrap = require('./wrap')
const AppKitColor = require('./color')
const AppKitFont = require('./font')
const AppKitView = require('./view')

module.exports = exports = class AppKitText extends AppKitView {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.textInit(x, y, width, height)
  }

  get string() {
    return binding.textString(this._tag)
  }

  set string(string) {
    binding.textString(this._tag, string)
  }

  get editable() {
    return binding.textEditable(this._tag)
  }

  set editable(editable) {
    binding.textEditable(this._tag, editable)
  }

  get selectable() {
    return binding.textSelectable(this._tag)
  }

  set selectable(selectable) {
    binding.textSelectable(this._tag, selectable)
  }

  get richText() {
    return binding.textRichText(this._tag)
  }

  set richText(richText) {
    binding.textRichText(this._tag, richText)
  }

  get importsGraphics() {
    return binding.textImportsGraphics(this._tag)
  }

  set importsGraphics(importsGraphics) {
    binding.textImportsGraphics(this._tag, importsGraphics)
  }

  get fieldEditor() {
    return binding.textFieldEditor(this._tag)
  }

  set fieldEditor(fieldEditor) {
    binding.textFieldEditor(this._tag, fieldEditor)
  }

  get usesFontPanel() {
    return binding.textUsesFontPanel(this._tag)
  }

  set usesFontPanel(usesFontPanel) {
    binding.textUsesFontPanel(this._tag, usesFontPanel)
  }

  get drawsBackground() {
    return binding.textDrawsBackground(this._tag)
  }

  set drawsBackground(drawsBackground) {
    binding.textDrawsBackground(this._tag, drawsBackground)
  }

  get rulerVisible() {
    return binding.textRulerVisible(this._tag)
  }

  get alignment() {
    return binding.textAlignment(this._tag)
  }

  set alignment(alignment) {
    binding.textAlignment(this._tag, alignment)
  }

  get baseWritingDirection() {
    return binding.textBaseWritingDirection(this._tag)
  }

  set baseWritingDirection(baseWritingDirection) {
    binding.textBaseWritingDirection(this._tag, baseWritingDirection)
  }

  sizeToFit() {
    binding.textSizeToFit(this._tag)
    return this
  }

  copy() {
    binding.textCopy(this._tag)
    return this
  }

  cut() {
    binding.textCut(this._tag)
    return this
  }

  paste() {
    binding.textPaste(this._tag)
    return this
  }

  delete() {
    binding.textDelete(this._tag)
    return this
  }

  get selectedRange() {
    return binding.textSelectedRange(this._tag)
  }

  set selectedRange(selectedRange) {
    const { location = 0, length = 0 } = selectedRange

    binding.textSelectedRange(this._tag, location, length)
  }

  selectAll() {
    binding.textSelectAll(this._tag)
    return this
  }

  get font() {
    return wrap(AppKitFont, binding.textFont(this._tag))
  }

  set font(font) {
    binding.textFont(this._tag, font === null ? null : font._tag)
  }

  get textColor() {
    return wrap(AppKitColor, binding.textTextColor(this._tag))
  }

  set textColor(textColor) {
    binding.textTextColor(this._tag, textColor === null ? null : textColor._tag)
  }

  get backgroundColor() {
    return wrap(AppKitColor, binding.textBackgroundColor(this._tag))
  }

  set backgroundColor(backgroundColor) {
    binding.textBackgroundColor(this._tag, backgroundColor === null ? null : backgroundColor._tag)
  }

  get verticallyResizable() {
    return binding.textVerticallyResizable(this._tag)
  }

  set verticallyResizable(verticallyResizable) {
    binding.textVerticallyResizable(this._tag, verticallyResizable)
  }

  get horizontallyResizable() {
    return binding.textHorizontallyResizable(this._tag)
  }

  set horizontallyResizable(horizontallyResizable) {
    binding.textHorizontallyResizable(this._tag, horizontallyResizable)
  }

  get minSize() {
    return binding.textMinSize(this._tag)
  }

  set minSize(minSize) {
    const { width = 0, height = 0 } = minSize

    binding.textMinSize(this._tag, width, height)
  }

  get maxSize() {
    return binding.textMaxSize(this._tag)
  }

  set maxSize(maxSize) {
    const { width = 0, height = 0 } = maxSize

    binding.textMaxSize(this._tag, width, height)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitText }
    }
  }
}

exports.ALIGNMENT = {
  LEFT: binding.TEXT_ALIGNMENT_LEFT,
  RIGHT: binding.TEXT_ALIGNMENT_RIGHT,
  CENTER: binding.TEXT_ALIGNMENT_CENTER,
  JUSTIFIED: binding.TEXT_ALIGNMENT_JUSTIFIED,
  NATURAL: binding.TEXT_ALIGNMENT_NATURAL
}

exports.WRITING_DIRECTION = {
  NATURAL: binding.WRITING_DIRECTION_NATURAL,
  LEFT_TO_RIGHT: binding.WRITING_DIRECTION_LEFT_TO_RIGHT,
  RIGHT_TO_LEFT: binding.WRITING_DIRECTION_RIGHT_TO_LEFT
}
