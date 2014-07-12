// number.ino
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
	while (u) {
		f[--k] = u % 10;
		u /= 10;
	}
	bool ze;
	for (int k = 1;k <= 300;k++) {
		ze = 0;
		for (int j = 1;j <= 4;j++) {
			if (f[j] != 0 || ze) digitalWrite(index[j] + 1, HIGH);
			if (f[j] != 0) ze = 1;
			for (int i = 1;i <= 9;i++) {
				if (num[f[j]][i]) {
					digitalWrite(flag[num[f[j]][i]] + 1, LOW);
					delayMicroseconds(140 / num[f[j]][0]);
					digitalWrite(flag[num[f[j]][i]] + 1, HIGH);
				}
			}
			digitalWrite(index[j] + 1, LOW);
		}
	}
}
// void dark(int u) {
// 	for (int i = 0;i < 9;i++) {
// 		if (num[u][i]) digitalWrite(flag[num[u][i]] + 1, HIGH);
// 	}
// }
void setup() {
	for (int i = 2;i  <= 13;i++) pinMode(i,OUTPUT);
	digitalWrite(flag[3], HIGH);
}

void loop() {
	for (int i = 0;i < 9999;i++) {
		light(i);
	}
}

