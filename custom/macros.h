static bool use_intl = true;

enum {
  S_INTL = SAFE_RANGE,
  S_TILD,
  S_SQTE,
  S_DQTE,
  S_TICK,
  S_CART,
  T_1,
  T_2,
  T_3,
  T_4,
  T_5,
  T_6,
  T_7,
  T_8,
  T_CPYM,
  T_SP,
  T_VS,
  T_NEW,
  T_ZOOM,
  T_JN_V,
  T_JN_H,
  T_BRKP,
  T_FNGR,
  T_SESH,
  E_THMUP,
  E_JOY,
  KVM_1,
  KVM_2,
  KVM_3,
  KVM_4
};

void toggle_intl(keyrecord_t *record) {
  if (record->event.pressed) {
    if (use_intl == true) {
      use_intl = false;
    } else {
      use_intl = true;
    }
  }
}

void do_dead_key(keyrecord_t *record, int code, uint8_t modifier) {
  if (record->event.pressed) {
    register_code(modifier);
    register_code(code);
    unregister_code(code);
    unregister_code(modifier);

    if (use_intl) {
      register_code(KC_SPC);
      unregister_code(KC_SPC);
    }
  }
}

void do_tmux_key(keyrecord_t *record, uint8_t code, uint8_t modifier) {
  if (record->event.pressed) {
    register_code(KC_LCTL);
    register_code(KC_B);
    unregister_code(KC_B);
    unregister_code(KC_LCTL);

    register_code(modifier);
    register_code(code);
    unregister_code(code);
    unregister_code(modifier);

    if (code == KC_QUOT && use_intl) {
      register_code(KC_SPC);
      unregister_code(KC_SPC);
    }
  }
}

void do_kvm_key(keyrecord_t *record, uint8_t code) {
  if (record->event.pressed) {
    register_code(KC_LCTL);
    unregister_code(KC_LCTL);
    register_code(KC_LCTL);
    unregister_code(KC_LCTL);

    register_code(code);
    unregister_code(code);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case S_INTL: toggle_intl(record); break;
    case S_TILD: do_dead_key(record, KC_TILD, KC_LSFT); break;
    case S_DQTE: do_dead_key(record, KC_DQUO, KC_LSFT); break;
    case S_SQTE: do_dead_key(record, KC_QUOT, KC_NO); break;
    case S_CART: do_dead_key(record, KC_CIRC, KC_LSFT); break;
    case S_TICK: do_dead_key(record, KC_GRV, KC_NO); break;
    case T_1: do_tmux_key(record, KC_1, KC_NO); break;
    case T_2: do_tmux_key(record, KC_2, KC_NO); break;
    case T_3: do_tmux_key(record, KC_3, KC_NO); break;
    case T_4: do_tmux_key(record, KC_4, KC_NO); break;
    case T_5: do_tmux_key(record, KC_5, KC_NO); break;
    case T_6: do_tmux_key(record, KC_6, KC_NO); break;
    case T_7: do_tmux_key(record, KC_7, KC_NO); break;
    case T_8: do_tmux_key(record, KC_8, KC_NO); break;
    case T_CPYM: do_tmux_key(record, KC_LBRC, KC_NO); break;
    case T_SP: do_tmux_key(record, KC_QUOT, KC_LSFT); break;
    case T_VS: do_tmux_key(record, KC_5, KC_LSFT); break;
    case T_NEW: do_tmux_key(record, KC_C, KC_NO); break;
    case T_ZOOM: do_tmux_key(record, KC_Z, KC_NO); break;
    case T_JN_V: do_tmux_key(record, KC_V, KC_LSFT); break;
    case T_JN_H: do_tmux_key(record, KC_S, KC_LSFT); break;
    case T_BRKP: do_tmux_key(record, KC_B, KC_LSFT); break;
    case T_FNGR: do_tmux_key(record, KC_F, KC_LSFT); break;
    case T_SESH: do_tmux_key(record, KC_Y, KC_NO); break;
    case E_THMUP: if (record->event.pressed) { SEND_STRING(":+1:"); } break;
    case E_JOY: if (record->event.pressed) { SEND_STRING(":joy:"); } break;
    case KVM_1: do_kvm_key(record, KC_1); break;
    case KVM_2: do_kvm_key(record, KC_2); break;
    case KVM_3: do_kvm_key(record, KC_3); break;
    case KVM_4: do_kvm_key(record, KC_4); break;
  }

  return true;
}
