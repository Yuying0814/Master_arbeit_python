/*
  TMP4719 local-driver test for RP2040.

  The driver implementation is included directly from code_TMP_local so that
  this sketch can be compiled without copying or modifying the driver files.
*/

#include <Wire.h>
#include <math.h>

#include "D:/python/master_arbeit/code_TMP_local/TMP4719/v2/TMP4719_Basic/TMP4719.h"
#include "D:/python/master_arbeit/code_TMP_local/TMP4719/v2/TMP4719_Basic/TMP4719.cpp"

// Board wiring.
static constexpr uint8_t I2C_SDA_PIN = 0;
static constexpr uint8_t I2C_SCL_PIN = 1;
static constexpr uint8_t ALERT_PIN = 10;
static constexpr uint8_t TCRIT_PIN = 11;

// This reflects the current board setup. Change only if the diode wiring is different.
static constexpr bool REMOTE_CH1_CONNECTED = true;
static constexpr bool REMOTE_CH2_CONNECTED = false;
static constexpr uint8_t ALERT_ACTIVE_LEVEL = LOW;
static constexpr uint8_t TCRIT_ACTIVE_LEVEL = LOW;

static constexpr uint32_t SERIAL_BAUD = 115200;
static constexpr uint32_t CONVERSION_WAIT_MS = 600;
static constexpr uint32_t MONITOR_PERIOD_MS = 2000;

TMP4719 sensor;

bool deviceReady = false;
bool fullTestFinished = false;
uint32_t passCount = 0;
uint32_t failCount = 0;
uint32_t skipCount = 0;
uint32_t apiActionCount = 0;
uint32_t lastMonitorMs = 0;

void printSeparator() {
  Serial.println(F("------------------------------------------------------------"));
}

void printSection(const __FlashStringHelper *title) {
  Serial.println();
  printSeparator();
  Serial.println(title);
  printSeparator();
}

void reportResult(const char *label, bool passed) {
  Serial.print(passed ? F("[PASS] ") : F("[FAIL] "));
  Serial.println(label);
  if (passed) {
    ++passCount;
  } else {
    ++failCount;
  }
}

void reportExecution(const char *label) {
  Serial.print(F("[EXEC] "));
  Serial.println(label);
  ++apiActionCount;
}

void reportSkip(const char *label) {
  Serial.print(F("[SKIP] "));
  Serial.println(label);
  ++skipCount;
}

void markSetterAction() {
  ++apiActionCount;
}

bool isFiniteValue(float value) {
  return !isnan(value) && !isinf(value);
}

bool almostEqual(float first, float second, float tolerance = 0.001f) {
  return fabs(first - second) <= tolerance;
}

int8_t clampRoundedInt8(float value) {
  if (value >= 127.0f) {
    return 127;
  }
  if (value <= -128.0f) {
    return -128;
  }
  return static_cast<int8_t>(value >= 0.0f ? value + 0.5f : value - 0.5f);
}

void printTemperatureValues(float localTemp, float ch1Temp, float ch2Temp) {
  Serial.print(F("Local temperature: "));
  Serial.print(localTemp, 4);
  Serial.println(F(" C"));
  Serial.print(F("Remote CH1 temperature: "));
  Serial.print(ch1Temp, 4);
  Serial.println(F(" C"));
  Serial.print(F("Remote CH2 temperature: "));
  Serial.print(ch2Temp, 4);
  Serial.println(F(" C"));
}

void printStatusValues(uint8_t rawStatus, const StatusFlags &status) {
  Serial.print(F("Raw status: 0x"));
  if (rawStatus < 0x10) {
    Serial.print('0');
  }
  Serial.println(rawStatus, HEX);
  Serial.print(F("ADC busy: "));
  Serial.print(status.adcBusy ? F("1") : F("0"));
  Serial.print(F("; High: "));
  Serial.print(status.tempHigh ? F("1") : F("0"));
  Serial.print(F("; Low: "));
  Serial.print(status.tempLow ? F("1") : F("0"));
  Serial.print(F("; Remote fault: "));
  Serial.print(status.remoteFault ? F("1") : F("0"));
  Serial.print(F("; T_CRIT: "));
  Serial.println(status.tCrit ? F("1") : F("0"));
}

