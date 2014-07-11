// beep.ino
int pin_in = 3,in = 3,out = 5;
int beep = 13;

void setup() {
	Serial.begin(9600);
	pinMode(pin_in, INPUT_PULLUP);
	pinMode(out,OUTPUT);
}

void loop() {
	digitalWrite(beep, HIGH);
	digitalWrite(out, LOW);
	delayMicroseconds(2);
	digitalWrite(out, HIGH);
	delayMicroseconds(10);
	digitalWrite(out, LOW);
	int t = pulseIn(in, HIGH);
	double distance = ((double)t * 0.034 / 2.0);
	Serial.println(distance);
	if (distance < 50) { 
		digitalWrite(beep, LOW);
		delay(100);
		digitalWrite(beep, HIGH);
	}
}

