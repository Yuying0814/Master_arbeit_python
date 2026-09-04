/*
 * IAM20680HV driver verification sketch for the RP2040 test board.
 *
 * The sketch uses the public driver API only. It waits for one host command
 * (RUN_TEST) and prints one machine-readable result marker after the test.
 * SPI is intentionally not exercised because the target board has no SPI
 * connection to the sensor.
 */

#include <Arduino.h>
#include <Wire.h>
#include <math.h>
#include <string.h>

#include "IAM20680HV.h"

namespace {

constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 1;
constexpr uint8_t IAM20680_INT2_PIN = 16;
constexpr uint8_t IAM20680_INT1_PIN = 17;
constexpr uint8_t IAM20680_I2C_ADDRESS = 0x68;

constexpr uint32_t TEST_TIME_BUDGET_MS = 9000;

IAM20680HV sensor;
bool testStarted = false;
bool overallPass = true;
uint32_t testStartMillis = 0;
uint16_t checkCount = 0;
uint16_t failedCheckCount = 0;

void logLine(const char *message) {
  Serial.print("TEST_LOG: ");
  Serial.println(message);
}

bool recordCheck(const char *name, bool pass) {
  ++checkCount;
  if (!pass) {
    ++failedCheckCount;
    overallPass = false;
  }

  Serial.print("TEST_LOG: CHECK ");
  Serial.print(name);
  Serial.print("=");
  Serial.println(pass ? "PASS" : "FAIL");
  return pass;
}

bool recordIndexedCheck(const char *name, uint8_t index, bool pass) {
  ++checkCount;
  if (!pass) {
    ++failedCheckCount;
    overallPass = false;
  }

  Serial.print("TEST_LOG: CHECK ");
  Serial.print(name);
  Serial.print("[");
  Serial.print(index);
  Serial.print("]=");
  Serial.println(pass ? "PASS" : "FAIL");
  return pass;
}

void logHex(const char *name, uint8_t value) {
  Serial.print("TEST_LOG: ");
  Serial.print(name);
  Serial.print("=0x");
  if (value < 0x10) {
    Serial.print("0");
  }
  Serial.println(value, HEX);
}

void logInt16(const char *name, int16_t value) {
  Serial.print(name);
  Serial.print("=");
  Serial.print(value);
}

void logFloat(const char *name, float value, uint8_t decimals = 4) {
  Serial.print(name);
  Serial.print("=");
  Serial.print(value, decimals);
}

bool isFiniteFloat(float value) {
  return !isnan(value) && !isinf(value);
}

bool approximatelyEqual(float actual, float expected, float absoluteTolerance) {
  return isFiniteFloat(actual) && isFiniteFloat(expected) &&
         fabsf(actual - expected) <= absoluteTolerance;
}

bool timeBudgetAvailable(const char *phase) {
  if (static_cast<uint32_t>(millis() - testStartMillis) <= TEST_TIME_BUDGET_MS) {
    return true;
  }

  Serial.print("TEST_LOG: TIME_BUDGET_EXCEEDED phase=");
  Serial.println(phase);
  overallPass = false;
  return false;
}

void printSensorSnapshot(const IAM20680HV::SensorData &data, float temperatureC,
                         bool temperatureValid) {
  Serial.print("TEST_LOG: SENSOR_RAW ");
  logInt16("A_X", data.ax);
  Serial.print(" ");
  logInt16("A_Y", data.ay);
  Serial.print(" ");
  logInt16("A_Z", data.az);
  Serial.print(" ");
  logInt16("T", data.temp);
  Serial.print(" ");
  logInt16("G_X", data.gx);
  Serial.print(" ");
  logInt16("G_Y", data.gy);
  Serial.print(" ");
  logInt16("G_Z", data.gz);
  Serial.println();

  Serial.print("TEST_LOG: SENSOR_CONVERTED ");
  logFloat("A_X_G", sensor.convertAccelRawToG(data.ax));
  Serial.print(" ");
  logFloat("A_Y_G", sensor.convertAccelRawToG(data.ay));
  Serial.print(" ");
  logFloat("A_Z_G", sensor.convertAccelRawToG(data.az));
  Serial.print(" ");
  logFloat("G_X_DPS", sensor.convertGyroRawToDPS(data.gx));
  Serial.print(" ");
  logFloat("G_Y_DPS", sensor.convertGyroRawToDPS(data.gy));
  Serial.print(" ");
  logFloat("G_Z_DPS", sensor.convertGyroRawToDPS(data.gz));
  Serial.print(" ");
  if (temperatureValid) {
    logFloat("TEMP_C", temperatureC);
  } else {
    Serial.print("TEMP_C=READ_FAIL");
  }
  Serial.println();
}

bool initializeI2C() {
  bool beginOk = sensor.beginI2C(Wire, IAM20680_I2C_ADDRESS);
  recordCheck("beginI2C", beginOk);
  if (!beginOk) {
    logLine("I2C initialization failed; remaining hardware checks are aborted.");
    return false;
  }

  const uint8_t id = sensor.whoAmI();
  logHex("WHO_AM_I", id);
  recordCheck("whoAmI_is_0xFE", id == 0xFE);
  return true;
}

bool testLowLevelRegisterAccess() {
  logLine("Testing public register access APIs with safe configuration and output registers.");

  const uint8_t originalSampleDivider = sensor.readRegister(IAM20680_REG::SMPLRT_DIV);
  const uint8_t originalConfig = sensor.readRegister(IAM20680_REG::CONFIG);
  const bool savedConfiguration = originalSampleDivider != 0xFF && originalConfig != 0xFF;
  recordCheck("readRegister_configuration", savedConfiguration);
  if (!savedConfiguration) {
    return false;
  }

  uint8_t whoAmIBuffer[1] = {0};
  const bool readOne = sensor.readRegisters(IAM20680_REG::WHO_AM_I, whoAmIBuffer, 1);
  recordCheck("readRegisters_single_byte", readOne && whoAmIBuffer[0] == 0xFE);

  uint8_t outputBuffer[14] = {0};
  const bool readBurst = sensor.readRegisters(IAM20680_REG::ACCEL_XOUT_H, outputBuffer,
                                              sizeof(outputBuffer));
  recordCheck("readRegisters_sensor_burst", readBurst);

  const uint8_t accelConfig2 = sensor.readRegister(IAM20680_REG::ACCEL_CONFIG2);
  recordCheck("readRegister_accel_config2", accelConfig2 != 0xFF);
  logHex("ACCEL_CONFIG2", accelConfig2);

  const bool writeOne = sensor.writeRegister(IAM20680_REG::SMPLRT_DIV, 7);
  const uint8_t oneByteReadback = sensor.readRegister(IAM20680_REG::SMPLRT_DIV);
  recordCheck("writeRegister", writeOne && oneByteReadback == 7);

  uint8_t configurationPair[2] = {11, static_cast<uint8_t>(originalConfig)};
  const bool writeBurst = sensor.writeRegisters(IAM20680_REG::SMPLRT_DIV,
                                                configurationPair,
                                                sizeof(configurationPair));
  uint8_t pairReadback[2] = {0};
  const bool pairRead = sensor.readRegisters(IAM20680_REG::SMPLRT_DIV,
                                             pairReadback,
                                             sizeof(pairReadback));
  recordCheck("writeRegisters", writeBurst && pairRead && pairReadback[0] == 11 &&
                                  pairReadback[1] == originalConfig);

  uint8_t originalPair[2] = {originalSampleDivider, originalConfig};
  const bool restore = sensor.writeRegisters(IAM20680_REG::SMPLRT_DIV,
                                             originalPair,
                                             sizeof(originalPair));
  recordCheck("restore_register_access_configuration", restore);
  return restore;
}

bool testMeasurementConfiguration() {
  logLine("Testing clock, full-scale, sample-rate, filter, and conversion APIs.");

  const uint8_t originalPowerManagement1 = sensor.readRegister(IAM20680_REG::PWR_MGMT_1);
  const uint8_t originalGyroConfig = sensor.readRegister(IAM20680_REG::GYRO_CONFIG);
  const uint8_t originalAccelConfig = sensor.readRegister(IAM20680_REG::ACCEL_CONFIG);
  const uint8_t originalConfig = sensor.readRegister(IAM20680_REG::CONFIG);
  const uint8_t originalSampleDivider = sensor.readRegister(IAM20680_REG::SMPLRT_DIV);
  const bool saved = originalPowerManagement1 != 0xFF && originalGyroConfig != 0xFF &&
                     originalAccelConfig != 0xFF && originalConfig != 0xFF &&
                     originalSampleDivider != 0xFF;
  recordCheck("read_measurement_configuration", saved);
  if (!saved) {
    return false;
  }

  const uint8_t clockSources[] = {0, 1, 2, 3, 4, 5, 6};
  for (uint8_t i = 0; i < sizeof(clockSources); ++i) {
    const uint8_t requested = clockSources[i];
    const bool callOk = sensor.setClockSource(requested);
    const uint8_t value = sensor.readRegister(IAM20680_REG::PWR_MGMT_1);
    const bool readbackOk = value != 0xFF && (value & 0x07) == requested;
    recordIndexedCheck("setClockSource_code", requested, callOk && readbackOk);
  }
  logLine("CLKSEL=7 was not written because it stops the device clock and holds timing reset.");

  const float expectedGyroDpsAtRaw1000[] = {
      1000.0f / 262.0f,
      1000.0f / 131.0f,
      1000.0f / 65.5f,
      1000.0f / 32.8f,
  };
  for (uint8_t range = 0; range < 4; ++range) {
    const bool callOk = sensor.setGyroRange(range);
    const uint8_t getter = sensor.getGyroRange();
    const float converted = sensor.convertGyroRawToDPS(1000);
    const bool rangeOk = callOk && getter == range;
    recordIndexedCheck("set_get_gyro_range", range, rangeOk);
    recordIndexedCheck("convert_gyro_raw_to_dps", range,
                       rangeOk && approximatelyEqual(converted,
                                                     expectedGyroDpsAtRaw1000[range],
                                                     0.0005f));
  }

  const float expectedAccelGAtRaw4096[] = {0.25f, 0.5f, 1.0f, 2.0f};
  for (uint8_t range = 0; range < 4; ++range) {
    const bool callOk = sensor.setAccelRange(range);
    const uint8_t getter = sensor.getAccelRange();
    const float converted = sensor.convertAccelRawToG(4096);
    const bool rangeOk = callOk && getter == range;
    recordIndexedCheck("set_get_accel_range", range, rangeOk);
    recordIndexedCheck("convert_accel_raw_to_g", range,
                       rangeOk && approximatelyEqual(converted,
                                                     expectedAccelGAtRaw4096[range],
                                                     0.0005f));
  }

  const uint8_t sampleDividers[] = {0, 1, 7, 31, 255};
  for (uint8_t i = 0; i < sizeof(sampleDividers); ++i) {
    const uint8_t requested = sampleDividers[i];
    const bool callOk = sensor.setSMPLRT_DIV(requested);
    const uint8_t value = sensor.readRegister(IAM20680_REG::SMPLRT_DIV);
    recordIndexedCheck("setSMPLRT_DIV", i, callOk && value == requested);
  }

  for (uint8_t filter = 0; filter < 8; ++filter) {
    const bool callOk = sensor.setDLPF(filter);
    const uint8_t value = sensor.readRegister(IAM20680_REG::CONFIG);
    recordIndexedCheck("setDLPF", filter, callOk && value != 0xFF && (value & 0x07) == filter);
  }

  bool restore = sensor.writeRegister(IAM20680_REG::PWR_MGMT_1, originalPowerManagement1);
  restore = sensor.writeRegister(IAM20680_REG::GYRO_CONFIG, originalGyroConfig) && restore;
  restore = sensor.writeRegister(IAM20680_REG::ACCEL_CONFIG, originalAccelConfig) && restore;
  restore = sensor.writeRegister(IAM20680_REG::CONFIG, originalConfig) && restore;
  restore = sensor.writeRegister(IAM20680_REG::SMPLRT_DIV, originalSampleDivider) && restore;
  restore = sensor.setGyroRange((originalGyroConfig >> 3) & 0x03) && restore;
  restore = sensor.setAccelRange((originalAccelConfig >> 3) & 0x03) && restore;
  recordCheck("restore_measurement_configuration", restore);
  return restore;
}

bool testSensorReadAndConversionAPIs() {
  logLine("Testing raw accelerometer, raw gyroscope, raw temperature, combined data, and Celsius APIs.");

  int16_t ax = 0;
  int16_t ay = 0;
  int16_t az = 0;
  const bool accelOk = sensor.readRawAccel(ax, ay, az);
  recordCheck("readRawAccel", accelOk);

  int16_t gx = 0;
  int16_t gy = 0;
  int16_t gz = 0;
  const bool gyroOk = sensor.readRawGyro(gx, gy, gz);
  recordCheck("readRawGyro", gyroOk);

  int16_t rawTemperature = 0;
  const bool rawTemperatureOk = sensor.readRawTemp(rawTemperature);
  recordCheck("readRawTemp", rawTemperatureOk);

  IAM20680HV::SensorData data{};
  const bool combinedOk = sensor.readSensor(data);
  recordCheck("readSensor", combinedOk);

  float temperatureC = 0.0f;
  const bool temperatureOk = sensor.readTemperatureC(temperatureC);
  const bool temperatureRangeOk = temperatureOk && isFiniteFloat(temperatureC) &&
                                  temperatureC > -100.0f && temperatureC < 200.0f;
  recordCheck("readTemperatureC", temperatureRangeOk);

  if (combinedOk) {
    printSensorSnapshot(data, temperatureC, temperatureOk);
  }

  return accelOk && gyroOk && rawTemperatureOk && combinedOk && temperatureRangeOk;
}

bool testInterruptAPIs() {
  logLine("Testing interrupt pin configuration, interrupt enable masks, status read, and INT pins.");

  const uint8_t originalPinConfig = sensor.readRegister(IAM20680_REG::INT_PIN_CFG);
  const uint8_t originalInterruptEnable = sensor.readRegister(IAM20680_REG::INT_ENABLE);
  const bool saved = originalPinConfig != 0xFF && originalInterruptEnable != 0xFF;
  recordCheck("read_interrupt_configuration", saved);
  if (!saved) {
    return false;
  }

  const uint8_t pinConfigurations[] = {0x00, 0x01, 0xB5};
  for (uint8_t i = 0; i < sizeof(pinConfigurations); ++i) {
    const uint8_t requested = pinConfigurations[i];
    const bool callOk = sensor.configureInterruptPins(requested);
    const uint8_t value = sensor.readRegister(IAM20680_REG::INT_PIN_CFG);
    recordIndexedCheck("configureInterruptPins", i, callOk && value == requested);
  }

  const uint8_t interruptMasks[] = {0x00, 0x01, 0xE0, 0xE5};
  for (uint8_t i = 0; i < sizeof(interruptMasks); ++i) {
    const uint8_t requested = interruptMasks[i];
    const bool callOk = sensor.setInterruptEnable(requested);
    const uint8_t value = sensor.readRegister(IAM20680_REG::INT_ENABLE);
    recordIndexedCheck("setInterruptEnable", i, callOk && value == requested);
  }

  const bool dataReadyConfiguration = sensor.configureInterruptPins(0x01) &&
                                      sensor.setInterruptEnable(0x01);
  recordCheck("configure_data_ready_on_INT1", dataReadyConfiguration);
  delay(25);
  const uint8_t interruptStatus = sensor.readIntStatus();
  logHex("INT_STATUS", interruptStatus);
  recordCheck("readIntStatus", interruptStatus != 0xFF);
  Serial.print("TEST_LOG: DATA_READY_BIT=");
  Serial.println((interruptStatus & 0x01) != 0 ? "SET" : "NOT_OBSERVED");

  const uint8_t fsyncStatus = sensor.readRegister(IAM20680_REG::FSYNC_INT);
  recordCheck("readRegister_fsync_status", fsyncStatus != 0xFF);
  logHex("FSYNC_INT", fsyncStatus);

  Serial.print("TEST_LOG: INT1_LEVEL=");
  Serial.print(digitalRead(IAM20680_INT1_PIN));
  Serial.print(" INT2_LEVEL=");
  Serial.println(digitalRead(IAM20680_INT2_PIN));

  bool restore = sensor.configureInterruptPins(originalPinConfig);
  restore = sensor.setInterruptEnable(originalInterruptEnable) && restore;
  recordCheck("restore_interrupt_configuration", restore);
  return restore;
}

bool testWakeOnMotion() {
  logLine("Testing the complete driver Wake-on-Motion configuration path.");

  const uint8_t originalWomX = sensor.readRegister(IAM20680_REG::ACCEL_WOM_X_THR);
  const uint8_t originalWomY = sensor.readRegister(IAM20680_REG::ACCEL_WOM_Y_THR);
  const uint8_t originalWomZ = sensor.readRegister(IAM20680_REG::ACCEL_WOM_Z_THR);
  const uint8_t originalIntel = sensor.readRegister(IAM20680_REG::ACCEL_INTEL_CTRL);
  const uint8_t originalLpMode = sensor.readRegister(IAM20680_REG::LP_MODE_CFG);
  const uint8_t originalPower1 = sensor.readRegister(IAM20680_REG::PWR_MGMT_1);
  const uint8_t originalPower2 = sensor.readRegister(IAM20680_REG::PWR_MGMT_2);
  const uint8_t originalPinConfig = sensor.readRegister(IAM20680_REG::INT_PIN_CFG);
  const uint8_t originalInterruptEnable = sensor.readRegister(IAM20680_REG::INT_ENABLE);
  const bool saved = originalWomX != 0xFF && originalWomY != 0xFF && originalWomZ != 0xFF &&
                     originalIntel != 0xFF && originalLpMode != 0xFF && originalPower1 != 0xFF &&
                     originalPower2 != 0xFF && originalPinConfig != 0xFF &&
                     originalInterruptEnable != 0xFF;
  recordCheck("read_wom_configuration", saved);
  if (!saved) {
    return false;
  }

  const bool lowNoise = sensor.setPowerModeLowNoise(true);
  recordCheck("prepare_wom_low_noise", lowNoise);
  const bool gyroStandby = sensor.setGyroStandbyMask(0x07);
  recordCheck("prepare_wom_gyro_standby", gyroStandby);
  const bool intRoute = sensor.configureInterruptPins(0x01);
  const bool womEnable = sensor.setInterruptEnable(0xE0);
  recordCheck("prepare_wom_interrupt_route", intRoute && womEnable);

  const bool configureNoCycle = sensor.configureWakeOnMotion(8, 12, 16,
                                                             0x80,
                                                             0x08,
                                                             false);
  const uint8_t noCycleX = sensor.readRegister(IAM20680_REG::ACCEL_WOM_X_THR);
  const uint8_t noCycleY = sensor.readRegister(IAM20680_REG::ACCEL_WOM_Y_THR);
  const uint8_t noCycleZ = sensor.readRegister(IAM20680_REG::ACCEL_WOM_Z_THR);
  const uint8_t noCycleIntel = sensor.readRegister(IAM20680_REG::ACCEL_INTEL_CTRL);
  const uint8_t noCycleLp = sensor.readRegister(IAM20680_REG::LP_MODE_CFG);
  const uint8_t noCyclePower = sensor.readRegister(IAM20680_REG::PWR_MGMT_1);
  const bool noCycleReadback = noCycleX == 8 && noCycleY == 12 && noCycleZ == 16 &&
                               noCycleIntel == 0x80 && noCycleLp == 0x08 &&
                               (noCyclePower & 0x20) == 0;
  recordCheck("configureWakeOnMotion_without_cycle",
              configureNoCycle && noCycleReadback);
  logLine("WoM threshold resolution is 4 mg/LSB; tested thresholds are 32, 48, and 64 mg.");

  const bool configureCycle = sensor.configureWakeOnMotion(4, 8, 12,
                                                           0xC0,
                                                           0x09,
                                                           true);
  const uint8_t cycleX = sensor.readRegister(IAM20680_REG::ACCEL_WOM_X_THR);
  const uint8_t cycleY = sensor.readRegister(IAM20680_REG::ACCEL_WOM_Y_THR);
  const uint8_t cycleZ = sensor.readRegister(IAM20680_REG::ACCEL_WOM_Z_THR);
  const uint8_t cycleIntel = sensor.readRegister(IAM20680_REG::ACCEL_INTEL_CTRL);
  const uint8_t cycleLp = sensor.readRegister(IAM20680_REG::LP_MODE_CFG);
  const uint8_t cyclePower = sensor.readRegister(IAM20680_REG::PWR_MGMT_1);
  const bool cycleReadback = cycleX == 4 && cycleY == 8 && cycleZ == 12 &&
                             cycleIntel == 0xC0 && cycleLp == 0x09 &&
                             (cyclePower & 0x20) != 0;
  recordCheck("configureWakeOnMotion_with_cycle", configureCycle && cycleReadback);

  delay(200);
  const uint8_t womStatus = sensor.readIntStatus();
  logHex("WOM_STATUS_OBSERVATION", womStatus);
  Serial.println("TEST_LOG: WOM_EVENT observation is informational; physical movement is required to force an event.");

  bool restore = sensor.writeRegister(IAM20680_REG::ACCEL_WOM_X_THR, originalWomX);
  restore = sensor.writeRegister(IAM20680_REG::ACCEL_WOM_Y_THR, originalWomY) && restore;
  restore = sensor.writeRegister(IAM20680_REG::ACCEL_WOM_Z_THR, originalWomZ) && restore;
  restore = sensor.writeRegister(IAM20680_REG::ACCEL_INTEL_CTRL, originalIntel) && restore;
  restore = sensor.writeRegister(IAM20680_REG::LP_MODE_CFG, originalLpMode) && restore;
  restore = sensor.writeRegister(IAM20680_REG::PWR_MGMT_1, originalPower1) && restore;
  restore = sensor.writeRegister(IAM20680_REG::PWR_MGMT_2, originalPower2) && restore;
  restore = sensor.configureInterruptPins(originalPinConfig) && restore;
  restore = sensor.setInterruptEnable(originalInterruptEnable) && restore;
  recordCheck("restore_wom_configuration", restore);
  return lowNoise && gyroStandby && intRoute && womEnable && configureNoCycle &&
         noCycleReadback && configureCycle && cycleReadback && restore;
}

int16_t decodeAccelOffset(const uint8_t bytes[2]) {
  int32_t value = (static_cast<int32_t>(bytes[0]) << 7) | (bytes[1] >> 1);
  if ((value & 0x4000) != 0) {
    value |= ~0x7FFF;
  }
  return static_cast<int16_t>(value);
}

bool readAccelOffsetPair(uint8_t highRegister, uint8_t bytes[2]) {
  return sensor.readRegisters(highRegister, bytes, 2);
}

bool testOffsetAPIs() {
  logLine("Testing temporary gyro and accelerometer offset writes and exact restoration.");

  uint8_t originalGyroOffsets[6] = {0};
  uint8_t originalAccelX[2] = {0};
  uint8_t originalAccelY[2] = {0};
  uint8_t originalAccelZ[2] = {0};
  const bool savedGyro = sensor.readRegisters(IAM20680_REG::XG_OFFS_USRH,
                                              originalGyroOffsets,
                                              sizeof(originalGyroOffsets));
  const bool savedAccel = readAccelOffsetPair(IAM20680_REG::XA_OFFSET_H, originalAccelX) &&
                          readAccelOffsetPair(IAM20680_REG::YA_OFFSET_H, originalAccelY) &&
                          readAccelOffsetPair(IAM20680_REG::ZA_OFFSET_H, originalAccelZ);
  recordCheck("read_original_offsets", savedGyro && savedAccel);
  if (!savedGyro || !savedAccel) {
    return false;
  }

  const bool gyroWrite = sensor.setGyroOffsets(120, -240, 360);
  uint8_t gyroReadback[6] = {0};
  const bool gyroRead = sensor.readRegisters(IAM20680_REG::XG_OFFS_USRH,
                                             gyroReadback,
                                             sizeof(gyroReadback));
  const int16_t gyroX = static_cast<int16_t>((static_cast<uint16_t>(gyroReadback[0]) << 8) |
                                             gyroReadback[1]);
  const int16_t gyroY = static_cast<int16_t>((static_cast<uint16_t>(gyroReadback[2]) << 8) |
                                             gyroReadback[3]);
  const int16_t gyroZ = static_cast<int16_t>((static_cast<uint16_t>(gyroReadback[4]) << 8) |
                                             gyroReadback[5]);
  recordCheck("setGyroOffsets", gyroWrite && gyroRead && gyroX == 120 && gyroY == -240 &&
                                   gyroZ == 360);

  const bool accelWrite = sensor.setAccelOffsets(10, -20, 30);
  uint8_t accelXReadback[2] = {0};
  uint8_t accelYReadback[2] = {0};
  uint8_t accelZReadback[2] = {0};
  const bool accelRead = readAccelOffsetPair(IAM20680_REG::XA_OFFSET_H, accelXReadback) &&
                         readAccelOffsetPair(IAM20680_REG::YA_OFFSET_H, accelYReadback) &&
                         readAccelOffsetPair(IAM20680_REG::ZA_OFFSET_H, accelZReadback);
  recordCheck("setAccelOffsets", accelWrite && accelRead &&
                                   decodeAccelOffset(accelXReadback) == 10 &&
                                   decodeAccelOffset(accelYReadback) == -20 &&
                                   decodeAccelOffset(accelZReadback) == 30 &&
                                   (accelXReadback[1] & 0x01) == (originalAccelX[1] & 0x01) &&
                                   (accelYReadback[1] & 0x01) == (originalAccelY[1] & 0x01) &&
                                   (accelZReadback[1] & 0x01) == (originalAccelZ[1] & 0x01));

  bool restore = sensor.writeRegisters(IAM20680_REG::XG_OFFS_USRH,
                                       originalGyroOffsets,
                                       sizeof(originalGyroOffsets));
  restore = sensor.writeRegisters(IAM20680_REG::XA_OFFSET_H, originalAccelX, 2) && restore;
  restore = sensor.writeRegisters(IAM20680_REG::YA_OFFSET_H, originalAccelY, 2) && restore;
  restore = sensor.writeRegisters(IAM20680_REG::ZA_OFFSET_H, originalAccelZ, 2) && restore;
  recordCheck("restore_offsets", restore);
  return gyroWrite && gyroRead && accelWrite && accelRead && restore;
}

void logSelfTestAxis(const char *mode, const char *axis,
                     const IAM20680HV::AxisTest &result) {
  Serial.print("TEST_LOG: SELF_TEST_");
  Serial.print(mode);
  Serial.print("_");
  Serial.print(axis);
  Serial.print(" measured=");
  Serial.print(result.measured, 2);
  Serial.print(" expected=");
  Serial.print(result.expected, 2);
  Serial.print(" physical_pass=");
  Serial.println(result.pass ? "YES" : "NO");
}

bool selfTestResultFieldsAreFinite(const IAM20680HV::SelfTestResult &result) {
  return isFiniteFloat(result.accelX.measured) && isFiniteFloat(result.accelX.expected) &&
         isFiniteFloat(result.accelY.measured) && isFiniteFloat(result.accelY.expected) &&
         isFiniteFloat(result.accelZ.measured) && isFiniteFloat(result.accelZ.expected) &&
         isFiniteFloat(result.gyroX.measured) && isFiniteFloat(result.gyroX.expected) &&
         isFiniteFloat(result.gyroY.measured) && isFiniteFloat(result.gyroY.expected) &&
         isFiniteFloat(result.gyroZ.measured) && isFiniteFloat(result.gyroZ.expected);
}

void printSelfTestResult(const char *mode, const IAM20680HV::SelfTestResult &result) {
  logSelfTestAxis(mode, "ACCEL_X", result.accelX);
  logSelfTestAxis(mode, "ACCEL_Y", result.accelY);
  logSelfTestAxis(mode, "ACCEL_Z", result.accelZ);
  logSelfTestAxis(mode, "GYRO_X", result.gyroX);
  logSelfTestAxis(mode, "GYRO_Y", result.gyroY);
  logSelfTestAxis(mode, "GYRO_Z", result.gyroZ);

  const bool physicalPass = result.accelX.pass && result.accelY.pass && result.accelZ.pass &&
                            result.gyroX.pass && result.gyroY.pass && result.gyroZ.pass;
  Serial.print("TEST_LOG: SELF_TEST_");
  Serial.print(mode);
  Serial.print("_PHYSICAL_RESULT=");
  Serial.println(physicalPass ? "PASS" : "FAIL_OR_NOT_OBSERVED");
  Serial.println("TEST_LOG: Self-test physical flags are reported separately from API procedure validity.");
}

bool testSelfTestAPIs() {
  logLine("Testing self-test option selection and self-test procedure output.");

  IAM20680HV::SelfTestResult codeResult{};
  SelfTestOptions codeOptions;
  codeOptions.mode = SelfTestOtpMode::ST_CODE;
  codeOptions.tolerance_fraction = 0.30f;
  sensor.setSelfTestOptions(codeOptions);
  recordCheck("setSelfTestOptions_ST_CODE", true);
  const bool codeProcedure = sensor.selfTest(codeResult);
  const bool codeFields = selfTestResultFieldsAreFinite(codeResult);
  recordCheck("selfTest_ST_CODE_procedure", codeProcedure && codeFields);
  if (codeProcedure && codeFields) {
    printSelfTestResult("ST_CODE", codeResult);
  }

  IAM20680HV::SelfTestResult factoryResult{};
  SelfTestOptions factoryOptions;
  factoryOptions.mode = SelfTestOtpMode::ST_FAC;
  factoryOptions.tolerance_fraction = 0.30f;
  sensor.setSelfTestOptions(factoryOptions);
  recordCheck("setSelfTestOptions_ST_FAC", true);
  const bool factoryProcedure = sensor.selfTest(factoryResult);
  const bool factoryFields = selfTestResultFieldsAreFinite(factoryResult);
  recordCheck("selfTest_ST_FAC_procedure", factoryProcedure && factoryFields);
  if (factoryProcedure && factoryFields) {
    printSelfTestResult("ST_FAC", factoryResult);
  }

  sensor.setSelfTestOptions(codeOptions);
  return codeProcedure && codeFields && factoryProcedure && factoryFields;
}

bool testPowerModeAPIs() {
  logLine("Testing sleep, accelerometer cycle, gyro standby, and low-noise power helpers.");

  const uint8_t originalPower1 = sensor.readRegister(IAM20680_REG::PWR_MGMT_1);
  const uint8_t originalPower2 = sensor.readRegister(IAM20680_REG::PWR_MGMT_2);
  const uint8_t originalLpMode = sensor.readRegister(IAM20680_REG::LP_MODE_CFG);
  const bool saved = originalPower1 != 0xFF && originalPower2 != 0xFF && originalLpMode != 0xFF;
  recordCheck("read_power_mode_configuration", saved);
  if (!saved) {
    return false;
  }

  const bool sleepOn = sensor.setSleep(true);
  const uint8_t sleepOnValue = sensor.readRegister(IAM20680_REG::PWR_MGMT_1);
  recordCheck("setSleep_true", sleepOn && (sleepOnValue & 0x40) != 0);
  const bool sleepOff = sensor.setSleep(false);
  const uint8_t sleepOffValue = sensor.readRegister(IAM20680_REG::PWR_MGMT_1);
  recordCheck("setSleep_false", sleepOff && (sleepOffValue & 0x40) == 0);

  const bool accelCycleOn = sensor.setAccelCycle(true);
  const uint8_t accelCycleOnValue = sensor.readRegister(IAM20680_REG::PWR_MGMT_1);
  recordCheck("setAccelCycle_true", accelCycleOn && (accelCycleOnValue & 0x20) != 0);
  const bool accelCycleOff = sensor.setAccelCycle(false);
  const uint8_t accelCycleOffValue = sensor.readRegister(IAM20680_REG::PWR_MGMT_1);
  recordCheck("setAccelCycle_false", accelCycleOff && (accelCycleOffValue & 0x20) == 0);

  const bool gyroStandbyOn = sensor.setGyroStandbyMask(0x07);
  const uint8_t gyroStandbyOnValue = sensor.readRegister(IAM20680_REG::PWR_MGMT_2);
  recordCheck("setGyroStandbyMask_all", gyroStandbyOn && (gyroStandbyOnValue & 0x07) == 0x07);
  const bool gyroStandbyOff = sensor.setGyroStandbyMask(0x00);
  const uint8_t gyroStandbyOffValue = sensor.readRegister(IAM20680_REG::PWR_MGMT_2);
  recordCheck("setGyroStandbyMask_none", gyroStandbyOff && (gyroStandbyOffValue & 0x07) == 0);

  const bool lowNoiseOn = sensor.setPowerModeLowNoise(true);
  const uint8_t lowNoisePower1 = sensor.readRegister(IAM20680_REG::PWR_MGMT_1);
  const uint8_t lowNoisePower2 = sensor.readRegister(IAM20680_REG::PWR_MGMT_2);
  const uint8_t lowNoiseLp = sensor.readRegister(IAM20680_REG::LP_MODE_CFG);
  const bool lowNoiseReadback = (lowNoisePower1 & 0x20) == 0 &&
                                (lowNoisePower2 & 0x07) == 0 &&
                                (lowNoiseLp & 0x80) == 0;
  recordCheck("setPowerModeLowNoise_true", lowNoiseOn && lowNoiseReadback);
  const bool lowNoiseOff = sensor.setPowerModeLowNoise(false);
  recordCheck("setPowerModeLowNoise_false", lowNoiseOff);

  bool restore = sensor.writeRegister(IAM20680_REG::PWR_MGMT_1, originalPower1);
  restore = sensor.writeRegister(IAM20680_REG::PWR_MGMT_2, originalPower2) && restore;
  restore = sensor.writeRegister(IAM20680_REG::LP_MODE_CFG, originalLpMode) && restore;
  recordCheck("restore_power_mode_configuration", restore);
  return sleepOn && sleepOff && accelCycleOn && accelCycleOff && gyroStandbyOn &&
         gyroStandbyOff && lowNoiseOn && lowNoiseReadback && lowNoiseOff && restore;
}

bool testSignalPathAndReinitialization() {
  logLine("Testing signal-path reset combinations, soft reset, and reinitialization.");

  const bool noReset = sensor.resetSignalPath(false, false, false);
  recordCheck("resetSignalPath_none", noReset);
  const bool accelReset = sensor.resetSignalPath(true, false, false);
  recordCheck("resetSignalPath_accel", accelReset);
  const bool temperatureReset = sensor.resetSignalPath(false, true, false);
  recordCheck("resetSignalPath_temperature", temperatureReset);
  const bool allReset = sensor.resetSignalPath(true, true, true);
  recordCheck("resetSignalPath_all_and_clear", allReset);

  const bool softResetOk = sensor.softReset();
  recordCheck("softReset", softResetOk);

  const bool reinitializeOk = sensor.beginI2C(Wire, IAM20680_I2C_ADDRESS);
  recordCheck("beginI2C_after_resets", reinitializeOk);
  if (reinitializeOk) {
    recordCheck("WHO_AM_I_after_reinitialize", sensor.whoAmI() == 0xFE);
  }

  const bool i2cStillEnabled = sensor.disableI2CInterface(false);
  recordCheck("disableI2CInterface_false", i2cStillEnabled &&
                                             (sensor.readRegister(IAM20680_REG::USER_CTRL) & 0x10) == 0);
  logLine("disableI2CInterface(true) is intentionally skipped because it would disconnect the active I2C bus.");
  logLine("beginSPI is intentionally skipped because no SPI wiring is present on this board.");

  return noReset && accelReset && temperatureReset && allReset && softResetOk &&
         reinitializeOk && i2cStillEnabled;
}

void finishTest() {
  const uint32_t duration = millis() - testStartMillis;
  Serial.print("TEST_LOG: CHECK_COUNT=");
  Serial.println(checkCount);
  Serial.print("TEST_LOG: FAILED_CHECK_COUNT=");
  Serial.println(failedCheckCount);
  Serial.print("TEST_LOG: DURATION_MS=");
  Serial.println(duration);
  Serial.println(overallPass ? "TEST_RESULT:PASS" : "TEST_RESULT:FAIL");
  Serial.flush();
}

void runAllTests() {
  testStartMillis = millis();
  checkCount = 0;
  failedCheckCount = 0;
  overallPass = true;

  logLine("IAM20680HV public API coverage test started.");
  logLine("Transport scope: I2C only; SDA=GPIO0, SCL=GPIO1, INT2=GPIO16, INT1=GPIO17, address=0x68.");

  if (!initializeI2C()) {
    finishTest();
    return;
  }

  if (timeBudgetAvailable("register_access")) {
    testLowLevelRegisterAccess();
  }
  if (timeBudgetAvailable("measurement_configuration")) {
    testMeasurementConfiguration();
  }
  if (timeBudgetAvailable("sensor_reads")) {
    testSensorReadAndConversionAPIs();
  }
  if (timeBudgetAvailable("interrupts")) {
    testInterruptAPIs();
  }
  if (timeBudgetAvailable("wake_on_motion")) {
    testWakeOnMotion();
  }
  if (timeBudgetAvailable("offsets")) {
    testOffsetAPIs();
  }
  if (timeBudgetAvailable("self_test")) {
    testSelfTestAPIs();
  }
  if (timeBudgetAvailable("power_modes")) {
    testPowerModeAPIs();
  }
  if (timeBudgetAvailable("signal_path_and_reinitialization")) {
    testSignalPathAndReinitialization();
  }

  finishTest();
}

bool isRunTestCommand(char *line) {
  size_t begin = 0;
  while (line[begin] == ' ' || line[begin] == '\t') {
    ++begin;
  }

  size_t end = strlen(line);
  while (end > begin && (line[end - 1] == ' ' || line[end - 1] == '\t' || line[end - 1] == '\r')) {
    --end;
  }
  line[end] = '\0';
  return strcmp(line + begin, "RUN_TEST") == 0;
}

}  // namespace

void setup() {
  Serial.begin(115200);
  const uint32_t serialWaitStart = millis();
  while (!Serial && millis() - serialWaitStart < 3000) {
    delay(10);
  }

  Wire.setSDA(I2C_SDA_PIN);
  Wire.setSCL(I2C_SCL_PIN);
  Wire.begin();
  Wire.setClock(400000);

  pinMode(IAM20680_INT1_PIN, INPUT);
  pinMode(IAM20680_INT2_PIN, INPUT);

  logLine("IAM20680HV test sketch ready; send RUN_TEST followed by newline.");
  logLine("No SPI test will be executed because SPI is not connected.");
}

void loop() {
  static char line[32] = {0};
  static size_t lineLength = 0;

  while (Serial.available() > 0) {
    const char c = static_cast<char>(Serial.read());
    if (c == '\n') {
      line[lineLength] = '\0';
      if (!testStarted && isRunTestCommand(line)) {
        testStarted = true;
        runAllTests();
      }
      lineLength = 0;
    } else if (c != '\r') {
      if (lineLength < sizeof(line) - 1) {
        line[lineLength++] = c;
      } else {
        lineLength = 0;
      }
    }
  }
}
