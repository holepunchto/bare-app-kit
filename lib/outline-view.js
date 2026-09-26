const binding = require('../binding')
const { expose } = require('./handle')
const retain = require('./retain')
const AppKitTableColumn = require('./table-column')
const AppKitTableView = require('./table-view')

// The root of the tree, as seen by the caller's data source callbacks.
const ROOT = -1

module.exports = exports = class AppKitOutlineView extends AppKitTableView {
  _init(opts) {
    const {
      x = 0,
      y = 0,
      width = 0,
      height = 0,
      numberOfChildren = null,
      child = null,
      isExpandable = null,
      makeView = null
    } = opts

    this._backgroundColor = null
    this._gridColor = null
    this._headerView = null
    this._outlineTableColumn = null
    this._views = new Map()

    // Items cross the boundary as integers, so the caller can use whatever it
    // likes to represent a node. Both directions are cached until `reloadData()`.
    this._items = new Map()
    this._ids = new Map()
    this._nextId = 0

    // Supplied by the caller, here or as properties. `item` is null at the root.
    this.numberOfChildren = numberOfChildren
    this.child = child
    this.isExpandable = isExpandable
    this.makeView = makeView

    return binding.outlineViewInit(
      x,
      y,
      width,
      height,
      this,
      this._numberofchildren,
      this._child,
      this._isexpandable,
      this._makeview
    )
  }

  reloadData() {
    this._views.clear()
    this._items.clear()
    this._ids.clear()
    binding.tableViewReloadData(this._tag)
    return this
  }

  // An outline view computes its own row count from the tree, so the table
  // view's pushed count does not apply.
  get numberOfRows() {
    return binding.outlineViewNumberOfRows(this._tag)
  }

  get indentationPerLevel() {
    return binding.outlineViewIndentationPerLevel(this._tag)
  }

  set indentationPerLevel(indentationPerLevel) {
    binding.outlineViewIndentationPerLevel(this._tag, indentationPerLevel)
  }

  get indentationMarkerFollowsCell() {
    return binding.outlineViewIndentationMarkerFollowsCell(this._tag)
  }

  set indentationMarkerFollowsCell(indentationMarkerFollowsCell) {
    binding.outlineViewIndentationMarkerFollowsCell(this._tag, indentationMarkerFollowsCell)
  }

  get autoresizesOutlineColumn() {
    return binding.outlineViewAutoresizesOutlineColumn(this._tag)
  }

  set autoresizesOutlineColumn(autoresizesOutlineColumn) {
    binding.outlineViewAutoresizesOutlineColumn(this._tag, autoresizesOutlineColumn)
  }

  get autosaveExpandedItems() {
    return binding.outlineViewAutosaveExpandedItems(this._tag)
  }

  set autosaveExpandedItems(autosaveExpandedItems) {
    binding.outlineViewAutosaveExpandedItems(this._tag, autosaveExpandedItems)
  }

  get stronglyReferencesItems() {
    return binding.outlineViewStronglyReferencesItems(this._tag)
  }

  set stronglyReferencesItems(stronglyReferencesItems) {
    binding.outlineViewStronglyReferencesItems(this._tag, stronglyReferencesItems)
  }

  get outlineTableColumn() {
    return retain(
      this,
      '_outlineTableColumn',
      AppKitTableColumn,
      binding.outlineViewOutlineTableColumn(this._tag)
    )
  }

  set outlineTableColumn(outlineTableColumn) {
    binding.outlineViewOutlineTableColumn(
      this._tag,
      outlineTableColumn === null ? null : outlineTableColumn._tag
    )

    this._outlineTableColumn = outlineTableColumn
  }

  expandItem(item, children) {
    binding.outlineViewExpandItem(this._tag, this._idFor(item), children)
    return this
  }

  collapseItem(item, children) {
    binding.outlineViewCollapseItem(this._tag, this._idFor(item), children)
    return this
  }

  isItemExpanded(item) {
    return binding.outlineViewIsItemExpanded(this._tag, this._idFor(item))
  }

  reloadItem(item, children) {
    binding.outlineViewReloadItem(this._tag, this._idFor(item), children)
    return this
  }

  levelForItem(item) {
    return binding.outlineViewLevelForItem(this._tag, this._idFor(item))
  }

  rowForItem(item) {
    return binding.outlineViewRowForItem(this._tag, this._idFor(item))
  }

  itemAtRow(row) {
    return this._itemFor(binding.outlineViewItemAtRow(this._tag, row))
  }

  parentForItem(item) {
    return this._itemFor(binding.outlineViewParentForItem(this._tag, this._idFor(item)))
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitOutlineView }
    }
  }

  _idFor(item) {
    if (item === null || item === undefined) return ROOT

    let id = this._ids.get(item)

    if (id === undefined) {
      id = this._nextId++

      this._ids.set(item, id)
      this._items.set(id, item)
    }

    return id
  }

  _itemFor(id) {
    return id === ROOT ? null : (this._items.get(id) ?? null)
  }

  _numberofchildren(id) {
    return this.numberOfChildren === null ? 0 : this.numberOfChildren(this._itemFor(id))
  }

  _child(index, id) {
    if (this.child === null) return ROOT

    return this._idFor(this.child(index, this._itemFor(id)))
  }

  _isexpandable(id) {
    return this.isExpandable === null ? false : this.isExpandable(this._itemFor(id))
  }

  _makeview(identifier, id) {
    const key = identifier + ':' + id

    let view = this._views.get(key)

    if (view === undefined) {
      view = this.makeView === null ? null : this.makeView(identifier, this._itemFor(id))

      this._views.set(key, view)
    }

    return view === null ? null : view._tag
  }

  _onitemdidexpand() {
    this.emit('itemDidExpand')
  }

  _onitemdidcollapse() {
    this.emit('itemDidCollapse')
  }
}

exports._events = {
  selectionDidChange: 1,
  itemDidExpand: 2,
  itemDidCollapse: 4
}

expose(exports)
