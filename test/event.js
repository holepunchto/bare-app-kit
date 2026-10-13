const { test } = require('bare-tap')
const { Application, Button, Event, View } = require('..')
const { open } = require('./helpers')

const { TYPE } = Event

function mouse(window, type, x, y) {
  return Event.mouseEvent(type, x, y, 0, 0, window.windowNumber)
}

test('creates a mouse event', (t) => {
  const event = Event.mouseEvent(TYPE.LEFT_MOUSE_DOWN, 12.5, 34, 0, 56, 78, 0, 2, 0.5)

  t.deepStrictEqual(
    {
      type: event.type,
      locationInWindow: event.locationInWindow,
      timestamp: event.timestamp,
      windowNumber: event.windowNumber,
      clickCount: event.clickCount,
      pressure: event.pressure
    },
    {
      type: TYPE.LEFT_MOUSE_DOWN,
      locationInWindow: { x: 12.5, y: 34 },
      timestamp: 56,
      windowNumber: 78,
      clickCount: 2,
      pressure: 0.5
    }
  )
})

test('sends a mouse event to the view under it', (t) => {
  const window = open(t, 300, 200)
  const view = new View({ x: 30, y: 40, width: 50, height: 60 })

  window.contentView.addSubview(view)

  const events = []

  view.on('mouseDown', ({ x, y }) => events.push(['down', x, y]))
  view.on('mouseUp', ({ x, y }) => events.push(['up', x, y]))

  const { x, y } = view.convertPointToView(10, 20, null)

  window.sendEvent(mouse(window, TYPE.LEFT_MOUSE_DOWN, x, y))
  window.sendEvent(mouse(window, TYPE.LEFT_MOUSE_UP, x, y))

  t.deepStrictEqual(events, [
    ['down', 10, 20],
    ['up', 10, 20]
  ])
})

test('clicks a button', (t) => {
  const window = open(t, 300, 200)
  const button = new Button()

  button.frame = { x: 30, y: 40, width: 100, height: 30 }

  window.contentView.addSubview(button)

  let clicks = 0

  button.on('click', () => clicks++)

  const { x, y } = button.convertPointToView(50, 15, null)

  // A button tracks the mouse by reading the event queue until it is released,
  // so the release has to be waiting there before the press is sent.
  Application.postEvent(mouse(window, TYPE.LEFT_MOUSE_UP, x, y))
  window.sendEvent(mouse(window, TYPE.LEFT_MOUSE_DOWN, x, y))

  t.equal(clicks, 1)
})
