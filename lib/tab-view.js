const binding = require('../binding')
const { adopt, expose } = require('./handle')
const wrap = require('./wrap')
const AppKitFont = require('./font')
const AppKitTabViewItem = require('./tab-view-item')
const AppKitView = require('./view')

module.exports = exports = class AppKitTabView extends AppKitView {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.tabViewInit(x, y, width, height, this)
  }

  get tabViewType() {
    return binding.tabViewTabViewType(this._tag)
  }

  set tabViewType(tabViewType) {
    binding.tabViewTabViewType(this._tag, tabViewType)
  }

  get tabPosition() {
    return binding.tabViewTabPosition(this._tag)
  }

  set tabPosition(tabPosition) {
    binding.tabViewTabPosition(this._tag, tabPosition)
  }

  get font() {
    return wrap(AppKitFont, binding.tabViewFont(this._tag))
  }

  set font(font) {
    binding.tabViewFont(this._tag, adopt(font))
  }

  get numberOfTabViewItems() {
    return binding.tabViewNumberOfTabViewItems(this._tag)
  }

  get allowsTruncatedLabels() {
    return binding.tabViewAllowsTruncatedLabels(this._tag)
  }

  set allowsTruncatedLabels(allowsTruncatedLabels) {
    binding.tabViewAllowsTruncatedLabels(this._tag, allowsTruncatedLabels)
  }

  get drawsBackground() {
    return binding.tabViewDrawsBackground(this._tag)
  }

  set drawsBackground(drawsBackground) {
    binding.tabViewDrawsBackground(this._tag, drawsBackground)
  }

  get controlSize() {
    return binding.tabViewControlSize(this._tag)
  }

  set controlSize(controlSize) {
    binding.tabViewControlSize(this._tag, controlSize)
  }

  get tabViewBorderType() {
    return binding.tabViewTabViewBorderType(this._tag)
  }

  set tabViewBorderType(tabViewBorderType) {
    binding.tabViewTabViewBorderType(this._tag, tabViewBorderType)
  }

  get contentRect() {
    return binding.tabViewContentRect(this._tag)
  }

  get minimumSize() {
    return binding.tabViewMinimumSize(this._tag)
  }

  get indexOfSelectedTabViewItem() {
    return binding.tabViewIndexOfSelectedTabViewItem(this._tag)
  }

  selectTabViewItemAtIndex(index) {
    binding.tabViewSelectTabViewItemAtIndex(this._tag, index)
    return this
  }

  get tabViewItems() {
    return binding.tabViewTabViewItems(this._tag).map((tag) => wrap(AppKitTabViewItem, tag))
  }

  get selectedTabViewItem() {
    return this.tabViewItems[this.indexOfSelectedTabViewItem] || null
  }

  indexOfTabViewItem(item) {
    return this.tabViewItems.indexOf(item)
  }

  addTabViewItem(item) {
    binding.tabViewAddTabViewItem(this._tag, adopt(item))
    this._retained.add(item)
    return this
  }

  insertTabViewItem(item, index) {
    binding.tabViewInsertTabViewItem(this._tag, adopt(item), index)
    this._retained.add(item)
    return this
  }

  removeTabViewItem(item) {
    binding.tabViewRemoveTabViewItem(this._tag, adopt(item))
    this._retained.delete(item)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTabView }
    }
  }

  _ondidselect() {
    this.emit('didSelect')
  }
}

exports._events = {
  didSelect: 1
}

exports.TYPE = {
  TOP_TABS_BEZEL_BORDER: binding.TAB_VIEW_TYPE_TOP_TABS_BEZEL_BORDER,
  LEFT_TABS_BEZEL_BORDER: binding.TAB_VIEW_TYPE_LEFT_TABS_BEZEL_BORDER,
  BOTTOM_TABS_BEZEL_BORDER: binding.TAB_VIEW_TYPE_BOTTOM_TABS_BEZEL_BORDER,
  RIGHT_TABS_BEZEL_BORDER: binding.TAB_VIEW_TYPE_RIGHT_TABS_BEZEL_BORDER,
  NO_TABS_BEZEL_BORDER: binding.TAB_VIEW_TYPE_NO_TABS_BEZEL_BORDER,
  NO_TABS_LINE_BORDER: binding.TAB_VIEW_TYPE_NO_TABS_LINE_BORDER,
  NO_TABS_NO_BORDER: binding.TAB_VIEW_TYPE_NO_TABS_NO_BORDER
}

exports.POSITION = {
  NONE: binding.TAB_VIEW_POSITION_NONE,
  TOP: binding.TAB_VIEW_POSITION_TOP,
  LEFT: binding.TAB_VIEW_POSITION_LEFT,
  BOTTOM: binding.TAB_VIEW_POSITION_BOTTOM,
  RIGHT: binding.TAB_VIEW_POSITION_RIGHT
}

expose(exports)
