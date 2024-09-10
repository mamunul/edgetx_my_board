option(SHUTDOWN_CONFIRMATION "Shutdown confirmation" OFF)
option(PXX1 "PXX1 protocol support" ON)
option(PXX2 "PXX2 protocol support" OFF)
option(AFHDS3 "AFHDS3 TX Module" OFF)
option(GHOST "Ghost TX Module" ON)
option(INTERNAL_MODULE_PPM "Support for PPM internal module" OFF)
option(AUTOUPDATE "Auto update internal chips from SD" OFF)
option(BIND_KEY "Enable bind button" OFF)
option(BLUETOOTH "FrSky BT module support" OFF)

set(USE_RTC_CLOCK YES)
set(HARDWARE_EXTERNAL_MODULE NO)

set(HSE_VALUE 12000000)
set(TARGET_DIR xetoz)
set(PPM_LIMITS_SYMETRICAL YES)

add_definitions(-DPCBXETOZ -DAUDIO -DVOICE)

if(PCB STREQUAL XETOZ)
  set(DEFAULT_INTERNAL_MODULE ISRM_PXX2 CACHE STRING "Default internal module")
  set(INTERNAL_MODULE_SERIAL YES)
  set(MODULE_SIZE_SML YES)
  set(PXX_FREQUENCY "HIGH")
  set(PWR_BUTTON "PRESS" CACHE STRING "Pwr button type (PRESS/SWITCH)")
  set(CPU_TYPE_FULL STM32F405xG)
  set(HAPTIC NO)
  set(FLAVOUR xetoz1)
  add_definitions(-DBOARD_NAME="xetoz1")
  add_definitions(-DPCBXETOZ)
  add_definitions(-DPWR_BUTTON_${PWR_BUTTON})
  add_definitions(-DPCBREV=${PCBREV})
  # add_definitions(-DHARDWARE_POWER_MANAGEMENT_UNIT)
  set(GUI_DIR 128x64)
  set(BITMAPS_DIR 128x64)
  set(BITMAPS_TARGET 9x_bitmaps)
  set(FONTS_TARGET 9x_fonts_1bit)
  set(LCD_DRIVER lcd_driver_spi.cpp)
  set(STATUS_LEDS YES)
  set(PXX2 ON)
  set(BLUETOOTH NO)
  set(IMU NO)
  set(ROTARY_ENCODER NO)
  set(USB_CHARGER NO)
  add_definitions(-DMANUFACTURER_XETOZ)
endif()

message("CPU_TYPE_FULL = ${CPU_TYPE_FULL}")
if(CPU_TYPE_FULL STREQUAL STM32F205xE)
  set(CPU_TYPE STM32F2)
  add_definitions(-DSTM32F205xx)
  set(TARGET_LINKER_DIR stm32f20x)
elseif (CPU_TYPE_FULL STREQUAL STM32F405xG)
  set(CPU_TYPE STM32F4)
  add_definitions(-DSTM32F40_41xxx -DSTM32F405xx -DCCMRAM)
  set(TARGET_FLASH_SIZE 1M)
  add_definitions(-DSTM32F405xG)
  set(TARGET_LINKER_DIR stm32f40x)
else()
  message(FATAL_ERROR "Unknown CPU_TYPE_FULL" )
endif()


if(ENABLE_SERIAL_PASSTHROUGH)
  set(CLI ON "Enable CLI")
endif()

if(INTERNAL_MODULE_SERIAL)

  # defines default internal modules
  if(DEFAULT_INTERNAL_MODULE STREQUAL XJT_PXX1)
    set(INTERNAL_MODULES PXX1 CACHE STRING "Internal modules")
  elseif(DEFAULT_INTERNAL_MODULE STREQUAL ISRM_PXX2)
    set(INTERNAL_MODULES PXX2 CACHE STRING "Internal modules")
  else()
    set(INTERNAL_MODULES MULTI;CRSF CACHE STRING "Internal modules")
  endif()

  add_definitions(-DINTERNAL_MODULE_SERIAL)
  if(PXX_FREQUENCY STREQUAL HIGH)
    add_definitions(-DPXX_FREQUENCY_HIGH)
  endif()

else()

  # defines existing internal modules
  set(INTERNAL_MODULES PXX1)

endif()

set(TARGET_SRC_DIR targets/${TARGET_DIR})

