#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

enum layer_number {
  _QWERTY,
  _WORKMAN,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _FUNCTION,
  _ADJUST,
};

/* Custom keycodes for function layers */
enum custom_keycodes {
  KVMSWTCH = SAFE_RANGE,
  QWERTY,
  WORKMAN,
  COLEMAK,
  LOWER,
  RAISE,
  KC_WS1, KC_WS2, KC_WS3, KC_WS4, KC_WS5, KC_WS6, KC_WS7, KC_WS8, KC_WS9, KC_WS10
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LAlt  | LGUI |LOWER | /Space+ /       \Space \  |RAISE | LCtl |  FN  |
 *                   |      |      |      |/ Alt   /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_ESC,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  LCTL_T(KC_TAB),KC_A,KC_S, KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
                            KC_LALT, KC_LGUI, LOWER,LALT_T(KC_SPC),KC_SPC,RAISE,KC_LCTL, MO(_FUNCTION) \
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
[_COLEMAK] = LAYOUT( \
  KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_LCTL, KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,    KC_LBRC, KC_RBRC, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
                            KC_LALT, KC_LGUI, LOWER,LALT_T(KC_SPC),KC_SPC,RAISE,KC_LCTL, MO(_FUNCTION) \
),

/*
 * WORKMAN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |                    |   J  |   F  |   U  |   P  |   ;  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtrl |   A  |   S  |   H  |   T  |   G  |-------.    ,-------|   Y  |   N  |   E  |   O  |   I  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | HOME  |------+------+------+------+------+------|
 * |Sft/CL|   Z  |   X  |   M  |   C  |   V  |-------|    |-------|   K  |   L  |   ,  |   .  |   /  |SftEnt|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LAlt  | LGUI |LOWER | /Space+ /       \Space \  |RAISE | LCtl |  FN  |
 *                   |      |      |      |/ Alt   /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_WORKMAN] = LAYOUT( \
  KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,   KC_D,    KC_R,    KC_W,    KC_B,                      KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSPC, \
  KC_LCTL, KC_A,   KC_S,    KC_H,    KC_T,    KC_G,                      KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT, \
  KC_LSFT, KC_Z,   KC_X,    KC_M,    KC_C,    KC_V,    KC_LBRC, KC_RBRC, KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
                            KC_LALT, KC_LGUI, LOWER,LALT_T(KC_SPC),KC_SPC,RAISE,KC_LCTL, MO(_FUNCTION) \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |      |      |      |      |      |                    |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   "  | # £  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   [  |   ]  |   {  |   }  | Home |-------.    ,-------|  End |   _  |   +  | PgDn | PgUp |Insert|
 * |------+------+------+------+------+------| Home  |    |  End  |------+------+------+------+------+------|
 * |CapsLk|   \  |      |      |      |      |-------|    |-------|   \  |   #  |SfLeft|SfDown|ShftUp|SRight|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | / Home  /       \  End \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  KC_GRV,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,\
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  KC_TAB,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_HOME,                   KC_END,  KC_UNDS, KC_PLUS, KC_PGDN, KC_PGUP, KC_INS, \
  KC_CAPS, KC_NUBS, _______, _______, _______, _______, KC_HOME, KC_END,  KC_NUBS, KC_NUHS, S(KC_LEFT),S(KC_DOWN),S(KC_UP),S(KC_RGHT), \
                             _______, _______, _______, KC_HOME, KC_END,  _______,  _______, _______\
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   ¬  |      |      |      |      |      |                    |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CtlTab| WS1  | WS2  | WS2  | WS4  | WS5  |-------.    ,-------|   ]  |   -  |   =  |      |      |Insert|
 * |------+------+------+------+------+------|  PgDn |    |  PgUp |------+------+------+------+------+------|
 * |      | WS6  | WS7  | WS8  | WS9  | WS10 |-------|    |-------|   |  |   ~  | Left | Down |  Up  | Right|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | /Space  /       \Space \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
 S(KC_GRV),_______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL, \
 S(KC_GRV),KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
 C(KC_TAB), KC_WS1,  KC_WS2,  KC_WS3,  KC_WS4,  KC_WS5,                    KC_RBRC, KC_MINS, KC_EQL,  _______, _______, KC_INS, \
  _______, KC_WS6,  KC_WS7,  KC_WS8,  KC_WS9,  KC_WS10, KC_PGDN, KC_PGUP,S(KC_NUBS),S(KC_NUHS),KC_LEFT,KC_DOWN, KC_UP, KC_RGHT, \
                             _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* FUNCTION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |PrtScr|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |  F11 |-------.    ,-------|  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------|  Prev |    | Next  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| Pause| Mute | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | /Space  /       \Pause \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FUNCTION] = LAYOUT( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PSCR, \
  _______, _______, _______, _______, _______, KC_F11,                    KC_F12,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_MUTE, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, \
                             _______, _______, _______, _______, KC_MPLY, _______, _______, _______ \
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |Plain |Breath| Grad |      |      |KVMSw |
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
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_M_P, RGB_M_B, RGB_M_G, XXXXXXX, XXXXXXX, KVMSWTCH, \
  QK_BOOT, XXXXXXX, QWERTY,  COLEMAK, WORKMAN, XXXXXXX,                   RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, \
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
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        case _WORKMAN:
            oled_write_P(PSTR("Wrkmn"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
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

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    print_status_narrow();
  } else {
    if (get_highest_layer(layer_state) == _ADJUST) {
        oled_write_ln(read_rgb_info(), false);
        oled_write_ln(read_rgb_mode(), false);
    } else {
        oled_write(read_logo(), false);
    }
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case KVMSWTCH:
      if (record->event.pressed) {
        // KVM Switch key pressed - send switch sequence
        // ScrlLock, ScrlLock, Up
        SEND_STRING(SS_TAP(X_SCRL) SS_TAP(X_SCRL) SS_TAP(X_UP));
      }
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
    case KC_WS1:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("1"));
      }
      break;
    case KC_WS2:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("2"));
      }
      break;
    case KC_WS3:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("3"));
      }
      break;
    case KC_WS4:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("4"));
      }
      break;
    case KC_WS5:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("5"));
      }
      break;
    case KC_WS6:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("6"));
      }
      break;
    case KC_WS7:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("7"));
      }
      break;
    case KC_WS8:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("8"));
      }
      break;
    case KC_WS9:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("9"));
      }
      break;
    case KC_WS10:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("0"));
      }
      break;
    default:
      return true;
  }

  return true;
}
