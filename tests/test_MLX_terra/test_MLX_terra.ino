#include <Arduino.h>
#include <SPI.h>

#include "MLX90382.h"

// RP2040 SPI pin assignment.
constexpr uint8_t SPI_SCLK_PIN = 2;
constexpr uint8_t SPI_MOSI_PIN = 3;
constexpr uint8_t SPI_MISO_PIN = 4;
constexpr uint8_t MLX_CS1_PIN = 5;
constexpr uint8_t MLX_CS0_PIN = 9;

// The existing board exposes both chip-select lines. A missing device is reported as SKIP.
constexpr bool TEST_CS0 = true;
constexpr bool TEST_CS1 = true;

constexpr uint32_t SPI_CLOCK_HZ = 1000000UL;
constexpr uint32_t CRC_TIMEOUT_MS = 1000UL;
constexpr uint32_t MONITOR_INTERVAL_MS = 2000UL;
constexpr uint32_t MONITOR_CRC_TIMEOUT_MS = 250UL;

// Figure 14 defines the six-bit RR/RW command patterns. Bit 0 selects the 0x200 NVRAM page.
constexpr uint8_t RR_COMMAND_VOLATILE = 0xCC;
constexpr uint8_t RW_COMMAND_VOLATILE = 0x78;
constexpr uint8_t RR_COMMAND_NVRAM = 0xCD;
constexpr uint8_t RW_COMMAND_NVRAM = 0x79;

static const SPISettings mlxSpiSettings(
    SPI_CLOCK_HZ,
    MSBFIRST,
    SPI_MODE0);

uint32_t passCount = 0;
uint32_t failCount = 0;
uint32_t skipCount = 0;
uint32_t validatorReadCount = 0;
uint32_t validatorWriteCount = 0;
uint32_t validatedReadCount = 0;
uint32_t nvramEncoderCallCount = 0;
uint8_t connectedChipCount = 0;
bool spiPinConfigurationOk = false;
bool testExecuted = false;
bool cs0Connected = false;
bool cs1Connected = false;
bool monitorEnabled = false;
uint32_t monitorCycle = 0;
uint32_t nextMonitorAt = 0;

bool encodeNvramAddress(uint16_t logicalAddress, uint8_t& adrByte) {
  ++nvramEncoderCallCount;

  if ((logicalAddress & 0x0001u) != 0u ||
      logicalAddress < 0x0200u ||
      logicalAddress > 0x025Eu) {
    return false;
  }

  // The NVRAM page is selected by command bit 0; ADR carries address bits [8:1].
  adrByte = static_cast<uint8_t>((logicalAddress >> 1) & 0x00FFu);
  return true;
}

bool validateTransaction(
    bool isRead,
    uint16_t logicalAddress,
    const uint8_t* rxBytes,
    size_t rxLength) {
  if (isRead) {
    ++validatorReadCount;
  } else {
    ++validatorWriteCount;
  }

  if (rxBytes == nullptr || rxLength < 4u) {
    return false;
  }

  if (!isRead) {
    return true;
  }

  const bool isNvramAddress = (logicalAddress & 0x0200u) != 0u;
  const uint8_t expectedCommand = static_cast<uint8_t>(
      isNvramAddress ? RR_COMMAND_NVRAM : RR_COMMAND_VOLATILE);
  const uint8_t expectedAddress = static_cast<uint8_t>(
      (logicalAddress >> 1) & 0x00FFu);

  const bool responseMatches =
      rxBytes[1] == expectedCommand && rxBytes[2] == expectedAddress;
  if (responseMatches) {
    ++validatedReadCount;
  }
  return responseMatches;
}

static const SpiProtocol volatileProtocol = {
    RR_COMMAND_VOLATILE,
    RW_COMMAND_VOLATILE,
    true,
    1,
    nullptr,
    validateTransaction};

static const SpiProtocol nvramProtocol = {
    RR_COMMAND_NVRAM,
    RW_COMMAND_NVRAM,
    true,
    1,
    encodeNvramAddress,
    validateTransaction};

MLX90382 sensorVolatileCs0(
    MLX_CS0_PIN,
    mlxSpiSettings,
    volatileProtocol);
MLX90382 sensorNvramCs0(
    MLX_CS0_PIN,
    mlxSpiSettings,
    nvramProtocol);
MLX90382 sensorVolatileCs1(
    MLX_CS1_PIN,
    mlxSpiSettings,
    volatileProtocol);
