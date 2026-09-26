import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitToolbarItem = require('./toolbar-item')

/** A toolbar, as an `NSToolbar`. */
interface AppKitToolbar<
  M extends Record<keyof M, unknown[]> = AppKitToolbar.Events
> extends EventEmitter<M> {
  readonly items: AppKitToolbarItem[]

  addItem(item: Wrapper): this

  get allowedItemIdentifiers(): string | null
  set allowedItemIdentifiers(value: string[])

  get defaultItemIdentifiers(): string | null
  set defaultItemIdentifiers(value: string[])

  /** An `ITEM_IDENTIFIER` constant. */
  readonly identifier: string | null

  /** A `DISPLAY_MODE` constant. */
  displayMode: number

  /** An `ITEM_IDENTIFIER` constant. */
  selectedItemIdentifier: string | null

  readonly centeredItemIdentifiers: string | null

  visible: boolean

  allowsUserCustomization: boolean

  allowsExtensionItems: boolean

  autosavesConfiguration: boolean

  readonly customizationPaletteIsRunning: boolean

  insertItemWithItemIdentifier(identifier: string | null, index: number): this

  removeItemAtIndex(index: number): this

  runCustomizationPalette(): this

  validateVisibleItems(): this

  setCenteredItemIdentifiers(identifiers: string[]): this

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitToolbar<M extends Record<keyof M, unknown[]> = AppKitToolbar.Events> {
  constructor(opts?: { identifier?: string })

  static readonly DISPLAY_MODE: {
    readonly DEFAULT: number
    readonly ICON_AND_LABEL: number
    readonly ICON_ONLY: number
    readonly LABEL_ONLY: number
  }

  static readonly ITEM_IDENTIFIER: {
    readonly SPACE: string
    readonly FLEXIBLE_SPACE: string
    readonly TOGGLE_SIDEBAR: string
    readonly SIDEBAR_TRACKING_SEPARATOR: string
    readonly PRINT: string
    readonly SHOW_COLORS: string
    readonly SHOW_FONTS: string
    readonly CLOUD_SHARING: string
  }
}

declare namespace AppKitToolbar {
  export interface Events {
    willAddItem: []
    didRemoveItem: []
  }
}

export = AppKitToolbar
