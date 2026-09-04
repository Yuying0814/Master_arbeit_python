/*
BME280 I2C/SPI transactions, configuration, acquisition, diagnostics, and compensation. Calibration decoding hardened and bounds-checked.
*/

// Transport implementation: Implement I2C repeated-start reads and SPI beginTransaction/chip-select transactions; SPI reads set control-byte bit 7 and writes clear it, with the 7-bit register address.

#include "BME280.h"

// Constructors
BME280::BME280(TwoWire &wire, uint8_t address)
{
    m_if = InterfaceType::I2C;
    m_wire = &wire;
    m_i2cAddress = address;
}

BME280::BME280(SPIClass &spi, uint8_t csPin, SPISettings settings)
{
    m_if = InterfaceType::SPI;
    m_spi = &spi;
    m_csPin = csPin;
    m_spiSettings = settings;
    pinMode(m_csPin, OUTPUT);
    digitalWrite(m_csPin, HIGH);
}

// Low-level readRegisters
bool BME280::readRegisters(uint8_t reg, uint8_t *buffer, size_t length)
{
    if (!buffer || length == 0) {
        m_lastError = Error::InvalidArgument;
        return false;
    }

    if (m_if == InterfaceType::I2C) {
        // I2C repeated start read
        m_wire->beginTransmission(m_i2cAddress);
        m_wire->write(reg);
        uint8_t txerr = m_wire->endTransmission(false); // restart
        if (txerr != 0) {
            m_lastError = Error::CommError;
            return false;
        }
        size_t got = m_wire->requestFrom((int)m_i2cAddress, (int)length, (uint8_t)true);
        if (got != length) {
            // try to drain what is available but treat as error
            for (size_t i = 0; i < got; ++i) buffer[i] = (uint8_t)m_wire->read();
            m_lastError = Error::CommError;
            return false;
        }
        for (size_t i = 0; i < length; ++i) {
            int v = m_wire->read();
            buffer[i] = (uint8_t)(v & 0xFF);
        }
        return true;
    } else {
        // SPI: set MSB to 1 for read
        m_spi->beginTransaction(m_spiSettings);
        digitalWrite(m_csPin, LOW);
        uint8_t address = reg | 0x80;
        m_spi->transfer(address);
        for (size_t i = 0; i < length; ++i) {
            buffer[i] = m_spi->transfer(0x00);
        }
        digitalWrite(m_csPin, HIGH);
        m_spi->endTransaction();
        return true;
    }
}

// Low-level single register writer
bool BME280::writeRegister(uint8_t reg, uint8_t value)
{
    if (m_if == InterfaceType::I2C) {
        m_wire->beginTransmission(m_i2cAddress);
        m_wire->write(reg);
        m_wire->write(value);
        uint8_t txerr = m_wire->endTransmission(true);
        if (txerr != 0) {
            m_lastError = Error::CommError;
            return false;
        }
        return true;
    } else {
        m_spi->beginTransaction(m_spiSettings);
        digitalWrite(m_csPin, LOW);
        uint8_t address = reg & 0x7F; // write = MSB 0
        m_spi->transfer(address);
        m_spi->transfer(value);
        digitalWrite(m_csPin, HIGH);
        m_spi->endTransaction();
        return true;
    }
}

// Device control and decoding: register read/write wrappers
bool BME280::registerRead(uint8_t reg, uint8_t &value)
{
    uint8_t buf;
    bool ok = readRegisters(reg, &buf, 1);
    if (!ok) return false;
    value = buf;
    return true;
}

bool BME280::registerReadBurst(uint8_t reg, uint8_t *buf, size_t len)
{
    return readRegisters(reg, buf, len);
}

bool BME280::registerWrite(uint8_t reg, uint8_t value)
{
    return writeRegister(reg, value);
}

// readChipId
bool BME280::readChipId(uint8_t &chipId)
{
    uint8_t v;
    if (!registerRead(REG_ID, v)) {
        m_lastError = Error::CommError;
        return false;
    }
    chipId = v;
    return true;
}

