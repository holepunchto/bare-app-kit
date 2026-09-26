import { tag, handle, Handle, Wrapper } from 'bare-foundation-registry'

/** A color, as an `NSColor`. */
interface AppKitColor {
  readonly type: number

  readonly numberOfComponents: number

  highlight(level: number): AppKitColor | null

  shadow(level: number): AppKitColor | null

  withSystemEffect(effect: number): AppKitColor | null

  readonly alphaComponent: number

  readonly components: number

  withAlphaComponent(alpha: number): AppKitColor

  blendedColor(fraction: number, color: Wrapper): AppKitColor

  readonly [tag]: number

  readonly [handle]: Handle
}

declare class AppKitColor {
  protected constructor()

  static rgb(red: number, green: number, blue: number, alpha?: number): AppKitColor

  static hsb(hue: number, saturation: number, brightness: number, alpha?: number): AppKitColor

  static white(white: number, alpha?: number): AppKitColor

  static readonly blackColor: AppKitColor

  static readonly whiteColor: AppKitColor

  static readonly clearColor: AppKitColor

  static readonly labelColor: AppKitColor

  static readonly secondaryLabelColor: AppKitColor

  static readonly tertiaryLabelColor: AppKitColor

  static readonly quaternaryLabelColor: AppKitColor

  static readonly textColor: AppKitColor

  static readonly placeholderTextColor: AppKitColor

  static readonly selectedTextColor: AppKitColor

  static readonly textBackgroundColor: AppKitColor

  static readonly selectedTextBackgroundColor: AppKitColor

  static readonly linkColor: AppKitColor

  static readonly separatorColor: AppKitColor

  static readonly gridColor: AppKitColor

  static readonly headerTextColor: AppKitColor

  static readonly controlAccentColor: AppKitColor

  static readonly controlColor: AppKitColor

  static readonly controlBackgroundColor: AppKitColor

  static readonly controlTextColor: AppKitColor

  static readonly disabledControlTextColor: AppKitColor

  static readonly selectedControlColor: AppKitColor

  static readonly selectedControlTextColor: AppKitColor

  static readonly alternateSelectedControlTextColor: AppKitColor

  static readonly selectedContentBackgroundColor: AppKitColor

  static readonly unemphasizedSelectedContentBackgroundColor: AppKitColor

  static readonly windowBackgroundColor: AppKitColor

  static readonly windowFrameTextColor: AppKitColor

  static readonly underPageBackgroundColor: AppKitColor

  static readonly findHighlightColor: AppKitColor

  static readonly highlightColor: AppKitColor

  static readonly shadowColor: AppKitColor

  static readonly systemRedColor: AppKitColor

  static readonly systemOrangeColor: AppKitColor

  static readonly systemYellowColor: AppKitColor

  static readonly systemGreenColor: AppKitColor

  static readonly systemMintColor: AppKitColor

  static readonly systemTealColor: AppKitColor

  static readonly systemCyanColor: AppKitColor

  static readonly systemBlueColor: AppKitColor

  static readonly systemIndigoColor: AppKitColor

  static readonly systemPurpleColor: AppKitColor

  static readonly systemPinkColor: AppKitColor

  static readonly systemBrownColor: AppKitColor

  static readonly systemGrayColor: AppKitColor

  static withPatternImage(image: Wrapper): AppKitColor | null
}

export = AppKitColor
