const EventEmitter = require('bare-events')
const binding = require('../binding')
const { adopt, expose } = require('./handle')
const scratch = require('./scratch')
const observe = require('./events')
const retain = require('./retain')
const wrap = require('./wrap')
const AppKitMenu = require('./menu')
const AppKitLayoutAnchor = require('./layout-anchor')
const AppKitAppearance = require('./appearance')
const AppKitUndoManager = require('./undo-manager')

const EVENTS = {
  [binding.VIEW_EVENT_MOUSE_DOWN]: 'mouseDown',
  [binding.VIEW_EVENT_MOUSE_UP]: 'mouseUp',
  [binding.VIEW_EVENT_MOUSE_DRAGGED]: 'mouseDragged',
  [binding.VIEW_EVENT_MOUSE_MOVED]: 'mouseMoved',
  [binding.VIEW_EVENT_RIGHT_MOUSE_DOWN]: 'rightMouseDown',
  [binding.VIEW_EVENT_RIGHT_MOUSE_UP]: 'rightMouseUp',
  [binding.VIEW_EVENT_MOUSE_ENTERED]: 'mouseEntered',
  [binding.VIEW_EVENT_MOUSE_EXITED]: 'mouseExited',
  [binding.VIEW_EVENT_SCROLL_WHEEL]: 'scrollWheel',
  [binding.VIEW_EVENT_KEY_DOWN]: 'keyDown',
  [binding.VIEW_EVENT_KEY_UP]: 'keyUp',
  [binding.VIEW_EVENT_FLAGS_CHANGED]: 'flagsChanged'
}

function holder(tag) {
  const superview = binding.viewSuperview(tag)

  if (superview === null) return null

  return binding.wrapper(superview) || null
}

