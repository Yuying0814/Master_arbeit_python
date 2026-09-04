/*
Public declarations for BME280 driver (class, enums, structs, API prototypes, documentation comments).
*/

#pragma once

// Header guards and includes: Include guards and required includes (stdint.h, Wire.h, SPI.h, Arduino.h).
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <stdint.h>

// Public types and enums: Enums and structs representing oversampling, mode, filter, standby, raw/compensated data and calibration container.
namespace BME280Driver {

// Oversampling settings (3-bit fields, 0..5 valid as per register map)
enum Oversampling : uint8_t {
  OSRS_SKIP = 0x00, // skipped
  OSRS_X1   = 0x01,
  OSRS_X2   = 0x02,
  OSRS_X4   = 0x03,
  OSRS_X8   = 0x04,
  OSRS_X16  = 0x05
};

// Mode settings (2-bit)
enum Mode : uint8_t {
  MODE_SLEEP  = 0x00,
  MODE_FORCED = 0x01, // 01 and 10 both are forced; drivers will write 01
  MODE_NORMAL = 0x03
};

// IIR filter coefficient (3-bit)
enum FilterCoeff : uint8_t {
  FILTER_OFF = 0x00,
  FILTER_2   = 0x01,
  FILTER_4   = 0x02,
  FILTER_8   = 0x03,
  FILTER_16  = 0x04
};

// Standby time in normal mode (3-bit)
enum StandbyTime : uint8_t {
  TSB_0_5_MS  = 0x00,
  TSB_62_5_MS = 0x01,
  TSB_125_MS  = 0x02,
  TSB_250_MS  = 0x03,
  TSB_500_MS  = 0x04,
  TSB_1000_MS = 0x05,
  TSB_10_MS   = 0x06,
  TSB_20_MS   = 0x07
};

// Raw sensor readings and sentinel flags
struct RawData {
  uint32_t press_raw; // 20-bit (stored in 32-bit)
  uint32_t temp_raw;  // 20-bit
  uint16_t hum_raw;   // 16-bit
  bool pressure_skipped; // true if raw equals sentinel 0x80000
  bool temperature_skipped;
  bool humidity_skipped; // true if raw equals sentinel 0x8000
};

// Calibration container (public read-only via driver)
struct Calibration {
  uint16_t dig_T1;
  int16_t  dig_T2;
  int16_t  dig_T3;
  uint16_t dig_P1;
  int16_t  dig_P2;
  int16_t  dig_P3;
  int16_t  dig_P4;
  int16_t  dig_P5;
  int16_t  dig_P6;
  int16_t  dig_P7;
  int16_t  dig_P8;
  int16_t  dig_P9;
  uint8_t  dig_H1;
  int16_t  dig_H2;
  uint8_t  dig_H3;
  int16_t  dig_H4; // signed 12-bit stored in int16_t
  int16_t  dig_H5; // signed 12-bit stored in int16_t
  int8_t   dig_H6;
};

} // namespace BME280Driver

// Public API: High-level driver APIs for initialization, configuration, data acquisition, status and self-test.
class BME280 {
public:
  // Default constructor. Creates an instance of the driver; does not initialize communication buses.
  BME280();

  // Initialize the driver to use I2C. Does NOT call Wire.begin().
  // address: 7-bit I2C address (default 0x76).
  // wire: pointer to TwoWire instance (default &Wire).
  // Returns true if chip ID validated and calibration successfully read.
  bool beginI2C(uint8_t address = 0x76, TwoWire* wire = &Wire);

  // Initialize the driver to use SPI. Does NOT call SPI.begin().
  // cs_pin: digital pin used for chip-select.
  // spi: pointer to SPIClass instance (default &SPI).
  // Returns true if chip ID validated and calibration successfully read.
  // NOTE: prefer using the overload below that accepts SPISettings. If caller provides SPISettings,
  // the driver will call SPI.beginTransaction() / endTransaction() around transfers. If caller does
  // not provide SPISettings (this overload), the driver will perform direct spi->transfer() calls
  // without beginTransaction; the caller must ensure SPI is configured appropriately before use.
  bool beginSPI(uint8_t cs_pin, SPIClass* spi = &SPI);

  // Preferred SPI initializer: caller provides SPISettings describing clock, bit order and mode.
  // When this overload is used the driver will call spi->beginTransaction(settings) for transfers.
  // The driver still does not call SPI.begin().
  bool beginSPI(uint8_t cs_pin, SPIClass* spi, const SPISettings& settings);

