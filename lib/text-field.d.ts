import { Wrapper } from 'bare-foundation-registry'
import AppKitColor = require('./color')
import AppKitControl = require('./control')

/** A text field, as an `NSTextField`. */
interface AppKitTextField<
  M extends Record<keyof M, unknown[]> = AppKitTextField.Events
> extends AppKitControl<M> {
  placeholderString: string | null

  get textColor(): AppKitColor | null
  set textColor(value: Wrapper)

  get backgroundColor(): AppKitColor | null
  set backgroundColor(value: Wrapper)

  bordered: boolean

  bezeled: boolean

  editable: boolean

  selectable: boolean

  drawsBackground: boolean

  /** A `BEZEL_STYLE` constant. */
  bezelStyle: number

  truncatesLastVisibleLine: boolean

  maximumNumberOfLines: number

  preferredMaxLayoutWidth: number

  selectText(): this
}

declare class AppKitTextField<M extends Record<keyof M, unknown[]> = AppKitTextField.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly BEZEL_STYLE: {
    readonly SQUARE: number
    readonly ROUNDED: number
  }
}

declare namespace AppKitTextField {
  export interface Events {
    change: []
    didChange: []
    didBeginEditing: []
    didEndEditing: []
    becomeFirstResponder: []
    resignFirstResponder: []
    didChangeSelection: []
    shouldChangeText: [edit: { location: number; length: number; string: string }]
    willDraw: []
  }
}

export = AppKitTextField
