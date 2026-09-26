import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import AppKitAttributedString = require('./attributed-string')
import AppKitView = require('./view')

/** Measures text with a text storage, layout manager and text container that are kept between measurements, which makes measuring the same text repeatedly cheap. AppKit has no such class. */
interface AppKitTextMeasurer {
  lineFragmentPadding: number

  maximumNumberOfLines: number

  measure(
    string: string,
    attributes?: AppKitAttributedString.Attributes,
    width?: number,
    height?: number
  ): { width: number; height: number; lines: number }

  measureAttributed(text: Wrapper, width?: number, height?: number): AppKitView.Size

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitTextMeasurer {
  protected constructor()
}

export = AppKitTextMeasurer
