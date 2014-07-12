// VoltMeter.ino
int index[5] = {0,13,10,9,7}; //4个位置对应的引脚
int flag[10] = {0,12,8,5,3,2,11,6,4}; //7个段对应的引脚
int num[10][10] = {
	{6,1,2,3,4,5,6},
	{2,2,3},
	{5,1,2,7,5,4},
	{5,1,2,3,4,7},
	{4,2,3,6,7},
	{5,1,6,7,3,4},
	{6,1,6,7,3,4,5},
	{3,1,2,3},
	{7,1,2,3,4,5,6,7},
	{6,1,2,3,4,6,7}
};//0~9各个数字的段位组成
void light(int u) {
	int f[5] = {0,0,0,0,0},k = 5;
	while(u) {
		f[--k] = u % 10;
		u /= 10;
	}//得到各位数字
	for (int i = 1;i <= 4;i++) {
		digitalWrite(index[i], HIGH);//对应位引脚输出高电压
		for (int j = 1;j <= 7;j++) {
			if (num[f[i]][j]) digitalWrite(flag[num[f[i]][j]], LOW);
			delayMicroseconds(50);
			digitalWrite(flag[num[f[i]][j]], HIGH);
		}//数字相应段依次输出低电压
		if (i == 1) digitalWrite(flag[8], LOW);//点亮第一个小数点
		delayMicroseconds(50);
		digitalWrite(flag[8], HIGH);
		digitalWrite(index[i], LOW);//对应位引脚恢复低电压
	}
}
void setup() {
	Serial.begin(9600);
	for (int i = 2;i <= 13;i++) pinMode(i, OUTPUT);
}

void loop() {
	int re = analogRead(A0);//读入电压数值
	int volt = map(re,0,1023,0,5000);//对应到相应电压值的1000倍
	Serial.println(volt);//用于串口调试
	light(volt);//输出电压值
}

