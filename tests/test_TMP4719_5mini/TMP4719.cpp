/*
TMP4719.cpp - implementation of TMP4719 driver.
*/

// Includes and constants: Include TMP4719.h and Wire.h, define any private constants (timeouts, default delays).
#include "TMP4719.h"

// Private timing constants
static const uint32_t TMP4719_DEFAULT_CONV_WAIT_MS = 200; // used by waitForConversion default
static const uint32_t TMP4719_POR_DELAY_MS = 15; // recommended tPOR
static const uint32_t TMP4719_FIRST_CONV_APPROX_MS = 67; // recommended wait for first conversion after POR

// Constructor & begin: Implement constructors and begin() that attach TwoWire pointer, optionally verify device by reading Chip_ID. Do NOT call Wire.begin(). Provide recommended POR delay (15 ms) and optional initial conversion wait (≈67 ms) in comments and as optional behavior.
TMP4719::TMP4719(uint8_t addr) {
  _addr = addr & 0x7F;
  _wire = nullptr;
}

bool TMP4719::begin(TwoWire* wire, bool verify) {
  _wire = wire ? wire : &Wire;
  // Respect datasheet POR recommendation: host should ensure device had stable VDD. We provide recommended small delay.
  delay(TMP4719_POR_DELAY_MS);

  if (!verify) return true;

  int16_t cid = readChipID();
  int16_t vid = readVendorID();
  if (cid < 0 || vid < 0) return false;
  // Optionally allow waiting for first conversion externally. We don't block for full conversion here beyond POR.
  return true;
}

// Low-level I2C helpers: Implement readRegister/writeRegister with single-byte pointer write then single-byte read/write. Return boolean success.
// Behavior change: if value == nullptr perform only pointer-write (presence-check) and return based on ACK; if value != nullptr perform pointer-write then single-byte read.
bool TMP4719::readRegister(uint8_t reg, uint8_t* value) {
  // Pointer-write only (presence check) path
  _wire->beginTransmission(_addr);
  _wire->write(reg);
  uint8_t err = _wire->endTransmission();
  if (err != 0) {
    return false; // NACK or bus error
  }

  if (value == nullptr) {
    // caller only wanted to verify pointer-write (presence)
    return true;
  }

  // Now request the single byte
  uint8_t got = _wire->requestFrom((int)_addr, 1);
  if (got != 1) return false;
  uint8_t b = _wire->read();
  *value = b;
  return true;
}

bool TMP4719::writeRegister(uint8_t reg, uint8_t value) {
  _wire->beginTransmission(_addr);
  _wire->write(reg);
  _wire->write(value);
  uint8_t err = _wire->endTransmission();
  return (err == 0);
}

// High-level APIs implementation
// New boolean-style unambiguous local raw read
bool TMP4719::readLocalTemperatureRaw(int8_t &out) {
  uint8_t b;
  if (!readRegister(TMP4719_REG_TEMP_LOCAL, &b)) return false;
  out = decodeLocalRaw(b);
  return true;
}

// Backward-compatible ambiguous form
int8_t TMP4719::readLocalTemperatureRaw() {
  int8_t v;
  if (!readLocalTemperatureRaw(v)) return INT8_MIN;
  return v;
}

float TMP4719::readLocalTemperatureC() {
  int8_t raw;
  if (!readLocalTemperatureRaw(raw)) return NAN;
  return (float)raw; // LSB = 1°C
}

int8_t TMP4719::decodeLocalRaw(uint8_t raw) {
  // Interpret as signed 8-bit two's complement
  return (int8_t)raw;
}

int16_t TMP4719::readRemoteTemperatureRaw(uint8_t channel) {
  uint8_t high_reg, low_reg;
  if (channel == 1) {
    high_reg = TMP4719_REG_TEMP_REMOTE_CH1_HIGH;
    low_reg  = TMP4719_REG_TEMP_REMOTE_CH1_LOW;
  } else if (channel == 2) {
    high_reg = TMP4719_REG_TEMP_REMOTE_CH2_HIGH;
    low_reg  = TMP4719_REG_TEMP_REMOTE_CH2_LOW;
  } else return INT16_MIN;

  uint8_t high, low;
  if (!readRemoteParts(high_reg, low_reg, &high, &low)) return INT16_MIN;
  uint8_t low_nibble = (low >> 4) & 0x0F;
  int16_t signed12 = combineSigned12(high, low_nibble);
  return signed12;
}

float TMP4719::readRemoteTemperatureC(uint8_t channel) {
  int16_t raw = readRemoteTemperatureRaw(channel);
  if (raw == INT16_MIN) return NAN;
  // Per datasheet, raw==0x000 may indicate diode fault; check Diode_Fault register.
  if (raw == 0) {
    int16_t df = readDiodeFault();
    if (df < 0) return NAN; // couldn't read diag
    if (df != 0) return NAN; // diode fault present
  }
  return decodeRemoteRawToFloat(raw);
}

