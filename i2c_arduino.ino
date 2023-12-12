#include <Arduino.h>
#include <Wire.h>

#define I2C_DEVICE_ADDRESS 0x44

void setup() {
  Wire.begin(I2C_DEVICE_ADDRESS);
  Wire.onReceive(receiveMsg);
  Serial.begin(9600);
  Serial.println("Listening for Input");
}

void loop() {
  Serial.print(".");
  delay(500);
}

void receiveMsg() {
  if (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
}