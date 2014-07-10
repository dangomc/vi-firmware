/*#include "LPC17xx.h"
#include "lpc_types.h"
#include "lpc17xx_timer.h"*/
#include "util/timer.h"

#define DELAY_TIMER LPC_TIM0

unsigned int SYSTEM_TICK_COUNT;

extern "C" {

void SysTick_Handler() {
    ++SYSTEM_TICK_COUNT;
}

}

void openxc::util::time::delayMs(unsigned long delayInMs) {

}

unsigned long openxc::util::time::systemTimeMs() {
    return SYSTEM_TICK_COUNT;
}

void openxc::util::time::initialize() {

}
