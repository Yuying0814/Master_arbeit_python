/*
 * Periodic I2C monitor and functional checklist for the LIS3DH driver.
 * Target: RP2040 custom board (SDA=GPIO0, SCL=GPIO1, INT1=GPIO12, INT2=GPIO13).
 */

#include <Arduino.h>
#include <Wire.h>
#include <math.h>

#include "LIS3DH.h"

namespace {

constexpr uint8_t LIS3DH_I2C_ADDRESS = 0x18;
constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 1;
constexpr uint8_t INT1_PIN = 12;
constexpr uint8_t INT2_PIN = 13;

constexpr unsigned long MONITOR_INTERVAL_MS = 1000UL;
constexpr unsigned long MODE_SWITCH_INTERVAL_MS = 20000UL;
constexpr unsigned long RETRY_INTERVAL_MS = 2000UL;

// At ±2 g, one threshold LSB represents 16 mg.
constexpr uint8_t POSTURE_THRESHOLD_REGISTER_VALUE = 32;
constexpr float POSTURE_THRESHOLD_MG = 500.0f;

// 1500 mg is represented by the nearest 7-bit value: 94 * 16 mg = 1504 mg.
constexpr uint8_t EVENT_THRESHOLD_REGISTER_VALUE = 94;
constexpr float EVENT_THRESHOLD_MG = 1500.0f;
constexpr uint8_t ACTIVITY_DURATION_REGISTER_VALUE = 5;

// AOI=1, 6D=1, and all six directions enabled: 6D position recognition.
constexpr uint8_t INT1_POSTURE_CFG = 0x02;
// ZH only: positive Z threshold event.
constexpr uint8_t INT2_Z_POSITIVE_CFG = 0x20;
constexpr uint8_t FIFO_WATERMARK = 4;
constexpr unsigned long FIFO_FILL_WAIT_MS = 150UL;

LIS3DH sensor(Wire, LIS3DH_I2C_ADDRESS);

enum class PeriodicMode : uint8_t {
  NormalMonitoring = 0,
  ClickDetection,
  Activity,
  HighResolutionLittleEndian,
  LowPower
};

// Normal monitoring is repeated between event modes so both transitions are checked.
const PeriodicMode PERIODIC_MODE_SEQUENCE[] = {
    PeriodicMode::NormalMonitoring,
    PeriodicMode::ClickDetection,
    PeriodicMode::NormalMonitoring,
    PeriodicMode::Activity,
    PeriodicMode::NormalMonitoring,
    PeriodicMode::HighResolutionLittleEndian,
    PeriodicMode::LowPower};

bool deviceReady = false;
unsigned long lastMonitorMs = 0;
unsigned long lastModeSwitchMs = 0;
unsigned long lastRetryMs = 0;
uint32_t checklistCycle = 0;
uint16_t passCount = 0;
uint16_t failCount = 0;
uint8_t periodicModeIndex = 0;
PeriodicMode currentMode = PeriodicMode::NormalMonitoring;

const char *periodicModeName(PeriodicMode mode) {
  switch (mode) {
    case PeriodicMode::NormalMonitoring:
      return "Normal monitoring";
    case PeriodicMode::ClickDetection:
      return "Click detection";
    case PeriodicMode::Activity:
      return "Activity / auto sleep-wake";
    case PeriodicMode::HighResolutionLittleEndian:
      return "High-resolution little-endian";
    case PeriodicMode::LowPower:
      return "Low-power";
    default:
      return "Unknown";
  }
}

void printHex8(uint8_t value) {
  if (value < 0x10) {
    Serial.print('0');
  }
  Serial.print(value, HEX);
}

bool sampleIsValid(const AccelerationSample &sample) {
  return isfinite(sample.x_mg) && isfinite(sample.y_mg) &&
         isfinite(sample.z_mg) && fabsf(sample.x_mg) <= 2500.0f &&
         fabsf(sample.y_mg) <= 2500.0f && fabsf(sample.z_mg) <= 2500.0f;
}

void printAcceleration(const AccelerationSample &sample) {
  Serial.print("Acceleration [mg]: X=");
  Serial.print(sample.x_mg, 1);
  Serial.print(" Y=");
  Serial.print(sample.y_mg, 1);
  Serial.print(" Z=");
  Serial.println(sample.z_mg, 1);

  Serial.print("Raw counts: X=");
  Serial.print(sample.x_raw);
  Serial.print(" Y=");
  Serial.print(sample.y_raw);
  Serial.print(" Z=");
  Serial.println(sample.z_raw);
}

void printStatus(const AccelerationStatus &status) {
  Serial.print("STATUS_REG=0x");
  printHex8(status.status_reg);
  Serial.print(" XYZ_NEW=");
  Serial.print(status.xyz_new ? "1" : "0");
  Serial.print(" XYZ_OVERRUN=");
  Serial.println(status.xyz_overrun ? "1" : "0");
}

void printAuxiliary(const AuxiliaryData &data) {
  Serial.print("Auxiliary counts: ADC1=");
  Serial.print(data.adc1_raw);
  Serial.print(" ADC2=");
  Serial.print(data.adc2_raw);
  Serial.print(" ADC3/TEMP=");
  Serial.print(data.adc3_raw);
  Serial.print(" ready=");
  Serial.print(data.adc1_ready ? "1" : "0");
  Serial.print(data.adc2_ready ? "1" : "0");
  Serial.print(data.adc3_ready ? "1" : "0");
  Serial.println();
}

void printInterruptSource(const char *label, const InterruptSource &source) {
  Serial.print(label);
  Serial.print(" source=0x");
  printHex8(source.raw);
  Serial.print(" event status=");
  Serial.print(source.ia ? "EVENT_DETECTED" : "NO_EVENT");
  Serial.print(" axes[X_high,x_low,y_high,y_low,z_high,z_low]=");
  Serial.print(source.xh ? "1" : "0");
  Serial.print(source.xl ? "1" : "0");
  Serial.print(source.yh ? "1" : "0");
  Serial.print(source.yl ? "1" : "0");
  Serial.print(source.zh ? "1" : "0");
  Serial.println(source.zl ? "1" : "0");
}

void printClickSource(const char *label, const ClickSource &source) {
  Serial.print(label);
  Serial.print(" source=0x");
  printHex8(source.raw);
  Serial.print(" event=");
  Serial.print(source.ia ? "CLICK_DETECTED" : "NO_CLICK");
  Serial.print(" single=");
  Serial.print(source.sclick ? "1" : "0");
  Serial.print(" double=");
  Serial.print(source.dclick ? "1" : "0");
  Serial.print(" direction=");
  if (source.ia) {
    Serial.print(source.sign ? "NEGATIVE" : "POSITIVE");
  } else {
    Serial.print("NONE");
  }
  Serial.print(" axes[X,Y,Z]=");
  Serial.print(source.x ? "1" : "0");
  Serial.print(source.y ? "1" : "0");
  Serial.println(source.z ? "1" : "0");
}

void reportCheck(const char *label, bool passed) {
  Serial.print(passed ? "[PASS] " : "[FAIL] ");
  Serial.println(label);
  if (passed) {
    ++passCount;
  } else {
    ++failCount;
  }
}

MeasurementConfig makeMeasurementConfig(Lis3dhResolution resolution) {
  MeasurementConfig config{};
  config.odr = Lis3dhOdr::Hz100;
  config.fs = Lis3dhFullScale::FS2;
  config.res = resolution;
  config.enableX = true;
  config.enableY = true;
  config.enableZ = true;
  config.bdu = true;
  return config;
}

bool configureInt1PostureInterrupt() {
  InterruptConfig int1{};
  int1.engine = InterruptEngine::INT1;
  int1.cfg_reg_val = INT1_POSTURE_CFG;
  int1.ths = POSTURE_THRESHOLD_REGISTER_VALUE;
  int1.dur = 0;
  int1.routeToInt2 = false;
  int1.latch = false;
  int1.d4d = false;
  int1.polarityActiveLow = false;

  return sensor.configureInterrupt(int1);
}

bool configureInt2ThresholdInterrupt(uint8_t cfg, uint8_t threshold) {
  InterruptConfig int2{};
  int2.engine = InterruptEngine::INT2;
  int2.cfg_reg_val = cfg;
  int2.ths = threshold;
  int2.dur = 0;
  int2.routeToInt2 = true;
  int2.latch = false;
  int2.d4d = false;
  int2.polarityActiveLow = false;

  return sensor.configureInterrupt(int2);
}

bool disableInt2ThresholdInterrupt() {
  return configureInt2ThresholdInterrupt(0x00, 0);
}

bool configurePostureMonitoringInterrupts() {
  return configureInt1PostureInterrupt() && disableInt2ThresholdInterrupt();
}

bool configureInt2PositiveZThreshold() {
  return configureInt2ThresholdInterrupt(INT2_Z_POSITIVE_CFG,
                                          EVENT_THRESHOLD_REGISTER_VALUE);
}

const char *fifoModeName(uint8_t mode) {
  switch (mode & 0x03) {
    case 0:
      return "bypass";
    case 1:
      return "FIFO";
    case 2:
      return "stream";
    case 3:
      return "stream-to-FIFO";
    default:
      return "unknown";
  }
}

void printFifoStatus(const FifoStatus &status) {
  Serial.print("FIFO status: FSS=");
  Serial.print(status.fss);
  Serial.print(" empty=");
  Serial.print(status.empty ? "1" : "0");
  Serial.print(" watermark=");
  Serial.print(status.wtm ? "1" : "0");
  Serial.print(" overrun=");
  Serial.println(status.overrun ? "1" : "0");
}

bool testFifoMode(uint8_t mode, bool triggerInt2) {
  Serial.print("[FIFO] Testing mode: ");
  Serial.print(fifoModeName(mode));
  Serial.print(" trigger=");
  Serial.println(triggerInt2 ? "INT2" : "INT1");

  FifoConfig config{};
  config.fm = mode;
  config.tr = triggerInt2;
  config.fth = FIFO_WATERMARK;

  const bool configured = sensor.configureFifo(config);
  reportCheck("  FIFO mode configuration", configured);
  if (!configured) {
    return false;
  }

  delay(FIFO_FILL_WAIT_MS);

  FifoStatus before{};
  const bool statusOk = sensor.readFifoStatus(before);
  reportCheck("  FIFO status read", statusOk);
  if (statusOk) {
    printFifoStatus(before);
  }

  bool sampleOk = true;
  if (statusOk && before.fss > 0) {
    AccelerationSample sample{};
    sampleOk = sensor.readFifoSample(sample) && sampleIsValid(sample);
    reportCheck("  FIFO acceleration sample read", sampleOk);
    if (sampleOk) {
      printAcceleration(sample);
    }

    FifoStatus after{};
    const bool afterOk = sensor.readFifoStatus(after);
    reportCheck("  FIFO status read after sample", afterOk);
    if (afterOk) {
      printFifoStatus(after);
    }
  } else {
    Serial.println("  FIFO sample read: SKIPPED (FIFO is empty)");
  }

  return configured && statusOk && sampleOk;
}

bool testFifo() {
  Serial.println();
  Serial.println("[TEST] FIFO modes, status, data, trigger selection, and reset");

  bool allOk = true;

  allOk = testFifoMode(0, false) && allOk;
  allOk = sensor.resetFifo() && allOk;
  allOk = testFifoMode(1, false) && allOk;
  allOk = sensor.resetFifo() && allOk;
  allOk = testFifoMode(1, true) && allOk;
  allOk = sensor.resetFifo() && allOk;
  allOk = testFifoMode(2, false) && allOk;
  allOk = sensor.resetFifo() && allOk;
  allOk = testFifoMode(3, false) && allOk;

  const bool resetOk = sensor.resetFifo();
  reportCheck("FIFO reset", resetOk);

  FifoStatus resetStatus{};
  const bool resetStatusOk = sensor.readFifoStatus(resetStatus);
  const bool resetEmpty = resetStatusOk && resetStatus.empty && resetStatus.fss == 0;
  reportCheck("FIFO empty after reset", resetEmpty);
  if (resetStatusOk) {
    printFifoStatus(resetStatus);
  }

  return allOk && resetOk && resetEmpty;
}

bool disableClickAndActivity() {
  // A zero CLICK_CFG disables all click axes. The driver keeps one route bit
  // selected, but no click event can be generated while all axes are disabled.
  ClickConfig click{};
  click.cfg = 0x00;
  click.ths = 0;
  click.latch = false;
  click.timeLimit = 0;
  click.timeLatency = 0;
  click.timeWindow = 0;
  click.routeToInt2 = false;

  return sensor.configureClick(click) && sensor.configureActivity(0, 0, false);
}

bool restoreMonitoringConfiguration() {
  const MeasurementConfig normal = makeMeasurementConfig(Lis3dhResolution::Normal);
  return sensor.configureMeasurement(normal) && sensor.setBlockDataUpdate(true) &&
         sensor.configureAuxiliary(true, true) && disableClickAndActivity() &&
         configurePostureMonitoringInterrupts();
}

bool testMode(const char *name, Lis3dhResolution resolution) {
  const MeasurementConfig config = makeMeasurementConfig(resolution);
  const bool configured = sensor.configureMeasurement(config);
  reportCheck(name, configured);
  if (!configured) {
    return false;
  }

  AccelerationSample sample{};
  const bool accelerationOk = sensor.readAcceleration(sample) && sampleIsValid(sample);
  reportCheck("  acceleration read after mode switch", accelerationOk);
  if (accelerationOk) {
    printAcceleration(sample);
  }

  AccelerationStatus status{};
  const bool statusOk = sensor.readAccelerationStatus(status);
  reportCheck("  STATUS_REG read after mode switch", statusOk);
  if (statusOk) {
    printStatus(status);
  }

  InterruptSource source{};
  const bool interruptOk = sensor.readInterruptSource(InterruptEngine::INT1, source);
  reportCheck("  INT1 posture source read after mode switch", interruptOk);
  if (interruptOk) {
    printInterruptSource("INT1", source);
  }

  return accelerationOk && statusOk && interruptOk;
}

bool testLittleEndianOutput() {
  Serial.println();
  Serial.println("[MODE] High-resolution little-endian output");

  const bool endianConfigured = sensor.setEndian(false);
  reportCheck("Little-endian output configuration", endianConfigured);
  if (!endianConfigured) {
    return false;
  }

  AccelerationSample sample{};
  const bool accelerationOk = sensor.readAcceleration(sample) && sampleIsValid(sample);
  reportCheck("  acceleration read after little-endian configuration", accelerationOk);
  if (accelerationOk) {
    printAcceleration(sample);
  }

  AccelerationStatus status{};
  const bool statusOk = sensor.readAccelerationStatus(status);
  reportCheck("  STATUS_REG read after little-endian configuration", statusOk);
  if (statusOk) {
    printStatus(status);
  }

  return accelerationOk && statusOk;
}

bool readEventModeState(const char *modeName, InterruptEngine interruptEngine,
                        bool readClickSourceValue, bool checkPositiveZ) {
  Serial.print("Measurement readback after ");
  Serial.println(modeName);

  AccelerationSample sample{};
  const bool accelerationOk = sensor.readAcceleration(sample) && sampleIsValid(sample);
  reportCheck("  acceleration read after event-mode switch", accelerationOk);
  if (accelerationOk) {
    printAcceleration(sample);
  }

  AccelerationStatus status{};
  const bool statusOk = sensor.readAccelerationStatus(status);
  reportCheck("  STATUS_REG read after event-mode switch", statusOk);
  if (statusOk) {
    printStatus(status);
  }

  InterruptSource interruptSource{};
  const bool interruptOk =
      sensor.readInterruptSource(interruptEngine, interruptSource);
  reportCheck("  interrupt source read after event-mode switch", interruptOk);
  if (interruptOk) {
    printInterruptSource(interruptEngine == InterruptEngine::INT1 ? "INT1" : "INT2",
                         interruptSource);
  }

  bool clickOk = true;
  if (readClickSourceValue) {
    ClickSource clickSource{};
    clickOk = sensor.readClickSource(clickSource);
    reportCheck("  CLICK_SRC read after Click-mode switch", clickOk);
    if (clickOk) {
      printClickSource("CLICK", clickSource);
      if (clickSource.ia) {
        const bool positiveZ = clickSource.z && !clickSource.sign;
        reportCheck("  detected Click is positive Z", positiveZ);
      } else {
        Serial.println("  Click event: NONE (apply a positive-Z click to validate direction)");
      }
    }
  }

  if (checkPositiveZ && interruptOk) {
    if (interruptSource.ia) {
      reportCheck("  detected Activity is positive Z", interruptSource.zh);
    } else {
      Serial.println("  Activity event: NONE (apply +Z acceleration above 1500 mg to validate)");
    }
  }

  const uint8_t pin = interruptEngine == InterruptEngine::INT1 ? INT1_PIN : INT2_PIN;
  Serial.print("GPIO");
  Serial.print(pin);
  Serial.print(" / selected interrupt level: ");
  Serial.println(digitalRead(pin) == HIGH ? "HIGH" : "LOW");

  return accelerationOk && statusOk && interruptOk && clickOk;
}

bool testNormalMonitoringMode() {
  Serial.println();
  Serial.println("[MODE] Normal monitoring mode");

  const bool configured = restoreMonitoringConfiguration();
  reportCheck("Normal monitoring mode configuration", configured);
  if (!configured) {
    return false;
  }

  AccelerationSample sample{};
  const bool accelerationOk = sensor.readAcceleration(sample) && sampleIsValid(sample);
  reportCheck("  acceleration read in normal monitoring mode", accelerationOk);
  if (accelerationOk) {
    printAcceleration(sample);
  }

  AccelerationStatus status{};
  const bool statusOk = sensor.readAccelerationStatus(status);
  reportCheck("  STATUS_REG read in normal monitoring mode", statusOk);
  if (statusOk) {
    printStatus(status);
  }

  InterruptSource int1{};
  InterruptSource int2{};
  const bool int1Ok = sensor.readInterruptSource(InterruptEngine::INT1, int1);
  const bool int2Ok = sensor.readInterruptSource(InterruptEngine::INT2, int2);
  reportCheck("  INT1 source read in normal monitoring mode", int1Ok);
  reportCheck("  INT2 source read in normal monitoring mode", int2Ok);
  if (int1Ok) {
    printInterruptSource("INT1", int1);
  }
  if (int2Ok) {
    printInterruptSource("INT2", int2);
  }

  Serial.print("GPIO12 / INT1 level: ");
  Serial.println(digitalRead(INT1_PIN) == HIGH ? "HIGH" : "LOW");
  Serial.print("GPIO13 / INT2 level: ");
  Serial.println(digitalRead(INT2_PIN) == HIGH ? "HIGH" : "LOW");

  return accelerationOk && statusOk && int1Ok && int2Ok;
}

bool testClickMode() {
  Serial.println();
  Serial.println("[MODE] Click detection mode");

  const MeasurementConfig normal = makeMeasurementConfig(Lis3dhResolution::Normal);
  ClickConfig click{};
  click.cfg = 0x10;       // Z-axis single-click detection.
  click.ths = EVENT_THRESHOLD_REGISTER_VALUE;
  click.latch = true;
  click.timeLimit = 10;
  click.timeLatency = 20;
  click.timeWindow = 80;
  click.routeToInt2 = true;

  Serial.println("Click configuration: Z single-click, approximately 1500 mg, routed to INT2/GPIO13");

  const bool configured = sensor.configureMeasurement(normal) &&
                          sensor.setBlockDataUpdate(true) &&
                          sensor.configureAuxiliary(true, true) &&
                          disableClickAndActivity() &&
                          configureInt1PostureInterrupt() &&
                          disableInt2ThresholdInterrupt() &&
                          sensor.configureClick(click);
  reportCheck("Click detection mode configuration", configured);
  if (!configured) {
    return false;
  }

  return readEventModeState("Click detection mode", InterruptEngine::INT2, true, false);
}

bool testActivityMode() {
  Serial.println();
  Serial.println("[MODE] Activity / auto sleep-wake mode");

  const MeasurementConfig normal = makeMeasurementConfig(Lis3dhResolution::Normal);
  Serial.println("Activity configuration: approximately 1500 mg, +Z threshold path on INT2/GPIO13");
  const bool configured = sensor.configureMeasurement(normal) &&
                          sensor.setBlockDataUpdate(true) &&
                          sensor.configureAuxiliary(true, true) &&
                          disableClickAndActivity() &&
                          configureInt1PostureInterrupt() &&
                          configureInt2PositiveZThreshold() &&
                          sensor.configureActivity(EVENT_THRESHOLD_REGISTER_VALUE,
                                                   ACTIVITY_DURATION_REGISTER_VALUE, true);
  reportCheck("Activity mode configuration", configured);
  if (!configured) {
    return false;
  }

  return readEventModeState("Activity / auto sleep-wake mode", InterruptEngine::INT2,
                           false, true);
}

void runChecklist() {
  ++checklistCycle;
  passCount = 0;
  failCount = 0;

  Serial.println();
  Serial.println("========================================");
  Serial.print("LIS3DH long-period checklist cycle ");
  Serial.println(checklistCycle);
  Serial.println("========================================");

  reportCheck("WHO_AM_I device identification", sensor.whoAmI());
  reportCheck("Auxiliary ADC and temperature channel enable",
              sensor.configureAuxiliary(true, true));

  AuxiliaryData auxiliary{};
  const bool auxiliaryOk = sensor.readAuxiliary(auxiliary);
  reportCheck("Auxiliary ADC read", auxiliaryOk);
  if (auxiliaryOk) {
    printAuxiliary(auxiliary);
  }

  reportCheck("INT1 posture and INT2 monitoring configuration",
              configurePostureMonitoringInterrupts());

  testFifo();

  testMode("Normal-resolution mode configuration", Lis3dhResolution::Normal);
  testMode("High-resolution mode configuration", Lis3dhResolution::HighResolution);
  testLittleEndianOutput();
  testMode("Low-power mode configuration", Lis3dhResolution::LowPower);

  testClickMode();
  testNormalMonitoringMode();
  testActivityMode();
  testNormalMonitoringMode();

  reportCheck("Restore normal monitoring configuration",
              restoreMonitoringConfiguration());

  Serial.println("----------------------------------------");
  Serial.print("Checklist summary: PASS=");
  Serial.print(passCount);
  Serial.print(" FAIL=");
  Serial.println(failCount);
  Serial.println(failCount == 0 ? "[OVERALL] PASS" : "[OVERALL] FAIL");
  Serial.println("----------------------------------------");
  Serial.println();
}

void runPeriodicModeChecklist() {
  const uint8_t sequenceLength =
      static_cast<uint8_t>(sizeof(PERIODIC_MODE_SEQUENCE) /
                          sizeof(PERIODIC_MODE_SEQUENCE[0]));
  periodicModeIndex = static_cast<uint8_t>((periodicModeIndex + 1) % sequenceLength);
  currentMode = PERIODIC_MODE_SEQUENCE[periodicModeIndex];

  ++checklistCycle;
  passCount = 0;
  failCount = 0;

  Serial.println();
  Serial.println("========================================");
  Serial.print("LIS3DH 20-second mode-switch checklist cycle ");
  Serial.println(checklistCycle);
  Serial.println("========================================");
  Serial.print("Switched to mode: ");
  Serial.println(periodicModeName(currentMode));

  testFifo();

  switch (currentMode) {
    case PeriodicMode::NormalMonitoring:
      testNormalMonitoringMode();
      break;

    case PeriodicMode::ClickDetection:
      testClickMode();
      break;

    case PeriodicMode::Activity:
      testActivityMode();
      break;

    case PeriodicMode::HighResolutionLittleEndian: {
      const bool prepared = restoreMonitoringConfiguration();
      reportCheck("Prepare high-resolution monitoring mode", prepared);
      if (prepared) {
        testMode("High-resolution mode configuration", Lis3dhResolution::HighResolution);
        testLittleEndianOutput();
      }
      break;
    }

    case PeriodicMode::LowPower: {
      const bool prepared = restoreMonitoringConfiguration();
      reportCheck("Prepare low-power monitoring mode", prepared);
      if (prepared) {
        testMode("Low-power mode configuration", Lis3dhResolution::LowPower);
      }
      break;
    }
  }

  Serial.println("----------------------------------------");
  Serial.print("Checklist summary: PASS=");
  Serial.print(passCount);
  Serial.print(" FAIL=");
  Serial.println(failCount);
  Serial.println(failCount == 0 ? "[OVERALL] PASS" : "[OVERALL] FAIL");
  Serial.println("----------------------------------------");
  Serial.println();
}

void runMonitorCycle() {
  Serial.println();
  Serial.println("========================================");
  Serial.println("LIS3DH short-period measurement monitor");
  Serial.println("========================================");
  Serial.print("Current mode: ");
  Serial.println(periodicModeName(currentMode));

  AccelerationSample sample{};
  const bool accelerationOk = sensor.readAcceleration(sample) && sampleIsValid(sample);
  if (accelerationOk) {
    printAcceleration(sample);
  } else {
    Serial.println("Acceleration: READ_ERROR");
  }

  AccelerationStatus status{};
  if (sensor.readAccelerationStatus(status)) {
    printStatus(status);
  } else {
    Serial.println("STATUS_REG: READ_ERROR");
  }

  AuxiliaryData auxiliary{};
  if (sensor.readAuxiliary(auxiliary)) {
    printAuxiliary(auxiliary);
  } else {
    Serial.println("Auxiliary ADC/temperature: READ_ERROR");
  }

  const bool int1Level = digitalRead(INT1_PIN) == HIGH;
  const bool int2Level = digitalRead(INT2_PIN) == HIGH;
  InterruptSource int1{};
  InterruptSource int2{};
  const bool int1Ok = sensor.readInterruptSource(InterruptEngine::INT1, int1);
  const bool int2Ok = sensor.readInterruptSource(InterruptEngine::INT2, int2);

  ClickSource click{};
  bool clickOk = true;
  if (currentMode == PeriodicMode::ClickDetection) {
    clickOk = sensor.readClickSource(click);
    if (clickOk) {
      printClickSource("CLICK", click);
    } else {
      Serial.println("CLICK source: READ_ERROR");
    }
  }

  if (currentMode == PeriodicMode::Activity) {
    const bool positiveZCrossing =
        accelerationOk && sample.z_mg >= EVENT_THRESHOLD_MG;
    Serial.print("Activity +Z reference: >=");
    Serial.print(EVENT_THRESHOLD_MG, 0);
    Serial.print(" mg; software crossing=");
    Serial.println(positiveZCrossing ? "YES" : "NO");
  } else if (currentMode == PeriodicMode::ClickDetection) {
    Serial.print("Click threshold: approximately ");
    Serial.print(EVENT_THRESHOLD_MG, 0);
    Serial.println(" mg; direction: Z-axis, positive sign checked in CLICK source");
  } else {
    Serial.print("INT1 function: 6D position recognition; threshold reference=");
    Serial.print(POSTURE_THRESHOLD_MG, 0);
    Serial.println(" mg");
  }

  Serial.print("GPIO12 / INT1 level: ");
  Serial.println(int1Level ? "HIGH" : "LOW");
  if (int1Ok) {
    printInterruptSource("INT1", int1);
  } else {
    Serial.println("INT1 source: READ_ERROR");
  }

  Serial.print("GPIO13 / INT2 level: ");
  Serial.println(int2Level ? "HIGH" : "LOW");
  if (int2Ok) {
    printInterruptSource("INT2", int2);
  } else {
    Serial.println("INT2 source: READ_ERROR");
  }

  const bool hardwareEvent = (int1Ok && int1.ia) || (int2Ok && int2.ia) ||
                             int1Level || int2Level || (clickOk && click.ia);
  Serial.print("Overall event state: ");
  Serial.println(hardwareEvent ? "EVENT_DETECTED" : "NO_EVENT");
  Serial.println();
}

}  // namespace

