// measure.ino
int trig = 3,echo = 5;
void setup() {
	Serial.begin(9600);
	pinMode(trig,OUTPUT);
	pinMode(echo,INPUT_PULLUP);
}

void loop() {
	// digitalWrite(trig, LOW);
	// delayMicroseconds(2);
	// digitalWrite(trig, HIGH);
	// delayMicroseconds(10);
	// digitalWrite(trig, LOW);
	// double d = (double)pulseIn(echo, HIGH) * 0.017;
	// Serial.println(d);
	// tone(8,(int)d+1000,100);
	tone(8,1010,100);
	delay(130);
	noTone(8);
	tone(8,1000,100);
	delay(130);
	noTone(8);
}

