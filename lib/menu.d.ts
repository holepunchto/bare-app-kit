import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitFont = require('./font')
import AppKitMenuItem = require('./menu-item')

/** A menu, as an `NSMenu`. */
interface AppKitMenu<
  M extends Record<keyof M, unknown[]> = AppKitMenu.Events
> extends EventEmitter<M> {
  title: string | null

  autoenablesItems: boolean

  minimumWidth: number

  showsStateColumn: boolean

  allowsContextMenuPlugIns: boolean

  readonly size: { width: number; height: number }

  readonly highlightedItem: AppKitMenuItem | null

  readonly supermenu: AppKitMenu | null

  get font(): AppKitFont | null
  set font(value: Wrapper)

  readonly numberOfItems: number

  popUpContextMenu(view: Wrapper): this

  performActionForItemAtIndex(index: number): this

  cancelTracking(): this

  update(): this

  indexOfItemWithTitle(title: string | null): number

  indexOfItemWithTag(tag: number): number

  readonly items: AppKitMenuItem[]

  itemAtIndex(index: number): AppKitMenuItem | null

  indexOfItem(item: AppKitMenuItem): number

  addItem(item: Wrapper): this

  insertItem(item: Wrapper, index: number): this

  removeItem(item: Wrapper): this

  removeItemAtIndex(index: number): this

  removeAllItems(): this

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitMenu<M extends Record<keyof M, unknown[]> = AppKitMenu.Events> {
  constructor(opts?: { title?: string })
}

declare namespace AppKitMenu {
  export interface Events {
    willOpen: []
    didClose: []
  }
}

export = AppKitMenu
