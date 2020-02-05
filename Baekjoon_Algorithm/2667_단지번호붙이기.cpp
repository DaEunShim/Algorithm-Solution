#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int a[26][26];
int d[26][26];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;
int ans[25 * 25];

void bfs(int x,int y,int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
				}
			}
		}

	}
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%1d", &a[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && d[i][j] == 0) {
				bfs(i, j, ++cnt);
			}
		}
	}
	cout << cnt << endl;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			ans[d[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}