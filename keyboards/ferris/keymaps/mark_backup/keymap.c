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
		    					                            TO(_NAV),     LT(0, KC_SPACE),     LT(0, KC_BSPC),     TO(_SYM)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
  ),

  [_SYM] = LAYOUT(
// ||----<ESCAPE>----|-------&&-------|-------\|-------|-------/?-------|-------%%-------|| ||-------""-------|-------{{-------|-------}}-------|-------!!-------|--<BACKSPACE>---||
        KC_ESCAPE,         KC_AMPR,         UK_BSLS,         KC_SLSH,         KC_PERC,             UK_DQUO,         KC_LBRC,         KC_RBRC,        KC_EXLM,         KC_BSPC,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-----<TAB>------|------ `~ ------|------ =+ ------|------ -_ ------|-------$$-------|| ||-------^^-------|-------[[-------|-------]]-------|-------::-------|----<ENTER>-----||
          KC_TAB,          UK_GRV,          KC_EQL,          KC_MINS,         KC_DLR,              KC_CIRC,      LSFT(KC_LBRC),   LSFT(KC_RBRC),     KC_COLN,         KC_ENTER,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||------ ~~ ------|-------**-------|-------<<-------|------->>-------|-------@@-------|| ||-------##-------|-------((-------|-------))-------|-------..-------|-------XX-------||
          UK_TILD,          KC_ASTR,          KC_LT,           KC_GT,           UK_AT,              UK_HASH,         KC_LPRN,         KC_RPRN,         KC_DOT,         XXXXXXX,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|-----<CTRL>-----|| ||-----<SHIFT>----|----------------||
		    					                            TO(_BASE),        KC_LCTL,            KC_LSFT,         TO(_NUM)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
  ),

  [_NAV] = LAYOUT(

// ||----<ESCAPE>----|-----<MUTE>-----|----<PAUSE>-----|--<SHIFT-TAB>---|-----<TAB>------|| ||---<REFRESH>----|-----<BACK>-----|---<FORWARD>----|--<FAVOURITES>--|-<CTRL-ALT-DEL>-||
        KC_ESCAPE,         KC_MUTE,        KC_MPLY,        S(KC_TAB),        KC_TAB,              KC_WREF,          KC_WBAK,        KC_WFWD,          KC_WFAV,       C(A(KC_DEL)),
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-----<ALT>------|-----<PREV>-----|-----<NEXT>-----|--<ARROW-LEFT>--|--<ARROW-RGHT>--|| ||--<ARROW-DOWN>--|---<ARROW-UP>---|--<ARROW-LEFT>--|--<ARROW-RGHT>--|----<ENTER>-----||
         KC_LALT,         KC_MPRV,         KC_MNXT,        C(KC_LEFT),      C(KC_RGHT),           KC_LEFT,          KC_DOWN,         KC_UP,           KC_RGHT,        KC_ENTER,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||----<SLEEP>-----|-----<CUT>------|-----<COPY>-----|-----<PASTE>----|---<CTRL-TAB>---|| ||-<PRINT-SCREEN>-|---<SNIPPET>----|--<CALCULATOR>--|--<MYCOMPUTER>--|----------------||
         KC_SLEP,          KC_CUT,         KC_COPY,         KC_PSTE,        C(KC_TAB),            KC_PSCR,        G(S(KC_S)),       KC_CALC,         KC_MYCM,        XXXXXXX,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|-----<CTRL>-----|| ||-----<SHIFT>----|----------------||
		    					                            TO(_BASE),        KC_LGUI,             KC_LSFT,         TO(_NUM)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    ),

  [_NUM] = LAYOUT(
// ||----<ESCAPE>----|-------77-------|-------88-------|-------99-------|------ -- ------|| ||---<REFRESH>----|-----<BACK>-----|---<FORWARD>----|--<FAVOURITES>--|-<CTRL-ALT-DEL>-||
        KC_ESCAPE,          KC_7,            KC_8,            KC_9,          KC_MINUS,           _______,         _______,         _______,         _______,        _______,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------**-------|-------44-------|-------55-------|-------66-------|------ ++ ------|| ||--<ARROW-DOWN>--|---<ARROW-UP>---|--<ARROW-LEFT>--|--<ARROW-RGHT>--|----<ENTER>-----||
         KC_ASTR,           KC_4,            KC_5,            KC_6,           KC_PLUS,            _______,         _______,         _______,         _______,          _______,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------//-------|-------11-------|-------22-------|-------33-------|-------00-------|| ||-------££-------|-------$$-------|-------€€-------|------ .. ------|----------------||
         KC_SLSH,           KC_1,            KC_2,            KC_3,            KC_0,               UK_PND,          UK_DLR,         UK_EURO,          KC_DOT,          _______,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|-----<CTRL>-----|| ||-----<SHIFT>----|----------------||
		    					                            TO(_BASE),        KC_LGUI,             KC_LSFT,      TO(_FUNC)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    ),

  [_FUNC] = LAYOUT(
// ||----<ESCAPE>----|-------F7-------|-------F8-------|-------F9-------|-------F12------|| ||----------------|----------------|----------------|----------------|----------------||
        KC_ESCAPE,          KC_F7,           KC_F8,           KC_F9,          KC_F12,             XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||----------------|-------F4-------|-------F5-------|-------F6-------|-------F11------|| ||----------------|----------------|----------------|----------------|----------------||
         XXXXXXX,           KC_F4,           KC_F5,           KC_F6,           KC_F11,             XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||----------------|-------F1-------|-------F2-------|-------F3-------|-------F10------|| ||----------------|----------------|----------------|----------------|---BOOTLOADER---||
         XXXXXXX,           KC_F1,           KC_F2,           KC_F3,          KC_F10,              XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,       QK_BOOTLOADER,
// ||----------------|----------------|----------------|----------------|----------------|| ||----------------|----------------|----------------|----------------|----------------||
// ||-------------------------------------------------||----------------|-----<CTRL>-----|| ||-----<SHIFT>----|----------------||
		    					                            TO(_BASE),        KC_LALT,             KC_LSFT,        TO(_NAV)
// ||-------------------------------------------------||----------------|----------------|| ||----------------|----------------||
    )


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



