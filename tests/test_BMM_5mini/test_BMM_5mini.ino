#include <Arduino.h>
#include <Wire.h>
#include <math.h>

// The sketch is stored at code_BMM_5mini root while the generated driver is nested.
#include "BMM350.h"

// RP2040 board wiring.
constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 1;
constexpr uint8_t BMM350_INT_PIN = 18;

// The datasheet defines ADSEL-low/high as 0x14/0x15.
constexpr uint8_t BMM350_I2C_ADDRESS_ADSEL_LOW = 0x14;
constexpr uint8_t BMM350_I2C_ADDRESS_ADSEL_HIGH = 0x15;

// Valid datasheet settings used by the test sequence.
constexpr uint8_t ODR_200HZ = 0x03;
constexpr uint8_t ODR_100HZ = 0x04;
constexpr uint8_t ODR_12_5HZ = 0x07;
constexpr uint8_t AVG_1 = 0x00;
constexpr uint8_t AVG_2 = 0x01;
constexpr uint8_t AVG_8 = 0x03;

constexpr uint8_t DATA_READY_MASK = 0x04;
constexpr uint8_t PMU_BUSY_MASK = 0x01;
constexpr uint8_t PMU_NORMAL_MASK = 0x08;
constexpr uint8_t PMU_ILLEGAL_MASK = 0x10;

constexpr unsigned long DATA_READY_TIMEOUT_MS = 500UL;
constexpr unsigned long MONITOR_INTERVAL_MS = 2000UL;
constexpr unsigned long FULL_API_TEST_INTERVAL_MS = 30000UL;

BMM350 sensor;

bool sensorInitialized = false;
bool deviceReady = false;
uint8_t activeAddress = 0;
unsigned long lastMonitorMs = 0;
unsigned long lastFullApiTestMs = 0;
uint32_t monitorCycle = 0;

uint32_t passCount = 0;
uint32_t failCount = 0;
uint32_t skipCount = 0;

void runFullApiTest();
void runMonitorCycle();

void printHex8(uint8_t value) {
  if (value < 0x10) {
    Serial.print('0');
  }
  Serial.print(static_cast<unsigned int>(value), HEX);
}

void printBoolean(bool value) {
  Serial.print(value ? "YES" : "NO");
}

void reportBool(const char *label, bool passed) {
  Serial.print(passed ? "[PASS] " : "[FAIL] ");
  Serial.println(label);
  if (passed) {
    ++passCount;
  } else {
    ++failCount;
  }
}

void reportExpectedFalse(const char *label, bool returnedTrue) {
  reportBool(label, !returnedTrue);
}

void reportSkip(const char *label) {
  Serial.print("[SKIP] ");
  Serial.println(label);
  ++skipCount;
}

void reportInfo(const char *label) {
  Serial.print("[INFO] ");
  Serial.println(label);
}

bool readRegister8(uint8_t reg, uint8_t &value) {
  return sensor.readRegister(reg, &value, 1, true);
}

bool waitForDataReady(unsigned long timeoutMs) {
  const unsigned long startMs = millis();

  while (millis() - startMs < timeoutMs) {
    uint8_t interruptStatus = 0;
    if (!readRegister8(BMM350Reg::INT_STATUS, interruptStatus)) {
      return false;
    }
    if ((interruptStatus & DATA_READY_MASK) != 0) {
      return true;
    }
    delay(2);
  }

  return false;
}

bool initializeSensor() {
  const uint8_t firstAddress = activeAddress == BMM350_I2C_ADDRESS_ADSEL_HIGH
                                   ? BMM350_I2C_ADDRESS_ADSEL_HIGH
                                   : BMM350_I2C_ADDRESS_ADSEL_LOW;
  const uint8_t secondAddress = firstAddress == BMM350_I2C_ADDRESS_ADSEL_LOW
                                    ? BMM350_I2C_ADDRESS_ADSEL_HIGH
                                    : BMM350_I2C_ADDRESS_ADSEL_LOW;
  const uint8_t candidates[] = {firstAddress, secondAddress};

  for (uint8_t address : candidates) {
    Serial.print("[INFO] Initializing BMM350 at I2C address 0x");
    printHex8(address);
    Serial.println();

    if (sensor.begin(address, &Wire)) {
      activeAddress = address;
      sensorInitialized = true;
      Serial.println("[INFO] BMM350 initialization succeeded.");
      return true;
    }

    Serial.println("[INFO] Initialization attempt failed.");
  }

  sensorInitialized = false;
  return false;
}

