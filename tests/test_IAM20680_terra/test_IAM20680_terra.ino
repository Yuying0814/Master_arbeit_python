#include <Arduino.h>
#include <Wire.h>
#include <math.h>

#include "IAM20680HV.h"

constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 1;
constexpr uint8_t INT2_PIN = 16;
constexpr uint8_t INT1_PIN = 17;

constexpr uint8_t DATA_READY_INTERRUPT_MASK = 0x01;
constexpr uint8_t ALL_SUPPORTED_INTERRUPT_MASK = 0xE5;
constexpr uint8_t EXPECTED_WHO_AM_I = 0xFE;
constexpr unsigned long DATA_READY_TIMEOUT_MS = 250UL;
constexpr uint32_t I2C_TRANSACTION_TIMEOUT_MS = 100UL;
constexpr unsigned long FULL_API_TEST_INTERVAL_MS = 10000UL;
constexpr unsigned long MONITOR_INTERVAL_MS = 1000UL;
constexpr uint16_t SELF_TEST_SAMPLE_COUNT = 32;
constexpr unsigned long SELF_TEST_SETTLE_MS = 20UL;
constexpr unsigned long WOM_EVENT_TIMEOUT_MS = 5000UL;
constexpr uint8_t WOM_INTERRUPT_MASK = 0xE0;

enum class TestMode {
  API_TEST,
  WOM
};

// =========================================
// Change this selection before compiling the sketch. TestMode::API_TEST/TestMode::WOM
constexpr TestMode TEST_MODE = TestMode::API_TEST;
// =========================================

enum class PowerMode {
  SLEEP,
  ALL_AXIS_STANDBY,
  ACCEL_LOW_NOISE,
  GYRO_LOW_NOISE,
  SIX_AXIS_LOW_NOISE
};

IAM20680HV sensor(Wire);

bool firstFullApiTestPending = true;
unsigned long lastFullApiTestMs = 0;
unsigned long lastMonitorMs = 0;
uint16_t passCount = 0;
uint16_t failCount = 0;

void printHex8(uint8_t value) {
  if (value < 0x10) {
    Serial.print('0');
  }
  Serial.print(static_cast<unsigned int>(value), HEX);
}

void printBoolean(bool value) {
  Serial.print(value ? "1" : "0");
}

void logInfo(const char *message) {
  Serial.print("TEST_LOG: INFO: ");
  Serial.println(message);
}

void reportResult(const char *label, bool passed) {
  Serial.print("TEST_LOG: ");
  Serial.print(passed ? "PASS: " : "FAIL: ");
  Serial.println(label);

  if (passed) {
    ++passCount;
  } else {
    ++failCount;
  }
}

void reportExpectedFalse(const char *label, bool returnedTrue) {
  reportResult(label, !returnedTrue);
}

bool isFiniteFloat(float value) {
  return !isnan(value) && !isinf(value);
}

bool isFiniteVector(const Vector3f &value) {
  return isFiniteFloat(value.x) && isFiniteFloat(value.y) &&
         isFiniteFloat(value.z);
}

void printRawData(const RawData &data) {
  Serial.print("TEST_LOG: RAW accel=");
  Serial.print(data.accel_x);
  Serial.print(',');
  Serial.print(data.accel_y);
  Serial.print(',');
  Serial.print(data.accel_z);
  Serial.print(" temp=");
  Serial.print(data.temp);
  Serial.print(" gyro=");
  Serial.print(data.gyro_x);
  Serial.print(',');
  Serial.print(data.gyro_y);
  Serial.print(',');
  Serial.println(data.gyro_z);
}

void printScaledData(const Vector3f &accelG,
                     const Vector3f &gyroDps,
                     float temperatureC) {
  Serial.print("TEST_LOG: SCALED accel_g=");
  Serial.print(accelG.x, 4);
  Serial.print(',');
  Serial.print(accelG.y, 4);
  Serial.print(',');
  Serial.print(accelG.z, 4);
  Serial.print(" gyro_dps=");
  Serial.print(gyroDps.x, 4);
  Serial.print(',');
  Serial.print(gyroDps.y, 4);
  Serial.print(',');
  Serial.print(gyroDps.z, 4);
  Serial.print(" temp_c=");
  Serial.println(temperatureC, 4);
}

