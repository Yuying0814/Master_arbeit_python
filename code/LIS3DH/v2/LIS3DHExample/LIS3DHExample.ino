/*
Minimal I2C LIS3DH initialization sketch.
*/

// Includes and instance: include Wire and driver, create I2C instance
// section_name: Includes and instance

#include <Wire.h>
#include "LIS3DH.h"

LIS3DH sensor; // default I2C Wire, address 0x18

// Arduino entry points
// section_name: Arduino entry points

void setup() {
  Wire.begin();
  Serial.begin(115200);
  if (!sensor.begin()) {
    Serial.println("LIS3DH begin failed");
    while (1) delay(1000);
  }
  Serial.println("LIS3DH initialized");
}

void loop() {
  // idle
  delay(1000);
}

