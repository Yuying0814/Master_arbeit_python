/*
Implementation of the BME280 driver using Arduino Wire. Implements I2C helpers, calibration reading, raw data assembly, configuration and conversion functions using official formulas.
*/

// includes_and_private_structs: includes and internal state
#include "bme280.h"
#include <Wire.h>
#include <math.h>

// constructor
BME280::BME280()
: _address(BME280_I2C_ADDR_0), _wire(&Wire), _t_fine(0)
{
    memset(&_lastRaw, 0, sizeof(_lastRaw));
    memset(&calibration, 0, sizeof(calibration));
}

// i2c_helpers: low-level read/write helpers

bool BME280::begin(uint8_t address, TwoWire &wirePort)
{
    _address = address;
    _wire = &wirePort;

    // quick ack check
    _wire->begin();
    if (!isConnected()) return false;

    // read chip id to confirm
    int id = readRegister8(BME280_REG_ID);
    if (id < 0) return false;
    if ((uint8_t)id != 0x60) {
        // Unexpected ID but still attempt to read calibration; return false to indicate mismatch
        // still attempt calibration read to populate values if possible
    }

    // read calibration block
    if (!readCalibration()) return false;

    return true;
}

bool BME280::isConnected()
{
    _wire->beginTransmission(_address);
    uint8_t res = _wire->endTransmission();
    return (res == 0);
}

int BME280::readRegister8(uint8_t reg)
{
    // Write register address
    _wire->beginTransmission(_address);
    _wire->write(reg);
    uint8_t et = _wire->endTransmission(false); // repeated start
    if (et != 0) {
        return -((int)et);
    }

    // request one byte
    uint8_t got = _wire->requestFrom((int)_address, (int)1);
    if (got < 1) return -2;
    int val = _wire->read();
    return val;
}

bool BME280::writeRegister8(uint8_t reg, uint8_t value)
{
    _wire->beginTransmission(_address);
    _wire->write(reg);
    _wire->write(value);
    uint8_t res = _wire->endTransmission();
    return (res == 0);
}

int BME280::readRegister16LE(uint8_t lsb_reg)
{
    // read two bytes starting at lsb_reg (LSB then MSB) and combine
    uint8_t buf[2];
    int n = readBytes(lsb_reg, buf, 2);
    if (n != 2) return -1;
    uint16_t value = (uint16_t)buf[0] | ((uint16_t)buf[1] << 8);
    return (int)value;
}

int BME280::readBytes(uint8_t start_reg, uint8_t *buf, size_t len)
{
    if (len == 0) return 0;
    // send start register
    _wire->beginTransmission(_address);
    _wire->write(start_reg);
    uint8_t et = _wire->endTransmission(false); // repeated start
    if (et != 0) return -((int)et);

    size_t got = _wire->requestFrom((int)_address, (int)len);
    if (got != len) return -3;
    for (size_t i = 0; i < len; ++i) {
        buf[i] = (uint8_t)_wire->read();
    }
    return (int)got;
}

// calibration_parsing: read calibration registers and store raw results

