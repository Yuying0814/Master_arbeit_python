/*
Public header declaring LIS3DH class, enums for ODR/FS/FIFO modes, and register defines.
*/

#pragma once

// section: Includes and register defines
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

// Register addresses (from provided register_map)
#define LIS3DH_REG_STATUS_REG_AUX 0x07
#define LIS3DH_REG_OUT_ADC1_L     0x08
#define LIS3DH_REG_OUT_ADC1_H     0x09
#define LIS3DH_REG_OUT_ADC2_L     0x0A
#define LIS3DH_REG_OUT_ADC2_H     0x0B
#define LIS3DH_REG_OUT_ADC3_L     0x0C
#define LIS3DH_REG_OUT_ADC3_H     0x0D
#define LIS3DH_REG_WHO_AM_I       0x0F

#define LIS3DH_REG_CTRL_REG0      0x1E
#define LIS3DH_REG_TEMP_CFG_REG   0x1F
#define LIS3DH_REG_CTRL_REG1      0x20
#define LIS3DH_REG_CTRL_REG2      0x21
#define LIS3DH_REG_CTRL_REG3      0x22
#define LIS3DH_REG_CTRL_REG4      0x23
#define LIS3DH_REG_CTRL_REG5      0x24
#define LIS3DH_REG_CTRL_REG6      0x25
#define LIS3DH_REG_REFERENCE      0x26
#define LIS3DH_REG_STATUS_REG     0x27

#define LIS3DH_REG_OUT_X_L        0x28
#define LIS3DH_REG_OUT_X_H        0x29
#define LIS3DH_REG_OUT_Y_L        0x2A
#define LIS3DH_REG_OUT_Y_H        0x2B
#define LIS3DH_REG_OUT_Z_L        0x2C
#define LIS3DH_REG_OUT_Z_H        0x2D

#define LIS3DH_REG_FIFO_CTRL_REG  0x2E
#define LIS3DH_REG_FIFO_SRC_REG   0x2F

#define LIS3DH_REG_INT1_CFG       0x30
#define LIS3DH_REG_INT1_SRC       0x31
#define LIS3DH_REG_INT1_THS       0x32
#define LIS3DH_REG_INT1_DURATION  0x33
#define LIS3DH_REG_INT2_CFG       0x34
#define LIS3DH_REG_INT2_SRC       0x35
#define LIS3DH_REG_INT2_THS       0x36
#define LIS3DH_REG_INT2_DURATION  0x37

#define LIS3DH_REG_CLICK_CFG      0x38
#define LIS3DH_REG_CLICK_SRC      0x39
#define LIS3DH_REG_CLICK_THS      0x3A
#define LIS3DH_REG_TIME_LIMIT     0x3B
#define LIS3DH_REG_TIME_LATENCY   0x3C
#define LIS3DH_REG_TIME_WINDOW    0x3D
#define LIS3DH_REG_ACT_THS        0x3E
#define LIS3DH_REG_ACT_DUR        0x3F

// Bit masks for common fields
#define LIS3DH_WHO_AM_I_ID        0x33

#define LIS3DH_CTRL_REG0_SDO_PU_DISC (1 << 7)

#define LIS3DH_CTRL_REG1_ODR_MASK   0xF0
#define LIS3DH_CTRL_REG1_LPEN       (1 << 3)
#define LIS3DH_CTRL_REG1_XEN        (1 << 0)
#define LIS3DH_CTRL_REG1_YEN        (1 << 1)
#define LIS3DH_CTRL_REG1_ZEN        (1 << 2)

#define LIS3DH_CTRL_REG4_BDU        (1 << 7)
#define LIS3DH_CTRL_REG4_BLE        (1 << 6)
#define LIS3DH_CTRL_REG4_FS_MASK    (0x3 << 4)
#define LIS3DH_CTRL_REG4_HR         (1 << 3)
#define LIS3DH_CTRL_REG4_ST_MASK    (0x3 << 1)
#define LIS3DH_CTRL_REG4_SIM        (1 << 0)

#define LIS3DH_CTRL_REG5_BOOT       (1 << 7)
#define LIS3DH_CTRL_REG5_FIFO_EN    (1 << 6)
#define LIS3DH_CTRL_REG5_LIR_INT1   (1 << 3)
#define LIS3DH_CTRL_REG5_LIR_INT2   (1 << 1)

