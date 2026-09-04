/*
BMM350 Wire transport and device-operation implementation.
*/

// Transport and status helpers: implement low-level Wire transactions, dummy-byte-aware reads and helpers
#include "BMM350.h"

// section: Transport and PMU status helpers

BMM350::BMM350(TwoWire &wire, uint8_t address) : wire_(wire), address_(address) {}

// Low-level write of one register
Status BMM350::writeRegister8(uint8_t reg, uint8_t value) {
    wire_.beginTransmission(address_);
    wire_.write(reg);
    wire_.write(value);
    uint8_t res = wire_.endTransmission();
    if (res != 0) return Status::BusError;
    return Status::Ok;
}

// Low-level multi-byte write (register followed by data bytes). Per datasheet multiple-byte write uses pairs of reg+data,
// but many chips accept auto-increment writes; use simple reg followed by data as the API expects multiple writes.
Status BMM350::writeRegisters(uint8_t reg, const uint8_t *data, size_t length) {
    wire_.beginTransmission(address_);
    wire_.write(reg);
    for (size_t i = 0; i < length; ++i) wire_.write(data[i]);
    uint8_t res = wire_.endTransmission();
    if (res != 0) return Status::BusError;
    return Status::Ok;
}

// Low-level single-byte read using dummy byte behavior: write the register, then request length+2 bytes and discard first two.
Status BMM350::readRegisters(uint8_t reg, uint8_t *buffer, size_t length) {
    // Send register address (write) without a stop (use repeated start)
    wire_.beginTransmission(address_);
    wire_.write(reg);
    uint8_t et = wire_.endTransmission(false); // send repeated start
    if (et != 0) return Status::BusError;

    // Request length + 2 dummy bytes per datasheet
    size_t toRequest = length + 2;
    size_t got = wire_.requestFrom((int)address_, (int)toRequest);
    if (got != toRequest) return Status::BusError;

    // Discard first two dummy bytes
    if (wire_.available()) wire_.read();
    if (wire_.available()) wire_.read();

    for (size_t i = 0; i < length; ++i) {
        if (wire_.available()) {
            buffer[i] = (uint8_t)wire_.read();
        } else return Status::BusError;
    }
    return Status::Ok;
}

Status BMM350::readRegister8(uint8_t reg, uint8_t &value) {
    uint8_t buf[1];
    Status s = readRegisters(reg, buf, 1);
    if (s != Status::Ok) return s;
    value = buf[0];
    return Status::Ok;
}

// Poll PMU_CMD_STATUS_0.pmu_cmd_busy until cleared or timeout
Status BMM350::pollPmuBusyClear(uint16_t timeoutMs) {
    uint32_t start = millis();
    uint8_t st = 0;
    while (true) {
        Status s = readRegister8(BMM350Reg::PMU_CMD_STATUS_0, st);
        if (s != Status::Ok) return s;
        bool busy = (st & 0x01) != 0;
        if (!busy) return Status::Ok;
        if ((millis() - start) > timeoutMs) return Status::Timeout;
        delay(1);
    }
}

// ensureSuspended: explicitly wait for outstanding PMU busy to complete, then issue SUS, wait for busy clear, and validate
Status BMM350::ensureSuspended(uint16_t timeoutMs) {
    // Step 1: wait for any outstanding PMU busy to clear
    Status s = pollPmuBusyClear(timeoutMs);
    if (s != Status::Ok) return s;

    // Step 2: explicitly request SUSPEND
    s = writeRegister8(BMM350Reg::PMU_CMD, static_cast<uint8_t>(PmuCommand::Suspend));
    if (s != Status::Ok) return s;

    // Step 3: wait for busy clear after SUS
    s = pollPmuBusyClear(timeoutMs);
    if (s != Status::Ok) return s;

    // Step 4: verify PMU_CMD_STATUS_0: pwr_mode_is_normal == 0 and cmd_is_illegal == 0
    uint8_t st0;
    s = readRegister8(BMM350Reg::PMU_CMD_STATUS_0, st0);
    if (s != Status::Ok) return s;
    bool isNormal = (st0 & 0x08) != 0;
    bool illegal = (st0 & 0x10) != 0;
    if (illegal) return Status::PmuIllegal;
    if (isNormal) return Status::Unknown; // expected not-normal (suspend), but still normal

    // Step 5: verify ERR_REG.pmu_cmd_error == 0
    uint8_t err;
    s = readRegister8(BMM350Reg::ERR_REG, err);
    if (s != Status::Ok) return s;
    if (err & 0x01) return Status::ErrRegSet;

    return Status::Ok;
}

