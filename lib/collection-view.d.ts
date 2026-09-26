import AppKitCollectionViewFlowLayout = require('./collection-view-flow-layout')
import AppKitCollectionViewItem = require('./collection-view-item')
import AppKitView = require('./view')

/** A grid of items, as an `NSCollectionView`. Items are not stored: `numberOfItems` is asked for the count of each section, and `makeItem` for each item as it is shown. */
interface AppKitCollectionView<
  M extends Record<keyof M, unknown[]> = AppKitCollectionView.Events
> extends AppKitView<M> {
  /** Called for the number of items in `section`. */
  numberOfItems: ((section: number) => number) | null

  /** Called for the item at `item` in `section` as it is shown. Its answer is kept until `reloadData()`. */
  makeItem: ((section: number, item: number) => AppKitCollectionViewItem | null) | null

  numberOfSections: number

  reloadData(): this

  collectionViewLayout: AppKitCollectionViewFlowLayout | null

  backgroundView: AppKitView | null

  selectable: boolean

  allowsEmptySelection: boolean

  allowsMultipleSelection: boolean

  backgroundViewScrollsWithContent: boolean

  readonly selectionIndexPaths: AppKitView.IndexPath[]

  deselectAll(): this

  selectItem(section: number, item: number): this

  scrollToItem(section: number, item: number, position: number): this

  itemAt(section: number, item: number): AppKitCollectionViewItem | null

  numberOfItemsInSection(section: number): number
}

declare class AppKitCollectionView<
  M extends Record<keyof M, unknown[]> = AppKitCollectionView.Events
> {
  constructor(opts?: {
    x?: number
    y?: number
    width?: number
    height?: number
    numberOfSections?: number
    numberOfItems?: ((section: number) => number) | null
    makeItem?: ((section: number, item: number) => AppKitCollectionViewItem | null) | null
  })

  static readonly SCROLL_POSITION: {
    readonly NONE: number
    readonly TOP: number
    readonly CENTERED_VERTICALLY: number
    readonly BOTTOM: number
    readonly LEFT: number
    readonly CENTERED_HORIZONTALLY: number
    readonly RIGHT: number
  }
}

declare namespace AppKitCollectionView {
  export interface Events {
    didSelectItems: []
    didDeselectItems: []
  }
}

export = AppKitCollectionView
