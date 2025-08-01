#include QMK_KEYBOARD_H
#include "achordion/achordion.h"

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

// Home row mod keys
#define HM_A LALT_T(KC_A)
#define HM_S LGUI_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)
#define HM_J RSFT_T(KC_J)
#define HM_K LCTL_T(KC_K)
#define HM_L LGUI_T(KC_L)
#define HM_SCLN LALT_T(KC_SCLN)
#define L_MSESC LT(_MOUSE,KC_ESC)
#define L_NVSPC LT(_NAV,KC_SPC)
#define L_MEDTB LT(_MEDIA,KC_TAB)
#define L_SYMEN LT(_SYM, KC_ENT)
#define L_NUMBS LT(_NUM, KC_BSPC)
#define L_FNDEL LT(_FUNC, KC_DEL)

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY = 0,
    _COLEMAKDH,
    _GAME,
    _NUM,
    _SYM,
    _FUNC,
    _MOUSE,
    _NAV,
    _MEDIA,
    _ADJUST
};

/* Custom keycodes for function layers */
enum custom_keycodes {
  MO_QWRT = SAFE_RANGE,
  MO_CLMK,
  MO_GAME,
};

// Tap dance definitions
enum {
    TD_BRCK,
    TD_CRLB,
    TD_SQBR,
    TD_ASTR,

};


void asterisk_search(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            SEND_STRING("*");
            break;
        case 2:
            SEND_STRING("**");
            break;
        case 3:
            SEND_STRING("*:*");
            break;
        case 4:
            SEND_STRING("[* TO *]");
            break;
    }
    reset_tap_dance(state);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_BRCK] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_CRLB] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_SQBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_ASTR] = ACTION_TAP_DANCE_FN(asterisk_search)
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LAlt  |  Esc |Space | / Tab   /       \Enter \  |BkSpc |Delete|  FN  |
 *                   |      | Mouse| Nav  |/ Media /         \ Sym  \ | Num  |  Fn  |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  XXXXXXX, KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, \
  XXXXXXX, HM_A,   HM_S,    HM_D,    HM_F,    KC_G,                      KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, XXXXXXX, \
  XXXXXXX, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, \
                            KC_LALT, L_MSESC, L_NVSPC, L_MEDTB, L_SYMEN, L_NUMBS, L_FNDEL, MO(_FUNC) \
),

