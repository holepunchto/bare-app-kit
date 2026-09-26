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
  didResize: binding.PANEL_EVENT_DID_RESIZE,
  didMove: binding.PANEL_EVENT_DID_MOVE,
  willClose: binding.PANEL_EVENT_WILL_CLOSE,
  didBecomeKey: binding.PANEL_EVENT_DID_BECOME_KEY,
  didResignKey: binding.PANEL_EVENT_DID_RESIGN_KEY,
  didBecomeMain: binding.PANEL_EVENT_DID_BECOME_MAIN,
  didResignMain: binding.PANEL_EVENT_DID_RESIGN_MAIN,
  didMiniaturize: binding.PANEL_EVENT_DID_MINIATURIZE,
  didDeminiaturize: binding.PANEL_EVENT_DID_DEMINIATURIZE,
  didEnterFullScreen: binding.PANEL_EVENT_DID_ENTER_FULL_SCREEN,
  didExitFullScreen: binding.PANEL_EVENT_DID_EXIT_FULL_SCREEN,
  willStartLiveResize: binding.PANEL_EVENT_WILL_START_LIVE_RESIZE,
  didEndLiveResize: binding.PANEL_EVENT_DID_END_LIVE_RESIZE
}

exports._always = binding.PANEL_EVENT_WILL_CLOSE
