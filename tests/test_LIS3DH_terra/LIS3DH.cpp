/*
Implementation of LIS3DH public API, transport, decoding, and validation.
*/

// Transport and register validation: I2C/SPI transfer implementations, mapped-address/write-mask checks and read-modify-write helper.
#include "LIS3DH.h"

using namespace lis3dh;

// Helper: map ODR code to approximate Hz
static uint32_t odrCodeToHz(uint8_t code) {
  switch (code & 0x0F) {
    case 0x1: return 1;
    case 0x2: return 10;
    case 0x3: return 25;
    case 0x4: return 50;
    case 0x5: return 100;
    case 0x6: return 200;
    case 0x7: return 400;
    case 0x8: return 1600; // 1.6 kHz
    case 0x9: return 1344; // documented special
    default: return 100; // conservative default
  }
}

// Constructors
LIS3DH::LIS3DH(TwoWire &wire, uint8_t address) {
  _transport = Transport::I2C;
  _wire = &wire;
  _i2c_address = address & 0x7F;
}

LIS3DH::LIS3DH(SPIClass &spi, uint8_t csPin) {
  _transport = Transport::SPI;
  _spi = &spi;
  _cs_pin = csPin;
  pinMode(_cs_pin, OUTPUT);
  digitalWrite(_cs_pin, HIGH);
}

// Private transport helper implementations
bool LIS3DH::readBytes(uint8_t reg, uint8_t *data, uint8_t length) {
  if (!_wire && !_spi) return false;

  if (_transport == Transport::I2C) {
    // I2C: sub-address MSB (bit7) enables auto-increment for multi-byte
    uint8_t sub = reg;
    if (length > 1) sub |= 0x80; // set MSB for auto-increment

    _wire->beginTransmission(_i2c_address);
    _wire->write(sub);
    uint8_t txerr = _wire->endTransmission(false); // repeated start
    if (txerr != 0) return false;

    uint8_t got = _wire->requestFrom((int)_i2c_address, (int)length, (int)true);
    if (got != length) return false;
    for (uint8_t i = 0; i < length; ++i) {
      int v = _wire->read();
      if (v < 0) return false;
      data[i] = (uint8_t)v;
    }
    return true;
  } else {
    // SPI 4-wire: build command byte per datasheet: bit0=RW, bit1=MS, bits2-7=address(6 bits)
    // command = (address << 2) | (MS<<1) | RW
    uint8_t ms = (length > 1) ? 1 : 0;
    uint8_t cmd = (uint8_t)((reg & 0x3F) << 2) | (uint8_t)(ms << 1) | 1u;

    SPISettings settings(10000000UL, MSBFIRST, SPI_MODE0);
    _spi->beginTransaction(settings);
    digitalWrite(_cs_pin, LOW);

    _spi->transfer(cmd);
    for (uint8_t i = 0; i < length; ++i) {
      data[i] = _spi->transfer(0x00);
    }

    digitalWrite(_cs_pin, HIGH);
    _spi->endTransaction();
    return true;
  }
}

bool LIS3DH::writeBytes(uint8_t reg, const uint8_t *data, uint8_t length) {
  if (!_wire && !_spi) return false;

  if (_transport == Transport::I2C) {
    // I2C: subaddress MSB for autoinc
    uint8_t sub = reg;
    if (length > 1) sub |= 0x80;
    _wire->beginTransmission(_i2c_address);
    _wire->write(sub);
    for (uint8_t i = 0; i < length; ++i) _wire->write(data[i]);
    uint8_t txerr = _wire->endTransmission(true);
    return (txerr == 0);
  } else {
    // SPI write command: RW=0, MS bit set for auto-inc when length>1
    uint8_t ms = (length > 1) ? 1 : 0;
    uint8_t cmd = (uint8_t)((reg & 0x3F) << 2) | (uint8_t)(ms << 1) | 0u;

    SPISettings settings(10000000UL, MSBFIRST, SPI_MODE0);
    _spi->beginTransaction(settings);
    digitalWrite(_cs_pin, LOW);

    _spi->transfer(cmd);
    for (uint8_t i = 0; i < length; ++i) {
      _spi->transfer(data[i]);
    }

    digitalWrite(_cs_pin, HIGH);
    _spi->endTransaction();
    return true;
  }
}

