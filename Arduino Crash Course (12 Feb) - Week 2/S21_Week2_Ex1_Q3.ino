// 41028 DTU, Spring 21
// Week 2 - exercise 1.3

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status
int lastbuttonState = 0;
unsigned long startMillis;  
unsigned long currentMillis;
const unsigned long period = 5000;  
int counter = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

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
        startMillis = millis();
        counter++;
        delay(20);
      }
      // If button state changes from high to low, reset millis counter 
      // (takes into account sequences such as 2 sec down, 1 sec not down, 3 sec down, which would otherwise activate the 5 second millis threshold)
      else {
        startMillis = currentMillis;
      }
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
  
  Serial.println(counter);

  // If the button state is high and 5 seconds have passed, reset counter and millis. (Could also be achieved with a while-loop).
  if (buttonState == HIGH) {
    currentMillis = millis();
    if (currentMillis - startMillis >= period) {
      counter = 0;
      startMillis = currentMillis;
    }
  }

  delay(10);
  //Serial.println(startMillis);
}
