/*
Implementation of public APIs, protocol transactions, calibration decoding, wait logic, and integer compensation.
*/

// Register constants and utility logic: Define documented addresses, masks, reset/ID constants, SPI transaction settings, oversampling multiplier conversion, and timeout calculation.
#include "BME280.h"

// Register addresses
static const uint8_t REG_ID = 0xD0;
static const uint8_t REG_RESET = 0xE0;
static const uint8_t REG_CALIB00 = 0x88; // 0x88..0xA1 (26 bytes)
static const uint8_t REG_CALIB26 = 0xE1; // 0xE1..0xE7 (7 bytes)
static const uint8_t REG_CTRL_HUM = 0xF2;
static const uint8_t REG_STATUS = 0xF3;
static const uint8_t REG_CTRL_MEAS = 0xF4;
static const uint8_t REG_CONFIG = 0xF5;
static const uint8_t REG_PRESS_MSB = 0xF7; // data start (0xF7..0xFE)

static const uint8_t CHIP_ID_EXPECTED = 0x60;
static const uint8_t RESET_CMD = 0xB6;

// Transport constants for SPI
static const uint8_t SPI_READ_MASK = 0x80; // set MSB for read per plan
static const uint8_t SPI_WRITE_MASK = 0x7F; // clear MSB for write

// Utility: oversampling enum to numeric oversampling factor used in timing formula
static uint8_t osrs_to_mul(Oversampling osrs) {
    switch (osrs) {
        case Oversampling::Skipped: return 0;
        case Oversampling::X1: return 1;
        case Oversampling::X2: return 2;
        case Oversampling::X4: return 4;
        case Oversampling::X8: return 8;
        case Oversampling::X16: return 16;
    }
    return 0;
}

// Transport implementation: Implement complete checked I2C and SPI register transactions

// I2C read helper (internal)
static bool i2cRead(TwoWire *wire, uint8_t addr, uint8_t reg, uint8_t *dst, size_t len) {
    // Repeated start register read: write register pointer then request bytes
    wire->beginTransmission(addr);
    wire->write(reg);
    uint8_t err = wire->endTransmission(false); // send restart
    if (err != 0) return false;
    size_t got = wire->requestFrom((int)addr, (int)len, (uint8_t)true);
    if (got != len) return false;
    for (size_t i = 0; i < len; ++i) {
        int v = wire->read();
        if (v < 0) return false;
        dst[i] = (uint8_t)v;
    }
    return true;
}

// I2C single write
static bool i2cWrite(TwoWire *wire, uint8_t addr, uint8_t reg, uint8_t value) {
    wire->beginTransmission(addr);
    wire->write(reg);
    wire->write(value);
    uint8_t err = wire->endTransmission(true);
    return (err == 0);
}

// SPI read: perform transaction with SPIClass instance provided. Uses SPI_MODE0 per plan.
static bool spiRead(SPIClass *spi, uint8_t csPin, uint32_t clockHz, uint8_t reg, uint8_t *dst, size_t len) {
    SPISettings settings(clockHz, MSBFIRST, SPI_MODE0);
    spi->beginTransaction(settings);
    digitalWrite(csPin, LOW);
    // send reg with MSB = 1 per plan
    spi->transfer((uint8_t)(reg | SPI_READ_MASK));
    for (size_t i = 0; i < len; ++i) {
        dst[i] = spi->transfer(0x00);
    }
    digitalWrite(csPin, HIGH);
    spi->endTransaction();
    return true;
}

// SPI write single byte
static bool spiWrite(SPIClass *spi, uint8_t csPin, uint32_t clockHz, uint8_t reg, uint8_t value) {
    SPISettings settings(clockHz, MSBFIRST, SPI_MODE0);
    spi->beginTransaction(settings);
    digitalWrite(csPin, LOW);
    spi->transfer((uint8_t)(reg & SPI_WRITE_MASK));
    spi->transfer(value);
    digitalWrite(csPin, HIGH);
    spi->endTransaction();
    return true;
}

