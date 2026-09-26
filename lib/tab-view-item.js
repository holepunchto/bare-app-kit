const binding = require('../binding')
const { adopt } = require('./handle')
const observe = require('./events')
const retain = require('./retain')
const wrap = require('./wrap')
const EventEmitter = require('bare-events')
const AppKitView = require('./view')
const AppKitImage = require('./image')

module.exports = exports = class AppKitTabViewItem extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._view = null

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init() {
    return binding.tabViewItemInit()
  }

  get label() {
    return binding.tabViewItemLabel(this._tag)
  }

  set label(label) {
    binding.tabViewItemLabel(this._tag, label)
  }

  get toolTip() {
    return binding.tabViewItemToolTip(this._tag)
  }

  set toolTip(toolTip) {
    binding.tabViewItemToolTip(this._tag, toolTip)
  }

  get view() {
    return retain(this, '_view', AppKitView, binding.tabViewItemView(this._tag))
  }

  set view(view) {
    binding.tabViewItemView(this._tag, adopt(view))

    this._view = view
  }

  get image() {
    return wrap(AppKitImage, binding.tabViewItemImage(this._tag))
  }

  set image(image) {
    binding.tabViewItemImage(this._tag, adopt(image))
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTabViewItem }
    }
  }
}