// waitForDataReady: poll read-to-clear INT_STATUS DRDY bit until observed or timeout
Status BMM350::waitForDataReady(uint16_t timeoutMs) {
    uint32_t start = millis();
    while (true) {
        uint8_t intst;
        Status s = readRegister8(BMM350Reg::INT_STATUS, intst);
        if (s != Status::Ok) return s;
        if (intst & 0x04) {
            // DRDY observed; read has consumed status per datasheet
            return Status::Ok;
        }
        if ((millis() - start) > timeoutMs) return Status::Timeout;
        delay(1);
    }
}

// checkPmuCommandResult: centralize PMU post-checks after busy cleared
Status BMM350::checkPmuCommandResult() {
    // Read PMU_CMD_STATUS_0 and verify illegal-command flag
    uint8_t st0;
    Status s = readRegister8(BMM350Reg::PMU_CMD_STATUS_0, st0);
    if (s != Status::Ok) return s;
    if (st0 & 0x10) return Status::PmuIllegal; // cmd_is_illegal
    // Read ERR_REG (read-to-clear)
    uint8_t err;
    s = readRegister8(BMM350Reg::ERR_REG, err);
    if (s != Status::Ok) return s;
    if (err & 0x01) return Status::ErrRegSet; // pmu_cmd_error
    return Status::Ok;
}

int32_t BMM350::decodeSigned24(const uint8_t *b) {
    // b[0] = XLSB (bits 7:0), b[1] = LSB (bits 15:8), b[2] = MSB (bits 23:16)
    uint32_t val = ((uint32_t)b[2] << 16) | ((uint32_t)b[1] << 8) | (uint32_t)b[0];
    // Sign extend 24-bit
    if (val & 0x800000) {
        return (int32_t)(val | 0xFF000000);
    } else {
        return (int32_t)val;
    }
}

// section: PMU configuration and operations

Status BMM350::chipId(uint8_t &value) {
    return readRegister8(BMM350Reg::CHIP_ID, value);
}

Status BMM350::transducerRevision(uint8_t &value) {
    return readRegister8(BMM350Reg::TRANS_DUCER_REV_ID, value);
}

Status BMM350::begin(uint16_t timeoutMs) {
    // 1) Verify CHIP_ID
    uint8_t id = 0;
    Status s = chipId(id);
    if (s != Status::Ok) return s;
    if (id != 0x33) return Status::ChipIdMismatch;

    // 2) Wait for OTP_STATUS.otp_cmd_done == 1 and error == NO_ERROR
    uint32_t start = millis();
    while (true) {
        uint8_t otpStatus;
        s = readRegister8(BMM350Reg::OTP_STATUS_REG, otpStatus);
        if (s != Status::Ok) return s;
        bool done = (otpStatus & 0x01) != 0;
        uint8_t err = (otpStatus >> 5) & 0x07;
        if (err != 0) return Status::Unknown; // OTP error reported; propagate as Unknown
        if (done) break;
        if ((millis() - start) > timeoutMs) return Status::Timeout;
        delay(1);
    }

    // 3) Terminate OTP access by writing OTP_CMD_REG = 0x80 per programming plan
    s = writeRegister8(BMM350Reg::OTP_CMD_REG, 0x80);
    if (s != Status::Ok) return s;

    // 4) Perform flux-guide reset to charge CRST and leave suspended
    // Ensure suspend before issuing reset (guard PMU sequencing)
    s = ensureSuspended(10);
    if (s != Status::Ok) return s;
    s = writeRegister8(BMM350Reg::PMU_CMD, static_cast<uint8_t>(PmuCommand::FluxGuideReset));
    if (s != Status::Ok) return s;
    s = pollPmuBusyClear(10); // conservative 10 ms per instruction
    if (s != Status::Ok) return s;
    // final check of PMU command result
    return checkPmuCommandResult();
}

Status BMM350::softReset(uint16_t timeoutMs) {
    // Write CMD 0xB6 then 0x00
    Status s = writeRegister8(BMM350Reg::CMD, 0xB6);
    if (s != Status::Ok) return s;
    s = writeRegister8(BMM350Reg::CMD, 0x00);
    if (s != Status::Ok) return s;

    // Wait for CHIP_ID to reappear as 0x33
    uint32_t start = millis();
    while (true) {
        uint8_t id;
        s = readRegister8(BMM350Reg::CHIP_ID, id);
        if (s == Status::Ok && id == 0x33) return Status::Ok;
        if ((millis() - start) > timeoutMs) return Status::Timeout;
        delay(1);
    }
}

