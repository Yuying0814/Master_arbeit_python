/*
Implements MLX90382 SPI transport and all declared APIs.
*/

// Register constants and packing helpers: implementation-only helpers and small utilities
#include "MLX90382.h"

// Private helpers for byte packing/unpacking
static inline uint16_t pack16(uint8_t hi, uint8_t lo) { return (uint16_t)hi << 8 | (uint16_t)lo; }
static inline uint8_t hiByte(uint16_t v) { return (uint8_t)(v >> 8); }
static inline uint8_t loByte(uint16_t v) { return (uint8_t)(v & 0xFF); }

// Constructor
MLX90382::MLX90382(uint8_t csPin, const SPISettings& settings, const SpiProtocol& protocol)
  : _csPin(csPin), _settings(settings), _protocol(protocol), _hasFrameConfig(false) {
}

// SPI transaction implementation: CS control
void MLX90382::csAssert() {
  digitalWrite(_csPin, LOW);
}
void MLX90382::csRelease() {
  digitalWrite(_csPin, HIGH);
}

// begin: initialize local CS pin only
bool MLX90382::begin() {
  pinMode(_csPin, OUTPUT);
  digitalWrite(_csPin, HIGH); // inactive high
  return true;
}

// encodeAddress: default mapping for logical volatile addresses 0x000..0x1FE -> ADR = address >> 1
// Reject odd addresses. For addresses outside this range, invoke caller addrEncoder if provided.
bool MLX90382::encodeAddress(uint16_t logicalAddress, uint8_t& adrByte) {
  // Default representable range documented in the programming plan: 0x000..0x1FE (even only)
  if ((logicalAddress & 0x1u) != 0) return false; // must be even
  if (logicalAddress <= 0x1FEu) {
    adrByte = (uint8_t)(logicalAddress >> 1);
    return true;
  }
  // Non-default region: require caller-provided encoder
  if (_protocol.addrEncoder) {
    return _protocol.addrEncoder(logicalAddress, adrByte);
  }
  return false; // no encoder available, cannot represent this address
}

// Low-level register read implementation using caller-supplied protocol bytes and word-order selection
bool MLX90382::readRegister(uint16_t address, uint16_t& value) {
  // Validation: address must be even (LSB zero)
  if ((address & 0x1u) != 0) return false;

  uint8_t adrByte;
  if (!encodeAddress(address, adrByte)) return false;

  SPI.beginTransaction(_settings);
  csAssert();

  // We will capture MISO bytes returned during the sequence for validator
  uint8_t rxCapture[4];
  size_t rxCount = 0;

  // Send command byte; capture MISO during this transfer
  rxCapture[rxCount++] = SPI.transfer(_protocol.rrCmd);

  // Send ADR byte; capture MISO
  if (rxCount < sizeof(rxCapture)) rxCapture[rxCount++] = SPI.transfer(adrByte);
  else SPI.transfer(adrByte);

  // Clock optional dummy bytes if caller requested it in protocol
  for (uint8_t i = 0; i < _protocol.dummyAfterAddrBytes; ++i) {
    if (rxCount < sizeof(rxCapture)) rxCapture[rxCount++] = SPI.transfer((uint8_t)0x00);
    else SPI.transfer((uint8_t)0x00);
  }

  // Read two bytes for the 16-bit register; collect responses in-order
  uint8_t b0 = SPI.transfer((uint8_t)0x00);
  if (rxCount < sizeof(rxCapture)) rxCapture[rxCount++] = b0;
  uint8_t b1 = SPI.transfer((uint8_t)0x00);
  if (rxCount < sizeof(rxCapture)) rxCapture[rxCount++] = b1;

  csRelease();
  SPI.endTransaction();

  // If a transaction validator is provided, call it. If it returns false, report failure.
  if (_protocol.validator) {
    if (!_protocol.validator(true, address, rxCapture, rxCount)) return false;
  }

  if (_protocol.wordMsbFirst) {
    value = pack16(b0, b1);
  } else {
    value = pack16(b1, b0);
  }
  return true;
}

