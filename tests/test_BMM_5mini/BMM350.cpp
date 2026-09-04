/*
Source file: implements the public API, low-level I2C transactions, OTP load and compensation math placeholders, PMU command sequencing and status polling.
*/

// includes_and_private_constants: Include BMM350.h, Wire.h and local static helpers; define private timeout constants.
#include "BMM350.h"
#include <Wire.h>

// Private constants
static const uint8_t BURST_BLOCK_START = BMM350Reg::MAG_X_XLSB; // 0x31
static const size_t BURST_BLOCK_LEN = (size_t)(BMM350Reg::SENSORTIME_MSB - BMM350Reg::MAG_X_XLSB + 1);

// constructor_and_begin_impl: Implement constructor and begin()
BMM350::BMM350()
  : _wire(nullptr), _i2caddr(0), _otp_loaded(false) {
  _trim.valid = false;
}

bool BMM350::begin(uint8_t i2c_addr, TwoWire* wire) {
  _wire = wire ? wire : &Wire;
  _i2caddr = i2c_addr;

  // Probe CHIP_ID
  uint8_t id = 0;
  if (!readRegister(BMM350Reg::CHIP_ID, &id, 1, true)) return false;
  if (id != BMM350_CHIP_ID) return false;

  // Run OTP load sequence
  if (!reloadOTP()) return false;

  // Terminate boot-phase by writing documented value to OTP_CMD_REG
  uint8_t term = OTP_BOOT_TERMINATE_VALUE;
  if (!writeRegister(BMM350Reg::OTP_CMD_REG, &term, 1)) {
    return false;
  }

  // Allow some time for device to leave boot OTP-accessible state and for CRST charge.
  delay(10);

  _otp_loaded = true;
  return true;
}

bool BMM350::softReset() {
  // Write CMD = 0xB6 followed by 0x00
  uint8_t cmd_reset = 0xB6;
  if (!writeRegister(BMM350Reg::CMD, &cmd_reset, 1)) return false;
  uint8_t cmd_nop = 0x00;
  if (!writeRegister(BMM350Reg::CMD, &cmd_nop, 1)) return false;

  // Wait for CHIP_ID to reappear and for OTP_STATUS.otp_cmd_done to be set
  uint32_t start = millis();
  while (millis() - start < BMM350_OTP_CMD_TIMEOUT_MS) {
    uint8_t id = 0;
    if (readRegister(BMM350Reg::CHIP_ID, &id, 1, true) && id == BMM350_CHIP_ID) {
      // Wait for OTP_STATUS.otp_cmd_done==1
      uint8_t st = 0;
      if (readRegister(BMM350Reg::OTP_STATUS_REG, &st, 1, true)) {
        if (st & 0x01) return true;
      }
    }
    delay(5);
  }
  return false;
}

