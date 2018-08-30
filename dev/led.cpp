//
// Created by liuzikai on 2018/8/30.
//

#include "led.hpp"

void BlinkLEDThread::main(void) {
    setName("blink_leds");
    // Initialize GPIO to the LEDs.
    palSetPadMode(GPIOF, 9, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOF, 10, PAL_MODE_OUTPUT_PUSHPULL);
    while(!shouldTerminate()) {
        LED_RED_ON;
        LED_GREEN_OFF;
        sleep(TIME_MS2I(500));
        LED_RED_OFF;
        LED_GREEN_ON;
        sleep(TIME_MS2I(500));
    }
}