const binding = require('../binding')
const AppKitControl = require('./control')

module.exports = exports = class AppKitStepper extends AppKitControl {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.stepperInit(x, y, width, height, this)
  }

  get minValue() {
    return binding.stepperMinValue(this._tag)
  }

  set minValue(minValue) {
    binding.stepperMinValue(this._tag, minValue)
  }

  get maxValue() {
    return binding.stepperMaxValue(this._tag)
  }

  set maxValue(maxValue) {
    binding.stepperMaxValue(this._tag, maxValue)
  }

  get increment() {
    return binding.stepperIncrement(this._tag)
  }

  set increment(increment) {
    binding.stepperIncrement(this._tag, increment)
  }

  get valueWraps() {
    return binding.stepperValueWraps(this._tag)
  }

  set valueWraps(valueWraps) {
    binding.stepperValueWraps(this._tag, valueWraps)
  }

  get autorepeat() {
    return binding.stepperAutorepeat(this._tag)
  }

  set autorepeat(autorepeat) {
    binding.stepperAutorepeat(this._tag, autorepeat)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitStepper }
    }
  }

  _onchange() {
    this.emit('change')
  }
}

exports._events = {
  change: 1
}
