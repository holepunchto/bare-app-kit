const binding = require('../binding')
const registry = require('bare-foundation-registry')
const wrap = require('./wrap')

module.exports = exports = class AppKitPasteboard {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  get [registry.tag]() {
    return this._tag
  }

  get [registry.handle]() {
    return binding.handle(this._tag)
  }

  static general() {
    return wrap(AppKitPasteboard, binding.pasteboardGeneral())
  }

  static withName(name) {
    return wrap(AppKitPasteboard, binding.pasteboardWithName(name))
  }

  static withUniqueName() {
    return wrap(AppKitPasteboard, binding.pasteboardWithUniqueName())
  }

  get name() {
    return binding.pasteboardName(this._tag)
  }

  get changeCount() {
    return binding.pasteboardChangeCount(this._tag)
  }

  get types() {
    return binding.pasteboardTypes(this._tag)
  }

  clearContents() {
    return binding.pasteboardClearContents(this._tag)
  }

  setString(string, type) {
    return binding.pasteboardSetString(this._tag, string, type)
  }

  stringForType(type) {
    return binding.pasteboardStringForType(this._tag, type)
  }

  setData(data, type) {
    return binding.pasteboardSetData(this._tag, data, type)
  }

  dataForType(type) {
    return binding.pasteboardDataForType(this._tag, type)
  }

  availableTypeFrom(types) {
    return binding.pasteboardAvailableTypeFrom(this._tag, types)
  }

  declareTypes(types) {
    return binding.pasteboardDeclareTypes(this._tag, types)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitPasteboard }
    }
  }
}

exports.TYPE = {
  STRING: binding.PASTEBOARD_TYPE_STRING,
  URL: binding.PASTEBOARD_TYPE_URL,
  FILE_URL: binding.PASTEBOARD_TYPE_FILE_URL,
  PNG: binding.PASTEBOARD_TYPE_PNG,
  TIFF: binding.PASTEBOARD_TYPE_TIFF,
  PDF: binding.PASTEBOARD_TYPE_PDF,
  RTF: binding.PASTEBOARD_TYPE_RTF,
  HTML: binding.PASTEBOARD_TYPE_HTML,
  COLOR: binding.PASTEBOARD_TYPE_COLOR,
  SOUND: binding.PASTEBOARD_TYPE_SOUND
}