// otp_and_compensation_impl
bool BMM350::reloadOTP() {
  // This function performs a sequence of OTP DIR_READ commands across OTP words
  // required for sensor compensation. The exact number and encoding of trim words
  // is device-specific. Here we will read a small range of words as an example and
  // store placeholder trim values. Caller must call begin() to terminate boot-phase.

  // Wait until OTP_STATUS.otp_cmd_done==1 before issuing commands
  uint32_t start_wait = millis();
  while (millis() - start_wait < BMM350_OTP_CMD_TIMEOUT_MS) {
    uint8_t st = 0;
    if (!readRegister(BMM350Reg::OTP_STATUS_REG, &st, 1, true)) return false;
    if (st & 0x01) break;
    delay(5);
  }

  // Read a few OTP words with DIR_READ (encoding: otp_cmd bits in bits 5..7)
  // DIR_READ value from register_map: 0b001 -> 1
  // Compose OTP_CMD_REG: (otp_cmd << 5) | word_addr
  // We'll attempt to read word addresses 0..3 as example trim words.
  for (uint8_t word = 0; word < 4; ++word) {
    uint8_t cmd = (0x01 << 5) | (word & 0x1F);
    if (!writeRegister(BMM350Reg::OTP_CMD_REG, &cmd, 1)) return false;

    // Poll OTP_STATUS_REG.otp_cmd_done
    uint32_t start = millis();
    bool done = false;
    while (millis() - start < BMM350_OTP_CMD_TIMEOUT_MS) {
      uint8_t st = 0;
      if (!readRegister(BMM350Reg::OTP_STATUS_REG, &st, 1, true)) return false;
      if (st & 0x01) {
        // Check error bits [7:5]
        uint8_t err = (st >> 5) & 0x07;
        if (err != 0) {
          // OTP reported an error; abort
          return false;
        }
        done = true;
        break;
      }
      delay(2);
    }
    if (!done) return false;

    // Read data MSB/LSB
    uint8_t msb = 0, lsb = 0;
    if (!readRegister(BMM350Reg::OTP_DATA_MSB_REG, &msb, 1, true)) return false;
    if (!readRegister(BMM350Reg::OTP_DATA_LSB_REG, &lsb, 1, true)) return false;

    // Parse word into example trim storage (this is placeholder mapping)
    uint16_t word_val = ((uint16_t)msb << 8) | lsb;
    // Use simple heuristics to populate placeholders
    switch (word) {
      case 0:
        _trim.gain_x = 1.0f + ((int16_t)word_val) * 1e-5f;
        break;
      case 1:
        _trim.gain_y = 1.0f + ((int16_t)word_val) * 1e-5f;
        break;
      case 2:
        _trim.gain_z = 1.0f + ((int16_t)word_val) * 1e-5f;
        break;
      case 3:
        _trim.offset_x = ((int16_t)word_val) * 1e-2f;
        break;
      default:
        break;
    }
  }

  // Mark trim as valid. Note: full compensation table and formulas require datasheet detail
  // not present in structured register_map; compensation math is implemented as a placeholder.
  _trim.valid = true;
  return true;
}

bool BMM350::otpDirectAccess(uint8_t otp_cmd, uint8_t word_addr, uint16_t& data_out) {
  // Compose command byte and write
  uint8_t cmd = ((otp_cmd & 0x07) << 5) | (word_addr & 0x1F);
  if (!writeRegister(BMM350Reg::OTP_CMD_REG, &cmd, 1)) return false;

  // Poll OTP_STATUS_REG.otp_cmd_done
  uint32_t start = millis();
  bool done = false;
  while (millis() - start < BMM350_OTP_CMD_TIMEOUT_MS) {
    uint8_t st = 0;
    if (!readRegister(BMM350Reg::OTP_STATUS_REG, &st, 1, true)) return false;
    if (st & 0x01) {
      uint8_t err = (st >> 5) & 0x07;
      if (err != 0) return false;
      done = true;
      break;
    }
    delay(2);
  }
  if (!done) return false;

  uint8_t msb = 0, lsb = 0;
  if (!readRegister(BMM350Reg::OTP_DATA_MSB_REG, &msb, 1, true)) return false;
  if (!readRegister(BMM350Reg::OTP_DATA_LSB_REG, &lsb, 1, true)) return false;
  data_out = ((uint16_t)msb << 8) | lsb;
  return true;
}

// pmu_command_and_wait_impl
bool BMM350::_waitForPmuCmdComplete(uint32_t timeout_ms) {
  uint32_t start = millis();
  while (millis() - start < timeout_ms) {
    uint8_t st = 0;
    if (!readRegister(BMM350Reg::PMU_CMD_STATUS_0, &st, 1, true)) return false;
    // cmd_is_illegal bit 4
    if (st & (1 << 4)) return false; // illegal command
    // pmu_cmd_busy bit 0
    if (!(st & 0x01)) {
      // check ERR_REG.pmu_cmd_error
      uint8_t err = 0;
      // Previously the code treated read failure as success; treat it as an error now.
      if (!readRegister(BMM350Reg::ERR_REG, &err, 1, true)) return false; // read clears ERR_REG
      if (err & 0x01) return false; // pmu_cmd_error
      return true;
    }
    delay(2);
  }
  return false; // timeout
}

