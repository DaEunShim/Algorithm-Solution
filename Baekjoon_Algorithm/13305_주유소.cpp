#include <iostream>
#include <queue>

using namespace std;


int main() {
	int n;
	long long ans = 0;
	cin >> n;
	vector<long long> road(n);
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < n - 1; i++)
		cin >> road[i];// 도로길이
	for (int i = 0; i < n; i++) {
		long long price;
		cin >> price; // 리터당 가격
		pq.push(price);
		ans += pq.top() * road[i];
	}

	cout << ans << endl;
	return 0;
}