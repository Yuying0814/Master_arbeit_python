/*
Source file implementing TCS3472 driver methods.
*/

// Includes and private constants: include header and Wire
#include "TCS3472.h"

// Constructor and begin(): implement constructor and begin()
// Constructor implementation
TCS3472::TCS3472()
: _i2c_addr(0)
{
}

// begin(): Save i2c_addr internally and attempt to read ID register to verify device presence.
bool TCS3472::begin(uint8_t i2c_addr)
{
    _i2c_addr = i2c_addr;
    uint8_t id = readID();
    // readID returns 0xFF on failure
    if (id == 0xFF) {
        return false;
    }
    return true;
}

// Power and enable methods
void TCS3472::powerOn()
{
    // Read current ENABLE, set PON bit
    uint8_t en = read8(TCS3472_REG_ENABLE);
    if (en == 0xFF) {
        // I2C failure; attempt to write PON anyway (best-effort)
        write8(TCS3472_REG_ENABLE, TCS3472_ENABLE_PON);
        delay(3);
        return;
    }
    if ((en & TCS3472_ENABLE_PON) == 0) {
        en |= TCS3472_ENABLE_PON;
        write8(TCS3472_REG_ENABLE, en);
    }
    // Wait at least 2.4 ms for oscillator warm-up
    delay(3);
}

void TCS3472::powerOff()
{
    uint8_t en = read8(TCS3472_REG_ENABLE);
    if (en == 0xFF) {
        // best-effort clear
        write8(TCS3472_REG_ENABLE, 0x00);
        return;
    }
    en &= ~TCS3472_ENABLE_PON;
    write8(TCS3472_REG_ENABLE, en);
}

void TCS3472::enableRGBC(bool enable)
{
    // If enabling and PON not set, assert PON first and wait the required warm-up
    uint8_t en = read8(TCS3472_REG_ENABLE);
    if (en == 0xFF) {
        // I2C failure; attempt best-effort write
        if (enable) {
            // set PON then delay then set AEN
            write8(TCS3472_REG_ENABLE, TCS3472_ENABLE_PON);
            delay(3);
            write8(TCS3472_REG_ENABLE, TCS3472_ENABLE_PON | TCS3472_ENABLE_AEN);
        } else {
            write8(TCS3472_REG_ENABLE, 0x00);
        }
        return;
    }

    bool pon_set = (en & TCS3472_ENABLE_PON);
    if (enable) {
        if (!pon_set) {
            // set PON first and wait
            en |= TCS3472_ENABLE_PON;
            write8(TCS3472_REG_ENABLE, en);
            delay(3);
            // now set AEN as well
            en |= TCS3472_ENABLE_AEN;
            write8(TCS3472_REG_ENABLE, en);
            return;
        } else {
            // PON already set; just set AEN bit
            en |= TCS3472_ENABLE_AEN;
            write8(TCS3472_REG_ENABLE, en);
            return;
        }
    } else {
        // disable AEN
        en &= ~TCS3472_ENABLE_AEN;
        write8(TCS3472_REG_ENABLE, en);
    }
}

// RGBC data read and status
bool TCS3472::isRGBCValid()
{
    uint8_t st = readStatus();
    if (st == 0xFF) return false; // treat failure as not valid
    return (st & TCS3472_STATUS_AVALID) != 0;
}

bool TCS3472::readRaw(uint16_t &c, uint16_t &r, uint16_t &g, uint16_t &b)
{
    // Check STATUS.AVALID first
    uint8_t st = readStatus();
    if (st == 0xFF) return false; // I2C failure
    if ((st & TCS3472_STATUS_AVALID) == 0) {
        return false; // data not fresh
    }

    // Read 8 bytes CDATAL..BDATAH using TYPE=01 auto-increment
    uint8_t buf[8];
    bool ok = readBlock16AutoIncrement(TCS3472_REG_CDATAL, buf, sizeof(buf));
    if (!ok) return false;

    // Assemble little-endian 16-bit values
    c = (uint16_t)buf[1] << 8 | buf[0];
    r = (uint16_t)buf[3] << 8 | buf[2];
    g = (uint16_t)buf[5] << 8 | buf[4];
    b = (uint16_t)buf[7] << 8 | buf[6];
    return true;
}

// Configuration and interrupt methods
void TCS3472::setATime(uint8_t atime)
{
    // IntegrationTime_ms = 2.4 * (256 - ATIME)
    write8(TCS3472_REG_ATIME, atime);
}

uint8_t TCS3472::getATime()
{
    return read8(TCS3472_REG_ATIME);
}

void TCS3472::setGain(Gain g)
{
    uint8_t ctrl = read8(TCS3472_REG_CONTROL);
    if (ctrl == 0xFF) {
        // best-effort write new control
        write8(TCS3472_REG_CONTROL, (uint8_t)g & TCS3472_CONTROL_AGAIN_MASK);
        return;
    }
    ctrl &= ~TCS3472_CONTROL_AGAIN_MASK;
    ctrl |= ((uint8_t)g & TCS3472_CONTROL_AGAIN_MASK);
    write8(TCS3472_REG_CONTROL, ctrl);
}

