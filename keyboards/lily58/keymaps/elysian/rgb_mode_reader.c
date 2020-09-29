#ifdef RGBLIGHT_ENABLE

#include QMK_KEYBOARD_H
//#include rgblight_modes.h
#include "rgb_mode_reader.h"
#include <stdio.h>

extern rgblight_config_t rgblight_config;
extern rgblight_status_t rgblight_status;

char rbf_mode_str[24];
const char *read_rgb_mode(void) {
  snprintf(rbf_mode_str, sizeof(rbf_mode_str), "Mode: %s", get_mode());
  return rbf_mode_str;
}

char *get_mode(void) {
    if (rgblight_status.base_mode == RGBLIGHT_MODE_STATIC_LIGHT) {
        return "Static";
    }
# ifdef RGBLIGHT_EFFECT_BREATHING
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_BREATHING) {
        return "Breathing";
    }
#endif
#ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_RAINBOW_MOOD) {
        return "Rainbow Mood";
    }
#endif
#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_RAINBOW_SWIRL) {
        return "Rainbow Swirl";
    }
#endif
#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_STATIC_GRADIENT) {
        return "Static Gradient";
    }
#endif
#ifdef RGBLIGHT_EFFECT_TWINKLE
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_TWINKLE) {
        return "Twinkle";
    }
#endif
#ifdef RGBLIGHT_EFFECT_SNAKE
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_SNAKE) {
        return "Snake";
    }
#endif
#ifdef RGBLIGHT_EFFECT_KNIGHT
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_KNIGHT) {
        return "Knight Rider";
    }
 #endif
#ifdef RGBLIGHT_EFFECT_CHRISTMAS
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_CHRISTMAS) {
        return "Christmas";
    }
#endif
#ifdef RGBLIGHT_EFFECT_RGB_TEST
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_RGB_TEST) {
        return "RGB Test";
    }
#endif
#ifdef RGBLIGHT_EFFECT_ALTERNATING
    else if (rgblight_status.base_mode == RGBLIGHT_MODE_ALTERNATING) {
        return "Alternating";
    }
#endif
    else {
        return "None";
    }
}
#endif
