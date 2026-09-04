/*
LIS3DH I2C and 4-wire SPI driver interface.
*/

#pragma once

// Includes and public types: Arduino/Wire/SPI and driver public types
// section_name: Includes and public types

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

// Register addresses (from register_map)
#define LIS3DH_REG_WHO_AM_I      0x0F
#define LIS3DH_REG_STATUS_AUX    0x07
#define LIS3DH_REG_OUT_ADC1_L    0x08
#define LIS3DH_REG_OUT_ADC1_H    0x09
#define LIS3DH_REG_OUT_ADC2_L    0x0A
#define LIS3DH_REG_OUT_ADC2_H    0x0B
#define LIS3DH_REG_OUT_ADC3_L    0x0C
#define LIS3DH_REG_OUT_ADC3_H    0x0D
#define LIS3DH_REG_CTRL_REG0     0x1E
#define LIS3DH_REG_TEMP_CFG      0x1F
#define LIS3DH_REG_CTRL_REG1     0x20
#define LIS3DH_REG_CTRL_REG2     0x21
#define LIS3DH_REG_CTRL_REG3     0x22
#define LIS3DH_REG_CTRL_REG4     0x23
#define LIS3DH_REG_CTRL_REG5     0x24
#define LIS3DH_REG_CTRL_REG6     0x25
#define LIS3DH_REG_REFERENCE     0x26
#define LIS3DH_REG_STATUS        0x27
#define LIS3DH_REG_OUT_X_L       0x28
#define LIS3DH_REG_OUT_X_H       0x29
#define LIS3DH_REG_OUT_Y_L       0x2A
#define LIS3DH_REG_OUT_Y_H       0x2B
#define LIS3DH_REG_OUT_Z_L       0x2C
#define LIS3DH_REG_OUT_Z_H       0x2D
#define LIS3DH_REG_FIFO_CTRL     0x2E
#define LIS3DH_REG_FIFO_SRC      0x2F
#define LIS3DH_REG_INT1_CFG      0x30
#define LIS3DH_REG_INT1_SRC      0x31
#define LIS3DH_REG_INT1_THS      0x32
#define LIS3DH_REG_INT1_DURATION 0x33
#define LIS3DH_REG_INT2_CFG      0x34
#define LIS3DH_REG_INT2_SRC      0x35
#define LIS3DH_REG_INT2_THS      0x36
#define LIS3DH_REG_INT2_DURATION 0x37
#define LIS3DH_REG_CLICK_CFG     0x38
#define LIS3DH_REG_CLICK_SRC     0x39
#define LIS3DH_REG_CLICK_THS     0x3A
#define LIS3DH_REG_TIME_LIMIT    0x3B
#define LIS3DH_REG_TIME_LATENCY  0x3C
#define LIS3DH_REG_TIME_WINDOW   0x3D
#define LIS3DH_REG_ACT_THS       0x3E
#define LIS3DH_REG_ACT_DUR       0x3F

// WHO_AM_I expected value
#define LIS3DH_WHO_AM_I_ID 0x33

// Public typed enums and structs
enum class Lis3dhOdr : uint8_t {
  PowerDown = 0x0,
  Hz1       = 0x1,
  Hz10      = 0x2,
  Hz25      = 0x3,
  Hz50      = 0x4,
  Hz100     = 0x5,
  Hz200     = 0x6,
  Hz400     = 0x7,
  Hz1_6k    = 0x8,
  Hz1_344k  = 0x9
};

enum class Lis3dhFullScale : uint8_t { FS2 = 0, FS4 = 1, FS8 = 2, FS16 = 3 };

enum class Lis3dhResolution { LowPower = 0, Normal = 1, HighResolution = 2 };

struct MeasurementConfig {
  Lis3dhOdr odr = Lis3dhOdr::Hz100; // default 100 Hz
  Lis3dhFullScale fs = Lis3dhFullScale::FS2; // ±2 g
  Lis3dhResolution res = Lis3dhResolution::Normal;
  bool enableX = true;
  bool enableY = true;
  bool enableZ = true;
  bool bdu = true;
};

struct AccelerationSample {
  int16_t x_raw; // post-shift raw counts
  int16_t y_raw;
  int16_t z_raw;
  float x_mg; // converted mg
  float y_mg;
  float z_mg;
};

struct AccelerationStatus {
  uint8_t status_reg; // raw STATUS_REG
  bool x_new;
  bool y_new;
  bool z_new;
  bool xyz_new;
  bool x_overrun;
  bool y_overrun;
  bool z_overrun;
  bool xyz_overrun;
};

struct AuxiliaryData {
  int16_t adc1_raw;
  int16_t adc2_raw;
  int16_t adc3_raw;
  bool adc1_ready;
  bool adc2_ready;
  bool adc3_ready;
};

// Use ordinary fields for public configuration structs (avoid implementation-defined bitfields)
struct HighPassConfig {
  uint8_t hpm; // 2-bit valid
  uint8_t hpcf; // 2-bit valid
  bool fds;
  bool hp_click;
  bool hp_ia2;
  bool hp_ia1;
};