Status BMM350::setOdrAveraging(Odr odr, Averaging averaging, uint16_t timeoutMs) {
    // Compose PMU_CMD_AGGR_SET: bits [4:5]=avg, [0:3]=odr
    uint8_t val = (static_cast<uint8_t>(averaging) << 4) | (static_cast<uint8_t>(odr) & 0x0F);
    Status s = writeRegister8(BMM350Reg::PMU_CMD_AGGR_SET, val);
    if (s != Status::Ok) return s;

    // Ensure no outstanding PMU busy before issuing update
    s = pollPmuBusyClear(timeoutMs);
    if (s != Status::Ok) return s;

    // Issue update command
    s = writeRegister8(BMM350Reg::PMU_CMD, static_cast<uint8_t>(PmuCommand::UpdOae));
    if (s != Status::Ok) return s;

    // Wait for busy clear (PMU processed the update)
    s = pollPmuBusyClear(timeoutMs);
    if (s != Status::Ok) return s;

    // Now wait for a first new data-ready indication (INT_STATUS.drdy_data_reg) which is read-to-clear
    s = waitForDataReady(timeoutMs);
    if (s != Status::Ok) return s;

    // Finally read PMU_CMD_STATUS_1 and verify effective odr and averaging match requested values
    uint8_t s1;
    s = readRegister8(BMM350Reg::PMU_CMD_STATUS_1, s1);
    if (s != Status::Ok) return s;
    Averaging effectiveAvg = static_cast<Averaging>((s1 >> 4) & 0x03);
    Odr effectiveOdr = static_cast<Odr>(s1 & 0x0F);
    if (effectiveAvg != averaging || effectiveOdr != odr) {
        return Status::Unknown; // effective settings do not match requested
    }
    // clear-check PMU command postconditions
    return checkPmuCommandResult();
}

Status BMM350::getEffectiveOdrAveraging(Odr &odr, Averaging &averaging) {
    uint8_t s1;
    Status s = readRegister8(BMM350Reg::PMU_CMD_STATUS_1, s1);
    if (s != Status::Ok) return s;
    averaging = static_cast<Averaging>((s1 >> 4) & 0x03);
    odr = static_cast<Odr>(s1 & 0x0F);
    return Status::Ok;
}

Status BMM350::setPowerMode(PmuCommand command, uint16_t timeoutMs) {
    // For commands that require suspend, ensure suspended (ensureSuspended will explicitly write SUS)
    if (command == PmuCommand::FM || command == PmuCommand::FMFast ||
        command == PmuCommand::FluxGuideReset || command == PmuCommand::FluxGuideResetFast ||
        command == PmuCommand::BitReset || command == PmuCommand::BitResetFast) {
        Status s = ensureSuspended(timeoutMs);
        if (s != Status::Ok) return s;
    } else {
        // For safety, ensure outstanding busy is cleared before issuing other commands
        Status s = pollPmuBusyClear(timeoutMs);
        if (s != Status::Ok) return s;
    }

    Status s = writeRegister8(BMM350Reg::PMU_CMD, static_cast<uint8_t>(command));
    if (s != Status::Ok) return s;

    // Wait for busy clear and check result
    s = pollPmuBusyClear(timeoutMs);
    if (s != Status::Ok) return s;
    return checkPmuCommandResult();
}

Status BMM350::triggerForcedMeasurement(bool fast, uint16_t timeoutMs) {
    // Ensure explicit suspend state (will issue SUS and validate)
    Status s = ensureSuspended(timeoutMs);
    if (s != Status::Ok) return s;
    PmuCommand cmd = fast ? PmuCommand::FMFast : PmuCommand::FM;
    s = writeRegister8(BMM350Reg::PMU_CMD, static_cast<uint8_t>(cmd));
    if (s != Status::Ok) return s;
    s = pollPmuBusyClear(timeoutMs);
    if (s != Status::Ok) return s;
    return checkPmuCommandResult();
}

