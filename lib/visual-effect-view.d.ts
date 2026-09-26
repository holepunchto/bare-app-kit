import AppKitView = require('./view')

/** A visual effect view, as an `NSVisualEffectView`. */
interface AppKitVisualEffectView extends AppKitView<AppKitView.Events> {
  /** A `MATERIAL` constant. */
  material: number

  /** A `BLENDING_MODE` constant. */
  blendingMode: number

  /** A `STATE` constant. */
  state: number

  emphasized: boolean
}

declare class AppKitVisualEffectView {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly MATERIAL: {
    readonly TITLEBAR: number
    readonly SELECTION: number
    readonly MENU: number
    readonly POPOVER: number
    readonly SIDEBAR: number
    readonly HEADER_VIEW: number
    readonly SHEET: number
    readonly WINDOW_BACKGROUND: number
    readonly HUD_WINDOW: number
    readonly FULL_SCREEN_UI: number
    readonly TOOL_TIP: number
    readonly CONTENT_BACKGROUND: number
    readonly UNDER_WINDOW_BACKGROUND: number
    readonly UNDER_PAGE_BACKGROUND: number
  }

  static readonly BLENDING_MODE: {
    readonly BEHIND_WINDOW: number
    readonly WITHIN_WINDOW: number
  }

  static readonly STATE: {
    readonly FOLLOWS_WINDOW_ACTIVE_STATE: number
    readonly ACTIVE: number
    readonly INACTIVE: number
  }
}

export = AppKitVisualEffectView
