import { tag, handle, Handle } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitView = require('./view')

/** A tracking area, as an `NSTrackingArea`. */
interface AppKitTrackingArea<
  M extends Record<keyof M, unknown[]> = AppKitTrackingArea.Events
> extends EventEmitter<M> {
  readonly rect: AppKitView.Rect

  /** `OPTIONS` flags combined with `|`. */
  readonly options: number

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitTrackingArea<M extends Record<keyof M, unknown[]> = AppKitTrackingArea.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number; options?: number })

  static readonly OPTIONS: {
    readonly MOUSE_ENTERED_AND_EXITED: number
    readonly MOUSE_MOVED: number
    readonly CURSOR_UPDATE: number
    readonly ACTIVE_WHEN_FIRST_RESPONDER: number
    readonly ACTIVE_IN_KEY_WINDOW: number
    readonly ACTIVE_IN_ACTIVE_APP: number
    readonly ACTIVE_ALWAYS: number
    readonly ASSUME_INSIDE: number
    readonly IN_VISIBLE_RECT: number
    readonly ENABLED_DURING_MOUSE_DRAG: number
  }
}

declare namespace AppKitTrackingArea {
  export interface Events {
    mouseEntered: []
    mouseExited: []
    mouseMoved: []
    cursorUpdate: []
  }
}

export = AppKitTrackingArea
