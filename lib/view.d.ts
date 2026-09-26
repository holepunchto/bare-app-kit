import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitAppearance = require('./appearance')
import AppKitLayoutAnchor = require('./layout-anchor')
import AppKitMenu = require('./menu')
import AppKitScrollView = require('./scroll-view')
import AppKitUndoManager = require('./undo-manager')
import AppKitWindow = require('./window')

/** The base of every view, as an `NSView`. A view added to another view is kept alive by it, so its listeners keep working. */
interface AppKitView<
  M extends Record<keyof M, unknown[]> = AppKitView.Events
> extends EventEmitter<M> {
  flipped: boolean

  hitTestable: boolean

  acceptsFirstResponder: boolean

  get frame(): { x: number; y: number; width: number; height: number }
  set frame(value: Partial<{ x: number; y: number; width: number; height: number }>)

  get bounds(): { x: number; y: number; width: number; height: number }
  set bounds(value: Partial<{ x: number; y: number; width: number; height: number }>)

  hidden: boolean

  readonly hiddenOrHasHiddenAncestor: boolean

  alphaValue: number

  toolTip: string | null

  autoresizingMask: number

  autoresizesSubviews: boolean

  translatesAutoresizingMaskIntoConstraints: boolean

  wantsLayer: boolean

  needsDisplay: boolean

  needsLayout: boolean

  readonly fittingSize: AppKitView.Size

  readonly intrinsicContentSize: AppKitView.Size

  readonly safeAreaInsets: { top: number; left: number; bottom: number; right: number }

  readonly superview: AppKitView | null

  readonly subviews: AppKitView[]

  addSubview(view: Wrapper, ordering?: number, relativeTo?: Wrapper | null): this

  removeFromSuperview(): this

  display(): this

  layout(): this

  readonly topAnchor: AppKitLayoutAnchor | null

  readonly bottomAnchor: AppKitLayoutAnchor | null

  readonly leadingAnchor: AppKitLayoutAnchor | null

  readonly trailingAnchor: AppKitLayoutAnchor | null

  readonly leftAnchor: AppKitLayoutAnchor | null

  readonly rightAnchor: AppKitLayoutAnchor | null

  readonly widthAnchor: AppKitLayoutAnchor | null

  readonly heightAnchor: AppKitLayoutAnchor | null

  readonly centerXAnchor: AppKitLayoutAnchor | null

  readonly centerYAnchor: AppKitLayoutAnchor | null

  readonly firstBaselineAnchor: AppKitLayoutAnchor | null

  readonly lastBaselineAnchor: AppKitLayoutAnchor | null

  appearance: AppKitAppearance | null

  readonly effectiveAppearance: AppKitAppearance | null

  needsUpdateConstraints: boolean

  setContentHuggingPriority(priority: number, orientation: number): this

  setContentCompressionResistancePriority(priority: number, orientation: number): this

  readonly undoManager: AppKitUndoManager | null

  layoutSubtreeIfNeeded(): this

  addTrackingArea(area: Wrapper): this

  removeTrackingArea(area: Wrapper): this

  get menu(): AppKitMenu | null
  set menu(value: Wrapper)

  readonly visibleRect: { x: number; y: number; width: number; height: number }

  clipsToBounds: boolean

  canDrawSubviewsIntoLayer: boolean

  layerContentsRedrawPolicy: number

  /** A `FOCUS_RING_TYPE` constant. */
  focusRingType: number

  readonly opaque: boolean

  readonly allowsVibrancy: boolean

  readonly rotatedFromBase: boolean

  readonly inLiveResize: boolean

  readonly canBecomeKeyView: boolean

  userInterfaceLayoutDirection: number

  nextKeyView: AppKitView | null

  readonly window: AppKitWindow | null

  readonly enclosingScrollView: AppKitScrollView | null

  convertPointFromView(x: number, y: number, view?: Wrapper | null): AppKitView.Point

  convertPointToView(x: number, y: number, view?: Wrapper | null): AppKitView.Point

  hitTest(x: number, y: number): AppKitView | null

  setNeedsDisplayInRect(x: number, y: number, width: number, height: number): this

  scrollPointToVisible(x: number, y: number): this

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitView<M extends Record<keyof M, unknown[]> = AppKitView.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly AUTORESIZING_MASK_OPTIONS: {
    readonly NONE: number
    readonly MIN_X_MARGIN: number
    readonly WIDTH_SIZABLE: number
    readonly MAX_X_MARGIN: number
    readonly MIN_Y_MARGIN: number
    readonly HEIGHT_SIZABLE: number
    readonly MAX_Y_MARGIN: number
  }

  static readonly WINDOW_ORDERING_MODE: {
    readonly ABOVE: number
    readonly BELOW: number
  }

  static readonly FOCUS_RING_TYPE: {
    readonly DEFAULT: number
    readonly NONE: number
    readonly EXTERIOR: number
  }
}

declare namespace AppKitView {
  export interface Point {
    x: number
    y: number
  }

  export interface Size {
    width: number
    height: number
  }

  export interface Rect extends Point, Size {}

  export interface Insets {
    top: number
    left: number
    bottom: number
    right: number
  }

  /** A range of characters, as UTF-16 offsets. */
  export interface Range {
    location: number
    length: number
  }

  export interface IndexPath {
    section: number
    item: number
  }

  /** `modifiers` is `AppKitEvent.EVENT_MODIFIER_FLAGS` flags combined with `|`. */
  export interface MouseEvent {
    x: number
    y: number
    button: number
    clickCount: number
    modifiers: number
  }

  export interface ScrollEvent {
    x: number
    y: number
    deltaX: number
    deltaY: number
    modifiers: number
  }

  export interface KeyEvent {
    keyCode: number
    repeat: boolean
    modifiers: number
    characters: string | null
  }

  export interface ModifierEvent {
    modifiers: number
  }

  export interface Events {
    mouseDown: [event: AppKitView.MouseEvent]
    mouseUp: [event: AppKitView.MouseEvent]
    mouseDragged: [event: AppKitView.MouseEvent]
    mouseMoved: [event: AppKitView.MouseEvent]
    rightMouseDown: [event: AppKitView.MouseEvent]
    rightMouseUp: [event: AppKitView.MouseEvent]
    mouseEntered: [event: AppKitView.MouseEvent]
    mouseExited: [event: AppKitView.MouseEvent]
    scrollWheel: [event: AppKitView.ScrollEvent]
    keyDown: [event: AppKitView.KeyEvent]
    keyUp: [event: AppKitView.KeyEvent]
    flagsChanged: [event: AppKitView.ModifierEvent]
    willDraw: []
    didChangeEffectiveAppearance: []
  }
}

export = AppKitView
