/*
MLX90382 SPI driver declarations, register constants, types, and documented APIs.
*/

#pragma once

// Includes and protocol types: Arduino and SPI includes, status-neutral conventions, protocol struct and basic configs
#include <Arduino.h>
#include <SPI.h>

// Caller-provided helper types
// AddressEncoder: used when the default single-byte ADR encoding (address >> 1) is not applicable
// Returns true and sets adrByte when the logicalAddress can be serialized to one ADR byte
typedef bool (*AddressEncoder)(uint16_t logicalAddress, uint8_t& adrByte);

// TransactionValidator: optional hook invoked after every RR/RW transaction
// isRead: true for RR, false for RW
// logicalAddress: requested logical address
// rxBytes/rxLength: captured bytes returned by the device during the transaction (MISO samples)
// Return true if the captured response matches the caller's verified expectations; false indicates detectable anomaly
typedef bool (*TransactionValidator)(bool isRead, uint16_t logicalAddress, const uint8_t* rxBytes, size_t rxLength);

// SpiProtocol: caller-supplied verified command bytes, word ordering and optional hooks
struct SpiProtocol {
  uint8_t rrCmd;        // Register-Read command byte (caller-verified)
  uint8_t rwCmd;        // Register-Write command byte (caller-verified)
  bool wordMsbFirst;    // true if device transmits 16-bit words MSB-first
  uint8_t dummyAfterAddrBytes; // number of dummy bytes master must clock after address for RR (0 or 1) - caller-provided

  // Optional hooks
  // If address is outside default representable range (see driver docs), the driver will call addrEncoder.
  // If addrEncoder is nullptr, operations for non-default addresses will fail.
  AddressEncoder addrEncoder;

  // Optional transaction validator invoked after every RR/RW; if nullptr, no validation is performed.
  TransactionValidator validator;
};

// Frame read configuration minimal representation
struct FrameReadConfig {
  uint8_t faddr[4];     // FADDR0..FADDR3 (0x00 means omit or angle when FADDR0 == 0x00)
  uint8_t frfs;         // SPI_FRFS lower nibble
  bool frfsEn;          // SPI_FRFSEN
  bool frcrcEn;         // SPI_FRCRCEN
  uint8_t frInvMask;    // SPI_FRINV bits (bit positions 0..3)
};

// Measurement snapshot structure returned by readMeasurements
struct Measurement {
  uint16_t linPhase;    // LIN_PHASE (post-PEQ, pre-delay compensation)
  int16_t speed;        // SPEED (signed raw value)
  uint16_t agcGain;     // AGC_GAIN
  uint16_t agcAmp;      // AGC_AMP
  uint16_t temp;        // TEMP register raw
  uint16_t driftcPhase; // DRIFTC_PHASE
  uint16_t scPhase;     // SC_PHASE
};

// Device state decoded from STATE register low byte
enum class DeviceState : uint8_t {
  Unknown = 0,
  Normal = 0x08,
  SS2_NVM = 0x10,
  SS2 = 0x20,
  SS3 = 0x40
};

// Signal conditioning grouping
struct SignalConditioningConfig {
  uint16_t sc_x1;
  uint16_t sc_x2;
  uint16_t sc_y1;
  uint16_t sc_y2;
  uint16_t sc_hl;   // only lower 9 bits used by HW
  uint16_t sc_ye;
};

// PWM configuration grouping
struct PwmConfig {
  uint16_t period;    // PWM_PERIOD
  bool invert;        // PWM_INV bit
  bool periodCounterOn; // PWM_PCNT_ON
  int16_t dcOffset;   // signed offset, will be masked to valid PWM_DC_OFS bits
};

// Driver public API: class declaration with documented methods
class MLX90382 {
public:
  // MLX90382: Construct with CS pin, caller-managed SPI bus settings, and verified protocol
  // The SpiProtocol provided must contain caller-verified rrCmd and rwCmd bytes.
  MLX90382(uint8_t csPin, const SPISettings& settings, const SpiProtocol& protocol);

  // begin: Configure CS as inactive. Does not call SPI.begin() or modify device registers.
  bool begin();

  // Generic register access: 16-bit register read/write. Address must be even and aligned per device rules
  // Default ADR encoding (for volatile addresses 0x000..0x1FE) is: ADR = uint8_t(logicalAddress >> 1)
  // For addresses outside that range the driver calls the caller-provided AddressEncoder in SpiProtocol.
  bool readRegister(uint16_t address, uint16_t& value);
  bool writeRegister(uint16_t address, uint16_t value);

