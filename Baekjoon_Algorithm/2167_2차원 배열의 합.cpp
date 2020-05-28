#include <iostream>
#include <vector>
#define MAX 301


using namespace std;


int arr[301][301] = { 0, };
int dp[301][301] = { 0, };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	int k, i, j, x, y;
	cin >> k;
	while (k--) {
		int sum = 0;
		cin >> i >> j >> x >> y;
		sum = dp[x][y] - dp[i-1][y] - dp[x][j-1] + dp[i-1][j-1];
		cout << sum << endl;
	}

	return 0;
}