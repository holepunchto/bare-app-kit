import AppKitAppearance = require('./appearance')
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

  setActivationPolicy(policy: number): boolean

  activate(): this
}

declare class AppKitApplication {
  protected constructor()
}

declare const application: AppKitApplication

export = application
