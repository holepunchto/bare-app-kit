const binding = require('../binding')
const scratch = require('./scratch')
const wrap = require('./wrap')

module.exports = exports = class AppKitImage {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  static withContentsOfFile(path) {
    return wrap(AppKitImage, binding.imageWithContentsOfFile(path))
  }

  static named(name) {
    return wrap(AppKitImage, binding.imageNamed(name))
  }

  static withSystemSymbolName(name, description = null) {
    return wrap(AppKitImage, binding.imageWithSystemSymbolName(name, description))
  }

  static withSize(width, height) {
    return wrap(AppKitImage, binding.imageWithSize(width, height))
  }

  get size() {
    binding.imageSizeInto(this._tag, scratch.buffer, 0)

    return { width: scratch[0], height: scratch[1] }
  }

  set size(size) {
    const { width = 0, height = 0 } = size

    binding.imageSize(this._tag, width, height)
  }

  get template() {
    return binding.imageTemplate(this._tag)
  }

  set template(template) {
    binding.imageTemplate(this._tag, template)
  }

  get name() {
    return binding.imageName(this._tag)
  }

  get valid() {
    return binding.imageValid(this._tag)
  }

  get cacheMode() {
    return binding.imageCacheMode(this._tag)
  }

  set cacheMode(cacheMode) {
    binding.imageCacheMode(this._tag, cacheMode)
  }

  get resizingMode() {
    return binding.imageResizingMode(this._tag)
  }

  set resizingMode(resizingMode) {
    binding.imageResizingMode(this._tag, resizingMode)
  }

  get alignmentRect() {
    binding.imageAlignmentRectInto(this._tag, scratch.buffer, 0)

    return { x: scratch[0], y: scratch[1], width: scratch[2], height: scratch[3] }
  }

  set alignmentRect(alignmentRect) {
    const { x = 0, y = 0, width = 0, height = 0 } = alignmentRect

    binding.imageAlignmentRect(this._tag, x, y, width, height)
  }

  get matchesOnMultipleResolution() {
    return binding.imageMatchesOnMultipleResolution(this._tag)
  }

  set matchesOnMultipleResolution(matchesOnMultipleResolution) {
    binding.imageMatchesOnMultipleResolution(this._tag, matchesOnMultipleResolution)
  }

  get prefersColorMatch() {
    return binding.imagePrefersColorMatch(this._tag)
  }

  set prefersColorMatch(prefersColorMatch) {
    binding.imagePrefersColorMatch(this._tag, prefersColorMatch)
  }

  lockFocus() {
    binding.imageLockFocus(this._tag)
    return this
  }

  unlockFocus() {
    binding.imageUnlockFocus(this._tag)
    return this
  }

  drawInRect(x, y, width, height) {
    binding.imageDrawInRect(this._tag, x, y, width, height)
    return this
  }

  drawAtPoint(x, y) {
    binding.imageDrawAtPoint(this._tag, x, y)
    return this
  }

  tiffRepresentation() {
    return binding.imageTiffRepresentation(this._tag)
  }

  recommendedLayerContentsScale(scale) {
    return binding.imageRecommendedLayerContentsScale(this._tag, scale)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitImage }
    }
  }
}
