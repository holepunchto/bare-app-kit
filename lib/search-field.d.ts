import AppKitTextField = require('./text-field')

/** A search field, as an `NSSearchField`. */
interface AppKitSearchField<
  M extends Record<keyof M, unknown[]> = AppKitSearchField.Events
> extends AppKitTextField<M> {
  sendsSearchStringImmediately: boolean

  sendsWholeSearchString: boolean

  maximumRecents: number

  recentsAutosaveName: string | null

  get recentSearches(): string[]
  set recentSearches(value: string[])
}

declare class AppKitSearchField<M extends Record<keyof M, unknown[]> = AppKitSearchField.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })
}

declare namespace AppKitSearchField {
  export interface Events {
    change: []
    didChange: []
    didBeginEditing: []
    didEndEditing: []
    didStartSearching: []
    didEndSearching: []
  }
}

export = AppKitSearchField
