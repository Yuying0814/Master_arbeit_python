#include <Wire.h>
#include <math.h>

#include "TMP4719.h"

constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 1;
constexpr uint8_t ALERT_PIN = 10;
constexpr uint8_t TCRIT_PIN = 11;

constexpr int8_t ALERT_ACTIVE_LEVEL = LOW;
constexpr int8_t TCRIT_ACTIVE_LEVEL = LOW;

// This reflects the current hardware schematic.
constexpr bool REMOTE_CH1_CONNECTED = true;
constexpr bool REMOTE_CH2_CONNECTED = false;

constexpr unsigned long ADC_IDLE_TIMEOUT_MS = 1000UL;
constexpr unsigned long FULL_API_TEST_INTERVAL_MS = 10000UL;
constexpr uint8_t SCRATCHPAD1_TEST_VALUE = 0xA5;
constexpr uint8_t SCRATCHPAD2_TEST_VALUE = 0x5A;

TMP4719 sensor(Wire);
bool deviceReady = false;
unsigned long lastFullApiTestMs = 0;

uint16_t passCount = 0;
uint16_t failCount = 0;
uint16_t skipCount = 0;

void runMonitorCycle();

void printBoolean(bool value) {
  Serial.print(value ? "1" : "0");
}

void printHex8(uint8_t value) {
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

void reportExpectedFalse(const char *label, bool returnedTrue) {
  reportResult(label, !returnedTrue);
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

bool approximatelyEqual(float first, float second) {
  return fabsf(first - second) <= 0.001f;
}

void printPinCheck(const char *label,
                  int level,
                  int8_t activeLevel,
                  bool driverCondition) {
  const bool pinCondition = (level == activeLevel);

  Serial.print(label);
  Serial.print(" pin: ");
  Serial.print(level == HIGH ? "HIGH" : "LOW");
  Serial.print("; driver condition: ");
  Serial.print(driverCondition ? "ACTIVE" : "INACTIVE");
  Serial.print("; result: ");
  Serial.println(pinCondition == driverCondition ? "MATCH" : "MISMATCH");
}

bool waitForAdcIdle(unsigned long timeoutMs) {
  const unsigned long start = millis();

  while (millis() - start < timeoutMs) {
    bool busy;
    if (!sensor.isAdcBusy(busy)) {
      return false;
    }
    if (!busy) {
      return true;
    }
    delay(10);
  }

  return false;
}

void testDeviceIdentity() {
  Serial.println();
  Serial.println("[TEST] Device identification");

  uint8_t chipId;
  uint8_t vendorId;
  uint8_t deviceId;
  uint8_t revisionId;

  const bool ok = sensor.readDeviceId(chipId, vendorId, deviceId, revisionId);
  reportResult("readDeviceId()", ok);

  if (ok) {
    Serial.print("  Chip ID: 0x");
    printHex8(chipId);
    Serial.print("; Vendor ID: 0x");
    printHex8(vendorId);
    Serial.print("; Device ID: 0x");
    printHex8(deviceId);
    Serial.print("; Revision: 0x");
    printHex8(revisionId);
    Serial.println();
  }
}

void testTemperatureReads() {
  Serial.println();
  Serial.println("[TEST] Temperature reads");

  int8_t localTemperatureC;
  const bool localOk = sensor.readLocalTemperature(localTemperatureC);
  reportResult("readLocalTemperature()", localOk);
  if (localOk) {
    Serial.print("  Local: ");
    Serial.print(static_cast<int>(localTemperatureC));
    Serial.println(" C");
  }

  float remote1TemperatureC;
  const bool remote1Ok = sensor.readRemoteTemperature(
      TMP4719::RemoteChannel::CH1, remote1TemperatureC);
  reportResult("readRemoteTemperature(CH1)", remote1Ok);
  if (remote1Ok) {
    Serial.print("  Remote CH1: ");
    Serial.print(remote1TemperatureC, 4);
    Serial.println(" C");
  }

  float remote2TemperatureC;
  const bool remote2Ok = sensor.readRemoteTemperature(
      TMP4719::RemoteChannel::CH2, remote2TemperatureC);
  reportResult("readRemoteTemperature(CH2)", remote2Ok);
  if (remote2Ok) {
    Serial.print("  Remote CH2: ");
    Serial.print(remote2TemperatureC, 4);
    Serial.println(" C");
  }

  if (!REMOTE_CH2_CONNECTED) {
    reportInfo("CH2 is intentionally open; its temperature is not a valid measurement.");
  }
}

void testStatusAndFaults() {
  Serial.println();
  Serial.println("[TEST] Status and remote fault reporting");

  uint8_t highFlags;
  uint8_t lowFlags;
  uint8_t criticalFlags;
  const bool limitStatusOk = sensor.readLimitStatus(
      highFlags, lowFlags, criticalFlags);
  reportResult("readLimitStatus()", limitStatusOk);

  if (limitStatusOk) {
    Serial.print("  High flags Local/CH1/CH2: 0x");
    printHex8(highFlags);
    Serial.print("; Low flags: 0x");
    printHex8(lowFlags);
    Serial.print("; T_CRIT flags: 0x");
    printHex8(criticalFlags);
    Serial.println();
  }

  uint8_t faultFlags;
  const bool diodeFaultOk = sensor.readDiodeFaults(faultFlags);
  reportResult("readDiodeFaults()", diodeFaultOk);

  if (diodeFaultOk) {
    const bool ch1Open = (faultFlags & 0x01) != 0;
    const bool ch2Open = (faultFlags & 0x02) != 0;
    const bool shortDetected = (faultFlags & 0x04) != 0;

    Serial.print("  CH1 open: ");
    printBoolean(ch1Open);
    Serial.print("; CH2 open: ");
    printBoolean(ch2Open);
    Serial.print("; remote short: ");
    printBoolean(shortDetected);
    Serial.println();

    reportResult("CH1 open state matches hardware", ch1Open != REMOTE_CH1_CONNECTED);
    reportResult("CH2 open state matches hardware", ch2Open != REMOTE_CH2_CONNECTED);
    reportResult("No remote short detected", !shortDetected);
  }

  TMP4719::StatusFlags status{};
  const bool statusOk = sensor.readStatus(status);
  reportResult("readStatus()", statusOk);

  if (statusOk) {
    Serial.print("  ADC busy: ");
    printBoolean(status.adcBusy);
    Serial.print("; High: ");
    printBoolean(status.anyHigh);
    Serial.print("; Low: ");
    printBoolean(status.anyLow);
    Serial.print("; Remote fault: ");
    printBoolean(status.remoteFault);
    Serial.print("; T_CRIT: ");
    printBoolean(status.anyTCrit);
    Serial.println();

    const bool expectedRemoteFault =
        !REMOTE_CH1_CONNECTED || !REMOTE_CH2_CONNECTED;
    reportResult("Remote fault aggregate state matches hardware",
                 status.remoteFault == expectedRemoteFault);
  }
}

void testOperatingModeAndOneShot() {
  Serial.println();
  Serial.println("[TEST] Operating mode and one-shot conversion");

  TMP4719::OperatingMode originalMode;
  const bool getOk = sensor.getOperatingMode(originalMode);
  reportResult("getOperatingMode()", getOk);
  if (!getOk) {
    reportSkip("Operating mode write and one-shot tests");
    return;
  }

  reportResult("setOperatingMode(current mode)",
               sensor.setOperatingMode(originalMode));

  TMP4719::OperatingMode observedMode;
  const bool verifyOk = sensor.getOperatingMode(observedMode);
  reportResult("getOperatingMode() after write",
               verifyOk && observedMode == originalMode);

  if (originalMode == TMP4719::OperatingMode::CONTINUOUS) {
    reportExpectedFalse("triggerOneShot() is guarded in continuous mode",
                       sensor.triggerOneShot());

    const bool shutdownOk = sensor.setOperatingMode(
        TMP4719::OperatingMode::SHUTDOWN);
    reportResult("setOperatingMode(SHUTDOWN)", shutdownOk);

    if (shutdownOk) {
      const bool oneShotOk = sensor.triggerOneShot();
      reportResult("triggerOneShot() in shutdown mode", oneShotOk);
      if (oneShotOk) {
        reportResult("ADC returns idle after one-shot",
                     waitForAdcIdle(ADC_IDLE_TIMEOUT_MS));
      }
    }
  } else {
    const bool oneShotOk = sensor.triggerOneShot();
    reportResult("triggerOneShot() in shutdown mode", oneShotOk);
    if (oneShotOk) {
      reportResult("ADC returns idle after one-shot",
                   waitForAdcIdle(ADC_IDLE_TIMEOUT_MS));
    }
  }

  reportResult("restore original operating mode",
               sensor.setOperatingMode(originalMode));
}

bool configureSafeModeTestLimits() {
  const bool localLimitsOk =
      sensor.setAlertLimits(TMP4719::TemperatureChannel::LOCAL,
                            127.0f, -128.0f);
  const bool remote1LimitsOk =
      sensor.setAlertLimits(TMP4719::TemperatureChannel::REMOTE1,
                            127.0f, -127.875f);
  const bool remote2LimitsOk =
      sensor.setAlertLimits(TMP4719::TemperatureChannel::REMOTE2,
                            127.0f, -127.875f);
  const bool localCriticalOk =
      sensor.setCriticalLimit(TMP4719::TemperatureChannel::LOCAL, 127);
  const bool remote1CriticalOk =
      sensor.setCriticalLimit(TMP4719::TemperatureChannel::REMOTE1, 127);
  const bool remote2CriticalOk =
      sensor.setCriticalLimit(TMP4719::TemperatureChannel::REMOTE2, 127);

  return localLimitsOk && remote1LimitsOk && remote2LimitsOk &&
         localCriticalOk && remote1CriticalOk && remote2CriticalOk;
}

void verifyModeFunctionalState(const char *phase,
                               bool expectedHigh,
                               bool expectedLow,
                               bool expectedTCrit,
                               bool expectedAlertActive,
                               bool expectedTCritPinActive) {
  Serial.print("  Functional state: ");
  Serial.println(phase);

  int8_t localTemperatureC;
  float remote1TemperatureC;
  const bool localOk = sensor.readLocalTemperature(localTemperatureC);
  const bool remote1Ok = sensor.readRemoteTemperature(
      TMP4719::RemoteChannel::CH1, remote1TemperatureC);
  reportResult("temperature reads after mode transition", localOk && remote1Ok);

  TMP4719::StatusFlags status{};
  const bool statusOk = sensor.readStatus(status);
  reportResult("status read after mode transition", statusOk);
  if (statusOk) {
    reportResult("aggregate status after mode transition",
                 status.anyHigh == expectedHigh &&
                     status.anyLow == expectedLow &&
                     status.anyTCrit == expectedTCrit);
  }

  uint8_t highFlags;
  uint8_t lowFlags;
  uint8_t criticalFlags;
  const bool limitStatusOk = sensor.readLimitStatus(
      highFlags, lowFlags, criticalFlags);
  reportResult("per-channel limit status after mode transition",
               limitStatusOk &&
                   ((highFlags & 0x07) != 0) == expectedHigh &&
                   ((lowFlags & 0x07) != 0) == expectedLow &&
                   ((criticalFlags & 0x07) != 0) == expectedTCrit);

  const int alertLevel = digitalRead(ALERT_PIN);
  const int tcritLevel = digitalRead(TCRIT_PIN);
  printPinCheck("  ALERT", alertLevel, ALERT_ACTIVE_LEVEL,
                expectedAlertActive);
  printPinCheck("  T_CRIT", tcritLevel, TCRIT_ACTIVE_LEVEL,
                expectedTCritPinActive);
  reportResult("ALERT output after mode transition",
               (alertLevel == ALERT_ACTIVE_LEVEL) == expectedAlertActive);
  reportResult("T_CRIT output after mode transition",
               (tcritLevel == TCRIT_ACTIVE_LEVEL) == expectedTCritPinActive);
}

void testModeSwitchFunctionalBehavior() {
  Serial.println();
  Serial.println("[TEST] Functional behavior after operating-mode transitions");

  TMP4719::OperatingMode originalMode;
  uint8_t originalPeriod;
  float originalLocalHigh;
  float originalLocalLow;
  float originalRemote1High;
  float originalRemote1Low;
  float originalRemote2High;
  float originalRemote2Low;
  int8_t originalLocalCritical;
  int8_t originalRemote1Critical;
  int8_t originalRemote2Critical;
  uint8_t originalHysteresis;

  const bool stateSaved =
      sensor.getOperatingMode(originalMode) &&
      sensor.getConversionPeriodCode(originalPeriod) &&
      sensor.getAlertLimits(TMP4719::TemperatureChannel::LOCAL,
                            originalLocalHigh, originalLocalLow) &&
      sensor.getAlertLimits(TMP4719::TemperatureChannel::REMOTE1,
                            originalRemote1High, originalRemote1Low) &&
      sensor.getAlertLimits(TMP4719::TemperatureChannel::REMOTE2,
                            originalRemote2High, originalRemote2Low) &&
      sensor.getCriticalLimit(TMP4719::TemperatureChannel::LOCAL,
                              originalLocalCritical) &&
      sensor.getCriticalLimit(TMP4719::TemperatureChannel::REMOTE1,
                              originalRemote1Critical) &&
      sensor.getCriticalLimit(TMP4719::TemperatureChannel::REMOTE2,
                              originalRemote2Critical) &&
      sensor.getHysteresis(originalHysteresis);

  reportResult("save state before mode functional test", stateSaved);
  if (!stateSaved) {
    reportSkip("mode functional test because the original configuration could not be saved");
    return;
  }

  const bool periodCanBeRestored = originalPeriod <= 8;
  if (periodCanBeRestored) {
    reportResult("set fast conversion period for mode test",
                 sensor.setConversionPeriodCode(6));
  } else {
    reportSkip("fast conversion period because the original period code is outside the Terra driver's range");
  }

  const bool comparatorOk = sensor.setAlertMode(TMP4719::AlertMode::COMPARATOR);
  const bool globalMaskOk = sensor.setGlobalAlertMasked(false);
  const bool localMaskOk = sensor.setChannelAlertMasked(
      TMP4719::TemperatureChannel::LOCAL, false);
  const bool remote1MaskOk = sensor.setChannelAlertMasked(
      TMP4719::TemperatureChannel::REMOTE1, false);
  const bool remote2MaskOk = sensor.setChannelAlertMasked(
      TMP4719::TemperatureChannel::REMOTE2, false);
  const bool hysteresisOk = sensor.setHysteresis(1);
  reportResult("prepare comparator and unmasked mode-test state",
               comparatorOk && globalMaskOk && localMaskOk &&
                   remote1MaskOk && remote2MaskOk && hysteresisOk);

  const bool safeLimitsOk = configureSafeModeTestLimits();
  reportResult("prepare safe limits before mode transition", safeLimitsOk);
  if (!safeLimitsOk) {
    reportSkip("mode functional behavior because safe limits could not be written");
  } else {
    reportResult("switch to CONTINUOUS before functional test",
                 sensor.setOperatingMode(TMP4719::OperatingMode::CONTINUOUS));

    TMP4719::OperatingMode observedMode;
    const bool continuousModeOk = sensor.getOperatingMode(observedMode);
    reportResult("verify CONTINUOUS mode before functional test",
                 continuousModeOk &&
                     observedMode == TMP4719::OperatingMode::CONTINUOUS);
    delay(350);
    verifyModeFunctionalState("CONTINUOUS safe baseline", false, false, false,
                              false, false);

    reportResult("switch CONTINUOUS -> SHUTDOWN",
                 sensor.setOperatingMode(TMP4719::OperatingMode::SHUTDOWN));
    delay(100);
    const bool shutdownModeOk = sensor.getOperatingMode(observedMode);
    reportResult("verify SHUTDOWN mode after transition",
                 shutdownModeOk &&
                     observedMode == TMP4719::OperatingMode::SHUTDOWN);

    bool busy;
    const bool shutdownBusyReadOk = sensor.isAdcBusy(busy);
    reportResult("ADC is idle in SHUTDOWN mode",
                 shutdownBusyReadOk && !busy);
    verifyModeFunctionalState("SHUTDOWN before one-shot", false, false, false,
                              false, false);

    const bool oneShotOk = sensor.triggerOneShot();
    reportResult("trigger one-shot after entering SHUTDOWN",
                 oneShotOk);
    if (oneShotOk) {
      reportResult("ADC returns idle after SHUTDOWN one-shot",
                   waitForAdcIdle(ADC_IDLE_TIMEOUT_MS));
      verifyModeFunctionalState("SHUTDOWN after one-shot", false, false, false,
                                false, false);
    }

    reportResult("switch SHUTDOWN -> CONTINUOUS",
                 sensor.setOperatingMode(TMP4719::OperatingMode::CONTINUOUS));
    const bool resumedModeOk = sensor.getOperatingMode(observedMode);
    reportResult("verify CONTINUOUS mode after return",
                 resumedModeOk &&
                     observedMode == TMP4719::OperatingMode::CONTINUOUS);
    delay(350);
    verifyModeFunctionalState("CONTINUOUS after return from SHUTDOWN", false,
                              false, false, false, false);

    int8_t localTemperatureC;
    float remote1TemperatureC;
    const bool currentTemperatureOk =
        sensor.readLocalTemperature(localTemperatureC) &&
        sensor.readRemoteTemperature(TMP4719::RemoteChannel::CH1,
                                     remote1TemperatureC);
    reportResult("read temperatures for post-transition limit tests",
                 currentTemperatureOk);

    if (currentTemperatureOk) {
      const float localTemperature = static_cast<float>(localTemperatureC);

      // Verify the local high-limit path after returning to continuous mode.
      const bool localHighSetup =
          sensor.setAlertLimits(TMP4719::TemperatureChannel::LOCAL,
                                localTemperature - 1.0f, -128.0f) &&
          sensor.setAlertLimits(TMP4719::TemperatureChannel::REMOTE1,
                                127.0f, -127.875f) &&
          sensor.setAlertLimits(TMP4719::TemperatureChannel::REMOTE2,
                                127.0f, -127.875f) &&
          sensor.setCriticalLimit(TMP4719::TemperatureChannel::LOCAL, 127) &&
          sensor.setCriticalLimit(TMP4719::TemperatureChannel::REMOTE1, 127) &&
          sensor.setCriticalLimit(TMP4719::TemperatureChannel::REMOTE2, 127);
      reportResult("configure local high limit after mode return",
                   localHighSetup);
      delay(350);
      verifyModeFunctionalState("CONTINUOUS local high-limit condition", true,
                                false, false, true, false);

      const bool clearHighSetup = configureSafeModeTestLimits();
      reportResult("clear local high limit after mode return", clearHighSetup);
      delay(350);
      verifyModeFunctionalState("CONTINUOUS after high-limit release", false,
                                false, false, false, false);

      // Verify the local low-limit path after returning to continuous mode.
      const bool localLowSetup =
          sensor.setAlertLimits(TMP4719::TemperatureChannel::LOCAL,
                                127.0f, localTemperature + 1.0f) &&
          sensor.setAlertLimits(TMP4719::TemperatureChannel::REMOTE1,
                                127.0f, -127.875f) &&
          sensor.setAlertLimits(TMP4719::TemperatureChannel::REMOTE2,
                                127.0f, -127.875f);
      reportResult("configure local low limit after mode return",
                   localLowSetup);
      delay(350);
      verifyModeFunctionalState("CONTINUOUS local low-limit condition", false,
                                true, false, true, false);

      const bool clearLowSetup = configureSafeModeTestLimits();
      reportResult("clear local low limit after mode return", clearLowSetup);
      delay(350);
      verifyModeFunctionalState("CONTINUOUS after low-limit release", false,
                                false, false, false, false);

      // Verify the local T_CRIT path after returning to continuous mode.
      const bool localCriticalSetup =
          sensor.setCriticalLimit(TMP4719::TemperatureChannel::LOCAL,
                                  static_cast<int8_t>(localTemperature - 1.0f));
      reportResult("configure local T_CRIT after mode return",
                   localCriticalSetup);
      delay(350);
      verifyModeFunctionalState("CONTINUOUS local T_CRIT condition", false,
                                false, true, false, true);

      const bool clearCriticalSetup = configureSafeModeTestLimits();
      reportResult("clear local T_CRIT after mode return", clearCriticalSetup);
      delay(350);
      verifyModeFunctionalState("CONTINUOUS after T_CRIT release", false,
                                false, false, false, false);

      // Verify ALERT interrupt behavior after the operating-mode transitions.
      const bool interruptSetup =
          sensor.setAlertMode(TMP4719::AlertMode::INTERRUPT) &&
          sensor.setGlobalAlertMasked(false) &&
          sensor.setChannelAlertMasked(
              TMP4719::TemperatureChannel::LOCAL, false) &&
          sensor.setAlertLimits(TMP4719::TemperatureChannel::LOCAL,
                                localTemperature - 1.0f, -128.0f);
      reportResult("configure INTERRUPT ALERT after mode return",
                   interruptSetup);
      delay(350);

      const int interruptAlertLevel = digitalRead(ALERT_PIN);
      printPinCheck("  INTERRUPT ALERT", interruptAlertLevel,
                    ALERT_ACTIVE_LEVEL, true);
      reportResult("INTERRUPT ALERT asserts after mode return",
                   interruptAlertLevel == ALERT_ACTIVE_LEVEL);

      TMP4719::StatusFlags interruptStatus{};
      const bool interruptStatusOk = sensor.readStatus(interruptStatus);
      reportResult("read interrupt status after mode return",
                   interruptStatusOk && interruptStatus.anyHigh);
      reportResult("clear interrupt ALERT mask after status read",
                   sensor.setGlobalAlertMasked(false));

      const bool clearInterruptSetup = configureSafeModeTestLimits() &&
                                       sensor.setAlertMode(
                                           TMP4719::AlertMode::COMPARATOR) &&
                                       sensor.setGlobalAlertMasked(false);
      reportResult("restore safe comparator state after INTERRUPT test",
                   clearInterruptSetup);
      delay(350);
      verifyModeFunctionalState("CONTINUOUS after INTERRUPT recovery", false,
                                false, false, false, false);
    }
  }

  // Restore the configuration that existed before this functional test.
  const bool restoreLocalLimits = sensor.setAlertLimits(
      TMP4719::TemperatureChannel::LOCAL, originalLocalHigh, originalLocalLow);
  const bool restoreRemote1Limits = sensor.setAlertLimits(
      TMP4719::TemperatureChannel::REMOTE1, originalRemote1High,
      originalRemote1Low);
  const bool restoreRemote2Limits = sensor.setAlertLimits(
      TMP4719::TemperatureChannel::REMOTE2, originalRemote2High,
      originalRemote2Low);
  const bool restoreLocalCritical = sensor.setCriticalLimit(
      TMP4719::TemperatureChannel::LOCAL, originalLocalCritical);
  const bool restoreRemote1Critical = sensor.setCriticalLimit(
      TMP4719::TemperatureChannel::REMOTE1, originalRemote1Critical);
  const bool restoreRemote2Critical = sensor.setCriticalLimit(
      TMP4719::TemperatureChannel::REMOTE2, originalRemote2Critical);
  const bool restoreHysteresis = sensor.setHysteresis(originalHysteresis);
  const bool restoreAlertMode = sensor.setAlertMode(
      TMP4719::AlertMode::COMPARATOR);
  const bool restoreGlobalMask = sensor.setGlobalAlertMasked(false);
  const bool restoreLocalMask = sensor.setChannelAlertMasked(
      TMP4719::TemperatureChannel::LOCAL, false);
  const bool restoreRemote1Mask = sensor.setChannelAlertMasked(
      TMP4719::TemperatureChannel::REMOTE1, false);
  const bool restoreRemote2Mask = sensor.setChannelAlertMasked(
      TMP4719::TemperatureChannel::REMOTE2, false);
  const bool restorePeriod = !periodCanBeRestored ||
                             sensor.setConversionPeriodCode(originalPeriod);
  const bool restoreMode = sensor.setOperatingMode(originalMode);

  reportResult("restore mode-test thresholds and configuration",
               restoreLocalLimits && restoreRemote1Limits &&
                   restoreRemote2Limits && restoreLocalCritical &&
                   restoreRemote1Critical && restoreRemote2Critical &&
                   restoreHysteresis && restoreAlertMode &&
                   restoreGlobalMask && restoreLocalMask &&
                   restoreRemote1Mask && restoreRemote2Mask && restorePeriod &&
                   restoreMode);

  TMP4719::OperatingMode finalMode;
  const bool finalModeReadOk = sensor.getOperatingMode(finalMode);
  reportResult("verify original operating mode after functional test",
               finalModeReadOk && finalMode == originalMode);
}

void testConversionPeriod() {
  Serial.println();
  Serial.println("[TEST] Conversion period");

  uint8_t originalCode;
  const bool getOk = sensor.getConversionPeriodCode(originalCode);
  reportResult("getConversionPeriodCode()", getOk);
  if (!getOk) {
    reportSkip("Conversion period write and verification");
    return;
  }

  Serial.print("  Original conversion code: ");
  Serial.println(static_cast<unsigned int>(originalCode));

  if (originalCode <= 8) {
    const uint8_t testCode = originalCode == 0 ? 1 : 0;
    reportResult("setConversionPeriodCode(valid code)",
                 sensor.setConversionPeriodCode(testCode));

    uint8_t observedCode;
    const bool verifyOk = sensor.getConversionPeriodCode(observedCode);
    reportResult("getConversionPeriodCode() after write",
                 verifyOk && observedCode == testCode);

    reportResult("restore conversion period",
                 sensor.setConversionPeriodCode(originalCode));
  } else {
    reportSkip("Conversion period round-trip because the read code is outside the driver range");
  }

  reportExpectedFalse("setConversionPeriodCode(9) rejects invalid code",
                     sensor.setConversionPeriodCode(9));
}

void testAlertLimitsForChannel(TMP4719::TemperatureChannel channel,
                               const char *label) {
  float originalHigh;
  float originalLow;

  const bool getOk = sensor.getAlertLimits(channel, originalHigh, originalLow);
  reportResult(label, getOk);
  if (!getOk) {
    return;
  }

  Serial.print("  ");
  Serial.print(label);
  Serial.print(" high=");
  Serial.print(originalHigh, 4);
  Serial.print(" C, low=");
  Serial.print(originalLow, 4);
  Serial.println(" C");

  reportResult("setAlertLimits(current values)",
               sensor.setAlertLimits(channel, originalHigh, originalLow));

  float observedHigh;
  float observedLow;
  const bool verifyOk = sensor.getAlertLimits(channel, observedHigh, observedLow);
  reportResult("getAlertLimits() after write",
               verifyOk && approximatelyEqual(observedHigh, originalHigh) &&
                   approximatelyEqual(observedLow, originalLow));
}

void testAlertLimits() {
  Serial.println();
  Serial.println("[TEST] ALERT high and low limits");

  testAlertLimitsForChannel(TMP4719::TemperatureChannel::LOCAL,
                            "getAlertLimits(LOCAL)");
  testAlertLimitsForChannel(TMP4719::TemperatureChannel::REMOTE1,
                            "getAlertLimits(REMOTE1)");
  testAlertLimitsForChannel(TMP4719::TemperatureChannel::REMOTE2,
                            "getAlertLimits(REMOTE2)");

  reportExpectedFalse("setAlertLimits(LOCAL, 128 C, 0 C) rejects invalid range",
                     sensor.setAlertLimits(
                         TMP4719::TemperatureChannel::LOCAL, 128.0f, 0.0f));
}

void testCriticalLimitForChannel(TMP4719::TemperatureChannel channel,
                                 const char *label) {
  int8_t originalLimit;
  const bool getOk = sensor.getCriticalLimit(channel, originalLimit);
  reportResult(label, getOk);
  if (!getOk) {
    return;
  }

  Serial.print("  ");
  Serial.print(label);
  Serial.print(" = ");
  Serial.print(static_cast<int>(originalLimit));
  Serial.println(" C");

  reportResult("setCriticalLimit(current value)",
               sensor.setCriticalLimit(channel, originalLimit));

  int8_t observedLimit;
  const bool verifyOk = sensor.getCriticalLimit(channel, observedLimit);
  reportResult("getCriticalLimit() after write",
               verifyOk && observedLimit == originalLimit);
}

void testCriticalLimits() {
  Serial.println();
  Serial.println("[TEST] T_CRIT limits");

  testCriticalLimitForChannel(TMP4719::TemperatureChannel::LOCAL,
                              "getCriticalLimit(LOCAL)");
  testCriticalLimitForChannel(TMP4719::TemperatureChannel::REMOTE1,
                              "getCriticalLimit(REMOTE1)");
  testCriticalLimitForChannel(TMP4719::TemperatureChannel::REMOTE2,
                              "getCriticalLimit(REMOTE2)");
}

void testHysteresis() {
  Serial.println();
  Serial.println("[TEST] ALERT and T_CRIT hysteresis");

  uint8_t originalValue;
  const bool getOk = sensor.getHysteresis(originalValue);
  reportResult("getHysteresis()", getOk);
  if (!getOk) {
    return;
  }

  const uint8_t testValue = originalValue == 0 ? 1 : 0;
  reportResult("setHysteresis(valid value)",
               sensor.setHysteresis(testValue));

  uint8_t observedValue;
  const bool verifyOk = sensor.getHysteresis(observedValue);
  reportResult("getHysteresis() after write",
               verifyOk && observedValue == testValue);

  reportResult("restore hysteresis", sensor.setHysteresis(originalValue));
  reportExpectedFalse("setHysteresis(32) rejects invalid range",
                     sensor.setHysteresis(32));
}

void testAlertModeAndMasks() {
  Serial.println();
  Serial.println("[TEST] ALERT mode and masks");

  reportResult("setAlertMode(INTERRUPT)",
               sensor.setAlertMode(TMP4719::AlertMode::INTERRUPT));
  reportResult("setAlertMode(COMPARATOR)",
               sensor.setAlertMode(TMP4719::AlertMode::COMPARATOR));
  reportResult("restore Alert mode to COMPARATOR",
               sensor.setAlertMode(TMP4719::AlertMode::COMPARATOR));

  reportResult("setGlobalAlertMasked(true)",
               sensor.setGlobalAlertMasked(true));
  reportResult("setGlobalAlertMasked(false)",
               sensor.setGlobalAlertMasked(false));

  const TMP4719::TemperatureChannel channels[] = {
      TMP4719::TemperatureChannel::LOCAL,
      TMP4719::TemperatureChannel::REMOTE1,
      TMP4719::TemperatureChannel::REMOTE2};

  for (const TMP4719::TemperatureChannel channel : channels) {
    reportResult("setChannelAlertMasked(true)",
                 sensor.setChannelAlertMasked(channel, true));
    reportResult("setChannelAlertMasked(false)",
                 sensor.setChannelAlertMasked(channel, false));
  }

  reportInfo("Alert mode is left in COMPARATOR and all ALERT masks are cleared because the driver has no mask/mode getters.");
}

void testFilter() {
  Serial.println();
  Serial.println("[TEST] Digital filter");

  reportResult("setFilterLevel(DISABLED)",
               sensor.setFilterLevel(TMP4719::FilterLevel::DISABLED));
  reportResult("setFilterLevel(FOUR)",
               sensor.setFilterLevel(TMP4719::FilterLevel::FOUR));
  reportResult("setFilterLevel(EIGHT)",
               sensor.setFilterLevel(TMP4719::FilterLevel::EIGHT));
  reportResult("restore filter to DISABLED",
               sensor.setFilterLevel(TMP4719::FilterLevel::DISABLED));
  reportInfo("Filter level is left in DISABLED because the driver has no filter getter.");
}

void testIdealityForChannel(TMP4719::RemoteChannel channel,
                            const char *label) {
  uint8_t originalCode;
  const bool getOk = sensor.getIdealityCode(channel, originalCode);
  reportResult(label, getOk);
  if (!getOk) {
    return;
  }

  Serial.print("  ");
  Serial.print(label);
  Serial.print(" = 0x");
  printHex8(originalCode);
  Serial.println();

  if (originalCode >= 0x08 && originalCode <= 0x37) {
    const uint8_t testCode = originalCode == 0x08 ? 0x09 : 0x08;
    reportResult("setIdealityCode(valid code)",
                 sensor.setIdealityCode(channel, testCode));

    uint8_t observedCode;
    const bool verifyOk = sensor.getIdealityCode(channel, observedCode);
    reportResult("getIdealityCode() after write",
                 verifyOk && observedCode == testCode);

    reportResult("restore ideality code",
                 sensor.setIdealityCode(channel, originalCode));
  } else {
    reportSkip("Ideality round-trip because the read code is outside the driver range");
  }
}

void testIdeality() {
  Serial.println();
  Serial.println("[TEST] Remote diode ideality factor");

  testIdealityForChannel(TMP4719::RemoteChannel::CH1,
                         "getIdealityCode(CH1)");
  testIdealityForChannel(TMP4719::RemoteChannel::CH2,
                         "getIdealityCode(CH2)");

  reportExpectedFalse("setIdealityCode(CH1, 0x07) rejects invalid code",
                     sensor.setIdealityCode(TMP4719::RemoteChannel::CH1, 0x07));
  reportExpectedFalse("setIdealityCode(CH1, 0x38) rejects invalid code",
                     sensor.setIdealityCode(TMP4719::RemoteChannel::CH1, 0x38));
}

void testScratchpad(uint8_t index, uint8_t testValue) {
  uint8_t originalValue;
  const bool readOk = sensor.readScratchpad(index, originalValue);
  reportResult("readScratchpad(original)", readOk);
  if (!readOk) {
    return;
  }

  reportResult("writeScratchpad(test value)",
               sensor.writeScratchpad(index, testValue));

  uint8_t observedValue;
  const bool verifyOk = sensor.readScratchpad(index, observedValue);
  reportResult("readScratchpad(test value)",
               verifyOk && observedValue == testValue);

  reportResult("restoreScratchpad(original value)",
               sensor.writeScratchpad(index, originalValue));

  uint8_t restoredValue;
  const bool restoreVerifyOk = sensor.readScratchpad(index, restoredValue);
  reportResult("readScratchpad(restored value)",
               restoreVerifyOk && restoredValue == originalValue);
}

void testScratchpads() {
  Serial.println();
  Serial.println("[TEST] Scratchpads");

  testScratchpad(1, SCRATCHPAD1_TEST_VALUE);
  testScratchpad(2, SCRATCHPAD2_TEST_VALUE);

  uint8_t unusedValue;
  reportExpectedFalse("writeScratchpad(index 0) rejects invalid index",
                     sensor.writeScratchpad(0, 0x00));
  reportExpectedFalse("readScratchpad(index 3) rejects invalid index",
                     sensor.readScratchpad(3, unusedValue));
}

void testInvalidArguments() {
  Serial.println();
  Serial.println("[TEST] Input validation");

  reportExpectedFalse("setConversionPeriodCode(9) rejects invalid code",
                     sensor.setConversionPeriodCode(9));
  reportExpectedFalse("setHysteresis(32) rejects invalid value",
                     sensor.setHysteresis(32));
  reportExpectedFalse("setAlertLimits(LOCAL, 128 C, 0 C) rejects invalid range",
                     sensor.setAlertLimits(
                         TMP4719::TemperatureChannel::LOCAL, 128.0f, 0.0f));
  reportExpectedFalse("setIdealityCode(CH1, 0x07) rejects invalid code",
                     sensor.setIdealityCode(TMP4719::RemoteChannel::CH1, 0x07));
}

void runFullApiTest() {
  passCount = 0;
  failCount = 0;
  skipCount = 0;

  Serial.println();
  Serial.println("========================================");
  Serial.println("TMP4719 full driver API test");
  Serial.println("========================================");

  reportResult("begin()", sensor.begin());

  testDeviceIdentity();
  testTemperatureReads();
  testStatusAndFaults();
  testOperatingModeAndOneShot();
  testModeSwitchFunctionalBehavior();
  testConversionPeriod();
  testAlertLimits();
  testCriticalLimits();
  testHysteresis();
  testAlertModeAndMasks();
  testFilter();
  testIdeality();
  testScratchpads();
  testInvalidArguments();

  Serial.println();
  Serial.println("========================================");
  Serial.print("API test summary: PASS=");
  Serial.print(passCount);
  Serial.print(" FAIL=");
  Serial.print(failCount);
  Serial.print(" SKIP=");
  Serial.println(skipCount);
  Serial.println("========================================");
  reportInfo("Default ALERT state: COMPARATOR mode with all ALERT masks disabled.");
}

void runMonitorCycle() {
  Serial.println();
  Serial.println("--- Status monitor ---");

  int8_t localTemperatureC;
  if (sensor.readLocalTemperature(localTemperatureC)) {
    Serial.print("Local temperature: ");
    Serial.print(static_cast<int>(localTemperatureC));
    Serial.println(" C");
  } else {
    Serial.println("Local temperature: READ_ERROR");
  }

  float remote1TemperatureC;
  if (sensor.readRemoteTemperature(TMP4719::RemoteChannel::CH1,
                                   remote1TemperatureC)) {
    Serial.print("Remote CH1 temperature: ");
    Serial.print(remote1TemperatureC, 4);
    Serial.println(" C");
  } else {
    Serial.println("Remote CH1 temperature: READ_ERROR");
  }

  float remote2TemperatureC;
  if (sensor.readRemoteTemperature(TMP4719::RemoteChannel::CH2,
                                   remote2TemperatureC)) {
    Serial.print("Remote CH2 temperature: ");
    Serial.print(remote2TemperatureC, 4);
    Serial.println(" C (unused channel)");
  } else {
    Serial.println("Remote CH2 temperature: READ_ERROR");
  }

  const int alertLevel = digitalRead(ALERT_PIN);
  const int tcritLevel = digitalRead(TCRIT_PIN);

  uint8_t faultFlags;
  if (sensor.readDiodeFaults(faultFlags)) {
    Serial.print("Diode fault flags: 0x");
    printHex8(faultFlags);
    Serial.println();
  } else {
    Serial.println("Diode fault flags: READ_ERROR");
  }

  uint8_t highFlags;
  uint8_t lowFlags;
  uint8_t criticalFlags;
  if (sensor.readLimitStatus(highFlags, lowFlags, criticalFlags)) {
    Serial.print("Limit flags High/Low/T_CRIT: 0x");
    printHex8(highFlags);
    Serial.print("/0x");
    printHex8(lowFlags);
    Serial.print("/0x");
    printHex8(criticalFlags);
    Serial.println();
  } else {
    Serial.println("Limit flags: READ_ERROR");
  }

  TMP4719::StatusFlags status{};
  if (sensor.readStatus(status)) {
    Serial.print("ADC busy: ");
    printBoolean(status.adcBusy);
    Serial.print("; High: ");
    printBoolean(status.anyHigh);
    Serial.print("; Low: ");
    printBoolean(status.anyLow);
    Serial.print("; Remote fault: ");
    printBoolean(status.remoteFault);
    Serial.print("; T_CRIT: ");
    printBoolean(status.anyTCrit);
    Serial.println();

    printPinCheck("ALERT", alertLevel, ALERT_ACTIVE_LEVEL,
                  status.anyHigh || status.anyLow);
    printPinCheck("T_CRIT", tcritLevel, TCRIT_ACTIVE_LEVEL,
                  status.anyTCrit);
  } else {
    Serial.println("Status: READ_ERROR");
    Serial.print("ALERT pin: ");
    Serial.println(alertLevel == HIGH ? "HIGH" : "LOW");
    Serial.print("T_CRIT pin: ");
    Serial.println(tcritLevel == HIGH ? "HIGH" : "LOW");
  }
}

void setup() {
  Serial.begin(115200);

  const unsigned long serialStart = millis();
  while (!Serial && (millis() - serialStart < 3000UL)) {
    delay(10);
  }

  Wire.setSDA(I2C_SDA_PIN);
  Wire.setSCL(I2C_SCL_PIN);
  Wire.begin();

  pinMode(ALERT_PIN, INPUT);
  pinMode(TCRIT_PIN, INPUT);

  Serial.println();
  Serial.println("TMP4719 RP2040 test");
  Serial.print("I2C address: 0x");
  printHex8(TMP4719::I2C_DEFAULT_ADDRESS);
  Serial.println();

  deviceReady = sensor.begin();
  if (deviceReady) {
    Serial.println("TMP4719: READY");

    sensor.setHysteresis(1);

    sensor.setAlertLimits(TMP4719::TemperatureChannel::LOCAL, 35.0f, 0.0f);
    sensor.setAlertLimits(TMP4719::TemperatureChannel::REMOTE1, 35.0f, 0.0f);
    sensor.setAlertLimits(TMP4719::TemperatureChannel::REMOTE2, 35.0f, 0.0f);
    sensor.setCriticalLimit(TMP4719::TemperatureChannel::LOCAL, 35);
    sensor.setCriticalLimit(TMP4719::TemperatureChannel::REMOTE1, 35);
    sensor.setCriticalLimit(TMP4719::TemperatureChannel::REMOTE2, 35);



    runFullApiTest();
    lastFullApiTestMs = millis();
  } else {
    Serial.println("TMP4719: BEGIN_ERROR");
  }
}

void loop() {
  if (!deviceReady) {
    deviceReady = sensor.begin();
    if (!deviceReady) {
      delay(1000);
      return;
    }
    Serial.println("TMP4719: READY");
    runFullApiTest();
    lastFullApiTestMs = millis();
  }

  if (millis() - lastFullApiTestMs >= FULL_API_TEST_INTERVAL_MS) {
    runFullApiTest();
    lastFullApiTestMs = millis();
  }

  runMonitorCycle();
  delay(1000);
}
