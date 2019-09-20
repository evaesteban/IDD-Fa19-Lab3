// ECE 5413 - Developing and Designing Interactive Devices
// Lab 3 Exercise 2
// Author: Eva Pilar Esteban Velasco 
//Resources: Basic demo for accelerometer readings from Adafruit LIS3DH used as base code

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int ledRed = 10;
int ledGreen = 9;
int ledBlue = 8;

int nRed = 0;
int nGreen = 0;
int nBlue = 0;

int mappedRed = 0;
int mappedGreen = 0;
int mappedBlue = 0;

void setup(void) {
#ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  Serial.begin(9600);
  Serial.println("LIS3DH test!");

  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("LIS3DH found!");

  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!

  Serial.print("Range = "); Serial.print(2 << lis.getRange());
  Serial.println("G");
}

void loop() {

  lis.read();      // get X Y and Z data at once

  // display values on LCD screen
  lcd.setCursor(0, 0);
  lcd.print("X: ");
  lcd.setCursor(2, 0);
  lcd.print(lis.x);
  lcd.setCursor(8, 0);
  lcd.print("Y: ");
  lcd.setCursor(10, 0);
  lcd.print(lis.y);
  lcd.setCursor(0, 1);
  lcd.print("Z: ");
  lcd.setCursor(2, 1);
  lcd.print(lis.z);

// map accelerometer values to led range 0-255

  if (lis.x > 0) {
    nRed = lis.x / 255; // calculate number of times it goes over the 0-255 range
    mappedRed = lis.x - nRed * 255; // get value in range 0-255 after substracting nRed
  } else {
    mappedRed = 0; // map negative values to 0 brightness
  }

  if (lis.y > 0) {
    nGreen = lis.y / 255; // calculate number of times it goes over the 0-255 range
    mappedGreen = lis.y - nGreen * 255; // get value in range 0-255 after substracting nGreen
  } else {
    mappedGreen = 0; // map negative values to 0 brightness
  }

  if (lis.z > 0) {
    nBlue = lis.z / 255; // calculate number of times it goes over the 0-255 range
    mappedBlue = lis.z - nBlue * 255; // get value in range 0-255 after substracting nBlue
  } else {
    mappedBlue = 0; // map negative values to 0 brightness
  }

  // write values to the corresponding LED pins
  analogWrite(ledRed, mappedRed);
  analogWrite(ledGreen, mappedGreen);
  analogWrite(ledBlue, mappedBlue);

  // wait 1.5 seconds
  delay(1500);
}