bool readFiniteScaledData(const char *label) {
  Vector3f accelG{};
  Vector3f gyroDps{};
  float temperatureC = 0.0f;
  const bool readOk = sensor.readScaledData(accelG, gyroDps, temperatureC);
  const bool valid = readOk && isFiniteVector(accelG) &&
                     isFiniteVector(gyroDps) && isFiniteFloat(temperatureC);
  reportResult(label, valid);

  if (readOk) {
    printScaledData(accelG, gyroDps, temperatureC);
  }
  return valid;
}

bool waitForDataReady(uint8_t &status) {
  const unsigned long startMs = millis();

  while (millis() - startMs < DATA_READY_TIMEOUT_MS) {
    if (!sensor.readInterruptStatus(status)) {
      return false;
    }
    if ((status & DATA_READY_INTERRUPT_MASK) != 0) {
      return true;
    }
    delay(2);
  }

  return false;
}

bool readAverageRawData(RawData &average, uint16_t sampleCount) {
  if (sampleCount == 0) {
    return false;
  }

  int64_t accelX = 0;
  int64_t accelY = 0;
  int64_t accelZ = 0;
  int64_t temperature = 0;
  int64_t gyroX = 0;
  int64_t gyroY = 0;
  int64_t gyroZ = 0;

  for (uint16_t i = 0; i < sampleCount; ++i) {
    RawData sample{};
    if (!sensor.readRawData(sample)) {
      return false;
    }
    accelX += sample.accel_x;
    accelY += sample.accel_y;
    accelZ += sample.accel_z;
    temperature += sample.temp;
    gyroX += sample.gyro_x;
    gyroY += sample.gyro_y;
    gyroZ += sample.gyro_z;
    delay(2);
  }

  average.accel_x = static_cast<int16_t>(accelX / sampleCount);
  average.accel_y = static_cast<int16_t>(accelY / sampleCount);
  average.accel_z = static_cast<int16_t>(accelZ / sampleCount);
  average.temp = static_cast<int16_t>(temperature / sampleCount);
  average.gyro_x = static_cast<int16_t>(gyroX / sampleCount);
  average.gyro_y = static_cast<int16_t>(gyroY / sampleCount);
  average.gyro_z = static_cast<int16_t>(gyroZ / sampleCount);
  return true;
}

void printSelfTestResponse(const RawData &baseline, const RawData &enabled) {
  Serial.print("TEST_LOG: SELF_TEST_RESPONSE_LSB accel=");
  Serial.print(static_cast<int32_t>(enabled.accel_x) - baseline.accel_x);
  Serial.print(',');
  Serial.print(static_cast<int32_t>(enabled.accel_y) - baseline.accel_y);
  Serial.print(',');
  Serial.print(static_cast<int32_t>(enabled.accel_z) - baseline.accel_z);
  Serial.print(" gyro=");
  Serial.print(static_cast<int32_t>(enabled.gyro_x) - baseline.gyro_x);
  Serial.print(',');
  Serial.print(static_cast<int32_t>(enabled.gyro_y) - baseline.gyro_y);
  Serial.print(',');
  Serial.println(static_cast<int32_t>(enabled.gyro_z) - baseline.gyro_z);
}

bool selfTestResponseIsNonZero(const RawData &baseline,
                               const RawData &enabled) {
  return enabled.accel_x != baseline.accel_x &&
         enabled.accel_y != baseline.accel_y &&
         enabled.accel_z != baseline.accel_z &&
         enabled.gyro_x != baseline.gyro_x &&
         enabled.gyro_y != baseline.gyro_y &&
         enabled.gyro_z != baseline.gyro_z;
}

void testIdentityAndLifecycle() {
  Serial.println("TEST_LOG: [SECTION] Identity and lifecycle");

  uint8_t whoAmI = 0;
  const bool identityReadOk = sensor.readWhoAmI(whoAmI);
  reportResult("readWhoAmI() succeeds", identityReadOk);
  reportResult("WHO_AM_I equals 0xFE",
               identityReadOk && whoAmI == EXPECTED_WHO_AM_I);

  if (identityReadOk) {
    Serial.print("TEST_LOG: WHO_AM_I=0x");
    printHex8(whoAmI);
    Serial.println();
  }

  reportResult("lastError() is zero after successful read",
               sensor.lastError() == 0);

  const bool softResetOk = sensor.softReset();
  reportResult("softReset()", softResetOk);

  if (softResetOk) {
    whoAmI = 0;
    const bool postResetReadOk = sensor.readWhoAmI(whoAmI);
    reportResult("readWhoAmI() after softReset()",
                 postResetReadOk && whoAmI == EXPECTED_WHO_AM_I);
  }

  reportResult("begin() after softReset()", sensor.begin());
  reportResult("lastError() is zero after begin()", sensor.lastError() == 0);
}

