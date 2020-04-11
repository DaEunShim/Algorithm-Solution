#include <stdio.h>
int main(void) {
	int test, n, i, j,p;
	float sum;
	int a[1000] = { 0 };
	scanf_s("%d", &test);
	for (i = 0; i < test; i++) {
		scanf_s("%d", &n);
		for (j = 0, sum = 0; j < n; j++) {
			scanf_s("%d",&a[j]);
			sum += a[j];
		}
		for (j = 0,p = 0; j < n; j++) {
			if (a[j] > (sum / n)) p++;
		}
		printf("%.3f%%\n", ((float)p / (float)n) * 100);
	}
	return 0;
}