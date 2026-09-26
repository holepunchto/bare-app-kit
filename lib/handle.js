const binding = require('../binding')
const registry = require('bare-foundation-registry')

// The protocol itself lives in `bare-foundation-registry`, so every module
// that speaks it agrees on the symbol and on what adoption means.
exports.handle = registry.handle

exports.adopt = function adopt(object) {
  return registry.adopt(binding, object)
}

exports.expose = function expose(classes) {
  return registry.expose(binding, classes)
}