// Implementations
BME280::BME280(TwoWire &wire, uint8_t address) {
    _wire = &wire;
    _useSPI = false;
    _i2cAddress = address;
}

BME280::BME280(SPIClass &spi, uint8_t csPin, uint32_t clockHz) {
    _spi = &spi;
    _useSPI = true;
    _csPin = csPin;
    _spiClockHz = clockHz;
    // configure CS pin (caller is responsible for SPI.begin())
    pinMode(_csPin, OUTPUT);
    digitalWrite(_csPin, HIGH);
}

bool BME280::readRegisters(uint8_t reg, uint8_t *data, size_t length) {
    if (_useSPI) {
        if (!_spi) return false;
        bool ok = spiRead(_spi, _csPin, _spiClockHz, reg, data, length);
        if (!ok) {
            _lastError = Error::Transport;
            return false;
        }
        return true;
    } else {
        if (!_wire) return false;
        bool ok = i2cRead(_wire, _i2cAddress, reg, data, length);
        if (!ok) {
            _lastError = Error::Transport;
            return false;
        }
        return true;
    }
}

bool BME280::writeRegister(uint8_t reg, uint8_t value) {
    if (_useSPI) {
        if (!_spi) return false;
        bool ok = spiWrite(_spi, _csPin, _spiClockHz, reg, value);
        if (!ok) {
            _lastError = Error::Transport;
            return false;
        }
        return true;
    } else {
        if (!_wire) return false;
        bool ok = i2cWrite(_wire, _i2cAddress, reg, value);
        if (!ok) {
            _lastError = Error::Transport;
            return false;
        }
        return true;
    }
}

// Lifecycle and configuration
bool BME280::readChipId(uint8_t &chipId) {
    uint8_t v = 0;
    bool ok = readRegisters(REG_ID, &v, 1);
    if (!ok) return false;
    chipId = v;
    return true;
}

bool BME280::begin() {
    _lastError = Error::Ok;
    uint8_t id = 0;
    if (!readChipId(id)) {
        _lastError = Error::Transport;
        return false;
    }
    if (id != CHIP_ID_EXPECTED) {
        _lastError = Error::ChipIdMismatch;
        return false;
    }
    // perform soft reset and wait for im_update clear
    if (!reset(10)) return false;
    // read calibration blocks
    if (!readCalibration()) {
        _lastError = Error::Calibration;
        return false;
    }
    // Apply a safe default forced-mode profile: osrs_t=1, osrs_p=1, osrs_h=1, filter off
    Configuration def;
    def.osrs_t = Oversampling::X1;
    def.osrs_p = Oversampling::X1;
    def.osrs_h = Oversampling::X1;
    def.filter = Filter::Off;
    def.t_sb = Standby::Ms0_5;
    def.spi3w_en = false;
    if (!configure(def)) return false;
    // enter forced once to prime t_fine and caches (do not surface failure beyond return value)
    Sample s;
    if (!takeForcedMeasurement(s, 0)) {
        // allow initialization even if measurement fails: propagate error
        return false;
    }
    _lastError = Error::Ok;
    return true;
}

bool BME280::reset(uint16_t timeoutMs) {
    _lastError = Error::Ok;
    if (!writeRegister(REG_RESET, RESET_CMD)) {
        _lastError = Error::Transport;
        return false;
    }
    // Poll status.im_update until cleared
    uint32_t start = millis();
    while (true) {
        uint8_t st = 0;
        if (!readRegisters(REG_STATUS, &st, 1)) {
            _lastError = Error::Transport;
            return false;
        }
        if ((st & 0x01) == 0) break; // im_update == 0
        if ((uint32_t)(millis() - start) >= timeoutMs) {
            _lastError = Error::Timeout;
            return false;
        }
        delay(1);
    }
    return true;
}

