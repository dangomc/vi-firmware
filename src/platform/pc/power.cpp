#include "power.h"
#include "util/log.h"
#include "gpio.h"
/*#include "lpc17xx_pinsel.h"
#include "lpc17xx_clkpwr.h"
#include "lpc17xx_wdt.h"*/

#define POWER_CONTROL_PORT 2
#define POWER_CONTROL_PIN 13

#define PROGRAM_BUTTON_PORT 2
#define PROGRAM_BUTTON_PIN 12

namespace gpio = openxc::gpio;

using openxc::gpio::GPIO_VALUE_HIGH;
using openxc::gpio::GPIO_VALUE_LOW;
using openxc::gpio::GPIO_DIRECTION_OUTPUT;
using openxc::util::log::debug;

const uint32_t DISABLED_PERIPHERALS[] = {

};

void setPowerPassthroughStatus(bool enabled) {

}

void openxc::power::initialize() {

}

void openxc::power::handleWake() {

}

void openxc::power::suspend() {

}

void openxc::power::enableWatchdogTimer(int microseconds) {

}

void openxc::power::disableWatchdogTimer() {

}

void openxc::power::feedWatchdog() {

}

extern "C" {

void CANActivity_IRQHandler(void) {

}

void EINT2_IRQHandler(void) {

}

}