bool MLX90382::writeRegister(uint16_t address, uint16_t value) {
  if ((address & 0x1u) != 0) return false;

  uint8_t adrByte;
  if (!encodeAddress(address, adrByte)) return false;

  SPI.beginTransaction(_settings);
  csAssert();

  uint8_t rxCapture[4];
  size_t rxCount = 0;

  // Send command
  rxCapture[rxCount++] = SPI.transfer(_protocol.rwCmd);
  // ADR
  if (rxCount < sizeof(rxCapture)) rxCapture[rxCount++] = SPI.transfer(adrByte);
  else SPI.transfer(adrByte);

  // Data bytes in chosen order; capture returned bytes too
  if (_protocol.wordMsbFirst) {
    if (rxCount < sizeof(rxCapture)) rxCapture[rxCount++] = SPI.transfer(hiByte(value)); else SPI.transfer(hiByte(value));
    if (rxCount < sizeof(rxCapture)) rxCapture[rxCount++] = SPI.transfer(loByte(value)); else SPI.transfer(loByte(value));
  } else {
    if (rxCount < sizeof(rxCapture)) rxCapture[rxCount++] = SPI.transfer(loByte(value)); else SPI.transfer(loByte(value));
    if (rxCount < sizeof(rxCapture)) rxCapture[rxCount++] = SPI.transfer(hiByte(value)); else SPI.transfer(hiByte(value));
  }

  csRelease();
  SPI.endTransaction();

  if (_protocol.validator) {
    if (!_protocol.validator(false, address, rxCapture, rxCount)) return false;
  }

  return true;
}

// readModifyWrite: preserve reserved bits while updating mask
bool MLX90382::readModifyWrite(uint16_t address, uint16_t mask, uint16_t bits) {
  uint16_t cur;
  if (!readRegister(address, cur)) return false;
  uint16_t newv = (cur & ~mask) | (bits & mask);
  if (newv == cur) return true; // nothing to do
  return writeRegister(address, newv);
}

// readMeasurements: gather multiple volatile measurement registers; fail on any transport error
bool MLX90382::readMeasurements(Measurement& snapshot) {
  uint16_t tmp;
  if (!readRegister(MLXReg::LIN_PHASE, tmp)) return false;
  snapshot.linPhase = tmp;
  if (!readRegister(MLXReg::SPEED, tmp)) return false;
  snapshot.speed = (int16_t)tmp;
  if (!readRegister(MLXReg::AGC_GAIN, tmp)) return false;
  snapshot.agcGain = tmp & 0x003F; // AGC_GAIN uses lower 6 bits per map
  if (!readRegister(MLXReg::AGC_AMP, tmp)) return false;
  snapshot.agcAmp = tmp & 0x1FFF; // AGC_AMP uses lower 13 bits
  if (!readRegister(MLXReg::TEMP, tmp)) return false;
  snapshot.temp = tmp & 0x0FFF; // TEMP uses lower 12 bits
  if (!readRegister(MLXReg::DRIFTC_PHASE, tmp)) return false;
  snapshot.driftcPhase = tmp;
  if (!readRegister(MLXReg::SC_PHASE, tmp)) return false;
  snapshot.scPhase = tmp;
  return true;
}

bool MLX90382::readState(DeviceState& state) {
  uint16_t v;
  if (!readRegister(MLXReg::STATE, v)) return false;
  uint8_t low = (uint8_t)(v & 0xFF);
  switch (low) {
    case 0x08: state = DeviceState::Normal; break;
    case 0x10: state = DeviceState::SS2_NVM; break;
    case 0x20: state = DeviceState::SS2; break;
    case 0x40: state = DeviceState::SS3; break;
    default: state = DeviceState::Unknown; break;
  }
  return true;
}

// CRC start: set bit 0 in CRC_CALC_STRT via RMW
bool MLX90382::startCrcCalculation() {
  // mask = 0x0001, bits = 0x0001
  return readModifyWrite(MLXReg::CRC_CALC_STRT, 0x0001, 0x0001);
}

// readCrcWhenReady: poll CRC_CALC_DONE (bit 1 of 0x028) until timeoutMs elapses. If timeoutMs==0, perform single check.
bool MLX90382::readCrcWhenReady(uint32_t timeoutMs, uint16_t& crc) {
  uint32_t start = millis();
  while (true) {
    uint16_t st;
    if (!readRegister(MLXReg::CRC_CALC_STRT, st)) return false;
    bool done = (st & (1u << 1)) != 0; // CRC_CALC_DONE is bit 1
    if (done) {
      uint16_t c;
      if (!readRegister(MLXReg::CRC, c)) return false;
      crc = c;
      return true;
    }
    if (timeoutMs == 0) return false;
    if ((uint32_t)(millis() - start) >= timeoutMs) return false;
    // No assumed wait; yield to allow other tasks
    delay(1);
  }
}