void testPowerAndClockConfiguration() {
  Serial.println("TEST_LOG: [SECTION] Power and clock configuration");

  reportResult("setClockSource(INTERNAL)",
               sensor.setClockSource(ClockSource::INTERNAL));
  reportResult("setClockSource(AUTO)",
               sensor.setClockSource(ClockSource::AUTO));
  reportResult("setClockSource(AUTO2)",
               sensor.setClockSource(ClockSource::AUTO2));
  reportResult("setClockSource(AUTO3)",
               sensor.setClockSource(ClockSource::AUTO3));
  reportResult("setClockSource(AUTO4)",
               sensor.setClockSource(ClockSource::AUTO4));
  reportResult("setClockSource(AUTO5)",
               sensor.setClockSource(ClockSource::AUTO5));
  reportResult("setClockSource(INTERNAL_ALT)",
               sensor.setClockSource(ClockSource::INTERNAL_ALT));
  reportResult("restore clock source to AUTO",
               sensor.setClockSource(ClockSource::AUTO));

  reportResult("setSleep(true)", sensor.setSleep(true));
  reportResult("setSleep(false)", sensor.setSleep(false));

  reportResult("setAxisStandby(all axes)", sensor.setAxisStandby(0x3F));
  reportResult("setAxisStandby(clear all axes)", sensor.setAxisStandby(0x00));

  reportResult("setSampleRateDivider(9)", sensor.setSampleRateDivider(9));
  reportResult("restore sample-rate divider to 0",
               sensor.setSampleRateDivider(0));

  logInfo("ClockSource::STOP is not executed because it stops the timing generator.");
}

bool configurePowerMode(PowerMode mode) {
  switch (mode) {
    case PowerMode::SLEEP:
      return sensor.setAxisStandby(0x00) && sensor.setSleep(true);
    case PowerMode::ALL_AXIS_STANDBY:
      return sensor.setSleep(false) && sensor.setAxisStandby(0x3F);
    case PowerMode::ACCEL_LOW_NOISE:
      return sensor.setSleep(false) && sensor.setAxisStandby(0x07);
    case PowerMode::GYRO_LOW_NOISE:
      return sensor.setSleep(false) && sensor.setAxisStandby(0x38);
    case PowerMode::SIX_AXIS_LOW_NOISE:
      return sensor.setSleep(false) && sensor.setAxisStandby(0x00);
  }
  return false;
}

const char *powerModeName(PowerMode mode) {
  switch (mode) {
    case PowerMode::SLEEP:
      return "SLEEP";
    case PowerMode::ALL_AXIS_STANDBY:
      return "ALL_AXIS_STANDBY";
    case PowerMode::ACCEL_LOW_NOISE:
      return "ACCEL_LOW_NOISE";
    case PowerMode::GYRO_LOW_NOISE:
      return "GYRO_LOW_NOISE";
    case PowerMode::SIX_AXIS_LOW_NOISE:
      return "SIX_AXIS_LOW_NOISE";
  }
  return "UNKNOWN";
}

