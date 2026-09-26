const binding = require('../binding')
const { adopt } = require('./handle')
const observe = require('./events')
const retain = require('./retain')
const EventEmitter = require('bare-events')
const AppKitMenu = require('./menu')
const AppKitButton = require('./button')

module.exports = exports = class AppKitStatusItem extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._menu = null
    this._button = null

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init(opts) {
    const { length = binding.STATUS_ITEM_LENGTH_VARIABLE } = opts

    return binding.statusItemInit(length)
  }

  get length() {
    return binding.statusItemLength(this._tag)
  }

  set length(length) {
    binding.statusItemLength(this._tag, length)
  }

  get visible() {
    return binding.statusItemVisible(this._tag)
  }

  set visible(visible) {
    binding.statusItemVisible(this._tag, visible)
  }

  get menu() {
    return retain(this, '_menu', AppKitMenu, binding.statusItemMenu(this._tag))
  }

  set menu(menu) {
    binding.statusItemMenu(this._tag, adopt(menu))

    this._menu = menu
  }

  get button() {
    return retain(this, '_button', AppKitButton, binding.statusItemButton(this._tag))
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitStatusItem }
    }
  }
}

exports.LENGTH = {
  VARIABLE: binding.STATUS_ITEM_LENGTH_VARIABLE,
  SQUARE: binding.STATUS_ITEM_LENGTH_SQUARE
}
