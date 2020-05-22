
/*
* Lights Component
*/

int button;
int timer = 100;

void lightsSetup() {

  // Loop to initialize each Light pin as an output:
  for (int thisPin = 4; thisPin < 7; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }

  //Loop to initialize each Light pin OFF
  for (int thisPin = 4; thisPin < 7; thisPin++) {
    digitalWrite(thisPin, LOW);
  }

  Serial.println("Lights Setup complete");
}

void lightsLoop() {
  // ID of the button pressed pressed.
  button = phone.getButton();
  
  // Front Lights
  if (button == 0) {
    digitalWrite(4, !digitalRead(4));
    Serial.println("Luces delanteras!");
    Serial.println(digitalRead(4));
  } 

  // Breaks
  if (button == 1) {
    digitalWrite(5, !digitalRead(5));
    Serial.println("Luces traseras!");
    Serial.println(digitalRead(5));
  }

  // Warning Lights
  if (button == 2) {
    digitalWrite(6, !digitalRead(6));
    Serial.println("Luces Advertencia!");
    Serial.println(digitalRead(6));
  }

  // All systems down!
  if (button == 3) {
    for (int thisPin = 2; thisPin <= 10; thisPin++) {
      digitalWrite(thisPin, LOW);
    }
    Serial.println("Todas apagado!");
  }
}