// Status & polling
int16_t TMP4719::readStatus() {
  uint8_t b;
  if (!readRegister(TMP4719_REG_STATUS, &b)) return -1;
  return (int16_t)b;
}

bool TMP4719::isBusy() {
  int16_t s = readStatus();
  if (s < 0) return false; // On comms error assume not busy
  return ( (s & TMP4719_STATUS_ADC_BUSY_BIT) != 0 );
}

bool TMP4719::waitForConversion(uint32_t timeout_ms) {
  if (timeout_ms == 0) timeout_ms = TMP4719_DEFAULT_CONV_WAIT_MS;
  uint32_t start = millis();
  while (true) {
    if (!isBusy()) return true;
    if ((millis() - start) >= timeout_ms) return false;
    delay(5);
  }
}

bool TMP4719::isTHigh() {
  int16_t s = readStatus(); if (s < 0) return false;
  return ( (s & TMP4719_STATUS_THIGH_BIT) != 0 );
}
bool TMP4719::isTLow() {
  int16_t s = readStatus(); if (s < 0) return false;
  return ( (s & TMP4719_STATUS_TLOW_BIT) != 0 );
}
bool TMP4719::isTCrit() {
  int16_t s = readStatus(); if (s < 0) return false;
  return ( (s & TMP4719_STATUS_TCRIT_BIT) != 0 );
}

int16_t TMP4719::readHighLimitStatus() {
  uint8_t b; if (!readRegister(TMP4719_REG_HIGH_LIMIT_STATUS, &b)) return -1; return (int16_t)b;
}
int16_t TMP4719::readLowLimitStatus() {
  uint8_t b; if (!readRegister(TMP4719_REG_LOW_LIMIT_STATUS, &b)) return -1; return (int16_t)b;
}
int16_t TMP4719::readTcritStatus() {
  uint8_t b; if (!readRegister(TMP4719_REG_TCRIT_LIMIT_STATUS, &b)) return -1; return (int16_t)b;
}
int16_t TMP4719::readDiodeFault() {
  uint8_t b; if (!readRegister(TMP4719_REG_DIODE_FAULT, &b)) return -1; return (int16_t)b;
}

// Scratchpad
int16_t TMP4719::readScratchpad1() { uint8_t b; if (!readRegister(TMP4719_REG_SCRATCHPAD1, &b)) return -1; return (int16_t)b; }
bool TMP4719::writeScratchpad1(uint8_t value) { return writeRegister(TMP4719_REG_SCRATCHPAD1, value); }
int16_t TMP4719::readScratchpad2() { uint8_t b; if (!readRegister(TMP4719_REG_SCRATCHPAD2, &b)) return -1; return (int16_t)b; }
bool TMP4719::writeScratchpad2(uint8_t value) { return writeRegister(TMP4719_REG_SCRATCHPAD2, value); }

// Identification
int16_t TMP4719::readChipID() { uint8_t b; if (!readRegister(TMP4719_REG_CHIP_ID, &b)) return -1; return (int16_t)b; }
int16_t TMP4719::readVendorID() { uint8_t b; if (!readRegister(TMP4719_REG_VENDOR_ID, &b)) return -1; return (int16_t)b; }
int16_t TMP4719::readDeviceRevID() { uint8_t b; if (!readRegister(TMP4719_REG_DEVICE_REV_ID, &b)) return -1; return (int16_t)b; }

// Configuration read/write
int16_t TMP4719::readConfiguration() { uint8_t b; if (!readRegister(TMP4719_REG_CONFIGURATION, &b)) return -1; return (int16_t)b; }
bool TMP4719::writeConfiguration(uint8_t value) { return writeRegister(TMP4719_REG_CONFIGURATION, value); }

bool TMP4719::setModeShutdown(bool shutdown) {
  int16_t v = readConfiguration(); if (v < 0) return false;
  uint8_t b = (uint8_t)v;
  if (shutdown) b |= TMP4719_CFG_MODE_SHUTDOWN; else b &= ~TMP4719_CFG_MODE_SHUTDOWN;
  return writeConfiguration(b);
}

bool TMP4719::getModeIsShutdown() {
  int16_t v = readConfiguration(); if (v < 0) return false;
  return ( ((uint8_t)v & TMP4719_CFG_MODE_SHUTDOWN) != 0 );
}

