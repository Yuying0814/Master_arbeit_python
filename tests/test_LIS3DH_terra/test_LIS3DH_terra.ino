/*
Periodic I2C API and measurement test for the LIS3DH driver.
*/

#include <Arduino.h>
#include <Wire.h>
#include <math.h>

// The driver source is included because this sketch is stored one directory above the driver files.
#include "LIS3DH.h"

// Board wiring and driver defaults.
constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 1;
constexpr uint8_t INT1_PIN = 12;
constexpr uint8_t INT2_PIN = 13;
constexpr uint8_t LIS3DH_I2C_ADDRESS = LIS3DH_I2C_ADDR_SA0_LOW;

constexpr unsigned long MONITOR_INTERVAL_MS = 1000UL;
constexpr unsigned long FULL_API_TEST_INTERVAL_MS = 15000UL;
constexpr unsigned long DEVICE_RETRY_INTERVAL_MS = 2000UL;

LIS3DH sensor(Wire, LIS3DH_I2C_ADDRESS);

bool deviceReady = false;
unsigned long lastMonitorMs = 0;
unsigned long lastFullApiTestMs = 0;
unsigned long lastDeviceRetryMs = 0;

uint16_t passCount = 0;
uint16_t failCount = 0;
uint16_t skipCount = 0;

void printHex8(uint8_t value) {
  if (value < 0x10) {
    Serial.print('0');
  }
  Serial.print(static_cast<unsigned int>(value), HEX);
}

