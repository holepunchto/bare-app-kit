// Shared storage for the getters that write their components into a buffer
// rather than building an object natively. The components are copied into a
// plain object before anything else can run, so one buffer serves them all.
module.exports = exports = new Float64Array(4)
