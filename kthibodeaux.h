// Macros
enum {
  M_GAME_G,
  M_HOLD_SHIFT_W,
  M_TMUX_1,
  M_TMUX_2,
  M_TMUX_3,
  M_TMUX_4,
  M_TMUX_5,
  M_TMUX_6,
  M_TMUX_7,
  M_TMUX_8,
  M_TMUX_COPY_MODE,
  M_TMUX_SP,
  M_TMUX_VS,
  M_TMUX_NEW,
  M_TMUX_ZOOM,
  M_TMUX_SHOW_CURRENT_STORY,
  M_TMUX_JOIN_V,
  M_TMUX_JOIN_H,
  M_TMUX_BREAK_PANE,
  M_TMUX_OPEN_URL,
  M_TMUX_FINGERS_PLUGIN
};

// Tap dances
enum {
  TD_SPACE
};

enum custom_keycodes {
  THUMBS_UP = SAFE_RANGE,
  HORSES_QUOTE
};

#define EMJ_THUMBS_UP_STRING ":+1:"
#define EMJ_HORSES_QUOTE_STRING "> If I had asked people what they wanted, they would have said faster horses."

#define _______ KC_TRNS

#define NO_KEY KC_NO
#define TERM_PASTE LALT(LCTL(KC_V))

#define MY_T CTL_T(KC_T)
#define MY_N CTL_T(KC_N)
#define MY_R ALT_T(KC_R)
#define MY_S LT(_SKETCHUP, KC_S)
#define MY_I ALT_T(KC_I)
#define MY_E LT(_TMUX, KC_E)
#define MY_A LSFT_T(KC_A)
#define MY_O LSFT_T(KC_O)
#define MY_SPC TD(TD_SPACE)

#define GAME_G M(M_GAME_G)

#define I3_1 LALT(KC_1)
#define I3_2 LALT(KC_2)
#define I3_3 LALT(KC_3)
#define I3_4 LALT(KC_4)
#define I3_5 LALT(KC_5)
#define I3_6 LALT(KC_6)
#define I3_7 LALT(KC_7)
#define I3_8 LALT(KC_8)
#define I3_9 LALT(KC_9)
#define I3_0 LALT(KC_0)

#define I3M_1 LALT(LCTL(KC_1))
#define I3M_2 LALT(LCTL(KC_2))
#define I3M_3 LALT(LCTL(KC_3))
#define I3M_4 LALT(LCTL(KC_4))
#define I3M_5 LALT(LCTL(KC_5))
#define I3M_6 LALT(LCTL(KC_6))
#define I3M_7 LALT(LCTL(KC_7))
#define I3M_8 LALT(LCTL(KC_8))
#define I3M_9 LALT(LCTL(KC_9))
#define I3M_0 LALT(LCTL(KC_0))

#define SU_MOVE KC_M
#define SU_ROTATE KC_Q
#define SU_PUSH KC_P
#define SU_RECT CTL_T(KC_R)
#define SU_TAPE_M KC_T
#define SU_ORBIT KC_O
#define SU_PAN KC_H
#define SU_UNDO LCTL(KC_Z)
#define SU_REDO LCTL(KC_Y)
#define SU_2 CTL_T(KC_2)

static bool is_hold_shift_w;

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SPACE] = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, KC_UNDERSCORE)
};

void toggle_hold_shift_w(keyrecord_t *record) {
  if (record->event.pressed) {
    if (is_hold_shift_w == true) {
      is_hold_shift_w = false;
      unregister_code (KC_LSFT);
      unregister_code (KC_W);
    } else {
      is_hold_shift_w = true;
      register_code (KC_LSFT);
      register_code (KC_W);
    }
  }
}

void do_game_g(keyrecord_t *record) {
  if (record->event.pressed) {
    if (is_hold_shift_w == true) {
      toggle_hold_shift_w(record);
    }
    register_code (KC_G);
  } else {
    unregister_code (KC_G);
  }
}

void do_tmux_key(keyrecord_t *record, uint8_t code, uint8_t modifier) {
  if (record->event.pressed) {
    register_code(KC_LCTRL);
    register_code(KC_SPC);
    unregister_code(KC_SPC);
    unregister_code(KC_LCTRL);
    register_code(modifier);
    register_code(code);
    unregister_code(code);
    unregister_code(modifier);
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id) {
    case M_GAME_G: do_game_g(record); break;
    case M_HOLD_SHIFT_W: toggle_hold_shift_w(record); break;
    case M_TMUX_1: do_tmux_key(record, KC_1, KC_NO); break;
    case M_TMUX_2: do_tmux_key(record, KC_2, KC_NO); break;
    case M_TMUX_3: do_tmux_key(record, KC_3, KC_NO); break;
    case M_TMUX_4: do_tmux_key(record, KC_4, KC_NO); break;
    case M_TMUX_5: do_tmux_key(record, KC_5, KC_NO); break;
    case M_TMUX_6: do_tmux_key(record, KC_6, KC_NO); break;
    case M_TMUX_7: do_tmux_key(record, KC_7, KC_NO); break;
    case M_TMUX_8: do_tmux_key(record, KC_8, KC_NO); break;
    case M_TMUX_COPY_MODE: do_tmux_key(record, KC_LBRC, KC_NO); break;
    case M_TMUX_SP: do_tmux_key(record, KC_QUOT, KC_LSFT); break;
    case M_TMUX_VS: do_tmux_key(record, KC_5, KC_LSFT); break;
    case M_TMUX_NEW: do_tmux_key(record, KC_C, KC_NO); break;
    case M_TMUX_ZOOM: do_tmux_key(record, KC_Z, KC_NO); break;
    case M_TMUX_SHOW_CURRENT_STORY: do_tmux_key(record, KC_J, KC_NO); break;
    case M_TMUX_JOIN_V: do_tmux_key(record, KC_V, KC_LSFT); break;
    case M_TMUX_JOIN_H: do_tmux_key(record, KC_S, KC_LSFT); break;
    case M_TMUX_BREAK_PANE: do_tmux_key(record, KC_B, KC_LSFT); break;
    case M_TMUX_OPEN_URL: do_tmux_key(record, KC_O, KC_NO); break;
    case M_TMUX_FINGERS_PLUGIN: do_tmux_key(record, KC_F, KC_LSFT); break;
  }
  return MACRO_NONE;
};
