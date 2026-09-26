const binding = require('../binding')
const { expose } = require('./handle')
const AppKitToolbarItem = require('./toolbar-item')

module.exports = exports = class AppKitToolbarItemGroup extends AppKitToolbarItem {
  _init(opts) {
    const { identifier = '' } = opts

    return binding.toolbarItemGroupInit(identifier)
  }

  get selectionMode() {
    return binding.toolbarItemGroupSelectionMode(this._tag)
  }

  set selectionMode(selectionMode) {
    binding.toolbarItemGroupSelectionMode(this._tag, selectionMode)
  }

  get controlRepresentation() {
    return binding.toolbarItemGroupControlRepresentation(this._tag)
  }

  set controlRepresentation(controlRepresentation) {
    binding.toolbarItemGroupControlRepresentation(this._tag, controlRepresentation)
  }

  get selectedIndex() {
    return binding.toolbarItemGroupSelectedIndex(this._tag)
  }

  set selectedIndex(selectedIndex) {
    binding.toolbarItemGroupSelectedIndex(this._tag, selectedIndex)
  }

  get subitems() {
    return this._subitems.slice()
  }

  setSubitems(items) {
    binding.toolbarItemGroupSetSubitems(
      this._tag,
      items.map((item) => item._tag)
    )

    this._subitems = items.slice()

    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitToolbarItemGroup }
    }
  }
}

exports.SELECTION_MODE = {
  SELECT_ONE: binding.TOOLBAR_ITEM_GROUP_SELECTION_MODE_SELECT_ONE,
  SELECT_ANY: binding.TOOLBAR_ITEM_GROUP_SELECTION_MODE_SELECT_ANY,
  MOMENTARY: binding.TOOLBAR_ITEM_GROUP_SELECTION_MODE_MOMENTARY
}

exports.CONTROL_REPRESENTATION = {
  AUTOMATIC: binding.TOOLBAR_ITEM_GROUP_CONTROL_REPRESENTATION_AUTOMATIC,
  EXPANDED: binding.TOOLBAR_ITEM_GROUP_CONTROL_REPRESENTATION_EXPANDED,
  COLLAPSED: binding.TOOLBAR_ITEM_GROUP_CONTROL_REPRESENTATION_COLLAPSED
}

expose(exports)
