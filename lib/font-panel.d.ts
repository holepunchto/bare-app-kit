import { Wrapper } from 'bare-foundation-registry'
import AppKitPanel = require('./panel')
import AppKitView = require('./view')

/** A font panel, as an `NSFontPanel`. */
interface AppKitFontPanel extends AppKitPanel<AppKitPanel.Events> {
  enabled: boolean

  get accessoryView(): AppKitView | null
  set accessoryView(value: Wrapper)

  setPanelFont(font: Wrapper, multiple: boolean): this
}

declare class AppKitFontPanel {
  constructor(opts?: {
    x?: number
    y?: number
    width?: number
    height?: number
    styleMask?: number
    defer?: boolean
  })
}

export = AppKitFontPanel
