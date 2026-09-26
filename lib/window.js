const binding = require('../binding')
const { adopt, expose } = require('./handle')
const observe = require('./events')
const retain = require('./retain')
const wrap = require('./wrap')
const EventEmitter = require('bare-events')
const AppKitView = require('./view')
const AppKitColor = require('./color')
const AppKitImage = require('./image')
const AppKitToolbar = require('./toolbar')
const AppKitAppearance = require('./appearance')

// AppKit keeps ordered in windows alive; the native window now belongs to its
// JS wrapper, so something has to keep that wrapper reachable for as long.
const presented = new Set()

module.exports = exports = class AppKitWindow extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._contentView = null
    this._parentWindow = null
    this._toolbar = null
    this._retained = new Set()

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0, styleMask = 0, defer = false } = opts

    return binding.windowInit(x, y, width, height, styleMask, defer, this)
  }

  get title() {
    return binding.windowTitle(this._tag)
  }

  set title(title) {
    binding.windowTitle(this._tag, title)
  }

  get subtitle() {
    return binding.windowSubtitle(this._tag)
  }

  set subtitle(subtitle) {
    binding.windowSubtitle(this._tag, subtitle)
  }

  get representedFilename() {
    return binding.windowRepresentedFilename(this._tag)
  }

  set representedFilename(representedFilename) {
    binding.windowRepresentedFilename(this._tag, representedFilename)
  }

  get miniwindowTitle() {
    return binding.windowMiniwindowTitle(this._tag)
  }

  set miniwindowTitle(miniwindowTitle) {
    binding.windowMiniwindowTitle(this._tag, miniwindowTitle)
  }

  get frameAutosaveName() {
    return binding.windowFrameAutosaveName(this._tag)
  }

  get contentView() {
    return retain(this, '_contentView', AppKitView, binding.windowContentView(this._tag))
  }

  set contentView(contentView) {
    binding.windowContentView(this._tag, adopt(contentView))

    this._contentView = contentView
  }

  get backgroundColor() {
    return wrap(AppKitColor, binding.windowBackgroundColor(this._tag))
  }

  set backgroundColor(backgroundColor) {
    binding.windowBackgroundColor(this._tag, adopt(backgroundColor))
  }

  get miniwindowImage() {
    return wrap(AppKitImage, binding.windowMiniwindowImage(this._tag))
  }

  set miniwindowImage(miniwindowImage) {
    binding.windowMiniwindowImage(this._tag, adopt(miniwindowImage))
  }

  get toolbar() {
    return retain(this, '_toolbar', AppKitToolbar, binding.windowToolbar(this._tag))
  }

  set toolbar(toolbar) {
    binding.windowToolbar(this._tag, adopt(toolbar))

    this._toolbar = toolbar
  }

  get appearance() {
    return wrap(AppKitAppearance, binding.windowAppearance(this._tag))
  }

  set appearance(appearance) {
    binding.windowAppearance(this._tag, adopt(appearance))
  }

  get effectiveAppearance() {
    return wrap(AppKitAppearance, binding.windowEffectiveAppearance(this._tag))
  }

  get parentWindow() {
    return retain(this, '_parentWindow', AppKitWindow, binding.windowParentWindow(this._tag))
  }

  set parentWindow(parentWindow) {
    binding.windowParentWindow(this._tag, adopt(parentWindow))

    this._parentWindow = parentWindow
  }

  get attachedSheet() {
    return wrap(AppKitWindow, binding.windowAttachedSheet(this._tag))
  }

  get styleMask() {
    return binding.windowStyleMask(this._tag)
  }

  set styleMask(styleMask) {
    binding.windowStyleMask(this._tag, styleMask)
  }

  get level() {
    return binding.windowLevel(this._tag)
  }

  set level(level) {
    binding.windowLevel(this._tag, level)
  }

  get collectionBehavior() {
    return binding.windowCollectionBehavior(this._tag)
  }

  set collectionBehavior(collectionBehavior) {
    binding.windowCollectionBehavior(this._tag, collectionBehavior)
  }

  get animationBehavior() {
    return binding.windowAnimationBehavior(this._tag)
  }

  set animationBehavior(animationBehavior) {
    binding.windowAnimationBehavior(this._tag, animationBehavior)
  }

  get titleVisibility() {
    return binding.windowTitleVisibility(this._tag)
  }

  set titleVisibility(titleVisibility) {
    binding.windowTitleVisibility(this._tag, titleVisibility)
  }

  get toolbarStyle() {
    return binding.windowToolbarStyle(this._tag)
  }

  set toolbarStyle(toolbarStyle) {
    binding.windowToolbarStyle(this._tag, toolbarStyle)
  }

  get titlebarSeparatorStyle() {
    return binding.windowTitlebarSeparatorStyle(this._tag)
  }

  set titlebarSeparatorStyle(titlebarSeparatorStyle) {
    binding.windowTitlebarSeparatorStyle(this._tag, titlebarSeparatorStyle)
  }

  get tabbingMode() {
    return binding.windowTabbingMode(this._tag)
  }

  set tabbingMode(tabbingMode) {
    binding.windowTabbingMode(this._tag, tabbingMode)
  }

  get windowNumber() {
    return binding.windowWindowNumber(this._tag)
  }

  get titlebarAppearsTransparent() {
    return binding.windowTitlebarAppearsTransparent(this._tag)
  }

  set titlebarAppearsTransparent(titlebarAppearsTransparent) {
    binding.windowTitlebarAppearsTransparent(this._tag, titlebarAppearsTransparent)
  }

  get excludedFromWindowsMenu() {
    return binding.windowExcludedFromWindowsMenu(this._tag)
  }

  set excludedFromWindowsMenu(excludedFromWindowsMenu) {
    binding.windowExcludedFromWindowsMenu(this._tag, excludedFromWindowsMenu)
  }

  get documentEdited() {
    return binding.windowDocumentEdited(this._tag)
  }

  set documentEdited(documentEdited) {
    binding.windowDocumentEdited(this._tag, documentEdited)
  }

  get movable() {
    return binding.windowMovable(this._tag)
  }

  set movable(movable) {
    binding.windowMovable(this._tag, movable)
  }

  get movableByWindowBackground() {
    return binding.windowMovableByWindowBackground(this._tag)
  }

  set movableByWindowBackground(movableByWindowBackground) {
    binding.windowMovableByWindowBackground(this._tag, movableByWindowBackground)
  }

  get hidesOnDeactivate() {
    return binding.windowHidesOnDeactivate(this._tag)
  }

  set hidesOnDeactivate(hidesOnDeactivate) {
    binding.windowHidesOnDeactivate(this._tag, hidesOnDeactivate)
  }

  get canHide() {
    return binding.windowCanHide(this._tag)
  }

  set canHide(canHide) {
    binding.windowCanHide(this._tag, canHide)
  }

  get hasShadow() {
    return binding.windowHasShadow(this._tag)
  }

  set hasShadow(hasShadow) {
    binding.windowHasShadow(this._tag, hasShadow)
  }

  get opaque() {
    return binding.windowOpaque(this._tag)
  }

  set opaque(opaque) {
    binding.windowOpaque(this._tag, opaque)
  }

  get preservesContentDuringLiveResize() {
    return binding.windowPreservesContentDuringLiveResize(this._tag)
  }

  set preservesContentDuringLiveResize(preservesContentDuringLiveResize) {
    binding.windowPreservesContentDuringLiveResize(this._tag, preservesContentDuringLiveResize)
  }

  get allowsConcurrentViewDrawing() {
    return binding.windowAllowsConcurrentViewDrawing(this._tag)
  }

  set allowsConcurrentViewDrawing(allowsConcurrentViewDrawing) {
    binding.windowAllowsConcurrentViewDrawing(this._tag, allowsConcurrentViewDrawing)
  }

  get viewsNeedDisplay() {
    return binding.windowViewsNeedDisplay(this._tag)
  }

  set viewsNeedDisplay(viewsNeedDisplay) {
    binding.windowViewsNeedDisplay(this._tag, viewsNeedDisplay)
  }

  get initialFirstResponder() {
    return wrap(AppKitView, binding.windowInitialFirstResponder(this._tag))
  }

  set initialFirstResponder(view) {
    binding.windowInitialFirstResponder(this._tag, view === null ? null : adopt(view))

    this._initialFirstResponder = view
  }

  get autorecalculatesKeyViewLoop() {
    return binding.windowAutorecalculatesKeyViewLoop(this._tag)
  }

  set autorecalculatesKeyViewLoop(autorecalculatesKeyViewLoop) {
    binding.windowAutorecalculatesKeyViewLoop(this._tag, autorecalculatesKeyViewLoop)
  }

  get worksWhenModal() {
    return binding.windowWorksWhenModal(this._tag)
  }

  get visible() {
    return binding.windowVisible(this._tag)
  }

  get keyWindow() {
    return binding.windowKeyWindow(this._tag)
  }

  get mainWindow() {
    return binding.windowMainWindow(this._tag)
  }

  get zoomed() {
    return binding.windowZoomed(this._tag)
  }

  get miniaturized() {
    return binding.windowMiniaturized(this._tag)
  }

  get inLiveResize() {
    return binding.windowInLiveResize(this._tag)
  }

  get onActiveSpace() {
    return binding.windowOnActiveSpace(this._tag)
  }

  get sheet() {
    return binding.windowSheet(this._tag)
  }

  get canBecomeKeyWindow() {
    return binding.windowCanBecomeKeyWindow(this._tag)
  }

  get canBecomeMainWindow() {
    return binding.windowCanBecomeMainWindow(this._tag)
  }

  get alphaValue() {
    return binding.windowAlphaValue(this._tag)
  }

  set alphaValue(alphaValue) {
    binding.windowAlphaValue(this._tag, alphaValue)
  }

  get backingScaleFactor() {
    return binding.windowBackingScaleFactor(this._tag)
  }

  get frame() {
    return binding.windowFrame(this._tag)
  }

  get contentLayoutRect() {
    return binding.windowContentLayoutRect(this._tag)
  }

  get minSize() {
    return binding.windowMinSize(this._tag)
  }

  set minSize(minSize) {
    const { width = 0, height = 0 } = minSize

    binding.windowMinSize(this._tag, width, height)
  }

  get maxSize() {
    return binding.windowMaxSize(this._tag)
  }

  set maxSize(maxSize) {
    const { width = 0, height = 0 } = maxSize

    binding.windowMaxSize(this._tag, width, height)
  }

  get contentMinSize() {
    return binding.windowContentMinSize(this._tag)
  }

  set contentMinSize(contentMinSize) {
    const { width = 0, height = 0 } = contentMinSize

    binding.windowContentMinSize(this._tag, width, height)
  }

  get contentMaxSize() {
    return binding.windowContentMaxSize(this._tag)
  }

  set contentMaxSize(contentMaxSize) {
    const { width = 0, height = 0 } = contentMaxSize

    binding.windowContentMaxSize(this._tag, width, height)
  }

  get resizeIncrements() {
    return binding.windowResizeIncrements(this._tag)
  }

  set resizeIncrements(resizeIncrements) {
    const { width = 0, height = 0 } = resizeIncrements

    binding.windowResizeIncrements(this._tag, width, height)
  }

  get aspectRatio() {
    return binding.windowAspectRatio(this._tag)
  }

  set aspectRatio(aspectRatio) {
    const { width = 0, height = 0 } = aspectRatio

    binding.windowAspectRatio(this._tag, width, height)
  }

  get contentResizeIncrements() {
    return binding.windowContentResizeIncrements(this._tag)
  }

  set contentResizeIncrements(contentResizeIncrements) {
    const { width = 0, height = 0 } = contentResizeIncrements

    binding.windowContentResizeIncrements(this._tag, width, height)
  }

  get contentAspectRatio() {
    return binding.windowContentAspectRatio(this._tag)
  }

  set contentAspectRatio(contentAspectRatio) {
    const { width = 0, height = 0 } = contentAspectRatio

    binding.windowContentAspectRatio(this._tag, width, height)
  }

  center() {
    binding.windowCenter(this._tag)
    return this
  }

  close() {
    binding.windowClose(this._tag)
    return this
  }

  performClose() {
    binding.windowPerformClose(this._tag)
    return this
  }

  makeMainWindow() {
    binding.windowMakeMainWindow(this._tag)
    return this
  }

  orderOut() {
    binding.windowOrderOut(this._tag)
    return this
  }

  miniaturize() {
    binding.windowMiniaturize(this._tag)
    return this
  }

  deminiaturize() {
    binding.windowDeminiaturize(this._tag)
    return this
  }

  zoom() {
    binding.windowZoom(this._tag)
    return this
  }

  toggleFullScreen() {
    binding.windowToggleFullScreen(this._tag)
    return this
  }

  display() {
    binding.windowDisplay(this._tag)
    return this
  }

  invalidateShadow() {
    binding.windowInvalidateShadow(this._tag)
    return this
  }

  selectNextKeyView() {
    binding.windowSelectNextKeyView(this._tag)
    return this
  }

  selectPreviousKeyView() {
    binding.windowSelectPreviousKeyView(this._tag)
    return this
  }

  setFrame(x, y, width, height, display, animate) {
    binding.windowSetFrame(this._tag, x, y, width, height, display, animate)
    return this
  }

  setFrameOrigin(x, y) {
    binding.windowSetFrameOrigin(this._tag, x, y)
    return this
  }

  setFrameTopLeftPoint(x, y) {
    binding.windowSetFrameTopLeftPoint(this._tag, x, y)
    return this
  }

  setContentSize(width, height) {
    binding.windowSetContentSize(this._tag, width, height)
    return this
  }

  makeFirstResponder(view) {
    return binding.windowMakeFirstResponder(this._tag, adopt(view))
  }

  setFrameAutosaveName(name) {
    return binding.windowSetFrameAutosaveName(this._tag, name)
  }

  saveFrameUsingName(name) {
    binding.windowSaveFrameUsingName(this._tag, name)
    return this
  }

  setFrameUsingName(name) {
    return binding.windowSetFrameUsingName(this._tag, name)
  }

  get childWindows() {
    return binding.windowChildWindows(this._tag).map((tag) => wrap(AppKitWindow, tag))
  }

  addChildWindow(child, ordered = binding.WINDOW_ORDERING_ABOVE) {
    binding.windowAddChildWindow(this._tag, adopt(child), ordered)
    this._retained.add(child)
    return this
  }

  removeChildWindow(child) {
    binding.windowRemoveChildWindow(this._tag, adopt(child))
    this._retained.delete(child)
    return this
  }

  orderBack() {
    binding.windowOrderBack(this._tag)
    presented.add(this)
    return this
  }

  orderFront() {
    binding.windowOrderFront(this._tag)
    presented.add(this)
    return this
  }

  makeKeyWindow() {
    binding.windowMakeKeyWindow(this._tag)
    presented.add(this)
    return this
  }

  makeKeyAndOrderFront() {
    binding.windowMakeKeyAndOrderFront(this._tag)
    presented.add(this)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitWindow }
    }
  }

  _onwillclose() {
    presented.delete(this)
    this.emit('willClose')
  }

  _ondidresize() {
    this.emit('didResize')
  }

  _ondidmove() {
    this.emit('didMove')
  }

  _ondidbecomekey() {
    this.emit('didBecomeKey')
  }

  _ondidresignkey() {
    this.emit('didResignKey')
  }

  _ondidbecomemain() {
    this.emit('didBecomeMain')
  }

  _ondidresignmain() {
    this.emit('didResignMain')
  }

  _ondidminiaturize() {
    this.emit('didMiniaturize')
  }

  _ondiddeminiaturize() {
    this.emit('didDeminiaturize')
  }

  _ondidenterfullscreen() {
    this.emit('didEnterFullScreen')
  }

  _ondidexitfullscreen() {
    this.emit('didExitFullScreen')
  }

  _onwillstartliveresize() {
    this.emit('willStartLiveResize')
  }

  _ondidendliveresize() {
    this.emit('didEndLiveResize')
  }
}

