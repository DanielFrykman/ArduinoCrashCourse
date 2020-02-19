// Author - Daniel L. Frykman
// Task 3
/*
  Serial.println("OUTPUT"); - prints the output plus a new line to the serial monitor (the same as pressing ENTER on your keyboard)

  Serial.print("OUTPUT"); - prints the output without a new line

  Serial.begin(BAUD RATE); - initializes the communication between Arduino and computer. The standard baud rate is 9600

  delay(MILLISECONDS); - pauses the sketch for a number of milliseconds
*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int number = 0; number <= 20; number++) { // it is "just" a for loop - see https://www.arduino.cc/reference/en/language/structure/control-structure/for/
    Serial.println(number);
  }
}
