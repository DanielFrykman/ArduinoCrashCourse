/*
  Author - Oscar V. Bubandt 
  
  This sketch make the LCD-display print 3 different messages in a loop.


  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.print("This is");   // Print a message to the LCD
  delay(1000); // time before playing next message
  lcd.clear();   // clear screen for the next message

  lcd.print("how it's");
  delay(1000);
  lcd.clear();

  lcd.print("done!");
  delay(1000); 
  lcd.clear();
}
