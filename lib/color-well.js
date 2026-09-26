const binding = require('../binding')
const { adopt, expose } = require('./handle')
const wrap = require('./wrap')
const AppKitColor = require('./color')
const AppKitImage = require('./image')
const AppKitControl = require('./control')

module.exports = exports = class AppKitColorWell extends AppKitControl {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.colorWellInit(x, y, width, height, this)
  }

  get color() {
    return wrap(AppKitColor, binding.colorWellColor(this._tag))
  }

  set color(color) {
    binding.colorWellColor(this._tag, adopt(color))
  }

  get bordered() {
    return binding.colorWellBordered(this._tag)
  }

  set bordered(bordered) {
    binding.colorWellBordered(this._tag, bordered)
  }

  get active() {
    return binding.colorWellActive(this._tag)
  }

  get colorWellStyle() {
    return binding.colorWellColorWellStyle(this._tag)
  }

  set colorWellStyle(colorWellStyle) {
    binding.colorWellColorWellStyle(this._tag, colorWellStyle)
  }

  get image() {
    return wrap(AppKitImage, binding.colorWellImage(this._tag))
  }

  set image(image) {
    binding.colorWellImage(this._tag, adopt(image))
  }

  activate(exclusive) {
    binding.colorWellActivate(this._tag, exclusive)
    return this
  }

  deactivate() {
    binding.colorWellDeactivate(this._tag)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitColorWell }
    }
  }

  _onchange() {
    this.emit('change')
  }
}

exports._events = {
  change: 1
}

expose(exports)
