/*
TMP4719 Arduino I2C driver header file (final revision)
*/

#pragma once

#include <Arduino.h>
#include <Wire.h>

// section_name: Include Guards and Dependencies

// section_name: Register Address Definitions

// Data registers
static constexpr uint8_t TMP4719_REG_TEMP_LOCAL = 0x00;
static constexpr uint8_t TMP4719_REG_TEMP_REMOTE_CH1_HIGH = 0x01;
static constexpr uint8_t TMP4719_REG_TEMP_REMOTE_CH2_HIGH = 0x23;
static constexpr uint8_t TMP4719_REG_TEMP_REMOTE_CH1_LOW = 0x10;
static constexpr uint8_t TMP4719_REG_TEMP_REMOTE_CH2_LOW = 0x24;

// Status registers
static constexpr uint8_t TMP4719_REG_STATUS = 0x02;
static constexpr uint8_t TMP4719_REG_DIODE_FAULT = 0x1B;
static constexpr uint8_t TMP4719_REG_THIGH_LIMIT_STATUS = 0x35;
static constexpr uint8_t TMP4719_REG_TLOW_LIMIT_STATUS = 0x36;
static constexpr uint8_t TMP4719_REG_TCRIT_LIMIT_STATUS = 0x37;

// Configuration registers (primary and shared)
static constexpr uint8_t TMP4719_REG_CONFIGURATION_PRIMARY = 0x03;
static constexpr uint8_t TMP4719_REG_CONFIGURATION_SHARED = 0x09;

// Conversion period registers (primary and shared)
static constexpr uint8_t TMP4719_REG_CONV_PERIOD_PRIMARY = 0x04;
static constexpr uint8_t TMP4719_REG_CONV_PERIOD_SHARED = 0x0A;

// Local temperature limit registers (primary and shared)
static constexpr uint8_t TMP4719_REG_THIGH_LIMIT_LOCAL_PRIMARY = 0x05;
static constexpr uint8_t TMP4719_REG_THIGH_LIMIT_LOCAL_SHARED = 0x0B;
static constexpr uint8_t TMP4719_REG_TLOW_LIMIT_LOCAL_PRIMARY = 0x06;
static constexpr uint8_t TMP4719_REG_TLOW_LIMIT_LOCAL_SHARED = 0x0C;

// Remote channel 1 limit registers (primary and shared)
static constexpr uint8_t TMP4719_REG_THIGH_LIMIT_REMOTE_CH1_HIGH_PRIMARY = 0x07;
static constexpr uint8_t TMP4719_REG_THIGH_LIMIT_REMOTE_CH1_HIGH_SHARED = 0x0D;
static constexpr uint8_t TMP4719_REG_TLOW_LIMIT_REMOTE_CH1_HIGH_PRIMARY = 0x08;
static constexpr uint8_t TMP4719_REG_TLOW_LIMIT_REMOTE_CH1_HIGH_SHARED = 0x0E;

// Remote channel 2 limit registers (no shared addresses)
static constexpr uint8_t TMP4719_REG_THIGH_LIMIT_REMOTE_CH2_HIGH = 0x15;
static constexpr uint8_t TMP4719_REG_TLOW_LIMIT_REMOTE_CH2_HIGH = 0x16;

// Remote channel low byte limit registers (no shared addresses)
static constexpr uint8_t TMP4719_REG_THIGH_LIMIT_REMOTE_CH1_LOW = 0x13;
static constexpr uint8_t TMP4719_REG_TLOW_LIMIT_REMOTE_CH1_LOW = 0x14;
static constexpr uint8_t TMP4719_REG_THIGH_LIMIT_REMOTE_CH2_LOW = 0x17;
static constexpr uint8_t TMP4719_REG_TLOW_LIMIT_REMOTE_CH2_LOW = 0x18;

// Control registers
static constexpr uint8_t TMP4719_REG_ONE_SHOT = 0x0F;
static constexpr uint8_t TMP4719_REG_ALERT_MASK = 0x1F;
static constexpr uint8_t TMP4719_REG_FILTER_CONTROL = 0x40;

// Critical limit registers (no shared addresses)
static constexpr uint8_t TMP4719_REG_THIGH_CRIT_LOCAL = 0x20;
static constexpr uint8_t TMP4719_REG_THIGH_CRIT_REMOTE_CH1 = 0x19;
static constexpr uint8_t TMP4719_REG_THIGH_CRIT_REMOTE_CH2 = 0x1A;

// Configuration registers (no shared addresses)
static constexpr uint8_t TMP4719_REG_HYSTERESIS = 0x21;

// Calibration registers (no shared addresses)
static constexpr uint8_t TMP4719_REG_ETA_FACTOR_CH1 = 0x27;
static constexpr uint8_t TMP4719_REG_ETA_FACTOR_CH2 = 0x28;

// Data storage registers (no shared addresses)
static constexpr uint8_t TMP4719_REG_SCRATCHPAD1 = 0x11;
static constexpr uint8_t TMP4719_REG_SCRATCHPAD2 = 0x12;

// Identification registers (no shared addresses)
static constexpr uint8_t TMP4719_REG_CHIP_ID = 0xFD;
static constexpr uint8_t TMP4719_REG_VENDOR_ID = 0xFE;
static constexpr uint8_t TMP4719_REG_DEVICE_REV_ID = 0xFF;

// Default I2C address
static constexpr uint8_t TMP4719_DEFAULT_ADDRESS = 0x4C;

