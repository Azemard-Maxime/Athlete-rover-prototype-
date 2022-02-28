//    PROGRAMME ROBOT        //

// =============================================================================================================//

//------------------------- LIBRAIRIES ---------------------------------------//

#include <Servo.h>;
#include<SoftwareSerial.h>
#define RX 13
#define TX 12

//-----------------------------------------------------------------------------//
// Moteurs

  // bloc jaune

    // roues
    int JENA = 9 ;
    int JIN1 = 4 ;
    int JIN2 = 5 ;
    
    // articulation
    int JENB = 10 ;
    int JIN3 = 6 ;
    int JIN4 = 7 ;


  // bloc rouge

    // roues
    int RENA = 19 ;
    int RIN1 = 18 ;
    int RIN2 = 17 ;

    // articulation
    int RENB = 14;
    int RIN3 = 16;
    int RIN4 = 15 ;


// Servos 

  Servo monServoJaune;
  Servo monServoRouge;

  int positionServoJaune ;
  int positionServoRouge ;

  boolean jauneMonte = false;
  boolean jauneDescente = false;

  boolean rougeMonte = false ;
  boolean rougeDescente = false;


// Bluetooth

SoftwareSerial BlueT (RX,TX);

char Data;

//============================================================== SETUP =======================================================================//

void setup() {
  Serial.begin(9600);
  Serial.println("BEGIN");

  // bluetooth
  BlueT.begin(9600);

  // Moteurs

  /* RAPPEL
   * ENA: puissance
   * INx INy: sens
   */
   
  pinMode(JENA,OUTPUT);
  pinMode(JIN1,OUTPUT);
  pinMode(JIN2,OUTPUT);
  
  pinMode(JENB,OUTPUT);
  pinMode(JIN3,OUTPUT);
  pinMode(JIN4,OUTPUT);

  pinMode(RENA,OUTPUT);
  pinMode(RIN1,OUTPUT);
  pinMode(RIN2,OUTPUT);
  
  pinMode(RENB,OUTPUT);
  pinMode(RIN3,OUTPUT);
  pinMode(RIN4,OUTPUT);

  // Servos

  monServoRouge.attach(11);  
  monServoJaune.attach(3);

}

//============================================================== LOOP =======================================================================//

void loop() {

  positionServoJaune = monServoJaune.read();
  positionServoRouge = monServoRouge.read();



  
  
  if(BlueT.available()){ // si BlueT disponible
    Data = BlueT.read();
  }
    Serial.print("Data is : ");
    Serial.println(Data);


    if (Data == '1'){
      Serial.println("En avant");

      // Moteur roues Jaunes
      digitalWrite(JIN1,LOW);
      digitalWrite(JIN2,HIGH);
      // Moteur roues rouges
      digitalWrite(RIN1,HIGH);
      digitalWrite(RIN2,LOW);
      
      digitalWrite(JENA,255);
      digitalWrite(RENA,255);
    }
    
    if (Data == '3'){
      Serial.println("En arrière");

      // Moteur roues Jaunes
      digitalWrite(JIN1,HIGH);
      digitalWrite(JIN2,LOW);
      // Moteur roues rouges
      digitalWrite(RIN1,LOW);
      digitalWrite(RIN2,HIGH);
      digitalWrite(JENA,255);
      digitalWrite(RENA,255);
    }

    if (Data == 'A'){
      Serial.println("Jaune avant monte");
      digitalWrite(JIN3,LOW);
      digitalWrite(JIN4,HIGH);
      digitalWrite(JENB,255);
    }

    if (Data == 'a'){
      Serial.println("Jaune avant descend");
      digitalWrite(JIN3,HIGH);
      digitalWrite(JIN4,LOW);
      digitalWrite(JENB,255);
    }


    

  if (Data == 'b') {
    jauneMonte = false ;
  }

  if (Data == 'B' or jauneMonte)   {
    Serial.println("Servo jaune monte");
    jauneMonte = true ;
    if (positionServoJaune >=10){
         positionServoJaune -= 1 ;
         monServoJaune.write(positionServoJaune);
     }
   }
    
  if (Data == 'f') {
    jauneDescente = false ;  
  }
if (Data == 'F' or jauneDescente==true) {
      Serial.println("Servo jaune descend");
      jauneDescente = true ;
      if (positionServoJaune <=100){
         positionServoJaune += 1 ;
         monServoJaune.write(positionServoJaune);
       }
    }



 if (Data == 'c') {
    rougeMonte = false ;
  }

  if (Data == 'C' or rougeMonte)   {
    Serial.println("Servo rouge monte");
    rougeMonte = true ;
    if (positionServoRouge >=10){
         positionServoRouge -= 1 ;
         monServoRouge.write(positionServoRouge);
     }
   }
    
  if (Data == 'g') {
    rougeDescente = false ;  
  }
if (Data == 'G' or rougeDescente==true) {
      Serial.println("Servo rouge descend");
      rougeDescente = true ;
      if (positionServoRouge <=100){
         positionServoRouge += 1 ;
         monServoRouge.write(positionServoRouge);
       }
    }
/*  PARTIE RETIRE 
    if (Data == 'b'){
      Serial.println("Servo jaune monte");
      
      for (positionServoJaune ; positionServoJaune <= 120 ; positionServoJaune++){
        monServoJaune.write(positionServoJaune);
        delay(40);
      }
    }
JUSQUE LA !!!!

*/



    if (Data == 'C'){
      
    }

    if (Data == 'c'){
      
    }

    if (Data == 'D'){
      Serial.println("Rouge avant monte");
      
      digitalWrite(RIN3,LOW);
      digitalWrite(RIN4,HIGH);
      
      digitalWrite(RENB,255);
    }

    if (Data == 'd'){
      Serial.println("Rouge avant descend");
      
      digitalWrite(RIN3,HIGH);
      digitalWrite(RIN4,LOW);
      
      digitalWrite(RENB,255);
    }

    if (Data == 'S'){
      
    }

    if (Data == 's'){
      
    }

    if (Data == '0'){
      Serial.println("STOP !");
      digitalWrite(JENA,0);
      digitalWrite(RENA,0);
    }

    if (Data == 'r'){
      Serial.println("STOP !");
      digitalWrite(JENB,0);
      digitalWrite(RENB,0);
      
      //positionServoJaune = monServoJaune.read();
      //monServoJaune.write(positionServoJaune);
      
    }
    
  
}
