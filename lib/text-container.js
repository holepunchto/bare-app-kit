const binding = require('../binding')
const { expose } = require('./handle')

module.exports = exports = class AppKitTextContainer {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  get lineFragmentPadding() {
    return binding.textContainerLineFragmentPadding(this._tag)
  }

  set lineFragmentPadding(lineFragmentPadding) {
    binding.textContainerLineFragmentPadding(this._tag, lineFragmentPadding)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTextContainer }
    }
  }
}

expose(exports)
