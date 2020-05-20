/*

ARDUINO   L293D(Puente H)        
  5          10
  6          15
  9          7
  10         2
  5V         1, 9, 16
  GND        4, 5, 12, 13
  
  El motor LEFT se conecta a los pines 3 y 6 del Puente H
  El motor RIGHT se conecta a los pines 11 y 14 del Puente H
  
  La fuente de alimentacion de los Motores se conecta a tierra y
  el positivo al pin 8 del puente H.  

*/
//LEFT MOTOR
int leftA = 9; 
int leftB = 10;
//RIGHT MOTOR 
int rightA = 5; 
int rightB = 6; 

int vel = 255; // Velocidad de los motores (0-255)

void setup()  { 
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);
  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  Serial.begin(9600);
  analogWrite(rightA, 0); 
  analogWrite(rightB, 0);
  analogWrite(leftA, 0); 
  analogWrite(leftB, 0);
 } 
 
void loop()  { 
    if (Serial.available()) {
    char  a = Serial.read();
      // STOP  
          if (a =='X'||a =='x'){    
             Serial.println("STOP");
              analogWrite(rightA, 0); 
              analogWrite(rightB, 0);
              analogWrite(leftA, 0); 
              analogWrite(leftB, 0);   
          }    
      //MOTOR left FORWARDS
          if (a =='W'||a =='w'){
            Serial.println("MOTOR left FORWARDS");
              analogWrite(rightA, 0); 
              analogWrite(rightB, 0);
              analogWrite(leftA, vel); 
              analogWrite(leftB, 0);
          }
      //MOTOR left BACKWARDS
          if (a =='A'||a =='a'){
            Serial.println("MOTOR left BACKWARDS");
              analogWrite(rightA, 0); 
              analogWrite(rightB, 0);
              analogWrite(leftA, 0); 
              analogWrite(leftB, vel);
          } 
      //MOTOR right FORWARDS
          if (a =='E'||a =='e'){
            Serial.println("MOTOR right FORWARDS");
              analogWrite(rightA, vel); 
              analogWrite(rightB, 0);
              analogWrite(leftA, 0); 
              analogWrite(leftB, 0); 
          }
            
      //MOTOR right BACKWARDS
          if (a =='S'||a =='s'){
            Serial.println("MOTOR right BACKWARDS");
              analogWrite(rightA, 0); 
              analogWrite(rightB, vel);
              analogWrite(leftA, 0); 
              analogWrite(leftB, 0); 
          }
      
      //MOTOR left & right FORWARDS
          if (a =='T'||a =='t'){
            Serial.println("MOTOR left & right FORWARDS");
              analogWrite(rightA, vel); 
              analogWrite(rightB, 0);
              analogWrite(leftA, vel); 
              analogWrite(leftB, 0); 
          }
      //MOTOR left & right BACKWARDS
          if (a =='F'||a =='f'){
            Serial.println("MOTOR left & right BACKWARDS");
              analogWrite(rightA, 0); 
              analogWrite(rightB, vel);
              analogWrite(leftA, 0); 
              analogWrite(leftB, vel); 
          }
    }
  }
