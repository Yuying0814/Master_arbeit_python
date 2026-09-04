#include <Arduino.h>
#include <Wire.h>
#include <math.h>

// The sketch is kept separate from the driver source. The absolute path is
// intentional because Arduino CLI does not resolve parent-directory includes
// from a sketch stored outside the driver folder.
#include "BME280.h"

static const uint8_t I2C_SDA_PIN = 0;
static const uint8_t I2C_SCL_PIN = 1;
static const uint8_t BME280_I2C_ADDRESS = 0x76;

static const uint32_t BEGIN_TIMEOUT_MS = 500;
static const uint32_t STATUS_TIMEOUT_MS = 500;
static const uint32_t MONITOR_PERIOD_MS = 1000;
static const uint32_t FULL_TEST_PERIOD_MS = 15000;

static const BME280::Oversampling SAFE_HUMIDITY_OS = BME280::Oversampling::X1;
static const BME280::Oversampling SAFE_TEMPERATURE_OS = BME280::Oversampling::X1;
static const BME280::Oversampling SAFE_PRESSURE_OS = BME280::Oversampling::X1;

BME280 bme280(Wire, BME280_I2C_ADDRESS);

enum CheckId : uint8_t {
    CHECK_BEGIN,
    CHECK_LAST_ERROR,
    CHECK_CHIP_ID,
    CHECK_CONNECTION,
    CHECK_CALIBRATION,
    CHECK_STATUS,
    CHECK_MEASUREMENT_TIME,
    CHECK_CONFIGURATION,
    CHECK_MODE,
    CHECK_SLEEP_MODE_BEHAVIOR,
    CHECK_FORCED_MODE_BEHAVIOR,
    CHECK_NORMAL_MODE_BEHAVIOR,
    CHECK_WAIT,
    CHECK_FORCED_MEASUREMENT,
    CHECK_RAW_SAMPLE,
    CHECK_COMPENSATED_SAMPLE,
    CHECK_SOFT_RESET,
    CHECK_SELF_TEST,
    CHECK_SPI_TRANSPORT,
    CHECK_COUNT
};

enum CheckState : uint8_t {
    CHECK_NOT_RUN,
    CHECK_PASS,
    CHECK_FAIL,
    CHECK_SKIP
};

static CheckState checkStates[CHECK_COUNT];
static uint32_t monitorCycle = 0;
static uint32_t lastMonitorAt = 0;
static uint32_t lastFullTestAt = 0;
static bool deviceReady = false;

static const char *checkNames[CHECK_COUNT] = {
    "begin() initialization",
    "lastError() reporting",
    "readChipId()",
    "isConnected()",
    "readCalibration()",
    "isMeasuring() and isUpdating()",
    "measurementTimeMaxMs()",
    "configure() profiles and enum branches",
    "setMode() and getMode() selection",
    "Sleep mode functional behavior",
    "Forced mode functional behavior",
    "Normal mode cyclic behavior",
    "waitForMeasurement()",
    "takeForcedMeasurement()",
    "readRaw()",
    "readMeasurements() compensation",
    "softReset() and recovery",
    "selfTest()",
    "SPI transport and constructor"
};

static const char *errorName(BME280::Error error) {
    switch (error) {
        case BME280::Error::Ok:
            return "Ok";
        case BME280::Error::CommError:
            return "CommError";
        case BME280::Error::Timeout:
            return "Timeout";
        case BME280::Error::BadId:
            return "BadId";
        case BME280::Error::CalibrationMissing:
            return "CalibrationMissing";
        case BME280::Error::InvalidArgument:
            return "InvalidArgument";
        case BME280::Error::SelfTestFailed:
            return "SelfTestFailed";
        case BME280::Error::Unknown:
            return "Unknown";
        default:
            return "Unlisted";
    }
}

static const char *selfTestName(BME280::SelfTestResult result) {
    switch (result) {
        case BME280::SelfTestResult::Passed:
            return "Passed";
        case BME280::SelfTestResult::CommError:
            return "CommError";
        case BME280::SelfTestResult::BadId:
            return "BadId";
        case BME280::SelfTestResult::CalibrationMissing:
            return "CalibrationMissing";
        case BME280::SelfTestResult::ClippedRaw:
            return "ClippedRaw";
        case BME280::SelfTestResult::ImplausibleMeasurement:
            return "ImplausibleMeasurement";
        case BME280::SelfTestResult::ResetFailed:
            return "ResetFailed";
        default:
            return "Unlisted";
    }
}

static const char *modeName(BME280::Mode mode) {
    switch (mode) {
        case BME280::Mode::Sleep:
            return "Sleep";
        case BME280::Mode::Forced:
            return "Forced";
        case BME280::Mode::Normal:
            return "Normal";
        default:
            return "Unknown";
    }
}