void testPowerModeFunctionality() {
  Serial.println("TEST_LOG: [SECTION] Power-mode switching and functionality");
  logInfo("Power modes are composed from the driver's setSleep() and setAxisStandby() APIs.");

  const PowerMode modes[] = {
      PowerMode::SIX_AXIS_LOW_NOISE,
      PowerMode::ACCEL_LOW_NOISE,
      PowerMode::GYRO_LOW_NOISE,
      PowerMode::SIX_AXIS_LOW_NOISE,
      PowerMode::ALL_AXIS_STANDBY,
      PowerMode::SLEEP,
      PowerMode::SIX_AXIS_LOW_NOISE};

  for (PowerMode mode : modes) {
    Serial.print("TEST_LOG: POWER_MODE=");
    Serial.println(powerModeName(mode));

    const bool configured = configurePowerMode(mode);
    reportResult("configure selected power mode", configured);
    if (!configured) {
      continue;
    }

    delay(20);
    RawData rawData{};
    Vector3f accelG{};
    Vector3f gyroDps{};
    float temperatureC = 0.0f;
    const bool rawOk = sensor.readRawData(rawData);
    const bool scaledOk = sensor.readScaledData(accelG, gyroDps, temperatureC);
    const bool valuesFinite = isFiniteVector(accelG) &&
                              isFiniteVector(gyroDps) &&
                              isFiniteFloat(temperatureC);
    reportResult("read data after power-mode switch",
                 rawOk && scaledOk && valuesFinite);
    if (rawOk) {
      printRawData(rawData);
    }
    if (scaledOk) {
      printScaledData(accelG, gyroDps, temperatureC);
    }
  }

  reportResult("restore six-axis low-noise mode",
               configurePowerMode(PowerMode::SIX_AXIS_LOW_NOISE));
  logInfo("The public driver has no getPowerMode() or register-read API; this test verifies successful mode transitions and data-path behavior through the public API.");
}

void testSensorConfiguration() {
  Serial.println("TEST_LOG: [SECTION] Gyroscope and accelerometer configuration");

  const GyroRange gyroRanges[] = {
      GyroRange::DPS_125,
      GyroRange::DPS_250,
      GyroRange::DPS_500,
      GyroRange::DPS_1000};

  for (const GyroRange range : gyroRanges) {
    const bool configured = sensor.setGyroConfig(range, 0, 3);
    reportResult("setGyroConfig(valid range)", configured);
    if (configured) {
      readFiniteScaledData("readScaledData() after gyro-range configuration");
    }
  }

  reportExpectedFalse("setGyroConfig() rejects invalid FCHOICE", 
                     sensor.setGyroConfig(GyroRange::DPS_125, 4, 0));
  reportExpectedFalse("setGyroConfig() rejects invalid DLPF", 
                     sensor.setGyroConfig(GyroRange::DPS_125, 0, 8));

  const AccelRange accelRanges[] = {
      AccelRange::G_2,
      AccelRange::G_4,
      AccelRange::G_8,
      AccelRange::G_16};

  uint8_t womAverage = 0;
  for (const AccelRange range : accelRanges) {
    const bool configured = sensor.setAccelConfig(
        range, (womAverage & 0x01) != 0, 3, womAverage);
    reportResult("setAccelConfig(valid range)", configured);
    if (configured) {
      readFiniteScaledData("readScaledData() after accel-range configuration");
    }
    ++womAverage;
  }

  reportExpectedFalse("setAccelConfig() rejects invalid DLPF",
                     sensor.setAccelConfig(AccelRange::G_2, false, 8, 0));
  reportExpectedFalse("setAccelConfig() rejects invalid WoM averaging",
                     sensor.setAccelConfig(AccelRange::G_2, false, 0, 4));

  reportResult("restore gyroscope configuration",
               sensor.setGyroConfig(GyroRange::DPS_125, 0, 0));
  reportResult("restore accelerometer configuration",
               sensor.setAccelConfig(AccelRange::G_2, false, 0, 0));
}

void testSignalPathAndFsync() {
  Serial.println("TEST_LOG: [SECTION] Signal paths and FSYNC");

  reportResult("configureFsync(disabled, active-high)",
               sensor.configureFsync(0, false, false));
  reportResult("configureFsync(enabled, active-low)",
               sensor.configureFsync(3, true, true));

  bool fsyncActive = false;
  const bool fsyncStatusOk = sensor.readFsyncStatus(fsyncActive);
  reportResult("readFsyncStatus()", fsyncStatusOk);
  if (fsyncStatusOk) {
    Serial.print("TEST_LOG: FSYNC active=");
    printBoolean(fsyncActive);
    Serial.println();
  }

  reportExpectedFalse("configureFsync() rejects invalid sync selection",
                     sensor.configureFsync(8, false, false));

  reportResult("restoreFsyncConfiguration",
               sensor.configureFsync(0, false, false));

  reportResult("resetSignalPaths(accel)",
               sensor.resetSignalPaths(true, false));
  reportResult("resetSignalPaths(temp)",
               sensor.resetSignalPaths(false, true));
  reportResult("resetSignalPaths(accel, temp)",
               sensor.resetSignalPaths(true, true));
  delay(5);

  reportResult("resetAndClearSensorPaths()",
               sensor.resetAndClearSensorPaths());
  delay(5);
  reportResult("begin() after signal-path reset",
               sensor.begin());
}

