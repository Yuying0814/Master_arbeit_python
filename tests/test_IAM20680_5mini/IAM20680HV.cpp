/*
Source file implementing IAM20680HV methods and low-level bus operations using Wire.h and SPI.h.
*/

// Includes and private constants: include header and transports
// Includes and private constants: ...
#include "IAM20680HV.h"
#include <Wire.h>
#include <SPI.h>
#include <math.h>

// Includes and private constants: datasheet-derived sensitivity tables and conversion constants
// Gyro sensitivity per datasheet retrieval (page 6 in retrieval results): 262,131,65.5,32.8 LSB/dps
static const float GYRO_SENS_TABLE[4] = {262.0f, 131.0f, 65.5f, 32.8f};
// Accelerometer sensitivity per datasheet retrieval (page 7 in retrieval results): 16384,8192,4096,2048 LSB/g
static const float ACCEL_SENS_TABLE[4] = {16384.0f, 8192.0f, 4096.0f, 2048.0f};

// Temperature conversion constants (from retrieval results page 9):
// TEMP [°C] = ((TEMP_OUT - RoomTemp_Offset) / Temp_Sensitivity) + 25°C
static const float TEMP_SENSITIVITY = 326.8f; // LSB/°C (typical from datasheet page 9)
static const float ROOM_TEMP_OFFSET = 0.0f;   // typical

// Constructor
IAM20680HV::IAM20680HV() {
  // default self-test options
  _selfTestOpts.mode = SelfTestOtpMode::ST_CODE;
  _selfTestOpts.tolerance_fraction = 0.30f;
}

// Constructor and begin implementations
bool IAM20680HV::beginI2C(TwoWire &wire, uint8_t address) {
  _wire = &wire;
  _i2caddr = address;
  _trans = TRANSPORT_I2C;

  // Wait startup time per datasheet (typical 11 ms) before register R/W (retrieval page 9)
  delay(11);

  // Soft reset via PWR_MGMT_1 = 0x81 (DEVICE_RESET + CLKSEL=1)
  if (!writeRegister(IAM20680_REG::PWR_MGMT_1, 0x81)) return false;
  if (!_pollBitUntilCleared(IAM20680_REG::PWR_MGMT_1, 0x80, 200)) return false;

  uint8_t id = whoAmI();
  if (id != 0xFE) return false;
  return true;
}

bool IAM20680HV::beginSPI(uint8_t csPin, SPIClass &spi, SPISettings settings) {
  _spi = &spi;
  _csPin = csPin;
  pinMode(_csPin, OUTPUT);
  digitalWrite(_csPin, HIGH);
  _spiSettings = settings; // allow caller override
  _trans = TRANSPORT_SPI;

  // Wait startup time
  delay(11);

  // Soft reset via SPI
  if (!writeRegister(IAM20680_REG::PWR_MGMT_1, 0x81)) return false;
  if (!_pollBitUntilCleared(IAM20680_REG::PWR_MGMT_1, 0x80, 200)) return false;

  uint8_t id = whoAmI();
  if (id != 0xFE) return false;
  return true;
}

// Low-level bus helpers (private)
// I2C helpers
bool IAM20680HV::_i2cRead(uint8_t reg, uint8_t *buf, size_t len) {
  if (!_wire) return false;
  if (len == 0) return true;
  if (len > 32) return false; // Wire buffer limit
  _wire->beginTransmission(_i2caddr);
  _wire->write(reg);
  uint8_t err = _wire->endTransmission(false); // restart
  if (err != 0) return false;
  uint8_t got = _wire->requestFrom((int)_i2caddr, (int)len, (uint8_t)true);
  if (got != len) return false;
  for (size_t i = 0; i < len; ++i) {
    int v = _wire->read();
    if (v < 0) return false;
    buf[i] = (uint8_t)v;
  }
  return true;
}

bool IAM20680HV::_i2cWrite(uint8_t reg, const uint8_t *buf, size_t len) {
  if (!_wire) return false;
  if (len + 1 > 32) return false;
  _wire->beginTransmission(_i2caddr);
  _wire->write(reg);
  _wire->write(buf, (size_t)len);
  uint8_t err = _wire->endTransmission(true);
  return (err == 0);
}

