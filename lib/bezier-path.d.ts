import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'

/** A bezier path, as an `NSBezierPath`. */
interface AppKitBezierPath extends EventEmitter<{}> {
  lineWidth: number

  /** A `LINE_CAP_STYLE` constant. */
  lineCapStyle: number

  /** A `LINE_JOIN_STYLE` constant. */
  lineJoinStyle: number

  /** A `WINDING_RULE` constant. */
  windingRule: number

  miterLimit: number

  flatness: number

  readonly empty: boolean

  readonly elementCount: number

  readonly bounds: { x: number; y: number; width: number; height: number }

  readonly controlPointBounds: { x: number; y: number; width: number; height: number }

  readonly currentPoint: { x: number; y: number }

  moveTo(x: number, y: number): this

  lineTo(x: number, y: number): this

  curveTo(x: number, y: number, x1: number, y1: number, x2: number, y2: number): this

  closePath(): this

  removeAllPoints(): this

  appendRect(x: number, y: number, width: number, height: number): this

  appendOval(x: number, y: number, width: number, height: number): this

  append(other: Wrapper): this

  stroke(): this

  fill(): this

  addClip(): this

  setClip(): this

  containsPoint(x: number, y: number): boolean

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitBezierPath {
  constructor()

  static withRect(x: number, y: number, width: number, height: number): AppKitBezierPath | null

  static withOval(x: number, y: number, width: number, height: number): AppKitBezierPath | null

  static withRoundedRect(
    x: number,
    y: number,
    width: number,
    height: number,
    rx: number,
    ry: number
  ): AppKitBezierPath | null

  static readonly LINE_CAP_STYLE: {
    readonly BUTT: number
    readonly ROUND: number
    readonly SQUARE: number
  }

  static readonly LINE_JOIN_STYLE: {
    readonly MITER: number
    readonly ROUND: number
    readonly BEVEL: number
  }

  static readonly WINDING_RULE: {
    readonly NON_ZERO: number
    readonly EVEN_ODD: number
  }
}

export = AppKitBezierPath
