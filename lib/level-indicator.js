const binding = require('../binding')
const { expose } = require('./handle')
const AppKitControl = require('./control')

module.exports = exports = class AppKitLevelIndicator extends AppKitControl {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.levelIndicatorInit(x, y, width, height, this)
  }

  get minValue() {
    return binding.levelIndicatorMinValue(this._tag)
  }

  set minValue(minValue) {
    binding.levelIndicatorMinValue(this._tag, minValue)
  }

  get maxValue() {
    return binding.levelIndicatorMaxValue(this._tag)
  }

  set maxValue(maxValue) {
    binding.levelIndicatorMaxValue(this._tag, maxValue)
  }

  get warningValue() {
    return binding.levelIndicatorWarningValue(this._tag)
  }

  set warningValue(warningValue) {
    binding.levelIndicatorWarningValue(this._tag, warningValue)
  }

  get criticalValue() {
    return binding.levelIndicatorCriticalValue(this._tag)
  }

  set criticalValue(criticalValue) {
    binding.levelIndicatorCriticalValue(this._tag, criticalValue)
  }

  get levelIndicatorStyle() {
    return binding.levelIndicatorStyle(this._tag)
  }

  set levelIndicatorStyle(levelIndicatorStyle) {
    binding.levelIndicatorStyle(this._tag, levelIndicatorStyle)
  }

  get numberOfTickMarks() {
    return binding.levelIndicatorNumberOfTickMarks(this._tag)
  }

  set numberOfTickMarks(numberOfTickMarks) {
    binding.levelIndicatorNumberOfTickMarks(this._tag, numberOfTickMarks)
  }

  get numberOfMajorTickMarks() {
    return binding.levelIndicatorNumberOfMajorTickMarks(this._tag)
  }

  set numberOfMajorTickMarks(numberOfMajorTickMarks) {
    binding.levelIndicatorNumberOfMajorTickMarks(this._tag, numberOfMajorTickMarks)
  }

  get tickMarkPosition() {
    return binding.levelIndicatorTickMarkPosition(this._tag)
  }

  set tickMarkPosition(tickMarkPosition) {
    binding.levelIndicatorTickMarkPosition(this._tag, tickMarkPosition)
  }

  get editable() {
    return binding.levelIndicatorEditable(this._tag)
  }

  set editable(editable) {
    binding.levelIndicatorEditable(this._tag, editable)
  }

  tickMarkValueAtIndex(index) {
    return binding.levelIndicatorTickMarkValueAtIndex(this._tag, index)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitLevelIndicator }
    }
  }

  _onchange() {
    this.emit('change')
  }
}

exports._events = {
  change: 1
}

exports.STYLE = {
  RELEVANCY: binding.LEVEL_INDICATOR_STYLE_RELEVANCY,
  CONTINUOUS_CAPACITY: binding.LEVEL_INDICATOR_STYLE_CONTINUOUS_CAPACITY,
  DISCRETE_CAPACITY: binding.LEVEL_INDICATOR_STYLE_DISCRETE_CAPACITY,
  RATING: binding.LEVEL_INDICATOR_STYLE_RATING
}

expose(exports)
