// ROBOT 3
//____________________________________CONSTANTS + LIBRARIES_________________________________________________//


// Bluetooth

  #include<SoftwareSerial.h>
  #define RX 13
  #define TX 12
  
  SoftwareSerial BlueT (RX,TX);
  
  char Data;


// roues

  int RDIN3 = 53 ;
  int RDIN4 = 52 ;
  int RDENB = 2 ;

  int RGIN2 = 50 ;
  int RGIN1 = 51 ; 
  int RGENA = 3 ;

  int vitesse = 100 ;
  int vitesseRotForte = 230 ;
  int vitesseRotFaible = 40 ;

// Articulations

  int ArtBackIN3 = 28 ;
  int ArtBackIN4 = 29 ;
  int ArtBackENB = 30 ;

  int ArtMiddleIN1 = 22 ;
  int ArtMiddleIN2 = 24 ;
  int ArtMiddleENA = 23 ;

  int ArtFrontIN1 = 9 ;
  int ArtFrontIN2 = 8 ;
  int ArtFrontENA = 10 ;


//_______________________________________SETUP______________________________________________//

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("BEGIN");

  // bluetooth
    BlueT.begin(9600);

  // Moteurs initialisés en générateur

    pinMode(RDIN3,OUTPUT) ;
    pinMode(RDIN4,OUTPUT) ;
    pinMode(RDENB,OUTPUT) ;
    
    pinMode(RGIN2,OUTPUT) ;
    pinMode(RGIN1,OUTPUT) ;
    pinMode(RGENA,OUTPUT) ;
    
    pinMode(ArtBackIN3,OUTPUT) ;
    pinMode(ArtBackIN4,OUTPUT) ;
    pinMode(ArtBackENB,OUTPUT) ;

    pinMode(ArtMiddleIN1,OUTPUT) ;
    pinMode(ArtMiddleIN2,OUTPUT) ;
    pinMode(ArtMiddleENA,OUTPUT) ;

    pinMode(ArtFrontIN1,OUTPUT) ;
    pinMode(ArtFrontIN2,OUTPUT) ;
    pinMode(ArtFrontENA,OUTPUT) ;

}

//__________________________________________LOOP_____________________________________________//

