#include <iostream>

using namespace std;

int a[100][100];

int main(void) {
	int n, width=0, height=0, ck = 0;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == 'X') {
				a[i][j] = 0;
				ck = 0;
			}
			else {
				a[i][j] = 1;
				if (ck == 1) {
					width++;
					ck = 2;
				}
				else if (ck != 2) ck = 1;
			}
		}
		ck = 0;
	}
	ck = 0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (a[i][j] == 0) ck = 0;
			else {
				if (ck == 1) {
					height++;
					ck = 2;
				}
				else if (ck != 2) ck = 1;
			}
		}
		ck = 0;
	}

	cout << width << " " << height;
	return 0;
}