bool BME280::isConnected()
{
    uint8_t id;
    if (!readChipId(id)) return false;
    return id == 0x60;
}

// softReset
bool BME280::softReset(uint32_t timeoutMs)
{
    if (!registerWrite(REG_RESET, 0xB6)) {
        m_lastError = Error::CommError;
        return false;
    }
    delay(2); // mandatory 2 ms reset delay
    // wait for im_update to clear
    uint32_t start = millis();
    while (true) {
        bool upd;
        if (!isUpdating(upd)) {
            m_lastError = Error::CommError;
            return false;
        }
        if (!upd) break;
        if ((millis() - start) > timeoutMs) {
            m_lastError = Error::Timeout;
            return false;
        }
        delay(1);
    }
    // reload calibration
    if (!readCalibration()) {
        // m_lastError set by readCalibration
        return false;
    }
    m_lastError = Error::Ok;
    return true;
}

// readCalibration: read 0x88..0xA1 and 0xE1..0xE7
bool BME280::readCalibration()
{
    // Named register range constants for clarity
    constexpr uint8_t CALIB1_START = 0x88;
    constexpr uint8_t CALIB1_END   = 0xA1;
    constexpr size_t  CALIB1_LEN   = (size_t)(CALIB1_END - CALIB1_START + 1); // 26

    constexpr uint8_t CALIB2_START = 0xE1;
    constexpr uint8_t CALIB2_END   = 0xE7;
    constexpr size_t  CALIB2_LEN   = (size_t)(CALIB2_END - CALIB2_START + 1); // 7

    uint8_t buf1[CALIB1_LEN]; // holds 0x88..0xA1
    if (!registerReadBurst(REG_CALIB_88, buf1, sizeof(buf1))) {
        m_lastError = Error::CommError;
        m_calib.valid = false;
        return false;
    }
    uint8_t buf2[CALIB2_LEN]; // holds 0xE1..0xE7
    if (!registerReadBurst(REG_CALIB_E1, buf2, sizeof(buf2))) {
        m_lastError = Error::CommError;
        m_calib.valid = false;
        return false;
    }

    // Offsets inside buf1 relative to 0x88
    constexpr size_t OFF_dig_T1 = 0x88 - CALIB1_START; // 0
    constexpr size_t OFF_dig_T2 = 0x8A - CALIB1_START; // 2
    constexpr size_t OFF_dig_T3 = 0x8C - CALIB1_START; // 4
    constexpr size_t OFF_dig_P1 = 0x8E - CALIB1_START; // 6
    constexpr size_t OFF_dig_P2 = 0x90 - CALIB1_START; // 8
    constexpr size_t OFF_dig_P3 = 0x92 - CALIB1_START; // 10
    constexpr size_t OFF_dig_P4 = 0x94 - CALIB1_START; // 12
    constexpr size_t OFF_dig_P5 = 0x96 - CALIB1_START; // 14
    constexpr size_t OFF_dig_P6 = 0x98 - CALIB1_START; // 16
    constexpr size_t OFF_dig_P7 = 0x9A - CALIB1_START; // 18
    constexpr size_t OFF_dig_P8 = 0x9C - CALIB1_START; // 20
    constexpr size_t OFF_dig_P9 = 0x9E - CALIB1_START; // 22
    constexpr size_t OFF_dig_H1 = 0xA1 - CALIB1_START; // 25

    // Offsets inside buf2 relative to 0xE1
    constexpr size_t OFF_dig_H2 = 0xE1 - CALIB2_START; // 0
    constexpr size_t OFF_dig_H3 = 0xE3 - CALIB2_START; // 2
    constexpr size_t OFF_dig_H4_msb = 0xE4 - CALIB2_START; // 3
    constexpr size_t OFF_dig_H5_msb = 0xE6 - CALIB2_START; // 5
    constexpr size_t OFF_dig_H5_lsb_nibble = 0xE5 - CALIB2_START; // 4
    constexpr size_t OFF_dig_H4_lsb_nibble = 0xE5 - CALIB2_START; // 4
    constexpr size_t OFF_dig_H6 = 0xE7 - CALIB2_START; // 6

    // Basic bounds checking to avoid out-of-range buffer accesses
    if (OFF_dig_H1 >= sizeof(buf1) || OFF_dig_P9 + 1 >= sizeof(buf1)) {
        m_calib.valid = false;
        m_lastError = Error::CalibrationMissing;
        return false;
    }
    if (OFF_dig_H6 >= sizeof(buf2) || OFF_dig_H4_msb + 1 >= sizeof(buf2)) {
        m_calib.valid = false;
        m_lastError = Error::CalibrationMissing;
        return false;
    }

    // decode per register map (little endian) using computed offsets
    m_calib.dig_T1 = (uint16_t)buf1[OFF_dig_T1] | ((uint16_t)buf1[OFF_dig_T1 + 1] << 8);
    m_calib.dig_T2 = (int16_t)((uint16_t)buf1[OFF_dig_T2] | ((uint16_t)buf1[OFF_dig_T2 + 1] << 8));
    m_calib.dig_T3 = (int16_t)((uint16_t)buf1[OFF_dig_T3] | ((uint16_t)buf1[OFF_dig_T3 + 1] << 8));

    m_calib.dig_P1 = (uint16_t)buf1[OFF_dig_P1] | ((uint16_t)buf1[OFF_dig_P1 + 1] << 8);
    m_calib.dig_P2 = (int16_t)((uint16_t)buf1[OFF_dig_P2] | ((uint16_t)buf1[OFF_dig_P2 + 1] << 8));
    m_calib.dig_P3 = (int16_t)((uint16_t)buf1[OFF_dig_P3] | ((uint16_t)buf1[OFF_dig_P3 + 1] << 8));
    m_calib.dig_P4 = (int16_t)((uint16_t)buf1[OFF_dig_P4] | ((uint16_t)buf1[OFF_dig_P4 + 1] << 8));
    m_calib.dig_P5 = (int16_t)((uint16_t)buf1[OFF_dig_P5] | ((uint16_t)buf1[OFF_dig_P5 + 1] << 8));
    m_calib.dig_P6 = (int16_t)((uint16_t)buf1[OFF_dig_P6] | ((uint16_t)buf1[OFF_dig_P6 + 1] << 8));
    m_calib.dig_P7 = (int16_t)((uint16_t)buf1[OFF_dig_P7] | ((uint16_t)buf1[OFF_dig_P7 + 1] << 8));
    m_calib.dig_P8 = (int16_t)((uint16_t)buf1[OFF_dig_P8] | ((uint16_t)buf1[OFF_dig_P8 + 1] << 8));
    m_calib.dig_P9 = (int16_t)((uint16_t)buf1[OFF_dig_P9] | ((uint16_t)buf1[OFF_dig_P9 + 1] << 8));

    // dig_H1 from 0xA1 (use computed offset)
    m_calib.dig_H1 = buf1[OFF_dig_H1];

    // buf2 decoding
    m_calib.dig_H2 = (int16_t)((uint16_t)buf2[OFF_dig_H2] | ((uint16_t)buf2[OFF_dig_H2 + 1] << 8));
    m_calib.dig_H3 = buf2[OFF_dig_H3];

    // dig_H4: 12-bit signed across E4 (MSB) and E5[3:0]
    int16_t h4 = (int16_t)(((int16_t)buf2[OFF_dig_H4_msb] << 4) | (int16_t)(buf2[OFF_dig_H4_lsb_nibble] & 0x0F));
    if (h4 & 0x800) h4 |= 0xF000; // sign extend 12-bit
    m_calib.dig_H4 = h4;

    // dig_H5: 12-bit signed across E5[7:4] and E6
    int16_t h5 = (int16_t)(((int16_t)buf2[OFF_dig_H5_msb] << 4) | (int16_t)((buf2[OFF_dig_H5_lsb_nibble] >> 4) & 0x0F));
    if (h5 & 0x800) h5 |= 0xF000; // sign extend 12-bit
    m_calib.dig_H5 = h5;

    m_calib.dig_H6 = (int8_t)buf2[OFF_dig_H6];

    // Basic validation: dig_P1 must not be zero (would invalidate pressure compensation)
    if (m_calib.dig_P1 == 0) {
        m_calib.valid = false;
        m_lastError = Error::CalibrationMissing;
        return false;
    }

    m_calib.valid = true;
    m_lastError = Error::Ok;
    return true;
}