void setup() {
  Serial.begin(115200);
  const unsigned long serialStart = millis();
  while (!Serial && millis() - serialStart < 3000UL) {
    delay(10);
  }

  Wire.setSDA(I2C_SDA_PIN);
  Wire.setSCL(I2C_SCL_PIN);
  Wire.begin();

  pinMode(INT1_PIN, INPUT);
  pinMode(INT2_PIN, INPUT);

  Serial.println();
  Serial.println("LIS3DH RP2040 periodic I2C test");
  Serial.println("I2C: SDA=GPIO0, SCL=GPIO1, address=0x18");
  Serial.println("Interrupts: INT1=GPIO12, INT2=GPIO13");

  deviceReady = sensor.begin();
  if (!deviceReady) {
    Serial.println("LIS3DH: BEGIN_ERROR; retrying periodically");
    lastRetryMs = millis();
    return;
  }

  Serial.println("LIS3DH: READY");
  if (!restoreMonitoringConfiguration()) {
    Serial.println("LIS3DH: MONITOR_CONFIGURATION_ERROR");
  }
  runChecklist();
  currentMode = PeriodicMode::NormalMonitoring;
  periodicModeIndex = 0;
  lastModeSwitchMs = millis();
  lastMonitorMs = millis();
}

void loop() {
  const unsigned long now = millis();

  if (!deviceReady) {
    if (now - lastRetryMs >= RETRY_INTERVAL_MS) {
      lastRetryMs = now;
      Serial.println();
      Serial.println("[RETRY] Attempting LIS3DH initialization");
      deviceReady = sensor.begin();
      if (deviceReady && restoreMonitoringConfiguration()) {
        Serial.println("LIS3DH: READY");
        runChecklist();
        currentMode = PeriodicMode::NormalMonitoring;
        periodicModeIndex = 0;
        lastModeSwitchMs = millis();
        lastMonitorMs = millis();
      } else {
        deviceReady = false;
        Serial.println("LIS3DH: BEGIN_OR_CONFIGURATION_ERROR");
      }
    }
    return;
  }

  if (now - lastMonitorMs >= MONITOR_INTERVAL_MS) {
    runMonitorCycle();
    lastMonitorMs = millis();
  }

  if (now - lastModeSwitchMs >= MODE_SWITCH_INTERVAL_MS) {
    runPeriodicModeChecklist();
    lastModeSwitchMs = millis();
  }
}