bool BME280::readCalibration()
{
    // Read block 0x88..0xA1 (26 bytes) and 0xE1..0xE7 (7 bytes)
    uint8_t buf1[26];
    int r1 = readBytes(0x88, buf1, sizeof(buf1));
    if (r1 != (int)sizeof(buf1)) return false;

    uint8_t buf2[7];
    int r2 = readBytes(0xE1, buf2, sizeof(buf2));
    if (r2 != (int)sizeof(buf2)) return false;

    // parse temperature
    calibration.dig_T1 = (uint16_t)buf1[0] | ((uint16_t)buf1[1] << 8);
    calibration.dig_T2 = (int16_t) ( (uint16_t)buf1[2] | ((uint16_t)buf1[3] << 8) );
    calibration.dig_T3 = (int16_t) ( (uint16_t)buf1[4] | ((uint16_t)buf1[5] << 8) );

    // parse pressure
    calibration.dig_P1 = (uint16_t)buf1[6] | ((uint16_t)buf1[7] << 8);
    calibration.dig_P2 = (int16_t) ( (uint16_t)buf1[8] | ((uint16_t)buf1[9] << 8) );
    calibration.dig_P3 = (int16_t) ( (uint16_t)buf1[10] | ((uint16_t)buf1[11] << 8) );
    calibration.dig_P4 = (int16_t) ( (uint16_t)buf1[12] | ((uint16_t)buf1[13] << 8) );
    calibration.dig_P5 = (int16_t) ( (uint16_t)buf1[14] | ((uint16_t)buf1[15] << 8) );
    calibration.dig_P6 = (int16_t) ( (uint16_t)buf1[16] | ((uint16_t)buf1[17] << 8) );
    calibration.dig_P7 = (int16_t) ( (uint16_t)buf1[18] | ((uint16_t)buf1[19] << 8) );
    calibration.dig_P8 = (int16_t) ( (uint16_t)buf1[20] | ((uint16_t)buf1[21] << 8) );
    calibration.dig_P9 = (int16_t) ( (uint16_t)buf1[22] | ((uint16_t)buf1[23] << 8) );

    // dig_H1 at 0xA1 (buf1[25])
    calibration.dig_H1 = buf1[25];

    // humidity block buf2: E1..E7
    calibration.dig_H2 = (int16_t)((uint16_t)buf2[0] | ((uint16_t)buf2[1] << 8));
    calibration.dig_H3 = buf2[2];

    // dig_H4 and dig_H5 are stored across E4/E5/E6
    // dig_H4: bits [11:4] @ 0xE4, bits [3:0] @ 0xE5[3:0]
    // dig_H5: bits [3:0] @ 0xE5[7:4], bits [11:4] @ 0xE6
    int16_t h4 = (int16_t)((int16_t)buf2[3] << 4) | (int16_t)(buf2[4] & 0x0F);
    int16_t h5 = (int16_t)((int16_t)buf2[5] << 4) | (int16_t)((buf2[4] >> 4) & 0x0F);

    // sign extend 12-bit values to int16_t if needed
    if (h4 & 0x0800) h4 |= 0xF000;
    if (h5 & 0x0800) h5 |= 0xF000;

    calibration.dig_H4 = h4;
    calibration.dig_H5 = h5;

    calibration.dig_H6 = (int8_t)buf2[6];

    return true;
}

// raw_data_assembly: read measurement registers and assemble raw values

bool BME280::readRawData(uint32_t &rawP, uint32_t &rawT, uint32_t &rawH)
{
    // read contiguous registers from 0xF7..0xFE (8 bytes)
    uint8_t data[8];
    int rc = readBytes(BME280_REG_PRESS_MSB, data, 8);
    if (rc != 8) return false;

    uint32_t p_msb = data[0];
    uint32_t p_lsb = data[1];
    uint32_t p_xlsb = data[2];

    uint32_t t_msb = data[3];
    uint32_t t_lsb = data[4];
    uint32_t t_xlsb = data[5];

    uint32_t h_msb = data[6];
    uint32_t h_lsb = data[7];

    rawP = (p_msb << 12) | (p_lsb << 4) | (p_xlsb >> 4);
    rawT = (t_msb << 12) | (t_lsb << 4) | (t_xlsb >> 4);
    rawH = (h_msb << 8) | h_lsb;

    // store last raw
    _lastRaw.press = rawP;
    _lastRaw.temp  = rawT;
    _lastRaw.hum   = rawH;

    return true;
}

// conversion_functions: implement compensation using official formulas from retrieval_results

float BME280::readTemperature()
{
    uint32_t rawP, rawT, rawH;
    if (!readRawData(rawP, rawT, rawH)) return NAN;

    // apply double precision formula (from datasheet) for temperature
    double adc_T = (double)rawT;
    double var1 = (adc_T / 16384.0 - (double)calibration.dig_T1 / 1024.0) * (double)calibration.dig_T2;
    double var2 = (adc_T / 131072.0 - (double)calibration.dig_T1 / 8192.0);
    var2 = var2 * var2 * (double)calibration.dig_T3;
    double t_fine_d = var1 + var2;
    _t_fine = (int32_t) t_fine_d;
    double T = (t_fine_d) / 5120.0; // degrees C (double)
    return (float)T;
}

