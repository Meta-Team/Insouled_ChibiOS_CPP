//
// Created by liuzikai on 2018/8/30.
//

#ifndef INSOULED_CHIBIOS_CPP_LED_HPP
#define INSOULED_CHIBIOS_CPP_LED_HPP

#include "ch.hpp"
#include "hal.h"

#define LED_RED_OFF palSetPad(GPIOF, 9)
#define LED_RED_ON palClearPad(GPIOF, 9)
#define LED_RED_TOGGLE palTogglePad(GPIOF, 9)
#define LED_GREEN_OFF palSetPad(GPIOF, 10)
#define LED_GREEN_ON palClearPad(GPIOF, 10)
#define LED_GREEN_TOGGLE palTogglePad(GPIOF, 10)

/**
 * Blinks two LEDs, a demonstration of how to write a thread in C++.
 */
class BlinkLEDThread : public chibios_rt::BaseStaticThread<256> {
protected:
    void main(void) override;
};

static BlinkLEDThread blinkLEDThread;

#endif //INSOULED_CHIBIOS_CPP_LED_HPP
