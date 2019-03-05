#include<stdio.h>
#define nMax 8
#define iMax 200

int EE[iMax][iMax][2];
int w[nMax]; //전력소모량
int wSum[nMax]; // w[0] + ... + w[i]
int pos[nMax]; //가로등 위치
int n; //가로등의 수
int m; //처음 위치

//left: 1 ~ right: n
int min(int a, int b) {
	if (a >= b)
		return a;
	else return b;
}
int son(int left, int right, int side) {
	if (left == right)
		return 0;
	if (EE[left][right][side] != -1) { //if memorized
		return EE[left][right][side];
	}
	int value = 214748364; //intMax
	if (side == 0) { //왼쪽
		value = min(son(left + 1, right, 0) + w[left], son(left + 1, right, 1) + (pos[right] - pos[left]) * w[left]);
	}
	if (side == 1) { //오른쪽
		value = min(son(left, right - 1, 0) + (pos[right] - pos[left]) * w[right], son(left, right - 1, 1) + w[right]); 
	}
	return value;

}
int main(void) {

	int i, j, k;
	char fileName[20];
	printf("Input File Name?\n");
	scanf("%s", fileName);
	FILE* fp = fopen(fileName, "r");

	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);
	for (i = 0; i < n; i++) fscanf(fp, "%d", &pos[i]);

	fscanf(fp, "%d", &w[0]);
	wSum[0] = w[0];
	for (i = 1; i < n; i++) {
		fscanf(fp, "%d", &w[i]);
		wSum[i] = w[i] + wSum[i - 1];
	}

	for (i = 0; i < iMax; i++) {
		for (j = 0; j < iMax; j++) {
			for (k = 0; k < 2; k++) {
				EE[i][j][k] = -1;
			}
		}
	}
	int basePoint;
	for (i = 0; i < nMax; i++) {
		if (pos[i] > m) {
			basePoint = pos[i];
		}
	}

}
