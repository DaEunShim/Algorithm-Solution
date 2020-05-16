#include <iostream>
#include <queue>
using namespace std;

int n, ans = 0;
int pipe[20][20];
int visit[20][20];
int dx[] = { 0,1,1 };
int dy[] = { 1,0,1 };

void bfs(int x, int y,int dir) { //가로 0, 세로 1, 대각선 2
	queue<pair<pair<int, int>,int>> q;
	q.push({ {x,y,},dir });
	visit[x][y] = 1;

	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int direction = q.front().second;
		q.pop();

		if (cx == n && cy == n) { ans++; continue; }

		for (int i = 0; i < 3; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 1 || nx > n || ny < 1 || ny > n) continue; // 벗어남
			if (direction == 0 && i == 1) continue; // 가로일때 세로로 못 감
			if (direction == 1 && i == 0) continue; // 세로일때 가로로 못 감
			if (cx == n - 1 && direction == 1 && i != 2 && cy != n ) continue; // 무조건 대각선
			if (cy == n - 1 && direction == 0 && i != 2 && cx != n) continue; // 무조건 대각선
			if (cx == n - 1 && direction == 2 && i == 1 && cy != n) continue; // 맨 아랫줄에서 위, 대각선일때 세로로 못 감
			if (cy == n - 1 && direction == 2 && i == 0 && cx != n) continue; // 맨 오른쪽에서 옆, 대각선일때 가로로 못 감

			if (pipe[nx][ny] == 1) continue; // 벽
			if (i == 2 && (pipe[nx - 1][ny] == 1 || pipe[nx][ny - 1] == 1)) continue; // 대각선 벽


			visit[nx][ny] ++;
			q.push({ {nx,ny}, i });
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> pipe[i][j];
	}

	bfs(1,2,0);

	cout << ans << endl;
	return 0;
}