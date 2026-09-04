#include <Arduino.h>
#include <Wire.h>
#include <math.h>

#include "BME280.h"

static const uint8_t I2C_SDA_PIN = 0;
static const uint8_t I2C_SCL_PIN = 1;
static const uint8_t BME280_I2C_ADDRESS = 0x76;
static const uint32_t MONITOR_INTERVAL_MS = 1000;
static const uint32_t FULL_TEST_INTERVAL_MS = 15000;
static const uint32_t MEASUREMENT_TIMEOUT_MS = 2500;

static const uint32_t RAW_20BIT_SENTINEL = 0x80000u;
static const uint16_t RAW_16BIT_SENTINEL = 0x8000u;

enum CheckId : uint8_t {
  CHECK_I2C_INITIALIZATION,
  CHECK_CHIP_ID,
  CHECK_CALIBRATION,
  CHECK_IM_UPDATE_STATUS,
  CHECK_MEASURING_STATUS,
  CHECK_HUMIDITY_OVERSAMPLING,
  CHECK_TEMPERATURE_PRESSURE_OVERSAMPLING,
  CHECK_MEASUREMENT_MODES,
  CHECK_FILTER_AND_STANDBY,
  CHECK_SPI3W_CONFIGURATION,
  CHECK_FORCED_MEASUREMENT,
  CHECK_RAW_DATA,
  CHECK_TEMPERATURE_OUTPUT,
  CHECK_PRESSURE_OUTPUT,
  CHECK_HUMIDITY_OUTPUT,
  CHECK_MEASURED_DATA_FLAGS,
  CHECK_SKIPPED_SENTINELS,
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

static const char* const CHECK_NAMES[CHECK_COUNT] = {
  "I2C initialization on GPIO0/GPIO1",
  "Chip ID read",
  "Calibration read and public getter",
  "im_update status",
  "measuring status at idle",
  "Humidity oversampling values",
  "Temperature and pressure oversampling values",
  "Sleep, forced and normal modes",
  "Filter coefficients and standby values",
  "spi3w_en configuration branch",
  "Forced measurement and burst read",
  "Raw data getter and field ranges",
  "Temperature compensation output",
  "Pressure compensation output",
  "Humidity compensation output",
  "Normal-measurement raw flags",
  "Skipped-measurement sentinel flags",
  "Soft reset and post-reset recovery",
  "Driver self-test",
  "SPI transport and SPI initialization overloads"
};

static BME280 sensor;
static CheckState checkStates[CHECK_COUNT];
static bool sensorInitialized = false;
static uint32_t lastMonitorMs = 0;
static uint32_t lastFullTestMs = 0;
static uint32_t monitorCycle = 0;

static void resetChecklist() {
  for (size_t i = 0; i < CHECK_COUNT; ++i) {
    checkStates[i] = CHECK_NOT_RUN;
  }
}

static void markCheck(CheckId id, bool passed) {
  checkStates[id] = passed ? CHECK_PASS : CHECK_FAIL;
}

static void skipCheck(CheckId id) {
  checkStates[id] = CHECK_SKIP;
}

static const char* stateText(CheckState state) {
  switch (state) {
    case CHECK_PASS: return "PASS";
    case CHECK_FAIL: return "FAIL";
    case CHECK_SKIP: return "SKIP";
    default: return "NOT RUN";
  }
}

static bool isFiniteValue(float value) {
  return !isnan(value) && !isinf(value);
}

static bool waitForMeasurementComplete(uint32_t timeoutMs) {
  const uint32_t startMs = millis();
  while (sensor.isMeasuring()) {
    if ((millis() - startMs) > timeoutMs) {
      return false;
    }
    delay(2);
  }
  return true;
}

static bool configureForcedMeasurement() {
  bool ok = true;
  ok = sensor.setHumidityOversampling(BME280Driver::OSRS_X1) && ok;
  ok = sensor.setTempPressureOversamplingAndMode(
         BME280Driver::OSRS_X1,
         BME280Driver::OSRS_X1,
         BME280Driver::MODE_FORCED) && ok;
  ok = waitForMeasurementComplete(MEASUREMENT_TIMEOUT_MS) && ok;
  return ok;
}

static bool triggerAndReadMeasurement() {
  bool ok = configureForcedMeasurement();
  ok = sensor.readSensor() && ok;
  return ok;
}

static bool testHumidityOversamplingValues() {
  const uint8_t values[] = {
    BME280Driver::OSRS_SKIP,
    BME280Driver::OSRS_X1,
    BME280Driver::OSRS_X2,
    BME280Driver::OSRS_X4,
    BME280Driver::OSRS_X8,
    BME280Driver::OSRS_X16
  };
  bool ok = true;
  for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
    ok = sensor.setHumidityOversampling(values[i]) && ok;
    ok = sensor.setTempPressureOversamplingAndMode(
           BME280Driver::OSRS_X1,
           BME280Driver::OSRS_X1,
           BME280Driver::MODE_SLEEP) && ok;
  }
  return ok;
}

