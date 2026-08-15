#include <Arduino.h>
#include <Wire.h>

#include "bme280.h"

static struct bme280_dev bme280;
static uint8_t bme280Address = BME280_I2C_ADDR_PRIM;


/**
 * @brief Reads BME280 registers through I2C.
 */
static BME280_INTF_RET_TYPE bme280I2cRead(
    uint8_t regAddr,
    uint8_t *regData,
    uint32_t len,
    void *intfPtr)
{
    const uint8_t deviceAddress =
        *(static_cast<uint8_t *>(intfPtr));

    Wire.beginTransmission(deviceAddress);
    Wire.write(regAddr);

    if (Wire.endTransmission(false) != 0)
    {
        return BME280_E_COMM_FAIL;
    }

    const uint32_t received =
        Wire.requestFrom(deviceAddress, static_cast<uint8_t>(len));

    if (received != len)
    {
        return BME280_E_COMM_FAIL;
    }

    for (uint32_t i = 0; i < len; i++)
    {
        regData[i] = Wire.read();
    }

    return BME280_INTF_RET_SUCCESS;
}


/**
 * @brief Writes BME280 registers through I2C.
 */
static BME280_INTF_RET_TYPE bme280I2cWrite(
    uint8_t regAddr,
    const uint8_t *regData,
    uint32_t len,
    void *intfPtr)
{
    const uint8_t deviceAddress =
        *(static_cast<uint8_t *>(intfPtr));

    Wire.beginTransmission(deviceAddress);
    Wire.write(regAddr);

    for (uint32_t i = 0; i < len; i++)
    {
        Wire.write(regData[i]);
    }

    if (Wire.endTransmission() != 0)
    {
        return BME280_E_COMM_FAIL;
    }

    return BME280_INTF_RET_SUCCESS;
}


/**
 * @brief Provides the delay callback required by the BME280 driver.
 */
static void bme280DelayUs(
    uint32_t period,
    void *intfPtr)
{
    (void)intfPtr;

    delayMicroseconds(period);
}


void setup()
{
    Serial.begin(115200);

    Wire.setSDA(0);
    Wire.setSCL(1);
    Wire.begin();

    delay(1000);

    bme280.intf = BME280_I2C_INTF;
    bme280.intf_ptr = &bme280Address;
    bme280.read = bme280I2cRead;
    bme280.write = bme280I2cWrite;
    bme280.delay_us = bme280DelayUs;

    int8_t result = bme280_init(&bme280);

    if (result != BME280_OK)
    {
        Serial.print("BME280 initialization failed: ");
        Serial.println(result);
        return;
    }

    struct bme280_settings settings = {};

    settings.osr_t = BME280_OVERSAMPLING_2X;
    settings.osr_h = BME280_OVERSAMPLING_2X;
    settings.osr_p = BME280_NO_OVERSAMPLING;
    settings.filter = BME280_FILTER_COEFF_OFF;
    settings.standby_time = BME280_STANDBY_TIME_1000_MS;

    result = bme280_set_sensor_settings(
        BME280_SEL_OSR_TEMP |
        BME280_SEL_OSR_HUM |
        BME280_SEL_OSR_PRESS |
        BME280_SEL_FILTER |
        BME280_SEL_STANDBY,
        &settings,
        &bme280
    );

    if (result != BME280_OK)
    {
        Serial.print("BME280 configuration failed: ");
        Serial.println(result);
        return;
    }

    result = bme280_set_sensor_mode(
        BME280_POWERMODE_NORMAL,
        &bme280
    );

    if (result != BME280_OK)
    {
        Serial.print("BME280 mode configuration failed: ");
        Serial.println(result);
        return;
    }

    Serial.println("BME280 initialized successfully.");
}


void loop()
{
    struct bme280_data data = {};

    const int8_t result = bme280_get_sensor_data(
        BME280_TEMP | BME280_HUM,
        &data,
        &bme280
    );

    if (result == BME280_OK)
    {
        Serial.print("Temperature: ");
        Serial.print(data.temperature, 2);
        Serial.println(" C");

        Serial.print("Humidity: ");
        Serial.print(data.humidity, 2);
        Serial.println(" %");

        Serial.println();
    }
    else
    {
        Serial.print("BME280 read failed: ");
        Serial.println(result);
    }

    delay(1000);
}