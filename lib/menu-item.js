const binding = require('../binding')
const { adopt } = require('./handle')
const observe = require('./events')
const retain = require('./retain')
const wrap = require('./wrap')
const EventEmitter = require('bare-events')
const AppKitImage = require('./image')
const AppKitMenu = require('./menu')
const AppKitAttributedString = require('./attributed-string')

module.exports = exports = class AppKitMenuItem extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._submenu = null

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init(opts) {
    const { title = '', keyEquivalent = '', selector = '' } = opts

    return binding.menuItemInit(title, keyEquivalent, selector, this)
  }

  static separator() {
    return wrap(AppKitMenuItem, binding.menuItemSeparator())
  }

  get title() {
    return binding.menuItemTitle(this._tag)
  }

  set title(title) {
    binding.menuItemTitle(this._tag, title)
  }

  get enabled() {
    return binding.menuItemEnabled(this._tag)
  }

  set enabled(enabled) {
    binding.menuItemEnabled(this._tag, enabled)
  }

  get hidden() {
    return binding.menuItemHidden(this._tag)
  }

  set hidden(hidden) {
    binding.menuItemHidden(this._tag, hidden)
  }

  get state() {
    return binding.menuItemState(this._tag)
  }

  set state(state) {
    binding.menuItemState(this._tag, state)
  }

  get tag() {
    return binding.menuItemTag(this._tag)
  }

  set tag(tag) {
    binding.menuItemTag(this._tag, tag)
  }

  get toolTip() {
    return binding.menuItemToolTip(this._tag)
  }

  set toolTip(toolTip) {
    binding.menuItemToolTip(this._tag, toolTip)
  }

  get indentationLevel() {
    return binding.menuItemIndentationLevel(this._tag)
  }

  set indentationLevel(indentationLevel) {
    binding.menuItemIndentationLevel(this._tag, indentationLevel)
  }

  get keyEquivalent() {
    return binding.menuItemKeyEquivalent(this._tag)
  }

  set keyEquivalent(keyEquivalent) {
    binding.menuItemKeyEquivalent(this._tag, keyEquivalent)
  }

  get keyEquivalentModifierMask() {
    return binding.menuItemKeyEquivalentModifierMask(this._tag)
  }

  set keyEquivalentModifierMask(keyEquivalentModifierMask) {
    binding.menuItemKeyEquivalentModifierMask(this._tag, keyEquivalentModifierMask)
  }

  get image() {
    return wrap(AppKitImage, binding.menuItemImage(this._tag))
  }

  set image(image) {
    binding.menuItemImage(this._tag, adopt(image))
  }

  get submenu() {
    return retain(this, '_submenu', AppKitMenu, binding.menuItemSubmenu(this._tag))
  }

  set submenu(submenu) {
    binding.menuItemSubmenu(this._tag, adopt(submenu))

    this._submenu = submenu
  }

  get attributedTitle() {
    return wrap(AppKitAttributedString, binding.menuItemAttributedTitle(this._tag))
  }

  set attributedTitle(attributedTitle) {
    binding.menuItemAttributedTitle(this._tag, adopt(attributedTitle))
  }

  get separatorItem() {
    return binding.menuItemSeparatorItem(this._tag)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitMenuItem }
    }
  }

  _onclick() {
    this.emit('click')
  }
}

exports._events = {
  click: 1
}

exports.MODIFIER = {
  CAPS_LOCK: binding.EVENT_MODIFIER_CAPS_LOCK,
  SHIFT: binding.EVENT_MODIFIER_SHIFT,
  CONTROL: binding.EVENT_MODIFIER_CONTROL,
  OPTION: binding.EVENT_MODIFIER_OPTION,
  COMMAND: binding.EVENT_MODIFIER_COMMAND,
  FUNCTION: binding.EVENT_MODIFIER_FUNCTION
}
