import AppKitColor = require('./color')
import AppKitControl = require('./control')

/** A button, as an `NSButton`. */
interface AppKitButton<
  M extends Record<keyof M, unknown[]> = AppKitButton.Events
> extends AppKitControl<M> {
  title: string | null

  alternateTitle: string | null

  state: number

  allowsMixedState: boolean

  /** A `BEZEL_STYLE` constant. */
  bezelStyle: number

  bordered: boolean

  transparent: boolean

  showsBorderOnlyWhileMouseInside: boolean

  springLoaded: boolean

  hasDestructiveAction: boolean

  keyEquivalent: string | null

  keyEquivalentModifierMask: number

  /** `type` is a `TYPE` constant. */
  setButtonType(type: number): this

  setNextState(): this

  highlight(flag: boolean): this

  setPeriodicDelay(delay: number, interval: number): this

  getPeriodicDelay(): number

  contentTintColor: AppKitColor | null

  bezelColor: AppKitColor | null

  /** A `CELL_IMAGE_POSITION` constant. */
  imagePosition: number

  /** An `IMAGE_SCALING` constant. */
  imageScaling: number
}

declare class AppKitButton<M extends Record<keyof M, unknown[]> = AppKitButton.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly TYPE: {
    readonly MOMENTARY_LIGHT: number
    readonly PUSH_ON_PUSH_OFF: number
    readonly TOGGLE: number
    readonly SWITCH: number
    readonly RADIO: number
    readonly MOMENTARY_CHANGE: number
    readonly ON_OFF: number
    readonly MOMENTARY_PUSH_IN: number
    readonly ACCELERATOR: number
    readonly MULTI_LEVEL_ACCELERATOR: number
  }

  static readonly BEZEL_STYLE: {
    readonly PUSH: number
    readonly FLEXIBLE_PUSH: number
    readonly DISCLOSURE: number
    readonly CIRCULAR: number
    readonly HELP_BUTTON: number
    readonly SMALL_SQUARE: number
    readonly TOOLBAR: number
    readonly ACCESSORY_BAR_ACTION: number
    readonly ACCESSORY_BAR: number
    readonly PUSH_DISCLOSURE: number
    readonly BADGE: number
  }

  static readonly CELL_IMAGE_POSITION: {
    readonly NO_IMAGE: number
    readonly IMAGE_ONLY: number
    readonly IMAGE_LEFT: number
    readonly IMAGE_RIGHT: number
    readonly IMAGE_BELOW: number
    readonly IMAGE_ABOVE: number
    readonly IMAGE_OVERLAPS: number
    readonly IMAGE_LEADING: number
    readonly IMAGE_TRAILING: number
  }

  static readonly IMAGE_SCALING: {
    readonly PROPORTIONALLY_DOWN: number
    readonly AXES_INDEPENDENTLY: number
    readonly NONE: number
    readonly PROPORTIONALLY_UP_OR_DOWN: number
  }
}

declare namespace AppKitButton {
  export interface Events {
    mouseDown: []
    click: []
  }
}

export = AppKitButton
