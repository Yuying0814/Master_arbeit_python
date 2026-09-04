/*
Implementation of TMP4719 class: I2C transactions, conversions, and register access.
*/

// Constructor and begin: Implement constructor and safe begin(uint8_t, TwoWire&)
#include "TMP4719.h"
#include <Wire.h>

TMP4719::TMP4719() {
  _wire = nullptr;
  _i2caddr = 0;
}

bool TMP4719::begin(uint8_t address, TwoWire &wire) {
  // Store provided TwoWire reference and I2C address. Caller must call Wire.begin().
  _wire = &wire;
  _i2caddr = address;
  return true;
}

// Identification and isConnected: implement strict check against documented Chip_ID (0x21)
bool TMP4719::readChipID(uint8_t &id) {
  return readRegister8(TMP4719Regs::REG_CHIP_ID, id);
}

bool TMP4719::readVendorID(uint8_t &id) {
  return readRegister8(TMP4719Regs::REG_VENDOR_ID, id);
}

bool TMP4719::readDeviceRevID(uint8_t &rev) {
  return readRegister8(TMP4719Regs::REG_DEVICE_REV_ID, rev);
}

bool TMP4719::isConnected(bool strict) {
  if (!_wire || _i2caddr == 0) return false;
  uint8_t id = 0;
  if (strict) {
    // Strict: require chip id read to succeed and match documented reset value 0x21
    if (!readChipID(id)) return false;
    return (id == 0x21);
  }
  // Permissive: accept any successful identification or innocuous register read
  if (readChipID(id)) return true;
  uint8_t tmp = 0;
  if (readVendorID(tmp)) return true;
  if (readDeviceRevID(tmp)) return true;
  if (readStatus(tmp)) return true;
  if (readRegister8(TMP4719Regs::REG_TEMP_LOCAL, tmp)) return true;
  return false;
}

// Low-level I2C helpers: keep readRegister8 public, writeRegister8 implemented privately
bool TMP4719::readRegister8(uint8_t reg, uint8_t &value) {
  if (!_wire) return false;
  _wire->beginTransmission(_i2caddr);
  _wire->write(reg);
  uint8_t err = _wire->endTransmission(false); // repeated start
  if (err != 0) return false;
  uint8_t got = _wire->requestFrom((int)_i2caddr, (int)1);
  if (got != 1) return false;
  int c = _wire->read();
  if (c < 0) return false;
  value = (uint8_t)c;
  return true;
}

bool TMP4719::writeRegister8(uint8_t reg, uint8_t value) {
  if (!_wire) return false;
  _wire->beginTransmission(_i2caddr);
  _wire->write(reg);
  _wire->write(value);
  uint8_t err = _wire->endTransmission(true);
  return (err == 0);
}

bool TMP4719::_readRegisterBytes(uint8_t reg, uint8_t *buf, size_t len) {
  if (!_wire || buf == nullptr) return false;
  // Use single-register reads as datasheet indicates multi-register combined read
  // may be unsupported for some address spaces; assemble from individual reads.
  for (size_t i = 0; i < len; ++i) {
    uint8_t v = 0;
    if (!readRegister8((uint8_t)(reg + i), v)) return false;
    buf[i] = v;
  }
  return true;
}

// Temperature and conversion helpers
bool TMP4719::readStatus(uint8_t &status) {
  // Reading Status may clear flags in SMBus Alert interrupt mode.
  return readRegister8(TMP4719Regs::REG_STATUS, status);
}

bool TMP4719::readLocalRaw(int8_t &raw) {
  uint8_t v = 0;
  if (!readRegister8(TMP4719Regs::REG_TEMP_LOCAL, v)) return false;
  raw = (int8_t)v;
  return true;
}

bool TMP4719::readLocalTemperatureC(float &celsius) {
  int8_t raw = 0;
  if (!readLocalRaw(raw)) return false;
  celsius = (float)raw * 1.0f; // LSB = 1°C
  return true;
}

int16_t TMP4719::_signExtend12(uint16_t raw12) {
  if (raw12 & (1u << 11)) {
    return (int16_t)(raw12 | 0xF000u);
  }
  return (int16_t)raw12;
}

