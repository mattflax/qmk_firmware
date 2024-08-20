/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
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

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_GAME,
};

// Tap dance definitions
enum {
    TD_BRCK,
    TD_CRLB,
    TD_SQBR
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_BRCK] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_CRLB] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_SQBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |                      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  |CAPS |    |NUMLK|  |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,---------------------.   ,-----.
 *          |  1  |   | Esc | SPACE | TAB  |            | Enter | BS  |  Del  |   |  4  |
 *          |     |   |Mouse| Nav   | Media|            |  Sym  | Num | Func  |   |     |
 *          `-----'   `--------------------'            `---------------------'   `-----'
 */
[_QWERTY] = LAYOUT(
	KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
	LGUI_T(KC_A), LALT_T(KC_S),	LCTL_T(KC_D), LSFT_T(KC_F),	KC_G,		KC_H, LSFT_T(KC_J),	LCTL_T(KC_K), LALT_T(KC_L),	LGUI_T(KC_SCLN),
	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,	 KC_M, KC_COMM,  KC_DOT, KC_SLSH,
	KC_1,  LT(_MOUSE,KC_ESC), LT(_NAV,KC_SPC), LT(_MEDIA,KC_TAB), KC_CAPS,		KC_NUM,	LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC), LT(_FUNC,KC_DEL),	KC_4
),

/* Colemak-DH
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |                      |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |                      |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |  |  2  |    |  3  |  |   K  |   H  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            | TO(0) | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_COLEMAKDH] = LAYOUT(
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
  KC_A,    MT(MOD_LALT, KC_R),    MT(MOD_LCTL, KC_S),    MT(MOD_LSFT, KC_T),    KC_G,         KC_M,    MT(MOD_LSFT, KC_N),    MT(MOD_LCTL, KC_E),    MT(MOD_LALT, KC_I),    KC_O,
  KC_Z,    KC_X,    KC_C,    MT(MOD_LGUI, KC_D),    KC_V,         KC_K,    MT(MOD_LGUI, KC_H),    KC_COMM, KC_DOT,  KC_SLSH,
	KC_1,  LT(_MOUSE,KC_ESC), LT(_NAV,KC_SPC), LT(_MEDIA,KC_TAB), KC_CAPS,		KC_NUM,	LT(_SYM,KC_ENT), LT(_NUM,KC_BSPC), LT(_FUNC,KC_DEL),	KC_4
),

/* GAME
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |                      |      |      |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |Shift |   A  |   S  |   D  |   F  |                      |      |      |      |      |      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |  |  2  |    |  3  |  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   |  T  | SPACE | TAB  |            | Enter | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_GAME] = LAYOUT(
  KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,         KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
  KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,         KC_NO,    KC_NO,    KC_NO, KC_NO,  KC_NO,
  KC_1,     KC_T, KC_SPC, KC_TAB, KC_2,         KC_3, KC_ENT, KC_BSPC, KC_ENT, KC_QWERTY
),

/* NAVNUM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   /  |   7  |   8  |   9  |  -   |                      |      |      |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   (  |   4  |   5  |   6  |  +   |                      |      | Shft | Ctrl |  Alt |Super |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   )  |   1  |   2  |   3  |  *   |  |CAPS |    |NUMLK|  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,------------------.            ,--------------------.   ,-----.
 *          |  1  |   |  0 |   .  | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `------------------'            `--------------------'   `-----'
 */
[_NUM] = LAYOUT(
	KC_SLSH,	KC_7,		KC_8,		KC_9,	    KC_MINS,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	KC_LPRN,	KC_4,		KC_5,		KC_6,	    KC_PLUS,			XXXXXXX,	KC_LSFT,	KC_LCTL,	KC_LALT,	KC_LGUI,
	KC_RPRN,	KC_1,		KC_2,		KC_3,       KC_ASTR,	    	XXXXXXX,	XXXXXXX,	_______,	_______,	_______,
	KC_1,		KC_0,	    KC_DOT,	    KC_TAB,		KC_CAPS,			KC_NUM,		KC_ESC,	    _______,	KC_ENT,	    KC_4
),

/* SYM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   `  |   &  |   *  |  ( ) |  [ ] |                      |      |      |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   '  |   $  |   %  |   ^  |  { } |                      |      | Shft | Ctrl |  Alt |Super |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   \  |   !  |   "  |   £  |   ~  |  |CAPS |    |NUMLK|  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_SYM] = LAYOUT(
	KC_GRV,     KC_AMPR,		KC_ASTR,		TD(TD_BRCK),TD(TD_SQBR),	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	KC_QUOT,	KC_DLR,		    KC_PERC,		KC_CIRC,	TD(TD_CRLB),	XXXXXXX,	KC_LSFT,	KC_LCTL,	KC_LALT,	KC_LGUI,
	KC_BSLS,	KC_EXLM,		KC_DQUO,		KC_HASH,	KC_TILD,		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	KC_1,		KC_DEL,	        KC_SPC,	        KC_TAB,		KC_CAPS,		KC_NUM,		_______,	KC_BSPC,	KC_ENT,	    KC_4
),

