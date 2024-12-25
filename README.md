# DualShock4 on Pico-W

Pico-WとDualShock4を接続するためのサンプルプログラムです。

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
    DS4forPicoW controller;
    bool loop_contents = true;
    do {
        printf("Starting inquiry scan..\n");
        loop_contents = controller.scan();
    } while (false == loop_contents);

    while (loop_contents) {
       bt_hid_state state = controller.get_state();
    }
}
```






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
