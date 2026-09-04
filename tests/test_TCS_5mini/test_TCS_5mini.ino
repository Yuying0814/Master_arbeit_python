#include <Arduino.h>
#include <Wire.h>

#include "TCS3472/v1/tcs3472_example/TCS3472.h"
#include "TCS3472/v1/tcs3472_example/TCS3472.cpp"

// RP2040 hardware configuration.
constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 1;
constexpr uint8_t INT_PIN = 15;
constexpr uint8_t TCS3472_I2C_ADDRESS = 0x29;

constexpr uint8_t TEST_ATIME = 0xF6;
constexpr uint8_t TEST_WTIME = 0xFF;
constexpr unsigned long DATA_READY_TIMEOUT_MS = 1000UL;
constexpr unsigned long MONITOR_INTERVAL_MS = 1000UL;
constexpr unsigned long FULL_API_TEST_INTERVAL_MS = 10000UL;

TCS3472 sensor;

bool deviceReady = false;
unsigned long lastFullApiTestMs = 0;
unsigned long lastMonitorMs = 0;

uint16_t passCount = 0;
uint16_t failCount = 0;
uint16_t apiCallCount = 0;

void printBoolean(bool value) {
  Serial.print(value ? "1" : "0");
}

void printHex8(uint8_t value) {
  if (value < 0x10) {
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

void reportCall(const char *label) {
  Serial.print("[CALL] ");
  Serial.println(label);
  ++apiCallCount;
}

void reportInfo(const char *label) {
  Serial.print("[INFO] ");
  Serial.println(label);
}

bool waitForRGBCData(unsigned long timeoutMs) {
  const unsigned long startMs = millis();

  while (millis() - startMs < timeoutMs) {
    if (sensor.isRGBCValid()) {
      return true;
    }
    delay(10);
  }

  return false;
}

bool testDeviceIdentity() {
  Serial.println();
  Serial.println("[TEST] Device identity");

  const uint8_t id = sensor.readID();
  const bool idOk = id == 0x44 || id == 0x4D;
  reportResult("readID() returns a documented TCS3472 ID", idOk);

  Serial.print("  ID: 0x");
  printHex8(id);
  Serial.println(" (0x44=TCS34725, 0x4D=TCS34727)");

  return idOk;
}

bool testStatusRead() {
  Serial.println();
  Serial.println("[TEST] Device status");

  const uint8_t status = sensor.readStatus();
  const bool statusOk = status != 0xFF && (status & 0xEE) == 0;
  reportResult("readStatus() returns valid defined status bits", statusOk);

  Serial.print("  STATUS: 0x");
  printHex8(status);
  Serial.println();

  return statusOk;
}

bool testPowerAndRGBCControl() {
  Serial.println();
  Serial.println("[TEST] Power and RGBC control");

  sensor.enableRGBC(false);
  reportCall("enableRGBC(false)");

  sensor.powerOff();
  reportCall("powerOff()");
  delay(5);

  sensor.powerOn();
  reportCall("powerOn()");

  sensor.enableRGBC(true);
  reportCall("enableRGBC(true)");

  const bool dataReady = waitForRGBCData(DATA_READY_TIMEOUT_MS);
  reportResult("powerOn() and enableRGBC(true) allow RGBC conversion", dataReady);
  return dataReady;
}

bool testIntegrationTime() {
  Serial.println();
  Serial.println("[TEST] Integration time");

  sensor.enableRGBC(false);
  reportCall("enableRGBC(false) before setATime()");

  const uint8_t originalAtime = sensor.getATime();

  sensor.setATime(TEST_ATIME);
  reportCall("setATime(0xF6)");
  const uint8_t observedAtime = sensor.getATime();
  reportResult("setATime()/getATime() round-trip", observedAtime == TEST_ATIME);

  Serial.print("  Test ATIME: 0x");
  printHex8(observedAtime);
  Serial.print("; integration time: ");
  Serial.print(2.4f * static_cast<float>(256U - TEST_ATIME), 1);
  Serial.println(" ms");

  sensor.setATime(originalAtime);
  reportCall("restore original ATIME");
  const uint8_t restoredAtime = sensor.getATime();
  reportResult("original ATIME is restored", restoredAtime == originalAtime);

  return observedAtime == TEST_ATIME && restoredAtime == originalAtime;
}

void testGainControl() {
  Serial.println();
  Serial.println("[TEST] Analog gain control");

  sensor.setGain(GAIN_1X);
  reportCall("setGain(GAIN_1X)");
  sensor.setGain(GAIN_4X);
  reportCall("setGain(GAIN_4X)");
  sensor.setGain(GAIN_16X);
  reportCall("setGain(GAIN_16X)");
  sensor.setGain(GAIN_60X);
  reportCall("setGain(GAIN_60X)");

  sensor.setGain(GAIN_1X);
  reportCall("restore gain to GAIN_1X");
  reportInfo("setGain() is call-covered; the driver exposes no gain getter.");
}

void testWaitControl() {
  Serial.println();
  Serial.println("[TEST] Wait timer control");

  sensor.setWait(false);
  reportCall("setWait(false)");

  sensor.setWait(true, TEST_WTIME, false);
  reportCall("setWait(true, 0xFF, false)");

  sensor.setWait(true, TEST_WTIME, true);
  reportCall("setWait(true, 0xFF, true)");

  sensor.setWait(false);
  reportCall("restore wait timer disabled");
  reportInfo("setWait() is call-covered; the driver exposes no wait getter.");
}

void testInterruptControl() {
  Serial.println();
  Serial.println("[TEST] Interrupt control");

  sensor.setInterruptThresholds(0xFFFF, 0x0000);
  reportCall("setInterruptThresholds(reversed arguments)");

  sensor.setInterruptThresholds(0x0000, 0xFFFF);
  reportCall("setInterruptThresholds(0x0000, 0xFFFF)");

  sensor.setPersistence(0x03);
  reportCall("setPersistence(0x03)");

  sensor.setPersistence(0xFF);
  reportCall("setPersistence(0xFF), exercising clamp");

  sensor.setPersistence(0x00);
  reportCall("restore persistence to 0x00");

  sensor.setInterruptEnable(true);
  reportCall("setInterruptEnable(true)");

  sensor.clearInterrupt();
  reportCall("clearInterrupt()");

  const uint8_t statusAfterClear = sensor.readStatus();
  const bool clearStatusOk = statusAfterClear != 0xFF &&
                             (statusAfterClear & 0xEE) == 0;
  reportResult("clearInterrupt() keeps status communication valid", clearStatusOk);

  sensor.setInterruptEnable(false);
  reportCall("setInterruptEnable(false)");
  sensor.clearInterrupt();
  reportCall("clearInterrupt() with interrupt output disabled");

  reportInfo("Threshold and persistence setters are call-covered; this driver exposes no getters.");
}

bool testRGBCAcquisition() {
  Serial.println();
  Serial.println("[TEST] RGBC acquisition");

  sensor.enableRGBC(true);
  reportCall("enableRGBC(true) before acquisition");

  bool dataValid = sensor.isRGBCValid();
  if (!dataValid) {
    dataValid = waitForRGBCData(DATA_READY_TIMEOUT_MS);
  }
  reportResult("isRGBCValid() reports completed conversion", dataValid);

  uint16_t clearData = 0;
  uint16_t redData = 0;
  uint16_t greenData = 0;
  uint16_t blueData = 0;
  const bool rawOk = sensor.readRaw(clearData, redData, greenData, blueData);
  reportResult("readRaw() returns all four RGBC channels", rawOk);

  if (rawOk) {
    Serial.print("  Clear: ");
    Serial.print(clearData);
    Serial.print("; Red: ");
    Serial.print(redData);
    Serial.print("; Green: ");
    Serial.print(greenData);
    Serial.print("; Blue: ");
    Serial.println(blueData);
  }

  return dataValid && rawOk;
}

void restoreMonitorConfiguration() {
  sensor.enableRGBC(false);
  sensor.setWait(false);
  sensor.setInterruptEnable(false);
  sensor.setInterruptThresholds(0x0000, 0xFFFF);
  sensor.setPersistence(0x00);
  sensor.setATime(0xFF);
  sensor.setGain(GAIN_1X);
  sensor.powerOn();
  sensor.enableRGBC(true);
  sensor.clearInterrupt();
}

void printTestSummary() {
  Serial.println();
  Serial.println("----------------------------------------");
  Serial.print("Verified checks: PASS=");
  Serial.print(passCount);
  Serial.print(" FAIL=");
  Serial.println(failCount);
  Serial.print("Call-only API entries covered: ");
  Serial.println(apiCallCount);
  Serial.println(failCount == 0 ? "Full API cycle result: PASS"
                                : "Full API cycle result: FAIL");
  Serial.println("----------------------------------------");
}

bool runFullApiTest() {
  passCount = 0;
  failCount = 0;
  apiCallCount = 0;

  Serial.println();
  Serial.println("========================================");
  Serial.println("TCS3472 full driver API test");
  Serial.println("========================================");
  Serial.println("Hardware: RP2040, SDA=GPIO0, SCL=GPIO1, INT=GPIO15");
  Serial.print("I2C address: 0x");
  printHex8(TCS3472_I2C_ADDRESS);
  Serial.println();

  reportCall("TCS3472() constructor (global instance)");
  const bool beginOk = sensor.begin(TCS3472_I2C_ADDRESS);
  reportResult("begin(0x29)", beginOk);
  if (!beginOk) {
    reportInfo("No TCS3472 response. The next full API cycle will retry initialization.");
    printTestSummary();
    return false;
  }

  const bool identityOk = testDeviceIdentity();
  const bool statusOk = testStatusRead();
  const bool powerOk = testPowerAndRGBCControl();
  const bool integrationOk = testIntegrationTime();
  testGainControl();
  testWaitControl();
  testInterruptControl();
  const bool acquisitionOk = testRGBCAcquisition();

  restoreMonitorConfiguration();
  reportInfo("Monitor configuration restored: power on, RGBC enabled, wait disabled, interrupt disabled.");
  printTestSummary();

  const bool dataPathOk = powerOk && integrationOk && acquisitionOk;
  if (!dataPathOk) {
    reportInfo("A data-path check failed; monitoring remains active while the device responds.");
  }

  // Keep monitoring when a reversible API check fails, provided the device still answers.
  return beginOk && identityOk && statusOk;
}

void printStatusDetails(uint8_t status) {
  Serial.print("STATUS: 0x");
  printHex8(status);
  Serial.print("; AVALID=");
  printBoolean((status & TCS3472_STATUS_AVALID) != 0);
  Serial.print("; AINT=");
  printBoolean((status & TCS3472_STATUS_AINT) != 0);
  Serial.println();
}

void runMonitorCycle() {
  Serial.println();
  Serial.println("--- TCS3472 measurement monitor ---");
  Serial.print("Uptime: ");
  Serial.print(millis() / 1000UL);
  Serial.println(" s");

  const uint8_t status = sensor.readStatus();
  const bool statusOk = status != 0xFF && (status & 0xEE) == 0;
  if (statusOk) {
    printStatusDetails(status);
  } else {
    Serial.println("STATUS: READ_ERROR");
  }

  const int intLevel = digitalRead(INT_PIN);
  Serial.print("INT pin: ");
  Serial.println(intLevel == LOW ? "LOW (active)" : "HIGH (inactive)");

  const bool dataValid = sensor.isRGBCValid();
  Serial.print("RGBC data valid: ");
  Serial.println(dataValid ? "YES" : "NO");

  if (dataValid) {
    uint16_t clearData = 0;
    uint16_t redData = 0;
    uint16_t greenData = 0;
    uint16_t blueData = 0;
    if (sensor.readRaw(clearData, redData, greenData, blueData)) {
      Serial.print("Measurements [counts] - Clear: ");
      Serial.print(clearData);
      Serial.print("; Red: ");
      Serial.print(redData);
      Serial.print("; Green: ");
      Serial.print(greenData);
      Serial.print("; Blue: ");
      Serial.println(blueData);
    } else {
      Serial.println("Measurements: READ_ERROR");
    }
  } else {
    Serial.println("Measurements: waiting for the next RGBC conversion");
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
