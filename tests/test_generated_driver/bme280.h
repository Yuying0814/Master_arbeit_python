/*
Public interface for the BME280 driver: class declaration, register constants and public API.
*/

#pragma once

// include_guards_and_includes: Header includes and version
#include <Arduino.h>
#include <Wire.h>
#include <stdint.h>

#define BME280_DRIVER_VERSION "0.1"

// register_definitions: Register address constants derived from register_map
static const uint8_t BME280_REG_DIG_T1_LSB = 0x88; // dig_T1 [7:0]
static const uint8_t BME280_REG_DIG_T1_MSB = 0x89; // dig_T1 [15:8]
static const uint8_t BME280_REG_DIG_T2_LSB = 0x8A; // dig_T2 [7:0]
static const uint8_t BME280_REG_DIG_T2_MSB = 0x8B; // dig_T2 [15:8]
static const uint8_t BME280_REG_DIG_T3_LSB = 0x8C; // dig_T3 [7:0]
static const uint8_t BME280_REG_DIG_T3_MSB = 0x8D; // dig_T3 [15:8]

static const uint8_t BME280_REG_DIG_P1_LSB = 0x8E; // dig_P1 [7:0]
static const uint8_t BME280_REG_DIG_P1_MSB = 0x8F; // dig_P1 [15:8]
static const uint8_t BME280_REG_DIG_P2_LSB = 0x90; // dig_P2 [7:0]
static const uint8_t BME280_REG_DIG_P2_MSB = 0x91; // dig_P2 [15:8]
static const uint8_t BME280_REG_DIG_P3_LSB = 0x92; // dig_P3 [7:0]
static const uint8_t BME280_REG_DIG_P3_MSB = 0x93; // dig_P3 [15:8]
static const uint8_t BME280_REG_DIG_P4_LSB = 0x94; // dig_P4 [7:0]
static const uint8_t BME280_REG_DIG_P4_MSB = 0x95; // dig_P4 [15:8]
static const uint8_t BME280_REG_DIG_P5_LSB = 0x96; // dig_P5 [7:0]
static const uint8_t BME280_REG_DIG_P5_MSB = 0x97; // dig_P5 [15:8]
static const uint8_t BME280_REG_DIG_P6_LSB = 0x98; // dig_P6 [7:0]
static const uint8_t BME280_REG_DIG_P6_MSB = 0x99; // dig_P6 [15:8]
static const uint8_t BME280_REG_DIG_P7_LSB = 0x9A; // dig_P7 [7:0]
static const uint8_t BME280_REG_DIG_P7_MSB = 0x9B; // dig_P7 [15:8]
static const uint8_t BME280_REG_DIG_P8_LSB = 0x9C; // dig_P8 [7:0]
static const uint8_t BME280_REG_DIG_P8_MSB = 0x9D; // dig_P8 [15:8]
static const uint8_t BME280_REG_DIG_P9_LSB = 0x9E; // dig_P9 [7:0]
static const uint8_t BME280_REG_DIG_P9_MSB = 0x9F; // dig_P9 [15:8]

static const uint8_t BME280_REG_DIG_H1 = 0xA1; // dig_H1 [7:0]

// Humidity calibration block
static const uint8_t BME280_REG_DIG_H2_LSB = 0xE1; // dig_H2 [7:0]
static const uint8_t BME280_REG_DIG_H2_MSB = 0xE2; // dig_H2 [15:8]
static const uint8_t BME280_REG_DIG_H3 = 0xE3; // dig_H3 [7:0]
static const uint8_t BME280_REG_DIG_H4 = 0xE4; // dig_H4 [11:4]
static const uint8_t BME280_REG_DIG_H5 = 0xE5; // dig_H5 [3:0] / [7:4]
static const uint8_t BME280_REG_DIG_H6 = 0xE7; // dig_H6 signed char

// Data registers
static const uint8_t BME280_REG_PRESS_MSB = 0xF7;
static const uint8_t BME280_REG_PRESS_LSB = 0xF8;
static const uint8_t BME280_REG_PRESS_XLSB = 0xF9;
static const uint8_t BME280_REG_TEMP_MSB = 0xFA;
static const uint8_t BME280_REG_TEMP_LSB = 0xFB;
static const uint8_t BME280_REG_TEMP_XLSB = 0xFC;
static const uint8_t BME280_REG_HUM_MSB = 0xFD;
static const uint8_t BME280_REG_HUM_LSB = 0xFE;

// Control / config
static const uint8_t BME280_REG_CTRL_HUM = 0xF2;
static const uint8_t BME280_REG_STATUS = 0xF3;
static const uint8_t BME280_REG_CTRL_MEAS = 0xF4;
static const uint8_t BME280_REG_CONFIG = 0xF5;
static const uint8_t BME280_REG_RESET = 0xE0;
static const uint8_t BME280_REG_ID = 0xD0;

// Default I2C address options (7-bit)
static const uint8_t BME280_I2C_ADDR_0 = 0x76; // SDO = GND
static const uint8_t BME280_I2C_ADDR_1 = 0x77; // SDO = VDDIO

// types_and_structs: Calibration and raw-data containers
struct BME280_Calibration {
    uint16_t dig_T1;
    int16_t  dig_T2;
    int16_t  dig_T3;

    uint16_t dig_P1;
    int16_t  dig_P2;
    int16_t  dig_P3;
    int16_t  dig_P4;
    int16_t  dig_P5;
    int16_t  dig_P6;
    int16_t  dig_P7;
    int16_t  dig_P8;
    int16_t  dig_P9;

    uint8_t  dig_H1;
    int16_t  dig_H2;
    uint8_t  dig_H3;
    int16_t  dig_H4; // 12-bit signed stored in int16_t
    int16_t  dig_H5; // 12-bit signed stored in int16_t
    int8_t   dig_H6;
};

struct BME280_Raw {
    uint32_t press; // 20-bit
    uint32_t temp;  // 20-bit
    uint32_t hum;   // 16-bit
};

// class_declaration: BME280 public API
class BME280 {
public:
    // constructor
    BME280();

    // begin: initialize and optionally read calibration. address defaults to 0x76
    bool begin(uint8_t address = BME280_I2C_ADDR_0, TwoWire &wirePort = Wire);

    // quick connection check
    bool isConnected();

    // soft reset (write-only register)
    void reset();

    // configure oversampling, mode, standby and filter
    bool configure(uint8_t osrs_t = 1,
                   uint8_t osrs_p = 1,
                   uint8_t osrs_h = 1,
                   uint8_t mode   = 3,
                   uint8_t t_sb   = 0,
                   uint8_t filter = 0);

    // low-level register access
    int  readRegister8(uint8_t reg);
    bool writeRegister8(uint8_t reg, uint8_t value);
    int  readRegister16LE(uint8_t lsb_reg);

    // calibration read
    bool readCalibration();

    // raw measurement read
    bool readRawData(uint32_t &rawP, uint32_t &rawT, uint32_t &rawH);

    // conversion functions (implemented if compensation formulas available)
    float readTemperature();
    float readPressure();
    float readHumidity();

    // publicly accessible calibration copy (read-only use by caller)
    BME280_Calibration calibration;

private:
    // private state
    uint8_t _address;
    TwoWire *_wire;
    BME280_Raw _lastRaw;
    int32_t _t_fine; // intermediate variable for compensation

    // internal helpers (allowed lightweight helpers)
    int readBytes(uint8_t start_reg, uint8_t *buf, size_t len);
};

