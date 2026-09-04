/*
Public driver header declaring the MLX90382 class, register constants and public APIs.
*/

#pragma once

// Includes and macros: Include <SPI.h>, standard types, include-guard and version macro. Do NOT call SPI.begin() here.
#include <Arduino.h>
#include <SPI.h>
#include <stdint.h>
#include <stddef.h>

#define MLX90382_DRIVER_VERSION "0.1"

// Error codes for readRegister16
static const int MLX90382_OK = 0;
static const int MLX90382_ERR_SPI = -1;
static const int MLX90382_ERR_TIMEOUT = -2;

// Register address constants: Const uint16_t register address defines for registers from the provided register_maps (use the provided hex addresses).
// Addresses sourced from register_maps.
constexpr uint16_t MLX90382_DE_SR = 0x0BE;
constexpr uint16_t MLX90382_NVOP_KEY = 0x010;
constexpr uint16_t MLX90382_IN_APPLICATION = 0x024;
constexpr uint16_t MLX90382_CRC = 0x026;
constexpr uint16_t MLX90382_CRC_CALC_STRT = 0x028;
constexpr uint16_t MLX90382_STATE = 0x02C;
constexpr uint16_t MLX90382_AGC_GAIN = 0x034;
constexpr uint16_t MLX90382_AGC_AMP = 0x036;
constexpr uint16_t MLX90382_TEMP = 0x038;
constexpr uint16_t MLX90382_LIN_PHASE = 0x03A;
constexpr uint16_t MLX90382_SPEED = 0x03C;
constexpr uint16_t MLX90382_DRIFTC_PHASE = 0x042;
constexpr uint16_t MLX90382_SC_PHASE = 0x044;
constexpr uint16_t MLX90382_GC_I = 0x048;
constexpr uint16_t MLX90382_GC_Q = 0x04E;
constexpr uint16_t MLX90382_RMM_ASIQ = 0x062;
constexpr uint16_t MLX90382_RMM_ASQQ = 0x064;
constexpr uint16_t MLX90382_PWM_PCNT = 0x10A;
constexpr uint16_t MLX90382_SENSING_MODE = 0x200;
constexpr uint16_t MLX90382_ABI_CFG = 0x202;
constexpr uint16_t MLX90382_ABI_LOG2N = 0x204;
constexpr uint16_t MLX90382_PWM_INV = 0x206;
constexpr uint16_t MLX90382_PWM_PERIOD = 0x22E;
constexpr uint16_t MLX90382_PWM_DC_OFS = 0x248;
constexpr uint16_t MLX90382_SPI_FADDR0 = 0x230;
constexpr uint16_t MLX90382_SPI_FADDR2 = 0x232;
constexpr uint16_t MLX90382_SPI_FRFS = 0x234;
constexpr uint16_t MLX90382_SPI_SFRL = 0x236;
constexpr uint16_t MLX90382_SPI_CPTLT = 0x238;
constexpr uint16_t MLX90382_SSI_PARPOS = 0x23A;
constexpr uint16_t MLX90382_PHY_RC_EN = 0x23C;
constexpr uint16_t MLX90382_USER_ID0 = 0x23E;
constexpr uint16_t MLX90382_USER_ID2 = 0x240;
constexpr uint16_t MLX90382_USER_ID4 = 0x242;
constexpr uint16_t MLX90382_PH_OFFS = 0x220; // alias PHASE_OFS
constexpr uint16_t MLX90382_PHASE_OFS = 0x220;
constexpr uint16_t MLX90382_SC_X1 = 0x222;
constexpr uint16_t MLX90382_SC_X2 = 0x224;
constexpr uint16_t MLX90382_SC_Y1 = 0x226;
constexpr uint16_t MLX90382_SC_Y2 = 0x228;
constexpr uint16_t MLX90382_SC_YE = 0x22A;
constexpr uint16_t MLX90382_SC_HL = 0x22C;
constexpr uint16_t MLX90382_DELAY_CUS = 0x244;
constexpr uint16_t MLX90382_DSP_IQNEG = 0x246;
constexpr uint16_t MLX90382_RMM_FAST = 0x256;
constexpr uint16_t MLX90382_RMM_ASQQ_MIN = 0x258;
constexpr uint16_t MLX90382_DE_OV_VDD = 0x25A; // DE_* group base
constexpr uint16_t MLX90382_DE_DSP_RMM = 0x25C;
constexpr uint16_t MLX90382_CUS_CRC = 0x25E;
constexpr uint16_t MLX90382_AGC_GAIN_MINMAX = 0x208; // AGC_GAIN_MIN and MAX in this word
constexpr uint16_t MLX90382_PEQ_GAIN = 0x20A;
constexpr uint16_t MLX90382_PEQ00 = 0x20C; // PEQ00..PEQ15 occupy 0x20C .. 0x21A
constexpr uint16_t MLX90382_PEQ02 = 0x20E;
constexpr uint16_t MLX90382_PEQ04 = 0x210;
constexpr uint16_t MLX90382_PEQ06 = 0x212;
constexpr uint16_t MLX90382_PEQ08 = 0x214;
constexpr uint16_t MLX90382_PEQ10 = 0x216;
constexpr uint16_t MLX90382_PEQ12 = 0x218;
constexpr uint16_t MLX90382_PEQ14 = 0x21A;
constexpr uint16_t MLX90382_S_IQ = 0x21C;
constexpr uint16_t MLX90382_S_QQ = 0x21E;
constexpr uint16_t MLX90382_DIAG_TEMP_THD_LO = 0x24A;
constexpr uint16_t MLX90382_DIAG_TEMP_THD_MAX = 0x24C;
constexpr uint16_t MLX90382_DIAG_SPEED_THD = 0x24E;
constexpr uint16_t MLX90382_DIAG_AGC_THD = 0x252;
constexpr uint16_t MLX90382_NVOP = 0x010; // alias

