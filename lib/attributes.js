const AppKitColor = require('./color')
const AppKitFont = require('./font')
const AppKitParagraphStyle = require('./paragraph-style')

// Text attributes carry wrapped objects on the JavaScript side but bare handles
// across the boundary.
const WRAPPERS = {
  font: AppKitFont,
  foregroundColor: AppKitColor,
  backgroundColor: AppKitColor,
  underlineColor: AppKitColor,
  strikethroughColor: AppKitColor,
  paragraphStyle: AppKitParagraphStyle
}

exports.unwrapAttributes = function unwrapAttributes(attributes) {
  const result = {}

  for (const [key, value] of Object.entries(attributes)) {
    result[key] = key in WRAPPERS && value !== null ? value._tag : value
  }

  return result
}

exports.wrapAttributes = function wrapAttributes(attributes) {
  const result = {}

  for (const [key, value] of Object.entries(attributes)) {
    const Wrapper = WRAPPERS[key]

    result[key] = Wrapper && value !== null ? new Wrapper({ tag: value }) : value
  }

  return result
}
