const binding = require('../binding')
const AppKitControl = require('./control')

module.exports = exports = class AppKitSegmentedControl extends AppKitControl {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.segmentedControlInit(x, y, width, height, this)
  }

  get segmentCount() {
    return binding.segmentedControlSegmentCount(this._tag)
  }

  set segmentCount(segmentCount) {
    binding.segmentedControlSegmentCount(this._tag, segmentCount)
  }

  get selectedSegment() {
    return binding.segmentedControlSelectedSegment(this._tag)
  }

  set selectedSegment(selectedSegment) {
    binding.segmentedControlSelectedSegment(this._tag, selectedSegment)
  }

  get segmentStyle() {
    return binding.segmentedControlSegmentStyle(this._tag)
  }

  set segmentStyle(segmentStyle) {
    binding.segmentedControlSegmentStyle(this._tag, segmentStyle)
  }

  get trackingMode() {
    return binding.segmentedControlTrackingMode(this._tag)
  }

  set trackingMode(trackingMode) {
    binding.segmentedControlTrackingMode(this._tag, trackingMode)
  }

  get segmentDistribution() {
    return binding.segmentedControlSegmentDistribution(this._tag)
  }

  set segmentDistribution(segmentDistribution) {
    binding.segmentedControlSegmentDistribution(this._tag, segmentDistribution)
  }

  setLabelForSegment(label, segment) {
    binding.segmentedControlSetLabelForSegment(this._tag, label, segment)
    return this
  }

  labelForSegment(segment) {
    return binding.segmentedControlLabelForSegment(this._tag, segment)
  }

  setWidthForSegment(width, segment) {
    binding.segmentedControlSetWidthForSegment(this._tag, width, segment)
    return this
  }

  widthForSegment(segment) {
    return binding.segmentedControlWidthForSegment(this._tag, segment)
  }

  setSelectedForSegment(selected, segment) {
    binding.segmentedControlSetSelectedForSegment(this._tag, selected, segment)
    return this
  }

  selectedForSegment(segment) {
    return binding.segmentedControlSelectedForSegment(this._tag, segment)
  }

  setEnabledForSegment(enabled, segment) {
    binding.segmentedControlSetEnabledForSegment(this._tag, enabled, segment)
    return this
  }

  enabledForSegment(segment) {
    return binding.segmentedControlEnabledForSegment(this._tag, segment)
  }

  setToolTipForSegment(toolTip, segment) {
    binding.segmentedControlSetToolTipForSegment(this._tag, toolTip, segment)
    return this
  }

  toolTipForSegment(segment) {
    return binding.segmentedControlToolTipForSegment(this._tag, segment)
  }

  setTagForSegment(tag, segment) {
    binding.segmentedControlSetTagForSegment(this._tag, tag, segment)
    return this
  }

  tagForSegment(segment) {
    return binding.segmentedControlTagForSegment(this._tag, segment)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitSegmentedControl }
    }
  }

  _onchange() {
    this.emit('change')
  }
}

exports._events = {
  change: 1
}

exports.STYLE = {
  AUTOMATIC: binding.SEGMENTED_CONTROL_STYLE_AUTOMATIC,
  ROUNDED: binding.SEGMENTED_CONTROL_STYLE_ROUNDED,
  ROUND_RECT: binding.SEGMENTED_CONTROL_STYLE_ROUND_RECT,
  TEXTURED_SQUARE: binding.SEGMENTED_CONTROL_STYLE_TEXTURED_SQUARE,
  SMALL_SQUARE: binding.SEGMENTED_CONTROL_STYLE_SMALL_SQUARE,
  SEPARATED: binding.SEGMENTED_CONTROL_STYLE_SEPARATED
}

exports.TRACKING_MODE = {
  SELECT_ONE: binding.SEGMENTED_CONTROL_TRACKING_MODE_SELECT_ONE,
  SELECT_ANY: binding.SEGMENTED_CONTROL_TRACKING_MODE_SELECT_ANY,
  MOMENTARY: binding.SEGMENTED_CONTROL_TRACKING_MODE_MOMENTARY,
  MOMENTARY_ACCELERATOR: binding.SEGMENTED_CONTROL_TRACKING_MODE_MOMENTARY_ACCELERATOR
}

exports.DISTRIBUTION = {
  FIT: binding.SEGMENTED_CONTROL_DISTRIBUTION_FIT,
  FILL: binding.SEGMENTED_CONTROL_DISTRIBUTION_FILL,
  FILL_EQUALLY: binding.SEGMENTED_CONTROL_DISTRIBUTION_FILL_EQUALLY,
  FILL_PROPORTIONALLY: binding.SEGMENTED_CONTROL_DISTRIBUTION_FILL_PROPORTIONALLY
}
