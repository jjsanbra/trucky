
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

int button;
int timer = 100;

SoftwareSerial bluetooth(BLUETOOTH_TX, BLUETOOTH_RX);
ArduinoBlue phone(bluetooth); // pass reference of bluetooth object to ArduinoBlue constructor.


void setup() {
  // Start serial monitor at 9600 bps.
  Serial.begin(9600);

  // Start bluetooth serial at 9600 bps.
  bluetooth.begin(9600);

  // Loop to initialize each Light pin as an output:
  for (int thisPin = 2; thisPin < 5; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }

  //Loop to initialize each Light pin OFF
  for (int thisPin = 2; thisPin < 5; thisPin++) {
    digitalWrite(thisPin, LOW);
  }

  enginesSetup();
  Serial.println("Setup complete");

  // delay just in case bluetooth module needs time to "get ready".
  delay(100);

}

void loop() {
  // ID of the button pressed pressed.
  button = phone.getButton();
  enginesLoop();

  // Front Lights
  if (button == 0) {
    digitalWrite(2, !digitalRead(2));
    Serial.println("Luces delanteras!");
    Serial.println(digitalRead(2));
  } 

  // Breaks
  if (button == 1) {
    digitalWrite(3, !digitalRead(3));
    Serial.println("Luces traseras!");
    Serial.println(digitalRead(3));
  }

  // Warning Lights
  if (button == 2) {
    for (int thisPin = 4; thisPin <= 5; thisPin++) {
      digitalWrite(thisPin, HIGH);
      delay(timer);
      digitalWrite(thisPin, LOW);
    }
    for (int thisPin = 5; thisPin >= 4; thisPin--) {
      digitalWrite(thisPin, HIGH);
      delay(timer);
      digitalWrite(thisPin, LOW);
    }

    delay(500);
    Serial.println("Luces Advertencia!");
  }

  if (button == 3) {
    for (int thisPin = 2; thisPin <= 10; thisPin++) {
      digitalWrite(thisPin, LOW);
    }
    Serial.println("Todas las Luces apagadas!");
  }
}
