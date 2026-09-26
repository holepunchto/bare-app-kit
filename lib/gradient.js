const binding = require('../binding')
const { adopt } = require('./handle')
const observe = require('./events')
const wrap = require('./wrap')
const EventEmitter = require('bare-events')
const AppKitColor = require('./color')

module.exports = exports = class AppKitGradient extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init(opts) {
    const { colors = [] } = opts

    return binding.gradientInit(colors.map((object) => object._tag))
  }

  get numberOfColorStops() {
    return binding.gradientNumberOfColorStops(this._tag)
  }

  drawInRect(x, y, width, height, angle) {
    binding.gradientDrawInRect(this._tag, x, y, width, height, angle)
    return this
  }

  drawInPath(path, angle) {
    binding.gradientDrawInPath(this._tag, adopt(path), angle)
    return this
  }

  interpolatedColorAt(location) {
    return wrap(AppKitColor, binding.gradientInterpolatedColorAt(this._tag, location))
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitGradient }
    }
  }
}