module.exports = exports = class AppKitView extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._tag = tag === null ? this._init(opts) : tag
    this._retained = new Set()
    this._menu = null

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.viewInit(x, y, width, height, this)
  }

  set flipped(flipped) {
    binding.viewFlipped(this._tag, flipped)
  }

  get acceptsFirstResponder() {
    return binding.viewAcceptsFirstResponder(this._tag)
  }

  set acceptsFirstResponder(acceptsFirstResponder) {
    binding.viewAcceptsFirstResponder(this._tag, acceptsFirstResponder)
  }

  get frame() {
    binding.viewFrameInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1], width: scratch[2], height: scratch[3] }
  }

  set frame(frame) {
    const { x = 0, y = 0, width = 0, height = 0 } = frame

    binding.viewFrame(this._tag, x, y, width, height)
  }

  get bounds() {
    binding.viewBoundsInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1], width: scratch[2], height: scratch[3] }
  }

  set bounds(bounds) {
    const { x = 0, y = 0, width = 0, height = 0 } = bounds

    binding.viewBounds(this._tag, x, y, width, height)
  }

  get hidden() {
    return binding.viewHidden(this._tag)
  }

  set hidden(hidden) {
    binding.viewHidden(this._tag, hidden)
  }

  get hiddenOrHasHiddenAncestor() {
    return binding.viewHiddenOrHasHiddenAncestor(this._tag)
  }

  get alphaValue() {
    return binding.viewAlphaValue(this._tag)
  }

  set alphaValue(alphaValue) {
    binding.viewAlphaValue(this._tag, alphaValue)
  }

  get toolTip() {
    return binding.viewToolTip(this._tag)
  }

  set toolTip(toolTip) {
    binding.viewToolTip(this._tag, toolTip)
  }

  get autoresizingMask() {
    return binding.viewAutoresizingMask(this._tag)
  }

  set autoresizingMask(autoresizingMask) {
    binding.viewAutoresizingMask(this._tag, autoresizingMask)
  }

  get autoresizesSubviews() {
    return binding.viewAutoresizesSubviews(this._tag)
  }

  set autoresizesSubviews(autoresizesSubviews) {
    binding.viewAutoresizesSubviews(this._tag, autoresizesSubviews)
  }

  get translatesAutoresizingMaskIntoConstraints() {
    return binding.viewTranslatesAutoresizingMaskIntoConstraints(this._tag)
  }

  set translatesAutoresizingMaskIntoConstraints(translates) {
    binding.viewTranslatesAutoresizingMaskIntoConstraints(this._tag, translates)
  }

  get wantsLayer() {
    return binding.viewWantsLayer(this._tag)
  }

  set wantsLayer(wantsLayer) {
    binding.viewWantsLayer(this._tag, wantsLayer)
  }

  get needsDisplay() {
    return binding.viewNeedsDisplay(this._tag)
  }

  set needsDisplay(needsDisplay) {
    binding.viewNeedsDisplay(this._tag, needsDisplay)
  }

  get needsLayout() {
    return binding.viewNeedsLayout(this._tag)
  }

  set needsLayout(needsLayout) {
    binding.viewNeedsLayout(this._tag, needsLayout)
  }

  get fittingSize() {
    return binding.viewFittingSize(this._tag)
  }

  get intrinsicContentSize() {
    return binding.viewIntrinsicContentSize(this._tag)
  }

  get safeAreaInsets() {
    binding.viewSafeAreaInsetsInto(this._tag, scratch.buffer, 0)

    return { top: scratch[0], left: scratch[1], bottom: scratch[2], right: scratch[3] }
  }

  get superview() {
    return wrap(AppKitView, binding.viewSuperview(this._tag))
  }

  get subviews() {
    return binding.viewSubviews(this._tag).map((tag) => wrap(AppKitView, tag))
  }

  // Holding the wrapper is what keeps its listeners and any other JS state on
  // it alive; the native object is retained by its superview either way. Only
  // one of our views should be doing that, so the previous one lets go.
  // AppKit detaches the native view itself.
  _attach(view) {
    const tag = adopt(view)
    const superview = holder(tag)

    if (superview !== null) superview._retained.delete(view)

    this._retained.add(view)

    return tag
  }

  addSubview(view, ordering, relativeTo) {
    const tag = this._attach(view)

    if (ordering === undefined) {
      binding.viewAddSubview(this._tag, tag)
    } else {
      binding.viewAddSubview(this._tag, tag, ordering, relativeTo ? adopt(relativeTo) : null)
    }

    return this
  }

  removeFromSuperview() {
    const superview = holder(this._tag)

    if (superview !== null) superview._retained.delete(this)

    binding.viewRemoveFromSuperview(this._tag)

    return this
  }

  display() {
    binding.viewDisplay(this._tag)
    return this
  }

  layout() {
    binding.viewLayout(this._tag)
    return this
  }

  get topAnchor() {
    return wrap(AppKitLayoutAnchor, binding.viewTopAnchor(this._tag))
  }

  get bottomAnchor() {
    return wrap(AppKitLayoutAnchor, binding.viewBottomAnchor(this._tag))
  }

  get leadingAnchor() {
    return wrap(AppKitLayoutAnchor, binding.viewLeadingAnchor(this._tag))
  }

  get trailingAnchor() {
    return wrap(AppKitLayoutAnchor, binding.viewTrailingAnchor(this._tag))
  }

  get leftAnchor() {
    return wrap(AppKitLayoutAnchor, binding.viewLeftAnchor(this._tag))
  }

  get rightAnchor() {
    return wrap(AppKitLayoutAnchor, binding.viewRightAnchor(this._tag))
  }

  get widthAnchor() {
    return wrap(AppKitLayoutAnchor, binding.viewWidthAnchor(this._tag))
  }

  get heightAnchor() {
    return wrap(AppKitLayoutAnchor, binding.viewHeightAnchor(this._tag))
  }

  get centerXAnchor() {
    return wrap(AppKitLayoutAnchor, binding.viewCenterXAnchor(this._tag))
  }

  get centerYAnchor() {
    return wrap(AppKitLayoutAnchor, binding.viewCenterYAnchor(this._tag))
  }

  get firstBaselineAnchor() {
    return wrap(AppKitLayoutAnchor, binding.viewFirstBaselineAnchor(this._tag))
  }

  get lastBaselineAnchor() {
    return wrap(AppKitLayoutAnchor, binding.viewLastBaselineAnchor(this._tag))
  }

  get appearance() {
    return wrap(AppKitAppearance, binding.viewAppearance(this._tag))
  }

  set appearance(appearance) {
    binding.viewAppearance(this._tag, appearance === null ? null : appearance._tag)
  }

  get effectiveAppearance() {
    return wrap(AppKitAppearance, binding.viewEffectiveAppearance(this._tag))
  }

  get needsUpdateConstraints() {
    return binding.viewNeedsUpdateConstraints(this._tag)
  }

  set needsUpdateConstraints(needsUpdateConstraints) {
    binding.viewNeedsUpdateConstraints(this._tag, needsUpdateConstraints)
  }

  setContentHuggingPriority(priority, orientation) {
    binding.viewSetContentHuggingPriority(this._tag, priority, orientation)
    return this
  }

  setContentCompressionResistancePriority(priority, orientation) {
    binding.viewSetContentCompressionResistancePriority(this._tag, priority, orientation)
    return this
  }

  get undoManager() {
    return wrap(AppKitUndoManager, binding.viewUndoManager(this._tag))
  }

  layoutSubtreeIfNeeded() {
    binding.viewLayoutSubtreeIfNeeded(this._tag)
    return this
  }

  addTrackingArea(area) {
    binding.viewAddTrackingArea(this._tag, area._tag)
    return this
  }

  removeTrackingArea(area) {
    binding.viewRemoveTrackingArea(this._tag, area._tag)
    return this
  }

  get menu() {
    return retain(this, '_menu', AppKitMenu, binding.viewMenu(this._tag))
  }

  set menu(menu) {
    binding.viewMenu(this._tag, adopt(menu))
    this._menu = menu
  }

  get visibleRect() {
    binding.viewVisibleRectInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1], width: scratch[2], height: scratch[3] }
  }

  get clipsToBounds() {
    return binding.viewClipsToBounds(this._tag)
  }

  set clipsToBounds(clipsToBounds) {
    binding.viewClipsToBounds(this._tag, clipsToBounds)
  }

  get canDrawSubviewsIntoLayer() {
    return binding.viewCanDrawSubviewsIntoLayer(this._tag)
  }

  set canDrawSubviewsIntoLayer(canDrawSubviewsIntoLayer) {
    binding.viewCanDrawSubviewsIntoLayer(this._tag, canDrawSubviewsIntoLayer)
  }

  get layerContentsRedrawPolicy() {
    return binding.viewLayerContentsRedrawPolicy(this._tag)
  }

  set layerContentsRedrawPolicy(layerContentsRedrawPolicy) {
    binding.viewLayerContentsRedrawPolicy(this._tag, layerContentsRedrawPolicy)
  }

  get focusRingType() {
    return binding.viewFocusRingType(this._tag)
  }

  set focusRingType(focusRingType) {
    binding.viewFocusRingType(this._tag, focusRingType)
  }

  get opaque() {
    return binding.viewOpaque(this._tag)
  }

  get allowsVibrancy() {
    return binding.viewAllowsVibrancy(this._tag)
  }

  get rotatedFromBase() {
    return binding.viewRotatedFromBase(this._tag)
  }

  get flipped() {
    return binding.viewFlipped(this._tag)
  }

  get inLiveResize() {
    return binding.viewInLiveResize(this._tag)
  }

  get canBecomeKeyView() {
    return binding.viewCanBecomeKeyView(this._tag)
  }

  get userInterfaceLayoutDirection() {
    return binding.viewUserInterfaceLayoutDirection(this._tag)
  }

  set userInterfaceLayoutDirection(userInterfaceLayoutDirection) {
    binding.viewUserInterfaceLayoutDirection(this._tag, userInterfaceLayoutDirection)
  }

  get nextKeyView() {
    return wrap(AppKitView, binding.viewNextKeyView(this._tag))
  }

  set nextKeyView(nextKeyView) {
    binding.viewNextKeyView(this._tag, nextKeyView === null ? null : nextKeyView._tag)
  }

  get window() {
    // Required here rather than at the top: both subclass this class.
    const AppKitWindow = require('./window')

    return wrap(AppKitWindow, binding.viewWindow(this._tag))
  }

  get enclosingScrollView() {
    const AppKitScrollView = require('./scroll-view')

    return wrap(AppKitScrollView, binding.viewEnclosingScrollView(this._tag))
  }

  convertPointFromView(x, y, view) {
    return binding.viewConvertPointFromView(this._tag, x, y, view._tag)
  }

  convertPointToView(x, y, view) {
    return binding.viewConvertPointToView(this._tag, x, y, view._tag)
  }

  hitTest(x, y) {
    return wrap(AppKitView, binding.viewHitTest(this._tag, x, y))
  }

  setNeedsDisplayInRect(x, y, width, height) {
    binding.viewSetNeedsDisplayInRect(this._tag, x, y, width, height)
    return this
  }

  scrollPointToVisible(x, y) {
    binding.viewScrollPointToVisible(this._tag, x, y)
    return this
  }

  _onwilldraw() {
    this.emit('willDraw')
  }

  // One native callback carries every kind of input; the payload is
  // positional and its meaning depends on the type.
  _onevent(type, x, y, a, b, modifiers, characters) {
    const name = EVENTS[type]

    if (name === undefined) return

    if (type === binding.VIEW_EVENT_SCROLL_WHEEL) {
      this.emit(name, { x, y, deltaX: a, deltaY: b, modifiers })
    } else if (type === binding.VIEW_EVENT_KEY_DOWN || type === binding.VIEW_EVENT_KEY_UP) {
      this.emit(name, { keyCode: a, repeat: b === 1, modifiers, characters })
    } else if (type === binding.VIEW_EVENT_FLAGS_CHANGED) {
      this.emit(name, { modifiers })
    } else {
      this.emit(name, { x, y, button: a, clickCount: b, modifiers })
    }
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitView }
    }
  }
}

