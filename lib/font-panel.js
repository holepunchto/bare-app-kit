const binding = require('../binding')
const { adopt, expose } = require('./handle')
const retain = require('./retain')
const AppKitView = require('./view')
const AppKitPanel = require('./panel')

module.exports = exports = class AppKitFontPanel extends AppKitPanel {
  _init() {
    return binding.fontPanelInit()
  }

  get enabled() {
    return binding.fontPanelEnabled(this._tag)
  }

  set enabled(enabled) {
    binding.fontPanelEnabled(this._tag, enabled)
  }

  get accessoryView() {
    return retain(this, '_accessoryView', AppKitView, binding.fontPanelAccessoryView(this._tag))
  }

  set accessoryView(accessoryView) {
    binding.fontPanelAccessoryView(this._tag, adopt(accessoryView))

    this._accessoryView = accessoryView
  }

  setPanelFont(font, multiple) {
    binding.fontPanelSetPanelFont(this._tag, adopt(font), multiple)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitFontPanel }
    }
  }
}

expose(exports)
