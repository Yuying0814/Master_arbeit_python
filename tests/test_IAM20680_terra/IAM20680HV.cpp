/*
Dual Wire/SPI transactions and all documented API implementations.
*/

// Transport implementation: Implement I2C and SPI register bursts, CS timing, error tracking, and masked writes.

#include "IAM20680HV.h"

// Define default SPI settings (1 MHz, MSB first, MODE0) as a conservative default
const SPISettings IAM20680HV::_spiSettingsDefault = SPISettings(1000000, MSBFIRST, SPI_MODE0);

// I2C constructor
IAM20680HV::IAM20680HV(TwoWire &wire, uint8_t address) {
  _transport = TransportType::I2C;
  _wire = &wire;
  _i2cAddr = address;
}

// SPI constructor
IAM20680HV::IAM20680HV(SPIClass &spi, uint8_t csPin) {
  _transport = TransportType::SPI;
  _spi = &spi;
  _csPin = csPin;
  pinMode(_csPin, OUTPUT);
  digitalWrite(_csPin, HIGH);
}

bool IAM20680HV::readRegisters(uint8_t reg, uint8_t *buffer, size_t length) {
  if (length == 0) return true;
  if (_transport == TransportType::I2C) {
    // I2C: write register address, repeated-start read
    _wire->beginTransmission(_i2cAddr);
    _wire->write(reg);
    uint8_t res = _wire->endTransmission(false); // restart
    _lastError = res;
    if (res != 0) return false;

    size_t received = _wire->requestFrom((int)_i2cAddr, (int)length, (uint8_t)true);
    if (received != length) {
      _lastError = 5; // use 5 = timeout/short read
      return false;
    }
    for (size_t i = 0; i < length; ++i) {
      int v = _wire->read();
      buffer[i] = (uint8_t)v;
    }
    _lastError = 0;
    return true;
  } else {
    // SPI: MSB of first byte is read flag (1), then 7-bit address
    uint8_t cmd = 0x80 | (reg & 0x7F);
    _spi->beginTransaction(_spiSettingsDefault);
    digitalWrite(_csPin, LOW);
    _spi->transfer(cmd);
    for (size_t i = 0; i < length; ++i) {
      buffer[i] = _spi->transfer(0x00);
    }
    digitalWrite(_csPin, HIGH);
    _spi->endTransaction();
    _lastError = 0;
    return true;
  }
}

bool IAM20680HV::writeRegisters(uint8_t reg, const uint8_t *buffer, size_t length) {
  if (length == 0) return true;
  if (_transport == TransportType::I2C) {
    _wire->beginTransmission(_i2cAddr);
    _wire->write(reg);
    _wire->write(buffer, (size_t)length);
    uint8_t res = _wire->endTransmission(true);
    _lastError = res;
    return (res == 0);
  } else {
    // SPI write: MSB = 0 then 7-bit address
    uint8_t cmd = (reg & 0x7F);
    _spi->beginTransaction(_spiSettingsDefault);
    digitalWrite(_csPin, LOW);
    _spi->transfer(cmd);
    for (size_t i = 0; i < length; ++i) {
      _spi->transfer(buffer[i]);
    }
    digitalWrite(_csPin, HIGH);
    _spi->endTransaction();
    _lastError = 0;
    return true;
  }
}

bool IAM20680HV::updateRegister(uint8_t reg, uint8_t mask, uint8_t value) {
  uint8_t cur = 0;
  if (!readRegisters(reg, &cur, 1)) return false;
  uint8_t nv = (cur & (uint8_t)~mask) | (value & mask);
  if (nv == cur) return true; // nothing to do
  return writeRegisters(reg, &nv, 1);
}

// Lifecycle and configuration implementation: Implement reset delay, identity verification, power, configuration, and reset methods.