// section_name: Configuration Enums

enum class OperationMode : uint8_t {
  CONTINUOUS = 0,
  SHUTDOWN = 1
};

enum class AlertModeType : uint8_t {
  INTERRUPT = 0,
  COMPARATOR = 1
};

enum class Channel : uint8_t {
  LOCAL = 0,
  CH1 = 1,
  CH2 = 2
};

enum class ConvPeriod : uint8_t {
  PERIOD_16S = 0x00,   // 16s / 0.0625Hz
  PERIOD_8S = 0x01,    // 8s / 0.125Hz
  PERIOD_4S = 0x02,    // 4s / 0.25Hz
  PERIOD_2S = 0x03,    // 2s / 0.5Hz
  PERIOD_1S = 0x04,    // 1s / 1Hz
  PERIOD_0_5S = 0x05,  // 0.5s / 2Hz
  PERIOD_0_25S = 0x06, // 0.25s / 4Hz (default)
  PERIOD_0_125S = 0x07,// 0.125s / 8Hz
  PERIOD_0_0625S = 0x08 // 0.0625s / 16Hz
};

enum class FilterLevel : uint8_t {
  FILTER_LEVEL_0 = 0x00, // 0 moving average (default)
  FILTER_LEVEL_1_A = 0x01, // 4 moving average
  FILTER_LEVEL_1_B = 0x02, // 4 moving average
  FILTER_LEVEL_2 = 0x03  // 8 moving average
};

// section_name: Data Structures

struct TemperatureReadings {
  float localTempC;    // Local temperature in °C
  float remoteCh1TempC; // Remote channel 1 temperature in °C
  float remoteCh2TempC; // Remote channel 2 temperature in °C
};

struct StatusFlags {
  bool adcBusy;        // ADC is busy converting
  bool tempHigh;       // Any temperature exceeds high limit
  bool tempLow;        // Any temperature below low limit
  bool remoteFault;    // Remote channel fault (open/short)
  bool tCrit;          // Any temperature exceeds T_CRIT limit
};

struct LimitStatus {
  bool localLimit;     // Local channel limit exceeded
  bool ch1Limit;       // Remote channel 1 limit exceeded
  bool ch2Limit;       // Remote channel 2 limit exceeded
};

struct DiodeFaultStatus {
  bool ch1Open;        // Remote channel 1 open condition
  bool ch2Open;        // Remote channel 2 open condition
  bool shortCondition; // Either channel shorted
};

struct DeviceInfo {
  uint8_t chipID;      // Chip ID (expected 0x21)
  uint8_t vendorID;    // Vendor ID (expected 0x60)
  uint8_t deviceID;    // Device ID (bits 7:4 of Device_Rev_ID)
  uint8_t revisionID;  // Revision ID (bits 3:0 of Device_Rev_ID)
};

// section_name: Driver Class Definition

class TMP4719 {
public:
  // Constructor with configurable I2C address
  explicit TMP4719(uint8_t address = TMP4719_DEFAULT_ADDRESS, TwoWire &wire = Wire);

  // Initialization
  bool begin();

  // Temperature reading functions
  float readLocalTemperature();
  float readRemoteTemperature(uint8_t channel);

  // Status reading functions
  uint8_t getStatus();
  void getStatusStruct(StatusFlags *status);

  // Configuration functions
  void setOperationMode(OperationMode mode);
  void setAlertMode(AlertModeType alertMode);
  void setAlertMask(bool maskLocal, bool maskCh1, bool maskCh2);
  void setConversionPeriod(ConvPeriod period);

  // Threshold setting functions (local)
  void setLocalHighLimit(int8_t tempC);
  void setLocalLowLimit(int8_t tempC);

  // Threshold setting functions (remote)
  void setRemoteHighLimit(uint8_t channel, float tempC);
  void setRemoteLowLimit(uint8_t channel, float tempC);

  // T_CRIT limit setting
  void setTCritLimit(Channel channel, int8_t tempC);

  // Other configuration functions
  void setHysteresis(uint8_t hystC);
  void setEtaFactor(uint8_t channel, uint8_t etaValue);
  void setFilterLevel(FilterLevel level);

  // One-shot conversion
  bool triggerOneShot();

  // Fault and limit status functions
  void getDiodeFaultStatus(DiodeFaultStatus *fault);
  void getHighLimitStatus(LimitStatus *status);
  void getLowLimitStatus(LimitStatus *status);
  void getTCritLimitStatus(LimitStatus *status);

  // Identification functions
  uint8_t readChipID();
  uint8_t readVendorID();
  void readDeviceRevID(uint8_t *deviceID, uint8_t *revID);

  // Scratchpad access
  void writeScratchpad(uint8_t scratchpadNum, uint8_t value);
  uint8_t readScratchpad(uint8_t scratchpadNum);

private:
  // section_name: Private Helper Methods
  uint8_t readRegister(uint8_t regAddr);
  void writeRegister(uint8_t regAddr, uint8_t value);
  uint16_t readRegister16(uint8_t regAddrHigh, uint8_t regAddrLow);
  void writeRegister16(uint8_t regAddrHigh, uint8_t regAddrLow, uint16_t value);

  // Temperature conversion helpers
  float int8ToFloatTemp(int8_t rawValue);
  float int16ToFloatTemp(int16_t rawValue);
  int8_t floatToInt8Temp(float tempC);
  int16_t floatToInt12Temp(float tempC);

  // Member variables
  uint8_t _address;
  TwoWire *_wire;
};

