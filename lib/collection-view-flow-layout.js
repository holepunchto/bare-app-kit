const binding = require('../binding')
const scratch = require('./scratch')
const observe = require('./events')
const EventEmitter = require('bare-events')

module.exports = exports = class AppKitCollectionViewFlowLayout extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init() {
    return binding.collectionViewFlowLayoutInit()
  }

  get itemSize() {
    binding.collectionViewFlowLayoutItemSizeInto(this._tag, scratch.buffer, 0)

    return { width: scratch[0], height: scratch[1] }
  }

  set itemSize(itemSize) {
    const { width = 0, height = 0 } = itemSize

    binding.collectionViewFlowLayoutItemSize(this._tag, width, height)
  }

  get estimatedItemSize() {
    binding.collectionViewFlowLayoutEstimatedItemSizeInto(this._tag, scratch.buffer, 0)

    return { width: scratch[0], height: scratch[1] }
  }

  set estimatedItemSize(estimatedItemSize) {
    const { width = 0, height = 0 } = estimatedItemSize

    binding.collectionViewFlowLayoutEstimatedItemSize(this._tag, width, height)
  }

  get minimumLineSpacing() {
    return binding.collectionViewFlowLayoutMinimumLineSpacing(this._tag)
  }

  set minimumLineSpacing(minimumLineSpacing) {
    binding.collectionViewFlowLayoutMinimumLineSpacing(this._tag, minimumLineSpacing)
  }

  get minimumInteritemSpacing() {
    return binding.collectionViewFlowLayoutMinimumInteritemSpacing(this._tag)
  }

  set minimumInteritemSpacing(minimumInteritemSpacing) {
    binding.collectionViewFlowLayoutMinimumInteritemSpacing(this._tag, minimumInteritemSpacing)
  }

  get sectionInset() {
    binding.collectionViewFlowLayoutSectionInsetInto(this._tag, scratch.buffer, 0)

    return { top: scratch[0], left: scratch[1], bottom: scratch[2], right: scratch[3] }
  }

  set sectionInset(sectionInset) {
    const { top = 0, left = 0, bottom = 0, right = 0 } = sectionInset

    binding.collectionViewFlowLayoutSectionInset(this._tag, top, left, bottom, right)
  }

  get scrollDirection() {
    return binding.collectionViewFlowLayoutScrollDirection(this._tag)
  }

  set scrollDirection(scrollDirection) {
    binding.collectionViewFlowLayoutScrollDirection(this._tag, scrollDirection)
  }

  get headerReferenceSize() {
    binding.collectionViewFlowLayoutHeaderReferenceSizeInto(this._tag, scratch.buffer, 0)

    return { width: scratch[0], height: scratch[1] }
  }

  set headerReferenceSize(headerReferenceSize) {
    const { width = 0, height = 0 } = headerReferenceSize

    binding.collectionViewFlowLayoutHeaderReferenceSize(this._tag, width, height)
  }

  get footerReferenceSize() {
    binding.collectionViewFlowLayoutFooterReferenceSizeInto(this._tag, scratch.buffer, 0)

    return { width: scratch[0], height: scratch[1] }
  }

  set footerReferenceSize(footerReferenceSize) {
    const { width = 0, height = 0 } = footerReferenceSize

    binding.collectionViewFlowLayoutFooterReferenceSize(this._tag, width, height)
  }

  get sectionHeadersPinToVisibleBounds() {
    return binding.collectionViewFlowLayoutSectionHeadersPinToVisibleBounds(this._tag)
  }

  set sectionHeadersPinToVisibleBounds(sectionHeadersPinToVisibleBounds) {
    binding.collectionViewFlowLayoutSectionHeadersPinToVisibleBounds(
      this._tag,
      sectionHeadersPinToVisibleBounds
    )
  }

  get sectionFootersPinToVisibleBounds() {
    return binding.collectionViewFlowLayoutSectionFootersPinToVisibleBounds(this._tag)
  }

  set sectionFootersPinToVisibleBounds(sectionFootersPinToVisibleBounds) {
    binding.collectionViewFlowLayoutSectionFootersPinToVisibleBounds(
      this._tag,
      sectionFootersPinToVisibleBounds
    )
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitCollectionViewFlowLayout }
    }
  }
}

exports.SCROLL_DIRECTION = {
  VERTICAL: binding.COLLECTION_VIEW_SCROLL_DIRECTION_VERTICAL,
  HORIZONTAL: binding.COLLECTION_VIEW_SCROLL_DIRECTION_HORIZONTAL
}
