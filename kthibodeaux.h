// Macros
enum {
  M_TMUX_1,
  M_TMUX_2,
  M_TMUX_3,
  M_TMUX_4,
  M_TMUX_5,
  M_TMUX_COPY_MODE,
  M_TMUX_SP,
  M_TMUX_VS,
  M_TMUX_NEW,
  M_TMUX_ZOOM,
  M_TMUX_SHOW_CURRENT_STORY,
  M_HOLD_W
};

// Tap dances
enum {
  TD_SPACE
};

#define NO_KEY KC_NO
#define TERM_PASTE LALT(LSFT(KC_INS))

#define MY_T CTL_T(KC_T)
#define MY_N CTL_T(KC_N)
#define MY_R ALT_T(KC_R)
#define MY_I ALT_T(KC_I)
#define MY_E LT(_TMUX, KC_E)
#define MY_SPC TD(TD_SPACE)

static bool w_is_held;

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SPACE] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_UNDERSCORE)
};

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

void toggle_hold_w(keyrecord_t *record) {
  if (record->event.pressed) {
    if (w_is_held == true) {
      w_is_held = false;
      unregister_code (KC_W);
    } else {
      w_is_held = true;
      register_code (KC_W);
    }
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id) {
    case M_TMUX_1: do_tmux_key(record, KC_1, KC_NO); break;
    case M_TMUX_2: do_tmux_key(record, KC_2, KC_NO); break;
    case M_TMUX_3: do_tmux_key(record, KC_3, KC_NO); break;
    case M_TMUX_4: do_tmux_key(record, KC_4, KC_NO); break;
    case M_TMUX_5: do_tmux_key(record, KC_5, KC_NO); break;
    case M_TMUX_COPY_MODE: do_tmux_key(record, KC_LBRC, KC_NO); break;
    case M_TMUX_SP: do_tmux_key(record, KC_QUOT, KC_LSFT); break;
    case M_TMUX_VS: do_tmux_key(record, KC_5, KC_LSFT); break;
    case M_TMUX_NEW: do_tmux_key(record, KC_C, KC_NO); break;
    case M_TMUX_ZOOM: do_tmux_key(record, KC_Z, KC_NO); break;
    case M_TMUX_SHOW_CURRENT_STORY: do_tmux_key(record, KC_J, KC_NO); break;
    case M_HOLD_W: toggle_hold_w(record); break;
  }
  return MACRO_NONE;
};
