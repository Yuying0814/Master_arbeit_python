/*
Public driver header: class TMP4719, register definitions, public API declarations and brief docs.
*/

#pragma once

// Include guards and includes: Provide public API and register definitions. Include Wire.h so
// the header can use a safe default TwoWire& = Wire parameter.
#include <Arduino.h>
#include <Wire.h>

// Register definitions (addresses and documented reset/default values from register_maps)
// Register definitions: leave addresses and defaults unchanged.
namespace TMP4719Regs {
  static constexpr uint8_t REG_TEMP_LOCAL = 0x00;              // reset 0x00 (R)
  static constexpr uint8_t REG_TEMP_REMOTE_CH1_HIGH = 0x01;    // reset 0x00 (R)
  static constexpr uint8_t REG_STATUS = 0x02;                  // reset 0x00 (R)
  static constexpr uint8_t REG_CONFIGURATION = 0x03;           // reset 0x00 (R/W)
  static constexpr uint8_t REG_CONV_PERIOD = 0x04;             // reset 0x06 (R/W)
  static constexpr uint8_t REG_THIGH_LOCAL = 0x05;            // reset 0x55 (R/W)
  static constexpr uint8_t REG_TLOW_LOCAL = 0x06;             // reset 0x00 (R/W)
  static constexpr uint8_t REG_THIGH_REMOTE_CH1_HIGH = 0x07;  // reset 0x55 (R/W)
  static constexpr uint8_t REG_TLOW_REMOTE_CH1_HIGH = 0x08;   // reset 0x00 (R/W)
  static constexpr uint8_t REG_ONE_SHOT = 0x0F;               // write-only (W)
  static constexpr uint8_t REG_TEMP_REMOTE_CH1_LOW = 0x10;    // reset 0x00 (R)
  static constexpr uint8_t REG_SCRATCHPAD1 = 0x11;            // reset 0x00 (R/W)
  static constexpr uint8_t REG_SCRATCHPAD2 = 0x12;            // reset 0x00 (R/W)
  static constexpr uint8_t REG_THIGH_REMOTE_CH1_LOW = 0x13;   // reset 0x00 (R/W)
  static constexpr uint8_t REG_TLOW_REMOTE_CH1_LOW = 0x14;    // reset 0x00 (R/W)
  static constexpr uint8_t REG_THIGH_REMOTE_CH2_HIGH = 0x15;  // reset 0x55 (R/W)
  static constexpr uint8_t REG_TLOW_REMOTE_CH2_HIGH = 0x16;   // reset 0x00 (R/W)
  static constexpr uint8_t REG_THIGH_REMOTE_CH2_LOW = 0x17;   // reset 0x00 (R/W)
  static constexpr uint8_t REG_TLOW_REMOTE_CH2_LOW = 0x18;    // reset 0x00 (R/W)
  static constexpr uint8_t REG_THIGH_CRIT_REMOTE_CH1 = 0x19;  // reset 0x55 (R/W)
  static constexpr uint8_t REG_THIGH_CRIT_REMOTE_CH2 = 0x1A;  // reset 0x55 (R/W)
  static constexpr uint8_t REG_DIODE_FAULT = 0x1B;            // reset 0x00 (R)
  static constexpr uint8_t REG_ALERT_MASK = 0x1F;             // reset 0x00 (R/W)
  static constexpr uint8_t REG_THIGH_CRIT_LOCAL = 0x20;      // reset 0x55 (R/W)
  static constexpr uint8_t REG_HYSTERESIS = 0x21;            // reset 0x0A (R/W)
  static constexpr uint8_t REG_TEMP_REMOTE_CH2_HIGH = 0x23;  // reset 0x00 (R)
  static constexpr uint8_t REG_TEMP_REMOTE_CH2_LOW = 0x24;   // reset 0x00 (R)
  static constexpr uint8_t REG_ETA_FACTOR_CH1 = 0x27;        // reset 0x12 (R/W)
  static constexpr uint8_t REG_ETA_FACTOR_CH2 = 0x28;        // reset 0x12 (R/W)
  static constexpr uint8_t REG_HIGH_LIMIT_STATUS = 0x35;     // reset 0x00 (R)
  static constexpr uint8_t REG_LOW_LIMIT_STATUS = 0x36;      // reset 0x00 (R)
  static constexpr uint8_t REG_TCRIT_LIMIT_STATUS = 0x37;    // reset 0x00 (R)
  static constexpr uint8_t REG_FILTER_CONTROL = 0x40;        // reset 0x00 (R/W)
  static constexpr uint8_t REG_CHIP_ID = 0xFD;               // reset 0x21 (R)
  static constexpr uint8_t REG_VENDOR_ID = 0xFE;             // reset 0x60 (R)
  static constexpr uint8_t REG_DEVICE_REV_ID = 0xFF;         // reset 0xA0 (R)
}

// Class-level comment update: Add required documentation warning about read-only registers.
/**
 * TMP4719 I2C/SMBus driver
 *
 * Usage notes:
 *  - Call Wire.begin() in the Arduino sketch before calling begin() on this class.
 *  - begin(address, wire) stores device address and TwoWire instance; it does not call Wire.begin().
 *  - The low-level single-byte write helper is private and should not be used by application code.
 *
 * Important: Do not write to registers documented as read-only in the device register map. The low-level single-byte write helper writeRegister8() is private; application code must not call it. Use only the driver's public high-level write APIs to modify device state (for example: writeConfiguration, writeAlertMask, writeHighLimitLocal, writeEtaFactorCh1, writeEtaFactorCh2, setConversionPeriod, startOneShot).
 */