bool TMP4719::readRemoteRawCh1(int16_t &raw12) {
  uint8_t high = 0, low = 0;
  if (!readRegister8(TMP4719Regs::REG_TEMP_REMOTE_CH1_HIGH, high)) return false;
  if (!readRegister8(TMP4719Regs::REG_TEMP_REMOTE_CH1_LOW, low)) return false;
  uint16_t assembled = ((uint16_t)high << 4) | ((uint16_t)(low >> 4) & 0x0F);
  raw12 = _signExtend12(assembled);
  return true;
}

bool TMP4719::readRemoteTemperatureCCh1(float &celsius) {
  int16_t raw12 = 0;
  if (!readRemoteRawCh1(raw12)) return false;
  celsius = (float)raw12 * 0.0625f;
  return true;
}

bool TMP4719::readRemoteRawCh2(int16_t &raw12) {
  uint8_t high = 0, low = 0;
  if (!readRegister8(TMP4719Regs::REG_TEMP_REMOTE_CH2_HIGH, high)) return false;
  if (!readRegister8(TMP4719Regs::REG_TEMP_REMOTE_CH2_LOW, low)) return false;
  uint16_t assembled = ((uint16_t)high << 4) | ((uint16_t)(low >> 4) & 0x0F);
  raw12 = _signExtend12(assembled);
  return true;
}

bool TMP4719::readRemoteTemperatureCCh2(float &celsius) {
  int16_t raw12 = 0;
  if (!readRemoteRawCh2(raw12)) return false;
  celsius = (float)raw12 * 0.0625f;
  return true;
}

// Configuration register access
bool TMP4719::readConfiguration(uint8_t &config) {
  return readRegister8(TMP4719Regs::REG_CONFIGURATION, config);
}

bool TMP4719::writeConfiguration(uint8_t config) {
  return writeRegister8(TMP4719Regs::REG_CONFIGURATION, config);
}

bool TMP4719::setShutdownMode(bool enable) {
  uint8_t cfg = 0;
  if (!readConfiguration(cfg)) return false;
  if (enable) cfg |= (1u << 6); else cfg &= ~(1u << 6);
  return writeConfiguration(cfg);
}

bool TMP4719::startOneShot() {
  return writeRegister8(TMP4719Regs::REG_ONE_SHOT, 0x01);
}

bool TMP4719::setConversionPeriod(uint8_t periodNibble) {
  periodNibble &= 0x0F;
  uint8_t cur = 0;
  if (!readRegister8(TMP4719Regs::REG_CONV_PERIOD, cur)) return false;
  cur = (cur & 0xF0) | periodNibble;
  return writeRegister8(TMP4719Regs::REG_CONV_PERIOD, cur);
}

bool TMP4719::readAlertMask(uint8_t &mask) {
  return readRegister8(TMP4719Regs::REG_ALERT_MASK, mask);
}

bool TMP4719::writeAlertMask(uint8_t mask) {
  return writeRegister8(TMP4719Regs::REG_ALERT_MASK, mask);
}

bool TMP4719::readEtaFactorCh1(uint8_t &value) {
  return readRegister8(TMP4719Regs::REG_ETA_FACTOR_CH1, value);
}

bool TMP4719::writeEtaFactorCh1(uint8_t value) {
  return writeRegister8(TMP4719Regs::REG_ETA_FACTOR_CH1, value);
}

bool TMP4719::readEtaFactorCh2(uint8_t &value) {
  return readRegister8(TMP4719Regs::REG_ETA_FACTOR_CH2, value);
}

bool TMP4719::writeEtaFactorCh2(uint8_t value) {
  return writeRegister8(TMP4719Regs::REG_ETA_FACTOR_CH2, value);
}

bool TMP4719::readHighLimitLocal(uint8_t &value) {
  return readRegister8(TMP4719Regs::REG_THIGH_LOCAL, value);
}

bool TMP4719::writeHighLimitLocal(uint8_t value) {
  return writeRegister8(TMP4719Regs::REG_THIGH_LOCAL, value);
}

