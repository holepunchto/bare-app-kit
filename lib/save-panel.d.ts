import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitContentType = require('./content-type')
import AppKitView = require('./view')

/** A save panel, as an `NSSavePanel`. */
interface AppKitSavePanel<M extends Record<keyof M, unknown[]> = {}> extends EventEmitter<M> {
  readonly url: string | null

  get directoryURL(): string | null
  set directoryURL(value: string)

  nameFieldStringValue: string | null

  nameFieldLabel: string | null

  message: string | null

  prompt: string | null

  canCreateDirectories: boolean

  canSelectHiddenExtension: boolean

  showsHiddenFiles: boolean

  showsTagField: boolean

  extensionHidden: boolean

  treatsFilePackagesAsDirectories: boolean

  get accessoryView(): AppKitView | null
  set accessoryView(value: Wrapper)

  get allowedContentTypes(): AppKitContentType[]
  set allowedContentTypes(value: AppKitContentType[])

  runModal(): number

  ok(): this

  cancel(): this

  validateVisibleColumns(): this

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitSavePanel<M extends Record<keyof M, unknown[]> = {}> {
  constructor()

  static readonly MODAL_RESPONSE: {
    readonly OK: number
    readonly CANCEL: number
  }
}

export = AppKitSavePanel