// SPI helpers: implement datasheet framing
bool IAM20680HV::_spiRead(uint8_t reg, uint8_t *buf, size_t len) {
  if (!_spi || _csPin == 255) return false;
  _spi->beginTransaction(_spiSettings);
  digitalWrite(_csPin, LOW);
  // Per datasheet: first byte MSB = R/W (1=read), next 7 bits register address
  _spi->transfer(reg | 0x80);
  for (size_t i = 0; i < len; ++i) {
    buf[i] = _spi->transfer(0x00);
  }
  // follow CS timing; datasheet indicates very short setup/hold times; include minimal toggling
  digitalWrite(_csPin, HIGH);
  _spi->endTransaction();
  return true;
}

bool IAM20680HV::_spiWrite(uint8_t reg, const uint8_t *buf, size_t len) {
  if (!_spi || _csPin == 255) return false;
  _spi->beginTransaction(_spiSettings);
  digitalWrite(_csPin, LOW);
  // Per datasheet: first byte MSB R/W = 0 for write
  _spi->transfer(reg & 0x7F);
  for (size_t i = 0; i < len; ++i) {
    _spi->transfer(buf[i]);
  }
  digitalWrite(_csPin, HIGH);
  _spi->endTransaction();
  return true;
}

// Register access and rw helpers (public wrappers)
uint8_t IAM20680HV::readRegister(uint8_t reg) {
  uint8_t v = 0xFF;
  if (_trans == TRANSPORT_I2C) {
    if (!_i2cRead(reg, &v, 1)) return 0xFF;
  } else if (_trans == TRANSPORT_SPI) {
    if (!_spiRead(reg, &v, 1)) return 0xFF;
  } else return 0xFF;
  return v;
}

bool IAM20680HV::writeRegister(uint8_t reg, uint8_t value) {
  if (_trans == TRANSPORT_I2C) return _i2cWrite(reg, &value, 1);
  if (_trans == TRANSPORT_SPI) return _spiWrite(reg, &value, 1);
  return false;
}

bool IAM20680HV::readRegisters(uint8_t reg, uint8_t *buf, size_t len) {
  if (_trans == TRANSPORT_I2C) return _i2cRead(reg, buf, len);
  if (_trans == TRANSPORT_SPI) return _spiRead(reg, buf, len);
  return false;
}

bool IAM20680HV::writeRegisters(uint8_t reg, const uint8_t *buf, size_t len) {
  if (_trans == TRANSPORT_I2C) return _i2cWrite(reg, buf, len);
  if (_trans == TRANSPORT_SPI) return _spiWrite(reg, buf, len);
  return false;
}

// Utility poll helper
bool IAM20680HV::_pollBitUntilCleared(uint8_t reg, uint8_t mask, uint32_t timeout_ms) {
  uint32_t start = millis();
  while (millis() - start < timeout_ms) {
    uint8_t v = readRegister(reg);
    if ((v & mask) == 0) return true;
    delay(5);
  }
  return false;
}

// Configuration and control functions
bool IAM20680HV::softReset() {
  if (!writeRegister(IAM20680_REG::PWR_MGMT_1, 0x81)) return false;
  if (!_pollBitUntilCleared(IAM20680_REG::PWR_MGMT_1, 0x80, 200)) return false;
  return (whoAmI() == 0xFE);
}

uint8_t IAM20680HV::whoAmI() {
  return readRegister(IAM20680_REG::WHO_AM_I);
}

bool IAM20680HV::setClockSource(uint8_t clksel) {
  uint8_t v = readRegister(IAM20680_REG::PWR_MGMT_1);
  v = (v & ~0x07) | (clksel & 0x07);
  return writeRegister(IAM20680_REG::PWR_MGMT_1, v);
}

bool IAM20680HV::disableI2CInterface(bool disable) {
  uint8_t v = readRegister(IAM20680_REG::USER_CTRL);
  if (disable) v |= 0x10; else v &= ~0x10;
  return writeRegister(IAM20680_REG::USER_CTRL, v);
}

