import AppKitWindow = require('./window')

/** A panel, as an `NSPanel`. */
interface AppKitPanel<
  M extends Record<keyof M, unknown[]> = AppKitPanel.Events
> extends AppKitWindow<M> {
  floatingPanel: boolean

  becomesKeyOnlyIfNeeded: boolean
}

declare class AppKitPanel<M extends Record<keyof M, unknown[]> = AppKitPanel.Events> {
  constructor(opts?: {
    x?: number
    y?: number
    width?: number
    height?: number
    styleMask?: number
    defer?: boolean
  })
}

declare namespace AppKitPanel {
  export interface Events {
    didResize: []
    didMove: []
    willClose: []
    didBecomeKey: []
    didResignKey: []
    didBecomeMain: []
    didResignMain: []
    didMiniaturize: []
    didDeminiaturize: []
    didEnterFullScreen: []
    didExitFullScreen: []
    willStartLiveResize: []
    didEndLiveResize: []
  }
}

export = AppKitPanel
