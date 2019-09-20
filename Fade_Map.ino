/*
  ECE 5413 - Developing and Designing Interactive Devices
  Lab 3 Part C Exercise 3
  Author: Eva Pilar Esteban Velasco
  Resources: Arduino Fade Example Code as a base
*/

int ledPin = 9;           // the PWM pin the LED is attached to
int fsrPin = A0;        // the analog pin the FSR is connected to
int brightness = 0;    // how bright the LED is
int fsrValue = 0;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  fsrValue = analogRead(fsrPin);

  // check values are being read correcly
  Serial.print("FSR: ");
  Serial.print(fsrValue);
  Serial.print("\n");

  // map range of brightness parameter from 0-255 to 0-1023
  brightness = map(fsrValue, 0, 1023, 0, 255);

  // check values are being mapped correcly
  Serial.print("Brightness: ");
  Serial.print(brightness);
  Serial.print("\n");

  // set the brightness of led
  analogWrite(ledPin, fsrValue);

  // wait for 1 second
  delay(1000);
}
