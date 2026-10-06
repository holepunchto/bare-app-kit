const { test } = require('bare-tap')
const DisplayLink = require('bare-core-animation/display-link')
const RunLoop = require('bare-foundation/run-loop')
const { afterAnimationFrame } = require('bare-animation-frame')
const { LayoutConstraint, View } = require('..')
const { open } = require('./helpers')

function constrain(content) {
  const child = new View()
  child.translatesAutoresizingMaskIntoConstraints = false

  content.addSubview(child)

  return child
}

function pin(content) {
  const child = constrain(content)

  LayoutConstraint.activate([
    child.topAnchor.equalTo(content.topAnchor, 10),
    child.leadingAnchor.equalTo(content.leadingAnchor, 20),
    child.trailingAnchor.equalTo(content.trailingAnchor, -20),
    child.heightAnchor.equalToConstant(50)
  ])

  return child
}

test('waits for a frame to be displayed', async (t) => {
  const window = open(t, 300, 200)

  const link = new DisplayLink(window)
  t.teardown(() => link.invalidate())

  let ticks = 0

  link.on('tick', () => ticks++)
  link.addToRunLoop(RunLoop.main, RunLoop.MODE.COMMON)

  await afterAnimationFrame()

  t.ok(ticks > 0)
})

test('lays out on the next frame', async (t) => {
  const window = open(t, 300, 200)

  const child = pin(window.contentView)

  t.deepStrictEqual(child.frame, { x: 0, y: 0, width: 0, height: 0 }, 'not before')

  await afterAnimationFrame()

  t.deepStrictEqual(child.frame, { x: 20, y: 140, width: 260, height: 50 }, 'after')
})

test('follows a resize', async (t) => {
  const window = open(t, 300, 200)

  const child = pin(window.contentView)

  await afterAnimationFrame()

  t.deepStrictEqual(child.frame, { x: 20, y: 140, width: 260, height: 50 }, 'before')

  window.setContentSize(400, 300)

  await afterAnimationFrame()

  t.deepStrictEqual(child.frame, { x: 20, y: 240, width: 360, height: 50 }, 'after')
})

test('follows a changed constant', async (t) => {
  const window = open(t, 300, 200)
  const content = window.contentView

  const child = constrain(content)

  const width = child.widthAnchor.equalToConstant(100)

  LayoutConstraint.activate([
    width,
    child.heightAnchor.equalToConstant(50),
    child.leadingAnchor.equalTo(content.leadingAnchor, 0),
    child.bottomAnchor.equalTo(content.bottomAnchor, 0)
  ])

  await afterAnimationFrame()

  width.constant = 150

  await afterAnimationFrame()

  t.deepStrictEqual(child.frame, { x: 0, y: 0, width: 150, height: 50 })
})

test('describes a constraint', (t) => {
  const a = new View()
  const b = new View()

  const constraint = a.widthAnchor.equalToMultiple(b.widthAnchor, 0.5, 10)

  t.equal(constraint.multiplier, 0.5, 'multiplier')
  t.equal(constraint.constant, 10, 'constant')
  t.equal(constraint.relation, LayoutConstraint.LAYOUT_RELATION.EQUAL, 'relation')
  t.equal(constraint.priority, LayoutConstraint.LAYOUT_PRIORITY.REQUIRED, 'priority')
  t.equal(constraint.active, false, 'inactive')

  constraint.identifier = 'half'

  t.equal(constraint.identifier, 'half', 'identifier')

  t.equal(
    a.widthAnchor.greaterThanOrEqualToConstant(10).relation,
    LayoutConstraint.LAYOUT_RELATION.GREATER_THAN_OR_EQUAL,
    'greater than or equal'
  )
  t.equal(
    a.widthAnchor.lessThanOrEqualToConstant(10).relation,
    LayoutConstraint.LAYOUT_RELATION.LESS_THAN_OR_EQUAL,
    'less than or equal'
  )
})

test('activates and deactivates', async (t) => {
  const window = open(t, 300, 200)
  const content = window.contentView

  const child = constrain(content)

  const narrow = child.widthAnchor.equalToConstant(100)
  const wide = child.widthAnchor.equalToConstant(200)

  LayoutConstraint.activate([
    narrow,
    child.heightAnchor.equalToConstant(50),
    child.leadingAnchor.equalTo(content.leadingAnchor, 0),
    child.bottomAnchor.equalTo(content.bottomAnchor, 0)
  ])

  t.equal(narrow.active, true, 'activated')

  await afterAnimationFrame()

  t.equal(child.frame.width, 100, 'first width')

  LayoutConstraint.deactivate([narrow])
  wide.active = true

  t.equal(narrow.active, false, 'deactivated')

  await afterAnimationFrame()

  t.equal(child.frame.width, 200, 'second width')
})

test('yields to a higher priority', async (t) => {
  const window = open(t, 300, 200)
  const content = window.contentView

  const child = constrain(content)

  const weak = child.widthAnchor.equalToConstant(250)
  weak.priority = LayoutConstraint.LAYOUT_PRIORITY.DEFAULT_LOW

  LayoutConstraint.activate([
    weak,
    child.widthAnchor.lessThanOrEqualToConstant(120),
    child.heightAnchor.equalToConstant(50),
    child.leadingAnchor.equalTo(content.leadingAnchor, 0),
    child.bottomAnchor.equalTo(content.bottomAnchor, 0)
  ])

  await afterAnimationFrame()

  t.equal(child.frame.width, 120)
})

test('centers and scales relative to another view', async (t) => {
  const window = open(t, 300, 200)
  const content = window.contentView

  const child = constrain(content)

  LayoutConstraint.activate([
    child.centerXAnchor.equalTo(content.centerXAnchor, 0),
    child.centerYAnchor.equalTo(content.centerYAnchor, 0),
    child.widthAnchor.equalToMultiple(content.widthAnchor, 0.5, 0),
    child.heightAnchor.equalToMultiple(content.heightAnchor, 0.25, 10)
  ])

  await afterAnimationFrame()

  t.deepStrictEqual(child.frame, { x: 75, y: 70, width: 150, height: 60 })
})
