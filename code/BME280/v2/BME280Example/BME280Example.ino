/*
Minimal compile-verification sketch for I2C BME280 use.
*/

// Includes and driver instance: Include Wire.h and BME280.h and construct a BME280 instance using Wire.

#include <Wire.h>
#include "BME280.h"

BME280 sensor(Wire, 0x76);

// Arduino entry points: Initialize Wire and invoke driver begin in setup; provide an empty loop.

void setup() {
  Wire.begin();
  bool ok = sensor.begin();
  if (!ok) {
    // simple serial for debug if needed
    Serial.begin(115200);
    Serial.println("BME280 begin failed");
  }
}

void loop() {
  // idle
  delay(1000);
}

