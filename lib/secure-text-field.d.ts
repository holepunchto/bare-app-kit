import AppKitTextField = require('./text-field')

/** A secure text field, as an `NSSecureTextField`. */
interface AppKitSecureTextField<
  M extends Record<keyof M, unknown[]> = AppKitSecureTextField.Events
> extends AppKitTextField<M> {}

declare class AppKitSecureTextField<
  M extends Record<keyof M, unknown[]> = AppKitSecureTextField.Events
> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })
}

declare namespace AppKitSecureTextField {
  export interface Events {
    change: []
    didChange: []
    didBeginEditing: []
    didEndEditing: []
    becomeFirstResponder: []
    resignFirstResponder: []
    didChangeSelection: []
    shouldChangeText: [edit: { location: number; length: number; string: string }]
    willDraw: []
  }
}

export = AppKitSecureTextField
