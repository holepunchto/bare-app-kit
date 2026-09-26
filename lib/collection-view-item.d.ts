import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitImageView = require('./image-view')
import AppKitTextField = require('./text-field')
import AppKitView = require('./view')

/** A collection view item, as an `NSCollectionViewItem`. */
interface AppKitCollectionViewItem extends EventEmitter<{}> {
  get view(): AppKitView | null
  set view(value: Wrapper)

  selected: boolean

  /** A `HIGHLIGHT_STATE` constant. */
  highlightState: number

  get imageView(): AppKitImageView | null
  set imageView(value: Wrapper)

  get textField(): AppKitTextField | null
  set textField(value: Wrapper)

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitCollectionViewItem {
  constructor()

  static readonly HIGHLIGHT_STATE: {
    readonly NONE: number
    readonly FOR_SELECTION: number
    readonly FOR_DESELECTION: number
    readonly AS_DROP_TARGET: number
  }
}

export = AppKitCollectionViewItem