static const char *checkStateName(CheckState state) {
    switch (state) {
        case CHECK_PASS:
            return "PASS";
        case CHECK_FAIL:
            return "FAIL";
        case CHECK_SKIP:
            return "SKIP";
        default:
            return "NOT RUN";
    }
}

static void markCheck(CheckId id, bool passed) {
    checkStates[id] = passed ? CHECK_PASS : CHECK_FAIL;
    Serial.print("    [");
    Serial.print(passed ? "PASS" : "FAIL");
    Serial.print("] ");
    Serial.println(checkNames[id]);
}

static void skipCheck(CheckId id, const char *reason) {
    checkStates[id] = CHECK_SKIP;
    Serial.print("    [SKIP] ");
    Serial.print(checkNames[id]);
    if (reason != nullptr) {
        Serial.print(" -- ");
        Serial.print(reason);
    }
    Serial.println();
}

static void resetChecklist() {
    for (uint8_t i = 0; i < CHECK_COUNT; ++i) {
        checkStates[i] = CHECK_NOT_RUN;
    }
}

static void printChecklistPlan() {
    Serial.println();
    Serial.println("[CHECKLIST] Planned checks for this cycle");
    for (uint8_t i = 0; i < CHECK_COUNT; ++i) {
        Serial.print("  ");
        Serial.print(i + 1);
        Serial.print(". ");
        Serial.println(checkNames[i]);
    }
    Serial.println("  SPI is intentionally skipped: the sensor is not wired to SPI.");
}

static void printChecklistSummary() {
    uint8_t passCount = 0;
    uint8_t failCount = 0;
    uint8_t skipCount = 0;
    uint8_t notRunCount = 0;

    Serial.println();
    Serial.println("[CHECKLIST] Results");
    for (uint8_t i = 0; i < CHECK_COUNT; ++i) {
        Serial.print("  [");
        Serial.print(checkStateName(checkStates[i]));
        Serial.print("] ");
        Serial.println(checkNames[i]);

        if (checkStates[i] == CHECK_PASS) {
            ++passCount;
        } else if (checkStates[i] == CHECK_FAIL) {
            ++failCount;
        } else if (checkStates[i] == CHECK_SKIP) {
            ++skipCount;
        } else {
            ++notRunCount;
        }
    }

    Serial.println();
    Serial.print("Checklist summary: PASS=");
    Serial.print(passCount);
    Serial.print(" FAIL=");
    Serial.print(failCount);
    Serial.print(" SKIP=");
    Serial.print(skipCount);
    Serial.print(" NOT_RUN=");
    Serial.println(notRunCount);
}

static bool isFiniteFloat(float value) {
    return !isnan(value) && !isinf(value);
}

static bool rawSampleIsValid(const BME280::RawSample &raw) {
    const bool pressureValid = raw.pressure <= 0xFFFFFu && raw.pressure != 0x80000u;
    const bool temperatureValid = raw.temperature <= 0xFFFFFu && raw.temperature != 0x80000u;
    const bool humidityValid = raw.humidity <= 0xFFFFu && raw.humidity != 0x8000u;
    return pressureValid && temperatureValid && humidityValid;
}

static bool measurementIsValid(const BME280::Measurement &sample) {
    return isFiniteFloat(sample.temperature_C) &&
           isFiniteFloat(sample.pressure_Pa) &&
           isFiniteFloat(sample.humidity_pc) &&
           sample.temperature_C >= -40.0f && sample.temperature_C <= 85.0f &&
           sample.pressure_Pa >= 30000.0f && sample.pressure_Pa <= 110000.0f &&
           sample.humidity_pc >= 0.0f && sample.humidity_pc <= 100.0f;
}

static void printRawSample(const BME280::RawSample &raw) {
    Serial.print("Raw: P=");
    Serial.print(raw.pressure);
    Serial.print(", T=");
    Serial.print(raw.temperature);
    Serial.print(", H=");
    Serial.println(raw.humidity);
}

static void printMeasurement(const BME280::Measurement &sample) {
    Serial.print("Measurement: T=");
    Serial.print(sample.temperature_C, 2);
    Serial.print(" degC, P=");
    Serial.print(sample.pressure_Pa, 2);
    Serial.print(" Pa, H=");
    Serial.print(sample.humidity_pc, 2);
    Serial.println(" %RH");
}

static bool approximatelyEqual(float actual, float expected, float tolerance) {
    return fabsf(actual - expected) <= tolerance;
}

static bool rawSamplesEqual(const BME280::RawSample &a,
                            const BME280::RawSample &b) {
    return a.pressure == b.pressure &&
           a.temperature == b.temperature &&
           a.humidity == b.humidity;
}

