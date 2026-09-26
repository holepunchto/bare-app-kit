const binding = require('../binding')
const wrap = require('./wrap')

module.exports = exports = class AppKitAppearance {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  static named(name) {
    return wrap(AppKitAppearance, binding.appearanceNamed(name))
  }

  static current() {
    return wrap(AppKitAppearance, binding.appearanceCurrent())
  }

  get name() {
    return binding.appearanceName(this._tag)
  }

  bestMatch(names) {
    return binding.appearanceBestMatch(this._tag, names)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitAppearance }
    }
  }
}
