#include <string.h>
/*#include "lpc17xx_pinsel.h"
#include "lpc17xx_uart.h"*/
#include "interface/uart.h"
#include "pipeline.h"
#include "config.h"
#include "util/bytebuffer.h"
#include "util/log.h"
#include "gpio.h"

// Only UART1 supports hardware flow control, so this has to be UART1
#define UART1_DEVICE (LPC_UART_TypeDef*)LPC_UART1

#define UART_STATUS_PORT 0
#define UART_STATUS_PIN 18

#ifdef BLUEBOARD

#define UART1_FUNCNUM 2
#define UART1_PORTNUM 2
#define UART1_TX_PINNUM 0
#define UART1_RX_PINNUM 1
#define UART1_FLOW_PORTNUM UART1_PORTNUM
#define UART1_FLOW_FUNCNUM UART1_FUNCNUM
#define UART1_CTS1_PINNUM 2
#define UART1_RTS1_PINNUM 7

#else

// Ford OpenXC VI Prototype
#define UART1_FUNCNUM 1
#define UART1_PORTNUM 0
#define UART1_TX_PINNUM 15
#define UART1_RX_PINNUM 16
#define UART1_FLOW_PORTNUM 2
#define UART1_FLOW_FUNCNUM 2
#define UART1_RTS1_PINNUM 2
#define UART1_CTS1_PINNUM 7

#endif

namespace gpio = openxc::gpio;

using openxc::config::getConfiguration;
using openxc::util::log::debug;
using openxc::pipeline::Pipeline;
using openxc::util::bytebuffer::processQueue;
using openxc::gpio::GpioValue;
using openxc::gpio::GpioDirection;

/*__IO int32_t RTS_STATE;
__IO FlagStatus TRANSMIT_INTERRUPT_STATUS;*/

/* Disable request to send through RTS line. We cannot handle any more data
 * right now.
 */
void pauseReceive() {

}

/* Enable request to send through RTS line. We can handle more data now. */
void resumeReceive() {

}

void disableTransmitInterrupt() {

}

void enableTransmitInterrupt() {

}

void handleReceiveInterrupt() {

}

void handleTransmitInterrupt() {

}

extern "C" {

void UART1_IRQHandler() {

}

}

void openxc::interface::uart::read(UartDevice* device,
        openxc::util::bytebuffer::IncomingMessageCallback callback) {

}

/* Auto flow control does work, but it turns the uart write functions into
 * blocking functions, which drags USB down. Instead we handle it manually so we
 * can make them asynchronous and let USB run at full speed.
 */
void configureFlowControl() {

}

void configureUartPins() {

}

void configureFifo() {

}

void configureInterrupts() {

}

void openxc::interface::uart::changeBaudRate(UartDevice* device, int baud) {

}

void openxc::interface::uart::writeByte(UartDevice* device, uint8_t byte) {

}

int openxc::interface::uart::readByte(UartDevice* device) {

    return -1;
}

void openxc::interface::uart::initialize(UartDevice* device) {

}

void openxc::interface::uart::processSendQueue(UartDevice* device) {

}

bool openxc::interface::uart::connected(UartDevice* device) {
    return false;
}

