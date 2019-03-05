#include <stdio.h>
#define nMax 20

int d[nMax][nMax];
int p[nMax][nMax];


int main(void) {
	int n;
	int i, j, k;
	char fileName[20];
	scanf("%s", fileName);
	FILE *fp = fopen(fileName, "r");
	fscanf(fp, "%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fscanf(fp, "%d", &d[i][j]);
		}
	}
	//거쳐가는 정점을 기준으로 배열d,p를 갱신
	for (k = 0; k < n; k++) { //k : 거쳐가는 노드의 idx
		for (i = 0; i < n; i++) {  //i : 출발 노드
			for (j = 0; j < n; j++) {  //j : 도착 노드
				//i -> j 의 비용과 i-> k -> j의 비용을 비교, 갱신
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}

			}
		}
		printf("%d\n",k);
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%d", d[i][j]);
				if (j == n - 1)
					putchar('\n');
				else
					putchar(' ');
			}
		}
		if (k != n - 1)
			printf("---------------\n");
	}
}
/*  0   1    2    3   4

0	0   1   999   1   5
1	9   0    3    2   5
2	999 999  0    4   999
3	999 999  2    0   3
4	3   999  999  999 0
*/
