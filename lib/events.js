const binding = require('../binding')

// The delivery mask follows the listeners, so a native callback only crosses
// into JS when something is actually listening for what it emits.
//
// The map is inherited, so subclassing a widget in JS keeps its events. A
// subclass whose native class cannot deliver them simply never has the mask
// applied, which is what it did before there was a mask at all.
module.exports = exports = function observe(target) {
  const events = target.constructor._events

  if (events === undefined) return

  // Events the class itself depends on, such as a window unregistering itself
  // as it closes, fire whether or not anyone subscribed.
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
