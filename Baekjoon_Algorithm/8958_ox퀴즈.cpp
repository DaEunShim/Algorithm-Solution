#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	int n;
	char c[90];
	cin >> n;
	while (n--) {
		int sum = 0, cnt = 1;
		cin >> c;
		for (int i = 0; i < strlen(c); i++) {
			if (c[i] == 'O') {
				sum += cnt;
				cnt++;
			}
			else cnt = 1;
		}
		cout << sum << endl;
	}
	return 0;
}