bool IAM20680HV::begin() {
  // Issue soft reset via PWR_MGMT_1 = 0x81 as required
  uint8_t pwr = 0x81; // DEVICE_RESET=1 + leave other bits 0 as per plan
  if (!writeRegisters(REG_PWR_MGMT_1, &pwr, 1)) return false;

  // Wait start-up time (typical 11 ms from power-up)
  delay(11);

  // If SPI transport, disable I2C slave via USER_CTRL.I2C_IF_DIS (mask bit4)
  if (_transport == TransportType::SPI) {
    // read-modify-write USER_CTRL.I2C_IF_DIS
    if (!updateRegister(REG_USER_CTRL, (1 << 4), (1 << 4))) {
      return false;
    }
  }

  // Verify WHO_AM_I
  uint8_t who = 0;
  if (!readWhoAmI(who)) return false;
  if (who != 0xFE) {
    _lastError = 6; // identification mismatch
    return false;
  }

  // Leave normal operation with auto-select clock: set CLKSEL to AUTO (001) while preserving other bits
  uint8_t clkVal = static_cast<uint8_t>(ClockSource::AUTO) & 0x07;
  if (!updateRegister(REG_PWR_MGMT_1, 0x07, clkVal)) return false;

  _lastError = 0;
  return true;
}

bool IAM20680HV::readWhoAmI(uint8_t &value) {
  uint8_t v = 0;
  if (!readRegisters(REG_WHO_AM_I, &v, 1)) return false;
  value = v;
  return true;
}

bool IAM20680HV::softReset() {
  uint8_t v = 0x81;
  if (!writeRegisters(REG_PWR_MGMT_1, &v, 1)) return false;
  delay(11);
  return true;
}

bool IAM20680HV::setClockSource(ClockSource source) {
  uint8_t val = static_cast<uint8_t>(source) & 0x07;
  return updateRegister(REG_PWR_MGMT_1, 0x07, val);
}

bool IAM20680HV::setSleep(bool enabled) {
  return updateRegister(REG_PWR_MGMT_1, (1 << 6), enabled ? (1 << 6) : 0);
}

bool IAM20680HV::setAxisStandby(uint8_t standbyMask) {
  // Only bits[5:0] are standby controls; preserve reserved bits 7:6
  return updateRegister(REG_PWR_MGMT_2, 0x3F, standbyMask & 0x3F);
}

bool IAM20680HV::setSampleRateDivider(uint8_t divider) {
  return writeRegisters(REG_SMPLRT_DIV, &divider, 1);
}

bool IAM20680HV::setGyroConfig(GyroRange range, uint8_t fchoice, uint8_t dlpf) {
  // Validate encodings
  if (fchoice > 0x03) return false;
  if (dlpf > 0x07) return false;

  // Prepare write value: FS_SEL in bits 4:3, FCHOICE_B in bits1:0
  uint8_t writeVal = ((static_cast<uint8_t>(range) & 0x03) << 3) | (fchoice & 0x03);
  // Use mask 0x1B to only modify FS_SEL (bits4:3) and FCHOICE_B (bits1:0) and preserve reserved and self-test bits
  const uint8_t gyroMask = 0x1B; // bits [4,3,1,0]

  // Apply both writes: GYRO_CONFIG then CONFIG.DLPF_CFG. Only update cached range after both succeed.
  if (!updateRegister(REG_GYRO_CONFIG, gyroMask, writeVal)) return false;
  if (!updateRegister(REG_CONFIG, 0x07, (dlpf & 0x07))) return false;

  _gyroRange = range;
  return true;
}

bool IAM20680HV::setAccelConfig(AccelRange range, bool fchoiceBypass, uint8_t dlpf, uint8_t womAverage) {
  // Validate encodings
  if (dlpf > 0x07) return false;
  if ((womAverage & ~0x03) != 0) return false;

  uint8_t fs = (static_cast<uint8_t>(range) & 0x03) << 3;
  // Update ACCEL_CONFIG (only ACCEL_FS_SEL bits 4:3) while preserving reserved/self-test
  if (!updateRegister(REG_ACCEL_CONFIG, 0x18, fs)) return false;

  // Build ACCEL_CONFIG2 value: DEC2_CFG bits5:4, ACCEL_FCHOICE_B bit3, A_DLPF_CFG bits2:0
  uint8_t dec2 = (womAverage & 0x03) << 4;
  uint8_t fch = (fchoiceBypass ? 0x08 : 0x00);
  uint8_t dl = (dlpf & 0x07);
  uint8_t newVal = dec2 | fch | dl;
  // Mask for ACCEL_CONFIG2 valid fields: bits5:4, bit3, bits2:0 -> 0x3F
  if (!updateRegister(REG_ACCEL_CONFIG2, 0x3F, newVal)) return false;

  _accelRange = range;
  return true;
}

