/*
  Periodic hardware test for the LIS3DH 5mini driver.

  The sketch exercises the public API exposed by the current driver. It uses
  I2C on the supplied RP2040 pins and reports measurement, status and INT data.
*/

#include <Wire.h>
#include <SPI.h>
#include <math.h>

// The driver source is included without modifying the driver files. The
// absolute path remains valid when Arduino CLI stages the sketch elsewhere.
#include "LIS3DH.h"

constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 1;
constexpr uint8_t INT1_PIN = 12;
constexpr uint8_t INT2_PIN = 13;

constexpr uint8_t I2C_ADDRESS_SA0_LOW = 0x18;
constexpr uint8_t I2C_ADDRESS_SA0_HIGH = 0x19;
constexpr uint8_t EXPECTED_WHO_AM_I = LIS3DH_WHO_AM_I_ID;

constexpr uint32_t MONITOR_INTERVAL_MS = 2000UL;
constexpr uint32_t FULL_CHECKLIST_INTERVAL_MS = 20000UL;
constexpr float TEST_ODR_HZ = 100.0f;

// Setting SDO_PU_DISC=1 can change the electrical SA0/SDO behavior. Keep the
// potentially board-dependent operation disabled unless it is explicitly wanted.
constexpr bool RUN_SDO_PULLUP_DISCONNECT_SET = false;

constexpr uint8_t CTRL_REG1_ODR_MASK = LIS3DH_CTRL_REG1_ODR_MASK;
constexpr uint8_t CTRL_REG1_AXIS_MASK = 0x07;
constexpr uint8_t CTRL_REG1_LPEN_MASK = LIS3DH_CTRL_REG1_LPEN;
constexpr uint8_t CTRL_REG4_BDU_MASK = LIS3DH_CTRL_REG4_BDU;
constexpr uint8_t CTRL_REG4_BLE_MASK = LIS3DH_CTRL_REG4_BLE;
constexpr uint8_t CTRL_REG4_FS_MASK = LIS3DH_CTRL_REG4_FS_MASK;
constexpr uint8_t CTRL_REG4_HR_MASK = LIS3DH_CTRL_REG4_HR;
constexpr uint8_t CTRL_REG4_SIM_MASK = LIS3DH_CTRL_REG4_SIM;
constexpr uint8_t CTRL_REG4_ST_MASK = LIS3DH_CTRL_REG4_ST_MASK;
constexpr uint8_t CTRL_REG5_BOOT_MASK = LIS3DH_CTRL_REG5_BOOT;
constexpr uint8_t CTRL_REG5_FIFO_EN_MASK = LIS3DH_CTRL_REG5_FIFO_EN;
constexpr uint8_t CTRL_REG0_SDO_PU_DISC_MASK = LIS3DH_CTRL_REG0_SDO_PU_DISC;
constexpr uint8_t STATUS_ZYXDA_MASK = 0x08;
constexpr uint8_t FIFO_MODE_MASK = 0xC0;
constexpr uint8_t FIFO_WATERMARK_MASK = 0x1F;

LIS3DH sensor;

bool deviceReady = false;
bool addressDetected = false;
uint8_t activeAddress = I2C_ADDRESS_SA0_LOW;
uint32_t checklistNumber = 0;
uint32_t lastMonitorMs = 0;
uint32_t lastChecklistMs = 0;

uint16_t checkCount = 0;
uint16_t passCount = 0;
uint16_t failCount = 0;
uint16_t skipCount = 0;

void printHexByte(uint8_t value) {
  if (value < 0x10) {
    Serial.print('0');
  }
  Serial.print(value, HEX);
}

void printBoolean(bool value) {
  Serial.print(value ? F("1") : F("0"));
}

void reportCheck(const __FlashStringHelper *label, bool passed) {
  ++checkCount;
  if (passed) {
    ++passCount;
    Serial.print(F("[PASS] "));
  } else {
    ++failCount;
    Serial.print(F("[FAIL] "));
  }
  Serial.println(label);
}

void reportSkip(const __FlashStringHelper *label) {
  ++skipCount;
  Serial.print(F("[SKIP] "));
  Serial.println(label);
}

void reportInfo(const __FlashStringHelper *label) {
  Serial.print(F("[INFO] "));
  Serial.println(label);
}

void resetChecklistCounters() {
  checkCount = 0;
  passCount = 0;
  failCount = 0;
  skipCount = 0;
}

bool isFiniteFloat(float value) {
  return !isnan(value) && !isinf(value);
}

bool readRegisterValue(uint8_t reg, uint8_t &value) {
  const int result = sensor.readRegister(reg);
  if (result < 0) {
    return false;
  }
  value = static_cast<uint8_t>(result);
  return true;
}

void printRegisterValue(const __FlashStringHelper *label, uint8_t value) {
  Serial.print(F("      "));
  Serial.print(label);
  Serial.print(F(" = 0x"));
  printHexByte(value);
  Serial.println();
}

bool checkRegisterBits(const __FlashStringHelper *label,
                       uint8_t reg,
                       uint8_t mask,
                       uint8_t expected) {
  uint8_t value = 0;
  const bool readOk = readRegisterValue(reg, value);
  if (readOk) {
    printRegisterValue(label, value);
  }
  const bool passed = readOk && ((value & mask) == (expected & mask));
  reportCheck(label, passed);
  return passed;
}

bool writeReadRegister(const __FlashStringHelper *label,
                       uint8_t reg,
                       uint8_t value,
                       uint8_t mask = 0xFF) {
  const bool writeOk = sensor.writeRegister(reg, value);
  uint8_t readBack = 0;
  const bool readOk = writeOk && readRegisterValue(reg, readBack);
  if (readOk) {
    printRegisterValue(label, readBack);
  }
  const bool passed = writeOk && readOk &&
                      ((readBack & mask) == (value & mask));
  reportCheck(label, passed);
  return passed;
}

bool tryI2CAddress(uint8_t address) {
  if (!sensor.beginI2C(address, true)) {
    return false;
  }

  const uint8_t whoAmI = sensor.whoAmI();
  if (whoAmI != EXPECTED_WHO_AM_I) {
    return false;
  }

  activeAddress = address;
  addressDetected = true;
  deviceReady = true;
  Serial.print(F("[INFO] LIS3DH detected at 7-bit I2C address 0x"));
  printHexByte(activeAddress);
  Serial.print(F("; WHO_AM_I=0x"));
  printHexByte(whoAmI);
  Serial.println();
  return true;
}