// Lifecycle and measurement implementation
bool LIS3DH::isConnected() {
  uint8_t v = 0;
  if (!readRegister(REG_WHO_AM_I, v)) return false;
  return (v == 0x33);
}

bool LIS3DH::begin() {
  // Verify WHO_AM_I
  if (!isConnected()) return false;

  // Configure safe defaults:
  // CTRL_REG1: ODR = 0101 (100Hz), LPen=0, Xen=Yen=Zen=1 => 0x57
  uint8_t ctrl1 = 0x50 | 0x07; // 0x57
  if (!writeRegister(REG_CTRL_REG1, ctrl1)) return false;

  // CTRL_REG4: BDU=1 (bit7), BLE=0, FS=00 (±2g), HR=0, ST=00, SIM=0 => 0x80
  uint8_t ctrl4 = 0x80;
  if (!writeRegister(REG_CTRL_REG4, ctrl4)) return false;

  // CTRL_REG5: ensure FIFO disabled and BOOT=0 and LIR bits default (0)
  uint8_t ctrl5 = 0x00;
  if (!writeRegister(REG_CTRL_REG5, ctrl5)) return false;

  // FIFO_CTRL_REG: bypass default
  uint8_t fctrl = 0x00;
  if (!writeRegister(REG_FIFO_CTRL_REG, fctrl)) return false;

  // Respect documented turn-on time for normal mode: 1.6 ms -> wait 2 ms
  delay(2);
  return true;
}

bool LIS3DH::configureMeasurement(const MeasurementConfig &config) {
  // Illegal combination: LPen=1 and HR=1
  if (config.lp && config.hr) return false;

  // Compose CTRL_REG1
  uint8_t odr_bits = (uint8_t)((config.odr_code & 0x0F) << 4);
  uint8_t lp_bit = config.lp ? (1 << 3) : 0;
  uint8_t axes = (config.xen ? 1 : 0) | (config.yen ? 2 : 0) | (config.zen ? 4 : 0);
  uint8_t ctrl1 = odr_bits | lp_bit | axes;

  // Compose CTRL_REG4
  uint8_t bdu = config.bdu ? 0x80 : 0x00;
  uint8_t ble = config.ble ? 0x40 : 0x00;
  uint8_t fs = (uint8_t)((config.fs & 0x03) << 4);
  uint8_t hr = config.hr ? 0x08 : 0x00;
  uint8_t st = 0x00; // preserved by other API
  uint8_t sim = 0x00; // disallow 3-wire via SPI driver
  uint8_t ctrl4 = bdu | ble | fs | hr | st | sim;

  // Write registers
  if (!writeRegister(REG_CTRL_REG1, ctrl1)) return false;
  if (!writeRegister(REG_CTRL_REG4, ctrl4)) return false;

  // Wait mode transition according to datasheet
  uint32_t odrHz = odrCodeToHz(config.odr_code);
  uint32_t delay_ms = 0;
  if (config.lp) {
    delay_ms = 1; // low-power mode turn-on
  } else if (config.hr) {
    // HR turn-on: 7/ODR seconds -> 7000/ODR ms
    if (odrHz == 0) odrHz = 100;
    delay_ms = (uint32_t)((7000.0f) / (float)odrHz);
    if (delay_ms == 0) delay_ms = 1;
  } else {
    // normal mode turn-on 1.6 ms
    delay_ms = 2;
  }
  delay(delay_ms);
  return true;
}

bool LIS3DH::getMeasurementConfig(MeasurementConfig &config) {
  uint8_t c1 = 0, c4 = 0;
  if (!readRegister(REG_CTRL_REG1, c1)) return false;
  if (!readRegister(REG_CTRL_REG4, c4)) return false;
  config.odr_code = (c1 >> 4) & 0x0F;
  config.lp = (c1 & (1 << 3)) != 0;
  config.xen = (c1 & 0x01) != 0;
  config.yen = (c1 & 0x02) != 0;
  config.zen = (c1 & 0x04) != 0;
  config.fs = (c4 >> 4) & 0x03;
  config.hr = (c4 & 0x08) != 0;
  config.bdu = (c4 & 0x80) != 0;
  config.ble = (c4 & 0x40) != 0;
  return true;
}

