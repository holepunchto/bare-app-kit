const binding = require('../binding')
const { adopt, expose } = require('./handle')
const retain = require('./retain')
const wrap = require('./wrap')
const AppKitColor = require('./color')
const AppKitView = require('./view')
const AppKitPanel = require('./panel')

module.exports = exports = class AppKitColorPanel extends AppKitPanel {
  _init() {
    return binding.colorPanelInit()
  }

  get color() {
    return wrap(AppKitColor, binding.colorPanelColor(this._tag))
  }

  set color(color) {
    binding.colorPanelColor(this._tag, adopt(color))
  }

  get mode() {
    return binding.colorPanelMode(this._tag)
  }

  set mode(mode) {
    binding.colorPanelMode(this._tag, mode)
  }

  get showsAlpha() {
    return binding.colorPanelShowsAlpha(this._tag)
  }

  set showsAlpha(showsAlpha) {
    binding.colorPanelShowsAlpha(this._tag, showsAlpha)
  }

  get continuous() {
    return binding.colorPanelContinuous(this._tag)
  }

  set continuous(continuous) {
    binding.colorPanelContinuous(this._tag, continuous)
  }

  get accessoryView() {
    return retain(this, '_accessoryView', AppKitView, binding.colorPanelAccessoryView(this._tag))
  }

  set accessoryView(accessoryView) {
    binding.colorPanelAccessoryView(this._tag, adopt(accessoryView))

    this._accessoryView = accessoryView
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitColorPanel }
    }
  }
}

exports.MODE = {
  GRAY: binding.COLOR_PANEL_MODE_GRAY,
  RGB: binding.COLOR_PANEL_MODE_RGB,
  CMYK: binding.COLOR_PANEL_MODE_CMYK,
  HSB: binding.COLOR_PANEL_MODE_HSB,
  CUSTOM_PALETTE: binding.COLOR_PANEL_MODE_CUSTOM_PALETTE,
  COLOR_LIST: binding.COLOR_PANEL_MODE_COLOR_LIST,
  WHEEL: binding.COLOR_PANEL_MODE_WHEEL,
  CRAYON: binding.COLOR_PANEL_MODE_CRAYON
}

expose(exports)
