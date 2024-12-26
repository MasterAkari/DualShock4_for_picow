
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
    printf("======================\n[SETUP] DS4 on PicoW\n======================\n");

    controller.setup();
    while (1) {
        bool flag_can_use = false;
        do {
            printf("Starting inquiry scan..\n");
            loop_contents = controller.scan(3000);
            if (true == loop_contents) {
                printf("DS4 found\n");
            }
        } while (false == loop_contents);

        do {
            DualShock4_state state = controller.get_state();
            if (true == state.linked) {
                flag_can_use = true;
                break;
            }
        } while (false == flag_can_use);

        ////////////////////////////////////////////
        // LOOP
        ////////////////////////////////////////////
        DualShock4_state state;
        while (loop_contents) {
            tight_loop_contents();
            state = controller.get_state();
            printf("HAT[%01d] ", state.hat);
#if 0
            printf("SHA[%s] ", state.share ? "x" : " ");
            printf("OPT[%s] ", state.options ? "x" : " ");
            printf("PS[%s] ", state.ps ? "x" : " ");
            printf("A[%s] ", state.cross ? "x" : " ");
            printf("B[%s] ", state.circle ? "x" : " ");
            printf("X[%s] ", state.square ? "x" : " ");
            printf("Y[%s] ", state.triangle ? "x" : " ");
#else
            printf("BT[%s%s%s%s%s%s%s%s] ", //
                   state.share ? "S" : " ",
                   state.options ? "O" : " ",
                   state.ps ? "P" : " ",
                   state.cross ? "A" : " ",
                   state.circle ? "B" : " ",
                   state.square ? "X" : " ",
                   state.triangle ? "Y" : " ",
                   state.touch ? "T" : " ");
#endif
#if 0
            printf("Left[%s/%s(%03d)/%s(%03d,%03d)] ", state.l1 ? "x" : " ", state.l2 ? "x" : " ", state.l2_value, state.l3 ? "x" : " ", state.l3_x, state.l3_y);
            printf("Right[%s/%s(%03d)/%s(%03d,%03d)] ", state.r1 ? "x" : " ", state.r2 ? "x" : " ", state.r2_value, state.r3 ? "x" : " ", state.r3_x, state.r3_y);
#else
            printf("L[%s%s%s(%03d)(%03d,%03d)] ", state.l1 ? "1" : " ", state.l2 ? "2" : " ", state.l3 ? "3" : " ", state.l2_value, state.l3_x, state.l3_y);
            printf("R[%s%s%s(%03d)(%03d,%03d)] ", state.r1 ? "1" : " ", state.r2 ? "2" : " ", state.r3 ? "3" : " ", state.r2_value, state.r3_x, state.r3_y);
#endif
            printf("Touch[%02d/%3d] ", state.touch_packet_size, state.touch_counter);
            printf("T1[%s/%3d(%04d,%03d)] ", state.touch_f1_a_active ? "x" : " ", state.touch_f1_a_counter, state.touch_f1_a_x, state.touch_f1_a_y);
            printf("T2[%s/%3d(%04d,%03d)] ", state.touch_f2_a_active ? "x" : " ", state.touch_f2_a_counter, state.touch_f2_a_x, state.touch_f2_a_y);
#if 0
            printf("T1B[%s/%3d(%04d,%03d)] ", state.touch_f1_b_active ? "x" : " ", state.touch_f1_b_counter, state.touch_f1_b_x, state.touch_f1_b_y);
            printf("T2B[%s/%3d(%04d,%03d)] ", state.touch_f2_b_active ? "x" : " ", state.touch_f2_b_counter, state.touch_f2_b_x, state.touch_f2_b_y);
#endif
            printf("BtLv.%02d(%03d) ", state.battery_level, state.battery);
            printf("Gyro[%6d,%6d,%6d] ", state.gyro_x, state.gyro_y, state.gyro_z);
            printf("Accel[%6d,%6d,%6d] ", state.accel_x, state.accel_y, state.accel_z);
            printf("%s", state.linked ? " Linked " : "Unlinked");
            printf("in[%s/%s/%s] ", state.connected_usb ? "USB" : "   ", state.connected_mic ? "MIC" : "   ", state.connected_phone ? "Phone" : "     ");
            printf("ID.%02d ", state.report_id);
            printf("TS[%05d/%02d] ", state.timestamp, state.report_counter);

            printf("\n");

            if (false == state.linked) {
                loop_contents = false;
                break;
            }
            sleep_ms(20);
        }
    }

    ////////////////////////////////////////////
    // CLOSING
    ////////////////////////////////////////////
    printf("[CLOSING] DS4 on PicoW\n");
    stdio_deinit_all();
    return 0;
}
