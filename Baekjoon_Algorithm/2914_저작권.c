#include <stdio.h>
int main(void) {
	int A, I;;
	scanf_s("%d", &A);
	scanf_s("%d", &I);
	printf("%d\n", A*(I - 1) + 1);
	return 0;
}