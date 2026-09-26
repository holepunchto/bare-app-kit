import { Wrapper } from 'bare-foundation-registry'
import AppKitView = require('./view')

/** A split view, as an `NSSplitView`. */
interface AppKitSplitView extends AppKitView<AppKitView.Events> {
  vertical: boolean

  /** A `DIVIDER_STYLE` constant. */
  dividerStyle: number

  arrangesAllSubviews: boolean

  readonly dividerThickness: number

  setPosition(position: number, divider: number): this

  setHoldingPriority(priority: number, index: number): this

  holdingPriorityForSubviewAtIndex(index: number): number

  adjustSubviews(): this

  readonly arrangedSubviews: AppKitView[]

  addArrangedSubview(view: Wrapper): this

  insertArrangedSubview(view: Wrapper, index: number): this

  removeArrangedSubview(view: Wrapper): this
}

declare class AppKitSplitView {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly DIVIDER_STYLE: {
    readonly THICK: number
    readonly THIN: number
    readonly PANE_SPLITTER: number
  }
}

export = AppKitSplitView
