const { Window } = require('..')

exports.open = function open(t, width, height, opts = {}) {
  const window = new Window({ width, height, ...opts })

  t.teardown(() => window.close())

  window.makeKeyAndOrderFront()

  return window
}
