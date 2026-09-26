const binding = require('../binding')
const { unwrapAttributes } = require('./attributes')

module.exports = exports = class AppKitTextMeasurer {
  constructor() {
    this._tag = binding.textMeasurerInit()

    this._token = binding.claim(this._tag, this)
  }

  get lineFragmentPadding() {
    return binding.textMeasurerLineFragmentPadding(this._tag)
  }

  set lineFragmentPadding(lineFragmentPadding) {
    binding.textMeasurerLineFragmentPadding(this._tag, lineFragmentPadding)
  }

  get maximumNumberOfLines() {
    return binding.textMeasurerMaximumNumberOfLines(this._tag)
  }

  set maximumNumberOfLines(maximumNumberOfLines) {
    binding.textMeasurerMaximumNumberOfLines(this._tag, maximumNumberOfLines)
  }

  measure(string, attributes = {}, width = Infinity, height = Infinity) {
    return binding.textMeasurerMeasure(
      this._tag,
      string,
      unwrapAttributes(attributes),
      width,
      height
    )
  }

  measureAttributed(text, width = Infinity, height = Infinity) {
    return binding.textMeasurerMeasureAttributed(this._tag, text._tag, width, height)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTextMeasurer }
    }
  }
}