// Frame configuration: write FADDR0..3 and SPI_FRFS fields with reserved-safe updates
// Store configuration locally only after successful writes
bool MLX90382::configureFrameRead(const FrameReadConfig& config) {
  // Write FADDR0 register (0x230): lower byte = FADDR0, upper byte = FADDR1
  uint16_t f0 = ((uint16_t)config.faddr[1] << 8) | (uint16_t)config.faddr[0];
  if (!writeRegister(MLXReg::SPI_FADDR0, f0)) return false;

  // Write FADDR2 register (0x232): lower byte = FADDR2, upper byte = FADDR3
  uint16_t f2 = ((uint16_t)config.faddr[3] << 8) | (uint16_t)config.faddr[2];
  if (!writeRegister(MLXReg::SPI_FADDR2, f2)) return false;

  // Update SPI_FRFS (0x234) while preserving unrelated bits
  uint16_t mask = 0;
  uint16_t bits = 0;
  mask |= 0x000F; bits |= (uint16_t)(config.frfs & 0x0F);
  mask |= (1u << 4); if (config.frfsEn) bits |= (1u << 4);
  mask |= (1u << 5); if (config.frcrcEn) bits |= (1u << 5);
  mask |= (0x000F << 6); bits |= (uint16_t)((config.frInvMask & 0x0F) << 6);
  if (!readModifyWrite(MLXReg::SPI_FRFS, mask, bits)) return false;

  // store locally
  _frameConfig = config;
  _hasFrameConfig = true;
  return true;
}

// frameLength: compute L_Frame = SPI_FRFSEN + 2*(1 + (FADDR1>0) + (FADDR2>0) + (FADDR3>0)) + SPI_FRCRCEN
size_t MLX90382::frameLength() const {
  if (!_hasFrameConfig) return 0;
  size_t sf = _frameConfig.frfsEn ? 1u : 0u;
  size_t crc = _frameConfig.frcrcEn ? 1u : 0u;
  size_t faddrCount = 1; // FADDR0 always counted as 1 content slot (may be 0x00 meaning angle)
  if (_frameConfig.faddr[1] != 0) faddrCount++;
  if (_frameConfig.faddr[2] != 0) faddrCount++;
  if (_frameConfig.faddr[3] != 0) faddrCount++;
  size_t L = sf + 2 * faddrCount + crc;
  return L;
}

// readFrame: require stored config and adequate capacity, hold CS for exactly the derived transfer count
bool MLX90382::readFrame(uint8_t* buffer, size_t capacity, size_t& receivedLength) {
  receivedLength = 0;
  if (!_hasFrameConfig) return false;
  size_t L = frameLength();
  if (L == 0) return false;
  if (buffer == nullptr) return false;
  if (capacity < L) return false;

  SPI.beginTransaction(_settings);
  csAssert();
  for (size_t i = 0; i < L; ++i) {
    buffer[i] = SPI.transfer((uint8_t)0x00);
  }
  csRelease();
  SPI.endTransaction();

  receivedLength = L;
  return true;
}

// setSignalConditioning and getSignalConditioning
bool MLX90382::setSignalConditioning(const SignalConditioningConfig& config) {
  if (!writeRegister(MLXReg::SC_X1, config.sc_x1)) return false;
  if (!writeRegister(MLXReg::SC_X2, config.sc_x2)) return false;
  if (!writeRegister(MLXReg::SC_Y1, config.sc_y1)) return false;
  if (!writeRegister(MLXReg::SC_Y2, config.sc_y2)) return false;
  if (!writeRegister(MLXReg::SC_HL, config.sc_hl & 0x01FF)) return false; // mask 9 bits
  if (!writeRegister(MLXReg::SC_YE, config.sc_ye)) return false;
  return true;
}

