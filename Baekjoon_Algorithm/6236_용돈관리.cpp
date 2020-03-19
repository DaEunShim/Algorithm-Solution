#include <iostream>
#include<vector>
using namespace std;

int n, m;
int calc(int mid, vector<int> v) {
	int ans = 1;
	int now = 0;
	for (int i = 0; i < n; i++) {
		if (now + v[i] > mid) {
			ans++;
			now = v[i];
		}
		else now += v[i];
	}
	return ans;
}
int main() {
	int start = 1, end = 1000000000;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (start < v[i]) start = v[i];
	}
	while (start < end) {
		int mid = (start + end) / 2;
		if (calc(mid, v) > m)
			start = mid + 1;
		else end = mid;
	}
	cout << start << endl;
	return 0;
}