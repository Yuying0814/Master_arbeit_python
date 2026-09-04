/*
Header file: class declaration, register defines, enums, public APIs and documentation.
*/

#pragma once

// Include guards and includes: Include Arduino core and transport headers
// Include guards and includes: Arduino.h, Wire.h, SPI.h
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

// Register address and bitfield definitions: All registers from provided register_map
// Register address and bitfield definitions: NOTE: SPI framing, self-test formula and accelerometer sensitivity references
// NOTE: SPI framing and timing (MSB R/W in first byte, modes 0/3, f_spc <= 8 MHz) taken from datasheet retrieval pages: pages 10, 12 and 25.
// NOTE: SELF_TEST ST_OTP/ST_code equations taken from datasheet retrieval page: page 29.
// NOTE: Accelerometer sensitivity values (LSB/g) taken from datasheet retrieval page: page 7.
namespace IAM20680_REG {
  static const uint8_t SELF_TEST_X_GYRO = 0x00;
  static const uint8_t SELF_TEST_Y_GYRO = 0x01;
  static const uint8_t SELF_TEST_Z_GYRO = 0x02;
  static const uint8_t SELF_TEST_X_ACCEL = 0x0D;
  static const uint8_t SELF_TEST_Y_ACCEL = 0x0E;
  static const uint8_t SELF_TEST_Z_ACCEL = 0x0F;

  static const uint8_t XG_OFFS_USRH = 0x13;
  static const uint8_t XG_OFFS_USRL = 0x14;
  static const uint8_t YG_OFFS_USRH = 0x15;
  static const uint8_t YG_OFFS_USRL = 0x16;
  static const uint8_t ZG_OFFS_USRH = 0x17;
  static const uint8_t ZG_OFFS_USRL = 0x18;

  static const uint8_t SMPLRT_DIV = 0x19;
  static const uint8_t CONFIG = 0x1A;
  static const uint8_t GYRO_CONFIG = 0x1B;
  static const uint8_t ACCEL_CONFIG = 0x1C;
  static const uint8_t ACCEL_CONFIG2 = 0x1D;
  static const uint8_t LP_MODE_CFG = 0x1E;

  static const uint8_t ACCEL_WOM_X_THR = 0x20;
  static const uint8_t ACCEL_WOM_Y_THR = 0x21;
  static const uint8_t ACCEL_WOM_Z_THR = 0x22;

  static const uint8_t FSYNC_INT = 0x36;
  static const uint8_t INT_PIN_CFG = 0x37;
  static const uint8_t INT_ENABLE = 0x38;
  static const uint8_t INT_STATUS = 0x3A;

  static const uint8_t ACCEL_XOUT_H = 0x3B;
  static const uint8_t ACCEL_XOUT_L = 0x3C;
  static const uint8_t ACCEL_YOUT_H = 0x3D;
  static const uint8_t ACCEL_YOUT_L = 0x3E;
  static const uint8_t ACCEL_ZOUT_H = 0x3F;
  static const uint8_t ACCEL_ZOUT_L = 0x40;

  static const uint8_t TEMP_OUT_H = 0x41;
  static const uint8_t TEMP_OUT_L = 0x42;

  static const uint8_t GYRO_XOUT_H = 0x43;
  static const uint8_t GYRO_XOUT_L = 0x44;
  static const uint8_t GYRO_YOUT_H = 0x45;
  static const uint8_t GYRO_YOUT_L = 0x46;
  static const uint8_t GYRO_ZOUT_H = 0x47;
  static const uint8_t GYRO_ZOUT_L = 0x48;

  static const uint8_t SIGNAL_PATH_RESET = 0x68;
  static const uint8_t ACCEL_INTEL_CTRL = 0x69;
  static const uint8_t USER_CTRL = 0x6A;
  static const uint8_t PWR_MGMT_1 = 0x6B;
  static const uint8_t PWR_MGMT_2 = 0x6C;

  static const uint8_t XA_OFFSET_H = 0x77;
  static const uint8_t XA_OFFSET_L = 0x78;
  static const uint8_t YA_OFFSET_H = 0x7A;
  static const uint8_t YA_OFFSET_L = 0x7B;
  static const uint8_t ZA_OFFSET_H = 0x7D;
  static const uint8_t ZA_OFFSET_L = 0x7E;

  static const uint8_t WHO_AM_I = 0x75;
}