void printEffectivePerformance(const char *label,
                               uint8_t expectedOdr,
                               uint8_t expectedAvg) {
  uint8_t status1 = 0;
  const bool readOk = readRegister8(BMM350Reg::PMU_CMD_STATUS_1, status1);
  const uint8_t actualOdr = status1 & 0x0F;
  const uint8_t actualAvg = (status1 >> 4) & 0x03;

  Serial.print("  ");
  Serial.print(label);
  Serial.print(": ODR=0x");
  printHex8(actualOdr);
  Serial.print(" AVG=0x");
  printHex8(actualAvg);
  Serial.print(" raw=0x");
  printHex8(status1);
  Serial.println();

  reportBool("PMU_CMD_STATUS_1 matches requested ODR/averaging",
             readOk && actualOdr == expectedOdr && actualAvg == expectedAvg);
}

void printPmuStatus() {
  uint8_t status0 = 0;
  uint8_t status1 = 0;

  if (readRegister8(BMM350Reg::PMU_CMD_STATUS_0, status0)) {
    Serial.print("  PMU status: busy=");
    printBoolean((status0 & PMU_BUSY_MASK) != 0);
    Serial.print(" normal=");
    printBoolean((status0 & PMU_NORMAL_MASK) != 0);
    Serial.print(" illegal=");
    printBoolean((status0 & PMU_ILLEGAL_MASK) != 0);
    Serial.print(" raw=0x");
    printHex8(status0);
    Serial.println();
  } else {
    Serial.println("  PMU status: READ_ERROR");
  }

  if (readRegister8(BMM350Reg::PMU_CMD_STATUS_1, status1)) {
    Serial.print("  Effective performance: ODR=0x");
    printHex8(status1 & 0x0F);
    Serial.print(" AVG=0x");
    printHex8((status1 >> 4) & 0x03);
    Serial.println();
  } else {
    Serial.println("  Effective performance: READ_ERROR");
  }
}

void printMeasurement(float mx,
                     float my,
                     float mz,
                     float temperature,
                     uint32_t sensortime) {
  Serial.print("  Driver output X/Y/Z: ");
  Serial.print(mx, 4);
  Serial.print(" / ");
  Serial.print(my, 4);
  Serial.print(" / ");
  Serial.println(mz, 4);

  Serial.print("  Driver temperature: ");
  Serial.println(temperature, 4);

  Serial.print("  Sensortime: ");
  Serial.println(static_cast<unsigned long>(sensortime));
}

void testLowLevelAndIdentity() {
  Serial.println();
  Serial.println("[TEST] Identity and low-level register transport");

  uint8_t chipId = 0;
  const bool chipIdOk = sensor.readRegister(
      BMM350Reg::CHIP_ID, &chipId, 1);
  reportBool("readRegister(CHIP_ID)", chipIdOk && chipId == BMM350_CHIP_ID);
  Serial.print("  CHIP_ID: 0x");
  printHex8(chipId);
  Serial.println();

  uint8_t revision = 0;
  const bool revisionOk = readRegister8(
      BMM350Reg::TRANS_DUCER_REV_ID, revision);
  reportBool("readRegister(TRANS_DUCER_REV_ID)", revisionOk);
  Serial.print("  Transducer revision: 0x");
  printHex8(revision);
  Serial.println();

  uint8_t burstData[15] = {};
  const bool burstOk = sensor.readRegister(
      BMM350Reg::MAG_X_XLSB, burstData, sizeof(burstData));
  reportBool("readRegister(MAG_X_XLSB..SENSORTIME_MSB) with dummy-byte handling",
             burstOk);

  uint8_t selfTestClear = 0;
  const bool writeOk = sensor.writeRegister(
      BMM350Reg::TMR_SELFTEST_USER, &selfTestClear, 1);
  reportBool("writeRegister(TMR_SELFTEST_USER)", writeOk);

  uint8_t selfTestValue = 0xFF;
  const bool readBackOk = readRegister8(
      BMM350Reg::TMR_SELFTEST_USER, selfTestValue);
  reportBool("readRegister(TMR_SELFTEST_USER) after write",
             readBackOk && selfTestValue == 0);
}

