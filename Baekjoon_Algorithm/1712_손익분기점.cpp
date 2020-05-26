#include <iostream>

using namespace std;

int main(void) {
	int A, B, C;
	int n = 0;
	scanf_s("%d %d %d", &A, &B, &C);
	if (B >= C) n = -1;
	else {
		n = (int)(A / (C - B)) + 1;
	}
	printf("%d", n);
	return 0;
}