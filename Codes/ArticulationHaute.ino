// PROJET: Servomoteur

#include <Servo.h>;
Servo monServo;
int positionServo = 0;


void 






void setup() {
  monServo.attach(2);
/*Cette méthode accepte comme paramètres :
- évidemment la broche reliée au servo, dans l’exemple la broche 2
- en 2ème paramètre l’angle minimum en microsecondes, par défaut il est à 544 (microsecondes)
- en 3ème paramètre l’angle maximum en microsecondes, par défaut il est à 2400 (microsecondes)
 */
  monServo.write(positionServo);
  Serial.begin(9600);
}

void loop() {
  for(positionServo = 0 ; positionServo<=180 ; positionServo++){
    monServo.write(positionServo);
    delay(15);
  }

  
  
  
}
