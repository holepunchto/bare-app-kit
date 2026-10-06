const { test } = require('bare-tap')
const { TabView, TabViewItem, View } = require('..')
const { open } = require('./helpers')

function tabs(t, ...labels) {
  const window = open(t, 300, 200)

  const tabView = new TabView({ width: 300, height: 200 })

  const items = labels.map((label) => {
    const item = new TabViewItem()
    item.label = label
    item.view = new View()
    tabView.addTabViewItem(item)
    return item
  })

  window.contentView = tabView

  return { tabView, items }
}

test('adds and removes items', (t) => {
  const { tabView, items } = tabs(t, 'A', 'B')

  const inserted = new TabViewItem()
  inserted.label = 'C'

  tabView.insertTabViewItem(inserted, 1)

  t.equal(tabView.numberOfTabViewItems, 3, 'count')
  t.deepStrictEqual(
    tabView.tabViewItems.map((item) => item.label),
    ['A', 'C', 'B'],
    'in order'
  )
  t.equal(tabView.indexOfTabViewItem(items[1]), 2, 'index')

  tabView.removeTabViewItem(items[0])

  t.equal(tabView.indexOfTabViewItem(items[0]), -1, 'removed')
  t.equal(tabView.numberOfTabViewItems, 2, 'count after removing')
})

test('selects an item', (t) => {
  const { tabView, items } = tabs(t, 'A', 'B')

  t.equal(tabView.indexOfSelectedTabViewItem, 0, 'first by default')

  let selected = 0

  tabView.on('didSelect', () => selected++)
  tabView.selectTabViewItemAtIndex(1)

  t.equal(selected, 1, 'emits')
  t.ok(tabView.selectedTabViewItem === items[1], 'selected item')
  t.ok(items[1].view.window !== null, 'shows its view')
  t.equal(items[0].view.window, null, 'hides the other view')
})
