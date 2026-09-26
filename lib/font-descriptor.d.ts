import { tag, handle, Handle } from 'bare-foundation-registry'

/** A font descriptor, as an `NSFontDescriptor`. */
interface AppKitFontDescriptor {
  /** `SYMBOLIC_TRAITS` flags combined with `|`. */
  readonly symbolicTraits: number

  withSymbolicTraits(traits: number): AppKitFontDescriptor | null

  withFamily(family: string | null): AppKitFontDescriptor | null

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitFontDescriptor {
  protected constructor()

  static readonly SYMBOLIC_TRAITS: {
    readonly ITALIC: number
    readonly BOLD: number
    readonly EXPANDED: number
    readonly CONDENSED: number
    readonly MONO_SPACE: number
  }
}

export = AppKitFontDescriptor
