const binding = require('../binding')
const { adopt } = require('./handle')
const AppKitToolbarItem = require('./toolbar-item')

module.exports = exports = class AppKitTrackingSeparatorToolbarItem extends AppKitToolbarItem {
  _init(opts) {
    const { identifier = '', splitView = null, dividerIndex = 0 } = opts

    return binding.trackingSeparatorToolbarItemInit(identifier, adopt(splitView), dividerIndex)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTrackingSeparatorToolbarItem }
    }
  }
}
