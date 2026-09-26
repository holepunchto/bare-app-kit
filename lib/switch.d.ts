import AppKitControl = require('./control')

/** A switch, as an `NSSwitch`. */
interface AppKitSwitch<
  M extends Record<keyof M, unknown[]> = AppKitSwitch.Events
> extends AppKitControl<M> {
  state: number
}

declare class AppKitSwitch<M extends Record<keyof M, unknown[]> = AppKitSwitch.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })
}

declare namespace AppKitSwitch {
  export interface Events {
    change: []
    willDraw: []
  }
}

export = AppKitSwitch
