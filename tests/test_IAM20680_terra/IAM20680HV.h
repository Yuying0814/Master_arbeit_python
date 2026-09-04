/*
Public Arduino API, configuration enums, data structures, and private transport/register definitions.
*/

#pragma once

// Includes and public types: Include Arduino, Wire, and SPI declarations; define transport, range, filter, interrupt, WoM, vector, raw-data, and status types.

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

// Public types for callers
enum class TransportType { I2C, SPI };

enum class ClockSource : uint8_t {
  INTERNAL = 0,
  AUTO = 1,
  AUTO2 = 2,
  AUTO3 = 3,
  AUTO4 = 4,
  AUTO5 = 5,
  INTERNAL_ALT = 6,
  STOP = 7
};

enum class GyroRange : uint8_t {
  DPS_125 = 0,
  DPS_250 = 1,
  DPS_500 = 2,
  DPS_1000 = 3
};

enum class AccelRange : uint8_t {
  G_2 = 0,
  G_4 = 1,
  G_8 = 2,
  G_16 = 3
};

struct Vector3f {
  float x;
  float y;
  float z;
};

struct Vector3i16 {
  int16_t x;
  int16_t y;
  int16_t z;
};

struct RawData {
  int16_t accel_x;
  int16_t accel_y;
  int16_t accel_z;
  int16_t temp;
  int16_t gyro_x;
  int16_t gyro_y;
  int16_t gyro_z;
};

struct InterruptPinConfig {
  bool activeLow;
  bool openDrain;
  bool latched;
  bool clearOnAnyRead;
  bool fsyncActiveLow;
  bool fsyncInterruptEnable;
  bool routeToInt2;
};

struct WakeOnMotionConfig {
  uint8_t thresholdX; // 4 mg/LSB
  uint8_t thresholdY;
  uint8_t thresholdZ;
  bool enableX;
  bool enableY;
  bool enableZ;
  bool intelModePreviousSample; // ACCEL_INTEL_MODE
  uint8_t accelWomOdrCtrl; // LP_MODE_CFG ACCEL_WOM_ODR_CTRL 4-bit
};

// Construction and lifecycle API: Expose bus-specific constructors and initialization, identity, and error-state APIs.
class IAM20680HV {
public:
  // I2C constructor
  IAM20680HV(TwoWire &wire, uint8_t address = 0x68);

  // SPI constructor
  IAM20680HV(SPIClass &spi, uint8_t csPin);

  // Primary initialization API
  bool begin();

  // Read device identity without changing state
  bool readWhoAmI(uint8_t &value);

  // Return last transport error code (0 = no error)
  uint8_t lastError() const { return _lastError; }

  // Power and configuration API
  bool softReset();
  bool setClockSource(ClockSource source);
  bool setSleep(bool enabled);
  bool setAxisStandby(uint8_t standbyMask);
  bool setSampleRateDivider(uint8_t divider);
  bool setGyroConfig(GyroRange range, uint8_t fchoice, uint8_t dlpf);
  bool setAccelConfig(AccelRange range, bool fchoiceBypass, uint8_t dlpf, uint8_t womAverage);
  bool configureFsync(uint8_t syncSelection, bool interruptEnabled, bool activeLow);
  bool resetSignalPaths(bool resetAccel, bool resetTemp);
  bool resetAndClearSensorPaths();

  // Data, interrupt, WoM, calibration, and self-test API
  bool readRawData(RawData &data);
  bool readScaledData(Vector3f &accelG, Vector3f &gyroDps, float &temperatureC);
  bool configureInterruptPin(const InterruptPinConfig &config);
  bool setInterruptEnables(uint8_t enableMask);
  bool readInterruptStatus(uint8_t &status); // read-to-clear
  bool readFsyncStatus(bool &active); // read-to-clear FSYNC_INT
  bool configureWakeOnMotion(const WakeOnMotionConfig &config);
  bool setGyroOffsets(const Vector3i16 &offset);
  bool setAccelOffsets(const Vector3i16 &offset);
  bool readSelfTestCodes(uint8_t gyroCodes[3], uint8_t accelCodes[3]);
  bool setSelfTest(uint8_t gyroAxisMask, uint8_t accelAxisMask);

private:
  // Private transport and register utilities
  bool readRegisters(uint8_t reg, uint8_t *buffer, size_t length);
  bool writeRegisters(uint8_t reg, const uint8_t *buffer, size_t length);
  bool updateRegister(uint8_t reg, uint8_t mask, uint8_t value);

