import { tag, handle, Handle } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'

/** An undo manager, as an `NSUndoManager`. */
interface AppKitUndoManager extends EventEmitter<{}> {
  readonly canUndo: boolean

  readonly canRedo: boolean

  readonly undoing: boolean

  readonly redoing: boolean

  readonly undoRegistrationEnabled: boolean

  groupsByEvent: boolean

  levelsOfUndo: number

  readonly undoActionName: string | null

  readonly redoActionName: string | null

  readonly undoMenuItemTitle: string | null

  readonly redoMenuItemTitle: string | null

  readonly groupingLevel: number

  undo(): this

  redo(): this

  undoNestedGroup(): this

  beginUndoGrouping(): this

  endUndoGrouping(): this

  removeAllActions(): this

  disableUndoRegistration(): this

  enableUndoRegistration(): this

  setActionName(name: string | null): this

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitUndoManager {
  constructor()
}

export = AppKitUndoManager
