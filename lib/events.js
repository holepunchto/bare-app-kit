const binding = require('../binding')

// The mask follows the listeners, so native code only calls into JavaScript
// when something listens. The map is inherited, so a subclass keeps the events
// of its parent.
module.exports = exports = function observe(target) {
  const events = target.constructor._events

  if (events === undefined) return

  // Events the class itself needs, such as a window unregistering itself as it
  // closes, always fire.
  let mask = target.constructor._always || 0

  if (mask !== 0) binding.eventMask(target._tag, mask)

  target.on('newListener', (name) => {
    const bit = events[name]

    if (bit === undefined || (mask & bit) !== 0) return

    mask |= bit

    binding.eventMask(target._tag, mask)
  })

  target.on('removeListener', (name) => {
    const bit = events[name]

    if (bit === undefined || (mask & bit) === 0) return
    if (target.listenerCount(name) > 0) return

    mask &= ~bit

    binding.eventMask(target._tag, mask)
  })
}
