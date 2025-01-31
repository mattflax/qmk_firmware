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

enum layers {
    _QWERTY = 0,
    _COLEMAK,
    _WORKMAN,
    _GAME,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_WORKMAN,
    KC_GAME,
    KC_KVMSWITCH,
    KC_WS1, KC_WS2, KC_WS3, KC_WS4, KC_WS5, KC_WS6, KC_WS7, KC_WS8, KC_WS9, KC_WS10
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Escape |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |BackSpc |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Tab|   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | Home | Meh  |  | Hyper|  End |   N  |   M  | ,  < | . >  | /  ? |SftEnter|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Ctrl | Alt  | Super| Lower| Space|  | Space| Raise| RAlt | Func | LEAD |
 *                        |      |      |      |      |  Alt |  | Lower|      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      LCTL_T(KC_TAB),KC_A,KC_S,KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_HOME, KC_MEH,  KC_HYPR,   KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
            KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER), LALT_T(KC_SPC), LT(_LOWER, KC_SPC), MO(_RAISE), KC_RALT, MO(_FUNCTION), KC_LEAD
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
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   KC_HOME, KC_MEH,   KC_HYPR,  KC_END,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
            KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER), LALT_T(KC_SPC), LT(_LOWER, KC_SPC), MO(_RAISE), KC_RALT, MO(_FUNCTION), KC_LEAD
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
      KC_LSFT, KC_Z,   KC_X,   KC_M,   KC_C,   KC_V,   KC_HOME, KC_DEL,   KC_BSPC,  KC_END,  KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
              KC_MEH, KC_LALT, KC_LGUI,MO(_LOWER), LALT_T(KC_SPC), LT(_LOWER, KC_SPC), MO(_RAISE), KC_TAB,  KC_LEAD, TT(_FUNCTION)
    ),
/*
 * Base Layer: Game
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | Escape |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |BackSpc |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | Home | Del  |  | BkSp |  End |   N  |   M  | ,  < | . >  | /  ? |SftEnter|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Ctrl | Alt  | Super| Lower| Space|  | Space| Raise| Tab  | LEAD | Func |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_GAME] = LAYOUT(
      KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_TAB,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_HOME, KC_DEL,   KC_BSPC,  KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
                           KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER),KC_SPC,  KC_SPC,MO(_RAISE),KC_TAB,  KC_LEAD, TT(_FUNCTION)
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  !   |   "  | # £  |   $  |   %  |                              |   ^  |   &  |   *  |   (  |   )  | Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  [   |   ]  |   {  |   }  | Home |                              | End  |   _  |   +  |      |      | Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | CapsLk |      |      |      |      |      |      |      |  |      |      |   \  |   #  |SfLeft|SfDown|ShftUp|SRight  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT(
      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
      _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_HOME,                                     KC_END,  KC_UNDS, KC_PLUS, _______, _______, KC_INS,
      KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NUBS, KC_NUHS, S(KC_LEFT),S(KC_DOWN),S(KC_UP),S(KC_RGHT),
                                 _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
    ),
/*
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    ¬   |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   | Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | WS1  | WS2  | WS2  | WS4  | WS5  |                              |      |  -   |  =   |      |      | Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | WS6  | WS7  | WS8  | WS9  | WS10 |      |      |  |      |      |   |  |  ~   | Left | Down |  Up  | Right  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      | Alt  |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      S(KC_GRV),KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
      _______, KC_WS1,  KC_WS2,  KC_WS3,  KC_WS4,  KC_WS5,                                      _______, KC_MINS, KC_EQL,  _______, _______, KC_INS,
      _______, KC_WS6,  KC_WS7,  KC_WS8,  KC_WS9,  KC_WS10, _______, _______, _______, _______, S(KC_NUBS),S(KC_NUHS),KC_LEFT,KC_DOWN,KC_UP, KC_RGHT,
                                 _______, _______, _______, _______, KC_LALT, _______, _______, _______, _______, _______
    ),
/*
 * Function layer: Function keys, media
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      | F11  |                              | F12  |      |      |      |      | PrtScr |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      | Play |      | Prev | Vol- | Vol+ | Next   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  | Play/|      |      |      |      |
 *                        |      |      |      |      |      |  | Pause|      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, _______, _______, _______, _______, KC_F11,                                      KC_F12,  _______, _______, _______, _______, KC_PSCR,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
                                 _______, _______, _______, _______, _______, KC_MPLY, _______, _______, _______, _______
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
      QK_BOOT,XXXXXXX,KC_QWERTY,KC_COLEMAK,KC_WORKMAN,KC_GAME,                                    _______, _______, _______, _______, _______, KC_KVMSWITCH,
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
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
         case KC_WORKMAN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WORKMAN);
            }
            return false;
         case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
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
        case _WORKMAN:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Func\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);

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

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Top row - switch workspaces
        SEQ_ONE_KEY(KC_Q) {
            SEND_STRING(SS_LGUI("1"));
        }
        SEQ_ONE_KEY(KC_W) {
            SEND_STRING(SS_LGUI("2"));
        }
        SEQ_ONE_KEY(KC_E) {
            SEND_STRING(SS_LGUI("3"));
        }
        SEQ_ONE_KEY(KC_R) {
            SEND_STRING(SS_LGUI("4"));
        }
        SEQ_ONE_KEY(KC_T) {
            SEND_STRING(SS_LGUI("5"));
        }
        SEQ_ONE_KEY(KC_Y) {
            SEND_STRING(SS_LGUI("6"));
        }
        SEQ_ONE_KEY(KC_U) {
            SEND_STRING(SS_LGUI("7"));
        }
        SEQ_ONE_KEY(KC_I) {
            SEND_STRING(SS_LGUI("8"));
        }
        SEQ_ONE_KEY(KC_O) {
            SEND_STRING(SS_LGUI("9"));
        }
        SEQ_ONE_KEY(KC_P) {
            SEND_STRING(SS_LGUI("0"));
        }
    }
}

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