static bool waitForMeasuringState(bool expected, uint32_t timeoutMs) {
    const uint32_t startedAt = millis();
    bool measuring = !expected;

    do {
        if (!bme280.isMeasuring(measuring)) {
            return false;
        }
        if (measuring == expected) {
            return true;
        }
        delay(1);
    } while ((uint32_t)(millis() - startedAt) <= timeoutMs);

    return false;
}

static bool waitForMode(BME280::Mode expected, uint32_t timeoutMs) {
    const uint32_t startedAt = millis();
    BME280::Mode mode = BME280::Mode::Sleep;

    do {
        if (!bme280.getMode(mode)) {
            return false;
        }
        if (mode == expected) {
            return true;
        }
        delay(1);
    } while ((uint32_t)(millis() - startedAt) <= timeoutMs);

    return false;
}

static bool waitUntilIdle(uint32_t timeoutMs) {
    const uint32_t startedAt = millis();
    bool measuring = false;

    do {
        if (!bme280.isMeasuring(measuring)) {
            return false;
        }
        if (!measuring) {
            return true;
        }
        delay(1);
    } while ((uint32_t)(millis() - startedAt) <= timeoutMs);

    return false;
}

static bool settleAfterMeasurement(BME280::Oversampling humidity,
                                   BME280::Oversampling temperature,
                                   BME280::Oversampling pressure) {
    const float conversionTimeMs = bme280.measurementTimeMaxMs(
        humidity, temperature, pressure);
    const uint32_t conservativeDelayMs = (uint32_t)ceilf(conversionTimeMs) + 5u;
    delay(conservativeDelayMs);
    return waitUntilIdle(STATUS_TIMEOUT_MS);
}

static bool configureSafeSleep() {
    const bool configured = bme280.configure(
        SAFE_HUMIDITY_OS,
        SAFE_TEMPERATURE_OS,
        SAFE_PRESSURE_OS,
        BME280::StandbyTime::T_1000_ms,
        BME280::Filter::Off,
        BME280::Mode::Sleep,
        false);

    BME280::Mode mode = BME280::Mode::Normal;
    const bool modeReadable = bme280.getMode(mode);
    return configured && modeReadable && mode == BME280::Mode::Sleep;
}

static void testMeasurementTime() {
    const float allSkipped = bme280.measurementTimeMaxMs(
        BME280::Oversampling::Skipped,
        BME280::Oversampling::Skipped,
        BME280::Oversampling::Skipped);
    const float x1 = bme280.measurementTimeMaxMs(
        BME280::Oversampling::X1,
        BME280::Oversampling::X1,
        BME280::Oversampling::X1);
    const float x16 = bme280.measurementTimeMaxMs(
        BME280::Oversampling::X16,
        BME280::Oversampling::X16,
        BME280::Oversampling::X16);

    Serial.print("    all skipped: ");
    Serial.print(allSkipped, 3);
    Serial.println(" ms");
    Serial.print("    X1 all channels: ");
    Serial.print(x1, 3);
    Serial.println(" ms");
    Serial.print("    X16 all channels: ");
    Serial.print(x16, 3);
    Serial.println(" ms");

    // The tolerance keeps this check independent of small floating-point
    // implementation differences while still checking the formula branch.
    const bool passed = approximatelyEqual(allSkipped, 1.25f, 0.01f) &&
                        approximatelyEqual(x1, 9.30f, 0.02f) &&
                        approximatelyEqual(x16, 112.80f, 0.20f);
    markCheck(CHECK_MEASUREMENT_TIME, passed);
}