void testDataAcquisition() {
  Serial.println("TEST_LOG: [SECTION] Raw and scaled data acquisition");

  RawData rawData{};
  const bool rawOk = sensor.readRawData(rawData);
  reportResult("readRawData()", rawOk);
  if (rawOk) {
    printRawData(rawData);
  }

  readFiniteScaledData("readScaledData() returns finite values");
}

void testInterruptConfigurationAndStatus() {
  Serial.println("TEST_LOG: [SECTION] Interrupt configuration and status");

  const InterruptPinConfig activeHighLatched{
      false, false, true, false, false, false, false};
  const InterruptPinConfig activeLowRouted{
      true, true, false, true, true, true, true};

  reportResult("configureInterruptPin(active-high, INT1)",
               sensor.configureInterruptPin(activeHighLatched));
  reportResult("configureInterruptPin(active-low, routed INT2)",
               sensor.configureInterruptPin(activeLowRouted));
  reportResult("restore interrupt pin configuration",
               sensor.configureInterruptPin(activeHighLatched));

  reportResult("setInterruptEnables(all supported sources)",
               sensor.setInterruptEnables(ALL_SUPPORTED_INTERRUPT_MASK));
  reportResult("setInterruptEnables(data-ready only)",
               sensor.setInterruptEnables(DATA_READY_INTERRUPT_MASK));

  delay(10);
  Serial.print("TEST_LOG: INT1 level=");
  Serial.print(digitalRead(INT1_PIN));
  Serial.print(" INT2 level=");
  Serial.println(digitalRead(INT2_PIN));

  uint8_t interruptStatus = 0;
  const bool dataReadyObserved = waitForDataReady(interruptStatus);
  reportResult("readInterruptStatus() observes DATA_RDY_INT",
               dataReadyObserved &&
                   (interruptStatus & DATA_READY_INTERRUPT_MASK) != 0);
  if (dataReadyObserved) {
    Serial.print("TEST_LOG: INT_STATUS=0x");
    printHex8(interruptStatus);
    Serial.println();
  }

  reportResult("disable all interrupt sources",
               sensor.setInterruptEnables(0x00));
  reportResult("restore default interrupt pin configuration",
               sensor.configureInterruptPin(
                   InterruptPinConfig{false, false, false, false,
                                      false, false, false}));
}

void testSelfTestAndOffsets() {
  Serial.println("TEST_LOG: [SECTION] Self-test and offset APIs");

  uint8_t gyroCodes[3] = {0, 0, 0};
  uint8_t accelCodes[3] = {0, 0, 0};
  const bool selfTestCodeReadOk =
      sensor.readSelfTestCodes(gyroCodes, accelCodes);
  reportResult("readSelfTestCodes()", selfTestCodeReadOk);
  if (selfTestCodeReadOk) {
    Serial.print("TEST_LOG: GYRO_ST=0x");
    printHex8(gyroCodes[0]);
    Serial.print(" 0x");
    printHex8(gyroCodes[1]);
    Serial.print(" 0x");
    printHex8(gyroCodes[2]);
    Serial.print(" ACCEL_ST=0x");
    printHex8(accelCodes[0]);
    Serial.print(" 0x");
    printHex8(accelCodes[1]);
    Serial.print(" 0x");
    printHex8(accelCodes[2]);
    Serial.println();
  }

  reportExpectedFalse("setSelfTest() rejects invalid gyro mask",
                     sensor.setSelfTest(0x08, 0x00));
  reportExpectedFalse("setSelfTest() rejects invalid accel mask",
                     sensor.setSelfTest(0x00, 0x08));
  reportResult("setSelfTest(all axes)", sensor.setSelfTest(0x07, 0x07));
  delay(20);
  reportResult("clear self-test axes", sensor.setSelfTest(0x00, 0x00));

  reportExpectedFalse("setAccelOffsets() rejects values outside 15-bit range",
                     sensor.setAccelOffsets(Vector3i16{0x4000, 0, 0}));

  reportResult("setGyroOffsets(valid values)",
               sensor.setGyroOffsets(Vector3i16{4, -4, 8}));
  reportResult("setAccelOffsets(valid values)",
               sensor.setAccelOffsets(Vector3i16{8, -8, 16}));

  logInfo("Offset registers are write-only through the public API; a device reset restores the test state.");
  reportResult("softReset() after self-test and offsets", sensor.softReset());
  logInfo("Starting begin() after self-test and offsets");
  const bool beginAfterOffsetsOk = sensor.begin();
  reportResult("begin() after self-test and offsets", beginAfterOffsetsOk);
}