// Public class declaration: MLX90382 class public API covering high-level device functions and generic register access.
class MLX90382 {
public:
    // MLX90382: Constructor. Does not start SPI or touch device registers.
    /**
     * @brief Construct a new MLX90382 object
     * @param csPin Chip-select GPIO pin (optional). If 255 (default), user must call begin() with csPin.
     */
    explicit MLX90382(uint8_t csPin = 255);

    // begin: Initialize driver internals and store CS pin and SPI settings. Does not call global SPI.begin().
    /**
     * @brief Initialize driver internals and configure CS pin and SPI settings.
     * @param csPin Chip-select pin to use.
     * @param spiClock SPI clock in Hz (default 1MHz).
     * @param spiMode SPI mode (0..3).
     * @return true if initialization parameters accepted and CS configured.
     */
    bool begin(uint8_t csPin, uint32_t spiClock = 1000000, uint8_t spiMode = 0);

    // end: Optional clean-up, releases CS pin state; does not call SPI.end().
    /**
     * @brief Release internal resources and set CS pin to INPUT to reduce power. Does not call SPI.end().
     */
    void end();

    // readRegister16: Read a 16-bit device register by address (generic low-level read).
    /**
     * @brief Read a 16-bit register from the device.
     * @param regAddr 16-bit register address.
     * @param value Pointer to uint16_t to receive data.
     * @return 0 on success, negative error code on failure.
     */
    int readRegister16(uint16_t regAddr, uint16_t* value);

    // writeRegister16: Write a 16-bit device register by address (generic low-level write).
    /**
     * @brief Write a 16-bit register to the device.
     * @param regAddr 16-bit register address.
     * @param value Value to write.
     * @return true on success, false on failure.
     */
    bool writeRegister16(uint16_t regAddr, uint16_t value);

    // High-level convenience APIs
    /** @brief Read DRIFTC_PHASE (0x042). Returns signed 16-bit value or negative error code. */
    int32_t readDriftcPhase();

    /** @brief Read LIN_PHASE (0x03A). Returns unsigned 16-bit value or negative error code. */
    int32_t readLinPhase();

    /** @brief Read SC_PHASE (0x044). Returns unsigned 16-bit value or negative error code. */
    int32_t readSCPhase();

    /** @brief Read SPEED raw signed register (0x03C). Returns signed 16-bit or negative error code. */
    int32_t readSpeed();

    /** @brief Read raw TEMP register (0x038). Returns raw value or negative error code. */
    int32_t readTempRaw();

