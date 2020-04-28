#include <iostream>

using namespace std;
int a[11];

int main(void) {
	int n, k, cnt=0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = n-1; i >= 0; i--) {
		cnt += k / a[i];
		k %= a[i];
	}
	cout << cnt << endl;
	return 0;
}