// Status and configuration API: isMeasuring/isUpdating
bool BME280::isMeasuring(bool &measuring)
{
    uint8_t st;
    if (!registerRead(REG_STATUS, st)) return false;
    measuring = (st & (1 << 3)) != 0;
    return true;
}

bool BME280::isUpdating(bool &updating)
{
    uint8_t st;
    if (!registerRead(REG_STATUS, st)) return false;
    updating = (st & (1 << 0)) != 0;
    return true;
}

bool BME280::waitForMeasurement(uint32_t timeoutMs)
{
    uint32_t start = millis();
    while (true) {
        bool meas;
        if (!isMeasuring(meas)) {
            m_lastError = Error::CommError;
            return false;
        }
        if (!meas) { m_lastError = Error::Ok; return true; }
        if ((millis() - start) > timeoutMs) {
            m_lastError = Error::Timeout;
            return false;
        }
        delay(1);
    }
}

// Helper to map Oversampling enum to numeric factor used in timing
static uint32_t oversampleFactor(BME280::Oversampling o)
{
    switch (o) {
        case BME280::Oversampling::Skipped: return 0;
        case BME280::Oversampling::X1: return 1;
        case BME280::Oversampling::X2: return 2;
        case BME280::Oversampling::X4: return 4;
        case BME280::Oversampling::X8: return 8;
        case BME280::Oversampling::X16: return 16;
        default: return 16;
    }
}

