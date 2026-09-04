/*
Implementation of the BME280 class, low-level bus code for I2C/SPI, calibration parsing, burst read, compensation algorithms and self-test logic.
*/

// Includes and static consts: Include header, Wire.h, SPI.h and define register address constants, timeouts and sentinel constants.
#include "BME280.h"

// Register addresses (from register_maps)
static const uint8_t REG_ID = 0xD0;
static const uint8_t REG_RESET = 0xE0;
static const uint8_t REG_STATUS = 0xF3;
static const uint8_t REG_CTRL_HUM = 0xF2;
static const uint8_t REG_CTRL_MEAS = 0xF4;
static const uint8_t REG_CONFIG = 0xF5;
static const uint8_t REG_PRESS_MSB = 0xF7; // burst start

// calibration blocks
static const uint8_t CALIB_88_START = 0x88;
static const size_t CALIB_88_LEN = 26; // 0x88..0xA1 inclusive => 26 bytes
static const uint8_t CALIB_E1_START = 0xE1;
static const size_t CALIB_E1_LEN = 7;  // 0xE1..0xE7 => 7 bytes

// sentinel values
static const uint32_t SENTINEL_20BIT = 0x80000u;
static const uint16_t SENTINEL_16BIT = 0x8000u;

// Constructor and begin implementations: Implement constructor and beginI2C/beginSPI verifying chip id and reading calibration.
BME280::BME280()
: _transport(TRANSPORT_NONE), _wire(nullptr), _i2c_addr(0), _spi(nullptr), _cs_pin(255), _has_spi_settings(false), _temp_x100(0), _press_Pa(0), _hum_percent(0.0f), _t_fine(0)
{
  _raw.press_raw = 0;
  _raw.temp_raw = 0;
  _raw.hum_raw = 0;
  _raw.pressure_skipped = false;
  _raw.temperature_skipped = false;
  _raw.humidity_skipped = false;
  memset(&_calib, 0, sizeof(_calib));
}

bool BME280::beginI2C(uint8_t address, TwoWire* wire) {
  _transport = TRANSPORT_I2C;
  _wire = wire;
  _i2c_addr = address & 0x7F;

  // Verify chip id
  uint8_t id = readChipId();
  if (id != 0x60) return false;

  // After POR im_update may be set; wait until cleared
  uint32_t start = millis();
  while (isImUpdate()) {
    if ((millis() - start) > IM_UPDATE_TIMEOUT_MS) return false;
    delay(1);
  }

  if (!readCalibration()) return false;
  return true;
}

// Legacy beginSPI without SPISettings: driver will operate but will NOT call beginTransaction.
bool BME280::beginSPI(uint8_t cs_pin, SPIClass* spi) {
  // Do NOT construct or assign SPISettings here. Caller must configure SPI bus if not using the
  // beginSPI overload that supplies SPISettings. Mark that we do not have SPISettings.
  _has_spi_settings = false;

  _transport = TRANSPORT_SPI;
  _spi = spi;
  _cs_pin = cs_pin;
  pinMode(_cs_pin, OUTPUT);
  digitalWrite(_cs_pin, HIGH);

  uint8_t id = readChipId();
  if (id != 0x60) return false;

  uint32_t start = millis();
  while (isImUpdate()) {
    if ((millis() - start) > IM_UPDATE_TIMEOUT_MS) return false;
    delay(1);
  }

  if (!readCalibration()) return false;
  return true;
}

// Preferred beginSPI: store SPISettings provided by caller and enable beginTransaction usage.
bool BME280::beginSPI(uint8_t cs_pin, SPIClass* spi, const SPISettings& settings) {
  _has_spi_settings = true;
  _spi_settings = settings;
  _transport = TRANSPORT_SPI;
  _spi = spi;
  _cs_pin = cs_pin;
  pinMode(_cs_pin, OUTPUT);
  digitalWrite(_cs_pin, HIGH);

  uint8_t id = readChipId();
  if (id != 0x60) return false;

  uint32_t start = millis();
  while (isImUpdate()) {
    if ((millis() - start) > IM_UPDATE_TIMEOUT_MS) return false;
    delay(1);
  }

  if (!readCalibration()) return false;
  return true;
}