exports.AUTORESIZING = {
  NONE: binding.VIEW_AUTORESIZING_NONE,
  MIN_X_MARGIN: binding.VIEW_AUTORESIZING_MIN_X_MARGIN,
  WIDTH_SIZABLE: binding.VIEW_AUTORESIZING_WIDTH_SIZABLE,
  MAX_X_MARGIN: binding.VIEW_AUTORESIZING_MAX_X_MARGIN,
  MIN_Y_MARGIN: binding.VIEW_AUTORESIZING_MIN_Y_MARGIN,
  HEIGHT_SIZABLE: binding.VIEW_AUTORESIZING_HEIGHT_SIZABLE,
  MAX_Y_MARGIN: binding.VIEW_AUTORESIZING_MAX_Y_MARGIN
}

exports.ORDERING = {
  ABOVE: binding.VIEW_ORDERING_ABOVE,
  BELOW: binding.VIEW_ORDERING_BELOW
}

// The same bits the map above reads, by the name a listener uses. Both come
// from the binding rather than being written out twice.
exports._events = {}

for (const bit in EVENTS) exports._events[EVENTS[bit]] = Number(bit)

// Drawing is not input, so it arrives on a callback of its own rather than
// through the one above, and its bit is added here.
exports._events.willDraw = binding.VIEW_EVENT_WILL_DRAW

exports.FOCUS_RING_TYPE = {
  DEFAULT: binding.VIEW_FOCUS_RING_TYPE_DEFAULT,
  NONE: binding.VIEW_FOCUS_RING_TYPE_NONE,
  EXTERIOR: binding.VIEW_FOCUS_RING_TYPE_EXTERIOR
}

expose(exports)