void printLimitValues(const char *name, const LimitStatus &status) {
  Serial.print(name);
  Serial.print(F(" local="));
  Serial.print(status.localLimit ? F("1") : F("0"));
  Serial.print(F(" CH1="));
  Serial.print(status.ch1Limit ? F("1") : F("0"));
  Serial.print(F(" CH2="));
  Serial.println(status.ch2Limit ? F("1") : F("0"));
}

void printDiodeFaultValues(const DiodeFaultStatus &fault) {
  Serial.print(F("Diode faults: CH1 open="));
  Serial.print(fault.ch1Open ? F("1") : F("0"));
  Serial.print(F("; CH2 open="));
  Serial.print(fault.ch2Open ? F("1") : F("0"));
  Serial.print(F("; short="));
  Serial.println(fault.shortCondition ? F("1") : F("0"));
}

void printPinState(const char *name, uint8_t pin, uint8_t activeLevel) {
  int level = digitalRead(pin);
  Serial.print(name);
  Serial.print(F(" pin: "));
  Serial.print(level == HIGH ? F("HIGH") : F("LOW"));
  Serial.print(F("; driver condition: "));
  Serial.println(level == activeLevel ? F("ACTIVE") : F("INACTIVE"));
}

void checkPinState(const char *label, uint8_t pin, uint8_t activeLevel,
                  bool expectedActive) {
  int actualLevel = digitalRead(pin);
  bool actualActive = actualLevel == activeLevel;
  char detail[96];
  snprintf(detail, sizeof(detail), "%s (actual=%s, expected=%s)", label,
           actualActive ? "ACTIVE" : "INACTIVE",
           expectedActive ? "ACTIVE" : "INACTIVE");
  reportResult(detail, actualActive == expectedActive);
}

void waitForConversion() {
  delay(CONVERSION_WAIT_MS);
}

void readLimitStatuses(LimitStatus *high, LimitStatus *low, LimitStatus *tcrit) {
  sensor.getHighLimitStatus(high);
  sensor.getLowLimitStatus(low);
  sensor.getTCritLimitStatus(tcrit);
}

void printAllLimitStatuses() {
  LimitStatus high = {};
  LimitStatus low = {};
  LimitStatus tcrit = {};
  readLimitStatuses(&high, &low, &tcrit);
  printLimitValues("High-limit status:", high);
  printLimitValues("Low-limit status:", low);
  printLimitValues("T_CRIT status:", tcrit);
}

void checkLimitStatuses(const char *phase,
                        bool expectedHighLocal,
                        bool expectedHighCh1,
                        bool expectedHighCh2,
                        bool expectedLowLocal,
                        bool expectedLowCh1,
                        bool expectedLowCh2,
                        bool expectedTCritLocal,
                        bool expectedTCritCh1,
                        bool expectedTCritCh2) {
  Serial.print(F("Limit check: "));
  Serial.println(phase);

  LimitStatus high = {};
  LimitStatus low = {};
  LimitStatus tcrit = {};
  readLimitStatuses(&high, &low, &tcrit);
  printLimitValues("  High-limit status:", high);
  printLimitValues("  Low-limit status:", low);
  printLimitValues("  T_CRIT status:", tcrit);

  reportResult("  high-limit channel mapping",
               high.localLimit == expectedHighLocal &&
                   high.ch1Limit == expectedHighCh1 &&
                   high.ch2Limit == expectedHighCh2);
  reportResult("  low-limit channel mapping",
               low.localLimit == expectedLowLocal &&
                   low.ch1Limit == expectedLowCh1 &&
                   low.ch2Limit == expectedLowCh2);
  reportResult("  T_CRIT channel mapping",
               tcrit.localLimit == expectedTCritLocal &&
                   tcrit.ch1Limit == expectedTCritCh1 &&
                   tcrit.ch2Limit == expectedTCritCh2);
}

