import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitColor = require('./color')

/** A gradient, as an `NSGradient`. */
interface AppKitGradient extends EventEmitter<{}> {
  readonly numberOfColorStops: number

  drawInRect(x: number, y: number, width: number, height: number, angle: number): this

  drawInPath(path: Wrapper, angle: number): this

  interpolatedColorAt(location: number): AppKitColor | null

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitGradient {
  constructor(opts?: { colors?: AppKitColor[] })
}

export = AppKitGradient
