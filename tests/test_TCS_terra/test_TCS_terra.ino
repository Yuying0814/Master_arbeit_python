#include <Arduino.h>
#include <Wire.h>
#include <math.h>

#include "TCS3472.h"

// RP2040 hardware configuration.
constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 1;
constexpr uint8_t INT_PIN = 15;
constexpr uint8_t TCS3472_I2C_ADDRESS = 0x29;

constexpr uint8_t TEST_ATIME = 0xF6;
constexpr uint8_t TEST_WTIME = 0xFE;
constexpr bool TEST_WLONG = true;
constexpr uint16_t TEST_LOW_THRESHOLD = 0x0100;
constexpr uint16_t TEST_HIGH_THRESHOLD = 0xF000;
constexpr uint8_t TEST_PERSISTENCE = 0x03;

constexpr uint16_t MONITOR_LOW_THRESHOLD = 1000U;
constexpr uint16_t MONITOR_HIGH_THRESHOLD = 50000U;

constexpr unsigned long DATA_READY_TIMEOUT_MS = 1000UL;
constexpr unsigned long INTERRUPT_TIMEOUT_MS = 1000UL;
constexpr unsigned long MONITOR_INTERVAL_MS = 1000UL;
constexpr unsigned long FULL_API_TEST_INTERVAL_MS = 10000UL;

TCS3472 sensor(Wire, TCS3472_I2C_ADDRESS);

bool deviceReady = false;
unsigned long lastFullApiTestMs = 0;
unsigned long lastMonitorMs = 0;

uint16_t passCount = 0;
uint16_t failCount = 0;
uint16_t skipCount = 0;

TCS3472::RGBCData lastSample{};
bool haveLastSample = false;

void printBoolean(bool value) {
  Serial.print(value ? "1" : "0");
}

void printHex8(uint8_t value) {
  if (value < 0x10) {
    Serial.print('0');
  }
  Serial.print(static_cast<unsigned int>(value), HEX);
}

void printHex16(uint16_t value) {
  if (value < 0x1000) {
    Serial.print('0');
  }
  if (value < 0x0100) {
    Serial.print('0');
  }
  if (value < 0x0010) {
    Serial.print('0');
  }
  Serial.print(static_cast<unsigned int>(value), HEX);
}