bool LIS3DH::readAccelerationStatus(AccelerationStatus &status) {
  uint8_t s = 0;
  if (!readRegister(REG_STATUS_REG, s)) return false;
  status.status_byte = s;
  return true;
}

// Measurement acquisition: Ensure accelerometer samples are coherent before output-register access.
// Decode acceleration only with BLE=0 in HR mode; read CTRL_REG4 before decoding and require BDU.
bool LIS3DH::readAcceleration(Acceleration &sample) {
  // Read CTRL_REG4 first: ensure BDU is set to guarantee atomic read
  uint8_t c4 = 0;
  if (!readRegister(REG_CTRL_REG4, c4)) return false;
  if (!(c4 & 0x80)) return false; // require BDU

  // Now safe to burst-read outputs
  uint8_t buf[6];
  if (!readBytes(REG_OUT_X_L, buf, 6)) return false;

  // Read CTRL_REG1 to determine resolution
  uint8_t c1 = 0;
  if (!readRegister(REG_CTRL_REG1, c1)) return false;

  bool lp = (c1 & (1 << 3)) != 0;
  bool hr = (c4 & 0x08) != 0;
  bool ble = (c4 & 0x40) != 0;

  // Reject configuration with HR+BLE set: driver supports LSB-at-lower-address only
  if (hr && ble) return false;

  uint8_t fs = (c4 >> 4) & 0x03;

  uint8_t resolution_bits = 10;
  if (lp) resolution_bits = 8;
  else if (hr) resolution_bits = 12;
  else resolution_bits = 10;

  auto decode = [&](uint8_t lo, uint8_t hi) -> int16_t {
    // Device returns left-justified 16-bit: [MSB..LSB]
    uint16_t raw16 = ((uint16_t)hi << 8) | (uint16_t)lo;
    // preserve sign by casting full word to signed then arithmetic shift
    int16_t signed16 = (int16_t)raw16;
    int shift = 16 - resolution_bits;
    int16_t result = signed16 >> shift; // arithmetic right shift
    return result;
  };

  sample.x_counts = decode(buf[0], buf[1]);
  sample.y_counts = decode(buf[2], buf[3]);
  sample.z_counts = decode(buf[4], buf[5]);

  // Sensitivity table (mg/LSb) from datasheet depending on FS and mode
  float mg_per_lsb = 4.0f; // default normal ±2g
  if (fs == 0) {
    // ±2 g
    if (hr) mg_per_lsb = 1.0f;
    else if (lp) mg_per_lsb = 16.0f;
    else mg_per_lsb = 4.0f;
  } else if (fs == 1) {
    if (hr) mg_per_lsb = 2.0f; else if (lp) mg_per_lsb = 32.0f; else mg_per_lsb = 8.0f;
  } else if (fs == 2) {
    if (hr) mg_per_lsb = 4.0f; else if (lp) mg_per_lsb = 64.0f; else mg_per_lsb = 16.0f;
  } else {
    if (hr) mg_per_lsb = 12.0f; else if (lp) mg_per_lsb = 192.0f; else mg_per_lsb = 48.0f;
  }

  sample.x_g = (float)sample.x_counts * (mg_per_lsb / 1000.0f);
  sample.y_g = (float)sample.y_counts * (mg_per_lsb / 1000.0f);
  sample.z_g = (float)sample.z_counts * (mg_per_lsb / 1000.0f);
  return true;
}

// Auxiliary ADC acquisition: Decode signed left-justified auxiliary conversions correctly.
bool LIS3DH::configureAuxiliary(bool adcEnabled, bool temperatureEnabled) {
  // If enabling ADC, set BDU in CTRL_REG4 first
  if (adcEnabled) {
    uint8_t c4 = 0;
    if (!readRegister(REG_CTRL_REG4, c4)) return false;
    if (!(c4 & 0x80)) {
      uint8_t newc4 = c4 | 0x80;
      // writeRegister will validate SIM and HR/LPen compatibility
      if (!writeRegister(REG_CTRL_REG4, newc4)) return false;
    }
  }

  // Now update TEMP_CFG_REG bits: only ADC_EN(bit7) and TEMP_EN(bit6) are allowed
  uint8_t v = 0;
  if (!readRegister(REG_TEMP_CFG_REG, v)) return false;
  uint8_t newv = (v & 0x00); // clear everything
  if (adcEnabled) newv |= (1 << 7);
  if (temperatureEnabled) newv |= (1 << 6);
  // writeRegister enforces TEMP_CFG reserved bits
  if (!writeRegister(REG_TEMP_CFG_REG, newv)) return false;
  return true;
}

