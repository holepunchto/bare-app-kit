const binding = require('../binding')
const { expose } = require('./handle')
const wrap = require('./wrap')
const AppKitGridCell = require('./grid-cell')
const AppKitGridColumn = require('./grid-column')
const AppKitGridRow = require('./grid-row')
const AppKitView = require('./view')

module.exports = exports = class AppKitGridView extends AppKitView {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.gridViewInit(x, y, width, height)
  }

  get numberOfRows() {
    return binding.gridViewNumberOfRows(this._tag)
  }

  get numberOfColumns() {
    return binding.gridViewNumberOfColumns(this._tag)
  }

  get rowSpacing() {
    return binding.gridViewRowSpacing(this._tag)
  }

  set rowSpacing(rowSpacing) {
    binding.gridViewRowSpacing(this._tag, rowSpacing)
  }

  get columnSpacing() {
    return binding.gridViewColumnSpacing(this._tag)
  }

  set columnSpacing(columnSpacing) {
    binding.gridViewColumnSpacing(this._tag, columnSpacing)
  }

  get xPlacement() {
    return binding.gridViewXPlacement(this._tag)
  }

  set xPlacement(xPlacement) {
    binding.gridViewXPlacement(this._tag, xPlacement)
  }

  get yPlacement() {
    return binding.gridViewYPlacement(this._tag)
  }

  set yPlacement(yPlacement) {
    binding.gridViewYPlacement(this._tag, yPlacement)
  }

  get rowAlignment() {
    return binding.gridViewRowAlignment(this._tag)
  }

  set rowAlignment(rowAlignment) {
    binding.gridViewRowAlignment(this._tag, rowAlignment)
  }

  addRow(views) {
    return wrap(
      AppKitGridRow,
      binding.gridViewAddRow(
        this._tag,
        views.map((object) => object._tag)
      )
    )
  }

  insertRow(index, views) {
    return wrap(
      AppKitGridRow,
      binding.gridViewInsertRow(
        this._tag,
        index,
        views.map((object) => object._tag)
      )
    )
  }

  removeRow(index) {
    binding.gridViewRemoveRow(this._tag, index)
    return this
  }

  addColumn(views) {
    return wrap(
      AppKitGridColumn,
      binding.gridViewAddColumn(
        this._tag,
        views.map((object) => object._tag)
      )
    )
  }

  insertColumn(index, views) {
    return wrap(
      AppKitGridColumn,
      binding.gridViewInsertColumn(
        this._tag,
        index,
        views.map((object) => object._tag)
      )
    )
  }

  removeColumn(index) {
    binding.gridViewRemoveColumn(this._tag, index)
    return this
  }

  rowAtIndex(index) {
    return wrap(AppKitGridRow, binding.gridViewRowAtIndex(this._tag, index))
  }

  columnAtIndex(index) {
    return wrap(AppKitGridColumn, binding.gridViewColumnAtIndex(this._tag, index))
  }

  cellAt(column, row) {
    return wrap(AppKitGridCell, binding.gridViewCellAt(this._tag, column, row))
  }

  mergeCells(column, columns, row, rows) {
    binding.gridViewMergeCells(this._tag, column, columns, row, rows)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitGridView }
    }
  }
}

exports.PLACEMENT = {
  INHERITED: binding.GRID_PLACEMENT_INHERITED,
  NONE: binding.GRID_PLACEMENT_NONE,
  LEADING: binding.GRID_PLACEMENT_LEADING,
  TOP: binding.GRID_PLACEMENT_TOP,
  TRAILING: binding.GRID_PLACEMENT_TRAILING,
  BOTTOM: binding.GRID_PLACEMENT_BOTTOM,
  CENTER: binding.GRID_PLACEMENT_CENTER,
  FILL: binding.GRID_PLACEMENT_FILL
}

exports.ROW_ALIGNMENT = {
  INHERITED: binding.GRID_ROW_ALIGNMENT_INHERITED,
  NONE: binding.GRID_ROW_ALIGNMENT_NONE,
  FIRST_BASELINE: binding.GRID_ROW_ALIGNMENT_FIRST_BASELINE,
  LAST_BASELINE: binding.GRID_ROW_ALIGNMENT_LAST_BASELINE
}

expose(exports)
