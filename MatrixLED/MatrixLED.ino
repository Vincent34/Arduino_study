// MatrixLED.ino
#include <cstring>
int row[8] = {9,14,8,12,1,7,2,5},column[8] = {13,3,4,10,6,11,15,16};
int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int count = 0;
int a,b;
bool light[8][8],ex[8][8];
void setup() {
	Serial.begin(9600);
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) light[i][j] = ex[i][j] = 0;
		row[i]++;
		column[i]++;
	}
	for (int i = 0;i < 8;i++) {
		light[3][i] = ex[4][i] = light[4][i] = ex[4][i] = 1;
		light[i][3] = ex[i][4] = light[i][4] = ex[i][4] = 1;
	}
	for (int i = 0;i < 8;i++) {
		pinMode(row[i], OUTPUT);
		digitalWrite(row[i], LOW);
		pinMode(column[i], OUTPUT);
		digitalWrite(column[i], HIGH);
	}
}

void flash() {
	for (int i = 0;i < 8;i++) {
		digitalWrite(row[i], HIGH);
		for (int j = 0;j < 8;j++) {
			if (light[i][j])
				digitalWrite(column[j], LOW);
			delayMicroseconds(50);
			digitalWrite(column[j], HIGH);
		}
		digitalWrite(row[i], LOW);
	}
}

void change() {
	for (int i = 0;i < 8;i++)
		for (int j = 0;j < 8;j++) {
			int tmp = 0;
			for (int k = 0;k < 8;k++) {
				if (ex[i + dir[k][0]][j + dir[k][1]]) {
					tmp++;
				}
			}
			light[i][j] = tmp & 1;
		}
	memcpy(ex,light,sizeof(ex));
}
void loop() {
	flash();
	count++;
	if (count == 200) {
		change();
		count = 0;
	}
}
// void loop() {
// 	for (int i = 0;i < 8;i++) 
// 		for (int j = 0;j < 8;j++) {
// 			digitalWrite(row[i], HIGH);
// 			digitalWrite(column[j], LOW);
// 			delay(50);
// 		}
// }

