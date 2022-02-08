#include "switch_led_logic.h"

#include "board_io.h"
#include "gpio.h"

static gpio_s my_led;
static gpio_s my_switch;

void switch_led_logic__initialize(void) {
  my_led = board_io__get_led0();
  my_switch = board_io__get_sw0();
}

void switch_led_logic__run_once(void) {
  if (gpio__get(my_switch)) {
    gpio__set(my_led);
  } else {
    gpio__reset(my_led);
  }
}
