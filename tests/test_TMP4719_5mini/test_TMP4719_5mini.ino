#include <Wire.h>
#include <math.h>
#include <limits.h>

#include "TMP4719.h"

constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 1;
constexpr uint8_t ALERT_PIN = 10;
constexpr uint8_t TCRIT_PIN = 11;
constexpr uint8_t TMP4719_I2C_ADDRESS = 0x4D;

constexpr int8_t ALERT_ACTIVE_LEVEL = LOW;
constexpr int8_t TCRIT_ACTIVE_LEVEL = LOW;

// This reflects the currently connected board wiring.
constexpr bool REMOTE_CH1_CONNECTED = true;
constexpr bool REMOTE_CH2_CONNECTED = false;

constexpr unsigned long FULL_API_TEST_INTERVAL_MS = 10000UL;
constexpr unsigned long ONE_SHOT_TIMEOUT_MS = 1500UL;
constexpr uint8_t DEFAULT_HYSTERESIS_C = 1;
constexpr int8_t DEFAULT_ALERT_HIGH_C = 35;
constexpr int8_t DEFAULT_ALERT_LOW_C = 0;
constexpr int8_t DEFAULT_TCRIT_C = 35;
constexpr uint8_t ALERT_MASK_OFF = 0x00;
constexpr uint8_t ALERT_MASK_ALL_CHANNELS = 0x07;

constexpr uint8_t SCRATCHPAD1_TEST_VALUE = 0xA5;
constexpr uint8_t SCRATCHPAD2_TEST_VALUE = 0x5A;

TMP4719 sensor;
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

