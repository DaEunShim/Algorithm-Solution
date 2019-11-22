#include <iostream>

using namespace std;

int main(void) {
	int n, k;
	while (scanf_s("%d%d", &n, &k) != EOF) {
		int sum = n;
		while (n >= k) {
			sum += n / k;
			n = n % k + n / k;
		}
		cout << sum << endl;
	}
	return 0;
}