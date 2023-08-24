#include <Servo.h>
Servo D10;
Servo D11;
void setup() {
  D10.attach(10);
  D11.attach(11);
}
void loop() {
  D10.write(179);
  D11.write(179);
  delay(500);
  D10.write(0);
  delay(200);
  D11.write(0);
  delay(500);
}
