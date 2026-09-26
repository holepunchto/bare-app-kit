import { tag, handle, Handle } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'

/** A paragraph style, as an `NSMutableParagraphStyle`. */
interface AppKitParagraphStyle extends EventEmitter<{}> {
  alignment: number

  lineSpacing: number

  paragraphSpacing: number

  paragraphSpacingBefore: number

  firstLineHeadIndent: number

  headIndent: number

  tailIndent: number

  lineHeightMultiple: number

  minimumLineHeight: number

  maximumLineHeight: number

  defaultTabInterval: number

  hyphenationFactor: number

  /** A `LINE_BREAK_MODE` constant. */
  lineBreakMode: number

  baseWritingDirection: number

  allowsDefaultTighteningForTruncation: boolean

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitParagraphStyle {
  constructor()

  static readonly LINE_BREAK_MODE: {
    readonly WORD_WRAPPING: number
    readonly CHAR_WRAPPING: number
    readonly CLIPPING: number
    readonly TRUNCATING_HEAD: number
    readonly TRUNCATING_TAIL: number
    readonly TRUNCATING_MIDDLE: number
  }
}

export = AppKitParagraphStyle
