/*
Implementation of all TCS3472 public APIs and private Wire transport helpers.
*/

// Transport and command helpers: Implement command construction, single/block transfer checks, and reserved-safe ENABLE update.

#include "TCS3472.h"

// Private helpers

bool TCS3472::writeRegister(uint8_t reg, uint8_t value) {
  // TYPE = 00 (repeated byte), CMD = 1
  uint8_t cmd = cmd_make(0x0, reg);
  wire_.beginTransmission(address_);
  wire_.write(cmd);
  wire_.write(value);
  uint8_t res = static_cast<uint8_t>(wire_.endTransmission(true));
  return (res == 0);
}

bool TCS3472::writeBlock(uint8_t reg, const uint8_t *data, uint8_t length) {
  // TYPE = 01 (auto-increment)
  uint8_t cmd = cmd_make(0x1, reg);
  wire_.beginTransmission(address_);
  wire_.write(cmd);
  // Write data bytes
  for (uint8_t i = 0; i < length; ++i) {
    wire_.write(data[i]);
  }
  uint8_t res = static_cast<uint8_t>(wire_.endTransmission(true));
  return (res == 0);
}

bool TCS3472::readRegister(uint8_t reg, uint8_t &value) {
  // TYPE = 00 (repeated byte) for single register read
  uint8_t cmd = cmd_make(0x0, reg);
  wire_.beginTransmission(address_);
  wire_.write(cmd);
  uint8_t res = static_cast<uint8_t>(wire_.endTransmission(false));
  if (res != 0) return false;

  int available = wire_.requestFrom(static_cast<int>(address_), 1);
  if (available != 1) return false;
  int v = wire_.read();
  if (v < 0) return false;
  value = static_cast<uint8_t>(v);
  return true;
}

bool TCS3472::readBlock(uint8_t reg, uint8_t *data, uint8_t length) {
  // TYPE = 01 (auto-increment)
  uint8_t cmd = cmd_make(0x1, reg);
  wire_.beginTransmission(address_);
  wire_.write(cmd);
  uint8_t res = static_cast<uint8_t>(wire_.endTransmission(false));
  if (res != 0) return false;

  int got = wire_.requestFrom(static_cast<int>(address_), static_cast<int>(length));
  if (got != length) return false;
  for (uint8_t i = 0; i < length; ++i) {
    int v = wire_.read();
    if (v < 0) return false;
    data[i] = static_cast<uint8_t>(v);
  }
  return true;
}

bool TCS3472::updateEnable(uint8_t mask, uint8_t value) {
  // Read-modify-write only defined ENABLE bits and clear reserved bits in final write
  uint8_t cur;
  if (!readRegister(REG_ENABLE, cur)) return false;
  // Keep only allowed bits from current
  uint8_t cur_allowed = cur & ENABLE_ALLOWED_MASK;
  // Apply requested masked changes
  uint8_t new_allowed = (cur_allowed & static_cast<uint8_t>(~mask)) | (value & mask);
  // Write only allowed bits (reserved bits written as zero)
  return writeRegister(REG_ENABLE, new_allowed);
}

// Lifecycle and configuration implementation: Implement probe, warm-up, enable control, register settings, and timing calculations.

bool TCS3472::begin() {
  // Probe ID
  uint8_t id;
  if (!readID(id)) return false;
  if (!(id == 0x44 || id == 0x4D)) return false;

  // Configure documented defaults (do not enable AEN)
  bool ok = true;
  ok &= setIntegrationTime(0xFF); // default 2.4 ms
  ok &= writeRegister(REG_WTIME, 0xFF); // default wait
  ok &= writeRegister(REG_PERS, 0x00); // default persistence
  ok &= writeRegister(REG_CONFIG, 0x00); // default config (WLONG=0)
  ok &= writeRegister(REG_CONTROL, 0x00); // default gain
  ok &= writeRegister(REG_AILTL, 0x00); // low threshold low
  ok &= writeRegister(REG_AILTH, 0x00); // low threshold high
  ok &= writeRegister(REG_AIHTL, 0x00); // high threshold low
  ok &= writeRegister(REG_AIHTH, 0x00); // high threshold high

  if (!ok) return false;

  // Power on oscillator (PON) and wait at least 3 ms; do not enable AEN.
  if (!setPower(true)) return false;
  // setPower already delays when enabling, but ensure minimum
  delay(1);
  return true;
}

bool TCS3472::setPower(bool enabled) {
  bool res = updateEnable(ENABLE_PON, enabled ? ENABLE_PON : 0x00);
  if (res && enabled) {
    // Wait oscillator warm-up >= 2.4 ms
    delay(3);
  }
  return res;
}

bool TCS3472::setRGBCEnabled(bool enabled) {
  // Do not implicitly power on PON here
  return updateEnable(ENABLE_AEN, enabled ? ENABLE_AEN : 0x00);
}

bool TCS3472::setWaitEnabled(bool enabled) {
  return updateEnable(ENABLE_WEN, enabled ? ENABLE_WEN : 0x00);
}

bool TCS3472::setIntegrationTime(uint8_t atime) {
  // ATIME is safe to write anytime, but caller should disable AEN for deterministic timing
  return writeRegister(REG_ATIME, atime);
}

bool TCS3472::getIntegrationTime(uint8_t &atime) {
  return readRegister(REG_ATIME, atime);
}

