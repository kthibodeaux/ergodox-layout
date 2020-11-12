#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "kthibodeaux.h"

enum layers {
  _BASE,
  _GAME,
  _SYMB,
  _TMUX,
  _NUM,
  _EMOJI,
  _SKETCHUP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |   !  |      |      |   $  |   %  | GAME |           | GAME |   ^  |      |   *  |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Del    |   Q  |   W  |   F  |   P  |   G  | RGB  |           | RGB  |   J  |   L  |   U  |   Y  |   ;  |   \    |
   * |--------+------+------+------+------+------| SWRL |           | TOG  |------+------+------+------+------+--------|
   * | Tab    |   A  |  a/R | su/S |  ^/T |   D  |------|           |------|   H  |  ^/N |  t/E |  a/I |   O  |        |
   * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
   * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      | CAPS | EMOJI|  NUM |                                       | SYMB | LEFT | DOWN |  UP  |RIGHT |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Home |       | PgUp |        |      |
   *                                 | Space| BSPC |------|       |------|  TAB   |Enter |
   *                                 |      |      | Esc  |       | PgDn |        |      |
   *                                 `--------------------'       `----------------------'
   */
  [_BASE] = LAYOUT_ergodox(
      // left hand
      _______,  KC_EXLM, _______, _______,    KC_DLR,  KC_PERC, TG(_GAME),
      KC_DELT,  KC_Q,    KC_W,    KC_F,       KC_P,    KC_G,    RGB_M_SW,
      KC_TAB,   MY_A,    MY_R,    MY_S,       MY_T,    KC_D,
      _______,  KC_Z,    KC_X,    KC_C,       KC_V,    KC_B,    ALL_T(KC_NO),
      _______, _______,  KC_CAPS, MO(_EMOJI), MO(_NUM),
              ALT_T(KC_APP), KC_LGUI,
                             KC_HOME,
      MY_SPC, KC_BSPC,       KC_ESC,
      // right hand
      TG(_GAME),    KC_CIRC, _______, KC_ASTR, _______, _______, _______,
      RGB_TOG,      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
      KC_H,         MY_N,    MY_E,    MY_I,    MY_O,    _______,
      MEH_T(KC_NO), KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
      MO(_SYMB),    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
      KC_LALT, CTL_T(KC_ESC),
      KC_PGUP,
      KC_PGDN, KC_TAB,  KC_ENT
      ),
  /* Keymap 1: Game
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |GAME G| HOLD |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------| SFT+W|           |      |------+------+------+------+------+--------|
   * |        |  A   |  R   |  S   |   T  |      |------|           |------|      |   N  |   E  |  I   |  O   |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | Shift  |      |      |      |      |      |      |           |      |      |      |      |      |      | Shift  |
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
  [_GAME] = LAYOUT_ergodox(
      //left hand
      KC_TAB,   _______, _______, _______, _______, _______, _______,
      _______,  _______, _______, _______, _______, _______, M(M_HOLD_SHIFT_W),
      KC_LCTRL, KC_A,    KC_R,    KC_S,    KC_T,    _______,
      KC_LSFT,  _______, _______, _______, _______, _______, _______,
      _______,  _______, _______, _______, _______,
                _______, _______,
                        _______,
      KC_SPC,  _______, _______,
      // right hand
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, KC_N,    KC_E,    KC_I,    KC_O,    _______,
      _______, _______, _______, _______, _______, _______, KC_LSFT,
      _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, _______, _______
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
   *                                        |      |RESET |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 | Left | Right|------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [_SYMB] = LAYOUT_ergodox(
      //left hand
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
      _______, _______, KC_TILD, KC_LCBR, KC_RCBR, _______, _______,
      _______, KC_AMPR, KC_PIPE, KC_QUOT, KC_DQUO, _______,
      _______, _______, _______, KC_PLUS, KC_EQL,  _______, _______,
      _______, _______, _______, _______, _______,
               _______,  RESET,
                         _______,
      KC_LEFT, KC_RIGHT, _______,
      // right hand
      KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, KC_MUTE, KC_LPRN, KC_RPRN, KC_GRV,  _______, _______,
               KC_VOLU, KC_COLN, KC_AT,   KC_MINS, KC_HASH, _______,
      _______, KC_VOLD, KC_LBRC, KC_RBRC, _______, _______, _______,
                        _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, _______, _______
      ),
  /* Keymap 3: Tmux layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |JOIN V|JOIN H|      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|      | COPY |XXXXXX| VSP  | SP   |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   6  |   7  |   8  |PASTE |BREAK |      |           |      |      |STORY |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 | NEW  | ZOOM |------|       |------| OPEN |FINGER|
   *                                 |      |      |      |       |      | URL  |PLUGIN|
   *                                 `--------------------'       `--------------------'
   */
  [_TMUX] = LAYOUT_ergodox(
      //left hand
      _______, _______,     _______,     _______,          _______,          _______,              _______,
      _______, _______,     _______,     M(M_TMUX_JOIN_V), M(M_TMUX_JOIN_H), _______,              _______,
      _______, M(M_TMUX_1), M(M_TMUX_2), M(M_TMUX_3),      M(M_TMUX_4),      M(M_TMUX_5),
      _______, M(M_TMUX_6), M(M_TMUX_7), M(M_TMUX_8),      TERM_PASTE,       M(M_TMUX_BREAK_PANE), _______,
      _______, _______,     _______,     _______,          _______,
                     _______,        _______,
                                     _______,
      M(M_TMUX_NEW), M(M_TMUX_ZOOM), _______,
      // right hand
      _______, _______,             _______,                      _______,      _______,      _______, _______,
      _______, _______,             _______,                      _______,      _______,      _______, _______,
      _______, M(M_TMUX_COPY_MODE), _______,                      M(M_TMUX_VS), M(M_TMUX_SP), _______,
      _______, _______,             M(M_TMUX_SHOW_CURRENT_STORY), _______,      _______,      _______, _______,
      _______, _______,             _______,                      _______,      _______,
      _______, _______,
      _______,
      _______, M(M_TMUX_OPEN_URL), M(M_TMUX_FINGERS_PLUGIN)
      ),
  /* Keymap 4: Numpad
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        | i3 workspace switch
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        | i3 workspace move
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------| Down |  Up  |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [_NUM] = LAYOUT_ergodox(
      //left hand
      _______, _______, _______, _______, _______, _______, _______,
      _______, I3_1,    I3_2,    I3_3,    I3_4,    I3_5,    _______,
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
      _______, I3M_1,   I3M_2,   I3M_3,   I3M_4,   I3M_5,   _______,
      _______, _______, _______, _______, _______,
               _______, _______,
                        _______,
      _______, _______, _______,
      // right hand
      _______, _______, _______, _______, _______, _______, _______,
      _______, I3_6,    I3_7,    I3_8,    I3_9,    I3_0,    _______,
      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      _______, I3M_6,   I3M_7,   I3M_8,   I3M_9,   I3M_0,   _______,
      _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, KC_DOWN, KC_UP
      ),
  /* Keymap 5: Emoji
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |------|           |------|      |THUMUP|      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|HORSES|THUMBS|
   *                                 |      |      |      |       |      |QUOTE |  UP  |
   *                                 `--------------------'       `--------------------'
   */
  [_EMOJI] = LAYOUT_ergodox(
      //left hand
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,
               _______, _______,
                        _______,
      _______, _______, _______,
      // right hand
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, HORSES_QUOTE, THUMBS_UP
      ),
  /* Keymap 6: Sketchup
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      | UNDO | REDO |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        | MOVE |ROTATE|      |ORBIT |TAPE M|------|           |------|      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      | PAN  |      |      | // camera |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 | RECT | PUSH |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [_SKETCHUP] = LAYOUT_ergodox(
      //left hand
      _______, _______, _______,   _______, _______,  _______,   _______,
      _______, _______, _______,   _______, SU_UNDO,  SU_REDO,   _______,
      _______, SU_MOVE, SU_ROTATE, _______, SU_ORBIT, SU_TAPE_M,
      _______, _______, _______,   _______, SU_PAN,   _______,   _______,
      _______, _______, _______,   _______, _______,
               _______, _______,
                        _______,
      SU_RECT, SU_PUSH, _______,
      // right hand
      _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______,
      _______, _______,
      _______,
      _______, _______, _______
      ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case THUMBS_UP: if (record->event.pressed) { SEND_STRING(EMJ_THUMBS_UP_STRING); } break;
    case HORSES_QUOTE: if (record->event.pressed) { SEND_STRING(EMJ_HORSES_QUOTE_STRING); } break;
  }
  return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  eeconfig_init();
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
    case _SKETCHUP:
      ergodox_right_led_on(1);
      ergodox_right_led_set(1, 5);
      ergodox_right_led_on(2);
      ergodox_right_led_set(2, 5);
      ergodox_right_led_on(3);
      ergodox_right_led_set(3, 5);
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