bool BME280::configure(const Configuration &config) {
    _lastError = Error::Ok;
    // Ensure device in sleep before applying config as requested. If not sleep, set sleep.
    Mode cur;
    if (!readMode(cur)) return false;
    if (cur != Mode::Sleep) {
        if (!setMode(Mode::Sleep)) return false;
        // Wait briefly for transition
        delay(1);
    }
    // Compose config register: t_sb[7:5], filter[4:2], spi3w_en[0]
    uint8_t cfg = 0;
    cfg |= (static_cast<uint8_t>(config.t_sb) & 0x07) << 5;
    cfg |= (static_cast<uint8_t>(config.filter) & 0x07) << 2;
    if (config.spi3w_en) cfg |= 0x01;
    // Compose ctrl_hum: osrs_h in bits [2:0]
    uint8_t ctrl_h = (static_cast<uint8_t>(config.osrs_h) & 0x07);
    // Compose ctrl_meas: osrs_t[7:5], osrs_p[4:2], mode[1:0] leave mode = sleep (00) for now
    uint8_t ctrl_m = ((static_cast<uint8_t>(config.osrs_t) & 0x07) << 5) |
                     ((static_cast<uint8_t>(config.osrs_p) & 0x07) << 2) |
                     (0x00);
    // Write config, ctrl_hum then ctrl_meas only after in sleep
    if (!writeRegister(REG_CONFIG, cfg)) {
        _lastError = Error::Transport;
        return false;
    }
    if (!writeRegister(REG_CTRL_HUM, ctrl_h)) {
        _lastError = Error::Transport;
        return false;
    }
    if (!writeRegister(REG_CTRL_MEAS, ctrl_m)) {
        _lastError = Error::Transport;
        return false;
    }
    // update caches
    _config_cache = cfg;
    _ctrl_hum_cache = ctrl_h;
    _ctrl_meas_cache = ctrl_m;
    return true;
}

bool BME280::setMode(Mode mode) {
    _lastError = Error::Ok;
    // read current ctrl_meas to preserve oversampling fields
    uint8_t cur = 0;
    if (!readRegisters(REG_CTRL_MEAS, &cur, 1)) {
        _lastError = Error::Transport;
        return false;
    }
    uint8_t newv = (cur & 0xFC) | (static_cast<uint8_t>(mode) & 0x03);
    if (!writeRegister(REG_CTRL_MEAS, newv)) {
        _lastError = Error::Transport;
        return false;
    }
    _ctrl_meas_cache = newv;
    return true;
}

bool BME280::readMode(Mode &modeOut) {
    uint8_t v = 0;
    if (!readRegisters(REG_CTRL_MEAS, &v, 1)) return false;
    uint8_t m = v & 0x03;
    modeOut = static_cast<Mode>(m);
    return true;
}

bool BME280::isMeasuring(bool &measuring) {
    uint8_t st = 0;
    if (!readRegisters(REG_STATUS, &st, 1)) return false;
    measuring = ((st >> 3) & 0x01) != 0;
    return true;
}

bool BME280::isUpdating(bool &updating) {
    uint8_t st = 0;
    if (!readRegisters(REG_STATUS, &st, 1)) return false;
    updating = (st & 0x01) != 0;
    return true;
}

