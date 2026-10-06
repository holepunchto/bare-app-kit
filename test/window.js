const { test } = require('bare-tap')
const { View, Window } = require('..')
const { open } = require('./helpers')

const { STYLE_MASK } = Window

test('orders in and out', (t) => {
  const window = new Window({ width: 300, height: 200 })
  t.teardown(() => window.close())

  t.equal(window.visible, false, 'not before')

  window.makeKeyAndOrderFront()

  t.equal(window.visible, true, 'ordered in')

  window.orderOut()

  t.equal(window.visible, false, 'ordered out')
})

test('sizes the content view', (t) => {
  const window = open(t, 300, 200, {
    styleMask: STYLE_MASK.TITLED | STYLE_MASK.CLOSABLE | STYLE_MASK.RESIZABLE
  })

  t.equal(window.styleMask, STYLE_MASK.TITLED | STYLE_MASK.CLOSABLE | STYLE_MASK.RESIZABLE)

  const { width, height } = window.contentView.frame

  t.deepStrictEqual({ width, height }, { width: 300, height: 200 }, 'content size')
  t.ok(window.frame.height > 200, 'frame includes the title bar')
})

test('keeps the content view wrapper', (t) => {
  const window = open(t, 300, 200)

  t.ok(window.contentView === window.contentView, 'same default wrapper')

  const view = new View()

  window.contentView = view

  t.ok(window.contentView === view, 'same assigned wrapper')
  t.ok(view.window === window, 'view knows its window')
})

test('sets the title', (t) => {
  const window = open(t, 300, 200, { styleMask: STYLE_MASK.TITLED })

  window.title = 'Hello'

  t.equal(window.title, 'Hello', 'title')

  window.subtitle = 'World'

  t.equal(window.subtitle, 'World', 'subtitle')
})

test('emits when resized', (t) => {
  const window = open(t, 300, 200)

  let resized = 0

  window.on('didResize', () => resized++)
  window.setContentSize(400, 300)

  t.equal(resized, 1, 'once')
  t.deepStrictEqual(
    { width: window.frame.width, height: window.frame.height },
    { width: 400, height: 300 },
    'new size'
  )
})

test('emits when moved', (t) => {
  const window = open(t, 300, 200)

  let moved = 0

  window.on('didMove', () => moved++)
  window.setFrameOrigin(window.frame.x + 10, window.frame.y + 10)

  t.equal(moved, 1)
})

test('emits when closing', (t) => {
  const window = new Window({ width: 300, height: 200 })

  window.makeKeyAndOrderFront()

  let closing = 0

  window.on('willClose', () => closing++)
  window.close()

  t.equal(closing, 1, 'once')
  t.equal(window.visible, false, 'not visible')
})

test('limits the content size', (t) => {
  const window = open(t, 300, 200, { styleMask: STYLE_MASK.TITLED | STYLE_MASK.RESIZABLE })

  window.contentMinSize = { width: 200, height: 100 }
  window.contentMaxSize = { width: 500, height: 400 }

  t.deepStrictEqual(window.contentMinSize, { width: 200, height: 100 }, 'min')
  t.deepStrictEqual(window.contentMaxSize, { width: 500, height: 400 }, 'max')
})

test('holds child windows', (t) => {
  const parent = open(t, 300, 200)
  const child = open(t, 100, 100)

  parent.addChildWindow(child, Window.WINDOW_ORDERING_MODE.ABOVE)

  t.equal(parent.childWindows.length, 1, 'one child')
  t.ok(parent.childWindows[0] === child, 'the child')
  t.ok(child.parentWindow === parent, 'the parent')

  parent.removeChildWindow(child)

  t.deepStrictEqual(parent.childWindows, [], 'no children')
  t.equal(child.parentWindow, null, 'no parent')
})
