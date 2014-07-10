// try.ino
const int pin1 = 11,pin2 = 12;
const int Btpin = 2;
int flag = 1,start,finish;
int pin_in = 3;
int now = 0;

void setup() {
	pinMode(pin_in, INPUT_PULLUP);
	Serial.begin(9600);
}

void loop() {
	delay(3);
	int re = digitalRead(pin_in);
	if (flag == 1 && re == 0) start = millis();
	if (flag == 0 && re == 1) {
		finish = millis();
		Serial.println(finish - start);
	}
	flag = re;
}	