void testErrorAndStatusRegisters() {
  Serial.println();
  Serial.println("[TEST] Error and PMU status reporting");

  const uint8_t errorBeforeClear = sensor.readErrorAndClear();
  uint8_t errorAfterClear = 0xFF;
  const bool clearReadOk = readRegister8(BMM350Reg::ERR_REG, errorAfterClear);
  reportBool("readErrorAndClear() and clear-on-read behavior",
             clearReadOk && errorAfterClear == 0);
  Serial.print("  ERR_REG before clear: 0x");
  printHex8(errorBeforeClear);
  Serial.print("; after clear: 0x");
  printHex8(errorAfterClear);
  Serial.println();

  uint8_t i3cError = 0;
  const bool i3cErrorOk = readRegister8(BMM350Reg::I3C_ERR, i3cError);
  reportBool("readRegister(I3C_ERR)", i3cErrorOk);
  Serial.print("  I3C_ERR in I2C test mode: 0x");
  printHex8(i3cError);
  Serial.println();

  printPmuStatus();
  reportInfo("I3C error reporting is read through the driver's generic register API.");
}

void testPerformanceAndPowerModes() {
  Serial.println();
  Serial.println("[TEST] Performance, power modes, and forced measurements");

  reportBool("setPowerMode(PMU_NORMAL)", sensor.setPowerMode(PMU_NORMAL));

  const bool slowPerformanceOk = sensor.setODRandPerformance(
      ODR_12_5HZ, AVG_8);
  reportBool("setODRandPerformance(12.5 Hz, AVG_8)", slowPerformanceOk);
  if (slowPerformanceOk) {
    reportBool("data-ready after 12.5 Hz performance update",
               waitForDataReady(DATA_READY_TIMEOUT_MS));
  }
  printEffectivePerformance("Requested low-rate setting", ODR_12_5HZ, AVG_8);

  reportBool("setPowerMode(PMU_SUSPEND)", sensor.setPowerMode(PMU_SUSPEND));

  const bool forcedModeCommandOk = sensor.setPowerMode(PMU_FM);
  reportBool("setPowerMode(PMU_FM)", forcedModeCommandOk);
  if (forcedModeCommandOk) {
    reportBool("data-ready after setPowerMode(PMU_FM)",
               waitForDataReady(DATA_READY_TIMEOUT_MS));
  }

  reportBool("forcedMeasurement(FM)", sensor.forcedMeasurement(false));

  reportBool("setPowerMode(PMU_NORMAL) before fast setting",
             sensor.setPowerMode(PMU_NORMAL));

  const bool fastPerformanceOk = sensor.setODRandPerformance(
      ODR_200HZ, AVG_1);
  reportBool("setODRandPerformance(200 Hz, AVG_1)", fastPerformanceOk);
  if (fastPerformanceOk) {
    reportBool("data-ready after 200 Hz performance update",
               waitForDataReady(DATA_READY_TIMEOUT_MS));
  }
  printEffectivePerformance("Requested high-rate setting", ODR_200HZ, AVG_1);

  const bool forcedFastModeCommandOk = sensor.setPowerMode(PMU_FM_FAST);
  reportBool("setPowerMode(PMU_FM_FAST)", forcedFastModeCommandOk);
  if (forcedFastModeCommandOk) {
    reportBool("data-ready after setPowerMode(PMU_FM_FAST)",
               waitForDataReady(DATA_READY_TIMEOUT_MS));
  }

  reportBool("forcedMeasurement(FM_FAST)", sensor.forcedMeasurement(true));
  reportBool("setPowerMode(PMU_NORMAL) after forced tests",
             sensor.setPowerMode(PMU_NORMAL));
}

