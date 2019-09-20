// This borrows code from Examples->EEPROM->eeprom_read

byte value;

void state1Setup() {
  Serial.println("Reading from EEPROM");

  // read value stored in EEPROM
  value = EEPROM.read(0);
  Serial.print(value);
  Serial.println();

  Serial.println("Done reading from EEPROM");
}

void state1Loop() {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

void doState1() {
  if (lastState != 1) {
    state1Setup();
  }
  state1Loop();
}
