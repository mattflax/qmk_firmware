/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

enum LAYERS {
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

// Tap dance definitions
enum {
    TD_BRCK,
    TD_CRLB,
    TD_SQBR
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_BRCK] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_CRLB] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_SQBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * | Escape |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |BackSpc |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |Ctrl/Tab|   A  |   S  |  D   |   F  |   G  |  |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  | ,  < | . >  | /  ? |SftEnter|
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        | Super| Lower| Space|  | Space| Raise| Fn   |
 *                        |      |      |  Alt |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_QWERTY] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LCTL_T(KC_TAB),KC_A,KC_S,  KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SC_SENT,
          KC_LGUI,MO(_LOWER), LALT_T(KC_SPC),    KC_SPC,  MO(_RAISE), MO(_FUNCTION)

  ),

/*
 * Base Layer: GAME
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * | Escape |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |BackSpc |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |  Tab   |   A  |   S  |  D   |   F  |   G  |  |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  | ,  < | . >  | /  ? |SftEnter|
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        | Ctrl | Lower| Space|  | Space| Raise| Alt  |
 *                        |      |      |      |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_GAME] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SC_SENT,
                   KC_LCTL,  MO(_LOWER), KC_SPC,  KC_SPC,  MO(_RAISE), MO(_FUNCTION)

  ),

/*
 * Base Layer: ColemakDH
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
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
  [_COLEMAK] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
    LCTL_T(KC_TAB),KC_A,KC_R,  KC_S,    KC_T,    KC_G,      KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, SC_SENT,
          KC_LGUI,MO(_LOWER), LALT_T(KC_SPC),    KC_SPC,  MO(_RAISE), MO(_FUNCTION)
  ),

/*
 * Base Layer: Workman
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * | Escape |   Q  |   D  |   R  |   W  |   B  |  |   J  |   F  |   U  |   P  |   ;  |BackSpc |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |Ctrl/Tab|   A  |   S  |   H  |   T  |   G  |  |   Y  |   N  |   E  |   O  |   I  |  ' "   |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * | LShift |   Z  |   X  |   M  |   C  |   V  |  |   K  |   L  | ,  < | . >  | /  ? |SftEnter|
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        | Super| Lower| Space|  | Space| Raise| Fn   |
 *                        |      |      |  Alt |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_WORKMAN] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,      KC_J,    KC_F,    KC_U,    KC_P, KC_SCLN, KC_BSPC,
    LCTL_T(KC_TAB),KC_A,KC_S,  KC_H,    KC_T,    KC_G,      KC_Y,    KC_N,    KC_E,    KC_O,    KC_I, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,      KC_K,    KC_L, KC_COMM,  KC_DOT, KC_SLSH, SC_SENT,
          KC_LGUI,MO(_LOWER), LALT_T(KC_SPC),    KC_SPC,  MO(_RAISE), MO(_FUNCTION)
  ),

/*
 * Lower - Symbols
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |    `   |  !   |   "  | # £  |   $  |   %  |  |   ^  |   &  |   *  |   (  |   )  | Delete |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |Nav Mode|      |      | [  ] | {  } | Home |  |  End |   _  |   +  | PgDn | PgUp | Insert |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * | CapsLk |      |      |      |      |      |  |   \  |   #  |SfLeft|SfDown|ShftUp| SRight |
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        |Super | Lower| Space|  | Space| Raise|      |
 *                        |      |      |  Alt |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_LOWER] = LAYOUT_split_3x6_3(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_TAB,_______,_______,TD(TD_SQBR),TD(TD_CRLB),KC_HOME,    KC_END,  KC_UNDS, KC_PLUS, KC_PGDN, KC_PGUP, KC_INS,
    KC_CAPS, _______, _______, _______, _______, _______,    KC_NUBS, KC_NUHS, S(KC_LEFT),S(KC_DOWN),S(KC_UP),S(KC_RGHT),
                               _______, _______, _______,    _______, _______, _______
  ),

/*
 * Raise - numbers
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |    ¬   |   1  |  2   |  3   |  4   |  5   |  |  6   |  7   |  8   |  9   |  0   | Delete |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |  Tab   | WS1  | WS2  | WS2  | WS4  | WS5  |  |      |   -  |   =  |  [   |  ]   | Insert |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * | CapsLk | WS6  | WS7  | WS8  | WS9  | WS10 |  |   |  |   ~  | Left | Down |  Up  | Right  |
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        |      |      |LCtrl |  |      |      |      |
 *                        |      |      |      |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_RAISE] = LAYOUT_split_3x6_3(
    S(KC_GRV),KC_1,   KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_TAB,  KC_WS1,  KC_WS2,  KC_WS3,  KC_WS4,  KC_WS5,     _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_INS,
    KC_CAPS, KC_WS6,  KC_WS7,  KC_WS8,  KC_WS9,  KC_WS10,    S(KC_NUBS),S(KC_NUHS),KC_LEFT,KC_DOWN,KC_UP, KC_RGHT,
                               _______, _______, KC_LCTL,    _______,  _______, _______
  ),

/*
 * Function
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |  | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |        |      |      |      |      | F11  |  | F12  |      |      |      |      | PrtScr |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * |        |      |      |      |      |      |  | Play |      | Prev | Vol- | Vol+ |  Next  |
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        |      |      |      |  |      |      |      |
 *                        |      |      |      |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_FUNCTION] = LAYOUT_split_3x6_3(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,     KC_F7,   KC_F8,   KC_F9,  KC_F10,  _______,
    _______, _______, _______, _______, _______, KC_F11,     KC_F12,  _______, _______, _______, _______, KC_PSCR,
    _______, _______, _______, _______, _______, _______,    KC_MPLY, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
                               _______, _______, _______,    _______, _______, _______
  ),

/*
 * Adjust Layer: Layouts, KVM
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |  RESET |      |Qwerty|Colemk|Wrkman| Game |  |      |      |      |      |      | KVMSw  |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |  |RGB On| Mode+| Hue+ | Sat+ | Val+ |        |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * |        |      |      |      |      |      |  |      | Mode-| Hue- | Sat- | Val- |        |
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        | Super| Lower| Space|  | Space| Raise| Tab  |
 *                        |      |      | Raise|  | Lower|      |      |
 *                        `--------------------'  `--------------------'
 */
  [_ADJUST] = LAYOUT_split_3x6_3(
    QK_BOOT, XXXXXXX,KC_QWERTY,KC_COLEMAK,KC_WORKMAN,KC_GAME,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KVMSWITCH,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,    XXXXXXX, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,
                               KC_LGUI, _______,  KC_SPC,    KC_ENT, _______, KC_RALT
  )
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
                SEND_STRING(SS_TAP(X_SCRL) SS_TAP(X_SCRL) SS_TAP(X_PGUP));
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

static void print_status_narrow(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        case _WORKMAN:
            oled_write_P(PSTR("Wrkmn"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);  // No return at end of line
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);  // No return at end of line
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Func\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
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

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

static void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_DRIVER_ENABLE
