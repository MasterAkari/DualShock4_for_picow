/**
 * @file struct_ds4.hpp
 * @brief
 * @version 0.1
 * @date 2024-12-25
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef STRUCT_DS4_FOR_PICO_W_HPP
#define STRUCT_DS4_FOR_PICO_W_HPP
#include <stdint.h>

struct dual_shock_4_picow {
    // Directional buttons
    uint16_t directional = 0;
    // Share button
    bool share = false;
    // Options button
    bool options = false;
    // PS button
    bool ps = false;

    // Action Buttons
    bool triangle = false;
    bool square   = false;
    bool circle   = false;
    bool cross    = false;

    // Touch pad/Touch pad button
    //  To use the touch pad button, simply press the touch pad.
    uint8_t tpx = 0;
    uint8_t tpy = 0;
    bool touch  = false;

    // Top left button
    bool l1 = false;
    uint8_t l2;
    // Top Right button
    bool r1 = false;
    uint8_t r2;

    // Left stick/L3 button
    //    Press on the stick to use it as the R3 button.
    uint8_t rsx;
    uint8_t rsy;
    bool r3 = false;

    // Right stick / R3 button
    //    Press on the stick to use it as the L3 button.
    uint8_t lsx;
    uint8_t lsy;
    bool l3 = false;
};

struct bt_hid_state {
    uint16_t buttons;
    uint8_t lx;
    uint8_t ly;
    uint8_t rx;
    uint8_t ry;
    uint8_t l2;
    uint8_t r2;
    uint8_t hat;
    uint8_t pad;
    uint8_t pad2;
    uint8_t pad3;
    uint16_t temperature;
    uint16_t gyro[3];
    uint16_t accel[3];
    uint8_t status[2];
};

#endif // STRUCT_DS4_HPP
