/*#include "LPC17xx.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_pwm.h"*/
#include "util/timer.h"
#include "lights.h"
#include "util/log.h"

#define LED_PWM_PERIPHERAL LPC_PWM1

#define PWM_FUNCNUM 2
#define RIGHT_LED_PORT 1
#define RIGHT_LED_R_PIN 26
#define RIGHT_LED_G_PIN 23
#define RIGHT_LED_B_PIN 24
#define RIGHT_LED_R_CHANNEL 6
#define RIGHT_LED_G_CHANNEL 4
#define RIGHT_LED_B_CHANNEL 5

#define LEFT_LED_PORT 1
#define LEFT_LED_R_PIN 21
#define LEFT_LED_G_PIN 20
#define LEFT_LED_B_PIN 18
#define LEFT_LED_R_CHANNEL 3
#define LEFT_LED_G_CHANNEL 1
#define LEFT_LED_B_CHANNEL 2

#define PWM_PERIOD_MICROSECONDS 1000
#define DIMMER_DELAY 1

void setPwm(int channel, int value) {

}

void openxc::lights::enable(Light light, RGB color) {

}

void configureChannel(int channel) {

}

void configureLightPins() {

}

void initializePwm() {

}

void setPwmPeriod(int period) {

}

void openxc::lights::initialize() {

}
