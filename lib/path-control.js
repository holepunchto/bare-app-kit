const binding = require('../binding')
const { adopt } = require('./handle')
const retain = require('./retain')
const wrap = require('./wrap')
const AppKitPathControlItem = require('./path-control-item')
const AppKitColor = require('./color')
const AppKitMenu = require('./menu')
const AppKitControl = require('./control')

module.exports = exports = class AppKitPathControl extends AppKitControl {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    this._menu = null

    return binding.pathControlInit(x, y, width, height, this)
  }

  get url() {
    return binding.pathControlUrl(this._tag)
  }

  set url(url) {
    binding.pathControlUrl(this._tag, url)
  }

  get pathStyle() {
    return binding.pathControlPathStyle(this._tag)
  }

  set pathStyle(pathStyle) {
    binding.pathControlPathStyle(this._tag, pathStyle)
  }

  get editable() {
    return binding.pathControlEditable(this._tag)
  }

  set editable(editable) {
    binding.pathControlEditable(this._tag, editable)
  }

  get placeholderString() {
    return binding.pathControlPlaceholderString(this._tag)
  }

  set placeholderString(placeholderString) {
    binding.pathControlPlaceholderString(this._tag, placeholderString)
  }

  get backgroundColor() {
    return wrap(AppKitColor, binding.pathControlBackgroundColor(this._tag))
  }

  set backgroundColor(backgroundColor) {
    binding.pathControlBackgroundColor(this._tag, adopt(backgroundColor))
  }

  get allowedTypes() {
    return binding.pathControlAllowedTypes(this._tag)
  }

  set allowedTypes(allowedTypes) {
    binding.pathControlAllowedTypes(this._tag, allowedTypes)
  }

  get menu() {
    return retain(this, '_menu', AppKitMenu, binding.pathControlMenu(this._tag))
  }

  set menu(menu) {
    binding.pathControlMenu(this._tag, adopt(menu))

    this._menu = menu
  }

  setPathItems(items) {
    binding.pathControlSetPathItems(
      this._tag,
      items.map((object) => object._tag)
    )
    return this
  }

  numberOfPathItems() {
    return binding.pathControlNumberOfPathItems(this._tag)
  }

  pathItemAt(index) {
    return wrap(AppKitPathControlItem, binding.pathControlPathItemAt(this._tag, index))
  }

  clickedPathItem() {
    return wrap(AppKitPathControlItem, binding.pathControlClickedPathItem(this._tag))
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitPathControl }
    }
  }

  _onchange() {
    this.emit('change')
  }
}

exports._events = {
  change: 1
}

exports.STYLE = {
  STANDARD: binding.PATH_CONTROL_STYLE_STANDARD,
  POP_UP: binding.PATH_CONTROL_STYLE_POP_UP
}
