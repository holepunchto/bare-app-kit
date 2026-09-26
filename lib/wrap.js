const binding = require('../binding')

module.exports = exports = function wrap(Class, tag) {
  if (tag === null) return null

  return binding.wrapper(tag) || new Class({ tag })
}