struct FifoConfig {
  uint8_t fm; // 2-bit valid
  bool tr; // trigger: false => INT1, true => INT2
  uint8_t fth; // 5-bit watermark
};

struct FifoStatus {
  bool wtm;
  bool overrun;
  bool empty;
  uint8_t fss; // sample sets present
};

enum class InterruptEngine { INT1 = 1, INT2 = 2 };

struct InterruptSource {
  uint8_t raw;
  bool ia;
  bool xh;
  bool xl;
  bool yh;
  bool yl;
  bool zh;
  bool zl;
};

struct ClickSource {
  uint8_t raw;
  bool ia;
  bool dclick;
  bool sclick;
  bool sign;
  bool x;
  bool y;
  bool z;
};

// Expanded InterruptConfig with engine selection and routing options
struct InterruptConfig {
  InterruptEngine engine = InterruptEngine::INT1; // target engine
  uint8_t cfg_reg_val = 0; // INTx_CFG raw value (AOI, 6D, axis bits)
  uint8_t ths = 0; // 7-bit threshold
  uint8_t dur = 0; // 7-bit duration
  bool routeToInt2 = false; // when true route this engine to INT2, otherwise to INT1
  bool latch = false; // latch IA in CTRL_REG5 LIR_INTx
  bool d4d = false; // request 4D (will be validated against 6D)
  bool polarityActiveLow = false; // INT polarity when routing change required
};

struct ClickConfig {
  uint8_t cfg = 0; // CLICK_CFG raw (XS/YS/ZS, XD/YD/ZD) masked per datasheet
  uint8_t ths = 0; // 7-bit threshold
  bool latch = false; // whether CLICK_THS.LIR_Click (bit7) should be set
  uint8_t timeLimit = 0; // 7-bit
  uint8_t timeLatency = 0;
  uint8_t timeWindow = 0;
  bool routeToInt2 = false; // route click to INT2 (true) or INT1 (false)
};

enum class SelfTestMode : uint8_t { Disabled = 0, ST0 = 1, ST1 = 2 };

// Construction and lifecycle: bus constructors and lifecycle methods
// section_name: Construction and lifecycle

class LIS3DH {
public:
  // I2C constructor: caller must have called Wire.begin()
  LIS3DH(TwoWire &wire = Wire, uint8_t address = 0x18);

  // 4-wire SPI constructor: caller must have called SPI.begin(); caller provides SPISettings
  LIS3DH(SPIClass &spiBus, uint8_t csPin, const SPISettings &settings);

  // Primary initialization: verify device and apply safe defaults
  bool begin();

  // Identity check
  bool whoAmI();

  // Reboot memory (BOOT bit), wait ~5 ms
  bool rebootMemory();

  // Measurement configuration and data
  bool configureMeasurement(const MeasurementConfig &config);
  bool readAcceleration(AccelerationSample &sample);
  bool readAccelerationStatus(AccelerationStatus &status);
  bool setBlockDataUpdate(bool enabled);
  bool setEndian(bool bigEndian);

  // Auxiliary ADC and filter
  bool configureAuxiliary(bool adcEnabled, bool temperatureEnabled);
  bool readAuxiliary(AuxiliaryData &data);
  bool configureHighPass(const HighPassConfig &config);
  bool setReference(uint8_t value);
  // NOTE: reading REFERENCE may reset HPF when HPM mode 00 is selected (hardware side effect)
  bool readReference(uint8_t &value);
  bool setSdoPullupDisconnected(bool disconnected);

  // FIFO and event functions
  bool configureFifo(const FifoConfig &config);
  bool readFifoStatus(FifoStatus &status);
  bool readFifoSample(AccelerationSample &sample);
  bool resetFifo();
  bool configureInterrupt(const InterruptConfig &config);
  // reading INTx_SRC clears IA when latching is enabled (hardware side effect)
  bool readInterruptSource(InterruptEngine engine, InterruptSource &source);
  bool configureClick(const ClickConfig &config);
  // reading CLICK_SRC clears IA when LIR_Click is set (hardware side effect)
  bool readClickSource(ClickSource &source);
  // ACT_THS/ACT_DUR enable auto sleep/wake hardware behavior; mode fields may be ignored during low-power state
  bool configureActivity(uint8_t threshold, uint8_t duration, bool routeToInt2 = false);
  bool setSelfTest(SelfTestMode mode);
  bool setSpiThreeWire(bool enabled);

private:
  // Private transport helpers
  bool readRegisters(uint8_t reg, uint8_t *buffer, size_t count);
  bool writeRegisters(uint8_t reg, const uint8_t *buffer, size_t count);
  bool updateRegister(uint8_t reg, uint8_t mask, uint8_t value);

  // internal
  TwoWire * _wire = nullptr;
  uint8_t _i2c_addr = 0;
  SPIClass * _spi = nullptr;
  uint8_t _csPin = 0xFF;
  bool _isI2C = true;
  SPISettings _spiSettings = SPISettings();

  // cached measurement config
  MeasurementConfig _measConfig;

  // small helpers
  uint8_t _read8(uint8_t reg);
  bool _write8(uint8_t reg, uint8_t value);
};

