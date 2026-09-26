const binding = require('../binding')
const { adopt } = require('./handle')
const observe = require('./events')
const retain = require('./retain')
const EventEmitter = require('bare-events')
const AppKitView = require('./view')
const AppKitImageView = require('./image-view')
const AppKitTextField = require('./text-field')

module.exports = exports = class AppKitCollectionViewItem extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._view = null
    this._imageView = null
    this._textField = null

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init() {
    return binding.collectionViewItemInit()
  }

  get view() {
    return retain(this, '_view', AppKitView, binding.collectionViewItemView(this._tag))
  }

  set view(view) {
    binding.collectionViewItemView(this._tag, adopt(view))

    this._view = view
  }

  get selected() {
    return binding.collectionViewItemSelected(this._tag)
  }

  set selected(selected) {
    binding.collectionViewItemSelected(this._tag, selected)
  }

  get highlightState() {
    return binding.collectionViewItemHighlightState(this._tag)
  }

  set highlightState(highlightState) {
    binding.collectionViewItemHighlightState(this._tag, highlightState)
  }

  get imageView() {
    return retain(
      this,
      '_imageView',
      AppKitImageView,
      binding.collectionViewItemImageView(this._tag)
    )
  }

  set imageView(imageView) {
    binding.collectionViewItemImageView(this._tag, adopt(imageView))

    this._imageView = imageView
  }

  get textField() {
    return retain(
      this,
      '_textField',
      AppKitTextField,
      binding.collectionViewItemTextField(this._tag)
    )
  }

  set textField(textField) {
    binding.collectionViewItemTextField(this._tag, adopt(textField))

    this._textField = textField
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitCollectionViewItem }
    }
  }
}

exports.HIGHLIGHT = {
  NONE: binding.COLLECTION_VIEW_ITEM_HIGHLIGHT_NONE,
  FOR_SELECTION: binding.COLLECTION_VIEW_ITEM_HIGHLIGHT_FOR_SELECTION,
  FOR_DESELECTION: binding.COLLECTION_VIEW_ITEM_HIGHLIGHT_FOR_DESELECTION,
  AS_DROP_TARGET: binding.COLLECTION_VIEW_ITEM_HIGHLIGHT_AS_DROP_TARGET
}