float TCS3472::integrationTimeMs(uint8_t atime) {
  // Integration Time = 2.4 ms × (256 − ATIME)
  return 2.4f * static_cast<float>(256u - static_cast<unsigned int>(atime));
}

bool TCS3472::setGain(Gain gain) {
  uint8_t g = static_cast<uint8_t>(gain) & CONTROL_AGAIN_MASK;
  // Write CONTROL with only defined AGAIN bits; reserved bits must be zero
  return writeRegister(REG_CONTROL, g);
}

bool TCS3472::getGain(Gain &gain) {
  uint8_t v;
  if (!readRegister(REG_CONTROL, v)) return false;
  gain = static_cast<Gain>(v & CONTROL_AGAIN_MASK);
  return true;
}

bool TCS3472::setWaitTime(uint8_t wtime, bool longWait) {
  bool ok = writeRegister(REG_WTIME, wtime);
  uint8_t cfg = longWait ? CONFIG_WLONG : 0x00;
  ok &= writeRegister(REG_CONFIG, cfg);
  return ok;
}

bool TCS3472::getWaitTime(uint8_t &wtime, bool &longWait) {
  uint8_t cfg;
  bool ok = readRegister(REG_WTIME, wtime);
  ok &= readRegister(REG_CONFIG, cfg);
  if (!ok) return false;
  longWait = (cfg & CONFIG_WLONG) != 0;
  return true;
}

float TCS3472::waitTimeMs(uint8_t wtime, bool longWait) {
  float base = 2.4f * static_cast<float>(256u - static_cast<unsigned int>(wtime));
  if (longWait) base *= 12.0f;
  return base;
}

// Status, data, and interrupt implementation: Implement read-only status/data methods and all supported interrupt controls.

bool TCS3472::readID(uint8_t &id) {
  return readRegister(REG_ID, id);
}

bool TCS3472::readStatus(uint8_t &status) {
  return readRegister(REG_STATUS, status);
}

bool TCS3472::dataValid(bool &valid) {
  uint8_t s;
  if (!readStatus(s)) return false;
  valid = (s & 0x01) != 0;
  return true;
}

bool TCS3472::interruptActive(bool &active) {
  uint8_t s;
  if (!readStatus(s)) return false;
  active = (s & 0x10) != 0;
  return true;
}

bool TCS3472::readRGBC(RGBCData &sample) {
  // First confirm STATUS.AVALID
  uint8_t s;
  if (!readStatus(s)) return false;
  if ((s & 0x01) == 0) return false; // AVALID not set

  // Read contiguous 8 bytes from CDATAL using auto-increment
  uint8_t buf[8];
  if (!readBlock(REG_CDATAL, buf, 8)) return false;

  // Decode little-endian pairs
  uint16_t c = static_cast<uint16_t>(buf[0]) | (static_cast<uint16_t>(buf[1]) << 8);
  uint16_t r = static_cast<uint16_t>(buf[2]) | (static_cast<uint16_t>(buf[3]) << 8);
  uint16_t g = static_cast<uint16_t>(buf[4]) | (static_cast<uint16_t>(buf[5]) << 8);
  uint16_t b = static_cast<uint16_t>(buf[6]) | (static_cast<uint16_t>(buf[7]) << 8);

  sample.c = c;
  sample.r = r;
  sample.g = g;
  sample.b = b;
  return true;
}

bool TCS3472::setInterruptThresholds(uint16_t low, uint16_t high) {
  if (low > high) return false;
  uint8_t buf[4];
  buf[0] = static_cast<uint8_t>(low & 0xFF);        // AILTL
  buf[1] = static_cast<uint8_t>((low >> 8) & 0xFF); // AILTH
  buf[2] = static_cast<uint8_t>(high & 0xFF);       // AIHTL
  buf[3] = static_cast<uint8_t>((high >> 8) & 0xFF);// AIHTH
  return writeBlock(REG_AILTL, buf, 4);
}

bool TCS3472::getInterruptThresholds(uint16_t &low, uint16_t &high) {
  uint8_t buf[4];
  if (!readBlock(REG_AILTL, buf, 4)) return false;
  low = static_cast<uint16_t>(buf[0]) | (static_cast<uint16_t>(buf[1]) << 8);
  high = static_cast<uint16_t>(buf[2]) | (static_cast<uint16_t>(buf[3]) << 8);
  return true;
}

bool TCS3472::setInterruptPersistence(uint8_t persistence) {
  if ((persistence & ~PERS_APERS_MASK) != 0) return false;
  // Write only low nibble; upper nibble reserved and written as 0
  return writeRegister(REG_PERS, (persistence & PERS_APERS_MASK));
}

bool TCS3472::getInterruptPersistence(uint8_t &persistence) {
  uint8_t v;
  if (!readRegister(REG_PERS, v)) return false;
  persistence = v & PERS_APERS_MASK;
  return true;
}

bool TCS3472::setInterruptEnabled(bool enabled) {
  return updateEnable(ENABLE_AIEN, enabled ? ENABLE_AIEN : 0x00);
}

bool TCS3472::clearInterrupt() {
  // Special-function clear interrupt command (CMD=1, TYPE=11, ADDR/SF=00110) == 0xE6
  wire_.beginTransmission(address_);
  wire_.write(static_cast<uint8_t>(0xE6));
  uint8_t res = static_cast<uint8_t>(wire_.endTransmission(true));
  return (res == 0);
}

// Constructor
TCS3472::TCS3472(TwoWire &wire, uint8_t address)
  : wire_(wire), address_(address) {}

