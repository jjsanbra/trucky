
/*
* Engines Component
*/

/*
ARDUINO   L293D(Puente H)        
  11         2
  10         7
  6          10
  9          15
  5V         1, 9, 16
  GND        4, 5, 12, 13
  
  El motor LEFT se conecta a los pines 3 y 6 del Puente H
  El motor RIGHT se conecta a los pines 11 y 14 del Puente H
  
  La fuente de alimentacion de los Motores se conecta a tierra y
  el positivo al pin 8 del puente H.  

*/

//RIGHT Engine 
int rA = 11; 
int rB = 10; 
//LEFT Engine
int lA = 9; 
int lB = 6;

//
int prevThrottle = 49;
int prevSteering = 49;
int throttle, steering, Speed;

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
  
  Serial.println("Engines Setup complete");
 } 
 
void enginesLoop()  {
  /**
   * Speed 
   * We use map() funtion to calculate the Speed
   * according to throttle value recibed
   * example: x = map( value_getted , fromMin , fromMax , toMin , toMax );
   */
  Speed = 255;
  //Speed = map( throttle , 50 , 100 , 0 , 255 );
  
  // Throttle and steering values go from 0 to 99.
  // When throttle and steering values are at 99/2 = 49, the joystick is at center.
  throttle = phone.getThrottle();
  steering = phone.getSteering();
  // Display throttle and steering data if steering or throttle value is changed
//  if (prevThrottle != throttle) {
//    Serial.print("Throttle: "); Serial.println(throttle) ; Serial.println(Speed);Serial.println(-Speed);
//  }
  
  //STOP  
  if (prevThrottle == throttle){
    analogWrite(rA, 0); 
    analogWrite(rB, 0);
    analogWrite(lA, 0); 
    analogWrite(lB, 0);   
  }    
//  //MOTOR left FORWARDS :::TURNS RIGHT
//  if (prevSteering != steering && prevSteering <= steering){
//      Serial.println("MOTOR left FORWARDS");
//      analogWrite(rA, 0); 
//      analogWrite(rB, 0);
//      analogWrite(lA, Speed); 
//      analogWrite(lB, 0);
//  }
//  //MOTOR right FORWARDS :::TURNS LEFT
//  if (prevSteering != steering && prevSteering >= steering){
//      Serial.println("MOTOR right FORWARDS");
//      analogWrite(rA, Speed); 
//      analogWrite(rB, 0);
//      analogWrite(lA, 0); 
//      analogWrite(lB, 0); 
//  }
      
  //MOTOR left & right FORWARDS
  if (prevThrottle != throttle && prevThrottle <= throttle){
      Serial.println("MOTOR left & right FORWARDS"); Serial.println(Speed);
      analogWrite(rA, Speed); 
      analogWrite(rB, 0);
      analogWrite(lA, Speed); 
      analogWrite(lB, 0); 
  }
  //MOTOR left & right BACKWARDS
  if (prevThrottle != throttle && prevThrottle >= throttle){
      Serial.println("MOTOR left & right BACKWARDS"); Serial.println(Speed);
      analogWrite(rA, 0); 
      analogWrite(rB, Speed);
      analogWrite(lA, 0); 
      analogWrite(lB, Speed); 
  }
}
