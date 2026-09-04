/*
LIS3DH transaction, configuration, conversion, and status implementation.
*/

// Transport implementation
// section_name: Transport implementation

#include "LIS3DH.h"

// I2C buffer safety: Wire buffer is 32 bytes. Enforce limit on single transfers.
static const size_t WIRE_MAX = 32;

// Constructors
LIS3DH::LIS3DH(TwoWire &wire, uint8_t address)
  : _wire(&wire), _i2c_addr(address), _spi(nullptr), _csPin(0xFF), _isI2C(true), _spiSettings() {
}

LIS3DH::LIS3DH(SPIClass &spiBus, uint8_t csPin, const SPISettings &settings)
  : _wire(nullptr), _i2c_addr(0), _spi(&spiBus), _csPin(csPin), _isI2C(false), _spiSettings(settings) {
}

// Low-level helpers
bool LIS3DH::readRegisters(uint8_t reg, uint8_t *buffer, size_t count) {
  if (count == 0) return true;
  if (_isI2C) {
    if (count > WIRE_MAX) return false; // guard Wire buffer
    // I2C: SUB MSB = auto-increment when count>1
    uint8_t sub = reg | (count > 1 ? 0x80 : 0x00);
    _wire->beginTransmission(_i2c_addr);
    _wire->write(sub);
    uint8_t err = _wire->endTransmission(false); // repeated start
    if (err != 0) return false;
    size_t got = _wire->requestFrom((int)_i2c_addr, (int)count);
    if (got != count) return false;
    for (size_t i = 0; i < count; ++i) {
      int v = _wire->read();
      if (v < 0) return false;
      buffer[i] = (uint8_t)v;
    }
    return true;
  } else {
    // SPI 4-wire: command byte bit7=read, bit6=auto-increment
    if (!_spi) return false;
    uint8_t cmd = 0x80 | (count > 1 ? 0x40 : 0x00) | (reg & 0x3F);
    // Use caller-supplied SPISettings via _spi->beginTransaction
    _spi->beginTransaction(_spiSettings);
    digitalWrite(_csPin, LOW);
    _spi->transfer(cmd);
    for (size_t i = 0; i < count; ++i) {
      buffer[i] = _spi->transfer(0x00);
    }
    digitalWrite(_csPin, HIGH);
    _spi->endTransaction();
    return true;
  }
}

bool LIS3DH::writeRegisters(uint8_t reg, const uint8_t *buffer, size_t count) {
  if (count == 0) return true;
  if (_isI2C) {
    // I2C: the subaddress MSB bit enables auto-increment for multi-byte writes
    if (count + 1 > WIRE_MAX) return false; // ensure Wire buffer is not exceeded
    uint8_t sub = reg | (count > 1 ? 0x80 : 0x00);
    _wire->beginTransmission(_i2c_addr);
    _wire->write(sub);
    for (size_t i = 0; i < count; ++i) _wire->write(buffer[i]);
    uint8_t err = _wire->endTransmission(true);
    return err == 0;
  } else {
    if (!_spi) return false;
    uint8_t cmd = 0x00 | (count > 1 ? 0x40 : 0x00) | (reg & 0x3F); // write: bit7=0
    _spi->beginTransaction(_spiSettings);
    digitalWrite(_csPin, LOW);
    _spi->transfer(cmd);
    for (size_t i = 0; i < count; ++i) _spi->transfer(buffer[i]);
    digitalWrite(_csPin, HIGH);
    _spi->endTransaction();
    return true;
  }
}

bool LIS3DH::updateRegister(uint8_t reg, uint8_t mask, uint8_t value) {
  uint8_t cur;
  uint8_t buf[1];
  if (!readRegisters(reg, buf, 1)) return false;
  cur = buf[0];
  uint8_t newv = (cur & (uint8_t)~mask) | (value & mask);
  if (newv == cur) return true; // no change
  return writeRegisters(reg, &newv, 1);
}

// tiny helpers
uint8_t LIS3DH::_read8(uint8_t reg) {
  uint8_t v = 0xFF;
  if (!readRegisters(reg, &v, 1)) return 0xFF;
  return v;
}

bool LIS3DH::_write8(uint8_t reg, uint8_t value) {
  return writeRegisters(reg, &value, 1);
}

