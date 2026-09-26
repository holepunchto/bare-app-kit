const binding = require('../binding')
const AppKitTextField = require('./text-field')

module.exports = exports = class AppKitSecureTextField extends AppKitTextField {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.secureTextFieldInit(x, y, width, height, this)
  }

  _onwilldraw() {
    this.emit('willDraw')
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitSecureTextField }
    }
  }
}

exports._events = {
  change: binding.SECURE_TEXT_FIELD_EVENT_CHANGE,
  didChange: binding.SECURE_TEXT_FIELD_EVENT_DID_CHANGE,
  didBeginEditing: binding.SECURE_TEXT_FIELD_EVENT_DID_BEGIN_EDITING,
  didEndEditing: binding.SECURE_TEXT_FIELD_EVENT_DID_END_EDITING,
  becomeFirstResponder: binding.SECURE_TEXT_FIELD_EVENT_BECOME_FIRST_RESPONDER,
  resignFirstResponder: binding.SECURE_TEXT_FIELD_EVENT_RESIGN_FIRST_RESPONDER,
  didChangeSelection: binding.SECURE_TEXT_FIELD_EVENT_DID_CHANGE_SELECTION,
  shouldChangeText: binding.SECURE_TEXT_FIELD_EVENT_SHOULD_CHANGE_TEXT,
  willDraw: binding.SECURE_TEXT_FIELD_EVENT_WILL_DRAW
}