void testDataAccess() {
  Serial.println();
  Serial.println("[TEST] Magnetometer, temperature, and sensortime access");

  float mx = 0.0f;
  float my = 0.0f;
  float mz = 0.0f;
  float temperature = 0.0f;
  uint32_t sensortime = 0;

  const bool fullReadOk = sensor.readMagnetometer(
      mx, my, mz, &temperature, &sensortime);
  reportBool("readMagnetometer(with temperature and sensortime)", fullReadOk);
  if (fullReadOk) {
    printMeasurement(mx, my, mz, temperature, sensortime);
  }

  uint32_t separateSensortime = 0;
  const bool sensortimeOk = sensor.readSensorTime(separateSensortime);
  reportBool("readSensorTime()", sensortimeOk);
  if (sensortimeOk) {
    Serial.print("  Standalone sensortime: ");
    Serial.println(static_cast<unsigned long>(separateSensortime));
  }

  float mxWithoutOptional = 0.0f;
  float myWithoutOptional = 0.0f;
  float mzWithoutOptional = 0.0f;
  const bool optionalNullOk = sensor.readMagnetometer(
      mxWithoutOptional, myWithoutOptional, mzWithoutOptional, nullptr, nullptr);
  reportBool("readMagnetometer(nullptr, nullptr)", optionalNullOk);

  reportInfo("The current driver returns floating-point outputs using its implemented compensation model; no independent conversion is added here.");
}

void testInterruptAndInterface() {
  Serial.println();
  Serial.println("[TEST] Interrupt, pad drive, and I2C watchdog configuration");

  reportBool("configureInterrupt(disabled, pulsed, active-low, open-drain)",
             sensor.configureInterrupt(false, false, false, false));
  reportBool("configureInterrupt(enabled, latched, active-high, push-pull)",
             sensor.configureInterrupt(true, true, true, true));

  Serial.print("  INT GPIO18 level after configuration: ");
  Serial.println(digitalRead(BMM350_INT_PIN) == HIGH ? "HIGH" : "LOW");

  const bool padWeakOk = sensor.setPadDrive(0);
  const bool padStrongOk = sensor.setPadDrive(7);
  const bool padMaskedOk = sensor.setPadDrive(8);
  uint8_t padRegister = 0xFF;
  const bool padReadOk = readRegister8(BMM350Reg::PAD_CTRL, padRegister);

  reportBool("setPadDrive(0)", padWeakOk);
  reportBool("setPadDrive(7)", padStrongOk);
  reportBool("setPadDrive(8) is masked to drive=0 by the driver",
             padMaskedOk && padReadOk && (padRegister & 0x07) == 0);
  reportInfo("Restoring pad drive to 7.");
  reportBool("restore setPadDrive(7)", sensor.setPadDrive(7));

  // Keep the short-watchdog transaction sequence contiguous to avoid an intentional bus stall.
  const bool watchdogShortOk = sensor.setI2CWatchdog(true, false);
  const bool watchdogLongOk = sensor.setI2CWatchdog(true, true);
  const bool watchdogOffOk = sensor.setI2CWatchdog(false, false);
  reportBool("setI2CWatchdog(enabled, short timeout)", watchdogShortOk);
  reportBool("setI2CWatchdog(enabled, long timeout)", watchdogLongOk);
  reportBool("setI2CWatchdog(disabled)", watchdogOffOk);

  reportInfo("SPI is skipped: the 5mini driver exposes I2C only and SPI is not connected on this board.");
}

