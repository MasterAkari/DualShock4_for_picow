/**
 * @file struct_ds4_on_pico_w.hpp
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

typedef enum
{
    N      = 0,
    NE     = 1,
    E      = 2,
    SE     = 3,
    S      = 4,
    SW     = 5,
    W      = 6,
    NW     = 7,
    NO_HAT = 8
} hat_t;

struct DualShock4_state {
    uint8_t report_id;
    // Directional buttons
    hat_t hat;
    // Share button
    bool share;
    // Options button
    bool options;
    // PS button
    bool ps;

    // Action Buttons
    bool triangle;
    bool square;
    bool circle;
    bool cross;
    bool fn1;
    bool fn2;
    bool mute;

    // Touch pad/Touch pad button
    //  To use the touch pad button, simply press the touch pad.
    bool touch;
    uint8_t touch_packet_size;
    uint8_t touch_counter;

    bool touch_f1_a_active;
    uint8_t touch_f1_a_counter;
    uint16_t touch_f1_a_x;
    uint16_t touch_f1_a_y;

    bool touch_f2_a_active;
    uint8_t touch_f2_a_counter;
    uint16_t touch_f2_a_x;
    uint16_t touch_f2_a_y;

    bool touch_f1_b_active;
    uint8_t touch_f1_b_counter;
    uint16_t touch_f1_b_x;
    uint16_t touch_f1_b_y;

    bool touch_f2_b_active;
    uint8_t touch_f2_b_counter;
    uint16_t touch_f2_b_x;
    uint16_t touch_f2_b_y;

    // Top left button
    bool l1;
    bool l2;
    uint8_t l2_value;
    // Top Right button
    bool r1;
    bool r2;
    uint8_t r2_value;

    // Left stick/L3 button
    //    Press on the stick to use it as the R3 button.
    bool l3;
    uint8_t l3_x;
    uint8_t l3_y;

    // Right stick / R3 button
    //    Press on the stick to use it as the L3 button.
    bool r3;
    uint8_t r3_x;
    uint8_t r3_y;

    // Gyro sensor
    int16_t gyro_x;
    int16_t gyro_y;
    int16_t gyro_z;

    // Acceleration sensor
    int16_t accel_x;
    int16_t accel_y;
    int16_t accel_z;

    // Battery level
    uint8_t battery;
    uint8_t battery_level;
    bool connected_usb;
    bool connected_mic;
    bool connected_phone;

    // Timestamp
    uint32_t timestamp;

    // Status
    bool linked;
};

#endif // STRUCT_DS4_FOR_PICO_W_HPP
