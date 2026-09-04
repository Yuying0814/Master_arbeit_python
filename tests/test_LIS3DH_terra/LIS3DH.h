/*
LIS3DH class declaration, data types, register constants, and documented APIs.
*/

#pragma once

// Includes and public types: Arduino, Wire, SPI includes; interface/mode/range/FIFO/event enums and sample/status/config structures.
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

// I2C 7-bit default addresses
#define LIS3DH_I2C_ADDR_SA0_LOW  0x18
#define LIS3DH_I2C_ADDR_SA0_HIGH 0x19

namespace lis3dh {

// Register addresses (from register map)
static const uint8_t REG_STATUS_REG_AUX = 0x07;
static const uint8_t REG_OUT_ADC1_L = 0x08; // multi
static const uint8_t REG_OUT_ADC1_H = 0x09;
static const uint8_t REG_OUT_ADC2_L = 0x0A;
static const uint8_t REG_OUT_ADC2_H = 0x0B;
static const uint8_t REG_OUT_ADC3_L = 0x0C;
static const uint8_t REG_OUT_ADC3_H = 0x0D;
static const uint8_t REG_WHO_AM_I = 0x0F; // R, expected 0x33
static const uint8_t REG_CTRL_REG0 = 0x1E; // SDO_PU_DISC at bit7
static const uint8_t REG_TEMP_CFG_REG = 0x1F;
static const uint8_t REG_CTRL_REG1 = 0x20;
static const uint8_t REG_CTRL_REG2 = 0x21;
static const uint8_t REG_CTRL_REG3 = 0x22;
static const uint8_t REG_CTRL_REG4 = 0x23;
static const uint8_t REG_CTRL_REG5 = 0x24;
static const uint8_t REG_CTRL_REG6 = 0x25;
static const uint8_t REG_REFERENCE = 0x26;
static const uint8_t REG_STATUS_REG = 0x27;
static const uint8_t REG_OUT_X_L = 0x28; // through 0x2D
static const uint8_t REG_FIFO_CTRL_REG = 0x2E;
static const uint8_t REG_FIFO_SRC_REG = 0x2F;
static const uint8_t REG_INT1_CFG = 0x30;
static const uint8_t REG_INT1_SRC = 0x31;
static const uint8_t REG_INT1_THS = 0x32;
static const uint8_t REG_INT1_DURATION = 0x33;
static const uint8_t REG_INT2_CFG = 0x34;
static const uint8_t REG_INT2_SRC = 0x35;
static const uint8_t REG_INT2_THS = 0x36;
static const uint8_t REG_INT2_DURATION = 0x37;
static const uint8_t REG_CLICK_CFG = 0x38;
static const uint8_t REG_CLICK_SRC = 0x39;
static const uint8_t REG_CLICK_THS = 0x3A;
static const uint8_t REG_TIME_LIMIT = 0x3B;
static const uint8_t REG_TIME_LATENCY = 0x3C;
static const uint8_t REG_TIME_WINDOW = 0x3D;
static const uint8_t REG_ACT_THS = 0x3E;
static const uint8_t REG_ACT_DUR = 0x3F;

// Simple enums and structs used by the API
enum class Transport { I2C, SPI };

enum class SelfTestMode : uint8_t { Disabled = 0, ST0 = 1, ST1 = 2 };

enum class InterruptPin : uint8_t { INT1 = 0, INT2 = 1 };

struct MeasurementConfig {
  uint8_t odr_code; // ODR bits [7:4] value (4-bit code as in datasheet)
  bool lp; // LPen bit
  bool xen;
  bool yen;
  bool zen;
  uint8_t fs; // FS[1:0]
  bool hr; // HR bit
  bool bdu; // BDU bit
  bool ble; // BLE bit
};

struct Acceleration {
  int16_t x_counts;
  int16_t y_counts;
  int16_t z_counts;
  float x_g;
  float y_g;
  float z_g;
};

struct AccelerationStatus {
  uint8_t status_byte; // raw STATUS_REG
};

struct AuxiliaryData {
  int16_t adc1_counts;
  int16_t adc2_counts;
  int16_t adc3_counts;
  uint8_t status_aux; // STATUS_REG_AUX
};

struct FifoConfig {
  bool enable;
  uint8_t mode; // FM bits 0..3 mapping: 0=Bypass,1=FIFO,2=Stream,3=Stream-to-FIFO
  uint8_t watermark; // 0..31
  bool trigger_int2; // TR bit
};

struct FifoStatus {
  bool wtm;
  bool overrun;
  bool empty;
  uint8_t level; // FSS [4:0]
};

struct HighPassConfig {
  uint8_t hpm; // HPM[1:0]
  uint8_t hpcf; // HPCF[2:1]
  bool fds;
  bool hp_click;
  bool hp_ia2;
  bool hp_ia1;
};

struct InterruptConfig {
  uint8_t cfg; // raw INTx_CFG content convenience
  uint8_t ths; // threshold
  uint8_t dur; // duration
  bool latch;
};

struct InterruptSource {
  uint8_t srcbyte; // raw INTx_SRC
};

struct InterruptRouting {
  uint8_t ctrl3; // raw CTRL_REG3
  uint8_t ctrl6; // raw CTRL_REG6
};

struct ClickConfig {
  uint8_t cfg; // raw CLICK_CFG
  uint8_t ths; // CLICK_THS
  uint8_t tlimit;
  uint8_t tlatency;
  uint8_t twindow;
};

struct ClickSource {
  uint8_t src; // CLICK_SRC
};

// LIS3DH class declaration
class LIS3DH {
public:
  // Construct an I2C-backed driver without starting the bus.
  LIS3DH(TwoWire &wire = Wire, uint8_t address = LIS3DH_I2C_ADDR_SA0_HIGH);