// Low-level I2C helpers (unchanged)
static bool i2cWriteBytesInternal(TwoWire* wire, uint8_t addr, uint8_t reg, const uint8_t* buffer, size_t length) {
  wire->beginTransmission(addr);
  wire->write(reg);
  wire->write(buffer, (size_t)length);
  uint8_t res = wire->endTransmission();
  return (res == 0);
}

static bool i2cReadBytesInternal(TwoWire* wire, uint8_t addr, uint8_t start_reg, uint8_t* buffer, size_t length) {
  wire->beginTransmission(addr);
  wire->write(start_reg);
  uint8_t res = wire->endTransmission(false); // restart
  if (res != 0) return false;
  size_t got = wire->requestFrom((int)addr, (int)length);
  if (got != length) return false;
  for (size_t i = 0; i < length; ++i) {
    int v = wire->read();
    if (v < 0) return false;
    buffer[i] = (uint8_t)v;
  }
  return true;
}

// SPI helper members: use stored settings only when _has_spi_settings is true.
bool BME280::spiWriteBytesInternal(uint8_t reg, const uint8_t* buffer, size_t length) {
  if (!_spi) return false;
  uint8_t ctrl = (reg & 0x7F); // RW=0
  if (_has_spi_settings) {
    _spi->beginTransaction(_spi_settings);
    digitalWrite(_cs_pin, LOW);
    _spi->transfer(ctrl);
    for (size_t i = 0; i < length; ++i) _spi->transfer(buffer[i]);
    digitalWrite(_cs_pin, HIGH);
    _spi->endTransaction();
  } else {
    // caller configured SPI; do direct transfers without beginTransaction
    digitalWrite(_cs_pin, LOW);
    _spi->transfer(ctrl);
    for (size_t i = 0; i < length; ++i) _spi->transfer(buffer[i]);
    digitalWrite(_cs_pin, HIGH);
  }
  return true;
}

bool BME280::spiReadBytesInternal(uint8_t start_reg, uint8_t* buffer, size_t length) {
  if (!_spi) return false;
  uint8_t ctrl = (start_reg & 0x7F) | 0x80; // set RW=1 for read
  if (_has_spi_settings) {
    _spi->beginTransaction(_spi_settings);
    digitalWrite(_cs_pin, LOW);
    _spi->transfer(ctrl);
    for (size_t i = 0; i < length; ++i) buffer[i] = _spi->transfer((uint8_t)0x00);
    digitalWrite(_cs_pin, HIGH);
    _spi->endTransaction();
  } else {
    digitalWrite(_cs_pin, LOW);
    _spi->transfer(ctrl);
    for (size_t i = 0; i < length; ++i) buffer[i] = _spi->transfer((uint8_t)0x00);
    digitalWrite(_cs_pin, HIGH);
  }
  return true;
}

// Generic bus wrappers that choose I2C or SPI
bool BME280::writeRegister(uint8_t reg, uint8_t value) {
  if (_transport == TRANSPORT_I2C) {
    return i2cWriteBytesInternal(_wire, _i2c_addr, reg, &value, 1);
  } else if (_transport == TRANSPORT_SPI) {
    return spiWriteBytesInternal(reg, &value, 1);
  }
  return false;
}

bool BME280::readRegister(uint8_t reg, uint8_t &value) {
  uint8_t buf = 0;
  bool ok = false;
  if (_transport == TRANSPORT_I2C) {
    ok = i2cReadBytesInternal(_wire, _i2c_addr, reg, &buf, 1);
  } else if (_transport == TRANSPORT_SPI) {
    ok = spiReadBytesInternal(reg, &buf, 1);
  }
  if (ok) value = buf;
  return ok;
}

bool BME280::burstRead(uint8_t start_reg, uint8_t* buffer, size_t length) {
  if (_transport == TRANSPORT_I2C) {
    return i2cReadBytesInternal(_wire, _i2c_addr, start_reg, buffer, length);
  } else if (_transport == TRANSPORT_SPI) {
    return spiReadBytesInternal(start_reg, buffer, length);
  }
  return false;
}