bool ensureSensor() {
  if (deviceReady && addressDetected) {
    if (sensor.whoAmI() == EXPECTED_WHO_AM_I) {
      return true;
    }
    deviceReady = false;
  }

  if (tryI2CAddress(I2C_ADDRESS_SA0_LOW) ||
      tryI2CAddress(I2C_ADDRESS_SA0_HIGH)) {
    return true;
  }

  deviceReady = false;
  addressDetected = false;
  return false;
}

bool clearBootAndFifoBits() {
  uint8_t ctrl5 = 0;
  if (!readRegisterValue(LIS3DH_REG_CTRL_REG5, ctrl5)) {
    return false;
  }
  ctrl5 &= static_cast<uint8_t>(~(CTRL_REG5_BOOT_MASK | CTRL_REG5_FIFO_EN_MASK));
  return sensor.writeRegister(LIS3DH_REG_CTRL_REG5, ctrl5);
}

bool restoreSafeConfiguration() {
  bool ok = true;
  ok = sensor.setODR(LIS3DH_ODR_100HZ) && ok;
  ok = sensor.setPowerMode(false, false, TEST_ODR_HZ) && ok;
  ok = sensor.enableAxis(true, true, true) && ok;
  ok = sensor.setFullScale(LIS3DH_FS_2G) && ok;
  ok = sensor.setBDU(true) && ok;
  ok = sensor.setBLE(false) && ok;
  ok = sensor.setSIM(false) && ok;
  ok = sensor.enableADC(false, false) && ok;
  ok = sensor.selfTest(0, TEST_ODR_HZ) && ok;
  ok = sensor.configureFIFO(false, LIS3DH_FIFO_BYPASS, 0) && ok;
  ok = sensor.configureInterrupts(0x00, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_CTRL_REG2, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_REFERENCE, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_INT1_CFG, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_INT1_THS, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_INT1_DURATION, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_INT2_CFG, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_INT2_THS, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_INT2_DURATION, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_CLICK_CFG, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_CLICK_THS, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_TIME_LIMIT, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_TIME_LATENCY, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_TIME_WINDOW, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_ACT_THS, 0x00) && ok;
  ok = sensor.writeRegister(LIS3DH_REG_ACT_DUR, 0x00) && ok;
  ok = sensor.setSDOPullupDisconnect(false) && ok;
  ok = clearBootAndFifoBits() && ok;
  return ok;
}

void testIdentityAndStatus() {
  Serial.println(F("\n[TEST] Identity, status and generic register access"));

  const uint8_t whoAmI = sensor.whoAmI();
  printRegisterValue(F("WHO_AM_I"), whoAmI);
  reportCheck(F("whoAmI() returns the LIS3DH identity"),
              whoAmI == EXPECTED_WHO_AM_I);

  uint8_t whoViaGeneric = 0;
  const bool genericWhoOk = readRegisterValue(LIS3DH_REG_WHO_AM_I, whoViaGeneric);
  reportCheck(F("readRegister() reads WHO_AM_I"),
              genericWhoOk && whoViaGeneric == EXPECTED_WHO_AM_I);

  const uint8_t status = sensor.readStatus();
  printRegisterValue(F("STATUS_REG"), status);
  reportCheck(F("readStatus() returns a valid register value"), status != 0xFF);

  const uint8_t auxStatus = sensor.readStatusAux();
  printRegisterValue(F("STATUS_REG_AUX"), auxStatus);
  reportCheck(F("readStatusAux() returns a valid register value"), auxStatus != 0xFF);

  uint8_t referenceBefore = 0;
  const bool saved = readRegisterValue(LIS3DH_REG_REFERENCE, referenceBefore);
  const bool roundTrip = saved &&
                         writeReadRegister(F("generic REFERENCE round-trip"),
                                           LIS3DH_REG_REFERENCE, 0x5A);
  if (saved) {
    reportCheck(F("restore REFERENCE after generic access"),
                sensor.writeRegister(LIS3DH_REG_REFERENCE, referenceBefore));
  } else {
    reportCheck(F("save REFERENCE before generic access"), false);
  }
  (void)roundTrip;
}