bool IAM20680HV::setGyroRange(uint8_t fs_sel) {
  fs_sel &= 0x03;
  uint8_t v = readRegister(IAM20680_REG::GYRO_CONFIG);
  v = (v & ~(0x18)) | ((fs_sel & 0x03) << 3);
  bool ok = writeRegister(IAM20680_REG::GYRO_CONFIG, v);
  if (ok) _gyro_fs_sel = fs_sel;
  return ok;
}

uint8_t IAM20680HV::getGyroRange() {
  uint8_t v = readRegister(IAM20680_REG::GYRO_CONFIG);
  return (v >> 3) & 0x03;
}

bool IAM20680HV::setAccelRange(uint8_t fs_sel) {
  fs_sel &= 0x03;
  uint8_t v = readRegister(IAM20680_REG::ACCEL_CONFIG);
  v = (v & ~(0x18)) | ((fs_sel & 0x03) << 3);
  bool ok = writeRegister(IAM20680_REG::ACCEL_CONFIG, v);
  if (ok) _accel_fs_sel = fs_sel;
  return ok;
}

uint8_t IAM20680HV::getAccelRange() {
  uint8_t v = readRegister(IAM20680_REG::ACCEL_CONFIG);
  return (v >> 3) & 0x03;
}

bool IAM20680HV::setSMPLRT_DIV(uint8_t div) { return writeRegister(IAM20680_REG::SMPLRT_DIV, div); }
bool IAM20680HV::setDLPF(uint8_t dlpf_cfg) {
  uint8_t v = readRegister(IAM20680_REG::CONFIG);
  v = (v & ~0x07) | (dlpf_cfg & 0x07);
  return writeRegister(IAM20680_REG::CONFIG, v);
}

// Power-mode helpers
bool IAM20680HV::setSleep(bool enable) {
  uint8_t v = readRegister(IAM20680_REG::PWR_MGMT_1);
  if (enable) v |= (1 << 6); else v &= ~(1 << 6);
  return writeRegister(IAM20680_REG::PWR_MGMT_1, v);
}

bool IAM20680HV::setAccelCycle(bool enable) {
  uint8_t v = readRegister(IAM20680_REG::PWR_MGMT_1);
  if (enable) v |= (1 << 5); else v &= ~(1 << 5);
  return writeRegister(IAM20680_REG::PWR_MGMT_1, v);
}

bool IAM20680HV::setGyroStandbyMask(uint8_t mask) {
  // mask bits correspond to STBY_XG (2), STBY_YG (1), STBY_ZG (0)
  uint8_t v = readRegister(IAM20680_REG::PWR_MGMT_2);
  v = (v & ~0x07) | (mask & 0x07);
  return writeRegister(IAM20680_REG::PWR_MGMT_2, v);
}

bool IAM20680HV::setPowerModeLowNoise(bool enable) {
  // Enter low-noise: clear ACCEL_CYCLE and GYRO_CYCLE and ensure STBY bits cleared
  uint8_t p1 = readRegister(IAM20680_REG::PWR_MGMT_1);
  uint8_t p2 = readRegister(IAM20680_REG::PWR_MGMT_2);
  uint8_t lp = readRegister(IAM20680_REG::LP_MODE_CFG);
  if (enable) {
    p1 &= ~((1 << 5)); // clear ACCEL_CYCLE
    lp &= ~(1 << 7); // clear GYRO_CYCLE (bit7 of LP_MODE_CFG)
    p2 &= ~0x07; // clear STBY_XG..STBY_ZG
  }
  // write back
  bool ok = writeRegister(IAM20680_REG::PWR_MGMT_1, p1);
  ok &= writeRegister(IAM20680_REG::PWR_MGMT_2, p2);
  ok &= writeRegister(IAM20680_REG::LP_MODE_CFG, lp);
  return ok;
}

// Sensor read & conversion functions
bool IAM20680HV::readRawAccel(int16_t &ax, int16_t &ay, int16_t &az) {
  uint8_t buf[6];
  if (!readRegisters(IAM20680_REG::ACCEL_XOUT_H, buf, 6)) return false;
  ax = (int16_t)((buf[0] << 8) | buf[1]);
  ay = (int16_t)((buf[2] << 8) | buf[3]);
  az = (int16_t)((buf[4] << 8) | buf[5]);
  return true;
}

