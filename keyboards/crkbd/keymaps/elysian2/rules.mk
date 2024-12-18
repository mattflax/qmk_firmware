OLED_ENABLE = yes
#OLED_DRIVER = SSD1306

#BACKLIGHT_ENABLE = yes        # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no         # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes

BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work

TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes

# if firmware size over limit, try this option
LTO_ENABLE = yes

SRC += ./keymaps/elysian2/features/achordion.c