MLX90382 sensorNvramCs1(
    MLX_CS1_PIN,
    mlxSpiSettings,
    nvramProtocol);

void reportResult(const char* label, bool passed) {
  Serial.print("TEST_LOG:");
  Serial.print(passed ? "[PASS] " : "[FAIL] ");
  Serial.println(label);

  if (passed) {
    ++passCount;
  } else {
    ++failCount;
  }
}

void reportExpectedFalse(const char* label, bool returnedTrue) {
  reportResult(label, !returnedTrue);
}

void reportSkip(const char* label) {
  Serial.print("TEST_LOG:[SKIP] ");
  Serial.println(label);
  ++skipCount;
}

void reportInfo(const char* label) {
  Serial.print("TEST_LOG:[INFO] ");
  Serial.println(label);
}

void printHex16(uint16_t value) {
  if (value < 0x1000u) {
    Serial.print('0');
  }
  if (value < 0x0100u) {
    Serial.print('0');
  }
  if (value < 0x0010u) {
    Serial.print('0');
  }
  Serial.print(value, HEX);
}

void printHex8(uint8_t value) {
  if (value < 0x10u) {
    Serial.print('0');
  }
  Serial.print(value, HEX);
}

const char* stateName(DeviceState state) {
  switch (state) {
    case DeviceState::Normal:
      return "Normal";
    case DeviceState::SS2_NVM:
      return "SS2_NVM";
    case DeviceState::SS2:
      return "SS2";
    case DeviceState::SS3:
      return "SS3";
    default:
      return "Unknown";
  }
}

bool isDocumentedState(DeviceState state) {
  return state == DeviceState::Normal ||
         state == DeviceState::SS2_NVM ||
         state == DeviceState::SS2 ||
         state == DeviceState::SS3;
}

void printMeasurementLine(
    const char* label,
    const Measurement& measurement) {
  Serial.print(label);
  Serial.print(" LIN_PHASE=0x");
  printHex16(measurement.linPhase);
  Serial.print(" SPEED=");
  Serial.print(measurement.speed);
  Serial.print(" AGC_GAIN=");
  Serial.print(measurement.agcGain);
  Serial.print(" AGC_AMP=");
  Serial.print(measurement.agcAmp);
  Serial.print(" TEMP=0x");
  printHex16(measurement.temp);
  Serial.print(" DRIFTC_PHASE=0x");
  printHex16(measurement.driftcPhase);
  Serial.print(" SC_PHASE=0x");
  printHex16(measurement.scPhase);
  Serial.println();
}

void printMeasurement(const Measurement& measurement) {
  printMeasurementLine("TEST_LOG:Measurement", measurement);
}

void printSignalConditioningLine(
    const char* label,
    const SignalConditioningConfig& config) {
  Serial.print(label);
  Serial.print(" SC_X1=0x");
  printHex16(config.sc_x1);
  Serial.print(" SC_X2=0x");
  printHex16(config.sc_x2);
  Serial.print(" SC_Y1=0x");
  printHex16(config.sc_y1);
  Serial.print(" SC_Y2=0x");
  printHex16(config.sc_y2);
  Serial.print(" SC_HL=0x");
  printHex16(config.sc_hl);
  Serial.print(" SC_YE=0x");
  printHex16(config.sc_ye);
  Serial.println();
}

void printSignalConditioning(
    const SignalConditioningConfig& config) {
  printSignalConditioningLine("TEST_LOG:Signal conditioning", config);
}

void printPeqLine(
    const char* label,
    uint8_t gain,
    const int8_t* points) {
  Serial.print(label);
  Serial.print(" gain=");
  Serial.print(gain);
  Serial.print(" points=");
  for (uint8_t i = 0; i < 16u; ++i) {
    if (i != 0u) {
      Serial.print(',');
    }
    Serial.print(static_cast<int>(points[i]));
  }
  Serial.println();
}

void printPeq(uint8_t gain, const int8_t* points) {
  printPeqLine("TEST_LOG:PEQ", gain, points);
}

