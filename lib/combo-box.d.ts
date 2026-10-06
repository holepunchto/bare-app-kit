import AppKitTextField = require('./text-field')
import AppKitView = require('./view')

/** A combo box, as an `NSComboBox`. */
interface AppKitComboBox<
  M extends Record<keyof M, unknown[]> = AppKitComboBox.Events
> extends AppKitTextField<M> {
  hasVerticalScroller: boolean

  numberOfVisibleItems: number

  usesDataSource: boolean

  completes: boolean

  buttonBordered: boolean

  itemHeight: number

  get intercellSpacing(): AppKitView.Size
  set intercellSpacing(value: Partial<{ width: number; height: number }>)

  readonly numberOfItems: number

  readonly indexOfSelectedItem: number

  readonly objectValueOfSelectedItem: string | null

  readonly objectValues: string[]

  addItemWithObjectValue(value: string | null): this

  insertItemWithObjectValue(value: string | null, index: number): this

  removeItemWithObjectValue(value: string | null): this

  removeItemAtIndex(index: number): this

  removeAllItems(): this

  selectItemAtIndex(index: number): this

  deselectItemAtIndex(index: number): this

  selectItemWithObjectValue(value: string | null): this

  itemObjectValueAtIndex(index: number): string | null

  indexOfItemWithObjectValue(value: string | null): number

  reloadData(): this

  noteNumberOfItemsChanged(): this

  scrollItemAtIndexToTop(index: number): this

  scrollItemAtIndexToVisible(index: number): this
}

declare class AppKitComboBox<M extends Record<keyof M, unknown[]> = AppKitComboBox.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })
}

declare namespace AppKitComboBox {
  export interface Events {
    change: []
    didChange: []
    didBeginEditing: []
    didEndEditing: []
    selectionDidChange: []
    willPopUp: []
    willDismiss: []
  }
}

export = AppKitComboBox