void checkAggregateStatus(bool expectedHigh, bool expectedLow, bool expectedTCrit) {
  uint8_t rawStatus = sensor.getStatus();
  StatusFlags status = {};
  sensor.getStatusStruct(&status);
  printStatusValues(rawStatus, status);
  reportResult("aggregate high flag", status.tempHigh == expectedHigh);
  reportResult("aggregate low flag", status.tempLow == expectedLow);
  reportResult("aggregate T_CRIT flag", status.tCrit == expectedTCrit);
}

void setSafeLimits(float localTemp, float ch1Temp) {
  sensor.setLocalHighLimit(clampRoundedInt8(localTemp + 10.0f));
  markSetterAction();
  sensor.setLocalLowLimit(clampRoundedInt8(localTemp - 10.0f));
  markSetterAction();
  sensor.setRemoteHighLimit(1, ch1Temp + 10.0f);
  markSetterAction();
  sensor.setRemoteLowLimit(1, ch1Temp - 10.0f);
  markSetterAction();

  // CH2 is configured outside the expected temperature window because it is unused.
  sensor.setRemoteHighLimit(2, 127.0f);
  markSetterAction();
  sensor.setRemoteLowLimit(2, -127.0f);
  markSetterAction();

  sensor.setTCritLimit(Channel::LOCAL, 127);
  markSetterAction();
  sensor.setTCritLimit(Channel::CH1, 127);
  markSetterAction();
  sensor.setTCritLimit(Channel::CH2, 127);
  markSetterAction();
}

void testIdentification() {
  printSection(F("Identification API"));

  uint8_t chipID = sensor.readChipID();
  uint8_t vendorID = sensor.readVendorID();
  uint8_t deviceID = 0;
  uint8_t revisionID = 0;
  sensor.readDeviceRevID(&deviceID, &revisionID);

  Serial.print(F("Chip ID: 0x"));
  Serial.println(chipID, HEX);
  Serial.print(F("Vendor ID: 0x"));
  Serial.println(vendorID, HEX);
  Serial.print(F("Device ID: 0x"));
  Serial.println(deviceID, HEX);
  Serial.print(F("Revision ID: 0x"));
  Serial.println(revisionID, HEX);

  reportResult("readChipID()", chipID == 0x21);
  reportResult("readVendorID()", vendorID == 0x60);
  reportResult("readDeviceRevID() nibble decoding",
               deviceID <= 0x0F && revisionID <= 0x0F);
}

void testTemperatureReading() {
  printSection(F("Temperature reading API"));

  float localTemp = sensor.readLocalTemperature();
  float ch1Temp = sensor.readRemoteTemperature(1);
  float ch2Temp = sensor.readRemoteTemperature(2);
  float fallbackChannel0 = sensor.readRemoteTemperature(0);
  float fallbackChannel3 = sensor.readRemoteTemperature(3);

  printTemperatureValues(localTemp, ch1Temp, ch2Temp);
  Serial.print(F("Remote channel 0 fallback: "));
  Serial.println(fallbackChannel0, 4);
  Serial.print(F("Remote channel 3 fallback: "));
  Serial.println(fallbackChannel3, 4);

  reportResult("readLocalTemperature() returned a finite value",
               isFiniteValue(localTemp));
  reportResult("readRemoteTemperature(1) returned a finite value",
               isFiniteValue(ch1Temp));
  reportResult("readRemoteTemperature(2) returned a finite value",
               isFiniteValue(ch2Temp));
  reportResult("invalid remote channels follow the driver's CH2 fallback",
               almostEqual(fallbackChannel0, ch2Temp) &&
                   almostEqual(fallbackChannel3, ch2Temp));
}

