#include<stdio.h>
#include<math.h>
void htower(int n,int a, int b);
int main(void) {
	int n;
	scanf_s("%d", &n);
	printf("%d\n", (int)pow(2,n) - 1);
	htower(n, 1, 3);

	return 0;
}

void htower(int n, int a, int b) {
	int c;
	if (n == 1) printf("%d %d\n", a, b);
	else {
		c = 6 - a - b;
		htower(n - 1, a, c);
		printf("%d %d\n", a, b);
		htower(n - 1, c, b);
	}
}