// Moteur des roues
int ENA = 9 ;
int IN1 = 4 ;
int IN2 = 5 ;

// Moteur du bras articulé
int ENB = 10 ;
int IN3 = 6 ;
int IN4 = 7 ;


void setup() {
  Serial.begin(9600);
  
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  //puissance des moteurs
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);

  //Sens des moteurs
  // - Moteur roues
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);

  // - Moteur bras
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void loop() {

  // roues en marche pendant X secondes
  digitalWrite(ENA,255);
  delay(7000);
  digitalWrite(ENA,0);
  Serial.print("roues");

  // montée + arret + descente des roues
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
  digitalWrite(ENB,155);
  delay(5000);
  Serial.println("montée");
  
  digitalWrite(ENB,0);
  delay(5000);
  Serial.println("arret");
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  
  digitalWrite(ENB,155);
  delay(4000);
  Serial.println("descente");
  digitalWrite(ENB,0);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  Serial.println("fin");

}
