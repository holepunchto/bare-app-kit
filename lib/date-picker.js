const binding = require('../binding')
const { adopt, expose } = require('./handle')
const wrap = require('./wrap')
const AppKitColor = require('./color')
const AppKitControl = require('./control')

module.exports = exports = class AppKitDatePicker extends AppKitControl {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.datePickerInit(x, y, width, height, this)
  }

  get dateValue() {
    const value = binding.datePickerDateValue(this._tag)

    return value === null ? null : new Date(value)
  }

  set dateValue(dateValue) {
    binding.datePickerDateValue(this._tag, dateValue === null ? null : dateValue.getTime())
  }

  get minDate() {
    const value = binding.datePickerMinDate(this._tag)

    return value === null ? null : new Date(value)
  }

  set minDate(minDate) {
    binding.datePickerMinDate(this._tag, minDate === null ? null : minDate.getTime())
  }

  get maxDate() {
    const value = binding.datePickerMaxDate(this._tag)

    return value === null ? null : new Date(value)
  }

  set maxDate(maxDate) {
    binding.datePickerMaxDate(this._tag, maxDate === null ? null : maxDate.getTime())
  }

  get timeInterval() {
    return binding.datePickerTimeInterval(this._tag)
  }

  set timeInterval(timeInterval) {
    binding.datePickerTimeInterval(this._tag, timeInterval)
  }

  get datePickerStyle() {
    return binding.datePickerDatePickerStyle(this._tag)
  }

  set datePickerStyle(datePickerStyle) {
    binding.datePickerDatePickerStyle(this._tag, datePickerStyle)
  }

  get datePickerMode() {
    return binding.datePickerDatePickerMode(this._tag)
  }

  set datePickerMode(datePickerMode) {
    binding.datePickerDatePickerMode(this._tag, datePickerMode)
  }

  get datePickerElements() {
    return binding.datePickerDatePickerElements(this._tag)
  }

  set datePickerElements(datePickerElements) {
    binding.datePickerDatePickerElements(this._tag, datePickerElements)
  }

  get drawsBackground() {
    return binding.datePickerDrawsBackground(this._tag)
  }

  set drawsBackground(drawsBackground) {
    binding.datePickerDrawsBackground(this._tag, drawsBackground)
  }

  get bordered() {
    return binding.datePickerBordered(this._tag)
  }

  set bordered(bordered) {
    binding.datePickerBordered(this._tag, bordered)
  }

  get bezeled() {
    return binding.datePickerBezeled(this._tag)
  }

  set bezeled(bezeled) {
    binding.datePickerBezeled(this._tag, bezeled)
  }

  get textColor() {
    return wrap(AppKitColor, binding.datePickerTextColor(this._tag))
  }

  set textColor(textColor) {
    binding.datePickerTextColor(this._tag, adopt(textColor))
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitDatePicker }
    }
  }

  _onchange() {
    this.emit('change')
  }
}

exports._events = {
  change: 1
}

exports.STYLE = {
  TEXT_FIELD_AND_STEPPER: binding.DATE_PICKER_STYLE_TEXT_FIELD_AND_STEPPER,
  CLOCK_AND_CALENDAR: binding.DATE_PICKER_STYLE_CLOCK_AND_CALENDAR,
  TEXT_FIELD: binding.DATE_PICKER_STYLE_TEXT_FIELD
}

exports.MODE = {
  SINGLE: binding.DATE_PICKER_MODE_SINGLE,
  RANGE: binding.DATE_PICKER_MODE_RANGE
}

exports.ELEMENTS = {
  HOUR_MINUTE: binding.DATE_PICKER_ELEMENTS_HOUR_MINUTE,
  HOUR_MINUTE_SECOND: binding.DATE_PICKER_ELEMENTS_HOUR_MINUTE_SECOND,
  TIME_ZONE: binding.DATE_PICKER_ELEMENTS_TIME_ZONE,
  YEAR_MONTH: binding.DATE_PICKER_ELEMENTS_YEAR_MONTH,
  YEAR_MONTH_DAY: binding.DATE_PICKER_ELEMENTS_YEAR_MONTH_DAY,
  ERA: binding.DATE_PICKER_ELEMENTS_ERA
}

expose(exports)
