#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][33][3] = { 0 };  //dp[시간][횟수][무슨나무]
int tree[1001] = { 0 };		//tree[자두 떨어지는 나무]
int main() {
	int t, w, ans = 0;
	cin >> t >> w;	//t시간 w횟수
	for (int i = 1; i <= t; i++) 
		cin >> tree[i];

	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= w+1; j++) {
			if (tree[i] == 1) {
				if (i == 1) {
					dp[1][j][1] = 1;
					dp[1][i][2] = 0;
				}
				dp[i][j][1] = max(dp[i-1][j][1]+1, dp[i-1][j-1][2] +1);
				dp[i][j][2] = max(dp[i-1][j][2],dp[i-1][j-1][1]);
			}
			else {
				if (i == 1) {
					dp[1][j][1] = 0;
					dp[1][i][2] = 0;
				}
				dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]);
				dp[i][j][2] = max(dp[i - 1][j][2] + 1, dp[i - 1][j - 1][1] + 1);
			}
		}
	}
	for (int i = 1; i <= w+1; i++) {
		ans = max(ans,max(dp[t][i][1], dp[t][i][2]));
	}
	cout << ans << endl;
	return 0;
}