// Calibration, acquisition, and compensation
bool BME280::readCalibration() {
    _lastError = Error::Ok;
    uint8_t buf1[26];
    if (!readRegisters(REG_CALIB00, buf1, sizeof(buf1))) {
        _lastError = Error::Transport;
        return false;
    }
    uint8_t buf2[7];
    if (!readRegisters(REG_CALIB26, buf2, sizeof(buf2))) {
        _lastError = Error::Transport;
        return false;
    }
    // parse per register map and retrieval
    dig_T1 = (uint16_t)((uint16_t)buf1[1] << 8 | buf1[0]);
    dig_T2 = (int16_t)((uint16_t)buf1[3] << 8 | buf1[2]);
    dig_T3 = (int16_t)((uint16_t)buf1[5] << 8 | buf1[4]);

    dig_P1 = (uint16_t)((uint16_t)buf1[7] << 8 | buf1[6]);
    dig_P2 = (int16_t)((uint16_t)buf1[9] << 8 | buf1[8]);
    dig_P3 = (int16_t)((uint16_t)buf1[11] << 8 | buf1[10]);
    dig_P4 = (int16_t)((uint16_t)buf1[13] << 8 | buf1[12]);
    dig_P5 = (int16_t)((uint16_t)buf1[15] << 8 | buf1[14]);
    dig_P6 = (int16_t)((uint16_t)buf1[17] << 8 | buf1[16]);
    dig_P7 = (int16_t)((uint16_t)buf1[19] << 8 | buf1[18]);
    dig_P8 = (int16_t)((uint16_t)buf1[21] << 8 | buf1[20]);
    dig_P9 = (int16_t)((uint16_t)buf1[23] << 8 | buf1[22]);
    dig_H1 = buf1[25];

    dig_H2 = (int16_t)((uint16_t)buf2[1] << 8 | buf2[0]);
    dig_H3 = buf2[2];
    // dig_H4 is 12-bit: msb = buf2[3], lsb = lower nibble of buf2[4]
    dig_H4 = (int16_t)((int16_t)((int8_t)buf2[3]) << 4) | (int16_t)(buf2[4] & 0x0F);
    // dig_H5 is 12-bit: msb = upper nibble of buf2[4] (bits 7:4), lsb = buf2[5]
    dig_H5 = (int16_t)((int16_t)((int8_t)buf2[5]) << 4) | (int16_t)((buf2[4] >> 4) & 0x0F);
    dig_H6 = (int8_t)buf2[6];

    // sign-extend H4/H5 if needed: they are signed 12-bit. Above operations already sign-extend via shifts involving signed types.
    _haveCalibration = true;
    return true;
}

bool BME280::readRaw(RawData &raw) {
    _lastError = Error::Ok;
    uint8_t buf[8];
    if (!readRegisters(REG_PRESS_MSB, buf, sizeof(buf))) {
        _lastError = Error::Transport;
        return false;
    }
    // parse: pressure 20-bit: buf[0]<<12 | buf[1]<<4 | buf[2]>>4
    raw.pressure = ((uint32_t)buf[0] << 12) | ((uint32_t)buf[1] << 4) | ((uint32_t)buf[2] >> 4);
    raw.temperature = ((uint32_t)buf[3] << 12) | ((uint32_t)buf[4] << 4) | ((uint32_t)buf[5] >> 4);
    raw.humidity = ((uint16_t)buf[6] << 8) | buf[7];
    return true;
}

bool BME280::waitForMeasurement(uint16_t timeoutMs) {
    _lastError = Error::Ok;
    uint32_t start = millis();
    while (true) {
        bool measuring = false;
        if (!isMeasuring(measuring)) return false; // isMeasuring sets lastError on failure
        if (!measuring) return true;
        if ((uint32_t)(millis() - start) >= timeoutMs) {
            _lastError = Error::Timeout;
            return false;
        }
        delay(1);
    }
}

