import AppKitTableColumn = require('./table-column')
import AppKitTableView = require('./table-view')
import AppKitView = require('./view')

/** A table of rows that can expand into children, as an `NSOutlineView`. Items are not stored: `numberOfChildren`, `child` and `isExpandable` are asked about each item as it is shown, and `makeView` for the view of each cell. An item can be any value, and `null` stands for the root. */
interface AppKitOutlineView<
  M extends Record<keyof M, unknown[]> = AppKitOutlineView.Events
> extends AppKitTableView<M> {
  /** Called for the number of children of `item`, which is `null` for the root. */
  numberOfChildren: ((item: unknown) => number) | null

  /** Called for the child at `index` of `item`, which is `null` for the root. Return any value to stand for it. */
  child: ((index: number, item: unknown) => unknown) | null

  /** Called for whether `item` can be expanded. */
  isExpandable: ((item: unknown) => boolean) | null

  /** Called for the view of each cell as it is shown. Its answer is kept until `reloadData()`. */
  makeView: ((identifier: string, item: unknown) => AppKitView | null) | null

  reloadData(): this

  readonly numberOfRows: number

  indentationPerLevel: number

  indentationMarkerFollowsCell: boolean

  autoresizesOutlineColumn: boolean

  autosaveExpandedItems: boolean

  stronglyReferencesItems: boolean

  outlineTableColumn: AppKitTableColumn | null

  expandItem(item: unknown, children?: boolean): this

  collapseItem(item: unknown, children?: boolean): this

  isItemExpanded(item: unknown): boolean

  reloadItem(item: unknown, children?: boolean): this

  levelForItem(item: unknown): number

  rowForItem(item: unknown): number

  itemAtRow(row: number): unknown

  parentForItem(item: unknown): unknown
}

declare class AppKitOutlineView<M extends Record<keyof M, unknown[]> = AppKitOutlineView.Events> {
  constructor(opts?: {
    x?: number
    y?: number
    width?: number
    height?: number
    numberOfChildren?: ((item: unknown) => number) | null
    child?: ((index: number, item: unknown) => unknown) | null
    isExpandable?: ((item: unknown) => boolean) | null
    makeView?: ((identifier: string, item: unknown) => AppKitView | null) | null
  })
}

declare namespace AppKitOutlineView {
  export interface Events {
    selectionDidChange: []
    itemDidExpand: []
    itemDidCollapse: []
  }
}

export = AppKitOutlineView
