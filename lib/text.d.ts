import AppKitColor = require('./color')
import AppKitFont = require('./font')
import AppKitView = require('./view')

/** A text, as an `NSText`. */
interface AppKitText<
  M extends Record<keyof M, unknown[]> = AppKitView.Events
> extends AppKitView<M> {
  string: string | null

  editable: boolean

  selectable: boolean

  richText: boolean

  importsGraphics: boolean

  fieldEditor: boolean

  usesFontPanel: boolean

  drawsBackground: boolean

  readonly rulerVisible: boolean

  /** A `TEXT_ALIGNMENT` constant. */
  alignment: number

  /** A `WRITING_DIRECTION` constant. */
  baseWritingDirection: number

  sizeToFit(): this

  copy(): this

  cut(): this

  paste(): this

  delete(): this

  get selectedRange(): AppKitView.Range
  set selectedRange(value: Partial<{ location: number; length: number }>)

  selectAll(): this

  font: AppKitFont | null

  textColor: AppKitColor | null

  backgroundColor: AppKitColor | null

  verticallyResizable: boolean

  horizontallyResizable: boolean

  get minSize(): AppKitView.Size
  set minSize(value: Partial<{ width: number; height: number }>)

  get maxSize(): AppKitView.Size
  set maxSize(value: Partial<{ width: number; height: number }>)
}

declare class AppKitText<M extends Record<keyof M, unknown[]> = AppKitView.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly TEXT_ALIGNMENT: {
    readonly LEFT: number
    readonly RIGHT: number
    readonly CENTER: number
    readonly JUSTIFIED: number
    readonly NATURAL: number
  }

  static readonly WRITING_DIRECTION: {
    readonly NATURAL: number
    readonly LEFT_TO_RIGHT: number
    readonly RIGHT_TO_LEFT: number
  }
}

export = AppKitText