  // Construct a 4-wire hardware-SPI-backed driver without starting SPI.
  LIS3DH(SPIClass &spi, uint8_t csPin);

  // Verify identity and apply documented default measurement configuration.
  bool begin();

  // Read WHO_AM_I and test for LIS3DH identity.
  bool isConnected();

  // Issue BOOT and wait the documented 5 ms reload interval.
  bool rebootMemory();

  // Measurement configuration and data
  bool configureMeasurement(const MeasurementConfig &config);
  bool getMeasurementConfig(MeasurementConfig &config);
  bool readAcceleration(Acceleration &sample);
  bool readAccelerationStatus(AccelerationStatus &status);

  // ADC / temperature
  bool configureAuxiliary(bool adcEnabled, bool temperatureEnabled);
  bool readAuxiliary(AuxiliaryData &data);

  // Self-test
  bool setSelfTest(SelfTestMode mode);

  // FIFO and filter configuration
  bool configureFifo(const FifoConfig &config);
  bool getFifoStatus(FifoStatus &status);
  bool readFifo(Acceleration *samples, uint8_t capacity, uint8_t &count);
  bool clearFifo(const FifoConfig &config);
  bool configureHighPassFilter(const HighPassConfig &config);
  bool setReference(uint8_t value);
  bool readReference(uint8_t &value);

  // Interrupt / click / activity
  bool configureInterruptGenerator(InterruptPin interrupt, const InterruptConfig &config);
  bool readInterruptSource(InterruptPin interrupt, InterruptSource &source);
  bool configureInterruptRouting(const InterruptRouting &routing);
  bool configureClick(const ClickConfig &config);
  bool readClickSource(ClickSource &source);
  bool configureActivity(uint8_t threshold, uint8_t duration);

  // Advanced mapped register access
  bool readRegister(uint8_t reg, uint8_t &value);
  bool writeRegister(uint8_t reg, uint8_t value);
  bool setSa0PullupDisconnected(bool disconnect);

private:
  // Private transport and conversion helpers
  bool readBytes(uint8_t reg, uint8_t *data, uint8_t length);
  bool writeBytes(uint8_t reg, const uint8_t *data, uint8_t length);

  // Internal helpers
  Transport transport() const { return _transport; }
  TwoWire *_wire = nullptr;
  SPIClass *_spi = nullptr;
  uint8_t _i2c_address = 0x18;
  uint8_t _cs_pin = 255;
  Transport _transport = Transport::I2C;
};

} // namespace lis3dh

using lis3dh::LIS3DH;
using lis3dh::MeasurementConfig;
using lis3dh::Acceleration;
using lis3dh::AccelerationStatus;
using lis3dh::AuxiliaryData;
using lis3dh::SelfTestMode;
using lis3dh::FifoConfig;
using lis3dh::FifoStatus;
using lis3dh::HighPassConfig;
using lis3dh::InterruptPin;
using lis3dh::InterruptConfig;
using lis3dh::InterruptSource;
using lis3dh::InterruptRouting;
using lis3dh::ClickConfig;
using lis3dh::ClickSource;