bool LIS3DH::readAuxiliary(AuxiliaryData &data) {
  // Require BDU=1 for atomic ADC reads
  uint8_t c4 = 0;
  if (!readRegister(REG_CTRL_REG4, c4)) return false;
  if (!(c4 & 0x80)) return false; // BDU must be set

  uint8_t buf[6];
  if (!readBytes(REG_OUT_ADC1_L, buf, 6)) return false;

  // Auxiliary ADC are left-justified; resolution may be 10-bit or 8-bit depending on LPen
  uint8_t c1 = 0;
  if (!readRegister(REG_CTRL_REG1, c1)) return false;
  bool lp = (c1 & (1 << 3)) != 0;
  uint8_t res_bits = lp ? 8 : 10;

  auto decode = [&](uint8_t lo, uint8_t hi) -> int16_t {
    uint16_t raw16 = ((uint16_t)hi << 8) | (uint16_t)lo;
    // Cast to signed 16-bit first to preserve sign, then arithmetic right shift
    int16_t signed16 = (int16_t)raw16;
    int shift = 16 - res_bits;
    int16_t result = signed16 >> shift;
    return result;
  };

  data.adc1_counts = decode(buf[0], buf[1]);
  data.adc2_counts = decode(buf[2], buf[3]);
  data.adc3_counts = decode(buf[4], buf[5]);
  uint8_t stat = 0;
  if (!readRegister(REG_STATUS_REG_AUX, stat)) return false;
  data.status_aux = stat;
  return true;
}

// Self-test API: set ST bits then wait required samples
bool LIS3DH::setSelfTest(SelfTestMode mode) {
  uint8_t c4 = 0;
  if (!readRegister(REG_CTRL_REG4, c4)) return false;
  // Clear ST bits (bits 1 and 2)
  c4 &= ~(0x06);
  if (mode == SelfTestMode::ST0) c4 |= (0x02);
  else if (mode == SelfTestMode::ST1) c4 |= (0x04);
  if (!writeRegister(REG_CTRL_REG4, c4)) return false;

  // Determine samples required: 2 samples for normal/low-power, 8 for HR
  uint8_t c1 = 0;
  if (!readRegister(REG_CTRL_REG1, c1)) return false;
  bool lp = (c1 & (1 << 3)) != 0;
  bool hr = (c4 & 0x08) != 0;
  uint32_t samples = hr ? 8 : 2;
  uint32_t odrHz = odrCodeToHz((c1 >> 4) & 0x0F);
  if (odrHz == 0) odrHz = 100;
  uint32_t wait_ms = (uint32_t)((samples * 1000.0f) / (float)odrHz) + 1;
  delay(wait_ms);
  return true;
}

// Optional feature implementation: FIFO
bool LIS3DH::getFifoStatus(FifoStatus &status) {
  uint8_t v = 0;
  if (!readRegister(REG_FIFO_SRC_REG, v)) return false;
  status.wtm = (v & 0x80) != 0;
  status.overrun = (v & 0x40) != 0;
  status.empty = (v & 0x20) != 0;
  status.level = v & 0x1F;
  return true;
}

bool LIS3DH::readFifo(Acceleration *samples, uint8_t capacity, uint8_t &count) {
  count = 0;
  if (!samples || capacity == 0) return false;
  FifoStatus s;
  if (!getFifoStatus(s)) return false;
  uint8_t toRead = s.level;
  if (toRead > capacity) toRead = capacity;

  // Consume samples one by one to avoid I2C Wire buffer size limits
  for (uint8_t i = 0; i < toRead; ++i) {
    Acceleration a;
    if (!readAcceleration(a)) break;
    samples[count++] = a;
  }
  return true;
}

