const { test } = require('bare-tap')
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

test('does not click when disabled', (t) => {
  const button = new Button()

  let clicks = 0

  button.on('click', () => clicks++)
  button.enabled = false

  t.equal(button.enabled, false, 'disabled')

  button.performClick()

  t.equal(clicks, 0, 'no click')
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

test('toggles a switch', (t) => {
  const control = new Switch()

  t.equal(control.state, Control.STATE_VALUE.OFF, 'off')

  control.state = Control.STATE_VALUE.ON

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
