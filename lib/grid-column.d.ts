import { tag, handle, Handle } from 'bare-foundation-registry'
import AppKitGridCell = require('./grid-cell')

/** A grid column, as an `NSGridColumn`. */
interface AppKitGridColumn {
  readonly numberOfCells: number

  width: number

  leadingPadding: number

  trailingPadding: number

  xPlacement: number

  hidden: boolean

  cellAtIndex(index: number): AppKitGridCell | null

  mergeCells(index: number, count: number): this

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitGridColumn {
  protected constructor()
}

export = AppKitGridColumn