void testConfiguration() {
  Serial.println(F("\n[TEST] ODR, power mode, axes, range and data format"));

  const uint8_t odrCodes[] = {
      LIS3DH_ODR_POWER_DOWN,
      LIS3DH_ODR_1HZ,
      LIS3DH_ODR_10HZ,
      LIS3DH_ODR_25HZ,
      LIS3DH_ODR_50HZ,
      LIS3DH_ODR_100HZ,
      LIS3DH_ODR_200HZ,
      LIS3DH_ODR_400HZ,
      LIS3DH_ODR_LP_1_6KHZ,
      LIS3DH_ODR_HR_1344};

  for (const uint8_t odrCode : odrCodes) {
    const bool setOk = sensor.setODR(odrCode);
    uint8_t ctrl1 = 0;
    const bool readOk = readRegisterValue(LIS3DH_REG_CTRL_REG1, ctrl1);
    Serial.print(F("      ODR code=0x"));
    printHexByte(odrCode);
    Serial.print(F("; CTRL_REG1=0x"));
    printHexByte(ctrl1);
    Serial.println();
    reportCheck(F("setODR() writes the ODR field"),
                setOk && readOk &&
                    (ctrl1 & CTRL_REG1_ODR_MASK) ==
                        (odrCode & CTRL_REG1_ODR_MASK));
  }

  reportCheck(F("setODR() restores the 100 Hz operating rate"),
              sensor.setODR(LIS3DH_ODR_100HZ));

  const bool normalMode = sensor.setPowerMode(false, false, TEST_ODR_HZ);
  const bool normalBits = checkRegisterBits(F("normal mode clears LPen"),
                                            LIS3DH_REG_CTRL_REG1,
                                            CTRL_REG1_LPEN_MASK,
                                            0x00) &&
                          checkRegisterBits(F("normal mode clears HR"),
                                            LIS3DH_REG_CTRL_REG4,
                                            CTRL_REG4_HR_MASK,
                                            0x00);

  const bool lowPowerMode = sensor.setPowerMode(true, false, TEST_ODR_HZ);
  const bool lowPowerBits = checkRegisterBits(F("low-power mode sets LPen"),
                                              LIS3DH_REG_CTRL_REG1,
                                              CTRL_REG1_LPEN_MASK,
                                              CTRL_REG1_LPEN_MASK);
  const bool forbiddenCombination = sensor.setPowerMode(true, true, TEST_ODR_HZ);
  reportCheck(F("setPowerMode() rejects LPen and HR together"),
              !forbiddenCombination);

  const bool returnToNormal = sensor.setPowerMode(false, false, TEST_ODR_HZ);
  reportCheck(F("setPowerMode() handles normal and low-power transitions"),
              normalMode && normalBits && lowPowerMode && lowPowerBits && returnToNormal);

  const bool axisPatterns[][3] = {
      {true, true, true},
      {true, false, false},
      {false, true, false},
      {false, false, true},
      {false, false, false}};
  const uint8_t axisMasks[] = {0x07, 0x01, 0x02, 0x04, 0x00};
  for (uint8_t index = 0; index < 5; ++index) {
    const bool setOk = sensor.enableAxis(axisPatterns[index][0],
                                         axisPatterns[index][1],
                                         axisPatterns[index][2]);
    uint8_t ctrl1 = 0;
    const bool readOk = readRegisterValue(LIS3DH_REG_CTRL_REG1, ctrl1);
    Serial.print(F("      axis mask expected=0x"));
    printHexByte(axisMasks[index]);
    Serial.print(F("; actual=0x"));
    printHexByte(ctrl1 & CTRL_REG1_AXIS_MASK);
    Serial.println();
    reportCheck(F("enableAxis() writes X/Y/Z enable bits"),
                setOk && readOk &&
                    (ctrl1 & CTRL_REG1_AXIS_MASK) == axisMasks[index]);
  }
  sensor.enableAxis(true, true, true);

  const uint8_t fullScaleCodes[] = {
      LIS3DH_FS_2G, LIS3DH_FS_4G, LIS3DH_FS_8G, LIS3DH_FS_16G};
  for (const uint8_t fsCode : fullScaleCodes) {
    const bool setOk = sensor.setFullScale(fsCode);
    uint8_t ctrl4 = 0;
    const bool readOk = readRegisterValue(LIS3DH_REG_CTRL_REG4, ctrl4);
    Serial.print(F("      full-scale code=0x"));
    printHexByte(fsCode);
    Serial.print(F("; CTRL_REG4=0x"));
    printHexByte(ctrl4);
    Serial.println();
    reportCheck(F("setFullScale() writes the full-scale field"),
                setOk && readOk &&
                    (ctrl4 & CTRL_REG4_FS_MASK) ==
                        static_cast<uint8_t>(fsCode << 4));
  }
  sensor.setFullScale(LIS3DH_FS_2G);

  const bool bduOn = sensor.setBDU(true);
  const bool bduOnBit = checkRegisterBits(F("setBDU(true) sets BDU"),
                                          LIS3DH_REG_CTRL_REG4,
                                          CTRL_REG4_BDU_MASK,
                                          CTRL_REG4_BDU_MASK);
  const bool bduOff = sensor.setBDU(false);
  const bool bduOffBit = checkRegisterBits(F("setBDU(false) clears BDU"),
                                           LIS3DH_REG_CTRL_REG4,
                                           CTRL_REG4_BDU_MASK,
                                           0x00);
  const bool bduRestore = sensor.setBDU(true);
  reportCheck(F("setBDU() handles both states"),
              bduOn && bduOnBit && bduOff && bduOffBit && bduRestore);

  const bool bleOn = sensor.setBLE(true);
  const bool bleOnBit = checkRegisterBits(F("setBLE(true) sets BLE"),
                                          LIS3DH_REG_CTRL_REG4,
                                          CTRL_REG4_BLE_MASK,
                                          CTRL_REG4_BLE_MASK);
  const bool bleOff = sensor.setBLE(false);
  const bool bleOffBit = checkRegisterBits(F("setBLE(false) clears BLE"),
                                           LIS3DH_REG_CTRL_REG4,
                                           CTRL_REG4_BLE_MASK,
                                           0x00);
  reportCheck(F("setBLE() handles both byte orders"),
              bleOn && bleOnBit && bleOff && bleOffBit);

  const bool simOff = sensor.setSIM(false);
  const bool simOffBit = checkRegisterBits(F("setSIM(false) selects four-wire mode"),
                                           LIS3DH_REG_CTRL_REG4,
                                           CTRL_REG4_SIM_MASK,
                                           0x00);
  const bool simOn = sensor.setSIM(true);
  reportCheck(F("setSIM(true) reports unsupported three-wire mode"), !simOn);
  const bool simStillOff = checkRegisterBits(F("SIM remains cleared"),
                                             LIS3DH_REG_CTRL_REG4,
                                             CTRL_REG4_SIM_MASK,
                                             0x00);
  reportCheck(F("setSIM() leaves four-wire mode after rejected request"),
              simOff && simOffBit && simStillOff);

  const bool highResolution = sensor.setPowerMode(false, true, TEST_ODR_HZ);
  const bool highResolutionBit = checkRegisterBits(F("setPowerMode() sets HR"),
                                                   LIS3DH_REG_CTRL_REG4,
                                                   CTRL_REG4_HR_MASK,
                                                   CTRL_REG4_HR_MASK);
  const bool backToNormal = sensor.setPowerMode(false, false, TEST_ODR_HZ);
  reportCheck(F("setPowerMode() handles high-resolution transition"),
              highResolution && highResolutionBit && backToNormal);

  reportInfo(F("Mode transition delays are applied internally by the driver."));
}

void printMeasurement(const __FlashStringHelper *label,
                      int16_t rawX,
                      int16_t rawY,
                      int16_t rawZ,
                      float gx,
                      float gy,
                      float gz) {
  Serial.print(F("      "));
  Serial.print(label);
  Serial.print(F("; raw=("));
  Serial.print(rawX);
  Serial.print(',');
  Serial.print(rawY);
  Serial.print(',');
  Serial.print(rawZ);
  Serial.print(F("); normalized_g=("));
  Serial.print(gx, 4);
  Serial.print(',');
  Serial.print(gy, 4);
  Serial.print(',');
  Serial.print(gz, 4);
  Serial.println(')');
}

bool readAndReportMeasurement(const __FlashStringHelper *label,
                              bool waitForData) {
  uint8_t status = sensor.readStatus();
  const bool statusOk = status != 0xFF;
  if (statusOk && waitForData && (status & STATUS_ZYXDA_MASK) == 0) {
    const uint32_t start = millis();
    while (static_cast<uint32_t>(millis() - start) < 250UL) {
      status = sensor.readStatus();
      if (status == 0xFF || (status & STATUS_ZYXDA_MASK) != 0) {
        break;
      }
      delay(2);
    }
  }

  int16_t rawX = 0;
  int16_t rawY = 0;
  int16_t rawZ = 0;
  const bool rawOk = sensor.readRaw(rawX, rawY, rawZ);

  float gx = 0.0f;
  float gy = 0.0f;
  float gz = 0.0f;
  const bool normalizedOk = sensor.readNormalized(gx, gy, gz);
  if (rawOk && normalizedOk) {
    printMeasurement(label, rawX, rawY, rawZ, gx, gy, gz);
  }

  const bool finiteOk = normalizedOk && isFiniteFloat(gx) &&
                        isFiniteFloat(gy) && isFiniteFloat(gz);
  reportCheck(label, statusOk && rawOk && finiteOk);
  return statusOk && rawOk && finiteOk;
}

