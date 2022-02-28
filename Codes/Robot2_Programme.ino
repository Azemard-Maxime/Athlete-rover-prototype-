// Programme robot n°2
//--------------------------------------------------------------------//

#include<SoftwareSerial.h>
#define RX 13
#define TX 12


// Moteurs

  // roues

    
    int RDENA = 9 ;
    int RDIN1 = 4 ;
    int RDIN2 = 5 ;
    
    
    int RGENB = 10 ;
    int RGIN3 = 6 ;
    int RGIN4 = 7 ;


  // articulations

    
    int ENA = 19 ;
    int IN1 = 18 ;
    int IN2 = 17 ;

    
    int ENB = 14;
    int IN3 = 16;
    int IN4 = 15 ;

// Bluetooth

SoftwareSerial BlueT (RX,TX);

char Data;






//-----------------------------SETUP---------------------------------------//
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("BEGIN");

  // bluetooth
  BlueT.begin(9600);

  // Moteurs

  /* RAPPEL
   * ENA: puissance
   * INx INy: sens
   */
   
  pinMode(RDENA,OUTPUT);
  pinMode(RDIN1,OUTPUT);
  pinMode(RDIN2,OUTPUT);
  
  pinMode(RGENB,OUTPUT);
  pinMode(RGIN3,OUTPUT);
  pinMode(RGIN4,OUTPUT);

  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  

}



//----------------------------LOOP----------------------------------------//
void loop() {
  // put your main code here, to run repeatedly:

  if(BlueT.available()){ // si BlueT disponible
    Data = BlueT.read();

    Serial.print("Data is : ");
    Serial.println(Data);

    if (Data == '1'){
      Serial.println("En avant");

      
      digitalWrite(RDIN1,LOW);
      digitalWrite(RDIN2,HIGH);
      
      digitalWrite(RGIN3,LOW);
      digitalWrite(RGIN4,HIGH);
      
      digitalWrite(RDENA,255);
      digitalWrite(RGENB,255);
    }

    if (Data == '3'){
      Serial.println("En arrière");

      
      digitalWrite(RDIN1,HIGH);
      digitalWrite(RDIN2,LOW);
      
      digitalWrite(RGIN3,HIGH);
      digitalWrite(RGIN4,LOW);
      
      digitalWrite(RDENA,255);
      digitalWrite(RGENB,255);
    }

    if (Data == '0'){
      Serial.println("STOP !");
      digitalWrite(RDENA,0);
      digitalWrite(RGENB,0);
    }

    if (Data == 'A'){
      Serial.println("Avant monte");
      
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      
      digitalWrite(ENA,255);
    }

    if (Data == 'a'){
      Serial.println("STOP");
      
      digitalWrite(ENA,0);
    }

        if (Data == 'C'){
      Serial.println("Avant descend");
      
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      
      digitalWrite(ENA,255);
    }

    if (Data == 'c'){
      Serial.println("STOP");
      
      digitalWrite(ENA,0);
    }

     if (Data == 'B'){
      Serial.println("Arrière monte");
      
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      
      digitalWrite(ENB,255);
     }

    if (Data == 'b'){
      Serial.println("STOP");
      
      digitalWrite(ENB,0);
    }

    if (Data == 'D'){
      Serial.println("Arrière descend");
      
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      
      digitalWrite(ENB,255);
    }

    if (Data == 'd'){
      Serial.println("STOP");
      
      digitalWrite(ENB,0);
    }

    if (Data == '2'){
      digitalWrite(RDIN1,LOW);
      digitalWrite(RDIN2,HIGH);
      
      digitalWrite(RGIN3,LOW);
      digitalWrite(RGIN4,HIGH);
      
      digitalWrite(RDENA,255);
    }

    if (Data == '4'){
      digitalWrite(RDIN1,LOW);
      digitalWrite(RDIN2,HIGH);
      
      digitalWrite(RGIN3,LOW);
      digitalWrite(RGIN4,HIGH);
      
      digitalWrite(RGENB,255);
    }
    
  }
}
