const binding = require('../binding')
const AppKitTextField = require('./text-field')

module.exports = exports = class AppKitSearchField extends AppKitTextField {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.searchFieldInit(x, y, width, height, this)
  }

  get sendsSearchStringImmediately() {
    return binding.searchFieldSendsSearchStringImmediately(this._tag)
  }

  set sendsSearchStringImmediately(sendsSearchStringImmediately) {
    binding.searchFieldSendsSearchStringImmediately(this._tag, sendsSearchStringImmediately)
  }

  get sendsWholeSearchString() {
    return binding.searchFieldSendsWholeSearchString(this._tag)
  }

  set sendsWholeSearchString(sendsWholeSearchString) {
    binding.searchFieldSendsWholeSearchString(this._tag, sendsWholeSearchString)
  }

  get maximumRecents() {
    return binding.searchFieldMaximumRecents(this._tag)
  }

  set maximumRecents(maximumRecents) {
    binding.searchFieldMaximumRecents(this._tag, maximumRecents)
  }

  get recentsAutosaveName() {
    return binding.searchFieldRecentsAutosaveName(this._tag)
  }

  set recentsAutosaveName(recentsAutosaveName) {
    binding.searchFieldRecentsAutosaveName(this._tag, recentsAutosaveName)
  }

  get recentSearches() {
    return binding.searchFieldRecentSearches(this._tag)
  }

  set recentSearches(recentSearches) {
    binding.searchFieldRecentSearches(this._tag, recentSearches)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitSearchField }
    }
  }

  _onstartsearching() {
    this.emit('didStartSearching')
  }

  _onendsearching() {
    this.emit('didEndSearching')
  }
}

exports._events = {
  change: binding.SEARCH_FIELD_EVENT_CHANGE,
  didChange: binding.SEARCH_FIELD_EVENT_DID_CHANGE,
  didBeginEditing: binding.SEARCH_FIELD_EVENT_DID_BEGIN_EDITING,
  didEndEditing: binding.SEARCH_FIELD_EVENT_DID_END_EDITING,
  didStartSearching: binding.SEARCH_FIELD_EVENT_DID_START_SEARCHING,
  didEndSearching: binding.SEARCH_FIELD_EVENT_DID_END_SEARCHING
}