class TMP4719 {
public:
  // Public API - class TMP4719 declaration: Default constructor and primary public methods
  /**
   * Default constructor. Does not start any bus activity.
   */
  TMP4719();

  /**
   * begin - initialize driver instance
   * @param address 7-bit I2C/SMBus slave address of the TMP4719 (e.g. 0x4D)
   * @param wire TwoWire instance to use (default: Wire)
   * @return true if initialization parameters stored; does not guarantee device presence
   * @note Wire.begin() must be called by the sketch before using the device.
   */
  bool begin(uint8_t address, TwoWire &wire = Wire);

  /**
   * isConnected - quick check whether device responds on the bus.
   * @param strict when true (default) require Chip_ID==0x21; when false accept any successful
   *               read of an identification or innocuous register as connectivity.
   * @return true if device presence is detected per mode.
   */
  bool isConnected(bool strict = true);

  /**
   * Low-level 8-bit register read
   * @param reg register address
   * @param value out parameter receiving the register value
   * @return true on successful read
   */
  bool readRegister8(uint8_t reg, uint8_t &value);

  /**
   * Read raw local temperature (8-bit two's complement, LSB = 1°C)
   * @param raw out signed 8-bit raw reading
   * @return true on success
   */
  bool readLocalRaw(int8_t &raw);

  /**
   * Read local temperature converted to degrees Celsius (float)
   * @param celsius out temperature in °C
   * @return true on success
   */
  bool readLocalTemperatureC(float &celsius);

  /** Read raw 12-bit remote channel 1 value (signed)
   *  - High byte at 0x01 (bits 11:4)
   *  - Low nibble at 0x10 (bits 7:4 => bits 3:0)
   *  @param raw12 out signed 12-bit value (in a signed int16_t)
   *  @return true on success
   */
  bool readRemoteRawCh1(int16_t &raw12);

  /** Read remote channel 1 temperature converted to °C (LSB = 0.0625°C)
   *  @param celsius out temperature in °C
   *  @return true on success
   */
  bool readRemoteTemperatureCCh1(float &celsius);

  /** Read raw 12-bit remote channel 2 value (signed)
   *  - High byte at 0x23 (bits 11:4)
   *  - Low nibble at 0x24 (bits 7:4 => bits 3:0)
   *  @param raw12 out signed 12-bit value (in a signed int16_t)
   *  @return true on success
   */
  bool readRemoteRawCh2(int16_t &raw12);

  /** Read remote channel 2 temperature converted to °C (LSB = 0.0625°C)
   *  @param celsius out temperature in °C
   *  @return true on success
   */
  bool readRemoteTemperatureCCh2(float &celsius);

  /** Read Status register (0x02)
   *  Note: reading Status may clear limit flags in SMBus Alert (interrupt) mode per datasheet.
   */
  bool readStatus(uint8_t &status);

  /** Identification helpers */
  bool readChipID(uint8_t &id);
  bool readVendorID(uint8_t &id);
  bool readDeviceRevID(uint8_t &rev);

  /** One-shot trigger. Writing any value triggers a one-shot conversion.
   *  Effective only in Shutdown mode.
   */
  bool startOneShot();

  /** Set conversion period nibble (lower 4 bits of Conv_Period register)
   *  @param periodNibble lower 4 bits that encode conversion period per datasheet
   */
  bool setConversionPeriod(uint8_t periodNibble);

  /** Alert mask access (0x1F) */
  bool readAlertMask(uint8_t &mask);
  bool writeAlertMask(uint8_t mask);

  /** η-Factor registers for remote channels */
  bool readEtaFactorCh1(uint8_t &value);
  bool writeEtaFactorCh1(uint8_t value);
  bool readEtaFactorCh2(uint8_t &value);
  bool writeEtaFactorCh2(uint8_t value);

  /** Configuration register access (0x03) */
  bool readConfiguration(uint8_t &config);
  bool writeConfiguration(uint8_t config);

  /** Convenience: set or clear Shutdown mode (Configuration.Mode bit, bit 6)
   *  @param enable true to set Shutdown (Mode=1), false for continuous (Mode=0)
   */
  bool setShutdownMode(bool enable);

  /** Read/Write local THigh limit (0x05 primary) */
  bool readHighLimitLocal(uint8_t &value);
  bool writeHighLimitLocal(uint8_t value);

private:
  // Private / implementation details
  TwoWire* _wire = nullptr;
  uint8_t _i2caddr = 0;

  /**
   * _readRegisterBytes - private helper that reads len bytes starting from reg
   * Implementation note: TMP4719 may require single-register reads per address.
   */
  bool _readRegisterBytes(uint8_t reg, uint8_t *buf, size_t len);

  // Private / implementation details: repeat of the required warning for quick discoverability.
  // Important: Do not write to registers documented as read-only in the device register map. The low-level single-byte write helper writeRegister8() is private; application code must not call it. Use only the driver's public high-level write APIs to modify device state (for example: writeConfiguration, writeAlertMask, writeHighLimitLocal, writeEtaFactorCh1, writeEtaFactorCh2, setConversionPeriod, startOneShot).
  // Low-level single-byte write is private to prevent accidental writes to read-only registers.
  bool writeRegister8(uint8_t reg, uint8_t value);

  // Lightweight sign/extension helpers
  static int16_t _signExtend12(uint16_t raw12);
};

