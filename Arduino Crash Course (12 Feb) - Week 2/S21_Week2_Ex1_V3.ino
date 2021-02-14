// 41028 DTU, Spring 21
// author : Mathias Hovmark
// Week 2 - exercise 1.3

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status
int lastbuttonState = 0;
unsigned long buttonMillis; // Button millis, used to measure the time the button has been held down
unsigned long printMillis; // Print millis, used to measure the time since last print
unsigned long currentMillis; // Current millis, updated at the start of every loop
const unsigned long period = 5000;
const unsigned long printperiod = 1000;
int counter = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  printMillis = millis();

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  currentMillis = millis();

  // check if the pushbutton is pressed (status = HIGH).
  if (buttonState != lastbuttonState) {
    delay(10); // mitigate bouncing causing button state to change
    buttonState = digitalRead(buttonPin);
    if (buttonState != lastbuttonState)
    {
      lastbuttonState = buttonState; // Update button state
      if (buttonState == HIGH) { // If button state is high, increment counter and start millis. Note millis is only started if buttonstate is HIGH.
        buttonMillis = millis();
        counter++;
        delay(10);
      }
    }
  }

  // If button state is low, reset button millis (button is no longer being held down and the counter should therefore reset).
  if (buttonState == LOW) {
    buttonMillis = currentMillis;
  }

  // If the button state is high and 5 seconds have passed, reset counter and millis. (Could also be achieved with a while-loop).
  if (buttonState == HIGH) {
    if (currentMillis - buttonMillis >= period) {
      counter = 0;
      buttonMillis = currentMillis;
    }
  }


  // Turn on LED if counter is even
  if (counter % 2 == 0) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }

  else {
    digitalWrite(ledPin, LOW);
  }

  delay(10);

  // Print counter value every 1 second and reset printmillis to current millis.
  if (currentMillis - printMillis >= printperiod) {
    Serial.println(counter);
    printMillis = currentMillis;
  }
}
