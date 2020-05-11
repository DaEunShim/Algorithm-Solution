#include <iostream>
#include <queue>
using namespace std;

int box[1000][1000];
int visit[1000][1000];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int m,n,days = 0;
queue<pair<int, int>> q;

int check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!box[i][j] && visit[i][j] == -1) //다 안익음
				return -1;
			days = max(days, visit[i][j]);
		}
	}
	return days;
}
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (box[nx][ny]== 0 && visit[nx][ny] == -1) { //익지 않은 토마토
				visit[nx][ny] = visit[x][y] + 1;
				q.push({ nx,ny });
			}
		}

	}

}
int main() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			visit[i][j] = -1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];	// 1이면 익은거, 0은 안익은거, -1은 토마토 안들어 있음
			if (box[i][j] == 1) {
				visit[i][j] = 0;
				q.push({ i,j });
			}
			else visit[i][j] = -1;
		}
	}

	bfs();
	cout << check() << endl;
	return 0;
}