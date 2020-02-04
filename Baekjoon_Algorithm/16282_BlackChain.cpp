#include <iostream>

using namespace std;

int main() {
	int n, cnt, i;
	cin >> n;
	for (i = 1;; i++) {
		if ((n >> i) <= 0) break;
	}
	if (n % 2 == 0) i++;
	cnt = i / 2;
	/*for (int i = 3;; i += 2) {
		if (n <= (2 << i) - 1) {
			cnt = i / 2;
			break;
		}
	}*/
	cout << cnt;
	return 0;
}
