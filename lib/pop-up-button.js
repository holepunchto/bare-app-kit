const binding = require('../binding')
const { adopt } = require('./handle')
const retain = require('./retain')
const AppKitMenu = require('./menu')
const AppKitButton = require('./button')

module.exports = exports = class AppKitPopUpButton extends AppKitButton {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0, pullsDown = false } = opts

    this._menu = null

    return binding.popUpButtonInit(x, y, width, height, pullsDown, this)
  }

  get pullsDown() {
    return binding.popUpButtonPullsDown(this._tag)
  }

  set pullsDown(pullsDown) {
    binding.popUpButtonPullsDown(this._tag, pullsDown)
  }

  get autoenablesItems() {
    return binding.popUpButtonAutoenablesItems(this._tag)
  }

  set autoenablesItems(autoenablesItems) {
    binding.popUpButtonAutoenablesItems(this._tag, autoenablesItems)
  }

  get preferredEdge() {
    return binding.popUpButtonPreferredEdge(this._tag)
  }

  set preferredEdge(preferredEdge) {
    binding.popUpButtonPreferredEdge(this._tag, preferredEdge)
  }

  get numberOfItems() {
    return binding.popUpButtonNumberOfItems(this._tag)
  }

  get indexOfSelectedItem() {
    return binding.popUpButtonIndexOfSelectedItem(this._tag)
  }

  get titleOfSelectedItem() {
    return binding.popUpButtonTitleOfSelectedItem(this._tag)
  }

  get menu() {
    return retain(this, '_menu', AppKitMenu, binding.popUpButtonMenu(this._tag))
  }

  set menu(menu) {
    binding.popUpButtonMenu(this._tag, adopt(menu))

    this._menu = menu
  }

  get itemTitles() {
    return binding.popUpButtonItemTitles(this._tag)
  }

  addItemWithTitle(title) {
    binding.popUpButtonAddItemWithTitle(this._tag, title)
    return this
  }

  addItemsWithTitles(titles) {
    binding.popUpButtonAddItemsWithTitles(this._tag, titles)
    return this
  }

  insertItemWithTitle(title, index) {
    binding.popUpButtonInsertItemWithTitle(this._tag, title, index)
    return this
  }

  removeItemWithTitle(title) {
    binding.popUpButtonRemoveItemWithTitle(this._tag, title)
    return this
  }

  removeItemAtIndex(index) {
    binding.popUpButtonRemoveItemAtIndex(this._tag, index)
    return this
  }

  removeAllItems() {
    binding.popUpButtonRemoveAllItems(this._tag)
    return this
  }

  selectItemAtIndex(index) {
    binding.popUpButtonSelectItemAtIndex(this._tag, index)
    return this
  }

  selectItemWithTitle(title) {
    binding.popUpButtonSelectItemWithTitle(this._tag, title)
    return this
  }

  itemTitleAtIndex(index) {
    return binding.popUpButtonItemTitleAtIndex(this._tag, index)
  }

  indexOfItemWithTitle(title) {
    return binding.popUpButtonIndexOfItemWithTitle(this._tag, title)
  }

  synchronizeTitleAndSelectedItem() {
    binding.popUpButtonSynchronizeTitleAndSelectedItem(this._tag)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitPopUpButton }
    }
  }

  _onclick() {
    this.emit('change')
  }
}

exports._events = {
  mouseDown: 1,
  change: 2
}

exports.EDGE = {
  MIN_X: binding.POP_UP_BUTTON_EDGE_MIN_X,
  MIN_Y: binding.POP_UP_BUTTON_EDGE_MIN_Y,
  MAX_X: binding.POP_UP_BUTTON_EDGE_MAX_X,
  MAX_Y: binding.POP_UP_BUTTON_EDGE_MAX_Y
}
