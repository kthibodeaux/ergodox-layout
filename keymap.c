#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define NOMO 1 // default without extra modifiers
#define SYMB 2 // symbols
#define MDIA 3 // media keys

enum {
  TD_SCLN,
  TD_SPC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   =    |   1  |   2  |   3  |   4  |   5  | MODS |           | MODS |   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Del    |   Q  |   W  |   F  |   P  |   G  |  L2  |           |  L2  |   J  |   L  |   U  |   Y  |   ;  |   \    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | BkSp   |   A  |LGUI/R|LSFT/S|  ^/T |   D  |------|           |------|   H  |  ^/N |LSFT/E|LGUI/I|   O  |' / Cmd |
   * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
   * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L2  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Home |       | PgUp |        |      |
   *                                 | Space| BSPC |------|       |------|  TAB   |Enter |
   *                                 |      |      |^/Esc |       | PgDn |        |      |
   *                                 `--------------------'       `----------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [BASE] = KEYMAP(  // layer 0 : default
      // left hand
      KC_EQL,           KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   TG(NOMO),
      KC_DELT,          KC_Q,         KC_W,   KC_F,   KC_P,   KC_G,   TG(SYMB),
      KC_BSPC,          KC_A,         GUI_T(KC_R), MT(MOD_LSFT, KC_S),   CTL_T(KC_T),   KC_D,
      KC_LSFT,          KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
      LT(MDIA, KC_GRV), KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_RGHT,
      ALT_T(KC_APP),    KC_LGUI,
      KC_HOME,
      TD(TD_SPC),           KC_BSPC,     CTL_T(KC_ESC),
      // right hand
      TG(NOMO),         KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
      TG(SYMB),         KC_J,   KC_L,   KC_U,   KC_Y,   TD(TD_SCLN),             KC_BSLS,
      KC_H,             CTL_T(KC_N),   MT(MOD_LSFT, KC_E), GUI_T(KC_I),   KC_O,          GUI_T(KC_QUOT),
      MEH_T(KC_NO),     KC_K,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,
      KC_UP,            KC_DOWN,KC_LBRC,KC_RBRC,          LT(MDIA, KC_NO),
      KC_LALT,          CTL_T(KC_ESC),
      KC_PGUP,
      KC_PGDN,          KC_TAB, KC_ENT
      ),
  /* Keymap 1: No extra modifiers
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |   R  |   S  |   T  |      |------|           |------|      |   N  |   E  |   I  |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 | SPACE|      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [NOMO] = KEYMAP(  // layer 1 : modifiers
      //left hand
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_R,    KC_S,    KC_T,    KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_SPC, KC_TRNS, KC_TRNS,
      // right hand
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_N,    KC_E,    KC_I,    KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
      ),
  /* Keymap 2: Symbol Layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |Bkspc |      |------|       |------|      | Tab  |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // SYMBOLS
  [SYMB] = KEYMAP(
      // left hand
      M(0),   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
      KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
      KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
      KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
      KC_TRNS,KC_TRNS,
      KC_TRNS,
      KC_BSPC,KC_TRNS,KC_TRNS,
      // right hand
      KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
      KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
      KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
      KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
      KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TAB
      ),
  /* Keymap 3: Media and mouse keys
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |Brwser|
   *                                 |      |      |------|       |------|      |Back  |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // MEDIA AND MOUSE
  [MDIA] = KEYMAP(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,
      // right hand
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
      KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
      KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_WBAK
      ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 2 (Symbols)
};

void do_tap_dance (qk_tap_dance_state_t *state) {
  switch (state->keycode) {
    case TD(TD_SCLN):
      if (state->count == 1) {
        register_code (KC_SCLN);
        unregister_code (KC_SCLN);
      } else {
        register_code (KC_LSFT);
        register_code (KC_SCLN);
        unregister_code (KC_SCLN);
        unregister_code (KC_LSFT);
        reset_tap_dance (state);
      }
      break;
    case TD(TD_SPC):
      if (state->count == 1) {
        register_code (KC_SPC);
        unregister_code (KC_SPC);
      } else {
        register_code (KC_LSFT);
        register_code (KC_MINS);
        unregister_code (KC_MINS);
        unregister_code (KC_LSFT);
        reset_tap_dance (state);
      }
      break;
  }
}

const qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SCLN] = ACTION_TAP_DANCE_FN (do_tap_dance),
  [TD_SPC] = ACTION_TAP_DANCE_FN (do_tap_dance)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case 1:
      ergodox_right_led_on(3);
      ergodox_right_led_set(3, 5);
      break;
    case 2:
      ergodox_right_led_on(2);
      ergodox_right_led_set(2, 5);
      break;
    case 3:
      ergodox_right_led_on(3);
      ergodox_right_led_set(3, 5);
      ergodox_right_led_on(2);
      ergodox_right_led_set(2, 5);
      break;
    default:
      // none
      break;
  }

  // light up red when holding control
  if (keyboard_report->mods & MOD_BIT(KC_LCTRL)) {
    ergodox_right_led_on(1);
    ergodox_right_led_set(1, 100);
  }

  // light up green when holding shift
  if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
    ergodox_right_led_on(2);
    ergodox_right_led_set(2, 100);
  }

  // light up blue when holding gui
  if (keyboard_report->mods & MOD_BIT(KC_LGUI)) {
    ergodox_right_led_on(3);
    ergodox_right_led_set(3, 100);
  }
};
