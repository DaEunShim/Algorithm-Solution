#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> dp(k+1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

    for(int i = 1; i <= k; i++)
        dp[i] = 10001;

	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) { 
			dp[j] = min(dp[j-arr[i]] + 1, dp[j]);
		}
	}

    if(dp[k] == 10001) cout << -1 << endl;
	else cout<<dp[k]<<endl;
	return 0;
}