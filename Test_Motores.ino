/*

ARDUINO   L293D(Puente H)        
  6          10
  7          15
  9          7
  8          2
  5V         1, 9, 16
  GND        4, 5, 12, 13
  
  El motor LEFT se conecta a los pines 3 y 6 del Puente H
  El motor RIGHT se conecta a los pines 11 y 14 del Puente H
  
  La fuente de alimentacion de los Motores se conecta a tierra y
  el positivo al pin 8 del puente H.  

*/
//LEFT MOTOR
int lA = 6; 
int lB = 7;
//RIGHT MOTOR 
int rA = 8; 
int rB = 9; 

int vel = 255; // Velocidad de los motores (0-255)

//
int prevThrottle = 49;
int prevSteering = 49;
int throttle, steering;

void enginesSetup()  { 
  pinMode(rA, OUTPUT);
  pinMode(rB, OUTPUT);
  pinMode(lA, OUTPUT);
  pinMode(lB, OUTPUT);
  Serial.begin(9600);
  analogWrite(rA, 0); 
  analogWrite(rB, 0);
  analogWrite(lA, 0); 
  analogWrite(lB, 0);
 } 
 
void enginesLoop()  {
  // Throttle and steering values go from 0 to 99.
  // When throttle and steering values are at 99/2 = 49, the joystick is at center.
  throttle = phone.getThrottle();
  steering = phone.getSteering();

  // Display throttle and steering data if steering or throttle value is changed
  if (prevThrottle != throttle) {
      Serial.print("Throttle: "); Serial.println(throttle);
  }
  
  // STOP  
  if (prevThrottle == throttle && prevSteering == steering){    
     Serial.println("STOP");
      analogWrite(rA, 0); 
      analogWrite(rB, 0);
      analogWrite(lA, 0); 
      analogWrite(lB, 0);   
  }    
  //MOTOR left FORWARDS :::TURNS RIGHT
  if (prevSteering != steering && prevSteering <= steering){
    Serial.println("MOTOR left FORWARDS");
      analogWrite(rA, 0); 
      analogWrite(rB, 0);
      analogWrite(lA, vel); 
      analogWrite(lB, 0);
  }
  //MOTOR right FORWARDS :::TURNS LEFT
  if (prevSteering != steering && prevSteering >= steering){
    Serial.println("MOTOR right FORWARDS");
      analogWrite(rA, vel); 
      analogWrite(rB, 0);
      analogWrite(lA, 0); 
      analogWrite(lB, 0); 
  }
      
  //MOTOR left & right FORWARDS
  if (prevThrottle != throttle && prevThrottle <= throttle){
    Serial.println("MOTOR left & right FORWARDS");
      analogWrite(rA, vel); 
      analogWrite(rB, 0);
      analogWrite(lA, vel); 
      analogWrite(lB, 0); 
  }
  //MOTOR left & right BACKWARDS
  if (prevThrottle != throttle && prevThrottle >= throttle){
    Serial.println("MOTOR left & right BACKWARDS");
      analogWrite(rA, 0); 
      analogWrite(rB, vel);
      analogWrite(lA, 0); 
      analogWrite(lB, vel); 
  }
}