static void testConfigurationProfiles() {
    bool passed = true;

    const BME280::Oversampling oversamplingValues[] = {
        BME280::Oversampling::Skipped,
        BME280::Oversampling::X1,
        BME280::Oversampling::X2,
        BME280::Oversampling::X4,
        BME280::Oversampling::X8,
        BME280::Oversampling::X16
    };
    const BME280::StandbyTime standbyValues[] = {
        BME280::StandbyTime::T_0p5_ms,
        BME280::StandbyTime::T_62p5_ms,
        BME280::StandbyTime::T_125_ms,
        BME280::StandbyTime::T_250_ms,
        BME280::StandbyTime::T_500_ms,
        BME280::StandbyTime::T_1000_ms,
        BME280::StandbyTime::T_10_ms,
        BME280::StandbyTime::T_20_ms
    };
    const BME280::Filter filterValues[] = {
        BME280::Filter::Off,
        BME280::Filter::C2,
        BME280::Filter::C4,
        BME280::Filter::C8,
        BME280::Filter::C16
    };

    for (uint8_t i = 0; i < sizeof(oversamplingValues) / sizeof(oversamplingValues[0]); ++i) {
        passed = bme280.configure(
                     oversamplingValues[i],
                     SAFE_TEMPERATURE_OS,
                     SAFE_PRESSURE_OS,
                     BME280::StandbyTime::T_1000_ms,
                     BME280::Filter::Off,
                     BME280::Mode::Sleep,
                     false) && passed;
    }
    for (uint8_t i = 0; i < sizeof(oversamplingValues) / sizeof(oversamplingValues[0]); ++i) {
        passed = bme280.configure(
                     SAFE_HUMIDITY_OS,
                     oversamplingValues[i],
                     SAFE_PRESSURE_OS,
                     BME280::StandbyTime::T_1000_ms,
                     BME280::Filter::Off,
                     BME280::Mode::Sleep,
                     false) && passed;
    }
    for (uint8_t i = 0; i < sizeof(oversamplingValues) / sizeof(oversamplingValues[0]); ++i) {
        passed = bme280.configure(
                     SAFE_HUMIDITY_OS,
                     SAFE_TEMPERATURE_OS,
                     oversamplingValues[i],
                     BME280::StandbyTime::T_1000_ms,
                     BME280::Filter::Off,
                     BME280::Mode::Sleep,
                     false) && passed;
    }
    for (uint8_t i = 0; i < sizeof(standbyValues) / sizeof(standbyValues[0]); ++i) {
        passed = bme280.configure(
                     SAFE_HUMIDITY_OS,
                     SAFE_TEMPERATURE_OS,
                     SAFE_PRESSURE_OS,
                     standbyValues[i],
                     BME280::Filter::Off,
                     BME280::Mode::Sleep,
                     false) && passed;
    }
    for (uint8_t i = 0; i < sizeof(filterValues) / sizeof(filterValues[0]); ++i) {
        passed = bme280.configure(
                     SAFE_HUMIDITY_OS,
                     SAFE_TEMPERATURE_OS,
                     SAFE_PRESSURE_OS,
                     BME280::StandbyTime::T_1000_ms,
                     filterValues[i],
                     BME280::Mode::Sleep,
                     false) && passed;
    }

    // This exercises the driver's spi3w_en write branch. It is harmless on
    // the I2C transport and is restored immediately afterwards.
    const bool threeWireBranch = bme280.configure(
        SAFE_HUMIDITY_OS,
        SAFE_TEMPERATURE_OS,
        SAFE_PRESSURE_OS,
        BME280::StandbyTime::T_1000_ms,
        BME280::Filter::Off,
        BME280::Mode::Sleep,
        true);
    const bool restore = configureSafeSleep();
    markCheck(CHECK_CONFIGURATION, passed && threeWireBranch && restore);
}

