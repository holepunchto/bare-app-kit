import { tag, handle, Handle } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'

/** A table column, as an `NSTableColumn`. */
interface AppKitTableColumn extends EventEmitter<{}> {
  readonly identifier: string | null

  title: string | null

  width: number

  minWidth: number

  maxWidth: number

  resizingMask: number

  editable: boolean

  hidden: boolean

  sizeToFit(): this

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitTableColumn {
  constructor(opts?: { identifier?: string })

  static readonly RESIZING_OPTIONS: {
    readonly NONE: number
    readonly AUTORESIZING: number
    readonly USER_RESIZING: number
  }
}

export = AppKitTableColumn
