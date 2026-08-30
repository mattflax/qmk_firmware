// Copyright 2025 Dasky (@daskygit)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "homerowmodkeys.h"


enum LAYERS {
    _QWERTY = 0,
    _GAME,
    _COLEMAK,
    _NUM,
    _SYM,
    _FUNC,
    _MOUSE,
    _NAV,
    _MEDIA,
    _ADJUST
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAME,
    KC_COLEMAK
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


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | HOME  |------+------+------+------+------+------|
 * |Sft/CL|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |LCtrl | LAlt | Esc  | Space| /  Tab  /       \Enter \  |BkSpc | Del  | Rctl | RAlt |
 *            |      |      | Mouse|  Nav |/ Media /         \ Sym  \ | Num  | Fn   |      |      |
 *            `-----------------------------------'           '-----------------------------------'
 */
  [_QWERTY] = LAYOUT(
    KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, \
    KC_ESC,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, \
    XXXXXXX, HM_A,   HM_S,    HM_D,    HM_F,    KC_G,                      KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, KC_HOME, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT, \
                     KC_LCTL, KC_LALT, L_MSESC, L_NVSPC, L_MEDTB, L_SYMEN, L_NUMBS, L_FNDEL, KC_RCTL, KC_RALT \
  ),

/*
 * Base Layer: GAME
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |   Bksp |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * | Escape |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |BackSpc |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * | Shift  |   A  |   S  |  D   |   F  |   G  |  |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * |  Ctrl  |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  | Left | Down |  Up  |  Right |
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        |MOUSE | Space|  Tab |  | Enter| BkSpc| FUNC |
 *                        |      |      |      |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_GAME] = LAYOUT(
  KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_ESC,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  XXXXXXX, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE, KC_HOME, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT, \
                   KC_LCTL, KC_LALT, L_MSESC, L_NVSPC, L_MEDTB, L_SYMEN, L_NUMBS, L_FNDEL, KC_RCTL, KC_RALT \
  ),

/*
 * Base Layer: ColemakDH
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |   Bksp |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * | Escape |   Q  |   W  |   F  |   P  |   B  |  |   J  |   L  |   U  |   Y  |   ;  |BackSpc |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |Ctrl/Tab|   A  |   R  |  S   |   T  |   G  |  |   M  |   N  |   E  |   I  |   O  |  ' "   |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |  |   K  |   H  | ,  < | . >  | /  ? |SftEnter|
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        | Super| Lower| Space|  | Space| Raise| Fn   |
 *                        | Raise|      |  Alt |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_COLEMAK] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV, \
  KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC, \
  LCTL_T(KC_TAB),   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,             KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_MUTE,     KC_HOME,KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
            KC_LCTL, KC_LALT, L_MSESC, L_NVSPC, L_MEDTB, L_SYMEN, L_NUMBS, L_FNDEL, MO(_FUNC), KC_RALT \
  ),

/*
 * NUM
 *
 * ,-----------------------------------------.                    ,-------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |      |   /  |   7  |   8  |   9  |  +   |                    |      |      |      |      |      |        |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |      |   '  |   4  |   5  |   6  |  -   |-------.    ,-------|      |RShift| Ctrl | Super| Alt  |        |
 * |------+------+------+------+------+------|  MUTE |    | HOME  |------+------+------+------+------+--------|
 * |      |   |  |   1  |   2  |   3  |  =   |-------.    ,-------|      |      |      |      |      |        |
 * `-----------------------------------------/       /     \      \-------------------------------------------'
 *            |LCtrl | LAlt |   0  |   .  | /  Tab  /       \Enter \  |BkSpc | Del  | Rctl | RAlt |
 *            |      |      |      |      |/       /         \      \ | Num  | Fn   |      |      |
 *            `-----------------------------------'           '-----------------------------------'
 */
  [_NUM] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    XXXXXXX, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_PLUS,			        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_QUOT, KC_4,    KC_5,    KC_6,    KC_MINS,                   XXXXXXX, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, \
    XXXXXXX, S(KC_NUBS),KC_1,  KC_2,    KC_3,    KC_EQL,  KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                      _______, _______, KC_0,    KC_DOT,  KC_TAB,  KC_ENT,  _______, _______, _______, _______
  ),

/*
 * SYM
 *
 * ,-----------------------------------------.                    ,-------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |      |   `  |   &  |   *  |  ( ) |  [ ] |                    |      |      |      |      |      |        |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |      |   @  |   $  |   %  |   ^  |  { } |-------.    ,-------|      |RShift| Ctrl | Super| Alt  |        |
 * |------+------+------+------+------+------|  MUTE |    | HOME  |------+------+------+------+------+--------|
 * |      |  \ | |   !  |   "  |   £  | # ~  |-------.    ,-------|      |      |      |      |      |        |
 * `-----------------------------------------/       /     \      \-------------------------------------------'
 *            |LCtrl | LAlt |   0  |   .  | /  Tab  /       \  Sym \  |BkSpc | Del  | Rctl | RAlt |
 *            |      |      |      |      |/       /         \      \ | Num  | Fn   |      |      |
 *            `-----------------------------------'           '-----------------------------------'
 */
  [_SYM] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    XXXXXXX, KC_GRV,  KC_AMPR, KC_ASTR, TD(TD_ASTR),TD(TD_SQBR),            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, S(KC_QUOT),KC_DLR,KC_PERC, KC_CIRC, TD(TD_CRLB),               XXXXXXX, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, \
    XXXXXXX, KC_NUBS, KC_EXLM, KC_AT,   KC_HASH, KC_NUHS, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                      _______, _______, KC_DEL,  KC_SPC,  KC_TAB,  _______, _______, _______, _______, _______
  ),

