const binding = require('../binding')
const { adopt, expose } = require('./handle')
const scratch = require('./scratch')
const observe = require('./events')
const retain = require('./retain')
const wrap = require('./wrap')
const EventEmitter = require('bare-events')
const AppKitMenuItem = require('./menu-item')
const AppKitFont = require('./font')

module.exports = exports = class AppKitMenu extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._highlightedItem = null
    this._supermenu = null
    this._retained = new Set()

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init(opts) {
    const { title = '' } = opts

    return binding.menuInit(title, this)
  }

  get title() {
    return binding.menuTitle(this._tag)
  }

  set title(title) {
    binding.menuTitle(this._tag, title)
  }

  get autoenablesItems() {
    return binding.menuAutoenablesItems(this._tag)
  }

  set autoenablesItems(autoenablesItems) {
    binding.menuAutoenablesItems(this._tag, autoenablesItems)
  }

  get minimumWidth() {
    return binding.menuMinimumWidth(this._tag)
  }

  set minimumWidth(minimumWidth) {
    binding.menuMinimumWidth(this._tag, minimumWidth)
  }

  get showsStateColumn() {
    return binding.menuShowsStateColumn(this._tag)
  }

  set showsStateColumn(showsStateColumn) {
    binding.menuShowsStateColumn(this._tag, showsStateColumn)
  }

  get allowsContextMenuPlugIns() {
    return binding.menuAllowsContextMenuPlugIns(this._tag)
  }

  set allowsContextMenuPlugIns(allowsContextMenuPlugIns) {
    binding.menuAllowsContextMenuPlugIns(this._tag, allowsContextMenuPlugIns)
  }

  get size() {
    binding.menuSizeInto(this._tag, scratch.buffer, 0)

    return { width: scratch[0], height: scratch[1] }
  }

  get highlightedItem() {
    return retain(this, '_highlightedItem', AppKitMenuItem, binding.menuHighlightedItem(this._tag))
  }

  get supermenu() {
    return retain(this, '_supermenu', AppKitMenu, binding.menuSupermenu(this._tag))
  }

  get font() {
    return wrap(AppKitFont, binding.menuFont(this._tag))
  }

  set font(font) {
    binding.menuFont(this._tag, adopt(font))
  }

  get numberOfItems() {
    return binding.menuNumberOfItems(this._tag)
  }

  popUpContextMenu(view) {
    binding.menuPopUpContextMenu(this._tag, adopt(view))
    return this
  }

  performActionForItemAtIndex(index) {
    binding.menuPerformActionForItemAtIndex(this._tag, index)
    return this
  }

  cancelTracking() {
    binding.menuCancelTracking(this._tag)
    return this
  }

  update() {
    binding.menuUpdate(this._tag)
    return this
  }

  indexOfItemWithTitle(title) {
    return binding.menuIndexOfItemWithTitle(this._tag, title)
  }

  indexOfItemWithTag(tag) {
    return binding.menuIndexOfItemWithTag(this._tag, tag)
  }

  get items() {
    return binding.menuItems(this._tag).map((tag) => wrap(AppKitMenuItem, tag))
  }

  itemAtIndex(index) {
    return this.items[index] || null
  }

  indexOfItem(item) {
    return this.items.indexOf(item)
  }

  addItem(item) {
    binding.menuAddItem(this._tag, adopt(item))
    this._retained.add(item)
    return this
  }

  insertItem(item, index) {
    binding.menuInsertItem(this._tag, adopt(item), index)
    this._retained.add(item)
    return this
  }

  removeItem(item) {
    binding.menuRemoveItem(this._tag, adopt(item))
    this._retained.delete(item)
    return this
  }

  removeItemAtIndex(index) {
    const item = this.itemAtIndex(index)

    binding.menuRemoveItemAtIndex(this._tag, index)

    if (item !== null) this._retained.delete(item)

    return this
  }

  removeAllItems() {
    binding.menuRemoveAllItems(this._tag)
    this._retained.clear()
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitMenu }
    }
  }

  _onwillopen() {
    this.emit('willOpen')
  }

  _ondidclose() {
    this.emit('didClose')
  }
}

exports._events = {
  willOpen: 1,
  didClose: 2
}

expose(exports)
