const binding = require('../binding')
const { adopt, expose } = require('./handle')
const observe = require('./events')
const retain = require('./retain')
const wrap = require('./wrap')
const EventEmitter = require('bare-events')
const AppKitImage = require('./image')
const AppKitView = require('./view')
const AppKitButton = require('./button')
const AppKitWindow = require('./window')

module.exports = exports = class AppKitAlert extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._accessoryView = null
    this._suppressionButton = null
    this._window = null
    this._retained = new Set()

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init() {
    return binding.alertInit(this)
  }

  get messageText() {
    return binding.alertMessageText(this._tag)
  }

  set messageText(messageText) {
    binding.alertMessageText(this._tag, messageText)
  }

  get informativeText() {
    return binding.alertInformativeText(this._tag)
  }

  set informativeText(informativeText) {
    binding.alertInformativeText(this._tag, informativeText)
  }

  get alertStyle() {
    return binding.alertAlertStyle(this._tag)
  }

  set alertStyle(alertStyle) {
    binding.alertAlertStyle(this._tag, alertStyle)
  }

  get showsHelp() {
    return binding.alertShowsHelp(this._tag)
  }

  set showsHelp(showsHelp) {
    binding.alertShowsHelp(this._tag, showsHelp)
  }

  get showsSuppressionButton() {
    return binding.alertShowsSuppressionButton(this._tag)
  }

  set showsSuppressionButton(showsSuppressionButton) {
    binding.alertShowsSuppressionButton(this._tag, showsSuppressionButton)
  }

  get helpAnchor() {
    return binding.alertHelpAnchor(this._tag)
  }

  set helpAnchor(helpAnchor) {
    binding.alertHelpAnchor(this._tag, helpAnchor)
  }

  get icon() {
    return wrap(AppKitImage, binding.alertIcon(this._tag))
  }

  set icon(icon) {
    binding.alertIcon(this._tag, adopt(icon))
  }

  get accessoryView() {
    return retain(this, '_accessoryView', AppKitView, binding.alertAccessoryView(this._tag))
  }

  set accessoryView(accessoryView) {
    binding.alertAccessoryView(this._tag, adopt(accessoryView))

    this._accessoryView = accessoryView
  }

  get suppressionButton() {
    return retain(
      this,
      '_suppressionButton',
      AppKitButton,
      binding.alertSuppressionButton(this._tag)
    )
  }

  get window() {
    return retain(this, '_window', AppKitWindow, binding.alertWindow(this._tag))
  }

  runModal() {
    return binding.alertRunModal(this._tag)
  }

  beginSheetModal(parent) {
    binding.alertBeginSheetModal(this._tag, adopt(parent))
    return this
  }

  get buttons() {
    return binding.alertButtons(this._tag).map((tag) => wrap(AppKitButton, tag))
  }

  addButtonWithTitle(title) {
    const button = new AppKitButton({
      tag: binding.alertAddButtonWithTitle(this._tag, title)
    })

    this._retained.add(button)

    return button
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitAlert }
    }
  }

  _onresponse(response) {
    this.emit('response', response)
  }
}

exports._events = {
  response: 1
}

exports.STYLE = {
  WARNING: binding.ALERT_STYLE_WARNING,
  INFORMATIONAL: binding.ALERT_STYLE_INFORMATIONAL,
  CRITICAL: binding.ALERT_STYLE_CRITICAL
}

exports.RESPONSE = {
  OK: binding.MODAL_RESPONSE_OK,
  CANCEL: binding.MODAL_RESPONSE_CANCEL,
  STOP: binding.MODAL_RESPONSE_STOP,
  ABORT: binding.MODAL_RESPONSE_ABORT,
  CONTINUE: binding.MODAL_RESPONSE_CONTINUE,
  FIRST_BUTTON: binding.MODAL_RESPONSE_FIRST_BUTTON,
  SECOND_BUTTON: binding.MODAL_RESPONSE_SECOND_BUTTON,
  THIRD_BUTTON: binding.MODAL_RESPONSE_THIRD_BUTTON
}

expose(exports)
