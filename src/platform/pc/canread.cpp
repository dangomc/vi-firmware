#include "can/canread.h"
//#include "canutil_lpc17xx.h"
#include "signals.h"
#include "util/log.h"

using openxc::util::log::debug;
using openxc::signals::getCanBusCount;
using openxc::signals::getCanBuses;

CanMessage receiveCanMessage(CanBus* bus) {

    CanMessage result = {
    };


    return result;
}

extern "C" {

void CAN_IRQHandler() {
}

}
