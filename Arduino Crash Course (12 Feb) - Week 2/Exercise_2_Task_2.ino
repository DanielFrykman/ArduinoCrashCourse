// Author - Daniel L. Frykman
// Task 2
/*
  Serial.println("OUTPUT"); - prints the output plus a new line to the serial monitor (the same as pressing ENTER on your keyboard)

  Serial.print("OUTPUT"); - prints the output without a new line

  Serial.begin(BAUD RATE); - initializes the communication between Arduino and computer. The standard baud rate is 9600

  delay(MILLISECONDS); - pauses the sketch for a number of milliseconds
*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // tells the Arduino which data rate to use for serial data transmission. 9600 bits per second is fine for this use.
}

void loop() {
  // put your main code here, to run repeatedly:
  int number = 3; // defines a varibel called number as a Integers with the value 3 

  if (number == 3) { // the condition for the if statemant
    Serial.println("Number is 3!"); // if the condition is true, then print "Number is 3!"
  } else { // if the condition is False use the else statemant
    Serial.println("Number is NOT 3!");
  }

}