/* FUNC
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |  F11 |  F7  |  F8  |  F9  |      |                      |      |      |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |  F12 |  F4  |  F5  |  F6  |      |                      |      | Shft | Ctrl |  Alt |Super |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |PrtScr|  F1  |  F2  |  F3  |      |  |CAPS |    |NUMLK|  | Pause| Prev | VolUp| VolDn| Next |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | F10 | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_FUNC] =  LAYOUT(
	KC_F11,	    KC_F7,	    KC_F8,		KC_F9,	    XXXXXXX,		XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	KC_F12,	    KC_F4,	    KC_F5,		KC_F6,	    XXXXXXX,		XXXXXXX,	KC_LSFT,	KC_LCTL,	KC_LALT,	KC_LGUI,
	KC_PSCR,	KC_F1,	    KC_F2,		KC_F3,	    XXXXXXX,		KC_MPLY,	KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,
	_______,    KC_F10,	    KC_SPC,	    KC_TAB,	    _______,		_______,    KC_ESC,	    KC_BSPC,	_______,	_______
),

/* MOUSE
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      |WhlLft| WhlUp|WhlDn |WhlRt |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |Super |  Alt | Ctrl |Shift |      |                      | MsLft|MsDown| MsUp |MsRght|      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |      |      |      |  |CAPS |    |NUMLK|  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   |     |       |      |            | Right |Left|Middle |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_MOUSE] =  LAYOUT(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			KC_WH_L,	KC_WH_D,	KC_WH_U,	KC_WH_R,	XXXXXXX,
	KC_LGUI,    KC_LALT,	KC_LCTL,	KC_LSFT,    KC_NO,			    KC_MS_L,	KC_MS_D,	KC_MS_U,	KC_MS_R,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	_______,    _______,	_______,	_______,	_______,		    KC_BTN2,	KC_BTN1,	KC_BTN3,	_______,	_______
),

/* NAV
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      | Home | PgDn | PgUp | End  |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |Super | Alt  | Ctrl |Shift |      |                      | Left | Down |  Up  | Right| Ins  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |      |      |      |  |CAPS |    |NUMLK|  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | Esc | SPACE | TAB  |            | Enter | BS |  Del  |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_NAV] =  LAYOUT(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,	    XXXXXXX,
	KC_LGUI,    KC_LALT,	KC_LCTL,	KC_LSFT,    XXXXXXX,		    KC_LEFT,	KC_DOWN,	KC_UP,	    KC_RGHT,	KC_INS,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	_______,    _______,	_______,	_______,	_______,		    _______,	KC_ENT,	    KC_BSPC,	KC_DEL,	    _______
),

/* Media
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      |      |      |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |Super |  Alt | Ctrl |Shift |      |                      |      |      |      |      |      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |      |      |      |  |CAPS |    |NUMLK|  | Pause| Prev | VolUp| VolDn| Next |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | Esc | SPACE | TAB  |            | Enter | BS |  Del  |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_MEDIA] =  LAYOUT(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	KC_LGUI,    KC_LALT,	KC_LCTL,	KC_LSFT,    KC_NO,			    XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,			KC_MPLY,	KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,
	_______,    _______,	_______,	_______,	_______,		    _______,	KC_ENT,	    KC_BSPC,	KC_DEL,	    _______
),

/* Adjust
 *
 * ,----------------------------------.                      ,----------------------------------.
 * | Reset|      | Qwrt | Clmk | Game |                      |      |      |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      |      |      |      |      |                      |      |      |      |      |      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |      |      |      |  |CAPS |    |NUMLK|  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   | DEL | SPACE | TAB  |            |  ESC  | BS | ENTER |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_ADJUST] = LAYOUT(
    QK_BOOT,    XXXXXXX,    KC_QWERTY,  KC_COLEMAK, KC_GAME,            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    _______,    _______,	_______,	_______,	_______,		    _______,	_______,	_______,	_______,	_______
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
         case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
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

#ifdef OLED_ENABLE
static void render_status(void) {
    // QMK Logo and version information
    oled_write_P(PSTR("Waterfowl\n\n"), false);

    // Layout
    oled_write_ln_P(PSTR("Layout: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case _COLEMAKDH:
            oled_write_P(PSTR("ColemakDH\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef\n"), false);
    }
    oled_write_ln_P(PSTR(""), false);

    // Host Keyboard Layer Status
    oled_write_ln_P(PSTR("Layer:  "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _COLEMAKDH:
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
    oled_write_ln_P(PSTR("Sft"), (mod_state & MOD_MASK_SHIFT));
    oled_write_ln_P(PSTR("Ctl"), (mod_state & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL));
    // oled_write_P(PSTR(" "), false);
    oled_write_ln_P(PSTR("Alt"), (mod_state & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT));
    // oled_write_P(PSTR(" "), false);
    oled_write_ln_P(PSTR("Sup"), (mod_state & MOD_BIT(KC_LGUI)) == MOD_BIT(KC_LGUI));
    // oled_write_ln_P(PSTR(" "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
        return false;
    }
    return true;
}
#endif