static void testModesAndWait() {
    bool selectionPassed = true;

    Serial.println("\n    [MODE] Forced mode behavior");
    const bool forcedConfigured = bme280.configure(
        SAFE_HUMIDITY_OS,
        SAFE_TEMPERATURE_OS,
        SAFE_PRESSURE_OS,
        BME280::StandbyTime::T_62p5_ms,
        BME280::Filter::Off,
        BME280::Mode::Sleep,
        false);

    BME280::RawSample forcedBefore = {0, 0, 0};
    const bool forcedBeforeRead = bme280.readRaw(forcedBefore);
    const bool forcedSet = bme280.setMode(BME280::Mode::Forced);
    BME280::Mode mode = BME280::Mode::Sleep;
    const bool forcedModeRead = bme280.getMode(mode) && mode == BME280::Mode::Forced;
    const bool forcedStarted = waitForMeasuringState(true, 50);
    const bool waitResult = forcedStarted && bme280.waitForMeasurement(STATUS_TIMEOUT_MS);
    const bool forcedIdle = waitForMeasuringState(false, 20);
    const bool forcedReturnedToSleep = waitForMode(BME280::Mode::Sleep, 50);

    BME280::RawSample forcedAfter = {0, 0, 0};
    const bool forcedAfterRead = bme280.readRaw(forcedAfter);
    const bool forcedRawValid = forcedAfterRead && rawSampleIsValid(forcedAfter);
    const bool forcedSampleChanged = forcedBeforeRead && forcedAfterRead &&
                                     !rawSamplesEqual(forcedBefore, forcedAfter);

    Serial.print("      measuring asserted: ");
    Serial.println(forcedStarted ? "true" : "false");
    Serial.print("      measuring cleared: ");
    Serial.println(forcedIdle ? "true" : "false");
    Serial.print("      automatic return to Sleep: ");
    Serial.println(forcedReturnedToSleep ? "true" : "false");
    Serial.print("      raw sample valid: ");
    Serial.println(forcedRawValid ? "true" : "false");
    Serial.print("      raw sample changed: ");
    Serial.println(forcedSampleChanged ? "true" : "false (informational)");

    const bool forcedBehaviorPassed = forcedConfigured && forcedSet &&
                                      forcedModeRead && forcedStarted &&
                                      waitResult && forcedIdle &&
                                      forcedReturnedToSleep && forcedRawValid;
    selectionPassed = forcedConfigured && forcedSet && forcedModeRead && selectionPassed;
    markCheck(CHECK_FORCED_MODE_BEHAVIOR, forcedBehaviorPassed);
    markCheck(CHECK_WAIT, waitResult && forcedIdle);

    Serial.println("\n    [MODE] Normal mode behavior");
    BME280::RawSample normalBefore = forcedAfter;
    const bool normalBeforeValid = forcedAfterRead && rawSampleIsValid(normalBefore);
    const bool normalConfigured = bme280.configure(
        SAFE_HUMIDITY_OS,
        SAFE_TEMPERATURE_OS,
        SAFE_PRESSURE_OS,
        BME280::StandbyTime::T_62p5_ms,
        BME280::Filter::Off,
        BME280::Mode::Normal,
        false);
    const bool normalModeRead = bme280.getMode(mode) && mode == BME280::Mode::Normal;

    bool normalStatusReadable = true;
    bool previousMeasuring = false;
    if (!bme280.isMeasuring(previousMeasuring)) {
        normalStatusReadable = false;
    }
    uint8_t normalStarts = previousMeasuring ? 1 : 0;
    uint8_t normalCompletions = 0;
    const uint32_t normalObservationStartedAt = millis();
    while (normalStatusReadable &&
           (uint32_t)(millis() - normalObservationStartedAt) < 300u) {
        bool measuringNow = false;
        if (!bme280.isMeasuring(measuringNow)) {
            normalStatusReadable = false;
            break;
        }
        if (!previousMeasuring && measuringNow) {
            ++normalStarts;
        }
        if (previousMeasuring && !measuringNow) {
            ++normalCompletions;
        }
        previousMeasuring = measuringNow;
        delay(1);
    }

    BME280::RawSample normalAfter = {0, 0, 0};
    const bool normalAfterRead = bme280.readRaw(normalAfter);
    const bool normalRawValid = normalAfterRead && rawSampleIsValid(normalAfter);
    const bool normalSampleChanged = normalBeforeValid && normalAfterRead &&
                                     !rawSamplesEqual(normalBefore, normalAfter);
    const bool normalModeRetained = bme280.getMode(mode) && mode == BME280::Mode::Normal;

    Serial.print("      measurement starts observed: ");
    Serial.println(normalStarts);
    Serial.print("      measurement completions observed: ");
    Serial.println(normalCompletions);
    Serial.print("      mode remained Normal: ");
    Serial.println(normalModeRetained ? "true" : "false");
    Serial.print("      raw sample valid: ");
    Serial.println(normalRawValid ? "true" : "false");
    Serial.print("      raw sample changed: ");
    Serial.println(normalSampleChanged ? "true" : "false (informational)");

    const bool normalBehaviorPassed = normalConfigured && normalModeRead &&
                                      normalStatusReadable && normalStarts >= 2 &&
                                      normalCompletions >= 2 && normalModeRetained &&
                                      normalRawValid;
    selectionPassed = normalConfigured && normalModeRead && selectionPassed;
    markCheck(CHECK_NORMAL_MODE_BEHAVIOR, normalBehaviorPassed);

    Serial.println("\n    [MODE] Sleep mode behavior");
    const bool sleepSet = bme280.setMode(BME280::Mode::Sleep);
    const bool sleepModeReached = waitForMode(BME280::Mode::Sleep, STATUS_TIMEOUT_MS);
    const bool sleepIdle = waitUntilIdle(STATUS_TIMEOUT_MS);

    BME280::RawSample sleepBefore = {0, 0, 0};
    const bool sleepBeforeRead = bme280.readRaw(sleepBefore);
    bool sleepStatusReadable = true;
    bool measuredDuringSleep = false;
    const uint32_t sleepObservationStartedAt = millis();
    while ((uint32_t)(millis() - sleepObservationStartedAt) < 40u) {
        bool measuringNow = false;
        if (!bme280.isMeasuring(measuringNow)) {
            sleepStatusReadable = false;
            break;
        }
        if (measuringNow) {
            measuredDuringSleep = true;
        }
        delay(1);
    }

    BME280::RawSample sleepAfter = {0, 0, 0};
    const bool sleepAfterRead = bme280.readRaw(sleepAfter);
    const bool sleepDataStable = sleepBeforeRead && sleepAfterRead &&
                                 rawSamplesEqual(sleepBefore, sleepAfter);
    const bool sleepModeRead = bme280.getMode(mode) && mode == BME280::Mode::Sleep;

    Serial.print("      measuring remained false: ");
    Serial.println(sleepStatusReadable && !measuredDuringSleep ? "true" : "false");
    Serial.print("      data registers remained stable: ");
    Serial.println(sleepDataStable ? "true" : "false");
    Serial.print("      mode remained Sleep: ");
    Serial.println(sleepModeRead ? "true" : "false");

    const bool sleepBehaviorPassed = sleepSet && sleepModeReached && sleepIdle &&
                                     sleepStatusReadable && !measuredDuringSleep &&
                                     sleepDataStable && sleepModeRead;
    selectionPassed = sleepSet && sleepModeReached && sleepModeRead && selectionPassed;
    markCheck(CHECK_SLEEP_MODE_BEHAVIOR, sleepBehaviorPassed);
    markCheck(CHECK_MODE, selectionPassed);

    const bool restored = configureSafeSleep();
    if (!restored) {
        Serial.println("    [WARN] Could not restore Sleep mode after behavioral checks.");
    }
}

