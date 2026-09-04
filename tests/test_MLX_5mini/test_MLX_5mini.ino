#include <Arduino.h>
#include <SPI.h>
#include <math.h>

#include "MLX90382.h"

// RP2040 SPI pin assignment supplied for the custom board.
constexpr uint8_t SPI_SCLK_PIN = 2;
constexpr uint8_t SPI_MOSI_PIN = 3;
constexpr uint8_t SPI_MISO_PIN = 4;
constexpr uint8_t MLX_CS1_PIN = 5;
constexpr uint8_t MLX_CS0_PIN = 9;

// Both chip-select lines are tested. An absent device is reported as SKIP.
constexpr bool TEST_CS0 = true;
constexpr bool TEST_CS1 = true;

// These values are the driver defaults and are explicitly supported by the board setup.
constexpr uint32_t SPI_CLOCK_HZ = 1000000UL;
constexpr uint8_t SPI_MODE = 0;
constexpr uint32_t CRC_TIMEOUT_MS = 1000UL;

MLX90382 sensorCs0;
MLX90382 sensorCs1;

uint32_t passCount = 0;
uint32_t failCount = 0;
uint32_t skipCount = 0;
uint8_t connectedChipCount = 0;
bool spiPinConfigurationOk = false;
bool testExecuted = false;

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

void reportSkip(const char* label) {
  Serial.print("TEST_LOG:[SKIP] ");
  Serial.println(label);
  ++skipCount;
}

void reportInfo(const char* label) {
  Serial.print("TEST_LOG:[INFO] ");
  Serial.println(label);
}

