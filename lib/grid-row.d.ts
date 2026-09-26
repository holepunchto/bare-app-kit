import { tag, handle, Handle } from 'bare-foundation-registry'
import AppKitGridCell = require('./grid-cell')

/** A grid row, as an `NSGridRow`. */
interface AppKitGridRow {
  readonly numberOfCells: number

  height: number

  topPadding: number

  bottomPadding: number

  yPlacement: number

  rowAlignment: number

  hidden: boolean

  cellAtIndex(index: number): AppKitGridCell | null

  mergeCells(index: number, count: number): this

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitGridRow {
  protected constructor()
}

export = AppKitGridRow
