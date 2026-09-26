const binding = require('../binding')
const { adopt } = require('./handle')
const retain = require('./retain')
const wrap = require('./wrap')
const AppKitImage = require('./image')
const AppKitMenu = require('./menu')
const AppKitControl = require('./control')

module.exports = exports = class AppKitComboButton extends AppKitControl {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    this._menu = null

    return binding.comboButtonInit(x, y, width, height, this)
  }

  get title() {
    return binding.comboButtonTitle(this._tag)
  }

  set title(title) {
    binding.comboButtonTitle(this._tag, title)
  }

  get image() {
    return wrap(AppKitImage, binding.comboButtonImage(this._tag))
  }

  set image(image) {
    binding.comboButtonImage(this._tag, adopt(image))
  }

  get imageScaling() {
    return binding.comboButtonImageScaling(this._tag)
  }

  set imageScaling(imageScaling) {
    binding.comboButtonImageScaling(this._tag, imageScaling)
  }

  get style() {
    return binding.comboButtonStyle(this._tag)
  }

  set style(style) {
    binding.comboButtonStyle(this._tag, style)
  }

  get menu() {
    return retain(this, '_menu', AppKitMenu, binding.comboButtonMenu(this._tag))
  }

  set menu(menu) {
    binding.comboButtonMenu(this._tag, adopt(menu))

    this._menu = menu
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitComboButton }
    }
  }

  _onclick() {
    this.emit('click')
  }
}

exports._events = {
  click: 1
}

exports.STYLE = {
  SPLIT: binding.COMBO_BUTTON_STYLE_SPLIT,
  UNIFIED: binding.COMBO_BUTTON_STYLE_UNIFIED
}