void printHex16(uint16_t value) {
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

bool configureDefaultTestState() {
  int16_t configuration = sensor.readConfiguration();
  if (configuration < 0) {
    return false;
  }

  uint8_t configurationByte = static_cast<uint8_t>(configuration);
  configurationByte &= static_cast<uint8_t>(~TMP4719_CFG_ALERT_MASK_BIT);
  configurationByte |= TMP4719_CFG_ALERT_MODE_COMP;

  if (!sensor.writeConfiguration(configurationByte)) {
    return false;
  }
  if (!sensor.writeAlertMask(ALERT_MASK_OFF)) {
    return false;
  }
  if (!sensor.setHysteresis(DEFAULT_HYSTERESIS_C)) {
    return false;
  }

  if (!sensor.setLocalTHigh(DEFAULT_ALERT_HIGH_C) ||
      !sensor.setLocalTLow(DEFAULT_ALERT_LOW_C)) {
    return false;
  }
  if (!sensor.setRemoteTHigh(1, DEFAULT_ALERT_HIGH_C) ||
      !sensor.setRemoteTLow(1, DEFAULT_ALERT_LOW_C)) {
    return false;
  }
  if (!sensor.setRemoteTHigh(2, DEFAULT_ALERT_HIGH_C) ||
      !sensor.setRemoteTLow(2, DEFAULT_ALERT_LOW_C)) {
    return false;
  }

  if (!sensor.setTHighCritLocal(DEFAULT_TCRIT_C) ||
      !sensor.setTHighCritRemote(1, DEFAULT_TCRIT_C) ||
      !sensor.setTHighCritRemote(2, DEFAULT_TCRIT_C)) {
    return false;
  }

  return true;
}

void testInitializationAndAddress() {
  Serial.println();
  Serial.println("[TEST] Initialization and I2C address");

  reportResult("begin(&Wire, false)", sensor.begin(&Wire, false));
  reportResult("begin(&Wire, true)", sensor.begin(&Wire, true));

  sensor.setAddress(TMP4719_I2C_ADDRESS);
  reportResult("setAddress(0x4D) preserves communication",
               sensor.readChipID() >= 0);
  reportInfo("setAddress() has no getter; communication after restoring 0x4D is used as indirect verification.");
}

void testIdentification() {
  Serial.println();
  Serial.println("[TEST] Device identification");

  const int16_t chipId = sensor.readChipID();
  const int16_t vendorId = sensor.readVendorID();
  const int16_t revisionId = sensor.readDeviceRevID();

  reportResult("readChipID()", chipId >= 0);
  reportResult("readVendorID()", vendorId >= 0);
  reportResult("readDeviceRevID()", revisionId >= 0);

  if (chipId >= 0 && vendorId >= 0 && revisionId >= 0) {
    Serial.print("  Chip ID: 0x");
    printHex16(static_cast<uint16_t>(chipId));
    Serial.print("; Vendor ID: 0x");
    printHex16(static_cast<uint16_t>(vendorId));
    Serial.print("; Revision: 0x");
    printHex16(static_cast<uint16_t>(revisionId));
    Serial.println();
  }
}

void testLowLevelRegisterAccess() {
  Serial.println();
  Serial.println("[TEST] Low-level register access");

  uint8_t chipId = 0;
  reportResult("readRegister(CHIP_ID, &value)",
               sensor.readRegister(TMP4719_REG_CHIP_ID, &chipId));
  reportResult("readRegister(CHIP_ID, nullptr)",
               sensor.readRegister(TMP4719_REG_CHIP_ID, nullptr));

  const int16_t originalScratchpad = sensor.readScratchpad1();
  if (originalScratchpad < 0) {
    reportSkip("writeRegister() readback because Scratchpad1 could not be read");
    return;
  }

  reportResult("writeRegister(SCRATCHPAD1)",
               sensor.writeRegister(TMP4719_REG_SCRATCHPAD1,
                                    SCRATCHPAD1_TEST_VALUE));

  uint8_t observedValue = 0;
  const bool readbackOk = sensor.readRegister(
      TMP4719_REG_SCRATCHPAD1, &observedValue);
  reportResult("readRegister(SCRATCHPAD1) after write",
               readbackOk && observedValue == SCRATCHPAD1_TEST_VALUE);

  reportResult("restore Scratchpad1 through writeRegister()",
               sensor.writeRegister(TMP4719_REG_SCRATCHPAD1,
                                    static_cast<uint8_t>(originalScratchpad)));
}

void testTemperatureReads() {
  Serial.println();
  Serial.println("[TEST] Temperature reads and raw conversions");

  int8_t localRaw = 0;
  const bool localRawOk = sensor.readLocalTemperatureRaw(localRaw);
  reportResult("readLocalTemperatureRaw(int8_t &)", localRawOk);

  const int8_t localRawConvenience = sensor.readLocalTemperatureRaw();
  reportResult("readLocalTemperatureRaw()", localRawConvenience != INT8_MIN);

  const float localTemperatureC = sensor.readLocalTemperatureC();
  reportResult("readLocalTemperatureC()", !isnan(localTemperatureC));

  if (localRawOk) {
    reportResult("local raw overloads agree",
                 localRaw == localRawConvenience &&
                     approximatelyEqual(localTemperatureC,
                                        static_cast<float>(localRaw)));
    Serial.print("  Local: ");
    Serial.print(localTemperatureC, 2);
    Serial.println(" C");
  }

  reportResult("decodeLocalRaw(0x7F) returns 127 C",
               TMP4719::decodeLocalRaw(0x7F) == 127);
  reportResult("decodeLocalRaw(0x80) returns -128 C",
               TMP4719::decodeLocalRaw(0x80) == -128);

  const int16_t remote1Raw = sensor.readRemoteTemperatureRaw(1);
  const int16_t remote2Raw = sensor.readRemoteTemperatureRaw(2);
  reportResult("readRemoteTemperatureRaw(CH1)", remote1Raw != INT16_MIN);
  reportResult("readRemoteTemperatureRaw(CH2)", remote2Raw != INT16_MIN);
  reportExpectedFalse("readRemoteTemperatureRaw(invalid channel) rejects channel 0",
                     sensor.readRemoteTemperatureRaw(0) != INT16_MIN);

  const float remote1TemperatureC = sensor.readRemoteTemperatureC(1);
  const float remote2TemperatureC = sensor.readRemoteTemperatureC(2);
  const float invalidTemperatureC = sensor.readRemoteTemperatureC(3);

  reportResult("readRemoteTemperatureC(CH1)", !isnan(remote1TemperatureC));
  if (REMOTE_CH2_CONNECTED) {
    reportResult("readRemoteTemperatureC(CH2)", !isnan(remote2TemperatureC));
  } else {
    reportResult("readRemoteTemperatureC(CH2) reports diode fault",
                 isnan(remote2TemperatureC));
  }
  reportResult("readRemoteTemperatureC(invalid channel) returns NaN",
               isnan(invalidTemperatureC));

  Serial.print("  Remote CH1 raw: ");
  Serial.print(remote1Raw);
  Serial.print("; temperature: ");
  Serial.print(remote1TemperatureC, 4);
  Serial.println(" C");
  Serial.print("  Remote CH2 raw: ");
  Serial.print(remote2Raw);
  Serial.print("; temperature: ");
  if (isnan(remote2TemperatureC)) {
    Serial.print("NaN");
  } else {
    Serial.print(remote2TemperatureC, 4);
  }
  Serial.println(" C");
}

void testConversionHelpers() {
  Serial.println();
  Serial.println("[TEST] Static conversion helpers");

  reportResult("decodeRemoteRawToFloat(400) returns 25 C",
               approximatelyEqual(TMP4719::decodeRemoteRawToFloat(400),
                                  25.0f));
  reportResult("decodeRemoteRawToFloat(-200) returns -12.5 C",
               approximatelyEqual(TMP4719::decodeRemoteRawToFloat(-200),
                                  -12.5f));

  uint8_t highByte = 0;
  uint8_t lowByte = 0;
  const bool encodeOk = TMP4719::encodeFloatToRemoteRaw12(
      25.0f, &highByte, &lowByte);
  const int16_t reconstructedRaw = static_cast<int16_t>(
      (static_cast<uint16_t>(highByte) << 4) | (lowByte >> 4));
  reportResult("encodeFloatToRemoteRaw12(25 C)", encodeOk);
  reportResult("encode/decode remote 25 C round-trip",
               encodeOk && reconstructedRaw == 400 &&
                   approximatelyEqual(
                       TMP4719::decodeRemoteRawToFloat(reconstructedRaw),
                       25.0f));

  reportExpectedFalse("encodeFloatToRemoteRaw12() rejects null high pointer",
                     TMP4719::encodeFloatToRemoteRaw12(25.0f, nullptr,
                                                       &lowByte));
  reportExpectedFalse("encodeFloatToRemoteRaw12() rejects null low pointer",
                     TMP4719::encodeFloatToRemoteRaw12(25.0f, &highByte,
                                                       nullptr));
}

void testConversionPeriod() {
  Serial.println();
  Serial.println("[TEST] Conversion period");

  const int16_t originalCode = sensor.getConvPeriodCode();
  reportResult("getConvPeriodCode()", originalCode >= 0 && originalCode <= 15);
  if (originalCode < 0 || originalCode > 15) {
    reportSkip("conversion period round-trip");
    return;
  }

  const uint8_t testCodes[] = {
      TMP4719_CONV_16S,
      TMP4719_CONV_0_25S,
      TMP4719_CONV_1S_ALT,
      0x0F};

  for (const uint8_t code : testCodes) {
    const bool setOk = sensor.setConvPeriodCode(code);
    reportResult("setConvPeriodCode(valid nibble)", setOk);

    const int16_t observedCode = sensor.getConvPeriodCode();
    reportResult("getConvPeriodCode() after write",
                 observedCode == static_cast<int16_t>(code));
  }

  reportResult("restore conversion period",
               sensor.setConvPeriodCode(static_cast<uint8_t>(originalCode)));
  reportInfo("Conversion codes 0x9-0xF are tested as valid register codes by this driver.");
}

void testStatusAndFaults() {
  Serial.println();
  Serial.println("[TEST] Status, polling, limit status, and diode faults");

  const int16_t rawStatus = sensor.readStatus();
  reportResult("readStatus()", rawStatus >= 0);

  const bool busy = sensor.isBusy();
  const bool high = sensor.isTHigh();
  const bool low = sensor.isTLow();
  const bool critical = sensor.isTCrit();

  if (rawStatus >= 0) {
    const uint8_t status = static_cast<uint8_t>(rawStatus);
    reportResult("isBusy() matches Status.ADC_Busy",
                 busy == ((status & TMP4719_STATUS_ADC_BUSY_BIT) != 0));
    reportResult("isTHigh() matches Status.THigh",
                 high == ((status & TMP4719_STATUS_THIGH_BIT) != 0));
    reportResult("isTLow() matches Status.TLow",
                 low == ((status & TMP4719_STATUS_TLOW_BIT) != 0));
    reportResult("isTCrit() matches Status.TCrit",
                 critical == ((status & TMP4719_STATUS_TCRIT_BIT) != 0));

    Serial.print("  Status: 0x");
    printHex8(status);
    Serial.println();
  } else {
    reportSkip("status accessor comparisons");
  }

  const int16_t highLimitStatus = sensor.readHighLimitStatus();
  const int16_t lowLimitStatus = sensor.readLowLimitStatus();
  const int16_t tcritLimitStatus = sensor.readTcritStatus();
  reportResult("readHighLimitStatus()", highLimitStatus >= 0);
  reportResult("readLowLimitStatus()", lowLimitStatus >= 0);
  reportResult("readTcritStatus()", tcritLimitStatus >= 0);

  if (highLimitStatus >= 0 && lowLimitStatus >= 0 &&
      tcritLimitStatus >= 0) {
    Serial.print("  Limit status High/Low/T_CRIT: 0x");
    printHex8(static_cast<uint8_t>(highLimitStatus));
    Serial.print("/0x");
    printHex8(static_cast<uint8_t>(lowLimitStatus));
    Serial.print("/0x");
    printHex8(static_cast<uint8_t>(tcritLimitStatus));
    Serial.println();
  }

  const int16_t diodeFault = sensor.readDiodeFault();
  reportResult("readDiodeFault()", diodeFault >= 0);
  if (diodeFault >= 0) {
    const uint8_t faults = static_cast<uint8_t>(diodeFault);
    const bool ch1Open = (faults & TMP4719_DF_CH1_OPEN) != 0;
    const bool ch2Open = (faults & TMP4719_DF_CH2_OPEN) != 0;
    const bool remoteShort = (faults & TMP4719_DF_SHORT_BIT) != 0;

    Serial.print("  Diode fault raw: 0x");
    printHex8(faults);
    Serial.print("; CH1 open: ");
    printBoolean(ch1Open);
    Serial.print("; CH2 open: ");
    printBoolean(ch2Open);
    Serial.print("; short: ");
    printBoolean(remoteShort);
    Serial.println();

    reportResult("CH1 open state matches hardware",
                 ch1Open != REMOTE_CH1_CONNECTED);
    reportResult("CH2 open state matches hardware",
                 ch2Open != REMOTE_CH2_CONNECTED);
    reportResult("No remote short detected", !remoteShort);
  }
}

void testOperatingModeAndOneShot() {
  Serial.println();
  Serial.println("[TEST] Operating mode and one-shot conversion");

  const int16_t originalConfiguration = sensor.readConfiguration();
  const int16_t originalPeriod = sensor.getConvPeriodCode();
  reportResult("readConfiguration() for operating-mode test",
               originalConfiguration >= 0);
  reportResult("read conversion period for one-shot test",
               originalPeriod >= 0 && originalPeriod <= 15);

  if (originalConfiguration < 0 || originalPeriod < 0 ||
      originalPeriod > 15) {
    reportSkip("operating mode and one-shot round-trip");
    return;
  }

  const bool originalShutdown =
      (static_cast<uint8_t>(originalConfiguration) &
       TMP4719_CFG_MODE_SHUTDOWN) != 0;

  reportResult("setConvPeriodCode(0.25 s) for one-shot",
               sensor.setConvPeriodCode(TMP4719_CONV_0_25S));
  reportResult("setModeShutdown(true)", sensor.setModeShutdown(true));
  reportResult("getModeIsShutdown() after enabling shutdown",
               sensor.getModeIsShutdown());

  const bool oneShotOk = sensor.triggerOneShot();
  reportResult("triggerOneShot()", oneShotOk);
  if (oneShotOk) {
    reportResult("waitForConversion() after one-shot",
                 sensor.waitForConversion(ONE_SHOT_TIMEOUT_MS));
  }

  const bool zeroValueOneShotOk = sensor.triggerOneShot(0);
  reportResult("triggerOneShot(value=0)", zeroValueOneShotOk);
  if (zeroValueOneShotOk) {
    reportResult("waitForConversion() after value=0 one-shot",
                 sensor.waitForConversion(ONE_SHOT_TIMEOUT_MS));
  }

  reportResult("setModeShutdown(false)", sensor.setModeShutdown(false));
  reportResult("getModeIsShutdown() after disabling shutdown",
               !sensor.getModeIsShutdown());

  reportResult("restore original operating mode",
               sensor.setModeShutdown(originalShutdown));
  reportResult("restore original conversion period",
               sensor.setConvPeriodCode(static_cast<uint8_t>(originalPeriod)));
}

void testConfigurationAndAlertMask() {
  Serial.println();
  Serial.println("[TEST] Configuration, ALERT mode, and ALERT mask");

  const int16_t originalConfiguration = sensor.readConfiguration();
  const int16_t originalAlertMask = sensor.readAlertMask();
  reportResult("readConfiguration()", originalConfiguration >= 0);
  reportResult("readAlertMask()", originalAlertMask >= 0);

  if (originalConfiguration < 0 || originalAlertMask < 0) {
    reportSkip("configuration and ALERT mask round-trip");
    return;
  }

  const uint8_t originalConfigurationByte =
      static_cast<uint8_t>(originalConfiguration);
  reportResult("writeConfiguration(current value)",
               sensor.writeConfiguration(originalConfigurationByte));
  const int16_t sameConfiguration = sensor.readConfiguration();
  reportResult("readConfiguration() after write",
               sameConfiguration == originalConfiguration);

  uint8_t comparatorConfiguration = originalConfigurationByte;
  comparatorConfiguration &= static_cast<uint8_t>(
      ~TMP4719_CFG_ALERT_MASK_BIT);
  comparatorConfiguration |= TMP4719_CFG_ALERT_MODE_COMP;

  reportResult("set ALERT mode COMPARATOR and global mask OFF",
               sensor.writeConfiguration(comparatorConfiguration));
  int16_t observedConfiguration = sensor.readConfiguration();
  reportResult("verify COMPARATOR and global mask OFF",
               observedConfiguration >= 0 &&
                   (static_cast<uint8_t>(observedConfiguration) &
                    TMP4719_CFG_ALERT_MODE_COMP) != 0 &&
                   (static_cast<uint8_t>(observedConfiguration) &
                    TMP4719_CFG_ALERT_MASK_BIT) == 0);

  uint8_t interruptConfiguration = static_cast<uint8_t>(
      comparatorConfiguration & static_cast<uint8_t>(
          ~TMP4719_CFG_ALERT_MODE_COMP));
  reportResult("set ALERT mode INTERRUPT",
               sensor.writeConfiguration(interruptConfiguration));
  observedConfiguration = sensor.readConfiguration();
  reportResult("verify INTERRUPT mode",
               observedConfiguration >= 0 &&
                   (static_cast<uint8_t>(observedConfiguration) &
                    TMP4719_CFG_ALERT_MODE_COMP) == 0);

  uint8_t maskedConfiguration = static_cast<uint8_t>(
      comparatorConfiguration | TMP4719_CFG_ALERT_MASK_BIT);
  reportResult("enable global ALERT mask",
               sensor.writeConfiguration(maskedConfiguration));
  observedConfiguration = sensor.readConfiguration();
  reportResult("verify global ALERT mask enabled",
               observedConfiguration >= 0 &&
                   (static_cast<uint8_t>(observedConfiguration) &
                    TMP4719_CFG_ALERT_MASK_BIT) != 0);

  reportResult("writeAlertMask(all channels)",
               sensor.writeAlertMask(ALERT_MASK_ALL_CHANNELS));
  reportResult("readAlertMask() after enabling channel masks",
               sensor.readAlertMask() == ALERT_MASK_ALL_CHANNELS);

  reportResult("writeAlertMask(MASK_OFF)",
               sensor.writeAlertMask(ALERT_MASK_OFF));
  reportResult("readAlertMask() after disabling channel masks",
               sensor.readAlertMask() == ALERT_MASK_OFF);

  reportResult("restore COMPARATOR and global mask OFF",
               sensor.writeConfiguration(comparatorConfiguration));
  reportResult("restore ALERT channel masks OFF",
               sensor.writeAlertMask(ALERT_MASK_OFF));
  reportInfo("Final ALERT state is COMPARATOR with global and channel masks disabled.");
}

void testFilter() {
  Serial.println();
  Serial.println("[TEST] Digital filter");

  const int16_t originalLevel = sensor.getFilterLevel();
  reportResult("getFilterLevel()", originalLevel >= 0 && originalLevel <= 3);
  if (originalLevel < 0 || originalLevel > 3) {
    reportSkip("filter-level round-trip");
    return;
  }

  for (uint8_t level = 0; level <= 3; ++level) {
    reportResult("setFilterLevel(valid level)", sensor.setFilterLevel(level));
    reportResult("getFilterLevel() after write",
                 sensor.getFilterLevel() == static_cast<int16_t>(level));
  }

  reportExpectedFalse("setFilterLevel(4) rejects invalid level",
                     sensor.setFilterLevel(4));
  reportResult("restore filter level",
               sensor.setFilterLevel(static_cast<uint8_t>(originalLevel)));
}

void testHysteresis() {
  Serial.println();
  Serial.println("[TEST] ALERT and T_CRIT hysteresis");

  const int16_t originalValue = sensor.getHysteresis();
  reportResult("getHysteresis()", originalValue >= 0 && originalValue <= 31);
  if (originalValue < 0 || originalValue > 31) {
    reportSkip("hysteresis round-trip");
    return;
  }

  reportResult("setHysteresis(1 C)", sensor.setHysteresis(1));
  reportResult("getHysteresis() after setting 1 C",
               sensor.getHysteresis() == 1);
  reportResult("setHysteresis(31 C)", sensor.setHysteresis(31));
  reportResult("getHysteresis() after setting 31 C",
               sensor.getHysteresis() == 31);
  reportExpectedFalse("setHysteresis(32) rejects invalid value",
                     sensor.setHysteresis(32));
  reportResult("restore hysteresis",
               sensor.setHysteresis(static_cast<uint8_t>(originalValue)));
}

void testEtaFactorForChannel(uint8_t channel, const char *label) {
  const int16_t originalCode = sensor.getEtaFactorCode(channel);
  reportResult(label, originalCode >= 0 && originalCode <= 255);
  if (originalCode < 0 || originalCode > 255) {
    return;
  }

  const uint8_t testCode = static_cast<uint8_t>(
      originalCode == 0x13 ? 0x12 : 0x13);
  reportResult("setEtaFactor(valid code)",
               sensor.setEtaFactor(channel, testCode));
  reportResult("getEtaFactorCode() after write",
               sensor.getEtaFactorCode(channel) == testCode);
  reportResult("restore Eta factor",
               sensor.setEtaFactor(channel, static_cast<uint8_t>(originalCode)));
}

void testEtaFactors() {
  Serial.println();
  Serial.println("[TEST] Remote diode Eta factors");

  testEtaFactorForChannel(1, "getEtaFactorCode(CH1)");
  testEtaFactorForChannel(2, "getEtaFactorCode(CH2)");

  reportExpectedFalse("setEtaFactor(invalid channel)",
                     sensor.setEtaFactor(0, 0x12));
  reportExpectedFalse("getEtaFactorCode(invalid channel)",
                     sensor.getEtaFactorCode(0) >= 0);
}

void testLocalThresholds() {
  Serial.println();
  Serial.println("[TEST] Local ALERT thresholds");

  const int16_t originalHigh = sensor.getLocalTHigh();
  const int16_t originalLow = sensor.getLocalTLow();
  reportResult("getLocalTHigh()", originalHigh != INT16_MIN);
  reportResult("getLocalTLow()", originalLow != INT16_MIN);
  if (originalHigh == INT16_MIN || originalLow == INT16_MIN) {
    reportSkip("local threshold round-trip");
    return;
  }

  reportResult("setLocalTHigh(current value)",
               sensor.setLocalTHigh(static_cast<int8_t>(originalHigh)));
  reportResult("getLocalTHigh() after write",
               sensor.getLocalTHigh() == originalHigh);
  reportResult("setLocalTLow(current value)",
               sensor.setLocalTLow(static_cast<int8_t>(originalLow)));
  reportResult("getLocalTLow() after write",
               sensor.getLocalTLow() == originalLow);
}

void testRemoteThresholdsForChannel(uint8_t channel, const char *label) {
  const int16_t originalHigh = sensor.getRemoteTHighRaw(channel);
  const int16_t originalLow = sensor.getRemoteTLowRaw(channel);
  reportResult(label, originalHigh != INT16_MIN && originalLow != INT16_MIN);
  if (originalHigh == INT16_MIN || originalLow == INT16_MIN) {
    return;
  }

  const float originalHighC = TMP4719::decodeRemoteRawToFloat(originalHigh);
  const float originalLowC = TMP4719::decodeRemoteRawToFloat(originalLow);

  reportResult("setRemoteTHigh(current value)",
               sensor.setRemoteTHigh(channel, originalHighC));
  reportResult("getRemoteTHighRaw() after write",
               sensor.getRemoteTHighRaw(channel) == originalHigh);
  reportResult("setRemoteTLow(current value)",
               sensor.setRemoteTLow(channel, originalLowC));
  reportResult("getRemoteTLowRaw() after write",
               sensor.getRemoteTLowRaw(channel) == originalLow);
}

void testRemoteThresholds() {
  Serial.println();
  Serial.println("[TEST] Remote ALERT thresholds");

  testRemoteThresholdsForChannel(1, "CH1 remote thresholds");
  testRemoteThresholdsForChannel(2, "CH2 remote thresholds");

  reportExpectedFalse("setRemoteTHigh(invalid channel)",
                     sensor.setRemoteTHigh(0, 35.0f));
  reportExpectedFalse("setRemoteTLow(invalid channel)",
                     sensor.setRemoteTLow(3, 0.0f));
  reportExpectedFalse("getRemoteTHighRaw(invalid channel)",
                     sensor.getRemoteTHighRaw(0) != INT16_MIN);
  reportExpectedFalse("getRemoteTLowRaw(invalid channel)",
                     sensor.getRemoteTLowRaw(3) != INT16_MIN);
}

bool readSignedRegister(uint8_t reg, int8_t &value) {
  uint8_t raw = 0;
  if (!sensor.readRegister(reg, &raw)) {
    return false;
  }
  value = static_cast<int8_t>(raw);
  return true;
}

void testCriticalThresholds() {
  Serial.println();
  Serial.println("[TEST] T_CRIT thresholds");

  int8_t localValue = 0;
  bool localReadOk = readSignedRegister(TMP4719_REG_THIGH_CRIT_LOCAL,
                                        localValue);
  reportResult("read local T_CRIT register", localReadOk);
  if (localReadOk) {
    reportResult("setTHighCritLocal(current value)",
                 sensor.setTHighCritLocal(localValue));
    int8_t observed = 0;
    reportResult("read local T_CRIT after write",
                 readSignedRegister(TMP4719_REG_THIGH_CRIT_LOCAL, observed) &&
                     observed == localValue);
  }

  int8_t remote1Value = 0;
  bool remote1ReadOk = readSignedRegister(TMP4719_REG_THIGH_CRIT_REM_CH1,
                                          remote1Value);
  reportResult("read CH1 T_CRIT register", remote1ReadOk);
  if (remote1ReadOk) {
    reportResult("setTHighCritRemote(CH1, current value)",
                 sensor.setTHighCritRemote(1, remote1Value));
    int8_t observed = 0;
    reportResult("read CH1 T_CRIT after write",
                 readSignedRegister(TMP4719_REG_THIGH_CRIT_REM_CH1, observed) &&
                     observed == remote1Value);
  }

  int8_t remote2Value = 0;
  bool remote2ReadOk = readSignedRegister(TMP4719_REG_THIGH_CRIT_REM_CH2,
                                          remote2Value);
  reportResult("read CH2 T_CRIT register", remote2ReadOk);
  if (remote2ReadOk) {
    reportResult("setTHighCritRemote(CH2, current value)",
                 sensor.setTHighCritRemote(2, remote2Value));
    int8_t observed = 0;
    reportResult("read CH2 T_CRIT after write",
                 readSignedRegister(TMP4719_REG_THIGH_CRIT_REM_CH2, observed) &&
                     observed == remote2Value);
  }

  reportExpectedFalse("setTHighCritRemote(invalid channel)",
                     sensor.setTHighCritRemote(0, DEFAULT_TCRIT_C));
}

void testScratchpad(uint8_t index, uint8_t testValue) {
  int16_t originalValue = index == 1 ? sensor.readScratchpad1()
                                    : sensor.readScratchpad2();
  reportResult("readScratchpad(original)", originalValue >= 0);
  if (originalValue < 0) {
    return;
  }

  const bool writeOk = index == 1
                           ? sensor.writeScratchpad1(testValue)
                           : sensor.writeScratchpad2(testValue);
  reportResult("writeScratchpad(test value)", writeOk);

  const int16_t observedValue = index == 1 ? sensor.readScratchpad1()
                                           : sensor.readScratchpad2();
  reportResult("readScratchpad(test value)", observedValue == testValue);

  const bool restoreOk = index == 1
                             ? sensor.writeScratchpad1(
                                   static_cast<uint8_t>(originalValue))
                             : sensor.writeScratchpad2(
                                   static_cast<uint8_t>(originalValue));
  reportResult("restoreScratchpad(original value)", restoreOk);

  const int16_t restoredValue = index == 1 ? sensor.readScratchpad1()
                                           : sensor.readScratchpad2();
  reportResult("readScratchpad(restored value)",
               restoredValue == originalValue);
}

void testScratchpads() {
  Serial.println();
  Serial.println("[TEST] Scratchpads");

  testScratchpad(1, SCRATCHPAD1_TEST_VALUE);
  testScratchpad(2, SCRATCHPAD2_TEST_VALUE);
}

void testInvalidArguments() {
  Serial.println();
  Serial.println("[TEST] Input validation");

  reportExpectedFalse("readRemoteTemperatureRaw(invalid channel)",
                     sensor.readRemoteTemperatureRaw(0) != INT16_MIN);
  reportExpectedFalse("readRemoteTemperatureC(invalid channel)",
                     !isnan(sensor.readRemoteTemperatureC(3)));
  reportExpectedFalse("setFilterLevel(4) rejects invalid level",
                     sensor.setFilterLevel(4));
  reportExpectedFalse("setHysteresis(32) rejects invalid value",
                     sensor.setHysteresis(32));
  reportExpectedFalse("setEtaFactor(invalid channel)",
                     sensor.setEtaFactor(3, 0x12));
  reportExpectedFalse("getEtaFactorCode(invalid channel)",
                     sensor.getEtaFactorCode(3) >= 0);
  reportExpectedFalse("setRemoteTHigh(invalid channel)",
                     sensor.setRemoteTHigh(3, 35.0f));
  reportExpectedFalse("setRemoteTLow(invalid channel)",
                     sensor.setRemoteTLow(0, 0.0f));
  reportExpectedFalse("setTHighCritRemote(invalid channel)",
                     sensor.setTHighCritRemote(3, DEFAULT_TCRIT_C));

  uint8_t highByte = 0;
  reportExpectedFalse("encodeFloatToRemoteRaw12(null high pointer)",
                     TMP4719::encodeFloatToRemoteRaw12(25.0f, nullptr,
                                                       &highByte));
}

void runFullApiTest() {
  passCount = 0;
  failCount = 0;
  skipCount = 0;

  Serial.println();
  Serial.println("========================================");
  Serial.println("TMP4719 5mini full driver API test");
  Serial.println("========================================");

  testInitializationAndAddress();
  testIdentification();
  testLowLevelRegisterAccess();
  testTemperatureReads();
  testConversionHelpers();
  testConversionPeriod();
  testStatusAndFaults();
  testOperatingModeAndOneShot();
  testConfigurationAndAlertMask();
  testFilter();
  testHysteresis();
  testEtaFactors();
  testLocalThresholds();
  testRemoteThresholds();
  testCriticalThresholds();
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
  reportInfo("Default test state: ALERT COMPARATOR, global/channel ALERT masks OFF, hysteresis 1 C, ALERT/T_CRIT high limits 35 C.");
}

void runMonitorCycle() {
  Serial.println();
  Serial.println("--- Status monitor ---");

  const float localTemperatureC = sensor.readLocalTemperatureC();
  if (isnan(localTemperatureC)) {
    Serial.println("Local temperature: READ_ERROR");
  } else {
    Serial.print("Local temperature: ");
    Serial.print(localTemperatureC, 2);
    Serial.println(" C");
  }

  const float remote1TemperatureC = sensor.readRemoteTemperatureC(1);
  if (isnan(remote1TemperatureC)) {
    Serial.println("Remote CH1 temperature: READ_ERROR");
  } else {
    Serial.print("Remote CH1 temperature: ");
    Serial.print(remote1TemperatureC, 4);
    Serial.println(" C");
  }

  const float remote2TemperatureC = sensor.readRemoteTemperatureC(2);
  Serial.print("Remote CH2 temperature: ");
  if (isnan(remote2TemperatureC)) {
    Serial.print("NaN");
  } else {
    Serial.print(remote2TemperatureC, 4);
  }
  Serial.println(" C (unused channel)");

  const int alertLevel = digitalRead(ALERT_PIN);
  const int tcritLevel = digitalRead(TCRIT_PIN);

  const int16_t diodeFault = sensor.readDiodeFault();
  if (diodeFault < 0) {
    Serial.println("Diode fault flags: READ_ERROR");
  } else {
    Serial.print("Diode fault flags: 0x");
    printHex8(static_cast<uint8_t>(diodeFault));
    Serial.println();
  }

  const int16_t highLimitStatus = sensor.readHighLimitStatus();
  const int16_t lowLimitStatus = sensor.readLowLimitStatus();
  const int16_t tcritLimitStatus = sensor.readTcritStatus();
  if (highLimitStatus < 0 || lowLimitStatus < 0 || tcritLimitStatus < 0) {
    Serial.println("Limit flags: READ_ERROR");
  } else {
    Serial.print("Limit flags High/Low/T_CRIT: 0x");
    printHex8(static_cast<uint8_t>(highLimitStatus));
    Serial.print("/0x");
    printHex8(static_cast<uint8_t>(lowLimitStatus));
    Serial.print("/0x");
    printHex8(static_cast<uint8_t>(tcritLimitStatus));
    Serial.println();
  }

  const int16_t rawStatus = sensor.readStatus();
  if (rawStatus < 0) {
    Serial.println("Status: READ_ERROR");
    Serial.print("ALERT pin: ");
    Serial.println(alertLevel == HIGH ? "HIGH" : "LOW");
    Serial.print("T_CRIT pin: ");
    Serial.println(tcritLevel == HIGH ? "HIGH" : "LOW");
    return;
  }

  const uint8_t status = static_cast<uint8_t>(rawStatus);
  const bool adcBusy = (status & TMP4719_STATUS_ADC_BUSY_BIT) != 0;
  const bool anyHigh = (status & TMP4719_STATUS_THIGH_BIT) != 0;
  const bool anyLow = (status & TMP4719_STATUS_TLOW_BIT) != 0;
  const bool remoteFault = (status & TMP4719_STATUS_REMOTE_FAULT) != 0;
  const bool anyTCrit = (status & TMP4719_STATUS_TCRIT_BIT) != 0;

  Serial.print("ADC busy: ");
  printBoolean(adcBusy);
  Serial.print("; High: ");
  printBoolean(anyHigh);
  Serial.print("; Low: ");
  printBoolean(anyLow);
  Serial.print("; Remote fault: ");
  printBoolean(remoteFault);
  Serial.print("; T_CRIT: ");
  printBoolean(anyTCrit);
  Serial.println();

  printPinCheck("ALERT", alertLevel, ALERT_ACTIVE_LEVEL,
                anyHigh || anyLow);
  printPinCheck("T_CRIT", tcritLevel, TCRIT_ACTIVE_LEVEL, anyTCrit);
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
  Serial.println("TMP4719 RP2040 5mini test");
  Serial.print("I2C address: 0x");
  printHex8(TMP4719_I2C_ADDRESS);
  Serial.println();

  deviceReady = sensor.begin(&Wire, true);
  if (deviceReady) {
    Serial.println("TMP4719: READY");

    if (configureDefaultTestState()) {
      Serial.println("Default ALERT/T_CRIT test configuration applied.");
    } else {
      Serial.println("WARNING: default ALERT/T_CRIT test configuration failed.");
    }

    runFullApiTest();
    lastFullApiTestMs = millis();
  } else {
    Serial.println("TMP4719: BEGIN_ERROR");
  }
}

void loop() {
  if (!deviceReady) {
    deviceReady = sensor.begin(&Wire, true);
    if (!deviceReady) {
      delay(1000);
      return;
    }

    Serial.println("TMP4719: READY");
    configureDefaultTestState();
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
