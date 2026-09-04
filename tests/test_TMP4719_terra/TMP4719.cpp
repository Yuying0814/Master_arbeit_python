/*
I2C transactions, safe field access, decoding, validation, and register-level TMP4719 behavior.
*/

#include "TMP4719.h"

// I2C transport and encoding helpers: Implement reliable single-byte Wire transactions, sign extension, local/remote conversion, and channel-to-register selection.

TMP4719::TMP4719(TwoWire &wire, uint8_t address)
  : wire_(&wire), address_(address) {}

bool TMP4719::readRegister(uint8_t reg, uint8_t &value) {
  // Write register pointer with a repeated start then request one byte
  wire_->beginTransmission(address_);
  wire_->write(reg);
  uint8_t err = wire_->endTransmission(false); // send restart
  if (err != 0) return false;

  uint8_t got = wire_->requestFrom((int)address_, (int)1);
  if (got != 1) return false;
  int v = wire_->read();
  if (v < 0) return false;
  value = (uint8_t)v;
  return true;
}

bool TMP4719::writeRegister(uint8_t reg, uint8_t value) {
  wire_->beginTransmission(address_);
  wire_->write(reg);
  wire_->write(value);
  uint8_t err = wire_->endTransmission(true);
  return (err == 0);
}

uint8_t TMP4719::remoteHighReg(RemoteChannel ch) const {
  return (ch == RemoteChannel::CH1) ? REG_TEMP_REMOTE_CH1_HIGH : REG_TEMP_REMOTE_CH2_HIGH;
}
uint8_t TMP4719::remoteLowReg(RemoteChannel ch) const {
  return (ch == RemoteChannel::CH1) ? REG_TEMP_REMOTE_CH1_LOW : REG_TEMP_REMOTE_CH2_LOW;
}
uint8_t TMP4719::remoteHighLimitReg(RemoteChannel ch) const {
  return (ch == RemoteChannel::CH1) ? REG_THIGH_REMOTE_CH1_HIGH : REG_THIGH_REMOTE_CH2_HIGH;
}
uint8_t TMP4719::remoteLowLimitReg(RemoteChannel ch) const {
  return (ch == RemoteChannel::CH1) ? REG_THIGH_REMOTE_CH1_LOW : REG_THIGH_REMOTE_CH2_LOW;
}
uint8_t TMP4719::remoteCritReg(RemoteChannel ch) const {
  return (ch == RemoteChannel::CH1) ? REG_THIGH_CRIT_REMOTE_CH1 : REG_THIGH_CRIT_REMOTE_CH2;
}
uint8_t TMP4719::etaReg(RemoteChannel ch) const {
  return (ch == RemoteChannel::CH1) ? REG_ETA_CH1 : REG_ETA_CH2;
}

bool TMP4719::readRemoteRaw12(RemoteChannel channel, int16_t &raw12) {
  uint8_t high, low;
  if (!readRegister(remoteHighReg(channel), high)) return false;
  if (!readRegister(remoteLowReg(channel), low)) return false;
  // high contains bits [11:4]; low contains bits [7:4] => data bits [3:0]
  uint16_t raw = ((uint16_t)high << 4) | (uint16_t)(low >> 4);
  // Sign-extend 12-bit two's complement to 16-bit signed
  if (raw & 0x800) {
    raw12 = (int16_t)(raw | 0xF000);
  } else {
    raw12 = (int16_t)raw;
  }
  return true;
}

// Public API implementation: Implement all public APIs declared in the header using only mapped registers and documented side effects.

bool TMP4719::begin() {
  uint8_t chip, vendor;
  if (!readRegister(REG_CHIP_ID, chip)) return false;
  if (!readRegister(REG_VENDOR_ID, vendor)) return false;
  return (chip == 0x21) && (vendor == 0x60);
}

bool TMP4719::readLocalTemperature(int8_t &temperatureC) {
  uint8_t v;
  if (!readRegister(REG_TEMP_LOCAL, v)) return false;
  temperatureC = (int8_t)v; // register is 8-bit two's complement, 1C LSB
  return true;
}

bool TMP4719::readRemoteTemperature(RemoteChannel channel, float &temperatureC) {
  int16_t raw12;
  if (!readRemoteRaw12(channel, raw12)) return false;
  // raw12 is signed integer in units of 1/16 C
  temperatureC = ((float)raw12) * REMOTE_LSB_C;
  return true;
}