// Calibration parsing and storage: Read calibration block and parse dig_T*, dig_P*, dig_H*
bool BME280::readCalibration() {
  uint8_t raw1[CALIB_88_LEN];
  uint8_t raw2[CALIB_E1_LEN];
  if (!burstRead(CALIB_88_START, raw1, CALIB_88_LEN)) return false;
  if (!burstRead(CALIB_E1_START, raw2, CALIB_E1_LEN)) return false;

  // parse per register_map
  _calib.dig_T1 = (uint16_t)((raw1[1] << 8) | raw1[0]);
  _calib.dig_T2 = (int16_t)((raw1[3] << 8) | raw1[2]);
  _calib.dig_T3 = (int16_t)((raw1[5] << 8) | raw1[4]);

  _calib.dig_P1 = (uint16_t)((raw1[7] << 8) | raw1[6]);
  _calib.dig_P2 = (int16_t)((raw1[9] << 8) | raw1[8]);
  _calib.dig_P3 = (int16_t)((raw1[11] << 8) | raw1[10]);
  _calib.dig_P4 = (int16_t)((raw1[13] << 8) | raw1[12]);
  _calib.dig_P5 = (int16_t)((raw1[15] << 8) | raw1[14]);
  _calib.dig_P6 = (int16_t)((raw1[17] << 8) | raw1[16]);
  _calib.dig_P7 = (int16_t)((raw1[19] << 8) | raw1[18]);
  _calib.dig_P8 = (int16_t)((raw1[21] << 8) | raw1[20]);
  _calib.dig_P9 = (int16_t)((raw1[23] << 8) | raw1[22]);

  _calib.dig_H1 = raw1[25]; // 0xA1

  _calib.dig_H2 = (int16_t)((raw2[1] << 8) | raw2[0]);
  _calib.dig_H3 = raw2[2];

  // dig_H4: bits [11:4] from 0xE4, bits [3:0] from 0xE5[3:0]
  int16_t h4 = (int16_t)((int16_t)raw2[3] << 4) | (int16_t)(raw2[4] & 0x0F);
  // sign extend 12-bit
  if (h4 & 0x800) h4 |= 0xF000;
  _calib.dig_H4 = h4;

  // dig_H5: bits [3:0] in 0xE5[7:4], bits [11:4] in 0xE6
  int16_t h5 = (int16_t)((int16_t)raw2[5] << 4) | (int16_t)((raw2[4] >> 4) & 0x0F);
  if (h5 & 0x800) h5 |= 0xF000;
  _calib.dig_H5 = h5;

  _calib.dig_H6 = (int8_t)raw2[6];

  return true;
}

// Compensation algorithms
int32_t BME280::compensateTemperature(uint32_t adc_T) {
  // Return temperature in 0.01 degC (int32)
  int32_t var1, var2;
  int32_t adc = (int32_t)adc_T;
  var1 = ((((adc >> 3) - ((int32_t)_calib.dig_T1 << 1))) * ((int32_t)_calib.dig_T2)) >> 11;
  var2 = (((((adc >> 4) - ((int32_t)_calib.dig_T1)) * ((adc >> 4) - ((int32_t)_calib.dig_T1))) >> 12) * ((int32_t)_calib.dig_T3)) >> 14;
  _t_fine = var1 + var2;
  int32_t T = (_t_fine * 5 + 128) >> 8; // T in 0.01 degC
  _temp_x100 = T;
  return T;
}

uint32_t BME280::compensatePressure(uint32_t adc_P) {
  // Uses 64-bit intermediate values. Returns pressure in Pa, 0 on error (division by zero)
  int64_t var1, var2, p;
  var1 = (int64_t)_t_fine - 128000;
  var2 = var1 * var1 * (int64_t)_calib.dig_P6;
  var2 = var2 + ((var1 * (int64_t)_calib.dig_P5) << 17);
  var2 = var2 + (((int64_t)_calib.dig_P4) << 35);
  var1 = ((var1 * var1 * (int64_t)_calib.dig_P3) >> 8) + ((var1 * (int64_t)_calib.dig_P2) << 12);
  var1 = (((((int64_t)1) << 47) + var1) * ((int64_t)_calib.dig_P1)) >> 33;
  if (var1 == 0) return 0; // avoid division by zero
  p = 1048576 - (int64_t)adc_P;
  p = (((p << 31) - var2) * 3125) / var1;
  var1 = (((int64_t)_calib.dig_P9) * (p >> 13) * (p >> 13)) >> 25;
  var2 = (((int64_t)_calib.dig_P8) * p) >> 19;
  p = ((p + var1 + var2) >> 8) + (((int64_t)_calib.dig_P7) << 4);
  uint32_t pres = (uint32_t)(p >> 8);
  _press_Pa = pres;
  return pres;
}