  // High-level helpers
  bool readMeasurements(Measurement& snapshot);
  bool readState(DeviceState& state);

  // CRC control APIs
  bool startCrcCalculation();
  bool readCrcWhenReady(uint32_t timeoutMs, uint16_t& crc);

  // Frame configuration and acquisition helpers
  // configureFrameRead stores the validated configuration locally for subsequent frameLength()/readFrame() calls
  bool configureFrameRead(const FrameReadConfig& config);

  // frameLength: return the derived byte length of the stored FrameReadConfig using
  // L_Frame = SPI_FRFSEN + 2*(1 + (FADDR1>0) + (FADDR2>0) + (FADDR3>0)) + SPI_FRCRCEN
  // Returns 0 if no frame configuration is stored.
  size_t frameLength() const;

  // readFrame: clock exactly the derived frame length into buffer. capacity must be >= frameLength().
  // receivedLength is set to the derived number of bytes. CRC tail remains raw and unvalidated.
  bool readFrame(uint8_t* buffer, size_t capacity, size_t& receivedLength);

  // Grouped configuration helpers
  bool setSignalConditioning(const SignalConditioningConfig& config);
  bool getSignalConditioning(SignalConditioningConfig& config);
  bool setPwmConfig(const PwmConfig& config);

  // PEQ calibration
  bool setPeq(uint8_t gain, const int8_t* points); // points must point to 16 int8_t values
  bool getPeq(uint8_t& gain, int8_t* points);     // points must point to buffer for 16 int8_t values

  // Safety-critical / explicit writes
  bool setSafetyMonitorDisableMask(uint16_t mask); // writes DE_OV_VDD register (0x25A)

  // Customer ID bytes USER_ID0..USER_ID5
  bool setCustomerId(uint8_t index, uint8_t value);

private:
  // Private transport and field helpers
  // readModifyWrite: preserve unknown/reserved bits while changing a documented field mask
  bool readModifyWrite(uint16_t address, uint16_t mask, uint16_t bits);

  // encodeAddress: use default address >>1 encoding for addresses 0x000..0x1FE (even only), otherwise call addrEncoder
  bool encodeAddress(uint16_t logicalAddress, uint8_t& adrByte);

  // Low-level transport primitives
  void csAssert();
  void csRelease();

  uint8_t _csPin;
  SPISettings _settings;
  SpiProtocol _protocol;

  // Stored frame configuration
  FrameReadConfig _frameConfig;
  bool _hasFrameConfig;
};

// Register constants (addresses taken from register_maps). Only those used by implemented APIs are defined.
namespace MLXReg {
  static const uint16_t CRC = 0x026;
  static const uint16_t CRC_CALC_STRT = 0x028;
  static const uint16_t STATE = 0x02C;

  static const uint16_t AGC_GAIN = 0x034;
  static const uint16_t AGC_AMP = 0x036;
  static const uint16_t TEMP = 0x038;
  static const uint16_t LIN_PHASE = 0x03A;
  static const uint16_t SPEED = 0x03C;
  static const uint16_t DRIFTC_PHASE = 0x042;
  static const uint16_t SC_PHASE = 0x044;

  static const uint16_t PEQ_GAIN = 0x20A;
  static const uint16_t PEQ00 = 0x20C; // PEQ00..PEQ15 sequential

  static const uint16_t PHASE_OFS = 0x220;
  static const uint16_t SC_X1 = 0x222;
  static const uint16_t SC_X2 = 0x224;
  static const uint16_t SC_Y1 = 0x226;
  static const uint16_t SC_Y2 = 0x228;
  static const uint16_t SC_YE = 0x22A;
  static const uint16_t SC_HL = 0x22C;

  static const uint16_t PWM_PERIOD = 0x22E;
  static const uint16_t PWM_INV = 0x206;
  static const uint16_t PWM_DC_OFS = 0x248;
  static const uint16_t PWM_PCNT = 0x10A;

  static const uint16_t SPI_FADDR0 = 0x230;
  static const uint16_t SPI_FADDR2 = 0x232;
  static const uint16_t SPI_FRFS = 0x234;
  static const uint16_t SPI_CPTLT = 0x238;

  static const uint16_t NVOP_KEY = 0x010;
  static const uint16_t IN_APPLICATION = 0x024;
  static const uint16_t DE_OV_VDD = 0x25A;

  static const uint16_t USER_ID0 = 0x23E; // USER_ID0..5: 0x23E,0x240,0x242

  static const uint16_t PEQ_LAST = 0x21A; // last PEQ register
}


