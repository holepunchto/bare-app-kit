import AppKitControl = require('./control')

/** A segmented control, as an `NSSegmentedControl`. */
interface AppKitSegmentedControl<
  M extends Record<keyof M, unknown[]> = AppKitSegmentedControl.Events
> extends AppKitControl<M> {
  segmentCount: number

  selectedSegment: number

  /** A `SEGMENT_STYLE` constant. */
  segmentStyle: number

  trackingMode: number

  /** A `SEGMENT_DISTRIBUTION` constant. */
  segmentDistribution: number

  setLabelForSegment(label: string | null, segment: number): this

  labelForSegment(segment: number): string | null

  setWidthForSegment(width: number, segment: number): this

  widthForSegment(segment: number): number

  setSelectedForSegment(selected: boolean, segment: number): this

  selectedForSegment(segment: number): boolean

  setEnabledForSegment(enabled: boolean, segment: number): this

  enabledForSegment(segment: number): boolean

  setToolTipForSegment(toolTip: string | null, segment: number): this

  toolTipForSegment(segment: number): string | null

  setTagForSegment(tag: number, segment: number): this

  tagForSegment(segment: number): number
}

declare class AppKitSegmentedControl<
  M extends Record<keyof M, unknown[]> = AppKitSegmentedControl.Events
> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly SEGMENT_STYLE: {
    readonly AUTOMATIC: number
    readonly ROUNDED: number
    readonly ROUND_RECT: number
    readonly TEXTURED_SQUARE: number
    readonly SMALL_SQUARE: number
    readonly SEPARATED: number
  }

  static readonly SEGMENT_SWITCH_TRACKING: {
    readonly SELECT_ONE: number
    readonly SELECT_ANY: number
    readonly MOMENTARY: number
    readonly MOMENTARY_ACCELERATOR: number
  }

  static readonly SEGMENT_DISTRIBUTION: {
    readonly FIT: number
    readonly FILL: number
    readonly FILL_EQUALLY: number
    readonly FILL_PROPORTIONALLY: number
  }
}

declare namespace AppKitSegmentedControl {
  export interface Events {
    change: []
  }
}

export = AppKitSegmentedControl
