const binding = require('../binding')
const { adopt } = require('./handle')
const observe = require('./events')
const wrap = require('./wrap')
const EventEmitter = require('bare-events')
const AppKitImage = require('./image')
const AppKitAttributedString = require('./attributed-string')

module.exports = exports = class AppKitPathControlItem extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init() {
    return binding.pathControlItemInit()
  }

  get title() {
    return binding.pathControlItemTitle(this._tag)
  }

  set title(title) {
    binding.pathControlItemTitle(this._tag, title)
  }

  get image() {
    return wrap(AppKitImage, binding.pathControlItemImage(this._tag))
  }

  set image(image) {
    binding.pathControlItemImage(this._tag, adopt(image))
  }

  get url() {
    return binding.pathControlItemUrl(this._tag)
  }

  get attributedTitle() {
    return wrap(AppKitAttributedString, binding.pathControlItemAttributedTitle(this._tag))
  }

  set attributedTitle(attributedTitle) {
    binding.pathControlItemAttributedTitle(this._tag, adopt(attributedTitle))
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitPathControlItem }
    }
  }
}
