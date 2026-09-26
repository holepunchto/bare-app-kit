const binding = require('../binding')
const { expose } = require('./handle')
const wrap = require('./wrap')

module.exports = exports = class AppKitPasteboard {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
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

expose(exports)
