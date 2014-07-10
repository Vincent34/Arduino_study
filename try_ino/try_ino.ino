int pin[8];
void setup() {
  for (int i = 0;i <= 8;i++) {
    pin[i] = i;
    pinMode(i,OUTPUT);
  }
}
void loop() {
  for (int i = 0;i < 8;i++) {
    for (int j = 0;j < 8 - i;j++) {
      digitalWrite(pin[j],HIGH);
      delay(200);
      digitalWrite(pin[j],LOW);
      delay(200);
    }
    digitalWrite(pin[8 - i],HIGH);
  }
}
