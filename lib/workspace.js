const binding = require('../binding')
const wrap = require('./wrap')
const AppKitImage = require('./image')
const { validateNoNullBytes } = require('./validate')

module.exports = exports = new (class AppKitWorkspace {
  openURL(url) {
    validateNoNullBytes(url, 'url')

    return binding.workspaceOpenURL(url)
  }

  openFile(path) {
    validateNoNullBytes(path, 'path')

    return binding.workspaceOpenFile(path)
  }

  selectFile(path) {
    validateNoNullBytes(path, 'path')

    binding.workspaceSelectFile(path)
    return this
  }

  iconForFile(path) {
    validateNoNullBytes(path, 'path')

    return wrap(AppKitImage, binding.workspaceIconForFile(path))
  }

  urlForApplication(identifier) {
    return binding.workspaceUrlForApplication(identifier)
  }

  iconForContentType(identifier) {
    return wrap(AppKitImage, binding.workspaceIconForContentType(identifier))
  }

  isFilePackage(path) {
    validateNoNullBytes(path, 'path')

    return binding.workspaceIsFilePackage(path)
  }

  openApplication(path) {
    validateNoNullBytes(path, 'path')

    binding.workspaceOpenApplication(path)
    return this
  }

  hideOtherApplications() {
    binding.workspaceHideOtherApplications()
    return this
  }

  urlForApplicationToOpenFile(path) {
    validateNoNullBytes(path, 'path')

    return binding.workspaceUrlForApplicationToOpenFile(path)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitWorkspace }
    }
  }
})()
