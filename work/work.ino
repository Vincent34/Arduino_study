//work.ino
#define abs(a) (((a) > 0)?(a):(-a))
//include <Servo.h>
// int ultrasonic_in = 5,ultrasonic_out = 3;
// int angle = 30;
int out[5] = {-1,6,7,8,9};
int Left = 10,Right = 11;
int head, tail;
long pre, t;
int stp[1000][2];
// Servo myServo;
// void ServoMove() {
// 	angle += 30;
// 	if (angle == 180) angle = 30;
// 	myServo.write(angle);
// }
// void UltrasonicSetup() {
// 	pinMode(ultrasonic_out, OUTPUT);
// 	pinMode(ultrasonic_in, INPUT_PULLUP);
// }
// double UltrasonicRead() {
// 	digitalWrite(ultrasonic_out, LOW);
// 	delayMicroseconds(2);
// 	digitalWrite(ultrasonic_out, HIGH);
// 	delayMicroseconds(15);
// 	digitalWrite(ultrasonic_out, LOW);
// 	int t = pulseIn(ultrasonic_in,HIGH);
// 	return (double)t * 0.017;
// }
void LMove(int u) {
	switch (u) {
		case -1:
		digitalWrite(out[1], HIGH);
		digitalWrite(out[2], LOW);
		break;
		case 1:
		digitalWrite(out[1], LOW);
		digitalWrite(out[2], HIGH);
		break;
		default:
		digitalWrite(out[1], LOW);
		digitalWrite(out[2], LOW);
	}
}
void RMove(int u) {
	switch (u) {
		case -1:
		digitalWrite(out[4], HIGH);
		digitalWrite(out[3], LOW);
		break;
		case 1:
		digitalWrite(out[4], LOW);
		digitalWrite(out[3], HIGH);
		break;
		default:
		digitalWrite(out[4], LOW);
		digitalWrite(out[3], LOW);
	}
}
void setup() {
	Serial.begin(9600);
	// UltrasonicSetup();
	// myServo.attach(10);
	//myServo.write(30);
	analogWrite(Left, 255);
	analogWrite(Right, 255);
	// Serial.setTimeout(200);
	for (int i = 1;i <= 4;i++) {
		pinMode(out[i], OUTPUT);
	}
	t = -1;
}
// void getstp() {
// 	num = 0;
// 	k = 0;
// 	Serial.println("getstp");
// 	while (Serial.available()) {
// 		stp[num][0] = Serial.read();
// 		Serial.print(stp[num][0]);
// 		stp[num][1] = Serial.parseInt();
// 		num++;
// 	}
// }
void loop() {
	int v;
	while (Serial.available()) {
		char ch = Serial.read();
		Serial.write(ch);
		switch(ch) {
			// default:
			// 	if (stp[tail][1] == 0 || (t != -1 && millis() - t > stp[tail][1])) {
			// 		tail = (tail + 1) % 1000;
			// 		t = -1;
			// 		break;
			// 	}
			case 'w':
					RMove(1);
					LMove(1);
				break;
			case 's':
					RMove(-1);
					LMove(-1);
				break;
			case 'a':
					LMove(0);
					RMove(1);
				break;
			case 'd':
					LMove(1);
					RMove(0);
				break;
			case 'p':
					LMove(0);
					RMove(0);
				break;
			case 'l':
			case 'L':
				v = Serial.parseInt();
				if (ch == 'L') {
					if (v > 80) LMove(1);
					else if (v < -80) LMove(-1);
					else LMove(0);
				}
				analogWrite(Left, abs(v));;
				break;
			case 'r':
			case 'R':
				v = Serial.parseInt();
				if (ch == 'R') {
					if (v > 80) RMove(1);
					else if (v  < -80) RMove(-1);
					else RMove(0);
				}
				analogWrite(Right, abs(v));
				break;
		}
	}
}