void testAcceleration() {
  Serial.println(F("\n[TEST] Acceleration acquisition and normalized conversion"));

  sensor.setODR(LIS3DH_ODR_100HZ);
  sensor.setFullScale(LIS3DH_FS_2G);
  sensor.enableAxis(true, true, true);
  sensor.setBDU(true);

  const bool normalMode = sensor.setPowerMode(false, false, TEST_ODR_HZ);
  reportCheck(F("configure normal-resolution acquisition"), normalMode);
  delay(30);
  readAndReportMeasurement(F("normal-resolution acceleration"), true);

  const bool highResolutionMode = sensor.setPowerMode(false, true, TEST_ODR_HZ);
  reportCheck(F("configure high-resolution acquisition"), highResolutionMode);
  delay(20);
  readAndReportMeasurement(F("high-resolution acceleration"), true);

  const bool lowPowerMode = sensor.setPowerMode(true, false, TEST_ODR_HZ);
  reportCheck(F("configure low-power acquisition"), lowPowerMode);
  delay(20);
  readAndReportMeasurement(F("low-power acceleration"), true);

  const bool restored = sensor.setPowerMode(false, false, TEST_ODR_HZ) &&
                        sensor.setFullScale(LIS3DH_FS_2G) &&
                        sensor.setBDU(true) &&
                        sensor.setBLE(false);
  reportCheck(F("restore normal acceleration format"), restored);
}

void testAuxiliaryChannels() {
  Serial.println(F("\n[TEST] Auxiliary ADC and temperature channel access"));

  const bool enableOk = sensor.enableADC(true, true);
  reportCheck(F("enableADC(true, true) enables ADC and temperature"), enableOk);

  for (uint8_t channel = 1; channel <= 3; ++channel) {
    const int16_t value = sensor.readADC(channel);
    Serial.print(F("      ADC channel "));
    Serial.print(channel);
    Serial.print(F(" raw="));
    Serial.println(value);
    reportCheck(F("readADC() reads a valid channel"), value != INT16_MIN);
  }

  const int16_t invalidChannelZero = sensor.readADC(0);
  const int16_t invalidChannelFour = sensor.readADC(4);
  reportCheck(F("readADC() rejects channel 0"), invalidChannelZero == INT16_MIN);
  reportCheck(F("readADC() rejects channel 4"), invalidChannelFour == INT16_MIN);

  const uint8_t auxStatus = sensor.readStatusAux();
  printRegisterValue(F("STATUS_REG_AUX after ADC enable"), auxStatus);
  reportCheck(F("readStatusAux() remains readable with ADC enabled"),
              auxStatus != 0xFF);

  reportCheck(F("disable ADC and temperature channels"),
              sensor.enableADC(false, false));
}

void printFifoStatus(uint8_t fss,
                     bool watermark,
                     bool overrun,
                     bool empty) {
  Serial.print(F("      FIFO; FSS="));
  Serial.print(fss);
  Serial.print(F("; WTM="));
  printBoolean(watermark);
  Serial.print(F("; OVRN="));
  printBoolean(overrun);
  Serial.print(F("; EMPTY="));
  printBoolean(empty);
  Serial.println();
}

bool readAndPrintFifoStatus(const __FlashStringHelper *label) {
  const uint8_t rawStatus = sensor.readFifoStatus();
  const int sampleCount = sensor.getFifoSampleCount();
  uint8_t fss = 0;
  bool watermark = false;
  bool overrun = false;
  bool empty = false;
  const bool parsedOk = sensor.readFifoStatusParsed(fss, watermark, overrun, empty);

  Serial.print(F("      "));
  Serial.print(label);
  Serial.print(F("; raw=0x"));
  printHexByte(rawStatus);
  Serial.print(F("; count="));
  Serial.println(sampleCount);
  if (parsedOk) {
    printFifoStatus(fss, watermark, overrun, empty);
  }

  const bool passed = rawStatus != 0xFF && sampleCount >= 0 && sampleCount <= 31 &&
                      parsedOk && fss <= 31;
  reportCheck(label, passed);
  return passed;
}

void testFifo() {
  Serial.println(F("\n[TEST] FIFO modes, status parsing and sample retrieval"));

  sensor.setODR(LIS3DH_ODR_100HZ);
  sensor.setPowerMode(false, false, TEST_ODR_HZ);
  sensor.enableAxis(true, true, true);

  const uint8_t fifoModes[] = {
      LIS3DH_FIFO_BYPASS,
      LIS3DH_FIFO_FIFO,
      LIS3DH_FIFO_STREAM,
      LIS3DH_FIFO_STR_TO_FIFO};

  for (const uint8_t mode : fifoModes) {
    const bool configureOk = sensor.configureFIFO(true, mode, 4);
    uint8_t fifoControl = 0;
    const bool readControlOk = readRegisterValue(LIS3DH_REG_FIFO_CTRL_REG,
                                                 fifoControl);
    uint8_t ctrl5 = 0;
    const bool readCtrl5Ok = readRegisterValue(LIS3DH_REG_CTRL_REG5, ctrl5);

    Serial.print(F("      FIFO mode="));
    Serial.print(mode);
    Serial.print(F("; CTRL=0x"));
    printHexByte(fifoControl);
    Serial.println();
    reportCheck(F("configureFIFO() writes mode and watermark"),
                configureOk && readControlOk &&
                    (fifoControl & FIFO_MODE_MASK) ==
                        static_cast<uint8_t>(mode << 6) &&
                    (fifoControl & FIFO_WATERMARK_MASK) == 4);
    reportCheck(F("configureFIFO() sets FIFO_EN"),
                readCtrl5Ok && (ctrl5 & CTRL_REG5_FIFO_EN_MASK) != 0);

    readAndPrintFifoStatus(F("FIFO status"));

    if (mode == LIS3DH_FIFO_STREAM) {
      delay(220);
      readAndPrintFifoStatus(F("FIFO status after accumulation"));

      int16_t samples[3 * 2] = {};
      uint8_t samplesRead = 0;
      const bool readSamplesOk = sensor.readFifoSamples(2, samples, samplesRead);
      Serial.print(F("      readFifoSamples() returned "));
      Serial.print(samplesRead);
      Serial.println(F(" sample set(s)"));
      if (samplesRead > 0) {
        Serial.print(F("      first FIFO raw sample=("));
        Serial.print(samples[0]);
        Serial.print(',');
        Serial.print(samples[1]);
        Serial.print(',');
        Serial.print(samples[2]);
        Serial.println(')');
      }
      reportCheck(F("readFifoSamples() retrieves requested capacity"),
                  readSamplesOk && samplesRead <= 2);

      uint8_t discardedCount = 0;
      const bool nullBufferRejected =
          !sensor.readFifoSamples(1, nullptr, discardedCount);
      reportCheck(F("readFifoSamples() rejects a null output buffer"),
                  nullBufferRejected);

      reportCheck(F("drainFIFO() empties the remaining FIFO samples"),
                  sensor.drainFIFO());
    }

    reportCheck(F("disable FIFO before selecting the next mode"),
                sensor.configureFIFO(false, LIS3DH_FIFO_BYPASS, 0));
  }
}