bool TMP4719::isAdcBusy(bool &busy) {
  uint8_t s;
  if (!readRegister(REG_STATUS, s)) return false;
  busy = (s & STATUS_ADC_BUSY_MASK) != 0;
  return true;
}

bool TMP4719::setOperatingMode(OperatingMode mode) {
  uint8_t cfg;
  if (!readRegister(REG_CONFIGURATION, cfg)) return false;
  if (mode == OperatingMode::SHUTDOWN) cfg |= CONFIG_MODE_BIT;
  else cfg &= ~CONFIG_MODE_BIT;
  return writeRegister(REG_CONFIGURATION, cfg);
}

bool TMP4719::getOperatingMode(OperatingMode &mode) {
  uint8_t cfg;
  if (!readRegister(REG_CONFIGURATION, cfg)) return false;
  mode = (cfg & CONFIG_MODE_BIT) ? OperatingMode::SHUTDOWN : OperatingMode::CONTINUOUS;
  return true;
}

bool TMP4719::triggerOneShot() {
  // Only effective when device is in Shutdown mode.
  OperatingMode m;
  if (!getOperatingMode(m)) return false;
  if (m != OperatingMode::SHUTDOWN) return false; // guarded one-shot
  // Writing any value triggers one-shot; use 0x01
  return writeRegister(REG_ONE_SHOT, 0x01);
}

bool TMP4719::setConversionPeriodCode(uint8_t code) {
  if (code > 8) return false; // codes 9..15 rejected per plan
  uint8_t v;
  if (!readRegister(REG_CONV_PERIOD, v)) return false;
  v &= 0xF0; // preserve upper reserved bits (though per map they should be zero)
  v |= (code & 0x0F);
  return writeRegister(REG_CONV_PERIOD, v);
}

bool TMP4719::getConversionPeriodCode(uint8_t &code) {
  uint8_t v;
  if (!readRegister(REG_CONV_PERIOD, v)) return false;
  code = v & 0x0F;
  return true;
}

bool TMP4719::setAlertLimits(TemperatureChannel channel, float highC, float lowC) {
  if (channel == TemperatureChannel::LOCAL) {
    // Local thresholds are integral 1C LSB, 8-bit two's complement
    // Validate integer values in int8_t
    int16_t hi = (int16_t)roundf(highC);
    int16_t lo = (int16_t)roundf(lowC);
    if (hi < -128 || hi > 127 || lo < -128 || lo > 127) return false;
    if (!writeRegister(REG_THIGH_LOCAL, (uint8_t)(int8_t)hi)) return false;
    if (!writeRegister(REG_TLOW_LOCAL, (uint8_t)(int8_t)lo)) return false;
    return true;
  } else {
    // Remote channels: full 12-bit signed with LSB 0.0625C. Write components in separate single-byte transactions.
    RemoteChannel rch = (channel == TemperatureChannel::REMOTE1) ? RemoteChannel::CH1 : RemoteChannel::CH2;
    auto encode12 = [](float temp)->int32_t { return (int32_t)lrintf(temp / REMOTE_LSB_C); };
    int32_t hi_raw = encode12(highC);
    int32_t lo_raw = encode12(lowC);
    // 12-bit signed range -2048..2047
    if (hi_raw < -2048 || hi_raw > 2047) return false;
    if (lo_raw < -2048 || lo_raw > 2047) return false;
    uint16_t uhi = (uint16_t)(hi_raw & 0x0FFF);
    uint16_t ulo = (uint16_t)(lo_raw & 0x0FFF);
    uint8_t hi_byte = (uint8_t)((uhi >> 4) & 0xFF);
    uint8_t hi_lowbyte = (uint8_t)(((uhi & 0x0F) << 4) & 0xF0); // bits stored in 7:4, lower nibble reserved=0
    uint8_t lo_byte = (uint8_t)((ulo >> 4) & 0xFF);
    uint8_t lo_lowbyte = (uint8_t)(((ulo & 0x0F) << 4) & 0xF0);
    // Write high parts then low parts using single-byte transactions
    if (!writeRegister(remoteHighLimitReg(rch), hi_byte)) return false;
    if (!writeRegister(remoteLowLimitReg(rch), hi_lowbyte)) return false;
    if (!writeRegister((rch == RemoteChannel::CH1) ? REG_TLOW_REMOTE_CH1_HIGH : REG_TLOW_REMOTE_CH2_HIGH, lo_byte)) return false;
    if (!writeRegister((rch == RemoteChannel::CH1) ? REG_TLOW_REMOTE_CH1_LOW  : REG_TLOW_REMOTE_CH2_LOW, lo_lowbyte)) return false;
    return true;
  }
}