float BME280::compensateHumidity(uint16_t adc_H) {
  int32_t v_x1_u32r;
  int32_t adc = (int32_t)adc_H;
  v_x1_u32r = _t_fine - ((int32_t)76800);
  v_x1_u32r = (((((adc << 14) - (((int32_t)_calib.dig_H4) << 20) - (((int32_t)_calib.dig_H5) * v_x1_u32r)) + ((int32_t)16384)) >> 15) * (((((((v_x1_u32r * ((int32_t)_calib.dig_H6)) >> 10) * (((v_x1_u32r * ((int32_t)_calib.dig_H3)) >> 11) + ((int32_t)32768))) >> 10) + ((int32_t)2097152)) * ((int32_t)_calib.dig_H2) + 8192) >> 14));
  v_x1_u32r = v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * ((int32_t)_calib.dig_H1)) >> 4);
  v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
  v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);
  int32_t h = (v_x1_u32r >> 12); // Q22.10
  float hf = (float)h / 1024.0f;
  if (hf > 100.0f) hf = 100.0f;
  if (hf < 0.0f) hf = 0.0f;
  _hum_percent = hf;
  return hf;
}

// Burst read and value extraction: Implement readSensor() that calls burstRead for 8 bytes and extracts press/temp/hum raw integers
bool BME280::readSensor() {
  uint8_t buf[8];
  if (!burstRead(REG_PRESS_MSB, buf, 8)) return false;

  // press: buf[0..2]
  uint32_t press_raw = ((uint32_t)buf[0] << 12) | ((uint32_t)buf[1] << 4) | ((uint32_t)(buf[2] >> 4));
  uint32_t temp_raw  = ((uint32_t)buf[3] << 12) | ((uint32_t)buf[4] << 4) | ((uint32_t)(buf[5] >> 4));
  uint16_t hum_raw   = ((uint16_t)buf[6] << 8) | (uint16_t)buf[7];

  _raw.press_raw = press_raw;
  _raw.temp_raw = temp_raw;
  _raw.hum_raw = hum_raw;

  _raw.pressure_skipped = (press_raw == SENTINEL_20BIT);
  _raw.temperature_skipped = (temp_raw == SENTINEL_20BIT);
  _raw.humidity_skipped = (hum_raw == SENTINEL_16BIT);

  // Update compensated cached values only when raw not skipped and calibration present
  if (!_raw.temperature_skipped) compensateTemperature(_raw.temp_raw);
  if (!_raw.pressure_skipped) compensatePressure(_raw.press_raw);
  if (!_raw.humidity_skipped) compensateHumidity(_raw.hum_raw);

  return true;
}

BME280Driver::RawData BME280::getRawData() const {
  return _raw;
}

float BME280::getTemperature() const {
  return ((float)_temp_x100) / 100.0f;
}

float BME280::getPressure() const {
  return (float)_press_Pa;
}

float BME280::getHumidity() const {
  return _hum_percent;
}

// Status helpers
bool BME280::isMeasuring() {
  uint8_t s = 0;
  if (!readRegister(REG_STATUS, s)) return false; // assume not measuring on comm error
  return (s & (1 << 3)) != 0;
}

bool BME280::isImUpdate() {
  uint8_t s = 0;
  if (!readRegister(REG_STATUS, s)) return false; // on error, return false
  return (s & 0x01) != 0;
}

// Control writes: enforce ctrl_hum write semantics (changes take effect only after ctrl_meas write). Before changing mode or ctrl_meas check measuring
bool BME280::setHumidityOversampling(uint8_t osrs_h) {
  osrs_h &= 0x07;
  // write ctrl_hum
  uint8_t val = osrs_h & 0x07;
  return writeRegister(REG_CTRL_HUM, val);
}

