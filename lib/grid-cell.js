const binding = require('../binding')
const { adopt, expose } = require('./handle')
const retain = require('./retain')
const AppKitView = require('./view')

module.exports = exports = class AppKitGridCell {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  get contentView() {
    return retain(this, '_contentView', AppKitView, binding.gridCellContentView(this._tag))
  }

  set contentView(contentView) {
    binding.gridCellContentView(this._tag, adopt(contentView))

    this._contentView = contentView
  }

  get xPlacement() {
    return binding.gridCellXPlacement(this._tag)
  }

  set xPlacement(xPlacement) {
    binding.gridCellXPlacement(this._tag, xPlacement)
  }

  get yPlacement() {
    return binding.gridCellYPlacement(this._tag)
  }

  set yPlacement(yPlacement) {
    binding.gridCellYPlacement(this._tag, yPlacement)
  }

  get rowAlignment() {
    return binding.gridCellRowAlignment(this._tag)
  }

  set rowAlignment(rowAlignment) {
    binding.gridCellRowAlignment(this._tag, rowAlignment)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitGridCell }
    }
  }
}

expose(exports)
