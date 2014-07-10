#include "interface/usb.h"
#include <stdio.h>
#include "util/log.h"
#include "util/bytebuffer.h"
#include "gpio.h"
#include "usb_config.h"
#include "config.h"
#include "emqueue.h"
#include "commands.h"

/*#include "LPC17xx.h"
#include "lpc17xx_pinsel.h"*/

extern "C" {
//#include "bsp.h"
}

#define VBUS_PORT 1
#define VBUS_PIN 30
#define VBUS_FUNCNUM 2

#define USB_DM_PORT 0
#define USB_DM_PIN 30
#define USB_DM_FUNCNUM 1

#define USB_HOST_DETECT_INACTIVE_VALUE 400
#define USB_HOST_DETECT_ACTIVE_VALUE 50

#define USB_CONNECT_PORT 2
#define USB_CONNECT_PIN 9

namespace gpio = openxc::gpio;
namespace commands = openxc::commands;

using openxc::config::getConfiguration;
using openxc::util::log::debug;
using openxc::interface::usb::UsbDevice;
using openxc::interface::usb::UsbEndpoint;
using openxc::interface::usb::UsbEndpointDirection;
using openxc::util::bytebuffer::processQueue;
using openxc::gpio::GPIO_VALUE_HIGH;
using openxc::gpio::GPIO_VALUE_LOW;

void configureEndpoints() {

}

extern "C" {

void EVENT_USB_Device_Disconnect() {
    
}

void EVENT_USB_Device_ControlRequest() {

}

void EVENT_USB_Device_ConfigurationChanged(void) {

}

}

/* Private: Flush any queued data out to the USB host. */
static void flushQueueToHost(UsbDevice* usbDevice, UsbEndpoint* endpoint) {

}

/* Private: Detect if USB VBUS is active.
 *
 * This isn't useful if there's no diode between an external 12v/9v power supply
 * (e.g. vehicle power from OBD-II) and the 5v rail, because then VBUS high when
 * the power is powered on regardless of the status of USB. In that situation,
 * you can fall back to the usbHostDetected() function instead.
 *
 * Returns true if VBUS is high.
 */
bool vbusDetected() {
    return false;
}

/* Private: Detect if a USB host is actually attached, regardless of VBUS.
 *
 * This is a bit hacky, as normally you should rely on VBUS to detect if USB is
 * connected. See vbusDetected() for reasons why we need this workaround on the
 * current prototype.
 *
 * Returns true of there is measurable activity on the D- USB line.
 */
bool usbHostDetected(UsbDevice* usbDevice) {

    return false;
}

/* Private: Configure I/O pins used to detect if USB is connected to a host. */
void configureUsbDetection() {

}

bool openxc::interface::usb::sendControlMessage(UsbDevice* usbDevice,
        uint8_t* data, size_t length) {

    return true;
}


void openxc::interface::usb::processSendQueue(UsbDevice* usbDevice) {

}

void openxc::interface::usb::initialize(UsbDevice* usbDevice) {
}

void openxc::interface::usb::read(UsbDevice* device, UsbEndpoint* endpoint,
        openxc::util::bytebuffer::IncomingMessageCallback callback) {

}

void openxc::interface::usb::deinitialize(UsbDevice* usbDevice) {

}
