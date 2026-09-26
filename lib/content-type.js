const binding = require('../binding')
const wrap = require('./wrap')

module.exports = exports = class AppKitContentType {
  constructor(opts = {}) {
    const { tag = null } = opts

    this._tag = tag

    this._token = binding.claim(this._tag, this)
  }

  static withIdentifier(identifier) {
    return wrap(AppKitContentType, binding.contentTypeWithIdentifier(identifier))
  }

  static withFilenameExtension(extension) {
    return wrap(AppKitContentType, binding.contentTypeWithFilenameExtension(extension))
  }

  static withMIMEType(mimeType) {
    return wrap(AppKitContentType, binding.contentTypeWithMIMEType(mimeType))
  }

  static get item() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_ITEM)
    })
  }

  static get content() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_CONTENT)
    })
  }

  static get data() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_DATA)
    })
  }

  static get directory() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_DIRECTORY)
    })
  }

  static get folder() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_FOLDER)
    })
  }

  static get package() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_PACKAGE)
    })
  }

  static get bundle() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_BUNDLE)
    })
  }

  static get application() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_APPLICATION)
    })
  }

  static get applicationBundle() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_APPLICATION_BUNDLE)
    })
  }

  static get executable() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_EXECUTABLE)
    })
  }

  static get symbolicLink() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_SYMBOLIC_LINK)
    })
  }

  static get aliasFile() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_ALIAS_FILE)
    })
  }

  static get volume() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_VOLUME)
    })
  }

  static get diskImage() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_DISK_IMAGE)
    })
  }

  static get url() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_URL)
    })
  }

  static get fileUrl() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_FILE_URL)
    })
  }

  static get text() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_TEXT)
    })
  }

  static get plainText() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_PLAIN_TEXT)
    })
  }

  static get utf8PlainText() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_UTF8_PLAIN_TEXT)
    })
  }

  static get delimitedText() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_DELIMITED_TEXT)
    })
  }

  static get commaSeparatedText() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_COMMA_SEPARATED_TEXT)
    })
  }

  static get tabSeparatedText() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_TAB_SEPARATED_TEXT)
    })
  }

  static get rtf() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_RTF)
    })
  }

  static get html() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_HTML)
    })
  }

  static get xml() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_XML)
    })
  }

  static get yaml() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_YAML)
    })
  }

  static get json() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_JSON)
    })
  }

  static get propertyList() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_PROPERTY_LIST)
    })
  }

  static get sourceCode() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_SOURCE_CODE)
    })
  }

  static get cSource() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_C_SOURCE)
    })
  }

  static get cHeader() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_C_HEADER)
    })
  }

  static get objectiveCSource() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_OBJECTIVE_C_SOURCE)
    })
  }

  static get swiftSource() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_SWIFT_SOURCE)
    })
  }

  static get javascript() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_JAVASCRIPT)
    })
  }

  static get shellScript() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_SHELL_SCRIPT)
    })
  }

  static get pythonScript() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_PYTHON_SCRIPT)
    })
  }

  static get makefile() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_MAKEFILE)
    })
  }

  static get pdf() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_PDF)
    })
  }

  static get epub() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_EPUB)
    })
  }

  static get webArchive() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_WEB_ARCHIVE)
    })
  }

  static get image() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_IMAGE)
    })
  }

  static get png() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_PNG)
    })
  }

  static get jpeg() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_JPEG)
    })
  }

  static get gif() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_GIF)
    })
  }

  static get tiff() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_TIFF)
    })
  }

  static get bmp() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_BMP)
    })
  }

  static get icns() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_ICNS)
    })
  }

  static get ico() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_ICO)
    })
  }

  static get svg() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_SVG)
    })
  }

  static get webp() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_WEBP)
    })
  }

  static get heic() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_HEIC)
    })
  }

  static get rawImage() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_RAW_IMAGE)
    })
  }

  static get livePhoto() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_LIVE_PHOTO)
    })
  }

  static get audiovisualContent() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_AUDIOVISUAL_CONTENT)
    })
  }

  static get movie() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_MOVIE)
    })
  }

  static get video() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_VIDEO)
    })
  }

  static get audio() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_AUDIO)
    })
  }

  static get quicktimeMovie() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_QUICKTIME_MOVIE)
    })
  }

  static get mpeg4Movie() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_MPEG4_MOVIE)
    })
  }

  static get mpeg4Audio() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_MPEG4_AUDIO)
    })
  }

  static get mp3() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_MP3)
    })
  }

  static get wav() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_WAV)
    })
  }

  static get aiff() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_AIFF)
    })
  }

  static get midi() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_MIDI)
    })
  }

  static get archive() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_ARCHIVE)
    })
  }

  static get zip() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_ZIP)
    })
  }

  static get gzip() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_GZIP)
    })
  }

  static get spreadsheet() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_SPREADSHEET)
    })
  }

  static get presentation() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_PRESENTATION)
    })
  }

  static get database() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_DATABASE)
    })
  }

  static get font() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_FONT)
    })
  }

  static get contact() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_CONTACT)
    })
  }

  static get vcard() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_VCARD)
    })
  }

  static get calendarEvent() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_CALENDAR_EVENT)
    })
  }

  static get emailMessage() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_EMAIL_MESSAGE)
    })
  }

  static get log() {
    return new AppKitContentType({
      tag: binding.contentTypeSystem(binding.CONTENT_TYPE_LOG)
    })
  }

  // Requires macOS 15.0; null on earlier systems.
  static get css() {
    return wrap(AppKitContentType, binding.contentTypeSystem(binding.CONTENT_TYPE_CSS))
  }

  // Requires macOS 15.0; null on earlier systems.
  static get tarArchive() {
    return wrap(AppKitContentType, binding.contentTypeSystem(binding.CONTENT_TYPE_TAR_ARCHIVE))
  }

  // Requires macOS 15.0; null on earlier systems.
  static get geojson() {
    return wrap(AppKitContentType, binding.contentTypeSystem(binding.CONTENT_TYPE_GEOJSON))
  }

  // Requires macOS 27.0; null on earlier systems.
  static get markdown() {
    return wrap(AppKitContentType, binding.contentTypeSystem(binding.CONTENT_TYPE_MARKDOWN))
  }

  get identifier() {
    return binding.contentTypeIdentifier(this._tag)
  }

  get preferredFilenameExtension() {
    return binding.contentTypePreferredFilenameExtension(this._tag)
  }

  get preferredMIMEType() {
    return binding.contentTypePreferredMIMEType(this._tag)
  }

  get localizedDescription() {
    return binding.contentTypeLocalizedDescription(this._tag)
  }

  get dynamic() {
    return binding.contentTypeDynamic(this._tag)
  }

  get declared() {
    return binding.contentTypeDeclared(this._tag)
  }

  get publicType() {
    return binding.contentTypePublicType(this._tag)
  }

  conformsTo(other) {
    return binding.contentTypeConformsTo(this._tag, other._tag)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitContentType }
    }
  }
}