// measurementTimeMaxMs
float BME280::measurementTimeMaxMs(Oversampling humidity, Oversampling temperature, Oversampling pressure)
{
    double t = 1.25; // base
    uint32_t t_ov = oversampleFactor(temperature);
    uint32_t p_ov = oversampleFactor(pressure);
    uint32_t h_ov = oversampleFactor(humidity);
    if (t_ov != 0) t += 2.3 * (double)t_ov;
    if (p_ov != 0) t += 2.3 * (double)p_ov + 0.575;
    if (h_ov != 0) t += 2.3 * (double)h_ov + 0.575;
    return (float)t;
}

// configure: must write ctrl_hum before ctrl_meas; enter sleep before config writes and restore requested mode afterward
bool BME280::configure(Oversampling humidity, Oversampling temperature, Oversampling pressure, StandbyTime standby, Filter filter, Mode mode, bool enable3WireSpi)
{
    // Read current ctrl_meas
    uint8_t cur_ctrl = 0;
    if (!registerRead(REG_CTRL_MEAS, cur_ctrl)) { m_lastError = Error::CommError; return false; }

    // Save original mode to restore if necessary
    uint8_t orig_mode = cur_ctrl & 0x03;

    // Ensure device in sleep for config writes
    if (!setMode(Mode::Sleep)) return false;

    // Write ctrl_hum (0xF2)
    uint8_t ctrl_hum = static_cast<uint8_t>(humidity) & 0x07;
    if (!registerWrite(REG_CTRL_HUM, ctrl_hum)) { m_lastError = Error::CommError; return false; }

    // Update config (preserve reserved bit1)
    uint8_t cfg = 0;
    if (!registerRead(REG_CONFIG, cfg)) { m_lastError = Error::CommError; return false; }
    // t_sb bits [7:5]
    cfg &= ~(0xE0);
    cfg |= (static_cast<uint8_t>(standby) & 0x07) << 5;
    // filter bits [4:2]
    cfg &= ~(0x1C);
    uint8_t filterBits = 0;
    switch (filter) {
        case Filter::Off: filterBits = 0; break;
        case Filter::C2: filterBits = 1; break;
        case Filter::C4: filterBits = 2; break;
        case Filter::C8: filterBits = 3; break;
        case Filter::C16: filterBits = 4; break;
        default: filterBits = 0; break;
    }
    cfg |= (filterBits & 0x07) << 2;
    // spi3w_en bit[0]
    cfg &= ~(0x01);
    if (enable3WireSpi) cfg |= 0x01;

    if (!registerWrite(REG_CONFIG, cfg)) { m_lastError = Error::CommError; return false; }

    // Now write ctrl_meas with temperature and pressure oversampling and requested mode
    uint8_t new_ctrl = 0;
    uint8_t ot = static_cast<uint8_t>(temperature) & 0x07;
    uint8_t op = static_cast<uint8_t>(pressure) & 0x07;
    new_ctrl = (ot << 5) | (op << 2) | (static_cast<uint8_t>(mode) & 0x03);

    if (!registerWrite(REG_CTRL_MEAS, new_ctrl)) { m_lastError = Error::CommError; return false; }

    m_lastError = Error::Ok;
    return true;
}

