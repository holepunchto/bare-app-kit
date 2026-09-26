import { tag, handle, Handle } from 'bare-foundation-registry'

/** A screen, as an `NSScreen`. */
interface AppKitScreen {
  readonly frame: { x: number; y: number; width: number; height: number }

  readonly visibleFrame: { x: number; y: number; width: number; height: number }

  readonly backingScaleFactor: number

  readonly localizedName: string | null

  readonly safeAreaInsets: { top: number; left: number; bottom: number; right: number }

  readonly maximumFramesPerSecond: number

  readonly minimumRefreshInterval: number

  readonly maximumRefreshInterval: number

  readonly displayUpdateGranularity: number

  readonly auxiliaryTopLeftArea: { x: number; y: number; width: number; height: number }

  readonly auxiliaryTopRightArea: { x: number; y: number; width: number; height: number }

  readonly maximumExtendedDynamicRangeColorComponentValue: number

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitScreen {
  protected constructor()

  static main(): AppKitScreen | null

  static deepest(): AppKitScreen | null

  static count(): number

  static at(index: number): AppKitScreen | null
}

export = AppKitScreen
