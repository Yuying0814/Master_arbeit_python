#include <Arduino.h>
#include <Wire.h>

#include "bme280.h"

BME280 sensor;

void setup()
{
    Serial.begin(115200);

    Wire.setSDA(0);
    Wire.setSCL(1);
    Wire.begin();

    delay(1000);

    if (!sensor.begin(BME280_I2C_ADDR_0, Wire))
    {
        Serial.println("BME280 initialization failed.");
        return;
    }

    if (!sensor.configure(
            1,  // Temperature oversampling x1
            0,  // Pressure disabled
            1,  // Humidity oversampling x1
            3,  // Normal mode
            5,  // Standby time 1000 ms
            0   // Filter off
        ))
    {
        Serial.println("BME280 configuration failed.");
        return;
    }

    Serial.println("BME280 initialized successfully.");
}

void loop()
{
    const float temperature = sensor.readTemperature();
    const float humidity = sensor.readHumidity();

    if (isnan(temperature) || isnan(humidity))
    {
        Serial.println("BME280 read failed.");
    }
    else
    {
        Serial.print("Temperature: ");
        Serial.print(temperature, 2);
        Serial.println(" C");

        Serial.print("Humidity: ");
        Serial.print(humidity, 2);
        Serial.println(" %");

        Serial.println();
    }

    delay(1000);
}