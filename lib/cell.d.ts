import { tag, handle, Handle } from 'bare-foundation-registry'
import AppKitView = require('./view')

/** A cell, as an `NSCell`. */
interface AppKitCell {
  drawingRectForBounds(bounds: Partial<AppKitView.Rect>): AppKitView.Rect

  imageRectForBounds(bounds: Partial<AppKitView.Rect>): AppKitView.Rect

  titleRectForBounds(bounds: Partial<AppKitView.Rect>): AppKitView.Rect

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitCell {
  protected constructor()
}

export = AppKitCell
