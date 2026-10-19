const { test } = require('bare-tap')
const AnimationFrameProvider = require('bare-animation-frame')
const Pointer = require('bare-pointer')
const {
  Button,
  Control,
  PopUpButton,
  SegmentedControl,
  Slider,
  Stepper,
  Switch,
  TextField
} = require('..')
const { open } = require('./helpers')

test('cannot create a bare control', (t) => {
  t.throws(() => new Control())
})

test('emits a click', (t) => {
  const button = new Button()

  let clicks = 0

  button.on('click', () => clicks++)
  button.performClick()

  t.equal(clicks, 1)
})

test('clicks a button with the pointer', async (t) => {
  const window = open(t, 300, 200)
  const pointer = new Pointer()

  t.teardown(() => pointer.destroy())

  const button = new Button({ x: 30, y: 40, width: 100, height: 30 })

  window.contentView.addSubview(button)

  let clicks = 0

  button.on('click', () => clicks++)

  await pointer.tap(button)

  t.equal(clicks, 1)
})

test('does not click when disabled', (t) => {
  const button = new Button()

  let clicks = 0

  button.on('click', () => clicks++)
  button.enabled = false

  t.equal(button.enabled, false, 'disabled')

  button.performClick()

  t.equal(clicks, 0, 'no click')
})

test('does not click a disabled button with the pointer', async (t) => {
  const window = open(t, 300, 200)
  const pointer = new Pointer()

  t.teardown(() => pointer.destroy())

  const button = new Button({ x: 30, y: 40, width: 100, height: 30 })

  button.enabled = false

  window.contentView.addSubview(button)

  let clicks = 0

  button.on('click', () => clicks++)

  await pointer.tap(button)

  t.equal(clicks, 0)
})

test('toggles a check box', (t) => {
  const button = new Button()
  button.setButtonType(Button.TYPE.SWITCH)

  t.equal(button.state, Control.STATE_VALUE.OFF, 'off')

  button.performClick()

  t.equal(button.state, Control.STATE_VALUE.ON, 'on after a click')

  button.setNextState()

  t.equal(button.state, Control.STATE_VALUE.OFF, 'off after the next state')

  button.allowsMixedState = true
  button.state = Control.STATE_VALUE.MIXED

  t.equal(button.state, Control.STATE_VALUE.MIXED, 'mixed')
})

test('checks a check box with the pointer', async (t) => {
  const window = open(t, 300, 200)
  const pointer = new Pointer()

  t.teardown(() => pointer.destroy())

  const button = new Button({ x: 30, y: 40, width: 100, height: 30 })

  button.setButtonType(Button.TYPE.SWITCH)
  button.title = 'Check'

  window.contentView.addSubview(button)

  await pointer.tap(button)

  t.equal(button.state, Control.STATE_VALUE.ON, 'on')

  await pointer.tap(button)

  t.equal(button.state, Control.STATE_VALUE.OFF, 'off again')
})

test('sets the title of a button', (t) => {
  const button = new Button()

  button.title = 'Hello'

  t.equal(button.title, 'Hello', 'title')

  button.sizeToFit()

  t.ok(button.frame.width > 0, 'sized to fit')
})

test('converts the value of a control', (t) => {
  const field = new TextField()

  field.stringValue = '42.5'

  t.equal(field.doubleValue, 42.5, 'double')
  t.equal(field.integerValue, 42, 'integer')

  field.integerValue = 7

  t.equal(field.stringValue, '7', 'string')
})

test('round trips a string with non-ASCII characters', (t) => {
  const field = new TextField()

  field.stringValue = 'Grüße 👋'

  t.equal(field.stringValue, 'Grüße 👋')
})

test('sets the placeholder of a text field', (t) => {
  const field = new TextField()

  t.equal(field.placeholderString, null, 'none')

  field.placeholderString = 'Name'

  t.equal(field.placeholderString, 'Name', 'set')
})

test('focuses a text field with the pointer', async (t) => {
  const window = open(t, 300, 200)
  const pointer = new Pointer()

  t.teardown(() => pointer.destroy())

  const field = new TextField({ x: 30, y: 40, width: 200, height: 24 })

  window.contentView.addSubview(field)

  let focused = 0

  field.on('becomeFirstResponder', () => focused++)

  await pointer.tap(field)

  t.equal(focused, 1)
})

test('grows a label with its text', (t) => {
  const field = new TextField()
  field.bezeled = false
  field.editable = false

  field.stringValue = 'A'

  const short = field.intrinsicContentSize.width

  field.stringValue = 'A much longer string'

  t.ok(field.intrinsicContentSize.width > short)
})

test('clamps the value of a slider', (t) => {
  const slider = new Slider()

  slider.minValue = 10
  slider.maxValue = 20

  slider.doubleValue = 15

  t.equal(slider.doubleValue, 15, 'within')

  slider.doubleValue = 30

  t.equal(slider.doubleValue, 20, 'above')

  slider.doubleValue = 0

  t.equal(slider.doubleValue, 10, 'below')
})

test('snaps a slider to tick marks', (t) => {
  const slider = new Slider()

  slider.minValue = 0
  slider.maxValue = 100
  slider.numberOfTickMarks = 5

  t.equal(slider.tickMarkValueAtIndex(1), 25, 'tick mark')
  t.equal(slider.closestTickMarkValueToValue(60), 50, 'closest')

  slider.allowsTickMarkValuesOnly = true
  slider.doubleValue = 60

  t.equal(slider.doubleValue, 50, 'snapped')
})

