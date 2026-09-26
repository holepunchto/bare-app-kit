const binding = require('../binding')
const { adopt, expose } = require('./handle')
const wrap = require('./wrap')
const EventEmitter = require('bare-events')
const AppKitToolbarItem = require('./toolbar-item')

module.exports = exports = class AppKitToolbar extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._retained = new Set()

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)
  }

  _init(opts) {
    const { identifier = '' } = opts

    return binding.toolbarInit(identifier, this)
  }

  get items() {
    return binding.toolbarItems(this._tag).map((tag) => wrap(AppKitToolbarItem, tag))
  }

  // An item has to be registered before the toolbar's delegate can hand it back
  // by identifier.
  addItem(item) {
    binding.toolbarRegisterItem(this._tag, adopt(item))
    this._retained.add(item)
    return this
  }

  get allowedItemIdentifiers() {
    return binding.toolbarAllowedItemIdentifiers(this._tag)
  }

  set allowedItemIdentifiers(identifiers) {
    binding.toolbarAllowedItemIdentifiers(this._tag, identifiers)
  }

  get defaultItemIdentifiers() {
    return binding.toolbarDefaultItemIdentifiers(this._tag)
  }

  set defaultItemIdentifiers(identifiers) {
    binding.toolbarDefaultItemIdentifiers(this._tag, identifiers)
  }

  get identifier() {
    return binding.toolbarIdentifier(this._tag)
  }

  get displayMode() {
    return binding.toolbarDisplayMode(this._tag)
  }

  set displayMode(displayMode) {
    binding.toolbarDisplayMode(this._tag, displayMode)
  }

  get selectedItemIdentifier() {
    return binding.toolbarSelectedItemIdentifier(this._tag)
  }

  set selectedItemIdentifier(selectedItemIdentifier) {
    binding.toolbarSelectedItemIdentifier(this._tag, selectedItemIdentifier)
  }

  get centeredItemIdentifiers() {
    return binding.toolbarCenteredItemIdentifiers(this._tag)
  }

  get visible() {
    return binding.toolbarVisible(this._tag)
  }

  set visible(visible) {
    binding.toolbarVisible(this._tag, visible)
  }

  get allowsUserCustomization() {
    return binding.toolbarAllowsUserCustomization(this._tag)
  }

  set allowsUserCustomization(allowsUserCustomization) {
    binding.toolbarAllowsUserCustomization(this._tag, allowsUserCustomization)
  }

  get allowsExtensionItems() {
    return binding.toolbarAllowsExtensionItems(this._tag)
  }

  set allowsExtensionItems(allowsExtensionItems) {
    binding.toolbarAllowsExtensionItems(this._tag, allowsExtensionItems)
  }

  get autosavesConfiguration() {
    return binding.toolbarAutosavesConfiguration(this._tag)
  }

  set autosavesConfiguration(autosavesConfiguration) {
    binding.toolbarAutosavesConfiguration(this._tag, autosavesConfiguration)
  }

  get customizationPaletteIsRunning() {
    return binding.toolbarCustomizationPaletteIsRunning(this._tag)
  }

  insertItemWithItemIdentifier(identifier, index) {
    binding.toolbarInsertItemWithItemIdentifier(this._tag, identifier, index)
    return this
  }

  removeItemAtIndex(index) {
    binding.toolbarRemoveItemAtIndex(this._tag, index)
    return this
  }

  runCustomizationPalette() {
    binding.toolbarRunCustomizationPalette(this._tag)
    return this
  }

  validateVisibleItems() {
    binding.toolbarValidateVisibleItems(this._tag)
    return this
  }

  setCenteredItemIdentifiers(identifiers) {
    binding.toolbarSetCenteredItemIdentifiers(this._tag, identifiers)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitToolbar }
    }
  }

  _onwilladditem() {
    this.emit('willAddItem')
  }

  _ondidremoveitem() {
    this.emit('didRemoveItem')
  }
}

exports.DISPLAY_MODE = {
  DEFAULT: binding.TOOLBAR_DISPLAY_MODE_DEFAULT,
  ICON_AND_LABEL: binding.TOOLBAR_DISPLAY_MODE_ICON_AND_LABEL,
  ICON_ONLY: binding.TOOLBAR_DISPLAY_MODE_ICON_ONLY,
  LABEL_ONLY: binding.TOOLBAR_DISPLAY_MODE_LABEL_ONLY
}

exports.ITEM = {
  SPACE: binding.TOOLBAR_ITEM_SPACE,
  FLEXIBLE_SPACE: binding.TOOLBAR_ITEM_FLEXIBLE_SPACE,
  TOGGLE_SIDEBAR: binding.TOOLBAR_ITEM_TOGGLE_SIDEBAR,
  SIDEBAR_TRACKING_SEPARATOR: binding.TOOLBAR_ITEM_SIDEBAR_TRACKING_SEPARATOR,
  PRINT: binding.TOOLBAR_ITEM_PRINT,
  SHOW_COLORS: binding.TOOLBAR_ITEM_SHOW_COLORS,
  SHOW_FONTS: binding.TOOLBAR_ITEM_SHOW_FONTS,
  CLOUD_SHARING: binding.TOOLBAR_ITEM_CLOUD_SHARING
}

exports._events = {
  willAddItem: 1,
  didRemoveItem: 2
}

expose(exports)
