const binding = require('../binding')
const { expose } = require('./handle')
const scratch = require('./scratch')
const wrap = require('./wrap')

module.exports = exports = class AppKitEvent {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  static current() {
    return wrap(AppKitEvent, binding.eventCurrent())
  }

  static currentModifierFlags() {
    return binding.eventCurrentModifierFlags()
  }

  static currentMouseLocation() {
    return binding.eventCurrentMouseLocation()
  }

  static currentPressedMouseButtons() {
    return binding.eventCurrentPressedMouseButtons()
  }

  static doubleClickInterval() {
    return binding.eventDoubleClickInterval()
  }

  get type() {
    return binding.eventType(this._tag)
  }

  get modifierFlags() {
    return binding.eventModifierFlags(this._tag)
  }

  get timestamp() {
    return binding.eventTimestamp(this._tag)
  }

  get windowNumber() {
    return binding.eventWindowNumber(this._tag)
  }

  get clickCount() {
    return binding.eventClickCount(this._tag)
  }

  get buttonNumber() {
    return binding.eventButtonNumber(this._tag)
  }

  get pressure() {
    return binding.eventPressure(this._tag)
  }

  get locationInWindow() {
    binding.eventLocationInWindowInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1] }
  }

  get deltaX() {
    return binding.eventDeltaX(this._tag)
  }

  get deltaY() {
    return binding.eventDeltaY(this._tag)
  }

  get scrollingDeltaX() {
    return binding.eventScrollingDeltaX(this._tag)
  }

  get scrollingDeltaY() {
    return binding.eventScrollingDeltaY(this._tag)
  }

  get magnification() {
    return binding.eventMagnification(this._tag)
  }

  get characters() {
    return binding.eventCharacters(this._tag)
  }

  get charactersIgnoringModifiers() {
    return binding.eventCharactersIgnoringModifiers(this._tag)
  }

  get keyCode() {
    return binding.eventKeyCode(this._tag)
  }

  get repeat() {
    return binding.eventRepeat(this._tag)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitEvent }
    }
  }
}

exports.TYPE = {
  LEFT_MOUSE_DOWN: binding.EVENT_TYPE_LEFT_MOUSE_DOWN,
  LEFT_MOUSE_UP: binding.EVENT_TYPE_LEFT_MOUSE_UP,
  RIGHT_MOUSE_DOWN: binding.EVENT_TYPE_RIGHT_MOUSE_DOWN,
  RIGHT_MOUSE_UP: binding.EVENT_TYPE_RIGHT_MOUSE_UP,
  MOUSE_MOVED: binding.EVENT_TYPE_MOUSE_MOVED,
  LEFT_MOUSE_DRAGGED: binding.EVENT_TYPE_LEFT_MOUSE_DRAGGED,
  RIGHT_MOUSE_DRAGGED: binding.EVENT_TYPE_RIGHT_MOUSE_DRAGGED,
  MOUSE_ENTERED: binding.EVENT_TYPE_MOUSE_ENTERED,
  MOUSE_EXITED: binding.EVENT_TYPE_MOUSE_EXITED,
  KEY_DOWN: binding.EVENT_TYPE_KEY_DOWN,
  KEY_UP: binding.EVENT_TYPE_KEY_UP,
  FLAGS_CHANGED: binding.EVENT_TYPE_FLAGS_CHANGED,
  SCROLL_WHEEL: binding.EVENT_TYPE_SCROLL_WHEEL,
  OTHER_MOUSE_DOWN: binding.EVENT_TYPE_OTHER_MOUSE_DOWN,
  OTHER_MOUSE_UP: binding.EVENT_TYPE_OTHER_MOUSE_UP,
  MAGNIFY: binding.EVENT_TYPE_MAGNIFY,
  SWIPE: binding.EVENT_TYPE_SWIPE,
  ROTATE: binding.EVENT_TYPE_ROTATE
}

exports.MODIFIER = {
  CAPS_LOCK: binding.EVENT_MODIFIER_CAPS_LOCK,
  SHIFT: binding.EVENT_MODIFIER_SHIFT,
  CONTROL: binding.EVENT_MODIFIER_CONTROL,
  OPTION: binding.EVENT_MODIFIER_OPTION,
  COMMAND: binding.EVENT_MODIFIER_COMMAND,
  FUNCTION: binding.EVENT_MODIFIER_FUNCTION
}

expose(exports)
