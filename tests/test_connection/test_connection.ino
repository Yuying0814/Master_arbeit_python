#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

// -----------------------------------------------------------------------------
// RP2040 GPIO configuration
// -----------------------------------------------------------------------------

// RP2040 physical pin 2 -> GPIO0.
// RP2040 physical pin 3 -> GPIO1.
constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 1;

// RP2040 physical pin 4 -> GPIO2.
// RP2040 physical pin 5 -> GPIO3.
// RP2040 physical pin 6 -> GPIO4.
constexpr uint8_t SPI_SCLK_PIN = 2;
constexpr uint8_t SPI_MOSI_PIN = 3;
constexpr uint8_t SPI_MISO_PIN = 4;

// RP2040 physical pin 7 -> GPIO5.
// RP2040 physical pin 12 -> GPIO9.
constexpr uint8_t MLX_CS1_PIN = 5;
constexpr uint8_t MLX_CS0_PIN = 9;


// -----------------------------------------------------------------------------
// I2C addresses
// -----------------------------------------------------------------------------

constexpr uint8_t TMP4719_ADDRESS = 0x4D;
constexpr uint8_t BME280_ADDRESS = 0x76;
constexpr uint8_t IAM20680HV_ADDRESS = 0x68;
constexpr uint8_t LIS3DH_ADDRESS = 0x18;
constexpr uint8_t BMM350_ADDRESS = 0x14;
constexpr uint8_t TCS34725_ADDRESS = 0x29;


// -----------------------------------------------------------------------------
// MLX90382 SPI configuration
// -----------------------------------------------------------------------------

constexpr uint32_t MLX_SPI_FREQUENCY = 1000000;

// STATE register used for a non-destructive communication probe.
constexpr uint16_t MLX_STATE_REGISTER = 0x002C;


// -----------------------------------------------------------------------------
// Monitor configuration
// -----------------------------------------------------------------------------

constexpr uint32_t STATUS_INTERVAL_MS = 2000;

uint32_t lastStatusTime = 0;


// -----------------------------------------------------------------------------
// Device definitions
// -----------------------------------------------------------------------------

struct I2CDevice {
    const char* name;
    uint8_t address;
};

const I2CDevice i2cDevices[] = {
    {"TMP4719", TMP4719_ADDRESS},
    {"BME280", BME280_ADDRESS},
    {"IAM20680HV", IAM20680HV_ADDRESS},
    {"LIS3DH", LIS3DH_ADDRESS},
    {"BMM350", BMM350_ADDRESS},
    {"TCS34725", TCS34725_ADDRESS},
};

constexpr size_t I2C_DEVICE_COUNT =
    sizeof(i2cDevices) / sizeof(i2cDevices[0]);


struct MLX90382ProbeResult {
    bool connected;
    uint16_t state;
    uint8_t commandEcho;
    uint8_t addressEcho;
};


// -----------------------------------------------------------------------------
// I2C communication
// -----------------------------------------------------------------------------

/**
 * Probe an I2C slave by checking its ACK response.
 */
bool probeI2CDevice(uint8_t address) {
    Wire.beginTransmission(address);

    const uint8_t result = Wire.endTransmission();

    return result == 0;
}


/**
 * Print the state of one I2C device.
 */
void printI2CStatus(const I2CDevice& device) {
    const bool connected = probeI2CDevice(device.address);

    Serial.print(device.name);
    Serial.print(" [I2C 0x");

    if (device.address < 0x10) {
        Serial.print('0');
    }

    Serial.print(device.address, HEX);
    Serial.print("]: ");

    if (connected) {
        Serial.println("CONNECTED");
    } else {
        Serial.println("DISCONNECTED");
    }
}


// -----------------------------------------------------------------------------
// MLX90382 SPI communication
// -----------------------------------------------------------------------------

/**
 * Probe an MLX90382 by reading its STATE register.
 *
 * The transaction additionally checks the returned command and address echoes
 * to distinguish a valid SPI response from an inactive MISO line.
 */
MLX90382ProbeResult probeMLX90382(uint8_t chipSelectPin) {
    const uint16_t address = MLX_STATE_REGISTER;

    // Register-read command with address bit 9 encoded in bit 0.
    const uint8_t command =
        0xCC |
        static_cast<uint8_t>((address >> 9) & 0x01);

    // Transfer register address bits [8:1].
    const uint8_t alignedAddress =
        static_cast<uint8_t>((address >> 1) & 0xFF);

    SPI.beginTransaction(
        SPISettings(
            MLX_SPI_FREQUENCY,
            MSBFIRST,
            SPI_MODE0
        )
    );

    digitalWrite(chipSelectPin, LOW);

    // Send the register-read command.
    SPI.transfer(command);

    // Receive the command echo.
    const uint8_t commandEcho =
        SPI.transfer(alignedAddress);

    // Receive the address echo.
    const uint8_t addressEcho =
        SPI.transfer(0x00);

    // Receive the 16-bit register value.
    const uint8_t dataHigh =
        SPI.transfer(0x00);

    const uint8_t dataLow =
        SPI.transfer(0x00);

    digitalWrite(chipSelectPin, HIGH);

    SPI.endTransaction();

    const bool connected =
        commandEcho == command &&
        addressEcho == alignedAddress;

    const uint16_t state =
        (static_cast<uint16_t>(dataHigh) << 8) |
        static_cast<uint16_t>(dataLow);

    return {
        connected,
        state,
        commandEcho,
        addressEcho
    };
}


