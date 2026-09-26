import { Wrapper } from 'bare-foundation-registry'
import AppKitView = require('./view')

/** A stack view, as an `NSStackView`. */
interface AppKitStackView extends AppKitView<AppKitView.Events> {
  /** An `USER_INTERFACE_LAYOUT_ORIENTATION` constant. */
  orientation: number

  /** A `LAYOUT_ATTRIBUTE` constant. */
  alignment: number

  /** A `DISTRIBUTION` constant. */
  distribution: number

  spacing: number

  get edgeInsets(): { top: number; left: number; bottom: number; right: number }
  set edgeInsets(value: Partial<{ top: number; left: number; bottom: number; right: number }>)

  detachesHiddenViews: boolean

  setVisibilityPriority(priority: number, view: Wrapper): this

  setCustomSpacing(spacing: number, view: Wrapper): this

  readonly arrangedSubviews: AppKitView[]

  addArrangedSubview(view: Wrapper): this

  insertArrangedSubview(view: Wrapper, index: number): this

  removeArrangedSubview(view: Wrapper): this

  removeView(view: Wrapper): this
}

declare class AppKitStackView {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly USER_INTERFACE_LAYOUT_ORIENTATION: {
    readonly HORIZONTAL: number
    readonly VERTICAL: number
  }

  static readonly LAYOUT_ATTRIBUTE: {
    readonly LEADING: number
    readonly TRAILING: number
    readonly TOP: number
    readonly BOTTOM: number
    readonly CENTER_X: number
    readonly CENTER_Y: number
    readonly FIRST_BASELINE: number
    readonly WIDTH: number
    readonly HEIGHT: number
  }

  static readonly DISTRIBUTION: {
    readonly GRAVITY_AREAS: number
    readonly FILL: number
    readonly FILL_EQUALLY: number
    readonly FILL_PROPORTIONALLY: number
    readonly EQUAL_SPACING: number
    readonly EQUAL_CENTERING: number
  }

  static readonly VISIBILITY_PRIORITY: {
    readonly MUST_HOLD: number
    readonly DETACH_ONLY_IF_NECESSARY: number
    readonly NOT_VISIBLE: number
  }
}

export = AppKitStackView
