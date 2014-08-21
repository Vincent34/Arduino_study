// ultrasonic.ino
int out = 3;
int in = 5;

void setup() {
	pinMode(in,INPUT_PULLUP);
	pinMode(out,OUTPUT);
	Serial.begin(9600);
}

void loop() {
	digitalWrite(out, LOW);
	delayMicroseconds(2);
	digitalWrite(out, HIGH);
	delayMicroseconds(10);
	digitalWrite(out, LOW);
	int t = pulseIn(in, HIGH);
	Serial.println(t);
	Serial.print((double)t * 340.0 / 10000.0 / 2);
	Serial.println("cm");
	delay(1000);
}

