const binding = require('../binding')
const { adopt } = require('./handle')
const retain = require('./retain')
const wrap = require('./wrap')
const AppKitColor = require('./color')
const AppKitTableColumn = require('./table-column')
const AppKitView = require('./view')

module.exports = exports = class AppKitTableView extends AppKitView {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0, makeView = null, numberOfRows = 0 } = opts

    this._backgroundColor = null
    this._gridColor = null
    this._headerView = null
    this._views = new Map()

    // Supplied by the caller, here or as a property: (identifier, row) -> View.
    // Called once per cell until `reloadData()`, so it does not have to tag
    // reuse itself.
    this.makeView = makeView

    const tag = binding.tableViewInit(x, y, width, height, this, this._makeview)

    binding.tableViewNumberOfRows(tag, numberOfRows)

    return tag
  }

  get numberOfRows() {
    return binding.tableViewNumberOfRows(this._tag)
  }

  set numberOfRows(numberOfRows) {
    binding.tableViewNumberOfRows(this._tag, numberOfRows)
  }

  get columns() {
    return binding.tableViewColumns(this._tag).map((tag) => wrap(AppKitTableColumn, tag))
  }

  addTableColumn(column) {
    binding.tableViewAddTableColumn(this._tag, adopt(column))
    this._retained.add(column)
    return this
  }

  removeTableColumn(column) {
    binding.tableViewRemoveTableColumn(this._tag, adopt(column))
    this._retained.delete(column)
    return this
  }

  reloadData() {
    this._views.clear()
    binding.tableViewReloadData(this._tag)
    return this
  }

  get rowHeight() {
    return binding.tableViewRowHeight(this._tag)
  }

  set rowHeight(rowHeight) {
    binding.tableViewRowHeight(this._tag, rowHeight)
  }

  get intercellSpacing() {
    return binding.tableViewIntercellSpacing(this._tag)
  }

  set intercellSpacing(intercellSpacing) {
    const { width = 0, height = 0 } = intercellSpacing

    binding.tableViewIntercellSpacing(this._tag, width, height)
  }

  get usesAlternatingRowBackgroundColors() {
    return binding.tableViewUsesAlternatingRowBackgroundColors(this._tag)
  }

  set usesAlternatingRowBackgroundColors(usesAlternatingRowBackgroundColors) {
    binding.tableViewUsesAlternatingRowBackgroundColors(
      this._tag,
      usesAlternatingRowBackgroundColors
    )
  }

  get usesAutomaticRowHeights() {
    return binding.tableViewUsesAutomaticRowHeights(this._tag)
  }

  set usesAutomaticRowHeights(usesAutomaticRowHeights) {
    binding.tableViewUsesAutomaticRowHeights(this._tag, usesAutomaticRowHeights)
  }

  get allowsMultipleSelection() {
    return binding.tableViewAllowsMultipleSelection(this._tag)
  }

  set allowsMultipleSelection(allowsMultipleSelection) {
    binding.tableViewAllowsMultipleSelection(this._tag, allowsMultipleSelection)
  }

  get allowsEmptySelection() {
    return binding.tableViewAllowsEmptySelection(this._tag)
  }

  set allowsEmptySelection(allowsEmptySelection) {
    binding.tableViewAllowsEmptySelection(this._tag, allowsEmptySelection)
  }

  get allowsColumnReordering() {
    return binding.tableViewAllowsColumnReordering(this._tag)
  }

  set allowsColumnReordering(allowsColumnReordering) {
    binding.tableViewAllowsColumnReordering(this._tag, allowsColumnReordering)
  }

  get allowsColumnResizing() {
    return binding.tableViewAllowsColumnResizing(this._tag)
  }

  set allowsColumnResizing(allowsColumnResizing) {
    binding.tableViewAllowsColumnResizing(this._tag, allowsColumnResizing)
  }

  get allowsColumnSelection() {
    return binding.tableViewAllowsColumnSelection(this._tag)
  }

  set allowsColumnSelection(allowsColumnSelection) {
    binding.tableViewAllowsColumnSelection(this._tag, allowsColumnSelection)
  }

  get style() {
    return binding.tableViewStyle(this._tag)
  }

  set style(style) {
    binding.tableViewStyle(this._tag, style)
  }

  get gridStyleMask() {
    return binding.tableViewGridStyleMask(this._tag)
  }

  set gridStyleMask(gridStyleMask) {
    binding.tableViewGridStyleMask(this._tag, gridStyleMask)
  }

  get rowSizeStyle() {
    return binding.tableViewRowSizeStyle(this._tag)
  }

  set rowSizeStyle(rowSizeStyle) {
    binding.tableViewRowSizeStyle(this._tag, rowSizeStyle)
  }

  get columnAutoresizingStyle() {
    return binding.tableViewColumnAutoresizingStyle(this._tag)
  }

  set columnAutoresizingStyle(columnAutoresizingStyle) {
    binding.tableViewColumnAutoresizingStyle(this._tag, columnAutoresizingStyle)
  }

  get backgroundColor() {
    return retain(
      this,
      '_backgroundColor',
      AppKitColor,
      binding.tableViewBackgroundColor(this._tag)
    )
  }

  set backgroundColor(backgroundColor) {
    binding.tableViewBackgroundColor(
      this._tag,
      backgroundColor === null ? null : backgroundColor._tag
    )

    this._backgroundColor = backgroundColor
  }

  get gridColor() {
    return retain(this, '_gridColor', AppKitColor, binding.tableViewGridColor(this._tag))
  }

  set gridColor(gridColor) {
    binding.tableViewGridColor(this._tag, gridColor === null ? null : gridColor._tag)

    this._gridColor = gridColor
  }

  get headerView() {
    return retain(this, '_headerView', AppKitView, binding.tableViewHeaderView(this._tag))
  }

  set headerView(headerView) {
    binding.tableViewHeaderView(this._tag, headerView === null ? null : headerView._tag)

    this._headerView = headerView
  }

  get numberOfColumns() {
    return binding.tableViewNumberOfColumns(this._tag)
  }

  get selectedRow() {
    return binding.tableViewSelectedRow(this._tag)
  }

  get selectedColumn() {
    return binding.tableViewSelectedColumn(this._tag)
  }

  get clickedRow() {
    return binding.tableViewClickedRow(this._tag)
  }

  get clickedColumn() {
    return binding.tableViewClickedColumn(this._tag)
  }

  get numberOfSelectedRows() {
    return binding.tableViewNumberOfSelectedRows(this._tag)
  }

  moveColumn(column, index) {
    binding.tableViewMoveColumn(this._tag, column, index)
    return this
  }

  selectRow(row, extend) {
    binding.tableViewSelectRow(this._tag, row, extend)
    return this
  }

  deselectRow(row) {
    binding.tableViewDeselectRow(this._tag, row)
    return this
  }

  deselectAll() {
    binding.tableViewDeselectAll(this._tag)
    return this
  }

  selectAll() {
    binding.tableViewSelectAll(this._tag)
    return this
  }

  isRowSelected(row) {
    return binding.tableViewIsRowSelected(this._tag, row)
  }

  scrollRowToVisible(row) {
    binding.tableViewScrollRowToVisible(this._tag, row)
    return this
  }

  reloadRow(row) {
    binding.tableViewReloadRow(this._tag, row)
    return this
  }

  sizeToFit() {
    binding.tableViewSizeToFit(this._tag)
    return this
  }

  sizeLastColumnToFit() {
    binding.tableViewSizeLastColumnToFit(this._tag)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTableView }
    }
  }

  // Memoised per cell so that the caller's `makeView` is called once per
  // (column, row), and so the views stay reachable while AppKit displays them.
  _makeview(identifier, row) {
    const key = identifier + ':' + row

    let view = this._views.get(key)

    if (view === undefined) {
      view = this.makeView === null ? null : this.makeView(identifier, row)

      this._views.set(key, view)
    }

    return view === null ? null : view._tag
  }

  _onselectionchange() {
    this.emit('selectionDidChange')
  }

  _onclick() {
    this.emit('click')
  }

  _ondoubleclick() {
    this.emit('doubleClick')
  }
}