bool testSelfTestResponse() {
  Serial.println("TEST_LOG: [SECTION] Self-test response measurement");
  logInfo("Self-test response is measured as enabled output minus normal output.");

  const bool clearBeforeOk = sensor.setSelfTest(0x00, 0x00);
  reportResult("clear self-test before baseline measurement", clearBeforeOk);
  if (!clearBeforeOk) {
    return false;
  }
  delay(SELF_TEST_SETTLE_MS);

  RawData baseline{};
  const bool baselineOk = readAverageRawData(baseline, SELF_TEST_SAMPLE_COUNT);
  reportResult("read normal-output self-test baseline", baselineOk);
  if (!baselineOk) {
    reportResult("disable self-test after response measurement",
                 sensor.setSelfTest(0x00, 0x00));
    return false;
  }

  const bool enableSelfTestOk = sensor.setSelfTest(0x07, 0x07);
  reportResult("enable self-test on all axes", enableSelfTestOk);
  if (!enableSelfTestOk) {
    reportResult("disable self-test after enable failure",
                 sensor.setSelfTest(0x00, 0x00));
    return false;
  }
  delay(SELF_TEST_SETTLE_MS);

  RawData enabled{};
  const bool enabledOk = readAverageRawData(enabled, SELF_TEST_SAMPLE_COUNT);
  reportResult("read self-test-enabled output", enabledOk);
  bool responseOk = false;
  if (enabledOk) {
    printSelfTestResponse(baseline, enabled);
    responseOk = selfTestResponseIsNonZero(baseline, enabled);
    reportResult("self-test response is non-zero on all six axes", responseOk);
  }

  const bool disableSelfTestOk = sensor.setSelfTest(0x00, 0x00);
  reportResult("disable self-test after response measurement", disableSelfTestOk);
  logInfo("The non-zero response check is a functional sanity check; PDF limit-based compliance requires the factory limits and calibration data.");
  return enabledOk && responseOk && disableSelfTestOk;
}

void testWakeOnMotion(bool waitForPhysicalEvent) {
  Serial.println("TEST_LOG: [SECTION] Wake-on-Motion");

  const InterruptPinConfig womInterruptConfig{
      false, false, true, false, false, false, true};
  reportResult("configureInterruptPin(WoM routed to INT2)",
               sensor.configureInterruptPin(womInterruptConfig));

  const WakeOnMotionConfig womConfig{
      8, 12, 16,
      true, true, true,
      true,
      8};

  const bool womOk = sensor.configureWakeOnMotion(womConfig);
  reportResult("configureWakeOnMotion(all axes)", womOk);

  if (womOk) {
    uint8_t interruptStatus = 0;
    const bool statusReadOk = sensor.readInterruptStatus(interruptStatus);
    reportResult("readInterruptStatus() after WoM configuration",
                 statusReadOk);

    Serial.print("TEST_LOG: WoM INT1 level=");
    Serial.print(digitalRead(INT1_PIN));
    Serial.print(" INT2 level=");
    Serial.println(digitalRead(INT2_PIN));
  }

  if (!waitForPhysicalEvent) {
    logInfo("API_TEST mode checks WoM configuration and status access; physical event waiting is enabled only in WOM mode.");
    reportResult("softReset() after WoM configuration", sensor.softReset());
    reportResult("begin() after WoM configuration", sensor.begin());
    return;
  }

  logInfo("Move or shake the board during the next 5 seconds to verify the physical WoM event.");
  bool womEventDetected = false;
  uint8_t womStatus = 0;
  const unsigned long startMs = millis();
  while (millis() - startMs < WOM_EVENT_TIMEOUT_MS) {
    const bool statusReadOk = sensor.readInterruptStatus(womStatus);
    const bool int2Active = digitalRead(INT2_PIN) == HIGH;
    if ((statusReadOk && (womStatus & WOM_INTERRUPT_MASK) != 0) ||
        int2Active) {
      womEventDetected = true;
      Serial.print("TEST_LOG: WOM_EVENT status=0x");
      printHex8(womStatus);
      Serial.print(" INT2=");
      Serial.println(digitalRead(INT2_PIN));
      break;
    }
    delay(10);
  }

  if (womEventDetected) {
    Serial.println("TEST_LOG: WOM_PHYSICAL_RESULT=PASS");
  } else {
    Serial.println("TEST_LOG: WOM_PHYSICAL_RESULT=NOT_TRIGGERED");
    logInfo("WoM physical result is not counted as an API failure when no motion occurs during the timeout.");
  }
  reportResult("softReset() after WoM configuration", sensor.softReset());
  reportResult("begin() after WoM configuration", sensor.begin());
}