void testStatusAndFaultAPIs() {
  printSection(F("Status, limit-status, and fault APIs"));

  uint8_t rawStatus = sensor.getStatus();
  StatusFlags status = {};
  sensor.getStatusStruct(&status);
  printStatusValues(rawStatus, status);

  bool rawMappingMatches = status.adcBusy == ((rawStatus >> 7) & 0x01) &&
                            status.tempHigh == ((rawStatus >> 4) & 0x01) &&
                            status.tempLow == ((rawStatus >> 3) & 0x01) &&
                            status.remoteFault == ((rawStatus >> 2) & 0x01) &&
                            status.tCrit == ((rawStatus >> 1) & 0x01);
  reportResult("getStatusStruct() matches getStatus() bit mapping",
               rawMappingMatches);

  DiodeFaultStatus diodeFault = {};
  sensor.getDiodeFaultStatus(&diodeFault);
  printDiodeFaultValues(diodeFault);
  reportResult("CH1 diode-fault state matches board setup",
               diodeFault.ch1Open == !REMOTE_CH1_CONNECTED);
  reportResult("CH2 diode-fault state matches board setup",
               diodeFault.ch2Open == !REMOTE_CH2_CONNECTED);
  reportResult("no short condition is reported", !diodeFault.shortCondition);

  printAllLimitStatuses();
  reportExecution("getHighLimitStatus(), getLowLimitStatus(), getTCritLimitStatus()");
}

void testConfigurationSetters() {
  printSection(F("Configuration setter API actions"));

  sensor.setOperationMode(OperationMode::CONTINUOUS);
  reportExecution("setOperationMode(CONTINUOUS)");
  sensor.setOperationMode(OperationMode::SHUTDOWN);
  reportExecution("setOperationMode(SHUTDOWN)");
  sensor.setOperationMode(OperationMode::CONTINUOUS);
  reportExecution("restore setOperationMode(CONTINUOUS)");

  sensor.setAlertMode(AlertModeType::COMPARATOR);
  reportExecution("setAlertMode(COMPARATOR)");
  sensor.setAlertMode(AlertModeType::INTERRUPT);
  reportExecution("setAlertMode(INTERRUPT)");
  sensor.setAlertMode(AlertModeType::COMPARATOR);
  reportExecution("restore setAlertMode(COMPARATOR)");

  sensor.setAlertMask(false, false, false);
  reportExecution("setAlertMask(OFF, OFF, OFF)");
  sensor.setAlertMask(true, false, false);
  reportExecution("setAlertMask(ON, OFF, OFF)");
  sensor.setAlertMask(false, true, true);
  reportExecution("setAlertMask(OFF, ON, ON)");
  sensor.setAlertMask(false, false, false);
  reportExecution("restore setAlertMask(OFF, OFF, OFF)");

  sensor.setConversionPeriod(ConvPeriod::PERIOD_16S);
  reportExecution("setConversionPeriod(PERIOD_16S)");
  sensor.setConversionPeriod(ConvPeriod::PERIOD_8S);
  reportExecution("setConversionPeriod(PERIOD_8S)");
  sensor.setConversionPeriod(ConvPeriod::PERIOD_4S);
  reportExecution("setConversionPeriod(PERIOD_4S)");
  sensor.setConversionPeriod(ConvPeriod::PERIOD_2S);
  reportExecution("setConversionPeriod(PERIOD_2S)");
  sensor.setConversionPeriod(ConvPeriod::PERIOD_1S);
  reportExecution("setConversionPeriod(PERIOD_1S)");
  sensor.setConversionPeriod(ConvPeriod::PERIOD_0_5S);
  reportExecution("setConversionPeriod(PERIOD_0_5S)");
  sensor.setConversionPeriod(ConvPeriod::PERIOD_0_25S);
  reportExecution("setConversionPeriod(PERIOD_0_25S)");
  sensor.setConversionPeriod(ConvPeriod::PERIOD_0_125S);
  reportExecution("setConversionPeriod(PERIOD_0_125S)");
  sensor.setConversionPeriod(ConvPeriod::PERIOD_0_0625S);
  reportExecution("setConversionPeriod(PERIOD_0_0625S)");
  sensor.setConversionPeriod(ConvPeriod::PERIOD_0_25S);
  reportExecution("restore setConversionPeriod(PERIOD_0_25S)");

  sensor.setHysteresis(1);
  reportExecution("setHysteresis(1)");
  sensor.setHysteresis(31);
  reportExecution("setHysteresis(31)");
  sensor.setHysteresis(32);
  reportExecution("setHysteresis(32), driver clamp path");
  sensor.setHysteresis(1);
  reportExecution("restore setHysteresis(1)");

  sensor.setEtaFactor(1, 0x08);
  reportExecution("setEtaFactor(CH1, 0x08)");
  sensor.setEtaFactor(1, 0x12);
  reportExecution("setEtaFactor(CH1, 0x12)");
  sensor.setEtaFactor(2, 0x37);
  reportExecution("setEtaFactor(CH2, 0x37)");
  sensor.setEtaFactor(2, 0x12);
  reportExecution("setEtaFactor(CH2, 0x12)");

  sensor.setFilterLevel(FilterLevel::FILTER_LEVEL_0);
  reportExecution("setFilterLevel(FILTER_LEVEL_0)");
  sensor.setFilterLevel(FilterLevel::FILTER_LEVEL_1_A);
  reportExecution("setFilterLevel(FILTER_LEVEL_1_A)");
  sensor.setFilterLevel(FilterLevel::FILTER_LEVEL_1_B);
  reportExecution("setFilterLevel(FILTER_LEVEL_1_B)");
  sensor.setFilterLevel(FilterLevel::FILTER_LEVEL_2);
  reportExecution("setFilterLevel(FILTER_LEVEL_2)");
  sensor.setFilterLevel(FilterLevel::FILTER_LEVEL_0);
  reportExecution("restore setFilterLevel(FILTER_LEVEL_0)");
}