bool IAM20680HV::configureFsync(uint8_t syncSelection, bool interruptEnabled, bool activeLow) {
  if (syncSelection > 7) return false;
  if (!updateRegister(REG_CONFIG, 0x38, (uint8_t)((syncSelection & 0x07) << 3))) return false; // EXT_SYNC_SET bits[5:3]
  // INT_PIN_CFG: FSYNC_INT_MODE_EN bit2, FSYNC_INT_LEVEL bit3, INT_LEVEL bit7
  uint8_t mask = (1 << 2) | (1 << 3) | (1 << 7);
  uint8_t val = (interruptEnabled ? (1 << 2) : 0) | (activeLow ? (1 << 3) : 0) | (activeLow ? (1 << 7) : 0);
  return updateRegister(REG_INT_PIN_CFG, mask, val);
}

bool IAM20680HV::resetSignalPaths(bool resetAccel, bool resetTemp) {
  uint8_t v = 0;
  if (resetAccel) v |= (1 << 1);
  if (resetTemp) v |= (1 << 0);
  return writeRegisters(REG_SIGNAL_PATH_RESET, &v, 1);
}

bool IAM20680HV::resetAndClearSensorPaths() {
  return updateRegister(REG_USER_CTRL, (1 << 0), (1 << 0));
}

// Acquisition and advanced feature implementation: Implement burst parsing/conversion, interrupt semantics, WoM ordering, offsets, and self-test controls.

bool IAM20680HV::readRawData(RawData &data) {
  uint8_t buf[14];
  if (!readRegisters(REG_ACCEL_XOUT_H, buf, 14)) return false;
  data.accel_x = (int16_t)((buf[0] << 8) | buf[1]);
  data.accel_y = (int16_t)((buf[2] << 8) | buf[3]);
  data.accel_z = (int16_t)((buf[4] << 8) | buf[5]);
  data.temp    = (int16_t)((buf[6] << 8) | buf[7]);
  data.gyro_x  = (int16_t)((buf[8] << 8) | buf[9]);
  data.gyro_y  = (int16_t)((buf[10] << 8) | buf[11]);
  data.gyro_z  = (int16_t)((buf[12] << 8) | buf[13]);
  return true;
}

bool IAM20680HV::readScaledData(Vector3f &accelG, Vector3f &gyroDps, float &temperatureC) {
  RawData r;
  if (!readRawData(r)) return false;

  // Temperature conversion: Celsius = raw / 326.8 + 25 (room offset 0)
  temperatureC = ((float)r.temp - TEMP_ROOM_OFFSET) / TEMP_SENSITIVITY + 25.0f;

  // Gyro conversion: authoritative retrieved sensitivities per FS_SEL
  float gyroLSBperDps = 131.0f; // default
  switch (_gyroRange) {
    case GyroRange::DPS_125: gyroLSBperDps = 262.0f; break; // FS_SEL=0 -> 262 LSB/dps
    case GyroRange::DPS_250: gyroLSBperDps = 131.0f; break; // FS_SEL=1 -> 131 LSB/dps
    case GyroRange::DPS_500: gyroLSBperDps = 65.5f; break; // FS_SEL=2 -> 65.5 LSB/dps
    case GyroRange::DPS_1000: gyroLSBperDps = 32.8f; break; // FS_SEL=3 -> 32.8 LSB/dps
  }
  gyroDps.x = (float)r.gyro_x / gyroLSBperDps;
  gyroDps.y = (float)r.gyro_y / gyroLSBperDps;
  gyroDps.z = (float)r.gyro_z / gyroLSBperDps;

  // Accel conversion: authoritative retrieved sensitivities per ACCEL_FS_SEL
  float accelLSBperG = 16384.0f;
  switch (_accelRange) {
    case AccelRange::G_2: accelLSBperG = 16384.0f; break; // ±2g
    case AccelRange::G_4: accelLSBperG = 8192.0f; break;  // ±4g
    case AccelRange::G_8: accelLSBperG = 4096.0f; break;  // ±8g
    case AccelRange::G_16: accelLSBperG = 2048.0f; break; // ±16g
  }
  accelG.x = (float)r.accel_x / accelLSBperG;
  accelG.y = (float)r.accel_y / accelLSBperG;
  accelG.z = (float)r.accel_z / accelLSBperG;

  return true;
}