bool IAM20680HV::readRawGyro(int16_t &gx, int16_t &gy, int16_t &gz) {
  uint8_t buf[6];
  if (!readRegisters(IAM20680_REG::GYRO_XOUT_H, buf, 6)) return false;
  gx = (int16_t)((buf[0] << 8) | buf[1]);
  gy = (int16_t)((buf[2] << 8) | buf[3]);
  gz = (int16_t)((buf[4] << 8) | buf[5]);
  return true;
}

bool IAM20680HV::readRawTemp(int16_t &t) {
  uint8_t buf[2];
  if (!readRegisters(IAM20680_REG::TEMP_OUT_H, buf, 2)) return false;
  t = (int16_t)((buf[0] << 8) | buf[1]);
  return true;
}

bool IAM20680HV::readSensor(SensorData &data) {
  uint8_t buf[14];
  if (!readRegisters(IAM20680_REG::ACCEL_XOUT_H, buf, 14)) return false;
  data.ax = (int16_t)((buf[0] << 8) | buf[1]);
  data.ay = (int16_t)((buf[2] << 8) | buf[3]);
  data.az = (int16_t)((buf[4] << 8) | buf[5]);
  data.temp = (int16_t)((buf[6] << 8) | buf[7]);
  data.gx = (int16_t)((buf[8] << 8) | buf[9]);
  data.gy = (int16_t)((buf[10] << 8) | buf[11]);
  data.gz = (int16_t)((buf[12] << 8) | buf[13]);
  return true;
}

float IAM20680HV::convertGyroRawToDPS(int16_t raw) {
  uint8_t fs = _gyro_fs_sel;
  float sens = GYRO_SENS_TABLE[fs];
  return ((float)raw) / sens;
}

float IAM20680HV::convertAccelRawToG(int16_t raw) {
  uint8_t fs = _accel_fs_sel;
  float sens = ACCEL_SENS_TABLE[fs];
  return ((float)raw) / sens;
}

bool IAM20680HV::readTemperatureC(float &celsius) {
  int16_t raw;
  if (!readRawTemp(raw)) return false;
  celsius = ((float)raw - ROOM_TEMP_OFFSET) / TEMP_SENSITIVITY + 25.0f;
  return true;
}

// Interrupt and WoM functions
bool IAM20680HV::configureInterruptPins(uint8_t cfg) { return writeRegister(IAM20680_REG::INT_PIN_CFG, cfg); }
bool IAM20680HV::setInterruptEnable(uint8_t mask) { return writeRegister(IAM20680_REG::INT_ENABLE, mask); }
uint8_t IAM20680HV::readIntStatus() { return readRegister(IAM20680_REG::INT_STATUS); }

bool IAM20680HV::configureWakeOnMotion(uint8_t thr_x, uint8_t thr_y, uint8_t thr_z,
                                       uint8_t accel_intel_ctrl, uint8_t lp_mode_cfg,
                                       bool enter_cycle) {
  if (!writeRegister(IAM20680_REG::ACCEL_WOM_X_THR, thr_x)) return false;
  if (!writeRegister(IAM20680_REG::ACCEL_WOM_Y_THR, thr_y)) return false;
  if (!writeRegister(IAM20680_REG::ACCEL_WOM_Z_THR, thr_z)) return false;
  if (!writeRegister(IAM20680_REG::ACCEL_INTEL_CTRL, accel_intel_ctrl & 0xFE)) return false; // preserve bit0=0
  if (!writeRegister(IAM20680_REG::LP_MODE_CFG, lp_mode_cfg)) return false;
  if (enter_cycle) {
    uint8_t v = readRegister(IAM20680_REG::PWR_MGMT_1);
    v |= (1 << 5); // ACCEL_CYCLE
    if (!writeRegister(IAM20680_REG::PWR_MGMT_1, v)) return false;
  }
  return true;
}

