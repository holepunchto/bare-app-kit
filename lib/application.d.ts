import { Wrapper } from 'bare-foundation-registry'
import AppKitAppearance = require('./appearance')
import AppKitEvent = require('./event')
import AppKitImage = require('./image')
import AppKitMenu = require('./menu')
import AppKitWindow = require('./window')

/** The running application, as the shared `NSApplication`. It already exists, so it is not constructed. */
interface AppKitApplication {
  shouldTerminateAfterLastWindowClosed: boolean

  mainMenu: AppKitMenu | null

  activationPolicy: number

  presentationOptions: number

  applicationIconImage: AppKitImage | null

  readonly running: boolean

  readonly active: boolean

  readonly hidden: boolean

  readonly mainWindow: AppKitWindow | null

  readonly keyWindow: AppKitWindow | null

  windowsMenu: AppKitMenu | null

  servicesMenu: AppKitMenu | null

  helpMenu: AppKitMenu | null

  readonly effectiveAppearance: AppKitAppearance | null

  appearance: AppKitAppearance | null

  hide(): this

  unhide(): this

  unhideAllApplications(): this

  terminate(): this

  arrangeInFront(): this

  requestUserAttention(type: number): number

  cancelUserAttentionRequest(request: number): this

  numberOfWindows(): number

  windowAt(index: number): AppKitWindow | null

  /** Add `event` to the event queue, at the front if `atStart`. */
  postEvent(event: Wrapper, atStart?: boolean): this

  /**
   * The next event matching `mask`, a combination of `MASK` flags, waiting until `untilDate` for
   * one. A `null` date does not wait, and with `dequeue` false the event is left in the queue.
   * `mode` is a run loop mode and defaults to the default mode.
   */
  nextEventMatchingMask(
    mask: number,
    untilDate?: Date | null,
    mode?: string | null,
    dequeue?: boolean
  ): AppKitEvent | null

  setActivationPolicy(policy: number): boolean

  activate(): this
}

declare class AppKitApplication {
  protected constructor()
}

declare const application: AppKitApplication

export = application