bool IAM20680HV::configureInterruptPin(const InterruptPinConfig &config) {
  uint8_t val = 0;
  if (config.activeLow) val |= (1 << 7);
  if (config.openDrain) val |= (1 << 6);
  if (config.latched) val |= (1 << 5);
  if (config.clearOnAnyRead) val |= (1 << 4);
  if (config.fsyncActiveLow) val |= (1 << 3);
  if (config.fsyncInterruptEnable) val |= (1 << 2);
  if (config.routeToInt2) val |= (1 << 0);
  // Mask covers writable bits while preserving reserved bit1
  const uint8_t intPinMask = 0xFD; // bits 7,6,5,4,3,2,0 writable; bit1 reserved
  return updateRegister(REG_INT_PIN_CFG, intPinMask, val);
}

bool IAM20680HV::setInterruptEnables(uint8_t enableMask) {
  // Only mapped INT_ENABLE non-reserved bits are honored: bits7,6,5,2,0
  uint8_t mask = (1 << 7) | (1 << 6) | (1 << 5) | (1 << 2) | (1 << 0);
  return updateRegister(REG_INT_ENABLE, mask, enableMask & mask);
}

bool IAM20680HV::readInterruptStatus(uint8_t &status) {
  uint8_t v = 0;
  if (!readRegisters(REG_INT_STATUS, &v, 1)) return false;
  status = v;
  return true;
}

bool IAM20680HV::readFsyncStatus(bool &active) {
  uint8_t v = 0;
  if (!readRegisters(REG_FSYNC_INT, &v, 1)) return false;
  active = (v & (1 << 7)) != 0;
  return true;
}

bool IAM20680HV::configureWakeOnMotion(const WakeOnMotionConfig &config) {
  bool ok = true;
  // 1) Set ACCEL_CONFIG2.ACCEL_FCHOICE_B=0 and A_DLPF_CFG=111 as suggested for WoM
  ok &= updateRegister(REG_ACCEL_CONFIG2, (uint8_t)((1 << 3) | 0x07), (uint8_t)(0x07)); // ACCEL_FCHOICE_B=0 and A_DLPF_CFG=7
  // 2) Set WOM thresholds
  ok &= writeRegisters(REG_ACCEL_WOM_X_THR, &config.thresholdX, 1);
  ok &= writeRegisters(REG_ACCEL_WOM_Y_THR, &config.thresholdY, 1);
  ok &= writeRegisters(REG_ACCEL_WOM_Z_THR, &config.thresholdZ, 1);
  // 3) Enable WOM interrupts bits in INT_ENABLE
  uint8_t intMask = 0;
  if (config.enableX) intMask |= (1 << 7);
  if (config.enableY) intMask |= (1 << 6);
  if (config.enableZ) intMask |= (1 << 5);
  ok &= setInterruptEnables(intMask);
  // 4) ACCEL_INTEL_CTRL: ACCEL_INTEL_EN bit7 and ACCEL_INTEL_MODE bit6; ensure bit0 remains zero
  uint8_t intelVal = (config.enableX || config.enableY || config.enableZ) ? (1 << 7) : 0;
  if (config.intelModePreviousSample) intelVal |= (1 << 6);
  ok &= updateRegister(REG_ACCEL_INTEL_CTRL, (uint8_t)((1<<7) | (1<<6)), intelVal);
  // 5) LP_MODE_CFG.ACCEL_WOM_ODR_CTRL set
  ok &= updateRegister(REG_LP_MODE_CFG, 0x0F, (uint8_t)(config.accelWomOdrCtrl & 0x0F));
  // 6) Put into cycle mode: disable gyros in PWR_MGMT_2 as required then set ACCEL_CYCLE in PWR_MGMT_1
  uint8_t pwr2 = (1 << 2) | (1 << 1) | (1 << 0); // STBY_XG, STBY_YG, STBY_ZG
  ok &= updateRegister(REG_PWR_MGMT_2, 0x3F, pwr2);
  ok &= updateRegister(REG_PWR_MGMT_1, (1 << 5), (1 << 5));
  return ok;
}

