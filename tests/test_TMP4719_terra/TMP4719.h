/*
Wire-based TMP4719 public API, data types, and documented constants.
*/

#pragma once

// Includes and class constants: Include Arduino and Wire interfaces; declare address, register addresses, field masks, and supported ranges/codes.
#include <Arduino.h>
#include <Wire.h>

class TMP4719 {
public:
  // Public register addresses (primary addresses and common aliases). These are provided for advanced reference.
  static const uint8_t I2C_DEFAULT_ADDRESS = 0x4D; // 7-bit

  // Data registers
  static const uint8_t REG_TEMP_LOCAL = 0x00;
  static const uint8_t REG_TEMP_REMOTE_CH1_HIGH = 0x01;
  static const uint8_t REG_TEMP_REMOTE_CH1_LOW = 0x10;
  static const uint8_t REG_STATUS = 0x02;

  // Configuration/registers (primary and alias)
  static const uint8_t REG_CONFIGURATION = 0x03; // alias 0x09
  static const uint8_t REG_CONV_PERIOD = 0x04;   // alias 0x0A

  // Local thresholds
  static const uint8_t REG_THIGH_LOCAL = 0x05; // alias 0x0B
  static const uint8_t REG_TLOW_LOCAL  = 0x06; // alias 0x0C

  // Remote channel 1 thresholds (high/low bytes)
  static const uint8_t REG_THIGH_REMOTE_CH1_HIGH = 0x07; // alias 0x0D
  static const uint8_t REG_TLOW_REMOTE_CH1_HIGH  = 0x08; // alias 0x0E
  static const uint8_t REG_THIGH_REMOTE_CH1_LOW  = 0x13;
  static const uint8_t REG_TLOW_REMOTE_CH1_LOW   = 0x14;

  // One-shot
  static const uint8_t REG_ONE_SHOT = 0x0F;

  // Scratchpads
  static const uint8_t REG_SCRATCHPAD1 = 0x11;
  static const uint8_t REG_SCRATCHPAD2 = 0x12;

  // Remote channel 2 thresholds
  static const uint8_t REG_THIGH_REMOTE_CH2_HIGH = 0x15;
  static const uint8_t REG_THIGH_REMOTE_CH2_LOW  = 0x17;
  static const uint8_t REG_TLOW_REMOTE_CH2_HIGH  = 0x16;
  static const uint8_t REG_TLOW_REMOTE_CH2_LOW   = 0x18;

  // Critical limits
  static const uint8_t REG_THIGH_CRIT_REMOTE_CH1 = 0x19;
  static const uint8_t REG_THIGH_CRIT_REMOTE_CH2 = 0x1A;
  static const uint8_t REG_THIGH_CRIT_LOCAL      = 0x20;

  // Diode fault, per-channel mask, status
  static const uint8_t REG_DIODE_FAULT = 0x1B;
  static const uint8_t REG_ALERT_MASK  = 0x1F; // per-channel mask

  // Hysteresis
  static const uint8_t REG_HYSTERESIS = 0x21; // bits 4:0

  // Remote results channel 2
  static const uint8_t REG_TEMP_REMOTE_CH2_HIGH = 0x23;
  static const uint8_t REG_TEMP_REMOTE_CH2_LOW  = 0x24;

  // Ideality factors
  static const uint8_t REG_ETA_CH1 = 0x27;
  static const uint8_t REG_ETA_CH2 = 0x28;

  // Per-channel status registers (read side-effects documented in source)
  static const uint8_t REG_HIGH_LIMIT_STATUS = 0x35;
  static const uint8_t REG_LOW_LIMIT_STATUS  = 0x36;
  static const uint8_t REG_TCRIT_LIMIT_STATUS = 0x37;

  // Filter control
  static const uint8_t REG_FILTER_CONTROL = 0x40; // bits [1:0]

  // Identification
  static const uint8_t REG_CHIP_ID = 0xFD;
  static const uint8_t REG_VENDOR_ID = 0xFE;
  static const uint8_t REG_DEVICE_REV = 0xFF;

  // Bit masks
  static const uint8_t STATUS_ADC_BUSY_MASK = (1 << 7);
  static const uint8_t STATUS_THIGH_MASK    = (1 << 4);
  static const uint8_t STATUS_TLOW_MASK     = (1 << 3);
  static const uint8_t STATUS_REMOTE_FAULT_MASK = (1 << 2);
  static const uint8_t STATUS_TCRIT_MASK    = (1 << 1);

