/*
BME280 dual I2C/SPI sensor driver declarations.
*/

#pragma once

// Includes and public data types: Include Arduino, Wire, and SPI interfaces; declare result codes, operating mode, oversampling, standby, filter, raw sample, compensated sample, calibration, and self-test limits/results.

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

class BME280 {
public:
    // Public error/result codes
    enum class Error : uint8_t {
        Ok = 0,
        CommError,
        Timeout,
        BadId,
        CalibrationMissing,
        InvalidArgument,
        SelfTestFailed,
        Unknown
    };

    // Oversampling selection (maps to register encodings)
    enum class Oversampling : uint8_t {
        Skipped = 0, // 000
        X1 = 1,      // 001
        X2 = 2,      // 010
        X4 = 3,      // 011
        X8 = 4,      // 100
        X16 = 5      // 101 (and others treated as 16)
    };

    // Mode selection
    enum class Mode : uint8_t {
        Sleep = 0,
        Forced = 1, // both encodings 01 and 10 should be reported as Forced
        Normal = 3
    };

    // Standby settings (t_sb field encodings)
    enum class StandbyTime : uint8_t {
        T_0p5_ms = 0, // 000
        T_62p5_ms = 1,
        T_125_ms = 2,
        T_250_ms = 3,
        T_500_ms = 4,
        T_1000_ms = 5,
        T_10_ms = 6,
        T_20_ms = 7
    };

    // IIR filter settings
    enum class Filter : uint8_t {
        Off = 0,
        C2 = 1,
        C4 = 2,
        C8 = 3,
        C16 = 4
    };

    // Raw ADC sample parts
    struct RawSample {
        uint32_t pressure;   // 20-bit unsigned (0..0xFFFFF)
        uint32_t temperature; // 20-bit unsigned
        uint16_t humidity;    // 16-bit unsigned
    };

    // Compensated measurement
    struct Measurement {
        float temperature_C; // degrees Celsius
        float pressure_Pa;   // Pascals
        float humidity_pc;   // percent relative humidity (0..100)
    };

    // Calibration storage (decoded)
    struct Calibration {
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
        int16_t  dig_H4; // signed 12-bit extended to int16_t
        int16_t  dig_H5; // signed 12-bit extended to int16_t
        int8_t   dig_H6;
        bool     valid = false;
    };

    // Self-test limits and result types
    struct SelfTestLimits {
        float minTempC;
        float maxTempC;
        float minPressurePa;
        float maxPressurePa;
        float minHumidityPc;
        float maxHumidityPc;
    };

    enum class SelfTestResult : uint8_t {
        Passed = 0,
        CommError,
        BadId,
        CalibrationMissing,
        ClippedRaw,
        ImplausibleMeasurement,
        ResetFailed
    };


    // Construction and initialization API: I2C constructor
    BME280(TwoWire &wire, uint8_t address = 0x76);

    // Construction and initialization API: SPI constructor
    BME280(SPIClass &spi, uint8_t csPin, SPISettings settings = SPISettings(10000000, MSBFIRST, SPI_MODE0));

    // begin: Validate chip ID, wait for im_update clear, load calibration, leave device in sleep
    bool begin(uint32_t timeoutMs = 100);

    // Soft reset and post-reset calibration reload
    bool softReset(uint32_t timeoutMs = 100);

    // Read chip id without side effects
    bool readChipId(uint8_t &chipId);

    // True if readable chip ID equals 0x60
    bool isConnected();

    // Read and decode calibration registers after im_update cleared
    bool readCalibration();

    // Status and configuration API
    bool isMeasuring(bool &measuring);
    bool isUpdating(bool &updating);
    bool waitForMeasurement(uint32_t timeoutMs = 100);

    // Atomically configure humidity, oversampling, standby, filter, mode and spi3w_en with required ordering
    bool configure(Oversampling humidity, Oversampling temperature, Oversampling pressure, StandbyTime standby, Filter filter, Mode mode, bool enable3WireSpi = false);

    // Set only mode bits while preserving osrs fields
    bool setMode(Mode mode);
    bool getMode(Mode &mode);

    // Calculate conservative maximum conversion time in ms from oversampling selections
    float measurementTimeMaxMs(Oversampling humidity, Oversampling temperature, Oversampling pressure);

    // Acquisition and diagnostic API
    bool takeForcedMeasurement(uint32_t timeoutMs = 0);
    bool readRaw(RawSample &raw);
    bool readMeasurements(Measurement &sample);
    SelfTestResult selfTest(const SelfTestLimits &limits);

    // Return the last error
    Error lastError() const { return m_lastError; }

private:
    // Private transport and compensation helpers: transport state and register constants
    enum class InterfaceType { I2C, SPI };

    InterfaceType m_if = InterfaceType::I2C;
    TwoWire *m_wire = nullptr;
    uint8_t m_i2cAddress = 0x76;
    SPIClass *m_spi = nullptr;
    uint8_t m_csPin = 0;
    SPISettings m_spiSettings = SPISettings(10000000, MSBFIRST, SPI_MODE0);

    // Decoded calibration
    Calibration m_calib;

    // t_fine carries intermediate temperature for compensation
    int32_t m_tFine = 0;

    // Last error
    Error m_lastError = Error::Ok;

    // Register constants
    static constexpr uint8_t REG_ID = 0xD0;
    static constexpr uint8_t REG_RESET = 0xE0;
    static constexpr uint8_t REG_CALIB_88 = 0x88;
    static constexpr uint8_t REG_CALIB_E1 = 0xE1;
    static constexpr uint8_t REG_CTRL_HUM = 0xF2;
    static constexpr uint8_t REG_STATUS = 0xF3;
    static constexpr uint8_t REG_CTRL_MEAS = 0xF4;
    static constexpr uint8_t REG_CONFIG = 0xF5;
    static constexpr uint8_t REG_DATA = 0xF7; // burst read start

    // Private transport primitives
    bool readRegisters(uint8_t reg, uint8_t *buffer, size_t length);
    bool writeRegister(uint8_t reg, uint8_t value);

    // Private helpers for compensation
    int32_t compensateTemperatureInt32(int32_t adc_T);
    uint32_t compensatePressureInt64(int32_t adc_P);
    uint32_t compensateHumidityInt32(int32_t adc_H);

    // Utility
    static uint16_t readU16LE(const uint8_t *buf) { return (uint16_t)buf[0] | ((uint16_t)buf[1] << 8); }
    static int16_t readS16LE(const uint8_t *buf) { return (int16_t)(readU16LE(buf)); }

    // Internal register read/write helpers that maintain m_lastError
    bool registerRead(uint8_t reg, uint8_t &value);
    bool registerReadBurst(uint8_t reg, uint8_t *buf, size_t len);
    bool registerWrite(uint8_t reg, uint8_t value);
};

