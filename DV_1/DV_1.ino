#include "SoftwareSerial.h"
// DV_1.ino
SoftwareSerial mySerial(2,3);
void setup() {
	mySerial.begin(9600);
}

void loop() {
	int re = analogRead(A0);
	mySerial.print(map(re,0,1023,0,255));
	delay(2000  );
}