/*
 * FUNC
 *
 * ,-----------------------------------------.                    ,-------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |                    |      |      |      |      |      |        |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |      |      |  F4  |  F5  |  F6  |  F11 |-------.    ,-------|      |RShift| Ctrl | Super| Alt  |        |
 * |------+------+------+------+------+------|  MUTE |    | HOME  |------+------+------+------+------+--------|
 * |      |PrtScr|  F1  |  F2  |  F3  |  F12 |-------.    ,-------|      |      |      |      |      |        |
 * `-----------------------------------------/       /     \      \-------------------------------------------'
 *            |LCtrl | LAlt |ADJUST| Space| /  Tab  /       \  Sym \  |BkSpc | Del  | Rctl | RAlt |
 *            |      |      |      |      |/       /         \      \ | Num  | Fn   |      |      |
 *            `-----------------------------------'           '-----------------------------------'
 */
  [_FUNC] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC, \
    _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,	XXXXXXX, XXXXXXX,
    KC_TAB,  _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,                    XXXXXXX, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,
    XXXXXXX, KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F12,  KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,	XXXXXXX, XXXXXXX,
                      _______, _______, MO(_MOUSE),KC_SPC,KC_TAB,  _______, _______, _______, _______, _______
  ),

/*
 * MOUSE
 *
 * ,-----------------------------------------.                    ,-------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |      |      |      |      |      |      |                    |WhlLft| WhlUp|WhlDn |WhlRt |      |        |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |      | Alt  | Super| Ctrl |LShift|      |-------.    ,-------| MsLft|MsDown| MsUp |MsRght|      |        |
 * |------+------+------+------+------+------|  MUTE |    | HOME  |------+------+------+------+------+--------|
 * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |      |        |
 * `-----------------------------------------/       /     \      \-------------------------------------------'
 *            |LCtrl | LAlt |Mouse |      | /       /       \Right \  | Left |ADJUST| Mid  |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '-----------------------------------'
 */
  [_MOUSE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX, XXXXXXX,
    KC_TAB,  KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                   MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,	XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______, MS_BTN2, MS_BTN1, _______, _______, _______
  ),

/*
 * NAV
 *
 * ,-----------------------------------------.                    ,-------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |      |      |      |      |      |      |                    | Home | PgDn | PgUp | End  |      |        |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |      | Alt  | Super| Ctrl |LShift|      |-------.    ,-------| Left | Down |  Up  | Right| Ins  |        |
 * |------+------+------+------+------+------|  MUTE |    | HOME  |------+------+------+------+------+--------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |        |
 * `-----------------------------------------/       /     \      \-------------------------------------------'
 *            |LCtrl | LAlt |Mouse |      | /       /       \Right \  | Left |ADJUST| Mid  |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '-----------------------------------'
 */
[_NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
    KC_TAB,  KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,	XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

/*
 * MEDIA
 *
 * ,-----------------------------------------.                    ,-------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |        |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |      | Alt  | Super| Ctrl |LShift|      |-------.    ,-------| Prev | VolUp| VolDn| Next |      |        |
 * |------+------+------+------+------+------|       |    | MUTE  |------+------+------+------+------+--------|
 * |      |      |      |      |      |      |-------.    ,-------| Pause|      |      |      |      |        |
 * `-----------------------------------------/       /     \      \-------------------------------------------'
 *            |LCtrl | LAlt |Mouse |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '-----------------------------------'
 */
[_MEDIA] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_TAB,  KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),



/*
 * Adjust Layer: Layouts, KVM
 *
*
 * ,-----------------------------------------.                    ,-------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |RESET |      |Qwerty|Colemk|      | Game |                    |      |      |      |      |      |        |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+--------|
 * |RGB On| Mode+| Hue+ | Sat+ | Val+ |      |-------.    ,-------| Prev | VolUp| VolDn| Next |      |        |
 * |------+------+------+------+------+------|       |    | MUTE  |------+------+------+------+------+--------|
 * |      | Mode-| Hue- | Sat- | Val- |      |      |-------.    ,-------| Pause|      |      |      |      |        |
 * `-----------------------------------------/       /     \      \-------------------------------------------'
 *            |LCtrl | LAlt |Mouse |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '-----------------------------------'
 */
[_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
    XXXXXXX, RM_PREV, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _MOUSE, _FUNC, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
         case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        default:
            return true;
    }
    return true;
}


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
[0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
[1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
[2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
[3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}
};
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:  // Left encoder
            // No function, carry on with parent function
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
            break;
        case 1:  // Right encoder
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            return false;
    }

    return true;
}
#endif

// clang-format on