void testOneShot() {
  printSection(F("Operation-mode and one-shot API"));

  sensor.setConversionPeriod(ConvPeriod::PERIOD_0_25S);
  markSetterAction();
  sensor.setOperationMode(OperationMode::CONTINUOUS);
  markSetterAction();
  reportResult("triggerOneShot() rejects continuous mode",
               !sensor.triggerOneShot());

  sensor.setOperationMode(OperationMode::SHUTDOWN);
  markSetterAction();
  reportResult("triggerOneShot() accepts shutdown mode", sensor.triggerOneShot());
  delay(CONVERSION_WAIT_MS);

  sensor.setOperationMode(OperationMode::CONTINUOUS);
  markSetterAction();
  reportExecution("restore continuous mode after one-shot test");
}

void testAlertAndLimitBehavior() {
  printSection(F("ALERT, T_CRIT, threshold, and hysteresis behavior"));

  float localTemp = sensor.readLocalTemperature();
  float ch1Temp = sensor.readRemoteTemperature(1);
  if (!isFiniteValue(localTemp) || !isFiniteValue(ch1Temp)) {
    reportResult("temperature prerequisites for threshold tests", false);
    return;
  }

  sensor.setOperationMode(OperationMode::CONTINUOUS);
  markSetterAction();
  sensor.setConversionPeriod(ConvPeriod::PERIOD_0_25S);
  markSetterAction();
  sensor.setAlertMode(AlertModeType::COMPARATOR);
  markSetterAction();
  sensor.setAlertMask(false, false, false);
  markSetterAction();
  sensor.setHysteresis(1);
  markSetterAction();

  setSafeLimits(localTemp, ch1Temp);
  waitForConversion();
  checkLimitStatuses("safe baseline", false, false, false, false, false, false,
                     false, false, false);
  checkAggregateStatus(false, false, false);
  checkPinState("ALERT safe baseline", ALERT_PIN, ALERT_ACTIVE_LEVEL, false);
  checkPinState("T_CRIT safe baseline", TCRIT_PIN, TCRIT_ACTIVE_LEVEL, false);

  // Local high limit only.
  sensor.setLocalHighLimit(clampRoundedInt8(localTemp - 2.0f));
  markSetterAction();
  sensor.setRemoteHighLimit(1, ch1Temp + 10.0f);
  markSetterAction();
  waitForConversion();
  checkLimitStatuses("local high limit only", true, false, false, false, false, false,
                     false, false, false);
  checkAggregateStatus(true, false, false);
  checkPinState("ALERT local high limit", ALERT_PIN, ALERT_ACTIVE_LEVEL, true);
  checkPinState("T_CRIT local high limit", TCRIT_PIN, TCRIT_ACTIVE_LEVEL, false);

  // Remote channel 1 high limit only.
  sensor.setLocalHighLimit(clampRoundedInt8(localTemp + 10.0f));
  markSetterAction();
  sensor.setRemoteHighLimit(1, ch1Temp - 2.0f);
  markSetterAction();
  waitForConversion();
  checkLimitStatuses("CH1 high limit only", false, true, false, false, false, false,
                     false, false, false);
  checkAggregateStatus(true, false, false);
  checkPinState("ALERT CH1 high limit", ALERT_PIN, ALERT_ACTIVE_LEVEL, true);
  checkPinState("T_CRIT CH1 high limit", TCRIT_PIN, TCRIT_ACTIVE_LEVEL, false);

  // Local and CH1 T_CRIT limits, independently visible in the per-channel status.
  sensor.setRemoteHighLimit(1, ch1Temp + 10.0f);
  markSetterAction();
  sensor.setTCritLimit(Channel::LOCAL, clampRoundedInt8(localTemp - 2.0f));
  markSetterAction();
  sensor.setTCritLimit(Channel::CH1, 127);
  markSetterAction();
  waitForConversion();
  checkLimitStatuses("local T_CRIT only", false, false, false, false, false, false,
                     true, false, false);
  checkAggregateStatus(false, false, true);
  checkPinState("ALERT local T_CRIT", ALERT_PIN, ALERT_ACTIVE_LEVEL, false);
  checkPinState("T_CRIT local limit", TCRIT_PIN, TCRIT_ACTIVE_LEVEL, true);

  sensor.setTCritLimit(Channel::LOCAL, 127);
  markSetterAction();
  sensor.setTCritLimit(Channel::CH1, clampRoundedInt8(ch1Temp - 2.0f));
  markSetterAction();
  waitForConversion();
  checkLimitStatuses("CH1 T_CRIT only", false, false, false, false, false, false,
                     false, true, false);
  checkAggregateStatus(false, false, true);
  checkPinState("ALERT CH1 T_CRIT", ALERT_PIN, ALERT_ACTIVE_LEVEL, false);
  checkPinState("T_CRIT CH1 limit", TCRIT_PIN, TCRIT_ACTIVE_LEVEL, true);

  // Low limits for local and CH1.
  setSafeLimits(localTemp, ch1Temp);
  sensor.setLocalLowLimit(clampRoundedInt8(localTemp + 2.0f));
  markSetterAction();
  sensor.setRemoteLowLimit(1, ch1Temp + 2.0f);
  markSetterAction();
  waitForConversion();
  checkLimitStatuses("local and CH1 low limits", false, false, false, true, true, false,
                     false, false, false);
  checkAggregateStatus(false, true, false);
  checkPinState("ALERT low limits", ALERT_PIN, ALERT_ACTIVE_LEVEL, true);
  checkPinState("T_CRIT low limits", TCRIT_PIN, TCRIT_ACTIVE_LEVEL, false);

  // Restore limits above/below the measured values and verify hysteresis release.
  setSafeLimits(localTemp, ch1Temp);
  waitForConversion();
  checkLimitStatuses("released limits after hysteresis", false, false, false, false, false,
                     false, false, false, false);
  checkAggregateStatus(false, false, false);
  checkPinState("ALERT after threshold release", ALERT_PIN, ALERT_ACTIVE_LEVEL, false);
  checkPinState("T_CRIT after threshold release", TCRIT_PIN, TCRIT_ACTIVE_LEVEL, false);
}