bool MLX90382::getSignalConditioning(SignalConditioningConfig& config) {
  uint16_t tmp;
  if (!readRegister(MLXReg::SC_X1, tmp)) return false; config.sc_x1 = tmp;
  if (!readRegister(MLXReg::SC_X2, tmp)) return false; config.sc_x2 = tmp;
  if (!readRegister(MLXReg::SC_Y1, tmp)) return false; config.sc_y1 = tmp;
  if (!readRegister(MLXReg::SC_Y2, tmp)) return false; config.sc_y2 = tmp;
  if (!readRegister(MLXReg::SC_HL, tmp)) return false; config.sc_hl = tmp & 0x01FF;
  if (!readRegister(MLXReg::SC_YE, tmp)) return false; config.sc_ye = tmp;
  return true;
}

// setPwmConfig
bool MLX90382::setPwmConfig(const PwmConfig& config) {
  // Validate period precondition is caller responsibility; driver will write masked fields
  if (!writeRegister(MLXReg::PWM_PERIOD, config.period)) return false;
  // PWM_INV is at 0x206 bit0 and PWM_PCNT_ON at bit1; do RMW
  uint16_t mask = (1u << 0) | (1u << 1);
  uint16_t bits = 0;
  if (config.invert) bits |= (1u << 0);
  if (config.periodCounterOn) bits |= (1u << 1);
  if (!readModifyWrite(MLXReg::PWM_INV, mask, bits)) return false;
  // PWM_DC_OFS lower 9 bits
  uint16_t ofs = (uint16_t)(config.dcOffset & 0x01FF);
  if (!readModifyWrite(MLXReg::PWM_DC_OFS, 0x01FF, ofs)) return false;
  return true;
}

// setPeq: pack 16 signed 8-bit samples into PEQ registers and write PEQ_GAIN
bool MLX90382::setPeq(uint8_t gain, const int8_t* points) {
  if (points == nullptr) return false;
  if (gain > 7) return false;
  // write gain
  if (!writeRegister(MLXReg::PEQ_GAIN, (uint16_t)(gain & 0x7))) return false;
  // pack points into PEQ00..PEQ14 (each register holds two signed 8-bit little-field-first)
  uint16_t regAddr = MLXReg::PEQ00;
  for (int i = 0; i < 16; i += 2) {
    uint8_t low = (uint8_t)points[i];
    uint8_t high = (uint8_t)points[i+1];
    uint16_t packed = ((uint16_t)high << 8) | (uint16_t)low; // little-field-first
    if (!writeRegister(regAddr, packed)) return false;
    regAddr += 2; // registers are 16-bit aligned addresses incremented by 2
  }
  return true;
}

bool MLX90382::getPeq(uint8_t& gain, int8_t* points) {
  if (points == nullptr) return false;
  uint16_t tmp;
  if (!readRegister(MLXReg::PEQ_GAIN, tmp)) return false;
  gain = (uint8_t)(tmp & 0x7);
  uint16_t regAddr = MLXReg::PEQ00;
  for (int i = 0; i < 16; i += 2) {
    if (!readRegister(regAddr, tmp)) return false;
    uint8_t low = (uint8_t)(tmp & 0xFF);
    uint8_t high = (uint8_t)((tmp >> 8) & 0xFF);
    points[i] = (int8_t)low;
    points[i+1] = (int8_t)high;
    regAddr += 2;
  }
  return true;
}

// setSafetyMonitorDisableMask: direct write to DE_OV_VDD (0x25A)
bool MLX90382::setSafetyMonitorDisableMask(uint16_t mask) {
  return writeRegister(MLXReg::DE_OV_VDD, mask);
}

// setCustomerId: index 0..5, USER_ID registers at 0x23E,0x240,0x242 each pack two bytes
bool MLX90382::setCustomerId(uint8_t index, uint8_t value) {
  if (index > 5) return false;
  uint16_t baseReg = MLXReg::USER_ID0 + (uint16_t)(index / 2) * 2; // each register address increments by 2
  uint16_t cur;
  if (!readRegister(baseReg, cur)) return false;
  if ((index & 1) == 0) {
    // lower byte
    cur = (cur & 0xFF00) | (uint16_t)value;
  } else {
    // upper byte
    cur = (cur & 0x00FF) | ((uint16_t)value << 8);
  }
  return writeRegister(baseReg, cur);
}

