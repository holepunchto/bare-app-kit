import AppKitControl = require('./control')

/** A slider, as an `NSSlider`. */
interface AppKitSlider<
  M extends Record<keyof M, unknown[]> = AppKitSlider.Events
> extends AppKitControl<M> {
  minValue: number

  maxValue: number

  altIncrementValue: number

  readonly knobThickness: number

  vertical: boolean

  /** A `TYPE` constant. */
  sliderType: number

  numberOfTickMarks: number

  /** A `TICK_MARK_POSITION` constant. */
  tickMarkPosition: number

  allowsTickMarkValuesOnly: boolean

  tickMarkValueAtIndex(index: number): number

  closestTickMarkValueToValue(value: number): number
}

declare class AppKitSlider<M extends Record<keyof M, unknown[]> = AppKitSlider.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly TYPE: {
    readonly LINEAR: number
    readonly CIRCULAR: number
  }

  static readonly TICK_MARK_POSITION: {
    readonly BELOW: number
    readonly ABOVE: number
    readonly LEADING: number
    readonly TRAILING: number
  }
}

declare namespace AppKitSlider {
  export interface Events {
    change: []
  }
}

export = AppKitSlider
