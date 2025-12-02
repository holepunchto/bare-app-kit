const EventEmitter = require('bare-events')
const binding = require('../binding')
const View = require('./view')

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

  get contentView() {
    return new View(binding.windowContentView(this._handle))
  }

  set contentView(view) {
    binding.windowContentView(this._handle, view._handle)
  }

  get titlebarAppearsTransparent() {
    return binding.windowTitlebarAppearsTransparent(this._handle)
  }

  set titlebarAppearsTransparent(value) {
    binding.windowTitlebarAppearsTransparent(this._handle, value)
  }

  center() {
    binding.windowCenter(this._handle)
    return this
  }

  close() {
    binding.windowClose(this._handle)
    return this
  }

  makeKeyWindow() {
    binding.windowMakeKeyWindow(this._handle)
    return this
  }

  orderBack() {
    binding.windowOrderBack(this._handle)
    return this
  }

  orderFront() {
    binding.windowOrderFront(this._handle)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitWindow }
    }
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
  RESIZABLE: binding.WINDOW_STYLE_MASK_RESIZABLE,
  FULL_SCREEN: binding.WINDOW_STYLE_MASK_FULL_SCREEN,
  FULL_SIZE_CONTENT_VIEW: binding.WINDOW_STYLE_MASK_FULL_SIZE_CONTENT_VIEW
}