// Offset & signal-path functions
bool IAM20680HV::setGyroOffsets(int16_t x, int16_t y, int16_t z) {
  uint8_t buf[2];
  buf[0] = (uint8_t)((x >> 8) & 0xFF); buf[1] = (uint8_t)(x & 0xFF);
  if (!writeRegisters(IAM20680_REG::XG_OFFS_USRH, buf, 2)) return false;
  buf[0] = (uint8_t)((y >> 8) & 0xFF); buf[1] = (uint8_t)(y & 0xFF);
  if (!writeRegisters(IAM20680_REG::YG_OFFS_USRH, buf, 2)) return false;
  buf[0] = (uint8_t)((z >> 8) & 0xFF); buf[1] = (uint8_t)(z & 0xFF);
  if (!writeRegisters(IAM20680_REG::ZG_OFFS_USRH, buf, 2)) return false;
  return true;
}

bool IAM20680HV::setAccelOffsets(int16_t x, int16_t y, int16_t z) {
  uint8_t low;
  uint8_t buf[2];
  // X
  if (!readRegisters(IAM20680_REG::XA_OFFSET_L, &low, 1)) return false;
  uint8_t preserved_bit = low & 0x01;
  buf[0] = (uint8_t)((x >> 7) & 0xFF);
  buf[1] = (uint8_t)(((x & 0x7F) << 1) & 0xFE);
  buf[1] |= preserved_bit;
  if (!writeRegisters(IAM20680_REG::XA_OFFSET_H, buf, 2)) return false;
  // Y
  if (!readRegisters(IAM20680_REG::YA_OFFSET_L, &low, 1)) return false;
  preserved_bit = low & 0x01;
  buf[0] = (uint8_t)((y >> 7) & 0xFF);
  buf[1] = (uint8_t)(((y & 0x7F) << 1) & 0xFE);
  buf[1] |= preserved_bit;
  if (!writeRegisters(IAM20680_REG::YA_OFFSET_H, buf, 2)) return false;
  // Z
  if (!readRegisters(IAM20680_REG::ZA_OFFSET_L, &low, 1)) return false;
  preserved_bit = low & 0x01;
  buf[0] = (uint8_t)((z >> 7) & 0xFF);
  buf[1] = (uint8_t)(((z & 0x7F) << 1) & 0xFE);
  buf[1] |= preserved_bit;
  if (!writeRegisters(IAM20680_REG::ZA_OFFSET_H, buf, 2)) return false;
  return true;
}

bool IAM20680HV::resetSignalPath(bool resetAccel, bool resetTemp, bool clearAllSensorRegisters) {
  uint8_t v = 0;
  if (resetAccel) v |= (1 << 1);
  if (resetTemp) v |= (1 << 0);
  if (v) {
    if (!writeRegister(IAM20680_REG::SIGNAL_PATH_RESET, v)) return false;
  }
  if (clearAllSensorRegisters) {
    uint8_t u = readRegister(IAM20680_REG::USER_CTRL);
    u |= 0x01; // SIG_COND_RST
    if (!writeRegister(IAM20680_REG::USER_CTRL, u)) return false;
    delay(5);
  }
  return true;
}

// Self-test implementation
void IAM20680HV::setSelfTestOptions(const SelfTestOptions &opts) {
  _selfTestOpts = opts;
}