void testInputValidation(
    MLX90382& volatileSensor,
    MLX90382& nvramSensor) {
  Serial.println("TEST_LOG:[TEST] Input validation and unconfigured frame state");

  uint16_t value = 0;
  reportExpectedFalse(
      "readRegister(odd address) rejects input",
      volatileSensor.readRegister(MLXReg::STATE + 1u, value));
  reportExpectedFalse(
      "writeRegister(odd address) rejects input",
      volatileSensor.writeRegister(MLXReg::STATE + 1u, 0u));
  reportExpectedFalse(
      "readRegister(NVRAM address) rejects missing encoder",
      volatileSensor.readRegister(MLXReg::USER_ID0, value));
  reportExpectedFalse(
      "writeRegister(NVRAM address) rejects missing encoder",
      volatileSensor.writeRegister(MLXReg::USER_ID0, 0u));

  int8_t points[16] = {};
  uint8_t invalidGain = 0;
  reportExpectedFalse(
      "setPeq(nullptr) rejects a null point buffer",
      nvramSensor.setPeq(0u, nullptr));
  reportExpectedFalse(
      "setPeq(gain 8) rejects an out-of-range gain",
      nvramSensor.setPeq(8u, points));
  reportExpectedFalse(
      "getPeq(nullptr) rejects a null point buffer",
      nvramSensor.getPeq(invalidGain, nullptr));
  reportExpectedFalse(
      "setCustomerId(index 6) rejects an invalid index",
      nvramSensor.setCustomerId(6u, 0u));

  size_t receivedLength = 99u;
  uint8_t frameBuffer[16] = {};
  reportResult(
      "frameLength() is zero before configuration",
      nvramSensor.frameLength() == 0u);
  reportResult(
      "readFrame() rejects an unconfigured frame",
      !nvramSensor.readFrame(
          frameBuffer,
          sizeof(frameBuffer),
          receivedLength) &&
          receivedLength == 0u);
  reportResult(
      "readFrame(nullptr) rejects an unconfigured frame",
      !nvramSensor.readFrame(nullptr, 0u, receivedLength) &&
          receivedLength == 0u);
}

void testVolatileRegisterAccess(
    const char* chipLabel,
    MLX90382& sensor) {
  Serial.print("TEST_LOG:[TEST] ");
  Serial.print(chipLabel);
  Serial.println(" generic volatile register access");

  uint16_t stateRaw = 0;
  const bool readStateRegisterOk =
      sensor.readRegister(MLXReg::STATE, stateRaw);
  reportResult("readRegister(STATE)", readStateRegisterOk);
  if (readStateRegisterOk) {
    Serial.print("TEST_LOG:STATE raw=0x");
    printHex16(stateRaw);
    Serial.println();
  }

  uint16_t applicationRaw = 0;
  const bool readApplicationOk =
      sensor.readRegister(MLXReg::IN_APPLICATION, applicationRaw);
  reportResult("readRegister(IN_APPLICATION)", readApplicationOk);
  if (readApplicationOk) {
    reportResult(
        "writeRegister(IN_APPLICATION, unchanged value)",
        sensor.writeRegister(MLXReg::IN_APPLICATION, applicationRaw));

    uint16_t observedApplicationRaw = 0;
    reportResult(
        "readRegister(IN_APPLICATION) after unchanged write",
        sensor.readRegister(
            MLXReg::IN_APPLICATION,
            observedApplicationRaw) &&
            observedApplicationRaw == applicationRaw);
  }
}

void testMeasurements(
    const char* chipLabel,
    MLX90382& sensor) {
  Serial.print("TEST_LOG:[TEST] ");
  Serial.print(chipLabel);
  Serial.println(" measurements");

  Measurement measurement = {};
  const bool readOk = sensor.readMeasurements(measurement);
  reportResult("readMeasurements()", readOk);
  if (!readOk) {
    return;
  }

  printMeasurement(measurement);
  reportResult(
      "readMeasurements() applies documented field widths",
      measurement.agcGain <= 0x003Fu &&
          measurement.agcAmp <= 0x1FFFu &&
          measurement.temp <= 0x0FFFu);
}

void testState(
    const char* chipLabel,
    MLX90382& sensor) {
  Serial.print("TEST_LOG:[TEST] ");
  Serial.print(chipLabel);
  Serial.println(" state decoding");

  DeviceState state = DeviceState::Unknown;
  const bool readOk = sensor.readState(state);
  reportResult("readState()", readOk);
  if (readOk) {
    Serial.print("TEST_LOG:Decoded state=");
    Serial.println(stateName(state));
    reportResult("readState() returns a documented state", isDocumentedState(state));
  }
}

