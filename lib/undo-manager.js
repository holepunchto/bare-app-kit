const binding = require('../binding')
const { expose } = require('./handle')
const observe = require('./events')
const EventEmitter = require('bare-events')

module.exports = exports = class AppKitUndoManager extends EventEmitter {
  constructor(opts = {}) {
    super()

    const { tag = null } = opts

    this._tag = tag === null ? this._init(opts) : tag

    this._token = binding.claim(this._tag, this)

    observe(this)
  }

  _init() {
    return binding.undoManagerInit()
  }

  get canUndo() {
    return binding.undoManagerCanUndo(this._tag)
  }

  get canRedo() {
    return binding.undoManagerCanRedo(this._tag)
  }

  get undoing() {
    return binding.undoManagerUndoing(this._tag)
  }

  get redoing() {
    return binding.undoManagerRedoing(this._tag)
  }

  get undoRegistrationEnabled() {
    return binding.undoManagerUndoRegistrationEnabled(this._tag)
  }

  get groupsByEvent() {
    return binding.undoManagerGroupsByEvent(this._tag)
  }

  set groupsByEvent(groupsByEvent) {
    binding.undoManagerGroupsByEvent(this._tag, groupsByEvent)
  }

  get levelsOfUndo() {
    return binding.undoManagerLevelsOfUndo(this._tag)
  }

  set levelsOfUndo(levelsOfUndo) {
    binding.undoManagerLevelsOfUndo(this._tag, levelsOfUndo)
  }

  get undoActionName() {
    return binding.undoManagerUndoActionName(this._tag)
  }

  get redoActionName() {
    return binding.undoManagerRedoActionName(this._tag)
  }

  get undoMenuItemTitle() {
    return binding.undoManagerUndoMenuItemTitle(this._tag)
  }

  get redoMenuItemTitle() {
    return binding.undoManagerRedoMenuItemTitle(this._tag)
  }

  get groupingLevel() {
    return binding.undoManagerGroupingLevel(this._tag)
  }

  undo() {
    binding.undoManagerUndo(this._tag)
    return this
  }

  redo() {
    binding.undoManagerRedo(this._tag)
    return this
  }

  undoNestedGroup() {
    binding.undoManagerUndoNestedGroup(this._tag)
    return this
  }

  beginUndoGrouping() {
    binding.undoManagerBeginUndoGrouping(this._tag)
    return this
  }

  endUndoGrouping() {
    binding.undoManagerEndUndoGrouping(this._tag)
    return this
  }

  removeAllActions() {
    binding.undoManagerRemoveAllActions(this._tag)
    return this
  }

  disableUndoRegistration() {
    binding.undoManagerDisableUndoRegistration(this._tag)
    return this
  }

  enableUndoRegistration() {
    binding.undoManagerEnableUndoRegistration(this._tag)
    return this
  }

  setActionName(name) {
    binding.undoManagerSetActionName(this._tag, name)
    return this
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitUndoManager }
    }
  }
}

expose(exports)
