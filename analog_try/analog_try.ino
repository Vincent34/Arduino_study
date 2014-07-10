// analog_try.ino
int pin_in = 3;
int now = 0,n,time = 20,up = 20;
int k = 0;
int gcd(int x,int y) {
	if (int c = x % y) return gcd(y,c);
	return y;
}
void setup() {
	Serial.begin(9600);
	randomSeed(analogRead(A0));
	pinMode(pin_in, INPUT_PULLUP);
	for (int i = 0;i < 8;i++) pinMode(i + 6, OUTPUT);
	for (int i = 0;i < 8;i++) digitalWrite(i + 6, HIGH);
}

void loop() {
	delay(10);
	int re = digitalRead(pin_in);
	delay(5);
	digitalRead(pin_in);
	Serial.print('$');
	Serial.println(re);
	Serial.println(now);
	switch(now) {
		case 0:
			if (re == LOW) {
				now = 1;Serial.println("RIGHT");
			}
			else break;
		case 1:
			Serial.println("RIGHT_CASE2");
			if (re == HIGH) now = 2;
			else {
				digitalWrite(k + 6, LOW);
				delay(time);
				digitalWrite(k + 6, HIGH);
				k++;
				k %= 8;
				break;
			}
		case 2:
			if (re == LOW) {
				now = 0;
				time = 10;
				up = 20;
				delay(1000);
				for (int i = 0;i < 8;i++) digitalWrite(i, HIGH);
			}
			else {
				if (time >= 1000) {
					digitalWrite(k + 6, LOW);
					break;
				} else {
					time += up;
					up += random(0,20);
					digitalWrite(k + 6, LOW);
					delay(time);
					digitalWrite(k + 6, HIGH);
					k++;
					k = k % 8;
				}
			}
		default:
			break;
	}
}