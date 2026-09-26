import { Wrapper } from 'bare-foundation-registry'
import AppKitColor = require('./color')
import AppKitPanel = require('./panel')
import AppKitView = require('./view')

/** A color panel, as an `NSColorPanel`. */
interface AppKitColorPanel extends AppKitPanel<AppKitPanel.Events> {
  get color(): AppKitColor | null
  set color(value: Wrapper)

  /** A `MODE` constant. */
  mode: number

  showsAlpha: boolean

  continuous: boolean

  get accessoryView(): AppKitView | null
  set accessoryView(value: Wrapper)
}

declare class AppKitColorPanel {
  constructor(opts?: {
    x?: number
    y?: number
    width?: number
    height?: number
    styleMask?: number
    defer?: boolean
  })

  static readonly MODE: {
    readonly GRAY: number
    readonly RGB: number
    readonly CMYK: number
    readonly HSB: number
    readonly CUSTOM_PALETTE: number
    readonly COLOR_LIST: number
    readonly WHEEL: number
    readonly CRAYON: number
  }
}

export = AppKitColorPanel
