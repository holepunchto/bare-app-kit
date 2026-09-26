const binding = require('../binding')
const { adopt } = require('./handle')
const scratch = require('./scratch')
const wrap = require('./wrap')
const AppKitView = require('./view')

module.exports = exports = class AppKitStackView extends AppKitView {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.stackViewInit(x, y, width, height)
  }

  get orientation() {
    return binding.stackViewOrientation(this._tag)
  }

  set orientation(orientation) {
    binding.stackViewOrientation(this._tag, orientation)
  }

  get alignment() {
    return binding.stackViewAlignment(this._tag)
  }

  set alignment(alignment) {
    binding.stackViewAlignment(this._tag, alignment)
  }

  get distribution() {
    return binding.stackViewDistribution(this._tag)
  }

  set distribution(distribution) {
    binding.stackViewDistribution(this._tag, distribution)
  }

  get spacing() {
    return binding.stackViewSpacing(this._tag)
  }

  set spacing(spacing) {
    binding.stackViewSpacing(this._tag, spacing)
  }

  get edgeInsets() {
    binding.stackViewEdgeInsetsInto(this._tag, scratch.buffer, 0)

    return { top: scratch[0], left: scratch[1], bottom: scratch[2], right: scratch[3] }
  }

  set edgeInsets(edgeInsets) {
    const { top = 0, left = 0, bottom = 0, right = 0 } = edgeInsets

    binding.stackViewEdgeInsets(this._tag, top, left, bottom, right)
  }

  get detachesHiddenViews() {
    return binding.stackViewDetachesHiddenViews(this._tag)
  }

  set detachesHiddenViews(detachesHiddenViews) {
    binding.stackViewDetachesHiddenViews(this._tag, detachesHiddenViews)
  }

  setVisibilityPriority(priority, view) {
    binding.stackViewSetVisibilityPriority(this._tag, priority, adopt(view))
    return this
  }

  setCustomSpacing(spacing, view) {
    binding.stackViewSetCustomSpacing(this._tag, spacing, adopt(view))
    return this
  }

  get arrangedSubviews() {
    return binding.stackViewArrangedSubviews(this._tag).map((tag) => wrap(AppKitView, tag))
  }

  addArrangedSubview(view) {
    binding.stackViewAddArrangedSubview(this._tag, this._attach(view))
    return this
  }

  insertArrangedSubview(view, index) {
    binding.stackViewInsertArrangedSubview(this._tag, this._attach(view), index)
    return this
  }

  removeArrangedSubview(view) {
    binding.stackViewRemoveArrangedSubview(this._tag, adopt(view))
    return this
  }

  removeView(view) {
    binding.stackViewRemoveView(this._tag, adopt(view))

    this._retained.delete(view)

    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitStackView }
    }
  }
}

exports.ORIENTATION = {
  HORIZONTAL: binding.STACK_VIEW_ORIENTATION_HORIZONTAL,
  VERTICAL: binding.STACK_VIEW_ORIENTATION_VERTICAL
}

exports.ALIGNMENT = {
  LEADING: binding.STACK_VIEW_ALIGNMENT_LEADING,
  TRAILING: binding.STACK_VIEW_ALIGNMENT_TRAILING,
  TOP: binding.STACK_VIEW_ALIGNMENT_TOP,
  BOTTOM: binding.STACK_VIEW_ALIGNMENT_BOTTOM,
  CENTER_X: binding.STACK_VIEW_ALIGNMENT_CENTER_X,
  CENTER_Y: binding.STACK_VIEW_ALIGNMENT_CENTER_Y,
  FIRST_BASELINE: binding.STACK_VIEW_ALIGNMENT_FIRST_BASELINE,
  WIDTH: binding.STACK_VIEW_ALIGNMENT_WIDTH,
  HEIGHT: binding.STACK_VIEW_ALIGNMENT_HEIGHT
}

exports.DISTRIBUTION = {
  GRAVITY_AREAS: binding.STACK_VIEW_DISTRIBUTION_GRAVITY_AREAS,
  FILL: binding.STACK_VIEW_DISTRIBUTION_FILL,
  FILL_EQUALLY: binding.STACK_VIEW_DISTRIBUTION_FILL_EQUALLY,
  FILL_PROPORTIONALLY: binding.STACK_VIEW_DISTRIBUTION_FILL_PROPORTIONALLY,
  EQUAL_SPACING: binding.STACK_VIEW_DISTRIBUTION_EQUAL_SPACING,
  EQUAL_CENTERING: binding.STACK_VIEW_DISTRIBUTION_EQUAL_CENTERING
}

exports.VISIBILITY_PRIORITY = {
  MUST_HOLD: binding.STACK_VIEW_VISIBILITY_PRIORITY_MUST_HOLD,
  DETACH_ONLY_IF_NECESSARY: binding.STACK_VIEW_VISIBILITY_PRIORITY_DETACH_ONLY_IF_NECESSARY,
  NOT_VISIBLE: binding.STACK_VIEW_VISIBILITY_PRIORITY_NOT_VISIBLE
}