void testCrc(
    const char* chipLabel,
    MLX90382& sensor) {
  Serial.print("TEST_LOG:[TEST] ");
  Serial.print(chipLabel);
  Serial.println(" NVRAM CRC calculation");

  const bool startOk = sensor.startCrcCalculation();
  reportResult("startCrcCalculation()", startOk);
  if (!startOk) {
    reportSkip("readCrcWhenReady() because CRC calculation did not start");
    return;
  }

  uint16_t crc = 0;
  const bool readyOk = sensor.readCrcWhenReady(CRC_TIMEOUT_MS, crc);
  reportResult("readCrcWhenReady(1000 ms)", readyOk);
  if (readyOk) {
    Serial.print("TEST_LOG:CRC=0x");
    printHex16(crc);
    Serial.println();
  }
}

void testNVRAMReads(
    const char* chipLabel,
    MLX90382& sensor) {
  Serial.print("TEST_LOG:[TEST] ");
  Serial.print(chipLabel);
  Serial.println(" NVRAM register reads");

  uint16_t userIdWord = 0;
  const bool userIdOk = sensor.readRegister(MLXReg::USER_ID0, userIdWord);
  reportResult("readRegister(USER_ID0)", userIdOk);
  if (userIdOk) {
    Serial.print("TEST_LOG:USER_ID0/1=0x");
    printHex16(userIdWord);
    Serial.println();
  }

  uint16_t frameRegister = 0;
  reportResult(
      "readRegister(SPI_FRFS)",
      sensor.readRegister(MLXReg::SPI_FRFS, frameRegister));

  SignalConditioningConfig signalConditioning = {};
  const bool signalConditioningOk =
      sensor.getSignalConditioning(signalConditioning);
  reportResult("getSignalConditioning()", signalConditioningOk);
  if (signalConditioningOk) {
    printSignalConditioning(signalConditioning);
    reportResult(
        "getSignalConditioning() masks SC_HL to nine bits",
        signalConditioning.sc_hl <= 0x01FFu);
  }

  uint8_t gain = 0;
  int8_t points[16] = {};
  const bool peqOk = sensor.getPeq(gain, points);
  reportResult("getPeq()", peqOk);
  if (peqOk) {
    printPeq(gain, points);
    reportResult("getPeq() returns a documented gain range", gain <= 7u);
  }
}

void testFrameReadGuards(
    const char* chipLabel,
    MLX90382& sensor) {
  Serial.print("TEST_LOG:[TEST] ");
  Serial.print(chipLabel);
  Serial.println(" frame-read guards");

  reportResult(
      "frameLength() remains zero without configuration",
      sensor.frameLength() == 0u);

  size_t receivedLength = 17u;
  uint8_t frameBuffer[16] = {};
  reportResult(
      "readFrame() rejects a missing frame configuration",
      !sensor.readFrame(
          frameBuffer,
          sizeof(frameBuffer),
          receivedLength) &&
          receivedLength == 0u);
}

void reportSkippedWriteApis() {
  reportSkip(
      "configureFrameRead() valid path requires NVRAM writes and is disabled");
  reportSkip(
      "frameLength() configured calculation is not executed without NVRAM writes");
  reportSkip(
      "readFrame() successful transfer is not executed without frame configuration");
  reportSkip(
      "setSignalConditioning() valid write is disabled to preserve NVRAM");
  reportSkip(
      "setPwmConfig() valid write is disabled to preserve NVRAM");
  reportSkip(
      "setPeq() valid write is disabled to preserve calibration data");
  reportSkip(
      "setSafetyMonitorDisableMask() is disabled because it changes safety monitoring");
  reportSkip(
      "setCustomerId() valid write is disabled because it changes traceability data");
}

void reportMonitorCheck(
    const char* label,
    bool passed,
    uint8_t& localPassCount,
    uint8_t& localFailCount) {
  Serial.print("TEST_LOG:    ");
  Serial.print(passed ? "[PASS] " : "[FAIL] ");
  Serial.println(label);

  if (passed) {
    ++localPassCount;
  } else {
    ++localFailCount;
  }
}