bool LIS3DH::clearFifo(const FifoConfig &config) {
  // Enter bypass mode (FM=00) then restore config
  uint8_t fctrl = 0x00;
  if (!writeRegister(REG_FIFO_CTRL_REG, fctrl)) return false;
  // Restore provided config
  uint8_t fm = (config.mode & 0x03) << 6;
  uint8_t tr = config.trigger_int2 ? (1 << 5) : 0;
  uint8_t fth = config.watermark & 0x1F;
  uint8_t newf = fm | tr | fth;
  if (!writeRegister(REG_FIFO_CTRL_REG, newf)) return false;
  return true;
}

bool LIS3DH::configureFifo(const FifoConfig &config) {
  uint8_t ctrl5 = 0;
  if (!readRegister(REG_CTRL_REG5, ctrl5)) return false;
  if (config.enable) ctrl5 |= (1 << 6); else ctrl5 &= ~(1 << 6);
  if (!writeRegister(REG_CTRL_REG5, ctrl5)) return false;
  uint8_t fm = (config.mode & 0x03) << 6;
  uint8_t tr = config.trigger_int2 ? (1 << 5) : 0;
  uint8_t fth = config.watermark & 0x1F;
  uint8_t fctrl = fm | tr | fth;
  if (!writeRegister(REG_FIFO_CTRL_REG, fctrl)) return false;
  return true;
}

bool LIS3DH::configureHighPassFilter(const HighPassConfig &config) {
  uint8_t v = 0;
  if (!readRegister(REG_CTRL_REG2, v)) return false;
  v &= ~(0xC0); // clear HPM
  v |= ((config.hpm & 0x03) << 6);
  v &= ~(0x30);
  v |= ((config.hpcf & 0x03) << 4);
  if (config.fds) v |= (1 << 3); else v &= ~(1 << 3);
  if (config.hp_click) v = (v | (1 << 2)); else v &= ~(1 << 2);
  if (config.hp_ia2) v = (v | (1 << 1)); else v &= ~(1 << 1);
  if (config.hp_ia1) v = (v | (1 << 0)); else v &= ~(1 << 0);
  return writeRegister(REG_CTRL_REG2, v);
}

bool LIS3DH::setReference(uint8_t value) {
  return writeRegister(REG_REFERENCE, value);
}

bool LIS3DH::readReference(uint8_t &value) {
  return readRegister(REG_REFERENCE, value);
}

// Interrupt, click, and activity configuration
bool LIS3DH::configureInterruptGenerator(InterruptPin interrupt, const InterruptConfig &config) {
  // Validate 7-bit fields
  if ((config.ths & 0x80) != 0) return false;
  if ((config.dur & 0x80) != 0) return false;

  if (interrupt == InterruptPin::INT1) {
    if (!writeRegister(REG_INT1_CFG, config.cfg)) return false;
    if (!writeRegister(REG_INT1_THS, config.ths & 0x7F)) return false;
    if (!writeRegister(REG_INT1_DURATION, config.dur & 0x7F)) return false;
    // Apply latch to CTRL_REG5 LIR_INT1 (bit3)
    uint8_t ctrl5 = 0;
    if (!readRegister(REG_CTRL_REG5, ctrl5)) return false;
    if (config.latch) ctrl5 |= (1 << 3); else ctrl5 &= ~(1 << 3);
    if (!writeRegister(REG_CTRL_REG5, ctrl5)) return false;
    return true;
  } else {
    if (!writeRegister(REG_INT2_CFG, config.cfg)) return false;
    if (!writeRegister(REG_INT2_THS, config.ths & 0x7F)) return false;
    if (!writeRegister(REG_INT2_DURATION, config.dur & 0x7F)) return false;
    // Apply latch to CTRL_REG5 LIR_INT2 (bit1)
    uint8_t ctrl5 = 0;
    if (!readRegister(REG_CTRL_REG5, ctrl5)) return false;
    if (config.latch) ctrl5 |= (1 << 1); else ctrl5 &= ~(1 << 1);
    if (!writeRegister(REG_CTRL_REG5, ctrl5)) return false;
    return true;
  }
}

bool LIS3DH::readInterruptSource(InterruptPin interrupt, InterruptSource &source) {
  uint8_t v = 0;
  if (interrupt == InterruptPin::INT1) {
    if (!readRegister(REG_INT1_SRC, v)) return false;
  } else {
    if (!readRegister(REG_INT2_SRC, v)) return false;
  }
  source.srcbyte = v;
  return true;
}