void runMonitorCycle() {
  Serial.println();
  Serial.println("TEST_LOG: [MONITOR] one-second sensor status");

  uint8_t whoAmI = 0;
  const bool identityOk = sensor.readWhoAmI(whoAmI);
  Serial.print("TEST_LOG: MONITOR WHO_AM_I=");
  if (identityOk) {
    Serial.print("0x");
    printHex8(whoAmI);
  } else {
    Serial.print("READ_ERROR");
  }
  Serial.println();

  RawData rawData{};
  const bool rawOk = sensor.readRawData(rawData);
  if (rawOk) {
    Serial.print("TEST_LOG: MONITOR RAW accel=");
    Serial.print(rawData.accel_x);
    Serial.print(',');
    Serial.print(rawData.accel_y);
    Serial.print(',');
    Serial.print(rawData.accel_z);
    Serial.print(" temp=");
    Serial.print(rawData.temp);
    Serial.print(" gyro=");
    Serial.print(rawData.gyro_x);
    Serial.print(',');
    Serial.print(rawData.gyro_y);
    Serial.print(',');
    Serial.println(rawData.gyro_z);
  } else {
    Serial.println("TEST_LOG: MONITOR RAW=READ_ERROR");
  }

  Vector3f accelG{};
  Vector3f gyroDps{};
  float temperatureC = 0.0f;
  const bool scaledOk = sensor.readScaledData(
      accelG, gyroDps, temperatureC);
  if (scaledOk) {
    Serial.print("TEST_LOG: MONITOR SCALED accel_g=");
    Serial.print(accelG.x, 4);
    Serial.print(',');
    Serial.print(accelG.y, 4);
    Serial.print(',');
    Serial.print(accelG.z, 4);
    Serial.print(" gyro_dps=");
    Serial.print(gyroDps.x, 4);
    Serial.print(',');
    Serial.print(gyroDps.y, 4);
    Serial.print(',');
    Serial.print(gyroDps.z, 4);
    Serial.print(" temp_c=");
    Serial.println(temperatureC, 4);
  } else {
    Serial.println("TEST_LOG: MONITOR SCALED=READ_ERROR");
  }

  uint8_t interruptStatus = 0;
  const bool interruptStatusOk = sensor.readInterruptStatus(interruptStatus);
  Serial.print("TEST_LOG: MONITOR INT_STATUS=");
  if (interruptStatusOk) {
    Serial.print("0x");
    printHex8(interruptStatus);
  } else {
    Serial.print("READ_ERROR");
  }
  Serial.print(" DATA_RDY=");
  printBoolean(interruptStatusOk &&
               (interruptStatus & DATA_READY_INTERRUPT_MASK) != 0);
  Serial.println(" (read-to-clear)");

  bool fsyncActive = false;
  const bool fsyncStatusOk = sensor.readFsyncStatus(fsyncActive);
  Serial.print("TEST_LOG: MONITOR FSYNC=");
  if (fsyncStatusOk) {
    printBoolean(fsyncActive);
  } else {
    Serial.print("READ_ERROR");
  }
  Serial.println(" (read-to-clear)");

  Serial.print("TEST_LOG: MONITOR INT1_GPIO17=");
  Serial.print(digitalRead(INT1_PIN));
  Serial.print(" INT2_GPIO16=");
  Serial.println(digitalRead(INT2_PIN));

  Serial.print("TEST_LOG: MONITOR read_ok raw=");
  printBoolean(rawOk);
  Serial.print(" scaled=");
  printBoolean(scaledOk);
  Serial.print(" lastError=0x");
  printHex8(sensor.lastError());
  Serial.println();
}

