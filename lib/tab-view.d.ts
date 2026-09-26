import { Wrapper } from 'bare-foundation-registry'
import AppKitFont = require('./font')
import AppKitTabViewItem = require('./tab-view-item')
import AppKitView = require('./view')

/** A tab view, as an `NSTabView`. */
interface AppKitTabView<
  M extends Record<keyof M, unknown[]> = AppKitTabView.Events
> extends AppKitView<M> {
  /** A `TYPE` constant. */
  tabViewType: number

  /** A `POSITION` constant. */
  tabPosition: number

  get font(): AppKitFont | null
  set font(value: Wrapper)

  readonly numberOfTabViewItems: number

  allowsTruncatedLabels: boolean

  drawsBackground: boolean

  controlSize: number

  /** A `TYPE` constant. */
  tabViewBorderType: number

  readonly contentRect: AppKitView.Rect

  readonly minimumSize: AppKitView.Size

  readonly indexOfSelectedTabViewItem: number

  selectTabViewItemAtIndex(index: number): this

  readonly tabViewItems: AppKitTabViewItem[]

  readonly selectedTabViewItem: AppKitTabViewItem | null

  indexOfTabViewItem(item: AppKitTabViewItem): number

  addTabViewItem(item: Wrapper): this

  insertTabViewItem(item: Wrapper, index: number): this

  removeTabViewItem(item: Wrapper): this
}

declare class AppKitTabView<M extends Record<keyof M, unknown[]> = AppKitTabView.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly TYPE: {
    readonly TOP_TABS_BEZEL_BORDER: number
    readonly LEFT_TABS_BEZEL_BORDER: number
    readonly BOTTOM_TABS_BEZEL_BORDER: number
    readonly RIGHT_TABS_BEZEL_BORDER: number
    readonly NO_TABS_BEZEL_BORDER: number
    readonly NO_TABS_LINE_BORDER: number
    readonly NO_TABS_NO_BORDER: number
  }

  static readonly POSITION: {
    readonly NONE: number
    readonly TOP: number
    readonly LEFT: number
    readonly BOTTOM: number
    readonly RIGHT: number
  }
}

declare namespace AppKitTabView {
  export interface Events {
    didSelect: []
  }
}

export = AppKitTabView