bool BME280::setTempPressureOversamplingAndMode(uint8_t osrs_t, uint8_t osrs_p, uint8_t mode) {
  osrs_t &= 0x07; osrs_p &= 0x07; mode &= 0x03;
  // Wait for measuring to finish before writing
  uint32_t start = millis();
  while (isMeasuring()) {
    if ((millis() - start) > MEASUREMENT_TIMEOUT_MS) return false;
    delay(1);
  }
  uint8_t val = (uint8_t)((osrs_t << 5) | (osrs_p << 2) | (mode & 0x03));
  return writeRegister(REG_CTRL_MEAS, val);
}

bool BME280::setFilterAndStandby(uint8_t t_sb, uint8_t filter, bool spi3w_en) {
  t_sb &= 0x07; filter &= 0x07;
  uint8_t val = (uint8_t)((t_sb << 5) | (filter << 2) | (spi3w_en ? 0x01 : 0x00));
  return writeRegister(REG_CONFIG, val);
}

// softReset implementation
bool BME280::softReset() {
  if (!writeRegister(REG_RESET, 0xB6)) return false;
  delay(RESET_DELAY_MS);
  uint32_t start = millis();
  while (isImUpdate()) {
    if ((millis() - start) > IM_UPDATE_TIMEOUT_MS) return false;
    delay(1);
  }
  return true;
}

uint8_t BME280::readChipId() {
  uint8_t v = 0;
  if (!readRegister(REG_ID, v)) return 0x00;
  return v;
}

// Self-test implementation: extend to include bond-wire clipping checks per datasheet. Return codes in ascending order.
int BME280::performSelfTest() {
  // Soft reset
  if (!softReset()) return 10;
  // Read chip id
  uint8_t id = readChipId();
  if (id != 0x60) return 10;
  // Read calibration
  if (!readCalibration()) return 20;
  // Basic plausibility: dig_T1 must be non-zero
  if (_calib.dig_T1 == 0) return 20;

  // Trigger a forced measurement with modest oversampling
  if (!setHumidityOversampling(BME280Driver::OSRS_X1)) return 10;
  if (!setTempPressureOversamplingAndMode(BME280Driver::OSRS_X1, BME280Driver::OSRS_X1, BME280Driver::MODE_FORCED)) return 10;

  // Wait for measurement to complete (use conservative timeout)
  uint32_t start = millis();
  while (isMeasuring()) {
    if ((millis() - start) > MEASUREMENT_TIMEOUT_MS) return 10;
    delay(1);
  }

  // Read sensor burst
  if (!readSensor()) return 10;

  // Bond-wire test: check uncompensated raw ADC clipping for temperature and pressure
  // As documented, clipping to min (0) or max (0xFFFFF for 20-bit) indicates bond-wire or MEMS defect.
  const uint32_t MAX_20BIT = 0xFFFFFu; // full-scale for 20-bit ADC
  if (_raw.temp_raw == 0u || _raw.temp_raw == MAX_20BIT) {
    return 30; // temperature bond-wire / MEMS defect
  }
  if (_raw.press_raw == 0u || _raw.press_raw == MAX_20BIT) {
    return 31; // pressure bond-wire / MEMS defect
  }

  // If any measurement skipped (oversampling set to 0), return implausible codes as earlier
  if (_raw.temperature_skipped) return 40;
  if (_raw.pressure_skipped) return 41;
  if (_raw.humidity_skipped) return 42;

  // Compute compensated values already computed in readSensor(); validate ranges
  float T = getTemperature();
  float P = getPressure();
  float H = getHumidity();

  // Plausibility ranges: defaults can be tuned per production; use conservative limits here
  // Following retrieved datasheet defaults in 10.2/10.4: default temperature limits 0..40 C and pressure 900..1100 hPa
  if (T < -40.0f || T > 85.0f) return 40; // wide allowed range, but still detect gross failure
  if (P < 90000.0f || P > 110000.0f) return 41; // 900..1100 hPa -> 90000..110000 Pa
  if (H < 0.0f || H > 100.0f) return 42;

  return 0; // OK
}

