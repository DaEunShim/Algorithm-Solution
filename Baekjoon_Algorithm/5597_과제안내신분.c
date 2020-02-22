#include <stdio.h>
int main(void) {
	int i,n=0;
	int num[31] = { 0 };
	for (i = 1; i <= 28; i++) {
		scanf_s("%d", &n);
		num[n] = 1;
	}
	for (i = 1; i <= 30; i++) {
		if (num[i] == 0) printf("%d\n", i);
	}
	return 0;
}