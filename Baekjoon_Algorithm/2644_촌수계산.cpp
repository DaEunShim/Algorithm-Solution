#include <iostream>
#include <queue>
using namespace std;

int n, a, b, m;  // a와 b의 촌수 계산
int family[101][101];
int visit[101];

void bfs(int x) {
	for (int i = 1; i <= n; i++)
		visit[i] = -1;
	queue<int> q;
	q.push(x);
	visit[x] = 0;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			// 방문 안했고, 부모 자식 관계
			if (visit[i] == -1 && (family[temp][i] || family[i][temp])) { 
				visit[i] = visit[temp] + 1;
				q.push(i);
			}

		}

	}
}
int main() {
	cin >> n >> a >> b >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y; //x는 y의 부모
		family[x][y] = 1;
	}
	bfs(a);

	cout << visit[b] << endl;
	return 0;
}