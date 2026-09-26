import AppKitMenu = require('./menu')

/**
 * Build the standard main menu for an app called `name`, with Quit and the Edit commands. Set it
 * as `AppKitApplication.mainMenu`.
 */
declare function defaultMenu(name?: string): AppKitMenu

export = defaultMenu