// Driver API implementation
// section_name: Driver API implementation

bool LIS3DH::whoAmI() {
  uint8_t id = _read8(LIS3DH_REG_WHO_AM_I);
  return id == LIS3DH_WHO_AM_I_ID;
}

bool LIS3DH::begin() {
  // For SPI mode ensure CS pin is output but do not call SPI.begin()
  if (!_isI2C) {
    pinMode(_csPin, OUTPUT);
    digitalWrite(_csPin, HIGH);
  }

  // Verify presence
  if (!whoAmI()) return false;

  // Set safe defaults: all axes enabled, 100 Hz normal mode, ±2 g, BDU enabled
  // CTRL_REG1 (0x20): ODR[3:0] << 4 | LPen <<3 | Zen<<2 | Yen<<1 | Xen
  uint8_t ctrl1 = (static_cast<uint8_t>(Lis3dhOdr::Hz100) << 4) | (0 << 3) | (1<<2) | (1<<1) | (1<<0);
  if (!_write8(LIS3DH_REG_CTRL_REG1, ctrl1)) return false;

  // CTRL_REG4 (0x23): BDU=1, FS=00 (±2g), HR=0
  uint8_t ctrl4 = (1<<7); // BDU
  if (!_write8(LIS3DH_REG_CTRL_REG4, ctrl4)) return false;

  // cache config
  _measConfig.odr = Lis3dhOdr::Hz100;
  _measConfig.fs = Lis3dhFullScale::FS2;
  _measConfig.res = Lis3dhResolution::Normal;
  _measConfig.enableX = true;
  _measConfig.enableY = true;
  _measConfig.enableZ = true;
  _measConfig.bdu = true;

  // Wait at least one sample period after configuration
  float odr_hz = 100.0f;
  uint16_t delay_ms = (uint16_t)ceil(1000.0f / odr_hz);
  delay(delay_ms + 1);

  return true;
}

bool LIS3DH::rebootMemory() {
  // Set BOOT bit in CTRL_REG5 (0x24) bit7 = 1
  if (!updateRegister(LIS3DH_REG_CTRL_REG5, (1<<7), (1<<7))) return false;
  delay(5);
  return true;
}

bool LIS3DH::configureMeasurement(const MeasurementConfig &config) {
  // Validate HR + LP not both set
  if (config.res == Lis3dhResolution::HighResolution) {
    // ensure LPen not set via any other API; here we respect the provided resolution
  }

  // Build CTRL_REG1
  uint8_t ctrl1 = (static_cast<uint8_t>(config.odr) << 4) | ((config.res == Lis3dhResolution::LowPower ? 1 : 0) << 3) |
                  ((config.enableZ ? 1 : 0) << 2) | ((config.enableY ? 1 : 0) << 1) | ((config.enableX ? 1 : 0) << 0);
  if (! _write8(LIS3DH_REG_CTRL_REG1, ctrl1)) return false;

  // Build CTRL_REG4: BDU preserved if requested, FS bits and HR
  uint8_t ctrl4 = 0;
  if (config.bdu) ctrl4 |= (1<<7);
  // BLE left as 0 by default; FS in bits4..5
  ctrl4 |= (static_cast<uint8_t>(config.fs) << 4);
  if (config.res == Lis3dhResolution::HighResolution) ctrl4 |= (1<<3);

  if (! _write8(LIS3DH_REG_CTRL_REG4, ctrl4)) return false;

  // cache
  _measConfig = config;

  // Wait required turn-on time. Conservative: wait at least one sample period; if HR, wait 7/ODR (ms)
  float odr = 100.0f;
  switch (config.odr) {
    case Lis3dhOdr::Hz1: odr = 1; break;
    case Lis3dhOdr::Hz10: odr = 10; break;
    case Lis3dhOdr::Hz25: odr = 25; break;
    case Lis3dhOdr::Hz50: odr = 50; break;
    case Lis3dhOdr::Hz100: odr = 100; break;
    case Lis3dhOdr::Hz200: odr = 200; break;
    case Lis3dhOdr::Hz400: odr = 400; break;
    case Lis3dhOdr::Hz1_6k: odr = 1600; break;
    case Lis3dhOdr::Hz1_344k: odr = 1344; break;
    default: odr = 100; break;
  }
  uint16_t wait_ms = 1;
  if (config.res == Lis3dhResolution::HighResolution) {
    // 7/ODR in seconds -> (7000/ODR) ms
    wait_ms = (uint16_t)ceil(7000.0f / odr);
  } else {
    // normal/low-power: wait at least one sample period (1000/ODR) ms
    wait_ms = (uint16_t)ceil(1000.0f / odr);
  }
  delay(wait_ms + 1);
  return true;
}

