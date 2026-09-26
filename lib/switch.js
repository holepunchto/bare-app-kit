const binding = require('../binding')
const { expose } = require('./handle')
const AppKitControl = require('./control')

module.exports = exports = class AppKitSwitch extends AppKitControl {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.switchInit(x, y, width, height, this)
  }

  get state() {
    return binding.switchState(this._tag)
  }

  set state(state) {
    binding.switchState(this._tag, state)
  }

  _onwilldraw() {
    this.emit('willDraw')
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitSwitch }
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

expose(exports)
