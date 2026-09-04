/*
Source file implementing MLX90382 methods using SPI.h and the register_map constants.
*/

// Includes and static registers: Include MLX90382.h and <SPI.h>. Define any small inline helpers or static lookup arrays.
#include "MLX90382.h"

// Constructor and lifecycle: Implement constructor, begin(), and end().

MLX90382::MLX90382(uint8_t csPin)
    : _csPin(csPin), _spiSettings(1000000, MSBFIRST, SPI_MODE0), _configured(false) {
}

bool MLX90382::begin(uint8_t csPin, uint32_t spiClock, uint8_t spiMode) {
    if (csPin != 255) {
        _csPin = csPin;
    }
    if (_csPin == 255) {
        return false; // CS must be provided
    }
    pinMode(_csPin, OUTPUT);
    digitalWrite(_csPin, HIGH);
    // store SPI settings; SPI.begin() is caller's responsibility
    uint8_t mode = spiMode & 0x3;
    _spiSettings = SPISettings(spiClock, MSBFIRST, mode);
    _configured = true;
    return true;
}

void MLX90382::end() {
    if (_csPin != 255) {
        // release pin to reduce power
        digitalWrite(_csPin, LOW);
        pinMode(_csPin, INPUT);
    }
    _configured = false;
}

// Low-level SPI helpers: Implement spiReadRegister16 and spiWriteRegister16 using SPI.beginTransaction / endTransaction and digitalWrite for CS.

bool MLX90382::spiReadRegister16(uint16_t regAddr, uint16_t* out) {
    if (!_configured || _csPin == 255 || out == nullptr) return false;
    uint8_t addr_hi = (uint8_t)((regAddr >> 8) & 0xFF);
    uint8_t addr_lo = (uint8_t)(regAddr & 0xFF);
    uint8_t rx_hi = 0, rx_lo = 0;

    SPI.beginTransaction(_spiSettings);
    digitalWrite(_csPin, LOW);
    // send address high/low
    SPI.transfer(addr_hi);
    SPI.transfer(addr_lo);
    // read two data bytes (big-endian)
    rx_hi = SPI.transfer(0x00);
    rx_lo = SPI.transfer(0x00);
    digitalWrite(_csPin, HIGH);
    SPI.endTransaction();

    *out = (uint16_t)((rx_hi << 8) | rx_lo);
    return true;
}

bool MLX90382::spiWriteRegister16(uint16_t regAddr, uint16_t value) {
    if (!_configured || _csPin == 255) return false;
    uint8_t addr_hi = (uint8_t)((regAddr >> 8) & 0xFF);
    uint8_t addr_lo = (uint8_t)(regAddr & 0xFF);
    uint8_t val_hi = (uint8_t)((value >> 8) & 0xFF);
    uint8_t val_lo = (uint8_t)(value & 0xFF);

    SPI.beginTransaction(_spiSettings);
    digitalWrite(_csPin, LOW);
    // send address then data (write op assumed by device when followed by data)
    SPI.transfer(addr_hi);
    SPI.transfer(addr_lo);
    SPI.transfer(val_hi);
    SPI.transfer(val_lo);
    digitalWrite(_csPin, HIGH);
    SPI.endTransaction();
    return true;
}

// Public generic register access wrappers
int MLX90382::readRegister16(uint16_t regAddr, uint16_t* value) {
    if (!_configured) return MLX90382_ERR_SPI;
    uint16_t tmp = 0;
    bool ok = spiReadRegister16(regAddr, &tmp);
    if (!ok) return MLX90382_ERR_SPI;
    if (value) *value = tmp;
    return MLX90382_OK;
}

bool MLX90382::writeRegister16(uint16_t regAddr, uint16_t value) {
    if (!_configured) return false;
    return spiWriteRegister16(regAddr, value);
}

// High-level API implementations

