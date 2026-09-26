import { tag, handle, Handle } from 'bare-foundation-registry'

/** A layout constraint, as an `NSLayoutConstraint`. */
interface AppKitLayoutConstraint {
  active: boolean

  constant: number

  /** A `LAYOUT_PRIORITY` constant. */
  priority: number

  identifier: string | null

  readonly multiplier: number

  /** A `LAYOUT_RELATION` constant. */
  readonly relation: number

  readonly firstAttribute: number

  readonly secondAttribute: number

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitLayoutConstraint {
  protected constructor()

  static activate(constraints: AppKitLayoutConstraint[]): void

  static deactivate(constraints: AppKitLayoutConstraint[]): void

  static readonly LAYOUT_RELATION: {
    readonly LESS_THAN_OR_EQUAL: number
    readonly EQUAL: number
    readonly GREATER_THAN_OR_EQUAL: number
  }

  static readonly LAYOUT_PRIORITY: {
    readonly REQUIRED: number
    readonly DEFAULT_HIGH: number
    readonly DRAG_THAT_CAN_RESIZE_WINDOW: number
    readonly WINDOW_SIZE_STAY_PUT: number
    readonly DRAG_THAT_CANNOT_RESIZE_WINDOW: number
    readonly DEFAULT_LOW: number
    readonly FITTING_SIZE_COMPRESSION: number
  }
}

export = AppKitLayoutConstraint
