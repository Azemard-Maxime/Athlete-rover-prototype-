// PROJET: Servomoteur

#include <Servo.h>;
Servo monServo;
int positionServo = 2;


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
  
  /*
   TEST
    
  for(positionServo = 0 ; positionServo<=180 ; positionServo++){
    monServo.write(positionServo);
    delay(15);
  }
  
  monServo.write(40);
  delay(1050);
  Serial.print("bas");
  
  monServo.write(20);
  delay(850);
  monServo.write(40);
  delay(850);
  monServo.write(60);
  delay(850);
  
  monServo.write(125);
  delay(1050);
  Serial.print("haut");
  
  */

  
  for (positionServo= 2 ; positionServo <= 120 ; positionServo++){
    monServo.write(positionServo);
    delay(40);
    Serial.print(positionServo);
  }

   for (positionServo= 120 ; positionServo >= 2 ; positionServo--){
    monServo.write(positionServo);
    delay(40);
    Serial.print(positionServo);
  }
  
  
  
}

/* RESULTATS
 *  Attention valeur initiale
 *  valeurs = {2;120}
 *  valeur intémerdiaire = 70
 */