/*
 * COLEMAK DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtrl |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | HOME  |------+------+------+------+------+------|
 * |Sft/CL|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |SftEnt|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LAlt  | LGUI |LOWER | /Space+ /       \Space \  |RAISE | LCtl |  FN  |
 *                   |      |      |      |/ Alt   /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_COLEMAKDH] = LAYOUT( \
  KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_LCTL, KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,    KC_LBRC, KC_RBRC, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT, \
                            KC_LALT, L_MSESC, L_NVSPC, L_MEDTB, L_SYMEN, L_NUMBS, L_FNDEL, MO(_FUNC) \
),

/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LAlt  |      |Space | / Tab   /       \Enter \  |BkSpc |Delete|  FN  |
 *                   |      | Mouse|      |/       /         \ Sym  \ | Num  |  Fn  |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_GAME] = LAYOUT( \
  KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, \
  KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, XXXXXXX, \
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, MO_QWRT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
                            KC_LALT, L_MSESC, KC_SPC,  KC_TAB,  KC_ENT,  L_NUMBS, L_FNDEL, MO(_FUNC) \
),

/* NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   /  |   7  |   8  |   9  |  +   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   '  |   4  |   5  |   6  |  -   |-------.    ,-------|      |RShift| Ctrl | Super| Alt  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |   |  |   1  |   2  |   3  | = +  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LAlt  |  0   |  .   | / Tab   /       \Enter \  |      |Delete|  FN  |
 *                   |      |      |      |/ Media /         \ Sym  \ | Num  |  Fn  |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NUM] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  XXXXXXX, KC_SLSH, KC_7,	KC_8,	KC_9,	KC_PLUS,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_QUOT,	KC_4,	KC_5,	KC_6,	KC_MINS,                   XXXXXXX,	KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, \
  XXXXXXX, S(KC_NUBS),KC_1,	KC_2,	KC_3,   KC_EQL,  KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                           KC_LALT, KC_0,   KC_DOT,  KC_TAB,  KC_ENT,  _______, L_FNDEL, MO(_FUNC) \
),

/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   `  |   &  |   *  |  ( ) |  [ ] |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   @  |   $  |   %  |   ^  |  { } |-------.    ,-------|      |RShift| Ctrl | Super| Alt  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |  \ | |   !  |   "  |   £  | # ~  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LAlt  | Del  | Space| / Tab   /       \Enter \  |      |Delete|  FN  |
 *                   |      |      |      |/ Media /         \ Sym  \ | Num  |  Fn  |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYM] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  XXXXXXX, KC_GRV,  KC_AMPR,TD(TD_ASTR),TD(TD_BRCK),TD(TD_SQBR),       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, S(KC_QUOT),KC_DLR,KC_PERC,KC_CIRC,TD(TD_CRLB),              XXXXXXX,	KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, \
  XXXXXXX, KC_NUBS,	KC_EXLM, KC_AT, KC_HASH,KC_NUHS, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                            KC_LALT, KC_DEL, KC_SPC, KC_TAB,  _______, L_NUMBS, L_FNDEL, MO(_FUNC) \
),

/* FUNC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  F4  |  F5  |  F6  |  F11 |-------.    ,-------|      |RShift| Ctrl | Super| Alt  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |PrtScr|  F1  |  F2  |  F3  |  F12 |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LAlt  | Esc  | Space| / Tab   /       \Enter \  |      |Delete|  FN  |
 *                   |      |      |      |/ Media /         \ Sym  \ | Num  |  Fn  |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FUNC] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  XXXXXXX, _______, KC_F7,	KC_F8,	KC_F9,	KC_F10,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, _______,	KC_F4,	KC_F5,	KC_F6,	KC_F11,                   XXXXXXX, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, \
  XXXXXXX, KC_PSCR, KC_F1,  KC_F2,	KC_F3,  KC_F12, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                            KC_LALT,L_MSESC,L_NVSPC,L_MEDTB, L_SYMEN, L_NUMBS, _______, MO(_FUNC) \
),

/* FUNC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |WhlLft| WhlUp|WhlDn |WhlRt |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  Alt | Super| Ctrl |LShift|      |-------.    ,-------| MsLft|MsDown| MsUp |MsRght|      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| Left | Down |  Up  |Right |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \Right \  | Left | Mid  |  FN  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_MOUSE] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_WH_L, KC_WH_D,	KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_LALT,	KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_MS_L, KC_MS_D,	KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN,	KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
                             KC_LALT, _______, L_NVSPC, L_MEDTB, KC_BTN2, KC_BTN1, KC_BTN3, MO(_FUNC) \
),

/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | Home | PgDn | PgUp | End  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  Alt | Super| Ctrl |LShift|      |-------.    ,-------| Left | Down |  Up  | Right| Ins  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \Enter \  | Bkspc| Del  |  FN  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NAV] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN,	KC_PGUP, KC_END,  XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_LALT,	KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_LEFT, KC_DOWN,	KC_UP,   KC_RGHT, KC_INS,  XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             KC_LALT, L_MSESC, _______, L_MEDTB, KC_ENT,  KC_BSPC, KC_DEL,  MO(_FUNC) \
),

/* MEDIA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  Alt | Super| Ctrl |LShift|      |-------.    ,-------| Prev | VolDn| VolUp| Next |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| Pause|      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \Pause \  | Bkspc| Del  |  FN  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_MEDIA] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX,	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_LALT,	KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_MPLY, XXXXXXX,	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             KC_LALT, L_MSESC, L_NVSPC, _______, KC_MPLY, KC_BSPC, KC_DEL,  MO(_FUNC) \
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |Plain |Breath| Grad |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RESET |      |Qwerty|Colemk|Workmn|      |                    |RGB On| Mode+| Hue+ | Sat+ | Val+ |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Mode-| Hue- | Sat- | Val- |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |ScrLck|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | /Space  /       \ Space\  |RAISE |      |ADJUST|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_M_P, RGB_M_B, RGB_M_G, XXXXXXX, XXXXXXX, XXXXXXX, \
  QK_BOOT, XXXXXXX, MO_QWRT, MO_CLMK, XXXXXXX, MO_GAME,                   RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, \
  KC_SCRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             _______, _______, _______, _______, _______, _______, _______, _______ \
 )
};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
const char *read_rgb_info(void);
const char *read_rgb_mode(void);

static void print_status_narrow(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAKDH:
        case _QWERTY:
        case _GAME:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Num"), false);  // No return at end of line
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Sym"), false);  // No return at end of line
            break;
        case _FUNC:
            oled_write_ln_P(PSTR("Func"), false);  // No return at end of line
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Nav"), false);  // No return at end of line
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media"), false);  // No return at end of line
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse"), false);  // No return at end of line
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adj"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);

    // Modifiers
    uint8_t mod_state = get_mods();
    oled_write_ln_P(PSTR("Sup"), (mod_state & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI));
    oled_write_ln_P(PSTR("Alt"), (mod_state & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT));
    oled_write_ln_P(PSTR("Ctrl"), (mod_state & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL));
    oled_write_ln_P(PSTR("Shft"), (mod_state & MOD_MASK_SHIFT));
    oled_write_ln_P(PSTR("\n"), false);

    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    print_status_narrow();
  } else {
    /*
    if (get_highest_layer(layer_state) == _ADJUST) {
        oled_write_ln(read_rgb_info(), false);
        oled_write_ln(read_rgb_mode(), false);
    } else {
        oled_write(read_logo(), false);
    }
    */
  }

  return true;
}

#endif // OLED_DRIVER_ENABLE

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _MOUSE, _FUNC, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }

    switch (keycode) {
        case MO_QWRT:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
         case MO_CLMK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
         case MO_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
        default:
            return true;
    }
    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

