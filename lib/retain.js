const wrap = require('./wrap')

// Reads a property and holds on to whatever it currently points at. Reading
// native every time is what keeps the answer true when the property is
// changed from the other side; holding the result is what keeps its listeners
// alive, since the reference back from a native object to its wrapper is weak
// and the wrapper is otherwise unreachable.
module.exports = exports = function retain(holder, key, Class, tag) {
  const value = wrap(Class, tag)

  holder[key] = value

  return value
}
