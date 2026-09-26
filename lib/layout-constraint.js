const binding = require('../binding')
const { expose } = require('./handle')

module.exports = exports = class AppKitLayoutConstraint {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  static activate(constraints) {
    return binding.layoutConstraintActivate(constraints.map((object) => object._tag))
  }

  static deactivate(constraints) {
    return binding.layoutConstraintDeactivate(constraints.map((object) => object._tag))
  }

  get active() {
    return binding.layoutConstraintActive(this._tag)
  }

  set active(active) {
    binding.layoutConstraintActive(this._tag, active)
  }

  get constant() {
    return binding.layoutConstraintConstant(this._tag)
  }

  set constant(constant) {
    binding.layoutConstraintConstant(this._tag, constant)
  }

  get priority() {
    return binding.layoutConstraintPriority(this._tag)
  }

  set priority(priority) {
    binding.layoutConstraintPriority(this._tag, priority)
  }

  get identifier() {
    return binding.layoutConstraintIdentifier(this._tag)
  }

  set identifier(identifier) {
    binding.layoutConstraintIdentifier(this._tag, identifier)
  }

  get multiplier() {
    return binding.layoutConstraintMultiplier(this._tag)
  }

  get relation() {
    return binding.layoutConstraintRelation(this._tag)
  }

  get firstAttribute() {
    return binding.layoutConstraintFirstAttribute(this._tag)
  }

  get secondAttribute() {
    return binding.layoutConstraintSecondAttribute(this._tag)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitLayoutConstraint }
    }
  }
}

exports.RELATION = {
  LESS_THAN_OR_EQUAL: binding.LAYOUT_RELATION_LESS_THAN_OR_EQUAL,
  EQUAL: binding.LAYOUT_RELATION_EQUAL,
  GREATER_THAN_OR_EQUAL: binding.LAYOUT_RELATION_GREATER_THAN_OR_EQUAL
}

exports.PRIORITY = {
  REQUIRED: binding.LAYOUT_PRIORITY_REQUIRED,
  DEFAULT_HIGH: binding.LAYOUT_PRIORITY_DEFAULT_HIGH,
  DRAG_THAT_CAN_RESIZE_WINDOW: binding.LAYOUT_PRIORITY_DRAG_THAT_CAN_RESIZE_WINDOW,
  WINDOW_SIZE_STAY_PUT: binding.LAYOUT_PRIORITY_WINDOW_SIZE_STAY_PUT,
  DRAG_THAT_CANNOT_RESIZE_WINDOW: binding.LAYOUT_PRIORITY_DRAG_THAT_CANNOT_RESIZE_WINDOW,
  DEFAULT_LOW: binding.LAYOUT_PRIORITY_DEFAULT_LOW,
  FITTING_SIZE_COMPRESSION: binding.LAYOUT_PRIORITY_FITTING_SIZE_COMPRESSION
}

expose(exports)
