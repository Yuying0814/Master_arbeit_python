/*
Public header file: class interface, register addresses, enums, constants, and documentation for all public APIs.
*/

#pragma once

// include_guard_and_includes: Header guard, includes and forward declarations.
#include <Arduino.h>

class TwoWire; // forward

// register_definitions_and_constants: Device register address constants, OTP/PMU/INT constants and timeout constants.
namespace BMM350Reg {
  static const uint8_t CHIP_ID = 0x00;
  static const uint8_t ERR_REG = 0x02;
  static const uint8_t PAD_CTRL = 0x03;
  static const uint8_t PMU_CMD_AGGR_SET = 0x04;
  static const uint8_t PMU_CMD_AXIS_EN = 0x05;
  static const uint8_t PMU_CMD = 0x06;
  static const uint8_t PMU_CMD_STATUS_0 = 0x07;
  static const uint8_t PMU_CMD_STATUS_1 = 0x08;
  static const uint8_t I3C_ERR = 0x09;
  static const uint8_t I2C_WDT_SET = 0x0A;
  static const uint8_t TRANS_DUCER_REV_ID = 0x0D;
  static const uint8_t INT_CTRL = 0x2E;
  static const uint8_t INT_CTRL_IBI = 0x2F;
  static const uint8_t INT_STATUS = 0x30;

  // Burst-read block (explicitly enumerated)
  static const uint8_t MAG_X_XLSB = 0x31;
  static const uint8_t MAG_X_LSB  = 0x32;
  static const uint8_t MAG_X_MSB  = 0x33;

  static const uint8_t MAG_Y_XLSB = 0x34;
  static const uint8_t MAG_Y_LSB  = 0x35;
  static const uint8_t MAG_Y_MSB  = 0x36;

  static const uint8_t MAG_Z_XLSB = 0x37;
  static const uint8_t MAG_Z_LSB  = 0x38;
  static const uint8_t MAG_Z_MSB  = 0x39;

  static const uint8_t TEMP_XLSB  = 0x3A;
  static const uint8_t TEMP_LSB   = 0x3B;
  static const uint8_t TEMP_MSB   = 0x3C;

  static const uint8_t SENSORTIME_XLSB = 0x3D;
  static const uint8_t SENSORTIME_LSB  = 0x3E;
  static const uint8_t SENSORTIME_MSB  = 0x3F;

  static const uint8_t OTP_CMD_REG = 0x50;
  static const uint8_t OTP_DATA_MSB_REG = 0x52;
  static const uint8_t OTP_DATA_LSB_REG = 0x53;
  static const uint8_t OTP_STATUS_REG = 0x55;
  static const uint8_t TMR_SELFTEST_USER = 0x60;
  static const uint8_t CTRL_USER = 0x61;
  static const uint8_t CMD = 0x7E;
}

// Known values
static const uint8_t BMM350_CHIP_ID = 0x33;
static const uint8_t OTP_BOOT_TERMINATE_VALUE = 0x80; // write to OTP_CMD_REG to end boot-phase

// PMU command encodings (PMU_CMD.pmu_cmd)
enum PMUCommand : uint8_t {
  PMU_SUSPEND = 0x00,
  PMU_NORMAL = 0x01,
  PMU_UPD_OAE = 0x02,
  PMU_FM = 0x03,
  PMU_FM_FAST = 0x04,
  PMU_FGR = 0x05,
  PMU_FGR_FAST = 0x06,
  PMU_BR = 0x07,
  PMU_BR_FAST = 0x08
};

// Timeout constants (caller may recompile driver to change values).
// OTP commands may require longer time; default conservative timeout.
static const uint32_t BMM350_OTP_CMD_TIMEOUT_MS = 500;
static const uint32_t BMM350_PMU_CMD_TIMEOUT_MS = 50;
static const uint32_t BMM350_FM_TIMEOUT_MS = 200; // forced measurement timeout
static const uint32_t BMM350_MAG_RESET_TIMEOUT_MS = 100;

// Notes:
// - The driver is I2C-only and uses TwoWire*. The driver never calls Wire.begin();
//   callers must initialize the Wire bus (e.g., Wire.begin()) before calling begin().
// - Timeouts are compile-time constants above and can be adjusted by recompiling the library.

