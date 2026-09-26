const binding = require('../binding')
const AppKitView = require('./view')

module.exports = exports = class AppKitProgressIndicator extends AppKitView {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.progressIndicatorInit(x, y, width, height)
  }

  get minValue() {
    return binding.progressIndicatorMinValue(this._tag)
  }

  set minValue(minValue) {
    binding.progressIndicatorMinValue(this._tag, minValue)
  }

  get maxValue() {
    return binding.progressIndicatorMaxValue(this._tag)
  }

  set maxValue(maxValue) {
    binding.progressIndicatorMaxValue(this._tag, maxValue)
  }

  get doubleValue() {
    return binding.progressIndicatorDoubleValue(this._tag)
  }

  set doubleValue(doubleValue) {
    binding.progressIndicatorDoubleValue(this._tag, doubleValue)
  }

  get indeterminate() {
    return binding.progressIndicatorIndeterminate(this._tag)
  }

  set indeterminate(indeterminate) {
    binding.progressIndicatorIndeterminate(this._tag, indeterminate)
  }

  get style() {
    return binding.progressIndicatorStyle(this._tag)
  }

  set style(style) {
    binding.progressIndicatorStyle(this._tag, style)
  }

  get controlSize() {
    return binding.progressIndicatorControlSize(this._tag)
  }

  set controlSize(controlSize) {
    binding.progressIndicatorControlSize(this._tag, controlSize)
  }

  get usesThreadedAnimation() {
    return binding.progressIndicatorUsesThreadedAnimation(this._tag)
  }

  set usesThreadedAnimation(usesThreadedAnimation) {
    binding.progressIndicatorUsesThreadedAnimation(this._tag, usesThreadedAnimation)
  }

  get displayedWhenStopped() {
    return binding.progressIndicatorDisplayedWhenStopped(this._tag)
  }

  set displayedWhenStopped(displayedWhenStopped) {
    binding.progressIndicatorDisplayedWhenStopped(this._tag, displayedWhenStopped)
  }

  startAnimation() {
    binding.progressIndicatorStartAnimation(this._tag)
    return this
  }

  stopAnimation() {
    binding.progressIndicatorStopAnimation(this._tag)
    return this
  }

  incrementBy(delta) {
    binding.progressIndicatorIncrementBy(this._tag, delta)
    return this
  }

  sizeToFit() {
    binding.progressIndicatorSizeToFit(this._tag)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitProgressIndicator }
    }
  }
}

exports.STYLE = {
  BAR: binding.PROGRESS_INDICATOR_STYLE_BAR,
  SPINNING: binding.PROGRESS_INDICATOR_STYLE_SPINNING
}