// Public types and enums: Self-test and power-mode helpers
// Public types and enums: ...

/** SelfTestOtpMode: interpretation of the value stored in SELF_TEST_* registers.
 *  - ST_CODE: registers contain ST_code (default). Use ST_OTP = (2620 / 2^FS) * 1.01^(ST_code-1)
 *  - ST_FAC: registers contain ST_FAC; compute ST_code via
 *      ST_code = round(log(ST_FAC/(2620 / 2^FS)) / log(1.01)) + 1
 *  NOTE: Retrieval pages (page 29) describe both ST_OTP and ST_code equations but do not
 *  unambiguously declare which encoding is stored in SELF_TEST_*. This enum lets the caller
 *  choose the interpretation. Default is ST_CODE (assumed by the driver).
 *  Source: datasheet retrieval page 29.
 */
enum class SelfTestOtpMode {
  ST_CODE = 0,
  ST_FAC = 1
};

/** SelfTestOptions: configure how selfTest() interprets OTP and tolerance. */
struct SelfTestOptions {
  SelfTestOtpMode mode = SelfTestOtpMode::ST_CODE; //!< default assume SELF_TEST_* contains ST_code
  float tolerance_fraction = 0.30f; //!< default pass/fail tolerance (30% of expected ST_OTP)
};

/** PowerMode helpers: small enum for convenience when toggling modes (public APIs below) */
enum class PowerMode { NORMAL = 0, SLEEP = 1 };

// Public class IAM20680HV declaration
class IAM20680HV {
public:
  // Public types
  /** SensorData: raw sensor snapshot container. All fields are signed 16-bit. */
  struct SensorData {
    int16_t ax; int16_t ay; int16_t az;
    int16_t temp; // raw
    int16_t gx; int16_t gy; int16_t gz;
  };

  /** SelfTestResult: per-axis measured/expected and pass flags */
  struct AxisTest {
    float measured; // measured self-test response in LSB
    float expected; // OTP-derived expected response in LSB
    bool pass;      // true if within threshold
  };
  struct SelfTestResult {
    AxisTest accelX, accelY, accelZ;
    AxisTest gyroX, gyroY, gyroZ;
  };

  /** Default constructor; does not initialize any bus. */
  IAM20680HV();

  /**
   * beginI2C: Initialize driver to use I2C transport. Does not call Wire.begin().
   * Caller must call Wire.begin() before this.
   * @param wire Reference to TwoWire instance (e.g. Wire).
   * @param address 7-bit device address to use.
   * @return true on success (WHO_AM_I verified and device ready).
   */
  bool beginI2C(TwoWire &wire, uint8_t address);

  /**
   * beginSPI: Initialize driver to use SPI transport. Does not call SPI.begin().
   * Caller must call SPI.begin() before this.
   * Default SPISettings: 8 MHz, MSBFIRST, SPI_MODE0 (datasheet recommended modes 0/3; max 8 MHz).
   * Overload allows caller to pass custom SPISettings.
   * @param csPin chip-select pin to use (active low).
   * @param spi reference to SPIClass instance (default SPI)
   * @param settings SPISettings to use (optional; default uses datasheet-derived 8 MHz/Mode0)
   * @return true on success (WHO_AM_I verified and device ready).
   * @note SPI framing: first byte MSB = R/W (1=read,0=write), next 7 bits = register address.
   *       Data are MSB-first and latched on SPC rising edge. (datasheet pages 10,12,25)
   */
  bool beginSPI(uint8_t csPin, SPIClass &spi = SPI, SPISettings settings = SPISettings(8000000UL, MSBFIRST, SPI_MODE0));

  /** Soft reset: set DEVICE_RESET and wait until it auto-clears. Returns true on success. */
  bool softReset();

  /** whoAmI: read WHO_AM_I register and return raw byte. 0xFF indicates bus/read error. */
  uint8_t whoAmI();

  /** setClockSource: write CLKSEL[2:0] in PWR_MGMT_1. */
  bool setClockSource(uint8_t clksel);

  /** disableI2CInterface: set or clear USER_CTRL.I2C_IF_DIS. */
  bool disableI2CInterface(bool disable);

  /** setGyroRange: set GYRO_CONFIG.FS_SEL (0..3). */
  bool setGyroRange(uint8_t fs_sel);
  /** getGyroRange: read current FS_SEL value (0..3). */
  uint8_t getGyroRange();