void testAxesAndSensorTimeConfiguration() {
  Serial.println();
  Serial.println("[TEST] Axis enable and sensor-time configuration");

  reportBool("enableAxes(X, Y, Z)", sensor.enableAxes(true, true, true));
  reportBool("enableAxes(X only)", sensor.enableAxes(true, false, false));
  reportBool("enableAxes(Y only)", sensor.enableAxes(false, true, false));
  reportBool("enableAxes(Z only)", sensor.enableAxes(false, false, true));
  reportExpectedFalse("enableAxes(all axes disabled) is rejected",
                      sensor.enableAxes(false, false, false));
  reportBool("restore enableAxes(X, Y, Z)",
             sensor.enableAxes(true, true, true));

  reportBool("setCtrlUser(false)", sensor.setCtrlUser(false));
  reportBool("setCtrlUser(true)", sensor.setCtrlUser(true));
  reportBool("restore setCtrlUser(false)", sensor.setCtrlUser(false));

  reportBool("setPowerMode(PMU_NORMAL) after configuration",
             sensor.setPowerMode(PMU_NORMAL));
}

void testMagneticReset() {
  Serial.println();
  Serial.println("[TEST] Magnetic reset variants");

  reportBool("setPowerMode(PMU_SUSPEND) before magnetic reset",
             sensor.setPowerMode(PMU_SUSPEND));

  const uint8_t resetCommands[] = {PMU_FGR, PMU_FGR_FAST, PMU_BR, PMU_BR_FAST};
  const char *resetLabels[] = {
      "magneticReset(PMU_FGR)",
      "magneticReset(PMU_FGR_FAST)",
      "magneticReset(PMU_BR)",
      "magneticReset(PMU_BR_FAST)"};

  for (uint8_t index = 0; index < 4; ++index) {
    reportBool(resetLabels[index], sensor.magneticReset(resetCommands[index]));
  }

  reportBool("setPowerMode(PMU_NORMAL) after magnetic reset",
             sensor.setPowerMode(PMU_NORMAL));
}

void testSelfTest() {
  Serial.println();
  Serial.println("[TEST] X/Y self-test");

  reportBool("setPowerMode(PMU_NORMAL) before self-test setup",
             sensor.setPowerMode(PMU_NORMAL));
  const bool selfTestPerformanceOk = sensor.setODRandPerformance(
      ODR_12_5HZ, AVG_8);
  reportBool("setODRandPerformance(12.5 Hz, AVG_8) for self-test",
             selfTestPerformanceOk);
  if (selfTestPerformanceOk) {
    reportBool("data-ready before self-test",
               waitForDataReady(DATA_READY_TIMEOUT_MS));
  }

  float deltaX = 0.0f;
  float deltaY = 0.0f;
  const bool xSelfTestOk = sensor.performSelfTest(
      true, false, true, deltaX, deltaY);
  reportBool("performSelfTest(X, positive)", xSelfTestOk);
  Serial.print("  X self-test delta X/Y: ");
  Serial.print(deltaX, 4);
  Serial.print(" / ");
  Serial.println(deltaY, 4);

  deltaX = 0.0f;
  deltaY = 0.0f;
  const bool ySelfTestOk = sensor.performSelfTest(
      false, true, false, deltaX, deltaY);
  reportBool("performSelfTest(Y, negative)", ySelfTestOk);
  Serial.print("  Y self-test delta X/Y: ");
  Serial.print(deltaX, 4);
  Serial.print(" / ");
  Serial.println(deltaY, 4);

  // The current driver does not clear TMR_SELFTEST_USER after a successful test.
  uint8_t clearValue = 0;
  reportBool("clear TMR_SELFTEST_USER after self-test",
             sensor.writeRegister(BMM350Reg::TMR_SELFTEST_USER, &clearValue, 1));
}

