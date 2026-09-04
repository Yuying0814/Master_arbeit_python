/*
Source implementing initialization, configuration, data acquisition, FIFO, ADC and interrupt helpers, low-level SPI/I2C transactions and conversion utilities.
*/

// section: Includes and private constants
#include "LIS3DH.h"

// Default SPI settings for the device (master must call SPI.begin())
static const uint32_t DEFAULT_SPI_CLOCK = 5000000UL; // 5 MHz conservative
static const uint8_t WHOAMI_EXPECT = LIS3DH_WHO_AM_I_ID;
static const uint32_t BOOT_WAIT_MS = 5; // boot procedure complete about 5 ms after power-up

// section: Constructor and begin methods
LIS3DH::LIS3DH()
  : _busIsSPI(false), _i2caddr(0), _csPin(255), _spi(nullptr), _spiSettings(DEFAULT_SPI_CLOCK, MSBFIRST, SPI_MODE0),
    _fs_code(0), _hr_enabled(false), _bdu_enabled(false), _lpen_enabled(false), _sim_supported(false), _sim_enabled(false) {
}

bool LIS3DH::beginI2C(uint8_t i2c_address, bool verify) {
  _busIsSPI = false;
  _i2caddr = i2c_address & 0x7F;
  // Per design do NOT call Wire.begin() here. Application must initialize Wire.
  // Wait boot time to allow device to be ready if it was just powered.
  delay(BOOT_WAIT_MS);
  if (verify) {
    uint8_t id = whoAmI();
    return (id == WHOAMI_EXPECT);
  }
  return true;
}

bool LIS3DH::beginSPI(uint8_t csPin, SPIClass &spi, bool verify) {
  _busIsSPI = true;
  _csPin = csPin;
  _spi = &spi;
  pinMode(_csPin, OUTPUT);
  digitalWrite(_csPin, HIGH);
  _spiSettings = SPISettings(DEFAULT_SPI_CLOCK, MSBFIRST, SPI_MODE0);
  delay(BOOT_WAIT_MS);
  if (verify) {
    uint8_t id = whoAmI();
    if (id != WHOAMI_EXPECT) return false;
  }
  // Read CTRL_REG4 to cache SIM bit state; spi transactions will work in 4-wire if SIM==0
  int r = readRegister(LIS3DH_REG_CTRL_REG4);
  if (r >= 0) {
    _sim_enabled = ((uint8_t)r & LIS3DH_CTRL_REG4_SIM) != 0;
  } else {
    _sim_enabled = false;
  }
  return true;
}

uint8_t LIS3DH::whoAmI() {
  int v = readRegister(LIS3DH_REG_WHO_AM_I);
  if (v < 0) return 0x00;
  return (uint8_t)v;
}

bool LIS3DH::reboot() {
  // Set BOOT bit in CTRL_REG5
  int r = readRegister(LIS3DH_REG_CTRL_REG5);
  if (r < 0) return false;
  uint8_t v = (uint8_t)r | LIS3DH_CTRL_REG5_BOOT;
  if (!writeRegister(LIS3DH_REG_CTRL_REG5, v)) return false;
  delay(BOOT_WAIT_MS);
  return true;
}

// section: Configuration and mode change implementations
bool LIS3DH::setODR(uint8_t odr_code) {
  // write ODR bits (top 4 bits of CTRL_REG1)
  int r = readRegister(LIS3DH_REG_CTRL_REG1);
  if (r < 0) return false;
  uint8_t v = (uint8_t)r;
  v &= ~LIS3DH_CTRL_REG1_ODR_MASK;
  v |= (odr_code & LIS3DH_CTRL_REG1_ODR_MASK);
  return writeRegister(LIS3DH_REG_CTRL_REG1, v);
}