/**
 * Print a 16-bit value with fixed-width hexadecimal formatting.
 */
void printHex16(uint16_t value) {
    if (value < 0x1000) {
        Serial.print('0');
    }

    if (value < 0x0100) {
        Serial.print('0');
    }

    if (value < 0x0010) {
        Serial.print('0');
    }

    Serial.print(value, HEX);
}


/**
 * Print the communication state of one MLX90382 interface.
 */
bool printMLXStatus(
    const char* name,
    uint8_t chipSelectPin
) {
    const MLX90382ProbeResult result =
        probeMLX90382(chipSelectPin);

    Serial.print(name);
    Serial.print(" [SPI CS=GP");
    Serial.print(chipSelectPin);
    Serial.print("]: ");

    if (!result.connected) {
        Serial.println("DISCONNECTED");
        return false;
    }

    Serial.print("CONNECTED | STATE=0x");
    printHex16(result.state);
    Serial.println();

    return true;
}


// -----------------------------------------------------------------------------
// Status reporting
// -----------------------------------------------------------------------------

/**
 * Print the current communication state of all connected sensors.
 */
void printSensorStatus() {
    Serial.println();
    Serial.println("========================================");
    Serial.println("Sensor connectivity status");
    Serial.println("========================================");

    for (size_t i = 0; i < I2C_DEVICE_COUNT; ++i) {
        printI2CStatus(i2cDevices[i]);
    }

    Serial.println("----------------------------------------");

    const bool mlxCs0Connected =
        printMLXStatus(
            "MLX90382 CS0",
            MLX_CS0_PIN
        );

    const bool mlxCs1Connected =
        printMLXStatus(
            "MLX90382 CS1",
            MLX_CS1_PIN
        );

    Serial.print("MLX90382 overall: ");

    if (mlxCs0Connected && mlxCs1Connected) {
        Serial.println("CONNECTED");
    } else if (mlxCs0Connected || mlxCs1Connected) {
        Serial.println("PARTIALLY CONNECTED");
    } else {
        Serial.println("DISCONNECTED");
    }

    Serial.println("========================================");
}


// -----------------------------------------------------------------------------
// Arduino entry points
// -----------------------------------------------------------------------------

void setup() {
    Serial.begin(115200);

    delay(1000);

    Serial.println();
    Serial.println("Sensor connectivity monitor starting.");

    // Configure RP2040 I2C0.
    const bool sdaConfigured =
        Wire.setSDA(I2C_SDA_PIN);

    const bool sclConfigured =
        Wire.setSCL(I2C_SCL_PIN);

    Serial.print("I2C SDA GP");
    Serial.print(I2C_SDA_PIN);
    Serial.print(": ");
    Serial.println(
        sdaConfigured ? "CONFIGURED" : "CONFIGURATION FAILED"
    );

    Serial.print("I2C SCL GP");
    Serial.print(I2C_SCL_PIN);
    Serial.print(": ");
    Serial.println(
        sclConfigured ? "CONFIGURED" : "CONFIGURATION FAILED"
    );

    Wire.begin();
    Wire.setClock(100000);

    // Configure RP2040 hardware SPI0.
    const bool sckConfigured =
        SPI.setSCK(SPI_SCLK_PIN);

    const bool mosiConfigured =
        SPI.setTX(SPI_MOSI_PIN);

    const bool misoConfigured =
        SPI.setRX(SPI_MISO_PIN);

    Serial.print("SPI SCLK GP");
    Serial.print(SPI_SCLK_PIN);
    Serial.print(": ");
    Serial.println(
        sckConfigured ? "CONFIGURED" : "CONFIGURATION FAILED"
    );

    Serial.print("SPI MOSI GP");
    Serial.print(SPI_MOSI_PIN);
    Serial.print(": ");
    Serial.println(
        mosiConfigured ? "CONFIGURED" : "CONFIGURATION FAILED"
    );

    Serial.print("SPI MISO GP");
    Serial.print(SPI_MISO_PIN);
    Serial.print(": ");
    Serial.println(
        misoConfigured ? "CONFIGURED" : "CONFIGURATION FAILED"
    );

    SPI.begin();

    // Chip-select lines are controlled manually.
    pinMode(MLX_CS0_PIN, OUTPUT);
    pinMode(MLX_CS1_PIN, OUTPUT);

    digitalWrite(MLX_CS0_PIN, HIGH);
    digitalWrite(MLX_CS1_PIN, HIGH);

    delay(100);

    Serial.println();
    Serial.println("Sensor connectivity monitor started.");

    // Print the first result immediately.
    printSensorStatus();

    lastStatusTime = millis();
}


void loop() {
    const uint32_t currentTime = millis();

    if (currentTime - lastStatusTime >= STATUS_INTERVAL_MS) {
        lastStatusTime = currentTime;

        printSensorStatus();
    }
}