/*
TMP4719.h - public declarations for TMP4719 Arduino driver.
*/

#pragma once

// Include Guards & Includes: Standard header guards and include <Wire.h>, <Arduino.h> types.
#include <Arduino.h>
#include <Wire.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

// Register Definitions: Define register addresses and bit masks for all registers from the register_map.
// Primary addresses chosen as documented (aliases available for some registers as noted in register map).
#define TMP4719_REG_TEMP_LOCAL               0x00
#define TMP4719_REG_TEMP_REMOTE_CH1_HIGH     0x01
#define TMP4719_REG_STATUS                   0x02
#define TMP4719_REG_CONFIGURATION            0x03
#define TMP4719_REG_CONV_PERIOD              0x04
#define TMP4719_REG_THIGH_LIMIT_LOCAL        0x05
#define TMP4719_REG_TLOW_LIMIT_LOCAL         0x06
#define TMP4719_REG_THIGH_LIMIT_REM_CH1_HIGH 0x07
#define TMP4719_REG_TLOW_LIMIT_REM_CH1_HIGH  0x08
#define TMP4719_REG_CONFIGURATION_ALIAS      0x09
#define TMP4719_REG_CONV_PERIOD_ALIAS        0x0A
#define TMP4719_REG_THIGH_LIMIT_LOCAL_ALIAS  0x0B
#define TMP4719_REG_TLOW_LIMIT_LOCAL_ALIAS   0x0C
#define TMP4719_REG_THIGH_LIMIT_REM_CH1_HIGH_ALIAS 0x0D
#define TMP4719_REG_TLOW_LIMIT_REM_CH1_HIGH_ALIAS  0x0E
#define TMP4719_REG_ONE_SHOT                 0x0F
#define TMP4719_REG_TEMP_REMOTE_CH1_LOW      0x10
#define TMP4719_REG_SCRATCHPAD1              0x11
#define TMP4719_REG_SCRATCHPAD2              0x12
#define TMP4719_REG_THIGH_LIMIT_REM_CH1_LOW  0x13
#define TMP4719_REG_TLOW_LIMIT_REM_CH1_LOW   0x14
#define TMP4719_REG_THIGH_LIMIT_REM_CH2_HIGH 0x15
#define TMP4719_REG_TLOW_LIMIT_REM_CH2_HIGH  0x16
#define TMP4719_REG_THIGH_LIMIT_REM_CH2_LOW  0x17
#define TMP4719_REG_TLOW_LIMIT_REM_CH2_LOW   0x18
#define TMP4719_REG_THIGH_CRIT_REM_CH1       0x19
#define TMP4719_REG_THIGH_CRIT_REM_CH2       0x1A
#define TMP4719_REG_DIODE_FAULT              0x1B
#define TMP4719_REG_ALERT_MASK               0x1F
#define TMP4719_REG_THIGH_CRIT_LOCAL         0x20
#define TMP4719_REG_HYSTERESIS               0x21
#define TMP4719_REG_TEMP_REMOTE_CH2_HIGH     0x23
#define TMP4719_REG_TEMP_REMOTE_CH2_LOW      0x24
#define TMP4719_REG_HIGH_LIMIT_STATUS        0x35
#define TMP4719_REG_LOW_LIMIT_STATUS         0x36
#define TMP4719_REG_TCRIT_LIMIT_STATUS       0x37
#define TMP4719_REG_ETA_FACTOR_CH1           0x27
#define TMP4719_REG_ETA_FACTOR_CH2           0x28
#define TMP4719_REG_FILTER_CONTROL           0x40
#define TMP4719_REG_CHIP_ID                  0xFD
#define TMP4719_REG_VENDOR_ID                0xFE
#define TMP4719_REG_DEVICE_REV_ID            0xFF

// Status bits (Status register 0x02)
#define TMP4719_STATUS_ADC_BUSY_BIT  (1 << 7)
#define TMP4719_STATUS_THIGH_BIT     (1 << 4)
#define TMP4719_STATUS_TLOW_BIT      (1 << 3)
#define TMP4719_STATUS_REMOTE_FAULT  (1 << 2)
#define TMP4719_STATUS_TCRIT_BIT     (1 << 1)

