#include <iostream>

using namespace std;
int money[] = { 500,100,50,10,5,1 };

int main(void) {
	int n, cnt = 0;
	cin >> n;
	n = 1000 - n;
	for (int i = 0; i < 6; i++) {
		while (n - money[i] >= 0) {
			cnt++;
			n -= money[i];
		}
		if (n == 0) break;
	}
	cout << cnt << endl;
	return 0;
}