static bool testTemperaturePressureOversamplingValues() {
  const uint8_t values[] = {
    BME280Driver::OSRS_SKIP,
    BME280Driver::OSRS_X1,
    BME280Driver::OSRS_X2,
    BME280Driver::OSRS_X4,
    BME280Driver::OSRS_X8,
    BME280Driver::OSRS_X16
  };
  bool ok = sensor.setHumidityOversampling(BME280Driver::OSRS_X1);
  for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
    ok = sensor.setTempPressureOversamplingAndMode(
           values[i],
           values[i],
           BME280Driver::MODE_SLEEP) && ok;
  }
  return ok;
}

static bool testMeasurementModes() {
  bool ok = true;
  ok = sensor.setHumidityOversampling(BME280Driver::OSRS_X1) && ok;
  ok = sensor.setTempPressureOversamplingAndMode(
         BME280Driver::OSRS_X1,
         BME280Driver::OSRS_X1,
         BME280Driver::MODE_SLEEP) && ok;
  ok = sensor.setTempPressureOversamplingAndMode(
         BME280Driver::OSRS_X2,
         BME280Driver::OSRS_X4,
         BME280Driver::MODE_FORCED) && ok;
  ok = waitForMeasurementComplete(MEASUREMENT_TIMEOUT_MS) && ok;
  ok = sensor.setTempPressureOversamplingAndMode(
         BME280Driver::OSRS_X1,
         BME280Driver::OSRS_X1,
         BME280Driver::MODE_NORMAL) && ok;
  delay(25);
  ok = sensor.setTempPressureOversamplingAndMode(
         BME280Driver::OSRS_X1,
         BME280Driver::OSRS_X1,
         BME280Driver::MODE_SLEEP) && ok;
  return ok;
}

static bool testFilterAndStandbyValues(bool& spi3wBranchOk) {
  const uint8_t filterValues[] = {
    BME280Driver::FILTER_OFF,
    BME280Driver::FILTER_2,
    BME280Driver::FILTER_4,
    BME280Driver::FILTER_8,
    BME280Driver::FILTER_16
  };
  const uint8_t standbyValues[] = {
    BME280Driver::TSB_0_5_MS,
    BME280Driver::TSB_62_5_MS,
    BME280Driver::TSB_125_MS,
    BME280Driver::TSB_250_MS,
    BME280Driver::TSB_500_MS,
    BME280Driver::TSB_1000_MS,
    BME280Driver::TSB_10_MS,
    BME280Driver::TSB_20_MS
  };
  bool ok = true;
  for (size_t i = 0; i < sizeof(filterValues) / sizeof(filterValues[0]); ++i) {
    ok = sensor.setFilterAndStandby(
           BME280Driver::TSB_0_5_MS,
           filterValues[i],
           false) && ok;
  }
  for (size_t i = 0; i < sizeof(standbyValues) / sizeof(standbyValues[0]); ++i) {
    ok = sensor.setFilterAndStandby(
           standbyValues[i],
           BME280Driver::FILTER_OFF,
           false) && ok;
  }

  const bool enableSpi3wOk = sensor.setFilterAndStandby(
    BME280Driver::TSB_20_MS,
    BME280Driver::FILTER_16,
    true);
  const bool restoreSpi3wOk = sensor.setFilterAndStandby(
    BME280Driver::TSB_0_5_MS,
    BME280Driver::FILTER_OFF,
    false);
  spi3wBranchOk = enableSpi3wOk && restoreSpi3wOk;
  return ok && spi3wBranchOk;
}