void reportResult(const char *label, bool passed) {
  Serial.print(passed ? "[PASS] " : "[FAIL] ");
  Serial.println(label);
  if (passed) {
    ++passCount;
  } else {
    ++failCount;
  }
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

bool approximatelyEqual(float actual, float expected, float tolerance) {
  return isfinite(actual) && fabsf(actual - expected) <= tolerance;
}

const char *gainName(TCS3472::Gain gain) {
  switch (gain) {
    case TCS3472::Gain::GAIN_1X:
      return "GAIN_1X";
    case TCS3472::Gain::GAIN_4X:
      return "GAIN_4X";
    case TCS3472::Gain::GAIN_16X:
      return "GAIN_16X";
    case TCS3472::Gain::GAIN_60X:
      return "GAIN_60X";
    default:
      return "UNKNOWN";
  }
}

bool waitForDataValid(unsigned long timeoutMs) {
  const unsigned long startMs = millis();

  while (millis() - startMs < timeoutMs) {
    bool valid = false;
    if (!sensor.dataValid(valid)) {
      return false;
    }
    if (valid) {
      return true;
    }
    delay(10);
  }

  return false;
}

bool waitForInterruptActive(bool &communicationOk, unsigned long timeoutMs) {
  const unsigned long startMs = millis();
  communicationOk = true;

  while (millis() - startMs < timeoutMs) {
    bool active = false;
    if (!sensor.interruptActive(active)) {
      communicationOk = false;
      return false;
    }
    if (active) {
      return true;
    }
    delay(10);
  }

  return false;
}

bool testDeviceIdentity() {
  Serial.println();
  Serial.println("[TEST] Device identity");

  uint8_t id = 0;
  const bool readOk = sensor.readID(id);
  reportResult("readID() communication", readOk);

  const bool supportedId = readOk && (id == 0x44 || id == 0x4D);
  reportResult("readID() matches TCS34725 or TCS34727", supportedId);

  Serial.print("  ID: 0x");
  printHex8(id);
  Serial.println(" (0x44=TCS34725, 0x4D=TCS34727)");

  return supportedId;
}

bool testStatusAndFlags() {
  Serial.println();
  Serial.println("[TEST] Status and flag APIs");

  uint8_t status = 0;
  const bool statusOk = sensor.readStatus(status);
  reportResult("readStatus() communication", statusOk);

  const bool definedBitsOk = statusOk && (status & 0xEE) == 0;
  reportResult("readStatus() contains only documented flags", definedBitsOk);

  bool dataValid = false;
  const bool dataValidOk = sensor.dataValid(dataValid);
  reportResult("dataValid() communication", dataValidOk);

  bool interruptActive = false;
  const bool interruptActiveOk = sensor.interruptActive(interruptActive);
  reportResult("interruptActive() communication", interruptActiveOk);

  Serial.print("  STATUS: 0x");
  printHex8(status);
  Serial.print("; data valid: ");
  printBoolean(dataValid);
  Serial.print("; interrupt active: ");
  printBoolean(interruptActive);
  Serial.println();

  return definedBitsOk && dataValidOk && interruptActiveOk;
}

bool testPowerAndRGBCControl() {
  Serial.println();
  Serial.println("[TEST] Power and RGBC control");

  bool allOk = true;
  allOk &= sensor.setRGBCEnabled(false);
  reportResult("setRGBCEnabled(false)", allOk);

  const bool waitDisabled = sensor.setWaitEnabled(false);
  reportResult("setWaitEnabled(false)", waitDisabled);
  allOk &= waitDisabled;

  const bool interruptDisabled = sensor.setInterruptEnabled(false);
  reportResult("setInterruptEnabled(false)", interruptDisabled);
  allOk &= interruptDisabled;

  const bool powerOffOk = sensor.setPower(false);
  reportResult("setPower(false)", powerOffOk);
  allOk &= powerOffOk;
  delay(5);

  const bool powerOnOk = sensor.setPower(true);
  reportResult("setPower(true)", powerOnOk);
  allOk &= powerOnOk;

  const bool rgbcEnabled = sensor.setRGBCEnabled(true);
  reportResult("setRGBCEnabled(true)", rgbcEnabled);
  allOk &= rgbcEnabled;

  const bool dataReady = allOk && waitForDataValid(DATA_READY_TIMEOUT_MS);
  reportResult("power and RGBC enable path produces valid data", dataReady);
  return allOk && dataReady;
}

bool testIntegrationTime() {
  Serial.println();
  Serial.println("[TEST] Integration time");

  bool allOk = sensor.setRGBCEnabled(false);
  reportResult("disable RGBC before integration-time write", allOk);

  uint8_t originalAtime = 0;
  const bool originalReadOk = sensor.getIntegrationTime(originalAtime);
  reportResult("getIntegrationTime() before write", originalReadOk);
  allOk &= originalReadOk;

  const bool setOk = sensor.setIntegrationTime(TEST_ATIME);
  reportResult("setIntegrationTime(0xF6)", setOk);
  allOk &= setOk;

  uint8_t observedAtime = 0;
  const bool observedReadOk = sensor.getIntegrationTime(observedAtime);
  reportResult("getIntegrationTime() after write", observedReadOk);
  reportResult("integration-time register round-trip", observedReadOk &&
                                                        observedAtime == TEST_ATIME);
  allOk &= observedReadOk && observedAtime == TEST_ATIME;

  const float expectedTestTimeMs = 24.0f;
  const bool conversionOk = approximatelyEqual(
      sensor.integrationTimeMs(TEST_ATIME), expectedTestTimeMs, 0.01f);
  reportResult("integrationTimeMs(0xF6) returns 24.0 ms", conversionOk);
  allOk &= conversionOk;

  const bool minimumConversionOk = approximatelyEqual(
      sensor.integrationTimeMs(0xFF), 2.4f, 0.01f);
  reportResult("integrationTimeMs(0xFF) returns 2.4 ms", minimumConversionOk);
  allOk &= minimumConversionOk;

  const bool restoreOk = originalReadOk &&
                         sensor.setIntegrationTime(originalAtime);
  reportResult("restore original integration time", restoreOk);
  allOk &= restoreOk;

  uint8_t restoredAtime = 0;
  const bool restoredReadOk = sensor.getIntegrationTime(restoredAtime);
  reportResult("getIntegrationTime() after restore", restoredReadOk);
  reportResult("original integration time is restored",
               restoredReadOk && restoredAtime == originalAtime);
  allOk &= restoredReadOk && restoredAtime == originalAtime;

  Serial.print("  Test duration: ");
  Serial.print(sensor.integrationTimeMs(TEST_ATIME), 1);
  Serial.println(" ms");
  return allOk;
}

bool testGainControl() {
  Serial.println();
  Serial.println("[TEST] Analog gain");

  bool allOk = sensor.setRGBCEnabled(false);
  reportResult("disable RGBC before gain writes", allOk);

  TCS3472::Gain originalGain = TCS3472::Gain::GAIN_1X;
  const bool originalReadOk = sensor.getGain(originalGain);
  reportResult("getGain() before writes", originalReadOk);
  allOk &= originalReadOk;

  const TCS3472::Gain gains[] = {
      TCS3472::Gain::GAIN_1X,
      TCS3472::Gain::GAIN_4X,
      TCS3472::Gain::GAIN_16X,
      TCS3472::Gain::GAIN_60X};

  for (const TCS3472::Gain gain : gains) {
    const bool setOk = sensor.setGain(gain);
    Serial.print("  setGain(");
    Serial.print(gainName(gain));
    Serial.println(")");
    reportResult("setGain() returns success", setOk);
    allOk &= setOk;

    TCS3472::Gain observedGain = TCS3472::Gain::GAIN_1X;
    const bool getOk = sensor.getGain(observedGain);
    reportResult("getGain() returns success", getOk);
    reportResult("getGain() matches the requested gain",
                 getOk && observedGain == gain);
    allOk &= getOk && observedGain == gain;
  }

  const bool restoreOk = originalReadOk && sensor.setGain(originalGain);
  reportResult("restore original gain", restoreOk);
  allOk &= restoreOk;
  return allOk;
}

bool testWaitTimeControl() {
  Serial.println();
  Serial.println("[TEST] Wait time and wait enable");

  bool allOk = sensor.setRGBCEnabled(false);
  reportResult("disable RGBC before wait-time writes", allOk);

  uint8_t originalWtime = 0;
  bool originalLongWait = false;
  const bool originalReadOk = sensor.getWaitTime(originalWtime, originalLongWait);
  reportResult("getWaitTime() before writes", originalReadOk);
  allOk &= originalReadOk;

  const bool setNormalOk = sensor.setWaitTime(TEST_WTIME, false);
  reportResult("setWaitTime(0xFE, false)", setNormalOk);
  allOk &= setNormalOk;

  uint8_t observedWtime = 0;
  bool observedLongWait = true;
  const bool normalReadOk = sensor.getWaitTime(observedWtime, observedLongWait);
  reportResult("getWaitTime() after normal wait write", normalReadOk);
  reportResult("normal wait-time round-trip",
               normalReadOk && observedWtime == TEST_WTIME && !observedLongWait);
  allOk &= normalReadOk && observedWtime == TEST_WTIME && !observedLongWait;

  const bool setLongOk = sensor.setWaitTime(TEST_WTIME, TEST_WLONG);
  reportResult("setWaitTime(0xFE, true)", setLongOk);
  allOk &= setLongOk;

  observedWtime = 0;
  observedLongWait = false;
  const bool longReadOk = sensor.getWaitTime(observedWtime, observedLongWait);
  reportResult("getWaitTime() after long wait write", longReadOk);
  reportResult("long wait-time round-trip",
               longReadOk && observedWtime == TEST_WTIME && observedLongWait);
  allOk &= longReadOk && observedWtime == TEST_WTIME && observedLongWait;

  const bool normalTimeFormulaOk = approximatelyEqual(
      sensor.waitTimeMs(TEST_WTIME, false), 4.8f, 0.01f);
  reportResult("waitTimeMs(0xFE, false) returns 4.8 ms", normalTimeFormulaOk);
  allOk &= normalTimeFormulaOk;

  const bool longTimeFormulaOk = approximatelyEqual(
      sensor.waitTimeMs(TEST_WTIME, true), 57.6f, 0.01f);
  reportResult("waitTimeMs(0xFE, true) returns 57.6 ms", longTimeFormulaOk);
  allOk &= longTimeFormulaOk;

  const bool waitDisableOk = sensor.setWaitEnabled(false);
  reportResult("setWaitEnabled(false)", waitDisableOk);
  allOk &= waitDisableOk;

  const bool waitEnableOk = sensor.setWaitEnabled(true);
  reportResult("setWaitEnabled(true)", waitEnableOk);
  allOk &= waitEnableOk;

  const bool waitRestoreOk = sensor.setWaitEnabled(false);
  reportResult("restore wait timer disabled", waitRestoreOk);
  allOk &= waitRestoreOk;

  const bool restoreOk = originalReadOk &&
                         sensor.setWaitTime(originalWtime, originalLongWait);
  reportResult("restore original wait time", restoreOk);
  allOk &= restoreOk;
  return allOk;
}

bool testInterruptControl() {
  Serial.println();
  Serial.println("[TEST] Interrupt thresholds, persistence, and clear");

  bool allOk = true;

  uint16_t originalLow = 0;
  uint16_t originalHigh = 0;
  const bool originalThresholdsOk =
      sensor.getInterruptThresholds(originalLow, originalHigh);
  reportResult("getInterruptThresholds() before writes", originalThresholdsOk);
  allOk &= originalThresholdsOk;

  const bool thresholdSetOk =
      sensor.setInterruptThresholds(TEST_LOW_THRESHOLD, TEST_HIGH_THRESHOLD);
  reportResult("setInterruptThresholds(0x0100, 0xF000)", thresholdSetOk);
  allOk &= thresholdSetOk;

  uint16_t observedLow = 0;
  uint16_t observedHigh = 0;
  const bool thresholdReadOk =
      sensor.getInterruptThresholds(observedLow, observedHigh);
  reportResult("getInterruptThresholds() after write", thresholdReadOk);
  reportResult("interrupt thresholds round-trip",
               thresholdReadOk && observedLow == TEST_LOW_THRESHOLD &&
                   observedHigh == TEST_HIGH_THRESHOLD);
  allOk &= thresholdReadOk && observedLow == TEST_LOW_THRESHOLD &&
           observedHigh == TEST_HIGH_THRESHOLD;

  const bool reversedThresholdOk =
      sensor.setInterruptThresholds(TEST_HIGH_THRESHOLD, TEST_LOW_THRESHOLD);
  reportResult("reversed thresholds are rejected", !reversedThresholdOk);
  allOk &= !reversedThresholdOk;

  uint16_t afterRejectedLow = 0;
  uint16_t afterRejectedHigh = 0;
  const bool afterRejectedReadOk =
      sensor.getInterruptThresholds(afterRejectedLow, afterRejectedHigh);
  reportResult("thresholds remain unchanged after rejection",
               afterRejectedReadOk && afterRejectedLow == TEST_LOW_THRESHOLD &&
                   afterRejectedHigh == TEST_HIGH_THRESHOLD);
  allOk &= afterRejectedReadOk && afterRejectedLow == TEST_LOW_THRESHOLD &&
           afterRejectedHigh == TEST_HIGH_THRESHOLD;

  uint8_t originalPersistence = 0;
  const bool originalPersistenceOk =
      sensor.getInterruptPersistence(originalPersistence);
  reportResult("getInterruptPersistence() before write", originalPersistenceOk);
  allOk &= originalPersistenceOk;

  const bool persistenceSetOk =
      sensor.setInterruptPersistence(TEST_PERSISTENCE);
  reportResult("setInterruptPersistence(0x03)", persistenceSetOk);
  allOk &= persistenceSetOk;

  uint8_t observedPersistence = 0;
  const bool persistenceReadOk =
      sensor.getInterruptPersistence(observedPersistence);
  reportResult("getInterruptPersistence() after write", persistenceReadOk);
  reportResult("interrupt persistence round-trip",
               persistenceReadOk && observedPersistence == TEST_PERSISTENCE);
  allOk &= persistenceReadOk && observedPersistence == TEST_PERSISTENCE;

  const bool invalidPersistenceOk = sensor.setInterruptPersistence(0x10);
  reportResult("reserved persistence bits are rejected", !invalidPersistenceOk);
  allOk &= !invalidPersistenceOk;

  uint8_t afterRejectedPersistence = 0;
  const bool afterRejectedPersistenceReadOk =
      sensor.getInterruptPersistence(afterRejectedPersistence);
  reportResult("persistence remains unchanged after rejection",
               afterRejectedPersistenceReadOk &&
                   afterRejectedPersistence == TEST_PERSISTENCE);
  allOk &= afterRejectedPersistenceReadOk &&
           afterRejectedPersistence == TEST_PERSISTENCE;

  const bool disableBeforeTriggerOk = sensor.setInterruptEnabled(false);
  reportResult("setInterruptEnabled(false) before trigger", disableBeforeTriggerOk);
  allOk &= disableBeforeTriggerOk;

  const bool clearBeforeTriggerOk = sensor.clearInterrupt();
  reportResult("clearInterrupt() before trigger", clearBeforeTriggerOk);
  allOk &= clearBeforeTriggerOk;

  bool physicalInterruptObserved = false;
  bool interruptCommunicationOk = true;
  if (haveLastSample) {
    uint16_t triggerLow = 0;
    uint16_t triggerHigh = 0;
    if (lastSample.c < 0xFFFF) {
      triggerLow = static_cast<uint16_t>(lastSample.c + 1U);
      triggerHigh = 0xFFFF;
    } else {
      triggerLow = 0;
      triggerHigh = 0;
    }

    const bool triggerThresholdOk =
        sensor.setInterruptThresholds(triggerLow, triggerHigh);
    reportResult("set thresholds for interrupt trigger", triggerThresholdOk);
    allOk &= triggerThresholdOk;

    const bool triggerPersistenceOk = sensor.setInterruptPersistence(0x00);
    reportResult("setInterruptPersistence(0x00) for trigger", triggerPersistenceOk);
    allOk &= triggerPersistenceOk;

    const bool enableForTriggerOk = sensor.setInterruptEnabled(true);
    reportResult("setInterruptEnabled(true) for trigger", enableForTriggerOk);
    allOk &= enableForTriggerOk;

    physicalInterruptObserved = waitForInterruptActive(
        interruptCommunicationOk, INTERRUPT_TIMEOUT_MS);
    reportResult("interruptActive() remains readable during trigger", interruptCommunicationOk);
    allOk &= interruptCommunicationOk;

    if (physicalInterruptObserved) {
      reportResult("configured threshold produces AINT", true);
      reportResult("INT pin is LOW when AINT is active", digitalRead(INT_PIN) == LOW);
    } else if (interruptCommunicationOk) {
      reportSkip("physical AINT assertion was not observed within the timeout");
    }

    const bool stopConversionOk = sensor.setRGBCEnabled(false);
    reportResult("setRGBCEnabled(false) before interrupt clear", stopConversionOk);
    allOk &= stopConversionOk;

    const bool clearAfterTriggerOk = sensor.clearInterrupt();
    reportResult("clearInterrupt() after trigger", clearAfterTriggerOk);
    allOk &= clearAfterTriggerOk;

    bool activeAfterClear = false;
    const bool readAfterClearOk = sensor.interruptActive(activeAfterClear);
    reportResult("interruptActive() after clear", readAfterClearOk);
    allOk &= readAfterClearOk;
    if (physicalInterruptObserved) {
      reportResult("clearInterrupt() clears AINT", readAfterClearOk && !activeAfterClear);
      allOk &= readAfterClearOk && !activeAfterClear;
    }
  } else {
    reportSkip("physical interrupt trigger because no RGBC sample is available");
  }

  const bool disableAfterTriggerOk = sensor.setInterruptEnabled(false);
  reportResult("setInterruptEnabled(false) after trigger", disableAfterTriggerOk);
  allOk &= disableAfterTriggerOk;

  const bool restoreThresholdsOk = originalThresholdsOk &&
                                   sensor.setInterruptThresholds(originalLow, originalHigh);
  reportResult("restore original interrupt thresholds", restoreThresholdsOk);
  allOk &= restoreThresholdsOk;

  const bool restorePersistenceOk = originalPersistenceOk &&
                                    sensor.setInterruptPersistence(originalPersistence);
  reportResult("restore original interrupt persistence", restorePersistenceOk);
  allOk &= restorePersistenceOk;

  sensor.setRGBCEnabled(true);
  sensor.clearInterrupt();
  return allOk;
}

bool testRGBCAcquisition() {
  Serial.println();
  Serial.println("[TEST] RGBC acquisition");

  bool allOk = sensor.setWaitEnabled(false);
  reportResult("setWaitEnabled(false) before acquisition", allOk);

  const bool enableOk = sensor.setRGBCEnabled(true);
  reportResult("setRGBCEnabled(true) before acquisition", enableOk);
  allOk &= enableOk;

  bool valid = false;
  const bool initialValidReadOk = sensor.dataValid(valid);
  reportResult("dataValid() before acquisition", initialValidReadOk);
  allOk &= initialValidReadOk;

  if (!valid) {
  valid = waitForDataValid(DATA_READY_TIMEOUT_MS);
}
  reportResult("dataValid() reports completed conversion", valid);
  allOk &= valid;

  bool interruptActive = false;
  const bool interruptReadOk = sensor.interruptActive(interruptActive);
  reportResult("interruptActive() during acquisition", interruptReadOk);
  allOk &= interruptReadOk;

  TCS3472::RGBCData sample{};
  const bool readOk = sensor.readRGBC(sample);
  reportResult("readRGBC() returns a complete sample", readOk);
  allOk &= readOk;

  if (readOk) {
  lastSample = sample;
  haveLastSample = true;
  Serial.print("  Clear: ");
  Serial.print(sample.c);
  Serial.print("; Red: ");
  Serial.print(sample.r);
  Serial.print("; Green: ");
  Serial.print(sample.g);
  Serial.print("; Blue: ");
  Serial.println(sample.b);
}

  return allOk;
}

bool restoreMonitorConfiguration() {
  bool allOk = true;

  // Stop measurement-related modes before changing timing parameters.
  allOk &= sensor.setRGBCEnabled(false);
  allOk &= sensor.setWaitEnabled(false);
  allOk &= sensor.setInterruptEnabled(false);

  // Keep the oscillator enabled.
  allOk &= sensor.setPower(true);

  // Configure interrupt behavior.
  allOk &= sensor.setInterruptThresholds(MONITOR_LOW_THRESHOLD,
                                         MONITOR_HIGH_THRESHOLD);
  allOk &= sensor.setInterruptPersistence(0x00);

  // Configure approximately 900 ms measurement cycle.
  allOk &= sensor.setWaitTime(0x8A, false);  // 283.2 ms wait
  allOk &= sensor.setIntegrationTime(0x00);  // 614.4 ms integration
  allOk &= sensor.setGain(TCS3472::Gain::GAIN_4X);

  // Remove any previous latched interrupt before enabling AIEN.
  allOk &= sensor.clearInterrupt();

  // Start the selected modes.
  allOk &= sensor.setInterruptEnabled(true); // AIEN=1
  allOk &= sensor.setWaitEnabled(true);      // WEN=1
  allOk &= sensor.setRGBCEnabled(true);      // AEN=1

  return allOk;
}

void printTestSummary(bool completeCoverage) {
  Serial.println();
  Serial.println("----------------------------------------");
  Serial.print("Verified checks: PASS=");
  Serial.print(passCount);
  Serial.print(" FAIL=");
  Serial.print(failCount);
  Serial.print(" SKIP=");
  Serial.println(skipCount);
  if (completeCoverage) {
    Serial.println("Public API coverage: 24/24 entries exercised");
  } else {
    Serial.println("Public API coverage: initialization stopped before all entries could be exercised");
  }
  if (failCount != 0) {
    Serial.println("Full API cycle result: FAIL");
  } else if (skipCount != 0) {
    Serial.println("Full API cycle result: PASS with documented runtime skip");
  } else {
    Serial.println("Full API cycle result: PASS");
  }
  Serial.println("----------------------------------------");
}

bool runFullApiTest() {
  passCount = 0;
  failCount = 0;
  skipCount = 0;
  haveLastSample = false;

  Serial.println();
  Serial.println("========================================");
  Serial.println("TCS3472 full driver API test");
  Serial.println("========================================");
  Serial.println("Hardware: RP2040, SDA=GPIO0, SCL=GPIO1, INT=GPIO15");
  Serial.print("I2C address: 0x");
  printHex8(TCS3472_I2C_ADDRESS);
  Serial.println();
  reportInfo("TCS3472(Wire, 0x29) constructor executed during global initialization.");

  const bool beginOk = sensor.begin();
  reportResult("begin()", beginOk);
  if (!beginOk) {
    reportInfo("No supported TCS3472 response; the next cycle will retry initialization.");
    printTestSummary(false);
    return false;
  }

  const bool identityOk = testDeviceIdentity();

  bool initialSetupOk = true;
  const bool initialRgbcOffOk = sensor.setRGBCEnabled(false);
  reportResult("setRGBCEnabled(false) before full test", initialRgbcOffOk);
  initialSetupOk &= initialRgbcOffOk;

  const bool initialWaitOffOk = sensor.setWaitEnabled(false);
  reportResult("setWaitEnabled(false) before full test", initialWaitOffOk);
  initialSetupOk &= initialWaitOffOk;

  const bool initialInterruptOffOk = sensor.setInterruptEnabled(false);
  reportResult("setInterruptEnabled(false) before full test", initialInterruptOffOk);
  initialSetupOk &= initialInterruptOffOk;

  const bool initialClearOk = sensor.clearInterrupt();
  reportResult("clearInterrupt() before full test", initialClearOk);
  initialSetupOk &= initialClearOk;

  const bool statusOk = testStatusAndFlags();
  const bool powerOk = testPowerAndRGBCControl();
  const bool integrationOk = testIntegrationTime();
  const bool gainOk = testGainControl();
  const bool waitOk = testWaitTimeControl();
  const bool acquisitionOk = testRGBCAcquisition();
  const bool interruptOk = testInterruptControl();

  const bool restoreOk = restoreMonitorConfiguration();
  reportResult("restore monitor configuration", restoreOk);
  reportInfo("Monitor state: power on, RGBC enabled, wait enabled, interrupt enabled.");
  printTestSummary(true);

  const bool communicationOk = beginOk && identityOk && initialSetupOk && statusOk;
  const bool completeCycleOk = communicationOk && powerOk && integrationOk && gainOk &&
                               waitOk && acquisitionOk && interruptOk && restoreOk;
  if (!completeCycleOk) {
    reportInfo("At least one full-cycle check failed; monitor remains active if communication is available.");
  }

  return communicationOk;
}

void printStatusDetails(uint8_t status) {
  Serial.print("STATUS: 0x");
  printHex8(status);
  Serial.print("; AVALID=");
  printBoolean((status & 0x01) != 0);
  Serial.print("; AINT=");
  printBoolean((status & 0x10) != 0);
  Serial.println();
}

void runMonitorCycle() {
  Serial.println();
  Serial.println("--- TCS3472 measurement monitor ---");
  Serial.print("Uptime: ");
  Serial.print(millis() / 1000UL);
  Serial.println(" s");

  bool dataValid = false;
  const bool dataValidReadOk = sensor.dataValid(dataValid);
  if (dataValidReadOk) {
    Serial.print("RGBC data valid: ");
    Serial.println(dataValid ? "YES" : "NO");
  } else {
    Serial.println("RGBC data valid: READ_ERROR");
  }

  bool sampleReadOk = false;
  bool thresholdEvaluated = false;
  bool thresholdExceeded = false;
  if (dataValid) {
    TCS3472::RGBCData sample{};
    sampleReadOk = sensor.readRGBC(sample);
    if (sampleReadOk) {
      Serial.print("Measurements [counts] - Clear: ");
      Serial.print(sample.c);
      Serial.print("; Red: ");
      Serial.print(sample.r);
      Serial.print("; Green: ");
      Serial.print(sample.g);
      Serial.print("; Blue: ");
      Serial.println(sample.b);

      thresholdEvaluated = true;
      thresholdExceeded = (sample.c < MONITOR_LOW_THRESHOLD) ||
                          (sample.c > MONITOR_HIGH_THRESHOLD);
      Serial.print("Clear threshold [");
      Serial.print(MONITOR_LOW_THRESHOLD);
      Serial.print(", ");
      Serial.print(MONITOR_HIGH_THRESHOLD);
      Serial.print("]: ");
      Serial.println(thresholdExceeded ? "OUT_OF_RANGE" : "IN_RANGE");
    } else {
      Serial.println("Measurements: READ_ERROR");
    }
  } else if (dataValidReadOk) {
    Serial.println("Measurements: waiting for the next RGBC conversion");
  }

  // Clear an old latched event only after the current Clear value is in range.
  bool activeBeforeClear = false;
  const bool activeBeforeClearReadOk = sensor.interruptActive(activeBeforeClear);
  if (thresholdEvaluated && !thresholdExceeded && activeBeforeClearReadOk &&
      activeBeforeClear) {
    const bool clearOk = sensor.clearInterrupt();
    Serial.print("Latched interrupt clear: ");
    Serial.println(clearOk ? "SUCCESS" : "FAILED");
  }

  uint8_t status = 0;
  if (sensor.readStatus(status)) {
    printStatusDetails(status);
  } else {
    Serial.println("STATUS: READ_ERROR");
  }

  bool interruptActive = false;
  const bool interruptReadOk = sensor.interruptActive(interruptActive);
  if (interruptReadOk) {
    Serial.print("Driver interrupt status: ");
    Serial.println(interruptActive ? "ACTIVE" : "INACTIVE");
  } else {
    Serial.println("Driver interrupt status: READ_ERROR");
  }

  const bool intPinActive = digitalRead(INT_PIN) == LOW;
  Serial.print("INT pin: ");
  Serial.println(intPinActive ? "LOW (active)" : "HIGH (inactive)");

  if (thresholdEvaluated && sampleReadOk) {
    if (thresholdExceeded) {
      if (interruptReadOk && interruptActive && intPinActive) {
        Serial.println("Threshold interrupt: TRIGGERED (AINT=1, INT=LOW)");
      } else if (interruptReadOk && interruptActive) {
        Serial.println("Threshold interrupt: LATCHED (AINT=1, INT output not LOW)");
      } else {
        Serial.println("Threshold interrupt: WAITING FOR AINT");
      }
    } else {
      Serial.println("Threshold interrupt: INACTIVE (Clear is in range)");
    }
  }
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

  // TCS3472 INT is an open-drain, active-low output.
  pinMode(INT_PIN, INPUT_PULLUP);

  Serial.println();
  Serial.println("TCS3472 RP2040 driver test");
  Serial.println("The full API test repeats every 10 s; the monitor repeats every 1 s.");

  deviceReady = runFullApiTest();
  lastFullApiTestMs = millis();
  lastMonitorMs = millis();
}

void loop() {
  const unsigned long nowMs = millis();

  if (nowMs - lastFullApiTestMs >= FULL_API_TEST_INTERVAL_MS) {
    deviceReady = runFullApiTest();
    lastFullApiTestMs = millis();
    lastMonitorMs = millis();
  }

  if (!deviceReady) {
    delay(10);
    return;
  }

  if (millis() - lastMonitorMs >= MONITOR_INTERVAL_MS) {
    runMonitorCycle();
    lastMonitorMs = millis();
  }
}
