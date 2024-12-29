# DualShock4 on Pico-W

## 概要

[usedbytes/picow_ds4](https://github.com/usedbytes/picow_ds4)を元に、VS-Codeの拡張機能「raspberry-pi.raspberry-pi-pico」を使用して、Pico-WとDualShock4を接続するためのサンプルプログラムを作成しました。



## 取り込み方

### CMakeLists.txt

自プログラムに取り込む場合は、プロジェクトを配置後に「CMakeLists.txt」に下記のことを記載してください。

```cmake
add_subdirectory(DualShock4_on_picow/lib)

# Add any user requested libraries
target_link_libraries(DualShock4_on_picow
        lib_ds4_on_pico
)
```

### Sample code

Sample code is as follows:

```cpp
#include "ds4_on_pico_w.h"

int your_function()
{
    stdio_init_all();

    bool loop_contents = true;
    DualShock4_state state;
    DS4forPicoW controller;
    ////////////////////////////////////////////
    // SETUP
    ////////////////////////////////////////////
    controller.setup((DS4forPicoW::config){ .blink_led = true, .mac_address = "" });
    do {
        loop_contents = controller.is_connected(3000);
    } while (false == loop_contents);

    ////////////////////////////////////////////
    // LOOP
    ////////////////////////////////////////////
    while (loop_contents) {
        tight_loop_contents();
        state = controller.get_state();
    }

    stdio_deinit_all();

    return 0;
}
```


## 構造体

取得する構造体"DualShock4_state"の説明


| グループ             | 定義     | 構造体             | 概要                                                           |
| -------------------- | -------- | ------------------ | -------------------------------------------------------------- |
| ID                   | uint8_t  | report_id          | HID レポートID                                                 |
| 十字キー             | hat_t    | hat                | 8は未入力、北=0として45度づつ、+1 されます                     |
| メニューボタン       | bool     | share              | PADの左側にあるメニューボタン                                  |
| ^                    | bool     | options            | PADの右側にあるメニューボタン                                  |
| ^                    | bool     | ps                 | PADの下側にあるメニューボタン                                  |
| ^                    | bool     | fn1                | Fn1 ボタン : △□○×ボタンは反応しなくなります                    |
| ^                    | bool     | fn2                | Fn2 ボタン : △□○×ボタンは反応しなくなります                    |
| ^                    | bool     | mute               | ミュートボタン                                                 |
| アクション ボタン    | bool     | triangle           | △ ボタン                                                       |
| ^                    | bool     | square             | □ ボタン                                                       |
| ^                    | bool     | circle             | ○ ボタン                                                       |
| ^                    | bool     | cross              | × ボタン                                                       |
| トリガーボタン(左)   | bool     | l1                 | 上面のL1 ボタン                                                |
| ^                    | bool     | l2                 | 上面のL2 ボタン                                                |
| ^                    | uint8_t  | l2_value           | 上面のL2 ボタン 押し込み量(0～255)                             |
| ^                    | bool     | l3                 | 左側のステック ボタン 押し込み時                               |
| ^                    | uint8_t  | l3_x               | 左側のステック X軸                                             |
| ^                    | uint8_t  | l3_y               | 左側のステック Y軸                                             |
| トリガーボタン  (右) | bool     | r1                 | 上面のR1 ボタン                                                |
| ^                    | bool     | r2                 | 上面のR2 ボタン                                                |
| ^                    | uint8_t  | r2_value           | 上面のR2 ボタン 押し込み量(0～255)                             |
| ^                    | bool     | r3                 | 右側のステック ボタン 押し込み時                               |
| ^                    | uint8_t  | r3_x               | 右側のステック X軸                                             |
| ^                    | uint8_t  | r3_y               | 右側のステック Y軸                                             |
| タッチパッド         | bool     | touch              | タッチパッドのボタン                                           |
| ^                    | uint8_t  | touch_packet_size  | データ受信数                                                   |
| ^                    | uint8_t  | touch_counter      | 数値変更カウンター                                             |
| タッチパッド(1)      | bool     | touch_f1_a_active  | １本目の接触フラグ                                             |
| ^                    | uint8_t  | touch_f1_a_counter | タッチ数(1本目,2本目共有)                                      |
| ^                    | uint16_t | touch_f1_a_x       | １本目の X軸                                                   |
| ^                    | uint16_t | touch_f1_a_y       | １本目の Y軸                                                   |
| タッチパッド(1)-予備 | bool     | touch_f1_b_active  | [遅延が発生したときに更新される模様] １本目の接触フラグ        |
| ^                    | uint8_t  | touch_f1_b_counter | [遅延が発生したときに更新される模様] タッチ数(1本目,2本目共有) |
| ^                    | uint16_t | touch_f1_b_x       | [遅延が発生したときに更新される模様] １本目の X軸              |
| ^                    | uint16_t | touch_f1_b_y       | [遅延が発生したときに更新される模様] １本目の Y軸              |
| タッチパッド(2)      | bool     | touch_f2_a_active  | ２本目の接触フラグ                                             |
| ^                    | uint8_t  | touch_f2_a_counter | タッチ数(1本目,2本目共有)                                      |
| ^                    | uint16_t | touch_f2_a_x       | ２本目の X軸                                                   |
| ^                    | uint16_t | touch_f2_a_y       | ２本目の Y軸                                                   |
| タッチパッド(2)-予備 | bool     | touch_f2_b_active  | [遅延が発生したときに更新される模様] ２本目の接触フラグ        |
| ^                    | uint8_t  | touch_f2_b_counter | [遅延が発生したときに更新される模様] タッチ数(1本目,2本目共有) |
| ^                    | uint16_t | touch_f2_b_x       | [遅延が発生したときに更新される模様] ２本目の X軸              |
| ^                    | uint16_t | touch_f2_b_y       | [遅延が発生したときに更新される模様] ２本目の Y軸              |
| ジャイロセンサー     | int16_t  | gyro_x             | [確認中]  単位：[m rad/s]                                      |
| ^                    | int16_t  | gyro_y             | [確認中]  単位：[m rad/s]                                      |
| ^                    | int16_t  | gyro_z             | [確認中]  単位：[m rad/s]                                      |
| 加速度センサー       | int16_t  | accel_x            | [確認中]  単位：[m/s^2]                                        |
| ^                    | int16_t  | accel_y            | [確認中]  単位：[m/s^2]                                        |
| ^                    | int16_t  | accel_z            | [確認中]  単位：[m/s^2]                                        |
| バッテリーレベル     | uint8_t  | battery            | [確認中] 数値の妥当性を確認中                                  |
| ^                    | uint8_t  | battery_level      | [確認中] Lv1～10かな                                           |
| 接続                 | bool     | connected_usb      | USB接続されているか                                            |
| ^                    | bool     | connected_mic      | micが接続されているか                                          |
| ^                    | bool     | connected_phone    | [T.B.D.説明の修正] イヤホンが接続されているか                  |
| タイムスタンプ       | uint16_t | timestamp          | タイムスタンプ                                                 |
| ^                    | uint8_t  | report_counter     | レポートカウンター                                             |
| ステータス           | bool     | linked             | 接続していた場合、true                                         |




## Changelog

It is listed [here](./Changelog).

## Support

Kindly provide the details by creating a new issue.

## Contributing

We welcome pull requests from the community. If you're considering significant changes, we kindly ask you to begin by opening an issue to initiate a discussion about your proposed modifications.
Additionally, when submitting a pull request, please ensure that any relevant tests are updated or added as needed.


## Authors and acknowledgment

We offer heartfelt thanks to the open-source community for the invaluable gifts they've shared with us. The hardware, libraries, and tools they've provided have breathed life into our journey of development. Each line of code and innovation has woven a tapestry of brilliance, lighting our path. In this symphony of ingenuity, we find ourselves humbled and inspired. These offerings infuse our project with boundless possibilities. As we create, they guide us like stars, reminding us that collaboration can turn dreams into reality. With deep appreciation, we honor the open-source universe that nurtures us on this journey of discovery and growth.

## License

[BSD-3-Clause license](./LICENSE)
