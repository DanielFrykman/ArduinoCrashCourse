/*
   Author - Oscar V. Bubandt

   This code demonstrates toggeling led sequences on and of with push buttons.
   This code is done wihout tabs and void functions.
*/

// the number of the push button pins
int buttonPin_1 = 8;
int buttonPin_2 = 9;

int ledPins[] = {
  2, 3, 4, 5, 6, 7
};       // an array of pin numbers to which LEDs are attached

int pinCount = 6; // the number of pins (i.e. the length of the array)

boolean on = false; // led's are turned off by default

// variables for reading the pushbutton states
int buttonState_1 = 0;
int buttonState_2 = 0;

void setup() {
  // the array elements are numbered from 0 to (pinCount - 1).
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }

  // initialize the pushbutton pins as an inputs:
  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);
}

void loop() {
  // read the state of the pushbutton values:
  buttonState_1 = digitalRead(buttonPin_1);
  buttonState_2 = digitalRead(buttonPin_2);

  // checking "buttonState_1"
  if (buttonState_1 == HIGH) {
    if (on == true) {
      on = false;
    }  else {
      on = true;
    }
  }

  // turn on the led sequence:
  if (on == true) {
    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      digitalWrite(ledPins[thisPin], HIGH);

      delay(200); // time between each led turning on
    }
  }

  // turn off the led sequence:
  else {
    for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
      // turn the pin on:
      digitalWrite(ledPins[thisPin], LOW);

      delay(200); // time between each led turning off
    }
  }


  /*
     toggeling the secind push button
     uses same logic as the first button
  */
  if (buttonState_2 == HIGH) {
    if (on == true) {
      on = false;
    }  else {
      on = true;
    }
  }

  // turn on all led's
  if (on == true) {
    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      // turn the pin on:
      digitalWrite(ledPins[thisPin], HIGH);

      delay (1);
    }
  }

  // turn off all led's
  else {
    for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
      // turn the pin on:
      digitalWrite(ledPins[thisPin], LOW);

      delay (1);
    }
  }

  delay(5); // push button reading time
}
