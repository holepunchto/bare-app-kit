const { test } = require('bare-tap')
const Pointer = require('bare-pointer')
const { TableColumn, TableView, TextField } = require('..')
const { open, shown } = require('./helpers')

test('selects a row with the pointer', async (t) => {
  const window = open(t, 300, 200)
  const pointer = new Pointer()

  t.teardown(() => pointer.destroy())

  const table = new TableView({
    width: 300,
    height: 200,
    numberOfRows: 5,
    makeView(identifier, row) {
      const field = new TextField()
      field.bezeled = false
      field.editable = false
      field.stringValue = `Row ${row}`
      return field
    }
  })

  const column = new TableColumn({ identifier: 'name' })
  column.width = 280

  table.style = TableView.STYLE.PLAIN
  table.headerView = null
  table.rowHeight = 24
  table.intercellSpacing = { height: 0 }
  table.addTableColumn(column)

  window.contentView.addSubview(table)

  const events = []

  table.on('selectionDidChange', () => events.push(['selectionDidChange', table.selectedRow]))
  table.on('click', () => events.push(['click', table.clickedRow]))

  const middle = (row) => (table.flipped ? row + 0.5 : table.numberOfRows - row - 0.5) * 24

  await shown(window)

  await pointer.tap(table, 100, middle(2))

  t.equal(table.selectedRow, 2, 'selected')

  await pointer.tap(table, 100, middle(4))

  t.equal(table.selectedRow, 4, 'selected another')
  t.equal(table.numberOfSelectedRows, 1, 'only one')
  t.deepStrictEqual(
    events,
    [
      ['selectionDidChange', 2],
      ['click', 2],
      ['selectionDidChange', 4],
      ['click', 4]
    ],
    'events'
  )
})
