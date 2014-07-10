// bar.ino
int A_in = A0;

void setup() {
	Serial.begin(9600);
	for (int i = 0;i < 8;i++) pinMode(i + 6, OUTPUT);
}

void loop() {
	int re = analogRead(A_in);
	Serial.println(re);
	re = map(re,0,1023,0,8);
	for (int i = 0;i <= re;i++) {
		digitalWrite(i + 6, LOW);
	}
	for (int i = re + 1;i < 8;i++) {
		digitalWrite(i + 6, HIGH);
	}
	delay(200);
}

