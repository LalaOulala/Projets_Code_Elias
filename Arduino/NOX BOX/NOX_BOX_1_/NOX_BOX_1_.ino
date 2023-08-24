#include <Servo.h>
const int t = 5;
Servo servo;
bool lumiere = false; 

void setup() {
  servo.attach(11);
  pinMode(2,INPUT);
  pinMode(5,OUTPUT);
  servo.write(0);
  Serial.begin(9600);
}

void loop() {
  bool interrupteur = false;
  interrupteur = digitalRead(2);
  bool a = interrupteur && lumiere;
  

  if (a == false and interrupteur == true){
    Serial.print("----- valeur de lumiere ----- = ");
    Serial.println(lumiere);
    // Fait bouger le bras de 0° à 180°
    for (int position = 0; position <= 180; position++){
      servo.write(position);
      delay(t);
    }
    for (int position = 180; position >= 0; position--){
      servo.write(position);
      delay(t);
    }
    lumiere = true;
    digitalWrite(5,HIGH);
    delay(100);
  }
 

  if (a == true){
        Serial.print("----- valeur de lumiere ----- = ");
        Serial.println(lumiere);
        // Fait bouger le bras de 0° à 180°
        for (int position = 0; position <= 180; position++){
          servo.write(position);
          delay(t);
        }
      for (int position = 180; position >= 0; position--){
        servo.write(position);
        delay(t);
      }
      lumiere = false;
      digitalWrite(5,LOW);
      delay(100);
  }

  if (interrupteur == false){
    delay(100);
  }

  Serial.println(interrupteur);
}
