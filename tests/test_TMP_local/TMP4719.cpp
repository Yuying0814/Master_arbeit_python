/*
TMP4719 Arduino I2C driver implementation file (final revision)
*/

#include "TMP4719.h"

// section_name: Includes

// section_name: Constructor Implementation

TMP4719::TMP4719(uint8_t address, TwoWire &wire) : _address(address), _wire(&wire) {}

// section_name: Public API Implementations

bool TMP4719::begin() {
  uint8_t chipID = readChipID();
  return (chipID == 0x21);
}

float TMP4719::readLocalTemperature() {
  int8_t rawTemp = static_cast<int8_t>(readRegister(TMP4719_REG_TEMP_LOCAL));
  return int8ToFloatTemp(rawTemp);
}

float TMP4719::readRemoteTemperature(uint8_t channel) {
  uint8_t highReg, lowReg;
  if (channel == 1) {
    highReg = TMP4719_REG_TEMP_REMOTE_CH1_HIGH;
    lowReg = TMP4719_REG_TEMP_REMOTE_CH1_LOW;
  } else { // channel == 2
    highReg = TMP4719_REG_TEMP_REMOTE_CH2_HIGH;
    lowReg = TMP4719_REG_TEMP_REMOTE_CH2_LOW;
  }

  uint8_t highByte = readRegister(highReg);
  uint8_t lowByte = readRegister(lowReg);
  
  // Combine high byte (bits 11:4) and low nibble (bits 3:0)
  int16_t combined = ((highByte & 0xFF) << 4) | ((lowByte >> 4) & 0x0F);
  
  // Sign extend for 12-bit two's complement (bit 11 is the sign bit)
  if (combined & 0x0800) {
    combined |= 0xF000;
  }
  return int16ToFloatTemp(combined);
}

uint8_t TMP4719::getStatus() {
  return readRegister(TMP4719_REG_STATUS);
}

void TMP4719::getStatusStruct(StatusFlags *status) {
  uint8_t reg = getStatus();
  status->adcBusy = (reg & 0x80) != 0;
  status->tempHigh = (reg & 0x10) != 0;
  status->tempLow = (reg & 0x08) != 0;
  status->remoteFault = (reg & 0x04) != 0;
  status->tCrit = (reg & 0x02) != 0;
}

void TMP4719::setOperationMode(OperationMode mode) {
  uint8_t configPri = readRegister(TMP4719_REG_CONFIGURATION_PRIMARY);
  uint8_t configSha = readRegister(TMP4719_REG_CONFIGURATION_SHARED);
  
  // Preserve all bits except Mode (bit 6)
  // Mask: 0xBF = 0b10111111 (clears bit 6, preserves 7,5-0)
  uint8_t newConfigPri = (configPri & 0xBF) | ((static_cast<uint8_t>(mode) << 6) & 0x40);
  uint8_t newConfigSha = (configSha & 0xBF) | ((static_cast<uint8_t>(mode) << 6) & 0x40);
  
  writeRegister(TMP4719_REG_CONFIGURATION_PRIMARY, newConfigPri);
  writeRegister(TMP4719_REG_CONFIGURATION_SHARED, newConfigSha);
}

void TMP4719::setAlertMode(AlertModeType alertMode) {
  uint8_t configPri = readRegister(TMP4719_REG_CONFIGURATION_PRIMARY);
  uint8_t configSha = readRegister(TMP4719_REG_CONFIGURATION_SHARED);
  
  // Preserve all bits except Alert_Mode (bit 5)
  // Mask: 0xDF = 0b11011111 (clears bit 5, preserves 7,6,4-0)
  uint8_t newConfigPri = (configPri & 0xDF) | ((static_cast<uint8_t>(alertMode) << 5) & 0x20);
  uint8_t newConfigSha = (configSha & 0xDF) | ((static_cast<uint8_t>(alertMode) << 5) & 0x20);
  
  writeRegister(TMP4719_REG_CONFIGURATION_PRIMARY, newConfigPri);
  writeRegister(TMP4719_REG_CONFIGURATION_SHARED, newConfigSha);
}

void TMP4719::setAlertMask(bool maskLocal, bool maskCh1, bool maskCh2) {
  uint8_t mask = 0;
  if (maskLocal) mask |= 0x01; // Mask_L bit 0
  if (maskCh1) mask |= 0x02;   // Mask_Ch1 bit 1
  if (maskCh2) mask |= 0x04;   // Mask_Ch2 bit 2
  
  writeRegister(TMP4719_REG_ALERT_MASK, mask & 0x07);
}

void TMP4719::setConversionPeriod(ConvPeriod period) {
  uint8_t value = static_cast<uint8_t>(period);
  // Only lower 4 bits are used (bits 3:0)
  writeRegister(TMP4719_REG_CONV_PERIOD_PRIMARY, value & 0x0F);
  writeRegister(TMP4719_REG_CONV_PERIOD_SHARED, value & 0x0F);
}

