enum dances {
  TD_SPACE
};

#define MY_SPC TD(TD_SPACE)

tap_dance_action_t tap_dance_actions[] = {
  [TD_SPACE] = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, KC_UNDERSCORE)
};