bool runFullApiTest() {
  passCount = 0;
  failCount = 0;

  Serial.println("TEST_LOG: ========================================");
  Serial.println("TEST_LOG: IAM20680HV I2C driver API test");
  Serial.println("TEST_LOG: ========================================");
  Serial.println("TEST_LOG: I2C SDA=GPIO0 SCL=GPIO1 INT1=GPIO17 INT2=GPIO16");
  Serial.println("TEST_LOG: I2C address uses the driver's default 0x68");

  bool selfTestPassed = false;
  const bool beginOk = sensor.begin();
  reportResult("begin()", beginOk);
  if (!beginOk) {
    logInfo("Initialization failed; remaining hardware tests were not attempted.");
  } else {
    selfTestPassed = testSelfTestResponse();
    Serial.print("TEST_LOG: SELF_TEST_RESULT=");
    Serial.println(selfTestPassed ? "PASS" : "FAIL");
    testIdentityAndLifecycle();
    testPowerAndClockConfiguration();
    testPowerModeFunctionality();
    testSensorConfiguration();
    testSignalPathAndFsync();
    testDataAcquisition();
    testInterruptConfigurationAndStatus();
    testSelfTestAndOffsets();
    testWakeOnMotion(false);
  }

  if (!beginOk) {
    Serial.println("TEST_LOG: SELF_TEST_RESULT=NOT_RUN");
  }

  Serial.println("TEST_LOG: ========================================");
  Serial.print("TEST_LOG: SUMMARY PASS=");
  Serial.print(passCount);
  Serial.print(" FAIL=");
  Serial.println(failCount);
  Serial.println("TEST_LOG: ========================================");

  return failCount == 0;
}

bool runWomTest() {
  passCount = 0;
  failCount = 0;

  Serial.println("TEST_LOG: ========================================");
  Serial.println("TEST_LOG: IAM20680HV WoM functional test");
  Serial.println("TEST_LOG: ========================================");
  Serial.println("TEST_LOG: I2C SDA=GPIO0 SCL=GPIO1 INT2=GPIO16");

  const bool beginOk = sensor.begin();
  reportResult("begin() before WoM test", beginOk);
  if (beginOk) {
    testWakeOnMotion(true);
  }

  Serial.println("TEST_LOG: ========================================");
  Serial.print("TEST_LOG: WOM_API_SUMMARY PASS=");
  Serial.print(passCount);
  Serial.print(" FAIL=");
  Serial.println(failCount);
  Serial.println("TEST_LOG: ========================================");
  return failCount == 0;
}

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1000);
  delay(100);

  Wire.setSDA(I2C_SDA_PIN);
  Wire.setSCL(I2C_SCL_PIN);
  Wire.begin();
  Wire.setTimeout(I2C_TRANSACTION_TIMEOUT_MS, true);

  pinMode(INT1_PIN, INPUT);
  pinMode(INT2_PIN, INPUT);

  Serial.println("TEST_LOG: IAM20680HV automatic test monitor started.");
  Serial.print("TEST_LOG: Selected test mode: ");
  Serial.println(TEST_MODE == TestMode::WOM ? "WOM" : "API_TEST");
  Serial.println("TEST_LOG: Selected test: immediately and every 10 seconds.");
  Serial.println("TEST_LOG: Sensor monitor: every 1 second in API_TEST mode.");
  Serial.println("TEST_LOG: I2C transaction timeout: 100 ms.");
}

void loop() {
  const unsigned long nowMs = millis();

  if (firstFullApiTestPending ||
      nowMs - lastFullApiTestMs >= FULL_API_TEST_INTERVAL_MS) {
    firstFullApiTestPending = false;
    const bool passed = TEST_MODE == TestMode::WOM ? runWomTest()
                                                   : runFullApiTest();
    Serial.print("TEST_LOG: ");
    Serial.print(TEST_MODE == TestMode::WOM ? "WOM_TEST_RESULT="
                                            : "FULL_API_TEST_RESULT=");
    Serial.println(passed ? "PASS" : "FAIL");
    lastFullApiTestMs = millis();
    lastMonitorMs = lastFullApiTestMs;
  }

  if (millis() - lastMonitorMs >= MONITOR_INTERVAL_MS) {
    runMonitorCycle();
    lastMonitorMs = millis();
  }
}