test('moves a slider to the pointer', async (t) => {
  const window = open(t, 300, 200)
  const pointer = new Pointer()

  t.teardown(() => pointer.destroy())

  const slider = new Slider({ x: 30, y: 40, width: 200, height: 24 })

  slider.minValue = 0
  slider.maxValue = 100
  slider.doubleValue = 0

  window.contentView.addSubview(slider)

  let changes = 0

  slider.on('change', () => changes++)

  await pointer.tap(slider, slider.bounds.width * 0.75)

  t.ok(changes > 0, 'changed')
  t.ok(slider.doubleValue > 50, 'past the middle')
})

test('steps a stepper', (t) => {
  const stepper = new Stepper()

  stepper.minValue = 0
  stepper.maxValue = 10
  stepper.increment = 2.5

  t.equal(stepper.increment, 2.5, 'increment')

  stepper.doubleValue = 20

  t.equal(stepper.doubleValue, 10, 'clamped')

  stepper.valueWraps = true

  t.equal(stepper.valueWraps, true, 'wraps')
})

test('steps a stepper with the pointer', async (t) => {
  const window = open(t, 300, 200)
  const pointer = new Pointer()

  t.teardown(() => pointer.destroy())

  const stepper = new Stepper({ x: 30, y: 40 })

  stepper.minValue = 0
  stepper.maxValue = 10
  stepper.doubleValue = 5

  stepper.sizeToFit()

  window.contentView.addSubview(stepper)

  let changes = 0

  stepper.on('change', () => changes++)

  const { height } = stepper.bounds
  const top = stepper.flipped ? height / 4 : (height * 3) / 4
  const bottom = height - top

  // A stepper only knows where its arrows are once it has been drawn.
  await new AnimationFrameProvider(stepper).afterAnimationFrame()

  await pointer.tap(stepper, undefined, top)

  t.equal(stepper.doubleValue, 6, 'up')

  await pointer.tap(stepper, undefined, bottom)

  t.equal(stepper.doubleValue, 5, 'down')
  t.equal(changes, 2, 'changed twice')
})

test('toggles a switch', (t) => {
  const control = new Switch()

  t.equal(control.state, Control.STATE_VALUE.OFF, 'off')

  control.state = Control.STATE_VALUE.ON

  t.equal(control.state, Control.STATE_VALUE.ON, 'on')
})

test('toggles a switch with the pointer', async (t) => {
  const window = open(t, 300, 200)
  const pointer = new Pointer()

  t.teardown(() => pointer.destroy())

  const control = new Switch({ x: 30, y: 40 })

  control.sizeToFit()

  window.contentView.addSubview(control)

  let changes = 0

  control.on('change', () => changes++)

  await pointer.tap(control)

  t.equal(changes, 1, 'changed')
  t.equal(control.state, Control.STATE_VALUE.ON, 'on')
})

test('labels and selects segments', (t) => {
  const control = new SegmentedControl()

  control.segmentCount = 3

  for (let i = 0; i < 3; i++) control.setLabelForSegment(`Segment ${i}`, i)

  t.equal(control.segmentCount, 3, 'count')
  t.equal(control.labelForSegment(1), 'Segment 1', 'label')
  t.equal(control.selectedSegment, -1, 'nothing selected')

  control.selectedSegment = 2

  t.equal(control.selectedSegment, 2, 'selected')
  t.equal(control.selectedForSegment(2), true, 'segment knows it is selected')

  control.setEnabledForSegment(false, 0)

  t.equal(control.enabledForSegment(0), false, 'disabled segment')

  control.setTagForSegment(42, 1)

  t.equal(control.tagForSegment(1), 42, 'tag')
})

test('selects a segment with the pointer', async (t) => {
  const window = open(t, 300, 200)
  const pointer = new Pointer()

  t.teardown(() => pointer.destroy())

  const control = new SegmentedControl({ x: 30, y: 40 })

  control.segmentCount = 3

  for (let i = 0; i < 3; i++) {
    control.setLabelForSegment(`Segment ${i}`, i)
    control.setWidthForSegment(60, i)
  }

  control.sizeToFit()

  window.contentView.addSubview(control)

  let changes = 0

  control.on('change', () => changes++)

  await pointer.tap(control, control.bounds.width - 30)

  t.equal(changes, 1, 'changed')
  t.equal(control.selectedSegment, 2, 'last segment')
})

test('manages the items of a pop up button', (t) => {
  const button = new PopUpButton()

  button.addItemsWithTitles(['One', 'Two', 'Three'])

  t.equal(button.numberOfItems, 3, 'count')
  t.deepStrictEqual(button.itemTitles, ['One', 'Two', 'Three'], 'titles')
  t.equal(button.indexOfSelectedItem, 0, 'first selected')

  button.selectItemWithTitle('Three')

  t.equal(button.indexOfSelectedItem, 2, 'selected by title')
  t.equal(button.titleOfSelectedItem, 'Three', 'title of selected')

  button.removeItemAtIndex(0)

  t.equal(button.itemTitleAtIndex(0), 'Two', 'shifted')
  t.equal(button.indexOfItemWithTitle('One'), -1, 'removed')

  t.equal(button.menu.numberOfItems, 2, 'backed by a menu')
})