bool TMP4719::getAlertLimits(TemperatureChannel channel, float &highC, float &lowC) {
  if (channel == TemperatureChannel::LOCAL) {
    uint8_t hi, lo;
    if (!readRegister(REG_THIGH_LOCAL, hi)) return false;
    if (!readRegister(REG_TLOW_LOCAL, lo)) return false;
    highC = (float)(int8_t)hi;
    lowC = (float)(int8_t)lo;
    return true;
  } else {
    RemoteChannel rch = (channel == TemperatureChannel::REMOTE1) ? RemoteChannel::CH1 : RemoteChannel::CH2;
    // High limit read
    uint8_t hi_high, hi_low;
    if (!readRegister(remoteHighLimitReg(rch), hi_high)) return false;
    if (!readRegister(remoteLowLimitReg(rch), hi_low)) return false;
    uint16_t hi_raw = ((uint16_t)hi_high << 4) | ((hi_low >> 4) & 0x0F);
    if (hi_raw & 0x800) hi_raw |= 0xF000;
    int16_t hi_signed = (int16_t)hi_raw;
    // Low limit read: corresponding registers
    uint8_t lo_high, lo_low;
    uint8_t lo_high_reg = (rch == RemoteChannel::CH1) ? REG_TLOW_REMOTE_CH1_HIGH : REG_TLOW_REMOTE_CH2_HIGH;
    uint8_t lo_low_reg  = (rch == RemoteChannel::CH1) ? REG_TLOW_REMOTE_CH1_LOW  : REG_TLOW_REMOTE_CH2_LOW;
    if (!readRegister(lo_high_reg, lo_high)) return false;
    if (!readRegister(lo_low_reg, lo_low)) return false;
    uint16_t lo_raw = ((uint16_t)lo_high << 4) | ((lo_low >> 4) & 0x0F);
    if (lo_raw & 0x800) lo_raw |= 0xF000;
    int16_t lo_signed = (int16_t)lo_raw;
    highC = ((float)hi_signed) * REMOTE_LSB_C;
    lowC  = ((float)lo_signed) * REMOTE_LSB_C;
    return true;
  }
}

bool TMP4719::setCriticalLimit(TemperatureChannel channel, int8_t temperatureC) {
  uint8_t reg;
  if (channel == TemperatureChannel::LOCAL) reg = REG_THIGH_CRIT_LOCAL;
  else reg = remoteCritReg((channel == TemperatureChannel::REMOTE1) ? RemoteChannel::CH1 : RemoteChannel::CH2);
  return writeRegister(reg, (uint8_t)temperatureC);
}

bool TMP4719::getCriticalLimit(TemperatureChannel channel, int8_t &temperatureC) {
  uint8_t reg;
  if (channel == TemperatureChannel::LOCAL) reg = REG_THIGH_CRIT_LOCAL;
  else reg = remoteCritReg((channel == TemperatureChannel::REMOTE1) ? RemoteChannel::CH1 : RemoteChannel::CH2);
  uint8_t v;
  if (!readRegister(reg, v)) return false;
  temperatureC = (int8_t)v;
  return true;
}

bool TMP4719::setHysteresis(uint8_t degreesC) {
  if (degreesC > 31) return false; // 5-bit field range 0..31
  uint8_t v;
  if (!readRegister(REG_HYSTERESIS, v)) return false;
  v &= 0xE0; // clear bits 4:0
  v |= (degreesC & 0x1F);
  return writeRegister(REG_HYSTERESIS, v);
}

bool TMP4719::getHysteresis(uint8_t &degreesC) {
  uint8_t v;
  if (!readRegister(REG_HYSTERESIS, v)) return false;
  degreesC = v & 0x1F;
  return true;
}

bool TMP4719::setAlertMode(AlertMode mode) {
  uint8_t v;
  if (!readRegister(REG_CONFIGURATION, v)) return false;
  if (mode == AlertMode::COMPARATOR) v |= CONFIG_ALERT_MODE_BIT;
  else v &= ~CONFIG_ALERT_MODE_BIT;
  return writeRegister(REG_CONFIGURATION, v);
}

