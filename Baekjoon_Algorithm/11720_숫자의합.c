#include <stdio.h>
int main(void) {
	int N, sum = 0, i;
	char num[101];
	scanf_s("%d", &N);
	scanf_s("%s", num);
	for (i = 0; i < N; i++) {
		sum += (num[i] - '0');
	}
	printf("%d\n", sum);
	return 0;
}