static bool testCalibrationGetter() {
  if (!sensor.readCalibration()) {
    return false;
  }
  const BME280Driver::Calibration& calibration = sensor.calibration();
  Serial.print("Calibration: dig_T1=");
  Serial.print(calibration.dig_T1);
  Serial.print(", dig_P1=");
  Serial.print(calibration.dig_P1);
  Serial.print(", dig_H1=");
  Serial.println(calibration.dig_H1);
  return calibration.dig_T1 != 0 && calibration.dig_P1 != 0;
}

static bool testRawDataAndOutputs() {
  const BME280Driver::RawData raw = sensor.getRawData();
  const bool rawRanges = raw.press_raw <= 0xFFFFFu &&
                         raw.temp_raw <= 0xFFFFFu;
  const bool flagConsistency =
    (raw.pressure_skipped == (raw.press_raw == RAW_20BIT_SENTINEL)) &&
    (raw.temperature_skipped == (raw.temp_raw == RAW_20BIT_SENTINEL)) &&
    (raw.humidity_skipped == (raw.hum_raw == RAW_16BIT_SENTINEL));
  const bool measured = !raw.pressure_skipped &&
                        !raw.temperature_skipped &&
                        !raw.humidity_skipped;
  markCheck(CHECK_RAW_DATA, rawRanges && flagConsistency);
  markCheck(CHECK_MEASURED_DATA_FLAGS, flagConsistency && measured);

  const float temperature = sensor.getTemperature();
  const float pressure = sensor.getPressure();
  const float humidity = sensor.getHumidity();
  markCheck(CHECK_TEMPERATURE_OUTPUT,
            isFiniteValue(temperature) && temperature >= -40.0f && temperature <= 85.0f);
  markCheck(CHECK_PRESSURE_OUTPUT,
            isFiniteValue(pressure) && pressure >= 30000.0f && pressure <= 110000.0f);
  markCheck(CHECK_HUMIDITY_OUTPUT,
            isFiniteValue(humidity) && humidity >= 0.0f && humidity <= 100.0f);

  Serial.print("Raw: P=");
  Serial.print(raw.press_raw);
  Serial.print(", T=");
  Serial.print(raw.temp_raw);
  Serial.print(", H=");
  Serial.println(raw.hum_raw);
  Serial.print("Values: T=");
  Serial.print(temperature, 2);
  Serial.print(" degC, P=");
  Serial.print(pressure, 2);
  Serial.print(" Pa, H=");
  Serial.print(humidity, 2);
  Serial.println(" %RH");

  return checkStates[CHECK_RAW_DATA] == CHECK_PASS &&
         checkStates[CHECK_MEASURED_DATA_FLAGS] == CHECK_PASS &&
         checkStates[CHECK_TEMPERATURE_OUTPUT] == CHECK_PASS &&
         checkStates[CHECK_PRESSURE_OUTPUT] == CHECK_PASS &&
         checkStates[CHECK_HUMIDITY_OUTPUT] == CHECK_PASS;
}

