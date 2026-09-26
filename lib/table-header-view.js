const binding = require('../binding')
const AppKitView = require('./view')

module.exports = exports = class AppKitTableHeaderView extends AppKitView {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.tableHeaderViewInit(x, y, width, height)
  }

  get draggedColumn() {
    return binding.tableHeaderViewDraggedColumn(this._tag)
  }

  get resizedColumn() {
    return binding.tableHeaderViewResizedColumn(this._tag)
  }

  get draggedDistance() {
    return binding.tableHeaderViewDraggedDistance(this._tag)
  }

  columnAtPoint(x, y) {
    return binding.tableHeaderViewColumnAtPoint(this._tag, x, y)
  }

  headerRectOfColumn(column) {
    return binding.tableHeaderViewHeaderRectOfColumn(this._tag, column)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitTableHeaderView }
    }
  }
}
