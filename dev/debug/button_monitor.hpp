#ifndef _BUTTON_MONITOR_HPP_
#define _BUTTON_MONITOR_HPP_

#include "ch.hpp"
#include "hal.h"
#include "port_to_string.hpp"

class ButtonMonitorThread : public chibios_rt::BaseStaticThread<64> {
private:
    ioportid_t _ioportid;
    ioportmask_t _ioportmask;
protected:
    void main(void) override;
public:
    bool pressed = false;
    bool toggle = false;
    uint32_t counter = 0;
    ButtonMonitorThread(ioportid_t ioportid, ioportmask_t ioportmask);
};

static ButtonMonitorThread buttonK0(GPIOD, 10);

#endif