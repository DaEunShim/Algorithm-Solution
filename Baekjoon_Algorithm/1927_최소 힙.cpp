#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	int n, x, ans = 0;
	scanf_s("%d", &n);
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		scanf_s("%d", &x);
		if (!x) { // 배열에서 가장 작은 값 출력
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