void testInterruptsAndEvents() {
  Serial.println(F("\n[TEST] INT1/INT2 routing, event registers and source reads"));

  uint8_t ctrl3Before = 0;
  uint8_t ctrl6Before = 0;
  const bool routingSaved = readRegisterValue(LIS3DH_REG_CTRL_REG3, ctrl3Before) &&
                            readRegisterValue(LIS3DH_REG_CTRL_REG6, ctrl6Before);
  const bool routingWrite = sensor.configureInterrupts(0x40, 0x20);
  uint8_t ctrl3Read = 0;
  uint8_t ctrl6Read = 0;
  const bool routingRead = readRegisterValue(LIS3DH_REG_CTRL_REG3, ctrl3Read) &&
                           readRegisterValue(LIS3DH_REG_CTRL_REG6, ctrl6Read);
  reportCheck(F("configureInterrupts() writes INT1/INT2 routing"),
              routingSaved && routingWrite && routingRead &&
                  ctrl3Read == 0x40 && ctrl6Read == 0x20);

  const uint8_t int1Source = sensor.readInt1Src();
  printRegisterValue(F("INT1_SRC"), int1Source);
  reportCheck(F("readInt1Src() reads the INT1 event source"), int1Source != 0xFF);

  const int int2ReadResult = sensor.readRegister(LIS3DH_REG_INT2_SRC);
  const uint8_t int2Source = int2ReadResult < 0
                                 ? 0xFF
                                 : static_cast<uint8_t>(int2ReadResult);
  printRegisterValue(F("INT2_SRC"), int2Source);
  reportCheck(F("generic readRegister() reaches INT2_SRC"), int2Source != 0xFF);

  uint8_t int1CfgBefore = 0;
  uint8_t int1ThsBefore = 0;
  uint8_t int1DurationBefore = 0;
  const bool int1Saved = readRegisterValue(LIS3DH_REG_INT1_CFG, int1CfgBefore) &&
                         readRegisterValue(LIS3DH_REG_INT1_THS, int1ThsBefore) &&
                         readRegisterValue(LIS3DH_REG_INT1_DURATION,
                                           int1DurationBefore);
  const bool int1Write = int1Saved &&
                         sensor.writeRegister(LIS3DH_REG_INT1_CFG, 0x2A) &&
                         sensor.writeRegister(LIS3DH_REG_INT1_THS, 0x10) &&
                         sensor.writeRegister(LIS3DH_REG_INT1_DURATION, 0x02);
  uint8_t int1CfgRead = 0;
  uint8_t int1ThsRead = 0;
  uint8_t int1DurationRead = 0;
  const bool int1Read = int1Write &&
                        readRegisterValue(LIS3DH_REG_INT1_CFG, int1CfgRead) &&
                        readRegisterValue(LIS3DH_REG_INT1_THS, int1ThsRead) &&
                        readRegisterValue(LIS3DH_REG_INT1_DURATION,
                                          int1DurationRead);
  reportCheck(F("generic access covers INT1 configuration registers"),
              int1Read && int1CfgRead == 0x2A && int1ThsRead == 0x10 &&
                  int1DurationRead == 0x02);
  if (int1Saved) {
    sensor.writeRegister(LIS3DH_REG_INT1_CFG, int1CfgBefore);
    sensor.writeRegister(LIS3DH_REG_INT1_THS, int1ThsBefore);
    sensor.writeRegister(LIS3DH_REG_INT1_DURATION, int1DurationBefore);
  }

  uint8_t int2CfgBefore = 0;
  uint8_t int2ThsBefore = 0;
  uint8_t int2DurationBefore = 0;
  const bool int2Saved = readRegisterValue(LIS3DH_REG_INT2_CFG, int2CfgBefore) &&
                         readRegisterValue(LIS3DH_REG_INT2_THS, int2ThsBefore) &&
                         readRegisterValue(LIS3DH_REG_INT2_DURATION,
                                           int2DurationBefore);
  const bool int2Write = int2Saved &&
                         sensor.writeRegister(LIS3DH_REG_INT2_CFG, 0x15) &&
                         sensor.writeRegister(LIS3DH_REG_INT2_THS, 0x11) &&
                         sensor.writeRegister(LIS3DH_REG_INT2_DURATION, 0x03);
  uint8_t int2CfgRead = 0;
  uint8_t int2ThsRead = 0;
  uint8_t int2DurationRead = 0;
  const bool int2Read = int2Write &&
                        readRegisterValue(LIS3DH_REG_INT2_CFG, int2CfgRead) &&
                        readRegisterValue(LIS3DH_REG_INT2_THS, int2ThsRead) &&
                        readRegisterValue(LIS3DH_REG_INT2_DURATION,
                                          int2DurationRead);
  reportCheck(F("generic access covers INT2 configuration registers"),
              int2Read && int2CfgRead == 0x15 && int2ThsRead == 0x11 &&
                  int2DurationRead == 0x03);
  if (int2Saved) {
    sensor.writeRegister(LIS3DH_REG_INT2_CFG, int2CfgBefore);
    sensor.writeRegister(LIS3DH_REG_INT2_THS, int2ThsBefore);
    sensor.writeRegister(LIS3DH_REG_INT2_DURATION, int2DurationBefore);
  }

  uint8_t clickCfgBefore = 0;
  uint8_t clickThsBefore = 0;
  uint8_t timeLimitBefore = 0;
  uint8_t timeLatencyBefore = 0;
  uint8_t timeWindowBefore = 0;
  const bool clickSaved = readRegisterValue(LIS3DH_REG_CLICK_CFG, clickCfgBefore) &&
                          readRegisterValue(LIS3DH_REG_CLICK_THS, clickThsBefore) &&
                          readRegisterValue(LIS3DH_REG_TIME_LIMIT, timeLimitBefore) &&
                          readRegisterValue(LIS3DH_REG_TIME_LATENCY,
                                            timeLatencyBefore) &&
                          readRegisterValue(LIS3DH_REG_TIME_WINDOW,
                                            timeWindowBefore);
  const bool clickWrite = clickSaved &&
                          sensor.writeRegister(LIS3DH_REG_CLICK_CFG, 0x15) &&
                          sensor.writeRegister(LIS3DH_REG_CLICK_THS, 0x12) &&
                          sensor.writeRegister(LIS3DH_REG_TIME_LIMIT, 0x04) &&
                          sensor.writeRegister(LIS3DH_REG_TIME_LATENCY, 0x08) &&
                          sensor.writeRegister(LIS3DH_REG_TIME_WINDOW, 0x20);
  uint8_t clickCfgRead = 0;
  uint8_t clickThsRead = 0;
  uint8_t timeLimitRead = 0;
  uint8_t timeLatencyRead = 0;
  uint8_t timeWindowRead = 0;
  const bool clickRead = clickWrite &&
                         readRegisterValue(LIS3DH_REG_CLICK_CFG, clickCfgRead) &&
                         readRegisterValue(LIS3DH_REG_CLICK_THS, clickThsRead) &&
                         readRegisterValue(LIS3DH_REG_TIME_LIMIT, timeLimitRead) &&
                         readRegisterValue(LIS3DH_REG_TIME_LATENCY,
                                           timeLatencyRead) &&
                         readRegisterValue(LIS3DH_REG_TIME_WINDOW,
                                           timeWindowRead);
  reportCheck(F("generic access covers click timing and threshold registers"),
              clickRead && clickCfgRead == 0x15 && clickThsRead == 0x12 &&
                  timeLimitRead == 0x04 && timeLatencyRead == 0x08 &&
                  timeWindowRead == 0x20);
  const uint8_t clickSource = sensor.readClickSrc();
  printRegisterValue(F("CLICK_SRC"), clickSource);
  reportCheck(F("readClickSrc() reads the click event source"), clickSource != 0xFF);
  if (clickSaved) {
    sensor.writeRegister(LIS3DH_REG_CLICK_CFG, clickCfgBefore);
    sensor.writeRegister(LIS3DH_REG_CLICK_THS, clickThsBefore);
    sensor.writeRegister(LIS3DH_REG_TIME_LIMIT, timeLimitBefore);
    sensor.writeRegister(LIS3DH_REG_TIME_LATENCY, timeLatencyBefore);
    sensor.writeRegister(LIS3DH_REG_TIME_WINDOW, timeWindowBefore);
  }

  uint8_t activityThresholdBefore = 0;
  uint8_t activityDurationBefore = 0;
  const bool activitySaved =
      readRegisterValue(LIS3DH_REG_ACT_THS, activityThresholdBefore) &&
      readRegisterValue(LIS3DH_REG_ACT_DUR, activityDurationBefore);
  const bool activityWrite = activitySaved &&
                             sensor.writeRegister(LIS3DH_REG_ACT_THS, 0x08) &&
                             sensor.writeRegister(LIS3DH_REG_ACT_DUR, 0x02);
  uint8_t activityThresholdRead = 0;
  uint8_t activityDurationRead = 0;
  const bool activityRead = activityWrite &&
                            readRegisterValue(LIS3DH_REG_ACT_THS,
                                              activityThresholdRead) &&
                            readRegisterValue(LIS3DH_REG_ACT_DUR,
                                              activityDurationRead);
  reportCheck(F("generic access covers activity threshold and duration"),
              activityRead && activityThresholdRead == 0x08 &&
                  activityDurationRead == 0x02);
  if (activitySaved) {
    sensor.writeRegister(LIS3DH_REG_ACT_THS, activityThresholdBefore);
    sensor.writeRegister(LIS3DH_REG_ACT_DUR, activityDurationBefore);
  }

  if (routingSaved) {
    reportCheck(F("restore INT1/INT2 routing registers"),
                sensor.writeRegister(LIS3DH_REG_CTRL_REG3, ctrl3Before) &&
                    sensor.writeRegister(LIS3DH_REG_CTRL_REG6, ctrl6Before));
  } else {
    reportCheck(F("save INT1/INT2 routing registers"), false);
  }

  Serial.print(F("      INT pins; INT1(GPIO12)="));
  Serial.print(digitalRead(INT1_PIN) ? F("HIGH") : F("LOW"));
  Serial.print(F("; INT2(GPIO13)="));
  Serial.println(digitalRead(INT2_PIN) ? F("HIGH") : F("LOW"));
}

