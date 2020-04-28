#include <iostream>

using namespace std;
int T, a, b, m;
int main(void) {
	cin >> T;
	while (T--) {
		m = 0;
		cin >> a >> b;
		if (!a) m += 0;
		else if (a == 1) m += 500;
		else if (a <= 3) m += 300;
		else if (a <= 6) m += 200;
		else if (a <= 10) m += 50;
		else if (a <= 15) m += 30;
		else if (a <= 21) m += 10;

		if (!b) m += 0;
		else if (b == 1) m += 512;
		else if (b <= 3) m += 256;
		else if (b <= 7) m += 128;
		else if (b <= 15) m += 64;
		else if (b <= 31) m += 32;

		cout << m * 10000 << '\n';
	}
	return 0;
}