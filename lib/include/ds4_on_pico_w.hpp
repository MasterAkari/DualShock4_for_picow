
#ifndef PICO_W_FOR_DS4_HPP
#define PICO_W_FOR_DS4_HPP
#include "struct_ds4_on_pico_w.hpp"

class DS4forPicoW {
public:
    struct config {
        bool blink_led       = true;
        char mac_address[18] = "";
    };

public:
    DS4forPicoW();
    ~DS4forPicoW();
    void setup(config config);
    bool is_connected(int timeout_ms = 3000);
    DualShock4_state get_state();

private:
    const int TIMEOUT_SPAN_MS = 100;
};

#endif
