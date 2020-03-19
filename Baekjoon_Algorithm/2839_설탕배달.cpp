#include <iostream>

using namespace std;

int main(void) {
	int n, k = 0;
	cin >> n;
	while(n > 0) {
		if (n % 5 == 0) {
			k += n / 5;
			n = 0;
			break;
		}
		n = n - 3;
		k++;
	}
	if (n == 0) cout << k;
	else cout << "-1";
	return 0;
}