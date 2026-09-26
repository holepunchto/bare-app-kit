import { Wrapper } from 'bare-foundation-registry'
import AppKitColor = require('./color')
import AppKitControl = require('./control')
import AppKitImage = require('./image')

/** An image view, as an `NSImageView`. */
interface AppKitImageView<
  M extends Record<keyof M, unknown[]> = AppKitImageView.Events
> extends AppKitControl<M> {
  get image(): AppKitImage | null
  set image(value: Wrapper)

  /** An `IMAGE_SCALING` constant. */
  imageScaling: number

  /** An `IMAGE_ALIGNMENT` constant. */
  imageAlignment: number

  /** An `IMAGE_FRAME_STYLE` constant. */
  imageFrameStyle: number

  editable: boolean

  animates: boolean

  get contentTintColor(): AppKitColor | null
  set contentTintColor(value: Wrapper)
}

declare class AppKitImageView<M extends Record<keyof M, unknown[]> = AppKitImageView.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly IMAGE_SCALING: {
    readonly PROPORTIONALLY_DOWN: number
    readonly AXES_INDEPENDENTLY: number
    readonly NONE: number
    readonly PROPORTIONALLY_UP_OR_DOWN: number
  }

  static readonly IMAGE_ALIGNMENT: {
    readonly CENTER: number
    readonly TOP: number
    readonly TOP_LEFT: number
    readonly TOP_RIGHT: number
    readonly LEFT: number
    readonly BOTTOM: number
    readonly BOTTOM_LEFT: number
    readonly BOTTOM_RIGHT: number
    readonly RIGHT: number
  }

  static readonly IMAGE_FRAME_STYLE: {
    readonly NONE: number
    readonly PHOTO: number
    readonly GRAY_BEZEL: number
    readonly GROOVE: number
    readonly BUTTON: number
  }
}

declare namespace AppKitImageView {
  export interface Events {
    change: []
    willDraw: []
  }
}

export = AppKitImageView
