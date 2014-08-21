// bluetooth_try.ino
char ch;
int in1 = 4,in2 = 5,in3 = 6,in4 = 7;
void moveW(int x) {
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in4, LOW);
	digitalWrite(in3, HIGH);
	delay(x);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
}
void moveS(int x)  {
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in4, HIGH);
	digitalWrite(in3, LOW);
	delay(x);
	digitalWrite(in1, LOW);
	digitalWrite(in4, LOW);
}
void moveD(int x) {
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	delay(x);
	digitalWrite(in2, LOW);
}
void moveA(int x) {
	digitalWrite(in4, LOW);
	digitalWrite(in3, HIGH);
	delay(x);
	digitalWrite(in3, LOW);
}
void setup() {
	Serial.begin(9600);
	pinMode(13, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
	digitalWrite(13, LOW);
}

void loop() {
	int t;
	while(Serial.available()) {
		ch = Serial.read();
		Serial.write(ch);
		switch (ch) {
		    case 'W':
		    	digitalWrite(13, HIGH);
		    	t = Serial.parseInt();
				moveW(t);
				Serial.write('Y');
		      	break;
		    case 'A':
		    	digitalWrite(13, HIGH);
		    	t = Serial.parseInt();
		    	moveA(t);
		    	Serial.write('Y');
		      	break;
		    case 'D':
		     	digitalWrite(13, HIGH);
		     	t = Serial.parseInt();
		     	moveD(t);
		     	Serial.write('Y');
		     	break;
		    case 'S':
		    	digitalWrite(13, HIGH);
		    	t = Serial.parseInt();
		    	moveS(t);
		    	Serial.write('Y');
		    	break;
		    default:
			    digitalWrite(13, LOW);
				Serial.write('N');
		}
	}
}