void testAlertMaskBehavior() {
  printSection(F("ALERT mode and channel-mask behavior"));

  float localTemp = sensor.readLocalTemperature();
  float ch1Temp = sensor.readRemoteTemperature(1);
  if (!isFiniteValue(localTemp) || !isFiniteValue(ch1Temp)) {
    reportResult("temperature prerequisites for ALERT mask tests", false);
    return;
  }

  setSafeLimits(localTemp, ch1Temp);
  sensor.setHysteresis(1);
  markSetterAction();
  sensor.setAlertMode(AlertModeType::INTERRUPT);
  markSetterAction();
  sensor.setAlertMask(false, false, false);
  markSetterAction();
  waitForConversion();

  sensor.setLocalHighLimit(clampRoundedInt8(localTemp - 2.0f));
  markSetterAction();
  waitForConversion();
  checkPinState("INTERRUPT mode, local ALERT mask OFF", ALERT_PIN,
                ALERT_ACTIVE_LEVEL, true);

  sensor.setAlertMask(true, false, false);
  markSetterAction();
  waitForConversion();
  checkPinState("INTERRUPT mode, local ALERT mask ON", ALERT_PIN,
                ALERT_ACTIVE_LEVEL, false);

  sensor.setAlertMask(false, false, false);
  markSetterAction();
  waitForConversion();
  checkPinState("INTERRUPT mode, local ALERT mask restored OFF", ALERT_PIN,
                ALERT_ACTIVE_LEVEL, true);

  // Check the CH1 mask with a CH1-only high-limit condition.
  sensor.setLocalHighLimit(clampRoundedInt8(localTemp + 10.0f));
  markSetterAction();
  sensor.setRemoteHighLimit(1, ch1Temp - 2.0f);
  markSetterAction();
  sensor.setAlertMask(false, true, false);
  markSetterAction();
  waitForConversion();
  checkPinState("INTERRUPT mode, CH1 ALERT mask ON", ALERT_PIN,
                ALERT_ACTIVE_LEVEL, false);

  sensor.setAlertMask(false, false, false);
  markSetterAction();
  waitForConversion();
  checkPinState("INTERRUPT mode, CH1 ALERT mask OFF", ALERT_PIN,
                ALERT_ACTIVE_LEVEL, true);

  sensor.setAlertMode(AlertModeType::COMPARATOR);
  markSetterAction();
  sensor.setAlertMask(false, false, false);
  markSetterAction();
  setSafeLimits(localTemp, ch1Temp);
  waitForConversion();
  checkPinState("restored COMPARATOR ALERT output", ALERT_PIN,
                ALERT_ACTIVE_LEVEL, false);
}

