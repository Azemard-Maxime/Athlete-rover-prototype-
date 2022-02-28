//bluetooth robot

//Commandes:
// AT -> OK
// AT+NAMExyz
// AT+PINxxxx

//name: robot_Athlete
//Password: 1234

#include<SoftwareSerial.h>
#define RX 13 
#define TX 12 
SoftwareSerial BlueT(RX,TX);


void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("Bonjour-Prête pour les commandes AT");
  BlueT.begin(9600);
  delay(500);
  
}

void loop() {
  while (BlueT.available()){
    Serial.print(char(BlueT.read()));
  }

  while (Serial.available()){
    BlueT.write(char(Serial.read()));
  }
Serial.println("Data is " + Data);
}
