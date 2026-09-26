const AppKitMenu = require('./menu')
const AppKitMenuItem = require('./menu-item')

const { MODIFIER } = AppKitMenuItem

function submenu(title, items) {
  const item = new AppKitMenuItem({ title })
  const menu = new AppKitMenu({ title })

  for (const child of items) menu.addItem(child)

  item.submenu = menu

  return item
}

function command(title, keyEquivalent, selector, modifiers) {
  const item = new AppKitMenuItem({ title, keyEquivalent, selector })

  if (modifiers !== undefined) item.keyEquivalentModifierMask = modifiers

  return item
}

// The menu the standard editing commands arrive through. A key equivalent is a
// menu's to deliver, so a text control has none of them until an application
// has a menu, and the first submenu of one is the application's own whatever
// it is titled.
module.exports = exports = function defaultMenu(name = 'Application') {
  const menu = new AppKitMenu()

  menu.addItem(submenu(name, [command(`Quit ${name}`, 'q', 'terminate:')]))

  menu.addItem(
    submenu('Edit', [
      command('Undo', 'z', 'undo:'),
      command('Redo', 'z', 'redo:', MODIFIER.COMMAND | MODIFIER.SHIFT),
      AppKitMenuItem.separator(),
      command('Cut', 'x', 'cut:'),
      command('Copy', 'c', 'copy:'),
      command('Paste', 'v', 'paste:'),
      command('Select All', 'a', 'selectAll:')
    ])
  )

  return menu
}