bool BME280::takeForcedMeasurement(Sample &sample, uint16_t timeoutMs) {
    _lastError = Error::Ok;
    // Compose ctrl_meas value by preserving osrs_t and osrs_p and setting mode to forced (01)
    uint8_t cur = 0;
    if (!readRegisters(REG_CTRL_MEAS, &cur, 1)) {
        _lastError = Error::Transport;
        return false;
    }
    // set mode bits to forced (use encoding 01)
    uint8_t modeBits = 0x01;
    uint8_t newv = (cur & 0xFC) | (modeBits & 0x03);
    if (!writeRegister(REG_CTRL_MEAS, newv)) {
        _lastError = Error::Transport;
        return false;
    }
    _ctrl_meas_cache = newv;
    // compute conservative timeout if requested (zero selects computed)
    if (timeoutMs == 0) {
        // compute t_measure_max per retrieval: t_measure_max = 1.25 + [2.3*T_oversampling]_{osrs_t != 0} + [2.3*P_oversampling + 0.575]_{osrs_p != 0} + [2.3*H_oversampling + 0.575]_{osrs_h != 0}
        // extract oversampling settings from ctrl_meas and ctrl_hum
        uint8_t ctrl_meas_val = newv;
        uint8_t osrs_t_bits = (ctrl_meas_val >> 5) & 0x07;
        uint8_t osrs_p_bits = (ctrl_meas_val >> 2) & 0x07;
        uint8_t osrs_h_bits = 0;
        if (!readRegisters(REG_CTRL_HUM, &osrs_h_bits, 1)) return false;
        osrs_h_bits &= 0x07;
        uint8_t t_oversamp = (osrs_t_bits == 0 ? 0 : (osrs_t_bits <=5 ? (uint8_t)(1 << (osrs_t_bits - 1)) : 16));
        // but simpler: map encodings to multiplicative count via osrs_to_mul
        Oversampling ost = static_cast<Oversampling>(osrs_t_bits);
        Oversampling osp = static_cast<Oversampling>(osrs_p_bits);
        Oversampling osh = static_cast<Oversampling>(osrs_h_bits);
        float t = 1.25f;
        uint8_t mulT = osrs_to_mul(ost);
        uint8_t mulP = osrs_to_mul(osp);
        uint8_t mulH = osrs_to_mul(osh);
        if (mulT != 0) t += 2.3f * (float)mulT;
        if (mulP != 0) t += 2.3f * (float)mulP + 0.575f;
        if (mulH != 0) t += 2.3f * (float)mulH + 0.575f;
        // add margin: 2x
        uint16_t computed = (uint16_t)ceil(t * 2.0f);
        timeoutMs = (computed < 1 ? 1 : computed) + 5; // small headroom
    }
    // wait for measuring to clear
    if (!waitForMeasurement(timeoutMs)) return false;
    // read raw data and compensate
    RawData raw;
    if (!readRaw(raw)) return false;
    // validate sentinel values per plan
    if (raw.temperature == 0x80000u || raw.pressure == 0x80000u || raw.humidity == 0x8000u) {
        _lastError = Error::SkippedData;
        return false;
    }
    // perform compensation
    if (!readCalibration() && !_haveCalibration) {
        _lastError = Error::Calibration;
        return false;
    }
    int32_t t_fine = 0;
    int32_t temp_x100 = compensateTemperatureInt32(raw.temperature, t_fine);
    uint32_t press_pa = compensatePressureInt32(raw.pressure, t_fine);
    uint32_t hum_q22_10 = compensateHumidityInt32(raw.humidity, t_fine);
    sample.temperature_c = temp_x100 / 100.0f;
    sample.pressure_pa = (float)press_pa;
    // humidity returned as Q22.10 -> convert to percent
    sample.humidity_rh = (float)hum_q22_10 / 1024.0f;
    // clamp humidity
    if (sample.humidity_rh < 0.0f) sample.humidity_rh = 0.0f;
    if (sample.humidity_rh > 100.0f) sample.humidity_rh = 100.0f;
    _lastError = Error::Ok;
    return true;
}

