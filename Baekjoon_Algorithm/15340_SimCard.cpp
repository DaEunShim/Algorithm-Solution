#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	while (1) {
		int c, d,A,B,C;
		cin >> c >> d;
		if (c == 0 && d == 0) break;
		A = c * 30 + d * 40;
		B = c * 35 + d * 30;
		C = c * 40 + d * 20;
		printf("%d\n",min(A,min(B, C)));
	}
	return 0;
}