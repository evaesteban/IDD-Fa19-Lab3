/* ECE 5413 - Developing and Designing Interactive Devices
 *  Lab 3 Exercise E
 *  Author: Eva Pilar Esteban Velasco
 *  Resources: Adafruit SSD 1306 ssd1306_128x32_i2c example code
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

int fsrPin = A0;
int fsrValue = 0;
int fsrValueMapped = 0;

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
}

void loop() {

  // clear display
  display.clearDisplay();

  // read FSR sensor value
  fsrValue = analogRead(fsrPin);

  // map FSR sensor value to range 0-255
  fsrValueMapped = map(fsrValue, 0, 1023, 0, 255);

  // display mapped FSR sensor value
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print(F("FSR: "));
  display.setCursor(60, 0);
  display.print(fsrValueMapped);
  display.display();      // Show initial text

  // delay to allow the user time to see the numbers
  delay(100);
}
