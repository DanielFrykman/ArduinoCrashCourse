// All led functions

// turn on the led sequence:
void turnOnLedSeq() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    digitalWrite(ledPins[thisPin], HIGH);

    delay(200); // time between each led turning on
  }
}

// turn off the led sequence:
void turnOffLedSeq() {
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], LOW);

    delay(200); // time between each led turning off
  }
}

// turn on the led's:
void turnOnAllLeds() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    digitalWrite(ledPins[thisPin], HIGH);

    delay(1); 
  }
}

// turn on the led's:
void turnOffAllLeds() {
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], LOW);

    delay(1); 
  }
}
