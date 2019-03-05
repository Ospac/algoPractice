#include <stdio.h>
#define nMAX 20000
/*
	input:
	9
	0 0 0 1 1 1 2 2 2
	0 0 0 1 1 1 2 2 2
	0 0 0 1 1 1 2 2 2
	1 1 1 0 0 0 0 0 0
	1 1 1 0 0 0 0 0 0
	1 1 1 0 0 0 0 0 0
	0 1 2 0 1 2 0 1 2
	0 2 1 0 2 1 0 2 1
	1 1 1 0 1 1 2 2 2

*/

int count = 0;
int zoo[nMAX][nMAX];

void fence(int left, int right, int top, int bottom) {
	int i, j;
	if (left == right) // baseCase
		return;

	int pivot = zoo[top][left];

	for (i = top; i <= bottom; i++) {
		for (j = left; j <= right; j++) {
			if (pivot != zoo[i][j]) {
				count++;
			
				int point = (right - left) / 3; // right와 left에 대한 식으로 정해야함, right나 left만으로 계산하면 오류!


					//divide
					fence(left,				point,					top,	point);
					fence(point + 1,		right - point - 1,		top,	point);
					fence(right - point,	right,					top,	point);

					fence(left,				point,				top + point + 1, bottom - point - 1);
					fence(point + 1,		right - point - 1,	top + point + 1, bottom - point - 1);
					fence(right - point,	right,				top + point + 1, bottom - point - 1);

					fence(left,				point,				bottom - point,		bottom);
					fence(point + 1,		right - point - 1,	bottom - point,		bottom);
					fence(right - point,	right,				bottom - point,		bottom);
					return;
			}
		}
	}
}
int main(void) {
	int n;
	int i, j;
	char fileName[20];
	printf("Input File Name?\n");
	scanf("%s", fileName);
	FILE* fp = fopen(fileName, "r");

	fscanf(fp, "%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
 			fscanf(fp, "%d", &zoo[i][j]);
		}
	}

	fence(0, n - 1, 0, n - 1);
	printf("%d", count);
}
