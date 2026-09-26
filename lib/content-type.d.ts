import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'

/** A content type, as a `UTType`. */
interface AppKitContentType {
  readonly identifier: string | null

  readonly preferredFilenameExtension: string | null

  readonly preferredMIMEType: string | null

  readonly localizedDescription: string | null

  readonly dynamic: boolean

  readonly declared: boolean

  readonly publicType: boolean

  conformsTo(other: Wrapper): boolean

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitContentType {
  protected constructor()

  static withIdentifier(identifier: string | null): AppKitContentType | null

  static withFilenameExtension(extension: string | null): AppKitContentType | null

  static withMIMEType(mimeType: string | null): AppKitContentType | null

  static readonly item: AppKitContentType

  static readonly content: AppKitContentType

  static readonly data: AppKitContentType

  static readonly directory: AppKitContentType

  static readonly folder: AppKitContentType

  static readonly package: AppKitContentType

  static readonly bundle: AppKitContentType

  static readonly application: AppKitContentType

  static readonly applicationBundle: AppKitContentType

  static readonly executable: AppKitContentType

  static readonly symbolicLink: AppKitContentType

  static readonly aliasFile: AppKitContentType

  static readonly volume: AppKitContentType

  static readonly diskImage: AppKitContentType

  static readonly url: AppKitContentType

  static readonly fileUrl: AppKitContentType

  static readonly text: AppKitContentType

  static readonly plainText: AppKitContentType

  static readonly utf8PlainText: AppKitContentType

  static readonly delimitedText: AppKitContentType

  static readonly commaSeparatedText: AppKitContentType

  static readonly tabSeparatedText: AppKitContentType

  static readonly rtf: AppKitContentType

  static readonly html: AppKitContentType

  static readonly xml: AppKitContentType

  static readonly yaml: AppKitContentType

  static readonly json: AppKitContentType

  static readonly propertyList: AppKitContentType

  static readonly sourceCode: AppKitContentType

  static readonly cSource: AppKitContentType

  static readonly cHeader: AppKitContentType

  static readonly objectiveCSource: AppKitContentType

  static readonly swiftSource: AppKitContentType

  static readonly javascript: AppKitContentType

  static readonly shellScript: AppKitContentType

  static readonly pythonScript: AppKitContentType

  static readonly makefile: AppKitContentType

  static readonly pdf: AppKitContentType

  static readonly epub: AppKitContentType

  static readonly webArchive: AppKitContentType

  static readonly image: AppKitContentType

  static readonly png: AppKitContentType

  static readonly jpeg: AppKitContentType

  static readonly gif: AppKitContentType

  static readonly tiff: AppKitContentType

  static readonly bmp: AppKitContentType

  static readonly icns: AppKitContentType

  static readonly ico: AppKitContentType

  static readonly svg: AppKitContentType

  static readonly webp: AppKitContentType

  static readonly heic: AppKitContentType

  static readonly rawImage: AppKitContentType

  static readonly livePhoto: AppKitContentType

  static readonly audiovisualContent: AppKitContentType

  static readonly movie: AppKitContentType

  static readonly video: AppKitContentType

  static readonly audio: AppKitContentType

  static readonly quicktimeMovie: AppKitContentType

  static readonly mpeg4Movie: AppKitContentType

  static readonly mpeg4Audio: AppKitContentType

  static readonly mp3: AppKitContentType

  static readonly wav: AppKitContentType

  static readonly aiff: AppKitContentType

  static readonly midi: AppKitContentType

  static readonly archive: AppKitContentType

  static readonly zip: AppKitContentType

  static readonly gzip: AppKitContentType

  static readonly spreadsheet: AppKitContentType

  static readonly presentation: AppKitContentType

  static readonly database: AppKitContentType

  static readonly font: AppKitContentType

  static readonly contact: AppKitContentType

  static readonly vcard: AppKitContentType

  static readonly calendarEvent: AppKitContentType

  static readonly emailMessage: AppKitContentType

  static readonly log: AppKitContentType

  static readonly css: AppKitContentType | null

  static readonly tarArchive: AppKitContentType | null

  static readonly geojson: AppKitContentType | null

  static readonly markdown: AppKitContentType | null
}

export = AppKitContentType
