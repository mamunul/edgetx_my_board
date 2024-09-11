/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once


/*

STM32F405 Pin assignment

Module(UART):        PA9 PA10
Volume Encoder(I2C):                         PB6 PB7
SDCard:              PA8                                                  PC8 PC9 PC10 PC11 PC12     PD2
LCD:                 PA5 PA6 PA7 PA13 PA14
Keys:                                        PB0 PB1 PB3 PB4 PB5 PB8
Trims:                                                                    PC0 PC1 PC2 PC3
Switch:                                      PB9 PB10 PB11 PB12
Sticks:                                                                   PC4 PC5 PC6 PC7
PWR_Button, PWR_Led: PA0                     PB2
Module_PWR:          PA1
Backlight:                                   PB14
Audio_enable:        PA2
Audio_OUT:                                   PB15
Battery:                                     PB13
Status Leds:         PA3 PA4
USB:                 PA11 PA12 PA15
32KHz:                                                                    PC14 PC15

AvailablePins:                                                            PC13

*/


#if defined(STM32F4)
#define CPU_FREQ 168000000
#define PERI1_FREQUENCY 42000000
#define PERI2_FREQUENCY 84000000
#define TIMER_MULT_APB1 2
#define TIMER_MULT_APB2 2
#else
#define CPU_FREQ 120000000
#define PERI1_FREQUENCY 30000000
#define PERI2_FREQUENCY 60000000
#define TIMER_MULT_APB1 2
#define TIMER_MULT_APB2 2
#endif

#define TELEMETRY_EXTI_PRIO 0  // required for soft serial

// Keys

#define KEYS_GPIO_REG_EXIT GPIOB
#define KEYS_GPIO_PIN_EXIT LL_GPIO_PIN_2  // PB.00
#define KEYS_GPIO_REG_ENTER GPIOB
#define KEYS_GPIO_PIN_ENTER LL_GPIO_PIN_10  // PB.01
#define KEYS_GPIO_REG_UP GPIOB
#define KEYS_GPIO_PIN_UP LL_GPIO_PIN_9  // PB.03
#define KEYS_GPIO_REG_DOWN GPIOB
#define KEYS_GPIO_PIN_DOWN LL_GPIO_PIN_11  // PB.04
#define KEYS_GPIO_REG_LEFT GPIOB
#define KEYS_GPIO_PIN_LEFT LL_GPIO_PIN_7  // PB.05
#define KEYS_GPIO_REG_RIGHT GPIOB
#define KEYS_GPIO_PIN_RIGHT LL_GPIO_PIN_3  // PB.08

// Trims

// #define TRIMS_COUNT_8

#if defined(TRIMS_COUNT_8)
#define TRIMS_GPIO_REG_LHL GPIOA
#define TRIMS_GPIO_PIN_LHL LL_GPIO_PIN_1  // PC.00
#define TRIMS_GPIO_REG_LHR GPIOA
#define TRIMS_GPIO_PIN_LHR LL_GPIO_PIN_0  // PC.01
#define TRIMS_GPIO_REG_LVD GPIOA
#define TRIMS_GPIO_PIN_LVD LL_GPIO_PIN_4  // PC.02
#define TRIMS_GPIO_REG_LVU GPIOA
#define TRIMS_GPIO_PIN_LVU LL_GPIO_PIN_3  // PC.03
#define TRIMS_GPIO_REG_RVD GPIOA
#define TRIMS_GPIO_PIN_RVD LL_GPIO_PIN_3  // PC.04
#define TRIMS_GPIO_REG_RHL GPIOA
#define TRIMS_GPIO_PIN_RHL LL_GPIO_PIN_1  // PC.05
#define TRIMS_GPIO_REG_RVU GPIOA
#define TRIMS_GPIO_PIN_RVU LL_GPIO_PIN_2  // PC.06
#define TRIMS_GPIO_REG_RHR GPIOA
#define TRIMS_GPIO_PIN_RHR LL_GPIO_PIN_13  // PC.07
#else
#define TRIMS_GPIO_REG_LHL GPIOC
#define TRIMS_GPIO_PIN_LHL LL_GPIO_PIN_4  // PC.00
#define TRIMS_GPIO_REG_LHR GPIOC
#define TRIMS_GPIO_PIN_LHR LL_GPIO_PIN_5  // PC.01
#define TRIMS_GPIO_REG_LVU GPIOC
#define TRIMS_GPIO_PIN_LVU LL_GPIO_PIN_0  // PC.02
#define TRIMS_GPIO_REG_LVD GPIOC
#define TRIMS_GPIO_PIN_LVD LL_GPIO_PIN_1  // PC.03
#define TRIMS_VIRTUAL_RV
#define TRIMS_VIRTUAL_RH
#endif
// Switches