static bool testSkippedMeasurementSentinels() {
  bool ok = true;
  ok = sensor.setHumidityOversampling(BME280Driver::OSRS_SKIP) && ok;
  ok = sensor.setTempPressureOversamplingAndMode(
         BME280Driver::OSRS_SKIP,
         BME280Driver::OSRS_SKIP,
         BME280Driver::MODE_FORCED) && ok;
  ok = waitForMeasurementComplete(MEASUREMENT_TIMEOUT_MS) && ok;
  ok = sensor.readSensor() && ok;

  const BME280Driver::RawData raw = sensor.getRawData();
  const bool sentinelFlags = raw.pressure_skipped &&
                             raw.temperature_skipped &&
                             raw.humidity_skipped &&
                             raw.press_raw == RAW_20BIT_SENTINEL &&
                             raw.temp_raw == RAW_20BIT_SENTINEL &&
                             raw.hum_raw == RAW_16BIT_SENTINEL;
  return ok && sentinelFlags;
}

static void printChecklist() {
  uint8_t passCount = 0;
  uint8_t failCount = 0;
  uint8_t skipCount = 0;

  Serial.println();
  Serial.println("=== BME280 periodic test checklist ===");
  for (size_t i = 0; i < CHECK_COUNT; ++i) {
    const CheckState state = checkStates[i];
    if (state == CHECK_PASS) {
      ++passCount;
    } else if (state == CHECK_FAIL) {
      ++failCount;
    } else if (state == CHECK_SKIP || state == CHECK_NOT_RUN) {
      ++skipCount;
    }
    Serial.print("[");
    Serial.print(stateText(state));
    Serial.print("] ");
    Serial.println(CHECK_NAMES[i]);
  }
  Serial.print("Checklist summary: ");
  Serial.print(passCount);
  Serial.print(" passed, ");
  Serial.print(failCount);
  Serial.print(" failed, ");
  Serial.print(skipCount);
  Serial.println(" skipped/not run.");
  Serial.println();
}

static void runFullTest() {
  resetChecklist();
  skipCheck(CHECK_SPI_TRANSPORT);
  sensorInitialized = false;

  Serial.println();
  Serial.println("=== BME280 full API test ===");
  Serial.println("Transport: I2C, address 0x76, SDA GPIO0, SCL GPIO1");
  Serial.println("SPI: skipped because the sensor is not wired to SPI.");

  const bool beginOk = sensor.beginI2C(BME280_I2C_ADDRESS, &Wire);
  markCheck(CHECK_I2C_INITIALIZATION, beginOk);
  if (!beginOk) {
    Serial.println("I2C initialization failed; dependent checks remain not run.");
    printChecklist();
    return;
  }
  sensorInitialized = true;

  const uint8_t chipId = sensor.readChipId();
  Serial.print("Chip ID: 0x");
  Serial.println(chipId, HEX);
  markCheck(CHECK_CHIP_ID, chipId == 0x60);
  markCheck(CHECK_CALIBRATION, testCalibrationGetter());
  markCheck(CHECK_IM_UPDATE_STATUS, !sensor.isImUpdate());
  markCheck(CHECK_MEASURING_STATUS, waitForMeasurementComplete(MEASUREMENT_TIMEOUT_MS));

  markCheck(CHECK_HUMIDITY_OVERSAMPLING, testHumidityOversamplingValues());
  markCheck(CHECK_TEMPERATURE_PRESSURE_OVERSAMPLING,
            testTemperaturePressureOversamplingValues());
  markCheck(CHECK_MEASUREMENT_MODES, testMeasurementModes());

  bool spi3wBranchOk = false;
  const bool filterStandbyOk = testFilterAndStandbyValues(spi3wBranchOk);
  markCheck(CHECK_FILTER_AND_STANDBY, filterStandbyOk);
  markCheck(CHECK_SPI3W_CONFIGURATION, spi3wBranchOk);

  const bool forcedReadOk = triggerAndReadMeasurement();
  markCheck(CHECK_FORCED_MEASUREMENT, forcedReadOk);
  if (forcedReadOk) {
    testRawDataAndOutputs();
  } else {
    markCheck(CHECK_RAW_DATA, false);
    markCheck(CHECK_MEASURED_DATA_FLAGS, false);
    markCheck(CHECK_TEMPERATURE_OUTPUT, false);
    markCheck(CHECK_PRESSURE_OUTPUT, false);
    markCheck(CHECK_HUMIDITY_OUTPUT, false);
  }

  const bool skippedSentinelsOk = testSkippedMeasurementSentinels();
  markCheck(CHECK_SKIPPED_SENTINELS, skippedSentinelsOk);

  bool resetOk = sensor.softReset();
  bool resetRecoveryOk = resetOk;
  resetRecoveryOk = (sensor.readChipId() == 0x60) && resetRecoveryOk;
  resetRecoveryOk = !sensor.isImUpdate() && resetRecoveryOk;
  resetRecoveryOk = sensor.readCalibration() && resetRecoveryOk;
  markCheck(CHECK_SOFT_RESET, resetRecoveryOk);

  const int selfTestCode = sensor.performSelfTest();
  Serial.print("Self-test return code: ");
  Serial.println(selfTestCode);
  markCheck(CHECK_SELF_TEST, selfTestCode == 0);

  sensor.setHumidityOversampling(BME280Driver::OSRS_X1);
  sensor.setTempPressureOversamplingAndMode(
    BME280Driver::OSRS_X1,
    BME280Driver::OSRS_X1,
    BME280Driver::MODE_SLEEP);

  printChecklist();
}

