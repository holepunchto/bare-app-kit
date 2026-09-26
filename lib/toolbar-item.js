const binding = require('../binding')
const { adopt } = require('./handle')
const observe = require('./events')
const retain = require('./retain')
const wrap = require('./wrap')
const EventEmitter = require('bare-events')
const AppKitImage = require('./image')
const AppKitView = require('./view')
const AppKitMenuItem = require('./menu-item')

module.exports = exports = class AppKitToolbarItem extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._view = null
    this._menuFormRepresentation = null

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init(opts) {
    const { identifier = '' } = opts

    return binding.toolbarItemInit(identifier, this)
  }

  get itemIdentifier() {
    return binding.toolbarItemItemIdentifier(this._tag)
  }

  get label() {
    return binding.toolbarItemLabel(this._tag)
  }

  set label(label) {
    binding.toolbarItemLabel(this._tag, label)
  }

  get paletteLabel() {
    return binding.toolbarItemPaletteLabel(this._tag)
  }

  set paletteLabel(paletteLabel) {
    binding.toolbarItemPaletteLabel(this._tag, paletteLabel)
  }

  get toolTip() {
    return binding.toolbarItemToolTip(this._tag)
  }

  set toolTip(toolTip) {
    binding.toolbarItemToolTip(this._tag, toolTip)
  }

  get title() {
    return binding.toolbarItemTitle(this._tag)
  }

  set title(title) {
    binding.toolbarItemTitle(this._tag, title)
  }

  get tag() {
    return binding.toolbarItemTag(this._tag)
  }

  set tag(tag) {
    binding.toolbarItemTag(this._tag, tag)
  }

  get enabled() {
    return binding.toolbarItemEnabled(this._tag)
  }

  set enabled(enabled) {
    binding.toolbarItemEnabled(this._tag, enabled)
  }

  get bordered() {
    return binding.toolbarItemBordered(this._tag)
  }

  set bordered(bordered) {
    binding.toolbarItemBordered(this._tag, bordered)
  }

  get navigational() {
    return binding.toolbarItemNavigational(this._tag)
  }

  set navigational(navigational) {
    binding.toolbarItemNavigational(this._tag, navigational)
  }

  get autovalidates() {
    return binding.toolbarItemAutovalidates(this._tag)
  }

  set autovalidates(autovalidates) {
    binding.toolbarItemAutovalidates(this._tag, autovalidates)
  }

  get visible() {
    return binding.toolbarItemVisible(this._tag)
  }

  get visibilityPriority() {
    return binding.toolbarItemVisibilityPriority(this._tag)
  }

  set visibilityPriority(visibilityPriority) {
    binding.toolbarItemVisibilityPriority(this._tag, visibilityPriority)
  }

  get image() {
    return wrap(AppKitImage, binding.toolbarItemImage(this._tag))
  }

  set image(image) {
    binding.toolbarItemImage(this._tag, adopt(image))
  }

  get view() {
    return retain(this, '_view', AppKitView, binding.toolbarItemView(this._tag))
  }

  set view(view) {
    binding.toolbarItemView(this._tag, adopt(view))

    this._view = view
  }

  get menuFormRepresentation() {
    return retain(
      this,
      '_menuFormRepresentation',
      AppKitMenuItem,
      binding.toolbarItemMenuFormRepresentation(this._tag)
    )
  }

  set menuFormRepresentation(menuFormRepresentation) {
    binding.toolbarItemMenuFormRepresentation(this._tag, adopt(menuFormRepresentation))

    this._menuFormRepresentation = menuFormRepresentation
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitToolbarItem }
    }
  }

  _onclick() {
    this.emit('click')
  }
}

exports._events = {
  click: 1
}

exports.VISIBILITY_PRIORITY = {
  STANDARD: binding.TOOLBAR_ITEM_VISIBILITY_PRIORITY_STANDARD,
  LOW: binding.TOOLBAR_ITEM_VISIBILITY_PRIORITY_LOW,
  HIGH: binding.TOOLBAR_ITEM_VISIBILITY_PRIORITY_HIGH,
  USER: binding.TOOLBAR_ITEM_VISIBILITY_PRIORITY_USER
}
