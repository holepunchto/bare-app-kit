const binding = require('../binding')
const { adopt, expose } = require('./handle')
const scratch = require('./scratch')
const observe = require('./events')
const wrap = require('./wrap')
const EventEmitter = require('bare-events')

module.exports = exports = class AppKitBezierPath extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init() {
    return binding.bezierPathInit()
  }

  static withRect(x, y, width, height) {
    return wrap(AppKitBezierPath, binding.bezierPathWithRect(x, y, width, height))
  }

  static withOval(x, y, width, height) {
    return wrap(AppKitBezierPath, binding.bezierPathWithOval(x, y, width, height))
  }

  static withRoundedRect(x, y, width, height, rx, ry) {
    return wrap(AppKitBezierPath, binding.bezierPathWithRoundedRect(x, y, width, height, rx, ry))
  }

  get lineWidth() {
    return binding.bezierPathLineWidth(this._tag)
  }

  set lineWidth(lineWidth) {
    binding.bezierPathLineWidth(this._tag, lineWidth)
  }

  get lineCapStyle() {
    return binding.bezierPathLineCapStyle(this._tag)
  }

  set lineCapStyle(lineCapStyle) {
    binding.bezierPathLineCapStyle(this._tag, lineCapStyle)
  }

  get lineJoinStyle() {
    return binding.bezierPathLineJoinStyle(this._tag)
  }

  set lineJoinStyle(lineJoinStyle) {
    binding.bezierPathLineJoinStyle(this._tag, lineJoinStyle)
  }

  get windingRule() {
    return binding.bezierPathWindingRule(this._tag)
  }

  set windingRule(windingRule) {
    binding.bezierPathWindingRule(this._tag, windingRule)
  }

  get miterLimit() {
    return binding.bezierPathMiterLimit(this._tag)
  }

  set miterLimit(miterLimit) {
    binding.bezierPathMiterLimit(this._tag, miterLimit)
  }

  get flatness() {
    return binding.bezierPathFlatness(this._tag)
  }

  set flatness(flatness) {
    binding.bezierPathFlatness(this._tag, flatness)
  }

  get empty() {
    return binding.bezierPathEmpty(this._tag)
  }

  get elementCount() {
    return binding.bezierPathElementCount(this._tag)
  }

  get bounds() {
    binding.bezierPathBoundsInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1], width: scratch[2], height: scratch[3] }
  }

  get controlPointBounds() {
    binding.bezierPathControlPointBoundsInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1], width: scratch[2], height: scratch[3] }
  }

  get currentPoint() {
    binding.bezierPathCurrentPointInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1] }
  }

  moveTo(x, y) {
    binding.bezierPathMoveTo(this._tag, x, y)
    return this
  }

  lineTo(x, y) {
    binding.bezierPathLineTo(this._tag, x, y)
    return this
  }

  curveTo(x, y, x1, y1, x2, y2) {
    binding.bezierPathCurveTo(this._tag, x, y, x1, y1, x2, y2)
    return this
  }

  closePath() {
    binding.bezierPathClosePath(this._tag)
    return this
  }

  removeAllPoints() {
    binding.bezierPathRemoveAllPoints(this._tag)
    return this
  }

  appendRect(x, y, width, height) {
    binding.bezierPathAppendRect(this._tag, x, y, width, height)
    return this
  }

  appendOval(x, y, width, height) {
    binding.bezierPathAppendOval(this._tag, x, y, width, height)
    return this
  }

  append(other) {
    binding.bezierPathAppend(this._tag, adopt(other))
    return this
  }

  stroke() {
    binding.bezierPathStroke(this._tag)
    return this
  }

  fill() {
    binding.bezierPathFill(this._tag)
    return this
  }

  addClip() {
    binding.bezierPathAddClip(this._tag)
    return this
  }

  setClip() {
    binding.bezierPathSetClip(this._tag)
    return this
  }

  containsPoint(x, y) {
    return binding.bezierPathContainsPoint(this._tag, x, y)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitBezierPath }
    }
  }
}

exports.LINE_CAP = {
  BUTT: binding.BEZIER_PATH_LINE_CAP_BUTT,
  ROUND: binding.BEZIER_PATH_LINE_CAP_ROUND,
  SQUARE: binding.BEZIER_PATH_LINE_CAP_SQUARE
}

exports.LINE_JOIN = {
  MITER: binding.BEZIER_PATH_LINE_JOIN_MITER,
  ROUND: binding.BEZIER_PATH_LINE_JOIN_ROUND,
  BEVEL: binding.BEZIER_PATH_LINE_JOIN_BEVEL
}

exports.WINDING = {
  NON_ZERO: binding.BEZIER_PATH_WINDING_NON_ZERO,
  EVEN_ODD: binding.BEZIER_PATH_WINDING_EVEN_ODD
}

expose(exports)