exports._events = {
  didResize: 1,
  didMove: 2,
  willClose: 4,
  didBecomeKey: 8,
  didResignKey: 16,
  didBecomeMain: 32,
  didResignMain: 64,
  didMiniaturize: 128,
  didDeminiaturize: 256,
  didEnterFullScreen: 512,
  didExitFullScreen: 1024,
  willStartLiveResize: 2048,
  didEndLiveResize: 4096
}

exports._always = 4

exports.STYLE_MASK = {
  BORDERLESS: binding.WINDOW_STYLE_MASK_BORDERLESS,
  TITLED: binding.WINDOW_STYLE_MASK_TITLED,
  CLOSABLE: binding.WINDOW_STYLE_MASK_CLOSABLE,
  MINIATURIZABLE: binding.WINDOW_STYLE_MASK_MINIATURIZABLE,
  RESIZABLE: binding.WINDOW_STYLE_MASK_RESIZABLE,
  UTILITY_WINDOW: binding.WINDOW_STYLE_MASK_UTILITY_WINDOW,
  DOC_MODAL_WINDOW: binding.WINDOW_STYLE_MASK_DOC_MODAL_WINDOW,
  NONACTIVATING_PANEL: binding.WINDOW_STYLE_MASK_NONACTIVATING_PANEL,
  HUD_WINDOW: binding.WINDOW_STYLE_MASK_HUD_WINDOW,
  FULL_SCREEN: binding.WINDOW_STYLE_MASK_FULL_SCREEN,
  FULL_SIZE_CONTENT_VIEW: binding.WINDOW_STYLE_MASK_FULL_SIZE_CONTENT_VIEW
}