bool IAM20680HV::setGyroOffsets(const Vector3i16 &offset) {
  uint8_t buf[6];
  buf[0] = (uint8_t)((offset.x >> 8) & 0xFF);
  buf[1] = (uint8_t)(offset.x & 0xFF);
  buf[2] = (uint8_t)((offset.y >> 8) & 0xFF);
  buf[3] = (uint8_t)(offset.y & 0xFF);
  buf[4] = (uint8_t)((offset.z >> 8) & 0xFF);
  buf[5] = (uint8_t)(offset.z & 0xFF);
  return writeRegisters(REG_XG_OFFS_USRH, buf, 6);
}

bool IAM20680HV::setAccelOffsets(const Vector3i16 &offset) {
  auto inRange15 = [](int16_t v)->bool { return (v >= -0x4000) && (v <= 0x3FFF); };
  if (!inRange15(offset.x) || !inRange15(offset.y) || !inRange15(offset.z)) return false;

  uint8_t low;
  // X
  if (!readRegisters(REG_XA_OFFSET_L, &low, 1)) return false;
  uint8_t preservedBit0 = low & 0x01;
  uint8_t xh = (uint8_t)((offset.x >> 7) & 0xFF);
  uint8_t xl = (uint8_t)((offset.x << 1) & 0xFE);
  xl |= preservedBit0;
  if (!writeRegisters(REG_XA_OFFSET_H, &xh, 1)) return false;
  if (!writeRegisters(REG_XA_OFFSET_L, &xl, 1)) return false;
  // Y
  if (!readRegisters(REG_YA_OFFSET_L, &low, 1)) return false;
  preservedBit0 = low & 0x01;
  uint8_t yh = (uint8_t)((offset.y >> 7) & 0xFF);
  uint8_t yl = (uint8_t)((offset.y << 1) & 0xFE);
  yl |= preservedBit0;
  if (!writeRegisters(REG_YA_OFFSET_H, &yh, 1)) return false;
  if (!writeRegisters(REG_YA_OFFSET_L, &yl, 1)) return false;
  // Z
  if (!readRegisters(REG_ZA_OFFSET_L, &low, 1)) return false;
  preservedBit0 = low & 0x01;
  uint8_t zh = (uint8_t)((offset.z >> 7) & 0xFF);
  uint8_t zl = (uint8_t)((offset.z << 1) & 0xFE);
  zl |= preservedBit0;
  if (!writeRegisters(REG_ZA_OFFSET_H, &zh, 1)) return false;
  if (!writeRegisters(REG_ZA_OFFSET_L, &zl, 1)) return false;

  return true;
}

bool IAM20680HV::readSelfTestCodes(uint8_t gyroCodes[3], uint8_t accelCodes[3]) {
  if (!readRegisters(REG_SELF_TEST_X_GYRO, &gyroCodes[0], 3)) return false;
  if (!readRegisters(REG_SELF_TEST_X_ACCEL, &accelCodes[0], 3)) return false;
  return true;
}

bool IAM20680HV::setSelfTest(uint8_t gyroAxisMask, uint8_t accelAxisMask) {
  if (gyroAxisMask & 0xF8) return false; // only lower 3 bits allowed
  uint8_t gyroBits = ((gyroAxisMask & 0x01) ? (1 << 7) : 0) | ((gyroAxisMask & 0x02) ? (1 << 6) : 0) | ((gyroAxisMask & 0x04) ? (1 << 5) : 0);
  if (!updateRegister(REG_GYRO_CONFIG, (uint8_t)((1<<7)|(1<<6)|(1<<5)), gyroBits)) return false;
  if (accelAxisMask & 0xF8) return false;
  uint8_t accelBits = ((accelAxisMask & 0x01) ? (1 << 7) : 0) | ((accelAxisMask & 0x02) ? (1 << 6) : 0) | ((accelAxisMask & 0x04) ? (1 << 5) : 0);
  if (!updateRegister(REG_ACCEL_CONFIG, (uint8_t)((1<<7)|(1<<6)|(1<<5)), accelBits)) return false;
  return true;
}

// End of implementation

