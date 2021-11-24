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
  LOWER,
  RAISE,
  KC_WS1, KC_WS2, KC_WS3, KC_WS4, KC_WS5, KC_WS6, KC_WS7, KC_WS8, KC_WS9, KC_WS10
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Ctl/Tb|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |SftEnt|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LAlt  | LGUI |LOWER | /Space+ /       \Space+\  |RAISE | LAlt |  FN  |
 *                   |      |      |      |/ Raise /         \ Func \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_ESC,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  LCTL_T(KC_TAB),KC_A,KC_S, KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
                            KC_LALT, KC_LGUI, LOWER,LT(_RAISE, KC_SPC),LT(_FUNCTION,KC_SPC),RAISE,KC_LALT, TT(_FUNCTION) \
),

/*
 * WORKMAN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |                    |   J  |   F  |   U  |   P  |   ;  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCtrl |   A  |   S  |   H  |   T  |   G  |-------.    ,-------|   Y  |   N  |   E  |   O  |   I  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | HOME  |------+------+------+------+------+------|
 * |Sft/CL|   Z  |   X  |   M  |   C  |   V  |-------|    |-------|   K  |   L  |   ,  |   .  |   /  |SftEnt|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LAlt  | LGUI |LOWER | /Space+ /       \Space+\  |RAISE | LAlt |  FN  |
 *                   |      |      |      |/ Super /         \ Func \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_WORKMAN] = LAYOUT( \
  KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,   KC_D,    KC_R,    KC_W,    KC_B,                      KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_MINS, \
  KC_LCTL, KC_A,   KC_S,    KC_H,    KC_T,    KC_G,                      KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT, \
  KC_LSFT, KC_Z,   KC_X,    KC_M,    KC_C,    KC_V,    KC_LBRC, KC_RBRC, KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
                            KC_LALT, KC_LGUI, LOWER,LGUI_T(KC_SPC),LT(_FUNCTION,KC_SPC),RAISE,KC_LALT, TT(_FUNCTION) \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |      |      |      |      |      |                    |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   "  | # £  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   [  |   ]  |   {  |   }  |   {  |-------.    ,-------|   }  |   _  |   +  |      |      |Insert|
 * |------+------+------+------+------+------| Home  |    |  End  |------+------+------+------+------+------|
 * |CapsLk|   \  |      |      |      |      |-------|    |-------|   \  |   #  |SfLeft|SfDown|ShftUp|SRight|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | / Home  /       \  End \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  KC_GRV,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,\
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_LCBR,                   KC_RCBR, KC_UNDS, KC_PLUS, _______, _______, KC_INS, \
  KC_CAPS, KC_NUBS, _______, _______, _______, _______, KC_HOME, KC_END,  KC_NUBS, KC_NUHS, S(KC_LEFT),S(KC_DOWN),S(KC_UP),S(KC_RGHT), \
                             _______, _______, _______, KC_HOME, KC_END,  _______,  _______, _______\
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   ¬  |      |      |      |      |      |                    |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | WS1  | WS2  | WS2  | WS4  | WS5  |-------.    ,-------|   ]  |   -  |   =  |      |      |Insert|
 * |------+------+------+------+------+------|  PgDn |    |  PgUp |------+------+------+------+------+------|
 * |      | WS6  | WS7  | WS8  | WS9  | WS10 |-------|    |-------|   |  |   ~  | Left | Down |  Up  | Right|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | /Space  /       \Space \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT( \
 S(KC_GRV),_______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL, \
 S(KC_GRV),KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_WS1,  KC_WS2,  KC_WS3,  KC_WS4,  KC_WS5,                    KC_RBRC, KC_MINS, KC_EQL,  _______, _______, KC_INS, \
  _______, KC_WS6,  KC_WS7,  KC_WS8,  KC_WS9,  KC_WS10, KC_PGDN, KC_PGUP,S(KC_NUBS),S(KC_NUHS),KC_LEFT,KC_DOWN, KC_UP, KC_RGHT, \
                             _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* FUNCTION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |  F11 |                    |  F12 |      |      |      |      |PrtScr|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Home | PgDn | PgUp | End  |      |      |
 * |------+------+------+------+------+------|  Prev |    | Next  |------+------+------+------+------+------|
 * |ScrLck|      |      |      |      |      |-------|    |-------| Pause| Mute | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | /Space  /       \Pause \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_FUNCTION] = LAYOUT( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, \
  _______, _______, _______, _______, _______, KC_F11,                    KC_F12,  _______, _______, _______, _______, KC_PSCR, \
  _______, _______, _______, _______, _______, _______,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, \
  KC_SLCK, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_MUTE, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, \
                             _______, _______, _______, _______, KC_MPLY, _______, _______, _______ \
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |Plain |Breath| Grad |      |      |KVMSw |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RESET |      |Qwerty|      |Workmn|      |                    |RGB On| Mode+| Hue+ | Sat+ | Val+ |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Mode-| Hue- | Sat- | Val- |      |
 * |------+------+------+------+------+------|  Prev |    | Next  |------+------+------+------+------+------|
 * |ScrLck|      |      |      |      |      |-------|    |-------|      |      |      | Vol- | Vol+ | Mute |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | /Space  /       \Pause \  |RAISE |      |ADJUST|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RGB_M_P, RGB_M_B, RGB_M_G, XXXXXXX, XXXXXXX, KVMSWTCH, \
  RESET,   XXXXXXX, QWERTY,  XXXXXXX, WORKMAN, XXXXXXX,                   RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, \
  KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, \
                             _______, _______, _______, _______, KC_MPLY, _______, _______, _______ \
 )
};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
const char *read_rgb_info(void);
const char *read_rgb_mode(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
      case _WORKMAN:
      case _QWERTY:
        oled_write_ln_P(PSTR("Base"), false);
        break;
      case _RAISE:
        oled_write_ln_P(PSTR("Raise"), false);  // No return at end of line
        break;
      case _LOWER:
        oled_write_ln_P(PSTR("Lower"), false);  // No return at end of line
        break;
      case _ADJUST:
        oled_write_ln_P(PSTR("Adj"), false);
        break;
      case _FUNCTION:
        oled_write_ln_P(PSTR("Func"), false);
        break;
      default:
        oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_ln(read_rgb_info(), false);
    oled_write_ln(read_rgb_mode(), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write("CPSLK", led_usb_state.caps_lock);
    oled_write("    ", false);
    switch (get_highest_layer(default_layer_state)) {
      case _WORKMAN:
        oled_write_ln("Workman", false);
        break;
      case _QWERTY:
        oled_write_ln("Qwerty", false);
        break;
      default:
        oled_write_ln("Undef", false);
    }
  } else {
    oled_write(read_logo(), false);
  }
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
        SEND_STRING(SS_TAP(X_SLCK) SS_TAP(X_SLCK) SS_TAP(X_UP));
      }
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
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
