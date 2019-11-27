#include <iostream>
using namespace std;
#include <string>

int elec[1000][1000];
int m, n, flag = 0;
int d_x[] = { -1, 0, 1, 0 };
int d_y[] = { 0, 1, 0, -1 };

void go(int x, int y) {
	elec[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int n_x = x + d_x[i];
		int n_y = y + d_y[i];
		if (n_x < 0 || n_x == m || n_y < 0 || n_y == n) continue;
		if (elec[n_x][n_y] == 1) continue;
		if (n_x == m - 1) {
			flag = 1;
			return;
		}
		go(n_x, n_y);
	}
	return;
}

int main() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &elec[i][j]);
		}
	}

	for (int k = 0; k < n; k++) {
		if (elec[0][k] == 0)
			go(0, k);
	}

	if (flag == 0) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}