    /** @brief Read temperature and convert to degrees Celsius: T[°C] = TEMP/8 + 200[K] - 273.15. Returns NaN on read error. */
    float readTemperatureC();

    /** @brief Read AGC_GAIN (0x034). Returns raw gain or negative error code. */
    int readAGCGain();

    /** @brief Read AGC_AMP (0x036). Returns raw amplitude or negative error code. */
    int readAGCAmp();

    /** @brief Set AGC min/max (packed into 0x208). minGain,maxGain in 0..63. Returns true if write succeeded. */
    bool setAGCGainLimits(uint8_t minGain, uint8_t maxGain);

    /** @brief Read GC_I (0x048). Returns raw 16-bit value or negative error. */
    int32_t readGC_I();

    /** @brief Read GC_Q (0x04E). Optionally wait for averaging to complete if wait_ms>0. Returns raw 16-bit value or negative error. */
    int32_t readGC_Q(uint32_t wait_ms = 0);

    /** @brief Wait for GC averaging; default timeout 200 ms if wait_ms==0. Best-effort polling. */
    bool waitForGCAverage(uint32_t wait_ms = 200);

    /** @brief Read RMM_ASIQ (0x062). Returns raw value or negative error. */
    int32_t readRMM_ASIQ();

    /** @brief Read RMM_ASQQ (0x064). Returns raw value or negative error. */
    int32_t readRMM_ASQQ();

    /** @brief Set PEQ_GAIN (0x20A). gain 0..7. Returns true on success. */
    bool setPEQGain(uint8_t gain);

    /** @brief Set a single PEQxx equalization byte value. index 0..15. Returns true on success. */
    bool setPEQValue(uint8_t index, int8_t value);

    /** @brief Set DELAY_CUS (0x244). value 0..255. Units: steps of (26/64)/fRCO. Returns true on success. */
    bool setDelayCus(uint8_t value);

    /** @brief Start internal NVM CRC calculation by writing CRC_CALC_STRT (0x028). Returns true if start command was written. */
    bool startNVMCRC();

    /** @brief Wait for NVM CRC completion. timeout_ms==0 -> default 1000 ms. Returns true if done before timeout. */
    bool waitForNVMCRCDone(uint32_t timeout_ms = 1000);

    /** @brief Read CRC (0x026). Returns 16-bit CRC or negative error code. */
    int32_t readCRC();

    /** @brief Read STATE (0x02C). Returns register value or negative error code. */
    int readState();

    /** @brief Generic DE_* bit write helper (safety-affecting). Caller must ensure safety impact. */
    bool setDEBits(uint16_t regAddr, uint16_t mask, uint16_t value);

    /** @brief Read USER_ID words. index 0..2 maps to USER_ID0..USER_ID4. Returns 16-bit word or negative error code. */
    int32_t readUserID(uint8_t index);

    /** @brief Read CUS_CRC (0x25E). Returns CRC or negative error code. */
    int32_t readCUS_CRC();

    /** @brief Configure SPI Frame Read related registers. faddr may be NULL to skip writing addresses. frfs 0..15 or 0xFF leave unchanged. enableCRC sets SPI_FRCRCEN in 0x234. spiMode 0..3 or 0xFF leave unchanged. */
    bool configureSPIFrameRead(const uint8_t* faddr, uint8_t frfs = 0xFF, bool enableCRC = false, uint8_t spiMode = 0xFF);

    /** @brief Raw burst transfer helper. tx or rx may be NULL. len bytes transferred. Returns true on success. */
    bool rawReadWriteBurst(const uint8_t* tx, uint8_t* rx, size_t len);

private:
    // Private helpers & fields: Private spiRead/spiWrite helpers, SPISettings storage, CS pin, and small utility helpers (pack/unpack 16-bit registers, timeouts).
    /**
     * @brief Private SPI read of a 16-bit register. Returns true on success.
     * @param regAddr register address
     * @param out pointer to uint16_t to receive the read value
     */
    bool spiReadRegister16(uint16_t regAddr, uint16_t* out);

    /**
     * @brief Private SPI write of a 16-bit register. Returns true on success.
     * @param regAddr register address
     * @param value value to write
     */
    bool spiWriteRegister16(uint16_t regAddr, uint16_t value);

    uint8_t _csPin;
    SPISettings _spiSettings;
    bool _configured;
};