bool LIS3DH::setPowerMode(bool lowPower, bool highResolution, float odr_hz) {
  // Check forbidden combination: LPen=1 and HR=1 not allowed
  if (lowPower && highResolution) return false;

  // Read current CTRL_REG1 and CTRL_REG4
  int r1 = readRegister(LIS3DH_REG_CTRL_REG1);
  int r4 = readRegister(LIS3DH_REG_CTRL_REG4);
  if (r1 < 0 || r4 < 0) return false;
  uint8_t v1 = (uint8_t)r1;
  uint8_t v4 = (uint8_t)r4;

  bool oldHR = (v4 & LIS3DH_CTRL_REG4_HR) != 0;

  // Set/clear LPen
  if (lowPower) v1 |= LIS3DH_CTRL_REG1_LPEN; else v1 &= ~LIS3DH_CTRL_REG1_LPEN;
  // Set/clear HR
  if (highResolution) v4 |= LIS3DH_CTRL_REG4_HR; else v4 &= ~LIS3DH_CTRL_REG4_HR;

  // Write registers
  if (!writeRegister(LIS3DH_REG_CTRL_REG1, v1)) return false;
  if (!writeRegister(LIS3DH_REG_CTRL_REG4, v4)) return false;

  // Compute required delay and wait
  uint32_t wait_ms = computeModeTransitionDelayMs(oldHR, highResolution, odr_hz);
  if (wait_ms > 0) delay(wait_ms);

  _hr_enabled = highResolution;
  _lpen_enabled = lowPower;
  return true;
}

bool LIS3DH::enableAxis(bool x, bool y, bool z) {
  int r = readRegister(LIS3DH_REG_CTRL_REG1);
  if (r < 0) return false;
  uint8_t v = (uint8_t)r;
  if (x) v |= LIS3DH_CTRL_REG1_XEN; else v &= ~LIS3DH_CTRL_REG1_XEN;
  if (y) v |= LIS3DH_CTRL_REG1_YEN; else v &= ~LIS3DH_CTRL_REG1_YEN;
  if (z) v |= LIS3DH_CTRL_REG1_ZEN; else v &= ~LIS3DH_CTRL_REG1_ZEN;
  return writeRegister(LIS3DH_REG_CTRL_REG1, v);
}

bool LIS3DH::setFullScale(uint8_t fs_code) {
  if (fs_code > 3) return false;
  int r = readRegister(LIS3DH_REG_CTRL_REG4);
  if (r < 0) return false;
  uint8_t v = (uint8_t)r;
  v &= ~LIS3DH_CTRL_REG4_FS_MASK;
  v |= ((fs_code & 0x3) << 4);
  if (!writeRegister(LIS3DH_REG_CTRL_REG4, v)) return false;
  _fs_code = fs_code;
  return true;
}

bool LIS3DH::setBDU(bool enable) {
  int r = readRegister(LIS3DH_REG_CTRL_REG4);
  if (r < 0) return false;
  uint8_t v = (uint8_t)r;
  if (enable) v |= LIS3DH_CTRL_REG4_BDU; else v &= ~LIS3DH_CTRL_REG4_BDU;
  if (!writeRegister(LIS3DH_REG_CTRL_REG4, v)) return false;
  _bdu_enabled = enable;
  return true;
}

bool LIS3DH::setBLE(bool bigEndian) {
  int r = readRegister(LIS3DH_REG_CTRL_REG4);
  if (r < 0) return false;
  uint8_t v = (uint8_t)r;
  if (bigEndian) v |= LIS3DH_CTRL_REG4_BLE; else v &= ~LIS3DH_CTRL_REG4_BLE;
  return writeRegister(LIS3DH_REG_CTRL_REG4, v);
}

