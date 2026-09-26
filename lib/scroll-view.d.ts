import { Wrapper } from 'bare-foundation-registry'
import AppKitClipView = require('./clip-view')
import AppKitColor = require('./color')
import AppKitView = require('./view')

/** A scroll view, as an `NSScrollView`. */
interface AppKitScrollView<
  M extends Record<keyof M, unknown[]> = AppKitScrollView.Events
> extends AppKitView<M> {
  get contentView(): AppKitClipView | null
  set contentView(value: Wrapper)

  reflectScrolledClipView(clipView: Wrapper): this

  get documentView(): AppKitView | null
  set documentView(value: Wrapper)

  hasVerticalScroller: boolean

  hasHorizontalScroller: boolean

  autohidesScrollers: boolean

  /** A `BORDER_TYPE` constant. */
  borderType: number

  /** A `SCROLLER_STYLE` constant. */
  scrollerStyle: number

  drawsBackground: boolean

  get backgroundColor(): AppKitColor | null
  set backgroundColor(value: Wrapper)

  allowsMagnification: boolean

  magnification: number

  /** An `ELASTICITY` constant. */
  horizontalScrollElasticity: number

  /** An `ELASTICITY` constant. */
  verticalScrollElasticity: number

  readonly contentSize: { width: number; height: number }

  readonly documentVisibleRect: { x: number; y: number; width: number; height: number }

  rulersVisible: boolean

  hasHorizontalRuler: boolean

  hasVerticalRuler: boolean

  scrollsDynamically: boolean

  lineScroll: number

  pageScroll: number

  horizontalLineScroll: number

  verticalLineScroll: number

  horizontalPageScroll: number

  verticalPageScroll: number

  automaticallyAdjustsContentInsets: boolean

  get contentInsets(): { top: number; left: number; bottom: number; right: number }
  set contentInsets(value: Partial<{ top: number; left: number; bottom: number; right: number }>)

  get scrollerInsets(): { top: number; left: number; bottom: number; right: number }
  set scrollerInsets(value: Partial<{ top: number; left: number; bottom: number; right: number }>)

  findBarPosition: number

  minMagnification: number

  maxMagnification: number

  flashScrollers(): this
}

declare class AppKitScrollView<M extends Record<keyof M, unknown[]> = AppKitScrollView.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly BORDER_TYPE: {
    readonly NONE: number
    readonly LINE: number
    readonly BEZEL: number
    readonly GROOVE: number
  }

  static readonly SCROLLER_STYLE: {
    readonly LEGACY: number
    readonly OVERLAY: number
  }

  static readonly ELASTICITY: {
    readonly AUTOMATIC: number
    readonly NONE: number
    readonly ALLOWED: number
  }
}

declare namespace AppKitScrollView {
  export interface Events {
    willDraw: []
  }
}

export = AppKitScrollView
