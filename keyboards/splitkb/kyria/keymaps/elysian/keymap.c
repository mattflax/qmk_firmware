/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "achordion/achordion.h"

enum layers {
    _QWERTY = 0,
    _COLEMAK,
    _WORKMAN,
    _GAME,
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
    KC_COLEMAK,
    KC_WORKMAN,
    KC_GAME,
};

// Tap dance definitions
enum {
    TD_BRCK,
    TD_CRLB,
    TD_SQBR,
    TD_SLSH
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_BRCK] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_CRLB] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_SQBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_QUOT)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  | Home | Meh  |  | Hyper|  End |   N  |   M  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Ctrl | Alt  | Esc  | Space| Tab  |  | Enter| BkSpc|Delete| Func | LEAD |
 *                        |      |      | Mouse|  Nav | Media|  |Symbol|Number| Func |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      XXXXXXX,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
      XXXXXXX,  LALT_T(KC_A),LGUI_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),   KC_G,                  KC_H,RSFT_T(KC_J),LCTL_T(KC_K),LGUI_T(KC_L),LALT_T(KC_SCLN),XXXXXXX,
      XXXXXXX,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_HOME, KC_MEH,  KC_HYPR,   KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
            KC_LCTL, KC_LALT, LT(_MOUSE,KC_ESC), LT(_NAV,KC_SPC), LT(_MEDIA,KC_TAB), LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC), LT(_FUNC,KC_DEL), MO(_FUNC), XXXXXXX
    ),
/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Escape |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   ;  |BackSpc |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Tab|   A  |   R  |  S   |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | Home | Meh  |  | Hyper|  End |   K  |   H  | ,  < | . >  | /  ? |SftEnter|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Ctrl | Alt  | Super| Lower| Space|  | Space| Raise| RAlt | Func | LEAD |
 *                        |      |      |      |      |  Alt |  | Lower|      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK] = LAYOUT(
      KC_ESC,  KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
      LCTL_T(KC_TAB),KC_A,KC_R,KC_S,   KC_T,   KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   KC_HOME, KC_MEH,   KC_HYPR,  KC_END,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
      KC_LCTL, KC_LALT, LT(_MOUSE,KC_ESC), LT(_NAV,KC_SPC), LT(_MEDIA,KC_TAB), LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC), LT(_FUNC,KC_DEL), MO(_FUNC), XXXXXXX
    ),
