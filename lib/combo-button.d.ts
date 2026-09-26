import { Wrapper } from 'bare-foundation-registry'
import AppKitControl = require('./control')
import AppKitImage = require('./image')
import AppKitMenu = require('./menu')

/** A combo button, as an `NSComboButton`. */
interface AppKitComboButton<
  M extends Record<keyof M, unknown[]> = AppKitComboButton.Events
> extends AppKitControl<M> {
  title: string | null

  get image(): AppKitImage | null
  set image(value: Wrapper)

  imageScaling: number

  /** A `STYLE` constant. */
  style: number

  get menu(): AppKitMenu | null
  set menu(value: Wrapper)
}

declare class AppKitComboButton<M extends Record<keyof M, unknown[]> = AppKitComboButton.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly STYLE: {
    readonly SPLIT: number
    readonly UNIFIED: number
  }
}

declare namespace AppKitComboButton {
  export interface Events {
    click: []
  }
}

export = AppKitComboButton
