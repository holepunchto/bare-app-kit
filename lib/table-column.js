const binding = require('../binding')
const { expose } = require('./handle')
const observe = require('./events')
const EventEmitter = require('bare-events')

module.exports = exports = class AppKitTableColumn extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init(opts) {
    const { identifier = '' } = opts

    return binding.tableColumnInit(identifier)
  }

  get identifier() {
    return binding.tableColumnIdentifier(this._tag)
  }

  get title() {
    return binding.tableColumnTitle(this._tag)
  }

  set title(title) {
    binding.tableColumnTitle(this._tag, title)
  }

  get width() {
    return binding.tableColumnWidth(this._tag)
  }

  set width(width) {
    binding.tableColumnWidth(this._tag, width)
  }

  get minWidth() {
    return binding.tableColumnMinWidth(this._tag)
  }

  set minWidth(minWidth) {
    binding.tableColumnMinWidth(this._tag, minWidth)
  }

  get maxWidth() {
    return binding.tableColumnMaxWidth(this._tag)
  }

  set maxWidth(maxWidth) {
    binding.tableColumnMaxWidth(this._tag, maxWidth)
  }

  get resizingMask() {
    return binding.tableColumnResizingMask(this._tag)
  }

  set resizingMask(resizingMask) {
    binding.tableColumnResizingMask(this._tag, resizingMask)
  }

  get editable() {
    return binding.tableColumnEditable(this._tag)
  }

  set editable(editable) {
    binding.tableColumnEditable(this._tag, editable)
  }

  get hidden() {
    return binding.tableColumnHidden(this._tag)
  }

  set hidden(hidden) {
    binding.tableColumnHidden(this._tag, hidden)
  }

  sizeToFit() {
    binding.tableColumnSizeToFit(this._tag)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTableColumn }
    }
  }
}

exports.RESIZING = {
  NONE: binding.TABLE_COLUMN_RESIZING_NONE,
  AUTORESIZING: binding.TABLE_COLUMN_RESIZING_AUTORESIZING,
  USER_RESIZING: binding.TABLE_COLUMN_RESIZING_USER_RESIZING
}

expose(exports)