bool testResetAndOtp() {
  Serial.println();
  Serial.println("[TEST] Soft reset and OTP access");

  const bool softResetOk = sensor.softReset();
  reportBool("softReset()", softResetOk);
  if (!softResetOk) {
    reportSkip("reloadOTP(), otpDirectAccess(), and begin() after soft reset");
    sensorInitialized = false;
    return false;
  }

  const bool reloadOk = sensor.reloadOTP();
  reportBool("reloadOTP() after soft reset", reloadOk);

  uint16_t otpWord = 0;
  const bool directOtpOk = sensor.otpDirectAccess(0x01, 0x00, otpWord);
  reportBool("otpDirectAccess(DIR_READ, word 0)", directOtpOk);
  if (directOtpOk) {
    Serial.print("  OTP word 0: 0x");
    Serial.println(static_cast<unsigned int>(otpWord), HEX);
  }

  const bool reinitializeOk = reloadOk && directOtpOk &&
                              initializeSensor();
  reportBool("begin() after direct OTP access", reinitializeOk);
  sensorInitialized = reinitializeOk;
  return reinitializeOk;
}

bool restoreMonitoringState() {
  Serial.println();
  Serial.println("[TEST] Restore periodic monitoring state");

  uint8_t selfTestClear = 0;
  const bool selfTestClearOk = sensor.writeRegister(
      BMM350Reg::TMR_SELFTEST_USER, &selfTestClear, 1);
  const bool watchdogOk = sensor.setI2CWatchdog(false, false);
  const bool padOk = sensor.setPadDrive(7);
  const bool axesOk = sensor.enableAxes(true, true, true);
  const bool sensorTimeOk = sensor.setCtrlUser(false);
  const bool interruptOk = sensor.configureInterrupt(true, true, true, true);
  const bool normalModeOk = sensor.setPowerMode(PMU_NORMAL);
  const bool performanceOk = sensor.setODRandPerformance(ODR_100HZ, AVG_2);
  const bool dataReadyOk = performanceOk &&
                           waitForDataReady(DATA_READY_TIMEOUT_MS);

  reportBool("clear self-test register", selfTestClearOk);
  reportBool("disable I2C watchdog", watchdogOk);
  reportBool("restore pad drive=7", padOk);
  reportBool("restore all axes enabled", axesOk);
  reportBool("disable sensor-time always-on", sensorTimeOk);
  reportBool("enable data-ready interrupt configuration", interruptOk);
  reportBool("restore normal power mode", normalModeOk);
  reportBool("restore 100 Hz / AVG_2 monitoring setting", performanceOk);
  reportBool("monitoring setting produces data-ready", dataReadyOk);

  const bool restored = selfTestClearOk && watchdogOk && padOk && axesOk &&
                        sensorTimeOk && interruptOk && normalModeOk &&
                        performanceOk && dataReadyOk;
  deviceReady = sensorInitialized && restored;
  return restored;
}

void printSummary() {
  Serial.println();
  Serial.println("========================================");
  Serial.print("BMM350 API test summary: PASS=");
  Serial.print(static_cast<unsigned long>(passCount));
  Serial.print(" FAIL=");
  Serial.print(static_cast<unsigned long>(failCount));
  Serial.print(" SKIP=");
  Serial.println(static_cast<unsigned long>(skipCount));
  Serial.println("========================================");
}

void runFullApiTest() {
  passCount = 0;
  failCount = 0;
  skipCount = 0;

  Serial.println();
  Serial.println("========================================");
  Serial.println("BMM350 5mini full driver API test");
  Serial.println("========================================");
  Serial.println("Scope: I2C only; GPIO0=SDA, GPIO1=SCL, GPIO18=INT.");

  bool readyForTest = sensorInitialized;
  if (!readyForTest) {
    const bool beginOk = initializeSensor();
    reportBool("begin() / OTP load and boot termination", beginOk);
    readyForTest = beginOk;
  } else {
    reportInfo("begin() is exercised again in the soft-reset/OTP section.");
  }

  if (!readyForTest) {
    reportSkip("All device-dependent tests because BMM350 initialization failed");
    deviceReady = false;
    printSummary();
    return;
  }

  testLowLevelAndIdentity();
  testErrorAndStatusRegisters();
  testPerformanceAndPowerModes();
  testDataAccess();
  testInterruptAndInterface();
  testAxesAndSensorTimeConfiguration();
  testMagneticReset();
  testSelfTest();

  const bool resetAndOtpOk = testResetAndOtp();
  if (resetAndOtpOk) {
    if (!restoreMonitoringState()) {
      sensorInitialized = false;
    }
  } else {
    reportSkip("Restore monitoring state because reset/OTP recovery failed");
    deviceReady = false;
  }

  printSummary();
}

