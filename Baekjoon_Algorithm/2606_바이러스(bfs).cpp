#include <iostream>
#include <queue>

using namespace std;

int n, m, cnt = 0;
int arr[101][101];
int visit[101] = { 0 };
void bfs(int x) {
	queue<int> q;
	q.push(x);
	visit[x] = 1;
	
	while (!q.empty()) {
		int next = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[next][i] && !visit[i]) {
				visit[i] = 1;
				q.push(i);
				cnt++;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	bfs(1);
	cout << cnt << endl;
	return 0;
}