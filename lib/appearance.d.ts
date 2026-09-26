import { tag, handle, Handle } from 'bare-foundation-registry'

/** An appearance, as an `NSAppearance`. */
interface AppKitAppearance {
  readonly name: string | null

  bestMatchFromAppearancesWithNames(names: string[]): string | null

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitAppearance {
  protected constructor()

  static named(name: string | null): AppKitAppearance | null

  static current(): AppKitAppearance | null
}

export = AppKitAppearance
