const binding = require('../binding')
const { expose } = require('./handle')
const wrap = require('./wrap')
const AppKitColor = require('./color')
const AppKitControl = require('./control')

module.exports = exports = class AppKitButton extends AppKitControl {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.buttonInit(x, y, width, height, this)
  }

  get title() {
    return binding.buttonTitle(this._tag)
  }

  set title(title) {
    binding.buttonTitle(this._tag, title)
  }

  get alternateTitle() {
    return binding.buttonAlternateTitle(this._tag)
  }

  set alternateTitle(alternateTitle) {
    binding.buttonAlternateTitle(this._tag, alternateTitle)
  }

  get state() {
    return binding.buttonState(this._tag)
  }

  set state(state) {
    binding.buttonState(this._tag, state)
  }

  get allowsMixedState() {
    return binding.buttonAllowsMixedState(this._tag)
  }

  set allowsMixedState(allowsMixedState) {
    binding.buttonAllowsMixedState(this._tag, allowsMixedState)
  }

  get bezelStyle() {
    return binding.buttonBezelStyle(this._tag)
  }

  set bezelStyle(bezelStyle) {
    binding.buttonBezelStyle(this._tag, bezelStyle)
  }

  get bordered() {
    return binding.buttonBordered(this._tag)
  }

  set bordered(bordered) {
    binding.buttonBordered(this._tag, bordered)
  }

  get transparent() {
    return binding.buttonTransparent(this._tag)
  }

  set transparent(transparent) {
    binding.buttonTransparent(this._tag, transparent)
  }

  get showsBorderOnlyWhileMouseInside() {
    return binding.buttonShowsBorderOnlyWhileMouseInside(this._tag)
  }

  set showsBorderOnlyWhileMouseInside(showsBorderOnlyWhileMouseInside) {
    binding.buttonShowsBorderOnlyWhileMouseInside(this._tag, showsBorderOnlyWhileMouseInside)
  }

  get springLoaded() {
    return binding.buttonSpringLoaded(this._tag)
  }

  set springLoaded(springLoaded) {
    binding.buttonSpringLoaded(this._tag, springLoaded)
  }

  get hasDestructiveAction() {
    return binding.buttonHasDestructiveAction(this._tag)
  }

  set hasDestructiveAction(hasDestructiveAction) {
    binding.buttonHasDestructiveAction(this._tag, hasDestructiveAction)
  }

  get keyEquivalent() {
    return binding.buttonKeyEquivalent(this._tag)
  }

  set keyEquivalent(keyEquivalent) {
    binding.buttonKeyEquivalent(this._tag, keyEquivalent)
  }

  get keyEquivalentModifierMask() {
    return binding.buttonKeyEquivalentModifierMask(this._tag)
  }

  set keyEquivalentModifierMask(keyEquivalentModifierMask) {
    binding.buttonKeyEquivalentModifierMask(this._tag, keyEquivalentModifierMask)
  }

  setButtonType(type) {
    binding.buttonSetButtonType(this._tag, type)
    return this
  }

  setNextState() {
    binding.buttonSetNextState(this._tag)
    return this
  }

  highlight(flag) {
    binding.buttonHighlight(this._tag, flag)
    return this
  }

  setPeriodicDelay(delay, interval) {
    binding.buttonSetPeriodicDelay(this._tag, delay, interval)
    return this
  }

  getPeriodicDelay() {
    return binding.buttonGetPeriodicDelay(this._tag)
  }

  get contentTintColor() {
    return wrap(AppKitColor, binding.buttonContentTintColor(this._tag))
  }

  set contentTintColor(contentTintColor) {
    binding.buttonContentTintColor(
      this._tag,
      contentTintColor === null ? null : contentTintColor._tag
    )
  }

  get bezelColor() {
    return wrap(AppKitColor, binding.buttonBezelColor(this._tag))
  }

  set bezelColor(bezelColor) {
    binding.buttonBezelColor(this._tag, bezelColor === null ? null : bezelColor._tag)
  }

  get imagePosition() {
    return binding.buttonImagePosition(this._tag)
  }

  set imagePosition(imagePosition) {
    binding.buttonImagePosition(this._tag, imagePosition)
  }

  get imageScaling() {
    return binding.buttonImageScaling(this._tag)
  }

  set imageScaling(imageScaling) {
    binding.buttonImageScaling(this._tag, imageScaling)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitButton }
    }
  }

  _onmousedown() {
    this.emit('mouseDown')
  }

  _onclick() {
    this.emit('click')
  }
}