void runMonitorCycle() {
  Serial.println();
  Serial.print("----- BMM350 monitor cycle ");
  Serial.print(static_cast<unsigned long>(monitorCycle++));
  Serial.println(" -----");

  Serial.print("  I2C address: 0x");
  printHex8(activeAddress);
  Serial.println();

  Serial.print("  INT GPIO18 level: ");
  Serial.println(digitalRead(BMM350_INT_PIN) == HIGH ? "HIGH" : "LOW");

  printPmuStatus();

  uint8_t interruptStatus = 0;
  if (readRegister8(BMM350Reg::INT_STATUS, interruptStatus)) {
    Serial.print("  Data ready: ");
    printBoolean((interruptStatus & DATA_READY_MASK) != 0);
    Serial.print(" (INT_STATUS=0x");
    printHex8(interruptStatus);
    Serial.println(")");
  } else {
    Serial.println("  Data ready: READ_ERROR");
  }

  float mx = 0.0f;
  float my = 0.0f;
  float mz = 0.0f;
  float temperature = 0.0f;
  uint32_t sensortime = 0;
  const bool measurementOk = sensor.readMagnetometer(
      mx, my, mz, &temperature, &sensortime);
  if (measurementOk) {
    printMeasurement(mx, my, mz, temperature, sensortime);
  } else {
    Serial.println("  Measurement: READ_ERROR");
  }

  uint32_t standaloneSensortime = 0;
  if (sensor.readSensorTime(standaloneSensortime)) {
    Serial.print("  Standalone sensortime: ");
    Serial.println(static_cast<unsigned long>(standaloneSensortime));
  } else {
    Serial.println("  Standalone sensortime: READ_ERROR");
  }

  const uint8_t error = sensor.readErrorAndClear();
  Serial.print("  ERR_REG (read and clear): 0x");
  printHex8(error);
  Serial.println();

  uint8_t i3cError = 0;
  if (readRegister8(BMM350Reg::I3C_ERR, i3cError)) {
    Serial.print("  I3C_ERR: 0x");
    printHex8(i3cError);
    Serial.println();
  } else {
    Serial.println("  I3C_ERR: READ_ERROR");
  }

  Serial.println("----------------------------------------");
}

void setup() {
  Serial.begin(115200);

  const unsigned long serialStartMs = millis();
  while (!Serial && millis() - serialStartMs < 3000UL) {
    delay(10);
  }

  Wire.setSDA(I2C_SDA_PIN);
  Wire.setSCL(I2C_SCL_PIN);
  Wire.begin();

  pinMode(BMM350_INT_PIN, INPUT);

  Serial.println();
  Serial.println("BMM350 RP2040 5mini driver test");
  Serial.println("I2C: GPIO0=SDA, GPIO1=SCL; INT: GPIO18; SPI: not connected");
  Serial.println("Monitor cycles are separated by blank lines for readability.");

  runFullApiTest();
  lastFullApiTestMs = millis();
  lastMonitorMs = millis();
}

void loop() {
  const unsigned long nowMs = millis();

  if (!deviceReady) {
    runFullApiTest();
    lastFullApiTestMs = millis();
    lastMonitorMs = millis();
    delay(1000);
    return;
  }

  if (nowMs - lastFullApiTestMs >= FULL_API_TEST_INTERVAL_MS) {
    runFullApiTest();
    lastFullApiTestMs = millis();
  }

  if (millis() - lastMonitorMs >= MONITOR_INTERVAL_MS) {
    runMonitorCycle();
    lastMonitorMs = millis();
  }

  delay(10);
}
