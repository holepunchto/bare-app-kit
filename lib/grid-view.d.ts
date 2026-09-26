import AppKitGridCell = require('./grid-cell')
import AppKitGridColumn = require('./grid-column')
import AppKitGridRow = require('./grid-row')
import AppKitView = require('./view')

/** A grid view, as an `NSGridView`. */
interface AppKitGridView extends AppKitView<AppKitView.Events> {
  readonly numberOfRows: number

  readonly numberOfColumns: number

  rowSpacing: number

  columnSpacing: number

  xPlacement: number

  yPlacement: number

  /** A `GRID_ROW_ALIGNMENT` constant. */
  rowAlignment: number

  addRow(views: AppKitView[]): AppKitGridRow | null

  insertRow(index: number, views: AppKitView[]): AppKitGridRow | null

  removeRow(index: number): this

  addColumn(views: AppKitView[]): AppKitGridColumn | null

  insertColumn(index: number, views: AppKitView[]): AppKitGridColumn | null

  removeColumn(index: number): this

  rowAtIndex(index: number): AppKitGridRow | null

  columnAtIndex(index: number): AppKitGridColumn | null

  cellAt(column: number, row: number): AppKitGridCell | null

  mergeCells(column: number, columns: number, row: number, rows: number): this
}

declare class AppKitGridView {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly GRID_CELL_PLACEMENT: {
    readonly INHERITED: number
    readonly NONE: number
    readonly LEADING: number
    readonly TOP: number
    readonly TRAILING: number
    readonly BOTTOM: number
    readonly CENTER: number
    readonly FILL: number
  }

  static readonly GRID_ROW_ALIGNMENT: {
    readonly INHERITED: number
    readonly NONE: number
    readonly FIRST_BASELINE: number
    readonly LAST_BASELINE: number
  }
}

export = AppKitGridView
