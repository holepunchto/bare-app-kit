import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'
import EventEmitter from 'bare-events'
import AppKitAppearance = require('./appearance')
import AppKitColor = require('./color')
import AppKitImage = require('./image')
import AppKitScreen = require('./screen')
import AppKitToolbar = require('./toolbar')
import AppKitView = require('./view')

/** A window, as an `NSWindow`. A window that is ordered in is kept alive until it closes. */
interface AppKitWindow<
  M extends Record<keyof M, unknown[]> = AppKitWindow.Events
> extends EventEmitter<M> {
  title: string | null

  subtitle: string | null

  representedFilename: string | null

  miniwindowTitle: string | null

  readonly frameAutosaveName: string | null

  get contentView(): AppKitView | null
  set contentView(value: Wrapper)

  get backgroundColor(): AppKitColor | null
  set backgroundColor(value: Wrapper)

  get miniwindowImage(): AppKitImage | null
  set miniwindowImage(value: Wrapper)

  get toolbar(): AppKitToolbar | null
  set toolbar(value: Wrapper)

  get appearance(): AppKitAppearance | null
  set appearance(value: Wrapper)

  readonly effectiveAppearance: AppKitAppearance | null

  get parentWindow(): AppKitWindow | null
  set parentWindow(value: Wrapper)

  readonly attachedSheet: AppKitWindow | null

  /** `STYLE_MASK` flags combined with `|`. */
  styleMask: number

  /** A `LEVEL` constant. */
  level: number

  /** A `COLLECTION_BEHAVIOR` constant. */
  collectionBehavior: number

  /** An `ANIMATION_BEHAVIOR` constant. */
  animationBehavior: number

  /** A `TITLE_VISIBILITY` constant. */
  titleVisibility: number

  /** A `TOOLBAR_STYLE` constant. */
  toolbarStyle: number

  /** A `TITLEBAR_SEPARATOR_STYLE` constant. */
  titlebarSeparatorStyle: number

  /** A `TABBING_MODE` constant. */
  tabbingMode: number

  readonly windowNumber: number

  titlebarAppearsTransparent: boolean

  excludedFromWindowsMenu: boolean

  documentEdited: boolean

  movable: boolean

  movableByWindowBackground: boolean

  hidesOnDeactivate: boolean

  canHide: boolean

  hasShadow: boolean

  opaque: boolean

  preservesContentDuringLiveResize: boolean

  allowsConcurrentViewDrawing: boolean

  viewsNeedDisplay: boolean

  get initialFirstResponder(): AppKitView | null
  set initialFirstResponder(value: Wrapper | null)

  autorecalculatesKeyViewLoop: boolean

  readonly worksWhenModal: boolean

  readonly visible: boolean

  readonly keyWindow: boolean

  readonly mainWindow: boolean

  readonly zoomed: boolean

  readonly miniaturized: boolean

  readonly inLiveResize: boolean

  readonly onActiveSpace: boolean

  readonly sheet: boolean

  readonly canBecomeKeyWindow: boolean

  readonly canBecomeMainWindow: boolean

  alphaValue: number

  readonly backingScaleFactor: number

  readonly screen: AppKitScreen | null

  readonly frame: AppKitView.Rect

  readonly contentLayoutRect: AppKitView.Rect

  get minSize(): AppKitView.Size
  set minSize(value: Partial<{ width: number; height: number }>)

  get maxSize(): AppKitView.Size
  set maxSize(value: Partial<{ width: number; height: number }>)

  get contentMinSize(): AppKitView.Size
  set contentMinSize(value: Partial<{ width: number; height: number }>)

  get contentMaxSize(): AppKitView.Size
  set contentMaxSize(value: Partial<{ width: number; height: number }>)

  get resizeIncrements(): AppKitView.Size
  set resizeIncrements(value: Partial<{ width: number; height: number }>)

  get aspectRatio(): AppKitView.Size
  set aspectRatio(value: Partial<{ width: number; height: number }>)

  get contentResizeIncrements(): AppKitView.Size
  set contentResizeIncrements(value: Partial<{ width: number; height: number }>)

  get contentAspectRatio(): AppKitView.Size
  set contentAspectRatio(value: Partial<{ width: number; height: number }>)

  center(): this

  close(): this

  performClose(): this

  makeMainWindow(): this

  orderOut(): this

  miniaturize(): this

  deminiaturize(): this

  zoom(): this

  toggleFullScreen(): this

  display(): this

  invalidateShadow(): this

  selectNextKeyView(): this

  selectPreviousKeyView(): this

  setFrame(
    x: number,
    y: number,
    width: number,
    height: number,
    display: boolean,
    animate: boolean
  ): this

  setFrameOrigin(x: number, y: number): this

  setFrameTopLeftPoint(x: number, y: number): this

  setContentSize(width: number, height: number): this

  makeFirstResponder(view: Wrapper): boolean

  setFrameAutosaveName(name: string | null): boolean

  saveFrameUsingName(name: string | null): this

  setFrameUsingName(name: string | null): boolean

  readonly childWindows: AppKitWindow[]

  addChildWindow(child: Wrapper, ordered?: number): this

  removeChildWindow(child: Wrapper): this

  orderBack(): this

  orderFront(): this

  makeKeyWindow(): this

  makeKeyAndOrderFront(): this

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitWindow<M extends Record<keyof M, unknown[]> = AppKitWindow.Events> {
  constructor(opts?: {
    x?: number
    y?: number
    width?: number
    height?: number
    styleMask?: number
    defer?: boolean
  })

  static readonly STYLE_MASK: {
    readonly BORDERLESS: number
    readonly TITLED: number
    readonly CLOSABLE: number
    readonly MINIATURIZABLE: number
    readonly RESIZABLE: number
    readonly UTILITY_WINDOW: number
    readonly DOC_MODAL_WINDOW: number
    readonly NONACTIVATING_PANEL: number
    readonly HUD_WINDOW: number
    readonly FULL_SCREEN: number
    readonly FULL_SIZE_CONTENT_VIEW: number
  }

  static readonly LEVEL: {
    readonly NORMAL: number
    readonly FLOATING: number
    readonly SUBMENU: number
    readonly TORN_OFF_MENU: number
    readonly MODAL_PANEL: number
    readonly MAIN_MENU: number
    readonly STATUS: number
    readonly POP_UP_MENU: number
    readonly SCREEN_SAVER: number
  }

  static readonly TITLE_VISIBILITY: {
    readonly VISIBLE: number
    readonly HIDDEN: number
  }

  static readonly TOOLBAR_STYLE: {
    readonly AUTOMATIC: number
    readonly EXPANDED: number
    readonly PREFERENCE: number
    readonly UNIFIED: number
    readonly UNIFIED_COMPACT: number
  }

  static readonly TITLEBAR_SEPARATOR_STYLE: {
    readonly AUTOMATIC: number
    readonly NONE: number
    readonly LINE: number
    readonly SHADOW: number
  }

  static readonly COLLECTION_BEHAVIOR: {
    readonly DEFAULT: number
    readonly CAN_JOIN_ALL_SPACES: number
    readonly MOVE_TO_ACTIVE_SPACE: number
    readonly MANAGED: number
    readonly TRANSIENT: number
    readonly STATIONARY: number
    readonly PARTICIPATES_IN_CYCLE: number
    readonly IGNORES_CYCLE: number
    readonly FULL_SCREEN_PRIMARY: number
    readonly FULL_SCREEN_AUXILIARY: number
    readonly FULL_SCREEN_NONE: number
    readonly ALLOWS_TILING: number
    readonly DISALLOWS_TILING: number
  }

  static readonly ANIMATION_BEHAVIOR: {
    readonly DEFAULT: number
    readonly NONE: number
    readonly DOCUMENT_WINDOW: number
    readonly UTILITY_WINDOW: number
    readonly ALERT_PANEL: number
  }

  static readonly TABBING_MODE: {
    readonly AUTOMATIC: number
    readonly PREFERRED: number
    readonly DISALLOWED: number
  }

  static readonly WINDOW_ORDERING_MODE: {
    readonly ABOVE: number
    readonly BELOW: number
    readonly OUT: number
  }
}

declare namespace AppKitWindow {
  export interface Events {
    didResize: []
    didMove: []
    willClose: []
    didBecomeKey: []
    didResignKey: []
    didBecomeMain: []
    didResignMain: []
    didMiniaturize: []
    didDeminiaturize: []
    didEnterFullScreen: []
    didExitFullScreen: []
    willStartLiveResize: []
    didEndLiveResize: []
    didChangeScreen: []
    didChangeBackingProperties: []
  }
}

export = AppKitWindow
