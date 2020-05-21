
/*
* Trucky Project
*/

#include <SoftwareSerial.h>
#include <ArduinoBlue.h>

int button;
int timer = 100;

void lightsSetup() {

  // Loop to initialize each Light pin as an output:
  for (int thisPin = 2; thisPin < 5; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }

  //Loop to initialize each Light pin OFF
  for (int thisPin = 2; thisPin < 5; thisPin++) {
    digitalWrite(thisPin, LOW);
  }

  Serial.println("Lights Setup complete");

}

void lightsLoop() {
  // ID of the button pressed pressed.
  button = phone.getButton();
  
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
    for (int thisPin = 4; thisPin < 5; thisPin++) {
      digitalWrite(thisPin, HIGH);
      delay(timer);
      digitalWrite(thisPin, LOW);
    }
    for (int thisPin = 5; thisPin > 4; thisPin--) {
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
