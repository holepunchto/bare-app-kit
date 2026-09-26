import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitImage = require('./image')
import AppKitMenuItem = require('./menu-item')
import AppKitView = require('./view')

/** A toolbar item, as an `NSToolbarItem`. */
interface AppKitToolbarItem<
  M extends Record<keyof M, unknown[]> = AppKitToolbarItem.Events
> extends EventEmitter<M> {
  readonly itemIdentifier: string | null

  label: string | null

  paletteLabel: string | null

  toolTip: string | null

  title: string | null

  tag: number

  enabled: boolean

  bordered: boolean

  navigational: boolean

  autovalidates: boolean

  readonly visible: boolean

  /** A `VISIBILITY_PRIORITY` constant. */
  visibilityPriority: number

  get image(): AppKitImage | null
  set image(value: Wrapper)

  get view(): AppKitView | null
  set view(value: Wrapper)

  get menuFormRepresentation(): AppKitMenuItem | null
  set menuFormRepresentation(value: Wrapper)

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitToolbarItem<M extends Record<keyof M, unknown[]> = AppKitToolbarItem.Events> {
  constructor(opts?: { identifier?: string })

  static readonly VISIBILITY_PRIORITY: {
    readonly STANDARD: string
    readonly LOW: string
    readonly HIGH: string
    readonly USER: string
  }
}

declare namespace AppKitToolbarItem {
  export interface Events {
    click: []
  }
}

export = AppKitToolbarItem