// setMode: write only mode bits while preserving osrs_t and osrs_p
bool BME280::setMode(Mode mode)
{
    uint8_t cur;
    if (!registerRead(REG_CTRL_MEAS, cur)) { m_lastError = Error::CommError; return false; }
    uint8_t newv = (cur & 0xFC) | (static_cast<uint8_t>(mode) & 0x03);
    if (!registerWrite(REG_CTRL_MEAS, newv)) { m_lastError = Error::CommError; return false; }
    m_lastError = Error::Ok;
    return true;
}

bool BME280::getMode(Mode &mode)
{
    uint8_t cur;
    if (!registerRead(REG_CTRL_MEAS, cur)) { m_lastError = Error::CommError; return false; }
    uint8_t m = cur & 0x03;
    if (m == 0) mode = Mode::Sleep;
    else if (m == 3) mode = Mode::Normal;
    else mode = Mode::Forced; // treat 01 and 10 as Forced
    return true;
}

// Acquisition and diagnostic API: takeForcedMeasurement
bool BME280::takeForcedMeasurement(uint32_t timeoutMs)
{
    // read current oversampling settings to compute timeout if needed
    uint8_t ctrl;
    if (!registerRead(REG_CTRL_MEAS, ctrl)) { m_lastError = Error::CommError; return false; }
    BME280::Oversampling osrs_t = static_cast<BME280::Oversampling>((ctrl >> 5) & 0x07);
    BME280::Oversampling osrs_p = static_cast<BME280::Oversampling>((ctrl >> 2) & 0x07);
    uint8_t ctrl_h = 0;
    if (!registerRead(REG_CTRL_HUM, ctrl_h)) return false;
    BME280::Oversampling osrs_h = static_cast<BME280::Oversampling>(ctrl_h & 0x07);

    if (timeoutMs == 0) {
        float tm = measurementTimeMaxMs(osrs_h, osrs_t, osrs_p);
        // margin factor
        timeoutMs = (uint32_t)(tm * 1.25f) + 2;
    }

    // trigger forced by setting mode bits to forced
    if (!setMode(Mode::Forced)) return false;

    // wait until measuring bit clears
    bool ok = waitForMeasurement(timeoutMs);
    return ok;
}

