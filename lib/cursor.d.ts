import { tag, handle, Handle } from 'bare-foundation-registry'
import AppKitImage = require('./image')
import AppKitView = require('./view')

/** A cursor, as an `NSCursor`. */
interface AppKitCursor {
  readonly image: AppKitImage | null

  readonly hotSpot: AppKitView.Point

  set(): this

  push(): this

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitCursor {
  protected constructor()

  static readonly arrow: AppKitCursor | null

  static readonly ibeam: AppKitCursor | null

  static readonly ibeamVertical: AppKitCursor | null

  static readonly crosshair: AppKitCursor | null

  static readonly pointingHand: AppKitCursor | null

  static readonly closedHand: AppKitCursor | null

  static readonly openHand: AppKitCursor | null

  static readonly resizeLeft: AppKitCursor | null

  static readonly resizeRight: AppKitCursor | null

  static readonly resizeLeftRight: AppKitCursor | null

  static readonly resizeUp: AppKitCursor | null

  static readonly resizeDown: AppKitCursor | null

  static readonly resizeUpDown: AppKitCursor | null

  static readonly disappearingItem: AppKitCursor | null

  static readonly operationNotAllowed: AppKitCursor | null

  static readonly dragLink: AppKitCursor | null

  static readonly dragCopy: AppKitCursor | null

  static readonly contextualMenu: AppKitCursor | null

  static readonly current: AppKitCursor | null

  static system(id: number): AppKitCursor | null

  static hide(): void

  static unhide(): void

  static pop(): void
}

export = AppKitCursor
