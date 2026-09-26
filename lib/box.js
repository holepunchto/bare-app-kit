const binding = require('../binding')
const { adopt, expose } = require('./handle')
const scratch = require('./scratch')
const retain = require('./retain')
const wrap = require('./wrap')
const AppKitView = require('./view')
const AppKitColor = require('./color')
const AppKitFont = require('./font')

module.exports = exports = class AppKitBox extends AppKitView {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    this._contentView = null

    return binding.boxInit(x, y, width, height)
  }

  get title() {
    return binding.boxTitle(this._tag)
  }

  set title(title) {
    binding.boxTitle(this._tag, title)
  }

  get titlePosition() {
    return binding.boxTitlePosition(this._tag)
  }

  set titlePosition(titlePosition) {
    binding.boxTitlePosition(this._tag, titlePosition)
  }

  get boxType() {
    return binding.boxType(this._tag)
  }

  set boxType(boxType) {
    binding.boxType(this._tag, boxType)
  }

  get borderWidth() {
    return binding.boxBorderWidth(this._tag)
  }

  set borderWidth(borderWidth) {
    binding.boxBorderWidth(this._tag, borderWidth)
  }

  get cornerRadius() {
    return binding.boxCornerRadius(this._tag)
  }

  set cornerRadius(cornerRadius) {
    binding.boxCornerRadius(this._tag, cornerRadius)
  }

  get transparent() {
    return binding.boxTransparent(this._tag)
  }

  set transparent(transparent) {
    binding.boxTransparent(this._tag, transparent)
  }

  get contentViewMargins() {
    binding.boxContentViewMarginsInto(this._tag, scratch.buffer, 0)

    return { width: scratch[0], height: scratch[1] }
  }

  set contentViewMargins(contentViewMargins) {
    const { width = 0, height = 0 } = contentViewMargins

    binding.boxContentViewMargins(this._tag, width, height)
  }

  get contentView() {
    return retain(this, '_contentView', AppKitView, binding.boxContentView(this._tag))
  }

  set contentView(contentView) {
    binding.boxContentView(this._tag, adopt(contentView))

    this._contentView = contentView
  }

  get fillColor() {
    return wrap(AppKitColor, binding.boxFillColor(this._tag))
  }

  set fillColor(fillColor) {
    binding.boxFillColor(this._tag, adopt(fillColor))
  }

  get borderColor() {
    return wrap(AppKitColor, binding.boxBorderColor(this._tag))
  }

  set borderColor(borderColor) {
    binding.boxBorderColor(this._tag, adopt(borderColor))
  }

  get titleFont() {
    return wrap(AppKitFont, binding.boxTitleFont(this._tag))
  }

  set titleFont(titleFont) {
    binding.boxTitleFont(this._tag, adopt(titleFont))
  }

  sizeToFit() {
    binding.boxSizeToFit(this._tag)
    return this
  }

  setFrameFromContentFrame(x, y, width, height) {
    binding.boxSetFrameFromContentFrame(this._tag, x, y, width, height)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitBox }
    }
  }
}

exports.TYPE = {
  PRIMARY: binding.BOX_TYPE_PRIMARY,
  SEPARATOR: binding.BOX_TYPE_SEPARATOR,
  CUSTOM: binding.BOX_TYPE_CUSTOM
}

exports.TITLE_POSITION = {
  NONE: binding.BOX_TITLE_POSITION_NONE,
  ABOVE_TOP: binding.BOX_TITLE_POSITION_ABOVE_TOP,
  AT_TOP: binding.BOX_TITLE_POSITION_AT_TOP,
  BELOW_TOP: binding.BOX_TITLE_POSITION_BELOW_TOP,
  ABOVE_BOTTOM: binding.BOX_TITLE_POSITION_ABOVE_BOTTOM,
  AT_BOTTOM: binding.BOX_TITLE_POSITION_AT_BOTTOM,
  BELOW_BOTTOM: binding.BOX_TITLE_POSITION_BELOW_BOTTOM
}

expose(exports)