bool LIS3DH::setSIM(bool threeWire) {
  // This port refuses to enable 3-wire SPI (SIM=1). Return false if caller requests SIM=1.
  if (threeWire) {
    return false; // unsupported on this port; do not change device register
  }
  // Clearing SIM (set 4-wire) is allowed
  int r = readRegister(LIS3DH_REG_CTRL_REG4);
  if (r < 0) return false;
  uint8_t v = (uint8_t)r & ~LIS3DH_CTRL_REG4_SIM;
  if (!writeRegister(LIS3DH_REG_CTRL_REG4, v)) return false;
  _sim_enabled = false;
  return true;
}

bool LIS3DH::selfTest(uint8_t mode, float odr_hz) {
  if (mode > 2) return false;
  int r = readRegister(LIS3DH_REG_CTRL_REG4);
  if (r < 0) return false;
  uint8_t v = (uint8_t)r & ~LIS3DH_CTRL_REG4_ST_MASK;
  v |= ((mode & 0x3) << 1);
  if (!writeRegister(LIS3DH_REG_CTRL_REG4, v)) return false;

  // Wait required number of samples: HR -> 8, normal/LP -> 2
  bool hr = (_hr_enabled);
  uint8_t samples = hr ? 8 : 2;
  float wait_ms = (1000.0f * samples) / (odr_hz > 0.0f ? odr_hz : 100.0f);
  // add small margin
  delay((uint32_t)ceil(wait_ms) + 2);
  return true;
}

// section: FIFO, ADC, interrupts and click implementations
bool LIS3DH::enableADC(bool adcEnable, bool tempEnable) {
  int r = readRegister(LIS3DH_REG_TEMP_CFG_REG);
  if (r < 0) return false;
  uint8_t v = (uint8_t)r;
  if (adcEnable) v |= (1 << 7); else v &= ~(1 << 7);
  if (tempEnable) v |= (1 << 6); else v &= ~(1 << 6);
  return writeRegister(LIS3DH_REG_TEMP_CFG_REG, v);
}

int16_t LIS3DH::readADC(uint8_t channel) {
  // channel must be 1..3
  if (channel < 1 || channel > 3) return INT16_MIN;
  uint8_t base = LIS3DH_REG_OUT_ADC1_L + (channel - 1) * 2;
  uint8_t buf[2] = {0,0};
  if (!readRegisters(base, buf, 2)) return INT16_MIN;
  // 10-bit left-aligned in two bytes, combine to signed 16
  int16_t raw = (int16_t)((buf[1] << 8) | buf[0]);
  return raw;
}

bool LIS3DH::configureFIFO(bool enable, uint8_t fifoMode, uint8_t watermark) {
  // CTRL_REG5 FIFO_EN bit
  int r5 = readRegister(LIS3DH_REG_CTRL_REG5);
  if (r5 < 0) return false;
  uint8_t v5 = (uint8_t)r5;
  if (enable) v5 |= LIS3DH_CTRL_REG5_FIFO_EN; else v5 &= ~LIS3DH_CTRL_REG5_FIFO_EN;
  if (!writeRegister(LIS3DH_REG_CTRL_REG5, v5)) return false;
  // FIFO_CTRL_REG: FM[1:0] (bits7:6) TR bit5 and FTH bits0:4
  uint8_t fifo = (uint8_t)((fifoMode & 0x3) << 6) | (watermark & 0x1F);
  if (!writeRegister(LIS3DH_REG_FIFO_CTRL_REG, fifo)) return false;
  return true;
}

uint8_t LIS3DH::readFifoStatus() {
  int r = readRegister(LIS3DH_REG_FIFO_SRC_REG);
  if (r < 0) return 0xFF;
  return (uint8_t)r;
}

// Return FSS (0..31) or -1 on error
int LIS3DH::getFifoSampleCount() {
  int r = readRegister(LIS3DH_REG_FIFO_SRC_REG);
  if (r < 0) return -1;
  uint8_t v = (uint8_t)r;
  return (int)(v & 0x1F);
}

