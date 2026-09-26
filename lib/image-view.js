const binding = require('../binding')
const { adopt, expose } = require('./handle')
const wrap = require('./wrap')
const AppKitImage = require('./image')
const AppKitColor = require('./color')
const AppKitControl = require('./control')

module.exports = exports = class AppKitImageView extends AppKitControl {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.imageViewInit(x, y, width, height, this)
  }

  get image() {
    return wrap(AppKitImage, binding.imageViewImage(this._tag))
  }

  set image(image) {
    binding.imageViewImage(this._tag, adopt(image))
  }

  get imageScaling() {
    return binding.imageViewImageScaling(this._tag)
  }

  set imageScaling(imageScaling) {
    binding.imageViewImageScaling(this._tag, imageScaling)
  }

  get imageAlignment() {
    return binding.imageViewImageAlignment(this._tag)
  }

  set imageAlignment(imageAlignment) {
    binding.imageViewImageAlignment(this._tag, imageAlignment)
  }

  get imageFrameStyle() {
    return binding.imageViewImageFrameStyle(this._tag)
  }

  set imageFrameStyle(imageFrameStyle) {
    binding.imageViewImageFrameStyle(this._tag, imageFrameStyle)
  }

  get editable() {
    return binding.imageViewEditable(this._tag)
  }

  set editable(editable) {
    binding.imageViewEditable(this._tag, editable)
  }

  get animates() {
    return binding.imageViewAnimates(this._tag)
  }

  set animates(animates) {
    binding.imageViewAnimates(this._tag, animates)
  }

  get contentTintColor() {
    return wrap(AppKitColor, binding.imageViewContentTintColor(this._tag))
  }

  set contentTintColor(contentTintColor) {
    binding.imageViewContentTintColor(this._tag, adopt(contentTintColor))
  }

  _onwilldraw() {
    this.emit('willDraw')
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitImageView }
    }
  }

  _onchange() {
    this.emit('change')
  }
}

exports._events = {
  change: 1,
  willDraw: 2
}

exports.SCALING = {
  PROPORTIONALLY_DOWN: binding.IMAGE_VIEW_SCALING_PROPORTIONALLY_DOWN,
  AXES_INDEPENDENTLY: binding.IMAGE_VIEW_SCALING_AXES_INDEPENDENTLY,
  NONE: binding.IMAGE_VIEW_SCALING_NONE,
  PROPORTIONALLY_UP_OR_DOWN: binding.IMAGE_VIEW_SCALING_PROPORTIONALLY_UP_OR_DOWN
}

exports.ALIGNMENT = {
  CENTER: binding.IMAGE_VIEW_ALIGNMENT_CENTER,
  TOP: binding.IMAGE_VIEW_ALIGNMENT_TOP,
  TOP_LEFT: binding.IMAGE_VIEW_ALIGNMENT_TOP_LEFT,
  TOP_RIGHT: binding.IMAGE_VIEW_ALIGNMENT_TOP_RIGHT,
  LEFT: binding.IMAGE_VIEW_ALIGNMENT_LEFT,
  BOTTOM: binding.IMAGE_VIEW_ALIGNMENT_BOTTOM,
  BOTTOM_LEFT: binding.IMAGE_VIEW_ALIGNMENT_BOTTOM_LEFT,
  BOTTOM_RIGHT: binding.IMAGE_VIEW_ALIGNMENT_BOTTOM_RIGHT,
  RIGHT: binding.IMAGE_VIEW_ALIGNMENT_RIGHT
}

exports.FRAME_STYLE = {
  NONE: binding.IMAGE_VIEW_FRAME_STYLE_NONE,
  PHOTO: binding.IMAGE_VIEW_FRAME_STYLE_PHOTO,
  GRAY_BEZEL: binding.IMAGE_VIEW_FRAME_STYLE_GRAY_BEZEL,
  GROOVE: binding.IMAGE_VIEW_FRAME_STYLE_GROOVE,
  BUTTON: binding.IMAGE_VIEW_FRAME_STYLE_BUTTON
}

expose(exports)