static void testAcquisition() {
    const bool configured = configureSafeSleep();
    const bool reconfigured = bme280.configure(
        SAFE_HUMIDITY_OS,
        SAFE_TEMPERATURE_OS,
        SAFE_PRESSURE_OS,
        BME280::StandbyTime::T_0p5_ms,
        BME280::Filter::Off,
        BME280::Mode::Sleep,
        false);

    const bool triggerResult = bme280.takeForcedMeasurement(0);
    const BME280::Error triggerError = bme280.lastError();
    bool measuringImmediately = false;
    const bool immediateStatusRead = bme280.isMeasuring(measuringImmediately);
    const bool settled = settleAfterMeasurement(
        SAFE_HUMIDITY_OS,
        SAFE_TEMPERATURE_OS,
        SAFE_PRESSURE_OS);

    Serial.print("    takeForcedMeasurement() returned: ");
    Serial.println(triggerResult ? "true" : "false");
    Serial.print("    error after trigger: ");
    Serial.println(errorName(triggerError));
    Serial.print("    measuring immediately after API return: ");
    Serial.println(measuringImmediately ? "true" : "false");
    Serial.print("    conversion settled before read: ");
    Serial.println(settled ? "true" : "false");

    // A successful forced-measurement API should return after the measuring
    // status clears. Keep the additional settle step so raw data can still be
    // evaluated when a board exposes the driver's early-return timing issue.
    const bool forcedPassed = configured && reconfigured && triggerResult &&
                              immediateStatusRead && !measuringImmediately && settled;
    markCheck(CHECK_FORCED_MEASUREMENT, forcedPassed);

    BME280::RawSample raw = {0, 0, 0};
    const bool rawRead = bme280.readRaw(raw);
    if (rawRead) {
        printRawSample(raw);
    } else {
        Serial.print("    readRaw() error: ");
        Serial.println(errorName(bme280.lastError()));
    }
    markCheck(CHECK_RAW_SAMPLE, rawRead && rawSampleIsValid(raw));

    BME280::Measurement sample = {0.0f, 0.0f, 0.0f};
    const bool measurementRead = bme280.readMeasurements(sample);
    if (measurementRead) {
        printMeasurement(sample);
    } else {
        Serial.print("    readMeasurements() error: ");
        Serial.println(errorName(bme280.lastError()));
    }
    markCheck(CHECK_COMPENSATED_SAMPLE, measurementRead && measurementIsValid(sample));

    const bool restored = configureSafeSleep();
    if (!restored) {
        Serial.println("    [WARN] Could not restore the safe Sleep profile after acquisition.");
    }
}

static void testResetAndRecovery() {
    const bool resetResult = bme280.softReset(BEGIN_TIMEOUT_MS);
    const BME280::Error resetError = bme280.lastError();
    Serial.print("    softReset() result: ");
    Serial.print(resetResult ? "true" : "false");
    Serial.print(" (error=");
    Serial.print(errorName(resetError));
    Serial.println(")");

    uint8_t chipId = 0;
    bool updating = true;
    const bool idRead = bme280.readChipId(chipId);
    const bool updateRead = bme280.isUpdating(updating);
    const bool calibrationRead = bme280.readCalibration();
    const bool recovered = bme280.begin(BEGIN_TIMEOUT_MS);

    Serial.print("    chip ID after reset: 0x");
    if (chipId < 0x10) {
        Serial.print('0');
    }
    Serial.println(chipId, HEX);
    Serial.print("    im_update after reset: ");
    Serial.println(updateRead ? (updating ? "true" : "false") : "unreadable");

    markCheck(CHECK_SOFT_RESET,
              resetResult && idRead && chipId == 0x60 && updateRead && !updating &&
                  calibrationRead && recovered);
}

