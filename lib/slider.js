const binding = require('../binding')
const { expose } = require('./handle')
const AppKitControl = require('./control')

module.exports = exports = class AppKitSlider extends AppKitControl {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.sliderInit(x, y, width, height, this)
  }

  get minValue() {
    return binding.sliderMinValue(this._tag)
  }

  set minValue(minValue) {
    binding.sliderMinValue(this._tag, minValue)
  }

  get maxValue() {
    return binding.sliderMaxValue(this._tag)
  }

  set maxValue(maxValue) {
    binding.sliderMaxValue(this._tag, maxValue)
  }

  get altIncrementValue() {
    return binding.sliderAltIncrementValue(this._tag)
  }

  set altIncrementValue(altIncrementValue) {
    binding.sliderAltIncrementValue(this._tag, altIncrementValue)
  }

  get knobThickness() {
    return binding.sliderKnobThickness(this._tag)
  }

  get vertical() {
    return binding.sliderVertical(this._tag)
  }

  set vertical(vertical) {
    binding.sliderVertical(this._tag, vertical)
  }

  get sliderType() {
    return binding.sliderType(this._tag)
  }

  set sliderType(sliderType) {
    binding.sliderType(this._tag, sliderType)
  }

  get numberOfTickMarks() {
    return binding.sliderNumberOfTickMarks(this._tag)
  }

  set numberOfTickMarks(numberOfTickMarks) {
    binding.sliderNumberOfTickMarks(this._tag, numberOfTickMarks)
  }

  get tickMarkPosition() {
    return binding.sliderTickMarkPosition(this._tag)
  }

  set tickMarkPosition(tickMarkPosition) {
    binding.sliderTickMarkPosition(this._tag, tickMarkPosition)
  }

  get allowsTickMarkValuesOnly() {
    return binding.sliderAllowsTickMarkValuesOnly(this._tag)
  }

  set allowsTickMarkValuesOnly(allowsTickMarkValuesOnly) {
    binding.sliderAllowsTickMarkValuesOnly(this._tag, allowsTickMarkValuesOnly)
  }

  tickMarkValueAtIndex(index) {
    return binding.sliderTickMarkValueAtIndex(this._tag, index)
  }

  closestTickMarkValueToValue(value) {
    return binding.sliderClosestTickMarkValueToValue(this._tag, value)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitSlider }
    }
  }

  _onchange() {
    this.emit('change')
  }
}

exports.TYPE = {
  LINEAR: binding.SLIDER_TYPE_LINEAR,
  CIRCULAR: binding.SLIDER_TYPE_CIRCULAR
}

exports.TICK_MARK_POSITION = {
  BELOW: binding.TICK_MARK_POSITION_BELOW,
  ABOVE: binding.TICK_MARK_POSITION_ABOVE,
  LEADING: binding.TICK_MARK_POSITION_LEADING,
  TRAILING: binding.TICK_MARK_POSITION_TRAILING
}

exports._events = {
  change: 1
}

expose(exports)