bool monitorChip(
    const char* chipLabel,
    MLX90382& volatileSensor,
    MLX90382& nvramSensor) {
  Serial.print("TEST_LOG:  Device: ");
  Serial.println(chipLabel);

  uint16_t stateRaw = 0;
  const bool stateRegisterOk =
      volatileSensor.readRegister(MLXReg::STATE, stateRaw);

  uint16_t applicationRaw = 0;
  const bool applicationRegisterOk =
      volatileSensor.readRegister(MLXReg::IN_APPLICATION, applicationRaw);

  Measurement measurement = {};
  const bool measurementReadOk = volatileSensor.readMeasurements(measurement);
  const bool measurementFieldsOk =
      measurementReadOk &&
      measurement.agcGain <= 0x003Fu &&
      measurement.agcAmp <= 0x1FFFu &&
      measurement.temp <= 0x0FFFu;

  DeviceState state = DeviceState::Unknown;
  const bool stateReadOk = volatileSensor.readState(state);
  const bool documentedStateOk = stateReadOk && isDocumentedState(state);

  uint16_t userIdWord = 0;
  const bool userIdOk = nvramSensor.readRegister(MLXReg::USER_ID0, userIdWord);

  uint16_t frameRegister = 0;
  const bool frameRegisterOk =
      nvramSensor.readRegister(MLXReg::SPI_FRFS, frameRegister);

  SignalConditioningConfig signalConditioning = {};
  const bool signalConditioningReadOk =
      nvramSensor.getSignalConditioning(signalConditioning);
  const bool signalConditioningFieldsOk =
      signalConditioningReadOk && signalConditioning.sc_hl <= 0x01FFu;

  uint8_t gain = 0;
  int8_t points[16] = {};
  const bool peqReadOk = nvramSensor.getPeq(gain, points);
  const bool peqFieldsOk = peqReadOk && gain <= 7u;

  uint16_t crc = 0;
  const bool crcStartOk = volatileSensor.startCrcCalculation();
  const bool crcReadyOk =
      crcStartOk &&
      volatileSensor.readCrcWhenReady(MONITOR_CRC_TIMEOUT_MS, crc);

  uint8_t localPassCount = 0;
  uint8_t localFailCount = 0;
  reportMonitorCheck(
      "readRegister(STATE)",
      stateRegisterOk,
      localPassCount,
      localFailCount);
  reportMonitorCheck(
      "readRegister(IN_APPLICATION)",
      applicationRegisterOk,
      localPassCount,
      localFailCount);
  reportMonitorCheck(
      "readMeasurements() and field widths",
      measurementFieldsOk,
      localPassCount,
      localFailCount);
  reportMonitorCheck(
      "readState() and documented state value",
      documentedStateOk,
      localPassCount,
      localFailCount);
  reportMonitorCheck(
      "readRegister(USER_ID0)",
      userIdOk,
      localPassCount,
      localFailCount);
  reportMonitorCheck(
      "readRegister(SPI_FRFS)",
      frameRegisterOk,
      localPassCount,
      localFailCount);
  reportMonitorCheck(
      "getSignalConditioning() and field widths",
      signalConditioningFieldsOk,
      localPassCount,
      localFailCount);
  reportMonitorCheck(
      "getPeq() and documented gain range",
      peqFieldsOk,
      localPassCount,
      localFailCount);
  reportMonitorCheck(
      "startCrcCalculation()",
      crcStartOk,
      localPassCount,
      localFailCount);
  reportMonitorCheck(
      "readCrcWhenReady()",
      crcReadyOk,
      localPassCount,
      localFailCount);

  if (measurementReadOk) {
    printMeasurementLine("TEST_LOG:  Measurement", measurement);
  }
  if (stateReadOk) {
    Serial.print("TEST_LOG:  State: ");
    Serial.print(stateName(state));
    Serial.print(" (raw=0x");
    printHex16(stateRaw);
    Serial.println(")");
  }
  if (crcReadyOk) {
    Serial.print("TEST_LOG:  CRC: 0x");
    printHex16(crc);
    Serial.println();
  }
  if (userIdOk) {
    Serial.print("TEST_LOG:  USER_ID0/1: 0x");
    printHex16(userIdWord);
    Serial.println();
  }
  if (frameRegisterOk) {
    Serial.print("TEST_LOG:  SPI_FRFS: 0x");
    printHex16(frameRegister);
    Serial.println();
  }
  if (signalConditioningReadOk) {
    printSignalConditioningLine(
        "TEST_LOG:  Signal conditioning",
        signalConditioning);
  }
  if (peqReadOk) {
    printPeqLine("TEST_LOG:  PEQ", gain, points);
  }

  Serial.print("TEST_LOG:  Checklist summary: PASS=");
  Serial.print(localPassCount);
  Serial.print(" FAIL=");
  Serial.println(localFailCount);
  return localFailCount == 0u;
}

