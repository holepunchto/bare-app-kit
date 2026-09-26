import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitImage = require('./image')
import AppKitView = require('./view')

/** A tab view item, as an `NSTabViewItem`. */
interface AppKitTabViewItem extends EventEmitter<{}> {
  label: string | null

  toolTip: string | null

  get view(): AppKitView | null
  set view(value: Wrapper)

  get image(): AppKitImage | null
  set image(value: Wrapper)

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitTabViewItem {
  constructor()
}

export = AppKitTabViewItem