// readRaw: burst read 0xF7..0xFE exactly one burst (8 bytes)
bool BME280::readRaw(RawSample &raw)
{
    uint8_t buf[8];
    if (!registerReadBurst(REG_DATA, buf, sizeof(buf))) {
        m_lastError = Error::CommError;
        return false;
    }
    // assemble pressure 20-bit: buf[0]=press_msb, [1]=press_lsb, [2]=press_xlsb (bits 7:4)
    uint32_t up = ((uint32_t)buf[0] << 12) | ((uint32_t)buf[1] << 4) | ((uint32_t)(buf[2] >> 4) & 0x0F);
    uint32_t ut = ((uint32_t)buf[3] << 12) | ((uint32_t)buf[4] << 4) | ((uint32_t)(buf[5] >> 4) & 0x0F);
    uint16_t uh = ((uint16_t)buf[6] << 8) | (uint16_t)buf[7];

    raw.pressure = up;
    raw.temperature = ut;
    raw.humidity = uh;
    m_lastError = Error::Ok;
    return true;
}

// Compensation internals: temperature (returns temperature in 0.01 degC as int32)
int32_t BME280::compensateTemperatureInt32(int32_t adc_T)
{
    // Follow Bosch integer algorithm
    int32_t var1 = (((adc_T >> 3) - ((int32_t)m_calib.dig_T1 << 1)) * (int32_t)m_calib.dig_T2) >> 11;
    int32_t var2 = (((((adc_T >> 4) - (int32_t)m_calib.dig_T1) * ((adc_T >> 4) - (int32_t)m_calib.dig_T1)) >> 12) * (int32_t)m_calib.dig_T3) >> 14;
    m_tFine = var1 + var2;
    int32_t T = (m_tFine * 5 + 128) >> 8; // temperature in 0.01 degC
    return T;
}

// Compensation pressure: returns Q24.8 format (i.e., p * 256)
uint32_t BME280::compensatePressureInt64(int32_t adc_P)
{
    int64_t var1, var2, p;
    var1 = ((int64_t)m_tFine) - 128000;
    var2 = var1 * var1 * (int64_t)m_calib.dig_P6;
    var2 = var2 + ((var1 * (int64_t)m_calib.dig_P5) << 17);
    var2 = var2 + (((int64_t)m_calib.dig_P4) << 35);
    var1 = ((var1 * var1 * (int64_t)m_calib.dig_P3) >> 8) + ((var1 * (int64_t)m_calib.dig_P2) << 12);
    var1 = (((((int64_t)1) << 47) + var1) * ((int64_t)m_calib.dig_P1)) >> 33;
    if (var1 == 0) {
        return 0; // avoid division by zero
    }
    p = 1048576 - (int64_t)adc_P;
    p = (((p << 31) - var2) * 3125) / var1;
    var1 = (((int64_t)m_calib.dig_P9) * (p >> 13) * (p >> 13)) >> 25;
    var2 = (((int64_t)m_calib.dig_P8) * p) >> 19;
    p = ((p + var1 + var2) >> 8) + (((int64_t)m_calib.dig_P7) << 4);
    return (uint32_t)p; // Q24.8
}

// Compensation humidity: returns Q22.10 (i.e., value * 1024)
uint32_t BME280::compensateHumidityInt32(int32_t adc_H)
{
    int32_t v_x1_u32r;
    v_x1_u32r = (m_tFine - ((int32_t)76800));
    int32_t var1 = (((adc_H << 14) - ((int32_t)m_calib.dig_H4 << 20) - ((int32_t)m_calib.dig_H5 * v_x1_u32r)) + 16384) >> 15;
    int32_t var2 = (((((v_x1_u32r * (int32_t)m_calib.dig_H6) >> 10) * (((v_x1_u32r * (int32_t)m_calib.dig_H3) >> 11) + 32768)) >> 10) + 2097152) * (int32_t)m_calib.dig_H2 + 8192;
    var2 = (var2 >> 14);
    v_x1_u32r = var1 * var2;
    v_x1_u32r = v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * (int32_t)m_calib.dig_H1) >> 4);
    if (v_x1_u32r < 0) v_x1_u32r = 0;
    if (v_x1_u32r > 419430400) v_x1_u32r = 419430400;
    return (uint32_t)(v_x1_u32r >> 12); // Q22.10
}