int32_t MLX90382::readDriftcPhase() {
    uint16_t v;
    if (readRegister16(MLX90382_DRIFTC_PHASE, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    // return as signed 16-bit per API contract
    return (int32_t)((int16_t)v);
}

int32_t MLX90382::readLinPhase() {
    uint16_t v;
    if (readRegister16(MLX90382_LIN_PHASE, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int32_t)((uint16_t)v);
}

int32_t MLX90382::readSCPhase() {
    uint16_t v;
    if (readRegister16(MLX90382_SC_PHASE, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int32_t)((uint16_t)v);
}

int32_t MLX90382::readSpeed() {
    uint16_t v;
    if (readRegister16(MLX90382_SPEED, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int32_t)((int16_t)v);
}

int32_t MLX90382::readTempRaw() {
    uint16_t v;
    if (readRegister16(MLX90382_TEMP, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int32_t)v;
}

float MLX90382::readTemperatureC() {
    uint16_t raw;
    if (readRegister16(MLX90382_TEMP, &raw) != MLX90382_OK) return NAN;
    // Formula from programming plan: T[°C] = TEMP/8 + 200[K] - 273.15
    float kelvin = ((float)raw) / 8.0f + 200.0f;
    float c = kelvin - 273.15f;
    return c;
}

int MLX90382::readAGCGain() {
    uint16_t v;
    if (readRegister16(MLX90382_AGC_GAIN, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int)(v & 0x3F); // 6-bit field
}

int MLX90382::readAGCAmp() {
    uint16_t v;
    if (readRegister16(MLX90382_AGC_AMP, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int)(v & 0x1FFF); // 13-bit field in doc
}

bool MLX90382::setAGCGainLimits(uint8_t minGain, uint8_t maxGain) {
    if (!_configured) return false;
    uint8_t minv = minGain & 0x3F;
    uint8_t maxv = maxGain & 0x3F;
    uint16_t packed = (uint16_t)((maxv << 6) | (minv & 0x3F));
    return writeRegister16(MLX90382_AGC_GAIN_MINMAX, packed);
}

int32_t MLX90382::readGC_I() {
    uint16_t v;
    if (readRegister16(MLX90382_GC_I, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int32_t)((int16_t)v);
}

int32_t MLX90382::readGC_Q(uint32_t wait_ms) {
    // If averaging is configured, optionally wait
    if (wait_ms > 0) {
        waitForGCAverage(wait_ms);
    } else {
        // if zero, use default if DSP_GC_AVG != 0
        uint16_t dsp;
        if (readRegister16(MLX90382_DSP_IQNEG, &dsp) == MLX90382_OK) {
            uint8_t avg = (dsp >> 2) & 0x7;
            if (avg != 0) {
                waitForGCAverage(200);
            }
        }
    }
    uint16_t v;
    if (readRegister16(MLX90382_GC_Q, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int32_t)((int16_t)v);
}

bool MLX90382::waitForGCAverage(uint32_t wait_ms) {
    uint32_t timeout = wait_ms ? wait_ms : 200;
    uint32_t start = millis();
    // Best-effort: poll DSP_IQNEG.DSP_GC_AVG and assume averaging completes within timeout
    while ((millis() - start) < timeout) {
        // nothing explicit to read to confirm completion in available map; rely on time only
        delay(5);
    }
    return true; // best-effort
}

int32_t MLX90382::readRMM_ASIQ() {
    uint16_t v;
    if (readRegister16(MLX90382_RMM_ASIQ, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int32_t)((int16_t)v);
}

int32_t MLX90382::readRMM_ASQQ() {
    uint16_t v;
    if (readRegister16(MLX90382_RMM_ASQQ, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int32_t)((int16_t)v);
}

bool MLX90382::setPEQGain(uint8_t gain) {
    if (gain > 7) gain = 7;
    // Only low 3 bits used
    uint16_t cur = 0;
    (void)readRegister16(MLX90382_PEQ_GAIN, &cur);
    uint16_t newv = (cur & ~0x7) | (gain & 0x7);
    return writeRegister16(MLX90382_PEQ_GAIN, newv);
}

bool MLX90382::setPEQValue(uint8_t index, int8_t value) {
    if (index > 15) return false;
    // Determine register address for the pair
    uint16_t pairIndex = index / 2; // 0..7
    uint16_t regAddr = (uint16_t)(MLX90382_PEQ00 + (pairIndex * 2));
    uint16_t cur = 0;
    if (readRegister16(regAddr, &cur) != MLX90382_OK) return false;
    uint8_t low = (uint8_t)(cur & 0xFF);
    uint8_t high = (uint8_t)((cur >> 8) & 0xFF);
    uint8_t byteVal = (uint8_t)value; // two's complement storage
    if ((index & 1) == 0) {
        low = byteVal;
    } else {
        high = byteVal;
    }
    uint16_t newv = (uint16_t)((high << 8) | low);
    return writeRegister16(regAddr, newv);
}

bool MLX90382::setDelayCus(uint8_t value) {
    // DELAY_CUS in low byte
    uint16_t cur = 0;
    (void)readRegister16(MLX90382_DELAY_CUS, &cur);
    uint16_t newv = (cur & 0xFF00) | ((uint16_t)value & 0x00FF);
    return writeRegister16(MLX90382_DELAY_CUS, newv);
}

bool MLX90382::startNVMCRC() {
    // Write bit0 = 1 to CRC_CALC_STRT register to start calculation
    // Register has write-only start bit; write 0x0001
    return writeRegister16(MLX90382_CRC_CALC_STRT, 0x0001);
}

bool MLX90382::waitForNVMCRCDone(uint32_t timeout_ms) {
    uint32_t timeout = timeout_ms ? timeout_ms : 1000;
    uint32_t start = millis();
    while ((millis() - start) < timeout) {
        uint16_t v = 0;
        if (readRegister16(MLX90382_CRC_CALC_STRT, &v) != MLX90382_OK) return false;
        if (v & (1 << 1)) {
            return true;
        }
        delay(5);
    }
    return false;
}

int32_t MLX90382::readCRC() {
    uint16_t v;
    if (readRegister16(MLX90382_CRC, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int32_t)v;
}

int MLX90382::readState() {
    uint16_t v;
    if (readRegister16(MLX90382_STATE, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int)(v & 0xFF);
}

bool MLX90382::setDEBits(uint16_t regAddr, uint16_t mask, uint16_t value) {
    uint16_t cur = 0;
    if (readRegister16(regAddr, &cur) != MLX90382_OK) return false;
    uint16_t newv = (uint16_t)((cur & ~mask) | (value & mask));
    return writeRegister16(regAddr, newv);
}

int32_t MLX90382::readUserID(uint8_t index) {
    uint16_t addr;
    if (index == 0) addr = MLX90382_USER_ID0;
    else if (index == 1) addr = MLX90382_USER_ID2;
    else if (index == 2) addr = MLX90382_USER_ID4;
    else return MLX90382_ERR_SPI;
    uint16_t v;
    if (readRegister16(addr, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int32_t)v;
}

int32_t MLX90382::readCUS_CRC() {
    uint16_t v;
    if (readRegister16(MLX90382_CUS_CRC, &v) != MLX90382_OK) return MLX90382_ERR_SPI;
    return (int32_t)v;
}

bool MLX90382::configureSPIFrameRead(const uint8_t* faddr, uint8_t frfs, bool enableCRC, uint8_t spiMode) {
    // Write SPI_FADDR0..3 if faddr provided (up to 4 bytes)
    if (faddr) {
        // SPI_FADDR0 contains two bytes: FADDR0 (bits 7:0) and FADDR1 (bits 15:8)
        uint16_t f0 = (uint16_t)faddr[0] | ((uint16_t)(faddr[1]) << 8);
        uint16_t f2 = (uint16_t)faddr[2] | ((uint16_t)(faddr[3]) << 8);
        if (!writeRegister16(MLX90382_SPI_FADDR0, f0)) return false;
        if (!writeRegister16(MLX90382_SPI_FADDR2, f2)) return false;
    }
    // modify SPI_FRFS (0x234)
    uint16_t cur = 0;
    if (readRegister16(MLX90382_SPI_FRFS, &cur) != MLX90382_OK) return false;
    uint16_t newv = cur;
    if (frfs != 0xFF) {
        newv = (uint16_t)((newv & ~0x000F) | (frfs & 0x0F));
    }
    if (enableCRC) newv |= (1 << 5); else newv &= ~(1 << 5);
    if (spiMode != 0xFF) {
        uint16_t m = (spiMode & 0x3);
        newv = (uint16_t)((newv & ~(0x3 << 10)) | (m << 10));
    }
    return writeRegister16(MLX90382_SPI_FRFS, newv);
}

bool MLX90382::rawReadWriteBurst(const uint8_t* tx, uint8_t* rx, size_t len) {
    if (!_configured || _csPin == 255) return false;
    SPI.beginTransaction(_spiSettings);
    digitalWrite(_csPin, LOW);
    for (size_t i = 0; i < len; ++i) {
        uint8_t toSend = tx ? tx[i] : 0x00;
        uint8_t r = SPI.transfer(toSend);
        if (rx) rx[i] = r;
    }
    digitalWrite(_csPin, HIGH);
    SPI.endTransaction();
    return true;
}