bool LIS3DH::readFifoStatusParsed(uint8_t &fss, bool &wtm, bool &ovrn, bool &empty) {
  int r = readRegister(LIS3DH_REG_FIFO_SRC_REG);
  if (r < 0) return false;
  uint8_t v = (uint8_t)r;
  wtm = (v & 0x80) != 0;
  ovrn = (v & 0x40) != 0;
  empty = (v & 0x20) != 0;
  fss = v & 0x1F;
  return true;
}

bool LIS3DH::readFifoSamples(uint8_t maxSamples, int16_t *outBuffer, uint8_t &samplesRead) {
  samplesRead = 0;
  if (!outBuffer) return false;
  // Read FIFO status
  uint8_t fss=0; bool wtm=false, ovrn=false, empty=false;
  if (!readFifoStatusParsed(fss, wtm, ovrn, empty)) return false;
  if (ovrn) return false; // caller should inspect status
  uint8_t available = fss;
  if (available == 0) return true; // nothing to do
  if (maxSamples == 0) return false;
  uint8_t toRead = available;
  if (toRead > maxSamples) toRead = maxSamples;
  if (toRead > 32) toRead = 32; // device FIFO max 32 sample-sets
  size_t total_bytes = (size_t)toRead * 6;
  if (total_bytes == 0) return true;
  // temporary buffer: 6 * 32 = 192 bytes maximum
  uint8_t tmp[192];
  if (!readRegisters(LIS3DH_REG_OUT_X_L, tmp, total_bytes)) return false;
  // Parse into int16_t left-justified values
  for (uint8_t i = 0; i < toRead; ++i) {
    size_t off = (size_t)i * 6;
    int16_t x = (int16_t)((tmp[off+1] << 8) | tmp[off+0]);
    int16_t y = (int16_t)((tmp[off+3] << 8) | tmp[off+2]);
    int16_t z = (int16_t)((tmp[off+5] << 8) | tmp[off+4]);
    outBuffer[(size_t)i*3 + 0] = x;
    outBuffer[(size_t)i*3 + 1] = y;
    outBuffer[(size_t)i*3 + 2] = z;
  }
  samplesRead = toRead;
  return true;
}

bool LIS3DH::drainFIFO() {
  // Repeatedly read and discard until EMPTY
  while (true) {
    uint8_t fss; bool wtm, ovrn, empty;
    if (!readFifoStatusParsed(fss, wtm, ovrn, empty)) return false;
    if (ovrn) return false; // overrun detected
    if (empty) return true;
    if (fss == 0) return true;
    uint8_t chunk = fss;
    if (chunk > 32) chunk = 32;
    // temporary buffer to consume
    static int16_t discardBuf[3*32];
    uint8_t samplesRead = 0;
    if (!readFifoSamples(chunk, discardBuf, samplesRead)) return false;
    if (samplesRead == 0) return true; // nothing more
    // loop continues until empty
  }
}

// section: Data acquisition
bool LIS3DH::readRaw(int16_t &x, int16_t &y, int16_t &z) {
  // Read 6 bytes starting at OUT_X_L (auto-increment)
  uint8_t buf[6];
  if (!readRegisters(LIS3DH_REG_OUT_X_L, buf, 6)) return false;
  // Little-endian bytes: OUT_X_L, OUT_X_H ... left-justified 16-bit two's complement
  x = (int16_t)((buf[1] << 8) | buf[0]);
  y = (int16_t)((buf[3] << 8) | buf[2]);
  z = (int16_t)((buf[5] << 8) | buf[4]);
  return true;
}