exports.STYLE = {
  AUTOMATIC: binding.TABLE_VIEW_STYLE_AUTOMATIC,
  FULL_WIDTH: binding.TABLE_VIEW_STYLE_FULL_WIDTH,
  INSET: binding.TABLE_VIEW_STYLE_INSET,
  SOURCE_LIST: binding.TABLE_VIEW_STYLE_SOURCE_LIST,
  PLAIN: binding.TABLE_VIEW_STYLE_PLAIN
}

exports.GRID = {
  NONE: binding.TABLE_VIEW_GRID_NONE,
  SOLID_VERTICAL: binding.TABLE_VIEW_GRID_SOLID_VERTICAL,
  SOLID_HORIZONTAL: binding.TABLE_VIEW_GRID_SOLID_HORIZONTAL,
  DASHED_HORIZONTAL: binding.TABLE_VIEW_GRID_DASHED_HORIZONTAL
}

exports.ROW_SIZE_STYLE = {
  DEFAULT: binding.TABLE_VIEW_ROW_SIZE_STYLE_DEFAULT,
  CUSTOM: binding.TABLE_VIEW_ROW_SIZE_STYLE_CUSTOM,
  SMALL: binding.TABLE_VIEW_ROW_SIZE_STYLE_SMALL,
  MEDIUM: binding.TABLE_VIEW_ROW_SIZE_STYLE_MEDIUM,
  LARGE: binding.TABLE_VIEW_ROW_SIZE_STYLE_LARGE
}

exports.COLUMN_AUTORESIZING = {
  NONE: binding.TABLE_VIEW_COLUMN_AUTORESIZING_NONE,
  UNIFORM: binding.TABLE_VIEW_COLUMN_AUTORESIZING_UNIFORM,
  SEQUENTIAL: binding.TABLE_VIEW_COLUMN_AUTORESIZING_SEQUENTIAL,
  REVERSE_SEQUENTIAL: binding.TABLE_VIEW_COLUMN_AUTORESIZING_REVERSE_SEQUENTIAL,
  LAST_COLUMN_ONLY: binding.TABLE_VIEW_COLUMN_AUTORESIZING_LAST_COLUMN_ONLY,
  FIRST_COLUMN_ONLY: binding.TABLE_VIEW_COLUMN_AUTORESIZING_FIRST_COLUMN_ONLY
}

exports._events = {
  selectionDidChange: 1,
  click: 2,
  doubleClick: 4
}
