const binding = require('../binding')
const { expose } = require('./handle')
const wrap = require('./wrap')
const AppKitImage = require('./image')

module.exports = exports = class AppKitCursor {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  static get arrow() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_ARROW))
  }

  static get ibeam() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_IBEAM))
  }

  static get ibeamVertical() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_IBEAM_VERTICAL))
  }

  static get crosshair() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_CROSSHAIR))
  }

  static get pointingHand() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_POINTING_HAND))
  }

  static get closedHand() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_CLOSED_HAND))
  }

  static get openHand() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_OPEN_HAND))
  }

  static get resizeLeft() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_RESIZE_LEFT))
  }

  static get resizeRight() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_RESIZE_RIGHT))
  }

  static get resizeLeftRight() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_RESIZE_LEFT_RIGHT))
  }

  static get resizeUp() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_RESIZE_UP))
  }

  static get resizeDown() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_RESIZE_DOWN))
  }

  static get resizeUpDown() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_RESIZE_UP_DOWN))
  }

  static get disappearingItem() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_DISAPPEARING_ITEM))
  }

  static get operationNotAllowed() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_OPERATION_NOT_ALLOWED))
  }

  static get dragLink() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_DRAG_LINK))
  }

  static get dragCopy() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_DRAG_COPY))
  }

  static get contextualMenu() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_CONTEXTUAL_MENU))
  }

  static get current() {
    return wrap(AppKitCursor, binding.cursorSystem(binding.CURSOR_CURRENT))
  }

  static system(id) {
    return wrap(AppKitCursor, binding.cursorSystem(id))
  }

  static hide() {
    return binding.cursorHide()
  }

  static unhide() {
    return binding.cursorUnhide()
  }

  static pop() {
    return binding.cursorPop()
  }

  get image() {
    return wrap(AppKitImage, binding.cursorImage(this._tag))
  }

  get hotSpot() {
    return binding.cursorHotSpot(this._tag)
  }

  set() {
    binding.cursorSet(this._tag)
    return this
  }

  push() {
    binding.cursorPush(this._tag)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitCursor }
    }
  }
}

expose(exports)
