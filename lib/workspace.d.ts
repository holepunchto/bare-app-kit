import AppKitImage = require('./image')

/** Opens files, URLs and applications, as the shared `NSWorkspace`. It already exists, so it is not constructed. */
interface AppKitWorkspace {
  openURL(url: string | null): boolean

  openFile(path: string): boolean

  selectFile(path: string): this

  iconForFile(path: string | null): AppKitImage | null

  urlForApplication(identifier: string | null): string | null

  iconForContentType(identifier: string | null): AppKitImage | null

  isFilePackage(path: string | null): boolean

  openApplication(path: string): this

  hideOtherApplications(): this

  urlForApplicationToOpenFile(path: string): string | null
}

declare class AppKitWorkspace {
  protected constructor()
}

declare const workspace: AppKitWorkspace

export = workspace
