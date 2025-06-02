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
#include "features/achordion.h"
#include <stdio.h>

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

void query_all(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING("*");
    }
    else if (state->count == 3) {
        SEND_STRING("*:*");
    } else if (state->count >= 4) {
        SEND_STRING("[* TO *]");
    }
    reset_tap_dance(state);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_BRCK] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_CRLB] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_SQBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_ASTR] = ACTION_TAP_DANCE_FN(query_all)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |        |   A  |   S  |  D   |   F  |   G  |  |   H  |   J  |   K  |   L  | ;  : |        |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        |  Esc | Space|  Tab |  | Enter| BkSpc|Delete|
 *                        | Mouse|  Nav | Media|  |Symbol|Number| Func |
 *                        `--------------------'  `--------------------'
 */
  [_QWERTY] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
    XXXXXXX,LALT_T(KC_A),LGUI_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),    KC_G,      KC_H,    RSFT_T(KC_J),LCTL_T(KC_K),LGUI_T(KC_L),LALT_T(KC_SCLN), XXXXXXX,
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
          LT(_MOUSE,KC_ESC), LT(_NAV,KC_SPC), LT(_MEDIA,KC_TAB),    LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC), LT(_FUNC,KC_DEL)

  ),

/*
 * Base Layer: GAME
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
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
  [_GAME] = LAYOUT_split_3x6_3(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M, KC_LEFT,  KC_DOWN,  KC_UP,      KC_RGHT,
                   MO(_MOUSE),  KC_SPC, KC_TAB,  KC_ENT, KC_BSPC, MO(_FUNC)

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
    LCTL_T(KC_TAB),LALT_T(KC_A),LGUI_T(KC_R),LCTL_T(KC_S),LSFT_T(KC_T),    KC_G,      KC_M,    RSFT_T(KC_N),LCTL_T(KC_E),LGUI_T(KC_I),LALT_T(KC_O), KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,      KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, SC_SENT,
          LT(_MOUSE,KC_ESC), LT(_NAV,KC_SPC), LT(_MEDIA,KC_TAB),    LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC), LT(_FUNC,KC_DEL)
  ),

/*
 * NUM
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |        |   /  |   7  |   8  |   9  |  +   |  |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |        |   '  |   4  |   5  |   6  |  -   |  |      |RShift| Ctrl | Super| Alt  |        |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * |        |   |  |   1  |   2  |   3  | = +  |  |      |      |      |      |      |        |
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        |   0  |   .  |  Tab |  | Enter| NUM  |      |
 *                        |      |      |      |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_NUM] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_SLSH,	KC_7,		KC_8,		KC_9,	    KC_PLUS,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX, XXXXXXX,
    XXXXXXX,  KC_QUOT,	KC_4,		KC_5,		KC_6,	    KC_MINS,			XXXXXXX,	KC_RSFT,	KC_LCTL,	KC_LGUI,    KC_LALT, XXXXXXX,
    XXXXXXX, S(KC_NUBS),KC_1,		KC_2,		KC_3,       KC_EQL, 	    	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,XXXXXXX,
                               KC_0,	    KC_DOT,	    KC_TAB,    KC_ENT, _______, _______
  ),

/*
 * SYM
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |        |   `  |   &  |   *  |  ( ) |  [ ] |  |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |        |   @  |   $  |   %  |   ^  |  { } |  |      |RShift| Ctrl | Super| Alt  |        |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * |        |  \ | |   !  |   "  |   £  | # ~  |  |      |      |      |      |      |        |
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        |  Del | Space|  Tab |  | SYM  |      |      |
 *                        |      |      |      |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_SYM] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_GRV,   KC_AMPR,		TD(TD_ASTR),		TD(TD_BRCK),TD(TD_SQBR),	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX, XXXXXXX,
    XXXXXXX,S(KC_QUOT), KC_DLR,		    KC_PERC,		KC_CIRC,	TD(TD_CRLB),			XXXXXXX,	KC_RSFT,	KC_LCTL,	KC_LGUI,    KC_LALT, XXXXXXX,
    XXXXXXX, KC_NUBS,	KC_EXLM,		KC_AT,  		KC_HASH,	KC_NUHS, 	    	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,XXXXXXX,
                               KC_DEL,	    KC_SPC,	    KC_TAB,    _______, _______, _______
  ),

/*
 * FUNC
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |        |      |  F7  |  F8  |  F9  |  F10 |  |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |        |      |  F4  |  F5  |  F6  |  F11 |  |      |RShift| Ctrl | Super| Alt  |        |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * |        |PrtScr|  F1  |  F2  |  F3  |  F12 |  |      |      |      |      |      |        |
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        |ADJUST| Space|  Tab |  | Enter|      | FUNC |
 *                        |      |      |      |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_FUNC] = LAYOUT_split_3x6_3(
    _______, _______,    KC_F7,	    KC_F8,		KC_F9,	    KC_F10,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX, XXXXXXX,
    KC_TAB,  _______,    KC_F4,	    KC_F5,		KC_F6,	    KC_F11,			XXXXXXX,	KC_RSFT,	KC_LCTL,	KC_LGUI,    KC_LALT, XXXXXXX,
    XXXXXXX, KC_PSCR,	 KC_F1,	    KC_F2,		KC_F3,	    KC_F12, 	    XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX, XXXXXXX,
                               MO(_MOUSE),	    KC_DOT,	    KC_TAB,    KC_ENT, _______, _______
  ),

/*
 * MOUSE
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |        |      |      |      |      |      |  |WhlLft| WhlUp|WhlDn |WhlRt |      |        |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |        | Alt  | Super| Ctrl |LShift|      |  | MsLft|MsDown| MsUp |MsRght|      |        |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * |        |      |      |      |      |      |  | Left | Down |  Up  |Right |  Mid |        |
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        | MOUSE|      |      |  | Right| Left |ADJUST|
 *                        |      |      |      |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_MOUSE] = LAYOUT_split_3x6_3(
    _______, XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			KC_WH_L,	KC_WH_D,	KC_WH_U,	KC_WH_R,	XXXXXXX, XXXXXXX,
    KC_TAB,  KC_LALT,	KC_LGUI,	KC_LCTL,	KC_LSFT,    XXXXXXX,		    KC_MS_L,	KC_MS_D,	KC_MS_U,	KC_MS_R,	XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			KC_LEFT,	KC_DOWN,	KC_UP,  	KC_RGHT,	KC_BTN3, XXXXXXX,
                               _______,	    XXXXXXX,	    XXXXXXX,            KC_BTN2,    KC_BTN1,    MO(_FUNC)
  ),

/*
 * NAV
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |        |      |      |      |      |      |  | Home | PgDn | PgUp | End  |      |        |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |        | Alt  | Super| Ctrl |LShift|      |  | Left | Down |  Up  | Right| Ins  |        |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * |        |      |      |      |      |      |  |      |      |      |      |      |        |
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        |      |  NAV |      |  | Enter| BSpc | Del  |
 *                        |      |      |      |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_NAV] = LAYOUT_split_3x6_3(
    _______, XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,	    XXXXXXX, XXXXXXX,
    KC_TAB,  KC_LALT,	KC_LGUI,	KC_LCTL,	KC_LSFT,    XXXXXXX,		    KC_LEFT,	KC_DOWN,	KC_UP,	    KC_RGHT,	KC_INS,  XXXXXXX,
    XXXXXXX, XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX, XXXXXXX,
                               _______,	    XXXXXXX,	    XXXXXXX,            KC_ENT,     KC_BSPC,    KC_DEL
  ),

/*
 * MEDIA
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |        |      |      |      |      |      |  |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|  |------+------+------+------+------+--------|
 * |        | Alt  | Super| Ctrl |LShift|      |  | Prev | VolUp| VolDn| Next |      |        |
 * |--------+------+------+------+------+------.  ,-------------+------+------+------+--------|
 * |        |      |      |      |      |      |  | Pause| Prev | VolUp| VolDn| Next |        |
 * `----------------------+------+------+------|  |------+------+------+------+------+--------'
 *                        |      |      | MEDIA|  | Enter| BSpc | Del  |
 *                        |      |      |      |  |      |      |      |
 *                        `--------------------'  `--------------------'
 */
  [_MEDIA] = LAYOUT_split_3x6_3(
    _______, XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX, XXXXXXX,
    KC_TAB,  KC_LALT,	KC_LGUI,	KC_LCTL,	KC_LSFT,    XXXXXXX,		    KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,	XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			KC_MPLY,	KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,XXXXXXX,
                               _______,	    XXXXXXX,	    XXXXXXX,            KC_ENT,     KC_BSPC,    KC_DEL
  ),



/*
 * Adjust Layer: Layouts, KVM
 *
 * ,-------------------------------------------.  ,-------------------------------------------.
 * |  RESET |      |Qwerty|Colemk|      | Game |  |      |      |      |      |      | KVMSw  |
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
    QK_BOOT, XXXXXXX,KC_QWERTY,KC_COLEMAK,XXXXXXX,KC_GAME,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,    XXXXXXX, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,
                               KC_LGUI, _______,  KC_SPC,    KC_ENT, _______, KC_RALT
  )
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


void matrix_scan_user(void) {
    achordion_task();
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
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Func\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse"), false);  // No return at end of line
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media"), false);  // No return at end of line
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);

    // Modifiers
    uint8_t mod_state = get_mods();
    oled_write_ln_P(PSTR("Sft"), (mod_state & MOD_MASK_SHIFT));
    oled_write_ln_P(PSTR("Ctl"), (mod_state & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL));
    oled_write_ln_P(PSTR("Alt"), (mod_state & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT));
    oled_write_ln_P(PSTR("Sup"), (mod_state & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI));
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
