const binding = require('../binding')
const { expose } = require('./handle')
const AppKitSavePanel = require('./save-panel')

module.exports = exports = class AppKitOpenPanel extends AppKitSavePanel {
  _init() {
    return binding.openPanelInit()
  }

  get urls() {
    return binding.openPanelUrls(this._tag)
  }

  get canChooseFiles() {
    return binding.openPanelCanChooseFiles(this._tag)
  }

  set canChooseFiles(canChooseFiles) {
    binding.openPanelCanChooseFiles(this._tag, canChooseFiles)
  }

  get canChooseDirectories() {
    return binding.openPanelCanChooseDirectories(this._tag)
  }

  set canChooseDirectories(canChooseDirectories) {
    binding.openPanelCanChooseDirectories(this._tag, canChooseDirectories)
  }

  get allowsMultipleSelection() {
    return binding.openPanelAllowsMultipleSelection(this._tag)
  }

  set allowsMultipleSelection(allowsMultipleSelection) {
    binding.openPanelAllowsMultipleSelection(this._tag, allowsMultipleSelection)
  }

  get resolvesAliases() {
    return binding.openPanelResolvesAliases(this._tag)
  }

  set resolvesAliases(resolvesAliases) {
    binding.openPanelResolvesAliases(this._tag, resolvesAliases)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitOpenPanel }
    }
  }
}

expose(exports)
