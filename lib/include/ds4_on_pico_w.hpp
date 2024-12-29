
#ifndef PICO_W_FOR_DS4_HPP
#define PICO_W_FOR_DS4_HPP
#include "struct_ds4_on_pico_w.hpp"

#include <string>

class DS4forPicoW {
public:
    struct config {
        bool blink_led          = true;
        std::string mac_address = "";
    };

public:
    DS4forPicoW();
    ~DS4forPicoW();
    void setup(config config = (DS4forPicoW::config){ .blink_led = true, .mac_address = "" });
    bool is_connected(int timeout_ms = 3000);
    DualShock4_state get_state();

private:
    const int TIMEOUT_SPAN_MS = 100;
};

#endif
