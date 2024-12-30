add_library(lib_ds4_on_pico STATIC
	src/ds4_on_pico_w.cpp
)

target_link_libraries(lib_ds4_on_pico
    pico_stdlib
)

target_include_directories(lib_ds4_on_pico PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D BUILD_TYPE=\\\"Debug\\\" -D ERROR_DS4_REPORTS=1 -D INFO_DS4_REPORTS=1 -D DEBUG_DS4_REPORTS=1 -D VERBOSE_DS4_REPORTS=0")
	message(STATUS "# Build \"lib_ds4_on_pico\":Debug")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D BUILD_TYPE=\\\"BUILD_TYPE=Release\\\" -D ERROR_DS4_REPORTS=0 -D INFO_DS4_REPORTS=0 -D DEBUG_DS4_REPORTS=0 -D VERBOSE_DS4_REPORTS=0")
	message(STATUS "# Build \"lib_ds4_on_pico\":Release")
endif()

target_link_libraries(lib_ds4_on_pico
	hardware_gpio
	pico_cyw43_arch_none
		pico_btstack_classic
		pico_btstack_ble
		pico_btstack_cyw43
	pico_multicore
)