#define STORAGE_SWITCH_A
#define HARDWARE_SWITCH_A
#define SWITCHES_GPIO_REG_A GPIOB
#define SWITCHES_GPIO_PIN_A LL_GPIO_PIN_5  // PB.09

#define STORAGE_SWITCH_B
#define HARDWARE_SWITCH_B
#define SWITCHES_B_INVERTED
#define SWITCHES_GPIO_REG_B GPIOB
#define SWITCHES_GPIO_PIN_B LL_GPIO_PIN_2  // PB.10

#define STORAGE_SWITCH_C
#define HARDWARE_SWITCH_C
#define SWITCHES_C_INVERTED
#define SWITCHES_GPIO_REG_C GPIOB
#define SWITCHES_GPIO_PIN_C LL_GPIO_PIN_2  // PB.11

#define STORAGE_SWITCH_D
#define HARDWARE_SWITCH_D
#define SWITCHES_D_INVERTED
#define SWITCHES_GPIO_REG_D GPIOB
#define SWITCHES_GPIO_PIN_D LL_GPIO_PIN_2  // PB.12

// ADC
#define ADC_MAIN ADC3
#define ADC_DMA DMA2
#define ADC_DMA_CHANNEL LL_DMA_CHANNEL_2
#define ADC_DMA_STREAM LL_DMA_STREAM_0
#define ADC_DMA_STREAM_IRQ DMA2_Stream0_IRQn
#define ADC_DMA_STREAM_IRQHandler DMA2_Stream0_IRQHandler

#define ADC_SAMPTIME LL_ADC_SAMPLINGTIME_28CYCLES
#define ADC_CHANNEL_RTC_BAT LL_ADC_CHANNEL_VBAT

#define ADC_GPIO_PIN_STICK_RV LL_GPIO_PIN_0    // PC.04
#define ADC_GPIO_PIN_STICK_RH LL_GPIO_PIN_1    // PC.05
#define ADC_GPIO_PIN_STICK_LH LL_GPIO_PIN_2    // PC.06
#define ADC_GPIO_PIN_STICK_LV LL_GPIO_PIN_3    // PC.07
#define ADC_CHANNEL_STICK_RV LL_ADC_CHANNEL_0  // ADC1_IN0
#define ADC_CHANNEL_STICK_RH LL_ADC_CHANNEL_1  // ADC1_IN1
#define ADC_CHANNEL_STICK_LH LL_ADC_CHANNEL_2  // ADC1_IN2
#define ADC_CHANNEL_STICK_LV LL_ADC_CHANNEL_3  // ADC1_IN3

#define ADC_GPIO_PIN_BATT LL_GPIO_PIN_0  // PB.13
#define ADC_GPIOA_PINS                                                     \
  (ADC_GPIO_PIN_STICK_RV | ADC_GPIO_PIN_STICK_RH | ADC_GPIO_PIN_STICK_LH | \
   ADC_GPIO_PIN_STICK_LV)
#define ADC_GPIOC_PINS (ADC_GPIO_PIN_BATT)
#define ADC_CHANNEL_BATT LL_ADC_CHANNEL_10  // ADC1_IN10

#define ADC_DIRECTION {1, -1, -1, 1, -1, 1}
#define ADC_VREF_PREC2 300

// PWR and LED driver

#define PWR_SWITCH_GPIO GPIO_PIN(GPIOA, 1)  // PA.01
#define PWR_ON_GPIO GPIO_PIN(GPIOA, 0)      // PA.00

#define STATUS_LEDS
#define GPIO_LED_GPIO_ON gpio_clear
#define GPIO_LED_GPIO_OFF gpio_set
// #define LED_GREEN_GPIO GPIO_PIN(GPIOA, 2)  // PA.02
#define LED_RED_GPIO GPIO_PIN(GPIOA, 3)    // PA.03
#define LED_BLUE_GPIO GPIO_PIN(GPIOA, 4)   // PA.04

// Internal Module

#define EXTERNAL_ANTENNA

#define INTMODULE_PWR_GPIO GPIO_PIN(GPIOB, 2)  // PB.02
#define INTMODULE_TX_GPIO GPIO_PIN(GPIOA, 9)   // PA.09
#define INTMODULE_RX_GPIO GPIO_PIN(GPIOA, 10)  // PA.10
#define INTMODULE_USART USART1
#define INTMODULE_USART_IRQn USART1_IRQn
#define INTMODULE_DMA DMA2
#define INTMODULE_DMA_STREAM LL_DMA_STREAM_7
#define INTMODULE_DMA_STREAM_IRQ DMA2_Stream7_IRQn
#define INTMODULE_DMA_STREAM_IRQHandler DMA2_Stream7_IRQHandler
#define INTMODULE_DMA_CHANNEL LL_DMA_CHANNEL_4

