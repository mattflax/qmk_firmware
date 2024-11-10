
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 220

// (Required) Sets the I2C Address for the Pimoroni Trackball.
#define PIMORONI_TRACKBALL_ADDRESS 0x0A
// (Optional) The timeout for i2c communication with the trackball in milliseconds.
#define PIMORONI_TRACKBALL_TIMEOUT 100
// (Optional) The multiplier used to generate reports from the sensor.
#define PIMORONI_TRACKBALL_SCALE 5
// (Optional) The number of scan cycles used for debouncing on the ball press.
#define PIMORONI_TRACKBALL_DEBOUNCE_CYCLES 20
// (Optional) Specifies the number of read/write errors until the sensor is disabled.
#define PIMORONI_TRACKBALL_ERROR_COUNT 10
