const binding = require('../binding')
const AppKitTextField = require('./text-field')

module.exports = exports = class AppKitSecureTextField extends AppKitTextField {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.secureTextFieldInit(x, y, width, height, this)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitSecureTextField }
    }
  }
}

exports._events = {
  change: 1,
  didChange: 2,
  didBeginEditing: 4,
  didEndEditing: 8,
  becomeFirstResponder: 16,
  resignFirstResponder: 32,
  didChangeSelection: 64,
  shouldChangeText: 128
}
