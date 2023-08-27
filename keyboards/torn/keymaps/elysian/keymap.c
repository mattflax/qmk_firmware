/* Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com)
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
#include <stdio.h>

/*enum torn_layers { _QWERTY, _LOWER, _RAISE, _ADJUST };*/

enum torn_layers {
    _QWERTY = 0,
    _GAME,
    _COLEMAK,
    _WORKMAN,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAME,
    KC_COLEMAK,
    KC_WORKMAN,
    KC_KVMSWITCH,
    KC_WS1, KC_WS2, KC_WS3, KC_WS4, KC_WS5, KC_WS6, KC_WS7, KC_WS8, KC_WS9, KC_WS10
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |    |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |CtlTab|   A  |   S  |   D  |   F  |   G  |    |   H  |   J  |   K  |   L  |   ;  | ' @  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |    |   N  |   M  |   ,  |   .  |   /  |EntShf|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | Alt  | Ctrl | Lower|Space |    |Space |Raise | Func | Ctrl |
 *               |      |      |      | Alt  |    |      |      |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_QWERTY] = LAYOUT_split_3x6_4(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    LCTL_T(KC_TAB),KC_A,KC_S,  KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_SFTENT,
         KC_LALT,KC_LGUI,MO(_LOWER),   LALT_T(KC_SPC),      KC_SPC,MO(_RAISE),MO(_FUNCTION),KC_LCTL
),

/*
 * Base Layer: ColemakDH
 *
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   B  |    |   J  |   L  |   U  |   Y  |   ;  |BckSpc|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |CtlTab|   A  |   R  |  S   |   T  |   G  |    |   M  |   N  |   E  |   I  |   O  |  ' " |
 * |------+------+------+------+------+------.    ,-------------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   D  |   V  |    |   K  |   H  | ,  < | . >  | /  ? |SftEnt|
 * `--------------------+------+------+------|    |------+------+------+------+------+------'
 *               | Alt  | Ctrl | Lower|Space |    |Space |Raise | Func | Ctrl |
 *               |      |      |      | Alt  |    |      |      |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_COLEMAK] = LAYOUT_split_3x6_4(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
    LCTL_T(KC_TAB),KC_A,KC_R,  KC_S,    KC_T,    KC_G,      KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_SFTENT,
         KC_LALT,KC_LGUI,MO(_LOWER),   LALT_T(KC_SPC),      KC_SPC,MO(_RAISE),MO(_FUNCTION),KC_LCTL
),

/* Game
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Escape |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |BackSpc |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |  Tab   |   A  |   S  |  D   |   F  |   G  |  |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  | ,  < | . >  | /  ? |SftEnter|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | Alt  | Ctrl | Lower|Space |    |Space |Raise | Func | Ctrl |
 *               |      |      |      |      |    |      |      |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_GAME] = LAYOUT_split_3x6_4(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_SFTENT,
          KC_LALT,  KC_LCTL,MO(_LOWER), LALT_T(KC_SPC),   KC_SPC,  MO(_RAISE), MO(_FUNCTION),KC_LCTL
),

/* Lower
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |    |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |   [  |   ]  |   {  |   }  | Home |    |  End |   _  |   +  | PgDn | PgUp |  Ins |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |    |   \  |  #   | SLeft|SDown | SUp  |SRight|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ | Ctrl | Bksp | Del  |    |Enter |Space | Alt  | ____ |
 *               |      |      |Shift |Raise |    | Gui  |Lower |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_LOWER] = LAYOUT_split_3x6_4(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_HOME,    KC_END,  KC_UNDS, KC_PLUS, KC_PGDN, KC_PGUP, KC_INS,
    KC_CAPS, _______, _______, _______, _______, _______,    KC_NUBS, KC_NUHS, S(KC_LEFT),S(KC_DOWN),S(KC_UP),S(KC_RGHT),
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Raise
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |  ¬   |   1  |   2  |   3  |   4  |   5  |    |  6   |   7  |   8  |   9  |   0  |Delete|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Tab  | WS1  | WS2  | WS2  | WS4  | WS5  |    |      |   -  |   =  |  [   |  ]   |Insert|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      | WS6  | WS7  | WS8  | WS9  | WS10 |    |   |  |   ~  | Left | Down |  Up  | Right|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ | ____ |      | Ctrl |    |      |      |      | ____ |
 *               |      |      |      |      |    |      |      |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_RAISE] = LAYOUT_split_3x6_4(
    S(KC_GRV),KC_1,   KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_TAB,  KC_WS1,  KC_WS2,  KC_WS3,  KC_WS4,  KC_WS5,     _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_INS,
    KC_CAPS, KC_WS6,  KC_WS7,  KC_WS8,  KC_WS9,  KC_WS10,    S(KC_NUBS),S(KC_NUHS),KC_LEFT,KC_DOWN,KC_UP, KC_RGHT,
                      KC_TRNS, KC_TRNS, KC_LCTL, KC_LCTL,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Function
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |      | F1   |  F2  | F3   | F4   | F5   |    | F6   | F7   |  F8  | F9   | F10  |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      | F11  |    | F12  |      |      |      |      |PrtScr|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    | Play |      | Prev | Vol- | Vol+ | Next |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               |      |      |      |      |    |      |      |      |      | ____ |
 *               |      |      |      |      |    |      |      |      |      |      |
 *               `---------------------------'    `----------------------------------'
 */
[_FUNCTION] = LAYOUT_split_3x6_4(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,     KC_F7,   KC_F8,   KC_F9,  KC_F10,  _______,
    _______, _______, _______, _______, _______, KC_F11,     KC_F12,  _______, _______, _______, _______, KC_PSCR,
    _______, _______, _______, _______, _______, _______,    KC_MPLY, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
                      _______, _______, _______, _______,    _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | RESET|      |Qwerty|Clmak |      | Game |    |      |      |      |      |      | KVMSw|
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ | Ctrl | Bksp | Del  |    |Enter |Space | Alt  | ____ |
 *               |      |      |Shift |Raise |    | Gui  |Lower |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_ADJUST] = LAYOUT_split_3x6_4(
    QK_BOOT,_______,KC_QWERTY,KC_COLEMAK,_______,KC_GAME,   _______, _______, _______, _______, _______, KC_KVMSWITCH,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    torn_set_led(0, IS_LAYER_ON_STATE(state, _LOWER));
    torn_set_led(1, IS_LAYER_ON_STATE(state, _RAISE));
    torn_set_led(2, IS_LAYER_ON_STATE(state, _FUNCTION));
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
         case KC_WORKMAN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WORKMAN);
            }
            return false;
        case KC_KVMSWITCH:
            if (record->event.pressed) {
                // KVM Switch key pressed - send switch sequence
                // ScrlLock, ScrlLock, Up
                SEND_STRING(SS_TAP(X_SCRL) SS_TAP(X_SCRL) SS_TAP(X_UP));
            }
            break;
        case KC_WS1:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("1"));
                break;
            }
        case KC_WS2:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("2"));
                break;
            }
        case KC_WS3:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("3"));
                break;
            }
        case KC_WS4:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("4"));
                break;
            }
        case KC_WS5:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("5"));
                break;
            }
        case KC_WS6:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("6"));
                break;
            }
        case KC_WS7:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("7"));
                break;
            }
        case KC_WS8:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("8"));
                break;
            }
        case KC_WS9:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("9"));
                break;
            }
        case KC_WS10:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("0"));
                break;
            }
        default:
            return true;
    }
    return true;
}