/*
 * Base Layer: Workman
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Escape |   Q  |   D  |   R  |   W  |   B  |                              |   J  |   F  |   U  |   P  |   ;  |BackSpc |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Tab|   A  |   S  |   H  |   T  |   G  |                              |   Y  |   N  |   E  |   O  |   I  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   M  |   C  |   V  | Home | Del  |  | BkSp |  End |   K  |   L  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Meh  | Alt  | Super| Lower| Space|  | Space| Raise| Tab  | LEAD | Func |
 *                        |      |      |      |      |  Alt |  | Lower|      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_WORKMAN] = LAYOUT(
      KC_ESC,  KC_Q,   KC_D,   KC_R,   KC_W,   KC_B,                                         KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSPC,
      LCTL_T(KC_TAB),KC_A,KC_S,KC_H,   KC_T,   KC_G,                                         KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT,
      KC_LSFT, KC_Z,   KC_X,   KC_M,   KC_C,   KC_V,   KC_HOME, KC_DEL,   KC_BSPC,  KC_END,  KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
      KC_LCTL, KC_LALT, LT(_MOUSE,KC_ESC), LT(_NAV,KC_SPC), LT(_MEDIA,KC_TAB), LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC), LT(_FUNC,KC_DEL), MO(_FUNC), XXXXXXX
    ),
/*
 * Base Layer: Game
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |Escape|   Q  |   W  |   E  |   R  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |Shift |   A  |   S  |  D   |   F  |                              |   H  |   J  |   K  |   L  | ;  : |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | Ctrl |   Z  |   X  |   C  |   V  | Home | Del  |  | BkSp |  End |   N  | Left | Down |  Up  | Right|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Ctrl | Alt  | Super| Space| Tab  |  | Enter| BkSpc| Tab  |      | Func |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_GAME] = LAYOUT(
      XXXXXXX, KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
      XXXXXXX, KC_LSFT, KC_A,   KC_S,   KC_D,   KC_F,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,
      XXXXXXX, KC_LCTL, KC_Z,   KC_X,   KC_C,   KC_V,  KC_HOME, KC_DEL,   KC_BSPC,  KC_END,  KC_N,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
                           KC_LCTL, KC_LALT, KC_LGUI,  KC_SPC,  KC_TAB,   KC_ENT,   KC_BSPC, KC_TAB,  XXXXXXX, KC_QWERTY
    ),
/*
 * Numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  /   |   7  |   8  |  9   |   +  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  '   |   4  |   5  |   6  |  - _ |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | CapsLk |  |   |   1  |   2  |   3  |   =  |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |   0  |   .  | Tab  |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      XXXXXXX, KC_SLSH,	KC_7,    KC_8,    KC_9,    KC_PLUS,                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_QUOT, KC_4,    KC_5,    KC_6,    KC_MINS,                                          XXXXXXX, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,
      XXXXXXX, S(KC_NUBS),KC_1,  KC_2,    KC_3,    KC_EQL,  _______, _______,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, KC_0,    KC_DOT,  KC_TAB,       _______, _______, _______, _______, _______
    ),
/*
 * Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   `  |  &   |  *   | ( )  | [ ]  |                              |  6   |  7   |  8   |  9   |  0   | Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   @  |  $   |  %   |  ^   | { }  |                              |      |  -   |  =   |      |      | Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | \ |  |  !   |  "   |  £   | # ~  |      |      |  |      |      |   |  |  ~   | Left | Down |  Up  | Right  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Space| Tab  |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      XXXXXXX, KC_GRV,  KC_AMPR, KC_ASTR, TD(TD_BRCK),TD(TD_SQBR),                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, S(KC_QUOT), KC_DLR,KC_PERC,KC_CIRC, TD(TD_CRLB),                                      XXXXXXX, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,
      _______, KC_NUBS,	KC_EXLM, KC_AT,   KC_HASH, KC_NUHS, _______, _______,      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______,  KC_SPC,  KC_TAB,      _______, _______, _______, _______, _______
    ),
/*
 * Function layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      !  F7  |  F8  |  F9  | F10  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      !  F4  |  F5  |  F6  | F11  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |PrtScr|  F1  |  F2  |  F3  | F12  |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  | Play/|      |      |      |      |KC_PSCRKC_PSCRKC_PSCR
 *                        |      |      |      |      |      |  | Pause|      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNC] = LAYOUT(
      _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,                                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,                                           XXXXXXX, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,
      _______, KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______, _______,      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 _______, _______, _______, KC_SPC,  KC_TAB ,      KC_MPLY, _______, _______, _______, _______
    ),
/*
 * Mouse layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      !      |      |      |      |                              |WhlLft| WhlUp|WhlDn |WhlRt |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Alt  | Super| Ctrl |LShift|      |                              | MsLft|MsDown| MsUp |MsRght|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      | Left | Down |  Up  |Right |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  | Right| Left |      | Mid  |      |
 *                        |      |      |      |      |      |  |  Btn |  Btn |      | Btn  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
 [_MOUSE] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                           KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, _______,
    _______, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                                           KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, KC_PSCR,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,      _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
                               _______, _______, _______,  KC_SPC,  KC_TAB ,      KC_BTN2, KC_BTN1, _______, KC_BTN3, _______
  ),
/*
 * Navigation layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      !      |      |      |      |                              | Home | PgDn | PgUp | End  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Alt  | Super| Ctrl |LShift|      |                              | Left | Down |  Up  | Right| Ins  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  | Right| Left | Mid  |      |      |
 *                        |      |      |      |      |      |  |  Btn |  Btn | Btn  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
 [_NAV] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                           KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,
    _______, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                                           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_PSCR,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               _______, _______, _______,  KC_SPC,  KC_TAB ,      KC_ENT,  KC_BSPC, KC_DEL,  _______, _______
  ),
/*
 * Media layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      !      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Alt  | Super| Ctrl |LShift|      |                              |      | Vol- | Vol+ |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      | Pause| Prev | VolUp| VolDn| Next |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  | Right| Left | Mid  |      |      |
 *                        |      |      |      |      |      |  |  Btn |  Btn | Btn  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
 [_MEDIA] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                                           XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,      _______, _______, KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
                               _______, _______, _______,  KC_SPC,  KC_TAB ,      KC_ENT,  KC_BSPC, KC_DEL,  _______, _______
  ),
/*
 * Adjust Layer: Layouts, KVM
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | RESET  |      |Qwerty|Colemk|Workmn| Game |                              |      |      |      |      |      | KVMSw  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      QK_BOOT,XXXXXXX,KC_QWERTY,KC_COLEMAK,KC_WORKMAN,KC_GAME,                                  _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _MOUSE, _FUNC, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }

    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
         case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
         case KC_GAME:
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

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n"), false);

    // Layout
    oled_write_P(PSTR("Layout: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("ColemakDH\n"), false);
            break;
        case _WORKMAN:
            oled_write_P(PSTR("Workman\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef\n"), false);
    }

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer:  "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _COLEMAK:
        case _GAME:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Function\n"), false);
            break;
        case _MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Navigate"), false);
            break;
        case _MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
    oled_write_ln_P(PSTR(""), false);

    // Host Keyboard LED Status
    // uint8_t led_usb_state = host_keyboard_leds();
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);

    // Modifiers
    uint8_t mod_state = get_mods();
    oled_write_P(PSTR("Ctl"), (mod_state & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Alt"), (mod_state & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Sup"), (mod_state & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Sft"), (mod_state & MOD_MASK_SHIFT));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif
