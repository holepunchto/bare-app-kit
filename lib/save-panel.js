const binding = require('../binding')
const { adopt, expose } = require('./handle')
const observe = require('./events')
const retain = require('./retain')
const wrap = require('./wrap')
const EventEmitter = require('bare-events')
const AppKitView = require('./view')
const AppKitContentType = require('./content-type')

module.exports = exports = class AppKitSavePanel extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._accessoryView = null

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init() {
    return binding.savePanelInit()
  }

  get url() {
    return binding.savePanelUrl(this._tag)
  }

  get directoryURL() {
    return binding.savePanelDirectoryURL(this._tag)
  }

  set directoryURL(directoryURL) {
    binding.savePanelDirectoryURL(this._tag, directoryURL)
  }

  get nameFieldStringValue() {
    return binding.savePanelNameFieldStringValue(this._tag)
  }

  set nameFieldStringValue(nameFieldStringValue) {
    binding.savePanelNameFieldStringValue(this._tag, nameFieldStringValue)
  }

  get nameFieldLabel() {
    return binding.savePanelNameFieldLabel(this._tag)
  }

  set nameFieldLabel(nameFieldLabel) {
    binding.savePanelNameFieldLabel(this._tag, nameFieldLabel)
  }

  get message() {
    return binding.savePanelMessage(this._tag)
  }

  set message(message) {
    binding.savePanelMessage(this._tag, message)
  }

  get prompt() {
    return binding.savePanelPrompt(this._tag)
  }

  set prompt(prompt) {
    binding.savePanelPrompt(this._tag, prompt)
  }

  get canCreateDirectories() {
    return binding.savePanelCanCreateDirectories(this._tag)
  }

  set canCreateDirectories(canCreateDirectories) {
    binding.savePanelCanCreateDirectories(this._tag, canCreateDirectories)
  }

  get canSelectHiddenExtension() {
    return binding.savePanelCanSelectHiddenExtension(this._tag)
  }

  set canSelectHiddenExtension(canSelectHiddenExtension) {
    binding.savePanelCanSelectHiddenExtension(this._tag, canSelectHiddenExtension)
  }

  get showsHiddenFiles() {
    return binding.savePanelShowsHiddenFiles(this._tag)
  }

  set showsHiddenFiles(showsHiddenFiles) {
    binding.savePanelShowsHiddenFiles(this._tag, showsHiddenFiles)
  }

  get showsTagField() {
    return binding.savePanelShowsTagField(this._tag)
  }

  set showsTagField(showsTagField) {
    binding.savePanelShowsTagField(this._tag, showsTagField)
  }

  get extensionHidden() {
    return binding.savePanelExtensionHidden(this._tag)
  }

  set extensionHidden(extensionHidden) {
    binding.savePanelExtensionHidden(this._tag, extensionHidden)
  }

  get treatsFilePackagesAsDirectories() {
    return binding.savePanelTreatsFilePackagesAsDirectories(this._tag)
  }

  set treatsFilePackagesAsDirectories(treatsFilePackagesAsDirectories) {
    binding.savePanelTreatsFilePackagesAsDirectories(this._tag, treatsFilePackagesAsDirectories)
  }

  get accessoryView() {
    return retain(this, '_accessoryView', AppKitView, binding.savePanelAccessoryView(this._tag))
  }

  set accessoryView(accessoryView) {
    binding.savePanelAccessoryView(this._tag, adopt(accessoryView))

    this._accessoryView = accessoryView
  }

  get allowedContentTypes() {
    return binding
      .savePanelAllowedContentTypes(this._tag)
      .map((tag) => wrap(AppKitContentType, tag))
  }

  set allowedContentTypes(allowedContentTypes) {
    binding.savePanelAllowedContentTypes(
      this._tag,
      allowedContentTypes.map((contentType) => contentType._tag)
    )
  }

  runModal() {
    return binding.savePanelRunModal(this._tag)
  }

  ok() {
    binding.savePanelOk(this._tag)
    return this
  }

  cancel() {
    binding.savePanelCancel(this._tag)
    return this
  }

  validateVisibleColumns() {
    binding.savePanelValidateVisibleColumns(this._tag)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitSavePanel }
    }
  }
}

exports.RESPONSE = {
  OK: binding.MODAL_RESPONSE_OK,
  CANCEL: binding.MODAL_RESPONSE_CANCEL
}

expose(exports)
