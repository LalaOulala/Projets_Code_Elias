#include <Servo.h>
Servo servo;
const int led = 5;
const int mouv = 2;
const int t = 5;

void setup() {
  pinMode(mouv, INPUT);
  pinMode(led, OUTPUT);
  pinMode(8,OUTPUT);
  servo.attach(11);
  Serial.begin(9600);
}

void loop() {
  bool state_mouv = digitalRead(2);
  bool state_led = digitalRead(5);
  bool a = state_led && state_mouv;

  if (a == false and state_mouv == true){
    for (int position = 0; position <= 180; position++){
      servo.write(position);
      delay(t);
    }
    for (int position = 180; position >= 0; position--){
      servo.write(position);
      delay(t);
    }
    digitalWrite(led, HIGH);
    digitalWrite(8,LOW);
  }


  if (a == false and state_led == true){
    digitalWrite(8,HIGH);
    delay(500);
    digitalWrite(8,LOW);
    delay(500);
    digitalWrite(8,HIGH);
    digitalWrite(led, LOW);
  }
}
