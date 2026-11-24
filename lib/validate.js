// Paths and URLs are handed on to AppKit as C strings or file system paths,
// where a NUL would cut them short and name something else.
exports.validateNoNullBytes = function validateNoNullBytes(value, name) {
  if (typeof value === 'string' && value.includes('\0')) {
    throw new TypeError(`The "${name}" argument must not contain null bytes`)
  }
}
