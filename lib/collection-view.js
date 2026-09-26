const binding = require('../binding')
const retain = require('./retain')
const wrap = require('./wrap')
const AppKitCollectionViewFlowLayout = require('./collection-view-flow-layout')
const AppKitCollectionViewItem = require('./collection-view-item')
const AppKitView = require('./view')

module.exports = exports = class AppKitCollectionView extends AppKitView {
  _init(opts) {
    const {
      x = 0,
      y = 0,
      width = 0,
      height = 0,
      numberOfSections = 1,
      numberOfItems = null,
      makeItem = null
    } = opts

    this._collectionViewLayout = null
    this._backgroundView = null
    this._items = new Map()

    // Supplied by the caller, here or as properties.
    this.numberOfItems = numberOfItems
    this.makeItem = makeItem

    const tag = binding.collectionViewInit(
      x,
      y,
      width,
      height,
      this,
      this._numberofitems,
      this._makeitem
    )

    binding.collectionViewNumberOfSections(tag, numberOfSections)

    return tag
  }

  get numberOfSections() {
    return binding.collectionViewNumberOfSections(this._tag)
  }

  set numberOfSections(numberOfSections) {
    binding.collectionViewNumberOfSections(this._tag, numberOfSections)
  }

  reloadData() {
    this._items.clear()
    binding.collectionViewReloadData(this._tag)
    return this
  }

  get collectionViewLayout() {
    return retain(
      this,
      '_collectionViewLayout',
      AppKitCollectionViewFlowLayout,
      binding.collectionViewCollectionViewLayout(this._tag)
    )
  }

  set collectionViewLayout(collectionViewLayout) {
    binding.collectionViewCollectionViewLayout(
      this._tag,
      collectionViewLayout === null ? null : collectionViewLayout._tag
    )

    this._collectionViewLayout = collectionViewLayout
  }

  get backgroundView() {
    return retain(
      this,
      '_backgroundView',
      AppKitView,
      binding.collectionViewBackgroundView(this._tag)
    )
  }

  set backgroundView(backgroundView) {
    binding.collectionViewBackgroundView(
      this._tag,
      backgroundView === null ? null : backgroundView._tag
    )

    this._backgroundView = backgroundView
  }

  get selectable() {
    return binding.collectionViewSelectable(this._tag)
  }

  set selectable(selectable) {
    binding.collectionViewSelectable(this._tag, selectable)
  }

  get allowsEmptySelection() {
    return binding.collectionViewAllowsEmptySelection(this._tag)
  }

  set allowsEmptySelection(allowsEmptySelection) {
    binding.collectionViewAllowsEmptySelection(this._tag, allowsEmptySelection)
  }

  get allowsMultipleSelection() {
    return binding.collectionViewAllowsMultipleSelection(this._tag)
  }

  set allowsMultipleSelection(allowsMultipleSelection) {
    binding.collectionViewAllowsMultipleSelection(this._tag, allowsMultipleSelection)
  }

  get backgroundViewScrollsWithContent() {
    return binding.collectionViewBackgroundViewScrollsWithContent(this._tag)
  }

  set backgroundViewScrollsWithContent(backgroundViewScrollsWithContent) {
    binding.collectionViewBackgroundViewScrollsWithContent(
      this._tag,
      backgroundViewScrollsWithContent
    )
  }

  get selectionIndexPaths() {
    return binding.collectionViewSelectionIndexPaths(this._tag)
  }

  deselectAll() {
    binding.collectionViewDeselectAll(this._tag)
    return this
  }

  selectItem(section, item) {
    binding.collectionViewSelectItem(this._tag, section, item)
    return this
  }

  scrollToItem(section, item, position) {
    binding.collectionViewScrollToItem(this._tag, section, item, position)
    return this
  }

  itemAt(section, item) {
    return wrap(AppKitCollectionViewItem, binding.collectionViewItemAt(this._tag, section, item))
  }

  numberOfItemsInSection(section) {
    return binding.collectionViewNumberOfItemsInSection(this._tag, section)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitCollectionView }
    }
  }

  // Memoised per cell, so the caller's `makeItem` runs once per item until
  // `reloadData()` and the wrappers stay reachable while AppKit shows them.
  _makeitem(section, item) {
    const key = section + ':' + item

    let value = this._items.get(key)

    if (value === undefined) {
      value = this.makeItem === null ? null : this.makeItem(section, item)

      this._items.set(key, value)
    }

    return value === null ? null : value._tag
  }

  _numberofitems(section) {
    return this.numberOfItems === null ? 0 : this.numberOfItems(section)
  }

  _onselectionchange() {
    this.emit('didSelectItems')
  }

  _ondeselectionchange() {
    this.emit('didDeselectItems')
  }
}

exports.SCROLL_POSITION = {
  NONE: binding.COLLECTION_VIEW_SCROLL_POSITION_NONE,
  TOP: binding.COLLECTION_VIEW_SCROLL_POSITION_TOP,
  CENTERED_VERTICALLY: binding.COLLECTION_VIEW_SCROLL_POSITION_CENTERED_VERTICALLY,
  BOTTOM: binding.COLLECTION_VIEW_SCROLL_POSITION_BOTTOM,
  LEFT: binding.COLLECTION_VIEW_SCROLL_POSITION_LEFT,
  CENTERED_HORIZONTALLY: binding.COLLECTION_VIEW_SCROLL_POSITION_CENTERED_HORIZONTALLY,
  RIGHT: binding.COLLECTION_VIEW_SCROLL_POSITION_RIGHT
}

exports._events = {
  didSelectItems: 1,
  didDeselectItems: 2
}