bool BMM350::setPowerMode(uint8_t pmu_cmd) {
  // If requesting FM or FM_FAST and current mode is NORMAL, ensure SUSPEND first
  if (pmu_cmd == PMU_FM || pmu_cmd == PMU_FM_FAST) {
    // transition to suspend first to ensure FM is accepted
    uint8_t sus = PMU_SUSPEND;
    if (!writeRegister(BMM350Reg::PMU_CMD, &sus, 1)) return false;
    if (!_waitForPmuCmdComplete()) return false;
  }

  uint8_t cmd = pmu_cmd & 0x0F;
  if (!writeRegister(BMM350Reg::PMU_CMD, &cmd, 1)) return false;
  return _waitForPmuCmdComplete(BMM350_PMU_CMD_TIMEOUT_MS);
}

bool BMM350::forcedMeasurement(bool fast) {
  // Ensure SUSPEND before forced measurement
  if (!setPowerMode(PMU_SUSPEND)) return false;

  uint8_t cmd = fast ? PMU_FM_FAST : PMU_FM;
  if (!writeRegister(BMM350Reg::PMU_CMD, &cmd, 1)) return false;

  // Wait for PMU command completion (conversion)
  if (!_waitForPmuCmdComplete(BMM350_FM_TIMEOUT_MS)) return false;

  // Check INT_STATUS.drdy_data_reg (bit 2)
  uint8_t intst = 0;
  if (!readRegister(BMM350Reg::INT_STATUS, &intst, 1, true)) return false;
  if (intst & (1 << 2)) return true;
  return false;
}

bool BMM350::magneticReset(uint8_t pmu_cmd) {
  // Caller provides FGR/BR/etc.
  if (!writeRegister(BMM350Reg::PMU_CMD, &pmu_cmd, 1)) return false;
  // Wait for completion including CRST recharge
  if (!_waitForPmuCmdComplete(BMM350_MAG_RESET_TIMEOUT_MS)) return false;
  // Allow a short recovery delay
  delay(5);
  return true;
}

// data_read_and_compensation_impl
bool BMM350::_burstReadDiscardLeading(uint8_t start_reg, uint8_t* buf, size_t len) {
  // Performs: write register pointer, then request len+2 bytes and discard first two dummy bytes
  if (!_wire) return false;
  _wire->beginTransmission(_i2caddr);
  _wire->write(start_reg);
  uint8_t res = _wire->endTransmission(false);
  if (res != 0) return false;

  size_t to_request = len + 2;
  size_t avail = _wire->requestFrom((int)_i2caddr, (int)to_request);
  if (avail < to_request) return false;

  // discard first two bytes
  (void)_wire->read();
  (void)_wire->read();
  for (size_t i = 0; i < len; ++i) {
    int v = _wire->read();
    if (v < 0) return false;
    buf[i] = (uint8_t)v;
  }
  return true;
}