void testFilterReferenceAndSdoControl() {
  Serial.println(F("\n[TEST] High-pass filter, reference and SDO pull-up control"));

  uint8_t filterBefore = 0;
  const bool filterSaved = readRegisterValue(LIS3DH_REG_CTRL_REG2, filterBefore);
  const bool filterWrite = filterSaved &&
                           sensor.writeRegister(LIS3DH_REG_CTRL_REG2, 0x1B);
  uint8_t filterRead = 0;
  const bool filterReadOk = filterWrite &&
                            readRegisterValue(LIS3DH_REG_CTRL_REG2, filterRead);
  reportCheck(F("generic access covers CTRL_REG2 filter fields"),
              filterReadOk && filterRead == 0x1B);
  if (filterSaved) {
    reportCheck(F("restore CTRL_REG2 after filter test"),
                sensor.writeRegister(LIS3DH_REG_CTRL_REG2, filterBefore));
  }

  uint8_t referenceBefore = 0;
  const bool referenceSaved = readRegisterValue(LIS3DH_REG_REFERENCE,
                                                referenceBefore);
  const bool referenceWrite = referenceSaved &&
                              sensor.writeRegister(LIS3DH_REG_REFERENCE, 0x66);
  uint8_t referenceRead = 0;
  const bool referenceReadOk = referenceWrite &&
                               readRegisterValue(LIS3DH_REG_REFERENCE,
                                                 referenceRead);
  reportCheck(F("generic access covers REFERENCE baseline register"),
              referenceReadOk && referenceRead == 0x66);
  if (referenceSaved) {
    reportCheck(F("restore REFERENCE after filter test"),
                sensor.writeRegister(LIS3DH_REG_REFERENCE, referenceBefore));
  }

  const bool clearPullupOk = sensor.setSDOPullupDisconnect(false);
  const bool clearPullupBit = checkRegisterBits(F("setSDOPullupDisconnect(false)"),
                                                LIS3DH_REG_CTRL_REG0,
                                                CTRL_REG0_SDO_PU_DISC_MASK,
                                                0x00);
  reportCheck(F("setSDOPullupDisconnect() clears the internal SDO pull-up"),
              clearPullupOk && clearPullupBit);

  if (RUN_SDO_PULLUP_DISCONNECT_SET) {
    const bool setPullupOk = sensor.setSDOPullupDisconnect(true);
    const bool setPullupBit = checkRegisterBits(
        F("setSDOPullupDisconnect(true)"),
        LIS3DH_REG_CTRL_REG0,
        CTRL_REG0_SDO_PU_DISC_MASK,
        CTRL_REG0_SDO_PU_DISC_MASK);
    reportCheck(F("setSDOPullupDisconnect(true) sets SDO_PU_DISC"),
                setPullupOk && setPullupBit);
  } else {
    reportSkip(F("setSDOPullupDisconnect(true) is disabled because SA0/SDO wiring is board-dependent"));
  }
}

