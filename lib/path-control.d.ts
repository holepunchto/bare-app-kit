import { Wrapper } from 'bare-foundation-registry'
import AppKitColor = require('./color')
import AppKitControl = require('./control')
import AppKitMenu = require('./menu')
import AppKitPathControlItem = require('./path-control-item')

/** A path control, as an `NSPathControl`. */
interface AppKitPathControl<
  M extends Record<keyof M, unknown[]> = AppKitPathControl.Events
> extends AppKitControl<M> {
  get url(): string | null
  set url(value: string)

  /** A `STYLE` constant. */
  pathStyle: number

  editable: boolean

  placeholderString: string | null

  get backgroundColor(): AppKitColor | null
  set backgroundColor(value: Wrapper)

  get allowedTypes(): string[]
  set allowedTypes(value: string[])

  get menu(): AppKitMenu | null
  set menu(value: Wrapper)

  setPathItems(items: AppKitPathControlItem[]): this

  numberOfPathItems(): number

  pathItemAt(index: number): AppKitPathControlItem | null

  clickedPathItem(): AppKitPathControlItem | null
}

declare class AppKitPathControl<M extends Record<keyof M, unknown[]> = AppKitPathControl.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly STYLE: {
    readonly STANDARD: number
    readonly POP_UP: number
  }
}

declare namespace AppKitPathControl {
  export interface Events {
    change: []
  }
}

export = AppKitPathControl
