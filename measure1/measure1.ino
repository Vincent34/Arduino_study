// measure.ino
int pin_in = 3;
int flag,start = -1,finish;
void setup() {
	Serial.begin(9600);
	pinMode(pin_in, INPUT_PULLUP);
}

void loop() {
	int re = digitalRead(pin_in);
	Serial.println(1000000 / (pulseIn(pin_in,LOW) + pulseIn(pin_in,HIGH)));
	delay(1000);
	flag = re;
}