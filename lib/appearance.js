const binding = require('../binding')
const registry = require('bare-foundation-registry')
const wrap = require('./wrap')

module.exports = exports = class AppKitAppearance {
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

  static named(name) {
    return wrap(AppKitAppearance, binding.appearanceNamed(name))
  }

  static current() {
    return wrap(AppKitAppearance, binding.appearanceCurrent())
  }

  get name() {
    return binding.appearanceName(this._tag)
  }

  bestMatchFromAppearancesWithNames(names) {
    return binding.appearanceBestMatch(this._tag, names)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitAppearance }
    }
  }
}
