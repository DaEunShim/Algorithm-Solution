#include <stdio.h>
int main(void) {
	int a, b,A,B;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	A = (a % 10)*100;
	a = a / 10;
	A += (a % 10)*10+(a/10);
	B = (b % 10) * 100;
	b = b / 10;
	B += (b % 10) * 10 + (b / 10);
	printf("%d", A > B ? A : B);
	return 0;
}