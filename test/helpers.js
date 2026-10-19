const AnimationFrameProvider = require('bare-animation-frame')
const { Window } = require('..')

exports.open = function open(t, width, height, opts = {}) {
  const window = new Window({ width, height, ...opts })

  t.teardown(() => window.close())

  window.makeKeyAndOrderFront()

  return window
}

// A window is only brought to the front on the next frame, and a click that
// arrives before then only activates it.
exports.shown = function shown(window) {
  return new AnimationFrameProvider(window).afterAnimationFrame()
}
