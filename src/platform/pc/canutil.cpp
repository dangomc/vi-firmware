#include "can/canutil.h"
//#include "canutil_lpc17xx.h"
#include "signals.h"
#include "util/log.h"
//#include "lpc17xx_pinsel.h"

// Same for both Blueboard and Ford VI prototype
// CAN1: select P0.21 as RD1. P0.22 as TD1
// CAN2: select P0.4 as RD2, P0.5 as RD2
#define CAN_RX_PIN_NUM(BUS) (BUS == LPC_CAN1 ? 21 : 4)
#define CAN_TX_PIN_NUM(BUS) (BUS == LPC_CAN1 ? 22 : 5)
#define CAN_PORT_NUM(BUS) 0
#define CAN_FUNCNUM(BUS) (BUS == LPC_CAN1 ? 3 : 2)

/*
using openxc::signals::getCanBusCount;
using openxc::signals::getCanBuses;
using openxc::util::log::debug;

extern uint16_t CANAF_std_cnt;
*/


static void configureCanControllerPins() {

}

static void configureTransceiver() {

}

static void clearAcceptanceFilterTable() {

}

bool openxc::can::updateAcceptanceFilterTable(CanBus* buses, const int busCount) {
return false;
}

void openxc::can::deinitialize(CanBus* bus) { }

void openxc::can::initialize(CanBus* bus, bool writable, CanBus* buses,
        const int busCount) {

}
