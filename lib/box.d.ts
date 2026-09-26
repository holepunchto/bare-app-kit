import { Wrapper } from 'bare-foundation-registry'
import AppKitColor = require('./color')
import AppKitFont = require('./font')
import AppKitView = require('./view')

/** A box, as an `NSBox`. */
interface AppKitBox extends AppKitView<AppKitView.Events> {
  title: string | null

  /** A `TITLE_POSITION` constant. */
  titlePosition: number

  /** A `TYPE` constant. */
  boxType: number

  borderWidth: number

  cornerRadius: number

  transparent: boolean

  get contentViewMargins(): { width: number; height: number }
  set contentViewMargins(value: Partial<{ width: number; height: number }>)

  get contentView(): AppKitView | null
  set contentView(value: Wrapper)

  get fillColor(): AppKitColor | null
  set fillColor(value: Wrapper)

  get borderColor(): AppKitColor | null
  set borderColor(value: Wrapper)

  get titleFont(): AppKitFont | null
  set titleFont(value: Wrapper)

  sizeToFit(): this

  setFrameFromContentFrame(x: number, y: number, width: number, height: number): this
}

declare class AppKitBox {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly TYPE: {
    readonly PRIMARY: number
    readonly SEPARATOR: number
    readonly CUSTOM: number
  }

  static readonly TITLE_POSITION: {
    readonly NONE: number
    readonly ABOVE_TOP: number
    readonly AT_TOP: number
    readonly BELOW_TOP: number
    readonly ABOVE_BOTTOM: number
    readonly AT_BOTTOM: number
    readonly BELOW_BOTTOM: number
  }
}

export = AppKitBox
