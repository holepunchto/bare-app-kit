import { Wrapper } from 'bare-foundation-registry'
import AppKitColor = require('./color')
import AppKitControl = require('./control')

/** A date picker, as an `NSDatePicker`. */
interface AppKitDatePicker<
  M extends Record<keyof M, unknown[]> = AppKitDatePicker.Events
> extends AppKitControl<M> {
  dateValue: Date | null

  minDate: Date | null

  maxDate: Date | null

  timeInterval: number

  /** A `STYLE` constant. */
  datePickerStyle: number

  /** A `MODE` constant. */
  datePickerMode: number

  datePickerElements: number

  drawsBackground: boolean

  bordered: boolean

  bezeled: boolean

  get textColor(): AppKitColor | null
  set textColor(value: Wrapper)
}

declare class AppKitDatePicker<M extends Record<keyof M, unknown[]> = AppKitDatePicker.Events> {
  constructor(opts?: { x?: number; y?: number; width?: number; height?: number })

  static readonly STYLE: {
    readonly TEXT_FIELD_AND_STEPPER: number
    readonly CLOCK_AND_CALENDAR: number
    readonly TEXT_FIELD: number
  }

  static readonly MODE: {
    readonly SINGLE: number
    readonly RANGE: number
  }

  static readonly ELEMENT_FLAGS: {
    readonly HOUR_MINUTE: number
    readonly HOUR_MINUTE_SECOND: number
    readonly TIME_ZONE: number
    readonly YEAR_MONTH: number
    readonly YEAR_MONTH_DAY: number
    readonly ERA: number
  }
}

declare namespace AppKitDatePicker {
  export interface Events {
    change: []
  }
}

export = AppKitDatePicker
