import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import AppKitView = require('./view')

/** A grid cell, as an `NSGridCell`. */
interface AppKitGridCell {
  get contentView(): AppKitView | null
  set contentView(value: Wrapper)

  xPlacement: number

  yPlacement: number

  rowAlignment: number

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitGridCell {
  protected constructor()
}

export = AppKitGridCell