bool BME280::readSample(Sample &sample) {
    _lastError = Error::Ok;
    if (!_haveCalibration) {
        if (!readCalibration()) {
            _lastError = Error::Calibration;
            return false;
        }
    }
    RawData raw;
    if (!readRaw(raw)) return false;
    if (raw.temperature == 0x80000u || raw.pressure == 0x80000u || raw.humidity == 0x8000u) {
        _lastError = Error::SkippedData;
        return false;
    }
    int32_t t_fine = 0;
    int32_t temp_x100 = compensateTemperatureInt32(raw.temperature, t_fine);
    uint32_t press_pa = compensatePressureInt32(raw.pressure, t_fine);
    uint32_t hum_q22_10 = compensateHumidityInt32(raw.humidity, t_fine);
    sample.temperature_c = temp_x100 / 100.0f;
    sample.pressure_pa = (float)press_pa;
    sample.humidity_rh = (float)hum_q22_10 / 1024.0f;
    if (sample.humidity_rh < 0.0f) sample.humidity_rh = 0.0f;
    if (sample.humidity_rh > 100.0f) sample.humidity_rh = 100.0f;
    return true;
}

// Compensation implementations following Bosch integer formulas retrieved
int32_t BME280::compensateTemperatureInt32(uint32_t adc_T, int32_t &t_fine_out) {
    // from datasheet integer implementation
    int32_t var1, var2, T;
    int32_t adc_T_s = (int32_t)adc_T;
    var1 = ((((adc_T_s >> 3) - ((int32_t)dig_T1 << 1))) * ((int32_t)dig_T2)) >> 11;
    var2 = (((((adc_T_s >> 4) - ((int32_t)dig_T1)) * ((adc_T_s >> 4) - ((int32_t)dig_T1))) >> 12) * ((int32_t)dig_T3)) >> 14;
    int32_t t_fine = var1 + var2;
    T = (t_fine * 5 + 128) >> 8; // temperature in 0.01 deg C
    t_fine_out = t_fine;
    return T;
}

uint32_t BME280::compensatePressureInt32(uint32_t adc_P, int32_t t_fine) {
    // use 64-bit intermediate as recommended
    int64_t var1, var2, p;
    var1 = ((int64_t)t_fine) - 128000;
    var2 = var1 * var1 * (int64_t)dig_P6;
    var2 = var2 + ((var1 * (int64_t)dig_P5) << 17);
    var2 = var2 + (((int64_t)dig_P4) << 35);
    var1 = ((var1 * var1 * (int64_t)dig_P3) >> 8) + ((var1 * (int64_t)dig_P2) << 12);
    var1 = (((((int64_t)1) << 47) + var1) * ((int64_t)dig_P1)) >> 33;
    if (var1 == 0) {
        return 0; // avoid div by zero
    }
    p = 1048576 - (int64_t)adc_P;
    p = (((p << 31) - var2) * 3125) / var1;
    var1 = (((int64_t)dig_P9) * (p >> 13) * (p >> 13)) >> 25;
    var2 = (((int64_t)dig_P8) * p) >> 19;
    p = ((p + var1 + var2) >> 8) + (((int64_t)dig_P7) << 4);
    if (p < 0) p = 0;
    return (uint32_t)p; // returned value is in Pa (Q24.8 in some implementations); this matches datasheet int64 variant
}

uint32_t BME280::compensateHumidityInt32(uint16_t adc_H, int32_t t_fine) {
    int32_t v_x1_u32r;
    int32_t adc_H_s = (int32_t)adc_H;
    v_x1_u32r = (t_fine - ((int32_t)76800));
    v_x1_u32r = (((((adc_H_s << 14) - ((int32_t)dig_H4 << 20) - ((int32_t)dig_H5 * v_x1_u32r)) + ((int32_t)16384)) >> 15)
                 * (((((((v_x1_u32r * (int32_t)dig_H6) >> 10) * (((v_x1_u32r * (int32_t)dig_H3) >> 11) + ((int32_t)32768))) >> 10)
                 + ((int32_t)2097152)) * (int32_t)dig_H2 + 8192) >> 14));
    v_x1_u32r = v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * (int32_t)dig_H1) >> 4);
    if (v_x1_u32r < 0) v_x1_u32r = 0;
    if (v_x1_u32r > 419430400) v_x1_u32r = 419430400;
    // return in Q22.10 format (value/1024 => %RH)
    return (uint32_t)(v_x1_u32r >> 12);
}


