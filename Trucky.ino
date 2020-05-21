
/*
* Trucky Project
*/

#include <SoftwareSerial.h>
#include <ArduinoBlue.h>


// The bluetooth tx and rx pins must be supported by software serial.
// Visit https://www.arduino.cc/en/Reference/SoftwareSerial for unsupported pins.
// Bluetooth TX -> Arduino D11
const int BLUETOOTH_TX = 11;
// Bluetooth RX -> Arduino D12
const int BLUETOOTH_RX = 12;

SoftwareSerial bluetooth(BLUETOOTH_TX, BLUETOOTH_RX);
ArduinoBlue phone(bluetooth); // pass reference of bluetooth object to ArduinoBlue constructor.


void setup() {
  // Start serial monitor at 9600 bps.
  Serial.begin(9600);

  // Start bluetooth serial at 9600 bps.
  bluetooth.begin(9600);

  lightsSetup();
  enginesSetup();

  // delay just in case bluetooth module needs time to "get ready".
  delay(100);

  Serial.println("Trucky Setup complete");
}

void loop() {
  lightsLoop();
  enginesLoop();
}