  /** setAccelRange: set ACCEL_CONFIG.ACCEL_FS_SEL (0..3). */
  bool setAccelRange(uint8_t fs_sel);
  uint8_t getAccelRange();

  bool setSMPLRT_DIV(uint8_t div);
  bool setDLPF(uint8_t dlpf_cfg);

  // Sensor reads
  bool readRawAccel(int16_t &ax, int16_t &ay, int16_t &az);
  bool readRawGyro(int16_t &gx, int16_t &gy, int16_t &gz);
  bool readRawTemp(int16_t &t);
  bool readSensor(SensorData &data);

  float convertGyroRawToDPS(int16_t raw);
  float convertAccelRawToG(int16_t raw);
  bool readTemperatureC(float &celsius);

  // Interrupts & WoM
  bool configureInterruptPins(uint8_t cfg);
  bool setInterruptEnable(uint8_t mask);
  uint8_t readIntStatus();
  bool configureWakeOnMotion(uint8_t thr_x, uint8_t thr_y, uint8_t thr_z,
                             uint8_t accel_intel_ctrl, uint8_t lp_mode_cfg,
                             bool enter_cycle);

  // Offsets & signal path
  bool setGyroOffsets(int16_t x, int16_t y, int16_t z);
  bool setAccelOffsets(int16_t x, int16_t y, int16_t z);
  bool resetSignalPath(bool resetAccel, bool resetTemp, bool clearAllSensorRegisters);

  // Self-test
  /**
   * setSelfTestOptions: configure how the driver interprets SELF_TEST_* OTP registers and tolerance.
   * Default: assume SELF_TEST_* contains ST_code (SelfTestOtpMode::ST_CODE) and 30% tolerance.
   */
  void setSelfTestOptions(const SelfTestOptions &opts);

  /** Run self-test sequence and populate result. Returns true if procedure completed and result populated.
   *  The pass flags reflect per-axis comparisons using configured tolerance and interpretation mode.
   */
  bool selfTest(SelfTestResult &result);

  // Power-mode helper APIs (public): convenience wrappers for PWR_MGMT_1 / PWR_MGMT_2 settings
  /** setSleep: true -> set PWR_MGMT_1.SLEEP, false -> clear */
  bool setSleep(bool enable);
  /** setAccelCycle: set or clear PWR_MGMT_1.ACCEL_CYCLE */
  bool setAccelCycle(bool enable);
  /** setGyroStandbyMask: set STBY_XG/STBY_YG/STBY_ZG bits in PWR_MGMT_2 according to mask bits 2..0 */
  bool setGyroStandbyMask(uint8_t mask);
  /** setPowerModeLowNoise: convenience to enter/leave low-noise mode (clear cycle bits and ensure sensors enabled) */
  bool setPowerModeLowNoise(bool enable);

  // Low-level bus access
  uint8_t readRegister(uint8_t reg);
  bool writeRegister(uint8_t reg, uint8_t value);
  bool readRegisters(uint8_t reg, uint8_t *buf, size_t len);
  bool writeRegisters(uint8_t reg, const uint8_t *buf, size_t len);

private:
  // Private members and helpers
  enum Transport { TRANSPORT_NONE = 0, TRANSPORT_I2C = 1, TRANSPORT_SPI = 2 };
  Transport _trans = TRANSPORT_NONE;

  // I2C
  TwoWire *_wire = nullptr;
  uint8_t _i2caddr = 0;

  // SPI
  SPIClass *_spi = nullptr;
  uint8_t _csPin = 255;
  // Default SPISettings per datasheet: max 8 MHz, modes 0/3 recommended. Default using mode0.
  SPISettings _spiSettings{8000000UL, MSBFIRST, SPI_MODE0};

  // cached settings
  uint8_t _gyro_fs_sel = 0; // 0..3
  uint8_t _accel_fs_sel = 0; // 0..3

  // Self-test options storage
  SelfTestOptions _selfTestOpts;

  // low-level helpers
  bool _i2cRead(uint8_t reg, uint8_t *buf, size_t len);
  bool _i2cWrite(uint8_t reg, const uint8_t *buf, size_t len);
  bool _spiRead(uint8_t reg, uint8_t *buf, size_t len);
  bool _spiWrite(uint8_t reg, const uint8_t *buf, size_t len);

  bool _pollBitUntilCleared(uint8_t reg, uint8_t mask, uint32_t timeout_ms);
};

