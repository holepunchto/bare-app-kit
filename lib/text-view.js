const binding = require('../binding')
const { adopt, expose } = require('./handle')
const scratch = require('./scratch')
const wrap = require('./wrap')
const AppKitAttributedString = require('./attributed-string')
const AppKitColor = require('./color')
const AppKitText = require('./text')
const AppKitTextContainer = require('./text-container')

module.exports = exports = class AppKitTextView extends AppKitText {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.textViewInit(x, y, width, height, this)
  }

  get textContainer() {
    return wrap(AppKitTextContainer, binding.textViewTextContainer(this._tag))
  }

  get textContainerInset() {
    binding.textViewTextContainerInsetInto(this._tag, scratch.buffer, 0)

    return { width: scratch[0], height: scratch[1] }
  }

  set textContainerInset(textContainerInset) {
    const { width = 0, height = 0 } = textContainerInset

    binding.textViewTextContainerInset(this._tag, width, height)
  }

  get insertionPointColor() {
    return wrap(AppKitColor, binding.textViewInsertionPointColor(this._tag))
  }

  set insertionPointColor(insertionPointColor) {
    binding.textViewInsertionPointColor(this._tag, adopt(insertionPointColor))
  }

  get allowsUndo() {
    return binding.textViewAllowsUndo(this._tag)
  }

  set allowsUndo(allowsUndo) {
    binding.textViewAllowsUndo(this._tag, allowsUndo)
  }

  get allowsImageEditing() {
    return binding.textViewAllowsImageEditing(this._tag)
  }

  set allowsImageEditing(allowsImageEditing) {
    binding.textViewAllowsImageEditing(this._tag, allowsImageEditing)
  }

  get allowsDocumentBackgroundColorChange() {
    return binding.textViewAllowsDocumentBackgroundColorChange(this._tag)
  }

  set allowsDocumentBackgroundColorChange(allowsDocumentBackgroundColorChange) {
    binding.textViewAllowsDocumentBackgroundColorChange(
      this._tag,
      allowsDocumentBackgroundColorChange
    )
  }

  get displaysLinkToolTips() {
    return binding.textViewDisplaysLinkToolTips(this._tag)
  }

  set displaysLinkToolTips(displaysLinkToolTips) {
    binding.textViewDisplaysLinkToolTips(this._tag, displaysLinkToolTips)
  }

  get usesFindBar() {
    return binding.textViewUsesFindBar(this._tag)
  }

  set usesFindBar(usesFindBar) {
    binding.textViewUsesFindBar(this._tag, usesFindBar)
  }

  get usesFindPanel() {
    return binding.textViewUsesFindPanel(this._tag)
  }

  set usesFindPanel(usesFindPanel) {
    binding.textViewUsesFindPanel(this._tag, usesFindPanel)
  }

  get usesRuler() {
    return binding.textViewUsesRuler(this._tag)
  }

  set usesRuler(usesRuler) {
    binding.textViewUsesRuler(this._tag, usesRuler)
  }

  get usesInspectorBar() {
    return binding.textViewUsesInspectorBar(this._tag)
  }

  set usesInspectorBar(usesInspectorBar) {
    binding.textViewUsesInspectorBar(this._tag, usesInspectorBar)
  }

  get incrementalSearchingEnabled() {
    return binding.textViewIncrementalSearchingEnabled(this._tag)
  }

  set incrementalSearchingEnabled(incrementalSearchingEnabled) {
    binding.textViewIncrementalSearchingEnabled(this._tag, incrementalSearchingEnabled)
  }

  get continuousSpellCheckingEnabled() {
    return binding.textViewContinuousSpellCheckingEnabled(this._tag)
  }

  set continuousSpellCheckingEnabled(continuousSpellCheckingEnabled) {
    binding.textViewContinuousSpellCheckingEnabled(this._tag, continuousSpellCheckingEnabled)
  }

  get grammarCheckingEnabled() {
    return binding.textViewGrammarCheckingEnabled(this._tag)
  }

  set grammarCheckingEnabled(grammarCheckingEnabled) {
    binding.textViewGrammarCheckingEnabled(this._tag, grammarCheckingEnabled)
  }

  get automaticSpellingCorrectionEnabled() {
    return binding.textViewAutomaticSpellingCorrectionEnabled(this._tag)
  }

  set automaticSpellingCorrectionEnabled(automaticSpellingCorrectionEnabled) {
    binding.textViewAutomaticSpellingCorrectionEnabled(
      this._tag,
      automaticSpellingCorrectionEnabled
    )
  }

  get automaticQuoteSubstitutionEnabled() {
    return binding.textViewAutomaticQuoteSubstitutionEnabled(this._tag)
  }

  set automaticQuoteSubstitutionEnabled(automaticQuoteSubstitutionEnabled) {
    binding.textViewAutomaticQuoteSubstitutionEnabled(this._tag, automaticQuoteSubstitutionEnabled)
  }

  get automaticDashSubstitutionEnabled() {
    return binding.textViewAutomaticDashSubstitutionEnabled(this._tag)
  }

  set automaticDashSubstitutionEnabled(automaticDashSubstitutionEnabled) {
    binding.textViewAutomaticDashSubstitutionEnabled(this._tag, automaticDashSubstitutionEnabled)
  }

  get automaticTextReplacementEnabled() {
    return binding.textViewAutomaticTextReplacementEnabled(this._tag)
  }

  set automaticTextReplacementEnabled(automaticTextReplacementEnabled) {
    binding.textViewAutomaticTextReplacementEnabled(this._tag, automaticTextReplacementEnabled)
  }

  get automaticLinkDetectionEnabled() {
    return binding.textViewAutomaticLinkDetectionEnabled(this._tag)
  }

  set automaticLinkDetectionEnabled(automaticLinkDetectionEnabled) {
    binding.textViewAutomaticLinkDetectionEnabled(this._tag, automaticLinkDetectionEnabled)
  }

  get smartInsertDeleteEnabled() {
    return binding.textViewSmartInsertDeleteEnabled(this._tag)
  }

  set smartInsertDeleteEnabled(smartInsertDeleteEnabled) {
    binding.textViewSmartInsertDeleteEnabled(this._tag, smartInsertDeleteEnabled)
  }

  insertText(string) {
    binding.textViewInsertText(this._tag, string)
    return this
  }

  scrollRangeToVisible(location, length) {
    binding.textViewScrollRangeToVisible(this._tag, location, length)
    return this
  }

  didChangeText() {
    binding.textViewDidChangeText(this._tag)
    return this
  }

  alignLeft() {
    binding.textViewAlignLeft(this._tag)
    return this
  }

  alignCenter() {
    binding.textViewAlignCenter(this._tag)
    return this
  }

  alignRight() {
    binding.textViewAlignRight(this._tag)
    return this
  }

  checkTextInDocument() {
    binding.textViewCheckTextInDocument(this._tag)
    return this
  }

  attributedString() {
    return wrap(AppKitAttributedString, binding.textViewAttributedString(this._tag))
  }

  setAttributedString(string) {
    binding.textViewSetAttributedString(this._tag, adopt(string))
    return this
  }

  _onwilldraw() {
    this.emit('willDraw')
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTextView }
    }
  }

  _onchange() {
    this.emit('didChange')
  }

  _onbeginediting() {
    this.emit('didBeginEditing')
  }

  _onendediting() {
    this.emit('didEndEditing')
  }

  _onselectionchange() {
    this.emit('didChangeSelection')
  }

  _onshouldchangetext(location, length, string) {
    this.emit('shouldChangeText', { location, length, string })
  }

  _onbecomefirstresponder() {
    this.emit('becomeFirstResponder')
  }
}

exports._events = {
  didChange: 1,
  didBeginEditing: 2,
  didEndEditing: 4,
  didChangeSelection: 8,
  shouldChangeText: 16,
  becomeFirstResponder: 32,
  willDraw: 64
}

expose(exports)