static void testSelfTest() {
    BME280::SelfTestLimits limits = {
        -40.0f,
        85.0f,
        30000.0f,
        110000.0f,
        0.0f,
        100.0f
    };
    const BME280::SelfTestResult result = bme280.selfTest(limits);
    Serial.print("    selfTest() result: ");
    Serial.println(selfTestName(result));
    markCheck(CHECK_SELF_TEST, result == BME280::SelfTestResult::Passed);
}

static void runFullTest() {
    resetChecklist();
    Serial.println();
    Serial.println("========================================");
    Serial.println("BME280 full API test");
    Serial.println("Transport: I2C, address 0x76, SDA GPIO0, SCL GPIO1");
    Serial.println("SPI: skipped because the sensor is not wired to SPI.");
    Serial.println("========================================");
    printChecklistPlan();

    const bool beginResult = bme280.begin(BEGIN_TIMEOUT_MS);
    const BME280::Error beginError = bme280.lastError();
    Serial.print("\n[INFO] begin() result: ");
    Serial.print(beginResult ? "true" : "false");
    Serial.print(" (error=");
    Serial.print(errorName(beginError));
    Serial.println(")");
    markCheck(CHECK_BEGIN, beginResult);
    markCheck(CHECK_LAST_ERROR, beginResult ?
              bme280.lastError() == BME280::Error::Ok :
              bme280.lastError() != BME280::Error::Ok);

    uint8_t chipId = 0;
    const bool chipRead = bme280.readChipId(chipId);
    Serial.print("    chip ID: 0x");
    if (chipId < 0x10) {
        Serial.print('0');
    }
    Serial.println(chipId, HEX);
    markCheck(CHECK_CHIP_ID, chipRead && chipId == 0x60);

    const bool connected = bme280.isConnected();
    markCheck(CHECK_CONNECTION, connected);

    if (!beginResult) {
        deviceReady = false;
        skipCheck(CHECK_CALIBRATION, "begin() did not complete");
        skipCheck(CHECK_STATUS, "begin() did not complete");
        skipCheck(CHECK_MEASUREMENT_TIME, "begin() did not complete");
        skipCheck(CHECK_CONFIGURATION, "begin() did not complete");
        skipCheck(CHECK_MODE, "begin() did not complete");
        skipCheck(CHECK_SLEEP_MODE_BEHAVIOR, "begin() did not complete");
        skipCheck(CHECK_FORCED_MODE_BEHAVIOR, "begin() did not complete");
        skipCheck(CHECK_NORMAL_MODE_BEHAVIOR, "begin() did not complete");
        skipCheck(CHECK_WAIT, "begin() did not complete");
        skipCheck(CHECK_FORCED_MEASUREMENT, "begin() did not complete");
        skipCheck(CHECK_RAW_SAMPLE, "begin() did not complete");
        skipCheck(CHECK_COMPENSATED_SAMPLE, "begin() did not complete");
        skipCheck(CHECK_SOFT_RESET, "begin() did not complete");
        skipCheck(CHECK_SELF_TEST, "begin() did not complete");
        skipCheck(CHECK_SPI_TRANSPORT, "SPI is not wired");
        printChecklistSummary();
        Serial.println("[INFO] Monitor diagnostics will continue while initialization is retried.");
        return;
    }

    deviceReady = true;

    const bool calibration = bme280.readCalibration();
    markCheck(CHECK_CALIBRATION, calibration);

    bool measuring = true;
    bool updating = true;
    const bool measuringRead = bme280.isMeasuring(measuring);
    const bool updatingRead = bme280.isUpdating(updating);
    Serial.print("    measuring: ");
    Serial.println(measuringRead ? (measuring ? "true" : "false") : "unreadable");
    Serial.print("    im_update: ");
    Serial.println(updatingRead ? (updating ? "true" : "false") : "unreadable");
    markCheck(CHECK_STATUS, measuringRead && updatingRead && !updating);

    testMeasurementTime();
    testConfigurationProfiles();
    testModesAndWait();
    testAcquisition();
    testResetAndRecovery();

    // selfTest() performs its own reset. Run it last and leave the sensor in a
    // known usable state for the periodic monitor.
    testSelfTest();
    const bool postSelfTestRecovery = bme280.begin(BEGIN_TIMEOUT_MS) && configureSafeSleep();
    if (!postSelfTestRecovery) {
        Serial.println("[WARN] Could not restore the safe profile after selfTest().");
        deviceReady = false;
    }

    skipCheck(CHECK_SPI_TRANSPORT, "SPI is not wired on this board");
    printChecklistSummary();
    Serial.println("[INFO] Full API test completed; periodic monitoring continues.");
}