// public_api_declarations: Public driver class and method declarations covering all device functions.
class BMM350 {
public:
  // Default constructor. Leaves bus uninitialized; caller must call begin() after Wire.begin().
  BMM350();

  // Initialize driver instance: set I2C address, verify CHIP_ID, run OTP load and terminate boot (BMM350_init).
  // wire may be nullptr to use &Wire.
  bool begin(uint8_t i2c_addr, TwoWire* wire = nullptr);

  // Perform documented soft-reset sequence via CMD register and wait for device boot and OTP readiness.
  bool softReset();

  // Explicitly re-run OTP read/load sequence and terminate boot-phase.
  bool reloadOTP();

  // Set device power mode (SUSPEND / NORMAL / FORCED variants).
  bool setPowerMode(uint8_t pmu_cmd);

  // Configure ODR and averaging by writing PMU_CMD_AGGR_SET and issuing UPD_OAE (0x02).
  bool setODRandPerformance(uint8_t odr, uint8_t avg);

  // Trigger a forced measurement (FM or FM_FAST)
  bool forcedMeasurement(bool fast = false);

  // Burst-read MAG/TEMP/SENSORTIME and return compensated floating-point results.
  // Optional outputs: temperature and sensortime. Pass nullptr if the caller does not require them.
  // Example: sensor.readMagnetometer(mx,my,mz, nullptr, nullptr);
  bool readMagnetometer(float& mx, float& my, float& mz, float* temperature, uint32_t* sensortime);

  // Read sensortime helper
  bool readSensorTime(uint32_t& sensortime);

  // Magnetic reset variants via PMU_CMD
  bool magneticReset(uint8_t pmu_cmd);

  // Run device self-test for requested axes and return pass/fail and delta outputs
  bool performSelfTest(bool axis_x, bool axis_y, bool positive, float& delta_x, float& delta_y);

  // Configure INT_CTRL and INT_CTRL_IBI
  bool configureInterrupt(bool drdy_enable, bool latched, bool active_high, bool push_pull);

  // Write PAD_CTRL.drv (0..7)
  bool setPadDrive(uint8_t drv);

  // Enable or disable X/Y/Z axes via PMU_CMD_AXIS_EN
  bool enableAxes(bool en_x, bool en_y, bool en_z);

  // Write CTRL_USER.cfg_sens_tim_aon (writable only in SUSPEND)
  bool setCtrlUser(bool sens_tim_aon);

  // Configure I2C watchdog
  bool setI2CWatchdog(bool enable, bool long_timeout);

  // Read ERR_REG and return the raw byte. Reading clears the register.
  uint8_t readErrorAndClear();

  // Low-level read helper: read len bytes starting at reg. If raw_read==false, driver discards device-specific dummy bytes for known multi-byte blocks.
  bool readRegister(uint8_t reg, uint8_t* buf, size_t len, bool raw_read = false);

  // Low-level write helper
  bool writeRegister(uint8_t reg, const uint8_t* buf, size_t len);

  // Advanced OTP direct access (DIR_READ / DIR_PRGM flows). Returns data_out for read operations.
  bool otpDirectAccess(uint8_t otp_cmd, uint8_t word_addr, uint16_t& data_out);

private:
  // private_helpers_and_internal_types: Private helper declarations and internal data structures.
  TwoWire* _wire;
  uint8_t _i2caddr;
  bool _otp_loaded;

  // Placeholder for compensation/trim values loaded from OTP.
  struct TrimData {
    // Actual trim fields (gain, offset, temp_coefs, etc.) are device-specific and populated by reloadOTP().
    // Fields are intentionally generic; compensation math is implemented in the .cpp file and may be
    // adjusted as datasheet clarification becomes available.
    bool valid;
    // Example placeholders
    float gain_x;
    float gain_y;
    float gain_z;
    float offset_x;
    float offset_y;
    float offset_z;
    float temp_sens;
  } _trim;

  // Small internal helpers
  bool _waitForPmuCmdComplete(uint32_t timeout_ms = BMM350_PMU_CMD_TIMEOUT_MS);
  bool _burstReadDiscardLeading(uint8_t start_reg, uint8_t* buf, size_t len);
};

