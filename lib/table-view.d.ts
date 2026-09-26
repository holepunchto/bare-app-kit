import { Wrapper } from 'bare-foundation-registry'
import AppKitColor = require('./color')
import AppKitTableColumn = require('./table-column')
import AppKitView = require('./view')

/** A table, as an `NSTableView`. Rows are not stored: set `numberOfRows`, and `makeView` is asked for the view of each cell as it is shown. Call `reloadData()` after the data changes. */
interface AppKitTableView<
  M extends Record<keyof M, unknown[]> = AppKitTableView.Events
> extends AppKitView<M> {
  /** Called for the view of each cell as it is shown. Its answer is kept until `reloadData()`. */
  makeView: ((identifier: string, row: number) => AppKitView | null) | null

  numberOfRows: number

  readonly columns: AppKitTableColumn[]

  addTableColumn(column: Wrapper): this

  removeTableColumn(column: Wrapper): this

  reloadData(): this

  rowHeight: number

  get intercellSpacing(): AppKitView.Size
  set intercellSpacing(value: Partial<{ width: number; height: number }>)

  usesAlternatingRowBackgroundColors: boolean

  usesAutomaticRowHeights: boolean

  allowsMultipleSelection: boolean

  allowsEmptySelection: boolean

  allowsColumnReordering: boolean

  allowsColumnResizing: boolean

  allowsColumnSelection: boolean

  /** A `STYLE` constant. */
  style: number

  gridStyleMask: number

  /** A `STYLE` constant. */
  rowSizeStyle: number

  /** A `STYLE` constant. */
  columnAutoresizingStyle: number

  backgroundColor: AppKitColor | null

  gridColor: AppKitColor | null

  headerView: AppKitView | null

  readonly numberOfColumns: number

  readonly selectedRow: number

  readonly selectedColumn: number

  readonly clickedRow: number

  readonly clickedColumn: number

  readonly numberOfSelectedRows: number

  moveColumn(column: number, index: number): this

  selectRow(row: number, extend: boolean): this

  deselectRow(row: number): this

  deselectAll(): this

  selectAll(): this

  isRowSelected(row: number): boolean

  scrollRowToVisible(row: number): this

  reloadRow(row: number): this

  sizeToFit(): this

  sizeLastColumnToFit(): this
}

declare class AppKitTableView<M extends Record<keyof M, unknown[]> = AppKitTableView.Events> {
  constructor(opts?: {
    x?: number
    y?: number
    width?: number
    height?: number
    makeView?: ((identifier: string, row: number) => AppKitView | null) | null
    numberOfRows?: number
  })

  static readonly STYLE: {
    readonly AUTOMATIC: number
    readonly FULL_WIDTH: number
    readonly INSET: number
    readonly SOURCE_LIST: number
    readonly PLAIN: number
  }

  static readonly GRID_LINE_STYLE: {
    readonly NONE: number
    readonly SOLID_VERTICAL: number
    readonly SOLID_HORIZONTAL: number
    readonly DASHED_HORIZONTAL: number
  }

  static readonly ROW_SIZE_STYLE: {
    readonly DEFAULT: number
    readonly CUSTOM: number
    readonly SMALL: number
    readonly MEDIUM: number
    readonly LARGE: number
  }

  static readonly COLUMN_AUTORESIZING_STYLE: {
    readonly NONE: number
    readonly UNIFORM: number
    readonly SEQUENTIAL: number
    readonly REVERSE_SEQUENTIAL: number
    readonly LAST_COLUMN_ONLY: number
    readonly FIRST_COLUMN_ONLY: number
  }
}

declare namespace AppKitTableView {
  export interface Events {
    selectionDidChange: []
    click: []
    doubleClick: []
  }
}

export = AppKitTableView
