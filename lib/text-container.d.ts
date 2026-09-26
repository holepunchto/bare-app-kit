import { tag, handle, Handle } from 'bare-foundation-registry'

/** A text container, as an `NSTextContainer`. */
interface AppKitTextContainer {
  lineFragmentPadding: number

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitTextContainer {
  protected constructor()
}

export = AppKitTextContainer
