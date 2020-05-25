#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, card, ans = 0;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		cin >> card;
		pq.push(card);
	}
	while (pq.size() != 1) {
		int num1 = pq.top();
		pq.pop();
		int num2 = pq.top();
		pq.pop();
		ans += num1 + num2;
		pq.push(num1+ num2);
	}
	cout << ans << endl;
	return 0;
}