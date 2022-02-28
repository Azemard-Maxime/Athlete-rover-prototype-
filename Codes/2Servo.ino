// 2 Servo

#include <Servo.h>;

Servo monServoRouge;
Servo monServoJaune;



void setup() {
  Serial.begin(9600);
  
   monServoRouge.attach(2);
   monServoJaune.attach(14);

   /*
   int positionServo =  monServoRouge.read();
   monServoJaune.write(120 - positionServo); // on met ServoRouge au même niveau que ServoJaune

   
  // MONTER
  
  for (positionServo ; positionServo<=120 ; positionServo++){
    monServoRouge.write(120 - positionServo);
    monServoJaune.write(positionServo);
    delay(40);
  }
   
    
    
  // DESCENDRE
  
  for (positionServo ; positionServo >=0 ; positionServo--){
    monServoRouge.write(120 - positionServo);
    monServoJaune.write(positionServo);
    delay(40);
  }
  */

   int positionServo =  monServoRouge.read();
   monServoJaune.write(positionServo); // on met ServoRouge au même niveau que ServoJaune
}


void loop() {

    int positionServo =  monServoRouge.read();


  
  // MONTER
  
  for (positionServo ; positionServo<=120 ; positionServo++){
    monServoRouge.write(positionServo);
    monServoJaune.write(positionServo);
    delay(40);
  }
   
    
    
  // DESCENDRE
  
  for (positionServo ; positionServo >=0 ; positionServo--){
    monServoRouge.write(positionServo);
    monServoJaune.write(positionServo);
    delay(40);
  }
  
}
