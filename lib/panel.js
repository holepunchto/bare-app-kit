const binding = require('../binding')
const AppKitWindow = require('./window')

module.exports = exports = class AppKitPanel extends AppKitWindow {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0, styleMask = 0, defer = false } = opts

    return binding.panelInit(x, y, width, height, styleMask, defer, this)
  }

  get floatingPanel() {
    return binding.panelFloatingPanel(this._tag)
  }

  set floatingPanel(floatingPanel) {
    binding.panelFloatingPanel(this._tag, floatingPanel)
  }

  get becomesKeyOnlyIfNeeded() {
    return binding.panelBecomesKeyOnlyIfNeeded(this._tag)
  }

  set becomesKeyOnlyIfNeeded(becomesKeyOnlyIfNeeded) {
    binding.panelBecomesKeyOnlyIfNeeded(this._tag, becomesKeyOnlyIfNeeded)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitPanel }
    }
  }
}

exports._events = {
  didResize: 1,
  didMove: 2,
  willClose: 4,
  didBecomeKey: 8,
  didResignKey: 16,
  didBecomeMain: 32,
  didResignMain: 64,
  didMiniaturize: 128,
  didDeminiaturize: 256,
  didEnterFullScreen: 512,
  didExitFullScreen: 1024,
  willStartLiveResize: 2048,
  didEndLiveResize: 4096
}

exports._always = 4
