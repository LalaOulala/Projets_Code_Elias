const int capteurOrange=4;
const int capteurBleu=5;
void setup() {
  pinMode(capteurOrange, INPUT);
  pinMode(capteurBleu, INPUT);
  Serial.begin(9600);
}
void loop() {
  bool stateOrange=digitalRead(capteurOrange);
  bool stateBleu=digitalRead(capteurBleu);
  Serial.print("capteur Orange : ");
  Serial.println(stateOrange);
  Serial.println();
  Serial.print("                    capteur Bleu : ");
  Serial.println(stateBleu);
}
