//work.ino
#include <Servo.h>
int ultrasonic_in = 5,ultrasonic_out = 3;
Servo myServo;
int angle = 30;
void ServoMove() {
  angle += 30;
  if (angle == 180) angle = 30;
  myServo.write(angle);
}
void setup() {
	Serial.begin(9600);
	UltrasonicSetup();
        myServo.attach(9);
        myServo.write(30);
}
void loop() {
        ServoMove();
	Serial.println(UltrasonicRead());
	delay(1000);
}
void UltrasonicSetup() {
	pinMode(ultrasonic_out, OUTPUT);
	pinMode(ultrasonic_in, INPUT_PULLUP);
}
double UltrasonicRead() {
	digitalWrite(ultrasonic_out, LOW);
	delayMicroseconds(2);
	digitalWrite(ultrasonic_out, HIGH);
	delayMicroseconds(15);
	digitalWrite(ultrasonic_out, LOW);
	int t = pulseIn(ultrasonic_in,HIGH);
	return (double)t * 0.017;
}