bool TMP4719::setGlobalAlertMasked(bool masked) {
  uint8_t v;
  if (!readRegister(REG_CONFIGURATION, v)) return false;
  if (masked) v |= CONFIG_ALERT_MASK_BIT;
  else v &= ~CONFIG_ALERT_MASK_BIT; // write 0 to clear mask
  return writeRegister(REG_CONFIGURATION, v);
}

bool TMP4719::setChannelAlertMasked(TemperatureChannel channel, bool masked) {
  uint8_t v;
  if (!readRegister(REG_ALERT_MASK, v)) return false;
  uint8_t bit = 0;
  if (channel == TemperatureChannel::LOCAL) bit = 0;
  else if (channel == TemperatureChannel::REMOTE1) bit = 1;
  else bit = 2;
  if (masked) v |= (1 << bit);
  else v &= ~(1 << bit);
  return writeRegister(REG_ALERT_MASK, v);
}

bool TMP4719::readStatus(StatusFlags &status) {
  uint8_t s;
  if (!readRegister(REG_STATUS, s)) return false;
  status.adcBusy = (s & STATUS_ADC_BUSY_MASK) != 0;
  status.anyHigh = (s & STATUS_THIGH_MASK) != 0;
  status.anyLow  = (s & STATUS_TLOW_MASK) != 0;
  status.remoteFault = (s & STATUS_REMOTE_FAULT_MASK) != 0;
  status.anyTCrit = (s & STATUS_TCRIT_MASK) != 0;
  // Note: In SMBus Alert interrupt mode, reading Status clears its limit flags and sets Configuration.Alert_Mask; caller must be aware of read-side effects.
  return true;
}

bool TMP4719::readLimitStatus(uint8_t &highFlags, uint8_t &lowFlags, uint8_t &criticalFlags) {
  // Read order: high, low, critical. Per datasheet, high/low reads may clear flags in interrupt mode.
  uint8_t h, l, c;
  if (!readRegister(REG_HIGH_LIMIT_STATUS, h)) return false;
  if (!readRegister(REG_LOW_LIMIT_STATUS, l)) return false;
  if (!readRegister(REG_TCRIT_LIMIT_STATUS, c)) return false;
  highFlags = h & 0x07; // low three bits are Local/Ch1/Ch2
  lowFlags  = l & 0x07;
  criticalFlags = c & 0x07; // reading critical does not clear according to map
  return true;
}

bool TMP4719::readDiodeFaults(uint8_t &faultFlags) {
  uint8_t v;
  if (!readRegister(REG_DIODE_FAULT, v)) return false;
  // return masked documented bits 3:1 (bit3=Short, bit2=Ch2_Open, bit1=Ch1_Open)
  faultFlags = (v >> 1) & 0x07;
  return true;
}

bool TMP4719::setFilterLevel(FilterLevel level) {
  uint8_t v;
  if (!readRegister(REG_FILTER_CONTROL, v)) return false;
  v &= 0xFC; // clear bits 1:0
  v |= (uint8_t)level & 0x03;
  return writeRegister(REG_FILTER_CONTROL, v);
}

bool TMP4719::setIdealityCode(RemoteChannel channel, uint8_t code) {
  // Validated range 0x08..0x37 inclusive
  if (code < 0x08 || code > 0x37) return false;
  return writeRegister(etaReg(channel), code);
}

bool TMP4719::getIdealityCode(RemoteChannel channel, uint8_t &code) {
  return readRegister(etaReg(channel), code);
}

bool TMP4719::writeScratchpad(uint8_t index, uint8_t value) {
  uint8_t reg = 0;
  if (index == 1) reg = REG_SCRATCHPAD1;
  else if (index == 2) reg = REG_SCRATCHPAD2;
  else return false;
  return writeRegister(reg, value);
}

bool TMP4719::readScratchpad(uint8_t index, uint8_t &value) {
  uint8_t reg = 0;
  if (index == 1) reg = REG_SCRATCHPAD1;
  else if (index == 2) reg = REG_SCRATCHPAD2;
  else return false;
  return readRegister(reg, value);
}

bool TMP4719::readDeviceId(uint8_t &chipId, uint8_t &vendorId, uint8_t &deviceId, uint8_t &revisionId) {
  uint8_t devrev;
  if (!readRegister(REG_CHIP_ID, chipId)) return false;
  if (!readRegister(REG_VENDOR_ID, vendorId)) return false;
  if (!readRegister(REG_DEVICE_REV, devrev)) return false;
  deviceId = (devrev >> 4) & 0x0F;
  revisionId = devrev & 0x0F;
  return true;
}

