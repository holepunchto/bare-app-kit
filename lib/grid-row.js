const binding = require('../binding')
const wrap = require('./wrap')
const AppKitGridCell = require('./grid-cell')

module.exports = exports = class AppKitGridRow {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  get numberOfCells() {
    return binding.gridRowNumberOfCells(this._tag)
  }

  get height() {
    return binding.gridRowHeight(this._tag)
  }

  set height(height) {
    binding.gridRowHeight(this._tag, height)
  }

  get topPadding() {
    return binding.gridRowTopPadding(this._tag)
  }

  set topPadding(topPadding) {
    binding.gridRowTopPadding(this._tag, topPadding)
  }

  get bottomPadding() {
    return binding.gridRowBottomPadding(this._tag)
  }

  set bottomPadding(bottomPadding) {
    binding.gridRowBottomPadding(this._tag, bottomPadding)
  }

  get yPlacement() {
    return binding.gridRowYPlacement(this._tag)
  }

  set yPlacement(yPlacement) {
    binding.gridRowYPlacement(this._tag, yPlacement)
  }

  get rowAlignment() {
    return binding.gridRowRowAlignment(this._tag)
  }

  set rowAlignment(rowAlignment) {
    binding.gridRowRowAlignment(this._tag, rowAlignment)
  }

  get hidden() {
    return binding.gridRowHidden(this._tag)
  }

  set hidden(hidden) {
    binding.gridRowHidden(this._tag, hidden)
  }

  cellAtIndex(index) {
    return wrap(AppKitGridCell, binding.gridRowCellAtIndex(this._tag, index))
  }

  mergeCells(index, count) {
    binding.gridRowMergeCells(this._tag, index, count)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitGridRow }
    }
  }
}
