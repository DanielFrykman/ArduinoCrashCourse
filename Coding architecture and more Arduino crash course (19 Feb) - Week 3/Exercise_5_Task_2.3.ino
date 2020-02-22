
#include <SPI.h>
#include <SD.h>
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output

File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // Test om SD-kort kan forbindes
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  // Create a now file
  myFile = SD.open("File.csv", FILE_WRITE);
  if (myFile) {
    Serial.println("File.csv:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening File.csv");
  }

}

void loop() {
  myFile = SD.open("Test.csv"); //Åbner SD kortet og skriver nedenstående på filen (hvis filen findes)
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  delay(20);
  if (myFile) {
    Serial.println(sensorValue);
    myFile.println(sensorValue);
    myFile.close();
  }    else {
    Serial.println("Filen er der ikke");// Hvis filen ikke åbner, printes "Filen er der ikke"
  }
  delay(5000);
}
