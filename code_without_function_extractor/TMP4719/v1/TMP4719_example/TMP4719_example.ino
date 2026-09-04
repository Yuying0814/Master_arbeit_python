/*
Minimal entrance sketch: includes Wire.h and TMP4719.h, calls Wire.begin() and sensor.begin().
*/

// Includes and global instance: minimal example
#include <Wire.h>
#include "TMP4719.h"

// Default 7-bit I2C address per datasheet retrieval: 0x4D
#ifndef TMP4719_I2C_ADDRESS
  #define TMP4719_I2C_ADDRESS 0x4D
#endif

TMP4719 sensor;

void setup() {
  Wire.begin(); // User must call this before using the driver
  Serial.begin(115200);
  delay(10);
  // Initialize driver with address and default Wire instance
  sensor.begin(TMP4719_I2C_ADDRESS, Wire);

  if (sensor.isConnected()) {
    Serial.println("TMP4719: device responded on I2C bus.");
  } else {
    Serial.println("TMP4719: device not found at address. Check wiring and address.");
  }
}

void loop() {
  // Empty loop: this sketch only demonstrates initialization.
  delay(1000);
}