bool LIS3DH::readAcceleration(AccelerationSample &sample) {
  uint8_t buf[6];
  if (!readRegisters(LIS3DH_REG_OUT_X_L, buf, 6)) return false;
  // combine bytes: OUT_X_H:MSB, OUT_X_L:LSB. Data is left-justified. We'll form signed 16-bit and shift down
  int16_t rawx = (int16_t)((int16_t)((uint16_t)buf[1] << 8) | buf[0]);
  int16_t rawy = (int16_t)((int16_t)((uint16_t)buf[3] << 8) | buf[2]);
  int16_t rawz = (int16_t)((int16_t)((uint16_t)buf[5] << 8) | buf[4]);

  // shift according to resolution: HR shift 4, normal shift 6, LP shift 8
  int shift = 6; // normal default
  if (_measConfig.res == Lis3dhResolution::HighResolution) shift = 4;
  else if (_measConfig.res == Lis3dhResolution::LowPower) shift = 8;

  int16_t sx = (int16_t)(rawx >> shift);
  int16_t sy = (int16_t)(rawy >> shift);
  int16_t sz = (int16_t)(rawz >> shift);

  // sensitivity mg/digit table
  float mg_per_lsb = 4.0f; // normal at ±2g
  if (_measConfig.fs == Lis3dhFullScale::FS2) {
    if (_measConfig.res == Lis3dhResolution::HighResolution) mg_per_lsb = 1.0f;
    else if (_measConfig.res == Lis3dhResolution::Normal) mg_per_lsb = 4.0f;
    else if (_measConfig.res == Lis3dhResolution::LowPower) mg_per_lsb = 16.0f;
  } else if (_measConfig.fs == Lis3dhFullScale::FS4) {
    if (_measConfig.res == Lis3dhResolution::HighResolution) mg_per_lsb = 2.0f;
    else if (_measConfig.res == Lis3dhResolution::Normal) mg_per_lsb = 8.0f;
    else if (_measConfig.res == Lis3dhResolution::LowPower) mg_per_lsb = 32.0f;
  } else if (_measConfig.fs == Lis3dhFullScale::FS8) {
    if (_measConfig.res == Lis3dhResolution::HighResolution) mg_per_lsb = 4.0f;
    else if (_measConfig.res == Lis3dhResolution::Normal) mg_per_lsb = 16.0f;
    else if (_measConfig.res == Lis3dhResolution::LowPower) mg_per_lsb = 64.0f;
  } else { // FS16
    if (_measConfig.res == Lis3dhResolution::HighResolution) mg_per_lsb = 12.0f;
    else if (_measConfig.res == Lis3dhResolution::Normal) mg_per_lsb = 48.0f;
    else if (_measConfig.res == Lis3dhResolution::LowPower) mg_per_lsb = 192.0f;
  }

  sample.x_raw = sx;
  sample.y_raw = sy;
  sample.z_raw = sz;
  sample.x_mg = sx * mg_per_lsb;
  sample.y_mg = sy * mg_per_lsb;
  sample.z_mg = sz * mg_per_lsb;
  return true;
}

bool LIS3DH::readAccelerationStatus(AccelerationStatus &status) {
  uint8_t v;
  if (!readRegisters(LIS3DH_REG_STATUS, &v, 1)) return false;
  status.status_reg = v;
  status.xyz_new = v & (1<<3);
  status.z_new = v & (1<<2);
  status.y_new = v & (1<<1);
  status.x_new = v & (1<<0);
  status.xyz_overrun = v & (1<<7);
  status.z_overrun = v & (1<<6);
  status.y_overrun = v & (1<<5);
  status.x_overrun = v & (1<<4);
  return true;
}

bool LIS3DH::setBlockDataUpdate(bool enabled) {
  return updateRegister(LIS3DH_REG_CTRL_REG4, (1<<7), enabled ? (1<<7) : 0x00);
}

