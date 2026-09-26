import AppKitView = require('./view')

/** A table header view, as an `NSTableHeaderView`. */
interface AppKitTableHeaderView extends AppKitView<AppKitView.Events> {
  readonly draggedColumn: number

  readonly resizedColumn: number

  readonly draggedDistance: number

  columnAtPoint(x: number, y: number): number

  headerRectOfColumn(column: number): AppKitView.Rect
}

declare class AppKitTableHeaderView {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })
}

export = AppKitTableHeaderView