bool IAM20680HV::selfTest(SelfTestResult &result) {
  // 1) read baseline
  SensorData base;
  if (!readSensor(base)) return false;

  // 2) enable self-test bits for accel and gyro (per-axis)
  uint8_t gconf = readRegister(IAM20680_REG::GYRO_CONFIG);
  uint8_t aconf = readRegister(IAM20680_REG::ACCEL_CONFIG);
  uint8_t gconf_st = gconf | 0xE0; // bits 7,6,5
  uint8_t aconf_st = aconf | 0xE0;
  if (!writeRegister(IAM20680_REG::GYRO_CONFIG, gconf_st)) return false;
  if (!writeRegister(IAM20680_REG::ACCEL_CONFIG, aconf_st)) return false;
  delay(20);

  SensorData st;
  if (!readSensor(st)) {
    // restore
    writeRegister(IAM20680_REG::GYRO_CONFIG, gconf);
    writeRegister(IAM20680_REG::ACCEL_CONFIG, aconf);
    return false;
  }
  // restore
  writeRegister(IAM20680_REG::GYRO_CONFIG, gconf);
  writeRegister(IAM20680_REG::ACCEL_CONFIG, aconf);

  // measured responses
  float meas_ax = (float)(st.ax - base.ax);
  float meas_ay = (float)(st.ay - base.ay);
  float meas_az = (float)(st.az - base.az);
  float meas_gx = (float)(st.gx - base.gx);
  float meas_gy = (float)(st.gy - base.gy);
  float meas_gz = (float)(st.gz - base.gz);

  // read SELF_TEST_* registers
  uint8_t raw_ax = readRegister(IAM20680_REG::SELF_TEST_X_ACCEL);
  uint8_t raw_ay = readRegister(IAM20680_REG::SELF_TEST_Y_ACCEL);
  uint8_t raw_az = readRegister(IAM20680_REG::SELF_TEST_Z_ACCEL);
  uint8_t raw_gx = readRegister(IAM20680_REG::SELF_TEST_X_GYRO);
  uint8_t raw_gy = readRegister(IAM20680_REG::SELF_TEST_Y_GYRO);
  uint8_t raw_gz = readRegister(IAM20680_REG::SELF_TEST_Z_GYRO);

  auto compute_expected = [&](uint8_t rawval, uint8_t fs_sel, bool isAccel) -> float {
    // Interpret rawval according to options
    int st_code = 1;
    if (_selfTestOpts.mode == SelfTestOtpMode::ST_CODE) {
      st_code = (int)rawval;
    } else {
      // rawval is ST_FAC; compute ST_code = round(log(ST_FAC/(2620/2^{FS})) / log(1.01)) + 1
      float denom = 2620.0f / (float)(1 << fs_sel);
      float ratio = (rawval > 0 && denom > 0.0f) ? ((float)rawval / denom) : 1.0f;
      if (ratio <= 0.0f) st_code = 1;
      else {
        float v = logf(ratio) / logf(1.01f);
        st_code = (int)roundf(v) + 1;
        if (st_code < 1) st_code = 1;
      }
    }
    // ST_OTP = (2620 / 2^{FS}) * 1.01^{(ST_code-1)}
    float base = 2620.0f / (float)(1 << fs_sel);
    float powterm = powf(1.01f, (float)(st_code - 1));
    return base * powterm;
  };

  float exp_ax = compute_expected(raw_ax, _accel_fs_sel, true);
  float exp_ay = compute_expected(raw_ay, _accel_fs_sel, true);
  float exp_az = compute_expected(raw_az, _accel_fs_sel, true);
  float exp_gx = compute_expected(raw_gx, _gyro_fs_sel, false);
  float exp_gy = compute_expected(raw_gy, _gyro_fs_sel, false);
  float exp_gz = compute_expected(raw_gz, _gyro_fs_sel, false);

  float tol = _selfTestOpts.tolerance_fraction;
  if (tol < 0.0f) tol = 0.0f;

  result.accelX.measured = meas_ax; result.accelX.expected = exp_ax; result.accelX.pass = (fabs(meas_ax - exp_ax) <= tol * exp_ax);
  result.accelY.measured = meas_ay; result.accelY.expected = exp_ay; result.accelY.pass = (fabs(meas_ay - exp_ay) <= tol * exp_ay);
  result.accelZ.measured = meas_az; result.accelZ.expected = exp_az; result.accelZ.pass = (fabs(meas_az - exp_az) <= tol * exp_az);

  result.gyroX.measured = meas_gx; result.gyroX.expected = exp_gx; result.gyroX.pass = (fabs(meas_gx - exp_gx) <= tol * exp_gx);
  result.gyroY.measured = meas_gy; result.gyroY.expected = exp_gy; result.gyroY.pass = (fabs(meas_gy - exp_gy) <= tol * exp_gy);
  result.gyroZ.measured = meas_gz; result.gyroZ.expected = exp_gz; result.gyroZ.pass = (fabs(meas_gz - exp_gz) <= tol * exp_gz);

  return true;
}

// Utility & error handling done above

