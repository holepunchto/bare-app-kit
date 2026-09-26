import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitAttributedString = require('./attributed-string')
import AppKitImage = require('./image')

/** A path control item, as an `NSPathControlItem`. */
interface AppKitPathControlItem extends EventEmitter<{}> {
  title: string | null

  get image(): AppKitImage | null
  set image(value: Wrapper)

  readonly url: string | null

  get attributedTitle(): AppKitAttributedString | null
  set attributedTitle(value: Wrapper)

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitPathControlItem {
  constructor()
}

export = AppKitPathControlItem