void loop() {
  // put your main code here, to run repeatedly:

    if(BlueT.available()){ // si BlueT disponible
      Data = BlueT.read();
    
      Serial.print("Data is : ");
      Serial.println(Data);


      //DIRECTIONS

      if (Data == '1'){
        Serial.println("En avant");

        digitalWrite(RDIN3, HIGH) ;
        digitalWrite(RDIN4 , LOW) ;
      
        digitalWrite( RGIN2 , LOW) ;
        digitalWrite(RGIN1 , HIGH) ;
        
        analogWrite(RGENA , vitesse) ;
        analogWrite(RDENB , vitesse) ;
      }

      

      if (Data == '3'){
        Serial.println("En arrière");

        digitalWrite(RDIN3, LOW) ;
        digitalWrite(RDIN4 , HIGH) ;
      
        digitalWrite( RGIN2 , HIGH) ;
        digitalWrite(RGIN1 , LOW) ;
        
        analogWrite(RGENA , vitesse) ;
        analogWrite(RDENB , vitesse) ;
      }


      

      if (Data == '2'){
        Serial.println("A droite");

        digitalWrite(RDIN3, HIGH) ;
        digitalWrite(RDIN4 , LOW) ;
      
        digitalWrite( RGIN2 , LOW) ;
        digitalWrite(RGIN1 , HIGH) ;
        
        analogWrite(RGENA , vitesseRotForte ) ;
        analogWrite(RDENB , vitesseRotFaible ) ;
      }

 

      if (Data == '4'){
        Serial.println("A gauche");

        digitalWrite(RDIN3, HIGH) ;
        digitalWrite(RDIN4 , LOW) ;
      
        digitalWrite( RGIN2 , LOW) ;
        digitalWrite(RGIN1 , HIGH) ;
        
        analogWrite(RGENA , vitesseRotFaible) ;
        analogWrite(RDENB , vitesseRotForte) ;
      }

      if (Data == '0'){
        Serial.println("Stop");
        digitalWrite(RGENA , LOW) ;
        digitalWrite(RDENB , LOW) ;
      }


      // moteur avant
      
      if (Data == 'A'){
        Serial.println("Train avant monte");

        digitalWrite(ArtFrontIN1, HIGH) ;
        digitalWrite(ArtFrontIN2 , LOW) ;
      
        digitalWrite(ArtFrontENA , HIGH) ;
      }

      if (Data == 'a'){
        Serial.println("Stop");
        digitalWrite(ArtFrontENA , LOW) ;
      }

      if (Data == 'B'){
        Serial.println("Train avant descend");

        digitalWrite(ArtFrontIN1, LOW) ;
        digitalWrite(ArtFrontIN2 , HIGH) ;
      
        digitalWrite(ArtFrontENA , HIGH) ;
      }

      if (Data == 'b'){
        Serial.println("Stop");
        digitalWrite(ArtFrontENA , LOW) ;
      }


      // Moteur centre
      
      if (Data == 'C'){
        Serial.println("Train central monte");

        digitalWrite(ArtMiddleIN1, LOW) ;
        digitalWrite(ArtMiddleIN2 , HIGH) ;
      
        digitalWrite(ArtMiddleENA , HIGH) ;
      }

      if (Data == 'c'){
        Serial.println("Stop");
        digitalWrite(ArtMiddleENA , LOW) ;
      }

      if (Data == 'D'){
        Serial.println("Train central descend");

        digitalWrite(ArtMiddleIN1, HIGH) ;
        digitalWrite(ArtMiddleIN2 , LOW) ;
      
        digitalWrite(ArtMiddleENA , HIGH) ;
      }

      
      if (Data == 'd'){
        Serial.println("Stop");
        digitalWrite(ArtMiddleENA , LOW) ;
      }


      // Moteur arrière
      
      if (Data == 'E'){
        Serial.println("Train arrière monte");

        digitalWrite(ArtBackIN3, HIGH) ;
        digitalWrite(ArtBackIN4 , LOW) ;
      
        digitalWrite(ArtBackENB , HIGH) ;
      }

      if (Data == 'e'){
        Serial.println("Stop");
        digitalWrite(ArtBackENB , LOW) ;
      }

      if (Data == 'F'){
        Serial.println("Train arrière descend");

        digitalWrite(ArtBackIN3, LOW) ;
        digitalWrite(ArtBackIN4 , HIGH) ;
      
        digitalWrite(ArtBackENB , HIGH) ;
      }

      if (Data == 'f'){
        Serial.println("Stop");
        digitalWrite(ArtBackENB , LOW) ;
      }


      //Tous les moteurs
      
      if (Data == 'H'){
        Serial.println("Robot monte");

        digitalWrite(ArtBackIN3, HIGH) ;
        digitalWrite(ArtBackIN4 , LOW) ;

        digitalWrite(ArtMiddleIN1, LOW) ;
        digitalWrite(ArtMiddleIN2 , HIGH) ;

        digitalWrite(ArtFrontIN1, HIGH) ;
        digitalWrite(ArtFrontIN2 , LOW) ;
      
        digitalWrite(ArtBackENB , HIGH) ;
        digitalWrite(ArtMiddleENA, HIGH) ;
        digitalWrite(ArtFrontENA , HIGH) ;
      }

      if (Data == 'h'){
        Serial.println("Stop");
       
        digitalWrite(ArtBackENB , LOW) ;
        digitalWrite(ArtMiddleENA, LOW) ;
        digitalWrite(ArtFrontENA , LOW) ;
      }

      if (Data == 'G'){
        Serial.println("Robot descend");

        digitalWrite(ArtBackIN3, LOW) ;
        digitalWrite(ArtBackIN4 , HIGH) ;

        digitalWrite(ArtMiddleIN1, HIGH) ;
        digitalWrite(ArtMiddleIN2 , LOW) ;

        digitalWrite(ArtFrontIN1, LOW) ;
        digitalWrite(ArtFrontIN2 , HIGH) ;
      
        digitalWrite(ArtBackENB , HIGH) ;
        digitalWrite(ArtMiddleENA, HIGH) ;
        digitalWrite(ArtFrontENA , HIGH) ;
      }

      if (Data == 'g'){
        Serial.println("Stop");
       
        digitalWrite(ArtBackENB , LOW) ;
        digitalWrite(ArtMiddleENA, LOW) ;
        digitalWrite(ArtFrontENA , LOW) ;
      }

    }
}
