#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int k, n;
	long long ans = 0, sum = 0;
	cin >> k >> n;
	vector<int> v(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i];
		sum += v[i];
	}

	sort(v.begin(), v.end());
	
	long long left = 1, right = v[k - 1];
	while (left<=right) {
		long long mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) 
			cnt += v[i] / mid;
		if (cnt >= n) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << ans << endl;
	return 0;
}
