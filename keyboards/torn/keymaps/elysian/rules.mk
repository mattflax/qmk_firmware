# Enable pointing devices
POINTING_DEVICE_ENABLE = yes

# Enable the Pimoroni trackball
POINTING_DEVICE_DRIVER = pimoroni_trackball
# (Required) Sets the I2C Address for the Pimoroni Trackball.
PIMORONI_TRACKBALL_ADDRESS = 0x0A
# (Optional) The timeout for i2c communication with the trackball in milliseconds.
PIMORONI_TRACKBALL_TIMEOUT = 100
# (Optional) The multiplier used to generate reports from the sensor.
PIMORONI_TRACKBALL_SCALE = 5
# (Optional) The number of scan cycles used for debouncing on the ball press.
PIMORONI_TRACKBALL_DEBOUNCE_CYCLES = 20
# (Optional) Specifies the number of read/write errors until the sensor is disabled.
PIMORONI_TRACKBALL_ERROR_COUNT = 10

# Enable mouse keys
MOUSEKEY_ENABLE = no
# Enable media keys
EXTRAKEY_ENABLE = yes