// Configuration bits (0x03)
#define TMP4719_CFG_ALERT_MASK_BIT   (1 << 7)
#define TMP4719_CFG_MODE_SHUTDOWN    (1 << 6)
#define TMP4719_CFG_ALERT_MODE_COMP  (1 << 5) // 0 = interrupt, 1 = comparator

// Diode fault bits (0x1B)
#define TMP4719_DF_SHORT_BIT  (1 << 3)
#define TMP4719_DF_CH2_OPEN   (1 << 2)
#define TMP4719_DF_CH1_OPEN   (1 << 1)

// Enums and Types: Enums for filter levels and conv-period codes; small structs for remote raw result if needed.
// Filter levels for Filter_Control register (bits [1:0])
enum TMP4719_FilterLevel {
  TMP4719_FILTER_OFF = 0,
  TMP4719_FILTER_4_A = 1, // documented as 4-sample (level 1)
  TMP4719_FILTER_4_B = 2, // alternate encoding alias for 4-sample
  TMP4719_FILTER_8   = 3  // 8-sample
};

// Conversion-period codes (Conv_Period[3:0]) -- use these symbolic constants when convenient
enum TMP4719_ConvPeriodCode {
  TMP4719_CONV_16S = 0x0,
  TMP4719_CONV_8S  = 0x1,
  TMP4719_CONV_4S  = 0x2,
  TMP4719_CONV_2S  = 0x3,
  TMP4719_CONV_1S  = 0x4,
  TMP4719_CONV_0_5S = 0x5,
  TMP4719_CONV_0_25S = 0x6, // reset default
  TMP4719_CONV_0_125S = 0x7,
  TMP4719_CONV_0_0625S = 0x8,
  TMP4719_CONV_1S_ALT = 0x9 // codes 0x9..0xF map to 1s per register_map note
};

// Notes:
// - readRegister(reg, nullptr): performs only the pointer-write (beginTransmission(write reg) / endTransmission)
//   and returns true if the pointer-write was ACKed. Use this to detect device presence without performing a
//   read() call.
// - Multi-register 12-bit writes: to minimize transient inconsistent results read/writes should follow a stable
//   order. This driver uses high-byte then low-byte write order when writing 12-bit remote registers to reduce the
//   window where a host may read a mixed new/old value.
// - The int8_t readLocalTemperatureRaw() overload returns INT8_MIN on error and is ambiguous; prefer the
//   bool readLocalTemperatureRaw(int8_t &out) overload that returns explicit success/failure.

// Class Declaration - Public API: Public-facing APIs for initialization, configuration, reads/writes, and conversions.
class TMP4719 {
public:
  // Constructor that sets I²C address (do not start Wire here).
  TMP4719(uint8_t addr = 0x4D);

  // Attach to a TwoWire bus instance and optionally verify device presence. Must NOT call Wire.begin().
  // If wire == nullptr, uses &Wire. If verify==true attempts to read Chip_ID and Vendor_ID.
  bool begin(TwoWire* wire = nullptr, bool verify = true);

  // Set the I2C address used by driver instance.
  void setAddress(uint8_t addr);

  // Low-level single-byte read/write helpers. Behavior:
  // - If value == nullptr: perform only pointer-write (set internal register pointer) and return true on ACK.
  // - If value != nullptr: perform pointer-write then requestFrom() a single byte and store it through value.
  bool readRegister(uint8_t reg, uint8_t* value);
  bool writeRegister(uint8_t reg, uint8_t value);

  // Local temperature helpers
  // New recommended API: unambiguous boolean-style read that returns success and fills out parameter.
  bool    readLocalTemperatureRaw(int8_t &out); // returns true on success, out contains signed 8-bit raw (LSB=1°C)

  // Backward-compatible convenience: returns INT8_MIN on error (ambiguous). Prefer the boolean overload above.
  int8_t  readLocalTemperatureRaw(); // returns INT8_MIN on error

  float   readLocalTemperatureC();   // returns NAN on error
  static int8_t decodeLocalRaw(uint8_t raw); // pure helper: converts raw byte to signed 8-bit temp (LSB=1C)

