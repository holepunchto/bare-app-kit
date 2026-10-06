import AppKitTextField = require('./text-field')

/** A token field, as an `NSTokenField`. */
interface AppKitTokenField<
  M extends Record<keyof M, unknown[]> = AppKitTokenField.Events
> extends AppKitTextField<M> {
  /** A `STYLE` constant. */
  tokenStyle: number

  completionDelay: number

  get tokens(): string[]
  set tokens(value: string[])
}

declare class AppKitTokenField<M extends Record<keyof M, unknown[]> = AppKitTokenField.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly STYLE: {
    readonly DEFAULT: number
    readonly NONE: number
    readonly ROUNDED: number
    readonly SQUARED: number
    readonly PLAIN_SQUARED: number
  }
}

declare namespace AppKitTokenField {
  export interface Events {
    change: []
    didChange: []
    didBeginEditing: []
    didEndEditing: []
  }
}

export = AppKitTokenField
