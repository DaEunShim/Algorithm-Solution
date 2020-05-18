#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<bool> v(n+1);
	vector<int> arr;
	
	// 에라토스테네스의 체
	for (int i = 2; i <= n; i++) {
		if (v[i]) continue; 
		for (int j = i + i; j <= n; j += i)
			v[j] = true;
	}

	// 소수들만 배열에 저장
	for (int i = 2; i <= n; i++) 
		if (!v[i]) arr.push_back(i);

	int start = 0, end = 0, ans = 0, sum = 0;
	int size = arr.size();
	while (start <= end) {
		if (sum == n) ans++;
		if (sum >= n) sum -= arr[start++];
		else if (end == size) break;
		else sum += arr[end++];
	}

	cout << ans << endl;
	return 0;
}