  // Write 0xB6 to reset register (0xE0) and wait min 2 ms; polls im_update until cleared (with timeout).
  // Returns true on success.
  bool softReset();

  // Read and return the chip ID register (0xD0).
  uint8_t readChipId();

  // Read and parse all calibration words (0x88..0xA1 and 0xE1..0xE7) into internal struct.
  // Returns true on success.
  bool readCalibration();

  // Set ctrl_hum.osrs_h (0xF2[2:0]). Note: change takes effect only after ctrl_meas write.
  bool setHumidityOversampling(uint8_t osrs_h);

  // Set osrs_t, osrs_p and mode in ctrl_meas (0xF4). Waits for measuring bit to clear before writing.
  bool setTempPressureOversamplingAndMode(uint8_t osrs_t, uint8_t osrs_p, uint8_t mode);

  // Set config.t_sb, config.filter and config.spi3w_en (0xF5).
  bool setFilterAndStandby(uint8_t t_sb, uint8_t filter, bool spi3w_en = false);

  // Perform an atomic burst read starting at 0xF7 to fetch pressure(3), temperature(3), humidity(2).
  // On success internal raw caches are updated. Returns true on successful read.
  bool readSensor();

  // Return the most recent raw ADC values read by readSensor().
  BME280Driver::RawData getRawData() const;

  // Return last compensated temperature in degrees Celsius (float).
  float getTemperature() const;

  // Return last compensated pressure in Pascals (float).
  float getPressure() const;

  // Return last compensated relative humidity in %RH (float). Clamped to 0..100.
  float getHumidity() const;

  // Read status.measuring (0xF3 bit3) to detect an ongoing conversion.
  bool isMeasuring();

  // Read status.im_update (0xF3 bit0) to detect NVM->image copying.
  bool isImUpdate();

  // Perform self-test sequence. Returns code: 0=OK, 10=comm/wrong device, 20=trimming error,
  // 30=temp bond-wire/MEMS defect, 31=pressure bond-wire/MEMS defect, 40/41/42=implausible T/P/H.
  int performSelfTest();

  // Access calibration values
  const BME280Driver::Calibration& calibration() const { return _calib; }

private:
  // Private helpers (declarations): Low-level bus helpers and internal data accesses.
  // These are private and not part of the public stable API.
  bool writeRegister(uint8_t reg, uint8_t value);
  bool readRegister(uint8_t reg, uint8_t &value);
  bool burstRead(uint8_t start_reg, uint8_t* buffer, size_t length);

  // SPI helper internals: use stored SPISettings only when provided by caller via beginSPI(..., settings).
  bool spiWriteBytesInternal(uint8_t reg, const uint8_t* buffer, size_t length);
  bool spiReadBytesInternal(uint8_t start_reg, uint8_t* buffer, size_t length);

  // Compensation helpers (declare so .cpp matches): private helper functions.
  int32_t compensateTemperature(uint32_t adc_T);
  uint32_t compensatePressure(uint32_t adc_P);
  float compensateHumidity(uint16_t adc_H);

  // Internal state
  enum Transport { TRANSPORT_NONE, TRANSPORT_I2C, TRANSPORT_SPI } _transport;
  TwoWire* _wire;
  uint8_t _i2c_addr;
  SPIClass* _spi;
  uint8_t _cs_pin;

  // when true driver will call SPI.beginTransaction(_spi_settings) around transfers
  SPISettings _spi_settings;
  bool _has_spi_settings;

  // Raw caches
  BME280Driver::RawData _raw;

  // Compensated cached results
  int32_t _temp_x100; // temperature in 0.01 degC
  uint32_t _press_Pa; // pressure in Pa
  float _hum_percent;

  // Calibration
  BME280Driver::Calibration _calib;

  // t_fine for compensation (signed 32-bit)
  int32_t _t_fine;

  // Timeouts and constants
  static const uint16_t RESET_DELAY_MS = 2;
  static const uint16_t IM_UPDATE_TIMEOUT_MS = 100;
  static const uint16_t MEASUREMENT_TIMEOUT_MS = 1500; // conservative default using measurement timing guidance
  static const uint16_t WRITE_TIMEOUT_MS = 100;
};