  // Private helpers
  TransportType _transport;
  TwoWire *_wire = nullptr;
  SPIClass *_spi = nullptr;
  uint8_t _i2cAddr = 0x68;
  uint8_t _csPin = 255;
  volatile uint8_t _lastError = 0;

  // Cached configuration state
  GyroRange _gyroRange = GyroRange::DPS_125;
  AccelRange _accelRange = AccelRange::G_2;

  // Register constants (private)
  static constexpr uint8_t REG_SELF_TEST_X_GYRO = 0x00;
  static constexpr uint8_t REG_SELF_TEST_Y_GYRO = 0x01;
  static constexpr uint8_t REG_SELF_TEST_Z_GYRO = 0x02;
  static constexpr uint8_t REG_SELF_TEST_X_ACCEL = 0x0D; // Added: base accel self-test register

  static constexpr uint8_t REG_XG_OFFS_USRH = 0x13; // X gyro offset high
  static constexpr uint8_t REG_XG_OFFS_USRL = 0x14; // X gyro offset low
  static constexpr uint8_t REG_YG_OFFS_USRH = 0x15;
  static constexpr uint8_t REG_YG_OFFS_USRL = 0x16;
  static constexpr uint8_t REG_ZG_OFFS_USRH = 0x17;
  static constexpr uint8_t REG_ZG_OFFS_USRL = 0x18;

  static constexpr uint8_t REG_SMPLRT_DIV = 0x19;
  static constexpr uint8_t REG_CONFIG = 0x1A;
  static constexpr uint8_t REG_GYRO_CONFIG = 0x1B;
  static constexpr uint8_t REG_ACCEL_CONFIG = 0x1C;
  static constexpr uint8_t REG_ACCEL_CONFIG2 = 0x1D;
  static constexpr uint8_t REG_LP_MODE_CFG = 0x1E;

  static constexpr uint8_t REG_ACCEL_WOM_X_THR = 0x20;
  static constexpr uint8_t REG_ACCEL_WOM_Y_THR = 0x21;
  static constexpr uint8_t REG_ACCEL_WOM_Z_THR = 0x22;

  static constexpr uint8_t REG_FSYNC_INT = 0x36;
  static constexpr uint8_t REG_INT_PIN_CFG = 0x37;
  static constexpr uint8_t REG_INT_ENABLE = 0x38;
  static constexpr uint8_t REG_INT_STATUS = 0x3A;

  static constexpr uint8_t REG_ACCEL_XOUT_H = 0x3B; // 14-byte burst start
  static constexpr uint8_t REG_TEMP_OUT_H = 0x41;
  static constexpr uint8_t REG_GYRO_XOUT_H = 0x43;

  static constexpr uint8_t REG_SIGNAL_PATH_RESET = 0x68;
  static constexpr uint8_t REG_ACCEL_INTEL_CTRL = 0x69;
  static constexpr uint8_t REG_USER_CTRL = 0x6A;
  static constexpr uint8_t REG_PWR_MGMT_1 = 0x6B;
  static constexpr uint8_t REG_PWR_MGMT_2 = 0x6C;
  static constexpr uint8_t REG_WHO_AM_I = 0x75;

  static constexpr uint8_t REG_XA_OFFSET_H = 0x77;
  static constexpr uint8_t REG_XA_OFFSET_L = 0x78;
  static constexpr uint8_t REG_YA_OFFSET_H = 0x7A;
  static constexpr uint8_t REG_YA_OFFSET_L = 0x7B;
  static constexpr uint8_t REG_ZA_OFFSET_H = 0x7D;
  static constexpr uint8_t REG_ZA_OFFSET_L = 0x7E;

  // Temperature conversion constants from retrieved datasheet
  // Celsius = raw / 326.8 + 25.0
  static constexpr float TEMP_SENSITIVITY = 326.8f; // LSB/°C
  static constexpr float TEMP_ROOM_OFFSET = 0.0f; // °C offset at room

  // SPI default settings
  static const SPISettings _spiSettingsDefault;
};