void runMonitorCycle() {
  ++monitorCycle;

  Serial.println();
  Serial.println("TEST_LOG:================================================");
  Serial.print("TEST_LOG:Live monitor cycle #");
  Serial.print(monitorCycle);
  Serial.print(" | uptime=");
  Serial.print(millis() / 1000UL);
  Serial.println(" s");
  Serial.println(
      "TEST_LOG:Full-test baseline: PASS/FAIL/SKIP counters are from RUN_TEST");
  Serial.print("TEST_LOG:  PASS=");
  Serial.print(passCount);
  Serial.print(" FAIL=");
  Serial.print(failCount);
  Serial.print(" SKIP=");
  Serial.println(skipCount);
  Serial.println(
      "TEST_LOG:Read-only live checklist; configuration and NVRAM writes are not repeated");

  bool allDevicesPassed = true;
  uint8_t monitoredDeviceCount = 0;

  if (cs0Connected) {
    allDevicesPassed =
        monitorChip("MLX90382 CS0", sensorVolatileCs0, sensorNvramCs0) &&
        allDevicesPassed;
    ++monitoredDeviceCount;
  }
  if (cs1Connected) {
    allDevicesPassed =
        monitorChip("MLX90382 CS1", sensorVolatileCs1, sensorNvramCs1) &&
        allDevicesPassed;
    ++monitoredDeviceCount;
  }

  Serial.print("TEST_LOG:Monitor summary: devices=");
  Serial.print(monitoredDeviceCount);
  Serial.print(" status=");
  Serial.println(allDevicesPassed ? "PASS" : "FAIL");
  Serial.print("TEST_MONITOR_RESULT:");
  Serial.println(allDevicesPassed ? "PASS" : "FAIL");
  Serial.println("TEST_LOG:Next monitor update in 2 seconds");
}

void startMonitor() {
  if (!testExecuted) {
    Serial.println("TEST_LOG:[INFO] Run RUN_TEST before starting the monitor");
    return;
  }
  if (connectedChipCount == 0u) {
    Serial.println(
        "TEST_LOG:[INFO] Monitor not started because no chip responded");
    return;
  }

  monitorEnabled = true;
  monitorCycle = 0;
  nextMonitorAt = millis() + MONITOR_INTERVAL_MS;
  Serial.println(
      "TEST_LOG:[INFO] Live monitor started; interval=2 seconds");
}

void stopMonitor() {
  monitorEnabled = false;
  Serial.println("TEST_LOG:[INFO] Live monitor stopped");
}

void printHelp() {
  Serial.println("TEST_LOG:Commands:");
  Serial.println("TEST_LOG:  RUN_TEST       - run the full API test once");
  Serial.println("TEST_LOG:  START_MONITOR  - start periodic read-only monitoring");
  Serial.println("TEST_LOG:  STOP_MONITOR   - stop periodic monitoring");
  Serial.println("TEST_LOG:  HELP           - show this command list");
}

bool testChip(
    const char* chipLabel,
    MLX90382& volatileSensor,
    MLX90382& nvramSensor) {
  Serial.print("TEST_LOG:[TEST] Starting ");
  Serial.println(chipLabel);

  const bool beginOk = volatileSensor.begin() && nvramSensor.begin();
  reportResult("begin() initializes the chip-select line", beginOk);
  if (!beginOk) {
    return false;
  }

  DeviceState probeState = DeviceState::Unknown;
  if (!volatileSensor.readState(probeState)) {
    Serial.print("TEST_LOG:[SKIP] ");
    Serial.print(chipLabel);
    Serial.println(" did not respond to the validated SPI probe");
    ++skipCount;
    return false;
  }

  ++connectedChipCount;
  testVolatileRegisterAccess(chipLabel, volatileSensor);
  testMeasurements(chipLabel, volatileSensor);
  testState(chipLabel, volatileSensor);
  testCrc(chipLabel, volatileSensor);
  testNVRAMReads(chipLabel, nvramSensor);
  testFrameReadGuards(chipLabel, nvramSensor);
  return true;
}

