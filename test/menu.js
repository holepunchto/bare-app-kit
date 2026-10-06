const { test } = require('bare-tap')
const { Menu, MenuItem } = require('..')

function items(...titles) {
  return titles.map((title) => new MenuItem({ title }))
}

test('adds and removes items', (t) => {
  const menu = new Menu({ title: 'File' })
  const [a, b, c] = items('A', 'B', 'C')

  t.equal(menu.title, 'File', 'title')

  menu.addItem(a)
  menu.addItem(c)
  menu.insertItem(b, 1)

  t.equal(menu.numberOfItems, 3, 'count')
  t.ok(menu.itemAtIndex(1) === b, 'inserted')
  t.deepStrictEqual(
    menu.items.map((item) => item.title),
    ['A', 'B', 'C'],
    'in order'
  )

  t.equal(menu.indexOfItem(c), 2, 'index of item')
  t.equal(menu.indexOfItemWithTitle('B'), 1, 'index of title')
  t.equal(menu.indexOfItemWithTitle('D'), -1, 'missing title')

  menu.removeItem(a)

  t.equal(menu.indexOfItem(a), -1, 'removed item')

  menu.removeItemAtIndex(0)

  t.ok(menu.itemAtIndex(0) === c, 'removed at index')

  menu.removeAllItems()

  t.equal(menu.numberOfItems, 0, 'removed all')
  t.equal(menu.itemAtIndex(0), null, 'no item')
})

test('finds an item by tag', (t) => {
  const menu = new Menu()
  const [a, b] = items('A', 'B')

  b.tag = 7

  menu.addItem(a)
  menu.addItem(b)

  t.equal(menu.indexOfItemWithTag(7), 1)
})

test('performs the action of an item', (t) => {
  const menu = new Menu()
  const [a, b] = items('A', 'B')

  menu.addItem(a)
  menu.addItem(b)

  const clicked = []

  a.on('click', () => clicked.push('A'))
  b.on('click', () => clicked.push('B'))

  menu.performActionForItemAtIndex(1)
  menu.performActionForItemAtIndex(0)

  t.deepStrictEqual(clicked, ['B', 'A'])
})

test('nests a submenu', (t) => {
  const menu = new Menu()
  const submenu = new Menu({ title: 'Recent' })
  const [item] = items('Open Recent')

  item.submenu = submenu
  menu.addItem(item)

  t.ok(item.submenu === submenu, 'submenu')
  t.ok(submenu.supermenu === menu, 'supermenu')
})

test('creates a separator', (t) => {
  const separator = MenuItem.separator()
  const [item] = items('A')

  t.equal(separator.separatorItem, true, 'separator')
  t.equal(item.separatorItem, false, 'regular item')
})

test('sets the properties of an item', (t) => {
  const item = new MenuItem({ title: 'Save', keyEquivalent: 's' })

  t.equal(item.title, 'Save', 'title')
  t.equal(item.keyEquivalent, 's', 'key equivalent')
  t.equal(item.keyEquivalentModifierMask, MenuItem.EVENT_MODIFIER_FLAGS.COMMAND, 'modifiers')

  item.state = 1
  item.indentationLevel = 2
  item.toolTip = 'Saves the document'

  t.equal(item.state, 1, 'state')
  t.equal(item.indentationLevel, 2, 'indentation level')
  t.equal(item.toolTip, 'Saves the document', 'tool tip')
})