void printSelfTestDelta(int16_t baseX,
                        int16_t baseY,
                        int16_t baseZ,
                        int16_t testX,
                        int16_t testY,
                        int16_t testZ) {
  Serial.print(F("      self-test delta=("));
  Serial.print(static_cast<int32_t>(testX) - baseX);
  Serial.print(',');
  Serial.print(static_cast<int32_t>(testY) - baseY);
  Serial.print(',');
  Serial.print(static_cast<int32_t>(testZ) - baseZ);
  Serial.println(')');
}

void testSelfTestAndReboot() {
  Serial.println(F("\n[TEST] Self-test modes and memory reboot"));

  sensor.setODR(LIS3DH_ODR_100HZ);
  sensor.setFullScale(LIS3DH_FS_2G);
  sensor.setPowerMode(false, false, TEST_ODR_HZ);
  sensor.enableAxis(true, true, true);
  sensor.setBDU(true);
  sensor.selfTest(0, TEST_ODR_HZ);
  delay(30);

  int16_t baseX = 0;
  int16_t baseY = 0;
  int16_t baseZ = 0;
  const bool baselineOk = sensor.readRaw(baseX, baseY, baseZ);
  Serial.print(F("      baseline raw=("));
  Serial.print(baseX);
  Serial.print(',');
  Serial.print(baseY);
  Serial.print(',');
  Serial.print(baseZ);
  Serial.println(')');
  reportCheck(F("readRaw() provides a self-test baseline"), baselineOk);

  const uint8_t selfTestModes[] = {1, 2};
  for (const uint8_t mode : selfTestModes) {
    const bool modeOk = sensor.selfTest(mode, TEST_ODR_HZ);
    uint8_t ctrl4 = 0;
    const bool readOk = readRegisterValue(LIS3DH_REG_CTRL_REG4, ctrl4);
    const uint8_t expected = static_cast<uint8_t>(mode << 1);
    reportCheck(F("selfTest() selects the requested mode"),
                modeOk && readOk && (ctrl4 & CTRL_REG4_ST_MASK) == expected);

    int16_t testX = 0;
    int16_t testY = 0;
    int16_t testZ = 0;
    const bool sampleOk = sensor.readRaw(testX, testY, testZ);
    if (sampleOk) {
      Serial.print(F("      self-test mode "));
      Serial.print(mode);
      Serial.print(F(" raw=("));
      Serial.print(testX);
      Serial.print(',');
      Serial.print(testY);
      Serial.print(',');
      Serial.print(testZ);
      Serial.println(')');
      if (baselineOk) {
        printSelfTestDelta(baseX, baseY, baseZ, testX, testY, testZ);
      }
    }
    reportCheck(F("readRaw() remains available during self-test"), sampleOk);
  }

  const bool normalSelfTest = sensor.selfTest(0, TEST_ODR_HZ);
  const bool selfTestBitsCleared = checkRegisterBits(F("self-test bits cleared"),
                                                     LIS3DH_REG_CTRL_REG4,
                                                     CTRL_REG4_ST_MASK,
                                                     0x00);
  reportCheck(F("selfTest(0) returns to normal operation"),
              normalSelfTest && selfTestBitsCleared);
  reportCheck(F("selfTest() rejects an invalid mode"),
              !sensor.selfTest(3, TEST_ODR_HZ));

  const bool highResolutionMode = sensor.setPowerMode(false, true, TEST_ODR_HZ);
  const bool highResolutionSelfTest = highResolutionMode &&
                                      sensor.selfTest(1, TEST_ODR_HZ);
  reportCheck(F("selfTest() applies the high-resolution timing path"),
              highResolutionSelfTest);
  const bool highResolutionCleared = sensor.selfTest(0, TEST_ODR_HZ);
  const bool backToNormal = sensor.setPowerMode(false, false, TEST_ODR_HZ);
  reportCheck(F("selfTest() clears high-resolution test mode"),
              highResolutionCleared && backToNormal);

  const bool rebootOk = sensor.reboot();
  reportCheck(F("reboot() requests factory-memory reload"), rebootOk);
  delay(10);
  const uint8_t whoAfterReboot = sensor.whoAmI();
  printRegisterValue(F("WHO_AM_I after reboot"), whoAfterReboot);
  reportCheck(F("communication recovers after reboot()"),
              whoAfterReboot == EXPECTED_WHO_AM_I);
  deviceReady = whoAfterReboot == EXPECTED_WHO_AM_I;
}

void testBeginSpiApi() {
  Serial.println(F("\n[TEST] SPI API availability"));

  // Verify the declared/linkable API without switching the live device away
  // from the supplied I2C wiring.
  bool (LIS3DH::*beginSpiApi)(uint8_t, SPIClass &, bool) = &LIS3DH::beginSPI;
  reportCheck(F("beginSPI() is declared and linkable"), beginSpiApi != nullptr);
  reportSkip(F("beginSPI() hardware test; no SPI pins or chip-select wiring were supplied"));
}

void printChecklistSummary() {
  Serial.println(F("\n[SUMMARY] LIS3DH 5mini checklist"));
  Serial.print(F("  checks="));
  Serial.print(checkCount);
  Serial.print(F("; passed="));
  Serial.print(passCount);
  Serial.print(F("; failed="));
  Serial.print(failCount);
  Serial.print(F("; skipped="));
  Serial.println(skipCount);
  if (failCount == 0) {
    Serial.println(F("  Result: PASS; review documented hardware skips."));
  } else {
    Serial.println(F("  Result: FAIL; inspect the failed items above."));
  }
}

