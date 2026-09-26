// Shared storage for getters that write into a buffer instead of building an
// object. Each getter copies the values out straight away, so one buffer serves
// all of them.
module.exports = exports = new Float64Array(4)