// Conv period
// Perform read-modify-write preserving upper nibble
bool TMP4719::setConvPeriodCode(uint8_t code) {
  code &= 0x0F;
  uint8_t cur;
  if (!readRegister(TMP4719_REG_CONV_PERIOD, &cur)) return false;
  uint8_t out = (uint8_t)((cur & 0xF0) | (code & 0x0F));
  return writeRegister(TMP4719_REG_CONV_PERIOD, out);
}
int16_t TMP4719::getConvPeriodCode() {
  uint8_t b; if (!readRegister(TMP4719_REG_CONV_PERIOD, &b)) return -1; return (int16_t)(b & 0x0F);
}

// Filter control
// Implement read-modify-write: preserve upper bits and update bits[1:0]
bool TMP4719::setFilterLevel(uint8_t level) {
  if (level > 3) return false;
  uint8_t cur;
  if (!readRegister(TMP4719_REG_FILTER_CONTROL, &cur)) return false;
  uint8_t out = (uint8_t)((cur & ~0x03) | (level & 0x03));
  return writeRegister(TMP4719_REG_FILTER_CONTROL, out);
}
int16_t TMP4719::getFilterLevel() {
  uint8_t b; if (!readRegister(TMP4719_REG_FILTER_CONTROL, &b)) return -1; return (int16_t)(b & 0x03);
}

// Hysteresis
bool TMP4719::setHysteresis(uint8_t h) {
  if (h > 31) return false;
  uint8_t out = h & 0x1F;
  return writeRegister(TMP4719_REG_HYSTERESIS, out);
}
int16_t TMP4719::getHysteresis() {
  uint8_t b; if (!readRegister(TMP4719_REG_HYSTERESIS, &b)) return -1; return (int16_t)(b & 0x1F);
}

// Eta-factor
bool TMP4719::setEtaFactor(uint8_t channel, uint8_t code) {
  if (channel == 1) return writeRegister(TMP4719_REG_ETA_FACTOR_CH1, code);
  if (channel == 2) return writeRegister(TMP4719_REG_ETA_FACTOR_CH2, code);
  return false;
}
int16_t TMP4719::getEtaFactorCode(uint8_t channel) {
  uint8_t b;
  if (channel == 1) { if (!readRegister(TMP4719_REG_ETA_FACTOR_CH1, &b)) return -1; return (int16_t)b; }
  if (channel == 2) { if (!readRegister(TMP4719_REG_ETA_FACTOR_CH2, &b)) return -1; return (int16_t)b; }
  return -1;
}

// Local thresholds
bool TMP4719::setLocalTHigh(int8_t value) { return writeRegister(TMP4719_REG_THIGH_LIMIT_LOCAL, (uint8_t)value); }
int16_t TMP4719::getLocalTHigh() { uint8_t b; if (!readRegister(TMP4719_REG_THIGH_LIMIT_LOCAL, &b)) return INT16_MIN; return (int16_t)(int8_t)b; }

bool TMP4719::setLocalTLow(int8_t value) { return writeRegister(TMP4719_REG_TLOW_LIMIT_LOCAL, (uint8_t)value); }
int16_t TMP4719::getLocalTLow() { uint8_t b; if (!readRegister(TMP4719_REG_TLOW_LIMIT_LOCAL, &b)) return INT16_MIN; return (int16_t)(int8_t)b; }

// Remote thresholds: setRemoteTHigh/Low/ read raw
bool TMP4719::setRemoteTHigh(uint8_t channel, float temp_c) {
  // map channel to registers
  uint8_t high_reg, low_reg;
  if (channel == 1) { high_reg = 0x07; low_reg = 0x13; }
  else if (channel == 2) { high_reg = 0x15; low_reg = 0x17; }
  else return false;

  uint8_t high, low;
  if (!encodeFloatToRemoteRaw12(temp_c, &high, &low)) return false;
  // write high then low to minimize transient inconsistent reads
  if (!writeRegister(high_reg, high)) return false;
  if (!writeRegister(low_reg, low)) return false;
  return true;
}

int16_t TMP4719::getRemoteTHighRaw(uint8_t channel) {
  uint8_t high_reg, low_reg;
  if (channel == 1) { high_reg = TMP4719_REG_THIGH_LIMIT_REM_CH1_HIGH; low_reg = TMP4719_REG_THIGH_LIMIT_REM_CH1_LOW; }
  else if (channel == 2) { high_reg = TMP4719_REG_THIGH_LIMIT_REM_CH2_HIGH; low_reg = TMP4719_REG_THIGH_LIMIT_REM_CH2_LOW; }
  else return INT16_MIN;
  uint8_t high, low;
  if (!readRemoteParts(high_reg, low_reg, &high, &low)) return INT16_MIN;
  uint8_t low_nibble = (low >> 4) & 0x0F;
  return combineSigned12(high, low_nibble);
}