void printBoolean(bool value) {
  Serial.print(value ? "1" : "0");
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

bool measurementConfigEqual(const MeasurementConfig &first,
                            const MeasurementConfig &second) {
  return first.odr_code == second.odr_code &&
         first.lp == second.lp &&
         first.xen == second.xen &&
         first.yen == second.yen &&
         first.zen == second.zen &&
         first.fs == second.fs &&
         first.hr == second.hr &&
         first.bdu == second.bdu &&
         first.ble == second.ble;
}

bool accelerationIsFinite(const Acceleration &sample) {
  return isfinite(sample.x_g) && isfinite(sample.y_g) &&
         isfinite(sample.z_g);
}

void printAcceleration(const Acceleration &sample) {
  Serial.print("  Acceleration [g]: X=");
  Serial.print(sample.x_g, 4);
  Serial.print(" Y=");
  Serial.print(sample.y_g, 4);
  Serial.print(" Z=");
  Serial.println(sample.z_g, 4);
  Serial.print("  Raw counts: X=");
  Serial.print(sample.x_counts);
  Serial.print(" Y=");
  Serial.print(sample.y_counts);
  Serial.print(" Z=");
  Serial.println(sample.z_counts);
}

void printMeasurementConfig(const MeasurementConfig &config) {
  Serial.print("  ODR code=0x");
  printHex8(config.odr_code);
  Serial.print(" LP=");
  printBoolean(config.lp);
  Serial.print(" HR=");
  printBoolean(config.hr);
  Serial.print(" FS=");
  Serial.print(config.fs);
  Serial.print(" BDU=");
  printBoolean(config.bdu);
  Serial.print(" BLE=");
  printBoolean(config.ble);
  Serial.print(" axes(XYZ)=");
  printBoolean(config.xen);
  printBoolean(config.yen);
  printBoolean(config.zen);
  Serial.println();
}

void printAccelerationStatus(const AccelerationStatus &status) {
  Serial.print("  STATUS_REG=0x");
  printHex8(status.status_byte);
  Serial.print(" data-ready=");
  printBoolean((status.status_byte & 0x08) != 0);
  Serial.print(" overrun=");
  printBoolean((status.status_byte & 0x80) != 0);
  Serial.println();
}

void printAuxiliaryData(const AuxiliaryData &data) {
  Serial.print("  Auxiliary counts: ADC1=");
  Serial.print(data.adc1_counts);
  Serial.print(" ADC2=");
  Serial.print(data.adc2_counts);
  Serial.print(" ADC3/TEMP=");
  Serial.println(data.adc3_counts);
  Serial.print("  STATUS_REG_AUX=0x");
  printHex8(data.status_aux);
  Serial.println();
}

void printFifoStatus(const FifoStatus &status) {
  Serial.print("  FIFO: level=");
  Serial.print(status.level);
  Serial.print(" empty=");
  printBoolean(status.empty);
  Serial.print(" watermark=");
  printBoolean(status.wtm);
  Serial.print(" overrun=");
  printBoolean(status.overrun);
  Serial.println();
}

void printInterruptSource(const char *label, const InterruptSource &source) {
  Serial.print("  ");
  Serial.print(label);
  Serial.print(" source=0x");
  printHex8(source.srcbyte);
  Serial.println();
}

void printClickSource(const ClickSource &source) {
  Serial.print("  CLICK_SRC=0x");
  printHex8(source.src);
  Serial.println();
}

bool configureAndVerifyMeasurement(const char *label,
                                   const MeasurementConfig &expected) {
  const bool configured = sensor.configureMeasurement(expected);
  reportResult(label, configured);
  if (!configured) {
    reportSkip("Measurement configuration readback");
    return false;
  }

  MeasurementConfig observed{};
  const bool readOk = sensor.getMeasurementConfig(observed);
  const bool matches = readOk && measurementConfigEqual(expected, observed);
  reportResult("getMeasurementConfig() round-trip", matches);
  if (readOk) {
    printMeasurementConfig(observed);
  }
  return matches;
}

void testIdentificationAndLifecycle() {
  Serial.println();
  Serial.println("[TEST] Identification and lifecycle");

  uint8_t whoAmI = 0;
  const bool readIdOk = sensor.readRegister(lis3dh::REG_WHO_AM_I, whoAmI);
  reportResult("readRegister(WHO_AM_I) returns 0x33",
               readIdOk && whoAmI == 0x33);
  if (readIdOk) {
    Serial.print("  WHO_AM_I=0x");
    printHex8(whoAmI);
    Serial.println();
  }

  reportResult("isConnected()", sensor.isConnected());
  const bool rebootOk = sensor.rebootMemory();
  reportResult("rebootMemory()", rebootOk);

  const bool beginOk = sensor.begin();
  reportResult("begin() after rebootMemory()", beginOk);
  if (beginOk) {
    reportResult("isConnected() after rebootMemory()", sensor.isConnected());
  } else {
    reportSkip("Post-reboot identity verification");
  }
}

void testMeasurementApi() {
  Serial.println();
  Serial.println("[TEST] Measurement configuration and acceleration");

  const MeasurementConfig normal = {
      0x05, false, true, true, true, 0, false, true, false};
  const MeasurementConfig highResolution = {
      0x05, false, true, true, true, 0, true, true, false};
  const MeasurementConfig lowPower = {
      0x05, true, true, true, true, 0, false, true, false};

  const bool normalOk =
      configureAndVerifyMeasurement("configureMeasurement(normal)", normal);
  if (normalOk) {
    Acceleration sample{};
    const bool readOk = sensor.readAcceleration(sample);
    reportResult("readAcceleration(normal) returns finite values",
                 readOk && accelerationIsFinite(sample));
    if (readOk) {
      printAcceleration(sample);
    }
  }

  const bool highOk = configureAndVerifyMeasurement(
      "configureMeasurement(high-resolution)", highResolution);
  if (highOk) {
    Acceleration sample{};
    const bool readOk = sensor.readAcceleration(sample);
    reportResult("readAcceleration(high-resolution) returns finite values",
                 readOk && accelerationIsFinite(sample));
    if (readOk) {
      printAcceleration(sample);
    }
  }

  const bool lowOk =
      configureAndVerifyMeasurement("configureMeasurement(low-power)", lowPower);
  if (lowOk) {
    Acceleration sample{};
    const bool readOk = sensor.readAcceleration(sample);
    reportResult("readAcceleration(low-power) returns finite values",
                 readOk && accelerationIsFinite(sample));
    if (readOk) {
      printAcceleration(sample);
    }
  }

  MeasurementConfig invalidMode = normal;
  invalidMode.lp = true;
  invalidMode.hr = true;
  reportExpectedFalse("configureMeasurement(LPen+HR) rejects invalid mode",
                     sensor.configureMeasurement(invalidMode));

  MeasurementConfig highResolutionBigEndian = highResolution;
  highResolutionBigEndian.ble = true;
  const bool bigEndianConfigOk = configureAndVerifyMeasurement(
      "configureMeasurement(HR with BLE)", highResolutionBigEndian);
  if (bigEndianConfigOk) {
    Acceleration sample{};
    reportExpectedFalse("readAcceleration(HR+BLE) rejects unsupported order",
                       sensor.readAcceleration(sample));
  }

  MeasurementConfig withoutBdu = normal;
  withoutBdu.bdu = false;
  const bool withoutBduConfigOk = sensor.configureMeasurement(withoutBdu);
  reportResult("configureMeasurement(BDU=0)", withoutBduConfigOk);
  if (withoutBduConfigOk) {
    Acceleration sample{};
    reportExpectedFalse("readAcceleration() rejects BDU=0",
                       sensor.readAcceleration(sample));
  } else {
    reportSkip("readAcceleration() BDU validation");
  }

  const bool restoreOk = sensor.configureMeasurement(normal);
  reportResult("restore normal measurement configuration", restoreOk);

  AccelerationStatus status{};
  const bool statusOk = sensor.readAccelerationStatus(status);
  reportResult("readAccelerationStatus()", statusOk);
  if (statusOk) {
    printAccelerationStatus(status);
  }
}

void testAuxiliaryApi() {
  Serial.println();
  Serial.println("[TEST] Auxiliary ADC and temperature channel");

  const bool enableOk = sensor.configureAuxiliary(true, true);
  reportResult("configureAuxiliary(ADC+temperature)", enableOk);
  if (enableOk) {
    uint8_t tempConfig = 0;
    const bool registerOk = sensor.readRegister(
        lis3dh::REG_TEMP_CFG_REG, tempConfig);
    reportResult("TEMP_CFG_REG enables ADC and temperature", registerOk &&
               (tempConfig & 0xC0) == 0xC0);

    AuxiliaryData data{};
    const bool readOk = sensor.readAuxiliary(data);
    reportResult("readAuxiliary()", readOk);
    if (readOk) {
      printAuxiliaryData(data);
    }
  } else {
    reportSkip("Auxiliary data read");
  }

  const bool disableOk = sensor.configureAuxiliary(false, false);
  reportResult("configureAuxiliary(disabled)", disableOk);
}

void testSelfTestApi() {
  Serial.println();
  Serial.println("[TEST] Embedded self-test modes");

  const SelfTestMode modes[] = {
      SelfTestMode::Disabled,
      SelfTestMode::ST0,
      SelfTestMode::ST1,
      SelfTestMode::Disabled};
  const uint8_t expectedBits[] = {0x00, 0x02, 0x04, 0x00};
  const char *labels[] = {
      "setSelfTest(Disabled)",
      "setSelfTest(ST0)",
      "setSelfTest(ST1)",
      "setSelfTest(Disabled) restore"};

  for (uint8_t i = 0; i < 4; ++i) {
    const bool setOk = sensor.setSelfTest(modes[i]);
    reportResult(labels[i], setOk);
    if (setOk) {
      uint8_t ctrl4 = 0;
      const bool readOk = sensor.readRegister(lis3dh::REG_CTRL_REG4, ctrl4);
      reportResult("CTRL_REG4 self-test bits read back", readOk &&
                   (ctrl4 & 0x06) == expectedBits[i]);
    }
  }
}

const char *fifoModeName(uint8_t mode) {
  switch (mode & 0x03) {
    case 0:
      return "bypass";
    case 1:
      return "FIFO";
    case 2:
      return "stream";
    default:
      return "stream-to-FIFO";
  }
}

void testOneFifoMode(uint8_t mode) {
  FifoConfig bypass{false, 0, 0, false};
  sensor.configureFifo(bypass);

  FifoConfig config{mode != 0, mode, 4, false};
  Serial.print("  Testing FIFO mode: ");
  Serial.println(fifoModeName(mode));
  const bool configureOk = sensor.configureFifo(config);
  reportResult("configureFifo(valid mode)", configureOk);
  if (!configureOk) {
    return;
  }

  if (mode != 0) {
    delay(60);
  }

  FifoStatus status{};
  const bool statusOk = sensor.getFifoStatus(status);
  reportResult("getFifoStatus()", statusOk);
  if (statusOk) {
    printFifoStatus(status);
  }
}

void testFifoApi() {
  Serial.println();
  Serial.println("[TEST] FIFO modes, status, and retrieval");

  for (uint8_t mode = 0; mode < 4; ++mode) {
    testOneFifoMode(mode);
  }

  FifoConfig stream{true, 2, 4, false};
  const bool streamOk = sensor.configureFifo(stream);
  reportResult("configureFifo(stream) for retrieval", streamOk);
  if (streamOk) {
    delay(80);
    FifoStatus before{};
    const bool beforeOk = sensor.getFifoStatus(before);
    reportResult("getFifoStatus() before readFifo()", beforeOk);
    if (beforeOk) {
      printFifoStatus(before);
    }

    Acceleration samples[4]{};
    uint8_t count = 0;
    const bool readOk = sensor.readFifo(samples, 4, count);
    const bool countValid = readOk && count <= 4 &&
                            (before.empty ? count == 0 : count > 0);
    reportResult("readFifo() respects capacity and FIFO state", countValid);
    Serial.print("  FIFO samples returned: ");
    Serial.println(count);
    if (count > 0) {
      printAcceleration(samples[0]);
    }

    uint8_t invalidCount = 0;
    reportExpectedFalse("readFifo(nullptr, ...) rejects null buffer",
                       sensor.readFifo(nullptr, 4, invalidCount));
    reportExpectedFalse("readFifo(..., capacity=0) rejects empty buffer",
                       sensor.readFifo(samples, 0, invalidCount));
  } else {
    reportSkip("FIFO retrieval and argument validation");
  }

  reportResult("clearFifo(stream)", sensor.clearFifo(stream));
  FifoConfig bypass{false, 0, 0, false};
  reportResult("configureFifo(bypass) cleanup", sensor.configureFifo(bypass));
}

void testFilterAndReferenceApi() {
  Serial.println();
  Serial.println("[TEST] High-pass filter and reference");

  const HighPassConfig filterConfig = {3, 2, true, true, true, true};
  const bool filterOk = sensor.configureHighPassFilter(filterConfig);
  reportResult("configureHighPassFilter()", filterOk);
  if (filterOk) {
    uint8_t ctrl2 = 0;
    const bool readOk = sensor.readRegister(lis3dh::REG_CTRL_REG2, ctrl2);
    const uint8_t expected =
        static_cast<uint8_t>(((filterConfig.hpm & 0x03) << 6) |
                             ((filterConfig.hpcf & 0x03) << 4) |
                             (filterConfig.fds ? 0x08 : 0x00) |
                             (filterConfig.hp_click ? 0x04 : 0x00) |
                             (filterConfig.hp_ia2 ? 0x02 : 0x00) |
                             (filterConfig.hp_ia1 ? 0x01 : 0x00));
    reportResult("CTRL_REG2 high-pass fields read back",
                 readOk && ctrl2 == expected);
  }

  uint8_t originalReference = 0;
  const bool originalOk = sensor.readReference(originalReference);
  reportResult("readReference()", originalOk);
  if (originalOk) {
    Serial.print("  Original reference=0x");
    printHex8(originalReference);
    Serial.println();

    const uint8_t testReference =
        originalReference == 0xA5 ? 0x5A : 0xA5;
    const bool setOk = sensor.setReference(testReference);
    reportResult("setReference(test value)", setOk);
    uint8_t observedReference = 0;
    const bool readBackOk = sensor.readReference(observedReference);
    reportResult("readReference() verifies setReference()",
                 readBackOk && observedReference == testReference);

    const bool restoreOk = sensor.setReference(originalReference);
    reportResult("restore reference", restoreOk);
  } else {
    reportSkip("Reference write and readback");
  }

  const HighPassConfig filterBypass = {0, 0, false, false, false, false};
  reportResult("configureHighPassFilter(bypass) cleanup",
               sensor.configureHighPassFilter(filterBypass));
}

void testInterruptApi() {
  Serial.println();
  Serial.println("[TEST] Interrupt generators, routing, and source registers");

  const InterruptConfig interruptConfig = {0x2A, 0x10, 0x02, true};
  const bool int1Ok = sensor.configureInterruptGenerator(
      InterruptPin::INT1, interruptConfig);
  reportResult("configureInterruptGenerator(INT1)", int1Ok);
  const bool int2Ok = sensor.configureInterruptGenerator(
      InterruptPin::INT2, interruptConfig);
  reportResult("configureInterruptGenerator(INT2)", int2Ok);

  if (int1Ok) {
    uint8_t threshold = 0;
    uint8_t duration = 0;
    const bool readOk = sensor.readRegister(lis3dh::REG_INT1_THS, threshold) &&
                        sensor.readRegister(lis3dh::REG_INT1_DURATION, duration);
    reportResult("INT1 threshold and duration read back",
                 readOk && threshold == interruptConfig.ths &&
                     duration == interruptConfig.dur);
  }
  if (int2Ok) {
    uint8_t threshold = 0;
    uint8_t duration = 0;
    const bool readOk = sensor.readRegister(lis3dh::REG_INT2_THS, threshold) &&
                        sensor.readRegister(lis3dh::REG_INT2_DURATION, duration);
    reportResult("INT2 threshold and duration read back",
                 readOk && threshold == interruptConfig.ths &&
                     duration == interruptConfig.dur);
  }

  InterruptConfig invalid = interruptConfig;
  invalid.ths = 0x80;
  reportExpectedFalse("configureInterruptGenerator() rejects THS bit7",
                     sensor.configureInterruptGenerator(
                         InterruptPin::INT1, invalid));
  invalid = interruptConfig;
  invalid.dur = 0x80;
  reportExpectedFalse("configureInterruptGenerator() rejects DURATION bit7",
                     sensor.configureInterruptGenerator(
                         InterruptPin::INT2, invalid));

  InterruptSource int1Source{};
  const bool int1SourceOk = sensor.readInterruptSource(
      InterruptPin::INT1, int1Source);
  reportResult("readInterruptSource(INT1)", int1SourceOk);
  if (int1SourceOk) {
    printInterruptSource("INT1", int1Source);
  }

  InterruptSource int2Source{};
  const bool int2SourceOk = sensor.readInterruptSource(
      InterruptPin::INT2, int2Source);
  reportResult("readInterruptSource(INT2)", int2SourceOk);
  if (int2SourceOk) {
    printInterruptSource("INT2", int2Source);
  }

  const InterruptRouting routing = {0x0C, 0x60};
  const bool routingOk = sensor.configureInterruptRouting(routing);
  reportResult("configureInterruptRouting()", routingOk);
  if (routingOk) {
    uint8_t ctrl3 = 0;
    uint8_t ctrl6 = 0;
    const bool readOk = sensor.readRegister(lis3dh::REG_CTRL_REG3, ctrl3) &&
                        sensor.readRegister(lis3dh::REG_CTRL_REG6, ctrl6);
    reportResult("interrupt routing registers read back",
                 readOk && ctrl3 == routing.ctrl3 && ctrl6 == routing.ctrl6);
  }

  InterruptRouting invalidRouting = {0x01, 0x00};
  reportExpectedFalse("configureInterruptRouting() rejects CTRL_REG3 bit0",
                     sensor.configureInterruptRouting(invalidRouting));
}

void testClickAndActivityApi() {
  Serial.println();
  Serial.println("[TEST] Click detection and activity configuration");

  const ClickConfig clickConfig = {0x15, 0x08, 0x03, 0x04, 0x08};
  const bool clickOk = sensor.configureClick(clickConfig);
  reportResult("configureClick()", clickOk);
  if (clickOk) {
    uint8_t cfg = 0;
    uint8_t threshold = 0;
    uint8_t timeLimit = 0;
    uint8_t timeLatency = 0;
    uint8_t timeWindow = 0;
    const bool readOk = sensor.readRegister(lis3dh::REG_CLICK_CFG, cfg) &&
                        sensor.readRegister(lis3dh::REG_CLICK_THS, threshold) &&
                        sensor.readRegister(lis3dh::REG_TIME_LIMIT, timeLimit) &&
                        sensor.readRegister(lis3dh::REG_TIME_LATENCY, timeLatency) &&
                        sensor.readRegister(lis3dh::REG_TIME_WINDOW, timeWindow);
    reportResult("click configuration registers read back",
                 readOk && cfg == clickConfig.cfg &&
                     threshold == clickConfig.ths &&
                     timeLimit == clickConfig.tlimit &&
                     timeLatency == clickConfig.tlatency &&
                     timeWindow == clickConfig.twindow);
  }

  ClickSource clickSource{};
  const bool sourceOk = sensor.readClickSource(clickSource);
  reportResult("readClickSource()", sourceOk);
  if (sourceOk) {
    printClickSource(clickSource);
  }

  ClickConfig invalidClick = clickConfig;
  invalidClick.cfg = 0x40;
  reportExpectedFalse("configureClick() rejects reserved CLICK_CFG bits",
                     sensor.configureClick(invalidClick));
  invalidClick = clickConfig;
  invalidClick.tlimit = 0x80;
  reportExpectedFalse("configureClick() rejects TIME_LIMIT bit7",
                     sensor.configureClick(invalidClick));

  const bool activityOk = sensor.configureActivity(0x10, 0x02);
  reportResult("configureActivity()", activityOk);
  if (activityOk) {
    uint8_t threshold = 0;
    uint8_t duration = 0;
    const bool readOk = sensor.readRegister(lis3dh::REG_ACT_THS, threshold) &&
                        sensor.readRegister(lis3dh::REG_ACT_DUR, duration);
    reportResult("activity registers read back",
                 readOk && threshold == 0x10 && duration == 0x02);
  }

  reportExpectedFalse("configureActivity() rejects threshold bit7",
                     sensor.configureActivity(0x80, 0x00));
}

void testRawRegisterApi() {
  Serial.println();
  Serial.println("[TEST] Mapped register access and SDO/SA0 pull-up control");

  uint8_t whoAmI = 0;
  reportResult("readRegister() identity check", sensor.readRegister(
                   lis3dh::REG_WHO_AM_I, whoAmI) && whoAmI == 0x33);

  uint8_t originalReference = 0;
  const bool originalOk = sensor.readReference(originalReference);
  reportResult("readReference() before raw write", originalOk);
  if (originalOk) {
    const uint8_t testValue = originalReference == 0x3C ? 0xC3 : 0x3C;
    const bool writeOk = sensor.writeRegister(
        lis3dh::REG_REFERENCE, testValue);
    reportResult("writeRegister(REFERENCE)", writeOk);

    uint8_t observed = 0;
    const bool readBackOk = sensor.readRegister(
        lis3dh::REG_REFERENCE, observed);
    reportResult("readRegister(REFERENCE) verifies raw write",
                 readBackOk && observed == testValue);
    reportResult("restore raw reference",
                 sensor.writeRegister(lis3dh::REG_REFERENCE,
                                      originalReference));
  } else {
    reportSkip("Raw writable-register round-trip");
  }

  reportExpectedFalse("writeRegister(WHO_AM_I) rejects read-only register",
                     sensor.writeRegister(lis3dh::REG_WHO_AM_I, 0x33));
  reportExpectedFalse("writeRegister(0x00) rejects reserved register",
                     sensor.writeRegister(0x00, 0x00));
  reportExpectedFalse("writeRegister(CTRL_REG0) rejects invalid fixed bits",
                     sensor.writeRegister(lis3dh::REG_CTRL_REG0, 0x00));

  const bool disconnectOk = sensor.setSa0PullupDisconnected(true);
  reportResult("setSa0PullupDisconnected(true)", disconnectOk);
  if (disconnectOk) {
    reportResult("setSa0PullupDisconnected(false) restore",
                 sensor.setSa0PullupDisconnected(false));
  } else {
    reportSkip("SDO/SA0 pull-up restoration");
  }
}

bool restoreMonitoringConfiguration() {
  const MeasurementConfig normal = {
      0x05, false, true, true, true, 0, false, true, false};
  const FifoConfig fifoBypass = {false, 0, 0, false};
  const HighPassConfig filterBypass = {0, 0, false, false, false, false};
  const InterruptRouting routingOff = {0x00, 0x00};
  const InterruptConfig interruptOff = {0x00, 0x00, 0x00, false};
  const ClickConfig clickOff = {0x00, 0x00, 0x00, 0x00, 0x00};

  if (!sensor.configureMeasurement(normal)) {
    return false;
  }
  if (!sensor.configureAuxiliary(true, true)) {
    return false;
  }
  if (!sensor.configureFifo(fifoBypass)) {
    return false;
  }
  if (!sensor.configureHighPassFilter(filterBypass)) {
    return false;
  }
  if (!sensor.configureInterruptRouting(routingOff)) {
    return false;
  }
  if (!sensor.configureInterruptGenerator(InterruptPin::INT1,
                                          interruptOff)) {
    return false;
  }
  if (!sensor.configureInterruptGenerator(InterruptPin::INT2,
                                          interruptOff)) {
    return false;
  }
  if (!sensor.configureClick(clickOff)) {
    return false;
  }
  if (!sensor.configureActivity(0x00, 0x00)) {
    return false;
  }
  if (!sensor.setSelfTest(SelfTestMode::Disabled)) {
    return false;
  }
  return true;
}

bool runFullApiTest() {
  passCount = 0;
  failCount = 0;
  skipCount = 0;

  Serial.println();
  Serial.println("========================================");
  Serial.println("LIS3DH full driver API test");
  Serial.println("========================================");
  Serial.println("All driver and diagnostic text is emitted in English for logging.");

  testIdentificationAndLifecycle();
  testMeasurementApi();
  testAuxiliaryApi();
  testSelfTestApi();
  testFifoApi();
  testFilterAndReferenceApi();
  testInterruptApi();
  testClickAndActivityApi();
  testRawRegisterApi();

  reportResult("restore user-friendly monitoring configuration",
               restoreMonitoringConfiguration());

  Serial.println();
  Serial.println("----------------------------------------");
  Serial.print("API test summary: PASS=");
  Serial.print(passCount);
  Serial.print(" FAIL=");
  Serial.print(failCount);
  Serial.print(" SKIP=");
  Serial.println(skipCount);
  const bool passed = failCount == 0 && skipCount == 0;
  Serial.println(passed ? "[OVERALL] PASS" : "[OVERALL] FAIL");
  Serial.println("----------------------------------------");
  return passed;
}

void printMonitorStatus() {
  AccelerationStatus status{};
  if (sensor.readAccelerationStatus(status)) {
    printAccelerationStatus(status);
  } else {
    Serial.println("  STATUS_REG: READ_ERROR");
  }
}

void runMonitorCycle() {
  Serial.println();
  Serial.println("========================================");
  Serial.println("LIS3DH periodic measurement monitor");
  Serial.println("========================================");

  Acceleration sample{};
  if (sensor.readAcceleration(sample) && accelerationIsFinite(sample)) {
    printAcceleration(sample);
  } else {
    Serial.println("  Acceleration: READ_ERROR");
  }

  printMonitorStatus();

  AuxiliaryData auxiliary{};
  if (sensor.readAuxiliary(auxiliary)) {
    printAuxiliaryData(auxiliary);
  } else {
    Serial.println("  Auxiliary ADC/temperature: READ_ERROR");
  }

  FifoStatus fifo{};
  if (sensor.getFifoStatus(fifo)) {
    printFifoStatus(fifo);
  } else {
    Serial.println("  FIFO status: READ_ERROR");
  }

  InterruptSource int1Source{};
  if (sensor.readInterruptSource(InterruptPin::INT1, int1Source)) {
    printInterruptSource("INT1", int1Source);
  } else {
    Serial.println("  INT1 source: READ_ERROR");
  }

  InterruptSource int2Source{};
  if (sensor.readInterruptSource(InterruptPin::INT2, int2Source)) {
    printInterruptSource("INT2", int2Source);
  } else {
    Serial.println("  INT2 source: READ_ERROR");
  }

  ClickSource clickSource{};
  if (sensor.readClickSource(clickSource)) {
    printClickSource(clickSource);
  } else {
    Serial.println("  CLICK_SRC: READ_ERROR");
  }

  Serial.print("  GPIO");
  Serial.print(INT1_PIN);
  Serial.print(" / INT1 level: ");
  Serial.println(digitalRead(INT1_PIN) == HIGH ? "HIGH" : "LOW");
  Serial.print("  GPIO");
  Serial.print(INT2_PIN);
  Serial.print(" / INT2 level: ");
  Serial.println(digitalRead(INT2_PIN) == HIGH ? "HIGH" : "LOW");
  Serial.println();
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

  pinMode(INT1_PIN, INPUT);
  pinMode(INT2_PIN, INPUT);

  Serial.println();
  Serial.println("LIS3DH RP2040 I2C test");
  Serial.print("I2C SDA GPIO: ");
  Serial.println(I2C_SDA_PIN);
  Serial.print("I2C SCL GPIO: ");
  Serial.println(I2C_SCL_PIN);
  Serial.print("INT1 GPIO: ");
  Serial.println(INT1_PIN);
  Serial.print("INT2 GPIO: ");
  Serial.println(INT2_PIN);
  Serial.print("I2C address: 0x");
  printHex8(LIS3DH_I2C_ADDRESS);
  Serial.println();

  deviceReady = sensor.begin();
  if (deviceReady) {
    Serial.println("LIS3DH: READY");
    runFullApiTest();
    lastFullApiTestMs = millis();
    lastMonitorMs = millis();
  } else {
    Serial.println("LIS3DH: BEGIN_ERROR; retrying periodically");
    lastDeviceRetryMs = millis();
  }
}

void loop() {
  const unsigned long now = millis();

  if (!deviceReady) {
    if (now - lastDeviceRetryMs >= DEVICE_RETRY_INTERVAL_MS) {
      lastDeviceRetryMs = now;
      Serial.println();
      Serial.println("[RETRY] Attempting LIS3DH initialization");
      deviceReady = sensor.begin();
      if (deviceReady) {
        Serial.println("LIS3DH: READY");
        runFullApiTest();
        lastFullApiTestMs = millis();
        lastMonitorMs = millis();
      } else {
        Serial.println("LIS3DH: BEGIN_ERROR");
      }
    }
    return;
  }

  if (now - lastFullApiTestMs >= FULL_API_TEST_INTERVAL_MS) {
    runFullApiTest();
    lastFullApiTestMs = millis();
  }

  if (now - lastMonitorMs >= MONITOR_INTERVAL_MS) {
    runMonitorCycle();
    lastMonitorMs = millis();
  }
}
