#include QMK_KEYBOARD_H
// add some of the UK keycodes - ie £ and €
#define UK_2    KC_2    // 2
#define UK_3    KC_3    // 3
#define UK_4    KC_4    // 4
#define UK_PND  S(UK_3)    // £
#define UK_DLR  S(UK_4)    // $
#define UK_EURO ALGR(UK_4)    // €
#define UK_HASH KC_NUHS // #
#define UK_BSLS KC_NUBS // (backslash)
#define UK_DQUO S(UK_2)    // "
#define UK_QUOT KC_QUOT // '
#define UK_AT   S(UK_QUOT) // @
#define UK_GRV  KC_GRV  // `
#define UK_TILD S(UK_HASH) // ~

// qmk flash -kb ferris/sweep -km mark -c -e CONVERT_TO=promicro_rp2040 -bl uf2-split-left

// add number layer, and maybe a macro layer too
enum layers {
    _BASE,
    _SYM,
    _NAV,
    _NUM,
    _FUNC
};

// tap dance codes
enum tap_dance_codes {
    SYM_D,
    NUM_D,
    NAV_D,
    BASE_D
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
// ||-------QQ-------|-------WW-------|-------EE-------|-------RR-------|-------TT-------|| ||-------YY-------|-------UU-------|-------II-------|-------OO-------|-------PP-------||
           KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,                KC_Y,            KC_U,            KC_I,            KC_O,            KC_P,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------AA-------|-------SS-------|-------DD-------|-------FF-------|-------GG-------|| ||-------HH-------|-------JJ-------|-------KK-------|-------LL-------|-------;;-------||
       LGUI_T(KC_A),    LALT_T(KC_S),    LSFT_T(KC_D),    LCTL_T(KC_F),        KC_G,                KC_H,        RCTL_T(KC_J),    RSFT_T(KC_K),    LALT_T(KC_L),    RGUI_T(KC_SCLN),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------ZZ-------|-------XX-------|-------CC-------|-------VV-------|-------BB-------|| ||-------NN-------|-------MM-------|-------,<-------|-------.>-------|-------/?-------||
           KC_Z,         LT(0, KC_X),    LT(0, KC_C),     LT(0, KC_V),         KC_B,                KC_N,            KC_M,           KC_COMM,         KC_DOT,         KC_SLSH,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|----<SPACE>-----|| ||--<BACKSPACE>---|----------------||
		    					                            TD(NAV_D),    LT(0, KC_SPACE),    LT(0, KC_BSPC),     TD(SYM_D)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    ),

  [_SYM] = LAYOUT(
// ||----<ESCAPE>----|------ ~~ ------|-------\|-------|-------/?-------|-------%%-------|| ||-------""-------|-------{{-------|-------}}-------|-------!!-------|--<BACKSPACE>---||
        KC_ESCAPE,         UK_TILD,         UK_BSLS,         KC_SLSH,         KC_PERC,             UK_DQUO,         KC_LBRC,         KC_RBRC,        KC_EXLM,      LT(0, KC_BSPC),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-----<TAB>------|------ -- ------|------ =+ ------|------ __ ------|-------$$-------|| ||-------^^-------|-------[[-------|-------]]-------|-------::-------|----<ENTER>-----||
          KC_TAB,          KC_MINS,          KC_EQL,         KC_UNDS,         KC_DLR,              KC_CIRC,      LSFT(KC_LBRC),   LSFT(KC_RBRC),     KC_COLN,      LT(0, KC_SPACE),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||------ `~ ------|-------**-------|-------<<-------|------->>-------|-------@@-------|| ||-------##-------|-------((-------|-------))-------|-------..-------|-------&&-------||
          UK_GRV,          KC_ASTR,          KC_LT,           KC_GT,           UK_AT,              UK_HASH,         KC_LPRN,         KC_RPRN,         KC_DOT,          KC_AMPR,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|-----<CTRL>-----|| ||-----<SHIFT>----|----------------||
		    					                           TO(_BASE),      KC_LCTL,             KC_LSFT,          TD(NUM_D)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    ),

  [_NAV] = LAYOUT(

// ||----<ESCAPE>----|-----<MUTE>-----|----<PAUSE>-----|--<SHIFT-TAB>---|-----<TAB>------|| ||---<REFRESH>----|-----<BACK>-----|---<FORWARD>----|--<FAVOURITES>--|--<BACKSPACE>---||
        KC_ESCAPE,         KC_MUTE,        KC_MPLY,        S(KC_TAB),        KC_TAB,              KC_WREF,          KC_WBAK,        KC_WFWD,          KC_WFAV,     LT(0, KC_BSPC),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-----<ALT>------|-----<PREV>-----|-----<NEXT>-----|--<ARROW-LEFT>--|--<ARROW-RGHT>--|| ||--<ARROW-DOWN>--|---<ARROW-UP>---|--<ARROW-LEFT>--|--<ARROW-RGHT>--|----<ENTER>-----||
         KC_LALT,         KC_MPRV,         KC_MNXT,        C(KC_LEFT),      C(KC_RGHT),           KC_LEFT,          KC_DOWN,         KC_UP,           KC_RGHT,     LT(0, KC_SPACE),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||----------------|-----<CUT>------|-----<COPY>-----|-----<PASTE>----|---<CTRL-TAB>---|| ||-<PRINT-SCREEN>-|---<SNIPPET>----|--<CALCULATOR>--|--<MYCOMPUTER>--|----------------||
         TO(_FUNC),        C(KC_X),         C(KC_C),         C(KC_V),        C(KC_TAB),            KC_PSCR,        G(S(KC_S)),       KC_CALC,         KC_MYCM,        TO(_SYM),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|-----<CTRL>-----|| ||-----<SHIFT>----|----------------||
		    					                           TO(_BASE),        KC_LGUI,             KC_LSFT,        TO(_NUM)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    ),

  [_NUM] = LAYOUT(
// ||----<ESCAPE>----|-------77-------|-------88-------|-------99-------|------ ++ ------|| ||-------''-------|-----<BACK>-----|---<FORWARD>----|-------%%-------|---<BACKSPACE>--||
        KC_ESCAPE,          KC_7,            KC_8,            KC_9,          KC_PLUS,             KC_QUOT,          KC_WBAK,         KC_WFWD,        KC_PERC,       LT(0, KC_BSPC),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------**-------|-------44-------|-------55-------|-------66-------|------ 00 ------|| ||--<ARROW-DOWN>--|---<ARROW-UP>---|--<ARROW-LEFT>--|--<ARROW-RGHT>--|----<ENTER>-----||
         KC_ASTR,           KC_4,            KC_5,            KC_6,            KC_0,              KC_LEFT,          KC_DOWN,         KC_UP,          KC_RGHT,       LT(0, KC_SPACE),
// ||-------//-------|-------11-------|-------22-------|-------33-------|------ -- ------|| ||-------££-------|-------$$-------|-------€€-------|------ .. ------|----------------||
         KC_SLSH,           KC_1,            KC_2,            KC_3,         KC_MINUS,             UK_PND,          UK_DLR,          UK_EURO,          KC_DOT,         TO(_SYM),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|-----<CTRL>-----|| ||-----<SHIFT>----|----------------||
		    					                            TO(_BASE),        KC_LGUI,             KC_LSFT,       TO(_FUNC)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    ),

  [_FUNC] = LAYOUT(
// ||----<ESCAPE>----|-------F7-------|-------F8-------|-------F9-------|-------F12------|| ||----------------|----------------|----------------|----------------|----------------||
        KC_ESCAPE,          KC_F7,           KC_F8,           KC_F9,          KC_F12,             KC_SLEP,         XXXXXXX,         XXXXXXX,         XXXXXXX,          XXXXXXX,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||----------------|-------F4-------|-------F5-------|-------F6-------|-------F11------|| ||----------------|----------------|----------------|----------------|----------------||
         XXXXXXX,           KC_F4,           KC_F5,           KC_F6,          KC_F11,              XXXXXXX,        XXXXXXX,         XXXXXXX,         XXXXXXX,          XXXXXXX,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||----------------|-------F1-------|-------F2-------|-------F3-------|-------F10------|| ||----------------|----------------|----------------|----------------|----------------||
         XXXXXXX,           KC_F1,           KC_F2,           KC_F3,          KC_F10,           C(A(KC_DEL)),      XXXXXXX,         XXXXXXX,         XXXXXXX,          XXXXXXX,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|-----<CTRL>-----|| ||-----<SHIFT>----|----------------||
		    					                            TO(_BASE),        KC_LALT,             KC_LSFT,        TO(_NAV)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    )
};
// COMBOS

const uint16_t PROGMEM bootloader_1[] = {KC_F10, KC_F12, COMBO_END};
const uint16_t PROGMEM bootloader_2[] = {KC_SLEP, LCTL(LALT(KC_DEL)), COMBO_END};
const uint16_t PROGMEM single_quote[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM jump_to_num[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[] = {
    COMBO(bootloader_1, QK_BOOTLOADER),
    COMBO(bootloader_2, QK_BOOTLOADER),
    COMBO(single_quote, KC_QUOT),
    COMBO(jump_to_num, TO(_NUM))
};


// Change the behaviour of some keys when they are held down
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // X
        case LT(0, KC_X):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        // C
        case LT(0, KC_C):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        // V
        case LT(0, KC_V):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        // BackSpace
        case LT(0, KC_BSPC):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_BSPC)); // Intercept hold function to send Ctrl-BackSpace
                return false;
            }
            return true;
        // Space
        case LT(0, KC_SPC):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_ENTER); // Intercept hold function to send Enter
                return false;
            }
            return true;

    }
    return true;
}

// ensure RETRO_TAPPING is not applied to C, V, X, Enter or BackSpace
// when we held down C, we got copy (Ctrl+C) but with an extra C - we are removing this output
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Don't retro tap for these keys.
    case LT(0, KC_C):
    case LT(0, KC_V):
    case LT(0, KC_X):
    case LT(0, KC_SPC):
    case LT(0, KC_BSPC):
      return false;

    default:
      return true;  // Enable retro tap otherwise.
  }
}





// a type for the states we need
typedef enum {
     TD_NONE,
     TD_UNKNOWN,
     TD_SINGLE_TAP,
     TD_DOUBLE_SINGLE_TAP
} td_state_t;

// a global instance of the tapdance state
static td_state_t td_state;
//
//
// determines the current state of the tapdance
td_state_t cur_dance(tap_dance_state_t *state);
//
//
// finished functions for each tap dance
void sym_dance_finished(tap_dance_state_t *state, void *user_data);
void num_dance_finished(tap_dance_state_t *state, void *user_data);
void nav_dance_finished(tap_dance_state_t *state, void *user_data);
void base_dance_finished(tap_dance_state_t *state, void *user_data);
//
// reset functions for each tap dance
void sym_dance_reset(tap_dance_state_t *state, void *user_data);
void num_dance_reset(tap_dance_state_t *state, void *user_data);
void nav_dance_reset(tap_dance_state_t *state, void *user_data);
void base_dance_reset(tap_dance_state_t *state, void *user_data);
//

// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
    // if tapped
    if (state->count == 1 || state->interrupted) {
        return TD_SINGLE_TAP;
    }
    // if double tapped
    if (state->count == 2) {
        return TD_DOUBLE_SINGLE_TAP;
    } else {
    // Any number higher than the maximum state value you return above
        return TD_UNKNOWN;
    }
}

/// SYM DANCE
// Handle the possible states for each tapdance keycode you define:
void sym_dance_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: set_oneshot_layer(_SYM, ONESHOT_START); break;
        case TD_DOUBLE_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); layer_move(_SYM); break;
        default: break;
    }
}

void sym_dance_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

// NUM DANCE
// Handle the possible states for each tapdance keycode you define:
void num_dance_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: set_oneshot_layer(_NUM, ONESHOT_START); break;
        case TD_DOUBLE_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); layer_move(_NUM); break;
        default: break;
    }
}

void num_dance_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

// NAV DANCE
// Handle the possible states for each tapdance keycode you define:
void nav_dance_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: set_oneshot_layer(_NAV, ONESHOT_START); break;
        case TD_DOUBLE_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); layer_move(_NAV); break;
        default: break;
    }
}

void nav_dance_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

// BASE DANCE
// Handle the possible states for each tapdance keycode you define:
void base_dance_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: set_oneshot_layer(_BASE, ONESHOT_START); break;
        case TD_DOUBLE_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); layer_move(_BASE); break;
        default: break;
    }
}

void base_dance_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}



// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    [SYM_D] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_dance_finished, sym_dance_reset),
    [NUM_D] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, num_dance_finished, num_dance_reset),
    [NAV_D] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_dance_finished, nav_dance_reset),
    [BASE_D] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, base_dance_finished, base_dance_reset)
};

