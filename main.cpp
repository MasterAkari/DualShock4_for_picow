
#include "ds4_on_pico_w.hpp"
#include "pico/stdlib.h"

#include <algorithm>
#include <stdio.h>

int main()
{
    DS4forPicoW controller;
    bool loop_contents = true;
    ////////////////////////////////////////////
    // SETUP
    ////////////////////////////////////////////
    stdio_init_all();
    sleep_ms(5000);
    controller.setup();
    do {
        printf("Starting inquiry scan..\n");
        loop_contents = controller.scan(3000);
    } while (false == loop_contents);

    ////////////////////////////////////////////
    // LOOP
    ////////////////////////////////////////////
    bool flag_can_use = false;
    while (loop_contents) {
        // tight_loop_contents();
        if (controller.is_use()) {
            flag_can_use       = true;
            bt_hid_state state = controller.get_state();

            printf("buttons: %04x, l: %03d,%03d, r: %03d,%03d, l2,r2: %03d,%03d hat: %d\n", //
                   state.buttons,
                   state.lx,
                   state.ly,
                   state.rx,
                   state.ry,
                   state.l2,
                   state.r2,
                   state.hat);
        } else {
            if (true == flag_can_use) {
                loop_contents = false;
                break;
            }
        }
        sleep_ms(20);
    }

    ////////////////////////////////////////////
    // CLOSING
    ////////////////////////////////////////////
    printf("CLOSING DS4 for PicoW\n");
    stdio_deinit_all();
    return 0;
}
