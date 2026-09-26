const binding = require('../binding')
const { expose } = require('./handle')
const observe = require('./events')
const EventEmitter = require('bare-events')

module.exports = exports = class AppKitTrackingArea extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init(opts) {
    const {
      x = 0,
      y = 0,
      width = 0,
      height = 0,
      options = binding.TRACKING_AREA_OPTIONS_MOUSE_ENTERED_AND_EXITED |
        binding.TRACKING_AREA_OPTIONS_ACTIVE_IN_KEY_WINDOW
    } = opts

    return binding.trackingAreaInit(x, y, width, height, options, this)
  }

  get rect() {
    return binding.trackingAreaRect(this._tag)
  }

  get options() {
    return binding.trackingAreaOptions(this._tag)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTrackingArea }
    }
  }

  _onmouseentered() {
    this.emit('mouseEntered')
  }

  _onmouseexited() {
    this.emit('mouseExited')
  }

  _onmousemoved() {
    this.emit('mouseMoved')
  }

  _oncursorupdate() {
    this.emit('cursorUpdate')
  }
}

exports.OPTIONS = {
  MOUSE_ENTERED_AND_EXITED: binding.TRACKING_AREA_OPTIONS_MOUSE_ENTERED_AND_EXITED,
  MOUSE_MOVED: binding.TRACKING_AREA_OPTIONS_MOUSE_MOVED,
  CURSOR_UPDATE: binding.TRACKING_AREA_OPTIONS_CURSOR_UPDATE,
  ACTIVE_WHEN_FIRST_RESPONDER: binding.TRACKING_AREA_OPTIONS_ACTIVE_WHEN_FIRST_RESPONDER,
  ACTIVE_IN_KEY_WINDOW: binding.TRACKING_AREA_OPTIONS_ACTIVE_IN_KEY_WINDOW,
  ACTIVE_IN_ACTIVE_APP: binding.TRACKING_AREA_OPTIONS_ACTIVE_IN_ACTIVE_APP,
  ACTIVE_ALWAYS: binding.TRACKING_AREA_OPTIONS_ACTIVE_ALWAYS,
  ASSUME_INSIDE: binding.TRACKING_AREA_OPTIONS_ASSUME_INSIDE,
  IN_VISIBLE_RECT: binding.TRACKING_AREA_OPTIONS_IN_VISIBLE_RECT,
  ENABLED_DURING_MOUSE_DRAG: binding.TRACKING_AREA_OPTIONS_ENABLED_DURING_MOUSE_DRAG
}

exports._events = {
  mouseEntered: 1,
  mouseExited: 2,
  mouseMoved: 4,
  cursorUpdate: 8
}

expose(exports)