  // Remote temperature helpers (channel: 1 or 2)
  // Channel validation: pass 1 or 2. Invalid channel returns INT16_MIN or NaN as per API.
  int16_t readRemoteTemperatureRaw(uint8_t channel); // signed 12-bit raw stored in int16_t. Returns INT16_MIN on error
  float   readRemoteTemperatureC(uint8_t channel);   // returns NAN on error or when diode fault detected

  // Status & polling
  int16_t readStatus(); // raw status byte or -1 on I2C error
  bool    isBusy();     // true if ADC_Busy set
  bool    waitForConversion(uint32_t timeout_ms = 200); // poll Status.ADC_Busy until clear or timeout

  // Convenience status accessors
  bool isTHigh();
  bool isTLow();
  bool isTCrit();

  // Per-channel and global status reads
  int16_t readHighLimitStatus(); // 0x35, -1 on error
  int16_t readLowLimitStatus();  // 0x36
  int16_t readTcritStatus();     // 0x37
  int16_t readDiodeFault();      // 0x1B

  // Scratchpad access
  int16_t readScratchpad1(); // 0x11
  bool    writeScratchpad1(uint8_t value);
  int16_t readScratchpad2(); // 0x12
  bool    writeScratchpad2(uint8_t value);

  // Identification
  int16_t readChipID();   // 0xFD
  int16_t readVendorID(); // 0xFE
  int16_t readDeviceRevID(); // 0xFF

  // Configuration read/write
  int16_t readConfiguration(); // primary address 0x03
  bool    writeConfiguration(uint8_t value);

  // Mode convenience
  bool setModeShutdown(bool shutdown); // set Mode bit (true=Shutdown)
  bool getModeIsShutdown();

  // Conv period
  // Writes lower nibble while preserving upper nibble. Note: codes 0x9..0xF map to 1s per datasheet note.
  bool    setConvPeriodCode(uint8_t code); // write lower nibble
  int16_t getConvPeriodCode(); // returns 0..15 or -1 on error

  // Filter control
  // Performs read-modify-write: preserves upper reserved bits and updates Filter_Control[1:0]
  bool    setFilterLevel(uint8_t level); // 0..3
  int16_t getFilterLevel(); // return 0..3 or -1 on error

  // Hysteresis
  bool    setHysteresis(uint8_t h); // 0..31 (LSB=1C)
  int16_t getHysteresis();

  // Eta-factor
  bool    setEtaFactor(uint8_t channel, uint8_t code); // channel 1 or 2
  int16_t getEtaFactorCode(uint8_t channel); // returns 0..255 or -1 on error

  // Local thresholds
  bool    setLocalTHigh(int8_t value);
  int16_t getLocalTHigh(); // returns signed value or INT16_MIN on error
  bool    setLocalTLow(int8_t value);
  int16_t getLocalTLow();

  // Remote thresholds (12-bit split) - high/low for channels
  bool    setRemoteTHigh(uint8_t channel, float temp_c);
  int16_t getRemoteTHighRaw(uint8_t channel);
  bool    setRemoteTLow(uint8_t channel, float temp_c);
  int16_t getRemoteTLowRaw(uint8_t channel);

  // T_CRIT settings
  bool    setTHighCritLocal(int8_t value);
  bool    setTHighCritRemote(uint8_t channel, int8_t value);

  // Alert mask
  int16_t readAlertMask();
  bool    writeAlertMask(uint8_t mask);

  // One-shot
  bool triggerOneShot(uint8_t value = 0x01);

  // Conversion helpers
  static float decodeRemoteRawToFloat(int16_t raw12); // LSB = 0.0625C
  static bool  encodeFloatToRemoteRaw12(float temp_c, uint8_t* high, uint8_t* low); // outputs high byte and low reg (bits7:4)

private:
  // Class - Private: Private members: TwoWire pointer, device address, private helpers for I2C transactions and splitting/combining remote registers.
  TwoWire* _wire;
  uint8_t _addr;

  // Private helpers
  bool readRemoteParts(uint8_t high_reg, uint8_t low_reg, uint8_t* high, uint8_t* low);
  int16_t combineSigned12(uint8_t high, uint8_t low_nibble);
  uint16_t saturateSigned12(int32_t val);
};