void TMP4719::setLocalHighLimit(int8_t tempC) {
  int8_t rawValue = floatToInt8Temp(static_cast<float>(tempC));
  // Pass int8_t directly - bit pattern is preserved when converting to uint8_t parameter
  writeRegister(TMP4719_REG_THIGH_LIMIT_LOCAL_PRIMARY, rawValue);
  writeRegister(TMP4719_REG_THIGH_LIMIT_LOCAL_SHARED, rawValue);
}

void TMP4719::setLocalLowLimit(int8_t tempC) {
  int8_t rawValue = floatToInt8Temp(static_cast<float>(tempC));
  // Pass int8_t directly - bit pattern is preserved when converting to uint8_t parameter
  writeRegister(TMP4719_REG_TLOW_LIMIT_LOCAL_PRIMARY, rawValue);
  writeRegister(TMP4719_REG_TLOW_LIMIT_LOCAL_SHARED, rawValue);
}

void TMP4719::setRemoteHighLimit(uint8_t channel, float tempC) {
  int16_t rawValue = floatToInt12Temp(tempC);
  uint8_t highByte = (rawValue >> 4) & 0xFF; // bits 11:4
  uint8_t lowByteValue = (rawValue & 0x0F) << 4; // bits 3:0 shifted to upper nibble, lower nibble = 0
  
  if (channel == 1) {
    writeRegister(TMP4719_REG_THIGH_LIMIT_REMOTE_CH1_HIGH_PRIMARY, highByte);
    writeRegister(TMP4719_REG_THIGH_LIMIT_REMOTE_CH1_HIGH_SHARED, highByte);
    writeRegister(TMP4719_REG_THIGH_LIMIT_REMOTE_CH1_LOW, lowByteValue);
  } else { // channel == 2
    writeRegister(TMP4719_REG_THIGH_LIMIT_REMOTE_CH2_HIGH, highByte);
    writeRegister(TMP4719_REG_THIGH_LIMIT_REMOTE_CH2_LOW, lowByteValue);
  }
}

void TMP4719::setRemoteLowLimit(uint8_t channel, float tempC) {
  int16_t rawValue = floatToInt12Temp(tempC);
  uint8_t highByte = (rawValue >> 4) & 0xFF; // bits 11:4
  uint8_t lowByteValue = (rawValue & 0x0F) << 4; // bits 3:0 shifted to upper nibble, lower nibble = 0
  
  if (channel == 1) {
    writeRegister(TMP4719_REG_TLOW_LIMIT_REMOTE_CH1_HIGH_PRIMARY, highByte);
    writeRegister(TMP4719_REG_TLOW_LIMIT_REMOTE_CH1_HIGH_SHARED, highByte);
    writeRegister(TMP4719_REG_TLOW_LIMIT_REMOTE_CH1_LOW, lowByteValue);
  } else { // channel == 2
    writeRegister(TMP4719_REG_TLOW_LIMIT_REMOTE_CH2_HIGH, highByte);
    writeRegister(TMP4719_REG_TLOW_LIMIT_REMOTE_CH2_LOW, lowByteValue);
  }
}

void TMP4719::setTCritLimit(Channel channel, int8_t tempC) {
  uint8_t regAddr;
  switch (channel) {
    case Channel::LOCAL:
      regAddr = TMP4719_REG_THIGH_CRIT_LOCAL;
      break;
    case Channel::CH1:
      regAddr = TMP4719_REG_THIGH_CRIT_REMOTE_CH1;
      break;
    case Channel::CH2:
      regAddr = TMP4719_REG_THIGH_CRIT_REMOTE_CH2;
      break;
    default:
      return; // Invalid channel
  }
  // Pass int8_t directly - bit pattern is preserved when converting to uint8_t parameter
  writeRegister(regAddr, tempC);
}

void TMP4719::setHysteresis(uint8_t hystC) {
  if (hystC > 31) hystC = 31; // Clamp to max 5-bit value
  writeRegister(TMP4719_REG_HYSTERESIS, hystC & 0x1F);
}

void TMP4719::setEtaFactor(uint8_t channel, uint8_t etaValue) {
  if (etaValue < 0x08) etaValue = 0x08;
  if (etaValue > 0x37) etaValue = 0x37;
  uint8_t regAddr = (channel == 1) ? TMP4719_REG_ETA_FACTOR_CH1 : TMP4719_REG_ETA_FACTOR_CH2;
  writeRegister(regAddr, etaValue);
}

void TMP4719::setFilterLevel(FilterLevel level) {
  uint8_t value = static_cast<uint8_t>(level);
  writeRegister(TMP4719_REG_FILTER_CONTROL, value & 0x03);
}

bool TMP4719::triggerOneShot() {
  // Check if device is in Shutdown mode (Mode bit = 1)
  uint8_t config = readRegister(TMP4719_REG_CONFIGURATION_PRIMARY);
  if ((config & 0x40) == 0) {
    return false; // Not in Shutdown mode, one-shot has no effect
  }
  writeRegister(TMP4719_REG_ONE_SHOT, 0x01);
  return true;
}

