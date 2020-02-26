// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------
#include <NewPing.h>    // NewPing is a library that makes it easyer to use the ultra sonic sensor (https://playground.arduino.cc/Code/NewPing/)
#define TRIGGER_PIN  9  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     10  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 30 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
int son; // Definer en variabel til at gemme sensordata i (arrays kan også bruges)
int outputValue; // sensor-output
const int analogOutPin = 11; // LED-out


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

}

void loop() {
  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  //Serial.print("Ping: ");
  son = (sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  outputValue = map(son, 0, 30, 0, 255);
  Serial.println(outputValue);
  analogWrite(analogOutPin, outputValue);
  //Serial.print(son);
  //Serial.println("cm");

}
