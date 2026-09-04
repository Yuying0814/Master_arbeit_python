/*
Public header for the TCS3472 Arduino driver (I2C).
*/

#pragma once

// Includes and defines: include Arduino and Wire, define register addresses and bit masks
#include <Arduino.h>
#include <Wire.h>

// Register addresses (physical) from register_map
#define TCS3472_REG_ENABLE   0x00
#define TCS3472_REG_ATIME    0x01
#define TCS3472_REG_WTIME    0x03
#define TCS3472_REG_AILTL    0x04
#define TCS3472_REG_AILTH    0x05
#define TCS3472_REG_AIHTL    0x06
#define TCS3472_REG_AIHTH    0x07
#define TCS3472_REG_PERS     0x0C
#define TCS3472_REG_CONFIG   0x0D
#define TCS3472_REG_CONTROL  0x0F
#define TCS3472_REG_ID       0x12
#define TCS3472_REG_STATUS   0x13
#define TCS3472_REG_CDATAL   0x14 // CDATAL (low)
#define TCS3472_REG_CDATAH   0x15 // CDATAH (high)
#define TCS3472_REG_RDATAL   0x16
#define TCS3472_REG_RDATAH   0x17
#define TCS3472_REG_GDATAL   0x18
#define TCS3472_REG_GDATAH   0x19
#define TCS3472_REG_BDATAL   0x1A
#define TCS3472_REG_BDATAH   0x1B

// ENABLE register bits
#define TCS3472_ENABLE_PON   (1 << 0)
#define TCS3472_ENABLE_AEN   (1 << 1)
#define TCS3472_ENABLE_WEN   (1 << 3)
#define TCS3472_ENABLE_AIEN  (1 << 4)

// STATUS bits
#define TCS3472_STATUS_AVALID (1 << 0)
#define TCS3472_STATUS_AINT   (1 << 4)

// CONFIG bits
#define TCS3472_CONFIG_WLONG  (1 << 1)

// CONTROL bits (AGAIN in bits 1:0)
#define TCS3472_CONTROL_AGAIN_MASK 0x03

// COMMAND composition helper fields (TYPE values)
#define TCS3472_CMD_TYPE_REPEATED 0x0
#define TCS3472_CMD_TYPE_AUTOINC  0x1
#define TCS3472_CMD_TYPE_SPECIAL  0x3

// Special-function ADDR/SF value for clear-interrupt (00110b == 0x06)
#define TCS3472_CMD_SF_CLEAR_INT  0x06


// Public types and enums: AGAIN gain selector
// Gain enum maps CONTROL.AGAIN settings: 00=1x, 01=4x, 10=16x, 11=60x
enum Gain {
    GAIN_1X = 0,
    GAIN_4X = 1,
    GAIN_16X = 2,
    GAIN_60X = 3
};

// Public class declaration: TCS3472
class TCS3472 {
public:
    // TCS3472(): Default constructor; does not touch the Wire bus.
    TCS3472();

    // begin(i2c_addr): Initialize driver instance with the device I2C address and validate presence by reading ID.
    // Does NOT call Wire.begin(). Returns true on success (ID read) or false on I2C failure.
    bool begin(uint8_t i2c_addr);

    // powerOn(): Set ENABLE.PON=1. Wait at least 2.4 ms (uses delay(3)) before enabling AEN.
    void powerOn();

    // powerOff(): Clear ENABLE.PON=0 to enter Sleep state.
    void powerOff();

    // enableRGBC(enable): Set/clear ENABLE.AEN to start/stop RGBC conversions.
    // If enabling and PON was not set, this method will assert PON and wait the required warm-up.
    void enableRGBC(bool enable);

    // isRGBCValid(): Read STATUS.AVALID and return true if fresh RGBC data is available.
    bool isRGBCValid();

    // readRaw(c,r,g,b): Atomically read CDATA, RDATA, GDATA, BDATA using COMMAND auto-increment/read-word.
    // Returns true if read succeeded and STATUS.AVALID was set prior to read (fresh data).
    bool readRaw(uint16_t &c, uint16_t &r, uint16_t &g, uint16_t &b);

    // setATime(atime): Write ATIME. IntegrationTime_ms = 2.4 * (256 - ATIME).
    void setATime(uint8_t atime);

    // getATime(): Read and return the ATIME register value.
    uint8_t getATime();

    // setGain(g): Set analog gain via CONTROL.AGAIN (00=1x, 01=4x, 10=16x, 11=60x).
    void setGain(Gain g);

    // setWait(enable, wtime, wlong): Configure wait timer (ENABLE.WEN, WTIME, CONFIG.WLONG).
    // If enable==true, set WEN and program WTIME and WLONG; if false clear WEN.
    void setWait(bool enable, uint8_t wtime = 0xFF, bool wlong = false);

    // setInterruptEnable(enable): Set ENABLE.AIEN to enable/disable INT pin assertion.
    void setInterruptEnable(bool enable);

    // setInterruptThresholds(low, high): Program 16-bit clear-channel low/high thresholds (AILT / AIHT).
    // If low > high the driver swaps values internally to ensure low <= high.
    void setInterruptThresholds(uint16_t low, uint16_t high);

    // clearInterrupt(): Issue COMMAND special-function TYPE=11 ADDR/SF=00110 to clear pending clear-channel interrupt.
    void clearInterrupt();

    // readID(): Read ID register (0x12) to identify the part. Returns 0xFF on I2C failure.
    uint8_t readID();

    // readStatus(): Read STATUS register (0x13).
    uint8_t readStatus();

    // setPersistence(apers): Program PERS.APERS (0..15). Values outside range are clamped.
    void setPersistence(uint8_t apers);

private:
    // Private helpers (declarations)
    // read8(reg): Low-level read of a single register. Returns read byte or 0xFF on failure.
    uint8_t read8(uint8_t reg);

    // write8(reg, value): Low-level single-byte write. Returns true on success.
    bool write8(uint8_t reg, uint8_t value);

    // readBlock16AutoIncrement(start_reg, buf, len): Read a block of bytes using COMMAND TYPE=01 auto-increment.
    // Returns true on success.
    bool readBlock16AutoIncrement(uint8_t start_reg, uint8_t *buf, size_t len);

    // composeCommand(type, addrsf, cmd): Compose the 8-bit COMMAND byte.
    uint8_t composeCommand(uint8_t type, uint8_t addrsf, bool cmd);

    uint8_t _i2c_addr; // 7-bit I2C address stored
};

