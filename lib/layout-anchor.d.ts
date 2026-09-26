import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import AppKitLayoutConstraint = require('./layout-constraint')

/** A layout anchor, as an `NSLayoutAnchor`. */
interface AppKitLayoutAnchor {
  equalTo(anchor: Wrapper, constant: number): AppKitLayoutConstraint | null

  greaterThanOrEqualTo(anchor: Wrapper, constant: number): AppKitLayoutConstraint | null

  lessThanOrEqualTo(anchor: Wrapper, constant: number): AppKitLayoutConstraint | null

  equalToConstant(constant: number): AppKitLayoutConstraint | null

  greaterThanOrEqualToConstant(constant: number): AppKitLayoutConstraint | null

  lessThanOrEqualToConstant(constant: number): AppKitLayoutConstraint | null

  equalToMultiple(
    anchor: Wrapper,
    multiplier: number,
    constant: number
  ): AppKitLayoutConstraint | null

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitLayoutAnchor {
  protected constructor()
}

export = AppKitLayoutAnchor
