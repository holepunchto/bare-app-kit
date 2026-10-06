import { Wrapper } from 'bare-foundation-registry'
import AppKitButton = require('./button')
import AppKitMenu = require('./menu')

/** A pop up button, as an `NSPopUpButton`. */
interface AppKitPopUpButton<
  M extends Record<keyof M, unknown[]> = AppKitPopUpButton.Events
> extends AppKitButton<M> {
  pullsDown: boolean

  autoenablesItems: boolean

  preferredEdge: number

  readonly numberOfItems: number

  readonly indexOfSelectedItem: number

  readonly titleOfSelectedItem: string | null

  get menu(): AppKitMenu | null
  set menu(value: Wrapper)

  readonly itemTitles: string[]

  addItemWithTitle(title: string | null): this

  addItemsWithTitles(titles: string[]): this

  insertItemWithTitle(title: string | null, index: number): this

  removeItemWithTitle(title: string | null): this

  removeItemAtIndex(index: number): this

  removeAllItems(): this

  selectItemAtIndex(index: number): this

  selectItemWithTitle(title: string | null): this

  itemTitleAtIndex(index: number): string | null

  indexOfItemWithTitle(title: string | null): number

  synchronizeTitleAndSelectedItem(): this
}

declare class AppKitPopUpButton<M extends Record<keyof M, unknown[]> = AppKitPopUpButton.Events> {
  constructor(opts?: {
    x?: number
    y?: number
    width?: number
    height?: number
    pullsDown?: boolean
  })

  static readonly RECT_EDGE: {
    readonly MIN_X: number
    readonly MIN_Y: number
    readonly MAX_X: number
    readonly MAX_Y: number
  }
}

declare namespace AppKitPopUpButton {
  export interface Events {
    mouseDown: []
    change: []
  }
}

export = AppKitPopUpButton
