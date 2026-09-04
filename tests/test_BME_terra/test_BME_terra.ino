#include <Arduino.h>
#include <Wire.h>
#include <math.h>

#include "BME280.h"

constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 1;
constexpr uint8_t BME280_I2C_ADDRESS = 0x76;
constexpr uint32_t I2C_CLOCK_HZ = 400000UL;

constexpr unsigned long MONITOR_INTERVAL_MS = 1000UL;
constexpr unsigned long FULL_API_TEST_INTERVAL_MS = 15000UL;
constexpr unsigned long BEGIN_RETRY_INTERVAL_MS = 2000UL;
constexpr unsigned long MEASUREMENT_TIMEOUT_MS = 500UL;

BME280 sensor(Wire, BME280_I2C_ADDRESS);

bool deviceReady = false;
bool lastBeginOk = false;
unsigned long lastMonitorMs = 0;
unsigned long lastFullApiTestMs = 0;
unsigned long lastBeginAttemptMs = 0;

uint16_t passCount = 0;
uint16_t failCount = 0;
uint16_t skipCount = 0;

enum class SkippedField : uint8_t {
  Temperature,
  Pressure,
  Humidity,
};

void printDriverError();

const char *errorName(Error error) {
  switch (error) {
    case Error::Ok:
      return "Ok";
    case Error::Transport:
      return "Transport";
    case Error::ChipIdMismatch:
      return "ChipIdMismatch";
    case Error::Timeout:
      return "Timeout";
    case Error::Calibration:
      return "Calibration";
    case Error::SkippedData:
      return "SkippedData";
    case Error::InvalidState:
      return "InvalidState";
    default:
      return "Unknown";
  }
}

const char *modeName(Mode mode) {
  switch (mode) {
    case Mode::Sleep:
      return "Sleep";
    case Mode::Forced1:
      return "Forced1";
    case Mode::Forced2:
      return "Forced2";
    case Mode::Normal:
      return "Normal";
    default:
      return "Unknown";
  }
}

void printBoolean(bool value) {
  Serial.print(value ? "true" : "false");
}

void printHex8(uint8_t value) {
  if (value < 0x10) {
    Serial.print('0');
  }
  Serial.print(static_cast<unsigned int>(value), HEX);
}

