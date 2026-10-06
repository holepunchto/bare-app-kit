const { test } = require('bare-tap')
const { Color, Font, Image, Screen, TextField } = require('..')

test('creates a color', (t) => {
  const color = Color.rgb(1, 0.5, 0, 0.25)

  t.equal(color.alphaComponent, 0.25, 'alpha')
  t.equal(color.withAlphaComponent(0.75).alphaComponent, 0.75, 'with alpha')
  t.equal(Color.white(0.5).alphaComponent, 1, 'opaque by default')
})

test('returns the same system color', (t) => {
  t.ok(Color.systemRedColor === Color.systemRedColor)
})

test('returns the wrapper of an assigned color', (t) => {
  const field = new TextField()
  const color = Color.systemRedColor

  field.textColor = color

  t.ok(field.textColor === color)
})

test('creates a font', (t) => {
  const font = Font.systemFont(13)

  t.equal(font.pointSize, 13, 'size')
  t.ok(font.ascender > 0, 'ascender')
  t.ok(font.descender < 0, 'descender')

  t.equal(Font.boldSystemFont(20).pointSize, 20, 'bold')
  t.equal(Font.monospacedSystemFont(12).fixedPitch, true, 'monospaced')
})

test('finds a font by name', (t) => {
  const font = Font.withName('Helvetica', 12)

  t.equal(font.familyName, 'Helvetica', 'found')
  t.equal(Font.withName('No Such Font', 12), null, 'missing')
})

test('creates an image', (t) => {
  const image = Image.withSize(30, 20)

  t.deepStrictEqual(image.size, { width: 30, height: 20 }, 'size')

  image.size = { width: 60, height: 40 }

  t.deepStrictEqual(image.size, { width: 60, height: 40 }, 'resized')

  image.template = true

  t.equal(image.template, true, 'template')
})

test('finds a symbol image', (t) => {
  t.ok(Image.withSystemSymbolName('star') !== null, 'found')
  t.equal(Image.withSystemSymbolName('no.such.symbol'), null, 'missing')
  t.equal(Image.withContentsOfFile('/no/such/file.png'), null, 'missing file')
})

test('describes the main screen', (t) => {
  const screen = Screen.main()

  t.ok(Screen.count() >= 1, 'at least one')
  t.ok(screen.frame.width > 0 && screen.frame.height > 0, 'has a size')
  t.ok(screen.backingScaleFactor >= 1, 'scale factor')
  t.ok(screen.visibleFrame.height <= screen.frame.height, 'visible frame within the frame')
})