// section: Public types and enums
// ODR codes (use register ODR[3:0] codes as per register map)
enum LIS3DH_ODR_t {
  LIS3DH_ODR_POWER_DOWN = 0x00,
  LIS3DH_ODR_1HZ        = 0x10,
  LIS3DH_ODR_10HZ       = 0x20,
  LIS3DH_ODR_25HZ       = 0x30,
  LIS3DH_ODR_50HZ       = 0x40,
  LIS3DH_ODR_100HZ      = 0x50,
  LIS3DH_ODR_200HZ      = 0x60,
  LIS3DH_ODR_400HZ      = 0x70,
  LIS3DH_ODR_LP_1_6KHZ  = 0x80,
  LIS3DH_ODR_HR_1344    = 0x90
};

// Full-scale codes FS[1:0]
enum LIS3DH_FS_t {
  LIS3DH_FS_2G  = 0,
  LIS3DH_FS_4G  = 1,
  LIS3DH_FS_8G  = 2,
  LIS3DH_FS_16G = 3
};

// FIFO modes (FM[1:0])
enum LIS3DH_FIFO_MODE_t {
  LIS3DH_FIFO_BYPASS = 0,
  LIS3DH_FIFO_FIFO   = 1,
  LIS3DH_FIFO_STREAM = 2,
  LIS3DH_FIFO_STR_TO_FIFO = 3
};

// section: LIS3DH public API
class LIS3DH {
public:
  // Constructor
  LIS3DH();

  // beginI2C: initialize driver for I2C. Does not call Wire.begin().
  // Parameters: i2c_address - 7-bit address; verify - if true read WHO_AM_I and return false if mismatch.
  // Returns true on success.
  bool beginI2C(uint8_t i2c_address, bool verify = true);

  // beginSPI: initialize driver for SPI. Does not call SPI.begin().
  // Parameters: csPin - chip-select pin (active low); spi - reference to SPI instance; verify - read WHO_AM_I when true.
  // Returns true on success.
  bool beginSPI(uint8_t csPin, SPIClass &spi = SPI, bool verify = true);

  // whoAmI: read WHO_AM_I register, return raw value (0x00 on communication error).
  uint8_t whoAmI();

  // reboot: set BOOT=1 to reload factory calibration. Returns true on successful write.
  bool reboot();

  // setODR: write ODR bits to CTRL_REG1. odr_code must be one of LIS3DH_ODR_t values.
  bool setODR(uint8_t odr_code);

  // setPowerMode: set lowPower (LPen) and highResolution (HR). odr_hz used to compute HR turn-on delay.
  bool setPowerMode(bool lowPower, bool highResolution, float odr_hz = 100.0);

  // enableAxis: enable/disable X/Y/Z axes in CTRL_REG1.
  bool enableAxis(bool x, bool y, bool z);

  // setFullScale: set FS[1:0] in CTRL_REG4 and update sensitivity.
  bool setFullScale(uint8_t fs_code);

  // setBDU: enable/disable block data update (CTRL_REG4 BDU)
  bool setBDU(bool enable);

  // setBLE: set byte order BLE in CTRL_REG4
  bool setBLE(bool bigEndian);

  // setSIM: set SPI 3-wire mode (CTRL_REG4 SIM)
  // Note: this driver port does not support enabling 3-wire (SIM=1). Calling setSIM(true) will return false and will not change device SIM bit.
  bool setSIM(bool threeWire);

  // selfTest: enable/disable self-test. mode: 0=off,1=ST0,2=ST1. odr_hz used to compute sample timing.
  bool selfTest(uint8_t mode, float odr_hz = 100.0);

  // enableADC: Enable/disable auxiliary ADC and temperature sensor via TEMP_CFG_REG.
  bool enableADC(bool adcEnable, bool tempEnable);

  // readADC: Read ADC channel 1..3, return raw left-aligned value. Returns INT16_MIN on error.
  int16_t readADC(uint8_t channel);

  // configureFIFO: enable/disable FIFO, set FIFO mode and watermark threshold.
  bool configureFIFO(bool enable, uint8_t fifoMode, uint8_t watermark);

  // readFifoStatus: read FIFO_SRC_REG raw value; returns 0xFF on comms error.
  uint8_t readFifoStatus();

  // getFifoSampleCount: return FSS field (0..31) or -1 on communication error
  int getFifoSampleCount();

  // readFifoStatusParsed: read FIFO_SRC_REG and return parsed fields (FSS, WTM, OVRN_FIFO, EMPTY).
  // Returns true on successful communication.
  bool readFifoStatusParsed(uint8_t &fss, bool &wtm, bool &ovrn, bool &empty);

