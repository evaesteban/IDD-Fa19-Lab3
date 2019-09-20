/*
  ECE 5413 - Developing and Designing Interactive Devices
  Lab 3 Part F Exercise e
  Author: Eva Pilar Esteban Velasco
  Resources: code created by Wendy Ju modified from switchCase by Tom Igoe used as base code
*/

#include <EEPROM.h>

const int numStates = 3;
const int sensorMin = 0;
const int sensorMax = 1024;
const int EEPROMSIZE = 1024;

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = LED_BUILTIN;
int state, lastState = -1;
int cellPin = A1; // set nalog pin for photocell

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // map the pot range to number of states :
  state = map(analogRead(sensorPin), sensorMin, sensorMax, 0, numStates);
  // do something different depending on the
  // range value:
  switch (state) {
    case 0:
      doState0();
      break;
    case 1:
      doState1();
      break;
    case 2:
      doState2();
      break;
  }
  lastState = state;
}
