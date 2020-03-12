#include <iostream>

using namespace std;

int fibo[41][2] = {0,};
int main(void) {
	int T;
	cin >> T;
	fibo[0][0] = 1;
	fibo[1][1] = 1;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 2; i <= n; i++) {
			fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
			fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
		}
		cout << fibo[n][0] << fibo[n][1] << endl;
	}
	return 0;
}