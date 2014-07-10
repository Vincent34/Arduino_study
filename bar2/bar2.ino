// bar2.ino
int A_in = A0;
int k = 0,count = 0;
void setup() {
	Serial.begin(9600);
	for (int i = 0;i < 8;i++) pinMode(i + 6, OUTPUT);
}

void loop() {
	delay(1);
	int re = analogRead(A_in);
	re = map(re,0,1023,0,1000) + 1;
	Serial.println(count);
	count++;
	if (count % re == 0) {
		Serial.println("RIGHT");
		digitalWrite(k + 6, HIGH);
		k++;
		k %= 8;
		digitalWrite(k + 6, LOW);
	}
	if (count > 2000000000) count = 1;
}