void TMP4719::getDiodeFaultStatus(DiodeFaultStatus *fault) {
  uint8_t reg = readRegister(TMP4719_REG_DIODE_FAULT);
  fault->ch1Open = (reg & 0x02) != 0;    // Ch1_Open bit 1
  fault->ch2Open = (reg & 0x04) != 0;    // Ch2_Open bit 2
  fault->shortCondition = (reg & 0x08) != 0; // Short bit 3
}

void TMP4719::getHighLimitStatus(LimitStatus *status) {
  uint8_t reg = readRegister(TMP4719_REG_THIGH_LIMIT_STATUS);
  status->localLimit = (reg & 0x01) != 0;
  status->ch1Limit = (reg & 0x02) != 0;
  status->ch2Limit = (reg & 0x04) != 0;
}

void TMP4719::getLowLimitStatus(LimitStatus *status) {
  uint8_t reg = readRegister(TMP4719_REG_TLOW_LIMIT_STATUS);
  status->localLimit = (reg & 0x01) != 0;
  status->ch1Limit = (reg & 0x02) != 0;
  status->ch2Limit = (reg & 0x04) != 0;
}

void TMP4719::getTCritLimitStatus(LimitStatus *status) {
  uint8_t reg = readRegister(TMP4719_REG_TCRIT_LIMIT_STATUS);
  status->localLimit = (reg & 0x01) != 0;
  status->ch1Limit = (reg & 0x02) != 0;
  status->ch2Limit = (reg & 0x04) != 0;
}

uint8_t TMP4719::readChipID() {
  return readRegister(TMP4719_REG_CHIP_ID);
}

uint8_t TMP4719::readVendorID() {
  return readRegister(TMP4719_REG_VENDOR_ID);
}

void TMP4719::readDeviceRevID(uint8_t *deviceID, uint8_t *revID) {
  uint8_t reg = readRegister(TMP4719_REG_DEVICE_REV_ID);
  *deviceID = (reg >> 4) & 0x0F;
  *revID = reg & 0x0F;
}

void TMP4719::writeScratchpad(uint8_t scratchpadNum, uint8_t value) {
  uint8_t regAddr = (scratchpadNum == 1) ? TMP4719_REG_SCRATCHPAD1 : TMP4719_REG_SCRATCHPAD2;
  writeRegister(regAddr, value);
}

uint8_t TMP4719::readScratchpad(uint8_t scratchpadNum) {
  uint8_t regAddr = (scratchpadNum == 1) ? TMP4719_REG_SCRATCHPAD1 : TMP4719_REG_SCRATCHPAD2;
  return readRegister(regAddr);
}

// section_name: Private Helper Implementations

uint8_t TMP4719::readRegister(uint8_t regAddr) {
  _wire->beginTransmission(_address);
  _wire->write(regAddr);
  _wire->endTransmission(false);
  
  _wire->requestFrom(static_cast<uint8_t>(_address), static_cast<uint8_t>(1));
  return _wire->read();
}

void TMP4719::writeRegister(uint8_t regAddr, uint8_t value) {
  _wire->beginTransmission(_address);
  _wire->write(regAddr);
  _wire->write(value);
  _wire->endTransmission();
}

uint16_t TMP4719::readRegister16(uint8_t regAddrHigh, uint8_t regAddrLow) {
  uint8_t highByte = readRegister(regAddrHigh);
  uint8_t lowByte = readRegister(regAddrLow);
  return (static_cast<uint16_t>(highByte) << 8) | lowByte;
}

void TMP4719::writeRegister16(uint8_t regAddrHigh, uint8_t regAddrLow, uint16_t value) {
  writeRegister(regAddrHigh, static_cast<uint8_t>((value >> 8) & 0xFF));
  // For low byte registers: write only upper nibble with data (value & 0x0F) << 4
  writeRegister(regAddrLow, static_cast<uint8_t>((value & 0x0F) << 4));
}

// section_name: Temperature Conversion Helpers

float TMP4719::int8ToFloatTemp(int8_t rawValue) {
  // 8-bit two's complement with LSB = 1°C
  return static_cast<float>(rawValue);
}

float TMP4719::int16ToFloatTemp(int16_t rawValue) {
  // Accepts sign-extended 12-bit two's complement value (bits 15:12 are copies of bit 11). LSB = 0.0625°C
  return static_cast<float>(rawValue) * 0.0625f;
}

int8_t TMP4719::floatToInt8Temp(float tempC) {
  // Clamp to valid range for 8-bit two's complement (-128 to 127)
  if (tempC < -128.0f) tempC = -128.0f;
  if (tempC > 127.0f) tempC = 127.0f;
  return static_cast<int8_t>(round(tempC));
}

int16_t TMP4719::floatToInt12Temp(float tempC) {
  // Clamp to valid range for 12-bit two's complement (-127.875 to 127.875)
  if (tempC < -127.875f) tempC = -127.875f;
  if (tempC > 127.875f) tempC = 127.875f;
  
  // Convert to 12-bit value with LSB = 0.0625°C
  int16_t rawValue = static_cast<int16_t>(round(tempC / 0.0625f));
  
  // Ensure only lower 12 bits are used
  return rawValue & 0x0FFF;
}

