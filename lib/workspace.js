const binding = require('../binding')
const wrap = require('./wrap')
const AppKitImage = require('./image')

module.exports = exports = new (class AppKitWorkspace {
  openURL(url) {
    return binding.workspaceOpenURL(url)
  }

  openFile(path) {
    return binding.workspaceOpenFile(path)
  }

  selectFile(path) {
    binding.workspaceSelectFile(path)
    return this
  }

  iconForFile(path) {
    return wrap(AppKitImage, binding.workspaceIconForFile(path))
  }

  urlForApplication(identifier) {
    return binding.workspaceUrlForApplication(identifier)
  }

  iconForContentType(identifier) {
    return wrap(AppKitImage, binding.workspaceIconForContentType(identifier))
  }

  isFilePackage(path) {
    return binding.workspaceIsFilePackage(path)
  }

  openApplication(path) {
    binding.workspaceOpenApplication(path)
    return this
  }

  hideOtherApplications() {
    binding.workspaceHideOtherApplications()
    return this
  }

  urlForApplicationToOpenFile(path) {
    return binding.workspaceUrlForApplicationToOpenFile(path)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitWorkspace }
    }
  }
})()
