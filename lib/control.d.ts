import AppKitAttributedString = require('./attributed-string')
import AppKitCell = require('./cell')
import AppKitFont = require('./font')
import AppKitText = require('./text')
import AppKitView = require('./view')

/** A control, as an `NSControl`. */
interface AppKitControl<
  M extends Record<keyof M, unknown[]> = AppKitView.Events
> extends AppKitView<M> {
  readonly cell: AppKitCell | null

  readonly currentEditor: AppKitText | null

  enabled: boolean

  continuous: boolean

  ignoresMultiClick: boolean

  highlighted: boolean

  refusesFirstResponder: boolean

  tag: number

  /** A `SIZE` constant. */
  controlSize: number

  stringValue: string | null

  get attributedStringValue(): AppKitAttributedString | null
  set attributedStringValue(value: AppKitAttributedString)

  intValue: number

  integerValue: number

  floatValue: number

  doubleValue: number

  sizeToFit(): this

  performClick(): this

  font: AppKitFont | null

  /** A `TEXT_ALIGNMENT` constant. */
  alignment: number

  /** A `LINE_BREAK_MODE` constant. */
  lineBreakMode: number

  usesSingleLineMode: boolean
}

declare class AppKitControl<M extends Record<keyof M, unknown[]> = AppKitView.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly SIZE: {
    readonly REGULAR: number
    readonly SMALL: number
    readonly MINI: number
    readonly LARGE: number
  }

  static readonly STATE_VALUE: {
    readonly MIXED: number
    readonly OFF: number
    readonly ON: number
  }

  static readonly TEXT_ALIGNMENT: {
    readonly LEFT: number
    readonly RIGHT: number
    readonly CENTER: number
    readonly JUSTIFIED: number
    readonly NATURAL: number
  }

  static readonly LINE_BREAK_MODE: {
    readonly WORD_WRAPPING: number
    readonly CHAR_WRAPPING: number
    readonly CLIPPING: number
    readonly TRUNCATING_HEAD: number
    readonly TRUNCATING_TAIL: number
    readonly TRUNCATING_MIDDLE: number
  }
}

export = AppKitControl
