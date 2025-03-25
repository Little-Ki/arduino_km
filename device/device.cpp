#include "device.h"

KMDevice& KMDevice::set_pid(anyid_t pid) {
    _pid = pid;
    return *this;
}

KMDevice& KMDevice::set_vid(anyid_t vid) {
    _vid = vid;
    return *this;
}

KMDevice& KMDevice::set_devname(const std::string &name) {
    _devname = name;
    return *this;
}

bool KMDevice::is_good() {
    return false;
}

KMDevice& initialize() {
    return *this
}