const binding = require('../binding')
const { adopt, expose } = require('./handle')
const wrap = require('./wrap')
const AppKitLayoutConstraint = require('./layout-constraint')

module.exports = exports = class AppKitLayoutAnchor {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  equalTo(anchor, constant) {
    return wrap(
      AppKitLayoutConstraint,
      binding.layoutAnchorEqualTo(this._tag, adopt(anchor), constant)
    )
  }

  greaterThanOrEqualTo(anchor, constant) {
    return wrap(
      AppKitLayoutConstraint,
      binding.layoutAnchorGreaterThanOrEqualTo(this._tag, adopt(anchor), constant)
    )
  }

  lessThanOrEqualTo(anchor, constant) {
    return wrap(
      AppKitLayoutConstraint,
      binding.layoutAnchorLessThanOrEqualTo(this._tag, adopt(anchor), constant)
    )
  }

  equalToConstant(constant) {
    return wrap(AppKitLayoutConstraint, binding.layoutAnchorEqualToConstant(this._tag, constant))
  }

  greaterThanOrEqualToConstant(constant) {
    return wrap(
      AppKitLayoutConstraint,
      binding.layoutAnchorGreaterThanOrEqualToConstant(this._tag, constant)
    )
  }

  lessThanOrEqualToConstant(constant) {
    return wrap(
      AppKitLayoutConstraint,
      binding.layoutAnchorLessThanOrEqualToConstant(this._tag, constant)
    )
  }

  equalToMultiple(anchor, multiplier, constant) {
    return wrap(
      AppKitLayoutConstraint,
      binding.layoutAnchorEqualToMultiple(this._tag, adopt(anchor), multiplier, constant)
    )
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitLayoutAnchor }
    }
  }
}

expose(exports)
