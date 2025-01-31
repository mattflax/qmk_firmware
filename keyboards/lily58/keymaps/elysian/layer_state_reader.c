
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
#define L_LOWER (1 << 1)
#define L_RAISE (1 << 2)
#define L_FN (1 << 3)
#define L_ADJUST (1 << 4)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char layer_state_str[24];

const char* layer_label = "Layer";

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "%s: Default", layer_label);
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "%s: Raise", layer_label);
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "%s: Lower", layer_label);
    break;
  case L_FN:
    snprintf(layer_state_str, sizeof(layer_state_str), "%s: Function", layer_label);
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "%s: Adjust", layer_label);
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "%s: Undef-%ld", layer_label, layer_state);
  }

  return layer_state_str;
}