Status BMM350::magneticReset(PmuCommand command, uint16_t timeoutMs) {
    // Allowed commands: FGR, FGR_FAST, BR, BR_FAST
    if (!(command == PmuCommand::FluxGuideReset || command == PmuCommand::FluxGuideResetFast ||
          command == PmuCommand::BitReset || command == PmuCommand::BitResetFast)) return Status::InvalidArgument;
    // Ensure suspended explicitly
    Status s = ensureSuspended(timeoutMs);
    if (s != Status::Ok) return s;
    s = writeRegister8(BMM350Reg::PMU_CMD, static_cast<uint8_t>(command));
    if (s != Status::Ok) return s;
    s = pollPmuBusyClear(timeoutMs);
    if (s != Status::Ok) return s;
    return checkPmuCommandResult();
}

Status BMM350::setAxes(bool x, bool y, bool z, uint16_t timeoutMs) {
    if (!x && !y && !z) return Status::InvalidArgument; // API rejects all-disabled request
    // Per plan: ensure suspended, write PMU_CMD_AXIS_EN (write-only) with bits 0..2
    Status s = ensureSuspended(timeoutMs);
    if (s != Status::Ok) return s;
    uint8_t val = (x ? 0x01 : 0x00) | (y ? 0x02 : 0x00) | (z ? 0x04 : 0x00);
    // Write-only register: simply write
    s = writeRegister8(BMM350Reg::PMU_CMD_AXIS_EN, val);
    if (s != Status::Ok) return s;
    return Status::Ok;
}

// section: Data, interrupt, self-test, and interface configuration

Status BMM350::readRawSample(RawSample &sample) {
    // Read contiguous 0x31..0x3F (15 bytes) in one transaction; decode signed 24-bit
    const size_t len = (BMM350Reg::MAG_BLOCK_END - BMM350Reg::MAG_X_XLSB) + 1;
    uint8_t buf[len];
    Status s = readRegisters(BMM350Reg::MAG_X_XLSB, buf, len);
    if (s != Status::Ok) return s;
    // Decode X: buf[0..2], Y: buf[3..5], Z: buf[6..8], TEMP: buf[9..11], SENSORTIME: buf[12..14]
    sample.x = decodeSigned24(&buf[0]);
    sample.y = decodeSigned24(&buf[3]);
    sample.z = decodeSigned24(&buf[6]);
    sample.temperature = decodeSigned24(&buf[9]);
    // Sensor time unsigned 24
    sample.sensortime = ((uint32_t)buf[14] << 16) | ((uint32_t)buf[13] << 8) | (uint32_t)buf[12];
    return Status::Ok;
}

Status BMM350::dataReady(bool &ready) {
    uint8_t st;
    Status s = readRegister8(BMM350Reg::INT_STATUS, st);
    if (s != Status::Ok) return s;
    ready = (st & 0x04) != 0; // drdy_data_reg bit is bit2
    // Note: reading INT_STATUS may clear the latched status per datasheet
    return Status::Ok;
}

Status BMM350::configureInterrupt(const InterruptConfig &config) {
    // Read current register to preserve reserved bits [6:4]
    uint8_t cur;
    Status s = readRegister8(BMM350Reg::INT_CTRL, cur);
    if (s != Status::Ok) return s;
    uint8_t preserved = cur & 0x70; // preserve bits 6:4
    uint8_t configuredFields = 0;
    if (config.drdy_data_reg_en) configuredFields |= (1 << 7);
    if (config.int_output_en) configuredFields |= (1 << 3);
    if (config.int_od) configuredFields |= (1 << 2);
    if (config.int_pol) configuredFields |= (1 << 1);
    if (config.int_mode) configuredFields |= (1 << 0);
    uint8_t newVal = preserved | (configuredFields & 0x8F); // ensure we only set documented bits
    s = writeRegister8(BMM350Reg::INT_CTRL, newVal);
    return s;
}

Status BMM350::configureIbi(bool mapDataReady, bool clearOnIbi) {
    // INT_CTRL_IBI is RW; preserve reserved bits and only touch documented bits
    uint8_t cur;
    Status s = readRegister8(BMM350Reg::INT_CTRL_IBI, cur);
    if (s != Status::Ok) return s;
    uint8_t newVal = cur;
    if (mapDataReady) newVal |= 0x01; else newVal &= ~0x01;
    if (clearOnIbi) newVal |= 0x10; else newVal &= ~0x10;
    s = writeRegister8(BMM350Reg::INT_CTRL_IBI, newVal);
    return s;
}

Status BMM350::setPadDrive(uint8_t drive) {
    if (drive > 7) return Status::InvalidArgument;
    uint8_t cur;
    Status s = readRegister8(BMM350Reg::PAD_CTRL, cur);
    if (s != Status::Ok) return s;
    // preserve reserved bits [7:3]
    uint8_t newVal = (cur & 0xF8) | (drive & 0x07);
    s = writeRegister8(BMM350Reg::PAD_CTRL, newVal);
    return s;
}

