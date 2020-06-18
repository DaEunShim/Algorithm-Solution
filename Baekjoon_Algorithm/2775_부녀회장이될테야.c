#include <stdio.h>
int main(void) {
	int house[15][15] = { 0 };
	int T, k, n;
	int i, j;
	for (i = 1; i < 15; i++) house[0][i] = i;
	for (i = 1; i < 15; i++){
		for (j = 1; j < 15; j++) {
			house[i][j] = house[i][j - 1] + house[i - 1][j];
		}
	}
	scanf_s("%d", &T);
	while (T--) {
		scanf_s("%d", &k);
		scanf_s("%d", &n);
		printf("%d\n", house[k][n]);
	}
	return 0;
}