exports.LEVEL = {
  NORMAL: binding.WINDOW_LEVEL_NORMAL,
  FLOATING: binding.WINDOW_LEVEL_FLOATING,
  SUBMENU: binding.WINDOW_LEVEL_SUBMENU,
  TORN_OFF_MENU: binding.WINDOW_LEVEL_TORN_OFF_MENU,
  MODAL_PANEL: binding.WINDOW_LEVEL_MODAL_PANEL,
  MAIN_MENU: binding.WINDOW_LEVEL_MAIN_MENU,
  STATUS: binding.WINDOW_LEVEL_STATUS,
  POP_UP_MENU: binding.WINDOW_LEVEL_POP_UP_MENU,
  SCREEN_SAVER: binding.WINDOW_LEVEL_SCREEN_SAVER
}

exports.TITLE_VISIBILITY = {
  VISIBLE: binding.WINDOW_TITLE_VISIBILITY_VISIBLE,
  HIDDEN: binding.WINDOW_TITLE_VISIBILITY_HIDDEN
}

exports.TOOLBAR_STYLE = {
  AUTOMATIC: binding.WINDOW_TOOLBAR_STYLE_AUTOMATIC,
  EXPANDED: binding.WINDOW_TOOLBAR_STYLE_EXPANDED,
  PREFERENCE: binding.WINDOW_TOOLBAR_STYLE_PREFERENCE,
  UNIFIED: binding.WINDOW_TOOLBAR_STYLE_UNIFIED,
  UNIFIED_COMPACT: binding.WINDOW_TOOLBAR_STYLE_UNIFIED_COMPACT
}

