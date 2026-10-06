const { test } = require('bare-tap')
const { ScrollView, View } = require('..')
const { open } = require('./helpers')

function scroll(t) {
  const window = open(t, 200, 100)

  const scrollView = new ScrollView({ width: 200, height: 100 })
  const document = new View({ width: 200, height: 1000 })

  scrollView.documentView = document
  window.contentView = scrollView

  return { scrollView, document }
}

test('holds a document view', (t) => {
  const { scrollView, document } = scroll(t)

  t.ok(scrollView.documentView === document, 'document view')
  t.ok(document.superview === scrollView.contentView, 'inside the clip view')
  t.ok(document.enclosingScrollView === scrollView, 'enclosing scroll view')
  t.ok(scrollView.contentView === scrollView.contentView, 'same clip view')
})

test('scrolls the clip view', (t) => {
  const { scrollView } = scroll(t)
  const clipView = scrollView.contentView

  let changes = 0

  clipView.on('boundsDidChange', () => changes++)
  clipView.scrollToPoint(0, 300)
  scrollView.reflectScrolledClipView(clipView)

  t.equal(changes, 1, 'emits')
  t.equal(clipView.bounds.y, 300, 'clip view')
  t.equal(scrollView.documentVisibleRect.y, 300, 'visible rect')
})

test('scrolls a point into view', (t) => {
  const { scrollView, document } = scroll(t)

  document.scrollPointToVisible(0, 600)

  t.equal(scrollView.contentView.bounds.y, 600, 'clip view')
  t.equal(document.visibleRect.y, 600, 'visible rect')
})

test('sets the content insets', (t) => {
  const { scrollView } = scroll(t)

  scrollView.automaticallyAdjustsContentInsets = false
  scrollView.contentInsets = { top: 10, left: 0, bottom: 20, right: 0 }

  t.deepStrictEqual(scrollView.contentInsets, { top: 10, left: 0, bottom: 20, right: 0 })
})

test('magnifies', (t) => {
  const { scrollView } = scroll(t)

  scrollView.allowsMagnification = true
  scrollView.maxMagnification = 4
  scrollView.magnification = 2

  t.equal(scrollView.magnification, 2, 'within')

  scrollView.magnification = 8

  t.equal(scrollView.magnification, 4, 'clamped')
})
