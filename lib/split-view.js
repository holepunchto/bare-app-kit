const binding = require('../binding')
const { adopt } = require('./handle')
const wrap = require('./wrap')
const AppKitView = require('./view')

module.exports = exports = class AppKitSplitView extends AppKitView {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.splitViewInit(x, y, width, height)
  }

  get vertical() {
    return binding.splitViewVertical(this._tag)
  }

  set vertical(vertical) {
    binding.splitViewVertical(this._tag, vertical)
  }

  get dividerStyle() {
    return binding.splitViewDividerStyle(this._tag)
  }

  set dividerStyle(dividerStyle) {
    binding.splitViewDividerStyle(this._tag, dividerStyle)
  }

  get arrangesAllSubviews() {
    return binding.splitViewArrangesAllSubviews(this._tag)
  }

  set arrangesAllSubviews(arrangesAllSubviews) {
    binding.splitViewArrangesAllSubviews(this._tag, arrangesAllSubviews)
  }

  get dividerThickness() {
    return binding.splitViewDividerThickness(this._tag)
  }

  setPosition(position, divider) {
    binding.splitViewSetPosition(this._tag, position, divider)
    return this
  }

  setHoldingPriority(priority, index) {
    binding.splitViewSetHoldingPriority(this._tag, priority, index)
    return this
  }

  holdingPriorityForSubviewAtIndex(index) {
    return binding.splitViewHoldingPriorityForSubviewAtIndex(this._tag, index)
  }

  adjustSubviews() {
    binding.splitViewAdjustSubviews(this._tag)
    return this
  }

  get arrangedSubviews() {
    return binding.splitViewArrangedSubviews(this._tag).map((tag) => wrap(AppKitView, tag))
  }

  addArrangedSubview(view) {
    binding.splitViewAddArrangedSubview(this._tag, this._attach(view))
    return this
  }

  insertArrangedSubview(view, index) {
    binding.splitViewInsertArrangedSubview(this._tag, this._attach(view), index)
    return this
  }

  removeArrangedSubview(view) {
    binding.splitViewRemoveArrangedSubview(this._tag, adopt(view))
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitSplitView }
    }
  }
}

exports.DIVIDER_STYLE = {
  THICK: binding.SPLIT_VIEW_DIVIDER_STYLE_THICK,
  THIN: binding.SPLIT_VIEW_DIVIDER_STYLE_THIN,
  PANE_SPLITTER: binding.SPLIT_VIEW_DIVIDER_STYLE_PANE_SPLITTER
}
