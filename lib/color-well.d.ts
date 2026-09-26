import { Wrapper } from 'bare-foundation-registry'
import AppKitColor = require('./color')
import AppKitControl = require('./control')
import AppKitImage = require('./image')

/** A color well, as an `NSColorWell`. */
interface AppKitColorWell<
  M extends Record<keyof M, unknown[]> = AppKitColorWell.Events
> extends AppKitControl<M> {
  get color(): AppKitColor | null
  set color(value: Wrapper)

  bordered: boolean

  readonly active: boolean

  colorWellStyle: number

  get image(): AppKitImage | null
  set image(value: Wrapper)

  activate(exclusive: boolean): this

  deactivate(): this
}

declare class AppKitColorWell<M extends Record<keyof M, unknown[]> = AppKitColorWell.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })
}

declare namespace AppKitColorWell {
  export interface Events {
    change: []
  }
}

export = AppKitColorWell
