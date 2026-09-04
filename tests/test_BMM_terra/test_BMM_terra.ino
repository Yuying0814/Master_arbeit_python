#include <Arduino.h>
#include <Wire.h>
#include <stdio.h>

#include "BMM350.h"

namespace {

constexpr uint8_t PIN_I2C_SDA = 0;
constexpr uint8_t PIN_I2C_SCL = 1;
constexpr uint8_t PIN_BMM350_INT = 18;

constexpr uint8_t BMM350_ADDRESS_ADSEL_LOW = 0x14;
constexpr uint8_t BMM350_ADDRESS_ADSEL_HIGH = 0x15;

constexpr uint32_t MONITOR_INTERVAL_MS = 2000;
constexpr uint32_t FULL_TEST_INTERVAL_MS = 30000;
constexpr uint16_t DATA_READY_TIMEOUT_MS = 750;

BMM350 sensorLow(Wire, BMM350_ADDRESS_ADSEL_LOW);
BMM350 sensorHigh(Wire, BMM350_ADDRESS_ADSEL_HIGH);
BMM350 *sensorPtr = &sensorLow;
#define sensor (*sensorPtr)
uint8_t activeAddress = BMM350_ADDRESS_ADSEL_LOW;
bool sensorInitialized = false;

uint32_t testPassCount = 0;
uint32_t testFailCount = 0;
uint32_t testSkipCount = 0;

uint32_t lastMonitorMillis = 0;
uint32_t lastFullTestMillis = 0;
uint32_t fullTestNumber = 0;

const char *statusName(Status status) {
  switch (status) {
    case Status::Ok:
      return "OK";
    case Status::BusError:
      return "BUS_ERROR";
    case Status::Timeout:
      return "TIMEOUT";
    case Status::InvalidArgument:
      return "INVALID_ARGUMENT";
    case Status::ChipIdMismatch:
      return "CHIP_ID_MISMATCH";
    case Status::PmuBusy:
      return "PMU_BUSY";
    case Status::PmuIllegal:
      return "PMU_ILLEGAL";
    case Status::ErrRegSet:
      return "ERR_REG_SET";
    case Status::Unknown:
      return "UNKNOWN";
    default:
      return "UNKNOWN_STATUS";
  }
}

const char *odrName(Odr odr) {
  switch (odr) {
    case Odr::ODR_400HZ:
      return "400 Hz";
    case Odr::ODR_200HZ:
      return "200 Hz";
    case Odr::ODR_100HZ:
      return "100 Hz";
    case Odr::ODR_50HZ:
      return "50 Hz";
    case Odr::ODR_25HZ:
      return "25 Hz";
    case Odr::ODR_12_5HZ:
      return "12.5 Hz";
    case Odr::ODR_6_25HZ:
      return "6.25 Hz";
    case Odr::ODR_3_125HZ:
      return "3.125 Hz";
    case Odr::ODR_1_5625HZ:
      return "1.5625 Hz";
    default:
      return "Unknown ODR";
  }
}

const char *averagingName(Averaging averaging) {
  switch (averaging) {
    case Averaging::AVG_0:
      return "1 sample";
    case Averaging::AVG_2:
      return "2 samples";
    case Averaging::AVG_4:
      return "4 samples";
    case Averaging::AVG_8:
      return "8 samples";
    default:
      return "Unknown averaging";
  }
}

const char *powerModeName(PmuCommand command) {
  switch (command) {
    case PmuCommand::Suspend:
      return "Suspend";
    case PmuCommand::Normal:
      return "Normal";
    case PmuCommand::FM:
      return "Forced";
    case PmuCommand::FMFast:
      return "Forced-fast";
    case PmuCommand::FluxGuideReset:
      return "Flux-guide-reset";
    case PmuCommand::FluxGuideResetFast:
      return "Flux-guide-reset-fast";
    case PmuCommand::BitReset:
      return "Bit-reset";
    case PmuCommand::BitResetFast:
      return "Bit-reset-fast";
    case PmuCommand::UpdOae:
      return "Update-ODR-averaging";
    default:
      return "Unknown PMU command";
  }
}

void printHex8(uint8_t value) {
  if (value < 0x10) {
    Serial.print('0');
  }
  Serial.print(value, HEX);
}

void printTestSummaryLine() {
  Serial.print("[SUMMARY] pass=");
  Serial.print(testPassCount);
  Serial.print(" fail=");
  Serial.print(testFailCount);
  Serial.print(" skipped=");
  Serial.println(testSkipCount);
}

void reportStatus(const char *label, Status actual) {
  Serial.print(actual == Status::Ok ? "[PASS] " : "[FAIL] ");
  Serial.print(label);
  Serial.print(" -> ");
  Serial.println(statusName(actual));

  if (actual == Status::Ok) {
    ++testPassCount;
  } else {
    ++testFailCount;
  }
}

void reportExpectedStatus(const char *label, Status actual, Status expected) {
  const bool passed = actual == expected;

  Serial.print(passed ? "[PASS] " : "[FAIL] ");
  Serial.print(label);
  Serial.print(" -> actual=");
  Serial.print(statusName(actual));
  Serial.print(" expected=");
  Serial.println(statusName(expected));

  if (passed) {
    ++testPassCount;
  } else {
    ++testFailCount;
  }
}

void reportCondition(const char *label, bool passed, const char *details) {
  Serial.print(passed ? "[PASS] " : "[FAIL] ");
  Serial.print(label);
  if (details != nullptr && details[0] != '\0') {
    Serial.print(" -> ");
    Serial.print(details);
  }
  Serial.println();

  if (passed) {
    ++testPassCount;
  } else {
    ++testFailCount;
  }
}

void reportSkipped(const char *label, const char *reason) {
  Serial.print("[SKIP] ");
  Serial.print(label);
  Serial.print(" -> ");
  Serial.println(reason);
  ++testSkipCount;
}

void printMeasurement(const RawSample &sample, const char *prefix) {
  Serial.print(prefix);
  Serial.print(" X=");
  Serial.print(static_cast<long>(sample.x));
  Serial.print(" Y=");
  Serial.print(static_cast<long>(sample.y));
  Serial.print(" Z=");
  Serial.print(static_cast<long>(sample.z));
  Serial.print(" T=");
  Serial.print(static_cast<long>(sample.temperature));
  Serial.print(" C, sensortime=");
  Serial.println(static_cast<unsigned long>(sample.sensortime));
}

bool probeAddress(uint8_t address) {
  Wire.beginTransmission(address);
  const uint8_t error = Wire.endTransmission();
  return error == 0;
}

bool selectSensorAddress() {
  Serial.println("[SETUP] Probing BMM350 I2C address...");

  if (probeAddress(BMM350_ADDRESS_ADSEL_LOW)) {
    sensorPtr = &sensorLow;
    activeAddress = BMM350_ADDRESS_ADSEL_LOW;
    Serial.print("[SETUP] Found BMM350 at 0x");
    printHex8(activeAddress);
    Serial.println();
    return true;
  }

  if (probeAddress(BMM350_ADDRESS_ADSEL_HIGH)) {
    sensorPtr = &sensorHigh;
    activeAddress = BMM350_ADDRESS_ADSEL_HIGH;
    Serial.print("[SETUP] Found BMM350 at 0x");
    printHex8(activeAddress);
    Serial.println();
    return true;
  }

  Serial.println("[SETUP] No BMM350 responded at 0x14 or 0x15.");
  return false;
}

Status waitForDataReady(uint16_t timeoutMs, bool &observedReady) {
  observedReady = false;
  const uint32_t start = millis();

  while (static_cast<uint32_t>(millis() - start) < timeoutMs) {
    bool ready = false;
    const Status status = sensor.dataReady(ready);
    if (status != Status::Ok) {
      return status;
    }
    if (ready) {
      observedReady = true;
      return Status::Ok;
    }
    delay(2);
  }

  return Status::Timeout;
}

Status observeNoContinuousData(uint16_t observationMs, bool &readyAfterObservation) {
  bool pendingReady = false;
  Status status = sensor.dataReady(pendingReady);
  if (status != Status::Ok) {
    return status;
  }

  delay(observationMs);
  status = sensor.dataReady(readyAfterObservation);
  return status;
}

void reportReadyExpectation(const char *label,
                            Status status,
                            bool observedReady,
                            bool expectedReady) {
  char details[96];
  snprintf(details,
           sizeof(details),
           "status=%s, ready=%s, expected=%s",
           statusName(status),
           observedReady ? "true" : "false",
           expectedReady ? "true" : "false");
  reportCondition(label,
                  status == Status::Ok && observedReady == expectedReady,
                  details);
}

bool setAndVerifyOdrAveraging(Odr odr, Averaging averaging, const char *label) {
  Status status = sensor.setOdrAveraging(odr, averaging, 100);
  reportStatus(label, status);
  if (status != Status::Ok) {
    return false;
  }

  Odr effectiveOdr = Odr::ODR_100HZ;
  Averaging effectiveAveraging = Averaging::AVG_0;
  status = sensor.getEffectiveOdrAveraging(effectiveOdr, effectiveAveraging);
  reportStatus("getEffectiveOdrAveraging()", status);

  const bool matches = status == Status::Ok &&
                       effectiveOdr == odr &&
                       effectiveAveraging == averaging;
  char details[128];
  snprintf(details,
           sizeof(details),
           "requested=%s/%s, effective=%s/%s",
           odrName(odr),
           averagingName(averaging),
           odrName(effectiveOdr),
           averagingName(effectiveAveraging));
  reportCondition("ODR and averaging getter matches the requested configuration",
                  matches,
                  details);
  return matches;
}

void printSelfTestResult(const SelfTestResult &result, uint8_t axis) {
  Serial.print("[INFO] Self-test axis ");
  Serial.print(axis);
  Serial.print(" baseline(X,Y,Z)=(");
  Serial.print(static_cast<long>(result.baseline.x));
  Serial.print(",");
  Serial.print(static_cast<long>(result.baseline.y));
  Serial.print(",");
  Serial.print(static_cast<long>(result.baseline.z));
  Serial.print(") stimulated(X,Y,Z)=(");
  Serial.print(static_cast<long>(result.stimulated.x));
  Serial.print(",");
  Serial.print(static_cast<long>(result.stimulated.y));
  Serial.print(",");
  Serial.print(static_cast<long>(result.stimulated.z));
  Serial.print(") delta(X,Y,Z)=(");
  Serial.print(static_cast<long>(result.delta.x));
  Serial.print(",");
  Serial.print(static_cast<long>(result.delta.y));
  Serial.print(",");
  Serial.print(static_cast<long>(result.delta.z));
  Serial.println(")");
}

void testIdentityAndStatus() {
  Serial.println("\n[TEST GROUP] Identity and status APIs");

  uint8_t chipId = 0;
  Status status = sensor.chipId(chipId);
  reportStatus("chipId()", status);
  if (status == Status::Ok) {
    Serial.print("[INFO] CHIP_ID=0x");
    printHex8(chipId);
    Serial.println();
    reportCondition("CHIP_ID is BMM350 value 0x33", chipId == 0x33, "expected=0x33");
  }

  uint8_t revision = 0;
  status = sensor.transducerRevision(revision);
  reportStatus("transducerRevision()", status);
  if (status == Status::Ok) {
    Serial.print("[INFO] Transducer revision=0x");
    printHex8(revision);
    Serial.println();
  }

  bool error = false;
  status = sensor.readAndClearError(error);
  reportStatus("readAndClearError()", status);
  if (status == Status::Ok) {
    Serial.print("[INFO] Device error was ");
    Serial.println(error ? "present and cleared" : "not present");
  }

  uint8_t i3cError = 0;
  status = sensor.readI3cError(i3cError);
  reportStatus("readI3cError()", status);
  if (status == Status::Ok) {
    Serial.print("[INFO] I3C error register=0x");
    printHex8(i3cError);
    Serial.println();
  }
}

void testPowerModeTransitions() {
  Serial.println("\n[TEST GROUP] Power-mode transitions and behavior");

  Status status = sensor.setPowerMode(PmuCommand::Suspend, 100);
  reportStatus("setPowerMode(Suspend)", status);

  bool ready = false;
  status = observeNoContinuousData(60, ready);
  reportReadyExpectation("Suspend mode stops continuous data", status, ready, false);

  status = sensor.setPowerMode(PmuCommand::Normal, 100);
  reportStatus("setPowerMode(Normal)", status);

  bool normalReady = false;
  status = waitForDataReady(DATA_READY_TIMEOUT_MS, normalReady);
  reportReadyExpectation("Normal mode produces data-ready", status, normalReady, true);

  RawSample firstSample{};
  status = sensor.readRawSample(firstSample);
  reportStatus("readRawSample() in Normal mode", status);
  if (status == Status::Ok) {
    printMeasurement(firstSample, "[MEASUREMENT] Normal sample 1:");
  }

  delay(25);
  bool secondReady = false;
  status = waitForDataReady(DATA_READY_TIMEOUT_MS, secondReady);
  reportReadyExpectation("Normal mode continues producing data", status, secondReady, true);

  RawSample secondSample{};
  status = sensor.readRawSample(secondSample);
  reportStatus("readRawSample() for second Normal sample", status);
  if (status == Status::Ok) {
    printMeasurement(secondSample, "[MEASUREMENT] Normal sample 2:");
    reportCondition("Normal mode sensortime advances", 
                    secondSample.sensortime != firstSample.sensortime,
                    "two consecutive samples compared");
  }

  status = sensor.setPowerMode(PmuCommand::Suspend, 100);
  reportStatus("setPowerMode(Suspend) after Normal mode", status);
  ready = false;
  status = observeNoContinuousData(60, ready);
  reportReadyExpectation("Returning to Suspend stops new continuous data", status, ready, false);
}

void testForcedModeBehavior() {
  Serial.println("\n[TEST GROUP] Forced and forced-fast behavior");

  Status status = sensor.setPowerMode(PmuCommand::Normal, 100);
  reportStatus("Prepare Normal for API-managed FM transition", status);

  bool pendingReady = false;
  status = sensor.dataReady(pendingReady);
  reportStatus("Clear pending data-ready before Normal-to-FM transition", status);

  status = sensor.setPowerMode(PmuCommand::FM, 100);
  reportStatus("setPowerMode(FM) from Normal via API-managed Suspend", status);

  bool forcedReady = false;
  status = waitForDataReady(DATA_READY_TIMEOUT_MS, forcedReady);
  reportReadyExpectation("FM produces one data-ready event", status, forcedReady, true);

  RawSample forcedSample{};
  status = sensor.readRawSample(forcedSample);
  reportStatus("readRawSample() after FM", status);
  if (status == Status::Ok) {
    printMeasurement(forcedSample, "[MEASUREMENT] FM sample:");
  }

  bool continuousReady = false;
  status = observeNoContinuousData(60, continuousReady);
  reportReadyExpectation("FM returns to Suspend after one conversion",
                         status,
                         continuousReady,
                         false);

  status = sensor.setPowerMode(PmuCommand::Normal, 100);
  reportStatus("Prepare Normal for FM_FAST ODR configuration", status);
  const bool odrConfigured = setAndVerifyOdrAveraging(
      Odr::ODR_100HZ,
      Averaging::AVG_2,
      "setOdrAveraging(100 Hz, 2 samples) for FM_FAST");
  (void)odrConfigured;

  status = sensor.setPowerMode(PmuCommand::Normal, 100);
  reportStatus("Prepare Normal for API-managed FM_FAST transition", status);
  pendingReady = false;
  status = sensor.dataReady(pendingReady);
  reportStatus("Clear pending data-ready before Normal-to-FM_FAST transition", status);

  status = sensor.setPowerMode(PmuCommand::FMFast, 100);
  reportStatus("setPowerMode(FMFast) from Normal via API-managed Suspend", status);

  forcedReady = false;
  status = waitForDataReady(DATA_READY_TIMEOUT_MS, forcedReady);
  reportReadyExpectation("FM_FAST produces one data-ready event", status, forcedReady, true);

  RawSample fastSample{};
  status = sensor.readRawSample(fastSample);
  reportStatus("readRawSample() after FM_FAST", status);
  if (status == Status::Ok) {
    printMeasurement(fastSample, "[MEASUREMENT] FM_FAST sample:");
  }

  continuousReady = false;
  status = observeNoContinuousData(60, continuousReady);
  reportReadyExpectation("FM_FAST returns to Suspend after one conversion",
                         status,
                         continuousReady,
                         false);

  status = sensor.setPowerMode(PmuCommand::Suspend, 100);
  reportStatus("Restore Suspend after forced-mode tests", status);

  status = sensor.triggerForcedMeasurement(false, 100);
  reportStatus("triggerForcedMeasurement(fast=false)", status);
  forcedReady = false;
  status = waitForDataReady(DATA_READY_TIMEOUT_MS, forcedReady);
  reportReadyExpectation("triggerForcedMeasurement(false) produces data",
                         status,
                         forcedReady,
                         true);
  if (forcedReady) {
    RawSample triggeredSample{};
    status = sensor.readRawSample(triggeredSample);
    reportStatus("readRawSample() after triggerForcedMeasurement(false)", status);
  }

  status = sensor.setPowerMode(PmuCommand::Suspend, 100);
  reportStatus("Prepare Suspend for triggerForcedMeasurement(true)", status);
  status = sensor.triggerForcedMeasurement(true, 100);
  reportStatus("triggerForcedMeasurement(fast=true)", status);
  forcedReady = false;
  status = waitForDataReady(DATA_READY_TIMEOUT_MS, forcedReady);
  reportReadyExpectation("triggerForcedMeasurement(true) produces data",
                         status,
                         forcedReady,
                         true);
  if (forcedReady) {
    RawSample fastTriggeredSample{};
    status = sensor.readRawSample(fastTriggeredSample);
    reportStatus("readRawSample() after triggerForcedMeasurement(true)", status);
  }
}

void testConfigurationGetter() {
  Serial.println("\n[TEST GROUP] Configuration setter/getter coverage");

  reportStatus("Prepare Normal for ODR/getter test",
               sensor.setPowerMode(PmuCommand::Normal, 100));
  setAndVerifyOdrAveraging(Odr::ODR_50HZ, Averaging::AVG_8,
                           "setOdrAveraging(50 Hz, 8 samples)");
  setAndVerifyOdrAveraging(Odr::ODR_100HZ, Averaging::AVG_2,
                           "setOdrAveraging(100 Hz, 2 samples)");

  Serial.println("[INFO] The terra driver exposes getEffectiveOdrAveraging() as its only explicit configuration getter.");
  Serial.println("[INFO] Interrupt, IBI, pad-drive, watchdog, sensor-time, and axis setters have no matching public getters.");
}

void testInterruptAndMiscConfiguration() {
  Serial.println("\n[TEST GROUP] Interrupt, IBI, pad-drive, and watchdog APIs");

  InterruptConfig interruptConfig{};
  interruptConfig.drdy_data_reg_en = true;
  interruptConfig.int_output_en = true;
  interruptConfig.int_od = false;
  interruptConfig.int_pol = true;
  interruptConfig.int_mode = true;
  reportStatus("configureInterrupt(enabled, open-drain, active-high, latched)",
               sensor.configureInterrupt(interruptConfig));

  interruptConfig.drdy_data_reg_en = false;
  interruptConfig.int_output_en = false;
  interruptConfig.int_od = true;
  interruptConfig.int_pol = false;
  interruptConfig.int_mode = false;
  reportStatus("configureInterrupt(disabled, push-pull, active-low, pulsed)",
               sensor.configureInterrupt(interruptConfig));

  reportStatus("configureIbi(mapDataReady=true, clearOnIbi=true)",
               sensor.configureIbi(true, true));
  reportStatus("configureIbi(mapDataReady=false, clearOnIbi=false)",
               sensor.configureIbi(false, false));

  reportStatus("setPadDrive(0)", sensor.setPadDrive(0));
  reportStatus("setPadDrive(7)", sensor.setPadDrive(7));
  reportExpectedStatus("setPadDrive(8) rejects an invalid drive value",
                       sensor.setPadDrive(8),
                       Status::InvalidArgument);

  reportStatus("setI2cWatchdog(enabled=false, longTimeout=false)",
               sensor.setI2cWatchdog(false, false));
  reportStatus("setI2cWatchdog(enabled=true, longTimeout=false)",
               sensor.setI2cWatchdog(true, false));
  reportStatus("setI2cWatchdog(enabled=true, longTimeout=true)",
               sensor.setI2cWatchdog(true, true));
  reportStatus("setI2cWatchdog(enabled=false, longTimeout=false) restore",
               sensor.setI2cWatchdog(false, false));
}

void testSetAxesModeBehavior() {
  Serial.println("\n[TEST GROUP] Axis configuration and mode behavior");

  Status status = sensor.setPowerMode(PmuCommand::Suspend, 100);
  reportStatus("Prepare Suspend before setAxes() behavior test", status);

  bool discardedReady = false;
  status = sensor.dataReady(discardedReady);
  reportStatus("Clear pending data-ready before setAxes() behavior test", status);

  status = sensor.setPowerMode(PmuCommand::Normal, 100);
  reportStatus("Prepare Normal mode for setAxes() behavior test", status);

  bool initialReady = false;
  status = waitForDataReady(DATA_READY_TIMEOUT_MS, initialReady);
  reportReadyExpectation("Obtain a baseline Normal-mode sample before setAxes()",
                         status,
                         initialReady,
                         true);
  if (initialReady) {
    RawSample baseline{};
    status = sensor.readRawSample(baseline);
    reportStatus("Read baseline sample before setAxes()", status);
    discardedReady = false;
    status = sensor.dataReady(discardedReady);
    reportStatus("Clear data-ready before setAxes() mode observation", status);
  }

  status = sensor.setAxes(true, true, false, 100);
  reportStatus("setAxes(X=true, Y=true, Z=false)", status);

  bool ready = false;
  status = waitForDataReady(DATA_READY_TIMEOUT_MS, ready);
  reportReadyExpectation("setAxes() from Normal preserves continuous Normal operation",
                         status,
                         ready,
                         true);
  if (status != Status::Ok || !ready) {
    Serial.println("[INFO] Observed no continuous data after setAxes(); the terra implementation currently leaves the device suspended.");
  }

  reportExpectedStatus("setAxes(all axes disabled) rejects an invalid configuration",
                       sensor.setAxes(false, false, false, 100),
                       Status::InvalidArgument);

  status = sensor.setAxes(true, true, true, 100);
  reportStatus("setAxes(X=true, Y=true, Z=true) restore", status);
  status = sensor.setPowerMode(PmuCommand::Normal, 100);
  reportStatus("Restore Normal mode after setAxes() test", status);
}

void testSensorTimeModeBehavior() {
  Serial.println("\n[TEST GROUP] Sensor-time always-on and mode behavior");

  Status status = sensor.setPowerMode(PmuCommand::Normal, 100);
  reportStatus("Prepare Normal mode for sensor-time test", status);

  status = sensor.setSensorTimeAlwaysOn(true, 100);
  reportStatus("setSensorTimeAlwaysOn(true) from Normal", status);
  bool ready = false;
  status = waitForDataReady(DATA_READY_TIMEOUT_MS, ready);
  reportReadyExpectation("Sensor-time enable restores Normal mode", status, ready, true);

  status = sensor.setSensorTimeAlwaysOn(false, 100);
  reportStatus("setSensorTimeAlwaysOn(false) from Normal", status);
  ready = false;
  status = waitForDataReady(DATA_READY_TIMEOUT_MS, ready);
  reportReadyExpectation("Sensor-time disable keeps Normal mode", status, ready, true);

  status = sensor.setPowerMode(PmuCommand::Suspend, 100);
  reportStatus("Prepare Suspend for sensor-time retention test", status);
  status = sensor.setSensorTimeAlwaysOn(true, 100);
  reportStatus("setSensorTimeAlwaysOn(true) from Suspend", status);
  ready = false;
  status = observeNoContinuousData(60, ready);
  reportReadyExpectation("Sensor-time enable from Suspend does not start magnetic conversion",
                         status,
                         ready,
                         false);

  status = sensor.setSensorTimeAlwaysOn(false, 100);
  reportStatus("setSensorTimeAlwaysOn(false) restore from Suspend", status);
  status = sensor.setPowerMode(PmuCommand::Normal, 100);
  reportStatus("Restore Normal after sensor-time test", status);
}

void testRawSampleAndDataReady() {
  Serial.println("\n[TEST GROUP] Raw sample and data-ready APIs");

  Status status = sensor.setPowerMode(PmuCommand::Normal, 100);
  reportStatus("Prepare Normal mode for raw sample test", status);

  bool ready = false;
  status = waitForDataReady(DATA_READY_TIMEOUT_MS, ready);
  reportReadyExpectation("dataReady() observes a Normal-mode sample", status, ready, true);

  RawSample sample{};
  status = sensor.readRawSample(sample);
  reportStatus("readRawSample()", status);
  if (status == Status::Ok) {
    printMeasurement(sample, "[MEASUREMENT] Raw sample:");
  }
}

void testMagneticReset() {
  Serial.println("\n[TEST GROUP] Magnetic-reset command coverage");

  Status status = sensor.setPowerMode(PmuCommand::Suspend, 100);
  reportStatus("Prepare Suspend for magnetic reset", status);

  reportStatus("magneticReset(FluxGuideReset)",
               sensor.magneticReset(PmuCommand::FluxGuideReset, 100));
  reportStatus("magneticReset(FluxGuideResetFast)",
               sensor.magneticReset(PmuCommand::FluxGuideResetFast, 100));
  reportStatus("magneticReset(BitReset)",
               sensor.magneticReset(PmuCommand::BitReset, 100));
  reportStatus("magneticReset(BitResetFast)",
               sensor.magneticReset(PmuCommand::BitResetFast, 100));
  reportExpectedStatus("magneticReset(Normal) rejects an invalid reset command",
                       sensor.magneticReset(PmuCommand::Normal, 100),
                       Status::InvalidArgument);

  status = sensor.setPowerMode(PmuCommand::Normal, 100);
  reportStatus("Restore Normal after magnetic reset tests", status);
}

void testSelfTest() {
  Serial.println("\n[TEST GROUP] X/Y self-test coverage");

  SelfTestResult xResult{};
  Status status = sensor.runSelfTest(1, xResult, 150);
  reportStatus("runSelfTest(axis=1, X)", status);
  if (status == Status::Ok) {
    printSelfTestResult(xResult, 1);
  }

  SelfTestResult yResult{};
  status = sensor.runSelfTest(2, yResult, 150);
  reportStatus("runSelfTest(axis=2, Y)", status);
  if (status == Status::Ok) {
    printSelfTestResult(yResult, 2);
  }

  SelfTestResult invalidResult{};
  reportExpectedStatus("runSelfTest(axis=0) rejects an invalid axis",
                       sensor.runSelfTest(0, invalidResult, 150),
                       Status::InvalidArgument);
}

bool initializeSensor() {
  Status status = sensor.begin(100);
  reportStatus("begin()", status);
  sensorInitialized = status == Status::Ok;

  if (sensorInitialized) {
    Serial.print("[INFO] BMM350 initialized at I2C address 0x");
    printHex8(activeAddress);
    Serial.println();
  }
  return sensorInitialized;
}

void testSoftResetAndReinitialize() {
  Serial.println("\n[TEST GROUP] Soft reset and reinitialization");

  Status status = sensor.softReset(150);
  reportStatus("softReset()", status);

  status = sensor.begin(100);
  reportStatus("begin() after softReset()", status);
  sensorInitialized = status == Status::Ok;
}

void restoreMonitoringState() {
  Serial.println("\n[RESTORE] Restoring a stable monitoring configuration");

  if (!sensorInitialized) {
    reportSkipped("Restore monitoring state", "sensor initialization is unavailable");
    return;
  }

  bool restoreOk = true;
  Status status = sensor.setPowerMode(PmuCommand::Suspend, 100);
  reportStatus("restore: setPowerMode(Suspend)", status);
  restoreOk = restoreOk && status == Status::Ok;

  status = sensor.setAxes(true, true, true, 100);
  reportStatus("restore: setAxes(all=true)", status);
  restoreOk = restoreOk && status == Status::Ok;

  status = sensor.setSensorTimeAlwaysOn(false, 100);
  reportStatus("restore: setSensorTimeAlwaysOn(false)", status);
  restoreOk = restoreOk && status == Status::Ok;

  status = sensor.setPadDrive(7);
  reportStatus("restore: setPadDrive(7)", status);
  restoreOk = restoreOk && status == Status::Ok;

  status = sensor.setI2cWatchdog(false, false);
  reportStatus("restore: setI2cWatchdog(false, false)", status);
  restoreOk = restoreOk && status == Status::Ok;

  InterruptConfig interruptConfig{};
  interruptConfig.drdy_data_reg_en = true;
  interruptConfig.int_output_en = true;
  interruptConfig.int_od = false;
  interruptConfig.int_pol = true;
  interruptConfig.int_mode = true;
  status = sensor.configureInterrupt(interruptConfig);
  reportStatus("restore: configureInterrupt(data-ready enabled)", status);
  restoreOk = restoreOk && status == Status::Ok;

  status = sensor.configureIbi(false, false);
  reportStatus("restore: configureIbi(false, false)", status);
  restoreOk = restoreOk && status == Status::Ok;

  status = sensor.setPowerMode(PmuCommand::Normal, 100);
  reportStatus("restore: setPowerMode(Normal)", status);
  restoreOk = restoreOk && status == Status::Ok;

  status = sensor.setOdrAveraging(Odr::ODR_100HZ, Averaging::AVG_2, 100);
  reportStatus("restore: setOdrAveraging(100 Hz, 2 samples)", status);
  restoreOk = restoreOk && status == Status::Ok;

  Odr effectiveOdr = Odr::ODR_100HZ;
  Averaging effectiveAveraging = Averaging::AVG_0;
  status = sensor.getEffectiveOdrAveraging(effectiveOdr, effectiveAveraging);
  reportStatus("restore: getEffectiveOdrAveraging()", status);
  restoreOk = restoreOk && status == Status::Ok &&
              effectiveOdr == Odr::ODR_100HZ &&
              effectiveAveraging == Averaging::AVG_2;

  reportCondition("Monitoring configuration restored",
                  restoreOk,
                  "Normal, all axes enabled, 100 Hz, averaging 2");
}

void runFullApiTest() {
  ++fullTestNumber;
  testPassCount = 0;
  testFailCount = 0;
  testSkipCount = 0;

  Serial.println("\n============================================================");
  Serial.print("BMM350 terra full test cycle #");
  Serial.println(fullTestNumber);
  Serial.println("============================================================");

  if (!sensorInitialized) {
    if (!selectSensorAddress()) {
      reportSkipped("Full API test cycle", "no BMM350 found on I2C");
      printTestSummaryLine();
      return;
    }
    if (!initializeSensor()) {
      reportSkipped("Remaining API tests", "begin() did not initialize the device");
      printTestSummaryLine();
      return;
    }
  }

  testIdentityAndStatus();
  testPowerModeTransitions();
  testForcedModeBehavior();
  testConfigurationGetter();
  testInterruptAndMiscConfiguration();
  testSetAxesModeBehavior();
  testSensorTimeModeBehavior();
  testRawSampleAndDataReady();
  testMagneticReset();
  testSelfTest();
  testSoftResetAndReinitialize();
  restoreMonitoringState();

  Serial.println("\n[TEST CYCLE RESULT]");
  printTestSummaryLine();
  if (testFailCount == 0) {
    Serial.println("[RESULT] All executed checks passed.");
  } else {
    Serial.println("[RESULT] One or more checks failed; inspect the detailed lines above.");
  }
}

void monitorSensor() {
  if (!sensorInitialized) {
    Serial.println("[MONITOR] Sensor is not initialized; waiting for the next test cycle.");
    return;
  }

  bool ready = false;
  Status status = sensor.dataReady(ready);
  Serial.print("[MONITOR] dataReady status=");
  Serial.print(statusName(status));
  Serial.print(" ready=");
  Serial.println(ready ? "true" : "false");

  if (status != Status::Ok || !ready) {
    if (status != Status::Ok) {
      Serial.println("[MONITOR] Data-ready read failed; measurement not requested.");
    } else {
      Serial.println("[MONITOR] No new sample in this interval.");
    }
    return;
  }

  RawSample sample{};
  status = sensor.readRawSample(sample);
  Serial.print("[MONITOR] readRawSample status=");
  Serial.println(statusName(status));
  if (status == Status::Ok) {
    printMeasurement(sample, "[MONITOR] Measurement:");
  }
}

}  // namespace

