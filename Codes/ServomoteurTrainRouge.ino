// PROJET: Servomoteur

#include <Servo.h>;
Servo monServo;
int positionServo = 70;


void setup() {
  monServo.attach(2);
  //monServo.write(positionServo);
  Serial.begin(9600);

  monServo.write(0);
  delay(100);
  
}

void loop() {
  
  positionServo = monServo.read();
  
  for (positionServo ; positionServo <= 123 ; positionServo++){
    monServo.write(positionServo);
    delay(40);
    Serial.println(positionServo);
  }

   for (positionServo ; positionServo >= 0 ; positionServo--){
    monServo.write(positionServo);
    delay(40);
    Serial.println(positionServo);
  }
  

}

/* RESULTATS
 *  Attention valeur initiale
 *  valeurs = {0;120}
 *  valeur intémerdiaire = 70
 */