// Trainer Port

// Serial Port

// Telemetry
#define TELEMETRY_DIR_GPIO GPIO_PIN(GPIOD, 2)  // PD.02

#define TELEMETRY_SET_INPUT 0
#define TELEMETRY_TX_GPIO GPIO_PIN(GPIOA, 9)   // PA.09
#define TELEMETRY_RX_GPIO GPIO_PIN(GPIOA, 10)  // PA.10
#define TELEMETRY_USART                 USART2
#define TELEMETRY_USART_IRQn            USART2_IRQn
#define TELEMETRY_DMA                   DMA1
#define TELEMETRY_DMA_Stream_TX         LL_DMA_STREAM_6
#define TELEMETRY_DMA_Channel_TX        LL_DMA_CHANNEL_4
#define TELEMETRY_DMA_TX_Stream_IRQ     DMA1_Stream6_IRQn
#define TELEMETRY_DMA_TX_IRQHandler     DMA1_Stream6_IRQHandler
// #define TELEMETRY_DMA_Stream_RX         LL_DMA_STREAM_5
// #define TELEMETRY_DMA_Channel_RX        LL_DMA_CHANNEL_4


// Software IRQ (Prio 5 -> FreeRTOS compatible)
#define TELEMETRY_RX_FRAME_EXTI_LINE    LL_EXTI_LINE_4
#define USE_EXTI4_IRQ
#define EXTI4_IRQ_Priority 5
// #define TELEMETRY_USART USART2
// #define TELEMETRY_DMA DMA1
// #define TELEMETRY_DMA_Stream_TX LL_DMA_STREAM_6
// #define TELEMETRY_DMA_Channel_TX LL_DMA_CHANNEL_4
// #define TELEMETRY_DMA_TX_Stream_IRQ DMA1_Stream6_IRQn
// #define TELEMETRY_DMA_TX_IRQHandler DMA1_Stream6_IRQHandler
// #define TELEMETRY_DMA_TX_FLAG_TC DMA_IT_TCIF6
// #define TELEMETRY_USART_IRQHandler USART2_IRQHandler
// #define TELEMETRY_USART_IRQn USART2_IRQn
// #define TELEMETRY_EXTI_PORT LL_SYSCFG_EXTI_PORTD
// #define TELEMETRY_EXTI_SYS_LINE LL_SYSCFG_EXTI_LINE6
// #define TELEMETRY_EXTI_LINE LL_EXTI_LINE_6
// #define TELEMETRY_EXTI_TRIGGER LL_EXTI_TRIGGER_RISING
// // TELEMETRY_EXTI IRQ
// #if !defined(USE_EXTI9_5_IRQ)
// #define USE_EXTI9_5_IRQ
// #endif
// // overwrite priority
// #undef EXTI9_5_IRQ_Priority
// #define EXTI9_5_IRQ_Priority TELEMETRY_EXTI_PRIO

// #define TELEMETRY_TIMER TIM11
// #define TELEMETRY_TIMER_IRQn TIM1_TRG_COM_TIM11_IRQn
// #define TELEMETRY_TIMER_IRQHandler TIM1_TRG_COM_TIM11_IRQHandler

// // Software IRQ (Prio 5 -> FreeRTOS compatible)
// #define TELEMETRY_RX_FRAME_EXTI_LINE LL_EXTI_LINE_4
// #define USE_EXTI4_IRQ
// #define EXTI4_IRQ_Priority 5

// USB Charger
#if defined(USB_CHARGER)
#define USB_CHARGER_GPIO GPIO_PIN(GPIOB, 5)
#endif

// USB
#define USB_GPIO_VBUS GPIO_PIN(GPIOA, 15)  // PA.15
#define USB_GPIO_DM GPIO_PIN(GPIOA, 11)    // PA.11
#define USB_GPIO_DP GPIO_PIN(GPIOA, 12)    // PA.12
#define USB_GPIO_AF GPIO_AF10

// BackLight

#define BACKLIGHT_TIMER_FREQ (PERI2_FREQUENCY * TIMER_MULT_APB2)
#define BACKLIGHT_TIMER TIM10
#define BACKLIGHT_GPIO GPIO_PIN(GPIOB, 14)  // PB.14
#define BACKLIGHT_GPIO_AF GPIO_AF3

