#include <iostream>
#include <queue>

using namespace std;

struct compare {
	bool operator()(const int& x, const int& y) {
		if (abs(x) == abs(y)) return x > y;
		return abs(x) > abs(y);
	}
};
int main() {
	int n, x, ans = 0;
	scanf_s("%d", &n);
	priority_queue<int, vector<int>, compare> pq;
	while (n--) {
		scanf_s("%d", &x);
		if (!x) { // 배열에서 절댓값이 가장 작은 값 출력
			if (pq.empty()) {
				printf("0\n");
				continue;
			}
			printf("%d\n", pq.top());
			pq.pop();
		}
		else {
			pq.push(x);
		}
	}
	return 0;
}