bool LIS3DH::configureInterruptRouting(const InterruptRouting &routing) {
  // Validate CTRL_REG3/6 reserved bits via writeRegister
  if (!writeRegister(REG_CTRL_REG3, routing.ctrl3)) return false;
  if (!writeRegister(REG_CTRL_REG6, routing.ctrl6)) return false;
  return true;
}

bool LIS3DH::configureClick(const ClickConfig &config) {
  // Validate TIME_LIMIT (bit7 must be clear)
  if ((config.tlimit & 0x80) != 0) return false;
  // CLICK_CFG bits7:6 must be clear
  if ((config.cfg & 0xC0) != 0) return false;
  if (!writeRegister(REG_CLICK_CFG, config.cfg)) return false;
  if (!writeRegister(REG_CLICK_THS, config.ths)) return false;
  if (!writeRegister(REG_TIME_LIMIT, config.tlimit & 0x7F)) return false;
  if (!writeRegister(REG_TIME_LATENCY, config.tlatency)) return false;
  if (!writeRegister(REG_TIME_WINDOW, config.twindow)) return false;
  return true;
}

bool LIS3DH::readClickSource(ClickSource &source) {
  uint8_t v = 0;
  if (!readRegister(REG_CLICK_SRC, v)) return false;
  source.src = v;
  return true;
}

bool LIS3DH::configureActivity(uint8_t threshold, uint8_t duration) {
  if ((threshold & 0x80) != 0) return false; // 7-bit only
  if (!writeRegister(REG_ACT_THS, threshold & 0x7F)) return false;
  if (!writeRegister(REG_ACT_DUR, duration)) return false;
  return true;
}

// Advanced mapped register access
bool LIS3DH::readRegister(uint8_t reg, uint8_t &value) {
  return readBytes(reg, &value, 1);
}