void TCS3472::setWait(bool enable, uint8_t wtime, bool wlong)
{
    uint8_t en = read8(TCS3472_REG_ENABLE);
    if (en == 0xFF) {
        // best-effort
        if (enable) {
            write8(TCS3472_REG_WTIME, wtime);
            uint8_t cfg = wlong ? TCS3472_CONFIG_WLONG : 0x00;
            write8(TCS3472_REG_CONFIG, cfg);
            write8(TCS3472_REG_ENABLE, TCS3472_ENABLE_WEN);
        } else {
            write8(TCS3472_REG_ENABLE, en & ~TCS3472_ENABLE_WEN);
        }
        return;
    }

    if (enable) {
        // program WTIME if provided
        write8(TCS3472_REG_WTIME, wtime);
        uint8_t cfg = read8(TCS3472_REG_CONFIG);
        if (cfg == 0xFF) cfg = 0x00;
        if (wlong) cfg |= TCS3472_CONFIG_WLONG;
        else cfg &= ~TCS3472_CONFIG_WLONG;
        write8(TCS3472_REG_CONFIG, cfg);
        en |= TCS3472_ENABLE_WEN;
        write8(TCS3472_REG_ENABLE, en);
    } else {
        en &= ~TCS3472_ENABLE_WEN;
        write8(TCS3472_REG_ENABLE, en);
    }
}

void TCS3472::setInterruptEnable(bool enable)
{
    uint8_t en = read8(TCS3472_REG_ENABLE);
    if (en == 0xFF) {
        // best-effort
        if (enable) write8(TCS3472_REG_ENABLE, TCS3472_ENABLE_AIEN);
        else write8(TCS3472_REG_ENABLE, 0x00);
        return;
    }
    if (enable) en |= TCS3472_ENABLE_AIEN;
    else en &= ~TCS3472_ENABLE_AIEN;
    write8(TCS3472_REG_ENABLE, en);
}

void TCS3472::setInterruptThresholds(uint16_t low, uint16_t high)
{
    // Ensure low <= high
    if (low > high) {
        uint16_t tmp = low; low = high; high = tmp;
    }
    // Write low threshold (AILTL then AILTH)
    write8(TCS3472_REG_AILTL, (uint8_t)(low & 0xFF));
    write8(TCS3472_REG_AILTH, (uint8_t)((low >> 8) & 0xFF));
    // Write high threshold
    write8(TCS3472_REG_AIHTL, (uint8_t)(high & 0xFF));
    write8(TCS3472_REG_AIHTH, (uint8_t)((high >> 8) & 0xFF));
}

void TCS3472::clearInterrupt()
{
    // Issue special-function command: TYPE=11, ADDR/SF=00110
    uint8_t cmd = composeCommand(TCS3472_CMD_TYPE_SPECIAL, TCS3472_CMD_SF_CLEAR_INT, true);
    // Write only the COMMAND byte; special-function will be executed
    Wire.beginTransmission(_i2c_addr);
    Wire.write(cmd);
    Wire.endTransmission();
}

void TCS3472::setPersistence(uint8_t apers)
{
    if (apers > 0x0F) apers = 0x0F;
    uint8_t val = apers & 0x0F;
    // Preserve upper nibble (PPERS) if present; spec says reserved write-as-0 but keep read-modify-write
    uint8_t cur = read8(TCS3472_REG_PERS);
    if (cur == 0xFF) {
        write8(TCS3472_REG_PERS, val);
        return;
    }
    cur &= 0xF0;
    cur |= val;
    write8(TCS3472_REG_PERS, cur);
}

// ID and STATUS reads
uint8_t TCS3472::readID()
{
    uint8_t v = read8(TCS3472_REG_ID);
    if (v == 0xFF) return 0xFF; // document failure sentinel
    return v;
}

uint8_t TCS3472::readStatus()
{
    uint8_t v = read8(TCS3472_REG_STATUS);
    return v;
}

// Low-level Wire helpers (implementation)
uint8_t TCS3472::read8(uint8_t reg)
{
    if (_i2c_addr == 0) return 0xFF;
    uint8_t cmd = composeCommand(TCS3472_CMD_TYPE_REPEATED, reg & 0x1F, true);
    Wire.beginTransmission(_i2c_addr);
    Wire.write(cmd);
    uint8_t txerr = Wire.endTransmission(false); // send restart
    if (txerr != 0) {
        return 0xFF;
    }
    uint8_t got = 0;
    uint8_t avail = Wire.requestFrom(_i2c_addr, (uint8_t)1);
    if (avail == 0) return 0xFF;
    if (Wire.available()) {
        got = (uint8_t)Wire.read();
        return got;
    }
    return 0xFF;
}

bool TCS3472::write8(uint8_t reg, uint8_t value)
{
    if (_i2c_addr == 0) return false;
    uint8_t cmd = composeCommand(TCS3472_CMD_TYPE_REPEATED, reg & 0x1F, true);
    Wire.beginTransmission(_i2c_addr);
    Wire.write(cmd);
    Wire.write(value);
    uint8_t err = Wire.endTransmission();
    return (err == 0);
}

bool TCS3472::readBlock16AutoIncrement(uint8_t start_reg, uint8_t *buf, size_t len)
{
    if (_i2c_addr == 0) return false;
    if (!buf) return false;
    if (len == 0) return true;
    // Compose COMMAND byte with TYPE=01 (autoincrement)
    uint8_t cmd = composeCommand(TCS3472_CMD_TYPE_AUTOINC, start_reg & 0x1F, true);
    Wire.beginTransmission(_i2c_addr);
    Wire.write(cmd);
    uint8_t txerr = Wire.endTransmission(false); // restart
    if (txerr != 0) return false;
    uint8_t avail = Wire.requestFrom(_i2c_addr, (uint8_t)len);
    if (avail < len) return false;
    for (size_t i = 0; i < len; ++i) {
        if (Wire.available()) buf[i] = (uint8_t)Wire.read();
        else return false;
    }
    return true;
}

uint8_t TCS3472::composeCommand(uint8_t type, uint8_t addrsf, bool cmd)
{
    uint8_t b = 0;
    if (cmd) b |= 0x80; // CMD bit7
    b |= (uint8_t)((type & 0x03) << 5);
    b |= (addrsf & 0x1F);
    return b;
}

