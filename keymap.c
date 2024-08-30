#include QMK_KEYBOARD_H
#include "custom/i3.h"
#include "custom/macros.h"
#include "custom/modifiers.h"
#include "custom/tapdance.h"

enum layers {
  BASE,
  GAME,
  SYMB,
  TMUX,
  NUM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(
      _______,  KC_EXLM, _______, KC_QUOT,    KC_DQUO,  _______, TG(GAME),
      KC_DEL,   KC_Q,    KC_W,    KC_F,       KC_P,     KC_G,    RGB_M_SW,
      _______,  MY_A,    MY_R,    KC_S,       MY_T,     KC_D,
      _______,  KC_Z,    KC_X,    KC_C,       KC_V,     KC_B,    S_INTL,
      _______, _______,  KC_CAPS, _______, MO(NUM),
              ALT_T(KC_APP), KC_LGUI,
                             KC_HOME,
      MY_SPC, KC_BSPC,       KC_ESC,

      TG(GAME), _______, _______, KC_TILD, _______, _______, _______,
      CW_TOGG,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
      KC_H,     MY_N,    MY_E,    MY_I,    MY_O,    E_JOY,
      _______,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, E_THMUP,
      MO(SYMB), _______, _______, _______, _______,
      KC_PGUP,  KC_LALT,
      KC_PGDN,
      OSM(MOD_RALT), KC_TAB,  KC_ENT
  ),
  [GAME] = LAYOUT_ergodox(
      KC_TAB,   _______, _______, _______, _______, _______, _______,
      _______,  _______, _______, _______, _______, _______, _______,
      KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    _______,
      KC_LSFT,  _______, _______, _______, _______, _______, _______,
      _______,  _______, _______, _______, _______,
                _______, _______,
                         _______,
      KC_SPC,   _______, _______,

      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, KC_N,    KC_E,    KC_I,    KC_O,    _______,
      _______, _______, _______, _______, _______, _______, KC_LSFT,
      _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, _______, _______
  ),
  [SYMB] = LAYOUT_ergodox(
      _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F11,
      _______, _______,  S_TILD,  KC_LCBR, KC_RCBR, KC_DLR, _______,
      _______, KC_AMPR,  KC_PIPE, S_SQTE,  S_DQTE,  S_TICK,
      _______, _______,  KC_PERC, KC_PLUS, KC_EQL,  S_CART, _______,
      _______, _______,  _______, _______, _______,
               _______,  QK_BOOT,
                         _______,
      KC_LEFT, KC_RIGHT, _______,

      KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, KC_MUTE, KC_LPRN, KC_RPRN, KC_ASTR, _______, _______,
               KC_VOLU, KC_COLN, KC_AT,   KC_MINS, KC_HASH, _______,
      _______, KC_VOLD, KC_LBRC, KC_RBRC, _______, _______, _______,
                        _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, _______, _______
  ),
  [TMUX] = LAYOUT_ergodox(
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, T_JN_V,  T_JN_H,  _______, _______,
      _______, T_1,     T_2,     T_3,     T_4,     T_5,
      _______, T_6,     T_7,     T_8,     TRM_PST, T_BRKP,  _______,
      _______, _______, _______, _______, _______,
               _______, _______,
                        _______,
      T_NEW,   T_ZOOM,  _______,

      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, T_CPYM,  _______, T_VS,    T_SP,    _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, _______, T_FNGR
  ),
  [NUM] = LAYOUT_ergodox(
      _______, _______, _______, _______, _______, _______, _______,
      _______, I3_1,    I3_2,    I3_3,    I3_4,    I3_5,    _______,
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
      _______, I3M_1,   I3M_2,   I3M_3,   I3M_4,   I3M_5,   _______,
      _______, _______, _______, _______, _______,
               _______, _______,
                        _______,
      _______, _______, _______,

      _______, _______, _______, _______, _______, _______, _______,
      _______, I3_6,    I3_7,    I3_8,    I3_9,    I3_0,    _______,
      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, I3M_6,   I3M_7,   I3M_8,   I3M_9,   I3M_0,   _______,
      _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, KC_DOWN, KC_UP
  )
};
