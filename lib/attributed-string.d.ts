import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitView = require('./view')

/** An attributed string, as an `NSMutableAttributedString`. */
interface AppKitAttributedString extends EventEmitter<{}> {
  readonly string: string | null

  readonly length: number

  attributesAt(location: number): AppKitAttributedString.Attributes

  setAttributes(
    attributes: AppKitAttributedString.Attributes,
    location: number,
    length: number
  ): this

  addAttributes(
    attributes: AppKitAttributedString.Attributes,
    location: number,
    length: number
  ): this

  removeAttributes(location: number, length: number): this

  append(other: Wrapper): this

  appendString(string: string, attributes?: AppKitAttributedString.Attributes): this

  replaceCharacters(location: number, length: number, string: string | null): this

  substring(location: number, length: number): AppKitAttributedString | null

  boundingRect(width: number, height: number, options: number): AppKitView.Rect

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitAttributedString {
  constructor(opts?: { string?: string; attributes?: AppKitAttributedString.Attributes })

  static measure(
    string: string,
    attributes: AppKitAttributedString.Attributes,
    width: number,
    height: number,
    options?: number
  ): AppKitView.Size

  static readonly UNDERLINE_STYLE: {
    readonly NONE: number
    readonly SINGLE: number
    readonly THICK: number
    readonly DOUBLE: number
    readonly PATTERN_DOT: number
    readonly PATTERN_DASH: number
    readonly BY_WORD: number
  }

  static readonly STRING_DRAWING_OPTIONS: {
    readonly USES_LINE_FRAGMENT_ORIGIN: number
    readonly USES_FONT_LEADING: number
    readonly USES_DEVICE_METRICS: number
    readonly TRUNCATES_LAST_VISIBLE_LINE: number
  }
}

declare namespace AppKitAttributedString {
  export interface Attributes {
    font?: import('./font') | null
    foregroundColor?: import('./color') | null
    backgroundColor?: import('./color') | null
    underlineColor?: import('./color') | null
    strikethroughColor?: import('./color') | null
    paragraphStyle?: import('./paragraph-style') | null
    [attribute: string]: unknown
  }
}

export = AppKitAttributedString
