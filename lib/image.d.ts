import { tag, handle, Handle } from 'bare-foundation-registry'

/** An image, as an `NSImage`. */
interface AppKitImage {
  get size(): { width: number; height: number }
  set size(value: Partial<{ width: number; height: number }>)

  template: boolean

  readonly name: string | null

  readonly valid: boolean

  cacheMode: number

  resizingMode: number

  get alignmentRect(): { x: number; y: number; width: number; height: number }
  set alignmentRect(value: Partial<{ x: number; y: number; width: number; height: number }>)

  matchesOnMultipleResolution: boolean

  prefersColorMatch: boolean

  lockFocus(): this

  unlockFocus(): this

  drawInRect(x: number, y: number, width: number, height: number): this

  drawAtPoint(x: number, y: number): this

  tiffRepresentation(): ArrayBuffer | null

  recommendedLayerContentsScale(scale: number): number

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitImage {
  protected constructor()

  static withContentsOfFile(path: string | null): AppKitImage | null

  static named(name: string | null): AppKitImage | null

  static withSystemSymbolName(name: string | null, description?: string | null): AppKitImage | null

  static withSize(width: number, height: number): AppKitImage | null
}

export = AppKitImage
