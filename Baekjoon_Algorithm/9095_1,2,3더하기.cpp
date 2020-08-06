
#include <iostream>

using namespace std;
int d[20];

int main() {
	int T, n;
	cin >> T;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	while (T--) {
		cin >> n;
		for (int i = 4; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		cout << d[n]<< "\n";
	}
	return 0;
}


