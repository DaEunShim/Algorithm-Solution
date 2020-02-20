#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum += a[i];
		}
	}
	cout << sum;
	return 0;
}