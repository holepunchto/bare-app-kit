import AppKitControl = require('./control')

/** A stepper, as an `NSStepper`. */
interface AppKitStepper<
  M extends Record<keyof M, unknown[]> = AppKitStepper.Events
> extends AppKitControl<M> {
  minValue: number

  maxValue: number

  increment: number

  valueWraps: boolean

  autorepeat: boolean
}

declare class AppKitStepper<M extends Record<keyof M, unknown[]> = AppKitStepper.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })
}

declare namespace AppKitStepper {
  export interface Events {
    change: []
  }
}

export = AppKitStepper