float BME280::readPressure()
{
    // Ensure temperature compensation computed
    // Use last raw readings if available, otherwise read new raw data
    uint32_t rawP = _lastRaw.press;
    uint32_t rawT = _lastRaw.temp;
    uint32_t rawH = _lastRaw.hum;
    if (rawT == 0 || _t_fine == 0) {
        // compute temperature first to set _t_fine
        if (isnan(readTemperature())) return NAN;
        rawP = _lastRaw.press;
        rawT = _lastRaw.temp;
    }

    double adc_P = (double)rawP;

    // double precision implementation from datasheet
    double var1 = ((double)_t_fine / 2.0) - 64000.0;
    double var2 = var1 * var1 * ((double)calibration.dig_P6) / 32768.0;
    var2 = var2 + var1 * ((double)calibration.dig_P5) * 2.0;
    var2 = (var2 / 4.0) + ((double)calibration.dig_P4) * 65536.0;
    var1 = (((double)calibration.dig_P3) * var1 * var1 / 524288.0 + ((double)calibration.dig_P2) * var1) / 524288.0;
    var1 = (1.0 + var1 / 32768.0) * ((double)calibration.dig_P1);
    if (var1 == 0.0) {
        return NAN; // avoid division by zero
    }
    double p = 1048576.0 - adc_P;
    p = (p - (var2 / 4096.0)) * 6250.0 / var1;
    var1 = ((double)calibration.dig_P9) * p * p / 2147483648.0;
    var2 = p * ((double)calibration.dig_P8) / 32768.0;
    p = p + (var1 + var2 + (double)calibration.dig_P7) / 16.0;

    return (float)p; // pressure in Pa (double -> float)
}

float BME280::readHumidity()
{
    // Ensure temperature compensation available
    if (_t_fine == 0) {
        if (isnan(readTemperature())) return NAN;
    }

    uint32_t rawP = _lastRaw.press;
    uint32_t rawT = _lastRaw.temp;
    uint32_t rawH = _lastRaw.hum;

    double adc_H = (double)rawH;
    double var_H = ((double)_t_fine) - 76800.0;
    var_H = (adc_H - (((double)calibration.dig_H4) * 64.0 + ((double)calibration.dig_H5) / 16384.0 * var_H)) *
            ((double)calibration.dig_H2 / 65536.0 * (1.0 + ((double)calibration.dig_H6) / 67108864.0 * var_H *
            (1.0 + ((double)calibration.dig_H3) / 67108864.0 * var_H)));
    var_H = var_H * (1.0 - ((double)calibration.dig_H1) * var_H / 524288.0);
    if (var_H > 100.0) var_H = 100.0;
    else if (var_H < 0.0) var_H = 0.0;
    return (float)var_H;
}

// configuration_and_reset: configure and reset implementations

bool BME280::configure(uint8_t osrs_t,
                       uint8_t osrs_p,
                       uint8_t osrs_h,
                       uint8_t mode,
                       uint8_t t_sb,
                       uint8_t filter)
{
    // Respect datasheet: write ctrl_hum first, then ctrl_meas, and config may be written before/after
    uint8_t ctrl_hum = (osrs_h & 0x07);
    if (!writeRegister8(BME280_REG_CTRL_HUM, ctrl_hum)) return false;

    uint8_t ctrl_meas = ((osrs_t & 0x07) << 5) | ((osrs_p & 0x07) << 2) | (mode & 0x03);
    if (!writeRegister8(BME280_REG_CTRL_MEAS, ctrl_meas)) return false;

    uint8_t config = ((t_sb & 0x07) << 5) | ((filter & 0x07) << 2) | 0x00; // spi3w_en = 0
    if (!writeRegister8(BME280_REG_CONFIG, config)) return false;

    return true;
}

void BME280::reset()
{
    // write 0xB6 to reset register (write-only)
    writeRegister8(BME280_REG_RESET, 0xB6);
}

