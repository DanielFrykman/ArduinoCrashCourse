// created by Daniel Lilja Frykman
#include <VarSpeedServo.h> // includes the new libary needed for this 

// create servo objects
VarSpeedServo myservo; // creates a object called myservo
int SPEED = 20; // sets the starting speed to 20
void setup() {
  myservo.attach(9); // sets the servo communication pin to pin 9
  Serial.begin(9600);
}

void loop() {
  Serial.println(SPEED);
  int LEF = 0; // sets the target posision of LEF to 0 degrees
  int RIG = 180; // sets the target posision of RIG to 0 degrees


  myservo.write(LEF, SPEED); // asks to servo to go to LEF posision with speed from the variable SPEED 
  myservo.wait(); // wait for servo 1 to finish

  myservo.write(RIG, SPEED); // asks to servo to go to RIG posision with speed from the variable SPEED

  myservo.write(LEF, SPEED); // asks to servo to go to LEF posision with speed from the variable SPEED
  myservo.wait();

  myservo.write(RIG, SPEED); // asks to servo to go to RIG posision with speed from the variable SPEED
  myservo.wait();

  SPEED = SPEED  + 10; // adds 10 to the speed 
}
