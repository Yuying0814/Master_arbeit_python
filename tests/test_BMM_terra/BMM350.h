/*
Public BMM350 Arduino I2C driver API.
*/

#pragma once

// Includes, constants, and public types: Public declarations, constants and types for BMM350 driver
#include <Arduino.h>
#include <Wire.h>

// Device I2C legacy addresses (ADSEL low = 0x14, high = 0x15)
static constexpr uint8_t BMM350_I2C_ADDR_DEFAULT = 0x14;

// Register addresses (from provided register map)
namespace BMM350Reg {
    static constexpr uint8_t CHIP_ID = 0x00;
    static constexpr uint8_t ERR_REG = 0x02;
    static constexpr uint8_t PAD_CTRL = 0x03;
    static constexpr uint8_t PMU_CMD_AGGR_SET = 0x04;
    static constexpr uint8_t PMU_CMD_AXIS_EN = 0x05; // write-only
    static constexpr uint8_t PMU_CMD = 0x06;
    static constexpr uint8_t PMU_CMD_STATUS_0 = 0x07;
    static constexpr uint8_t PMU_CMD_STATUS_1 = 0x08;
    static constexpr uint8_t I3C_ERR = 0x09;
    static constexpr uint8_t I2C_WDT_SET = 0x0A;
    static constexpr uint8_t TRANS_DUCER_REV_ID = 0x0D;

    static constexpr uint8_t INT_CTRL = 0x2E;
    static constexpr uint8_t INT_CTRL_IBI = 0x2F;
    static constexpr uint8_t INT_STATUS = 0x30;

    static constexpr uint8_t MAG_X_XLSB = 0x31; // block 0x31..0x3F
    static constexpr uint8_t MAG_BLOCK_END = 0x3F;

    static constexpr uint8_t OTP_CMD_REG = 0x50;
    static constexpr uint8_t OTP_DATA_MSB_REG = 0x52;
    static constexpr uint8_t OTP_DATA_LSB_REG = 0x53;
    static constexpr uint8_t OTP_STATUS_REG = 0x55;

    static constexpr uint8_t TMR_SELFTEST_USER = 0x60;
    static constexpr uint8_t CTRL_USER = 0x61;

    static constexpr uint8_t CMD = 0x7E; // write-only command register
}

// Public Status enum: all fallible operations return this
enum class Status : uint8_t {
    Ok = 0,
    BusError,        // Wire transfer failure
    Timeout,         // timed out while waiting for busy clear / boot
    InvalidArgument, // invalid parameter
    ChipIdMismatch,  // unexpected chip id
    PmuBusy,         // PMU busy not clearing
    PmuIllegal,      // PMU returned illegal command
    ErrRegSet,       // ERR_REG indicates error
    Unknown          // other unspecified error
};

// Output data structures and small enums
enum class Odr : uint8_t {
    ODR_400HZ = 0x02,
    ODR_200HZ = 0x03,
    ODR_100HZ = 0x04,
    ODR_50HZ  = 0x05,
    ODR_25HZ  = 0x06,
    ODR_12_5HZ = 0x07,
    ODR_6_25HZ = 0x08,
    ODR_3_125HZ = 0x09,
    ODR_1_5625HZ = 0x0A
};

enum class Averaging : uint8_t {
    AVG_0 = 0x00,
    AVG_2 = 0x01,
    AVG_4 = 0x02,
    AVG_8 = 0x03
};

enum class PmuCommand : uint8_t {
    Suspend = 0x00,
    Normal  = 0x01,
    UpdOae  = 0x02,
    FM      = 0x03,
    FMFast  = 0x04,
    FluxGuideReset = 0x05,
    FluxGuideResetFast = 0x06,
    BitReset = 0x07,
    BitResetFast = 0x08
};

// Raw 24-bit sample container. Values are signed 24-bit for X/Y/Z and temperature; sensortime is unsigned 24-bit
struct RawSample {
    int32_t x; // signed 24
    int32_t y; // signed 24
    int32_t z; // signed 24
    int32_t temperature; // signed 24
    uint32_t sensortime; // unsigned 24
};