bool LIS3DH::setEndian(bool bigEndian) {
  // BLE is only available in high-resolution mode per datasheet
  if (_measConfig.res != Lis3dhResolution::HighResolution) return false;
  return updateRegister(LIS3DH_REG_CTRL_REG4, (1<<6), bigEndian ? (1<<6) : 0x00);
}

// Auxiliary ADC and filter
bool LIS3DH::configureAuxiliary(bool adcEnabled, bool temperatureEnabled) {
  uint8_t mask = (1<<7) | (1<<6);
  uint8_t value = (adcEnabled ? (1<<7) : 0) | (temperatureEnabled ? (1<<6) : 0);
  return updateRegister(LIS3DH_REG_TEMP_CFG, mask, value);
}

bool LIS3DH::readAuxiliary(AuxiliaryData &data) {
  uint8_t buf[6];
  if (!readRegisters(LIS3DH_REG_OUT_ADC1_L, buf, 6)) return false;
  int16_t a1 = (int16_t)((uint16_t)buf[1] << 8 | buf[0]);
  int16_t a2 = (int16_t)((uint16_t)buf[3] << 8 | buf[2]);
  int16_t a3 = (int16_t)((uint16_t)buf[5] << 8 | buf[4]);
  // ADC resolution: normal/HR = 10-bit left-justified => shift 6; LP => 8-bit => shift 8
  int shift = (_measConfig.res == Lis3dhResolution::LowPower) ? 8 : 6;
  data.adc1_raw = (int16_t)(a1 >> shift);
  data.adc2_raw = (int16_t)(a2 >> shift);
  data.adc3_raw = (int16_t)(a3 >> shift);

  uint8_t staux;
  if (!readRegisters(LIS3DH_REG_STATUS_AUX, &staux, 1)) return false;
  data.adc1_ready = staux & 0x01;
  data.adc2_ready = staux & 0x02;
  data.adc3_ready = staux & 0x04;
  return true;
}

bool LIS3DH::configureHighPass(const HighPassConfig &config) {
  uint8_t v = ((config.hpm & 0x3) << 6) | ((config.hpcf & 0x3) << 4);
  if (config.fds) v |= (1<<3);
  if (config.hp_click) v |= (1<<2);
  if (config.hp_ia2) v |= (1<<1);
  if (config.hp_ia1) v |= (1<<0);
  return _write8(LIS3DH_REG_CTRL_REG2, v);
}

bool LIS3DH::setReference(uint8_t value) {
  return _write8(LIS3DH_REG_REFERENCE, value);
}

bool LIS3DH::readReference(uint8_t &value) {
  uint8_t v;
  if (!readRegisters(LIS3DH_REG_REFERENCE, &v, 1)) return false;
  value = v;
  // Note: reading REFERENCE resets HPF in HPM mode 00 (side effect documented)
  return true;
}

bool LIS3DH::setSdoPullupDisconnected(bool disconnected) {
  // CTRL_REG0 bits 0..6 must remain default 0x10 per register map; only bit7 (SDO_PU_DISC) is writable
  return updateRegister(LIS3DH_REG_CTRL_REG0, (1<<7), disconnected ? (1<<7) : 0x00);
}

// FIFO and event functions
bool LIS3DH::configureFifo(const FifoConfig &config) {
  // Validate watermark (5-bit): <= 31
  if ((config.fth & 0xE0) != 0) return false;
  uint8_t v = ((config.fm & 0x3) << 6) | ((config.tr ? 1:0) << 5) | (config.fth & 0x1F);
  if (! _write8(LIS3DH_REG_FIFO_CTRL, v)) return false;
  // enable FIFO_EN in CTRL_REG5 bit6 while preserving other bits (mask out reserved bits)
  if (!updateRegister(LIS3DH_REG_CTRL_REG5, (1<<6), (1<<6))) return false;
  return true;
}

bool LIS3DH::readFifoStatus(FifoStatus &status) {
  uint8_t v;
  if (!readRegisters(LIS3DH_REG_FIFO_SRC, &v, 1)) return false;
  status.wtm = v & (1<<7);
  status.overrun = v & (1<<6);
  status.empty = v & (1<<5);
  status.fss = v & 0x1F;
  return true;
}