bool LIS3DH::readNormalized(float &gx, float &gy, float &gz) {
  int16_t rx, ry, rz;
  if (!readRaw(rx, ry, rz)) return false;

  // Determine effective bits
  uint8_t eff_bits = 10;
  if (_lpen_enabled) eff_bits = 8;
  else if (_hr_enabled) eff_bits = 12;
  else eff_bits = 10;

  int shift = 16 - (int)eff_bits;

  auto convert = [&](int16_t raw)->float {
    // arithmetic right shift to get signed count at effective resolution
    int32_t cnt = (int32_t)raw >> shift;
    // mg/digit mapping per FS and mode
    int fs = _fs_code & 0x3;
    float mg_per_digit = 4.0f; // default normal ±2g
    if (fs == LIS3DH_FS_2G) {
      if (_hr_enabled) mg_per_digit = 1.0f;
      else if (_lpen_enabled) mg_per_digit = 16.0f;
      else mg_per_digit = 4.0f;
    } else if (fs == LIS3DH_FS_4G) {
      if (_hr_enabled) mg_per_digit = 2.0f;
      else if (_lpen_enabled) mg_per_digit = 32.0f;
      else mg_per_digit = 8.0f;
    } else if (fs == LIS3DH_FS_8G) {
      if (_hr_enabled) mg_per_digit = 4.0f;
      else if (_lpen_enabled) mg_per_digit = 64.0f;
      else mg_per_digit = 16.0f;
    } else { // ±16g
      if (_hr_enabled) mg_per_digit = 12.0f;
      else if (_lpen_enabled) mg_per_digit = 192.0f;
      else mg_per_digit = 48.0f;
    }
    float g = (float)cnt * (mg_per_digit * 0.001f);
    return g;
  };

  gx = convert(rx);
  gy = convert(ry);
  gz = convert(rz);
  return true;
}

// section: FIFO, ADC, interrupts and click continued
bool LIS3DH::configureInterrupts(uint8_t ctrl3_mask, uint8_t ctrl6_mask) {
  if (!writeRegister(LIS3DH_REG_CTRL_REG3, ctrl3_mask)) return false;
  if (!writeRegister(LIS3DH_REG_CTRL_REG6, ctrl6_mask)) return false;
  return true;
}

uint8_t LIS3DH::readInt1Src() {
  int r = readRegister(LIS3DH_REG_INT1_SRC);
  if (r < 0) return 0xFF;
  return (uint8_t)r;
}

uint8_t LIS3DH::readClickSrc() {
  int r = readRegister(LIS3DH_REG_CLICK_SRC);
  if (r < 0) return 0xFF;
  return (uint8_t)r;
}

bool LIS3DH::setSDOPullupDisconnect(bool disconnect) {
  int r = readRegister(LIS3DH_REG_CTRL_REG0);
  if (r < 0) return false;
  uint8_t v = (uint8_t)r;
  if (disconnect) v |= LIS3DH_CTRL_REG0_SDO_PU_DISC; else v &= ~LIS3DH_CTRL_REG0_SDO_PU_DISC;
  return writeRegister(LIS3DH_REG_CTRL_REG0, v);
}

// section: Low-level bus helpers

bool LIS3DH::readRegisters(uint8_t startReg, uint8_t *buf, size_t len) {
  if (_busIsSPI) {
    return spiWriteReadMultiple(startReg, nullptr, buf, len);
  } else {
    return i2cWriteThenRead(startReg, buf, len);
  }
}

bool LIS3DH::writeRegisters(uint8_t startReg, const uint8_t *buf, size_t len) {
  if (_busIsSPI) {
    // For SPI write, send command then data
    return spiWriteReadMultiple(startReg, buf, nullptr, len);
  } else {
    // I2C write: write register pointer + data
    Wire.beginTransmission(_i2caddr);
    Wire.write(startReg);
    size_t written = Wire.write(buf, len);
    uint8_t res = Wire.endTransmission();
    return (res == 0) && (written == len);
  }
}