Status BMM350::setI2cWatchdog(bool enabled, bool longTimeout) {
    uint8_t cur;
    Status s = readRegister8(BMM350Reg::I2C_WDT_SET, cur);
    if (s != Status::Ok) return s;
    uint8_t newVal = cur & 0xFC; // clear bit1 and bit0
    if (longTimeout) newVal |= (1 << 1);
    if (enabled) newVal |= 1;
    s = writeRegister8(BMM350Reg::I2C_WDT_SET, newVal);
    return s;
}

Status BMM350::setSensorTimeAlwaysOn(bool enabled, uint16_t timeoutMs) {
    // Must be in suspend to write CTRL_USER.cfg_sens_tim_aon
    // Save whether device was normal to restore
    uint8_t st0;
    Status s = readRegister8(BMM350Reg::PMU_CMD_STATUS_0, st0);
    if (s != Status::Ok) return s;
    bool wasNormal = (st0 & 0x08) != 0;
    if (wasNormal) {
        s = ensureSuspended(timeoutMs);
        if (s != Status::Ok) return s;
    }
    uint8_t cur;
    s = readRegister8(BMM350Reg::CTRL_USER, cur);
    if (s != Status::Ok) return s;
    uint8_t newVal = cur;
    if (enabled) newVal |= 0x01; else newVal &= ~0x01;
    s = writeRegister8(BMM350Reg::CTRL_USER, newVal);
    if (s != Status::Ok) return s;
    // restore normal mode if it was originally normal
    if (wasNormal) {
        s = setPowerMode(PmuCommand::Normal, timeoutMs);
    }
    return s;
}

Status BMM350::runSelfTest(uint8_t axis, SelfTestResult &result, uint16_t timeoutMs) {
    // axis: 1 for X, 2 for Y
    if (axis != 1 && axis != 2) return Status::InvalidArgument;
    // Must be in suspend
    Status s = ensureSuspended(timeoutMs);
    if (s != Status::Ok) return s;

    // Capture baseline sample via forced measurement
    s = triggerForcedMeasurement(false, timeoutMs);
    if (s != Status::Ok) return s;
    s = readRawSample(result.baseline);
    if (s != Status::Ok) return s;

    // Enable internal self-test generator and axis, set positive self-test (st_p) only
    uint8_t st_val = 0x01; // st_igen_en
    if (axis == 1) st_val |= (1 << 3); // ist_en_x bit3
    else st_val |= (1 << 4); // ist_en_y bit4
    st_val |= (1 << 2); // st_p bit2
    // Write TMR_SELFTEST_USER register
    s = writeRegister8(BMM350Reg::TMR_SELFTEST_USER, st_val);
    if (s != Status::Ok) return s;

    // Trigger forced measurement to capture stimulated sample
    s = triggerForcedMeasurement(false, timeoutMs);
    if (s != Status::Ok) {
        // attempt to clear selftest bits before returning
        uint8_t clr = 0x00;
        writeRegister8(BMM350Reg::TMR_SELFTEST_USER, clr);
        return s;
    }
    s = readRawSample(result.stimulated);
    if (s != Status::Ok) {
        uint8_t clr = 0x00;
        writeRegister8(BMM350Reg::TMR_SELFTEST_USER, clr);
        return s;
    }

    // Compute delta = stimulated - baseline
    result.delta.x = result.stimulated.x - result.baseline.x;
    result.delta.y = result.stimulated.y - result.baseline.y;
    result.delta.z = result.stimulated.z - result.baseline.z;
    result.delta.temperature = result.stimulated.temperature - result.baseline.temperature;
    result.delta.sensortime = (uint32_t)(result.stimulated.sensortime - result.baseline.sensortime);

    // Clear self-test bits
    uint8_t clr = 0x00;
    writeRegister8(BMM350Reg::TMR_SELFTEST_USER, clr);
    return Status::Ok;
}

Status BMM350::readAndClearError(bool &pmuCommandError) {
    uint8_t val;
    Status s = readRegister8(BMM350Reg::ERR_REG, val);
    if (s != Status::Ok) return s;
    pmuCommandError = (val & 0x01) != 0;
    // reading clears ERR_REG per datasheet
    return Status::Ok;
}

Status BMM350::readI3cError(uint8_t &flags) {
    Status s = readRegister8(BMM350Reg::I3C_ERR, flags);
    return s;
}

