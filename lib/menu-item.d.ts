import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitAttributedString = require('./attributed-string')
import AppKitImage = require('./image')
import AppKitMenu = require('./menu')

/** A menu item, as an `NSMenuItem`. */
interface AppKitMenuItem<
  M extends Record<keyof M, unknown[]> = AppKitMenuItem.Events
> extends EventEmitter<M> {
  title: string | null

  enabled: boolean

  hidden: boolean

  state: number

  tag: number

  toolTip: string | null

  indentationLevel: number

  keyEquivalent: string | null

  keyEquivalentModifierMask: number

  get image(): AppKitImage | null
  set image(value: Wrapper)

  get submenu(): AppKitMenu | null
  set submenu(value: Wrapper)

  get attributedTitle(): AppKitAttributedString | null
  set attributedTitle(value: Wrapper)

  readonly separatorItem: boolean

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitMenuItem<M extends Record<keyof M, unknown[]> = AppKitMenuItem.Events> {
  constructor(opts?: { title?: string; keyEquivalent?: string; selector?: string })

  static separator(): AppKitMenuItem | null

  static readonly EVENT_MODIFIER_FLAGS: {
    readonly CAPS_LOCK: number
    readonly SHIFT: number
    readonly CONTROL: number
    readonly OPTION: number
    readonly COMMAND: number
    readonly FUNCTION: number
  }
}

declare namespace AppKitMenuItem {
  export interface Events {
    click: []
  }
}

export = AppKitMenuItem
