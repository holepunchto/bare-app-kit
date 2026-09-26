const binding = require('../binding')
const { expose } = require('./handle')
const AppKitView = require('./view')

module.exports = exports = class AppKitVisualEffectView extends AppKitView {
  _init(opts) {
    const { x = 0, y = 0, width = 0, height = 0 } = opts

    return binding.visualEffectViewInit(x, y, width, height)
  }

  get material() {
    return binding.visualEffectViewMaterial(this._tag)
  }

  set material(material) {
    binding.visualEffectViewMaterial(this._tag, material)
  }

  get blendingMode() {
    return binding.visualEffectViewBlendingMode(this._tag)
  }

  set blendingMode(blendingMode) {
    binding.visualEffectViewBlendingMode(this._tag, blendingMode)
  }

  get state() {
    return binding.visualEffectViewState(this._tag)
  }

  set state(state) {
    binding.visualEffectViewState(this._tag, state)
  }

  get emphasized() {
    return binding.visualEffectViewEmphasized(this._tag)
  }

  set emphasized(emphasized) {
    binding.visualEffectViewEmphasized(this._tag, emphasized)
  }

  [Symbol.for('bare.inspect')]() {
    return {
      __proto__: { constructor: AppKitVisualEffectView }
    }
  }
}

exports.MATERIAL = {
  TITLEBAR: binding.VISUAL_EFFECT_VIEW_MATERIAL_TITLEBAR,
  SELECTION: binding.VISUAL_EFFECT_VIEW_MATERIAL_SELECTION,
  MENU: binding.VISUAL_EFFECT_VIEW_MATERIAL_MENU,
  POPOVER: binding.VISUAL_EFFECT_VIEW_MATERIAL_POPOVER,
  SIDEBAR: binding.VISUAL_EFFECT_VIEW_MATERIAL_SIDEBAR,
  HEADER_VIEW: binding.VISUAL_EFFECT_VIEW_MATERIAL_HEADER_VIEW,
  SHEET: binding.VISUAL_EFFECT_VIEW_MATERIAL_SHEET,
  WINDOW_BACKGROUND: binding.VISUAL_EFFECT_VIEW_MATERIAL_WINDOW_BACKGROUND,
  HUD_WINDOW: binding.VISUAL_EFFECT_VIEW_MATERIAL_HUD_WINDOW,
  FULL_SCREEN_UI: binding.VISUAL_EFFECT_VIEW_MATERIAL_FULL_SCREEN_UI,
  TOOL_TIP: binding.VISUAL_EFFECT_VIEW_MATERIAL_TOOL_TIP,
  CONTENT_BACKGROUND: binding.VISUAL_EFFECT_VIEW_MATERIAL_CONTENT_BACKGROUND,
  UNDER_WINDOW_BACKGROUND: binding.VISUAL_EFFECT_VIEW_MATERIAL_UNDER_WINDOW_BACKGROUND,
  UNDER_PAGE_BACKGROUND: binding.VISUAL_EFFECT_VIEW_MATERIAL_UNDER_PAGE_BACKGROUND
}

exports.BLENDING_MODE = {
  BEHIND_WINDOW: binding.VISUAL_EFFECT_VIEW_BLENDING_MODE_BEHIND_WINDOW,
  WITHIN_WINDOW: binding.VISUAL_EFFECT_VIEW_BLENDING_MODE_WITHIN_WINDOW
}

exports.STATE = {
  FOLLOWS_WINDOW_ACTIVE_STATE: binding.VISUAL_EFFECT_VIEW_STATE_FOLLOWS_WINDOW_ACTIVE_STATE,
  ACTIVE: binding.VISUAL_EFFECT_VIEW_STATE_ACTIVE,
  INACTIVE: binding.VISUAL_EFFECT_VIEW_STATE_INACTIVE
}

expose(exports)
