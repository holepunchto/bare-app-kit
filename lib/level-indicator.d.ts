import AppKitControl = require('./control')

/** A level indicator, as an `NSLevelIndicator`. */
interface AppKitLevelIndicator<
  M extends Record<keyof M, unknown[]> = AppKitLevelIndicator.Events
> extends AppKitControl<M> {
  minValue: number

  maxValue: number

  warningValue: number

  criticalValue: number

  /** A `STYLE` constant. */
  levelIndicatorStyle: number

  numberOfTickMarks: number

  numberOfMajorTickMarks: number

  tickMarkPosition: number

  editable: boolean

  tickMarkValueAtIndex(index: number): number
}

declare class AppKitLevelIndicator<
  M extends Record<keyof M, unknown[]> = AppKitLevelIndicator.Events
> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly STYLE: {
    readonly RELEVANCY: number
    readonly CONTINUOUS_CAPACITY: number
    readonly DISCRETE_CAPACITY: number
    readonly RATING: number
  }
}

declare namespace AppKitLevelIndicator {
  export interface Events {
    change: []
  }
}

export = AppKitLevelIndicator