bool TMP4719::setRemoteTLow(uint8_t channel, float temp_c) {
  uint8_t high_reg, low_reg;
  if (channel == 1) { high_reg = TMP4719_REG_TLOW_LIMIT_REM_CH1_HIGH; low_reg = TMP4719_REG_TLOW_LIMIT_REM_CH1_LOW; }
  else if (channel == 2) { high_reg = TMP4719_REG_TLOW_LIMIT_REM_CH2_HIGH; low_reg = TMP4719_REG_TLOW_LIMIT_REM_CH2_LOW; }
  else return false;
  uint8_t high, low; if (!encodeFloatToRemoteRaw12(temp_c, &high, &low)) return false;
  // write high then low to minimize transient inconsistent reads
  if (!writeRegister(high_reg, high)) return false;
  if (!writeRegister(low_reg, low)) return false;
  return true;
}

int16_t TMP4719::getRemoteTLowRaw(uint8_t channel) {
  uint8_t high_reg, low_reg;
  if (channel == 1) { high_reg = TMP4719_REG_TLOW_LIMIT_REM_CH1_HIGH; low_reg = TMP4719_REG_TLOW_LIMIT_REM_CH1_LOW; }
  else if (channel == 2) { high_reg = TMP4719_REG_TLOW_LIMIT_REM_CH2_HIGH; low_reg = TMP4719_REG_TLOW_LIMIT_REM_CH2_LOW; }
  else return INT16_MIN;
  uint8_t high, low; if (!readRemoteParts(high_reg, low_reg, &high, &low)) return INT16_MIN;
  uint8_t low_nibble = (low >> 4) & 0x0F;
  return combineSigned12(high, low_nibble);
}

// T_CRIT
bool TMP4719::setTHighCritLocal(int8_t value) { return writeRegister(TMP4719_REG_THIGH_CRIT_LOCAL, (uint8_t)value); }
bool TMP4719::setTHighCritRemote(uint8_t channel, int8_t value) {
  if (channel == 1) return writeRegister(TMP4719_REG_THIGH_CRIT_REM_CH1, (uint8_t)value);
  if (channel == 2) return writeRegister(TMP4719_REG_THIGH_CRIT_REM_CH2, (uint8_t)value);
  return false;
}

// Alert mask
int16_t TMP4719::readAlertMask() { uint8_t b; if (!readRegister(TMP4719_REG_ALERT_MASK, &b)) return -1; return (int16_t)b; }
bool TMP4719::writeAlertMask(uint8_t mask) { return writeRegister(TMP4719_REG_ALERT_MASK, mask); }

// One-shot
bool TMP4719::triggerOneShot(uint8_t value) {
  if (value == 0) value = 1;
  return writeRegister(TMP4719_REG_ONE_SHOT, value);
}

// Conversion helpers
float TMP4719::decodeRemoteRawToFloat(int16_t raw12) {
  // raw12 is signed 12-bit value in int16_t
  return ((float)raw12) * 0.0625f; // LSB = 0.0625°C
}

bool TMP4719::encodeFloatToRemoteRaw12(float temp_c, uint8_t* high, uint8_t* low) {
  if (!high || !low) return false;
  // Convert degrees C to signed 12-bit value (LSB = 0.0625C)
  float steps = temp_c / 0.0625f;
  int32_t r = (int32_t)lround(steps);
  // clamp to signed 12-bit range [-2048 .. 2047]
  if (r < -2048) r = -2048;
  if (r >  2047) r = 2047;
  uint16_t encoded = (uint16_t)(r & 0x0FFF);
  // high byte contains bits [11:4]
  *high = (uint8_t)((encoded >> 4) & 0xFF);
  // low register contains bits [3:0] in physical bits [7:4]; lower physical bits [3:0] are reserved -> set 0
  *low  = (uint8_t)(((encoded & 0x0F) << 4) & 0xF0);
  return true;
}

// Private helpers & utilities
bool TMP4719::readRemoteParts(uint8_t high_reg, uint8_t low_reg, uint8_t* high, uint8_t* low) {
  if (!high || !low) return false;
  if (!readRegister(high_reg, high)) return false;
  if (!readRegister(low_reg, low)) return false;
  return true;
}

int16_t TMP4719::combineSigned12(uint8_t high, uint8_t low_nibble) {
  uint16_t raw = ((uint16_t)high << 4) | (low_nibble & 0x0F);
  // sign extend 12-bit
  if (raw & 0x0800) {
    raw |= 0xF000;
  }
  return (int16_t)raw;
}

uint16_t TMP4719::saturateSigned12(int32_t val) {
  if (val < -2048) val = -2048;
  if (val >  2047) val = 2047;
  return (uint16_t)(val & 0x0FFF);
}

// Set address
void TMP4719::setAddress(uint8_t addr) {
  _addr = addr & 0x7F;
}

