const binding = require('../binding')
const registry = require('bare-foundation-registry')

module.exports = exports = class AppKitTextContainer {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  get [registry.tag]() {
    return this._tag
  }

  get [registry.handle]() {
    return binding.handle(this._tag)
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
