/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.hpp"
#include "hal.h"

#include "button_monitor.hpp"
#include "led.hpp"
#include "serial_shell.hpp"

using namespace chibios_rt;

int main(void) {
    halInit();
    System::init();

    palSetPadMode(GPIOA, 6, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA, 7, PAL_MODE_OUTPUT_PUSHPULL);

    buttonK0.start(NORMALPRIO);
    buttonK1.start(NORMALPRIO);

    shellStart();

    while (true) {
        if(buttonK0.toggle) {
            LED_D2_ON;
            LED_D3_OFF;
            BaseThread::sleep(TIME_MS2I((1 + buttonK1.counter % 3) * 100));
            LED_D2_OFF;
            LED_D3_ON;
            BaseThread::sleep(TIME_MS2I((1 + buttonK1.counter % 3) * 100));
        } else {
            LED_D2_ON;
            LED_D3_ON;
            BaseThread::sleep(TIME_MS2I((1 + buttonK1.counter % 3) * 100));
            LED_D2_OFF;
            LED_D3_OFF;
            BaseThread::sleep(TIME_MS2I((1 + buttonK1.counter % 3) * 100));
        }
    }
    return 0;
}