  static const uint8_t CONFIG_ALERT_MASK_BIT = (1 << 7);
  static const uint8_t CONFIG_MODE_BIT       = (1 << 6);
  static const uint8_t CONFIG_ALERT_MODE_BIT = (1 << 5);

  // Conversion helpers
  static constexpr float REMOTE_LSB_C = 0.0625f; // 1/16 C LSB for 12-bit remote values

  // Public types and lifecycle: Declare channel, operating-mode, alert-mode, filter-level, and status snapshot structures plus construction and initialization APIs.
  enum class RemoteChannel : uint8_t { CH1 = 1, CH2 = 2 };
  enum class TemperatureChannel : uint8_t { LOCAL = 0, REMOTE1 = 1, REMOTE2 = 2 };
  enum class OperatingMode : uint8_t { CONTINUOUS = 0, SHUTDOWN = 1 };
  enum class AlertMode : uint8_t { INTERRUPT = 0, COMPARATOR = 1 };
  enum class FilterLevel : uint8_t { DISABLED = 0, FOUR = 1, EIGHT = 3 };

  struct StatusFlags {
    bool adcBusy;
    bool anyHigh;
    bool anyLow;
    bool remoteFault;
    bool anyTCrit;
  };

  // Construct a driver using a caller-owned TwoWire bus and optional 7-bit address.
  TMP4719(TwoWire &wire = Wire, uint8_t address = I2C_DEFAULT_ADDRESS);

  // Verify bus communication and expected immutable chip/vendor IDs without changing configuration.
  bool begin();

  // Temperature and conversion control
  bool readLocalTemperature(int8_t &temperatureC);
  bool readRemoteTemperature(RemoteChannel channel, float &temperatureC);
  bool isAdcBusy(bool &busy);
  bool setOperatingMode(OperatingMode mode);
  bool getOperatingMode(OperatingMode &mode);
  bool triggerOneShot();
  bool setConversionPeriodCode(uint8_t code);
  bool getConversionPeriodCode(uint8_t &code);

  // Threshold and alert configuration
  bool setAlertLimits(TemperatureChannel channel, float highC, float lowC);
  bool getAlertLimits(TemperatureChannel channel, float &highC, float &lowC);
  bool setCriticalLimit(TemperatureChannel channel, int8_t temperatureC);
  bool getCriticalLimit(TemperatureChannel channel, int8_t &temperatureC);
  bool setHysteresis(uint8_t degreesC);
  bool getHysteresis(uint8_t &degreesC);
  bool setAlertMode(AlertMode mode);
  bool setGlobalAlertMasked(bool masked);
  bool setChannelAlertMasked(TemperatureChannel channel, bool masked);

  // Status, calibration, storage, and identification
  bool readStatus(StatusFlags &status);
  bool readLimitStatus(uint8_t &highFlags, uint8_t &lowFlags, uint8_t &criticalFlags);
  bool readDiodeFaults(uint8_t &faultFlags);
  bool setFilterLevel(FilterLevel level);
  bool setIdealityCode(RemoteChannel channel, uint8_t code);
  bool getIdealityCode(RemoteChannel channel, uint8_t &code);
  bool writeScratchpad(uint8_t index, uint8_t value);
  bool readScratchpad(uint8_t index, uint8_t &value);
  bool readDeviceId(uint8_t &chipId, uint8_t &vendorId, uint8_t &deviceId, uint8_t &revisionId);

private:
  // Private I2C and conversion helpers: Declare single-byte transactions, field/register conversions, and register selectors as private implementation details.
  TwoWire *wire_;
  uint8_t address_;

  bool readRegister(uint8_t reg, uint8_t &value);
  bool writeRegister(uint8_t reg, uint8_t value);

  // Helper to read remote 12-bit raw value (signed) for a channel
  bool readRemoteRaw12(RemoteChannel channel, int16_t &raw12);

  // Helpers to select remote registers for thresholds and results
  uint8_t remoteHighReg(RemoteChannel ch) const;
  uint8_t remoteLowReg(RemoteChannel ch) const;
  uint8_t remoteHighLimitReg(RemoteChannel ch) const;
  uint8_t remoteLowLimitReg(RemoteChannel ch) const;
  uint8_t remoteCritReg(RemoteChannel ch) const;
  uint8_t etaReg(RemoteChannel ch) const;
};