exports.TYPE = {
  MOMENTARY_LIGHT: binding.BUTTON_TYPE_MOMENTARY_LIGHT,
  PUSH_ON_PUSH_OFF: binding.BUTTON_TYPE_PUSH_ON_PUSH_OFF,
  TOGGLE: binding.BUTTON_TYPE_TOGGLE,
  SWITCH: binding.BUTTON_TYPE_SWITCH,
  RADIO: binding.BUTTON_TYPE_RADIO,
  MOMENTARY_CHANGE: binding.BUTTON_TYPE_MOMENTARY_CHANGE,
  ON_OFF: binding.BUTTON_TYPE_ON_OFF,
  MOMENTARY_PUSH_IN: binding.BUTTON_TYPE_MOMENTARY_PUSH_IN,
  ACCELERATOR: binding.BUTTON_TYPE_ACCELERATOR,
  MULTI_LEVEL_ACCELERATOR: binding.BUTTON_TYPE_MULTI_LEVEL_ACCELERATOR
}

exports.BEZEL_STYLE = {
  PUSH: binding.BUTTON_BEZEL_STYLE_PUSH,
  FLEXIBLE_PUSH: binding.BUTTON_BEZEL_STYLE_FLEXIBLE_PUSH,
  DISCLOSURE: binding.BUTTON_BEZEL_STYLE_DISCLOSURE,
  CIRCULAR: binding.BUTTON_BEZEL_STYLE_CIRCULAR,
  HELP_BUTTON: binding.BUTTON_BEZEL_STYLE_HELP_BUTTON,
  SMALL_SQUARE: binding.BUTTON_BEZEL_STYLE_SMALL_SQUARE,
  TOOLBAR: binding.BUTTON_BEZEL_STYLE_TOOLBAR,
  ACCESSORY_BAR_ACTION: binding.BUTTON_BEZEL_STYLE_ACCESSORY_BAR_ACTION,
  ACCESSORY_BAR: binding.BUTTON_BEZEL_STYLE_ACCESSORY_BAR,
  PUSH_DISCLOSURE: binding.BUTTON_BEZEL_STYLE_PUSH_DISCLOSURE,
  BADGE: binding.BUTTON_BEZEL_STYLE_BADGE
}

exports.IMAGE_POSITION = {
  NO_IMAGE: binding.BUTTON_IMAGE_POSITION_NO_IMAGE,
  IMAGE_ONLY: binding.BUTTON_IMAGE_POSITION_IMAGE_ONLY,
  IMAGE_LEFT: binding.BUTTON_IMAGE_POSITION_IMAGE_LEFT,
  IMAGE_RIGHT: binding.BUTTON_IMAGE_POSITION_IMAGE_RIGHT,
  IMAGE_BELOW: binding.BUTTON_IMAGE_POSITION_IMAGE_BELOW,
  IMAGE_ABOVE: binding.BUTTON_IMAGE_POSITION_IMAGE_ABOVE,
  IMAGE_OVERLAPS: binding.BUTTON_IMAGE_POSITION_IMAGE_OVERLAPS,
  IMAGE_LEADING: binding.BUTTON_IMAGE_POSITION_IMAGE_LEADING,
  IMAGE_TRAILING: binding.BUTTON_IMAGE_POSITION_IMAGE_TRAILING
}

exports.IMAGE_SCALING = {
  PROPORTIONALLY_DOWN: binding.IMAGE_SCALING_PROPORTIONALLY_DOWN,
  AXES_INDEPENDENTLY: binding.IMAGE_SCALING_AXES_INDEPENDENTLY,
  NONE: binding.IMAGE_SCALING_NONE,
  PROPORTIONALLY_UP_OR_DOWN: binding.IMAGE_SCALING_PROPORTIONALLY_UP_OR_DOWN
}

exports._events = {
  mouseDown: 1,
  click: 2
}

expose(exports)
