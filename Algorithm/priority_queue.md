일반적인 큐(queue)는 들어간 순서대로 나온다.

우선순위 큐(priority queue)는 **우선순위가 높은 순서대로 나온다.**

우선순위 큐는 주로 힙(heap)을 이용하여 구현한다.

## c++에서 우선순위 큐 사용법(STL priority_queue)

- #include <queue>
- priority_queue<T, Container, Compare>

    원하는 자료형 및 클래스 T를 통해 생성한다.

    Container는 주로 vector와 같은 컨테이너이다.

    Compare는 비교함수 클래스이다.(greater<int>, less<int>)

    ```cpp
    priority_queue<int, vector<int>, greater<int>> pq;
    ```

- push(data): 우선순위 큐에 원소 추가
- pop(): top의 원소 삭제
- top(): top에 있는 원소 반환. 삭제는 하지 않음.
- empty(): 우선순위 큐가 비어있으면 true, 아니면 false
- size(): 우선순위 큐에 포함되어 있는 원소들의 수

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, x, ans = 0;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		cin >> x;
		if (!x) { // 배열에서 가장 작은 값 출력
			if (pq.empty()) {
				cout << 0 << endl;
				continue;
			}
			cout << pq.top() << endl;
			pq.pop();
		}
		else {
			pq.push(x);
		}
	}
	return 0;
}
```