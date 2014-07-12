// number_1.ino
int index[5] = {0,12,9,8,6};
int flag[10] = {0,11,7,4,2,1,10,5,3};
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
};
void light(int u) {
	int f[5] = {0,0,0,0,0},k = 5;
	while(u) {
		f[--k] = u % 10;
		u /= 10;
	}
	for (int i = 1;i <= 4;i++) {
		digitalWrite(index[i] + 1, HIGH);
		for (int j = 1;j <= 7;j++) {
			if (num[f[i]][j]) digitalWrite(flag[num[f[i]][j]] + 1, LOW);
			delayMicroseconds(100);
			digitalWrite(flag[num[f[i]][j]] + 1, HIGH);
		}
		digitalWrite(index[i] + 1, LOW);
	}
}
void setup() {
	for (int i = 2;i <= 13;i++) pinMode(i, OUTPUT);
	digitalWrite(4, HIGH);
}

void loop() {
	light(1234);
	// for (int i = 1;i <= 9999;i++) {
	// 	light(i);
	// }
}

