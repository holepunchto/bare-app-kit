import { tag, handle, Handle } from 'bare-foundation-registry'
import AppKitView = require('./view')

/** An event, as an `NSEvent`. */
interface AppKitEvent {
  /** A `TYPE` constant. */
  readonly type: number

  /** An `EVENT_MODIFIER_FLAGS` constant. */
  readonly modifierFlags: number

  readonly timestamp: number

  readonly windowNumber: number

  readonly clickCount: number

  readonly buttonNumber: number

  readonly pressure: number

  readonly locationInWindow: { x: number; y: number }

  readonly deltaX: number

  readonly deltaY: number

  readonly scrollingDeltaX: number

  readonly scrollingDeltaY: number

  readonly magnification: number

  readonly characters: string | null

  readonly charactersIgnoringModifiers: string | null

  readonly keyCode: number

  readonly repeat: boolean

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitEvent {
  protected constructor()

  static current(): AppKitEvent | null

  static currentModifierFlags(): number

  static currentMouseLocation(): AppKitView.Point

  static currentPressedMouseButtons(): number

  static doubleClickInterval(): number

  static readonly TYPE: {
    readonly LEFT_MOUSE_DOWN: number
    readonly LEFT_MOUSE_UP: number
    readonly RIGHT_MOUSE_DOWN: number
    readonly RIGHT_MOUSE_UP: number
    readonly MOUSE_MOVED: number
    readonly LEFT_MOUSE_DRAGGED: number
    readonly RIGHT_MOUSE_DRAGGED: number
    readonly MOUSE_ENTERED: number
    readonly MOUSE_EXITED: number
    readonly KEY_DOWN: number
    readonly KEY_UP: number
    readonly FLAGS_CHANGED: number
    readonly SCROLL_WHEEL: number
    readonly OTHER_MOUSE_DOWN: number
    readonly OTHER_MOUSE_UP: number
    readonly MAGNIFY: number
    readonly SWIPE: number
    readonly ROTATE: number
  }

  static readonly EVENT_MODIFIER_FLAGS: {
    readonly CAPS_LOCK: number
    readonly SHIFT: number
    readonly CONTROL: number
    readonly OPTION: number
    readonly COMMAND: number
    readonly FUNCTION: number
  }
}

export = AppKitEvent
