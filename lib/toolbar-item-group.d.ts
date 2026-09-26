import AppKitToolbarItem = require('./toolbar-item')

/** A toolbar item group, as an `NSToolbarItemGroup`. */
interface AppKitToolbarItemGroup extends AppKitToolbarItem<AppKitToolbarItem.Events> {
  /** A `SELECTION_MODE` constant. */
  selectionMode: number

  /** A `CONTROL_REPRESENTATION` constant. */
  controlRepresentation: number

  selectedIndex: number

  readonly subitems: AppKitToolbarItem[]

  setSubitems(items: AppKitToolbarItem[]): this
}

declare class AppKitToolbarItemGroup {
  constructor(opts?: { identifier?: string })

  static readonly SELECTION_MODE: {
    readonly SELECT_ONE: string
    readonly SELECT_ANY: string
    readonly MOMENTARY: string
  }

  static readonly CONTROL_REPRESENTATION: {
    readonly AUTOMATIC: string
    readonly EXPANDED: string
    readonly COLLAPSED: string
  }
}

export = AppKitToolbarItemGroup