bool LIS3DH::readFifoSample(AccelerationSample &sample) {
  FifoStatus st;
  if (!readFifoStatus(st)) return false;
  if (st.fss == 0) return false; // empty
  uint8_t buf[6];
  if (!readRegisters(LIS3DH_REG_OUT_X_L, buf, 6)) return false;
  int16_t rawx = (int16_t)((uint16_t)buf[1] << 8 | buf[0]);
  int16_t rawy = (int16_t)((uint16_t)buf[3] << 8 | buf[2]);
  int16_t rawz = (int16_t)((uint16_t)buf[5] << 8 | buf[4]);
  int shift = 6;
  if (_measConfig.res == Lis3dhResolution::HighResolution) shift = 4;
  else if (_measConfig.res == Lis3dhResolution::LowPower) shift = 8;
  sample.x_raw = (int16_t)(rawx >> shift);
  sample.y_raw = (int16_t)(rawy >> shift);
  sample.z_raw = (int16_t)(rawz >> shift);
  float mg_per_lsb = 4.0f;
  if (_measConfig.fs == Lis3dhFullScale::FS2) {
    if (_measConfig.res == Lis3dhResolution::HighResolution) mg_per_lsb = 1.0f;
    else if (_measConfig.res == Lis3dhResolution::Normal) mg_per_lsb = 4.0f;
    else if (_measConfig.res == Lis3dhResolution::LowPower) mg_per_lsb = 16.0f;
  } else if (_measConfig.fs == Lis3dhFullScale::FS4) {
    if (_measConfig.res == Lis3dhResolution::HighResolution) mg_per_lsb = 2.0f;
    else if (_measConfig.res == Lis3dhResolution::Normal) mg_per_lsb = 8.0f;
    else if (_measConfig.res == Lis3dhResolution::LowPower) mg_per_lsb = 32.0f;
  } else if (_measConfig.fs == Lis3dhFullScale::FS8) {
    if (_measConfig.res == Lis3dhResolution::HighResolution) mg_per_lsb = 4.0f;
    else if (_measConfig.res == Lis3dhResolution::Normal) mg_per_lsb = 16.0f;
    else if (_measConfig.res == Lis3dhResolution::LowPower) mg_per_lsb = 64.0f;
  } else {
    if (_measConfig.res == Lis3dhResolution::HighResolution) mg_per_lsb = 12.0f;
    else if (_measConfig.res == Lis3dhResolution::Normal) mg_per_lsb = 48.0f;
    else if (_measConfig.res == Lis3dhResolution::LowPower) mg_per_lsb = 192.0f;
  }
  sample.x_mg = sample.x_raw * mg_per_lsb;
  sample.y_mg = sample.y_raw * mg_per_lsb;
  sample.z_mg = sample.z_raw * mg_per_lsb;
  return true;
}

bool LIS3DH::resetFifo() {
  uint8_t v = 0x00; // Bypass mode
  return _write8(LIS3DH_REG_FIFO_CTRL, v);
}

