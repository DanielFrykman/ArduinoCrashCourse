/* Button count and reset
 * author : Daniel Lilja Frykman
 * This code is based on the two build in examples from the Arduino IDE (https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection and https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay). 
 * Some of the logic have been changed inorder to help with easy code-understanding.
 * THIS IS NOT THE ONLY AND/OR IDEAL SOLUTION FOR THE EXERCISES IN WEEK 2 OF THE MECHATRONIC COURSE (https://learn.inside.dtu.dk/d2l/le/content/59917/viewContent/228278/View)
*/

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0; 
unsigned long currentMillis = 0; 

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int timerCounter = 0;       // counter for the seconds that the buttons is pressed


void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // read the time of the current loop. Millis is function that returns that amount of milliseconds the Arduino have been turned on in.
  currentMillis = millis();

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
    } 
    // Delay a little bit to avoid bouncing (nb. I have chaged it from 50 to 5 as in my experience it is plenty and the delay will for every loop mess up the mills timing logic just a bit)
    delay(5);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;


    // turns on the LED every four button pushes by checking the modulo of the
    // button push counter. the modulo function gives you the remainder of the
    // division of two numbers:
    if (buttonPushCounter % 2 == 0) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }


  // in this logic the if statement will only be invoked when the amount of time from the previousMills to the currentMills is greater then the interval. 
  // in this case we have set the value to 1000 milliseconds as that is interval that we should print buttonPushCounter
  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;

    // if the button is pressed when we check every 1 second then the timerCounter is increase by one. *you could in theory press the button on the exact right time every secound and trick the logic, but good luck with that. 
    if (buttonState == HIGH) {
      
      timerCounter++;
      
    } else {

      // if the button is not press that the timerCounter resets
      timerCounter = 0;
      
    }

    // as we only comes into this logic every 1 second we can also do the print here. If you want to print and check at diffrent intervals then you need to make two diffrent timer logics
    Serial.println(buttonPushCounter);

  }

  // if the counter reachs 5 then reset the buttonPushCounter
  if (timerCounter > 5) {
    
    buttonPushCounter = 0;
    
  }
}