static void runMonitorCycle() {
  Serial.println();
  Serial.println("=== BME280 monitor cycle ===");
  Serial.print("Cycle: ");
  Serial.println(++monitorCycle);
  Serial.println("Bus: I2C, SDA GPIO0, SCL GPIO1, address 0x76");

  if (!sensorInitialized) {
    Serial.println("Status: sensor is not initialized.");
    Serial.println("INT: not applicable; BME280 has no interrupt API or interrupt pin in this setup.");
    Serial.println("=== End monitor cycle ===");
    Serial.println();
    return;
  }

  const bool measurementOk = triggerAndReadMeasurement();
  const bool measuring = sensor.isMeasuring();
  const bool imUpdate = sensor.isImUpdate();
  Serial.print("Status: measuring=");
  Serial.print(measuring ? "true" : "false");
  Serial.print(", im_update=");
  Serial.println(imUpdate ? "true" : "false");

  if (measurementOk) {
    const BME280Driver::RawData raw = sensor.getRawData();
    Serial.print("Measurement: T=");
    Serial.print(sensor.getTemperature(), 2);
    Serial.print(" degC, P=");
    Serial.print(sensor.getPressure(), 2);
    Serial.print(" Pa, H=");
    Serial.print(sensor.getHumidity(), 2);
    Serial.println(" %RH");
    Serial.print("Raw: P=");
    Serial.print(raw.press_raw);
    Serial.print(", T=");
    Serial.print(raw.temp_raw);
    Serial.print(", H=");
    Serial.println(raw.hum_raw);
    Serial.print("Skipped: pressure=");
    Serial.print(raw.pressure_skipped ? "true" : "false");
    Serial.print(", temperature=");
    Serial.print(raw.temperature_skipped ? "true" : "false");
    Serial.print(", humidity=");
    Serial.println(raw.humidity_skipped ? "true" : "false");
  } else {
    Serial.println("Measurement: read failed.");
  }

  Serial.println("INT: not applicable; BME280 has no interrupt API or interrupt pin in this setup.");
  Serial.println("=== End monitor cycle ===");
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  delay(500);

  Wire.setSDA(I2C_SDA_PIN);
  Wire.setSCL(I2C_SCL_PIN);
  Wire.begin();

  runFullTest();
  lastFullTestMs = millis();
  lastMonitorMs = millis();
}

void loop() {
  const uint32_t nowMs = millis();
  if ((nowMs - lastMonitorMs) >= MONITOR_INTERVAL_MS) {
    lastMonitorMs = nowMs;
    runMonitorCycle();
  }
  if ((nowMs - lastFullTestMs) >= FULL_TEST_INTERVAL_MS) {
    lastFullTestMs = nowMs;
    runFullTest();
  }
  delay(10);
}
