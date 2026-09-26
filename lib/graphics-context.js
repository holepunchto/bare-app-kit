const binding = require('../binding')
const { expose } = require('./handle')
const wrap = require('./wrap')

module.exports = exports = class AppKitGraphicsContext {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  static current() {
    return wrap(AppKitGraphicsContext, binding.graphicsContextCurrent())
  }

  static save() {
    return binding.graphicsContextSave()
  }

  static restore() {
    return binding.graphicsContextRestore()
  }

  get shouldAntialias() {
    return binding.graphicsContextShouldAntialias(this._tag)
  }

  set shouldAntialias(shouldAntialias) {
    binding.graphicsContextShouldAntialias(this._tag, shouldAntialias)
  }

  get imageInterpolation() {
    return binding.graphicsContextImageInterpolation(this._tag)
  }

  set imageInterpolation(imageInterpolation) {
    binding.graphicsContextImageInterpolation(this._tag, imageInterpolation)
  }

  get compositingOperation() {
    return binding.graphicsContextCompositingOperation(this._tag)
  }

  set compositingOperation(compositingOperation) {
    binding.graphicsContextCompositingOperation(this._tag, compositingOperation)
  }

  get flipped() {
    return binding.graphicsContextFlipped(this._tag)
  }

  flush() {
    binding.graphicsContextFlush(this._tag)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitGraphicsContext }
    }
  }
}

exports.COMPOSITING = {
  CLEAR: binding.GRAPHICS_CONTEXT_COMPOSITING_CLEAR,
  COPY: binding.GRAPHICS_CONTEXT_COMPOSITING_COPY,
  SOURCE_OVER: binding.GRAPHICS_CONTEXT_COMPOSITING_SOURCE_OVER,
  MULTIPLY: binding.GRAPHICS_CONTEXT_COMPOSITING_MULTIPLY,
  SCREEN: binding.GRAPHICS_CONTEXT_COMPOSITING_SCREEN,
  OVERLAY: binding.GRAPHICS_CONTEXT_COMPOSITING_OVERLAY,
  DARKEN: binding.GRAPHICS_CONTEXT_COMPOSITING_DARKEN,
  LIGHTEN: binding.GRAPHICS_CONTEXT_COMPOSITING_LIGHTEN
}

exports.INTERPOLATION = {
  DEFAULT: binding.GRAPHICS_CONTEXT_INTERPOLATION_DEFAULT,
  NONE: binding.GRAPHICS_CONTEXT_INTERPOLATION_NONE,
  LOW: binding.GRAPHICS_CONTEXT_INTERPOLATION_LOW,
  MEDIUM: binding.GRAPHICS_CONTEXT_INTERPOLATION_MEDIUM,
  HIGH: binding.GRAPHICS_CONTEXT_INTERPOLATION_HIGH
}

expose(exports)
