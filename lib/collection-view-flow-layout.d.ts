import { tag, handle, Handle } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'

/** A collection view flow layout, as an `NSCollectionViewFlowLayout`. */
interface AppKitCollectionViewFlowLayout extends EventEmitter<{}> {
  get itemSize(): { width: number; height: number }
  set itemSize(value: Partial<{ width: number; height: number }>)

  get estimatedItemSize(): { width: number; height: number }
  set estimatedItemSize(value: Partial<{ width: number; height: number }>)

  minimumLineSpacing: number

  minimumInteritemSpacing: number

  get sectionInset(): { top: number; left: number; bottom: number; right: number }
  set sectionInset(value: Partial<{ top: number; left: number; bottom: number; right: number }>)

  /** A `SCROLL_DIRECTION` constant. */
  scrollDirection: number

  get headerReferenceSize(): { width: number; height: number }
  set headerReferenceSize(value: Partial<{ width: number; height: number }>)

  get footerReferenceSize(): { width: number; height: number }
  set footerReferenceSize(value: Partial<{ width: number; height: number }>)

  sectionHeadersPinToVisibleBounds: boolean

  sectionFootersPinToVisibleBounds: boolean

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitCollectionViewFlowLayout {
  constructor()

  static readonly SCROLL_DIRECTION: {
    readonly VERTICAL: number
    readonly HORIZONTAL: number
  }
}

export = AppKitCollectionViewFlowLayout
