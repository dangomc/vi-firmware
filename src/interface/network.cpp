#include "interface/network.h"
#include "util/log.h"
#include <stddef.h>

using openxc::util::log::debug;

void openxc::interface::network::initializeCommon(NetworkDevice* device) {
    if(device != NULL) {
        debug("Initializing Network...");
        QUEUE_INIT(uint8_t, &device->receiveQueue);
        QUEUE_INIT(uint8_t, &device->sendQueue);
        device->allowRawWrites = DEFAULT_ALLOW_RAW_WRITE_NETWORK;
    }
}