void testScratchpads() {
  printSection(F("Scratchpad read/write API"));

  uint8_t original1 = sensor.readScratchpad(1);
  uint8_t original2 = sensor.readScratchpad(2);
  Serial.print(F("Original scratchpad 1: 0x"));
  Serial.println(original1, HEX);
  Serial.print(F("Original scratchpad 2: 0x"));
  Serial.println(original2, HEX);

  sensor.writeScratchpad(1, 0x5A);
  reportExecution("writeScratchpad(1, 0x5A)");
  sensor.writeScratchpad(2, 0xA5);
  reportExecution("writeScratchpad(2, 0xA5)");

  uint8_t readback1 = sensor.readScratchpad(1);
  uint8_t readback2 = sensor.readScratchpad(2);
  reportResult("scratchpad 1 readback", readback1 == 0x5A);
  reportResult("scratchpad 2 readback", readback2 == 0xA5);

  sensor.writeScratchpad(1, original1);
  reportExecution("restore scratchpad 1");
  sensor.writeScratchpad(2, original2);
  reportExecution("restore scratchpad 2");
  reportResult("scratchpad 1 restored", sensor.readScratchpad(1) == original1);
  reportResult("scratchpad 2 restored", sensor.readScratchpad(2) == original2);
}

void printDriverVerificationLimits() {
  printSection(F("Driver-only verification limits"));
  reportSkip("No public getter exists for operation mode, ALERT mode, channel masks, conversion period, thresholds, hysteresis, eta, or filter configuration.");
  reportSkip("Global Configuration.Alert_Mask cannot be set or read through the public driver API.");
  reportSkip("Conversion-period register codes 0x09..0x0F are not represented by ConvPeriod.");
  reportSkip("I2C transaction errors are not exposed by the driver's public read/write methods.");
  Serial.println(F("The tests above verify setter effects through status bits and output pins where possible."));
}

