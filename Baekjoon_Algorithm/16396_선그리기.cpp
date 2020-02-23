#include <iostream>

using namespace std;
bool b[10001];

int main(void) {
	int n,sum=0,max=0;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		for (int i = x; i < y; i++) {
			b[i] = true;
		}
		if (y > max) max = y;
	}
	for (int i = 1; i <= max; i++) {
		if (b[i]) sum++;
	}
	cout << sum;
	return 0;
}