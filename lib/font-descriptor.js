const binding = require('../binding')
const { expose } = require('./handle')
const wrap = require('./wrap')

module.exports = exports = class AppKitFontDescriptor {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  get symbolicTraits() {
    return binding.fontDescriptorSymbolicTraits(this._tag)
  }

  withSymbolicTraits(traits) {
    return wrap(AppKitFontDescriptor, binding.fontDescriptorWithSymbolicTraits(this._tag, traits))
  }

  withFamily(family) {
    return wrap(AppKitFontDescriptor, binding.fontDescriptorWithFamily(this._tag, family))
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitFontDescriptor }
    }
  }
}

exports.TRAIT = {
  ITALIC: binding.FONT_DESCRIPTOR_TRAIT_ITALIC,
  BOLD: binding.FONT_DESCRIPTOR_TRAIT_BOLD,
  EXPANDED: binding.FONT_DESCRIPTOR_TRAIT_EXPANDED,
  CONDENSED: binding.FONT_DESCRIPTOR_TRAIT_CONDENSED,
  MONO_SPACE: binding.FONT_DESCRIPTOR_TRAIT_MONO_SPACE
}

expose(exports)
