import AppKitSplitView = require('./split-view')
import AppKitToolbarItem = require('./toolbar-item')

/** A tracking separator toolbar item, as an `NSTrackingSeparatorToolbarItem`. */
interface AppKitTrackingSeparatorToolbarItem extends AppKitToolbarItem<AppKitToolbarItem.Events> {}

declare class AppKitTrackingSeparatorToolbarItem {
  constructor(opts?: {
    identifier?: string
    splitView?: AppKitSplitView | null
    dividerIndex?: number
  })
}

export = AppKitTrackingSeparatorToolbarItem
