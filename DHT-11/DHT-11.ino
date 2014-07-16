// DHT-11.ino
int pin = 3;
long start,finish,now;
double heat,humi;
int data[5];
bool wrong = 1,right;
bool pre() {
	pinMode(pin, OUTPUT);
	digitalWrite(pin, HIGH);
	delay(100);
	digitalWrite(pin, LOW);
	delay(30);	//主机低电频
	digitalWrite(pin, HIGH);
	pinMode(pin, INPUT_PULLUP);
	start = micros();
	while((now = micros()) - start < 80) {	//等待拉低相应
		int re = digitalRead(pin);
		if (re == LOW) {
			start = now;
			wrong = 0;
			break;
		}
	}
	if (wrong) {	//拉低超时
		Serial.println("ERROR1");
		return 0;
	}
	wrong = 1;
	while ((now = micros()) - start < 100) { //等待拉高相应
		int re = digitalRead(pin);
		if (re == HIGH) {
			start = now;
			wrong = 0;
			break;
		}
	}
	if (wrong) {	//拉高超时
		Serial.println("ERROR2");
		return 0;
	}
	wrong = 1;
	while ((now = micros()) - start < 100) { //等待拉低相应
		int re = digitalRead(pin);
		if (re == LOW) {
			wrong = 0;
			start = now;
			break;
		}
	}
	if (wrong) { 	//拉低超时
		Serial.println("ERROR3");
		return 0;
	}
	return 1; //握手成功
}
int getNum() {
	start = micros();
	wrong = 1;
	while((now = micros()) - start < 50) { //低电平等待拉高响应
		int re = digitalRead(pin);
		if (re == HIGH) {
			start = now;
			wrong = 0;
			break;
		}
	}
	if (wrong) { //拉高超时
		Serial.println("ERROR4");
		return -1;
	}
	wrong = 1;
	while((now = micros()) - start < 200) { //高电频等待拉低响应
		int re = digitalRead(pin);
		if (re == LOW) {
			finish = now;
			wrong = 0;
			break;
		}
	}
	if (wrong) { //拉低超时
		Serial.println("ERROR5");
		return -1;
	}
	if (finish - start < 68) return 0; //判时间返回结果0、1
	else return 1;
}

bool getData() {
	for (int k = 0;k < 5;k++) {
		int tmp = 0;
		for (int i = 0;i < 8;i++) {
			int num = getNum();
			if (num != -1) 
				tmp = (tmp << 1) + num;
		}
		data[k] = tmp;
	}
	if (data[0] + data[1] + data[2] + data[3] == data[4]) return 1;
	else return 0;
}
void setup() {
	delay(500);
	Serial.begin(9600);
}

void loop() {
	if (pre()) {
		if (getData()) {
			humi = data[0];
			heat = data[2];
			Serial.println("--------------------------------");
			Serial.print("heat: ");
			Serial.println(heat);
			Serial.print("humi: ");
			Serial.println(humi);
		}
	}
	delay(1000);
}