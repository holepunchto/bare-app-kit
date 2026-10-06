const { test } = require('bare-tap')
const { Button, View } = require('..')
const { open } = require('./helpers')

test('sets the frame and bounds', (t) => {
  const view = new View({ x: 10, y: 20, width: 30, height: 40 })

  t.deepStrictEqual(view.frame, { x: 10, y: 20, width: 30, height: 40 }, 'initial frame')
  t.deepStrictEqual(view.bounds, { x: 0, y: 0, width: 30, height: 40 }, 'initial bounds')

  view.frame = { x: 1, y: 2, width: 3, height: 4 }

  t.deepStrictEqual(view.frame, { x: 1, y: 2, width: 3, height: 4 }, 'frame')

  view.bounds = { x: 5, y: 6, width: 3, height: 4 }

  t.deepStrictEqual(view.bounds, { x: 5, y: 6, width: 3, height: 4 }, 'bounds')
  t.deepStrictEqual(view.frame, { x: 1, y: 2, width: 3, height: 4 }, 'frame unchanged')
})

test('builds a hierarchy', (t) => {
  const parent = new View()
  const a = new View()
  const b = new View()

  t.equal(a.superview, null, 'no superview')
  t.deepStrictEqual(parent.subviews, [], 'no subviews')

  parent.addSubview(a)
  parent.addSubview(b)

  t.ok(a.superview === parent, 'same superview wrapper')
  t.equal(parent.subviews.length, 2, 'two subviews')
  t.ok(parent.subviews[0] === a, 'first subview')
  t.ok(parent.subviews[1] === b, 'second subview')

  a.removeFromSuperview()

  t.equal(a.superview, null, 'removed')
  t.equal(parent.subviews.length, 1, 'one subview')
  t.ok(parent.subviews[0] === b, 'remaining subview')
})

test('orders subviews', (t) => {
  const parent = new View()
  const a = new View()
  const b = new View()
  const c = new View()

  parent.addSubview(a)
  parent.addSubview(b, View.WINDOW_ORDERING_MODE.BELOW, a)
  parent.addSubview(c, View.WINDOW_ORDERING_MODE.ABOVE, b)

  const subviews = parent.subviews

  t.ok(subviews[0] === b, 'below')
  t.ok(subviews[1] === c, 'above the one below')
  t.ok(subviews[2] === a, 'top')
})

test('moves a view to another superview', (t) => {
  const first = new View()
  const second = new View()
  const view = new View()

  first.addSubview(view)
  second.addSubview(view)

  t.ok(view.superview === second, 'new superview')
  t.deepStrictEqual(first.subviews, [], 'left the old superview')
  t.equal(second.subviews.length, 1, 'joined the new superview')
})

test('reports hidden ancestors', (t) => {
  const parent = new View()
  const child = new View()

  parent.addSubview(child)

  t.equal(child.hiddenOrHasHiddenAncestor, false, 'visible')

  parent.hidden = true

  t.equal(child.hidden, false, 'not hidden itself')
  t.equal(child.hiddenOrHasHiddenAncestor, true, 'hidden ancestor')
})

test('converts points between views', (t) => {
  const parent = new View({ width: 200, height: 200 })
  const child = new View({ x: 30, y: 40, width: 50, height: 50 })

  parent.addSubview(child)

  t.deepStrictEqual(child.convertPointToView(5, 5, parent), { x: 35, y: 45 }, 'to the parent')
  t.deepStrictEqual(child.convertPointFromView(35, 45, parent), { x: 5, y: 5 }, 'from the parent')
})

test('converts points in a flipped view', (t) => {
  const parent = new View({ width: 200, height: 200 })
  const child = new View({ x: 30, y: 40, width: 50, height: 50 })

  child.flipped = true

  parent.addSubview(child)

  t.equal(child.flipped, true, 'flipped')
  t.deepStrictEqual(child.convertPointToView(5, 5, parent), { x: 35, y: 85 })
})

test('hit tests the wrapper of a subview', (t) => {
  const window = open(t, 300, 200)
  const content = window.contentView

  const button = new Button({ x: 10, y: 10, width: 100, height: 30 })
  const overlay = new View({ x: 0, y: 0, width: 300, height: 100 })

  content.addSubview(button)

  t.ok(content.hitTest(50, 20) === button, 'the button')
  t.ok(content.hitTest(200, 150) === content, 'the content view')

  content.addSubview(overlay)

  t.ok(content.hitTest(50, 20) === overlay, 'an overlay')

  overlay.hitTestable = false

  t.ok(content.hitTest(50, 20) === button, 'through an untestable overlay')
  t.throws(() => {
    button.hitTestable = false
  }, 'only on a plain view')
})

test('knows its window', (t) => {
  const window = open(t, 300, 200)

  const view = new View()

  t.equal(view.window, null, 'no window')

  window.contentView.addSubview(view)

  t.ok(view.window === window, 'the window')
})

test('sets the tool tip and alpha', (t) => {
  const view = new View()

  t.equal(view.toolTip, null, 'no tool tip')

  view.toolTip = 'Hello'

  t.equal(view.toolTip, 'Hello', 'tool tip')

  view.toolTip = null

  t.equal(view.toolTip, null, 'tool tip cleared')

  view.alphaValue = 0.5

  t.equal(view.alphaValue, 0.5, 'alpha')
})
