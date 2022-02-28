// TEST Led et lélécommande

#include<SoftwareSerial.h>
#define RX 13
#define TX 12
#define LED 2
SoftwareSerial BlueT (RX,TX);

char Data;
boolean etat = false;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  BlueT.begin(9600);
  pinMode(LED,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


  if(BlueT.available()){
    Data = BlueT.read();
    Serial.println(Data);
   
    
    if (Data == 'C'){
      etat = true;
      Serial.println("UN");
    }
    
    if (Data == 'c') {
      etat = false; 
      Serial.println("DEUX");
    } 

    if (etat==true){
      digitalWrite(LED,LOW);
      Serial.println("allumée");
    }
  
    else {
      digitalWrite(LED,HIGH);
      Serial.println("éteint");
    }
  }
}
