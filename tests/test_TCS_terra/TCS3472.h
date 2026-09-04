/*
Wire.h TCS3472 color sensor driver public API and device types.
*/

#pragma once

// Includes, class, constants, and data types: Declare Wire dependency, default address, supported IDs, Gain enum, RGBC sample struct, and private register/bit constants.

#include <Arduino.h>
#include <Wire.h>

class TCS3472 {
public:
  // Public types
  enum class Gain : uint8_t {
    GAIN_1X = 0,  // 00
    GAIN_4X = 1,  // 01
    GAIN_16X = 2, // 10
    GAIN_60X = 3  // 11
  };

  struct RGBCData {
    uint16_t c;
    uint16_t r;
    uint16_t g;
    uint16_t b;
  };

  // Construction and device lifecycle API: Declare bus/address construction, probe/init, and power/conversion controls.

  // Construct a driver bound to an I2C bus and address without initializing the bus.
  explicit TCS3472(TwoWire &wire = Wire, uint8_t address = 0x29);

  // Probe a supported ID, initialize documented configuration defaults, power the oscillator, and wait at least 3 ms.
  bool begin();

  // Set ENABLE.PON; waits for oscillator warm-up when enabling power.
  bool setPower(bool enabled);

  // Set ENABLE.AEN; caller must power first or use begin().
  bool setRGBCEnabled(bool enabled);

  // Set ENABLE.WEN to insert waits between RGBC cycles.
  bool setWaitEnabled(bool enabled);

  // Configuration and timing API: Declare configuration setters/getters and calculations directly supported by ATIME, WTIME, CONFIG, and CONTROL.

  // Write raw ATIME while conversion is disabled for deterministic timing.
  bool setIntegrationTime(uint8_t atime);

  // Read raw ATIME register value.
  bool getIntegrationTime(uint8_t &atime);

  // Convert an ATIME encoding to its 2.4 ms step integration duration.
  float integrationTimeMs(uint8_t atime);

  // Write CONTROL.AGAIN using a defined gain enum.
  bool setGain(Gain gain);

  // Read and decode CONTROL.AGAIN.
  bool getGain(Gain &gain);

  // Write WTIME and CONFIG.WLONG together.
  bool setWaitTime(uint8_t wtime, bool longWait);

  // Read WTIME and CONFIG.WLONG.
  bool getWaitTime(uint8_t &wtime, bool &longWait);

  // Convert WTIME and WLONG to the documented wait duration.
  float waitTimeMs(uint8_t wtime, bool longWait);

  // Status, acquisition, and interrupt API: Declare status/data functions and all interrupt register controls.

  // Read the read-only part identification value.
  bool readID(uint8_t &id);

  // Read STATUS without clearing any interrupt.
  bool readStatus(uint8_t &status);

  // Report STATUS.AVALID.
  bool dataValid(bool &valid);

  // Report latched STATUS.AINT.
  bool interruptActive(bool &active);

  // Read a fresh atomic RGBC sample after confirming AVALID.
  bool readRGBC(RGBCData &sample);

  // Program ordered 16-bit low and high clear-channel thresholds.
  bool setInterruptThresholds(uint16_t low, uint16_t high);

  // Read 16-bit low and high thresholds.
  bool getInterruptThresholds(uint16_t &low, uint16_t &high);

  // Set PERS.APERS persistence encoding.
  bool setInterruptPersistence(uint8_t persistence);

  // Read PERS.APERS.
  bool getInterruptPersistence(uint8_t &persistence);

  // Set ENABLE.AIEN controlling physical interrupt output.
  bool setInterruptEnabled(bool enabled);

  // Issue COMMAND special function clear-interrupt command.
  bool clearInterrupt();

private:
  // Private I2C transport helpers: Declare internal command formation and checked register access helpers.
  bool writeRegister(uint8_t reg, uint8_t value);
  bool writeBlock(uint8_t reg, const uint8_t *data, uint8_t length);
  bool readRegister(uint8_t reg, uint8_t &value);
  bool readBlock(uint8_t reg, uint8_t *data, uint8_t length);
  bool updateEnable(uint8_t mask, uint8_t value);

  // Private members
  TwoWire &wire_;
  uint8_t address_; // 7-bit I2C address

  // Register addresses (physical)
  static constexpr uint8_t REG_ENABLE = 0x00;
  static constexpr uint8_t REG_ATIME = 0x01;
  static constexpr uint8_t REG_WTIME = 0x03;
  static constexpr uint8_t REG_AILTL = 0x04; // low thresh low byte
  static constexpr uint8_t REG_AILTH = 0x05; // low thresh high byte
  static constexpr uint8_t REG_AIHTL = 0x06; // high thresh low byte
  static constexpr uint8_t REG_AIHTH = 0x07; // high thresh high byte
  static constexpr uint8_t REG_PERS = 0x0C;
  static constexpr uint8_t REG_CONFIG = 0x0D;
  static constexpr uint8_t REG_CONTROL = 0x0F;
  static constexpr uint8_t REG_ID = 0x12;
  static constexpr uint8_t REG_STATUS = 0x13;
  static constexpr uint8_t REG_CDATAL = 0x14; // 8 bytes CDATA..BDATAH

  // ENABLE bit masks (defined bits only)
  static constexpr uint8_t ENABLE_PON = 0x01;  // bit0
  static constexpr uint8_t ENABLE_AEN = 0x02;  // bit1
  static constexpr uint8_t ENABLE_WEN = 0x08;  // bit3
  static constexpr uint8_t ENABLE_AIEN = 0x10; // bit4
  static constexpr uint8_t ENABLE_ALLOWED_MASK = (ENABLE_PON | ENABLE_AEN | ENABLE_WEN | ENABLE_AIEN);

  // CONFIG bit masks
  static constexpr uint8_t CONFIG_WLONG = 0x02; // bit1

  // CONTROL masks
  static constexpr uint8_t CONTROL_AGAIN_MASK = 0x03; // bits1:0

  // PERS mask (APERS low nibble)
  static constexpr uint8_t PERS_APERS_MASK = 0x0F;

  // COMMAND formation helpers (not public)
  static inline uint8_t cmd_make(uint8_t type, uint8_t addr_or_sf) {
    return static_cast<uint8_t>(0x80 | ((type & 0x03) << 5) | (addr_or_sf & 0x1F));
  }
};