exports.TITLEBAR_SEPARATOR_STYLE = {
  AUTOMATIC: binding.WINDOW_TITLEBAR_SEPARATOR_STYLE_AUTOMATIC,
  NONE: binding.WINDOW_TITLEBAR_SEPARATOR_STYLE_NONE,
  LINE: binding.WINDOW_TITLEBAR_SEPARATOR_STYLE_LINE,
  SHADOW: binding.WINDOW_TITLEBAR_SEPARATOR_STYLE_SHADOW
}

exports.COLLECTION_BEHAVIOR = {
  DEFAULT: binding.WINDOW_COLLECTION_BEHAVIOR_DEFAULT,
  CAN_JOIN_ALL_SPACES: binding.WINDOW_COLLECTION_BEHAVIOR_CAN_JOIN_ALL_SPACES,
  MOVE_TO_ACTIVE_SPACE: binding.WINDOW_COLLECTION_BEHAVIOR_MOVE_TO_ACTIVE_SPACE,
  MANAGED: binding.WINDOW_COLLECTION_BEHAVIOR_MANAGED,
  TRANSIENT: binding.WINDOW_COLLECTION_BEHAVIOR_TRANSIENT,
  STATIONARY: binding.WINDOW_COLLECTION_BEHAVIOR_STATIONARY,
  PARTICIPATES_IN_CYCLE: binding.WINDOW_COLLECTION_BEHAVIOR_PARTICIPATES_IN_CYCLE,
  IGNORES_CYCLE: binding.WINDOW_COLLECTION_BEHAVIOR_IGNORES_CYCLE,
  FULL_SCREEN_PRIMARY: binding.WINDOW_COLLECTION_BEHAVIOR_FULL_SCREEN_PRIMARY,
  FULL_SCREEN_AUXILIARY: binding.WINDOW_COLLECTION_BEHAVIOR_FULL_SCREEN_AUXILIARY,
  FULL_SCREEN_NONE: binding.WINDOW_COLLECTION_BEHAVIOR_FULL_SCREEN_NONE,
  ALLOWS_TILING: binding.WINDOW_COLLECTION_BEHAVIOR_ALLOWS_TILING,
  DISALLOWS_TILING: binding.WINDOW_COLLECTION_BEHAVIOR_DISALLOWS_TILING
}

exports.ANIMATION_BEHAVIOR = {
  DEFAULT: binding.WINDOW_ANIMATION_BEHAVIOR_DEFAULT,
  NONE: binding.WINDOW_ANIMATION_BEHAVIOR_NONE,
  DOCUMENT_WINDOW: binding.WINDOW_ANIMATION_BEHAVIOR_DOCUMENT_WINDOW,
  UTILITY_WINDOW: binding.WINDOW_ANIMATION_BEHAVIOR_UTILITY_WINDOW,
  ALERT_PANEL: binding.WINDOW_ANIMATION_BEHAVIOR_ALERT_PANEL
}

exports.TABBING_MODE = {
  AUTOMATIC: binding.WINDOW_TABBING_MODE_AUTOMATIC,
  PREFERRED: binding.WINDOW_TABBING_MODE_PREFERRED,
  DISALLOWED: binding.WINDOW_TABBING_MODE_DISALLOWED
}

exports.ORDERING = {
  ABOVE: binding.WINDOW_ORDERING_ABOVE,
  BELOW: binding.WINDOW_ORDERING_BELOW,
  OUT: binding.WINDOW_ORDERING_OUT
}

expose(exports)
