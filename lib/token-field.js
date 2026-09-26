const binding = require('../binding')
const { expose } = require('./handle')
const AppKitTextField = require('./text-field')

module.exports = exports = class AppKitTokenField extends AppKitTextField {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.tokenFieldInit(x, y, width, height, this)
  }

  get tokenStyle() {
    return binding.tokenFieldTokenStyle(this._tag)
  }

  set tokenStyle(tokenStyle) {
    binding.tokenFieldTokenStyle(this._tag, tokenStyle)
  }

  get completionDelay() {
    return binding.tokenFieldCompletionDelay(this._tag)
  }

  set completionDelay(completionDelay) {
    binding.tokenFieldCompletionDelay(this._tag, completionDelay)
  }

  get tokens() {
    return binding.tokenFieldTokens(this._tag)
  }

  set tokens(tokens) {
    binding.tokenFieldTokens(this._tag, tokens)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTokenField }
    }
  }
}

exports._events = {
  change: 1,
  didChange: 2,
  didBeginEditing: 4,
  didEndEditing: 8
}

exports.STYLE = {
  DEFAULT: binding.TOKEN_FIELD_STYLE_DEFAULT,
  NONE: binding.TOKEN_FIELD_STYLE_NONE,
  ROUNDED: binding.TOKEN_FIELD_STYLE_ROUNDED,
  SQUARED: binding.TOKEN_FIELD_STYLE_SQUARED,
  PLAIN_SQUARED: binding.TOKEN_FIELD_STYLE_PLAIN_SQUARED
}

expose(exports)
