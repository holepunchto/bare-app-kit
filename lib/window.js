const EventEmitter = require('bare-events')
const binding = require('../binding')

module.exports = exports = class AppKitWindow extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { x = 0, y = 0, width = 0, height = 0, styleMask = 0, defer = false } = opts

    this._handle = binding.windowInit(
      x,
      y,
      width,
      height,
      styleMask,
      defer,
      this,
      this._ondidresize,
      this._ondidmove,
      this._onwillclose
    )
  }

  makeKeyAndOrderFront() {
    binding.windowMakeKeyAndOrderFront(this._handle)
  }

  _ondidresize() {
    this.emit('did-resize')
  }

  _ondidmove() {
    this.emit('did-move')
  }

  _onwillclose() {
    this.emit('will-close')
  }
}

exports.STYLE_MASK = {
  BORDERLESS: binding.WINDOW_STYLE_MASK_BORDERLESS,
  TITLED: binding.WINDOW_STYLE_MASK_TITLED,
  CLOSABLE: binding.WINDOW_STYLE_MASK_CLOSABLE,
  MINIATURIZABLE: binding.WINDOW_STYLE_MASK_MINIATURIZABLE,
  RESIZABLE: binding.WINDOW_STYLE_MASK_RESIZABLE
}