static void printMonitorCycle() {
    ++monitorCycle;
    Serial.println();
    Serial.println("========================================");
    Serial.println("BME280 monitor cycle");
    Serial.print("Cycle: ");
    Serial.println(monitorCycle);
    Serial.println("Bus: I2C, SDA GPIO0, SCL GPIO1, address 0x76");
    Serial.print("Device ready: ");
    Serial.println(deviceReady ? "true" : "false");

    const bool triggerResult = bme280.takeForcedMeasurement(0);
    const BME280::Error triggerError = bme280.lastError();
    bool measuringImmediately = false;
    const bool immediateStatusRead = bme280.isMeasuring(measuringImmediately);
    const bool settled = settleAfterMeasurement(
        SAFE_HUMIDITY_OS,
        SAFE_TEMPERATURE_OS,
        SAFE_PRESSURE_OS);

    Serial.print("Forced trigger: ");
    Serial.print(triggerResult ? "OK" : "FAIL");
    Serial.print(" (error=");
    Serial.print(errorName(triggerError));
    Serial.println(")");
    Serial.print("Status immediately after trigger: measuring=");
    Serial.println(immediateStatusRead ? (measuringImmediately ? "true" : "false") : "unreadable");
    Serial.print("Conversion settled: ");
    Serial.println(settled ? "true" : "false");

    BME280::RawSample raw = {0, 0, 0};
    const bool rawRead = bme280.readRaw(raw);
    if (rawRead) {
        printRawSample(raw);
        Serial.print("Skipped: pressure=");
        Serial.print(raw.pressure == 0x80000u ? "true" : "false");
        Serial.print(", temperature=");
        Serial.print(raw.temperature == 0x80000u ? "true" : "false");
        Serial.print(", humidity=");
        Serial.println(raw.humidity == 0x8000u ? "true" : "false");
    } else {
        Serial.print("Raw: unavailable (error=");
        Serial.print(errorName(bme280.lastError()));
        Serial.println(")");
    }

    BME280::Measurement sample = {0.0f, 0.0f, 0.0f};
    const bool measurementRead = bme280.readMeasurements(sample);
    if (measurementRead) {
        printMeasurement(sample);
        Serial.print("Range check: ");
        Serial.println(measurementIsValid(sample) ? "OK" : "OUT_OF_RANGE");
    } else {
        Serial.print("Measurement: unavailable (error=");
        Serial.print(errorName(bme280.lastError()));
        Serial.println(")");
    }

    bool measuring = false;
    bool updating = false;
    const bool measuringRead = bme280.isMeasuring(measuring);
    const bool updatingRead = bme280.isUpdating(updating);
    BME280::Mode mode = BME280::Mode::Sleep;
    const bool modeRead = bme280.getMode(mode);

    Serial.print("Status after read: measuring=");
    Serial.print(measuringRead ? (measuring ? "true" : "false") : "unreadable");
    Serial.print(", im_update=");
    Serial.println(updatingRead ? (updating ? "true" : "false") : "unreadable");
    Serial.print("Mode: ");
    Serial.println(modeRead ? modeName(mode) : "unreadable");
    Serial.println("INT: not applicable; BME280 has no interrupt API or interrupt pin in this setup.");
    Serial.print("lastError(): ");
    Serial.println(errorName(bme280.lastError()));
    Serial.println("========================================");
}

void setup() {
    Serial.begin(115200);
    delay(300);

    Wire.setSDA(I2C_SDA_PIN);
    Wire.setSCL(I2C_SCL_PIN);
    Wire.begin();

    Serial.println();
    Serial.println("BME280 terra_new driver coverage test");
    Serial.println("RP2040 I2C wiring: SDA=GPIO0, SCL=GPIO1, address=0x76");
    Serial.println("SPI is disabled in this test because no SPI wiring is present.");

    runFullTest();
    lastMonitorAt = millis();
    lastFullTestAt = millis();
}

void loop() {
    const uint32_t now = millis();

    if ((uint32_t)(now - lastMonitorAt) >= MONITOR_PERIOD_MS) {
        lastMonitorAt = now;
        printMonitorCycle();
    }

    if ((uint32_t)(now - lastFullTestAt) >= FULL_TEST_PERIOD_MS) {
        lastFullTestAt = now;
        runFullTest();
    }

    delay(5);
}
