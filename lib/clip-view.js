const binding = require('../binding')
const { adopt } = require('./handle')
const wrap = require('./wrap')
const AppKitColor = require('./color')
const AppKitView = require('./view')

// The view an `NSScrollView` scrolls its document view inside. It is what
// knows where a scroll view has been scrolled to, and what says so.
module.exports = exports = class AppKitClipView extends AppKitView {
  static _events = {
    boundsDidChange: binding.CLIP_VIEW_EVENT_BOUNDS_DID_CHANGE
  }

  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.clipViewInit(x, y, width, height, this)
  }

  get drawsBackground() {
    return binding.clipViewDrawsBackground(this._tag)
  }

  set drawsBackground(value) {
    binding.clipViewDrawsBackground(this._tag, value)
  }

  get backgroundColor() {
    return wrap(AppKitColor, binding.clipViewBackgroundColor(this._tag))
  }

  set backgroundColor(value) {
    binding.clipViewBackgroundColor(this._tag, adopt(value))
  }

  scrollToPoint(x, y) {
    binding.clipViewScrollToPoint(this._tag, x, y)

    return this
  }

  _onboundsdidchange() {
    this.emit('boundsDidChange')
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitClipView }
    }
  }
}
