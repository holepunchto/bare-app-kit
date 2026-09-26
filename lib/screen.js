const binding = require('../binding')
const { expose } = require('./handle')
const scratch = require('./scratch')
const wrap = require('./wrap')

module.exports = exports = class AppKitScreen {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  static main() {
    return wrap(AppKitScreen, binding.screenMain())
  }

  static deepest() {
    return wrap(AppKitScreen, binding.screenDeepest())
  }

  static count() {
    return binding.screenCount()
  }

  static at(index) {
    return wrap(AppKitScreen, binding.screenAt(index))
  }

  get frame() {
    binding.screenFrameInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1], width: scratch[2], height: scratch[3] }
  }

  get visibleFrame() {
    binding.screenVisibleFrameInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1], width: scratch[2], height: scratch[3] }
  }

  get backingScaleFactor() {
    return binding.screenBackingScaleFactor(this._tag)
  }

  get localizedName() {
    return binding.screenLocalizedName(this._tag)
  }

  get safeAreaInsets() {
    binding.screenSafeAreaInsetsInto(this._tag, scratch.buffer, 0)

    return { top: scratch[0], left: scratch[1], bottom: scratch[2], right: scratch[3] }
  }

  get maximumFramesPerSecond() {
    return binding.screenMaximumFramesPerSecond(this._tag)
  }

  get minimumRefreshInterval() {
    return binding.screenMinimumRefreshInterval(this._tag)
  }

  get maximumRefreshInterval() {
    return binding.screenMaximumRefreshInterval(this._tag)
  }

  get displayUpdateGranularity() {
    return binding.screenDisplayUpdateGranularity(this._tag)
  }

  get auxiliaryTopLeftArea() {
    binding.screenAuxiliaryTopLeftAreaInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1], width: scratch[2], height: scratch[3] }
  }

  get auxiliaryTopRightArea() {
    binding.screenAuxiliaryTopRightAreaInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1], width: scratch[2], height: scratch[3] }
  }

  get maximumExtendedDynamicRangeColorComponentValue() {
    return binding.screenMaximumExtendedDynamicRangeColorComponentValue(this._tag)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitScreen }
    }
  }
}

expose(exports)