void printHex20(uint32_t value) {
  Serial.print(static_cast<unsigned long>(value), HEX);
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

void printDriverError() {
  Serial.print("  Driver error: ");
  Serial.println(errorName(sensor.lastError()));
}

void printRawData(const RawData &raw) {
  Serial.print("  Raw pressure: 0x");
  printHex20(raw.pressure);
  Serial.print("; raw temperature: 0x");
  printHex20(raw.temperature);
  Serial.print("; raw humidity: 0x");
  printHex8(static_cast<uint8_t>(raw.humidity >> 8));
  printHex8(static_cast<uint8_t>(raw.humidity & 0xFF));
  Serial.println();
}

void printSample(const Sample &sample) {
  Serial.print("  Temperature: ");
  Serial.print(sample.temperature_c, 2);
  Serial.println(" deg C");
  Serial.print("  Pressure: ");
  Serial.print(sample.pressure_pa, 2);
  Serial.println(" Pa");
  Serial.print("  Humidity: ");
  Serial.print(sample.humidity_rh, 2);
  Serial.println(" %RH");
}

bool sampleIsValid(const Sample &sample) {
  return isfinite(sample.temperature_c) &&
         isfinite(sample.pressure_pa) &&
         isfinite(sample.humidity_rh) &&
         sample.temperature_c >= -40.0f && sample.temperature_c <= 85.0f &&
         sample.pressure_pa >= 30000.0f && sample.pressure_pa <= 110000.0f &&
         sample.humidity_rh >= 0.0f && sample.humidity_rh <= 100.0f;
}

bool rawFieldsAreValid(const RawData &raw) {
  return raw.pressure <= 0xFFFFFu &&
         raw.temperature <= 0xFFFFFu &&
         raw.humidity <= 0xFFFFu;
}

bool approximatelyEqual(float first, float second, float tolerance) {
  return fabsf(first - second) <= tolerance;
}

bool waitUntilIdle(unsigned long timeoutMs) {
  const unsigned long start = millis();
  while (millis() - start <= timeoutMs) {
    bool measuring = false;
    if (!sensor.isMeasuring(measuring)) {
      return false;
    }
    if (!measuring) {
      return true;
    }
    delay(2);
  }
  return false;
}

bool configureProfile(const Configuration &configuration, const char *label) {
  const bool configureOk = sensor.configure(configuration);
  reportResult(label, configureOk);
  if (!configureOk) {
    printDriverError();
    return false;
  }

  Mode observedMode = Mode::Sleep;
  const bool modeReadOk = sensor.readMode(observedMode);
  const bool modeOk = modeReadOk && observedMode == Mode::Sleep;
  reportResult("readMode() confirms sleep after configure()", modeOk);
  if (!modeOk && !modeReadOk) {
    printDriverError();
  }
  return configureOk && modeOk;
}

Configuration safeConfiguration() {
  Configuration configuration;
  configuration.osrs_t = Oversampling::X1;
  configuration.osrs_p = Oversampling::X1;
  configuration.osrs_h = Oversampling::X1;
  configuration.t_sb = Standby::Ms0_5;
  configuration.filter = Filter::Off;
  configuration.spi3w_en = false;
  return configuration;
}

bool testIdentificationAndStatus() {
  Serial.println();
  Serial.println("[TEST] Identification, mode, and status");
  bool allPassed = true;

  uint8_t chipId = 0;
  const bool chipIdReadOk = sensor.readChipId(chipId);
  const bool chipIdOk = chipIdReadOk && chipId == 0x60;
  reportResult("readChipId() returns 0x60", chipIdOk);
  if (!chipIdReadOk) {
    printDriverError();
  } else {
    Serial.print("  Chip ID: 0x");
    printHex8(chipId);
    Serial.println();
  }
  allPassed = allPassed && chipIdOk;

  Mode mode = Mode::Normal;
  const bool modeReadOk = sensor.readMode(mode);
  const bool initialModeOk = modeReadOk && mode == Mode::Sleep;
  reportResult("readMode() returns Sleep after begin()", initialModeOk);
  if (!modeReadOk) {
    printDriverError();
  } else {
    Serial.print("  Current mode: ");
    Serial.println(modeName(mode));
  }
  allPassed = allPassed && initialModeOk;

  delay(2);
  bool measuring = true;
  const bool measuringReadOk = sensor.isMeasuring(measuring);
  const bool idleOk = measuringReadOk && !measuring;
  reportResult("isMeasuring() reports idle", idleOk);
  if (!measuringReadOk) {
    printDriverError();
  }
  allPassed = allPassed && idleOk;

  bool updating = true;
  const bool updatingReadOk = sensor.isUpdating(updating);
  const bool updateIdleOk = updatingReadOk && !updating;
  reportResult("isUpdating() reports calibration idle", updateIdleOk);
  if (!updatingReadOk) {
    printDriverError();
  }
  allPassed = allPassed && updateIdleOk;

  RawData raw{};
  const bool rawReadOk = sensor.readRaw(raw);
  const bool rawOk = rawReadOk && rawFieldsAreValid(raw) &&
                     raw.temperature != 0x80000u &&
                     raw.pressure != 0x80000u &&
                     raw.humidity != 0x8000u;
  reportResult("readRaw() returns valid ADC fields", rawOk);
  if (!rawReadOk) {
    printDriverError();
  } else {
    printRawData(raw);
  }
  allPassed = allPassed && rawOk;

  return allPassed;
}

bool testResetAndReinitialization() {
  Serial.println();
  Serial.println("[TEST] Soft reset and reinitialization");
  bool allPassed = true;

  const bool resetOk = sensor.reset(20);
  reportResult("reset(20 ms)", resetOk);
  if (!resetOk) {
    printDriverError();
  }
  allPassed = allPassed && resetOk;

  uint8_t chipId = 0;
  const bool chipIdReadOk = sensor.readChipId(chipId);
  const bool chipIdOk = chipIdReadOk && chipId == 0x60;
  reportResult("readChipId() succeeds after reset", chipIdOk);
  if (!chipIdReadOk) {
    printDriverError();
  }
  allPassed = allPassed && chipIdOk;

  const bool beginOk = sensor.begin();
  reportResult("begin() restores calibration and defaults after reset", beginOk);
  if (!beginOk) {
    printDriverError();
  }
  allPassed = allPassed && beginOk;

  const bool errorOk = beginOk && sensor.lastError() == Error::Ok;
  reportResult("lastError() is Ok after reinitialization", errorOk);
  allPassed = allPassed && errorOk;

  return allPassed;
}

bool testModeTransitions() {
  Serial.println();
  Serial.println("[TEST] Sensor mode transitions");
  bool allPassed = true;

  const bool setNormalOk = sensor.setMode(Mode::Normal);
  reportResult("setMode(Normal)", setNormalOk);
  if (!setNormalOk) {
    printDriverError();
  }
  allPassed = allPassed && setNormalOk;

  Mode observedMode = Mode::Sleep;
  const bool readNormalOk = sensor.readMode(observedMode);
  const bool normalModeOk = readNormalOk && observedMode == Mode::Normal;
  reportResult("readMode() confirms Normal", normalModeOk);
  if (!readNormalOk) {
    printDriverError();
  }
  allPassed = allPassed && normalModeOk;

  bool measuring = false;
  const bool measuringReadOk = sensor.isMeasuring(measuring);
  reportResult("isMeasuring() is readable in Normal mode", measuringReadOk);
  if (!measuringReadOk) {
    printDriverError();
  } else {
    Serial.print("  Normal-mode measuring flag: ");
    printBoolean(measuring);
    Serial.println();
  }
  allPassed = allPassed && measuringReadOk;

  bool updating = false;
  const bool updatingReadOk = sensor.isUpdating(updating);
  reportResult("isUpdating() is readable in Normal mode", updatingReadOk);
  if (!updatingReadOk) {
    printDriverError();
  }
  allPassed = allPassed && updatingReadOk;

  const bool setSleepOk = sensor.setMode(Mode::Sleep);
  reportResult("setMode(Sleep)", setSleepOk);
  if (!setSleepOk) {
    printDriverError();
  }
  allPassed = allPassed && setSleepOk;

  const bool sleepIdleOk = waitUntilIdle(MEASUREMENT_TIMEOUT_MS);
  reportResult("Normal mode stops after setMode(Sleep)", sleepIdleOk);
  allPassed = allPassed && sleepIdleOk;

  observedMode = Mode::Normal;
  const bool readSleepOk = sensor.readMode(observedMode);
  const bool sleepModeOk = readSleepOk && observedMode == Mode::Sleep;
  reportResult("readMode() confirms Sleep", sleepModeOk);
  if (!readSleepOk) {
    printDriverError();
  }
  allPassed = allPassed && sleepModeOk;

  const bool setForced1Ok = sensor.setMode(Mode::Forced1);
  reportResult("setMode(Forced1)", setForced1Ok);
  if (!setForced1Ok) {
    printDriverError();
  }
  allPassed = allPassed && setForced1Ok;

  const bool forced1IdleOk = waitUntilIdle(MEASUREMENT_TIMEOUT_MS);
  reportResult("Forced1 measurement completes", forced1IdleOk);
  allPassed = allPassed && forced1IdleOk;

  const bool setForced2Ok = sensor.setMode(Mode::Forced2);
  reportResult("setMode(Forced2)", setForced2Ok);
  if (!setForced2Ok) {
    printDriverError();
  }
  allPassed = allPassed && setForced2Ok;

  const bool forced2IdleOk = waitUntilIdle(MEASUREMENT_TIMEOUT_MS);
  reportResult("Forced2 measurement completes", forced2IdleOk);
  allPassed = allPassed && forced2IdleOk;

  observedMode = Mode::Normal;
  const bool readFinalModeOk = sensor.readMode(observedMode);
  const bool finalSleepOk = readFinalModeOk && observedMode == Mode::Sleep;
  reportResult("Forced modes return to Sleep", finalSleepOk);
  if (!readFinalModeOk) {
    printDriverError();
  }
  allPassed = allPassed && finalSleepOk;

  return allPassed;
}

bool testConfigurationProfiles() {
  Serial.println();
  Serial.println("[TEST] Configuration enum coverage");
  bool allPassed = true;

  const Configuration profiles[] = {
      {Oversampling::X1, Oversampling::X1, Oversampling::X1,
       Standby::Ms0_5, Filter::Off, false},
      {Oversampling::X2, Oversampling::X4, Oversampling::X8,
       Standby::Ms62_5, Filter::C2, false},
      {Oversampling::X4, Oversampling::X8, Oversampling::X16,
       Standby::Ms125, Filter::C4, false},
      {Oversampling::X8, Oversampling::X16, Oversampling::X2,
       Standby::Ms250, Filter::C8, false},
      {Oversampling::X16, Oversampling::X2, Oversampling::X4,
       Standby::Ms500, Filter::C16, false},
      {Oversampling::X2, Oversampling::X8, Oversampling::X1,
       Standby::Ms1000, Filter::Off, false},
      {Oversampling::X4, Oversampling::X1, Oversampling::X2,
       Standby::Ms10, Filter::C2, false},
      {Oversampling::X8, Oversampling::X2, Oversampling::X4,
       Standby::Ms20, Filter::C4, true},
  };

  const char *labels[] = {
      "configure(): X1/X1/X1, 0.5 ms, filter Off",
      "configure(): X2/X4/X8, 62.5 ms, filter C2",
      "configure(): X4/X8/X16, 125 ms, filter C4",
      "configure(): X8/X16/X2, 250 ms, filter C8",
      "configure(): X16/X2/X4, 500 ms, filter C16",
      "configure(): X2/X8/X1, 1000 ms, filter Off",
      "configure(): X4/X1/X2, 10 ms, filter C2",
      "configure(): X8/X2/X4, 20 ms, filter C4, spi3w_en true",
  };

  for (size_t i = 0; i < sizeof(profiles) / sizeof(profiles[0]); ++i) {
    const bool profileOk = configureProfile(profiles[i], labels[i]);
    allPassed = allPassed && profileOk;
    if (profiles[i].spi3w_en) {
      reportInfo("spi3w_en is written through I2C; 3-wire SPI transport is not connected.");
    }
  }

  const bool restoreOk = configureProfile(
      safeConfiguration(), "restore safe X1/X1/X1 I2C configuration");
  allPassed = allPassed && restoreOk;
  return allPassed;
}

bool testAcquisitionAndCompensation() {
  Serial.println();
  Serial.println("[TEST] Forced acquisition, raw data, and compensation");
  bool allPassed = true;

  const bool safeConfigOk = configureProfile(
      safeConfiguration(), "configure() safe acquisition profile");
  allPassed = allPassed && safeConfigOk;

  Sample forcedSample{};
  const bool forcedOk = sensor.takeForcedMeasurement(forcedSample, 0);
  reportResult("takeForcedMeasurement() with computed timeout", forcedOk);
  if (!forcedOk) {
    printDriverError();
  } else {
    printSample(forcedSample);
  }
  allPassed = allPassed && forcedOk;

  const bool forcedSampleOk = forcedOk && sampleIsValid(forcedSample);
  reportResult("forced sample is finite and within datasheet ranges", forcedSampleOk);
  allPassed = allPassed && forcedSampleOk;

  RawData raw{};
  const bool rawReadOk = sensor.readRaw(raw);
  const bool rawOk = rawReadOk && rawFieldsAreValid(raw) &&
                     raw.temperature != 0x80000u &&
                     raw.pressure != 0x80000u &&
                     raw.humidity != 0x8000u;
  reportResult("readRaw() returns the latest valid measurement", rawOk);
  if (!rawReadOk) {
    printDriverError();
  } else {
    printRawData(raw);
  }
  allPassed = allPassed && rawOk;

  Sample readSampleValue{};
  const bool readSampleOk = sensor.readSample(readSampleValue);
  reportResult("readSample() succeeds without changing mode", readSampleOk);
  if (!readSampleOk) {
    printDriverError();
  } else {
    printSample(readSampleValue);
  }
  allPassed = allPassed && readSampleOk;

  const bool readSampleValueOk = readSampleOk && sampleIsValid(readSampleValue);
  reportResult("readSample() returns finite compensated values", readSampleValueOk);
  allPassed = allPassed && readSampleValueOk;

  const bool temperatureConsistency =
      forcedOk && readSampleOk &&
      approximatelyEqual(forcedSample.temperature_c,
                         readSampleValue.temperature_c, 0.05f);
  const bool pressureConsistency =
      forcedOk && readSampleOk &&
      approximatelyEqual(forcedSample.pressure_pa,
                         readSampleValue.pressure_pa, 2.0f);
  const bool humidityConsistency =
      forcedOk && readSampleOk &&
      approximatelyEqual(forcedSample.humidity_rh,
                         readSampleValue.humidity_rh, 0.2f);
  reportResult("readSample() matches the forced temperature", temperatureConsistency);
  reportResult("readSample() matches the forced pressure", pressureConsistency);
  reportResult("readSample() matches the forced humidity", humidityConsistency);
  allPassed = allPassed && temperatureConsistency && pressureConsistency &&
              humidityConsistency;

  const bool errorOk = sensor.lastError() == Error::Ok;
  reportResult("lastError() is Ok after valid acquisition", errorOk);
  allPassed = allPassed && errorOk;

  Configuration explicitTimeoutConfiguration = safeConfiguration();
  explicitTimeoutConfiguration.osrs_t = Oversampling::X2;
  explicitTimeoutConfiguration.osrs_p = Oversampling::X4;
  explicitTimeoutConfiguration.osrs_h = Oversampling::X2;
  explicitTimeoutConfiguration.filter = Filter::C2;
  const bool explicitConfigOk = configureProfile(
      explicitTimeoutConfiguration,
      "configure() profile for explicit timeout measurement");
  allPassed = allPassed && explicitConfigOk;

  Sample explicitTimeoutSample{};
  const bool explicitTimeoutOk =
      sensor.takeForcedMeasurement(explicitTimeoutSample,
                                   static_cast<uint16_t>(MEASUREMENT_TIMEOUT_MS));
  reportResult("takeForcedMeasurement() with explicit timeout", explicitTimeoutOk);
  if (!explicitTimeoutOk) {
    printDriverError();
  }
  allPassed = allPassed && explicitTimeoutOk;

  const bool explicitSampleOk = explicitTimeoutOk &&
                                sampleIsValid(explicitTimeoutSample);
  reportResult("explicit-timeout sample is valid", explicitSampleOk);
  allPassed = allPassed && explicitSampleOk;

  const bool restoreOk = configureProfile(
      safeConfiguration(), "restore safe configuration after acquisition");
  allPassed = allPassed && restoreOk;
  return allPassed;
}

bool testSkippedField(SkippedField field, const char *label) {
  Configuration configuration = safeConfiguration();
  if (field == SkippedField::Temperature) {
    configuration.osrs_t = Oversampling::Skipped;
  } else if (field == SkippedField::Pressure) {
    configuration.osrs_p = Oversampling::Skipped;
  } else {
    configuration.osrs_h = Oversampling::Skipped;
  }

  Serial.println();
  Serial.print("[TEST] ");
  Serial.println(label);

  bool allPassed = configureProfile(configuration, "configure() with one skipped channel");

  Sample sample{};
  const bool measurementOk = sensor.takeForcedMeasurement(sample, 0);
  reportExpectedFalse("takeForcedMeasurement() rejects skipped ADC output", measurementOk);
  if (measurementOk) {
    printSample(sample);
  }
  const bool skippedErrorOk = !measurementOk && sensor.lastError() == Error::SkippedData;
  reportResult("lastError() reports SkippedData", skippedErrorOk);
  allPassed = allPassed && !measurementOk && skippedErrorOk;

  RawData raw{};
  const bool rawReadOk = sensor.readRaw(raw);
  bool sentinelOk = false;
  if (field == SkippedField::Temperature) {
    sentinelOk = raw.temperature == 0x80000u;
  } else if (field == SkippedField::Pressure) {
    sentinelOk = raw.pressure == 0x80000u;
  } else {
    sentinelOk = raw.humidity == 0x8000u;
  }
  reportResult("readRaw() exposes the documented skipped-data sentinel",
               rawReadOk && sentinelOk);
  if (!rawReadOk) {
    printDriverError();
  } else {
    printRawData(raw);
  }
  allPassed = allPassed && rawReadOk && sentinelOk;

  const bool restoreOk = configureProfile(
      safeConfiguration(), "restore safe configuration after skipped channel");
  return allPassed && restoreOk;
}

bool testSkippedMeasurements() {
  Serial.println();
  Serial.println("[TEST] Independent channel disable coverage");
  bool allPassed = true;

  allPassed = testSkippedField(
                  SkippedField::Temperature, "Temperature oversampling skipped") &&
              allPassed;
  allPassed = testSkippedField(
                  SkippedField::Pressure, "Pressure oversampling skipped") &&
              allPassed;
  allPassed = testSkippedField(
                  SkippedField::Humidity, "Humidity oversampling skipped") &&
              allPassed;
  return allPassed;
}

void printTestSummary() {
  Serial.println();
  Serial.println("========================================");
  Serial.print("API test summary: PASS=");
  Serial.print(passCount);
  Serial.print(" FAIL=");
  Serial.print(failCount);
  Serial.print(" SKIP=");
  Serial.println(skipCount);
  Serial.println("========================================");
}

void printChecklistPlan() {
  Serial.println();
  Serial.println("[CHECKLIST] Planned checks for this cycle");
  Serial.println("  1. begin() initialization and lastError()");
  Serial.println("  2. readChipId() and chip ID validation");
  Serial.println("  3. readMode(), isMeasuring(), and isUpdating()");
  Serial.println("  4. readRaw() and ADC field validation");
  Serial.println("  5. reset() and begin() recovery");
  Serial.println("  6. setMode(): Sleep, Forced1, Forced2, and Normal");
  Serial.println("  7. configure(): oversampling, standby, filter, and spi3w_en");
  Serial.println("  8. takeForcedMeasurement() with computed timeout");
  Serial.println("  9. readSample() and compensated output validation");
  Serial.println(" 10. takeForcedMeasurement() with explicit timeout");
  Serial.println(" 11. Independent skipped-channel sentinel checks");
  Serial.println(" 12. Safe configuration restore");
  Serial.println(" 13. SPI transport: skipped because SPI is not connected");
}

void reportSkippedApiChecks() {
  const char *skippedChecks[] = {
      "readChipId(), readMode(), and status checks",
      "readRaw() ADC field validation",
      "reset() and begin() recovery",
      "setMode() transitions",
      "configure() enum and spi3w_en profiles",
      "takeForcedMeasurement() with computed timeout",
      "readSample() and compensation checks",
      "takeForcedMeasurement() with explicit timeout",
      "independent skipped-channel sentinel checks",
      "safe configuration restore",
      "SPI transport and SPI initialization"
  };

  for (size_t i = 0; i < sizeof(skippedChecks) / sizeof(skippedChecks[0]); ++i) {
    reportSkip(skippedChecks[i]);
  }
}

bool runFullApiTest() {
  passCount = 0;
  failCount = 0;
  skipCount = 0;

  Serial.println();
  Serial.println("========================================");
  Serial.println("BME280 full I2C driver coverage test");
  Serial.println("========================================");

  printChecklistPlan();

  lastBeginOk = sensor.begin();
  reportResult("begin()", lastBeginOk);
  if (!lastBeginOk) {
    printDriverError();
    reportSkippedApiChecks();
    printTestSummary();
    return false;
  }
  reportResult("lastError() is Ok after begin()", sensor.lastError() == Error::Ok);

  bool allPassed = true;
  allPassed = testIdentificationAndStatus() && allPassed;
  allPassed = testResetAndReinitialization() && allPassed;
  allPassed = testModeTransitions() && allPassed;
  allPassed = testConfigurationProfiles() && allPassed;
  allPassed = testAcquisitionAndCompensation() && allPassed;
  allPassed = testSkippedMeasurements() && allPassed;

  const bool finalRestoreOk = configureProfile(
      safeConfiguration(), "final restore of safe configuration");
  allPassed = finalRestoreOk && allPassed;

  reportInfo("I2C is tested on GPIO0 SDA and GPIO1 SCL at address 0x76.");
  reportInfo("SPI transport is intentionally not executed because the sensor is not wired to SPI.");
  reportInfo("The test is intended for live hardware; range checks use the datasheet operating limits.");
  printTestSummary();
  return allPassed;
}

void runMonitorCycle() {
  Serial.println();
  Serial.println("--- BME280 monitor cycle ---");
  Serial.print("Uptime: ");
  Serial.print(millis() / 1000UL);
  Serial.println(" s");
  Serial.print("Device ready: ");
  printBoolean(deviceReady);
  Serial.println();

  Sample freshSample{};
  const bool freshMeasurementOk = sensor.takeForcedMeasurement(freshSample, 0);
  const Error freshMeasurementError = sensor.lastError();
  if (freshMeasurementOk) {
    Serial.println("Fresh forced measurement: OK");
    printSample(freshSample);
    Serial.print("Fresh sample range check: ");
    Serial.println(sampleIsValid(freshSample) ? "VALID" : "OUT_OF_RANGE");
  } else {
    Serial.println("Fresh forced measurement: READ_ERROR");
    Serial.print("  Driver error: ");
    Serial.println(errorName(freshMeasurementError));
  }

  Mode mode = Mode::Sleep;
  const bool modeOk = sensor.readMode(mode);
  if (modeOk) {
    Serial.print("Mode: ");
    Serial.println(modeName(mode));
  } else {
    Serial.println("Mode: READ_ERROR");
    printDriverError();
  }

  bool measuring = false;
  if (sensor.isMeasuring(measuring)) {
    Serial.print("Measuring: ");
    printBoolean(measuring);
    Serial.println();
  } else {
    Serial.println("Measuring: READ_ERROR");
    printDriverError();
  }

  bool updating = false;
  if (sensor.isUpdating(updating)) {
    Serial.print("Calibration update: ");
    printBoolean(updating);
    Serial.println();
  } else {
    Serial.println("Calibration update: READ_ERROR");
    printDriverError();
  }

  RawData raw{};
  if (sensor.readRaw(raw)) {
    printRawData(raw);
  } else {
    Serial.println("Raw data: READ_ERROR");
    printDriverError();
  }

  Sample sample{};
  if (sensor.readSample(sample)) {
    Serial.println("Latest cached sample: OK");
    printSample(sample);
    Serial.print("Sample range check: ");
    Serial.println(sampleIsValid(sample) ? "VALID" : "OUT_OF_RANGE");
  } else {
    Serial.println("Compensated sample: READ_ERROR");
    printDriverError();
  }

  Serial.println("INT: not applicable; BME280 exposes no interrupt API or interrupt pin.");
  Serial.println("--- End monitor cycle ---");
  Serial.println();
}

void attemptBegin() {
  lastBeginAttemptMs = millis();
  Serial.println();
  Serial.println("[INFO] Attempting BME280 initialization...");
  deviceReady = sensor.begin();
  lastBeginOk = deviceReady;
  if (deviceReady) {
    Serial.println("[INFO] BME280 is ready.");
  } else {
    Serial.println("[INFO] BME280 initialization failed.");
    printDriverError();
    passCount = 0;
    failCount = 0;
    skipCount = 0;
    printChecklistPlan();
    reportResult("begin()", false);
    reportSkippedApiChecks();
    printTestSummary();
    Serial.println("[INFO] Monitor diagnostics will continue while initialization is retried.");
  }
}

void setup() {
  Serial.begin(115200);
  const unsigned long serialStart = millis();
  while (!Serial && millis() - serialStart < 3000UL) {
    delay(10);
  }

  Wire.setSDA(I2C_SDA_PIN);
  Wire.setSCL(I2C_SCL_PIN);
  Wire.begin();
  Wire.setClock(I2C_CLOCK_HZ);

  Serial.println();
  Serial.println("BME280 RP2040 I2C driver coverage test");
  Serial.println("Board wiring: GPIO0=SDA, GPIO1=SCL, SPI not connected");
  Serial.print("I2C address: 0x");
  printHex8(BME280_I2C_ADDRESS);
  Serial.print("; I2C clock: ");
  Serial.print(I2C_CLOCK_HZ);
  Serial.println(" Hz");

  attemptBegin();
  lastMonitorMs = millis();
  if (deviceReady) {
    const bool initialFullTestPassed = runFullApiTest();
    if (!lastBeginOk) {
      deviceReady = false;
    }
    if (!initialFullTestPassed) {
      reportInfo("At least one API check failed; monitoring continues for diagnosis.");
    }
    lastFullApiTestMs = millis();
  }
}

void loop() {
  const unsigned long now = millis();

  if (now - lastMonitorMs >= MONITOR_INTERVAL_MS) {
    lastMonitorMs = now;
    runMonitorCycle();
  }

  if (!deviceReady) {
    if (now - lastBeginAttemptMs >= BEGIN_RETRY_INTERVAL_MS) {
      attemptBegin();
      if (deviceReady) {
        runFullApiTest();
        if (!lastBeginOk) {
          deviceReady = false;
        }
        lastFullApiTestMs = millis();
      }
    }
    delay(100);
    return;
  }

  if (now - lastFullApiTestMs >= FULL_API_TEST_INTERVAL_MS) {
    const bool fullTestPassed = runFullApiTest();
    if (!lastBeginOk) {
      deviceReady = false;
    }
    if (!fullTestPassed) {
      reportInfo("Full API cycle reported failures; monitor output remains active.");
    }
    lastFullApiTestMs = millis();
  }

}
