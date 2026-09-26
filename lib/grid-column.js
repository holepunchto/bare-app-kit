const binding = require('../binding')
const wrap = require('./wrap')
const AppKitGridCell = require('./grid-cell')

module.exports = exports = class AppKitGridColumn {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  get numberOfCells() {
    return binding.gridColumnNumberOfCells(this._tag)
  }

  get width() {
    return binding.gridColumnWidth(this._tag)
  }

  set width(width) {
    binding.gridColumnWidth(this._tag, width)
  }

  get leadingPadding() {
    return binding.gridColumnLeadingPadding(this._tag)
  }

  set leadingPadding(leadingPadding) {
    binding.gridColumnLeadingPadding(this._tag, leadingPadding)
  }

  get trailingPadding() {
    return binding.gridColumnTrailingPadding(this._tag)
  }

  set trailingPadding(trailingPadding) {
    binding.gridColumnTrailingPadding(this._tag, trailingPadding)
  }

  get xPlacement() {
    return binding.gridColumnXPlacement(this._tag)
  }

  set xPlacement(xPlacement) {
    binding.gridColumnXPlacement(this._tag, xPlacement)
  }

  get hidden() {
    return binding.gridColumnHidden(this._tag)
  }

  set hidden(hidden) {
    binding.gridColumnHidden(this._tag, hidden)
  }

  cellAtIndex(index) {
    return wrap(AppKitGridCell, binding.gridColumnCellAtIndex(this._tag, index))
  }

  mergeCells(index, count) {
    binding.gridColumnMergeCells(this._tag, index, count)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitGridColumn }
    }
  }
}
