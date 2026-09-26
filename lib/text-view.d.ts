import { Wrapper } from 'bare-foundation-registry'
import AppKitAttributedString = require('./attributed-string')
import AppKitColor = require('./color')
import AppKitText = require('./text')
import AppKitTextContainer = require('./text-container')

/** A text view, as an `NSTextView`. */
interface AppKitTextView<
  M extends Record<keyof M, unknown[]> = AppKitTextView.Events
> extends AppKitText<M> {
  readonly textContainer: AppKitTextContainer | null

  get textContainerInset(): { width: number; height: number }
  set textContainerInset(value: Partial<{ width: number; height: number }>)

  get insertionPointColor(): AppKitColor | null
  set insertionPointColor(value: Wrapper)

  allowsUndo: boolean

  allowsImageEditing: boolean

  allowsDocumentBackgroundColorChange: boolean

  displaysLinkToolTips: boolean

  usesFindBar: boolean

  usesFindPanel: boolean

  usesRuler: boolean

  usesInspectorBar: boolean

  incrementalSearchingEnabled: boolean

  continuousSpellCheckingEnabled: boolean

  grammarCheckingEnabled: boolean

  automaticSpellingCorrectionEnabled: boolean

  automaticQuoteSubstitutionEnabled: boolean

  automaticDashSubstitutionEnabled: boolean

  automaticTextReplacementEnabled: boolean

  automaticLinkDetectionEnabled: boolean

  smartInsertDeleteEnabled: boolean

  insertText(string: string | null): this

  scrollRangeToVisible(location: number, length: number): this

  didChangeText(): this

  alignLeft(): this

  alignCenter(): this

  alignRight(): this

  checkTextInDocument(): this

  attributedString(): AppKitAttributedString | null

  setAttributedString(string: Wrapper): this
}

declare class AppKitTextView<M extends Record<keyof M, unknown[]> = AppKitTextView.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })
}

declare namespace AppKitTextView {
  export interface Events {
    didChange: []
    didBeginEditing: []
    didEndEditing: []
    didChangeSelection: []
    shouldChangeText: [edit: { location: number; length: number; string: string }]
    becomeFirstResponder: []
    willDraw: []
  }
}

export = AppKitTextView
