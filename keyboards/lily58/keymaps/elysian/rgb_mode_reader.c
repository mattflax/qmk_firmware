#ifdef RGBLIGHT_ENABLE

#include QMK_KEYBOARD_H
//#include rgblight_modes.h
#include "rgb_mode_reader.h"
#include <stdio.h>

extern rgblight_config_t rgblight_config;
extern rgblight_status_t rgblight_status;

char rbf_mode_str[24];
const char *read_rgb_mode(void) {
  if (rgblight_config.enable) {
    uint8_t offset = rgblight_config.mode - rgblight_status.base_mode;
    char offset_label[4];
    snprintf(offset_label, sizeof(offset_label), offset ? "+%d" : "", offset);
    snprintf(rbf_mode_str, sizeof(rbf_mode_str), "%s%s",
        get_mode(),
        offset_label);
    return rbf_mode_str;
  }
  return "";
}

char *get_mode(void) {
    if (rgblight_status.base_mode == RGBLIGHT_MODE_STATIC_LIGHT) {
        return RGBMODE_STATIC;
    }
#ifdef RGBLIGHT_EFFECT_BREATHING
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_BREATHING) {
        return RGBMODE_BREATHING;
    }
#endif
#ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_RAINBOW_MOOD) {
        return RGBMODE_RAINBOW_MOOD;
    }
#endif
#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_RAINBOW_SWIRL) {
        return RGBMODE_RAINBOW_SWIRL;
    }
#endif
#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_STATIC_GRADIENT) {
        return RGBMODE_STATIC_GRADIENT;
    }
#endif
#ifdef RGBLIGHT_EFFECT_TWINKLE
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_TWINKLE) {
        return RGBMODE_TWINKLE;
    }
#endif
#ifdef RGBLIGHT_EFFECT_SNAKE
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_SNAKE) {
        return RGBMODE_SNAKE;
    }
#endif
#ifdef RGBLIGHT_EFFECT_KNIGHT
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_KNIGHT) {
        return RGBMODE_KNIGHT;
    }
 #endif
#ifdef RGBLIGHT_EFFECT_CHRISTMAS
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_CHRISTMAS) {
        return RGBMODE_CHRISTMAS;
    }
#endif
#ifdef RGBLIGHT_EFFECT_RGB_TEST
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_RGB_TEST) {
        return RGBMODE_RGB_TEST;
    }
#endif
#ifdef RGBLIGHT_EFFECT_ALTERNATING
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_ALTERNATING) {
        return RGBMODE_ALTERNATING;
    }
#endif
    else {
        return RGBMODE_NONE;
    }
}
#endif
