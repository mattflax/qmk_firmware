#ifdef RGBLIGHT_ENABLE

#define RGBMODE_STATIC "Static"
#define RGBMODE_NONE "None"
#ifdef RGBLIGHT_EFFECT_BREATHING
#define RGBMODE_BREATHING "Breathing"
#endif
#ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBMODE_RAINBOW_MOOD "RainbowMood"
#endif
#ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBMODE_RAINBOW_SWIRL "RainbowSwirl"
#endif
#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBMODE_STATIC_GRADIENT "StaticGrad"
#endif
#ifdef RGBLIGHT_EFFECT_TWINKLE
#define RGBMODE_TWINKLE "Twinkle"
#endif
#ifdef RGBLIGHT_EFFECT_SNAKE
#define RGBMODE_SNAKE "Snake"
#endif
#ifdef RGBLIGHT_EFFECT_KNIGHT
#define RGBMODE_KNIGHT "KnightRider"
#endif
#ifdef RGBLIGHT_EFFECT_CHRISTMAS
#define RGBMODE_CHRISTMAS "Christmas"
#endif
#ifdef RGBLIGHT_EFFECT_RGB_TEST
#define RGBMODE_RGB_TEST "RGBTest"
#endif
#ifdef RGBLIGHT_EFFECT_ALTERNATING
#define RGBMODE_ALTERNATING "Alternating"
#endif


/* Get the mode label */
char *get_mode(void);

#endif
