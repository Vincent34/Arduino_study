// DV.ino
int re;
int a[8],k = 0;
void setup() {
	Serial.begin(9600);
	for (int i = 6;i <= 13;i++) pinMode(i,OUTPUT);
}

void loop() {
	re = Serial.parseInt();
	Serial.println(re);
	k = re;
	for (int i = 7;i >= 0;i--) {
		a[i] = k & 1;
		k >>= 1;
	}
	for (int i = 0;i < 8;i++) digitalWrite(i + 6, !a[i]);

}