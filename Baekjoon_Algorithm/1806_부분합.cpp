#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int start = 0, end = 0, sum = 0, minLen = 0x7FFFFFF;
	while (start <= end) {
		if (sum >= s) {
			minLen = min(minLen,end - start);
			sum -= arr[start++];
		}
		else if (end == n) break;
		else sum += arr[end++];
	}

	if (minLen == 0x7FFFFFF) cout << 0 << endl;
	else cout << minLen << endl;
	return 0;
}