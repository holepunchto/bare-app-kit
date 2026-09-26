import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import AppKitFontDescriptor = require('./font-descriptor')

/** A font, as an `NSFont`. */
interface AppKitFont {
  readonly fontDescriptor: AppKitFontDescriptor | null

  readonly fontName: string | null

  readonly familyName: string | null

  readonly displayName: string | null

  readonly pointSize: number

  readonly ascender: number

  readonly descender: number

  readonly capHeight: number

  readonly xHeight: number

  readonly leading: number

  readonly italicAngle: number

  readonly underlinePosition: number

  readonly underlineThickness: number

  readonly numberOfGlyphs: number

  readonly fixedPitch: boolean

  readonly boundingRectForFont: { x: number; y: number; width: number; height: number }

  readonly maximumAdvancement: { width: number; height: number }

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitFont {
  protected constructor()

  /** `weight` is a `WEIGHT` constant. */
  static systemFont(size: number, weight?: number): AppKitFont | null

  static boldSystemFont(size: number): AppKitFont | null

  /** `weight` is a `WEIGHT` constant. */
  static monospacedSystemFont(size: number, weight?: number): AppKitFont | null

  /** `weight` is a `WEIGHT` constant. */
  static monospacedDigitSystemFont(size: number, weight?: number): AppKitFont | null

  static withName(name: string | null, size: number): AppKitFont | null

  static withDescriptor(descriptor: Wrapper, size: number): AppKitFont | null

  static readonly WEIGHT: {
    readonly ULTRA_LIGHT: number
    readonly THIN: number
    readonly LIGHT: number
    readonly REGULAR: number
    readonly MEDIUM: number
    readonly SEMIBOLD: number
    readonly BOLD: number
    readonly HEAVY: number
    readonly BLACK: number
  }
}

export = AppKitFont