set(BOARD_COMMON_SRC
  ${TARGET_SRC_DIR}/board.cpp
  ${TARGET_SRC_DIR}/led_driver.cpp
  # ${TARGET_SRC_DIR}/haptic_driver.cpp
  ${TARGET_SRC_DIR}/backlight_driver.cpp
  ${TARGET_SRC_DIR}/${LCD_DRIVER}
  targets/common/arm/stm32/abnormal_reboot.cpp
  targets/common/arm/stm32/delays_driver.cpp
  targets/common/arm/stm32/flash_driver.cpp
  targets/common/arm/stm32/pwr_driver.cpp
  targets/common/arm/stm32/rtc_driver.cpp
  targets/common/arm/stm32/watchdog_driver.cpp
)

if(ROTARY_ENCODER)
  list(APPEND BOARD_COMMON_SRC
    targets/common/arm/stm32/rotary_encoder_driver.cpp
  )
endif()

if(BLUETOOTH)
  list(APPEND BOARD_COMMON_SRC
    targets/common/arm/stm32/bluetooth_driver.cpp
  )
endif()

# Bootloader board library
add_library(board_bl OBJECT EXCLUDE_FROM_ALL
  ${BOARD_COMMON_SRC}
  ${TARGET_SRC_DIR}/bootloader/boot_menu.cpp
)
# add_dependencies(board_bl ${BITMAPS_TARGET})
set(BOOTLOADER_SRC ${BOOTLOADER_SRC} $<TARGET_OBJECTS:board_bl>)

# Firmware board library
add_library(board OBJECT EXCLUDE_FROM_ALL
  ${BOARD_COMMON_SRC}
  ${TARGET_SRC_DIR}/volume_i2c.cpp
  targets/common/arm/stm32/audio_dac_driver.cpp
  targets/common/arm/stm32/delays_driver.cpp
  targets/common/arm/stm32/heartbeat_driver.cpp
  targets/common/arm/stm32/mixer_scheduler_driver.cpp
  targets/common/arm/stm32/module_timer_driver.cpp
  targets/common/arm/stm32/stm32_pulse_driver.cpp
  targets/common/arm/stm32/stm32_softserial_driver.cpp
  targets/common/arm/stm32/stm32_switch_driver.cpp
  targets/common/arm/stm32/trainer_driver.cpp
  targets/common/arm/stm32/stm32_ws2812.cpp
)
set(FIRMWARE_SRC ${FIRMWARE_SRC} $<TARGET_OBJECTS:board>)

if(STATUS_LEDS)
  target_sources(board PRIVATE ${TARGET_SRC_DIR}/led_driver.cpp)
endif()

if(BIND_KEY)
  add_definitions(-DBIND_KEY)
  target_sources(board PRIVATE ${TARGET_SRC_DIR}/bind_button_driver.cpp)
endif()

if(USB_CHARGER)
  add_definitions(-DUSB_CHARGER)
  target_sources(board PRIVATE ${TARGET_SRC_DIR}/usb_charger_driver.cpp)
endif()

if(IMU)
  target_sources(board PRIVATE targets/common/arm/stm32/lsm6ds_driver.cpp)
endif()

if(AUTOUPDATE)
  add_definitions(-DAUTOUPDATE)
endif()

if(USE_RTC_CLOCK)
  add_definitions(-DRTCLOCK)
endif()


set(SRC ${SRC}
  io/frsky_firmware_update.cpp
  io/multi_firmware_update.cpp
)

set(GUI_SRC ${GUI_SRC}
  model_input_edit.cpp
  model_mix_edit.cpp
  model_display.cpp
  radio_diagkeys.cpp
  radio_diaganas.cpp
  view_channels.cpp
  view_telemetry.cpp
  view_about.cpp
  bmp.cpp
)

if(PCB STREQUAL XLITE OR PCB STREQUAL XLITES OR PCBREV STREQUAL COMMANDO8)
  set(FIRMWARE_SRC
    ${FIRMWARE_SRC}
    targets/common/arm/stm32/sticks_pwm_driver.cpp)
endif()

set(FIRMWARE_SRC
  ${FIRMWARE_SRC}
  targets/common/arm/loadboot.cpp
  )

set(RADIO_DEPENDENCIES ${RADIO_DEPENDENCIES} ${BITMAPS_TARGET})
