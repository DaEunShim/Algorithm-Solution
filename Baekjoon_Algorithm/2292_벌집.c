#include <stdio.h>
int main(void) {
	int N, c = 1, sum = 1, i;
	scanf_s("%d", &N);
	while (sum < N){
		sum += c * 6;
		c++;
	}
	printf("%d", c);
	return 0;
}