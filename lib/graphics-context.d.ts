import { tag, handle, Handle } from 'bare-foundation-registry'

/** A graphics context, as an `NSGraphicsContext`. */
interface AppKitGraphicsContext {
  shouldAntialias: boolean

  /** An `IMAGE_INTERPOLATION` constant. */
  imageInterpolation: number

  /** A `COMPOSITING_OPERATION` constant. */
  compositingOperation: number

  readonly flipped: boolean

  flush(): this

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitGraphicsContext {
  protected constructor()

  static current(): AppKitGraphicsContext | null

  static save(): void

  static restore(): void

  static readonly COMPOSITING_OPERATION: {
    readonly CLEAR: number
    readonly COPY: number
    readonly SOURCE_OVER: number
    readonly MULTIPLY: number
    readonly SCREEN: number
    readonly OVERLAY: number
    readonly DARKEN: number
    readonly LIGHTEN: number
  }

  static readonly IMAGE_INTERPOLATION: {
    readonly DEFAULT: number
    readonly NONE: number
    readonly LOW: number
    readonly MEDIUM: number
    readonly HIGH: number
  }
}

export = AppKitGraphicsContext
