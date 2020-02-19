// Author - Daniel L. Frykman
// Task 4
/*
  Serial.println("OUTPUT"); - prints the output plus a new line to the serial monitor (the same as pressing ENTER on your keyboard)

  Serial.print("OUTPUT"); - prints the output without a new line

  Serial.begin(BAUD RATE); - initializes the communication between Arduino and computer. The standard baud rate is 9600

  delay(MILLISECONDS); - pauses the sketch for a number of milliseconds
*/
int number = 0; // defines a varibel called number as a Integers with the value 0 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // tells the Arduino which data rate to use for serial data transmission. 9600 bits per second is fine for this use.
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(number); // print the value of the varibel number
  if (0 == number % 2){ // the modulo operator is used for the if statement's condition - see https://www.arduino.cc/en/pmwiki.php?n=Reference/Modulo
    Serial.println(" is even");
  } else {
    Serial.println(" is odd");
  }
  number++; //adds 1 to the current value of number before the loops starts over 
}
