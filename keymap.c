#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "kthibodeaux.h"

enum layers {
  _BASE,
  _GAME,
  _SYMB,
  _TMUX,
  _DYN
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  DYNAMIC_MACRO_RANGE
};
void backlight_toggle(void) {}
#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |   1  |   2  |   3  |   4  |   5  | GAME |           | GAME |   6  |   7  |   8  |   9  |   0  |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Del    |   Q  |   W  |   F  |   P  |   G  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |   \    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | Tab    |   A  |  a/R |   S  |  ^/T |   D  |------|           |------|   H  |  ^/N |  t/E |  a/I |   O  |        |
   * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
   * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | DYN  |      |      |      | SYMB |                                       | SYMB |      |      |      | DYN  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Home |       | PgUp |        |      |
   *                                 | Space| BSPC |------|       |------|  TAB   |Enter |
   *                                 |      |      | Esc  |       | PgDn |        |      |
   *                                 `--------------------'       `----------------------'
   */
  [_BASE] = KEYMAP(
      // left hand
      KC_TRNS,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   TG(_GAME),
      KC_DELT,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,   KC_TRNS,
      KC_TAB,   KC_A,    MY_R,    KC_S,    MY_T,    KC_D,
      KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   ALL_T(KC_NO),
      MO(_DYN), KC_TRNS, KC_TRNS, KC_TRNS, MO(_SYMB),
              ALT_T(KC_APP), KC_LGUI,
                             KC_HOME,
      MY_SPC, KC_BSPC,       KC_ESC,
      // right hand
      TG(_GAME),     KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_TRNS,
      KC_TRNS,      KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_BSLS,
      KC_H,         MY_N,    MY_E,    MY_I,    KC_O,   KC_TRNS,
      MEH_T(KC_NO), KC_K,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
      MO(_SYMB),     KC_TRNS, KC_TRNS, KC_TRNS, MO(_DYN),
      KC_LALT, CTL_T(KC_ESC),
      KC_PGUP,
      KC_PGDN, KC_TAB,  KC_ENT
      ),
  /* Keymap 1: Gaming layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      | HOLD |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|   W  |           |      |------+------+------+------+------+--------|
   * |        |      |  R   |      |   T  |      |------|           |------|      |   N  |   E  |  I   |      |        |
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
  [_GAME] = KEYMAP(
      //left hand
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(M_HOLD_W),
      KC_TRNS, KC_TRNS, KC_R,    KC_TRNS, KC_T,    KC_TRNS,
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
   * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |   ~  |   {  |   }  |      |      |           |      | MUTE |   (  |   )  |   `  |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   &  |   |  |   '  |   "  |      |------|           |------| VOLU |   :  |   @  |   -  |  #   |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |   +  |   =  |      |      |           |      | VOLD |   [  |   ]  |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 | Left | Right|------|       |------| Down |  Up  |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [_SYMB] = KEYMAP(
      //left hand
      KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
      KC_TRNS, KC_TRNS, KC_TILD, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_AMPR, KC_PIPE, KC_QUOT, KC_DQUO, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_PLUS, KC_EQL,  KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
               KC_TRNS,  KC_TRNS,
                         KC_TRNS,
      KC_LEFT, KC_RIGHT, KC_TRNS,
      // right hand
      KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
      KC_TRNS, KC_MUTE, KC_LPRN, KC_RPRN, KC_GRV,  KC_TRNS, KC_TRNS,
               KC_VOLU, KC_COLN, KC_AT,   KC_MINS, KC_HASH, KC_TRNS,
      KC_TRNS, KC_VOLD, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_DOWN, KC_UP
      ),
  /* Keymap 3: Tmux layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|      | COPY |XXXXXX| VSP  | SP   |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |PASTE |      |      |           |      |      |STORY |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 | NEW  | ZOOM |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [_TMUX] = KEYMAP(
      //left hand
      KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
      KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
      KC_TRNS, M(M_TMUX_1), M(M_TMUX_2), M(M_TMUX_3), M(M_TMUX_4), M(M_TMUX_5),
      KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     TERM_PASTE,  KC_TRNS,     KC_TRNS,
      KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
                     KC_TRNS,        KC_TRNS,
                                     KC_TRNS,
      M(M_TMUX_NEW), M(M_TMUX_ZOOM), KC_TRNS,
      // right hand
      KC_TRNS, KC_TRNS,             KC_TRNS,                      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,             KC_TRNS,                      KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS,
      KC_TRNS, M(M_TMUX_COPY_MODE), KC_TRNS,                      M(M_TMUX_VS), M(M_TMUX_SP), KC_TRNS,
      KC_TRNS, KC_TRNS,             M(M_TMUX_SHOW_CURRENT_STORY), KC_TRNS,      KC_TRNS,      KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS,             KC_TRNS,                      KC_TRNS,      KC_TRNS,
      KC_TRNS, KC_TRNS,
      KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
      ),
  /* Keymap 4: Dynamic macro layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 | REC 1| REC 2|      |       |      |PLAY 1|PLAY 2|
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [_DYN] = KEYMAP(
      //left hand
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS,         KC_TRNS,
                                       KC_TRNS,
      DYN_REC_START1, DYN_MACRO_PLAY1, KC_TRNS,
      // right hand
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,        KC_TRNS,
      KC_TRNS,
      DYN_REC_START2, DYN_MACRO_PLAY2, KC_TRNS
      ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
    return true;
}

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
    case 4:
      ergodox_right_led_on(1);
      ergodox_right_led_set(1, 5);
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

  // light up blue when holding alt
  if (keyboard_report->mods & MOD_BIT(KC_LALT)) {
    ergodox_right_led_on(3);
    ergodox_right_led_set(3, 100);
  }
};
