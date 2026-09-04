/*
Public driver API, enums, result structures, register constants, and private transport/calibration declarations.
*/

#pragma once

// Includes and public types: Include Arduino/Wire/SPI dependencies and define documented error, oversampling, mode, standby, filter, configuration, raw-data, and compensated-sample types.
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

// Public error codes reported by lastError()
enum class Error {
    Ok = 0,
    Transport,       // I2C/SPI transaction failure
    ChipIdMismatch,  // ID != 0x60
    Timeout,         // Polling or conversion timeout
    Calibration,     // Calibration read/parse failure
    SkippedData,     // ADC sentinel values (measurement skipped)
    InvalidState     // Operation invalid in current state
};

// Oversampling options (maps to osrs_x register encodings)
enum class Oversampling : uint8_t {
    Skipped = 0,
    X1 = 1,
    X2 = 2,
    X4 = 3,
    X8 = 4,
    X16 = 5
};

// Sensor mode
enum class Mode : uint8_t {
    Sleep = 0,
    Forced1 = 1, // datasheet: 01 and 10 are forced; we represent as Forced1
    Forced2 = 2, // second forced encoding; treated equivalently
    Normal = 3
};

// Standby times for config.t_sb
enum class Standby : uint8_t {
    Ms0_5 = 0,
    Ms62_5 = 1,
    Ms125 = 2,
    Ms250 = 3,
    Ms500 = 4,
    Ms1000 = 5,
    Ms10 = 6,
    Ms20 = 7
};

// IIR filter coefficients
enum class Filter : uint8_t {
    Off = 0,
    C2 = 1,
    C4 = 2,
    C8 = 3,
    C16 = 4
};

// Public configuration struct mapping to registers config, ctrl_hum, ctrl_meas
struct Configuration {
    Oversampling osrs_t = Oversampling::X1;
    Oversampling osrs_p = Oversampling::X1;
    Oversampling osrs_h = Oversampling::X1;
    Standby t_sb = Standby::Ms0_5;
    Filter filter = Filter::Off;
    bool spi3w_en = false; // exposed but not used by this driver unless set
};

// Raw ADC parsed fields
struct RawData {
    uint32_t pressure; // 20-bit (or sentinel 0x80000)
    uint32_t temperature; // 20-bit (or sentinel 0x80000)
    uint16_t humidity; // 16-bit (or sentinel 0x8000)
};

// Compensated sample in engineering units
struct Sample {
    float temperature_c; // degrees C
    float pressure_pa;   // Pascal
    float humidity_rh;   // % relative humidity
};

// BME280 public API: Declare constructors for I2C and SPI plus documented sensor lifecycle, configuration, status, acquisition, and diagnostic APIs.
class BME280 {
public:
    // I2C constructor: bind an initialized TwoWire and 7-bit address (0x76 or 0x77)
    BME280(TwoWire &wire, uint8_t address = 0x76);

    // SPI constructor: bind an initialized SPIClass instance and CS pin (active low)
    BME280(SPIClass &spi, uint8_t csPin, uint32_t clockHz = 1000000);

    // Initialize sensor: read ID, reset, wait for im_update clear, read calibration, apply safe forced-mode default
    bool begin();

    // Soft reset and wait for im_update clear; bounded timeout in ms
    bool reset(uint16_t timeoutMs = 10);

    // Apply configuration safely while in sleep (writes config, ctrl_hum then ctrl_meas)
    bool configure(const Configuration &config);

    // Set mode bits preserving oversampling bits from last known ctrl_meas
    bool setMode(Mode mode);

    // Read and decode current mode bits
    bool readMode(Mode &modeOut);

    // Read status.measuring
    bool isMeasuring(bool &measuring);

    // Read status.im_update
    bool isUpdating(bool &updating);

    // Read chip ID register
    bool readChipId(uint8_t &chipId);

    // Burst read raw ADC outputs (0xF7..0xFE) without initiating measurement
    bool readRaw(RawData &raw);

    // Trigger a forced measurement, wait, burst-read and compensate
    bool takeForcedMeasurement(Sample &sample, uint16_t timeoutMs = 0);

    // Burst-read current outputs and compensate without changing mode
    bool readSample(Sample &sample);

    // Retrieve last driver error
    Error lastError() const { return _lastError; }

private:
    // Private transport and calibration: Declare private register I/O, status polling, calibration parsing, timing, and compensation helpers; calibration registers are internal-only.
    bool readRegisters(uint8_t reg, uint8_t *data, size_t length);
    bool writeRegister(uint8_t reg, uint8_t value);
    bool readCalibration();
    bool waitForMeasurement(uint16_t timeoutMs);

    // Internal helpers for compensation
    int32_t compensateTemperatureInt32(uint32_t adc_T, int32_t &t_fine_out);
    uint32_t compensatePressureInt32(uint32_t adc_P, int32_t t_fine);
    uint32_t compensateHumidityInt32(uint16_t adc_H, int32_t t_fine);

    // Transport bindings
    TwoWire *_wire = nullptr;
    SPIClass *_spi = nullptr;
    bool _useSPI = false;
    uint8_t _i2cAddress = 0x76;
    uint8_t _csPin = 255;
    uint32_t _spiClockHz = 1000000;

    // Cached configuration register values (mirror of last written ctrl_meas and ctrl_hum/config)
    uint8_t _ctrl_meas_cache = 0x00;
    uint8_t _ctrl_hum_cache = 0x00;
    uint8_t _config_cache = 0x00;

    // Calibration storage (internal-only)
    bool _haveCalibration = false;
    uint16_t dig_T1;
    int16_t dig_T2;
    int16_t dig_T3;
    uint16_t dig_P1;
    int16_t dig_P2;
    int16_t dig_P3;
    int16_t dig_P4;
    int16_t dig_P5;
    int16_t dig_P6;
    int16_t dig_P7;
    int16_t dig_P8;
    int16_t dig_P9;
    uint8_t dig_H1;
    int16_t dig_H2;
    uint8_t dig_H3;
    int16_t dig_H4; // signed 12-bit
    int16_t dig_H5; // signed 12-bit
    int8_t dig_H6;  // signed 8-bit

    // Last error
    Error _lastError = Error::Ok;
};