bool LIS3DH::configureInterrupt(const InterruptConfig &config) {
  // Write INTx_CFG register
  uint8_t cfgReg = config.cfg_reg_val;
  uint8_t cfgAddr = (config.engine == InterruptEngine::INT1) ? LIS3DH_REG_INT1_CFG : LIS3DH_REG_INT2_CFG;
  if (!writeRegisters(cfgAddr, &cfgReg, 1)) return false;

  // THS and DURATION: mask 0x7F (preserve reserved high bit)
  uint8_t thsAddr = (config.engine == InterruptEngine::INT1) ? LIS3DH_REG_INT1_THS : LIS3DH_REG_INT2_THS;
  if (!updateRegister(thsAddr, 0x7F, config.ths & 0x7F)) return false;
  uint8_t durAddr = (config.engine == InterruptEngine::INT1) ? LIS3DH_REG_INT1_DURATION : LIS3DH_REG_INT2_DURATION;
  if (!updateRegister(durAddr, 0x7F, config.dur & 0x7F)) return false;

  // D4D validation: only allowed when 6D bit set in cfg_reg_val
  if (config.d4d) {
    if (!(config.cfg_reg_val & (1<<6))) return false; // 6D not enabled
  }

  // CTRL_REG5: Latching and D4D bits. Mask preserve reserved bits per plan using mask 0xCF when updating multiple bits.
  uint8_t ctrl5_bits = 0;
  if (config.latch) {
    if (config.engine == InterruptEngine::INT1) ctrl5_bits |= (1<<3); // LIR_INT1
    else ctrl5_bits |= (1<<1); // LIR_INT2
  }
  if (config.d4d) {
    if (config.engine == InterruptEngine::INT1) ctrl5_bits |= (1<<2); // D4D_INT1
    else ctrl5_bits |= (1<<0); // D4D_INT2
  }
  if (!updateRegister(LIS3DH_REG_CTRL_REG5, 0xCF, ctrl5_bits & 0xCF)) return false;

  // Routing: set IA function routing to INT1 (CTRL_REG3) or INT2 (CTRL_REG6)
  if (config.engine == InterruptEngine::INT1) {
    // IA1 maps to bit6 in CTRL_REG3 (I1_IA1) or bit6 in CTRL_REG6 (I2_IA1)
    if (config.routeToInt2) {
      if (!updateRegister(LIS3DH_REG_CTRL_REG6, (1<<6), (1<<6))) return false; // set I2_IA1
      // clear I1_IA1 without touching other CTRL_REG3 bits: use mask (1<<6)
      if (!updateRegister(LIS3DH_REG_CTRL_REG3, (1<<6), 0x00)) return false;
    } else {
      if (!updateRegister(LIS3DH_REG_CTRL_REG3, (1<<6), (1<<6))) return false; // set I1_IA1
      if (!updateRegister(LIS3DH_REG_CTRL_REG6, (1<<6), 0x00)) return false;
    }
  } else {
    // engine == INT2: IA2 maps to bit5
    if (config.routeToInt2) {
      if (!updateRegister(LIS3DH_REG_CTRL_REG6, (1<<5), (1<<5))) return false; // set I2_IA2
      if (!updateRegister(LIS3DH_REG_CTRL_REG3, (1<<5), 0x00)) return false;
    } else {
      if (!updateRegister(LIS3DH_REG_CTRL_REG3, (1<<5), (1<<5))) return false; // set I1_IA2
      if (!updateRegister(LIS3DH_REG_CTRL_REG6, (1<<5), 0x00)) return false;
    }
  }

  // Polarity: INT_POLARITY in CTRL_REG6 bit1 (mask with that bit only)
  if (!updateRegister(LIS3DH_REG_CTRL_REG6, (1<<1), config.polarityActiveLow ? (1<<1) : 0x00)) return false;

  return true;
}

bool LIS3DH::readInterruptSource(InterruptEngine engine, InterruptSource &source) {
  uint8_t reg = (engine == InterruptEngine::INT1) ? LIS3DH_REG_INT1_SRC : LIS3DH_REG_INT2_SRC;
  uint8_t v;
  if (!readRegisters(reg, &v, 1)) return false;
  source.raw = v;
  source.ia = v & (1<<6);
  source.xh = v & (1<<1);
  source.xl = v & (1<<0);
  source.yh = v & (1<<3);
  source.yl = v & (1<<2);
  source.zh = v & (1<<5);
  source.zl = v & (1<<4);
  // Note: reading INTx_SRC clears latched IA for that engine (side effect)
  return true;
}

bool LIS3DH::configureClick(const ClickConfig &config) {
  // Mask CLICK_CFG (preserve reserved bits 6..7 per plan mask 0x3F)
  if (!updateRegister(LIS3DH_REG_CLICK_CFG, 0x3F, config.cfg & 0x3F)) return false;

  // CLICK_THS: set latch bit7 and Ths[6:0]
  uint8_t thsVal = (config.latch ? (1<<7) : 0) | (config.ths & 0x7F);
  if (! _write8(LIS3DH_REG_CLICK_THS, thsVal)) return false;

  // TIME_LIMIT: mask 0x7F
  if (!updateRegister(LIS3DH_REG_TIME_LIMIT, 0x7F, config.timeLimit & 0x7F)) return false;
  // TIME_LATENCY and TIME_WINDOW are full-byte registers
  if (! _write8(LIS3DH_REG_TIME_LATENCY, config.timeLatency)) return false;
  if (! _write8(LIS3DH_REG_TIME_WINDOW, config.timeWindow)) return false;

  // Route click to exactly requested INT pin: CTRL_REG3.I1_CLICK bit7 or CTRL_REG6.I2_CLICK bit7
  if (config.routeToInt2) {
    if (!updateRegister(LIS3DH_REG_CTRL_REG6, (1<<7), (1<<7))) return false; // I2_CLICK
    if (!updateRegister(LIS3DH_REG_CTRL_REG3, (1<<7), 0x00)) return false; // clear I1_CLICK
  } else {
    if (!updateRegister(LIS3DH_REG_CTRL_REG3, (1<<7), (1<<7))) return false; // I1_CLICK
    if (!updateRegister(LIS3DH_REG_CTRL_REG6, (1<<7), 0x00)) return false; // clear I2_CLICK
  }

  return true;
}

