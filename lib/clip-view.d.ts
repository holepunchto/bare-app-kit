import { Wrapper } from 'bare-foundation-registry'
import AppKitColor = require('./color')
import AppKitView = require('./view')

/** A clip view, as an `NSClipView`. */
interface AppKitClipView<
  M extends Record<keyof M, unknown[]> = AppKitClipView.Events
> extends AppKitView<M> {
  drawsBackground: boolean

  get backgroundColor(): AppKitColor | null
  set backgroundColor(value: Wrapper)

  scrollToPoint(x: number, y: number): this
}

declare class AppKitClipView<M extends Record<keyof M, unknown[]> = AppKitClipView.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })
}

declare namespace AppKitClipView {
  export interface Events {
    boundsDidChange: []
  }
}

export = AppKitClipView
