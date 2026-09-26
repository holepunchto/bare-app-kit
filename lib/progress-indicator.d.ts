import AppKitView = require('./view')

/** A progress indicator, as an `NSProgressIndicator`. */
interface AppKitProgressIndicator<
  M extends Record<keyof M, unknown[]> = AppKitProgressIndicator.Events
> extends AppKitView<M> {
  minValue: number

  maxValue: number

  doubleValue: number

  indeterminate: boolean

  /** A `STYLE` constant. */
  style: number

  controlSize: number

  usesThreadedAnimation: boolean

  displayedWhenStopped: boolean

  startAnimation(): this

  stopAnimation(): this

  incrementBy(delta: number): this

  sizeToFit(): this
}

declare class AppKitProgressIndicator<
  M extends Record<keyof M, unknown[]> = AppKitProgressIndicator.Events
> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly STYLE: {
    readonly BAR: number
    readonly SPINNING: number
  }
}

declare namespace AppKitProgressIndicator {
  export interface Events {
    willDraw: []
  }
}

export = AppKitProgressIndicator
