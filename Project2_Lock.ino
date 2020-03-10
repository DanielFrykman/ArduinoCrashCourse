/*----------- Electronic Lock Example ------------
   This code is an example on how to use a solenoid-driven electronic lock.
   See DTU learn for schematic.

   The lock will unlock when any characters are sent from the serial monitor.
   The serial monitor will also show the current state of the lock, where 1=unlocked and 0=locked

   Edited 9/03/20 - Mathias Hovmark
*/

int relayPin = D6;                      //This pin is connected to the S-pin of the relay
int btnPin = D5;                        //This pin is connected to one side of the button connector on the electronic lock
bool lockState;                         //Holds the current state of the lock. 1=unlocked, 0=locked
bool oldLockState = 0;                  //Used to compare the new lock state to the old one

void setup() {
  pinMode(relayPin, OUTPUT);            //Relay pin
  pinMode(btnPin, INPUT_PULLUP);        //Button pin: Note - you don't need to use an external resistor; we will use the internal pullup resistors on nodemcu. So, CONNECT one of the button pins to the GND, the other pin to btnPin
  Serial.begin(115200);                 //Remember to change the baudrate on serial monitor..
}

//This function activates the solenoid
void unlock() {
  digitalWrite(relayPin, HIGH);
  delay(250);                           //Give the solenoid time to retract - try to lower the number to save power
  digitalWrite(relayPin, LOW);
}

void loop() {
  lockState = digitalRead(btnPin);      //Get the state of the lock

  //Check if there's been a change in the lock-state:
  if (lockState != oldLockState) {      //If state changed...
    Serial.print("lock state: ");
    Serial.println(lockState);
    oldLockState = lockState;           //Save current state in comparison-variable
  }


  //Check if anything has been sent to the serial buffer - after the sketch is uploaded, open the serial monitor and write some characters to the box next to 'Send' at the top and click send (or enter)
  if (Serial.available()) {             //If any characters avaiable in serial buffer...
    unlock();                           //Unlock the lock
    Serial.println("Unlock attempted");
    while (Serial.available()) {        //Empty serial buffer to avoid unlocking several times
      char c = Serial.read();
    }
  }

}
