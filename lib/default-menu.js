const AppKitMenu = require('./menu')
const AppKitMenuItem = require('./menu-item')

const { EVENT_MODIFIER_FLAGS } = AppKitMenuItem

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

// Key equivalents are delivered through the menu, so a text control has no
// editing commands until the application has one. The first submenu belongs to
// the application whatever its title.
module.exports = exports = function defaultMenu(name = 'Application') {
  const menu = new AppKitMenu()

  menu.addItem(submenu(name, [command(`Quit ${name}`, 'q', 'terminate:')]))

  menu.addItem(
    submenu('Edit', [
      command('Undo', 'z', 'undo:'),
      command('Redo', 'z', 'redo:', EVENT_MODIFIER_FLAGS.COMMAND | EVENT_MODIFIER_FLAGS.SHIFT),
      AppKitMenuItem.separator(),
      command('Cut', 'x', 'cut:'),
      command('Copy', 'c', 'copy:'),
      command('Paste', 'v', 'paste:'),
      command('Select All', 'a', 'selectAll:')
    ])
  )

  return menu
}