// Self test result: baseline, stimulated and delta (raw 24 values). Only axis requested will have meaningful delta
struct SelfTestResult {
    RawSample baseline;
    RawSample stimulated;
    RawSample delta; // stimulated - baseline (signed)
};

// Interrupt configuration for INT_CTRL register
struct InterruptConfig {
    bool drdy_data_reg_en = false;
    bool int_output_en = false; // may be reserved on some parts
    bool int_od = false; // 0=open-drain, 1=push-pull
    bool int_pol = false; // 0=active low, 1=active high
    bool int_mode = false; // 0=pulsed, 1=latched
};

// Public API: Construction and bootstrap
class BMM350 {
public:
    // Construction and bootstrap: construct driver with a caller-owned TwoWire instance
    // Caller owns Wire and is responsible for calling Wire.begin()
    BMM350(TwoWire &wire = Wire, uint8_t address = BMM350_I2C_ADDR_DEFAULT);

    // begin: verify CHIP_ID 0x33, wait for OTP command-ready/no-error, write OTP_CMD_REG 0x80 to terminate OTP access,
    // perform a flux-guide reset to charge CRST and leave device suspended. Does not call Wire.begin().
    Status begin(uint16_t timeoutMs = 10);

    // softReset: write documented 0xB6 then 0x00 sequence to CMD and wait for CHIP_ID to reappear
    Status softReset(uint16_t timeoutMs = 10);

    // Read chip ID and transducer revision
    Status chipId(uint8_t &value);
    Status transducerRevision(uint8_t &value);

    // PMU configuration and operations
    Status setOdrAveraging(Odr odr, Averaging averaging, uint16_t timeoutMs = 10);
    Status getEffectiveOdrAveraging(Odr &odr, Averaging &averaging);
    Status setPowerMode(PmuCommand command, uint16_t timeoutMs = 10);
    Status triggerForcedMeasurement(bool fast = false, uint16_t timeoutMs = 30);
    Status magneticReset(PmuCommand command = PmuCommand::FluxGuideReset, uint16_t timeoutMs = 10);
    Status setAxes(bool x, bool y, bool z, uint16_t timeoutMs = 10);

    // Data, interrupt, self-test, and interface configuration
    Status readRawSample(RawSample &sample);
    Status dataReady(bool &ready);
    Status configureInterrupt(const InterruptConfig &config);
    Status configureIbi(bool mapDataReady, bool clearOnIbi);
    Status setPadDrive(uint8_t drive);
    Status setI2cWatchdog(bool enabled, bool longTimeout);
    Status setSensorTimeAlwaysOn(bool enabled, uint16_t timeoutMs = 10);
    Status runSelfTest(uint8_t axis /*1: X, 2: Y*/, SelfTestResult &result, uint16_t timeoutMs = 30);
    Status readAndClearError(bool &pmuCommandError);
    Status readI3cError(uint8_t &flags);

private:
    // Private transport and sequencing: low-level register read/write utilities (dummy-byte-aware reads)
    Status readRegisters(uint8_t reg, uint8_t *buffer, size_t length);
    Status readRegister8(uint8_t reg, uint8_t &value);
    Status writeRegister8(uint8_t reg, uint8_t value);
    Status writeRegisters(uint8_t reg, const uint8_t *data, size_t length);

    // Helpers
    Status pollPmuBusyClear(uint16_t timeoutMs);
    // ensureSuspended: explicitly wait for idle, issue SUS, wait for busy clear and validate suspend state
    Status ensureSuspended(uint16_t timeoutMs);

    // New private helpers requested by verifier
    // waitForDataReady: poll read-to-clear INT_STATUS DRDY bit until observed or timeout
    Status waitForDataReady(uint16_t timeoutMs);
    // checkPmuCommandResult: after PMU command completion, verify illegal-bit and ERR_REG PMU error
    Status checkPmuCommandResult();

    int32_t decodeSigned24(const uint8_t *b);

    TwoWire &wire_;
    uint8_t address_;
};

