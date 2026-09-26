import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitButton = require('./button')
import AppKitImage = require('./image')
import AppKitView = require('./view')
import AppKitWindow = require('./window')

/** An alert, as an `NSAlert`. */
interface AppKitAlert<
  M extends Record<keyof M, unknown[]> = AppKitAlert.Events
> extends EventEmitter<M> {
  messageText: string | null

  informativeText: string | null

  /** A `STYLE` constant. */
  alertStyle: number

  showsHelp: boolean

  showsSuppressionButton: boolean

  helpAnchor: string | null

  get icon(): AppKitImage | null
  set icon(value: Wrapper)

  get accessoryView(): AppKitView | null
  set accessoryView(value: Wrapper)

  readonly suppressionButton: AppKitButton | null

  readonly window: AppKitWindow | null

  runModal(): number

  beginSheetModal(parent: Wrapper): this

  readonly buttons: AppKitButton[]

  addButtonWithTitle(title: string): AppKitButton

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitAlert<M extends Record<keyof M, unknown[]> = AppKitAlert.Events> {
  constructor()

  static readonly STYLE: {
    readonly WARNING: number
    readonly INFORMATIONAL: number
    readonly CRITICAL: number
  }

  static readonly MODAL_RESPONSE: {
    readonly OK: number
    readonly CANCEL: number
    readonly STOP: number
    readonly ABORT: number
    readonly CONTINUE: number
    readonly FIRST_BUTTON: number
    readonly SECOND_BUTTON: number
    readonly THIRD_BUTTON: number
  }
}

declare namespace AppKitAlert {
  export interface Events {
    response: [response: number]
  }
}

export = AppKitAlert