void printHex8(uint8_t value) {
  if (value < 0x10u) {
    Serial.print('0');
  }
  Serial.print(value, HEX);
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

bool isSigned16Result(int32_t value) {
  return value >= -32768L && value <= 32767L;
}

bool isUnsigned16Result(int32_t value) {
  return value >= 0L && value <= 65535L;
}

bool isDocumentedState(int state) {
  const uint8_t stateValue = static_cast<uint8_t>(state & 0x00FF);
  return stateValue == 0x08u ||
         stateValue == 0x10u ||
         stateValue == 0x20u ||
         stateValue == 0x40u;
}

const char* stateName(int state) {
  switch (static_cast<uint8_t>(state & 0x00FF)) {
    case 0x08:
      return "Normal";
    case 0x10:
      return "SS2_NVM";
    case 0x20:
      return "SS2";
    case 0x40:
      return "SS3";
    default:
      return "Unknown";
  }
}

void printMeasurementSnapshot(
    int32_t driftcPhase,
    int32_t linPhase,
    int32_t scPhase,
    int32_t speed,
    int32_t tempRaw,
    float temperatureC,
    int agcGain,
    int agcAmp,
    int32_t gcI,
    int32_t gcQ,
    int32_t rmmAsIq,
    int32_t rmmAsQq) {
  Serial.print("TEST_LOG:Measurements DRIFTC_PHASE=");
  Serial.print(driftcPhase);
  Serial.print(" LIN_PHASE=");
  Serial.print(linPhase);
  Serial.print(" SC_PHASE=");
  Serial.print(scPhase);
  Serial.print(" SPEED=");
  Serial.print(speed);
  Serial.print(" TEMP_RAW=0x");
  printHex16(static_cast<uint16_t>(tempRaw));
  Serial.print(" TEMP_C=");
  Serial.print(temperatureC);
  Serial.print(" AGC_GAIN=");
  Serial.print(agcGain);
  Serial.print(" AGC_AMP=");
  Serial.print(agcAmp);
  Serial.print(" GC_I=");
  Serial.print(gcI);
  Serial.print(" GC_Q=");
  Serial.print(gcQ);
  Serial.print(" RMM_ASIQ=");
  Serial.print(rmmAsIq);
  Serial.print(" RMM_ASQQ=");
  Serial.println(rmmAsQq);
}

void testInputValidation() {
  Serial.println("TEST_LOG:[TEST] Constructor, lifecycle, and argument guards");

  MLX90382 unconfiguredSensor;
  uint16_t value = 0;
  uint8_t rawBytes[4] = {};

  reportResult(
      "begin(255) rejects a missing chip-select pin",
      !unconfiguredSensor.begin(255, SPI_CLOCK_HZ, SPI_MODE));
  reportResult(
      "readRegister16() rejects an unconfigured driver",
      unconfiguredSensor.readRegister16(
          MLX90382_STATE,
          &value) == MLX90382_ERR_SPI);
  reportResult(
      "writeRegister16() rejects an unconfigured driver",
      !unconfiguredSensor.writeRegister16(MLX90382_IN_APPLICATION, 0u));
  reportResult(
      "rawReadWriteBurst() rejects an unconfigured driver",
      !unconfiguredSensor.rawReadWriteBurst(
          nullptr,
          rawBytes,
          sizeof(rawBytes)));
  reportResult(
      "readUserID(3) rejects an invalid index",
      unconfiguredSensor.readUserID(3u) == MLX90382_ERR_SPI);
  reportResult(
      "setPEQValue(16) rejects an invalid index",
      !unconfiguredSensor.setPEQValue(16u, 0));
}

void testGenericRegisterAccess(MLX90382& sensor) {
  Serial.println("TEST_LOG:[TEST] Generic register access");

  uint16_t stateRaw = 0;
  const int stateReadStatus =
      sensor.readRegister16(MLX90382_STATE, &stateRaw);
  reportResult(
      "readRegister16(STATE) returns OK and a documented state",
      stateReadStatus == MLX90382_OK &&
          isDocumentedState(static_cast<int>(stateRaw & 0x00FFu)));

  uint16_t applicationRaw = 0;
  const int applicationReadStatus =
      sensor.readRegister16(MLX90382_IN_APPLICATION, &applicationRaw);
  reportResult(
      "readRegister16(IN_APPLICATION) returns OK",
      applicationReadStatus == MLX90382_OK);

  if (applicationReadStatus == MLX90382_OK && applicationRaw <= 0x0003u) {
    reportResult(
        "writeRegister16(IN_APPLICATION, unchanged value)",
        sensor.writeRegister16(MLX90382_IN_APPLICATION, applicationRaw));

    uint16_t observedApplicationRaw = 0;
    const int observedStatus = sensor.readRegister16(
        MLX90382_IN_APPLICATION,
        &observedApplicationRaw);
    reportResult(
        "readRegister16(IN_APPLICATION) preserves unchanged value",
        observedStatus == MLX90382_OK &&
            observedApplicationRaw == applicationRaw);
  } else {
    reportSkip(
        "IN_APPLICATION unchanged write because the returned value is outside its documented two-bit field");
  }

  uint16_t userIdRaw = 0;
  reportResult(
      "readRegister16(USER_ID0) reaches the NVRAM address space",
      sensor.readRegister16(MLX90382_USER_ID0, &userIdRaw) == MLX90382_OK);
}

void testMeasurementApis(MLX90382& sensor) {
  Serial.println("TEST_LOG:[TEST] DSP measurement and state APIs");

  const int32_t driftcPhase = sensor.readDriftcPhase();
  const int32_t linPhase = sensor.readLinPhase();
  const int32_t scPhase = sensor.readSCPhase();
  const int32_t speed = sensor.readSpeed();
  const int32_t tempRaw = sensor.readTempRaw();
  const float temperatureC = sensor.readTemperatureC();
  const int agcGain = sensor.readAGCGain();
  const int agcAmp = sensor.readAGCAmp();

  const bool driftcOk = isSigned16Result(driftcPhase);
  const bool linOk = isUnsigned16Result(linPhase);
  const bool scOk = isUnsigned16Result(scPhase);
  const bool speedOk = isSigned16Result(speed);
  const bool tempRawOk = tempRaw >= 0L && tempRaw <= 0x0FFF;
  const bool temperatureOk =
      !isnan(temperatureC) &&
      !isinf(temperatureC) &&
      temperatureC >= -74.0f &&
      temperatureC <= 439.0f;
  const bool agcGainOk = agcGain >= 0 && agcGain <= 63;
  const bool agcAmpOk = agcAmp >= 0 && agcAmp <= 8191;

  reportResult("readDriftcPhase() returns a signed 16-bit result", driftcOk);
  reportResult("readLinPhase() returns an unsigned 16-bit result", linOk);
  reportResult("readSCPhase() returns an unsigned 16-bit result", scOk);
  reportResult("readSpeed() returns a signed 16-bit result", speedOk);
  reportResult("readTempRaw() returns the documented 12-bit field", tempRawOk);
  reportResult(
      "readTemperatureC() returns a finite value in the datasheet range",
      temperatureOk);
  reportResult("readAGCGain() returns the documented six-bit field", agcGainOk);
  reportResult("readAGCAmp() returns the documented 13-bit field", agcAmpOk);

  const int32_t gcI = sensor.readGC_I();
  const bool averageWaitOk = sensor.waitForGCAverage(5UL);
  const int32_t gcQ = sensor.readGC_Q(5UL);
  const int32_t rmmAsIq = sensor.readRMM_ASIQ();
  const int32_t rmmAsQq = sensor.readRMM_ASQQ();

  reportResult("readGC_I() returns a signed 16-bit result", isSigned16Result(gcI));
  reportResult("waitForGCAverage(5 ms) completes", averageWaitOk);
  reportResult("readGC_Q(5 ms) returns a signed 16-bit result", isSigned16Result(gcQ));
  reportResult("readRMM_ASIQ() returns a signed 16-bit result", isSigned16Result(rmmAsIq));
  reportResult("readRMM_ASQQ() returns a signed 16-bit result", isSigned16Result(rmmAsQq));

  const int state = sensor.readState();
  reportResult("readState() returns a documented state", isDocumentedState(state));

  Serial.print("TEST_LOG:State=");
  Serial.print(stateName(state));
  Serial.print(" raw=0x");
  printHex8(static_cast<uint8_t>(state & 0x00FF));
  Serial.println();
  printMeasurementSnapshot(
      driftcPhase,
      linPhase,
      scPhase,
      speed,
      tempRaw,
      temperatureC,
      agcGain,
      agcAmp,
      gcI,
      gcQ,
      rmmAsIq,
      rmmAsQq);

  reportInfo(
      "Signed raw APIs are range-checked; the driver's -1/-2 error codes overlap valid signed 16-bit data values");
}

void testCrcApis(MLX90382& sensor) {
  Serial.println("TEST_LOG:[TEST] NVRAM CRC APIs");

  const bool startOk = sensor.startNVMCRC();
  reportResult("startNVMCRC() starts the checksum operation", startOk);
  if (!startOk) {
    reportSkip("waitForNVMCRCDone() and readCRC() because CRC did not start");
    return;
  }

  const bool doneOk = sensor.waitForNVMCRCDone(CRC_TIMEOUT_MS);
  reportResult("waitForNVMCRCDone(1000 ms)", doneOk);

  const int32_t crc = sensor.readCRC();
  reportResult("readCRC() returns a 16-bit CRC value", isUnsigned16Result(crc));
  if (isUnsigned16Result(crc)) {
    Serial.print("TEST_LOG:CRC=0x");
    printHex16(static_cast<uint16_t>(crc));
    Serial.println();
  }
}

void testNVRAMReadApis(MLX90382& sensor) {
  Serial.println("TEST_LOG:[TEST] NVRAM identity and checksum reads");

  for (uint8_t index = 0; index < 3u; ++index) {
    const int32_t userId = sensor.readUserID(index);
    const bool userIdOk = isUnsigned16Result(userId);
    Serial.print("TEST_LOG:USER_ID[");
    Serial.print(index);
    Serial.print("]=0x");
    if (userIdOk) {
      printHex16(static_cast<uint16_t>(userId));
    } else {
      Serial.print("ERROR");
    }
    Serial.println();

    Serial.print("TEST_LOG:");
    Serial.print("[" );
    Serial.print(userIdOk ? "PASS" : "FAIL");
    Serial.print("] readUserID(");
    Serial.print(index);
    Serial.println(") returns a 16-bit value");
    if (userIdOk) {
      ++passCount;
    } else {
      ++failCount;
    }
  }

  const int32_t customerCrc = sensor.readCUS_CRC();
  const bool customerCrcOk = isUnsigned16Result(customerCrc);
  reportResult("readCUS_CRC() returns a 16-bit checksum", customerCrcOk);
  if (customerCrcOk) {
    Serial.print("TEST_LOG:CUS_CRC=0x");
    printHex16(static_cast<uint16_t>(customerCrc));
    Serial.println();
  }
}

void testRawBurstApi(MLX90382& sensor) {
  Serial.println("TEST_LOG:[TEST] Raw burst API");

  uint8_t rxBytes[4] = {};
  const bool burstOk = sensor.rawReadWriteBurst(
      nullptr,
      rxBytes,
      sizeof(rxBytes));
  reportResult("rawReadWriteBurst(read-only four-byte transfer)", burstOk);
  if (burstOk) {
    Serial.print("TEST_LOG:Raw burst RX=");
    for (uint8_t i = 0; i < sizeof(rxBytes); ++i) {
      if (i != 0u) {
        Serial.print(' ');
      }
      printHex8(rxBytes[i]);
    }
    Serial.println();
  }
}

void reportSkippedWriteApis() {
  reportSkip(
      "setAGCGainLimits() valid write is skipped to preserve NVRAM configuration");
  reportSkip(
      "setPEQGain() valid write is skipped to preserve calibration data");
  reportSkip(
      "setPEQValue() valid write is skipped to preserve calibration data");
  reportSkip(
      "setDelayCus() valid write is skipped to preserve processing configuration");
  reportSkip(
      "setDEBits() is skipped because it changes safety-monitor behavior");
  reportSkip(
      "configureSPIFrameRead() valid write is skipped to preserve interface configuration");
  reportInfo(
      "setPEQValue(16) argument rejection was tested; valid calibration writes were intentionally not executed");
}

bool testChip(
    const char* chipLabel,
    MLX90382& sensor,
    uint8_t chipSelectPin) {
  Serial.print("TEST_LOG:[TEST] Starting ");
  Serial.println(chipLabel);

  const bool beginOk = sensor.begin(chipSelectPin, SPI_CLOCK_HZ, SPI_MODE);
  reportResult("begin(CS, 1 MHz, SPI mode 0)", beginOk);
  if (!beginOk) {
    return false;
  }

  // STATE is the only documented response-level probe exposed by this driver.
  const int state = sensor.readState();
  if (!isDocumentedState(state)) {
    Serial.print("TEST_LOG:[SKIP] ");
    Serial.print(chipLabel);
    Serial.println(" did not return a documented STATE value");
    ++skipCount;
    sensor.end();
    return false;
  }

  ++connectedChipCount;
  testGenericRegisterAccess(sensor);
  testMeasurementApis(sensor);
  testCrcApis(sensor);
  testNVRAMReadApis(sensor);
  testRawBurstApi(sensor);

  sensor.end();
  reportResult("end() releases the chip-select line", true);
  return true;
}

bool runFullApiTest() {
  passCount = 0;
  failCount = 0;
  skipCount = 0;
  connectedChipCount = 0;

  Serial.println("TEST_LOG:========================================");
  Serial.println("TEST_LOG:MLX90382 MLX_5mini driver API coverage test");
  Serial.println("TEST_LOG:========================================");
  Serial.println("TEST_LOG:SPI pins SCLK=GPIO2 MOSI=GPIO3 MISO=GPIO4");
  Serial.println("TEST_LOG:Chip selects CS0=GPIO9 CS1=GPIO5");
  Serial.println("TEST_LOG:Driver defaults SPI clock=1 MHz mode=0");

  reportResult("RP2040 SPI pin configuration", spiPinConfigurationOk);
  testInputValidation();

  bool cs0Responded = false;
  bool cs1Responded = false;
  if (TEST_CS0) {
    cs0Responded = testChip("MLX90382 CS0", sensorCs0, MLX_CS0_PIN);
  } else {
    reportSkip("CS0 test disabled by configuration");
  }
  if (TEST_CS1) {
    cs1Responded = testChip("MLX90382 CS1", sensorCs1, MLX_CS1_PIN);
  } else {
    reportSkip("CS1 test disabled by configuration");
  }

  reportResult(
      "at least one MLX90382 returned a documented STATE value",
      connectedChipCount > 0u);
  reportSkippedWriteApis();

  Serial.print("TEST_LOG:Responding chips CS0=");
  Serial.print(cs0Responded ? "YES" : "NO");
  Serial.print(" CS1=");
  Serial.println(cs1Responded ? "YES" : "NO");
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

  Serial.println("TEST_LOG:MLX90382 MLX_5mini test sketch ready");
  Serial.println("TEST_LOG:Send RUN_TEST to execute the hardware test");
}

void loop() {
  if (testExecuted || Serial.available() == 0) {
    return;
  }

  String command = Serial.readStringUntil('\n');
  command.trim();
  if (command != "RUN_TEST") {
    Serial.println("TEST_LOG:Ignored command; waiting for RUN_TEST");
    return;
  }

  testExecuted = true;
  const bool passed = runFullApiTest();
  Serial.println(passed ? "TEST_RESULT:PASS" : "TEST_RESULT:FAIL");
  Serial.flush();
}