void printTestSummary() {
  printSection(F("Test summary"));
  Serial.print(F("Observable PASS checks: "));
  Serial.println(passCount);
  Serial.print(F("Observable FAIL checks: "));
  Serial.println(failCount);
  Serial.print(F("Unsupported/not directly verifiable items: "));
  Serial.println(skipCount);
  Serial.print(F("API actions exercised: "));
  Serial.println(apiActionCount);
  Serial.println(F("The action count is not a pass count: void setters have no public readback."));
}

void printStatusMonitor() {
  float localTemp = sensor.readLocalTemperature();
  float ch1Temp = sensor.readRemoteTemperature(1);
  float ch2Temp = sensor.readRemoteTemperature(2);
  uint8_t rawStatus = sensor.getStatus();
  StatusFlags status = {};
  DiodeFaultStatus diodeFault = {};
  LimitStatus high = {};
  LimitStatus low = {};
  LimitStatus tcrit = {};

  sensor.getStatusStruct(&status);
  sensor.getDiodeFaultStatus(&diodeFault);
  readLimitStatuses(&high, &low, &tcrit);

  Serial.println();
  Serial.println(F("--- Status monitor ---"));
  printTemperatureValues(localTemp, ch1Temp, ch2Temp);
  printStatusValues(rawStatus, status);
  printDiodeFaultValues(diodeFault);
  printLimitValues("High-limit status:", high);
  printLimitValues("Low-limit status:", low);
  printLimitValues("T_CRIT status:", tcrit);
  printPinState("ALERT", ALERT_PIN, ALERT_ACTIVE_LEVEL);
  printPinState("T_CRIT", TCRIT_PIN, TCRIT_ACTIVE_LEVEL);
}

void runFullDriverTest() {
  printSection(F("TMP4719 local driver API test"));
  Serial.println(F("All calls use the public API declared in TMP4719.h."));
  Serial.println(F("The driver source in code_TMP_local is not modified."));

  testIdentification();
  testTemperatureReading();
  testStatusAndFaultAPIs();
  testConfigurationSetters();
  testOneShot();
  testAlertAndLimitBehavior();
  testAlertMaskBehavior();
  testScratchpads();
  printDriverVerificationLimits();
  printTestSummary();
}

void setup() {
  Serial.begin(SERIAL_BAUD);
  delay(1500);

  pinMode(ALERT_PIN, INPUT);
  pinMode(TCRIT_PIN, INPUT);

  Wire.setSDA(I2C_SDA_PIN);
  Wire.setSCL(I2C_SCL_PIN);
  Wire.begin();

  Serial.println();
  Serial.println(F("TMP4719 RP2040 test start"));
  Serial.println(F("I2C SDA=GPIO0, SCL=GPIO1, ALERT=GPIO10, T_CRIT=GPIO11"));
  Serial.print(F("I2C address: 0x"));
  Serial.println(TMP4719_DEFAULT_ADDRESS, HEX);

  deviceReady = sensor.begin();
  reportResult("begin()", deviceReady);
  if (!deviceReady) {
    Serial.println(F("Device initialization failed; check power, address, and I2C wiring."));
    printTestSummary();
    fullTestFinished = true;
    return;
  }

  runFullDriverTest();
  fullTestFinished = true;
  lastMonitorMs = millis();
}

void loop() {
  if (!deviceReady) {
    delay(MONITOR_PERIOD_MS);
    return;
  }

  if (fullTestFinished && millis() - lastMonitorMs >= MONITOR_PERIOD_MS) {
    lastMonitorMs = millis();
    printStatusMonitor();
  }
}
