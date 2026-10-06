const { test } = require('bare-tap')
const { afterAnimationFrame } = require('bare-animation-frame')
const { StackView, View } = require('..')
const { open } = require('./helpers')

const { USER_INTERFACE_LAYOUT_ORIENTATION, DISTRIBUTION } = StackView

function stack(t, opts = {}) {
  const {
    width = 300,
    height = 100,
    orientation = USER_INTERFACE_LAYOUT_ORIENTATION.HORIZONTAL,
    spacing = 0,
    count = 3
  } = opts

  const window = open(t, width, height)

  const stack = new StackView()
  stack.orientation = orientation
  stack.distribution = DISTRIBUTION.FILL_EQUALLY
  stack.spacing = spacing

  const views = []

  for (let i = 0; i < count; i++) {
    const view = new View()
    stack.addArrangedSubview(view)
    views.push(view)
  }

  window.contentView = stack

  return { stack, views }
}

function frames(views) {
  return views.map((view) => view.frame)
}

test('shares the width equally', async (t) => {
  const { views } = stack(t)

  await afterAnimationFrame()

  t.deepStrictEqual(frames(views), [
    { x: 0, y: 0, width: 100, height: 100 },
    { x: 100, y: 0, width: 100, height: 100 },
    { x: 200, y: 0, width: 100, height: 100 }
  ])
})

test('spaces the views', async (t) => {
  const { views } = stack(t, { spacing: 30 })

  await afterAnimationFrame()

  t.deepStrictEqual(frames(views), [
    { x: 0, y: 0, width: 80, height: 100 },
    { x: 110, y: 0, width: 80, height: 100 },
    { x: 220, y: 0, width: 80, height: 100 }
  ])
})

test('stacks vertically from the top', async (t) => {
  const { views } = stack(t, {
    width: 100,
    height: 300,
    orientation: USER_INTERFACE_LAYOUT_ORIENTATION.VERTICAL
  })

  await afterAnimationFrame()

  t.deepStrictEqual(frames(views), [
    { x: 0, y: 200, width: 100, height: 100 },
    { x: 0, y: 100, width: 100, height: 100 },
    { x: 0, y: 0, width: 100, height: 100 }
  ])
})

test('insets the views', async (t) => {
  const { stack: view, views } = stack(t, { count: 2 })

  view.edgeInsets = { top: 10, left: 20, bottom: 10, right: 40 }

  t.deepStrictEqual(view.edgeInsets, { top: 10, left: 20, bottom: 10, right: 40 }, 'insets')

  await afterAnimationFrame()

  t.deepStrictEqual(
    frames(views),
    [
      { x: 20, y: 10, width: 120, height: 80 },
      { x: 140, y: 10, width: 120, height: 80 }
    ],
    'frames'
  )
})

test('spaces after a single view', async (t) => {
  const { stack: view, views } = stack(t)

  view.setCustomSpacing(60, views[0])

  await afterAnimationFrame()

  t.deepStrictEqual(
    views.map((view) => view.frame.x),
    [0, 140, 220]
  )
})

test('keeps the order of arranged subviews', async (t) => {
  const { stack: view, views } = stack(t, { count: 2 })

  const inserted = new View()

  view.insertArrangedSubview(inserted, 1)

  const arranged = view.arrangedSubviews

  t.equal(arranged.length, 3, 'count')
  t.ok(arranged[0] === views[0], 'first')
  t.ok(arranged[1] === inserted, 'inserted')
  t.ok(arranged[2] === views[1], 'last')

  await afterAnimationFrame()

  t.deepStrictEqual(
    [views[0], inserted, views[1]].map((view) => view.frame.x),
    [0, 100, 200],
    'laid out in order'
  )
})

test('removes an arranged subview', async (t) => {
  const { stack: view, views } = stack(t)

  view.removeArrangedSubview(views[1])

  t.equal(view.arrangedSubviews.length, 2, 'no longer arranged')
  t.ok(views[1].superview === view, 'still a subview')

  view.removeView(views[2])

  t.equal(view.arrangedSubviews.length, 1, 'removed view no longer arranged')
  t.equal(views[2].superview, null, 'removed view no longer a subview')

  await afterAnimationFrame()

  t.equal(views[0].frame.width, 300, 'remaining view fills the stack')
})

test('detaches hidden views', async (t) => {
  const { stack: view, views } = stack(t)

  t.equal(view.detachesHiddenViews, true, 'by default')

  views[1].hidden = true

  await afterAnimationFrame()

  t.deepStrictEqual(
    [views[0], views[2]].map((view) => view.frame),
    [
      { x: 0, y: 0, width: 150, height: 100 },
      { x: 150, y: 0, width: 150, height: 100 }
    ],
    'shares the space'
  )
})