// LCD driver
#define LCD_VERTICAL_INVERT
#define LCD_HORIZONTAL_INVERT
// #define OLED_SCREEN
// #define SSD1309_LCD

#define LCD_MOSI_GPIO GPIO_PIN(GPIOA, 7)  // PA.07
#define LCD_CLK_GPIO GPIO_PIN(GPIOA, 5)   // PA.05
#define LCD_A0_GPIO GPIO_PIN(GPIOA, 6)    // PA.06
#define LCD_NCS_GPIO GPIO_PIN(GPIOA, 13)  // PA.13
#define LCD_RST_GPIO GPIO_PIN(GPIOA, 14)  // PA.14
#define LCD_DMA DMA1
#define LCD_DMA_Stream DMA1_Stream7
#define LCD_DMA_Stream_IRQn DMA1_Stream7_IRQn
#define LCD_DMA_Stream_IRQHandler DMA1_Stream7_IRQHandler
#define LCD_DMA_FLAGS                                       \
  (DMA_HIFCR_CTCIF7 | DMA_HIFCR_CHTIF7 | DMA_HIFCR_CTEIF7 | \
   DMA_HIFCR_CDMEIF7 | DMA_HIFCR_CFEIF7)
#define LCD_DMA_FLAG_INT DMA_HIFCR_CTCIF7
#define LCD_SPI SPI3
#define LCD_GPIO_AF GPIO_AF6

#if defined(SSD1309_LCD)
#define LCD_SPI_PRESCALER SPI_CR1_BR_1
#else
#define LCD_SPI_PRESCALER 0
#endif

// I2C Bus 1: EEPROM and CAT5137 digital pot for volume control
#define I2C_B1 I2C1
#define I2C_B1_GPIO_AF LL_GPIO_AF_4

#define I2C_B1_SCL_GPIO GPIO_PIN(GPIOB, 6)  // PB.06
#define I2C_B1_SDA_GPIO GPIO_PIN(GPIOB, 7)  // PB.07


// I2C Volume control
#if !defined(SOFTWARE_VOLUME)
#define VOLUME_I2C_ADDRESS 0x2E
#define VOLUME_I2C_BUS I2C_Bus_1
#endif

#define I2C_B1_CLK_RATE 400000

// SD - SDIO
#define SD_PRESENT_GPIO GPIO_PIN(GPIOA, 8)  // PA.08
#define SD_SDIO_DMA DMA2
#define SD_SDIO_DMA_STREAM DMA2_Stream3  // or Stream6
#define SD_SDIO_DMA_CHANNEL LL_DMA_CHANNEL_4
#define SD_SDIO_DMA_IRQn DMA2_Stream3_IRQn
#define SD_SDIO_DMA_IRQHANDLER DMA2_Stream3_IRQHandler
#define SD_SDIO_CLK_DIV(fq) ((48000000 / (fq)) - 2)
#define SD_SDIO_INIT_CLK_DIV SD_SDIO_CLK_DIV(400000)
#define SD_SDIO_TRANSFER_CLK_DIV SD_SDIO_CLK_DIV(24000000)

#define STORAGE_USE_SDIO

// Audio
#define AUDIO_RCC_APB1Periph LL_APB1_GRP1_PERIPH_DAC1
#define AUDIO_OUTPUT_GPIO GPIO_PIN(GPIOB, 15)
#define AUDIO_DMA DMA1
#define AUDIO_TIM_IRQn TIM6_DAC_IRQn
#define AUDIO_TIM_IRQHandler TIM6_DAC_IRQHandler
#define AUDIO_DMA_Stream DMA1_Stream5
#define AUDIO_DMA_Stream_IRQn DMA1_Stream5_IRQn
#define AUDIO_DMA_Stream_IRQHandler DMA1_Stream5_IRQHandler
#define AUDIO_TIMER TIM6

#define AUDIO_SPEAKER_ENABLE_GPIO GPIO_PIN(GPIOA, 2)  // PA.02

// Millisecond timer
#define MS_TIMER TIM14
#define MS_TIMER_IRQn TIM8_TRG_COM_TIM14_IRQn
#define MS_TIMER_IRQHandler TIM8_TRG_COM_TIM14_IRQHandler

// Mixer scheduler timer
#define MIXER_SCHEDULER_TIMER TIM12
#define MIXER_SCHEDULER_TIMER_FREQ (PERI1_FREQUENCY * TIMER_MULT_APB1)
#define MIXER_SCHEDULER_TIMER_IRQn TIM8_BRK_TIM12_IRQn
#define MIXER_SCHEDULER_TIMER_IRQHandler TIM8_BRK_TIM12_IRQHandler
