const binding = require('../binding')
const { adopt, expose } = require('./handle')
const scratch = require('./scratch')
const retain = require('./retain')
const wrap = require('./wrap')
const AppKitView = require('./view')
const AppKitClipView = require('./clip-view')
const AppKitColor = require('./color')

module.exports = exports = class AppKitScrollView extends AppKitView {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    this._documentView = null
    this._contentView = null

    return binding.scrollViewInit(x, y, width, height, this)
  }

  // The clip view a scroll view makes for itself is a plain one, which has
  // nothing to report with. A caller wanting to hear about scrolling puts one
  // of ours here.
  get contentView() {
    return retain(this, '_contentView', AppKitClipView, binding.scrollViewContentView(this._tag))
  }

  set contentView(contentView) {
    binding.scrollViewContentView(this._tag, adopt(contentView))

    this._contentView = contentView
  }

  reflectScrolledClipView(clipView) {
    binding.scrollViewReflectScrolledClipView(this._tag, adopt(clipView))

    return this
  }

  get documentView() {
    return retain(this, '_documentView', AppKitView, binding.scrollViewDocumentView(this._tag))
  }

  set documentView(documentView) {
    binding.scrollViewDocumentView(this._tag, adopt(documentView))

    this._documentView = documentView
  }

  get hasVerticalScroller() {
    return binding.scrollViewHasVerticalScroller(this._tag)
  }

  set hasVerticalScroller(hasVerticalScroller) {
    binding.scrollViewHasVerticalScroller(this._tag, hasVerticalScroller)
  }

  get hasHorizontalScroller() {
    return binding.scrollViewHasHorizontalScroller(this._tag)
  }

  set hasHorizontalScroller(hasHorizontalScroller) {
    binding.scrollViewHasHorizontalScroller(this._tag, hasHorizontalScroller)
  }

  get autohidesScrollers() {
    return binding.scrollViewAutohidesScrollers(this._tag)
  }

  set autohidesScrollers(autohidesScrollers) {
    binding.scrollViewAutohidesScrollers(this._tag, autohidesScrollers)
  }

  get borderType() {
    return binding.scrollViewBorderType(this._tag)
  }

  set borderType(borderType) {
    binding.scrollViewBorderType(this._tag, borderType)
  }

  get scrollerStyle() {
    return binding.scrollViewScrollerStyle(this._tag)
  }

  set scrollerStyle(scrollerStyle) {
    binding.scrollViewScrollerStyle(this._tag, scrollerStyle)
  }

  get drawsBackground() {
    return binding.scrollViewDrawsBackground(this._tag)
  }

  set drawsBackground(drawsBackground) {
    binding.scrollViewDrawsBackground(this._tag, drawsBackground)
  }

  get backgroundColor() {
    return wrap(AppKitColor, binding.scrollViewBackgroundColor(this._tag))
  }

  set backgroundColor(backgroundColor) {
    binding.scrollViewBackgroundColor(this._tag, adopt(backgroundColor))
  }

  get allowsMagnification() {
    return binding.scrollViewAllowsMagnification(this._tag)
  }

  set allowsMagnification(allowsMagnification) {
    binding.scrollViewAllowsMagnification(this._tag, allowsMagnification)
  }

  get magnification() {
    return binding.scrollViewMagnification(this._tag)
  }

  set magnification(magnification) {
    binding.scrollViewMagnification(this._tag, magnification)
  }

  get horizontalScrollElasticity() {
    return binding.scrollViewHorizontalScrollElasticity(this._tag)
  }

  set horizontalScrollElasticity(horizontalScrollElasticity) {
    binding.scrollViewHorizontalScrollElasticity(this._tag, horizontalScrollElasticity)
  }

  get verticalScrollElasticity() {
    return binding.scrollViewVerticalScrollElasticity(this._tag)
  }

  set verticalScrollElasticity(verticalScrollElasticity) {
    binding.scrollViewVerticalScrollElasticity(this._tag, verticalScrollElasticity)
  }

  get contentSize() {
    binding.scrollViewContentSizeInto(this._tag, scratch.buffer, 0)

    return { width: scratch[0], height: scratch[1] }
  }

  get documentVisibleRect() {
    binding.scrollViewDocumentVisibleRectInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1], width: scratch[2], height: scratch[3] }
  }

  get rulersVisible() {
    return binding.scrollViewRulersVisible(this._tag)
  }

  set rulersVisible(rulersVisible) {
    binding.scrollViewRulersVisible(this._tag, rulersVisible)
  }

  get hasHorizontalRuler() {
    return binding.scrollViewHasHorizontalRuler(this._tag)
  }

  set hasHorizontalRuler(hasHorizontalRuler) {
    binding.scrollViewHasHorizontalRuler(this._tag, hasHorizontalRuler)
  }

  get hasVerticalRuler() {
    return binding.scrollViewHasVerticalRuler(this._tag)
  }

  set hasVerticalRuler(hasVerticalRuler) {
    binding.scrollViewHasVerticalRuler(this._tag, hasVerticalRuler)
  }

  get scrollsDynamically() {
    return binding.scrollViewScrollsDynamically(this._tag)
  }

  set scrollsDynamically(scrollsDynamically) {
    binding.scrollViewScrollsDynamically(this._tag, scrollsDynamically)
  }

  get lineScroll() {
    return binding.scrollViewLineScroll(this._tag)
  }

  set lineScroll(lineScroll) {
    binding.scrollViewLineScroll(this._tag, lineScroll)
  }

  get pageScroll() {
    return binding.scrollViewPageScroll(this._tag)
  }

  set pageScroll(pageScroll) {
    binding.scrollViewPageScroll(this._tag, pageScroll)
  }

  get horizontalLineScroll() {
    return binding.scrollViewHorizontalLineScroll(this._tag)
  }

  set horizontalLineScroll(horizontalLineScroll) {
    binding.scrollViewHorizontalLineScroll(this._tag, horizontalLineScroll)
  }

  get verticalLineScroll() {
    return binding.scrollViewVerticalLineScroll(this._tag)
  }

  set verticalLineScroll(verticalLineScroll) {
    binding.scrollViewVerticalLineScroll(this._tag, verticalLineScroll)
  }

  get horizontalPageScroll() {
    return binding.scrollViewHorizontalPageScroll(this._tag)
  }

  set horizontalPageScroll(horizontalPageScroll) {
    binding.scrollViewHorizontalPageScroll(this._tag, horizontalPageScroll)
  }

  get verticalPageScroll() {
    return binding.scrollViewVerticalPageScroll(this._tag)
  }

  set verticalPageScroll(verticalPageScroll) {
    binding.scrollViewVerticalPageScroll(this._tag, verticalPageScroll)
  }

  get automaticallyAdjustsContentInsets() {
    return binding.scrollViewAutomaticallyAdjustsContentInsets(this._tag)
  }

  set automaticallyAdjustsContentInsets(automaticallyAdjustsContentInsets) {
    binding.scrollViewAutomaticallyAdjustsContentInsets(
      this._tag,
      automaticallyAdjustsContentInsets
    )
  }

  get contentInsets() {
    binding.scrollViewContentInsetsInto(this._tag, scratch.buffer, 0)

    return { top: scratch[0], left: scratch[1], bottom: scratch[2], right: scratch[3] }
  }

  set contentInsets(contentInsets) {
    const { top = 0, left = 0, bottom = 0, right = 0 } = contentInsets

    binding.scrollViewContentInsets(this._tag, top, left, bottom, right)
  }

  get scrollerInsets() {
    binding.scrollViewScrollerInsetsInto(this._tag, scratch.buffer, 0)

    return { top: scratch[0], left: scratch[1], bottom: scratch[2], right: scratch[3] }
  }

  set scrollerInsets(scrollerInsets) {
    const { top = 0, left = 0, bottom = 0, right = 0 } = scrollerInsets

    binding.scrollViewScrollerInsets(this._tag, top, left, bottom, right)
  }

  get findBarPosition() {
    return binding.scrollViewFindBarPosition(this._tag)
  }

  set findBarPosition(findBarPosition) {
    binding.scrollViewFindBarPosition(this._tag, findBarPosition)
  }

  get minMagnification() {
    return binding.scrollViewMinMagnification(this._tag)
  }

  set minMagnification(minMagnification) {
    binding.scrollViewMinMagnification(this._tag, minMagnification)
  }

  get maxMagnification() {
    return binding.scrollViewMaxMagnification(this._tag)
  }

  set maxMagnification(maxMagnification) {
    binding.scrollViewMaxMagnification(this._tag, maxMagnification)
  }

  flashScrollers() {
    binding.scrollViewFlashScrollers(this._tag)
    return this
  }

  _onwilldraw() {
    this.emit('willDraw')
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitScrollView }
    }
  }
}

exports.BORDER_TYPE = {
  NONE: binding.SCROLL_VIEW_BORDER_TYPE_NONE,
  LINE: binding.SCROLL_VIEW_BORDER_TYPE_LINE,
  BEZEL: binding.SCROLL_VIEW_BORDER_TYPE_BEZEL,
  GROOVE: binding.SCROLL_VIEW_BORDER_TYPE_GROOVE
}

exports.SCROLLER_STYLE = {
  LEGACY: binding.SCROLL_VIEW_SCROLLER_STYLE_LEGACY,
  OVERLAY: binding.SCROLL_VIEW_SCROLLER_STYLE_OVERLAY
}

exports.ELASTICITY = {
  AUTOMATIC: binding.SCROLL_VIEW_ELASTICITY_AUTOMATIC,
  NONE: binding.SCROLL_VIEW_ELASTICITY_NONE,
  ALLOWED: binding.SCROLL_VIEW_ELASTICITY_ALLOWED
}

exports._events = {
  willDraw: 1
}

expose(exports)
