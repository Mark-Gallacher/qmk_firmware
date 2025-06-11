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
#define UK_PIPE S(UK_BSLS) // (pipe)
#define UK_DQUO S(UK_2)    // "
#define UK_QUOT KC_QUOT // '
#define UK_AT   S(UK_QUOT) // @
#define UK_GRV  KC_GRV  // `
#define UK_TILD S(UK_HASH) // ~

// example command on how to flash drives
// qmk flash -kb ferris/sweep -km mark -c -e CONVERT_TO=promicro_rp2040 -bl uf2-split-left


// OVERVIEW of FILE
//
// LAYERS
// COMBOS
// HELD KEYS
// RETRO TAPPING
// TAPPING TERM
// TAPDANCE


// LAYERS
// add number layer, and maybe a macro layer too
enum layers {
    _QWER,
    _COLE,
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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT(
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
		    					                            TD(NUM_D),    LT(0, KC_SPACE),    LT(0, KC_BSPC),     TD(SYM_D)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    ),

  [_COLE] = LAYOUT(
// ||-------QQ-------|-------WW-------|-------FF-------|-------PP-------|-------BB-------|| ||-------JJ-------|-------LL-------|-------UU-------|-------YY-------|-------;;-------||
           KC_Q,            KC_W,            KC_F,            KC_P,            KC_B,                KC_J,            KC_L,            KC_U,            KC_Y,           KC_SCLN,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------AA-------|-------RR-------|-------SS-------|-------TT-------|-------GG-------|| ||-------MM-------|-------NN-------|-------EE-------|-------II-------|-------OO-------||
       LGUI_T(KC_A),    LALT_T(KC_R),    LSFT_T(KC_S),    LCTL_T(KC_T),        KC_G,                KC_M,        RCTL_T(KC_N),    RSFT_T(KC_E),    LALT_T(KC_I),    RGUI_T(KC_O),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------ZZ-------|-------XX-------|-------CC-------|-------DD-------|-------VV-------|| ||-------KK-------|-------HH-------|-------,<-------|-------.>-------|-------/?-------||
           KC_Z,         LT(0, KC_X),     LT(0, KC_C),        KC_D,        LT(0, KC_V),             KC_K,            KC_H,           KC_COMM,         KC_DOT,         KC_SLSH,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|----<SPACE>-----|| ||--<BACKSPACE>---|----------------||
		    					                            TD(NUM_D),    LT(0, KC_SPACE),    LT(0, KC_BSPC),     TD(SYM_D)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    ),