// readMeasurements: burst read and compensate one synchronized sample
bool BME280::readMeasurements(Measurement &sample)
{
    if (!m_calib.valid) {
        m_lastError = Error::CalibrationMissing;
        return false;
    }
    RawSample r;
    if (!readRaw(r)) return false;

    int32_t t_raw = (int32_t)r.temperature;
    int32_t p_raw = (int32_t)r.pressure;
    int32_t h_raw = (int32_t)r.humidity;

    int32_t t = compensateTemperatureInt32(t_raw); // 0.01 degC
    uint32_t p_q24_8 = compensatePressureInt64(p_raw);
    uint32_t h_q22_10 = compensateHumidityInt32(h_raw);

    sample.temperature_C = ((float)t) / 100.0f;
    // Convert Q24.8 to Pa by dividing by 256
    sample.pressure_Pa = ((float)p_q24_8) / 256.0f;
    // Convert Q22.10 to percent by dividing by 1024
    float hum = ((float)h_q22_10) / 1024.0f;
    if (hum < 0.0f) hum = 0.0f;
    if (hum > 100.0f) hum = 100.0f;
    sample.humidity_pc = hum;

    m_lastError = Error::Ok;
    return true;
}

// Diagnostics and errors: selfTest per plan
BME280::SelfTestResult BME280::selfTest(const SelfTestLimits &limits)
{
    // 1) soft reset
    if (!softReset(100)) return SelfTestResult::ResetFailed;

    // 2) check id
    uint8_t id;
    if (!readChipId(id)) return SelfTestResult::CommError;
    if (id != 0x60) return SelfTestResult::BadId;

    // 3) calibration availability
    if (!m_calib.valid) return SelfTestResult::CalibrationMissing;

    // 4) perform forced measurement
    if (!takeForcedMeasurement(0)) return SelfTestResult::CommError;

    // 5) read raw and check clipping
    RawSample raw;
    if (!readRaw(raw)) return SelfTestResult::CommError;
    // clipping check: if raw equals min or max ADC ranges -> clipped
    if (raw.pressure == 0x00000 || raw.pressure == 0xFFFFF) return SelfTestResult::ClippedRaw;
    if (raw.temperature == 0x00000 || raw.temperature == 0xFFFFF) return SelfTestResult::ClippedRaw;
    if (raw.humidity == 0x0000 || raw.humidity == 0xFFFF) return SelfTestResult::ClippedRaw;

    // 6) compensate and check plausibility
    Measurement meas;
    if (!readMeasurements(meas)) return SelfTestResult::CommError;
    if (meas.temperature_C < limits.minTempC || meas.temperature_C > limits.maxTempC) return SelfTestResult::ImplausibleMeasurement;
    if (meas.pressure_Pa < limits.minPressurePa || meas.pressure_Pa > limits.maxPressurePa) return SelfTestResult::ImplausibleMeasurement;
    if (meas.humidity_pc < limits.minHumidityPc || meas.humidity_pc > limits.maxHumidityPc) return SelfTestResult::ImplausibleMeasurement;

    return SelfTestResult::Passed;
}

// begin: Validate chip ID, wait for NVM copy completion, read calibration, and leave device in default sleep
bool BME280::begin(uint32_t timeoutMs)
{
    uint8_t id;
    if (!readChipId(id)) { m_lastError = Error::CommError; return false; }
    if (id != 0x60) { m_lastError = Error::BadId; return false; }

    // wait for im_update clear
    uint32_t start = millis();
    while (true) {
        bool upd;
        if (!isUpdating(upd)) { m_lastError = Error::CommError; return false; }
        if (!upd) break;
        if ((millis() - start) > timeoutMs) { m_lastError = Error::Timeout; return false; }
        delay(1);
    }

    if (!readCalibration()) { return false; }

    // Ensure device in sleep mode
    if (!setMode(Mode::Sleep)) { /* non-fatal? but follow plan */ return false; }

    m_lastError = Error::Ok;
    return true;
}