bool LIS3DH::readClickSource(ClickSource &source) {
  uint8_t v;
  if (!readRegisters(LIS3DH_REG_CLICK_SRC, &v, 1)) return false;
  source.raw = v;
  source.ia = v & (1<<6);
  source.dclick = v & (1<<5);
  source.sclick = v & (1<<4);
  source.sign = v & (1<<3);
  source.z = v & (1<<2);
  source.y = v & (1<<1);
  source.x = v & (1<<0);
  // reading CLICK_SRC clears latched click interrupt (if latch selected)
  return true;
}

bool LIS3DH::configureActivity(uint8_t threshold, uint8_t duration, bool routeToInt2) {
  // ACT_THS mask 0x7F
  if (!updateRegister(LIS3DH_REG_ACT_THS, 0x7F, threshold & 0x7F)) return false;
  if (! _write8(LIS3DH_REG_ACT_DUR, duration)) return false;
  // Update routing bit in CTRL_REG6: I2_ACT bit3
  if (!updateRegister(LIS3DH_REG_CTRL_REG6, (1<<3), routeToInt2 ? (1<<3) : 0x00)) return false;
  // Documented: ACT_THS/ACT_DUR enable hardware-managed sleep/wake; device may ignore CTRL_REG1/CTRL_REG4 fields during auto low-power.
  return true;
}

bool LIS3DH::setSelfTest(SelfTestMode mode) {
  // ST bits are bits1..2 in CTRL_REG4
  if (mode == SelfTestMode::Disabled) {
    return updateRegister(LIS3DH_REG_CTRL_REG4, (0x3<<1), 0x00);
  } else if (mode == SelfTestMode::ST0) {
    if (!updateRegister(LIS3DH_REG_CTRL_REG4, (0x3<<1), (1<<1))) return false; // ST0 = 01
  } else if (mode == SelfTestMode::ST1) {
    if (!updateRegister(LIS3DH_REG_CTRL_REG4, (0x3<<1), (2<<1))) return false; // ST1 = 10
  }
  // Wait required settle: 2 samples for LP/normal, 8 for HR. Use cached ODR to compute.
  float odr = 100.0f;
  switch (_measConfig.odr) {
    case Lis3dhOdr::Hz1: odr = 1; break;
    case Lis3dhOdr::Hz10: odr = 10; break;
    case Lis3dhOdr::Hz25: odr = 25; break;
    case Lis3dhOdr::Hz50: odr = 50; break;
    case Lis3dhOdr::Hz100: odr = 100; break;
    case Lis3dhOdr::Hz200: odr = 200; break;
    case Lis3dhOdr::Hz400: odr = 400; break;
    case Lis3dhOdr::Hz1_6k: odr = 1600; break;
    case Lis3dhOdr::Hz1_344k: odr = 1344; break;
    default: odr = 100; break;
  }
  uint16_t samples = (_measConfig.res == Lis3dhResolution::HighResolution) ? 8 : 2;
  uint16_t wait_ms = (uint16_t)ceil((samples * 1000.0f) / odr);
  delay(wait_ms + 1);
  return true;
}

bool LIS3DH::setSpiThreeWire(bool enabled) {
  // Set SIM bit in CTRL_REG4 (bit0). Note: enabling 3-wire SPI in device will make 4-wire host driver incompatible.
  return updateRegister(LIS3DH_REG_CTRL_REG4, (1<<0), enabled ? (1<<0) : 0x00);
}

// Conversion and timing: implemented inline in readAcceleration and configureMeasurement as needed
// section_name: Conversion and timing


