#include <Servo.h>
Servo servo;
const int red = 5;
const int yellow = 8;
const int mouv = 2;
const int t = 5;
long chrono1 = millis();
long attente = 60000;

void setup() {
  pinMode(mouv, INPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow,OUTPUT);
  servo.attach(11);
  Serial.begin(9600);
  servo.write(118);
}

void loop() {
  bool state_mouv = digitalRead(2);
  bool state_led = digitalRead(5);
  bool a = state_led && state_mouv;
  
  if (a == false and state_mouv == true){ // si la lumière est éteinte et que la NOX BOX capte un mouvement
    // déclenchement du mouvement du servo d'allumage
    for (int position = 118; position <= 178; position++){
      servo.write(position);
      delay(t);
    }
    for (int position = 178; position >= 118; position--){
      servo.write(position);
      delay(t);
    }
    // la led rouge symbolise la lumière allumée
    digitalWrite(red, HIGH);
    digitalWrite(yellow,LOW);
    delay(3000);
  }


  long chrono2 = millis();
  if (chrono2 > chrono1 + attente){
    chrono1 = millis();

    
    if (a == false and state_led == true){ // si la lumière est allumée et que la NOX BOX ne capte aucun mouvement
      
      // déclenchement du mouvement du servo d'éteignage (symbolisé par le clignotement de la led jaune)
      digitalWrite(yellow,HIGH);
      delay(500);
      digitalWrite(yellow,LOW);
      delay(500);
      digitalWrite(yellow,HIGH);
      delay(500);
      digitalWrite(yellow,LOW);
      // la led rouge symbolise la lumière éteinte 
      digitalWrite(red, LOW);
    }
  }
  Serial.println(chrono1);
  Serial.println(chrono2);
  Serial.print("chrono : ");
  Serial.println(chrono2 - chrono1);
  Serial.print("                             mouvement : ");
  Serial.println(state_mouv);
}