bool LIS3DH::spiWriteReadMultiple(uint8_t reg, const uint8_t *tx, uint8_t *rx, size_t len) {
  if (!_spi || _csPin == 255) return false;
  // If device is configured for 3-wire (SIM=1) we refuse to operate because this port does not implement 3-wire turn-around.
  if (_sim_enabled) return false;

  // Build command byte according to datasheet: bit0 = RW(1=read), bit1 = MS(auto-increment), bits2..7 = address
  uint8_t cmd = (reg & 0x3F);
  if (len > 1) cmd |= 0x40; // MS = auto-increment
  if (rx != nullptr && tx == nullptr) cmd |= 0x80; // READ

  _spi->beginTransaction(_spiSettings);
  digitalWrite(_csPin, LOW);
  // Send command byte
  _spi->transfer(cmd);
  if (rx && tx == nullptr) {
    // Read len bytes
    for (size_t i = 0; i < len; ++i) {
      rx[i] = _spi->transfer(0x00);
    }
  } else if (tx && rx == nullptr) {
    // Write len bytes
    for (size_t i = 0; i < len; ++i) {
      _spi->transfer(tx[i]);
    }
  } else if (tx && rx) {
    // Full-duplex transfer
    for (size_t i = 0; i < len; ++i) {
      rx[i] = _spi->transfer(tx[i]);
    }
  }
  digitalWrite(_csPin, HIGH);
  _spi->endTransaction();
  return true;
}

bool LIS3DH::i2cWriteThenRead(uint8_t reg, uint8_t *rx, size_t len) {
  // Handle Wire buffer limitations by chunking reads into <= 32 byte requests.
  const size_t CHUNK_MAX = 32;
  size_t remaining = len;
  size_t offset = 0;
  while (remaining > 0) {
    size_t chunk = remaining;
    if (chunk > CHUNK_MAX) chunk = CHUNK_MAX;
    // Write register pointer for this chunk (startReg + offset)
    Wire.beginTransmission(_i2caddr);
    Wire.write((uint8_t)(reg + offset));
    uint8_t res = Wire.endTransmission(false); // restart
    if (res != 0) return false;
    size_t got = Wire.requestFrom((int)_i2caddr, (int)chunk, (int)true);
    if (got != chunk) return false;
    for (size_t i = 0; i < chunk; ++i) {
      int b = Wire.read();
      if (b < 0) return false;
      rx[offset + i] = (uint8_t)b;
    }
    remaining -= chunk;
    offset += chunk;
  }
  return true;
}

// public low-level read/write
int LIS3DH::readRegister(uint8_t reg) {
  uint8_t buf[1];
  if (!readRegisters(reg, buf, 1)) return -1;
  return (int)buf[0];
}

bool LIS3DH::writeRegister(uint8_t reg, uint8_t value) {
  uint8_t buf[1] = { value };
  return writeRegisters(reg, buf, 1);
}

// section: Conversion and utility helpers
uint32_t LIS3DH::computeModeTransitionDelayMs(bool oldHR, bool newHR, float odr_hz) {
  // Implement rules from Table 10 and 11.
  // If entering high-resolution from non-HR: 7/ODR seconds
  // Otherwise for most other transitions use 1/ODR seconds (1000/ODR ms)
  if (odr_hz <= 0.0f) odr_hz = 100.0f;
  if (!oldHR && newHR) {
    float ms = (7000.0f / odr_hz);
    return (uint32_t)ceil(ms);
  }
  if (oldHR && !newHR) {
    float ms = (1000.0f / odr_hz);
    return (uint32_t)ceil(ms);
  }
  // No HR change: minimal delays: if entering LP -> 1 ms; entering normal from LP -> ~2 ms (1.6ms rounded)
  if (_lpen_enabled && !newHR) {
    // currently low-power; transitioning out to normal
    return 2; // conservative
  }
  return 0;
}

uint8_t LIS3DH::readStatus() {
  int r = readRegister(LIS3DH_REG_STATUS_REG);
  if (r < 0) return 0xFF;
  return (uint8_t)r;
}

uint8_t LIS3DH::readStatusAux() {
  int r = readRegister(LIS3DH_REG_STATUS_REG_AUX);
  if (r < 0) return 0xFF;
  return (uint8_t)r;
}

// End of file

