#include <iostream>

using namespace std;

int main() {
	int N, K, sum = 0;
	cin >> N >> K;
	while(K--) {
		int A;
		cin >> A;
		sum += (A + 1) / 2;
	}
	if (N <= sum) cout << "YES";
	else cout << "NO";
	return 0;
}