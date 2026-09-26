const binding = require('../binding')
const registry = require('bare-foundation-registry')

module.exports = exports = class AppKitCell {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  get [registry.tag]() {
    return this._tag
  }

  get [registry.handle]() {
    return binding.handle(this._tag)
  }

  drawingRectForBounds({ x = 0, y = 0, width = 0, height = 0 }) {
    return binding.cellDrawingRectForBounds(this._tag, x, y, width, height)
  }

  imageRectForBounds({ x = 0, y = 0, width = 0, height = 0 }) {
    return binding.cellImageRectForBounds(this._tag, x, y, width, height)
  }

  titleRectForBounds({ x = 0, y = 0, width = 0, height = 0 }) {
    return binding.cellTitleRectForBounds(this._tag, x, y, width, height)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitCell }
    }
  }
}
