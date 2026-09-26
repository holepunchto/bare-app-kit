const binding = require('../binding')
const AppKitTextField = require('./text-field')

module.exports = exports = class AppKitComboBox extends AppKitTextField {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.comboBoxInit(x, y, width, height, this)
  }

  get hasVerticalScroller() {
    return binding.comboBoxHasVerticalScroller(this._tag)
  }

  set hasVerticalScroller(hasVerticalScroller) {
    binding.comboBoxHasVerticalScroller(this._tag, hasVerticalScroller)
  }

  get numberOfVisibleItems() {
    return binding.comboBoxNumberOfVisibleItems(this._tag)
  }

  set numberOfVisibleItems(numberOfVisibleItems) {
    binding.comboBoxNumberOfVisibleItems(this._tag, numberOfVisibleItems)
  }

  get usesDataSource() {
    return binding.comboBoxUsesDataSource(this._tag)
  }

  set usesDataSource(usesDataSource) {
    binding.comboBoxUsesDataSource(this._tag, usesDataSource)
  }

  get completes() {
    return binding.comboBoxCompletes(this._tag)
  }

  set completes(completes) {
    binding.comboBoxCompletes(this._tag, completes)
  }

  get buttonBordered() {
    return binding.comboBoxButtonBordered(this._tag)
  }

  set buttonBordered(buttonBordered) {
    binding.comboBoxButtonBordered(this._tag, buttonBordered)
  }

  get itemHeight() {
    return binding.comboBoxItemHeight(this._tag)
  }

  set itemHeight(itemHeight) {
    binding.comboBoxItemHeight(this._tag, itemHeight)
  }

  get intercellSpacing() {
    return binding.comboBoxIntercellSpacing(this._tag)
  }

  set intercellSpacing(intercellSpacing) {
    const { width = 0, height = 0 } = intercellSpacing

    binding.comboBoxIntercellSpacing(this._tag, width, height)
  }

  get numberOfItems() {
    return binding.comboBoxNumberOfItems(this._tag)
  }

  get indexOfSelectedItem() {
    return binding.comboBoxIndexOfSelectedItem(this._tag)
  }

  get objectValueOfSelectedItem() {
    return binding.comboBoxObjectValueOfSelectedItem(this._tag)
  }

  get objectValues() {
    return binding.comboBoxObjectValues(this._tag)
  }

  addItemWithObjectValue(value) {
    binding.comboBoxAddItemWithObjectValue(this._tag, value)
    return this
  }

  insertItemWithObjectValue(value, index) {
    binding.comboBoxInsertItemWithObjectValue(this._tag, value, index)
    return this
  }

  removeItemWithObjectValue(value) {
    binding.comboBoxRemoveItemWithObjectValue(this._tag, value)
    return this
  }

  removeItemAtIndex(index) {
    binding.comboBoxRemoveItemAtIndex(this._tag, index)
    return this
  }

  removeAllItems() {
    binding.comboBoxRemoveAllItems(this._tag)
    return this
  }

  selectItemAtIndex(index) {
    binding.comboBoxSelectItemAtIndex(this._tag, index)
    return this
  }

  deselectItemAtIndex(index) {
    binding.comboBoxDeselectItemAtIndex(this._tag, index)
    return this
  }

  selectItemWithObjectValue(value) {
    binding.comboBoxSelectItemWithObjectValue(this._tag, value)
    return this
  }

  itemObjectValueAtIndex(index) {
    return binding.comboBoxItemObjectValueAtIndex(this._tag, index)
  }

  indexOfItemWithObjectValue(value) {
    return binding.comboBoxIndexOfItemWithObjectValue(this._tag, value)
  }

  reloadData() {
    binding.comboBoxReloadData(this._tag)
    return this
  }

  noteNumberOfItemsChanged() {
    binding.comboBoxNoteNumberOfItemsChanged(this._tag)
    return this
  }

  scrollItemAtIndexToTop(index) {
    binding.comboBoxScrollItemAtIndexToTop(this._tag, index)
    return this
  }

  scrollItemAtIndexToVisible(index) {
    binding.comboBoxScrollItemAtIndexToVisible(this._tag, index)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitComboBox }
    }
  }

  _onselectionchange() {
    this.emit('selectionDidChange')
  }

  _onwillpopup() {
    this.emit('willPopUp')
  }

  _onwilldismiss() {
    this.emit('willDismiss')
  }
}

exports._events = {
  change: 1,
  didChange: 2,
  didBeginEditing: 4,
  didEndEditing: 8,
  selectionDidChange: 16,
  willPopUp: 32,
  willDismiss: 64
}
