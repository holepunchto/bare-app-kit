const binding = require('../binding')
const registry = require('bare-foundation-registry')

// The protocol itself lives in `bare-foundation-registry`, so every module
// that speaks it agrees on the symbol and on what adoption means.
exports.handle = registry.handle

exports.adopt = function adopt(object) {
  return registry.adopt(binding, object)
}

// Exposing a class answers the native handle protocol on its behalf, so
// another module can take one of its objects and adopt it into its own
// registry. Every class that carries a handle does it for itself, because a
// caller reaching one of them directly never loads the index.
exports.expose = function expose(Class) {
  return registry.expose(binding, [Class])
}