bool runFullApiTest() {
  passCount = 0;
  failCount = 0;
  skipCount = 0;
  validatorReadCount = 0;
  validatorWriteCount = 0;
  validatedReadCount = 0;
  nvramEncoderCallCount = 0;
  connectedChipCount = 0;
  cs0Connected = false;
  cs1Connected = false;
  monitorEnabled = false;
  monitorCycle = 0;
  nextMonitorAt = 0;

  Serial.println("TEST_LOG:========================================");
  Serial.println("TEST_LOG:MLX90382 driver API coverage test");
  Serial.println("TEST_LOG:========================================");
  Serial.println("TEST_LOG:SPI uses GPIO2/GPIO3/GPIO4 and SPI mode 0 at 1 MHz");
  Serial.println("TEST_LOG:CS0=GPIO9, CS1=GPIO5");

  reportResult("RP2040 SPI pin configuration", spiPinConfigurationOk);
  testInputValidation(sensorVolatileCs0, sensorNvramCs0);

  if (TEST_CS0) {
    cs0Connected =
        testChip("MLX90382 CS0", sensorVolatileCs0, sensorNvramCs0);
  } else {
    reportSkip("CS0 test disabled by configuration");
  }

  if (TEST_CS1) {
    cs1Connected =
        testChip("MLX90382 CS1", sensorVolatileCs1, sensorNvramCs1);
  } else {
    reportSkip("CS1 test disabled by configuration");
  }

  reportResult(
      "at least one MLX90382 responded to the SPI probe",
      connectedChipCount > 0u);
  reportResult(
      "TransactionValidator received register-read callbacks",
      validatorReadCount > 0u && validatedReadCount > 0u);
  reportResult(
      "TransactionValidator received register-write callbacks",
      validatorWriteCount > 0u);
  reportResult(
      "NVRAM AddressEncoder was used",
      nvramEncoderCallCount > 0u);

  reportSkippedWriteApis();

  Serial.println("TEST_LOG:----------------------------------------");
  Serial.print("TEST_LOG:PASS=");
  Serial.print(passCount);
  Serial.print(" FAIL=");
  Serial.print(failCount);
  Serial.print(" SKIP=");
  Serial.println(skipCount);
  Serial.println("TEST_LOG:----------------------------------------");

  return failCount == 0u && connectedChipCount > 0u;
}

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1000);

  const unsigned long serialStart = millis();
  while (!Serial && (millis() - serialStart < 3000UL)) {
    delay(10);
  }

  pinMode(MLX_CS0_PIN, OUTPUT);
  pinMode(MLX_CS1_PIN, OUTPUT);
  digitalWrite(MLX_CS0_PIN, HIGH);
  digitalWrite(MLX_CS1_PIN, HIGH);

  const bool sclkOk = SPI.setSCK(SPI_SCLK_PIN);
  const bool mosiOk = SPI.setTX(SPI_MOSI_PIN);
  const bool misoOk = SPI.setRX(SPI_MISO_PIN);
  spiPinConfigurationOk = sclkOk && mosiOk && misoOk;

  SPI.begin();

  Serial.println("TEST_LOG:MLX90382 test sketch ready");
  Serial.println("TEST_LOG:Send RUN_TEST to execute the full hardware test");
  Serial.println(
      "TEST_LOG:After RUN_TEST, a user-friendly read-only monitor runs every 2 seconds");
  printHelp();
}

void handleSerialCommand() {
  if (Serial.available() == 0) {
    return;
  }

  String command = Serial.readStringUntil('\n');
  command.trim();

  if (command == "RUN_TEST") {
    if (testExecuted) {
      Serial.println(
          "TEST_LOG:[INFO] Full test already executed; use START_MONITOR or STOP_MONITOR");
      return;
    }

    testExecuted = true;
    const bool passed = runFullApiTest();
    Serial.println(passed ? "TEST_RESULT:PASS" : "TEST_RESULT:FAIL");
    if (connectedChipCount > 0u) {
      startMonitor();
    } else {
      Serial.println(
          "TEST_LOG:[INFO] Live monitor is unavailable because no chip responded");
    }
    Serial.flush();
    return;
  }

  if (command == "START_MONITOR") {
    startMonitor();
    return;
  }

  if (command == "STOP_MONITOR") {
    stopMonitor();
    return;
  }

  if (command == "HELP") {
    printHelp();
    return;
  }

  Serial.println("TEST_LOG:[INFO] Unknown command; use HELP for the command list");
}

void loop() {
  handleSerialCommand();

  if (!monitorEnabled) {
    return;
  }

  const uint32_t now = millis();
  if (static_cast<int32_t>(now - nextMonitorAt) < 0) {
    return;
  }

  runMonitorCycle();
  nextMonitorAt = millis() + MONITOR_INTERVAL_MS;
}
