#include <iostream>
#include <vector>

using namespace std;

int N, arr[81];

void func(int k) {
	for (int i = 1; i <= k / 2; i++) {
		if (equal(arr + k - i, arr + k, arr + k - i * 2)) return;
	}
	if (k == N) {
		for (int i = 0; i < N; i++) cout << arr[i];
		exit(0);
	}
	for (int i = 1; i <= 3; i++) {
		arr[k] = i;
		func(k + 1);
	}
}



int main(void) {
	cin >> N;
	func(0);
	return 0;
}