bool LIS3DH::writeRegister(uint8_t reg, uint8_t value) {
  // Whitelist of explicitly writable registers (from register map)
  static const uint8_t writable[] = {
    REG_CTRL_REG0, REG_TEMP_CFG_REG, REG_CTRL_REG1, REG_CTRL_REG2, REG_CTRL_REG3,
    REG_CTRL_REG4, REG_CTRL_REG5, REG_CTRL_REG6, REG_REFERENCE, REG_FIFO_CTRL_REG,
    REG_INT1_CFG, REG_INT1_THS, REG_INT1_DURATION, REG_INT2_CFG, REG_INT2_THS,
    REG_INT2_DURATION, REG_CLICK_CFG, REG_CLICK_THS, REG_TIME_LIMIT, REG_TIME_LATENCY,
    REG_TIME_WINDOW, REG_ACT_THS, REG_ACT_DUR
  };
  bool allowed = false;
  for (uint8_t r : writable) if (r == reg) { allowed = true; break; }
  if (!allowed) return false; // reject unlisted addresses

  // Enforce per-register reserved/fixed bits and global compatibility rules
  // CTRL_REG0 (0x1E): only bit7 (SDO_PU_DISC) may change; bits 6:0 must equal 0x10
  if (reg == REG_CTRL_REG0) {
    if ((value & 0x7F) != 0x10) return false;
    // allow bit7 either 0 or 1
    uint8_t out = (value & 0x80) | 0x10;
    return writeBytes(reg, &out, 1);
  }

  // TEMP_CFG_REG (0x1F): bits 5:0 must be 0; only bits 7 and 6 allowed
  if (reg == REG_TEMP_CFG_REG) {
    if ((value & 0x3F) != 0) return false;
    return writeBytes(reg, &value, 1);
  }

  // CTRL_REG3 (0x22): bit0 must be 0
  if (reg == REG_CTRL_REG3) {
    if (value & 0x01) return false;
    return writeBytes(reg, &value, 1);
  }

  // CTRL_REG5 (0x24): bits 5:4 must be 0
  if (reg == REG_CTRL_REG5) {
    if (value & 0x30) return false;
    return writeBytes(reg, &value, 1);
  }

  // CTRL_REG6 (0x25): bits 2 and 0 must be 0
  if (reg == REG_CTRL_REG6) {
    if (value & 0x05) return false;
    return writeBytes(reg, &value, 1);
  }

  // INT1_THS, INT1_DURATION, INT2_THS, INT2_DURATION, TIME_LIMIT, ACT_THS must have bit7 clear
  if (reg == REG_INT1_THS || reg == REG_INT1_DURATION || reg == REG_INT2_THS ||
      reg == REG_INT2_DURATION || reg == REG_TIME_LIMIT || reg == REG_ACT_THS) {
    if (value & 0x80) return false;
    return writeBytes(reg, &value, 1);
  }

  // CLICK_CFG bits7:6 must be clear
  if (reg == REG_CLICK_CFG) {
    if (value & 0xC0) return false;
    return writeBytes(reg, &value, 1);
  }

  // CTRL_REG4 (0x23): SIM must remain 0 for SPI transport; also prevent LPen+HR illegal combination
  if (reg == REG_CTRL_REG4) {
    // If SPI transport, SIM must be 0
    if (_transport == Transport::SPI && (value & 0x01)) return false;
    // If HR being set while CTRL_REG1 LPen==1 -> invalid
    uint8_t c1 = 0;
    if (!readRegister(REG_CTRL_REG1, c1)) return false;
    bool lpen = (c1 & (1 << 3)) != 0;
    bool set_hr = (value & 0x08) != 0;
    if (lpen && set_hr) return false;
    // allow other bits (BDU, BLE, FS, ST)
    return writeBytes(reg, &value, 1);
  }

  // CTRL_REG1 writes: prevent setting LPen when CTRL_REG4 HR==1
  if (reg == REG_CTRL_REG1) {
    uint8_t c4 = 0;
    if (!readRegister(REG_CTRL_REG4, c4)) return false;
    bool hr = (c4 & 0x08) != 0;
    bool set_lpen = (value & (1 << 3)) != 0;
    if (hr && set_lpen) return false;
    return writeBytes(reg, &value, 1);
  }

  // FIFO_CTRL_REG (0x2E): FTH 5 bits allowed, TR bit allowed, FM bits allowed
  if (reg == REG_FIFO_CTRL_REG) {
    // FM[1:0] in bits7:6, TR bit5, FTH[4:0] bits 4:0 -> accept any value within 8 bits
    return writeBytes(reg, &value, 1);
  }

  // REFERENCE, TIME_LATENCY, TIME_WINDOW, ACT_DUR: full byte writable
  if (reg == REG_REFERENCE || reg == REG_TIME_LATENCY || reg == REG_TIME_WINDOW || reg == REG_ACT_DUR) {
    return writeBytes(reg, &value, 1);
  }

  // INT1_CFG and INT2_CFG and INTx_THS/DURATION handled above or allowed
  if (reg == REG_INT1_CFG || reg == REG_INT2_CFG || reg == REG_INT1_THS || reg == REG_INT1_DURATION ||
      reg == REG_INT2_THS || reg == REG_INT2_DURATION) {
    // INTx_CFG may be written (boot-loaded in hardware but writable after boot). THS/DURATION validated above.
    return writeBytes(reg, &value, 1);
  }

  // CLICK_THS (0x3A) allows LIR bit (bit7) and Ths[6:0]
  if (reg == REG_CLICK_THS) {
    // Accept any value 0..255 because bit7 is latch control
    return writeBytes(reg, &value, 1);
  }

  // Default fallback: if listed writable and not matched above, write directly
  return writeBytes(reg, &value, 1);
}

bool LIS3DH::setSa0PullupDisconnected(bool disconnect) {
  // CTRL_REG0 bit7 SDO_PU_DISC
  uint8_t cur = 0;
  if (!readRegister(REG_CTRL_REG0, cur)) return false;
  uint8_t newv = cur;
  if (disconnect) newv |= (1 << 7); else newv &= ~(1 << 7);
  return writeRegister(REG_CTRL_REG0, newv);
}

// Optional feature implementation: reboot memory
bool LIS3DH::rebootMemory() {
  uint8_t v = 0;
  if (!readRegister(REG_CTRL_REG5, v)) return false;
  v |= (1 << 7); // BOOT bit
  if (!writeRegister(REG_CTRL_REG5, v)) return false;
  delay(5);
  return true;
}

