const binding = require('../binding')
const retain = require('./retain')
const wrap = require('./wrap')
const AppKitAppearance = require('./appearance')
const AppKitImage = require('./image')
const AppKitMenu = require('./menu')
const AppKitWindow = require('./window')

module.exports = exports = new (class AppKitApplication {
  constructor() {
    this._mainMenu = null
  }

  get mainMenu() {
    return retain(this, '_mainMenu', AppKitMenu, binding.applicationMainMenu())
  }

  set mainMenu(mainMenu) {
    binding.applicationMainMenu(mainMenu === null ? null : mainMenu._tag)

    this._mainMenu = mainMenu
  }

  get activationPolicy() {
    return binding.applicationActivationPolicy()
  }

  set activationPolicy(activationPolicy) {
    binding.applicationActivationPolicy(activationPolicy)
  }

  get presentationOptions() {
    return binding.applicationPresentationOptions()
  }

  set presentationOptions(presentationOptions) {
    binding.applicationPresentationOptions(presentationOptions)
  }

  get applicationIconImage() {
    return wrap(AppKitImage, binding.applicationApplicationIconImage())
  }

  set applicationIconImage(applicationIconImage) {
    binding.applicationApplicationIconImage(
      applicationIconImage === null ? null : applicationIconImage._tag
    )
  }

  get running() {
    return binding.applicationRunning()
  }

  get active() {
    return binding.applicationActive()
  }

  get hidden() {
    return binding.applicationHidden()
  }

  get mainWindow() {
    return wrap(AppKitWindow, binding.applicationMainWindow())
  }

  get keyWindow() {
    return wrap(AppKitWindow, binding.applicationKeyWindow())
  }

  get windowsMenu() {
    return wrap(AppKitMenu, binding.applicationWindowsMenu())
  }

  set windowsMenu(windowsMenu) {
    binding.applicationWindowsMenu(windowsMenu === null ? null : windowsMenu._tag)
  }

  get servicesMenu() {
    return wrap(AppKitMenu, binding.applicationServicesMenu())
  }

  set servicesMenu(servicesMenu) {
    binding.applicationServicesMenu(servicesMenu === null ? null : servicesMenu._tag)
  }

  get helpMenu() {
    return wrap(AppKitMenu, binding.applicationHelpMenu())
  }

  set helpMenu(helpMenu) {
    binding.applicationHelpMenu(helpMenu === null ? null : helpMenu._tag)
  }

  get effectiveAppearance() {
    return wrap(AppKitAppearance, binding.applicationEffectiveAppearance())
  }

  get appearance() {
    return wrap(AppKitAppearance, binding.applicationAppearance())
  }

  set appearance(appearance) {
    binding.applicationAppearance(appearance === null ? null : appearance._tag)
  }

  hide() {
    binding.applicationHide()
    return this
  }

  unhide() {
    binding.applicationUnhide()
    return this
  }

  unhideAllApplications() {
    binding.applicationUnhideAllApplications()
    return this
  }

  terminate() {
    binding.applicationTerminate()
    return this
  }

  arrangeInFront() {
    binding.applicationArrangeInFront()
    return this
  }

  requestUserAttention(type) {
    return binding.applicationRequestUserAttention(type)
  }

  cancelUserAttentionRequest(request) {
    binding.applicationCancelUserAttentionRequest(request)
    return this
  }

  numberOfWindows() {
    return binding.applicationNumberOfWindows()
  }

  windowAt(index) {
    return wrap(AppKitWindow, binding.applicationWindowAt(index))
  }

  setActivationPolicy(policy) {
    return binding.applicationSetActivationPolicy(policy)
  }

  activate() {
    binding.applicationActivate()
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitApplication }
    }
  }
})()
