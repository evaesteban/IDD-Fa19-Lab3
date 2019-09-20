// This borrows code from Examples->EEPROM->eeprom_write

//String textarray = "hello cornell tech!";
int endAddr;
int cellValue = 0;
int cellValueMapped = 0;

void state2Setup() {
  
  digitalWrite(ledPin, LOW);
  Serial.println("Writing to EEPROM");

  // read photocell value
  cellValue = analogRead(cellPin);

  cellValueMapped = map(cellValue, 0, 1023, 0, 255);

  // write value to EEPROM
  EEPROM.write(0, cellValueMapped);

  Serial.println("String committed to EEPROM!");
}

void state2Loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void doState2() {
  if (lastState != 2) state2Setup();
  state2Loop();
}
