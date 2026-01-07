const EventEmitter = require('bare-events')

module.exports = class AppKitView extends EventEmitter {
  constructor(handle = null) {
    super()

    this._handle = handle
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitView }
    }
  }
}
