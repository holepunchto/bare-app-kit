import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitButton = require('./button')
import AppKitMenu = require('./menu')

/** A status item, as an `NSStatusItem`. */
interface AppKitStatusItem extends EventEmitter<{}> {
  /** A `LENGTH` constant. */
  length: number

  visible: boolean

  get menu(): AppKitMenu | null
  set menu(value: Wrapper)

  readonly button: AppKitButton | null

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitStatusItem {
  constructor(opts?: { length?: number })

  static readonly LENGTH: {
    readonly VARIABLE: number
    readonly SQUARE: number
  }
}

export = AppKitStatusItem
