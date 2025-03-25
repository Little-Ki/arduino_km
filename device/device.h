#ifndef KM_DEVICE
#define KM_DEVICE

#include "HID.h"
#include <string>

#define DEFAULT_VID 0xFF00
#define DEFAULT_PID 0x00FF

#ifndef _USING_HID
#warning "Using legacy HID core (non pluggable)"
#endif

using anyid_t = unsigned short;
using report_handler = int *();

struct MouseState {
};

struct KeyboardState {
    uint8_t modifiers;
    uint8_t reserved;
    uint8_t keys[6];
    uint8_t layout[128]
}

class KMDevice {

private:
    anyid_t _vid = DEFAULT_VID;
    anyid_t _pid = DEFAULT_VID;
    std::string _devname;

    template <typename D>
    void send_report(int id, const D &data) {
        HID().SendReport(id, reinterpret_cast<const uint8_t *>(&data), sizeof(D));
    }

public:
    KMDevice() = default;

    KMDevice(const KMDevice &other) = delete;

    KMDevice &set_pid(anyid_t vid);

    KMDevice &set_vid(anyid_t pid);

    KMDevice &set_devname(const std::string &name);

    KMDevice &initialize();

    KMDevice &set_keyboard_layout();

    bool is_good();

    void key_down(uint8_t key);

    void key_up(uint8_t key);

    void mouse_down();

    void mouse_up();

    void mouse_move(int x, int y, int z);

    void set_report_handler();
};

#endif