  [_SYM] = LAYOUT(
// ||----<ESCAPE>----|------ ++ ------|-------\|-------|-------/?-------|------ || ------|| ||-------""-------|-------[[-------|-------]]-------|-------!!-------|------ '' ------||
        KC_ESCAPE,         KC_PLUS,         UK_BSLS,         KC_SLSH,         UK_PIPE,             UK_DQUO,        KC_LBRC,         KC_RBRC,         KC_EXLM,          KC_QUOT,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-----<TAB>------|------ -- ------|------ =+ ------|------ __ ------|-------%%-------|| ||------&&--------|-------((-------|-------))-------|-------**-------|-------;;-------||
          KC_TAB,          KC_MINS,         KC_EQL,          KC_UNDS,         KC_PERC,             KC_AMPR,        KC_LPRN,         KC_RPRN,         KC_ASTR,          KC_SCLN,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||------ `~ ------|-------<<-------|------->>-------|-------$$-------|-------@@-------|| ||-------##-------|-------{{-------|-------}}-------|-------^^-------|------ ~~ ------||
          UK_GRV,          KC_LT,           KC_GT,           KC_DLR,          UK_AT,               UK_HASH,        KC_LCBR,         KC_RCBR,         KC_CIRC,          UK_TILD,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|-----<CTRL>-----|| ||-----<SHIFT>----|----------------||
                                                           TG(_SYM),    LCTL_T(KC_SPACE),    LSFT_T(KC_BSPC),     TD(NUM_D)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    ),

  [_NAV] = LAYOUT(

// ||----<ESCAPE>----|-----<MUTE>-----|----<PAUSE>-----|--<SHIFT-TAB>---|-----<TAB>------|| ||---<REFRESH>----|-----<BACK>-----|---<FORWARD>----|--<FAVOURITES>--|--<BACKSPACE>---||
        KC_ESCAPE,         KC_MUTE,        KC_MPLY,        S(KC_TAB),        KC_TAB,              KC_WREF,          KC_WBAK,        KC_WFWD,          KC_WFAV,     LT(0, KC_BSPC),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-----<ALT>------|-----<PREV>-----|-----<NEXT>-----|--<ARROW-LEFT>--|--<ARROW-RGHT>--|| ||--<ARROW-DOWN>--|---<ARROW-UP>---|--<ARROW-LEFT>--|--<ARROW-RGHT>--|----<ENTER>-----||
         KC_LALT,         KC_MPRV,         KC_MNXT,        C(KC_LEFT),      C(KC_RGHT),           KC_LEFT,          KC_DOWN,         KC_UP,           KC_RGHT,     LT(0, KC_SPACE),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||----------------|-----<CUT>------|-----<COPY>-----|-----<PASTE>----|---<CTRL-TAB>---|| ||---<SNIPPET>----|---<PAGE DOWN>--|---<PAGE UP>----|-<PRINT-SCREEN>-|-----------------||
         TO(_FUNC),        C(KC_X),         C(KC_C),         C(KC_V),        C(KC_TAB),          G(S(KC_S)),       KC_PGDN,         KC_PGUP,         KC_PSCR,          TO(_SYM),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|-----<CTRL>-----|| ||-----<SHIFT>----|----------------||
		    					                           TG(_NAV),        KC_LGUI,             KC_LSFT,         TO(_NUM)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    ),

  [_NUM] = LAYOUT(
// ||----<ESCAPE>----|-------77-------|-------88-------|-------99-------|------ ++ ------|| ||-------''-------|-------££-------|------$$--------|-------€€-------|---<BACKSPACE>--||
        KC_ESCAPE,          KC_7,            KC_8,            KC_9,          KC_PLUS,             KC_QUOT,          UK_PND,          UK_DLR,          UK_EURO,      LT(0, KC_BSPC),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------**-------|-------44-------|-------55-------|-------66-------|------ 00 ------|| ||--<ARROW-DOWN>--|---<ARROW-UP>---|--<ARROW-LEFT>--|--<ARROW-RGHT>--|----<ENTER>-----||
         KC_ASTR,           KC_4,            KC_5,            KC_6,            KC_0,              KC_LEFT,          KC_DOWN,         KC_UP,          KC_RGHT,       LT(0, KC_SPACE),
// ||-------//-------|-------11-------|-------22-------|-------33-------|------ -- ------|| ||-------^^-------|-------%%-------|------ ,, ------|------ .. ------|----------------||
         KC_SLSH,           KC_1,            KC_2,            KC_3,          KC_MINUS,             KC_CIRC,          KC_PERC,       KC_COMM,          KC_DOT,         TO(_FUNC),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|-----<CTRL>-----|| ||-----<SHIFT>----|----------------||
		    					                            TG(_NUM),        KC_LGUI,             KC_LSFT,       TO(_SYM)
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
		    					                            TG(_FUNC),        KC_LALT,             KC_LSFT,        TO(_NAV)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    )
};


// COMBOS
const uint16_t PROGMEM bootloader_1[] = {KC_F10, KC_F12, COMBO_END};
const uint16_t PROGMEM bootloader_2[] = {KC_SLEP, LCTL(LALT(KC_DEL)), COMBO_END};
const uint16_t PROGMEM single_quote[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM jump_to_nav_q[] =  {LT(0, KC_C), LT(0, KC_V), COMBO_END};
const uint16_t PROGMEM jump_to_nav_c[] = {KC_D, LT(0, KC_C), COMBO_END};
const uint16_t PROGMEM jump_to_qwerty[] =  {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM jump_to_colemak[] =  {KC_G, KC_H, COMBO_END};

combo_t key_combos[] = {
    // Bootloader to flash the microcontroller
    COMBO(bootloader_1, QK_BOOTLOADER),
    COMBO(bootloader_2, QK_BOOTLOADER),

    // another way to type single quotes
    COMBO(single_quote, KC_QUOT),

    // move to nav layer from qwerty and colemak, respectively
    COMBO(jump_to_nav_q,  TO(_NAV)),
    COMBO(jump_to_nav_c, TO(_NAV)),

    // set the default layer.
    COMBO(jump_to_qwerty, DF(_QWER)),
    COMBO(jump_to_colemak, DF(_COLE)),
};


// HELD KEYS
// Refined Handling of held keys (mainly to learn how to do it)
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


// RETRO TAPPING
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


// TAPPING TERM
// More refined control for tapping_term,
// The home mods are usually good, apart from A, because it is on the pinky.
// This prevents my slow pinky from accidentally triggering the GUI key.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Double the tapping_term for A, on both Colemak and Qwerty
        case LGUI_T(KC_A):
            return TAPPING_TERM + TAPPING_TERM;

        // Double the tapping_term for O, on Colemak
        case RGUI_T(KC_O):
            return TAPPING_TERM + TAPPING_TERM;

        // Double the tapping_term for O, on Qwerty
        case RGUI_T(KC_SCLN):
            return TAPPING_TERM + TAPPING_TERM;

        default:
            return TAPPING_TERM;
    }
}


// TAPDANCE
// a type for the states we need
typedef enum {
     TD_NONE,
     TD_UNKNOWN,
     TD_SINGLE_TAP,
     TD_DOUBLE_SINGLE_TAP
} td_state_t;

// a global instance of the tapdance state
static td_state_t td_state;

// determines the current state of the tapdance
td_state_t cur_dance(tap_dance_state_t *state);

// finished functions for each tap dance
void sym_dance_finished(tap_dance_state_t *state, void *user_data);
void num_dance_finished(tap_dance_state_t *state, void *user_data);
void nav_dance_finished(tap_dance_state_t *state, void *user_data);

// reset functions for each tap dance
void sym_dance_reset(tap_dance_state_t *state, void *user_data);
void num_dance_reset(tap_dance_state_t *state, void *user_data);
void nav_dance_reset(tap_dance_state_t *state, void *user_data);

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

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    [SYM_D] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_dance_finished, sym_dance_reset),
    [NUM_D] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, num_dance_finished, num_dance_reset),
    [NAV_D] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_dance_finished, nav_dance_reset),
};


// END
