import { tag, handle, Handle } from 'bare-foundation-registry'

/** A pasteboard, as an `NSPasteboard`. */
interface AppKitPasteboard {
  readonly name: string | null

  readonly changeCount: number

  readonly types: string[]

  clearContents(): number

  /** `type` is a `TYPE` constant. */
  setString(string: string | null, type: string | null): boolean

  /** `type` is a `TYPE` constant. */
  stringForType(type: string | null): string | null

  /** `type` is a `TYPE` constant. */
  setData(data: ArrayBuffer, type: string | null): boolean

  /** `type` is a `TYPE` constant. */
  dataForType(type: string | null): ArrayBuffer | null

  availableTypeFrom(types: string[]): string | null

  declareTypes(types: string[]): number

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitPasteboard {
  protected constructor()

  static general(): AppKitPasteboard | null

  static withName(name: string | null): AppKitPasteboard | null

  static withUniqueName(): AppKitPasteboard | null

  static readonly TYPE: {
    readonly STRING: string
    readonly URL: string
    readonly FILE_URL: string
    readonly PNG: string
    readonly TIFF: string
    readonly PDF: string
    readonly RTF: string
    readonly HTML: string
    readonly COLOR: string
    readonly SOUND: string
  }
}

export = AppKitPasteboard
