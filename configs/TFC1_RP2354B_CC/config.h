/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software. You can redistribute this software
 * and/or modify this software under the terms of the GNU General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later
 * version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define FC_TARGET_MCU     RP2350B
#define BOARD_NAME        TFC1_RP2354B
#define MANUFACTURER_ID   TTIO
#define USBD_PRODUCT_STRING "TFC1 RP2354B CC ACCELGYRO DBG"

// BLUE LED
#define LED0_PIN             PA45
// RGB LED
#define LED_STRIP_PIN        PA46
// External LEDs
#define LED1_PIN             PA13 // green
//#define LED1_INVERTED
#define LED2_PIN             PA12 // red
//#define LED2_INVERTED


// For debugging (trace) via UART, make with env var PICO_TRACE set (see RP2350.mk).
// Example instance and pins below.
#define PICO_TRACE_UART_INSTANCE  1
#define PICO_TRACE_TX_GPIO        20
#define PICO_TRACE_RX_GPIO        21

#define UART0_TX_PIN         PA0
#define UART0_RX_PIN         PA1
// #define UART1_TX_PIN         PA4
// #define UART1_RX_PIN         PA5

#define PIOUART0_TX_PIN      PA10
#define PIOUART0_RX_PIN      PA11
#define PIOUART1_TX_PIN      PA14
#define PIOUART1_RX_PIN      PA15

// Bus for internal I2C sensors
#define I2C0_SDA_PIN         PA32
#define I2C0_SCL_PIN         PA33

#define I2C1_SDA_PIN         PA2
#define I2C1_SCL_PIN         PA3

// Battery voltage
#define USE_ADC
#define ADC_INSTANCE         ADC1
#define ADC_VBAT_PIN         PA44
#define DEFAULT_VOLTAGE_METER_SOURCE   VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE    110 // 100k/10k divider

// Unsupported feature in PCB design
#undef USE_SDCARD
#undef USE_SDCARD_SPI

// Gyro+acc
//#define USE_GYRO_CLKIN //TODO - gives compile error with betaflight_2025.12.0-beta
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_MPU9250
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_MPU9250
#define USE_ACC_SPI_ICM42688P
#define USE_ACCGYRO_ICM45686
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN         PA30
#define SPI1_SDI_PIN         PA28
#define SPI1_SDO_PIN         PA31
#define GYRO_1_EXTI_PIN      PA27
#define GYRO_1_CS_PIN        PA29
#define GYRO_1_CLKIN_PIN     PA26  // for ICM42688P,ICP45686 needs #define USE_GYRO_CLKIN
#define GYRO_1_SPI_INSTANCE  SPI1
#define GYRO_1_ALIGN         CW180_DEG // TODO: check if this is correct for ICM45686, may need to be CW90_DEG or CW270_DEG depending on orientation of chip on board

// Optional external barometer connected to I2C1 (second i2c bus) PA2=SDA PA3=SCL
// #define USE_BARO
// #define USE_BARO_MS5611
// #define USE_BARO_BMP280
// #define USE_BARO_BMP388
// #define USE_BARO_LPS
// #define USE_BARO_QMP6988
// #define USE_BARO_DPS310
// #define USE_BARO_BMP085
// #define USE_BARO_2SMBP_02B
// #define USE_BARO_LPS22DF
// #define BARO_I2C_INSTANCE    I2CDEV_1
#define USE_BARO
#define USE_BARO_BMP580
#define USE_BARO_BMP581
#define BARO_I2C_INSTANCE    I2CDEV_0
// TODO: madflight-fc3 claims that the BMP580 barometer on board is not supported by betaflight_2025.12.0-beta, but there is BMP580/581 options
// in latest codebase. Need to check if BMP580/581 support is working correctly in order to use the barometer on this board

// Optional external compass connected to I2C1 (second i2c bus) PA2=SDA PA3=SCL
// #define USE_MAG
// #define USE_MAG_HMC5883
// #define USE_MAG_QMC5883
// #define USE_MAG_LIS2MDL
// #define USE_MAG_LIS3MDL
// #define USE_MAG_AK8975
// #define USE_MAG_IST8310
// #define MAG_I2C_INSTANCE     I2CDEV_1
#define USE_MAG
#define USE_MAG_MMC560X
#define USE_MAG_MMC560X_ASYNC_READ
#define MAG_I2C_INSTANCE     I2CDEV_0
// TODO: madflight-fc3 claims that the MMC5603 magnetometer on board is not supported by betaflight_2025.12.0-beta, but there is MMC560X options
// in latest codebase. Need to check if MMC560X support is working correctly in order to use the magnetometer on this board


// Example GPIO pins for testing motor output
#define MOTOR1_PIN           PA6
#define MOTOR2_PIN           PA7
#define MOTOR3_PIN           PA8
#define MOTOR4_PIN           PA9

// Additional motors
#define MOTOR5_PIN           PA16 // pwm0a
#define MOTOR6_PIN           PA17 // pwm0b
#define MOTOR7_PIN           PA18 // pwm1a
#define MOTOR8_PIN           PA19 // pwm1b

// #define PINIO1_PIN PA22
// #define PINIO2_PIN PA23
// #define PINIO3_PIN PA24
// #define PINIO4_PIN PA25

// ADC pins
// #define ADC_RSSI_PIN         PA40
#define ADC_CURR_PIN         PA41
// #define ADC_EXTERNAL1_PIN    PA42
#define BEEPER_PIN           PA47

#define USE_BLACKBOX

#define USE_OPTICALFLOW
#define USE_POSITION_HOLD
#define USE_RANGEFINDER_MT

#define USE_RX_MSP // for `MSP_SET_RAW_RC` command to support RX passthrough to peripherals like the MT rangefinder
#define USE_RX_MSP_OVERRIDE