void runFullChecklist() {
  ++checklistNumber;
  resetChecklistCounters();

  Serial.println();
  Serial.println(F("============================================================"));
  Serial.print(F("LIS3DH 5mini driver checklist #"));
  Serial.println(checklistNumber);
  Serial.println(F("I2C: SDA=GPIO0, SCL=GPIO1; INT1=GPIO12; INT2=GPIO13"));
  Serial.println(F("Full checklist period: 20 s; monitor period: 2 s."));
  Serial.println(F("============================================================"));

  if (!ensureSensor()) {
    reportCheck(F("I2C initialization and WHO_AM_I identity"), false);
    reportSkip(F("register, configuration and measurement checks because the sensor is unavailable"));
    reportSkip(F("SPI hardware test because the board wiring exposes I2C only"));
    printChecklistSummary();
    Serial.println(F("============================================================"));
    return;
  }
  reportCheck(F("I2C initialization and WHO_AM_I identity"), true);

  const bool baselineOk = restoreSafeConfiguration();
  reportInfo(baselineOk ? F("safe baseline configuration applied")
                        : F("safe baseline configuration reported an error"));

  testIdentityAndStatus();
  testConfiguration();
  testAcceleration();
  testAuxiliaryChannels();
  testFifo();
  testInterruptsAndEvents();
  testFilterReferenceAndSdoControl();
  testSelfTestAndReboot();
  testBeginSpiApi();

  const bool cleanupOk = restoreSafeConfiguration();
  reportCheck(F("restore safe periodic-monitor configuration"), cleanupOk);

  printChecklistSummary();
  Serial.println(F("============================================================"));
}

void printMonitor() {
  Serial.println();
  Serial.println(F("[MONITOR] LIS3DH periodic measurement and status"));
  Serial.print(F("  I2C address: 0x"));
  printHexByte(activeAddress);
  Serial.println();
  Serial.println(F("  Pins: SDA=GPIO0; SCL=GPIO1; INT1=GPIO12; INT2=GPIO13"));

  if (!ensureSensor()) {
    Serial.println(F("  Status: sensor not responding at 0x18 or 0x19"));
    Serial.println();
    return;
  }

  const uint8_t whoAmI = sensor.whoAmI();
  const uint8_t status = sensor.readStatus();
  int16_t rawX = 0;
  int16_t rawY = 0;
  int16_t rawZ = 0;
  const bool rawOk = sensor.readRaw(rawX, rawY, rawZ);
  float gx = 0.0f;
  float gy = 0.0f;
  float gz = 0.0f;
  const bool normalizedOk = sensor.readNormalized(gx, gy, gz);

  Serial.print(F("  WHO_AM_I: 0x"));
  printHexByte(whoAmI);
  Serial.println(whoAmI == EXPECTED_WHO_AM_I ? F(" (OK)") : F(" (CHECK)"));

  Serial.print(F("  STATUS_REG: 0x"));
  printHexByte(status);
  Serial.print(F("; ZYXDA="));
  printBoolean(status != 0xFF && (status & STATUS_ZYXDA_MASK) != 0);
  Serial.println();

  if (rawOk && normalizedOk) {
    printMeasurement(F("measurement"), rawX, rawY, rawZ, gx, gy, gz);
  } else {
    Serial.println(F("      measurement: read error"));
  }

  const uint8_t int1Source = sensor.readInt1Src();
  const int int2Raw = sensor.readRegister(LIS3DH_REG_INT2_SRC);
  const uint8_t int2Source = int2Raw < 0 ? 0xFF : static_cast<uint8_t>(int2Raw);
  const uint8_t clickSource = sensor.readClickSrc();
  Serial.print(F("  INT1: pin="));
  Serial.print(digitalRead(INT1_PIN) ? F("HIGH") : F("LOW"));
  Serial.print(F("; SRC=0x"));
  printHexByte(int1Source);
  Serial.println();
  Serial.print(F("  INT2: pin="));
  Serial.print(digitalRead(INT2_PIN) ? F("HIGH") : F("LOW"));
  Serial.print(F("; SRC=0x"));
  printHexByte(int2Source);
  Serial.println();
  Serial.print(F("  CLICK_SRC=0x"));
  printHexByte(clickSource);
  Serial.println(F("; source reads may clear latched events"));

  uint8_t fss = 0;
  bool watermark = false;
  bool overrun = false;
  bool empty = false;
  const bool fifoOk = sensor.readFifoStatusParsed(fss, watermark, overrun, empty);
  if (fifoOk) {
    printFifoStatus(fss, watermark, overrun, empty);
  } else {
    Serial.println(F("  FIFO: status read error"));
  }

  const uint8_t auxStatus = sensor.readStatusAux();
  Serial.print(F("  STATUS_REG_AUX: 0x"));
  printHexByte(auxStatus);
  Serial.println();

  const bool communicationOk = whoAmI == EXPECTED_WHO_AM_I && status != 0xFF &&
                               rawOk && normalizedOk && int1Source != 0xFF &&
                               int2Source != 0xFF && clickSource != 0xFF && fifoOk;
  Serial.print(F("  Communication: "));
  Serial.println(communicationOk ? F("OK") : F("CHECK"));
  Serial.println();

  if (!communicationOk) {
    deviceReady = false;
  }
}

void setup() {
  pinMode(INT1_PIN, INPUT);
  pinMode(INT2_PIN, INPUT);

  Serial.begin(115200);
  const uint32_t serialStart = millis();
  while (!Serial && static_cast<uint32_t>(millis() - serialStart) < 3000UL) {
    delay(10);
  }

  Serial.println(F("\nLIS3DH 5mini driver hardware test"));
  Serial.println(F("Serial output is in English for reproducible test logs."));

  Wire.setSDA(I2C_SDA_PIN);
  Wire.setSCL(I2C_SCL_PIN);
  Wire.begin();
  delay(10);

  runFullChecklist();
  lastChecklistMs = millis();
  lastMonitorMs = millis() - MONITOR_INTERVAL_MS;
}

void loop() {
  const uint32_t now = millis();

  if (static_cast<uint32_t>(now - lastMonitorMs) >= MONITOR_INTERVAL_MS) {
    lastMonitorMs = now;
    printMonitor();
  }

  if (static_cast<uint32_t>(now - lastChecklistMs) >= FULL_CHECKLIST_INTERVAL_MS) {
    lastChecklistMs = now;
    runFullChecklist();
    lastChecklistMs = millis();
  }
}
