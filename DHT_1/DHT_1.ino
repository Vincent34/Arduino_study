
#include "DHT.h"

// DHT_1.ino
DHT dht(3,DHT11);
void setup() {
	Serial.begin(9600);
	Serial.println("DHTxx test!");
	dht.begin();

}

void loop() {
	delay(2000);
	Serial.println(dht.readHumidity());
	Serial.println(dht.readTemperature());
}