  // readFifoSamples: Read up to maxSamples sample-sets from FIFO into caller buffer.
  // outBuffer must have space for 3 * maxSamples int16_t entries (X,Y,Z for each sample).
  // samplesRead is set to the number of sample-sets actually read.
  // Returns true on success. If FIFO OVRN_FIFO is set the function returns false (use readFifoStatusParsed to inspect).
  bool readFifoSamples(uint8_t maxSamples, int16_t *outBuffer, uint8_t &samplesRead);

  // drainFIFO: read and discard all FIFO sample-sets until FIFO empty. Returns false if OVRN_FIFO detected or on comms error.
  bool drainFIFO();

  // readRaw: read accelerometer raw X,Y,Z left-justified 16-bit values. Returns true on success.
  bool readRaw(int16_t &x, int16_t &y, int16_t &z);

  // readNormalized: read accel and convert to g units using current FS and resolution. Returns true on success.
  // Conversion method (datasheet):
  // 1) Determine effective bits: HR=12, Normal=10, LP=8. Raw registers are left-justified into 16-bit words.
  // 2) Compute signed count = raw >> (16 - effective_bits) (arithmetic shift to preserve sign).
  // 3) Use mg/digit table (So) per FS and mode:
  //    FS=±2g:   HR=1 mg/digit, Normal=4 mg/digit, LP=16 mg/digit
  //    FS=±4g:   HR=2 mg/digit, Normal=8 mg/digit, LP=32 mg/digit
  //    FS=±8g:   HR=4 mg/digit, Normal=16 mg/digit, LP=64 mg/digit
  //    FS=±16g:  HR=12 mg/digit, Normal=48 mg/digit, LP=192 mg/digit
  // 4) g = count * mg_per_digit * 0.001
  bool readNormalized(float &gx, float &gy, float &gz);

  // configureInterrupts: write masks to CTRL_REG3 and CTRL_REG6
  bool configureInterrupts(uint8_t ctrl3_mask, uint8_t ctrl6_mask);

  // readInt1Src: read INT1_SRC register raw (0xFF on error)
  uint8_t readInt1Src();

  // readClickSrc: read CLICK_SRC register raw (0xFF on error)
  uint8_t readClickSrc();

  // setSDOPullupDisconnect: set/clear SDO_PU_DISC in CTRL_REG0. Returns true on success.
  bool setSDOPullupDisconnect(bool disconnect);

  // Advanced low-level helpers (documented as advanced): read/write single register
  // readRegister: return 0..255 on success, -1 on communication error
  int readRegister(uint8_t reg);
  bool writeRegister(uint8_t reg, uint8_t value);

  // Utility: read status registers
  uint8_t readStatus();
  uint8_t readStatusAux();

private:
  // section: Private helpers (to be implemented in .cpp)
  // computeModeTransitionDelayMs: compute required delay ms for transitions involving HR/non-HR and LP
  uint32_t computeModeTransitionDelayMs(bool oldHR, bool newHR, float odr_hz);

  // SPI multi-transfer helper: performs SPI multi-byte read/write using command byte with read and auto-inc bits
  // SPI command layout (datasheet): bit0 = RW (1=read), bit1 = MS (auto-increment), bits2..7 = address AD(5:0).
  // The first transmitted byte is therefore: (reg & 0x3F) | (MS?0x40:0) | (READ?0x80:0)
  bool spiWriteReadMultiple(uint8_t reg, const uint8_t *tx, uint8_t *rx, size_t len);

  // I2C write-then-read helper (handles Wire buffer chunking internally)
  bool i2cWriteThenRead(uint8_t reg, uint8_t *rx, size_t len);

  // low-level single-shot I2C/SPI primitives used by readRegister/writeRegister
  bool _busIsSPI;
  uint8_t _i2caddr;
  uint8_t _csPin;
  SPIClass *_spi;
  SPISettings _spiSettings;

  // cached configuration
  uint8_t _fs_code; // 0..3
  bool _hr_enabled;
  bool _bdu_enabled;
  bool _lpen_enabled;

  // SPI/3-wire support flags
  // This port does not implement 3-wire SPI operations; _sim_supported=false
  bool _sim_supported;
  // cached device SIM bit state when read during initialization
  bool _sim_enabled;

  // internal helpers
  bool readRegisters(uint8_t startReg, uint8_t *buf, size_t len);
  bool writeRegisters(uint8_t startReg, const uint8_t *buf, size_t len);
};

