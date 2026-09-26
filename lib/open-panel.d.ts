import AppKitSavePanel = require('./save-panel')

/** An open panel, as an `NSOpenPanel`. */
interface AppKitOpenPanel extends AppKitSavePanel<{}> {
  readonly urls: string[]

  canChooseFiles: boolean

  canChooseDirectories: boolean

  allowsMultipleSelection: boolean

  resolvesAliases: boolean
}

declare class AppKitOpenPanel {
  constructor()
}

export = AppKitOpenPanel
