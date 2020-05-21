
/*
* Lights Component
*/

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
    digitalWrite(4, !digitalRead(4));
    Serial.println("Luces Advertencia!");
    Serial.println(digitalRead(4));
  }

  // All systems down!
  if (button == 3) {
    for (int thisPin = 2; thisPin <= 10; thisPin++) {
      digitalWrite(thisPin, LOW);
    }
    Serial.println("Todas apagado!");
  }
}