// Updated signature: temperature and sensortime are optional outputs (pointers may be nullptr)
bool BMM350::readMagnetometer(float& mx, float& my, float& mz, float* temperature, uint32_t* sensortime) {
  // Ensure we have trim data
  if (!_trim.valid) return false;

  uint8_t raw[BURST_BLOCK_LEN];
  if (!_burstReadDiscardLeading(BURST_BLOCK_START, raw, BURST_BLOCK_LEN)) return false;

  // Registers order: XLSB, LSB, MSB for each axis and temperature and sensortime
  // Assemble 24-bit words then interpret. Device uses 21-bit samples internally; exact alignment and
  // compensation formulas are not fully specified in the provided register map. Here we assemble
  // 24-bit signed quantities and apply placeholder compensation using loaded trim values.

  auto assembleSigned24 = [&](size_t idx) -> int32_t {
    // idx points to XLSB at raw[idx], next raw[idx+1]=LSB, raw[idx+2]=MSB
    uint32_t v = ((uint32_t)raw[idx+2] << 16) | ((uint32_t)raw[idx+1] << 8) | (uint32_t)raw[idx];
    // sign-extend 24-bit
    if (v & 0x00800000) v |= 0xFF000000;
    return (int32_t)v;
  };

  int32_t raw_x = assembleSigned24(0);
  int32_t raw_y = assembleSigned24(3);
  int32_t raw_z = assembleSigned24(6);
  int32_t raw_t = assembleSigned24(9);

  // sensortime bytes at offsets 12..14 (XLSB, LSB, MSB)
  uint32_t st = ((uint32_t)raw[14] << 16) | ((uint32_t)raw[13] << 8) | (uint32_t)raw[12];

  // Apply placeholder compensation: scale by trim gains and subtract offsets
  float out_x = (float)raw_x * (_trim.gain_x != 0.0f ? _trim.gain_x : 1.0f) - _trim.offset_x;
  float out_y = (float)raw_y * (_trim.gain_y != 0.0f ? _trim.gain_y : 1.0f) - _trim.offset_y;
  float out_z = (float)raw_z * (_trim.gain_z != 0.0f ? _trim.gain_z : 1.0f) - _trim.offset_z;
  float out_t = (float)raw_t * (_trim.temp_sens != 0.0f ? _trim.temp_sens : 1.0f);

  mx = out_x;
  my = out_y;
  mz = out_z;
  if (temperature) *temperature = out_t;
  if (sensortime) *sensortime = st;

  // Note: checkForHighFieldAndReset is referenced in the plan but its logic is device-specific and not
  // present in the provided register map; caller may call magneticReset() if needed.
  return true;
}

bool BMM350::readSensorTime(uint32_t& sensortime) {
  uint8_t buf[3];
  if (!_burstReadDiscardLeading(BMM350Reg::SENSORTIME_XLSB, buf, 3)) return false;
  uint32_t st = ((uint32_t)buf[2] << 16) | ((uint32_t)buf[1] << 8) | (uint32_t)buf[0];
  sensortime = st;
  return true;
}

// interrupt_and_misc_impl
bool BMM350::configureInterrupt(bool drdy_enable, bool latched, bool active_high, bool push_pull) {
  uint8_t val = 0;
  if (drdy_enable) val |= (1 << 7);
  if (push_pull) val |= (1 << 2);
  if (active_high) val |= (1 << 1);
  if (latched) val |= (1 << 0);
  return writeRegister(BMM350Reg::INT_CTRL, &val, 1);
}

bool BMM350::setPadDrive(uint8_t drv) {
  drv &= 0x07;
  uint8_t cur = 0;
  // Read current PAD_CTRL, modify low 3 bits
  if (!readRegister(BMM350Reg::PAD_CTRL, &cur, 1, true)) return false;
  cur = (cur & 0xF8) | drv;
  return writeRegister(BMM350Reg::PAD_CTRL, &cur, 1);
}

bool BMM350::enableAxes(bool en_x, bool en_y, bool en_z) {
  if (!(en_x || en_y || en_z)) return false; // refuse to disable all axes
  // Ensure SUSPEND before writing
  if (!setPowerMode(PMU_SUSPEND)) return false;
  uint8_t val = (en_x ? 1 : 0) | (en_y ? 2 : 0) | (en_z ? 4 : 0);
  return writeRegister(BMM350Reg::PMU_CMD_AXIS_EN, &val, 1);
}

bool BMM350::setCtrlUser(bool sens_tim_aon) {
  // Must be in SUSPEND to write
  if (!setPowerMode(PMU_SUSPEND)) return false;
  uint8_t cur = 0;
  if (!readRegister(BMM350Reg::CTRL_USER, &cur, 1, true)) return false;
  if (sens_tim_aon) cur |= 0x01; else cur &= ~0x01;
  if (!writeRegister(BMM350Reg::CTRL_USER, &cur, 1)) return false;
  // verify
  uint8_t check = 0;
  if (!readRegister(BMM350Reg::CTRL_USER, &check, 1, true)) return false;
  return ((check & 0x01) == (sens_tim_aon ? 1 : 0));
}

