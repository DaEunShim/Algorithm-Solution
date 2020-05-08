#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, cntT = 0, cntF = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num = i;
		while (num % 2 == 0 || num % 5 == 0) {
			if (num % 2 == 0) {
				num /= 2;
				cntT++;
			}
			if (num % 5 == 0) {
				num /= 5;
				cntF++;
			}
		}
	}
	cout << min(cntT,cntF);
	return 0;
}