void setup() {
  Serial.begin(115200);
  const uint32_t serialStart = millis();
  while (!Serial && static_cast<uint32_t>(millis() - serialStart) < 3000) {
    delay(10);
  }

  pinMode(PIN_BMM350_INT, INPUT);
  Wire.setSDA(PIN_I2C_SDA);
  Wire.setSCL(PIN_I2C_SCL);
  Wire.begin();
  Wire.setClock(400000);

  Serial.println();
  Serial.println("BMM350 terra driver test");
  Serial.println("Board: RP2040 custom board");
  Serial.println("I2C: SDA=GPIO0, SCL=GPIO1, INT=GPIO18, SPI=not connected");
  Serial.println("The test uses I2C only and prints a blank line between monitor cycles.");

  runFullApiTest();
  lastMonitorMillis = millis();
  lastFullTestMillis = millis();
}

void loop() {
  const uint32_t now = millis();

  if (static_cast<uint32_t>(now - lastMonitorMillis) >= MONITOR_INTERVAL_MS) {
    Serial.println();
    Serial.println("-------------------- monitor cycle --------------------");
    monitorSensor();
    lastMonitorMillis = now;
  }

  if (static_cast<uint32_t>(now - lastFullTestMillis) >= FULL_TEST_INTERVAL_MS) {
    Serial.println();
    runFullApiTest();
    lastFullTestMillis = now;
  }
}