bool BMM350::setI2CWatchdog(bool enable, bool long_timeout) {
  uint8_t val = (enable ? 1 : 0) | (long_timeout ? (1 << 1) : 0);
  return writeRegister(BMM350Reg::I2C_WDT_SET, &val, 1);
}

uint8_t BMM350::readErrorAndClear() {
  uint8_t v = 0;
  if (!readRegister(BMM350Reg::ERR_REG, &v, 1, true)) return 0;
  return v;
}

bool BMM350::setODRandPerformance(uint8_t odr, uint8_t avg) {
  // Write PMU_CMD_AGGR_SET and issue update command
  uint8_t val = ((avg & 0x03) << 4) | (odr & 0x0F);
  if (!writeRegister(BMM350Reg::PMU_CMD_AGGR_SET, &val, 1)) return false;
  // Issue UPD_OAE
  if (!setPowerMode(PMU_UPD_OAE)) return false;
  // Wait for data-ready after settings in caller context (not implemented here). Return true if no error.
  return true;
}

bool BMM350::performSelfTest(bool axis_x, bool axis_y, bool positive, float& delta_x, float& delta_y) {
  // Ensure not both positive and negative asserted
  // Caller requests: run baseline in FORCED, then enable st_p/st_n and axes and run another FORCED.
  delta_x = 0.0f; delta_y = 0.0f;

  if (!setPowerMode(PMU_SUSPEND)) return false;

  // Prepare self-test register
  uint8_t reg = 0;
  if (axis_y) reg |= (1 << 4);
  if (axis_x) reg |= (1 << 3);
  if (positive) reg |= (1 << 2); else reg |= (1 << 1);
  reg |= (1 << 0); // enable internal current generator

  // Read baseline
  if (!forcedMeasurement(false)) return false;
  float bx=0, by=0, bz=0, bt=0; uint32_t st=0;
  if (!readMagnetometer(bx, by, bz, &bt, &st)) return false;

  // Enable self-test
  if (!writeRegister(BMM350Reg::TMR_SELFTEST_USER, &reg, 1)) return false;
  // Trigger forced
  if (!forcedMeasurement(false)) return false;
  float ax=0, ay=0, az=0, at=0;
  if (!readMagnetometer(ax, ay, az, &at, &st)) return false;

  if (axis_x) delta_x = ax - bx;
  if (axis_y) delta_y = ay - by;

  // Basic pass threshold example (device doc mentions ~130 uT). Use conservative check.
  bool pass = true;
  if (axis_x && fabs(delta_x) < 100.0f) pass = false;
  if (axis_y && fabs(delta_y) < 100.0f) pass = false;
  return pass;
}

// Low-level read/write helpers
bool BMM350::readRegister(uint8_t reg, uint8_t* buf, size_t len, bool raw_read) {
  if (!_wire) return false;
  // Special handling: for multi-byte data block 0x31..0x3F, default behavior discards two leading dummy bytes
  const uint8_t block_start = BMM350Reg::MAG_X_XLSB;
  const uint8_t block_end = BMM350Reg::SENSORTIME_MSB;
  if (!raw_read && reg >= block_start && (uint8_t)(reg + (uint8_t)(len - 1)) <= block_end) {
    return _burstReadDiscardLeading(reg, buf, len);
  }

  _wire->beginTransmission(_i2caddr);
  _wire->write(reg);
  uint8_t r = _wire->endTransmission(false);
  if (r != 0) return false;
  size_t avail = _wire->requestFrom((int)_i2caddr, (int)len);
  if (avail < len) return false;
  for (size_t i = 0; i < len; ++i) {
    int v = _wire->read();
    if (v < 0) return false;
    buf[i] = (uint8_t)v;
  }
  return true;
}

bool BMM350::writeRegister(uint8_t reg, const uint8_t* buf, size_t len) {
  if (!_wire) return false;
  _wire->beginTransmission(_i2caddr);
  _wire->write(reg);
  for (size_t i = 0; i < len; ++i) _wire->write(buf[i]);
  uint8_t res = _wire->endTransmission();
  return (res == 0);
}

