#include <Servo.h>
Servo servo1;
Servo servo2;
const int red = 13;
const int mouv1 = 4;
const int mouv2 = 5;
const int t = 5;
long chrono1 = millis();
long attente = 7000; // attente avant d'éteindre en milliseconde
// ceci est un delai d'attente de test, le projet finale n'a pas le même delai.

void setup() {
  pinMode(mouv1, INPUT);
  pinMode(mouv2, INPUT);
  pinMode(red, OUTPUT);
  servo2.attach(11);
  servo1.attach(10);
  Serial.begin(9600);
  servo1.write(118);
  servo2.write(118);
}

void loop() {
  bool state_mouv = (digitalRead(mouv1)) || (digitalRead(mouv2)); // booléen détection mouv 
  bool state_led = digitalRead(red);
  bool a = state_led && state_mouv;
 
  if (a == false and state_mouv == true){ // si la lumière est éteinte et que la NOX BOX capte un mouvement
    // déclenchement du mouvement du servo d'allumage
    for (int position = 118; position <= 178; position++){
      servo1.write(position);
      delay(t);
    }
    for (int position = 178; position >= 118; position--){
      servo1.write(position);
      delay(t);
    }
    // la led rouge symbolise la lumière allumée
    digitalWrite(red, HIGH);
    delay(3000);
  }


  long chrono2 = millis();
  if (chrono2 > chrono1 + attente){
    chrono1 = millis();

   
    if (a == false and state_led == true){ // si la lumière est allumée et que la NOX BOX ne capte aucun mouvement
      // déclenchement du mouvement du servo d'éteignage
      for (int position = 118; position <= 178; position++){
        servo2.write(position);
        delay(t);
      }
      for (int position = 178; position >= 118; position--){
        servo2.write(position);
        delay(t);
      }
      // la led rouge symbolise la lumière éteinte
      digitalWrite(red, LOW);
    }
  }
}
