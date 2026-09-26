const wrap = require('./wrap')

// Read the property every time, so the answer is right even when it was changed
// natively, and keep the result, because the reference from a native object to
// its wrapper is weak.
module.exports = exports = function retain(holder, key, Class, tag) {
  const value = wrap(Class, tag)

  holder[key] = value

  return value
}
