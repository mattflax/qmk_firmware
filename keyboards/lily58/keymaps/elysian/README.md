# mattonthehill's keymap layout

The keyboard layout here is based on the default layout, with some changes
to bring it closer to the Let's Split layout. Function keys have their own
layer, rather than existing on both Lower and Raise in different layouts;
the Function layer also has the media keys.

The local `layer_state_reader.c` has modifications to display the Function
layer, in addition to Lower, Raise and Adjust.


## OLED display tweaks

The OLED display on master has been tweaked to display the RGB settings, in
addition to the layer and a reduced keylogger display. It uses the default 
`rgb_mode_reader.c` code to display the mode, saturation, hue and value 
settings. On the fourth line, it uses the code from  `rgb_mode_reader.c` to 
display the mode name verbally, rather than using its mode number. Mode names
are defined in `rgb_mode_reader.h`.
