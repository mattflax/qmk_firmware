
# To build for RP2040, use
#   qmk compile -e CONVERT_TO=rp2040_ce

# MCU name
#MCU = atmega32u4

# Bootloader selection
#BOOTLOADER = caterina

TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes

# if firmware size over limit, try this option
LTO_ENABLE = yes

SRC += ./features/achordion.c
